<?php
/*
    General Blogs script - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2008 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.6.0 (04 June 2007)        : initial release (by Icare)
      v4.6.9 (25 December 2008)    : added management of the non-existent pages
      v4.6.11 (11 December 2009)   : added test userprefs (by Icare)
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");
define('PATH_PGEDITOR', 'inc/pgeditor/');		//Chemin relatif de l'éditeur (ne pas modifier)
define('PATH_CONFIG_PGEDITOR','inc/config_pgeditor_guppy/'); //Chemin relatif du fichier de configuration de l'éditeur
include CHEMIN.PATH_PGEDITOR.'pgeditor.php';    //Fichier contenant toutes les fonctions nécessaires pour intégration de l'éditeur
include CHEMIN.PATH_PGEDITOR.'syntaxcolor/syntaxcolor.php'; //Coloration syntaxique

if ($serviz[53] != "on") {
  exit($web143);
}
if ($userprefs[3] == "" || $userprefs[3] == "LR") $userprefs[3] = "L";
$widepage = $serviz[58];
$txtmess = (($lng == $lang[0])? $nom[42] : $nom[43]);
if (!empty($datej) || !empty($date)) $txtmess .= " - ".$web399;
//else $txtmess .= " - ".$web383;
$topmess = strip_tags($txtmess);
$indexblog = 0;
  if ($members[0]=="on" && $userprefs[1]=="" && $members[15]=="on") {
    if ($page[9] != "") {
    $topmess = "<img src=\"".CHEMIN."inc/img/icons/".$page[9]."/blog.gif\" align=\"right\" width=\"32\" height=\"32\" alt=\"blog.gif\" />".$topmess;
    }
    include("inc/hpage.inc");
    htable($topmess,"100%");
    echo "<p align=\"center\">".$web342."</p><br />";
    echo "<p align=\"center\">[ <a href=\"".CHEMIN."user.php?lng=".$lng."\">".$web343."</a> ]</p><br />";
    btable();
    include("inc/bpage.inc");
    }
    else {
include("inc/blog.inc");
}
?>
