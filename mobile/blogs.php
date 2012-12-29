<?php
/*
    Blogs list for PDA - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.6.0 (04 June 2007)          : initial release (by Icare)
      v4.6.17 (21 October 2011) : added private management (by Saxbar)
*/

header("Pragma: no-cache");

define("CHEMIN", "../");
include(CHEMIN."inc/includes.inc");

if ($serviz[53] != "on") {
  exit($web143);
}

$section_index = 15;
$section_name = $lng == $lang[0] ? $nom[42] : $nom[43];
include('inc/members.inc');
if ($section_access) {

    include("inc/hpalm.inc");

      if ($lng == $lang[0]) {
        $tartg = $nom[42];
        $tartd = $nom[44];
      }
      else {
        $tartg = $nom[43];
        $tartd = $nom[45];
      }
      $dbw = ReadDBFields(DBBLOG);
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
    	      echo "<b>".$rubr."</b><br>\n";
    	    }
          }
          if (trim($rubr) != "") {
    	    echo "&nbsp;&nbsp;".$texte[3]." <a href=\"blog.php?lng=".$lng."&pg=".$arttbl[$i][3]."\">".$arttbl[$i][2]."</a><br>\n";
          }
        }
      }

    include("inc/bpalm.inc");
}
?>
