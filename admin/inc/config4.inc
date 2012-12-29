<?php
/*
    Admin Configuration - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v1.0 (30 December 2002)     : initial release
      v1.3 (06 January 2003)      : added site's supervision options
      v1.6 (23 January 2003)      : added news publishing by external sites option
                                    added transition effect between pages (for IE browser only)
                                    added "page loaded in n.nn seconds" option
      v1.7 (28 January 2003)      : added Recommend to a Friend box
      v1.8 (05 February 2003)     : added category for forum
      v1.9 (11 February 2003)     : added Banners service and free box
                                    added Icon themes
      v2.0 (27 February 2003)     : added Meta Tags by Nicolas Alves & Laurent Duveau
                                    added fixed background image option
                                    added advanced photo service
                                    modified slogan and start using it
      v2.1 (10 March 2003)        : color management for the side scroll bar (by Nicolas Alves)
                                    counter theme management (by Nicolas Alves)
      v2.2 (22 April 2003)        : let webmaster decide how to place side boxes (by Nicolas Alves)
                                    left and right articles boxes (by Nicolas Alves)
      v2.3 (27 July 2003)         : added dynamic menu option
                                    added a calendar box (by Nicolas Alves)
                                    added quotations style management (by Nicolas Alves and Isabelle)
                                    added forms style management (by Nicolas Alves)
                                    added user prefs management by cookie
                                    added US date format management
                                    added user news submission option (no more mandatory)
      v2.4 (24 September 2003)    : added "Page loading" popup
                                    added forum summary in home page (last threads)
                                    added Guestbook's favourite message on home page
                                    added homepage's choice of central boxes
                                    config3 renamed to config4
                                    added react to an article option
                                    recycled $texte[3] to Articles mark (was no more used)
                                    added Hide Admin Button (by Nicolas Alves)
                                    added Quick Article Admin Access (by Nicolas Alves)
                                    added number of times an article was read (by Nicolas Alves and Laurent Duveau)
                                    added number of times a forum thread was read (by Nicolas Alves and Laurent Duveau)
                                    added number of times a file was downloaded (by Nicolas Alves and Laurent Duveau)
                                    added new dates formats and created time formats
                                    created shared Config Update script
       v4.0 (06 December 2004)    : clean up in the table syntax,
                                    added alt tags to img and removed border tag for non-linked img (by Isa)
        				                    added page title (by Jean-Mi)
        				                    added multi-admin management (by Nicolas Alves)
       v4.6.0 (15 March 2007)      : added fieldset (by Icare)
                                     added boxmenu name (by Ghazette)
       v4.6.10 (7 September 2009)  : corrected W3C
	   v4.6.19 (30 March 2012)     : add social networks by Saxbar
*/

if (stristr($_SERVER["SCRIPT_NAME"], "config4.inc")) {
  header("location:../index.php");
  die();
}

// FONCTIONS DE MISE EN PAGE /////////////////////////////////////////////////////////////////////////
function legend($legend) {
	return '<legend style="font-weight:bold;margin-left:30px;padding:0 4px;">'.$legend.'</legend>'."\n";
}
//////////////////////////////////////////////////////////////////////////////////////////////////////

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[3]=="") {
    $nomzone=$admin166;
    include("access.inc");
    exit();
  }
}
 if ($regit == 1) {
 include(CONFIG);
 $nom[0] = $nom0; // Nom de l'accueil langue principale
 $nom[1] = $nom1; // Page des téléchargements langue principale
 $nom[2] = $nom2; // Page des images langue principale
 $nom[3] = $nom3; // Page des liens langue principale
 $nom[4] = $nom4; // Boite des articles gauche langue principale
 $nom[5] = $nom5; // Boite spéciale langue principale
 $nom[6] = $nom6; // Sondage langue principale
 $nom[7] = $nom7; // Nouvelles langue principale
 $nom[8] = $nom8; // Compteur langue principale
 $nom[9] = $nom9; // Livre d'or langue principale
 $nom[10] = $nom10; // Nom de l'accueil deuxième langue
 $nom[11] = $nom11; // Page des téléchargements deuxième langue
 $nom[12] = $nom12; // Page des images deuxième langue
 $nom[13] = $nom13; // Page des liens deuxième langue
 $nom[14] = $nom14; // Boite des articles gauche deuxième langue
 $nom[15] = $nom15; // Boite spéciale deuxième langue
 $nom[16] = $nom16; // Sondage deuxième langue
 $nom[17] = $nom17; // Nouvelles deuxième langue
 $nom[18] = $nom18; // Compteur deuxième langue
 $nom[19] = $nom19; // Livre d'or deuxième langue
 $nom[20] = $nom20; // Recherche langue principale
 $nom[21] = $nom21; // Recherche deuxième langue
 $nom[22] = $nom22; // Forum langue principale
 $nom[23] = $nom23; // Forum deuxième langue
 $nom[24] = $nom24; // FAQ langue principale
 $nom[25] = $nom25; // FAQ deuxième langue
 $nom[26] = $nom26; // Statistiques langue principale
 $nom[27] = $nom27; // Statistiques deuxième langue
 $nom[28] = $nom28; // Recommander langue principale
 $nom[29] = $nom29; // Recommander deuxième langue
 $nom[30] = $nom30; // Boite des articles droite langue principale
 $nom[31] = $nom31; // Boite des articles droite deuxième langue
 $nom[32] = $nom32; // Boite Calendrier langue principale
 $nom[33] = $nom33; // Boite Calendrier deuxième langue
 $nom[34] = $nom34; // Boite préférences utilisateur langue principale
 $nom[35] = $nom35; // Boite préférences utilisateur deuxième langue
 $nom[36] = $nom36; // Boite RSS langue principale
 $nom[37] = $nom37; // Boite RSS deuxième langue
 $nom[38] = $nom38; // Boite Newsletter langue principale
 $nom[39] = $nom39; // Boite Newsletter deuxième langue
 $nom[40] = $nom40; // Boite Webmaster - Infos langue principale
 $nom[41] = $nom41; // Boite Webmaster - Infos deuxième langue
 $nom[42] = $nom42; // Blog langue principale
 $nom[43] = $nom43; // Blog deuxième langue
 $nom[44] = $nom44; // Boite Menu langue principale
 $nom[45] = $nom45; // Boite Menu deuxième langue
 $nom[46] = $nom46; // Boite Réseaux sociaux langue principale
 $nom[47] = $nom47; // Boite Réseaux sociaux deuxième langue
 include("inc/confupdt.inc");
 }
