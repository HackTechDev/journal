<?php
/*
    Admin Plugins Manager - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
	v3.0 (25 February 2004)    : new Plugins Manager
	v4.0 (06 December 2004)    : put cellpadding to 1 and cellspacing to 3 instead of 0 (by Isa)
	v4.6.0 (04 June 2007)      : table reorganization (by Icare)
	v4.6.5 (05 December 2007) : corrected display of $pluginlist when file is empty, thanks JeanMi
	v4.6.7 (30 April 2008)    : don't display useless icons (by JeanMi)
	v4.6.8 (24 May 2008)      : corrected plugins list (by JeanMi)
    v4.6.10 (7 September 2009)    : corrected #266
*/

if (stristr($_SERVER["SCRIPT_NAME"], "plugins.inc")) {
  header("location:../index.php");
  die();
}

$pluginlist = ExploreDir("plugins/");

if (!empty($pluginlist)) {
    $items = array();
    echo '<div style="width:540px;margin:0 auto;">';
    foreach ($pluginlist as $item) {
        if(is_file("plugins/".$item."/plugin.inc")) {
            $plugin_admin_name = '';
            include("plugins/".$item."/plugin.inc");
            if ($plugin_admin_name != '') {
                $items[] = array('txt'=>$plugin_admin_name, 'href'=>'plugin&amp;plug='.$plugin_admin_url, 'src'=>'plugins/'.$plugin_admin_icon);
            }
        }
    }
    echo '</div>';
    ShowBlock($admin883, $items);
}
