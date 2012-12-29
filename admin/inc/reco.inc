<?php
/*
    Admin Recommend to a Friend - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.7 (28 January 2003)   : initial release
      v2.4 (24 September 2003) : created $typ_[name] variables
      v4.0 (06 December 2004)  : added multi-admin management (by Nicolas Alves)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "reco.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[30]=="") {
    $nomzone=$admin249;
    include("access.inc");
    exit();
  }
}
$qtype = TYP_RECO;
$bname = 1;
$bemail = 1;
$bcat = 0;
$btitre = 1;
$bcontenu = 1;
$bnouveau = 0;
$qformonly = 0;
$qtitle = $admin246;
$qintro = $admin247.$admin223;
$qseeall = $admin172;
$qwrite = "";
$qcat = "";
$qtitre = $admin248;
$qcontenu = $admin174;
$qnouveau = "";
include ("inc/admin.inc");

?>
