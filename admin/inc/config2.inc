<?php
/*
    Admin Configuration - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.3 (06 January 2003)   : added site's supervision options
      v1.6 (23 January 2003)   : added access to color coding popup
                                 added news publishing by external sites option
                                 added transition effect between pages (for IE browser only)
                                 added "page loaded in n.nn seconds" option
      v1.7 (28 January 2003)   : added Recommend to a Friend box
      v1.8 (05 February 2003)  : added category for forum
      v1.9 (11 February 2003)  : added Banners service and free box
                                 added Icon themes
      v2.0 (27 February 2003)  : added Meta Tags by Nicolas Alves & Laurent Duveau
                                 added fixed background image option
                                 no logo option added
                                 added advanced photo service
                                 modified slogan and start using it
                                 upgraded the Icon themes management (thanks Alex)
      v2.1 (10 March 2003)     : color management for the side scroll bar (by Nicolas Alves)
                                 counter theme management (by Nicolas Alves)
                                 changed source code for all accesses to the pathinfo() PHP function for compatibility with PHP3 as pathinfo() only works with PHP4
      v2.2 (22 April 2003)     : let webmaster decide how to place side boxes (by Nicolas Alves)
                                 left and right articles boxes (by Nicolas Alves)
                                 bug correction : "Times New Roman, serif" instead of wrong "Time New Roman, serif" (Thanks Isabelle)
                                 new color selector (by Nicolas Alves)
                                 new smileys theme selector
                                 cleanup in the images organization
                                 option for choosing the number of items to display in news, forum threads, links, downloads, FAQ and Guestbook
      v2.3 (27 July 2003)      : added dynamic menu option
                                 added a "no logo" option
                                 moved number of items per service from config2 to config4
                                 added a calendar box (by Nicolas Alves)
                                 added quotations style management (by Nicolas Alves and Isabelle)
                                 added forms style management (by Nicolas Alves)
                                 added user prefs management by cookie
                                 added US date format management
                                 added user news submission option (no more mandatory)
      v2.4 (24 September 2003) : added "Page loading" popup
                                 added forum summary in home page (last threads)
                                 added Guestbook's favourite message on home page
                                 added homepage's choice of central boxes
                                 added react to an article option
                                 recycled $texte[3] to Articles mark (was no more used)
                                 added Hide Admin Button (by Nicolas Alves)
                                 added Quick Article Admin Access (by Nicolas Alves)
                                 added number of times an article was read (by Nicolas Alves and Laurent Duveau)
                                 added number of times a forum thread was read (by Nicolas Alves and Laurent Duveau)
                                 added number of times a file was downloaded (by Nicolas Alves and Laurent Duveau)
                                 added new dates formats and created time formats
                                 created shared Config Update script
      v3.0 (25 February 2004)  : added an links animation effect option (thanks reddog)
      v4.0 (06 December 2004)  : added forum-tables background colors (by Icare)
      		                       added HR config (by Isa)
      		                       added nav menu config and a rollover effect option on the menu bar,
      		                       splitted style of the central and side boxes / links / titles,
      		                       added some usual fonts in selectors (by Isa)
      		                       clean up table syntax and comments (by Icare and Isa)
      		                       added a non graphical (text) counter option,
      		                       added a CSS extension for CSS skin, to be included in the stylesheet (by Isa)
				                         added avatars theme and cursors (by Nicolas Alves)
				                         added page title (by Jean-Mi)
	    v4.6.0 (04 June 2007)    : added fieldset, boxes title items and reorganization (by Icare)
	    v4.6.8 (24 May 2008)     : added automatic generation of style.css (by Icare)
        v4.6.10 (7 September 2009)    : corrected #266 and W3C
        v4.6.17 (21 October 2011)     :  corrected display for config look (by Saxbar)				  
 	    v4.6.19 (30 March 2012)       : replace cursor:hand by cursor:pointer by Saxbar (thanks tonton_christian)
        v4.6.22 (29 December 2012)    : corrected include(CHEMIN.'skin/no_skin/confskin.inc') (thanks JeanMi)		
*/

if (stristr($_SERVER["SCRIPT_NAME"], "config2.inc")) {
  header("location:../index.php");
  die();
}

// FONCTIONS DE MISE EN PAGE /////////////////////////////////////////////////////////////////////////
function legend($legend) {
	return '<legend style="font-weight:bold;margin-left:30px;padding:0 4px;">'.$legend.'</legend>'."\n";
}
//////////////////////////////////////////////////////////////////////////////////////////////////////

if (!isset($selskin)) $selskin = $page[14];

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[1]=="") {
    $nomzone=$admin45;
    include("access.inc");
    exit();
  }
}

