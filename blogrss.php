<?php
/*
    Blog - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.6.0 (04 June 2007)        : initial release by Icare
      v4.6.1 (18 June 2007)        : added missing end of page (by Icare)
      v4.6.2 (22 July 2007)        : corrected bad end of page (by Icare)
      v4.6.10 (7 September 2009)   : corrected #263 and #274
      v4.6.11 (11 December 2009)   : corrected #300
      v4.6.22 (29 December 2012)   : corrected duplicate display of boxes (thanks Icare)
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");
if ($serviz[27] != "on") {
    exit($web143);
}
$max_height = "72"; // max height of the items summary
$longword = 300;
if ($userprefs[3] =="" || $userprefs[3] == "LR") $userprefs[3] = "L";
$widepage = $serviz[58];
$topmess = ($lng == $lang[0])? $nom[42] : $nom[43] ;
$topmess .= " - ".$web402;
$id = strip_tags($id);
ReadDoc(DBBASE.$id);
if ($lng == $lang[0]) {
  $rssurl = $fieldb1;
  $rsstxt = $fielda1;
} else {
  $rssurl = $fieldb2;
  $rsstxt = $fielda2;
}
if ($page[9] != "") {
  $topmess = "<img src=\"".CHEMIN."inc/img/icons/".$page[9]."/blog.gif\" align=\"right\" width=\"32\" height=\"32\" alt=\"\" title=\"\" />".$topmess;
}
include("inc/hpage.inc");
htable($topmess,"100%");
  if ($widepage != "") include(CHEMIN."inc/topblog.inc");
  echo '
<br />
<div style="width:100%;">
 <table align="center" cellpadding="4" style="width:100%" summary="">
  <tr>';
  $widthbox = !isset($boxwidth) ? "172px" : strpos($boxwidth, 'px') === false ? '172px' : $boxwidth;
  if ($widepage == "on" || $userprefs[3] != "L") {
    echo '
    <td valign="top" style="width:'.$widthbox.';">';
    include(CHEMIN."inc/blogcat.inc");
    include(CHEMIN."inc/bloglist.inc");
    if ($widepage != "on") {
      include(CHEMIN."inc/blogcalendar.inc");
      include(CHEMIN."inc/blogrss.inc");
    }
    echo '
    </td>';
  }
?>  
<td style="width:100%;vertical-align:top;padding-top:0px;">
<?php
// affichage blog rss --------------------------------- 
include("inc/lastRSS.inc");
$rss = new lastRSS;
$rss->cache_dir = substr(CACHEREP,0,strlen(CACHEREP)-1);
$rss->cache_time = $serviz[39];
if ($rs = $rss->Get($rssurl)) {
    // Modif pour iconv
    if(!function_exists('iconv')) {
      function iconv($from, $to, $string)
      {
        $converted = htmlentities($string, ENT_NOQUOTES, $from);
        $converted = html_entity_decode($converted, ENT_NOQUOTES, $to);
        return $converted;
      }
    }
    $cpin  = strtoupper($rs['encoding']);
    $cpout = strtoupper($charset);
    if ($cpin == $cpout) {
        function MyIConv($txt) { return $txt; }
    } else {
        function MyIConv($txt) {
            global $cpin, $cpout;
            return iconv($cpin, $cpout, $txt);
        }
    }
    //
    if ($rs['image_url'] != "") {
        echo "<center><img src='".$rs['image_url']."' border='0' alt='' title='' /></center>";
    }
echo '
<div class="titre"><b><a href="'.$rs['link'].'" target="_blank">'.MyIConv($rs['title']).'</a></b></div>
<div class="tbl">';  // can be changed by htable(...) and htable()
// htable('<a href="'.$rs['link'].'" target="_blank">'.MyIConv($rs['title']).'</a>', '100%');
?>
<p style="text-align: center; font-weight:bolder"><br /><i>----- <?php echo html_entity_decode(MyIConv($rs['description'])); ?> -----</i></p>
<hr style="width:10%; margin-top:10px;" />
<?php
    foreach($rs['items'] as $item) {
      $i++;
      if ($item['title'] == "" && $item['link'] == "") {
        $txt = "";
      } elseif ($item['title'] == "") {
        $txt = "<a href=\"".$item['link']."\" target=\"_blank\" title=\"\">".$item['link']."</a><br /><br />";
      } elseif ($item['link'] == "") {
        $txt = "<u>".MyIConv($item['title'])."</u><br /><br />";
      } else {
        $txt = "<a href=\"".$item['link']."\" target=\"_blank\" title=\"".$web296."\">".MyIConv($item['title']);
        $txt .= "&nbsp; <img src='".CHEMIN."inc/img/general/tolist.gif' border='0' alt='".$web297."' /></a><br /><br />";
      }
      $desc = html_entity_decode(MyIConv($item['description']));
      $txt1 = "<b>".$txt."</b>".$desc;
      if (strlen($desc) >= $longword) {
        $txt2 = "\n<div id=\"texte2".$i."\" class=\"rep\" style=\"margin: 0px; padding:2px\">";
        $txt2 .="\n<div class=\"rep\" style=\"height:".$max_height."px; overflow:hidden;\">".$txt1."</div>";
        $txt2 .= "<p style=\"text-align:right\"><a href=\"javascript:cache('texte2".$i."');montre('texte1".$i."');\" class=\"box\" title=\"".$web296."\">";
        $txt2 .= "<sup>...</sup> / ... <img src=\"".CHEMIN."inc/img/general/open.gif\" border=\"0\" alt=\"".$web296."\" title=\"".$web296."\" /></a></p></div>" ;
        echo $txt2;
        echo "\n<div id=\"texte1".$i."\" class=\"bord\" style=\"display:none; margin: 2px; padding: 10px 5px 5px 5px\">".$txt1;
        echo "<p align=\"right\" style=\"cursor:pointer;\"><img src=\"".CHEMIN."inc/img/general/close.gif\" border=\"0\" alt=\"".$web57."\" title=\"".$web57."\" onclick=\"cache('texte1".$i."');montre('texte2".$i."')\" /></p></div>";
      } else{
        echo "<div class=\"rep\">".$txt1."</div>\n";
      }
      if ($item['pubDate'] != "") {
        echo "<font color='#999999'>(";
        echo FormatDate($item['pubDate']).")</font>";
      }
      echo "<hr />";
    }
    $modfl = @filemtime(CACHEREP."rsscache_".md5($rssurl));
    if ($modfl == false) {
      $txt = $web261;
    } else {
      $txt = $web263." <b>".FormatDateStamp($modfl)."</b>";
    }
    echo "<p>".$txt."</p>";
   echo "</div>";
   //btable();
} else {
  echo "<p>".$web262." ".$rssurl."</p>";
}

// fin rss ----------------------------------------
echo "</td>";
if ($widepage == "on" || $userprefs[3] == "L") {
   echo '
   <td valign="top" style="width:'.$widthbox.';">';

if ($widepage != "on") {
  include(CHEMIN."inc/blogcat.inc");
  include(CHEMIN."inc/bloglist.inc");
}
include(CHEMIN."inc/blogcalendar.inc");
include(CHEMIN."inc/blogrss.inc");
 echo '
   </td>';
}
if ($lng == $lang[0]) {
    $i = 0;
} else {
    $i = 1;
}
echo "</tr>
</table>";
echo "</div>
</div>";
include(CHEMIN."inc/bpage.inc");
?>