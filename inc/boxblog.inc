<?php
/*
    Last Blogss - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.6.0 (04 June 2007)         : initial release by Icare
      v4.6.10  (7 September 2009)   : corrected #285
	  v4.6.20 (24 May 2012)         : added $topmess to btable (by Saxbar)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "boxblog.inc")) {
  header("location:../index.php");
  die();
}
define('PATH_PGEDITOR', 'inc/pgeditor/');		//Chemin relatif de l'éditeur (ne pas modifier)
define('PATH_CONFIG_PGEDITOR','inc/config_pgeditor_guppy/'); //Chemin relatif du fichier de configuration de l'éditeur
include CHEMIN.PATH_PGEDITOR.'pgeditor.php';    //Fichier contenant toutes les fonctions nécessaires pour intégration de l'éditeur
include CHEMIN.PATH_PGEDITOR.'syntaxcolor/syntaxcolor.php'; //Coloration syntaxique

if ($serviz[53] == "on" && $site[31] > 0) {
    if ($site[31] == 1) {
        $topmess = $web389;
    }
    else {
        $topmess = $web2." ".$site[31]." ".$web382;
    }
    if ($members[0] == 'on' && $members[15] == 'on' && $userprefs[1] == '') {
        htable($topmess,"100%");
        echo "<p align=\"center\">".$web342."</p><br />";
        echo "<p align=\"center\">[ <a href=\"".CHEMIN."user.php?lng=".$lng."\">".$web343."</a> ]</p><br />";
        btable($topmess);
    } else {
        $indexblog = 1;
        include("inc/blog.inc");
    }
}
