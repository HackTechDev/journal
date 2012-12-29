<?php
/*
    Admin Mind Plugin - GuppY PHP Script - vversion 4.6
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
  include(CHEMIN."plugins/mind/fr-mind.inc");
}
else {
  include(CHEMIN."plugins/mind/en-mind.inc");
}

$plugin_admin_name = $mind7;

$plugin_admin_url = "mind/mind";
$plugin_admin_icon = "mind/mind.gif";

$plugin_sidebox_name = $mind8;
$plugin_sidebox_url = "plugins/mind/boxmind";
?>