if ($regit == 1) {
  $messreg = " OK";
  include(CONFIG);
  $meskin = CHEMIN."skin/".$selskin."/";
  if (is_file ($meskin."confskin.inc")) include ($meskin."confskin.inc");
  else include(CHEMIN.'skin/no_skin/confskin.inc');

if ($mod_css != "off") {
 $citation[0] = $citation0; // Police des citations
 $citation[1] = $citation1; // Taille de la police des citations
 $citation[2] = ($citation2 == "") ? "inherit" : $citation2; // Couleur de la police des citations

 $lien[0] = ($lien0 == "") ? "inherit" : $lien0; // Lien OFF des boites centrales
 $lien[1] = ($lien1 == "") ? "inherit" : $lien1; // Lien ON des boites centrales
 $lien[2] = ($lien1 == "") ? "inherit" : $lien2; // Lien OFF des boites latérales
 $lien[3] = ($lien3 == "") ? "inherit" : $lien3; // Lien ON des boites latérales
 $lien[4] = ($lien4 == "") ? "inherit" : $lien4; // Lien OFF de la barre de menu haute
 $lien[5] = ($lien5 == "") ? "inherit" : $lien5; // Lien ON de la barre de menu haute

 $page[0] = ($page0 == "") ? "inherit" : $page0; // Arrière-plan de la page
 $page[1] = $page1; // Police des boites centrales
 $page[2] = $page2; // Taille des textes des boites centrales
 $page[3] = $page3; // Image de fond du site
 $page[4] = $page4; // Logo du site
 $page[5] = ($page5 == "") ? "transparent" : $page5; // Arrière-plan du bandeau
 $page[6] = $page6; // Image de fond du bandeau
}
 $page[7] = $page7; // Transition entre pages
 $page[8] = $page8; // Affichage Temps de chargement de page ON / OFF
if ($mod_css != "off") {
 $page[10] = $page10; // Image de fond fixe / mouvante
}
 $page[13] = $page13; // Image Page en cours de chargement
if ($mod_css != "off") {
 $page[15] = $page15; // Effet animation liens
 $page[16] = $page16; // Police des boites latérales
 $page[17] = $page17; // Taille des textes des boites latérales
 $page[18] = $page18; // Police du menu de navigation
 $page[19] = $page19; // Taille des liens du menu de navigation
 $page[20] = $page20; // Rollover sur les icônes
 $page[21] = $page21; // Image de fond menu icônes
}
 $page[22] = $page22; // utilisation titres longs

if ($mod_css != "off") {
 $bordure[0] = ($bordure0 == "") ? "inherit" : $bordure0; // Couleur des bordures des boites
 $bordure[1] = ($bordure1 == "") ? "inherit" : $bordure1; // Couleur de la base de la barre de défilement
 $bordure[2] = ($bordure2 == "") ? "inherit" : $bordure2; // Couleur des flèches de la barre de défilement

 $barre[0] = ($barre0 == "") ? "inherit" : $barre0; // Couleur des HR
 $barre[1] = $barre1; // Taille des HR
 $barre[2] = $barre2; // Style des HR

 $titre[0] = ($titre0 == "") ? "inherit" : $titre0; // Couleur du titre des boites centrales
 $titre[1] = ($titre1 == "") ? "inherit" : $titre1; // Arrière-plan du titre des boites centrales
 $titre[2] = $titre2; // Police des titres des boites centrales
 $titre[3] = $titre3; // Taille des titres des boites centrales
 $titre[4] = ($titre4 == "") ? "inherit" : $titre4; // Couleur du titre des boites latérales
 $titre[5] = ($titre5 == "") ? "inherit" : $titre5; // Arrière-plan du titre des boites latérales
 $titre[6] = $titre6; // Police des titres des boites latérales
 $titre[7] = $titre7; // Taille des titres des boites latérales
 $titre[8] = $titre8; // Image de fond des titres des boites centrales
 $titre[9] = $titre9; // Image de fond des titres des boites latérales

 $texte[0] = ($texte0 == "") ? "inherit" : $texte0; // Couleur des textes des boites centrales
 $texte[1] = ($texte1 == "") ? "inherit" : $texte1; // Arrière-plan OFF des boites centrales
 $texte[2] = ($texte2 == "") ? "inherit" : $texte2; // Arrière-plan ON des boites centrales
 $texte[4] = ($texte4 == "") ? "0px" : $texte4; // Taille des bordures
 $texte[5] = ($texte5 == "") ? "inherit" : $texte5; // Couleur des textes des boites latérales
 $texte[6] = ($texte6 == "") ? "inherit" : $texte6; // Arrière-plan OFF des boites latérales
 $texte[7] = ($texte7 == "") ? "inherit" : $texte7; // Arrière-plan ON des boites latérales
 $texte[8] = ($texte8 == "") ? "inherit" : $texte8; // Couleur des textes de bas de page

 $forum[0] = ($forum0 == "") ? "inherit" : $forum0; // Arrière-plan entêtes forum
 $forum[1] = ($forum1 == "") ? "inherit" : $forum1; // Arrière-plan du sujet
 $forum[2] = ($forum2 == "") ? "inherit" : $forum2; // Arrière-plan de la réponse

 $presform[0] = ($presform0 == "") ? "inherit" : $presform0; // Couleur des textes dans les boites de choix et boutons de commande
 $presform[1] = ($presform1 == "") ? "inherit" : $presform1; // Couleur des boites de choix
 $presform[2] = ($presform2 == "") ? "inherit" : $presform2; // Couleur des boutons de commande
 $presform[3] = ($presform3 == "") ? "inherit" : $presform3; // Couleur des zone de texte
 $presform[4] = $presform4; // Police dans la présentation des formulaires
 $presform[5] = $presform5; // Taille de la police dans la présentation des formulaires
 $presform[6] = ($presform6 == "") ? "inherit" : $presform6; // Couleur de fond des textarea
 $presform[7] = $presform7; // Taille de la bordure
 $presform[8] = ($presform8 == "") ? "inherit" : $presform8; // Couleur de la bordure

  $calendar[0] = ($calendar0 == "") ? "inherit" : $calendar0; // Couleur de fond des jours libre du mois
  $calendar[1] = ($calendar1 == "") ? "inherit" : $calendar1; // Couleur de fond des jours du mois
  $calendar[2] = ($calendar2 == "") ? "inherit" : $calendar2; // Couleur de fond de la journée
  $calendar[3] = ($calendar4 == "") ? "inherit" : $calendar3; // Couleur de fond des dimanches
  $calendar[4] = ($calendar1 == "") ? "inherit" : $calendar4; // Couleur de fond de la journée si dimanche
  $calendar[5] = $calendar5; // Police du calendrier
  $calendar[6] = $calendar6; // Taille de la police du calendrier
  $calendar[7] = ($calendar7 == "") ? "inherit" : $calendar7; // Couleurs de la police des chiffres
  $calendar[8] = ($calendar8 == "") ? "inherit" : $calendar8; // Couleurs de la police des jours de la semaine
  $calendar[9] = ($calendar9 == "") ? "0px" : $calendar9; // Taille des bordures/espacements du calendrier
  $calendar[10] = ($calendar10 == "") ? "inherit" : $calendar10; // Couleur évènement
  $calendar[11] = ($calendar11 == "") ? "inherit" : $calendar11; // Couleur de fond du calendrier/bordure
}
 include("inc/confskin.inc");

if ($mod_css != "off") 
	header("location:admin.php?lng=".$lng."&pg=config8&selskin=".$selskin."&mycss=".$selskin."&regit=1");
else
	header("location:admin.php?lng=".$lng."&pg=config8&selskin=".$selskin."&mycss=".$selskin);
}
include(CONFIG);
$meskin = CHEMIN."skin/".$selskin."/";
if (is_file ($meskin."confskin.inc"))
    include ($meskin."confskin.inc");
