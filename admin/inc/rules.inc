<?php
/*
    Admin Forum rules - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.6.0 (04 June 2007)      : initial release by Icare
*/

if (stristr($_SERVER["SCRIPT_NAME"], "rules.inc")) {
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
$qtype = TYP_RULES;
$bname = 0;
$bemail = 0;
$bcat = 0;
$btitre = 0;
$bcontenu = 1;
$bnouveau = 0;
$qformonly = 2;
$qtitle = $admin798;
$qintro = $admin866;
$qseeall = "";
$qwrite = "";
$qcat = "";
$qtitre = "";
$qcontenu = "[ <a href='admin.php?lng=".$lng."&amp;pg=config7'>".$admin799."</a> ]<br /><br />".$admin867;
$qnouveau = "";
$dbwork = SelectDBFieldsByStatus(SelectDBFieldsByType(ReadDBFields(DOCID),$qtype),"a");
 if (count($dbwork) == 0) {
  include(DBRULES);
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
  $data[11] = stripslashes($rule1);
  $data[12] = stripslashes($rule2);
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
