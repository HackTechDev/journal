<?php
/*
    Registered Plugins Management - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2008 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v3.0 (25 February 2004)     : initial release
      v4.0 (06 December 2004)     : added the sidebox specific style (by Isa)
                                  : added the menu management style (by Isa)
      v4.6.0 (04 June 2007)       : added management for lateral box (by Ghaz-Icare)
                                    new management (by djchouix))
      v4.6.9 (25 December 2008)   : correction of the activation of the items of the principal menu #224
*/

if (stristr($_SERVER["SCRIPT_NAME"], "hplugins.inc")) {
  header("location:../index.php");
  die();
}

$PluginsDB = ReadDBFields(DBPLUGIN);

for ($i = 0; $i < count($PluginsDB); $i++) {
	unset($plugin_bar_name, $plugin_bar_icon, $plugin_bar_url, $plugin_bar_alturls);

	if (is_file(CHEMIN."plugins/".$PluginsDB[$i][0]."/plugin.inc")) {
		include CHEMIN."plugins/".$PluginsDB[$i][0]."/plugin.inc";
	}

	if ($plugin_bar_name != "") {
		$menu[$plugin_bar_name.'_'.$PluginsDB[$i][0]] = array(
			'id' => $PluginsDB[$i][0],
			'name' => $plugin_bar_name,
			'icon' => 'plugins/'.$PluginsDB[$i][0].'/'.$plugin_bar_icon,
			'url' => 'plugins/'.$PluginsDB[$i][0].'/'.$plugin_bar_url,
			'alturls' => is_array($plugin_bar_alturls) ? $plugin_bar_alturls : array()
		);
	}
}
?>
