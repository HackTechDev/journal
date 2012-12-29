<?php
/*
    Admin Forum - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.7 (28 January 2003)   : added $bnouveau and $qnouveau
      v1.8 (05 February 2003)  : changed title's text (was wrong)
                                 added category for forum
                                 corrected hide e-mail bug
      v2.4 (24 September 2003) : created $typ_[name] variables
      v4.0 (06 December 2004)  : added multi-admin management (by Nicolas Alves)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "forum.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[23]=="") {
    $nomzone=$admin9;
    include("access.inc");
    exit();
  }
}
$qtype = TYP_FORUM;
$bname = 1;
$bemail = 1;
 if ($serviz[18] == "on") {
 $bcat = 1;
}
else {
 $bcat = 0;
}
$btitre = 1;
$bcontenu = 1;
$bnouveau = 2;
$qformonly = 0;
$qtitle = $admin210;
$qintro = $admin225.$admin223;
$qseeall = $admin172;
$qwrite = "";
$qcat = "";
$qtitre = $admin258;
$qcontenu = $admin174;
$qnouveau = $admin261;
include ("inc/admin.inc");

?>