include(CONFIG);
  if (is_file ($meskin."confskin.inc")) include ($meskin."confskin.inc");
  else include(CHEMIN.DATAREP."confskin.inc");
$topmess = $admin167;
include(CHEMIN."inc/hpage.inc");
htable($admin167, "100%");
?>
<center>
<div align="center"><p><?php echo $admin168; ?></p><hr />
<a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b>
<hr />
<form name="conf4" action="admin.php?lng=<?php echo $lng; ?>" method="post">
<input type="hidden" name="pg" value="config4" />
<input type="hidden" name="wri" value="<?echo $wri; ?>" />
<input type="hidden" name="regit" value="1" />
<p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin66; ?>"><?php echo $admin66; ?></button><?php echo $boutonright; ?></p>
<div align="center" style="width:514px;" />
<fieldset>
<?php
echo legend($admin70);
?>
<br />
<?php
function SectionName($description, $name0, $value0, $name1, $value1) {
global $flag1, $flag2, $lang;

  echo "<div style=\"width:90%;\">\n<span style=\"float:left;width:180px;text-align:left;vertical-align:center\">&bull; ".$description."</span>\n";
  echo "<div style=\"width:220px;float:left;padding:0px 4px;text-align:right\">\n";
  if (empty($lang[1])) {
    echo "<input class='texte' name=\"".$name0."\" type=\"text\" size=\"26\" value=\"".$value0."\" />";
  }
  else {
    echo "<img src=\"".$flag1."\" width=\"24\" height=\"16\" alt=\"".$lang[0]."\" /> &nbsp;<input class='texte' name=\"".$name0."\" type=\"text\" size=\"26\" value=\"".$value0."\" /><br />";
    echo "<img src=\"".$flag2."\" width=\"24\" height=\"16\" alt=\"".$lang[1]."\" /> &nbsp;<input class='texte' name=\"".$name1."\" type=\"text\" size=\"26\" value=\"".$value1."\" />";
  }
  echo "</div>\n";
	echo "<div style=\"clear:left;padding:4px 8px 4px 0px\"><br /></div>\n";
	echo "</div>\n";
}

echo '<p style="text-align:center">-------------- '.$admin806.' --------------</p><br />';
SectionName($admin71, "nom0", $nom[0], "nom10", $nom[10]);
SectionName($admin72, "nom7", $nom[7], "nom17", $nom[17]);
SectionName($admin780, "nom42", $nom[42], "nom43", $nom[43]);
SectionName($admin74, "nom2", $nom[2], "nom12", $nom[12]);
SectionName($admin73, "nom1", $nom[1], "nom11", $nom[11]);
SectionName($admin75, "nom3", $nom[3], "nom13", $nom[13]);
SectionName($admin207, "nom24", $nom[24], "nom25", $nom[25]);
SectionName($admin76, "nom9", $nom[9], "nom19", $nom[19]);
SectionName($admin164, "nom22", $nom[22], "nom23", $nom[23]);
SectionName($admin213, "nom26", $nom[26], "nom27", $nom[27]);
echo '<p style="text-align:center">-------------- '.strtoupper($admin346).' --------------</p><br />';
SectionName($admin880." :", "nom44", $nom[44], "nom45", $nom[45]);
SectionName($admin77, "nom4", $nom[4], "nom14", $nom[14]);
SectionName($admin336, "nom30", $nom[30], "nom31", $nom[31]);
SectionName($admin78, "nom5", $nom[5], "nom15", $nom[15]);
SectionName($admin79, "nom6", $nom[6], "nom16", $nom[16]);
SectionName($admin80, "nom8", $nom[8], "nom18", $nom[18]);
SectionName($admin163, "nom20", $nom[20], "nom21", $nom[21]);
SectionName($admin245, "nom28", $nom[28], "nom29", $nom[29]);
SectionName($admin448, "nom32", $nom[32], "nom33", $nom[33]);
SectionName($admin449, "nom34", $nom[34], "nom35", $nom[35]);
SectionName($admin548, "nom38", $nom[38], "nom39", $nom[39]);
SectionName($admin610, "nom36", $nom[36], "nom37", $nom[37]);
SectionName($admin853, "nom40", $nom[40], "nom41", $nom[41]);
SectionName($admin959.' :', "nom46", $nom[46], "nom47", $nom[47]);

?>
</fieldset>
<p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin66; ?>"><?php echo $admin66; ?></button><?php echo $boutonright; ?></p>
</form>
<hr />
<a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b>
</div>
</center>
<?php
btable();
include(CHEMIN."inc/bpage.inc");

?>
