<?php
/*
    Sample External Page - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    This is a sample external PHP script that integrates with GuppY

    Version History :
      v2.3 (27 July 2003)        : initial release (by Isabelle)
      v3.0 (25 February 2004)    : moved to pages/ directory
      v4.0 (06 December 2004)    : Added text in many languages (by Jean-Mi)
	    v4.5 (27 April 2005)       : Added page title (thanks Ricsen)
	    v4.6.0 (20 november 2006)  : corrected $topmess in htable() (by Ghazette)
	    v4.6.6 (14 April 2008)     : corrected bad position of include hpage.inc (by Icare)
*/

header("Pragma: no-cache");
define("CHEMIN", "../");
include(CHEMIN."inc/includes.inc");
if ($lng == $lang[0]) {
  $topmess = "Titre de la fenêtre en langue principale";
}
else {
  $topmess = "Window title in secondary language";
}
include(CHEMIN."inc/hpage.inc");

// Si vous voulez mettre une icône du répertoire img en tête de page:
// If you want to put an icon from img directory on top of the page:
$topmess = '<img src="'.CHEMIN.'img/my_icon.gif" align="right" width="32" height="32" border="0" alt="My icon">'.$topmess;
if ($lng == $lang[0]) {
htable($topmess, "100%"); // Titre en langue principale
?>

<!-- Début du texte HTML dans la langue principale -->

<br />
Texte HTML dans la langue principale <br />
Text HTML in the principal language <br />
HTML-Text in der Hauptsprache <br />
Texto HTML en la lengua principal <br />
Testo HTML nella lingua principale <br />
Tekst HTML in de belangrijkste taal <br />
Texto HTML na língua principal <br />
<br />

<!-- Fin du texte HTML en langue principale -->

<?php
}
else {
htable($topmess, "100%"); // Titre en langue secondaire
?>

<!-- Début du texte HTML dans la langue secondaire -->

<br />
Texte HTML dans la langue secondaire <br />
Text HTML in the secondary language <br />
HTML-Text in der sekundären Sprache <br />
Texto HTML en la lengua secundaria <br />
Testo HTML nella lingua secondaria <br />
Tekst HTML in de ondergeschikte taal <br />
Texto HTML na língua secundária <br />
<br />

<!-- Fin du texte HTML en langue secondaire -->

<?php
}
btable();
include(CHEMIN."inc/bpage.inc");
?>
