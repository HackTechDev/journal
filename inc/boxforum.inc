<?php
/*
    Forum Live - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v2.4 (24 September 2003)    : initial release
      v4.0 (06 December 2004)     : added alt tags to img and removed border tag for non-linked img (by Isa)
                                    removed the trans pixel (by Isa)
                                    replaced & by &amp; for better compliance with standards (by Isa)
      v4.6.0 (04 June 2007)       : added thread title and tr class, thread modification date (by Icare)
                                    added missing title when there is no category (by Ghazette)
                                    deleted unefficent string  and optimized table tags (by Icare)
                                    added icons new or sticky if option set by admin forum (by Icare)
      v4.6.1 (02 July 2007)       : suppress useless string $up (thanks hpsam)
      v4.6.5 (10 November 2007)   : added missing restriction to members (by Icare)
      v4.6.6 (14 April 2008)      : added title on icons (by Icare)
      v4.6.10 (7 September 2009)  : corrected #274
      v4.6.11 (xx november 2009)  : changed width by style=width on cells (by Icare)
      v4.6.15 (30 June 2011)      : added private forum management (by Icare)
      v4.6.16 (02 September 2011) : corrected private forum management (by jchouix, Pascal31, Laroche)
      v4.6.17 (21 October 2011)   : whether activated categories (by Laroche)
	  v4.6.20 (24 May 2012)       : corrected btable (by Saxbar)
      v4.6.22 (29 December 2012)  : added pseudo-private group for members (by Saxbar)	  
*/

if (stristr($_SERVER["SCRIPT_NAME"], "boxforum.inc")) {
  header("location:../index.php");
  die();
}

