<?php
/*
    Admin Blog - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.6.0 (04 June 2007)        : initial release (by Icare)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "blog.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[39]=="") {
    $nomzone=$admin13;
    include("access.inc");
    exit();
  }
}
$qtype = TYP_BLOG;
$bname = 1;
$bemail = 1;
$bcat = 1;
$btitre = 1;
$bcontenu = 1;
$bnouveau = 2;
$qformonly = 0;
$qtitle = $admin771;
$qintro = $admin772.$admin223;
$qseeall = $admin782;
$qwrite = $admin783;
$qcat = $admin794;
$qtitre = $admin784;
$qcontenu = $admin785;
$qnouveau = $admin261;
include ("inc/admin.inc");

?>
