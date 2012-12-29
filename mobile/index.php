<?php
/*
    Site Index for PDA - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alvès,
    followed by Albert Aymard, Jean Michel Misrachi and all the Team
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v2.3 (27 July 2003)      : initial release (thanks Palmipod)
      v2.4 (24 September 2003) : corrected a bug in the mobile version: the showing of articles
                                 for each of the 2 articles boxes is now fine (thanks Hubert)
                                 added option for choosing Articles mark (thanks Pavol)
                                 created $dbhomepage variable
      v4.0 (06 December 2004)  : no change
      v4.6.17 (21 October 2011) : added private management (by Saxbar)	  
*/

header("Pragma: no-cache");

define("CHEMIN", "../");
include(CHEMIN."inc/includes.inc");

if ($serviz[1] != "on") {
  exit($web143);
}

include("inc/hpalm.inc");

echo "<center><b>".$web1." ".$site[0]."</b></center><hr />";
include(DBHOMEPAGE);
if ($lng == $lang[0]) {
  echo PathToImage($home1);
}
else {
  echo PathToImage($home2);
}
if ($serviz[3] == "on" || $serviz[22] == "on") {
  echo "<hr />";
  if ($lng == $lang[0]) {
    $tartg = $nom[4];
    $tartd = $nom[30];
  }
  else {
    $tartg = $nom[14];
    $tartd = $nom[31];
  }
  $dbw = ReadDBFields(DBART);
  if (!empty($dbw)) {
    if ($lng == $lang[0]) {
      $j = 0;
    }
    else {
      $j = 1;
    }
    $k = 0;
    $arttbl = array();
    for ($i = 0; $i < count($dbw); $i++) {
  	  /// début modif accès privé
      $acces = "ok";
      if ($dbw[$i][6] != "") {
        $acces = "no";
        if ($userprefs[1] != "") {
          include_once (CHEMIN.'inc/func_groups.php');
          if (CheckGroup($dbw[$i][6], $userprefs[1])) $acces ="ok";
        }
      }
      if ($acces == "ok") {
      /// fin modif accès privé
				$arttbl[$k][0] = (empty($dbw[$i][5]))? "left": $dbw[$i][5];
				$arttbl[$k][1] = $dbw[$i][0+$j];
				$arttbl[$k][2] = $dbw[$i][2+$j];
				$arttbl[$k][3] = $dbw[$i][4];
				$k++;
			} /// fin accès privé
    }
    @sort($arttbl);
    $artboxpos = "";
    $rubr = "";
    for ($i = 0; $i < count($arttbl); $i++) {
      if ($artboxpos <> $arttbl[$i][0]) {
        $artboxpos = $arttbl[$i][0];
        if ($artboxpos == "left") {
          echo "<center><b>".$tartg."</b></center><hr />\n";
        }
        else {
          echo "<hr /><center><b>".$tartd."</b></center><hr />\n";
        }
      }
	  if ($rubr <> $arttbl[$i][1]) {
	    $rubr = $arttbl[$i][1];
        if (trim($rubr) != "") {
	      echo "<b>".$rubr."</b><br />\n";
	    }
      }
      if (trim($rubr) != "") {
	    echo "&nbsp;&nbsp;".$texte[3]." <a href=\"articles.php?lng=".$lng."&pg=".$arttbl[$i][3]."\">".$arttbl[$i][2]."</a><br />\n";
      }
    }
  }
}

include("inc/bpalm.inc");
?>
