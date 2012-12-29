<?php
/*
    Admin Speed Sample Plugin - GuppY PHP Script - version 4.6
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
  include(CHEMIN."plugins/speed/fr-speed.inc");
}
else {
  include(CHEMIN."plugins/speed/en-speed.inc");
}
$plugin_admin_name = $speed7;
$plugin_admin_url = "speed/speed";
$plugin_admin_icon = "speed/speed.gif";
$centerlabelslist[] = $speed7;
$centerboxeslist[] = "plugins/speed/boxspeed";
$editolabelslist[] = $speed7;
$editoboxeslist[] = "plugins/speed/boxspeed";
?>
