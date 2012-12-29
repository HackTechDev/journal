<?php
/*
    Admin extra Free Boxes - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v2.4 (24 September 2003) : initial release
      v4.0 (06 December 2004)  : added multi-admin management (by Nicolas Alves)
      v4.6.15 (30 June 2011)   : updated data[] for group management (by Icare)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "freebox3.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[26]=="") {
    $nomzone=$admin270."3";
    include("access.inc");
    exit();
  }
}
$qtype = TYP_FREEBOX3;
$bname = 0;
$bemail = 0;
$bcat = 0;
$btitre = 1;
$bcontenu = 1;
$bnouveau = 0;
$qtitle = $admin501;
$qintro = $admin272;
$qseeall = $admin503;
$qwrite = "";
$qcat = "";
$qtitre = $admin274;
$qcontenu = $admin273;
$qnouveau = "";
$qformonly = 2;
$dbwork = SelectDBFieldsByStatus(SelectDBFieldsByType(ReadDBFields(DOCID),$qtype),"a");
 if (count($dbwork) == 0) {
  $data[0] = $qtype;
  $data[1] = "";
  $data[2] = "a";
  $data[3] = "";
  $data[4] = "";
  $data[5] = $user[0];
  $data[6] = $user[1];
  $data[7] = "";
  $data[8] = "";
  $data[9] = "";
  $data[10] = "";
  $data[11] = "";
  $data[12] = "";
  $data[13] = "";
  $data[14] = "";
  $data[15] = "";
  $data[16] = ""; /// added with groups
  $data[17] = ""; /// added with groups
  ActionOnFields("add",$data);
  $id = ReadCounter(NEXTID);
}
else {
  $id = $dbwork[0][1];
}
include ("inc/admin.inc");

?>
