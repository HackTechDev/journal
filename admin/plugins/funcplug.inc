<?php
/*
    Plugins Functions - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
	v3.0 (25 February 2004)  : initial release
	v4.0 (06 December 2004)  : modified count loop (by Jean-Mi)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "funcplug.inc")) {
  header("location:../index.php");
  die();
}

function PluginRegistered($pluginame) {
  if (FileDBExist(DBPLUGIN)) {
    $DataDB = ReadDBFields(DBPLUGIN);
    for ($i = 0; $i < count($DataDB); $i++) {
      if ($DataDB[$i][0] == $pluginame) {
        return true;
      }
    }
  }
  return false;
}

function RegisterPlugin($pluginame) {
  $newplug[0] = $pluginame;
  AppendDBFields(DBPLUGIN,$newplug);
}

function UnregisterPlugin($pluginame) {
  $oldplug = ReadDBFields(DBPLUGIN);
  for ($i = 0 ; $i < count($oldplug); $i++) {
    if ($oldplug[$i][0] != $pluginame) {
      $newplug[] = $oldplug[$i];
    }
  }
  WriteDBFields(DBPLUGIN,$newplug);
}
?>
