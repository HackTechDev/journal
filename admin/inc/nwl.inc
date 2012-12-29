<?php
/*
    Admin Newsletter Box - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v3.0 (25 February 2004)  : initial release (by Nicolas Alves)
      v4.0 (06 December 2004)  : added multi-admin management (by Nicolas Alves)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "nwl.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[33]=="") {
    $nomzone=$admin546;
    include("access.inc");
    exit();
  }
}
$qtype = TYP_NWL;
$bname = 0;
$bemail = 0;
$bcat = 0;
$btitre = 1;
$bcontenu = 1;
$bnouveau = 0;
$qformonly = 0;
$qtitle = $admin545;
$qintro = $admin531;
$qseeall = $admin539;
$qwrite = $admin538;
$qcat = "";
$qtitre = $admin537;
$qcontenu = $admin536;
$qnouveau = "";
include ("inc/admin.inc");

?>