else
    include (CHEMIN.'skin/no_skin/confskin.inc');
$topmess = $admin67;
include(CHEMIN."inc/hpage.inc");


$img = ExploreImg("img/");
$theme =  ExploreDir('inc/img/icons/');
$countheme = ExploreDir('inc/img/counter/');
$smileystheme = ExploreDir('inc/img/smileys/');
$skintheme = ExploreDir('skin/');
$progbartheme = ExploreImg("inc/img/progbar/");
$avatartheme = ExploreDir('inc/img/avatars/');
$cursorbody = ExploreFile('inc/img/cursor/');


htable($admin67, "100%");
function GetSelector($inputename='idselector', $default='') {
    if ($default == "transparent") $default = "";
    if ($default == "inherit") $default = "";
    return "<input size=\"10\" class=\"texte\" type=\"text\" id=\"".$inputename."\" name=\"".$inputename."\" value=\"".$default."\" /><input id=\"".$inputename."btn\" name=\"".$inputename."btn\" type=\"button\" value=\"    \" onclick=\"opencolorselector('".$inputename."', event)\" style=\"background:".$default."\" />\n";
}
?>
<script type="text/javascript">
  var curselectorinput;
  function selectcolor(c) {
    document.getElementById(curselectorinput).value=c;
    if(document.all) {
    document.getElementById(curselectorinput+'btn').style.background=c;
    } else {
      if(document.getElementById) {
        document.getElementById(curselectorinput+'btn').style.background=c;
      }
    }
   closecolorselector();
  }
  function opencolorselector(o, e) {
		selecto = document.getElementById('colorselector').style;
		if(selecto.display == "block") {
			closecolorselector();
		} else {
			selecto.display = "block";
			if(document.all && typeof(window.opera) != 'object') {
				selecto.left = event.x + document.body.scrollLeft - 380;
				selecto.top = event.y + document.body.scrollTop - 220;
			} else {
				if(document.getElementById) {
				selecto.left = (e.clientX + window.pageXOffset - 400) + "px";
				selecto.top = (e.clientY + window.pageYOffset - 220) + "px";
				}
			}
			curselectorinput=o;
		}
	}
  function closecolorselector() {
    document.getElementById('colorselector').style.display="none";
  }
</script>
<div id="colorselector" style="z-index:50;position:absolute;top:15px;width:300px;display:none;border:thin solid black;background:#FFFFFF;">
<p align="center"><?php echo $web31; ?></p>
<table cellspacing="1" cellpadding="1" align="center" border="0" summary="">
<?php
$fill = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp";
$col_r = 0;
$col_g = 0;
$col_b = 0;
$row_return = 0;
$block_return = 0;
  echo "<tr>\n";
while($col_r <= 255) {
  $col_g = 0;
  $block_return++;
  while($col_g <= 255) {
    $col_b = 0;
    while($col_b <= 255) {
      $red = strtoupper(dechex($col_r));
      $green = strtoupper(dechex($col_g));
      $blue = strtoupper(dechex($col_b));
      $color = str_pad($red,2,'0',STR_PAD_LEFT)."".str_pad($green,2,'0',STR_PAD_LEFT)."".str_pad($blue,2,'0',STR_PAD_LEFT);
      echo "<td height=\"15\" width=\"15\" bgcolor=\"#".$color."\" onclick='selectcolor(\"#".$color."\")' style=\"cursor: pointer;\"></td>";
      $row_return++;
      if($row_return == 18) {
        echo "</tr><tr>\n";
        $row_return = 0;
      }
      $col_b += 51;
    }
    $col_g += 51;
  }
  $col_r += 51;
}
?>
<td></td></tr>
</table>
<p align="center"><?php echo $admin240; ?></p>
<table summary="">
<tr>
<?php
 $col = 15;
 while($col <= 255) {
  $red = strtoupper(dechex($col));
  $green = strtoupper(dechex($col));
  $blue = strtoupper(dechex($col));
  $color = str_pad($red,2,'0',STR_PAD_LEFT)."".str_pad($green, 2,'0',STR_PAD_LEFT)."".str_pad($blue,2,'0',STR_PAD_LEFT);
  echo "<td height=\"15\" width=\"15\" bgcolor=\"#".$color."\" onclick='selectcolor(\"#".$color."\")' style=\"cursor: pointer;\"></td>";
  $col += 15;
 }
?>
</tr>
</table>
</div>
<?php if (isset($selskin)) $skn = "&amp;selskin=".$selskin; ?>
<div align="center">
<?php
if ($mod_css != "off") 
	echo $admin68.'<br />'.$admin69;
