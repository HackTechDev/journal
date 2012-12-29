<?php
/*
    Admin Links - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.7 (28 January 2003)   : added $bnouveau and $qnouveau
      v2.4 (24 September 2003) : created $typ_[name] variables
      v4.0 (06 December 2004)  : added multi-admin management (by Nicolas Alves)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "links.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[20]=="") {
    $nomzone=$admin10;
    include("access.inc");
    exit();
  }
}
$qtype = TYP_LINKS;
$bname = 0;
$bemail = 0;
$bcat = 1;
$btitre = 1;
$bcontenu = 1;
$bnouveau = 1;
$qformonly = 0;
$qtitle = $admin106;
$qintro = $admin107.$admin223;
$qseeall = $admin108;
$qwrite = $admin109;
$qcat = $admin250;
$qtitre = $admin110;
$qcontenu = $admin112;
$qnouveau = $admin111;
include ("inc/admin.inc");

?>
