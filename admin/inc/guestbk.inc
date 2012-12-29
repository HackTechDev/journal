<?php
/*
    Admin Guestbook - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.7 (28 January 2003)   : added $bnouveau and $qnouveau
      v1.8 (05 February 2003)  : corrected hide e-mail bug
      v2.4 (24 September 2003) : created $typ_[name] variables
      v4.0 (06 December 2004)  : added multi-admin management (by Nicolas Alves)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "guestbl.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[22]=="") {
    $nomzone=$admin11;
    include("access.inc");
    exit();
  }
}
$qtype = TYP_GUESTBK;
$bname = 1;
$bemail = 1;
$bcat = 0;
$btitre = 1;
$bcontenu = 1;
$bnouveau = 2;
$qformonly = 0;
$qtitle = $admin113;
$qintro = $admin226.$admin223;
$qseeall = $admin172;
$qwrite = "";
$qcat = "";
$qtitre = $admin173;
$qcontenu = $admin174;
$qnouveau = $admin261;
include ("inc/admin.inc");

?>