?>
<hr /><br />
<a href="admin.php?lng=<?php echo $lng.$skn; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b>
<hr />
</div>
<?php
if ($mod_css == "off") {
  echo '
<br />
<div align="center" class="notice">'.$admin894.'<br /></div>
<br />
';
//echo '
// <script type="text/javascript">
  // setTimeout("history.back()",10000);
// </script>
// ';
  // echo '
// <p align="center">
// <a href="javascript:history.back();">
// <img src="'.CHEMIN.'inc/img/general/back.gif" border="0" alt="'.$web135.'" title="'.$web135.'" />
// </a></p>
// ';
	// btable();
	// include(CHEMIN."inc/bpage.inc");
  // exit();
}
?>
<div align="center" style="width:514px;margin-left:auto;margin-right:auto;">
<br />
<fieldset class="forum"><?php echo $admin725.$userprefs[10].$messreg."<br />";?>
</fieldset>
<form name="conf2" action="admin.php?lng=<?php echo $lng; ?>" method="post">
<input type="hidden" name="pg" value="config2" />
<input type="hidden" name="regit" value="1" />
<p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin66; ?>"><?php echo $admin66; ?></button><?php echo $boutonright; ?></p>
<?php
if ($mod_css != "off") {
?>
<fieldset>
<?php
echo legend($admin81);
?>
<table cellspacing="0" cellpadding="4" align="center" border="0" width="100%" summary="">
<tr style="text-align:left;"><td width="50%"><p>&bull; <?php echo $admin91; ?> </p></td><td width="50%"><select name="page4">
<option value=""><?php echo $admin90; ?></option>
<?php
for ($i = 0; $i < count($img); $i++) {
 if ($page[4] == $img[$i]) {
 $sel = '" selected="selected"';
}
else {
 $sel = "";
 }
 echo "<option value=\"".$img[$i]."\"".$sel.">".$img[$i]."</option>\n";
 }
?>
</select></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin82; ?></p></td><td>
<?php
 echo GetSelector("page5", "$page[5]");
?>
</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin88; ?> </p></td><td><select name="page6">
<option value=""><?php echo $admin90; ?></option>
<?php
for ($i = 0; $i < count($img); $i++) {
 if ($page[6] == $img[$i]) {
 $sel = '" selected="selected"';
}
else {
 $sel = "";
 }
 echo "<option value=\"".$img[$i]."\"".$sel.">".$img[$i]."</option>\n";
 }
?>
</select></td></tr></table>
</fieldset>
<br />
<fieldset>
<?php
echo legend($admin405);
?>
<br />
<table cellspacing="0" cellpadding="4" align="center" border="0" width="100%" summary="">
<tr style="text-align:left;"><td width="50%"><p>&bull; <?php echo $admin85; ?></p></td><td width="50%"><select name="citation0">
<option value="Arial, Helvetica, sans-serif"<?php if ($citation[0] == "Arial, Helvetica, sans-serif") { echo ' selected="selected"'; } ?>>Arial, Helvetica, sans-serif</option>
<option value="Verdana, 'Bitstream Vera Sans', sans-serif"<?php if ($citation[0] == "Verdana, 'Bitstream Vera Sans', sans-serif") { echo ' selected="selected"'; } ?>>Verdana, Bitstream Vera Sans, sans-serif</option>
<option value="'Trebuchet MS', Helvetica, sans-serif"<?php if ($citation[0] == "'Trebuchet MS', Helvetica, sans-serif") { echo ' selected="selected"'; } ?>>Trebuchet MS, Helvetica, sans-serif</option>
<option value="'Comic sans MS', Arial, sans-serif"<?php if ($citation[0] == "'Comic sans MS', Arial, sans-serif") { echo ' selected="selected"'; } ?>>Comic sans MS, Arial, sans-serif</option>
<option value="'Times New Roman', Times, serif"<?php if ($citation[0] == "'Times New Roman', Times, serif") { echo ' selected="selected"'; } ?>>Times New Roman, Times, serif</option>
<option value="Georgia, 'Times New Roman', serif"<?php if ($citation[0] == "Georgia, 'Times New Roman', serif") { echo ' selected="selected"'; } ?>>Georgia, Times New Roman, serif</option>
<option value="'Courier New', Courier, monospace"<?php if ($citation[0] == "'Courier New', Courier, monospace") { echo ' selected="selected"'; } ?>>Courier New, Courier, monospace</option>
</select></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin86; ?></p></td><td><input name="citation1" class="texte" type="text" size="4" value="<?php echo $citation[1]; ?>" /></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin93; ?></p></td><td>
<?php
 echo GetSelector("citation2", "$citation[2]");
?>
</td></tr></table>
</fieldset>
<br />
<fieldset>
<?php
echo legend($admin806);
?>
<br />
<table cellspacing="0" cellpadding="4" align="center" border="0" width="100%" summary="">
<tr style="text-align:left;"><td width="50%"><p>&bull; <?php echo $admin85; ?></p></td><td width="50%"><select name="page18">
<option value="Arial, Helvetica, sans-serif"<?php if ($page[18] == "Arial, Helvetica, sans-serif") { echo ' selected="selected"'; } ?>>Arial, Helvetica, sans-serif</option>
<option value="Verdana, 'Bitstream Vera Sans', sans-serif"<?php if ($page[18] == "Verdana, 'Bitstream Vera Sans', sans-serif") { echo ' selected="selected"'; } ?>>Verdana, Bitstream Vera Sans, sans-serif</option>
<option value="'Trebuchet MS', Helvetica, sans-serif"<?php if ($page[18] == "'Trebuchet MS', Helvetica, sans-serif") { echo ' selected="selected"'; } ?>>Trebuchet MS, Helvetica, sans-serif</option>
<option value="'Comic sans MS', Arial, sans-serif"<?php if ($page[18] == "'Comic sans MS', Arial, sans-serif") { echo ' selected="selected"'; } ?>>Comic sans MS, Arial, sans-serif</option>
<option value="'Times New Roman', Times, serif"<?php if ($page[18] == "'Times New Roman', Times, serif") { echo ' selected="selected"'; } ?>>Times New Roman, Times, serif</option>
<option value="Georgia, 'Times New Roman', serif"<?php if ($page[18] == "Georgia, 'Times New Roman', serif") { echo ' selected="selected"'; } ?>>Georgia, Times New Roman, serif</option>
<option value="'Courier New', Courier, monospace"<?php if ($page[18] == "'Courier New', Courier, monospace") { echo ' selected="selected"'; } ?>>Courier New, Courier, monospace</option>
</select></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin86; ?></p></td><td><input name="page19" class="texte" type="text" size="4" value="<?php echo $page[19]; ?>" /></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin101; ?></p></td><td>
<?php
 echo GetSelector("lien4", "$lien[4]");
?>
</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin102; ?></p></td><td>
<?php
 echo GetSelector("lien5", "$lien[5]");
?>

</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin88; ?></p></td><td><select name="page21">
<option value=""><?php echo $admin90; ?></option>
<?php
for ($i = 0; $i < count($img); $i++) {
 if ($page[21] == $img[$i]) {
 $sel = ' selected="selected"';
}
else {
 $sel = "";
 }
 echo "<option value=\"".$img[$i]."\"".$sel.">".$img[$i]."</option>\n";
 }
?>
</select></td></tr>
</table>
</fieldset>
<br />
<?php } ?>
<fieldset>
<?php
echo legend($admin83);
?>
<br />
<table cellspacing="0" cellpadding="4" align="center" border="0" width="100%" summary="">
<tr style="text-align:left;"><td width="70%"><p>&bull; <?php echo $admin623; ?>&nbsp;&nbsp;&nbsp;&nbsp;</p></td><td width="30%"><input type="checkbox" name="page22" <?php if ($page[22]) echo ' checked="checked"'; ?> /></td></tr>
<?php
if ($mod_css != "off") {
?>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin82; ?></p></td><td>
<?php
 echo GetSelector("page0", "$page[0]");
?>
</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin88; ?></p></td><td><select name="page3">
<option value=""><?php echo $admin90; ?></option>
<?php
for ($i = 0; $i < count($img); $i++) {
 if ($page[3] == $img[$i]) {
 $sel = ' selected="selected"';
}
else {
 $sel = "";
 }
 echo "<option value=\"".$img[$i]."\"".$sel.">".$img[$i]."</option>\n";
 }
?>
</select><p><?php echo $admin321; ?> <input type="checkbox" name="page10" <?php if ($page[10]) echo ' checked="checked"'; ?> /></p></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin87; ?></p></td><td>
<?php
 echo GetSelector("bordure0", "$bordure[0]");
?>
</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin211; ?></p></td><td><input name="texte4" class="texte" type="text" size="4" value="<?php echo $texte[4]; ?>" /></td></tr>
<?php } ?>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin243; ?>&nbsp;&nbsp;&nbsp;&nbsp;</p></td><td><input type="checkbox" name="page7" <?php if ($page[7]) echo ' checked="checked"'; ?> /></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin244; ?>&nbsp;&nbsp;&nbsp;&nbsp;</p></td><td><input type="checkbox" name="page8" <?php if ($page[8]) echo ' checked="checked"'; ?> /></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin459; ?>&nbsp;&nbsp;&nbsp;&nbsp;</p></td><td><select name="page13">
<option value=""><?php echo $admin460; ?></option>
<?php
for ($i = 0; $i < count($progbartheme); $i++) {
 if ($page[13] == $progbartheme[$i]) {
 $sel = ' selected="selected"';
}
else {
 $sel = "";
 }
 echo "<option value=\"".$progbartheme[$i]."\"".$sel.">".$progbartheme[$i]."</option>\n";
 }
