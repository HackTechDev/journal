<?php
/*
    News - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v1.0 (30 December 2002)      : initial release
      v1.6 (23 January 2003)       : added option to hide on the site the e-mail address of poster
      v2.0 (27 February 2003)      : added encryption of webmaster's e-mail @ (SPAM protection)
      v2.1 (10 March 2003)         : added addslashes() to var in Javascript functions (to avoid errors)
      v2.2 (22 April 2003)         : option for choosing the number of items to display in news, forum threads, links, downloads, FAQ and Guestbook
                                     replaced <P><CENTER> by <P align="center"> otherwise IE takes the default font instead of the required one (Thanks Michel)
                                     cleanup in the images organization
      v2.3 (27 July 2003)          : added direct jump to pages (by Nicolas Alves and Laurent Duveau)
                                     added user news submission option (no more mandatory)
                                     upgraded WriteMailTo() function for better SPAM protection (thanks Mitch)
      v2.4 (24 September 2003)     : added an icon for articles and news
                                     added section icon in central boxes
                                     added ReadDoc() function
                                     added GetCurrentDateTime() and FormatDate() function to ease various date and time formatings
                                     reviewed all Files Read & Write functions
                                     secured transfered parameters
                                     created $typ_[name] variables
      v3.0 (25 February 2004)      : added RSS News file link information
      v4.0 (06 December 2004)      : added alt tags to img and removed border tag for non-linked img (by Isa)
                                     replaced & by &amp; in URL for standard compliance (by Isa)
      v4.5 (13 March 2005)         : cut long news on home page,
	                                 replacing table by collapsed div (by Icare and Nico)
	                                 replacing navigation bar, exported javascript in inc/hpage.js (by Jean-Mi)
								                 added closing button on collapsed news of home page (by Icare)
      v4.6.0 (27 June 2006)        : changed .../... by .../...[+], no display if lang title empty (by Icare)
                                     display elapsed page if javascript disabled (by Djchouix)
      v4.6.6 (14 April 2008)       : removal of div clear:both unsueful (by Icare)
                                     added urlencode in WriteMailTo() (by JeanMi)
                                     added header("HTTP/1.0 404 Not found") in the event of pages not found (by JeanMi, thanks eDada)
      v4.6.8 (24 May 2008)         : added date accidently remove, thanks bvince
      v4.6.11 (xx november 2009)   : deleted unefficient hr tag (by Icare)
      v4.6.15 (30 June 2011)       : added private news management (by Icare)
	                                 partial display changes and add permalink (thanks Laroche)
      v4.6.16 (02 September 2011)  : corrected display border icon	(by Papinou)
                                     corrected private news management (by Laroche)
	                                 corrected the loop selection to differentiate between public and private items (by Laroche)
      v4.6.17 (21 October 2011)    : corrected display read more (by Laroche)
	  v4.6.20 (24 May 2012)        : corrected btable (by Saxbar)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "news.inc")) {
  header("location:../index.php");
  die();
}
include_once (CHEMIN.'inc/func_groups.php'); // déplacé

$id = strip_tags($id);
$longword = 300;
$separator = "<!--CUT-->";
if (isset($site[29]) && $site[29] > 0) $longword = $site[29];
$max_height = round($longword/3*0.72);
if ($page[9] != "") {
  $topmess = "<img src=\"".CHEMIN."inc/img/icons/".$page[9]."/news.gif\" align=\"right\" alt=\"news.gif\" />".$topmess;
}
htable($topmess, "100%");
echo "<br />";

if ($members[0]=="on" && $userprefs[1]=="" && $members[13]=="on") {  // réservé aux membres
	echo "<p align=\"center\">".$web342."</p><br />";
	echo "<p align=\"center\">[ <a href=\"".CHEMIN."user.php?lng=".$lng."\">".$web343."</a> ]</p><br />";
}
else { 
  if ($site[5] != "2") { // bouton poster
    ?>
    <form action="<?php echo CHEMIN ?>postguest.php" method="post">
    <input type="hidden" name="lng" value="<?php echo $lng; ?>"/>
    <input type="hidden" name="typ" value="<?php echo TYP_NEWS; ?>"/>
    <div align="center">
    <?php echo $boutonleft; ?><button type="submit" title="<?php echo $web4; ?>"><?php echo $web4; ?></button><?php echo $boutonright; ?>
    </div>
    </form>
    <br />
    <?php
  }
  if (!empty($pg)) {
    if (count(SelectDBFields(TYP_NEWS,"a",$pg)) != 0) {
      $dbw = SelectDBFields(TYP_NEWS,"a",$pg);
    }
    else {
      $dbw = array();
    }
  }
  else {
    $dbw = SelectDBFields(TYP_NEWS,"a","");
  }
  @rsort($dbw);
 
  for ($i = 0; $i < count($dbw); $i++) {
   	ReadDoc(DBBASE.$dbw[$i][1]);	
	if(($fieldmod == '') || ('1' == CheckGroup($fieldmod, $userprefs[1]))) {
		$dbw_allowed[] = $dbw[$i];
	}
  }
  
  if (empty($id)) {
    $id = 1;
  }
  if ($indexnews == 1) {
    $minnews = $site[4];
    $maxnews = Min($site[4],count($dbw_allowed));
    $id = 1;
  }
  else {
    $minnews = $serviz[2];
    $maxnews = Min($serviz[2]*$id,count($dbw_allowed));
  }
  if (!empty($dbw_allowed)) {
    if (count($dbw_allowed) > $site[4]){$nbrnvisi=$site[4]; } else {$nbrnvisi=count($dbw_allowed);}
      for ($i = $minnews*($id-1); $i < $maxnews; $i++) {
        ReadDoc(DBBASE.$dbw_allowed[$i][1]);
        $hr = "<hr />";
        if ($i == $maxnews-1) {
          $hr = "";
        }
        if ($lng == $lang[0]) {
          $txt1 = $fieldb1;
          $txt2 = $fieldc1;
        }
        else {
          $txt1 = $fieldb2;
          $txt2 = $fieldc2;
        }
        /// debut modif accès réservé
        $acces = "ok";
        if ($fieldmod != "") {
          $acces = "no";
          if ($userprefs[1] != "") {
            include_once (CHEMIN.'inc/func_groups.php');
            if (CheckGroup($fieldmod, $userprefs[1])) $acces ="ok";
          }
          if ($acces == 'no') { // pas d'affichage
            $txt1 = "";
            $txt2 = "<p align='center'><br><br>".$web444."<br /><br /></p>\n";
          }
        }
        /// fin modif accès réservé
        if (!empty($txt1)) {
          if (!empty($fieldd2)) {
          $txt1 = "<img src=\"".CHEMIN."img/".$fieldd2."\" align=\"right\" border=\"0\" alt=\"".$fieldd2."\" />".$txt1;
          }
        ?>
	   <a name="news_<?php echo $i; ?>"></a>			
        <div class="bord" style="padding: 1px;">
        <div class="forum2"><p><a href="<?php echo 'news.php?lng='.$lng.'&amp;pg='.$dbw_allowed[$i][1].'"><b>'.$txt1.'</b>' ?></a>
        <?php
        echo " - ".$web6." ";
        if ($fieldd1 != "on") {
          $em = BreakEMail($email);
          ?>
          <b><a href="JavaScript:WriteMailTo('<?php echo addslashes(urlencode($author)); ?>','<?php echo $em[0]; ?>','<?php echo $em[1]; ?>','<?php echo $em[2]; ?>')"><?php echo addslashes($author); ?></a></b>
          <?php
        }
        else {
          echo "<b>".$author."</b>";
        }
        echo " ".$web7." ".FormatDate($creadate)."</p></div>\n";
        if ($indexnews == 1) {
          $txt3 = "\n<div id=\"texte3".$i."\" class=\"rep\" style=\"margin: 0px; padding:2px\">";
		 if(preg_match("`".$separator."`",$txt2)) {
			$block = explode($separator,$txt2);
			echo '<div class="rep" style="overflow:hidden">'.$block[0].'</div>';
			$part1 = '<div id="txt'. $i . '" class="rep" style="display:none;">'. $block[1].'</div>';
			$part1 .= '<div id="lls'. $i .'" class="rep" style="display:none; text-align:right;">';
			$part1 .='<img src="'. CHEMIN .'inc/img/general/minus.gif" border="0" alt="" title=""  onclick="cache(\'txt' .$i .'\');cache(\'lls'.$i.'\');montre(\'ft'. $i . '\');" />&nbsp;</div>';
			echo $part1;
			$part2 = '<div id="ft'.$i.'" class="rep" style="text-align:right;font-size:smaller">';
			$part2 .='<a href="#news_'.$i.'" onclick="montre(\'txt' . $i . '\');montre(\'lls'.$i.'\');cache(\'ft'.$i.'\')" title="'.$web296.'">';
			$part2 .= $web461.'<img src="'.  CHEMIN . 'inc/img/general/plus.gif" border="0" alt="" /></a>&nbsp;</div></div';
			echo $part2;		  
                                                    } 
	      else if (strlen($txt2) >= $longword){
                              $txt3 .="\n<div class=\"rep\" style=\"height:".$max_height."px; overflow:hidden;\">\n".$txt2."</div>\n";
                              $txt3 .= "<p style=\"text-align:right\"><a href=\"javascript:ActiveMenu('texte3','texte2',0,".$nbrnvisi.",".$i.")\" class=\"box\" title=\"".$web296."\">";
                              $txt3 .= $web461."<img src=\"".CHEMIN."inc/img/general/plus.gif\" border=\"0\" alt=\"".$web296."\" /></a></p></div>" ;
          }
          else{
            $txt3 .= "\n<div class=\"rep\">".$txt2."</div></div>";
          }
          echo $txt3;
		      echo "\n<div id=\"texte2".$i."\" class=\"rep\" style=\"display:none; margin: 0px; padding: 10px 5px 5px 5px\">\n".$txt2;
		      echo "<p align=\"right\" style=\"cursor:pointer;\"><img src=\"".CHEMIN."inc/img/general/minus.gif\" border=\"0\" alt=\"".$web57."\" title=\"".$web57."\" onclick=\"cache('texte2".$i."');montre('texte3".$i."')\" /></p></div>\n";
        }
        else{
	       echo "<div id=\"texte".$i."\" class=\"rep\">".$txt2."</div>\n";
        }
        if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32] == "on" && $drtuser[14]=="on")) {
          ?>
          <div style="text-align:right;">
          <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=news&amp;form=2&amp;id=<?php echo $dbw_allowed[$i][1]; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/edit.gif" border="0" alt="<?php echo $web308; ?>" title="<?php echo $web308; ?>" /></a>
          <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=news&amp;act=i&amp;id=<?php echo $dbw_allowed[$i][1]; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/desact.gif" border="0" alt="<?php echo $web333; ?>" title="<?php echo $web333; ?>" /></a>
          <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=news&amp;del=<?php echo $dbw_allowed[$i][1]; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/del.gif" border="0" alt="<?php echo $web324; ?>" title="<?php echo $web324; ?>" /></a>
          </div>
          <?php
        }
      echo "</div><br />\n";
      }
    }
    if ($serviz[16] == "on") {
      $rssnewsurl = $site[3].DATAREP."news".$lng.".xml";
      echo '<div class="pop">';
      echo '<a href="'.$rssnewsurl.'" target="_blank"><img src="'.CHEMIN .'inc/img/general/rss.gif" style="border:0px;vertical-align:bottom;" alt="rss" /> ';
      echo '<span>'.$web221.':<br /><b> '.$rssnewsurl.'</b></span>';
      echo '</a></div>';
    }
  } else if (!empty($pg)) {
    echo '<p>'.$web36.'</p>';
  }
  if ($indexnews != 1) {
    echo GetNavBar("news.php?lng=".$lng."&amp;pg=".$pg."&amp;id=", count($dbw_allowed), $id, $minnews);
  }
}
btable($topmess);
?>
