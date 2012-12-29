<?php
/*
    Activity Log - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v3.0 (25 February 2004) : initial release
      v4.0 (06 December 2004) : updated log_stats (by Jean-Mi)
      v4.5 (30 March 2005)    : added test $dblogfiles (by Jean-Mi)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "log_stats.inc")) {
  header("location:../index.php");
  die();
}

function log_test() {
  if (is_file(DBLOGDATE)) {
    $last = ReadCounter(DBLOGDATE);
    return ($last != date("d/m/y"));
}
else
    return true;
}

function log_stats() {
  if (is_file(DBLOGFILES)) {
      WriteCounter(DBLOGDATE, date("d/m/y"));
      $files = file(DBLOGFILES);
      $s = "";
      foreach($files as $file) {
        $s .= ReadCounter(CHEMIN.DATAREP.trim($file)).";";
      }
      $fhandle = fopen(DBLOGSTATS, "a");
      fputs($fhandle, date("d/m/y;").$s."\n");
      fclose($fhandle);
    }
}

if (log_test()) log_stats();
?>
