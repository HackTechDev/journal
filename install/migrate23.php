<?php
/*
  Migrate from previous version - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.aldweb.com/
      e-mail   = guppy@freeguppy.org

    Version History :
      v2.0 (27 February 2003)  : initial release
      v2.2 (22 April 2003)     : full rewrite
      v2.3 (27 July 2003)      : upgraded the installation / migration script
      v2.4 (24 September 2003) : upgrade for v2.4 compatibility
	  v4.6.19 (30 March 2012)  : set datas in conformity with php5 by Saxbar
*/

header("Pragma: no-cache");
define("CHEMIN", "../");
include(CHEMIN."inc/reglobals.inc");
$version = "2.3";
$scriptname = "migrate23.php";

include("functions23.php");

if ($lng == "fr") {
  $clean1 = "MIGRATION DE MINIPORTAIL EN VERSION ".$version;
  $clean2 = "<CENTER>Ce script permet :</CENTER><UL><LI>de migrer à la version ".$version." de miniPortail à partir d'une version 2.2</UL>";
  $clean3 = "<CENTER><U>IMPORTANT :</U> assurez-vous de bien avoir lu le fichier <A HREF=\"../lisezmoi.txt\">lisezmoi.txt</A> (je vous conseille même de l'imprimer) avant de poursuivre.</CENTER>";
  $clean4 = "Allons-y !";
  $clean5 = "Migration à la version ".$version;
  $clean6 = "<CENTER>Vous êtes sur le point de lancer une migration à la version ".$version."</CENTER>";
  $clean7 = "<CENTER>Migration à la version ".$version." EN COURS.</CENTER>";
  $clean8 = "<CENTER>Etape n°1/1 : Migration du paramétrage terminée.</CENTER>";
  $clean9 = "<CENTER>Migration à la version ".$version." TERMINEE.</CENTER>";
  $clean10 = "<CENTER>La migration en version ".$version." de miniPortail est maintenant terminée.</CENTER>";
  $clean11 = "Suivant";
  $clean13 = 'Setting in conformity datas to php 5';
  $clean14 = ' files processed.';
}
else {
  $lng = "en";
  $clean1 = "MIGRATE MINIPORTAIL TO VERSION ".$version;
  $clean2 = "<CENTER>This script is ment:</CENTER><UL><LI>for migrating to miniPortail version ".$version." from a version 2.2</UL>";
  $clean3 = "<CENTER><U>IMPORTANT:</U> make sure that you carefully read the <A HREF=\"../readme.txt\">readme.txt</A> file (I even advise you to print it) before going on.</CENTER>";
  $clean4 = "Let's go!";
  $clean5 = "Migration to version ".$version;
  $clean6 = "<CENTER>You are about to launch a migration to version ".$version."</CENTER>";
  $clean7 = "<CENTER>Migration to version ".$version." ON GOING.</CENTER>";
  $clean8 = "<CENTER>Step #1/1: Parametrization migrated.</CENTER>";
  $clean9 = "<CENTER>Migration to version ".$version." DONE.</CENTER>";
  $clean10 = "<CENTER>The migration to version ".$version." of miniPortail is now over.</CENTER>";
  $clean11 = "Next";
  $clean13 = 'Mise en conformité des datas au php 5';
  $clean14 = ' fichiers traités.';
}

$nextstep = "";
$dodo = 1;

function DisplayTitre($titre,$texte) {
?>
<H3><CENTER><?php echo $titre; ?></CENTER></H3>
<table width="90%" align="center" cellpadding="0" cellspacing="0">
<tr><td bgcolor="#DDDDFF">
<br /><?php echo $texte; ?><br />
</td></tr>
</table>
<?php
}

function DisplayProcess($titre,$processus,$resultat) {
  DisplayTitre($titre,$processus);
?>
<p align="center">&nbsp;</p>
<table width="50%" align="center" cellpadding="0" cellspacing="0">
<tr><td bgcolor="#FF9933">
<br /><?php echo $resultat; ?><br />
</td></tr>
</table>
<?php
}

