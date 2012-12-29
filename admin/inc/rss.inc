<?php
/*
    Admin RSS News - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v3.0 (25 February 2004)  : initial release
      v4.0 (06 December 2004)  : added multi-admin management (by Nicolas Alves)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "rss.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[34]=="") {
    $nomzone=$admin602;
    include("access.inc");
    exit();
  }
}
$qtype = TYP_RSS;
$bname = 0;
$bemail = 0;
$bcat = 1;
$btitre = 1;
$bcontenu = 0;
$bnouveau = 0;
$qformonly = 0;
$qtitle = $admin603;
$qintro = $admin604.$admin223;
$qseeall = $admin605;
$qwrite = $admin606;
$qcat = $admin607;
$qtitre = $admin608;
$qcontenu = "";
$qnouveau = "";
include ("inc/admin.inc");

?>
