<?php
/*
    Admin Photos - GuppY PHP Script - vversion 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v2.0 (27 February 2003)  : initial release
      v2.4 (24 September 2003) : created $typ_[name] variables
      v4.0 (06 December 2004)  : added multi-admin management (by Nicolas Alves)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "photo.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[18]=="") {
    $nomzone=$admin322;
    include("access.inc");
    exit();
  }
}
$qtype = TYP_PHOTO;
$bname = 0;
$bemail = 0;
$bcat = 1;
$btitre = 1;
$bcontenu = 1;
$bnouveau = 1;
$qformonly = 0;
$qtitle = $admin323;
$qintro = $admin326.$admin223;
$qseeall = $admin324;
$qwrite = $admin325;
$qcat = $admin327;
$qtitre = $admin328;
$qcontenu = $admin329;
$qnouveau = $admin330;
include ("inc/admin.inc");

?>
