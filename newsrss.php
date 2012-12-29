<?php
/*
    News RSS - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v3.0 (25 February 2004)  : initial release
      v3.0p1 (26 Feb 2004)     : bug fix, if no icons set selected, then do not display news image
      v4.0 (06 December 2004)  : added page title (by Jean-Mi)
                                 added alt tags to img and removed border tag for non-linked img (by Isa)
      v4.5 (08 April 2005)     : corrected $item description (by JeanMi)
      v4.5.1 (06 July 2005)    : added editing date (thanks Tanet), enhanced presentation (by Icare)
      v4.6.0 (04 June 2007)    : added $max_chr for very long items (by Icare)
      v4.6.9 (25 December 2008): correction of the posting of certain flows RSS #229
      v4.6.10 (7 September 2009)    : corrected #263
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");
if ($serviz[38] != "on") {
  exit($web143);
}
$max_height = "72"; // max height of the items summary
$longword = 300;
//$max_height = round($longword/3);
$id = strip_tags($id);
ReadDoc(DBBASE.$id);
if ($lng == $lang[0]) {
  $rssurl = $fieldb1;
  $rsstxt = $nom[36]." - ".$fielda1;
}
else {
  $rssurl = $fieldb2;
  $rsstxt = $nom[37]." - ".$fielda2;
}
if ($page[9] != "") {
  $rsstxt = "<img src=\"".CHEMIN."inc/img/icons/".$page[9]."/news.gif\" align=\"right\" width=\"32\" height=\"32\" alt=\"news.gif\"/>".$rsstxt;
}
$topmess = $rsstxt;
include("inc/hpage.inc");
htable($rsstxt,"100%");
include("inc/lastRSS.inc");
$rss = new lastRSS;
$rss->default_cp = strtoupper($charset);
$rss->cache_dir = substr(CACHEREP,0,strlen(CACHEREP)-1);
$rss->cache_time = $serviz[39];
if ($rs = $rss->Get($rssurl)) {

    /// Modif pour iconv
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
    ///
    
  if ($rs['image_url'] != "") {
    echo "<center><img src='".$rs['image_url']."' border='0' alt='' title='' /></center>";
  }
?>
<p class="forum"><b><a href="<?php echo $rs['link']; ?>" target="_blank"><?php echo MyIConv($rs['title']); ?></a></b></p>
<p><br /><b><?php echo html_entity_decode(MyIConv($rs['description'])); ?></b></p>
<hr style="width:60%" />
<?php
  $i=0;
  foreach($rs['items'] as $item) {
    $i++;
    if ($item['title'] == "" && $item['link'] == "") {
      $txt = "";
    }
    elseif ($item['title'] == "") {
      $txt = "<a href=\"".$item['link']."\" target=\"_blank\">".$item['link']."</a><br /><br />";
    }
    elseif ($item['link'] == "") {
      $txt = "<u>".MyIConv($item['title'])."</u><br /><br />";
    }
    else {
      $txt = "<a href=\"".$item['link']."\" target=\"_blank\" title=\"".$web297."\">".MyIConv($item['title']);
      $txt .= "&nbsp; <img src='".CHEMIN."inc/img/general/tolist.gif' border='0' alt='".$web297."' /></a><br /><br />";
    }
    $desc = html_entity_decode(MyIConv($item['description']));
    $txt1 = "<b>".$txt."</b>".$desc;
      if (strlen($desc) >= $longword) {
        $txt2 = "\n<div id=\"texte2".$i."\" class=\"rep\" style=\"margin: 0px; padding:2px\">";
        $txt2 .="\n<div class=\"rep\" style=\"height:".$max_height."px; overflow:hidden;\">".$txt1."</div>";
        $txt2 .= "<p style=\"text-align:right\"><a href=\"javascript:cache('texte2".$i."');montre('texte1".$i."');\" class=\"box\" title=\"".$web296."\">";
        $txt2 .= "<sup>...</sup> / ... <img src=\"".CHEMIN."inc/img/general/open.gif\" border=\"0\" alt=\"".$web296."\" /></a></p></div>" ;
  	    echo $txt2;
		    echo "\n<div id=\"texte1".$i."\" class=\"bord\" style=\"display:none; margin: 2px; padding: 10px 5px 5px 5px\">".$txt1;
		    echo "<p align=\"right\" style=\"cursor:pointer;\"><img src=\"".CHEMIN."inc/img/general/close.gif\" border=\"0\" alt=\"".$web57."\" title=\"".$web57."\" onclick=\"cache('texte1".$i."');montre('texte2".$i."')\" /></p></div>";
      }
	    else{
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
    }
    else {
      $txt = $web263." <b>".FormatDateStamp($modfl)."</b>";
    }
    echo "<p>".$txt."</p>";
}
else {
  echo "<p>".$web262." ".$rssurl."</p>";
}
btable();
include("inc/bpage.inc");
?>
