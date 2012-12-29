<?php
/*
    Speed Sample Plugin Activation - GuppY PHP Script - version 4.0
    CeCILL Copyright (C) 2004-2006 by Laurent Duveau
    Made by Laurent Duveau, Nicolas Alves, Albert Aymard,
	Jean-Michel Misrachi, Isabelle Marchina and Team
      Web site = http://www.freeguppy.org/
      e-mail   = info@aldweb.com

    Version History :
      v3.0 (25 February 2004)   : initial release
      v4.6.3 (30 August 2007)   :added display in welcome page, thanks JeanMi
*/

if (stristr($_SERVER["SCRIPT_NAME"], "plugin.inc")) {
  header("location:index.php");
  die();
}

if ($lng == "fr") {
  include(CHEMIN."plugins/speed/fr-speed.inc");
}
else {
  include(CHEMIN."plugins/speed/en-speed.inc");
}
$plugin_bar_name = $speed7;
$plugin_bar_url = "speed.php";
$plugin_bar_icon = "speed.gif";
$centerlabelslist[] = $speed7;
$centerboxeslist[] = "plugins/speed/boxspeed";
$editolabelslist[] = $speed7;
$editoboxeslist[] = "plugins/speed/boxspeed";

?>
