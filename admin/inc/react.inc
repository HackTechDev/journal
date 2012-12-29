<?php
/*
    Admin Articles Reactions - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v2.4 (24 September 2003) : initial release
      v4.0 (06 December 2004)  : added multi-admin management (by Nicolas Alves)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "react.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[16]=="") {
    $nomzone=$admin476;
    include("access.inc");
    exit();
  }
}
$qtype = TYP_REACT;
$bname = 1;
$bemail = 1;
$bcat = 0;
$btitre = 0;
$bcontenu = 1;
$bnouveau = 2;
$qformonly = 0;
$qtitle = $admin477;
$qintro = $admin478.$admin223;
$qseeall = $admin172;
$qwrite = "";
$qcat = "";
$qtitre = $admin173;
$qcontenu = $admin174;
$qnouveau = $admin261;
include ("inc/admin.inc");

?>
