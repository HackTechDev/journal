<?php
/*
    Admin Download rules - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.6.0 (04 June 2007)      : initial release by Icare
*/

if (stristr($_SERVER["SCRIPT_NAME"], "disclaim.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[19]=="") {
    $nomzone=$admin18;
    include("access.inc");
    exit();
  }
}
$qtype = TYP_DISCLAIM;
$bname = 0;
$bemail = 0;
$bcat = 0;
$btitre = 0;
$bcontenu = 1;
$bnouveau = 0;
$qformonly = 2;
$qtitle = $admin870;
$qintro = $admin871;
$qseeall = "";
$qwrite = "";
$qcat = "";
$qtitre = "";
$qcontenu = $admin872;
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
  include(CHEMIN."pages/disclaim.php");
  echo $fr_disclaim."<br />";
  $data[11] = $fr_disclaim;
  $data[12] = $en_disclaim;
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
