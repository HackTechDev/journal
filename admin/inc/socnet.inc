<?php
/*
    Social Networks - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
     v4.6.19 (30 March 2012) :  initial release by Saxbar
*/

if (stristr($_SERVER['SCRIPT_NAME'], 'socnet.inc')) {
    header('location:../index.php');
    die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
    include REDACREP.$userprefs[1].INCEXT;
    if ($drtuser[44] == '') {
        $nomzone = $admin952;
        include 'access.inc';
        exit();
    }
}

$qtype     = TYP_SOCNET;
$bname     = 1;
$bemail    = 0;
$bcat      = 0;
$btitre    = 1;
$bcontenu  = 1;
$bnouveau  = 1;
$qformonly = 0;
$qtitle    = $admin945;
$qintro    = $admin946.$admin223;
$qseeall   = $admin947;
$qwrite    = $admin948;
$qcat      = '';
$qtitre    = $admin949;
$qcontenu  = $admin951;
$qnouveau  = $admin950;

include 'inc/admin.inc';
?>