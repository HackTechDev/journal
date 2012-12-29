<?php
/*
    Admin RSS Blog - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2008 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.6.0 (04 June 2007)      : initial release from news RSS by Icare

*/

if (stristr($_SERVER["SCRIPT_NAME"], "bss.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[41]=="") {
    $nomzone=$admin791;
    include("access.inc");
    exit();
  }
}
$qtype = TYP_BSS;
$bname = 0;
$bemail = 0;
$bcat = 1;
$btitre = 1;
$bcontenu = 0;
$bnouveau = 0;
$qformonly = 0;
$qtitle = $admin790;
$qintro = $admin604.$admin223;
$qseeall = $admin788;
$qwrite = $admin789;
$qcat = $admin607;
$qtitre = $admin608;
$qcontenu = "";
$qnouveau = "";
include ("inc/admin.inc");

?>
