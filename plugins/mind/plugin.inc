<?php
/*
    Mind Sample Plugin Activation - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2006 by Laurent Duveau
    Made by Laurent Duveau, Nicolas Alves, Albert Aymard,
	Jean-Michel Misrachi, Isabelle Marchina and Team
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v3.0 (25 February 2004)  : initial release
      v4.0 (06 December 2004)  : no change
*/

if (stristr($_SERVER["SCRIPT_NAME"], "plugin.inc")) {
  header("location:index.php");
  die();
}

$plugin_bar_name = "";
$plugin_bar_url = "";
$plugin_bar_icon = "";
?>
