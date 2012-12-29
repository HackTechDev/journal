<?php
/*
    Admin Banners - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.9 (11 February 2003)  : initial release
      v2.4 (24 September 2003) : created $typ_[name] variables
      v4.0 (06 December 2004)  : added multi-admin management (by Nicolas Alves)
      v4.6.10 (7 September 2009)    : corrected #268
*/

if (stristr($_SERVER["SCRIPT_NAME"], "banner.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[27]=="") {
    $nomzone=$admin263;
    include("access.inc");
    exit();
  }
}
$qtype = TYP_BANNER;
$bname = 0;
$bemail = 0;
$bcat = 1;
$btitre = 1;
$bcontenu = 0;
$bnouveau = 1;
$qformonly = 0;
$qtitle = $admin264;
$qintro = $admin265.$admin223;
$qseeall = $admin266;
$qwrite = $admin267;
$qcat = $admin269;
$qtitre = $admin268;
$qcontenu = "";
$qnouveau = $admin918;
include ("inc/admin.inc");
