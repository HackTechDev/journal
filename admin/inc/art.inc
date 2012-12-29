<?php
/*
    Admin Articles - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.7 (28 January 2003)   : added $bnouveau and $qnouveau
      v2.2 (22 April 2003)     : added management of two articles boxes (by Nicolas Alves)
      v2.4 (24 September 2003) : created $typ_[name] variables
      V4.0 (06 December 2004)  : added multi-admin management (by Nicolas Alves)
      v4.6.12 (01 May 2010) : corrected #318
*/

if (stristr($_SERVER["SCRIPT_NAME"], "art.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[15]=="") {
    $nomzone=$admin5;
    include("access.inc");
    exit();
  }
}
$qtype = TYP_ART;
$bname = 1;
$bemail = 1;
$bcat = 1;
$btitre = 1;
$bcontenu = 1;
if ($serviz[3] == "on" && $serviz[22] == "on") {
  $bnouveau = 1;
}
else {
  $bnouveau = 0;
}
$qformonly = 0;
$qtitle = $admin39;
$qintro = $admin222.$admin223;
$qseeall = $admin29;
$qwrite = $admin30;
$qcat = $admin35;
$qtitre = $admin36;
$qcontenu = $admin37;
$qnouveau = "";
include ("inc/admin.inc");

?>
