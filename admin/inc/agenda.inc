<?php
/*
    Admin Agenda - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
	v4.0 (06 December 2004)    : initial release by Nicolas Alves
	v4.5.11 (30 November 2005) : changed drtuser[38] by drtuser[37] on test (thanks jja)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "agenda.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[37]=="") {
    $nomzone=$admin624;
    include("access.inc");
    exit();
  }
}
  $qtype = TYP_AGENDA;
  $bname = 1;
  $bemail = 0;
  $bcat = 1;
  $btitre = 0;
  $bcontenu = 1;
  $bnouveau = 0;
  $qformonly = 0;
  $qtitle = $admin625;
  $qintro = $admin626.$admin223;
  $qseeall = $admin627;
  $qwrite = $admin628;
  $qcat = $admin630;
  $qtitre = "";
  $qcontenu = $admin629;
  $qnouveau = "";
  include ("inc/admin.inc");

?>
