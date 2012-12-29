<?php
/*
    Admin Clock Sample Plugin - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
	v3.0 (25 February 2004)  : initial release
	v4.0 (06 December 2004)  : no change
*/

if (stristr($_SERVER["SCRIPT_NAME"], "plugin.inc")) {
  header("location:../index.php");
  die();
}

if ($lng == "fr") {
  include(CHEMIN."plugins/clock/fr-clock.inc");
}
else {
  include(CHEMIN."plugins/clock/en-clock.inc");
}
$plugin_admin_name = $clock7;

$plugin_admin_url = "clock/clock";
$plugin_admin_icon = "clock/clock.gif";

$plugin_sidebox_name = "";
$plugin_sidebox_url = "";
?>