if ($serviz[13] == "on" && $site[20] > 0) {
  if ($lng == $lang[0]) {
    $l = 0;
  }
  else {
    $l = 1;
  }
  if ($serviz[18] == "on") {
    $dbworkcat = ReadDBFields(DBFORUMCAT);
	$CatForumOn = true;
  }
  $dbwork = array();
  $dbwork = ReadDBFields(DBTHREAD);
  @rsort($dbwork);
  $dbfor = ReadDBFields(DBFORUM);
  $dbmess = array();
  
  if (!empty($dbwork)) {
	$newdate = date("YmdHi",time()-(86400*$forum[8])); // délai pour nouveau
	$messtop = "<img src=\"".CHEMIN."inc/img/general/msg_t.gif\" alt=\"".$web370."\" title=\"".$web370."\" style=\"vertical-align:-5px\" />";
	$messnew = "<img src=\"".CHEMIN."inc/img/general/msg_n.gif\" alt=\"".$web371."\" title=\"".$web371."\" style=\"vertical-align:-5px\" />";
      $i = 0;
      $j = 0;
      $n = 0;

      while($n < $site[20] && !empty($dbwork[$i][3])) {
              ReadDoc(DBBASE.$dbwork[$i][3]);
              if ($fielda2 == "0") {
                $dbmess[$j][0] = $fileid; //thread sujet
                $sujet = strip_tags($fieldb1);
              }
              else {
                for ($k = 0; $k < count($dbfor); $k++) {
                  if ($fielda1 == $dbfor[$k][1]) {
                    $fieldb2 = $dbfor[$k][12];
                    $dbmess[$j][0] = $dbfor[$k][2];
                    $sujet = strip_tags($dbfor[$k][5]);
                    $nbrep = $dbfor[$k][7];
                    $dbmess[$j][7] = $dbwork[$i][2];
                    $dbmess[$j][8] = $dbfor[$k][3];
                  }
                }
              }
              $dbmess[$j][1] = $fieldb2;
			  $catpriv = '';
              for ($k = 0; $k < count($dbworkcat); $k++) {
				$prcat = explode(',', $dbworkcat[$k][0]);
				if (empty($prcat[1])) $prcat[1] = '';
                if ($prcat[0] == $fieldb2) {
                  $dbmess[$j][2] = $dbworkcat[$k][$l+1];
				  $catpriv = $prcat[1];
                }
              }
              $fieldc1 = str_replace('<br />',' &#172; ',$fieldc1);
              $tabc = SplitText(strip_tags($fieldc1),100);
              $dbmess[$j][3] = $tabc[0];
              $dbmess[$j][4] = FormatDate($creadate)."<br />";
              // début date de modif thread si up ou top
              if ($newdate < $creadate || $newdate < $moddate){
                $dbmess[$j][4] = FormatDate($creadate)."<br />".$messnew." ";
              }
              if ($moddate != $creadate){
                if ($moddate > date("YmdHi")) {
                  $dbmess[$j][4] = FormatDate(date("YmdHi"))."<br />".$messtop." ";
                }
                elseif ($fieldmod != ""){
                  $datemod = explode("#",$fieldmod);
                  $dbmess[$j][4] = FormatDate($datemod[2])."<br />";
                }
                else {
                  $dbmess[$j][4] = FormatDate($moddate)."<br />";
                }
              }
              $dbmess[$j][5] = $sujet;
              $dbmess[$j][6] = (ceil($dbmess[$j][7]/ $serviz[20]));
              $dbmess[$j][9] = $author;
              //fin modif date

              /// début modif si forum privé              
              $acces = "ok";
              if ((!is_numeric($fieldb2) && $CatForumOn) || !empty($catpriv)) {
                  $acces = "no";
                  if ($userprefs[1] != "") {
                    include_once (CHEMIN.'inc/func_groups.php');
                    if (CheckGroup($catpriv, $userprefs[1])) {
                        $acces ="ok";
                    }
                  }
              }
              $dbmess[$j][10] = $acces;
			  
              $i++;
              $j++;
               if ($acces != 'no') {$n++;}
        }
  }
  $topmess = $nom[$l+22]." ".$web179;
  if ($page[9] != "") {
    $topmess = "<img src=\"".CHEMIN."inc/img/icons/".$page[9]."/forum.gif\" align=\"right\" width=\"32\" height=\"32\" alt=\"forum.gif\"/>".$topmess;
  }
  htable($topmess,"100%");
if ($members[0]=="on" && $userprefs[1]=="" && $members[5]=="on") {
	echo "<p align=\"center\">".$web342."</p><br />";
	echo "<p align=\"center\">[ <a href=\"".CHEMIN."user.php?lng=".$lng."\">".$web343."</a> ]</p><br />";
}
else {
  if (!empty($dbmess)) {
    echo "<br /><div align=\"center\">\n";
    echo "<table class=\"bord\" style=\"margin:8px 0px;\" align=\"center\" cellspacing=\"0\" cellpadding=\"3\" width=\"98%\" summary=\"\">";
    for ($i = 0; $i < count($dbmess); $i++) {
      if ($dbmess[$i][10] == "ok") { /// début modif si forum privé
        if ($i %2 == 0) {$bgcol="rep";} else {$bgcol="quest";}
        $tmpmess = "<tr class=\"".$bgcol."\" style=\"vertical-align:top\">\n";
        if ($serviz[18] == "on") {
          $tmpmess .= "<td rowspan=\"2\" style=\"width:22%;\">";
          $tmpmess .= "<a href=\"forum.php?lng=".$lng."&amp;cat=".$dbmess[$i][1]."\" title =\"".$web297."\"><b>".$dbmess[$i][2]."</b></a></td>\n";
        }
        $tmpmess .= "<td colspan=\"2\" ><b>".$web384." <a href=\"thread.php?lng=".$lng."&amp;pg=".$dbmess[$i][0]."&amp;cat=".$dbmess[$i][1]."\" title =\"".$web6." ".$dbmess[$i][8]." ... ".$web297." \">".$dbmess[$i][5]."</a></b></td></tr>\n";
        $tmpmess .= "<tr class=\"".$bgcol."\" style=\"vertical-align:top\">\n";
        $tmpmess .= "<td style=\"width:100%\"><a href=\"thread.php?lng=".$lng."&amp;pg=".$dbmess[$i][0]."&amp;id=".$dbmess[$i][6]."&amp;cat=".$dbmess[$i][1]."#".$dbmess[$i][7]."\" title =\"".$web6." ".$dbmess[$i][9]." ... ".$web297." \"> ".$dbmess[$i][3]." ...</a></td>\n";
        $tmpmess .= "<td nowrap=\"nowrap\">".$dbmess[$i][4]." (".$web6." ".$dbmess[$i][9].")</td></tr>\n";
        echo $tmpmess;
      } ///fin modif si forum privé
    }
    echo "</table></div>\n";
  }
}
  btable($topmess);
}
?>
