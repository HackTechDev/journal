<?php
/*
    News for PDA - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v2.3 (27 July 2003)      : initial release (thanks Palmipod)
      v2.3p1 (03 August 2003)  : orrected bug in which next page link button was wrong (thanks airhero)
      v2.4 (24 September 2003) : added ReadDoc() function
                                 added GetCurrentDateTime() and FormatDate() function to ease various date and time formatings
                                 secured transfered parameters
                                 created $typ_[name] variables
      v4.0 (06 December 2004)  : no change
      v4.6.17 (21 October 2011) : added private management (by Saxbar)	  
*/

header("Pragma: no-cache");
define("CHEMIN", "../");
include(CHEMIN."inc/includes.inc");

if ($serviz[8] != "on") {
  exit($web143);
}

$section_index = 13;
$section_name = $lng == $lang[0] ? $nom[7] : $nom[17];
include('inc/members.inc');
if ($section_access) {

    $id = strip_tags($id);

    include("inc/hpalm.inc");

    if ($lng == $lang[0]) {
      $i = 0;
    }
    else {
      $i = 10;
    }
    $dbw = SelectDBFields(TYP_NEWS,"a","");
    @rsort($dbw);
    if (empty($id)) {
      $id = 1;
    }
    $minnews = $serviz[2];
    $maxnews = Min($serviz[2]*$id,count($dbw));
    echo "<center><b>".$nom[$i+7]."</b></center><hr />";
    if (!empty($dbw)) {
      for ($i = $minnews*($id-1); $i < $maxnews; $i++) {
        ReadDoc(DBBASE.$dbw[$i][1]);
				/// début modif accès privé
				$acces = "ok";
				if ($fieldmod != "") {
					$acces = "no";
					if ($userprefs[1] != "") {
						include_once (CHEMIN.'inc/func_groups.php');
						if (CheckGroup($fieldmod, $userprefs[1])) $acces ="ok";
					}
				}
				if ($acces == "ok") {
				/// fin modif accès privé
					$hr = "<hr />";
					if ($i == $maxnews-1) {
						$hr = "";
					}
					if ($lng == $lang[0]) {
						$txt1 = $fieldb1;
						$txt2 = PathToImage($fieldc1);
					}
					else {
						$txt1 = $fieldb2;
						$txt2 = PathToImage($fieldc2);
					}
					echo "<b>".$txt1."</b>";
					echo " - ".$web6." ";
					echo "<b>".$author."</b>";
					echo " ".$web7." ".FormatDate($creadate)."<br><br>".$txt2.$hr;
				} /// fin accès privé
      }
    }
    if (count($dbw)>$minnews) {
      echo '<hr />'.GetNavBar("news.php?lng=".$lng."&amp;id=", count($dbw), $id, $minnews);
    }
    include("inc/bpalm.inc");
}
?>
