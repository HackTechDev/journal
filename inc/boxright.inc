<?php
/*
    Site Right of Page - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.6.0 (04 June 2007)        : initial release by Icare
*/
echo '<div id="rightside">';
if (!isset($xposbox)) {
  $onemenu = 1;
  if ($userprefs[3] == "R" && !empty($posbox[0])) {
    include(CHEMIN.$posbox[0].INCEXT);
    $onemenu = 1;
  }
  if ($userprefs[3] != "L" && !empty($posbox[1])) {
    include(CHEMIN.$posbox[1].INCEXT);
    $onemenu = 1;
  }
  if ($userprefs[3] == "R" && !empty($posbox[2])) {
    include(CHEMIN.$posbox[2].INCEXT);
    $onemenu = 1;
  }
  if ($userprefs[3] != "L" && !empty($posbox[3])) {
    include(CHEMIN.$posbox[3].INCEXT);
    $onemenu = 1;
  }
  if ($userprefs[3] == "R" && !empty($posbox[4])) {
    include(CHEMIN.$posbox[4].INCEXT);
    $onemenu = 1;
  }
  if ($userprefs[3] != "L" && !empty($posbox[5])) {
    include(CHEMIN.$posbox[5].INCEXT);
    $onemenu = 1;
  }
  if ($userprefs[3] == "R" && !empty($posbox[6])) {
    include(CHEMIN.$posbox[6].INCEXT);
    $onemenu = 1;
  }
  if ($userprefs[3] != "L" && !empty($posbox[7])) {
    include(CHEMIN.$posbox[7].INCEXT);
    $onemenu = 1;
  }
  if ($userprefs[3] == "R" && !empty($posbox[8])) {
    include(CHEMIN.$posbox[8].INCEXT);
    $onemenu = 1;
  }
  if ($userprefs[3] != "L" && !empty($posbox[9])) {
    include(CHEMIN.$posbox[9].INCEXT);
    $onemenu = 1;
  }
  if ($userprefs[3] == "R" && !empty($posbox[10])) {
    include(CHEMIN.$posbox[10].INCEXT);
    $onemenu = 1;
  }
  if ($userprefs[3] != "L" && !empty($posbox[11])) {
    include(CHEMIN.$posbox[11].INCEXT);
    $onemenu = 1;
  }
  if ($userprefs[3] == "R" && !empty($posbox[12])) {
    include(CHEMIN.$posbox[12].INCEXT);
    $onemenu = 1;
  }
  if ($userprefs[3] != "L" && !empty($posbox[13])) {
    include(CHEMIN.$posbox[13].INCEXT);
    $onemenu = 1;
  }
  if ($userprefs[3] == "R" && !empty($posbox[14])) {
    include(CHEMIN.$posbox[14].INCEXT);
    $onemenu = 1;
  }
  if ($userprefs[3] != "L" && !empty($posbox[15])) {
    include(CHEMIN.$posbox[15].INCEXT);
    $onemenu = 1;
  }
  if ($userprefs[3] == "R" && !empty($posbox[16])) {
    include(CHEMIN.$posbox[16].INCEXT);
    $onemenu = 1;
  }
  if ($userprefs[3] != "L" && !empty($posbox[17])) {
    include(CHEMIN.$posbox[17].INCEXT);
    $onemenu = 1;
  }
  if ($userprefs[3] == "R" && !empty($posbox[18])) {
    include(CHEMIN.$posbox[18].INCEXT);
    $onemenu = 1;
  }
  if ($userprefs[3] != "L" && !empty($posbox[19])) {
    include(CHEMIN.$posbox[19].INCEXT);
    $onemenu = 1;
  }
} else {
  $onemenu = 1;
  for($ii=0; $ii<count($xposbox["R"]); $ii++) {
    if ($userprefs[3] == "R" && $xposbox["L"][$ii] != '') {
      include(CHEMIN.$xposbox["L"][$ii].INCEXT);
      $onemenu = 1;
    }
    if ($userprefs[3] != "L" && $xposbox["R"][$ii] != '') {
      include(CHEMIN.$xposbox["R"][$ii].INCEXT);
      $onemenu = 1;
    }
  }
}
echo '</div>';
?>
