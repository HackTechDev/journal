<?php
/*
    Admin Plugins Boxes Manager - GuppY PHP Script - vversion 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
	v3.0 (25 February 2004)  : new Plugins Manager
	v4.0 (06 December 2004)  : no change
    v4.6.10 (7 September 2009)    : corrected #266
*/

if (stristr($_SERVER["SCRIPT_NAME"], "plugbox.inc")) {
  header("location:../index.php");
  die();
}

$pluginlist = ExploreDir('plugins/');

if (!empty($pluginlist)) {
  for ($i = 0; $i < count($pluginlist); $i++) {
    $plugin_sidebox_name = "";
    if(is_file("plugins/".$pluginlist[$i]."/plugin.inc"))
    include("plugins/".$pluginlist[$i]."/plugin.inc");
    if ($plugin_sidebox_name != "") {
      $labelslist[] = $plugin_sidebox_name;
      $boxeslist[] = $plugin_sidebox_url;

    }
  }
}
?>
