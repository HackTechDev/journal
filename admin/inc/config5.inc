<?php
/*
    Admin Configuration - GuppY PHP Script - vversion 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.3 (06 January 2003)   : moved Showing of users' news ($site[5]) configuration
                                   from General config
                                 added site's supervision options
      v1.6 (23 January 2003)   : added news publishing by external sites option
                                 added transition effect between pages (for IE browser only)
                                 added "page loaded in n.nn seconds" option
      v1.7 (28 January 2003)   : added Recommend to a Friend box
                                 added call to UpdateDBnews() for service[16] update
      v1.8 (05 February 2003)  : added category for forum
      v1.9 (11 February 2003)  : category for forum presentation slighly changed for showing better
                                   that it is a sub option of Forum area
                                 added Banners service and free box
                                 added Icon themes
      v2.0 (27 February 2003)  : added Meta Tags by Nicolas Alves & Laurent Duveau
                                 added fixed background image option
                                 added advanced photo service
                                 modified slogan and start using it
      v2.1 (10 March 2003)     : color management for the side scroll bar (by Nicolas Alves)
                                 counter theme management (by Nicolas Alves)
      v2.2 (22 April 2003)     : removed boxes services (now in a dedicated option)
      v2.3 (27 July 2003)      : added dynamic menu option
                                 moved number of items per service from config2 to config4
                                 added a calendar box (by Nicolas Alves)
                                 added quotations style management (by Nicolas Alves and Isabelle)
                                 added forms style management (by Nicolas Alves)
                                 added user prefs management by cookie
                                 added US date format management
                                 added user news submission option (no more mandatory)
      v2.4 (24 September 2003) : added "Page loading" popup
                                 added forum summary in home page (last threads)
                                 moved homepage parametrization from General config to Services config
                                 added Guestbook's favourite message on home page
                                 added homepage's choice of central boxes
                                 config4 renamed to config5
                                 added react to an article option
                                 recycled $texte[3] to Articles mark (was no more used)
                                 added Hide Admin Button (by Nicolas Alves)
                                 added Quick Article Admin Access (by Nicolas Alves)
                                 added number of times an article was read (by Nicolas Alves and Laurent Duveau)
                                 added number of times a forum thread was read (by Nicolas Alves and Laurent Duveau)
                                 added number of times a file was downloaded (by Nicolas Alves and Laurent Duveau)
                                 upgraded eMailTo() function to accept additional specific e-mailing according to providers
                                 added new dates formats and created time formats
                                 created shared Config Update script
      v3.0 (25 February 2004)  : added Newsletter module
      v4.0 (06 December 2004)  : added user's guestbook and user's post submit option to admin (by Jean-Mi)
    		                     added optionnal writter, and editor choice (by Icare)
        				         added multi-admin management and quick admin options (by Nicolas Alves)
        				         added page title (by Jean-Mi)
        				         added agenda-planner option (by Nicolas Alves)
	  v4.5 (22 April 2005)       : changed editor options, ready for other editors (by Icare)
	  v4.5.4 (01 September 2005) : made ready for another editor (by Icare)
	  v4.6.0 (15 March 2007)     : made ready for another editor  (by djchouix)
	  v4.6.2 (10 July 2007)      : added mail supervision for comments on blog (by Icare)
	  v4.6.3 (30 August 2007)    : added adminsitrator validation for reactions to articles and comments on blog (by Icare)
	  v4.6.5 (10 November 2007)  : corrected bad $$serviz[36] for newsletter, thanks hpsam
	                               set pseudo webmaster to space if empty (by Icare)
	  v4.6.6 (06 January 2008)   : corrected $serviz31 (by Icare)
	  v4.6.9 (25 December 2008)  : added $serviz[62] to control the function To recommend ON/OFF #20
      v4.6.10(07 September 2009)    : corrected W3C
	  v4.6.17(21 October 2011)   : changed editors options (by Jchouix)
	  v4.6.18(09 February 2012)  : added $supervision10 (thanks tonton_christian)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "config5.inc")) {
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
  if ($drtuser[4]=="") {
    $nomzone=$admin169;
    include("access.inc");
    exit();
  }
}

if (!isset($serviz[51])) $serviz[51] = ANTISPAM_COUNT;
if (!isset($serviz[52])) $serviz[52] = ANTISPAM_DELAY;

if ($regit == 1) {
  include(CONFIG);
  $site[5] = $site5; // Activation des news ou pas
  $site[27] = $site27; // Temps d'attente popup postage
  $site[28] = $site28; // Barre de progression attente popup postage
  $site[30] = $site30; // Activation du blog ou pas

  $texte[3] = $texte3; // Puce articles

  $serviz[0] = "on"; //  Citations, service désactivable par boite
  $serviz[1] = $serviz1; // Choix page Accueil-Blog ON / OFF
  $serviz[2] = $serviz2; // Nb de news / page
  $serviz[4] = $serviz4; // Nb de téléchargements / page
  $serviz[5] = $serviz5; // Nb de liens / page
  $serviz[6] = $serviz6; // Nb de FAQ / page
  $serviz[7] = $serviz7; // Nb de messages Guestbook / page
  $serviz[8] = $serviz8; // Nouvelles ON / OFF
  $serviz[9] = $serviz9; // Photos ON / OFF
  $serviz[10] = $serviz10; // Téléchargements ON / OFF
  $serviz[11] = $serviz11; // Liens ON / OFF
  $serviz[12] = $serviz12; // Livre d'or ON / OFF
  $serviz[13] = $serviz13; // Forum ON / OFF
  $serviz[14] = $serviz14; // FAQ ON / OFF
  $serviz[15] = $serviz15; // Statistiques ON / OFF
  $serviz[16] = $serviz16; // Publication Nouvelles RSS ON / OFF
  $serviz[17] = $serviz17; // Nb de messages Forum / page
  // Catégories Forum ON / OFF transféré dans config7
  $serviz[19] = "on"; //  Bannières, service désactivable par boite
  $serviz[20] = $serviz20; // Nb de messages Thread / page
  $serviz[21] = $serviz21; // Photorama avancé ON /OFF
  $serviz[25] = $serviz25; // Menu dynamique Articles gauche
  $serviz[26] = $serviz26; // Menu dynamique Articles droit
  $serviz[27] = $serviz27; // Billets RSS des amis ON / OFF
  $serviz[29] = $serviz29; // Réactions aux articles ON / OFF / Ok Admin
  $serviz[30] = $serviz30; // Nb Réactions aux articles / page
  $serviz[31] = ($serviz31 == "")? " " : trim($serviz31); // Pseudo préférences webmaster
  $serviz[32] = $serviz32; // Accès à l'administration rapide
  $serviz[33] = $serviz33; // Compteur de lecture Articles
  // Compteur de lecture Threads Forum transféré dans config7
  $serviz[35] = $serviz35; // Compteur de Nb de téléchargements
  $serviz[36] = $serviz36; // Newsletter ON / OFF / TEST
  $serviz[37] = $serviz37; // Nb de news / articles publiés
  $serviz[39] = $serviz39; // Durée Cache RSS
  $serviz[40] = $serviz40; // Publication dans le livre d'or
  $serviz[41] = $serviz41; // Publication dans le forum
  $serviz[42] = $serviz42; // Option rédacteur
  $serviz[43] = $serviz43; // Avatar préférences webmaster
  $serviz[45] = $serviz45; // Masquer l'icône Admin
  $serviz[46] = $serviz46; // Nb de messages Agenda / page
  $serviz[47] = $serviz47; // Agenda ON / OFF
  $serviz[48] = $serviz48; // Nb de messages maximum dans Tinymessage
  $serviz[49] = $serviz49; // Choix éditeur IE /compatible intégré ou popup
  $serviz[50] = $serviz50; // Nb maxi de fichiers dans data/error
  $serviz[51] = max(50, $serviz51); // Nb maxi de lignes dans l'anti-spam
  $serviz[52] = max(10, $serviz52); // Durée maxi de validité du code anti-spam
  $serviz[53] = $serviz53; // Blog ON / OFF
  $serviz[54] = $serviz54; // Publication Blog RSS ON / OFF
  $serviz[55] = $serviz55; // Nb de Blogs / page
  $serviz[56] = $serviz56; // Nb de blogs publiés
  $serviz[57] = $serviz57; // Commentaires sur Blog ON /OFF / OK Admin
  $serviz[58] = $serviz58; // Blog pleine page ON /OFF
  $serviz[59] = $serviz59; // Menu dynamique Blog
  $serviz[60] = $serviz60; // Publication Articles RSS ON / OFF
  $serviz[61] = $serviz61; // Nb billets récents-commentaires / page
  $serviz[62] = $serviz62; // Recommander ON/OFF
  $serviz[63] = $serviz63; // Largeur de l'éditeur

  $supervision[0] = $supervision0; // e-mail compteur
  $supervision[1] = $supervision1; // incrément de compteur pour e-mail
  $supervision[2] = $supervision2; // e-mail publication nouvelle
  $supervision[3] = $supervision3; // e-mail publication livre d'or
  $supervision[4] = $supervision4; // e-mail publication forum
  $supervision[5] = $supervision5; // Type d'e-mail PHP
  $supervision[6] = $supervision6; // e-mail réagir aux articles
  $supervision[7] = $supervision7; // e-mail inscription ou résiliation Newsletter
  $supervision[8] = $supervision8; // e-mail publication blog
  $supervision[9] = $supervision8; // e-mail commentaire blog
  $supervision[10] = $supervision10; // e-mail publication forum aux modérateurs ON/OFF   

  include("inc/confupdt.inc");
  include(CHEMIN.INCREP."funcrss.php");
  UpdateDBnews();
  UpdateDBblog();
  UpdateDBart();
}

$mailer = array();
$dossier = opendir(CHEMIN."inc/mail/");
while ($fichier = readdir($dossier)) {
  if (is_file(CHEMIN."inc/mail/".$fichier)) {
    $basefic = basename($fichier);
    $path_parts = substr($basefic,strrpos($basefic,".")+1);
    if ($path_parts == "inc") {
      $mailer[] = substr($basefic,0,strlen($basefic)-4);
    }
  }
}
closedir($dossier);
@sort($mailer);

$progbartheme = array();
$dossier = opendir(CHEMIN."inc/img/progbar/");
while ($fichier = readdir($dossier)) {
  if (is_file(CHEMIN."inc/img/progbar/".$fichier)) {
    $path_parts = basename($fichier);
    $path_parts = substr($path_parts,strrpos($path_parts,".")+1);
    if (IsImage($path_parts)) {
      $progbartheme[] = $fichier;
    }
  }
}
closedir($dossier);
@sort($progbartheme);

include(CONFIG);
if (is_file ($meskin."confskin.inc")) include ($meskin."confskin.inc");
else include (CHEMIN.DATAREP."confskin.inc");
$topmess = $admin176;
include(CHEMIN."inc/hpage.inc");
htable($admin176, "100%");
?>
<div align="center">
<p><?php echo $admin177; ?></p><hr />
<a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b>
<hr /></div>
<form name="conf5" action="admin.php?lng=<?php echo $lng; ?>" method="post">
<input type="hidden" name="pg" value="config5" />
<input type="hidden" name="regit" value="1" />
<div align="center" style="width:514px;margin-left:auto;margin-right:auto;">
<p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin66; ?>"><?php echo $admin66; ?></button><?php echo $boutonright; ?></p>
<fieldset>
<?php
echo legend($admin810);
?>
<br />
<table cellspacing="0" cellpadding="2" align="center" border="0" width="96%" summary="">
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin714.', '.strtolower($admin850); ?></p></td><td width="180"><p>
<input class="texte" type="text" name="serviz31" size="16" value="<?php echo trim($serviz[31]); ?>" /></p></td></tr>
<tr style="text-align:left;"><td><p style="padding-left:25px;"><?php echo $admin482; ?></p></td><td><p><input type="checkbox" name="serviz32" <?php if ($serviz[32]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;"><td><p style="padding-left:25px;"><?php echo $admin709; ?></p></td><td><p><select name="serviz49">
<?php
echo "<option value=\"\""; if ($serviz[49] == "") {echo " selected='selected'";} echo "> ".$web314."</option>";     // éditeur non wysiwyg
echo "<option value=\"in\""; if ($serviz[49] == "in") {echo " selected='selected'";} echo "> ".$web313."</option>"; // editeur wysiwyg
?>
</select></p></td></tr>
<tr style="text-align:left;"><td><p style="padding-left:25px;"><?php echo $admin941; ?></p></td><td width="180"><p>
<input class="texte" type="text" name="serviz63" size="6" value="<?php echo trim($serviz[63]); ?>" /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin481; ?></p></td><td><p><input type="checkbox" name="serviz45" <?php if ($serviz[45]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin711; ?></p></td><td><p><input type="checkbox" name="serviz42" <?php if ($serviz[42]) echo "checked='checked'"; ?> /></p></td></tr>
</table>
</fieldset>
<br />
<fieldset>
<?php
echo legend($admin217);
?>
<br />
<table cellspacing="0" cellpadding="2" border="0" align="center" width="96%" summary="">
<tr style="text-align:left;">
  <td><p>&bull;<?php echo $admin71; ?></p></td>
  <td><p><select name="serviz1">
<option value="on"<?php if ($serviz[1] == "on") { echo " selected='selected'"; } ?>><?php echo $admin897; ?></option>
<option value=""<?php if ($serviz[1] == "") { echo " selected='selected'"; } ?>><?php echo $admin770; ?></option>
</select></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin780; ?></p></td><td><p><input type="checkbox" name="serviz53" <?php if ($serviz[53]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;"><td><p style="padding-left:25px;"><?php echo $admin777; ?></p></td><td><p><input type="checkbox" name="serviz58" <?php if ($serviz[58]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;">
  <td nowrap="nowrap"><p style="padding-left:25px;"><?php echo $admin787; ?></p></td>
  <td><p><select name="serviz59">
<option value="0"<?php if ($serviz[59] == "0") { echo " selected='selected'"; } ?>><?php echo $admin397; ?></option>
<option value="1"<?php if ($serviz[59] == "1") { echo " selected='selected'"; } ?>><?php echo $admin398; ?></option>
<option value="2"<?php if ($serviz[59] == "2") { echo " selected='selected'"; } ?>><?php echo $admin504; ?></option>
<option value="3"<?php if ($serviz[59] == "3") { echo " selected='selected'"; } ?>><?php echo $admin621; ?></option>
</select></p></td></tr>
<tr style="text-align:left;">
  <td><p style="padding-left:25px;"><?php echo $admin775; ?></p></td>
  <td><p><select name="site30">
<option value="2"<?php if ($site[30] == "2") { echo " selected='selected'"; } ?>><?php echo $web314; ?></option>
<option value="0"<?php if ($site[30] == "0") { echo " selected='selected'"; } ?>><?php echo $admin55; ?></option>
<option value="1"<?php if ($site[30] == "1") { echo " selected='selected'"; } ?>><?php echo $admin61; ?></option>
</select></p></td></tr>
<tr style="text-align:left;">
  <td><p style="padding-left:25px;"><?php echo $admin774; ?></p></td>
  <td><p><select name="serviz57">
<option value=""<?php if ($serviz[57] == "") { echo " selected='selected'"; } ?>><?php echo $web314; ?></option>
<option value="on"<?php if ($serviz[57] == "on") { echo " selected='selected'"; } ?>><?php echo $admin55; ?></option>
<option value="ok"<?php if ($serviz[57] == "ok") { echo " selected='selected'"; } ?>><?php echo $admin61; ?></option>
</select></p></td></tr>
<tr style="text-align:left;"><td><p style="padding-left:25px;"><?php echo $admin781; ?></p></td><td><p><input type="checkbox" name="serviz54" <?php if ($serviz[54]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin602.' ('.$web402.') :'; ?></p></td><td><p><input type="checkbox" name="serviz27" <?php if ($serviz[27]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin5; ?> :</p></td><td>&nbsp;</td></tr>
<tr style="text-align:left;">
  <td nowrap="nowrap"><p style="padding-left:25px;"><?php echo $admin77; ?></p></td>
  <td width="180"><p><select name="serviz25">
<option value="0"<?php if ($serviz[25] == "0") { echo " selected='selected'"; } ?>><?php echo $admin397; ?></option>
<option value="1"<?php if ($serviz[25] == "1") { echo " selected='selected'"; } ?>><?php echo $admin398; ?></option>
<option value="2"<?php if ($serviz[25] == "2") { echo " selected='selected'"; } ?>><?php echo $admin504; ?></option>
<option value="3"<?php if ($serviz[25] == "3") { echo " selected='selected'"; } ?>><?php echo $admin621; ?></option>
</select></p></td></tr>
<tr style="text-align:left;">
  <td nowrap="nowrap"><p style="padding-left:25px;"> <?php echo $admin336; ?></p></td>
  <td><p><select name="serviz26">
<option value="0"<?php if ($serviz[26] == "0") { echo " selected='selected'"; } ?>><?php echo $admin397; ?></option>
<option value="1"<?php if ($serviz[26] == "1") { echo " selected='selected'"; } ?>><?php echo $admin398; ?></option>
<option value="2"<?php if ($serviz[26] == "2") { echo " selected='selected'"; } ?>><?php echo $admin504; ?></option>
<option value="3"<?php if ($serviz[26] == "3") { echo " selected='selected'"; } ?>><?php echo $admin621; ?></option>
</select></p></td></tr>
<tr style="text-align:left;">
  <td nowrap="nowrap"><p style="padding-left:25px;"><?php echo "$admin480 &nbsp;&nbsp;<input name=\"puce\" class=\"texte\" type=\"text\" style=\"width: 18px; font-weight: bold\" value=\"&nbsp;".$texte[3]."\" />&nbsp;"; ?></p></td>
  <td><p><select name="texte3" style="width: 50px; font-weight: bold">
<?php
$carspec = array("&nbsp;","!","#","*","+","-",".",":","&lt;","=","&gt;","@","^","~",
"&deg;","&curren;","&middot;","&ordm;","&plusmn;","&raquo;","&times;","&bull;");
for ($i = 0; $i < count($carspec); $i++) {
  $selected = ($texte[3] == $carspec[$i] ? ' selected="selected"' : "" );
  echo "<option value=\"".htmlentities($carspec[$i])."\"".$selected.">".$carspec[$i]."</option>\n";
}
?>
</select></p></td></tr>
<tr style="text-align:left;">
  <td><p style="padding-left:25px;"><?php echo $admin472; ?></p></td>
  <td><p><select name="serviz29">
<option value=""<?php if ($serviz[29] == "") { echo " selected='selected'"; } ?>><?php echo $web314; ?></option>
<option value="on"<?php if ($serviz[29] == "on") { echo " selected='selected'"; } ?>><?php echo $admin55; ?></option>
<option value="ok"<?php if ($serviz[29] == "ok") { echo " selected='selected'"; } ?>><?php echo $admin61; ?></option>
</select></p></td></tr>
<tr style="text-align:left;"><td><p style="padding-left:25px;"><?php echo $admin483; ?></p></td><td><p><input type="checkbox" name="serviz33" <?php if ($serviz[33]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;"><td><p style="padding-left:25px;"><?php echo $admin795; ?></p></td><td><p><input type="checkbox" name="serviz60" <?php if ($serviz[60]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin72; ?></p></td><td><p><input type="checkbox" name="serviz8" <?php if ($serviz[8]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;">
  <td><p style="padding-left:25px;"><?php echo $admin59; ?></p></td>
  <td><p><select name="site5">
<option value="2"<?php if ($site[5] == "2") { echo " selected='selected'"; } ?>><?php echo $web314; ?></option>
<option value="0"<?php if ($site[5] == "0") { echo " selected='selected'"; } ?>><?php echo $admin55; ?></option>
<option value="1"<?php if ($site[5] == "1") { echo " selected='selected'"; } ?>><?php echo $admin61; ?></option>
</select></p></td></tr>
<tr style="text-align:left;"><td><p style="padding-left:25px;"><?php echo $admin242; ?></p></td><td><p><input type="checkbox" name="serviz16" <?php if ($serviz[16]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin74; ?></p></td><td><p><input type="checkbox" name="serviz9" <?php if ($serviz[9]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;"><td><p style="padding-left:25px;"><?php echo $admin331; ?></p></td><td><p><input type="checkbox" name="serviz21" <?php if ($serviz[21]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin73; ?></p></td><td><p><input type="checkbox" name="serviz10" <?php if ($serviz[10]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;"><td><p style="padding-left:25px;"><?php echo $admin484; ?></p></td><td><p><input type="checkbox" name="serviz35" <?php if ($serviz[35]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin75; ?></p></td><td><p><input type="checkbox" name="serviz11" <?php if ($serviz[11]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin207; ?></p></td><td><p><input type="checkbox" name="serviz14" <?php if ($serviz[14]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin76; ?></p></td><td><p><input type="checkbox" name="serviz12" <?php if ($serviz[12]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;">
  <td><p style="padding-left:25px;"><?php echo $admin454; ?></p></td>
  <td><p><select name="serviz40">
<option value=""<?php if ($serviz[40] == "") { echo " selected='selected'"; } ?>><?php echo $admin55; ?></option>
<option value="on"<?php if ($serviz[40] == "on") { echo " selected='selected'"; } ?>><?php echo $admin61; ?></option>
</select></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin164; ?></p></td><td><p><input type="checkbox" name="serviz13" <?php if ($serviz[13]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;">
  <td><p style="padding-left:25px;"><?php echo $admin454; ?></p></td>
  <td><p><select name="serviz41">
<option value=""<?php if ($serviz[41] == "") { echo " selected='selected'"; } ?>><?php echo $admin55; ?></option>
<option value="on"<?php if ($serviz[41] == "on") { echo " selected='selected'"; } ?>><?php echo $admin61; ?></option>
</select></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin213; ?></p></td><td><p><input type="checkbox" name="serviz15" <?php if ($serviz[15]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin651; ?></p></td><td><p><input type="checkbox" name="serviz47" <?php if ($serviz[47]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin249; ?></p></td><td><p><input type="checkbox" name="serviz62" <?php if ($serviz[62]) echo "checked='checked'"; ?> /></p></td></tr>

<tr style="text-align:left;">
  <td><p>&bull; <?php echo $admin546.' :'; ?></p></td>
  <td><p><select name="serviz36">
<option value=""<?php if ($serviz[36] == "") { echo " selected='selected'"; } ?>><?php echo $web314; ?></option>
<option value="on"<?php if ($serviz[36] == "on") { echo " selected='selected'"; } ?>><?php echo $web313." + ".$admin745; ?></option>
<option value="no"<?php if ($serviz[36] == "no") { echo " selected='selected'"; } ?>><?php echo $web313.", ".$admin916; ?></option>
</select></p></td></tr>

<tr style="text-align:left;">
  <td><p>&bull; <?php echo $admin612; ?></p></td>
  <td><p><select name="serviz39">
<option value="900"<?php if ($serviz[39] == "900") { echo " selected='selected'"; } ?>><?php echo $admin613; ?></option>
<option value="1800"<?php if ($serviz[39] == "1800") { echo " selected='selected'"; } ?>><?php echo $admin614; ?></option>
<option value="3600"<?php if ($serviz[39] == "3600") { echo " selected='selected'"; } ?>><?php echo $admin615; ?></option>
<option value="10800"<?php if ($serviz[39] == "10800") { echo " selected='selected'"; } ?>><?php echo $admin616; ?></option>
<option value="21600"<?php if ($serviz[39] == "21600") { echo " selected='selected'"; } ?>><?php echo $admin617; ?></option>
<option value="43200"<?php if ($serviz[39] == "43200") { echo " selected='selected'"; } ?>><?php echo $admin618; ?></option>
<option value="86400"<?php if ($serviz[39] == "86400") { echo " selected='selected'"; } ?>><?php echo $admin619; ?></option>
</select></p></td></tr>
</table>
</fieldset>
<br />
<fieldset>
<?php
echo legend($admin239);
?>
<br />
<table cellspacing="0" cellpadding="2" align="center" border="0" width="96%" summary="">
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin472; ?></p></td><td width="150"><p><input class="texte" type="text" name="serviz30" size="3" value="<?php echo $serviz[30]; ?>" /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin72; ?></p></td><td><p><input class="texte" type="text" name="serviz2" size="3" value="<?php echo $serviz[2]; ?>" /></p></td></tr>
<tr style="text-align:left;"><td><p style="padding-left:25px;"> <?php echo $admin242." &amp; ".$admin795; ?></p></td><td><p><input class="texte" type="text" name="serviz37" size="3" value="<?php echo $serviz[37]; ?>" /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin780; ?></p></td><td><p><input class="texte" type="text" name="serviz55" size="3" value="<?php echo $serviz[55]; ?>" /></p></td></tr>
<tr style="text-align:left;"><td><p style="padding-left:25px;"> <?php echo $admin749; ?></p></td><td><p><input class="texte" type="text" name="serviz61" size="3" value="<?php echo $serviz[61]; ?>" /></p></td></tr>
<tr style="text-align:left;"><td><p style="padding-left:25px;"> <?php echo $admin781; ?></p></td><td><p><input class="texte" type="text" name="serviz56" size="3" value="<?php echo $serviz[56]; ?>" /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin73; ?></p></td><td><p><input class="texte" type="text" name="serviz4" size="3" value="<?php echo $serviz[4]; ?>" /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin75; ?></p></td><td><p><input class="texte" type="text" name="serviz5" size="3" value="<?php echo $serviz[5]; ?>" /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin207; ?></p></td><td><p><input class="texte" type="text" name="serviz6" size="3" value="<?php echo $serviz[6]; ?>" /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin76; ?></p></td><td><p><input class="texte" type="text" name="serviz7" size="3" value="<?php echo $serviz[7]; ?>" /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin164; ?></p></td><td><p><input class="texte" type="text" name="serviz17" size="3" value="<?php echo $serviz[17]; ?>" /></p></td></tr>
<tr style="text-align:left;"><td><p style="padding-left:25px;"> <?php echo $admin98; ?></p></td><td><p><input class="texte" type="text" name="serviz20" size="3" value="<?php echo $serviz[20]; ?>" /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin651; ?></p></td><td><p><input class="texte" type="text" name="serviz46" size="3" value="<?php echo $serviz[46]; ?>" /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin682; ?></p></td><td><p><input class="texte" type="text" name="serviz48" size="3" value="<?php echo $serviz[48]; ?>" /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin683; ?></p></td><td><p><input class="texte" type="text" name="serviz50" size="3" value="<?php echo $serviz[50]; ?>" /></p></td></tr>
</table>
</fieldset>
<br />
<fieldset>
<?php
echo legend($admin600);
?>
<br />
<table cellspacing="0" cellpadding="2" align="center" border="0" width="96%" summary="">
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin593; ?></p></td><td width="170"><p><select name="site27">
<option value="0"<?php if ($site[27] == "0") { echo " selected='selected'"; } ?>><?php echo $admin594; ?></option>
<option value="1"<?php if ($site[27] == "1") { echo " selected='selected'"; } ?>><?php echo $admin595; ?></option>
<option value="2"<?php if ($site[27] == "2") { echo " selected='selected'"; } ?>><?php echo $admin596; ?></option>
<option value="3"<?php if ($site[27] == "3") { echo " selected='selected'"; } ?>><?php echo $admin597; ?></option>
<option value="4"<?php if ($site[27] == "4") { echo " selected='selected'"; } ?>><?php echo $admin598; ?></option>
<option value="5"<?php if ($site[27] == "5") { echo " selected='selected'"; } ?>><?php echo $admin599; ?></option>
</select></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin601; ?></p></td><td><p><select name="site28">
<option value=""><?php echo $admin460; ?></option>

<?php
for ($i = 0; $i < count($progbartheme); $i++) {
  if ($site[28] == $progbartheme[$i]) {
    $sel = ' selected="selected"';
  }
  else {
    $sel = "";
  }
  echo '<option value="'.$progbartheme[$i].'"'.$sel.'>'.$progbartheme[$i].'</option>'."\n";
}
?>

</select></p></td></tr>
</table>
</fieldset>
<br />
<fieldset>
<?php
echo legend($admin761);
?>
<br />
<table cellspacing="0" cellpadding="2" border="0" align="center" width="96%" summary="">
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin762; ?></p></td><td width="170"><p><input class="texte" type="text" name="serviz51" size="4" value="<?php echo $serviz[51]; ?>" /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin763; ?></p></td><td><p><input class="texte" type="text" name="serviz52" size="4" value="<?php echo $serviz[52]; ?>" /></p></td></tr>
</table>
</fieldset>
<br />
<fieldset>
<?php
echo legend($admin229);
?>
<br />
<table cellspacing="0" cellpadding="2" border="0" align="center" width="96%" summary="">
<tr style="text-align:left;">
  <td><p>&bull; <?php echo $admin230; ?></p></td>
  <td><p><select name="supervision5">
<option value="standard"<?php if ($supervision[5] == "standard") { echo " selected='selected'"; } ?>><?php echo $admin231; ?></option>

<?php
for ($i=0; $i<count($mailer); $i++) {
  $mailtext = $admin232." ".$mailer[$i];
  if ($supervision[5] == $mailer[$i]) {
    $mailselect = " selected='selected'";
  }
  else {
    $mailselect = "";
  }
?>

<option value="<?php echo $mailer[$i];?>"<?php echo $mailselect; ?>><?php echo $mailtext; ?></option>

<?php
 }
?>

  </select></p></td>
</tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin234; ?></p></td><td><p><input type="checkbox" name="supervision0" <?php if ($supervision[0]) echo "checked='checked'"; ?> />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input class="texte" type="text" name="supervision1" size="6" value="<?php echo $supervision[1]; ?>" /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin473; ?></p></td><td><p><input type="checkbox" name="supervision6" <?php if ($supervision[6]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin235; ?></p></td><td><p><input type="checkbox" name="supervision2" <?php if ($supervision[2]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin786; ?></p></td><td><p><input type="checkbox" name="supervision8" <?php if ($supervision[8]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin236; ?></p></td><td><p><input type="checkbox" name="supervision3" <?php if ($supervision[3]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin237; ?></p></td><td><p><input type="checkbox" name="supervision4" <?php if ($supervision[4]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin520; ?></p></td><td><p><input type="checkbox" name="supervision7" <?php if ($supervision[7]) echo "checked='checked'"; ?> /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin942; ?></p></td><td><p><input type="checkbox" name="supervision10" <?php if ($supervision[10]) echo "checked='checked'"; ?> /></p></td></tr>
</table>
</fieldset>
</div>
<p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin66; ?>"><?php echo $admin66; ?></button><?php echo $boutonright; ?></p>
</form>
<script language="javascript" type="text/javascript">
  document.conf5.serviz31.focus();
</script>
<div align="center">
<hr /><a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b>
</div>

<?php
btable();
include(CHEMIN."inc/bpage.inc");

?>
