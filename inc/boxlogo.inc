<?php
/*
    Logo Box - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.6.0 (04 June 2007)        : initial release (by Icare)

*/
if (stristr($_SERVER["SCRIPT_NAME"], "boxlogo.inc")) {
  header("location:../index.php");
  die();
}
if ($skn_logo != "") $logo = $skn_logo; else $logo = CHEMIN."img/".$page[4]; // skin logo
if ($logo != CHEMIN."img/") {
echo '
  <div class="logo">
  <a href="'.$site[3].'index.php?lng='.$lng.'" title="'.$site[0].'">
  <img src="'.$logo.'" border="0" alt="'.$site[0].'" /></a>
  </div>'."\n";
}
?>