?>
</select></td></tr>
<?php
if ($mod_css != "off") {
?>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin620; ?>&nbsp;&nbsp;&nbsp;&nbsp;</p></td><td><input type="checkbox" name="page15" <?php if ($page[15]) echo ' checked="checked"'; ?> /></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin14.", ".$web172." :"; ?></p></td><td width="50%">
<?php
 echo GetSelector("texte8", "$texte[8]");
?>
</td></tr>
<?php } ?>
</table>
</fieldset>
<br />
<?php
if ($mod_css != "off") {
?>
<fieldset>
<?php
echo legend($admin92.$admin96);
?>
<br />
<table cellspacing="0" cellpadding="4" align="center" border="0" width="100%" summary="">
<tr style="text-align:left;"><td width="50%"><p>&bull; <?php echo $admin82; ?></p></td><td width="50%">
<?php
 echo GetSelector("titre1", "$titre[1]");
?>
</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin94; ?></p></td><td><select name="titre8">
<option value=""><?php echo $admin90; ?></option>
<?php
for ($i = 0; $i < count($img); $i++) {
 if ($titre[8] == $img[$i]) {
 $sel = ' selected="selected"';
}
else {
 $sel = "";
 }
 echo "<option value=\"".$img[$i]."\"".$sel.">".$img[$i]."</option>\n";
 }
?>
</select></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin93; ?> </p></td><td>
<?php
 echo GetSelector("titre0", "$titre[0]");
?>
</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin85; ?></p></td><td><select name="titre2">
<option value="Arial, Helvetica, sans-serif"<?php if ($titre[2] == "Arial, Helvetica, sans-serif") { echo ' selected="selected"'; } ?>>Arial, Helvetica, sans-serif</option>
<option value="Verdana, 'Bitstream Vera Sans', sans-serif"<?php if ($titre[2] == "Verdana, 'Bitstream Vera Sans', sans-serif") { echo ' selected="selected"'; } ?>>Verdana, Bitstream Vera Sans, sans-serif</option>
<option value="'Comic sans MS', Arial, sans-serif"<?php if ($titre[2] == "'Comic sans MS', Arial, sans-serif") { echo ' selected="selected"'; } ?>>Comic sans MS, Arial, sans-serif</option>
<option value="'Trebuchet MS', Helvetica, sans-serif"<?php if ($titre[2] == "'Trebuchet MS', Helvetica, sans-serif") { echo ' selected="selected"'; } ?>>Trebuchet MS, Helvetica, sans-serif</option>
<option value="'Times New Roman', Times, serif"<?php if ($titre[2] == "Times New Roman, Times, serif") { echo ' selected="selected"'; } ?>>Times New Roman, Times, serif</option>
<option value="Georgia, 'Times New Roman', serif"<?php if ($titre[2] == "Georgia, 'Times New Roman', serif") { echo ' selected="selected"'; } ?>>Georgia, Times New Roman, serif</option>
<option value="'Courier New', Courier, monospace"<?php if ($titre[2] == "'Courier New', Courier, monospace") { echo ' selected="selected"'; } ?>>Courier New, Courier, monospace</option>
</select></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin86; ?></p></td><td><input name="titre3" class="texte" type="text" size="4" value="<?php echo $titre[3]; ?>" /></td></tr>
</table>
</fieldset>
<br />
<fieldset>
<?php
echo legend($admin96);
?>
<br />
<table cellspacing="0" cellpadding="4" align="center" border="0" width="100%" summary="">
<tr style="text-align:left;"><td width="50%"><p>&bull; <?php echo $admin85; ?></p></td><td width="50%"><select name="page1">
<option value="Arial, Helvetica, sans-serif"<?php if ($page[1] == "Arial, Helvetica, sans-serif") { echo ' selected="selected"'; } ?>>Arial, Helvetica, sans-serif</option>
<option value="Verdana, 'Bitstream Vera Sans', sans-serif"<?php if ($page[1] == "Verdana, 'Bitstream Vera Sans', sans-serif") { echo ' selected="selected"'; } ?>>Verdana, Bitstream Vera Sans, sans-serif</option>
<option value="'Trebuchet MS', Helvetica, sans-serif"<?php if ($page[1] == "'Trebuchet MS', Helvetica, sans-serif") { echo ' selected="selected"'; } ?>>Trebuchet MS, Helvetica, sans-serif</option>
<option value="'Comic sans MS', Arial, sans-serif"<?php if ($page[1] == "'Comic sans MS', Arial, sans-serif") { echo ' selected="selected"'; } ?>>Comic sans MS, Arial, sans-serif</option>
<option value="'Times New Roman', Times, serif"<?php if ($page[1] == "'Times New Roman', Times, serif") { echo ' selected="selected"'; } ?>>Times New Roman, Times, serif</option>
<option value="Georgia, 'Times New Roman', serif"<?php if ($page[1] == "Georgia, 'Times New Roman', serif") { echo ' selected="selected"'; } ?>>Georgia, Times New Roman, serif</option>
<option value="'Courier New', Courier, monospace"<?php if ($page[1] == "'Courier New', Courier, monospace") { echo ' selected="selected"'; } ?>>Courier New, Courier, monospace</option>
</select></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin86; ?></p></td><td><input name="page2" class="texte" type="text" size="4" value="<?php echo $page[2]; ?>" /></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin95; ?></p></td><td>
<?php
 echo GetSelector("texte0", "$texte[0]");
?>
</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin99; ?></p></td><td>
<?php
 echo GetSelector("texte1", "$texte[1]");
?>
</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin100; ?></p></td><td>
<?php
 echo GetSelector("texte2", "$texte[2]");
?>
</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin101; ?></p></td><td>
<?php
 echo GetSelector("lien0", "$lien[0]");
?>
</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin102; ?></p></td><td>
<?php
 echo GetSelector("lien1", "$lien[1]");
?>
</td></tr></table>
</fieldset>
<br />
<fieldset>
<?php
echo legend($admin92.$admin804);
?>
<br />
<table cellspacing="0" cellpadding="4" align="center" border="0" width="100%" summary="">
<tr style="text-align:left;"><td width="50%"><p>&bull; <?php echo $admin82; ?> </p></td><td width="50%">
<?php
 echo GetSelector("titre5", "$titre[5]");
?>
</td></tr>

<tr style="text-align:left;"><td><p>&bull; <?php echo $admin94; ?></p></td><td><select name="titre9">
<option value=""><?php echo $admin90; ?></option>
<?php
for ($i = 0; $i < count($img); $i++) {
 if ($titre[9] == $img[$i]) {
 $sel = ' selected="selected"';
}
else {
 $sel = "";
 }
 echo "<option value=\"".$img[$i]."\"".$sel.">".$img[$i]."</option>\n";
 }
?>
</select></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin93; ?></p></td><td>
<?php
 echo GetSelector("titre4", "$titre[4]");
?>
</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin85; ?></p></td><td><select name="titre6">
<option value="Arial, Helvetica, sans-serif"<?php if ($titre[6] == "Arial, Helvetica, sans-serif") { echo ' selected="selected"'; } ?>>Arial, Helvetica, sans-serif</option>
<option value="Verdana, 'Bitstream Vera Sans', sans-serif"<?php if ($titre[6] == "Verdana, 'Bitstream Vera Sans', sans-serif") { echo ' selected="selected"'; } ?>>Verdana, Bitstream Vera Sans, sans-serif</option>
<option value="'Trebuchet MS', Helvetica, sans-serif"<?php if ($titre[6] == "'Trebuchet MS', Helvetica, sans-serif") { echo ' selected="selected"'; } ?>>Trebuchet MS, Helvetica, sans-serif</option>
<option value="'Comic sans MS', Arial, sans-serif"<?php if ($titre[6] == "'Comic sans MS', Arial, sans-serif") { echo ' selected="selected"'; } ?>>Comic sans MS, Arial, sans-serif</option>
<option value="'Times New Roman', Times, serif"<?php if ($titre[6] == "'Times New Roman', Times, serif") { echo ' selected="selected"'; } ?>>Times New Roman, Times, serif</option>
<option value="Georgia, 'Times New Roman', serif"<?php if ($titre[6] == "Georgia, 'Times New Roman', serif") { echo ' selected="selected"'; } ?>>Georgia, Times New Roman, serif</option>
<option value="'Courier New', Courier, monospace"<?php if ($titre[6] == "'Courier New', Courier, monospace") { echo ' selected="selected"'; } ?>>Courier New, Courier, monospace</option>
</select></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin86; ?></p></td><td><input name="titre7" class="texte" type="text" size="4" value="<?php echo $titre[7]; ?>" /></td></tr>
</table>
</fieldset>
<br />
<fieldset>
<?php
echo legend($admin804);
?>
<br />
<table cellspacing="0" cellpadding="4" align="center" border="0" width="100%" summary="">
<tr style="text-align:left;"><td width="50%"><p>&bull; <?php echo $admin85; ?></p></td><td><select name="page16">
<option value="Arial, Helvetica, sans-serif"<?php if ($page[16] == "Arial, Helvetica, sans-serif") { echo ' selected="selected"'; } ?>>Arial, Helvetica, sans-serif</option>
<option value="Verdana, 'Bitstream Vera Sans', sans-serif"<?php if ($page[16] == "Verdana, 'Bitstream Vera Sans', sans-serif") { echo ' selected="selected"'; } ?>>Verdana, Bitstream Vera Sans, sans-serif</option>
<option value="'Trebuchet MS', Helvetica, sans-serif"<?php if ($page[16] == "'Trebuchet MS', Helvetica, sans-serif") { echo ' selected="selected"'; } ?>>Trebuchet MS, Helvetica, sans-serif</option>
<option value="'Comic sans MS', Arial, sans-serif"<?php if ($page[16] == "'Comic sans MS', Arial, sans-serif") { echo ' selected="selected"'; } ?>>Comic sans MS, Arial, sans-serif</option>
<option value="'Times New Roman', Times, serif"<?php if ($page[16] == "'Times New Roman', Times, serif") { echo ' selected="selected"'; } ?>>Times New Roman, Times, serif</option>
<option value="Georgia, 'Times New Roman', serif"<?php if ($page[16] == "Georgia, 'Times New Roman', serif") { echo ' selected="selected"'; } ?>>Georgia, Times New Roman, serif</option>
<option value="'Courier New', Courier, monospace"<?php if ($page[16] == "'Courier New', Courier, monospace") { echo ' selected="selected"'; } ?>>Courier New, Courier, monospace</option>
</select></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin86; ?></p></td><td><input name="page17" class="texte" type="text" size="4" value="<?php echo $page[17]; ?>" /></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin95; ?></p></td><td>
<?php
 echo GetSelector("texte5", "$texte[5]");
?>
</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin99; ?></p></td><td>
<?php
 echo GetSelector("texte6", "$texte[6]");
?>
</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin100; ?></p></td><td>
<?php
 echo GetSelector("texte7", "$texte[7]");
?>
</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin101; ?></p></td><td>
<?php
 echo GetSelector("lien2", "$lien[2]");
?>
</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin102; ?></p></td><td>
<?php
 echo GetSelector("lien3", "$lien[3]");
?>
</td></tr></table>
</fieldset>
<br />
<fieldset>
<?php
echo legend($admin800);
?>
<br />
<table cellspacing="0" cellpadding="4" align="center" border="0" width="100%" summary="">
<tr style="text-align:left;"><td width="50%"><p>&bull; <?php echo $admin801; ?></p></td><td width="50%">
<?php
 echo GetSelector("forum0", "$forum[0]");
?>
</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin802; ?></p></td><td>
<?php
 echo GetSelector("forum1", "$forum[1]");
?>
</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin803; ?></p></td><td>
<?php
 echo GetSelector("forum2", "$forum[2]");
?>
</td></tr></table>
</fieldset>
<br />
<fieldset>
<?php
echo legend($admin399);
?>
<br />
<table cellspacing="0" cellpadding="4" align="center" border="0" width="100%" summary="">
<tr style="text-align:left;"><td width="50%"><p>&bull; <?php echo $admin400; ?></p></td><td width="50%">
<?php
 echo GetSelector("presform1", "$presform[1]");
?>
</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin401; ?></p></td><td>
<?php
 echo GetSelector("presform2", "$presform[2]");
?>
</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin402; ?></p></td><td>
<?php
 echo GetSelector("presform3", "$presform[3]");
?>
</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin403; ?></p></td><td>
<?php
 echo GetSelector("presform6", "$presform[6]");
?>
</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin95; ?></p></td><td>
<?php
 echo GetSelector("presform0", "$presform[0]");
?>
</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin85; ?></p></td><td><select name="presform4">
<option value="Arial, Helvetica, sans-serif"<?php if ($presform[4] == "Arial, Helvetica, sans-serif") { echo ' selected="selected"'; } ?>>Arial, Helvetica, sans-serif</option>
<option value="Verdana, 'Bitstream Vera Sans', sans-serif"<?php if ($presform[4] == "Verdana, 'Bitstream Vera Sans', sans-serif") { echo ' selected="selected"'; } ?>>Verdana, Bitstream Vera Sans, sans-serif</option>
<option value="'Trebuchet MS', Helvetica, sans-serif"<?php if ($presform[4] == "'Trebuchet MS', Helvetica, sans-serif") { echo ' selected="selected"'; } ?>>Trebuchet MS, Helvetica, sans-serif</option>
<option value="'Comic sans MS', Arial, sans-serif"<?php if ($presform[4] == "'Comic sans MS', Arial, sans-serif") { echo ' selected="selected"'; } ?>>Comic sans MS, Arial, sans-serif</option>
<option value="'Times New Roman', Times, serif"<?php if ($presform[4] == "'Times New Roman', Times, serif") { echo ' selected="selected"'; } ?>>Times New Roman, Times, serif</option>
<option value="Georgia, 'Times New Roman', serif"<?php if ($presform[4] == "Georgia, 'Times New Roman', Times, serif") { echo ' selected="selected"'; } ?>>Georgia, Times New Roman, serif</option>
<option value="'Courier New', Courier, monospace"<?php if ($presform[4] == "'Courier New', Courier, monospace") { echo ' selected="selected"'; } ?>>Courier New, Courier, monospace</option>
</select></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin86; ?></p></td><td><input name="presform5" class="texte" type="text" size="4" value="<?php echo $presform[5]; ?>" /></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin211; ?></p></td><td><input name="presform7" class="texte" type="text" size="4" value="<?php echo $presform[7]; ?>" /></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin404; ?></p></td><td>
<?php
 echo GetSelector("presform8", "$presform[8]");
?>
</td></tr></table>
</fieldset>

<?php ##################################################### ?>
<br />
<fieldset>
<?php
echo legend($admin409);
?>
<br /><p align="center"><b></b></p>
<p align="center"><b><?php echo $admin410; ?></b></p>
<table cellspacing="0" cellpadding="2" align="center" border="0" summary="">
<tr align="left"><td><p>&bull; <?php echo $admin411; ?></p></td><td>
<?php
 echo GetSelector("calendar0", "$calendar[0]");
?>
</td></tr>
<tr align="left"><td><p>&bull; <?php echo $admin412; ?></p></td><td>
<?php
 echo GetSelector("calendar1", "$calendar[1]");
?>
</td></tr>
<tr align="left"><td><p>&bull; <?php echo $admin413; ?></p></td><td>
<?php
 echo GetSelector("calendar2", "$calendar[2]");
?>
</td></tr>
<tr align="left"><td><p>&bull; <?php echo $admin414; ?></p></td><td>
<?php
 echo GetSelector("calendar3", "$calendar[3]");
?>
</td></tr>
<tr align="left"><td><p>&bull; <?php echo $admin415; ?></p></td><td>
<?php
 echo GetSelector("calendar4", "$calendar[4]");
?>
</td></tr>
<tr align="left"><td><p>&bull; <?php echo $admin417; ?></p></td><td>
<?php
 echo GetSelector("calendar7", "$calendar[7]");
?>
</td></tr>
<tr align="left"><td><p>&bull; <?php echo $admin418; ?></p></td><td>
<?php
 echo GetSelector("calendar8", "$calendar[8]");
?>
</td></tr>
<tr align="left"><td><p>&bull; <?php echo $admin85; ?> </p></td><td><select name="calendar5">
<option value="Arial, Helvetica, sans-serif"<?php if ($calendar[5]== "Arial, Helvetica, sans-serif") { echo ' selected="selected"'; } ?>>Arial, Helvetica, sans-serif</option>
<option value="Verdana, 'Bitstream Vera Sans', sans-serif"<?php if ($calendar[5] == "Verdana, 'Bitstream Vera Sans', sans-serif") { echo ' selected="selected"'; } ?>>Verdana, Bitstream Vera Sans, sans-serif</option>
<option value="'Trebuchet MS', Helvetica, sans-serif"<?php if ($calendar[5] == "'Trebuchet MS', Helvetica, sans-serif") { echo ' selected="selected"'; } ?>>Trebuchet MS, Helvetica, sans-serif</option>
<option value="'Comic sans MS', Arial, sans-serif"<?php if ($calendar[5] == "'Comic sans MS', Arial, sans-serif") { echo ' selected="selected"'; } ?>>Comic sans MS, Arial, sans-serif</option>
<option value="'Times New Roman', Times, serif"<?php if ($calendar[5] == "'Times New Roman', Times, serif") { echo ' selected="selected"'; } ?>>Times New Roman, Times, serif</option>
<option value="Georgia, 'Times New Roman', serif"<?php if ($calendar[5] == "Georgia, 'Times New Roman', serif") { echo ' selected="selected"'; } ?>>Georgia, Times New Roman, serif</option>
<option value="'Courier New', Courier, monospace"<?php if ($calendar[5] == "'Courier New', Courier, monospace") { echo ' selected="selected"'; } ?>>Courier New, Courier, monospace</option>
</select></td></tr>
<tr align="left"><td><p>&bull; <?php echo $admin86; ?></p></td><td>
<input name="calendar6" class="texte" type="text" size="4" value="<?php echo $calendar[6]; ?>" /></p></td></tr>
<tr align="left"><td><p>&bull; <?php echo $admin865; ?></p></td><td>
<?php
 echo GetSelector("calendar11", "$calendar[11]");
?>
</td></tr>
<tr align="left"><td><p>&bull; <?php echo $web395; ?></p></td><td>
<?php
 echo GetSelector("calendar10", "$calendar[10]");
?>
</td></tr>
<tr align="left"><td><p>&bull; <?php echo $admin211; ?></p></td><td><select name="calendar9">
<option value="0px"<?php if ($calendar[9] == "0px") { echo ' selected="selected"'; } ?>>0</option>
<option value="1px"<?php if ($calendar[9] == "1px") { echo ' selected="selected"'; } ?>>1</option>
<option value="2px"<?php if ($calendar[9] == "2px") { echo ' selected="selected"'; } ?>>2</option>
<option value="3px"<?php if ($calendar[9] == "3px") { echo ' selected="selected"'; } ?>>3</option>
</select>
</td></tr>
</table>
</fieldset>

<br />
<fieldset>
<?php
echo legend($admin805);
?>
<br />
<table cellspacing="0" cellpadding="4" align="center" border="0" width="100%" summary="">
<tr style="text-align:left;"><td width="50%"><p>&bull; <?php echo $admin150; ?> :</p></td><td width="50%">
<?php
 echo GetSelector("barre0", "$barre[0]");
?>
</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin86; ?></p></td><td><input name="barre1" class="texte" type="text" size="4" value="<?php echo $barre[1]; ?>" /></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin422; ?> :</p></td><td><select name="barre2">
<option value="dotted"<?php if ($barre[2] == "dotted") { echo ' selected="selected"'; } ?>>dotted</option>
<option value="dashed"<?php if ($barre[2] == "dashed") { echo ' selected="selected"'; } ?>>dashed</option>
<option value="solid"<?php if ($barre[2] == "solid") { echo ' selected="selected"'; } ?>>solid</option>
<option value="double"<?php if ($barre[2] == "double") { echo ' selected="selected"'; } ?>>double</option>
<option value="groove"<?php if ($barre[2] == "groove") { echo ' selected="selected"'; } ?>>groove</option>
<option value="ridge"<?php if ($barre[2] == "ridge") { echo ' selected="selected"'; } ?>>ridge</option>
<option value="inset"<?php if ($barre[2] == "inset") { echo ' selected="selected"'; } ?>>inset</option>
<option value="outset"<?php if ($barre[2] == "outset") { echo ' selected="selected"'; } ?>>outset</option>
</select>
</td></tr></table>
</fieldset>
<br />
<fieldset>
<?php
echo legend($admin340);
?>
<br />
<table cellspacing="0" cellpadding="4" align="center" border="0" width="100%" summary="">
<tr style="text-align:left;"><td colspan="2"><p align="center"><?php echo $admin343; ?></p></td></tr>
<tr style="text-align:left;"><td width="50%"><p>&bull; <?php echo $admin341; ?></p></td><td width="50%">
<?php
 echo GetSelector("bordure1", "$bordure[1]");
?>
</td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin342; ?></p></td><td>
<?php
 echo GetSelector("bordure2", "$bordure[2]");
?>
</td></tr></table>
</fieldset>
<?php } ?>
<br />
<input type="hidden" name="selskin" value="<?php echo $selskin; ?>" />
<p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin66; ?>"><?php echo $admin66; ?></button><?php echo $boutonright; ?></p>
</form>
</div>
<br />
<div align="center"><hr />
<?php if (isset($selskin)) $skn = "&amp;selskin=".$selskin; ?>
<a href="admin.php?lng=<?php echo $lng.$skn; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b>
</div>
<?php
btable();
include(CHEMIN."inc/bpage.inc");
?>