function DatasToPhp5($dir) {
  $handle = opendir(CHEMIN.$dir);
  $n = 0; $x = 0;
  while (false !== ($fichier = readdir($handle))) {
    if (is_file(CHEMIN.$dir.$fichier)) {
        $contenu = file_get_contents(CHEMIN.$dir.$fichier); $x++;
        if (preg_match("!\<\?\s!", $contenu)) {
            $contenu = preg_replace("!\<\?!", "<?php", $contenu);
            $contenu = preg_replace("!\<\?phpphp!", "<?php ", $contenu);
            $h = fopen(CHEMIN.$dir.$fichier, "w");
            fputs($h, $contenu);
            fclose($h);
            $n++;
        }
    }
    
  }
  closedir($handle);
  return $n.'/'.$x;
}

function MigrateConfig() {
  include(CHEMIN.DATAREP."config.inc");
  $site19 = "";
  $nom32 = "";
  $nom33 = "";
  $nom34 = "";
  $nom35 = "";
  $serviz25 = "0";
  $serviz26 = "0";
  $serviz27 = "on";
  $serviz28 = "";
  $calendar0 = "";
  $calendar1 = "#FFFFCC";
  $calendar2 = "#6666FF";
  $calendar3 = "#FF6666";
  $calendar4 = "#6666FF";
  $calendar5 = "Verdana, sans-serif";
  $calendar6 = "14px";
  $calendar7 = "";
  $calendar8 = "#FF0000";
  $calendar9 = "0";
  $calendar10 = "";
  $calendar11 = "30%";
  $citation0 = "Arial, sans-serif";
  $citation1 = "";
  $citation2 = "";
  $presform0 = "";
  $presform1 = "";
  $presform2 = "";
  $presform3 = "";
  $presform4 = "Arial, sans-serif";
  $presform5 = "";
  $presform6 = "";
  $presform7 = "1px";
  $presform8 = "";

  $mettre = "<?php
\$site[0] = stripslashes(\"$site[0]\"); // Titre du site pour l'Editorial
\$site[1] = stripslashes(\"$site[1]\"); // Meta Description du site
\$site[2] = stripslashes(\"$site[2]\"); // Meta Mots-clés du site
\$site[3] = stripslashes(\"$site[3]\"); // URL du site
\$site[4] = stripslashes(\"$site[4]\"); // Nouvelles sur la page d'accueil
\$site[5] = stripslashes(\"$site[5]\"); // Activation des news ou pas
\$site[6] = stripslashes(\"$site[6]\"); // Meta Titre du site pour les moteurs de recherche
\$site[7] = stripslashes(\"$site[7]\"); // Meta Méthode d'indexation du site pour les robots
\$site[8] = stripslashes(\"$site[8]\"); // Meta Délai d'attente du robot avant une prochaine indexation
\$site[9] = stripslashes(\"$site[9]\"); // Meta Auteur du site
\$site[10] = stripslashes(\"$site[10]\"); // Meta Propriétaire du site
\$site[11] = stripslashes(\"$site[11]\"); // Meta Adresse e-mail principale de l'auteur du site
\$site[12] = stripslashes(\"$site[12]\"); // Meta Catégorie du public visé
\$site[13] = stripslashes(\"$site[13]\"); // Meta Mode de diffusion du site
\$site[14] = stripslashes(\"$site[14]\"); // Meta Copyright de l'auteur du site
\$site[15] = stripslashes(\"$site[15]\"); // Meta language
\$site[16] = stripslashes(\"$site[16]\"); // Meta Identifier URL
\$site[17] = stripslashes(\"$site[17]\"); // Slogan défilant langue principale
\$site[18] = stripslashes(\"$site[18]\"); // Slogan défilant deuxième langue
\$site[19] = stripslashes(\"$site19\"); // Format Dates

\$lang[0] = stripslashes(\"$lang[0]\"); // Langue principale du site
\$lang[1] = stripslashes(\"$lang[1]\"); // Deuxième langue du site

\$user[0] = stripslashes(\"$user[0]\"); // Webmaster
\$user[1] = stripslashes(\"$user[1]\"); // e-mail du responsable du site
\$user[2] = stripslashes(\"$user[2]\"); // # ICQ

\$nom[0] = stripslashes(\"$nom[0]\"); // Nom de l'accueil langue principale
\$nom[1] = stripslashes(\"$nom[1]\"); // Page des téléchargements langue principale
\$nom[2] = stripslashes(\"$nom[2]\"); // Page des images langue principale
\$nom[3] = stripslashes(\"$nom[3]\"); // Page des liens langue principale
\$nom[4] = stripslashes(\"$nom[4]\"); // Boite des articles gauche langue principale
\$nom[5] = stripslashes(\"$nom[5]\"); // Boite spéciale langue principale
\$nom[6] = stripslashes(\"$nom[6]\"); // Sondage langue principale
\$nom[7] = stripslashes(\"$nom[7]\"); // Nouvelles langue principale
\$nom[8] = stripslashes(\"$nom[8]\"); // Compteur langue principale
\$nom[9] = stripslashes(\"$nom[9]\"); // Livre d'or langue principale
\$nom[10] = stripslashes(\"$nom[10]\"); // Nom de l'accueil deuxième langue
\$nom[11] = stripslashes(\"$nom[11]\"); // Page des téléchargements deuxième langue
\$nom[12] = stripslashes(\"$nom[12]\"); // Page des images deuxième langue
\$nom[13] = stripslashes(\"$nom[13]\"); // Page des liens deuxième langue
\$nom[14] = stripslashes(\"$nom[14]\"); // Boite des articles gauche deuxième langue
\$nom[15] = stripslashes(\"$nom[15]\"); // Boite spéciale deuxième langue
\$nom[16] = stripslashes(\"$nom[16]\"); // Sondage deuxième langue
\$nom[17] = stripslashes(\"$nom[17]\"); // Nouvelles deuxième langue
\$nom[18] = stripslashes(\"$nom[18]\"); // Compteur deuxième langue
\$nom[19] = stripslashes(\"$nom[19]\"); // Livre d'or deuxième langue
\$nom[20] = stripslashes(\"$nom[20]\"); // Recherche langue principale
\$nom[21] = stripslashes(\"$nom[21]\"); // Recherche deuxième langue
\$nom[22] = stripslashes(\"$nom[22]\"); // Forum langue principale
\$nom[23] = stripslashes(\"$nom[23]\"); // Forum deuxième langue
\$nom[24] = stripslashes(\"$nom[24]\"); // FAQ langue principale
\$nom[25] = stripslashes(\"$nom[25]\"); // FAQ deuxième langue
\$nom[26] = stripslashes(\"$nom[26]\"); // Statistiques langue principale
\$nom[27] = stripslashes(\"$nom[27]\"); // Statistiques deuxième langue
\$nom[28] = stripslashes(\"$nom[28]\"); // Recommander langue principale
\$nom[29] = stripslashes(\"$nom[29]\"); // Recommander deuxième langue
\$nom[30] = stripslashes(\"$nom[30]\"); // Boite des articles droite langue principale
\$nom[31] = stripslashes(\"$nom[31]\"); // Boite des articles droite deuxième langue
\$nom[32] = stripslashes(\"$nom32\"); // Boite Calendrier langue principale
\$nom[33] = stripslashes(\"$nom33\"); // Boite Calendrier deuxième langue
\$nom[34] = stripslashes(\"$nom34\"); // Boite préférences utilisateur langue principale
\$nom[35] = stripslashes(\"$nom35\"); // Boite préférences utilisateur deuxième langue

\$page[0] = stripslashes(\"$page[0]\"); // Arrière-plan de la page
\$page[1] = stripslashes(\"$page[1]\"); // Police du site
\$page[2] = stripslashes(\"$page[2]\"); // Taille des textes du site
\$page[3] = stripslashes(\"$page[3]\"); // Image de fond du site
\$page[4] = stripslashes(\"$page[4]\"); // Logo du site
\$page[5] = stripslashes(\"$page[5]\"); // Arrière-plan du bandeau
\$page[6] = stripslashes(\"$page[6]\"); // Image de fond du bandeau
\$page[7] = stripslashes(\"$page[7]\"); // Transition entre pages
\$page[8] = stripslashes(\"$page[8]\"); // Affichage Temps de chargement de page ON / OFF
\$page[9] = stripslashes(\"$page[9]\"); // Thème d'icones
\$page[10] = stripslashes(\"$page[10]\"); // Image de fond fixe / mouvante
\$page[11] = stripslashes(\"$page[11]\"); // Thème de compteur de visites
\$page[12] = stripslashes(\"$page[12]\"); // Thème smileys

\$titre[0] = stripslashes(\"$titre[0]\"); // Couleur du titre
\$titre[1] = stripslashes(\"$titre[1]\"); // Arrière-plan du titre
\$titre[2] = stripslashes(\"$titre[2]\"); // Police des titres
\$titre[3] = stripslashes(\"$titre[3]\"); // Taille des titres

\$texte[0] = stripslashes(\"$texte[0]\"); // Couleur des textes dans les cadres
\$texte[1] = stripslashes(\"$texte[1]\"); // Arrière-plan des textes dans les cadres OFF
\$texte[2] = stripslashes(\"$texte[2]\"); // Arrière-plan des textes dans les cadres ON
\$texte[3] = stripslashes(\"$texte[3]\"); // *** Position des cadres ***
\$texte[4] = stripslashes(\"$texte[4]\"); // Taille des bordures de cadres

\$bordure[0] = stripslashes(\"$bordure[0]\"); // Couleur des bordures
\$bordure[1] = stripslashes(\"$bordure[1]\"); // Couleur de la base de la barre de défilement
\$bordure[2] = stripslashes(\"$bordure[2]\"); // Couleur des flèches de la barre de défilement

\$lien[0] = stripslashes(\"$lien[0]\"); // Lien OFF
\$lien[1] = stripslashes(\"$lien[1]\"); // Lien ON

\$serviz[0] = stripslashes(\"$serviz[0]\"); // Citations ON / OFF
\$serviz[1] = stripslashes(\"$serviz[1]\"); // Accueil Editorial ON / OFF
\$serviz[2] = stripslashes(\"$serviz[2]\"); // Nb de news / page
\$serviz[3] = stripslashes(\"$serviz[3]\"); // Boite Articles gauche ON / OFF
\$serviz[4] = stripslashes(\"$serviz[4]\"); // Nb de téléchargements / page
\$serviz[5] = stripslashes(\"$serviz[5]\"); // Nb de liens / page
\$serviz[6] = stripslashes(\"$serviz[6]\"); // Nb de FAQ / page
\$serviz[7] = stripslashes(\"$serviz[7]\"); // Nb de messages Guestbook / page
\$serviz[8] = stripslashes(\"$serviz[8]\"); // Nouvelles ON / OFF
\$serviz[9] = stripslashes(\"$serviz[9]\"); // Photos ON / OFF
\$serviz[10] = stripslashes(\"$serviz[10]\"); // Téléchargements ON / OFF
\$serviz[11] = stripslashes(\"$serviz[11]\"); // Liens ON / OFF
\$serviz[12] = stripslashes(\"$serviz[12]\"); // Livre d'or ON / OFF
\$serviz[13] = stripslashes(\"$serviz[13]\"); // Forum ON / OFF
\$serviz[14] = stripslashes(\"$serviz[14]\"); // FAQ ON / OFF
\$serviz[15] = stripslashes(\"$serviz[15]\"); // Statistiques ON / OFF
\$serviz[16] = stripslashes(\"$serviz[16]\"); // Publication Nouvelles ON / OFF
\$serviz[17] = stripslashes(\"$serviz[17]\"); // Nb de messages Forum / page
\$serviz[18] = stripslashes(\"$serviz[18]\"); // Catégories Forum ON / OFF
\$serviz[19] = stripslashes(\"$serviz[19]\"); // Bannières ON / OFF
\$serviz[20] = stripslashes(\"$serviz[20]\"); // Nb de messages Thread / page
\$serviz[21] = stripslashes(\"$serviz[21]\"); // Photorama avancé ON /OFF
\$serviz[22] = stripslashes(\"$serviz[22]\"); // Boite Articles droit ON / OFF
\$serviz[23] = stripslashes(\"$serviz[23]\"); // Sondage ON / OFF
\$serviz[24] = stripslashes(\"$serviz[24]\"); // Recherche ON / OFF
\$serviz[25] = stripslashes(\"$serviz25\"); // Menu dynamique Articles gauche
\$serviz[26] = stripslashes(\"$serviz26\"); // Menu dynamique Articles droit
\$serviz[27] = stripslashes(\"$serviz27\"); // Soumission de news
\$serviz[28] = stripslashes(\"$serviz28\"); // Préférences visiteurs

\$posbox[0] = stripslashes(\"$posbox[0]\"); // Première boite à droite
\$posbox[1] = stripslashes(\"$posbox[1]\"); // Seconde boite à droite
\$posbox[2] = stripslashes(\"$posbox[2]\"); // Troisième boite à droite
\$posbox[3] = stripslashes(\"$posbox[3]\"); // Quatrième boite à droite
\$posbox[4] = stripslashes(\"$posbox[4]\"); // Cinquième boite à droite
\$posbox[5] = stripslashes(\"$posbox[5]\"); // Sixième boite à droite
\$posbox[6] = stripslashes(\"$posbox[6]\"); // Septième boite à droite
\$posbox[7] = stripslashes(\"$posbox[7]\"); // Huitième boite à droite
\$posbox[8] = stripslashes(\"$posbox[8]\"); // Neuvième boite à droite
\$posbox[9] = stripslashes(\"$posbox[9]\"); // Première boite à gauche
\$posbox[10] = stripslashes(\"$posbox[10]\"); // Seconde boite à gauche
\$posbox[11] = stripslashes(\"$posbox[11]\"); // Troisième boite à gauche
\$posbox[12] = stripslashes(\"$posbox[12]\"); // Quatrième boite à gauche
\$posbox[13] = stripslashes(\"$posbox[13]\"); // Cinquième boite à gauche
\$posbox[14] = stripslashes(\"$posbox[14]\"); // Sixième  boite à gauche
\$posbox[15] = stripslashes(\"$posbox[15]\"); // Septième  boite à gauche
\$posbox[16] = stripslashes(\"$posbox[16]\"); // Huitième  boite à gauche
\$posbox[17] = stripslashes(\"$posbox[17]\"); // Neuvième  boite à gauche

\$supervision[0] = stripslashes(\"$supervision[0]\"); // e-mail compteur
\$supervision[1] = stripslashes(\"$supervision[1]\"); // incrément de compteur pour e-mail
\$supervision[2] = stripslashes(\"$supervision[2]\"); // e-mail publication nouvelle
\$supervision[3] = stripslashes(\"$supervision[3]\"); // e-mail publication livre d'or
\$supervision[4] = stripslashes(\"$supervision[4]\"); // e-mail publication forum
\$supervision[5] = stripslashes(\"$supervision[5]\"); // Type d'e-mail PHP

\$calendar[0] = stripslashes(\"$calendar0\"); // Couleur de fond des jours libre du mois
\$calendar[1] = stripslashes(\"$calendar1\"); // Couleur de fond du calendrier
\$calendar[2] = stripslashes(\"$calendar2\"); // Couleur de fond de la journée
\$calendar[3] = stripslashes(\"$calendar3\"); // Couleur de fond des dimanches
\$calendar[4] = stripslashes(\"$calendar4\"); // Couleur de fond de la journée quand c'est un dimanche
\$calendar[5] = stripslashes(\"$calendar5\"); // Police du calendrier
\$calendar[6] = stripslashes(\"$calendar6\"); // Taille de la police du calendrier
\$calendar[7] = stripslashes(\"$calendar7\"); // Couleurs de la police des chiffres
\$calendar[8] = stripslashes(\"$calendar8\"); // Couleurs de la police des jours de la semaine
\$calendar[9] = stripslashes(\"$calendar9\"); // Taille des bordures du calendrier
\$calendar[10] = stripslashes(\"$calendar10\"); // Couleur des bordures du calendrier
\$calendar[11] = stripslashes(\"$calendar11\"); // Largeur du calendrier dans sa boîte

\$citation[0] = stripslashes(\"$citation0\"); // Police des citations
\$citation[1] = stripslashes(\"$citation1\"); // Taille de la police des citations
\$citation[2] = stripslashes(\"$citation2\"); // Couleur de la police des citations

\$presform[0] = stripslashes(\"$presform0\"); // Couleur des textes dans les boites de choix et boutons de commande
\$presform[1] = stripslashes(\"$presform1\"); // Couleur des boites de choix
\$presform[2] = stripslashes(\"$presform2\"); // Couleur des boutons de commande
\$presform[3] = stripslashes(\"$presform3\"); // Couleur des zone de texte
\$presform[4] = stripslashes(\"$presform4\"); // Police dans la présentation des formulaires
\$presform[5] = stripslashes(\"$presform5\"); // Taille de la police dans la présentation des formulaires
\$presform[6] = stripslashes(\"$presform6\"); // Couleur de fond des textarea
\$presform[7] = stripslashes(\"$presform7\"); // Taille de la bordure
\$presform[8] = stripslashes(\"$presform8\"); // Couleur de la bordure
?>"; ?>
<?php
  WriteFullDB(CHEMIN.DATAREP."config.inc",$mettre);
}

function WriteNewVersion() {
  global $version;
  $txt = "<?php
\$DBversion = \"$version\";
?>"; ?> <?php
  WriteFullDB(CHEMIN.DATAREP."dbversion.php",$txt);
}
?>
<html>
<head>
<title><?php echo $clean1; ?></title>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset; ?>">
<SCRIPT LANGUAGE="JavaScript">
  function redir(param) {
    window.location = param;
  }
</SCRIPT>
</head>
<body bgcolor="#FFFFFF">
<p align="center"><img src="mplogo.gif"></p>
<?php
if (empty($form)) {
?>
<p align="center"><a href="Javascript: redir('<?php echo $scriptname ?>?lng=fr'); "><img src="<?php echo CHEMIN; ?>inc/lang/fr.gif" width="24" height="16" border="0"></a>&nbsp;&nbsp;&nbsp;&nbsp;<a href="Javascript: redir('<?php echo $scriptname ?>?lng=en'); "><img src="<?php echo CHEMIN; ?>inc/lang/en.gif" width="24" height="16" border="0"></a></p>
<?php
  DisplayTitre($clean1,$clean2."<br /><br />".$clean3);
?>
<form name="instal0" action="<?php echo $scriptname ?>?lng=<?php echo $lng; ?>" method="POST">
<input type="hidden" name="form" value="1">
<center><input type="submit" value="<?php echo $clean4; ?>"></center>
</form>
<?php
}
elseif ($form == "1") {
  DisplayTitre($clean5,$clean6);
?>
<form name="instal1" action="<?php echo $scriptname ?>?lng=<?php echo $lng; ?>" method="POST">
<input type="hidden" name="form" value="2">
<center><input type="submit" value="<?php echo $clean4; ?>"></center>
</form>
<?php
}
elseif ($form == "2") {
  if (empty($doing)) {
    MigrateConfig();
    DisplayProcess($clean5,$clean7,$clean8);
    $nextstep = $scriptname."?lng=".$lng."&form=2&doing=1";
  }
  elseif ($doing == "1") {
    $nf = DatasToPhp5('data');
    DisplayProcess($clean5,$clean13,$nf.$clean14);
    $nextstep = $scriptname."?lng=".$lng."&form=2&doing=2";
  }
  elseif ($doing == "2") {
    WriteNewVersion();
    DisplayProcess($clean5,$clean9."<br />",$clean8);
    $nextstep = $scriptname."?lng=".$lng."&form=3";
    $dodo = 2;
  }
}
elseif ($form == "3") {
  DisplayTitre($clean1,$clean10);
?>
<form name="instal3" action="<?php echo $scriptname ?>?lng=<?php echo $lng; ?>" method="POST">
<input type="hidden" name="form" value="4">
<center><input type="submit" value="<?php echo $clean11; ?>">
</form>
<?php
}
else {
  $nextstep = "migrate24.php?lng=".$lng;
  $dodo = 0;
}
?>
<p align="center">&nbsp;</p>
<p align="center"><img border="0" src="mpslogo.gif" width="88" height="31"></p>
<p align="center">miniPortail v<?php echo $version; ?><br />GNU Public License - © 2002-2003</p>
</body></html>
<?php
if ($nextstep != "") {
  if ($dodo != 0) {
    sleep($dodo);
  }
?>
<script language="JavaScript">
  redir('<?php echo $nextstep; ?>');
</script>
<?php
}
?>
