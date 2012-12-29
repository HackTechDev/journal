<?php
/*
    Admin Homepage - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.7 (28 January 2003)   : added $bnouveau and $qnouveau
      v1.9 (11 February 2003)  : added $data[13] and $data[14] (forgot before!)
      v2.4 (24 September 2003) : created $typ_[name] variables
      v4.0 (06 December 2004)  : added multi-admin management (by Nicolas Alves)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "homepg.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[13]=="") {
    $nomzone=$admin8;
    include("access.inc");
    exit();
  }
}
$qtype = TYP_HOMEPG;
$bname = 0;
$bemail = 0;
$bcat = 0;
$btitre = 0;
$bcontenu = 1;
$bnouveau = 0;
$qformonly = 2;
$qtitle = $admin103;
$qintro = $admin104;
$qseeall = "";
$qwrite = "";
$qcat = "";
$qtitre = "";
$qcontenu = $admin105;
$qnouveau = "";
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
  ActionOnFields("add",$data);
  $id = ReadCounter(NEXTID);
}
else {
  $id = $dbwork[0][1];
}
include ("inc/admin.inc");

?>
