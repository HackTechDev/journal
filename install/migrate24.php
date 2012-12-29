<?
/*
  Migrate from previous version - GuppY PHP Script - version 4.0
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Made by Laurent Duveau, Nicolas Alves, Albert Aymard, 
	Jean-Michel Misrachi, Isabelle Marchina and Team
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v2.0 (27 February 2003)  : initial release
      v2.2 (22 April 2003)     : full rewrite
      v2.3 (27 July 2003)      : upgraded the installation / migration script
      v2.4 (24 September 2003) : added $config variable
                                 upgrade for v2.4 compatibility
      v3.0 (25 February 2004)  : changed userindex.php by backindex.php in CreateUserMsg()
      v3.0p1 (26 Feb 2004)     : bug fix, now migrates correctly the doc[n].inc files
	  v4.6.19 (30 March 2012)  : set datas in conformity with php5 by Saxbar
*/

header("Pragma: no-cache");
$chemin = "../";
include($chemin."inc/reglobals.inc");
$version = "4.0";
$scriptname = "migrate24.php";

include("functions24.php");

if ($lng == "en") {
  $clean1 = "MIGRATE GUPPY TO VERSION ".$version;
  $clean2 = "<CENTER>This script is ment:</CENTER><UL><LI>for migrating to GuppY version ".$version." from a version 2.3 of miniPortail</UL>";
  $clean3 = "<CENTER><U>IMPORTANT:</U> make sure that you carefully read the <A HREF=\"../readme.html\">readme.html</A> file (I even advise you to print it) before going on.</CENTER>";
  $clean4 = "Let's go!";
  $clean5 = "Migration to version ".$version;
  $clean6 = "<CENTER>You are about to launch a migration to version ".$version."</CENTER>";
  $clean7 = "<CENTER>Migration to version ".$version." ON GOING.</CENTER>";
  $clean8 = "<CENTER>Step #1/7: Parametrization migrated.</CENTER>";
  $clean9 = "<CENTER>Step #2/7: Main database being migrated (";
  $clean10 = ")<CENTER>";
  $clean11 = "<CENTER>Step #2/7: Main database migrated.</CENTER>";
  $clean12 = "<CENTER>Step #3/7: Secondary database migrated.</CENTER>";
  $clean13 = "<CENTER>Step #4/7: Main index migrated.</CENTER>";
  $clean14 = "<CENTER>Step #5/7: Secondary indexes migrated.</CENTER>";
  $clean15 = "<CENTER>Step #6/7 : Forum indexes migrated.</CENTER>";
  $clean16 = "<CENTER>Step #7/7: Creation of data/usermsg/ directory done.</CENTER>";
  $clean17 = "<CENTER>Migration to version ".$version." DONE.</CENTER>";
  $clean18 = "<CENTER>The migration to version ".$version." of GuppY is now over.</CENTER>";
  $clean19 = "Next";
  $clean20 = 'Setting in conformity datas to php 5';
  $clean21 = ' files processed.';
}
else {
  $lng = "fr";
  $clean1 = "MIGRATION DE GUPPY EN VERSION ".$version;
  $clean2 = "<CENTER>Ce script permet :</CENTER><UL><LI>de migrer à la version ".$version." de GuppY à partir d'une version 2.3 de miniPortail</UL>";
  $clean3 = "<CENTER><U>IMPORTANT :</U> assurez-vous de bien avoir lu le fichier <A HREF=\"../lisezmoi.txt\">lisezmoi.txt</A> (je vous conseille même de l'imprimer) avant de poursuivre.</CENTER>";
  $clean4 = "Allons-y !";
  $clean5 = "Migration à la version ".$version;
  $clean6 = "<CENTER>Vous êtes sur le point de lancer une migration à la version ".$version."</CENTER>";
  $clean7 = "<CENTER>Migration à la version ".$version." EN COURS.</CENTER>";
  $clean8 = "<CENTER>Etape n°1/7 : Migration du paramétrage terminée.</CENTER>";
  $clean9 = "<CENTER>Etape n°2/7 : Migration de la base de données principale en cours (";
  $clean10 = ")<CENTER>";
  $clean11 = "<CENTER>Etape n°2/7 : Migration de la base de données principale terminée.</CENTER>";
  $clean12 = "<CENTER>Etape n°3/7 : Migration de la base de données secondaire terminée.</CENTER>";
  $clean13 = "<CENTER>Etape n°4/7 : Migration de l'index principal terminée.</CENTER>";
  $clean14 = "<CENTER>Etape n°5/7 : Migration des index secondaires terminée.</CENTER>";
  $clean15 = "<CENTER>Etape n°6/7 : Migration des index du forum terminée.</CENTER>";
  $clean16 = "<CENTER>Etape n°7/7 : Création du répertoire data/usermsg/ effectuée.</CENTER>";
  $clean17 = "<CENTER>Migration à la version ".$version." TERMINEE.</CENTER>";
  $clean18 = "<CENTER>La migration en version ".$version." de GuppY est maintenant terminée.</CENTER>";
  $clean19 = "Suivant";
  $clean20 = 'Mise en conformité des datas au php 5';
  $clean21 = ' fichiers traités.';
}

$nextstep = "";
$dodo = 1;

function DisplayTitre($titre,$texte) {
?>
<H3><CENTER><? echo $titre; ?></CENTER></H3>
<table width="90%" align="center" cellpadding="0" cellspacing="0">
<tr><td bgcolor="#DDDDFF">
<br><? echo $texte; ?><br>
</td></tr>
</table>
<?
}

function DisplayProcess($titre,$processus,$resultat) {
  DisplayTitre($titre,$processus);
?>
<p align="center">&nbsp;</p>
<table width="50%" align="center" cellpadding="0" cellspacing="0">
<tr><td bgcolor="#FF9933">
<br><? echo $resultat; ?><br>
</td></tr>
</table>
<?
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
  global $config;
  include($config);
  if ($site[19] == "US") {
    $site19 = "U1";
  }
  else {
    $site19 = "E1";
  }
  $site20 = "5";
  $site21 = "";
  $site22 = "H1";
  $site23 = "@";
  $page13 = "";
  $texte3 = "&#149;";
  $serviz29 = "";
  $serviz30 = "5";
  $serviz31 = "";
  $serviz32 = "";
  $serviz33 = "";
  $serviz34 = "";
  $serviz35 = "";
  if ($posbox[0] == "boxfree") {
    $posbox0 = "boxfree1";
  }
  else {
    $posbox0 = $posbox[0];
  }
  if ($posbox[1] == "boxfree") {
    $posbox1 = "boxfree1";
  }
  else {
    $posbox1 = $posbox[1];
  }
  if ($posbox[2] == "boxfree") {
    $posbox2 = "boxfree1";
  }
  else {
    $posbox2 = $posbox[2];
  }
  if ($posbox[3] == "boxfree") {
    $posbox3 = "boxfree1";
  }
  else {
    $posbox3 = $posbox[3];
  }
  if ($posbox[4] == "boxfree") {
    $posbox4 = "boxfree1";
  }
  else {
    $posbox4 = $posbox[4];
  }
  if ($posbox[5] == "boxfree") {
    $posbox5 = "boxfree1";
  }
  else {
    $posbox5 = $posbox[5];
  }
  if ($posbox[6] == "boxfree") {
    $posbox6 = "boxfree1";
  }
  else {
    $posbox6 = $posbox[6];
  }
  if ($posbox[7] == "boxfree") {
    $posbox7 = "boxfree1";
  }
  else {
    $posbox7 = $posbox[7];
  }
  if ($posbox[8] == "boxfree") {
    $posbox8 = "boxfree1";
  }
  else {
    $posbox8 = $posbox[8];
  }
  if ($posbox[9] == "boxfree") {
    $posbox9 = "boxfree1";
  }
  else {
    $posbox9 = $posbox[9];
  }
  if ($posbox[10] == "boxfree") {
    $posbox10 = "boxfree1";
  }
  else {
    $posbox10 = $posbox[10];
  }
  if ($posbox[11] == "boxfree") {
    $posbox11 = "boxfree1";
  }
  else {
    $posbox11 = $posbox[11];
  }
  if ($posbox[12] == "boxfree") {
    $posbox12 = "boxfree1";
  }
  else {
    $posbox12 = $posbox[12];
  }
  if ($posbox[13] == "boxfree") {
    $posbox13 = "boxfree1";
  }
  else {
    $posbox13 = $posbox[13];
  }
  if ($posbox[14] == "boxfree") {
    $posbox14 = "boxfree1";
  }
  else {
    $posbox14 = $posbox[14];
  }
  if ($posbox[15] == "boxfree") {
    $posbox15 = "boxfree1";
  }
  else {
    $posbox15 = $posbox[15];
  }
  if ($posbox[16] == "boxfree") {
    $posbox16 = "boxfree1";
  }
  else {
    $posbox16 = $posbox[16];
  }
  if ($posbox[17] == "boxfree") {
    $posbox17 = "boxfree1";
  }
  else {
    $posbox17 = $posbox[17];
  }
  if ($supervision[5] == "online") {
    $supervision5 = "online.net";
  }
  elseif ($supervision[5] == "nexen") {
    $supervision5 = "nexen.net";
  }
  else {
    $supervision5 = "standard";
  }
  $supervision6 = "";
  $editobox0 = "boxhome";
  $editobox1 = "boxnews";
  $editobox2 = "";
  $editobox3 = "";
  
  $mettre = "<?
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
\$site[20] = stripslashes(\"$site20\"); // Messages Forum sur la page d'accueil
\$site[21] = stripslashes(\"$site21\"); // ID du message Livre d'or préféré
\$site[22] = stripslashes(\"$site22\"); // Format Heure
\$site[23] = stripslashes(\"$site23\"); // Séparateur Date & Heure

\$lang[0] = stripslashes(\"$lang[0]\"); // Langue principale du site
\$lang[1] = stripslashes(\"$lang[1]\"); // Deuxième langue du site

\$user[0] = stripslashes(\"$user[0]\"); // Webmaster
\$user[1] = stripslashes(\"$user[1]\"); // e-mail du responsable du site
\$user[2] = stripslashes(\"$user[2]\"); // # ICQ

\$nom[0] = stripslashes(\"$nom[0]\"); // Nom de l'accueil langue principale
\$nom[1] = stripslashes(\"$nom[1]\"); // Page des téléchargements langue principale
\$nom[2] = stripslashes(\"$nom[2]\"); // Page des images langue principale
\$nom[3] = stripslashes(\"$nom[3]\"); // Page des liens langue principale
\$nom[4] = stripslashes(\"$nom[4]\"); // Boite des articles à gauche langue principale
\$nom[5] = stripslashes(\"$nom[5]\"); // Boite spéciale langue principale
\$nom[6] = stripslashes(\"$nom[6]\"); // Sondage langue principale
\$nom[7] = stripslashes(\"$nom[7]\"); // Nouvelles langue principale
\$nom[8] = stripslashes(\"$nom[8]\"); // Compteur langue principale
\$nom[9] = stripslashes(\"$nom[9]\"); // Livre d'or langue principale
\$nom[10] = stripslashes(\"$nom[10]\"); // Nom de l'accueil deuxième langue
\$nom[11] = stripslashes(\"$nom[11]\"); // Page des téléchargements deuxième langue
\$nom[12] = stripslashes(\"$nom[12]\"); // Page des images deuxième langue
\$nom[13] = stripslashes(\"$nom[13]\"); // Page des liens deuxième langue
\$nom[14] = stripslashes(\"$nom[14]\"); // Boite des articles à gauche deuxième langue
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
\$nom[30] = stripslashes(\"$nom[30]\"); // Boite des articles à droite langue principale
\$nom[31] = stripslashes(\"$nom[31]\"); // Boite des articles à droite deuxième langue
\$nom[32] = stripslashes(\"$nom[32]\"); // Boite Calendrier langue principale
\$nom[33] = stripslashes(\"$nom[33]\"); // Boite Calendrier deuxième langue
\$nom[34] = stripslashes(\"$nom[34]\"); // Boite préférences utilisateur langue principale
\$nom[35] = stripslashes(\"$nom[35]\"); // Boite préférences utilisateur deuxième langue

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
\$page[13] = stripslashes(\"$page13\"); // Image Page en cours de chargement

\$titre[0] = stripslashes(\"$titre[0]\"); // Couleur du titre
\$titre[1] = stripslashes(\"$titre[1]\"); // Arrière-plan du titre
\$titre[2] = stripslashes(\"$titre[2]\"); // Police des titres
\$titre[3] = stripslashes(\"$titre[3]\"); // Taille des titres

\$texte[0] = stripslashes(\"$texte[0]\"); // Couleur des textes dans les cadres
\$texte[1] = stripslashes(\"$texte[1]\"); // Arrière-plan des textes dans les cadres OFF
\$texte[2] = stripslashes(\"$texte[2]\"); // Arrière-plan des textes dans les cadres ON
\$texte[3] = stripslashes(\"$texte3\"); // Puce articles
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
\$serviz[25] = stripslashes(\"$serviz[25]\"); // Menu dynamique Articles gauche
\$serviz[26] = stripslashes(\"$serviz[26]\"); // Menu dynamique Articles droit
\$serviz[27] = stripslashes(\"$serviz[27]\"); // Soumission de news
\$serviz[28] = stripslashes(\"$serviz[28]\"); // Préférences visiteurs
\$serviz[29] = stripslashes(\"$serviz29\"); // Réactions aux articles
\$serviz[30] = stripslashes(\"$serviz30\"); // Nb Réactions aux articles / page
\$serviz[31] = stripslashes(\"$serviz31\"); // Masquer l'icone Admin
\$serviz[32] = stripslashes(\"$serviz32\"); // Icone d'accès rapide au contenu d'un article
\$serviz[33] = stripslashes(\"$serviz33\"); // Compteur de lecture Articles
\$serviz[34] = stripslashes(\"$serviz34\"); // Compteur de lecture Threads Forum
\$serviz[35] = stripslashes(\"$serviz35\"); // Compteur de Nb de téléchargements

\$posbox[0] = stripslashes(\"$posbox0\"); // Première boite à droite
\$posbox[1] = stripslashes(\"$posbox1\"); // Seconde boite à droite
\$posbox[2] = stripslashes(\"$posbox2\"); // Troisième boite à droite
\$posbox[3] = stripslashes(\"$posbox3\"); // Quatrième boite à droite
\$posbox[4] = stripslashes(\"$posbox4\"); // Cinquième boite à droite
\$posbox[5] = stripslashes(\"$posbox5\"); // Sixième boite à droite
\$posbox[6] = stripslashes(\"$posbox6\"); // Septième boite à droite
\$posbox[7] = stripslashes(\"$posbox7\"); // Huitième boite à droite
\$posbox[8] = stripslashes(\"$posbox8\"); // Neuvième boite à droite
\$posbox[9] = stripslashes(\"$posbox9\"); // Première boite à gauche
\$posbox[10] = stripslashes(\"$posbox10\"); // Seconde boite à gauche
\$posbox[11] = stripslashes(\"$posbox11\"); // Troisième boite à gauche
\$posbox[12] = stripslashes(\"$posbox12\"); // Quatrième boite à gauche
\$posbox[13] = stripslashes(\"$posbox13\"); // Cinquième boite à gauche
\$posbox[14] = stripslashes(\"$posbox14\"); // Sixième  boite à gauche
\$posbox[15] = stripslashes(\"$posbox15\"); // Septième  boite à gauche
\$posbox[16] = stripslashes(\"$posbox16\"); // Huitième  boite à gauche
\$posbox[17] = stripslashes(\"$posbox17\"); // Neuvième  boite à gauche

\$supervision[0] = stripslashes(\"$supervision[0]\"); // e-mail compteur
\$supervision[1] = stripslashes(\"$supervision[1]\"); // incrément de compteur pour e-mail
\$supervision[2] = stripslashes(\"$supervision[2]\"); // e-mail publication nouvelle
\$supervision[3] = stripslashes(\"$supervision[3]\"); // e-mail publication livre d'or
\$supervision[4] = stripslashes(\"$supervision[4]\"); // e-mail publication forum
\$supervision[5] = stripslashes(\"$supervision5\"); // Type d'e-mail PHP
\$supervision[6] = stripslashes(\"$supervision6\"); // e-mail réagir aux articles

\$calendar[0] = stripslashes(\"$calendar[0]\"); // Couleur de fond des jours libre du mois
\$calendar[1] = stripslashes(\"$calendar[1]\"); // Couleur de fond du calendrier
\$calendar[2] = stripslashes(\"$calendar[2]\"); // Couleur de fond de la journée
\$calendar[3] = stripslashes(\"$calendar[3]\"); // Couleur de fond des dimanches
\$calendar[4] = stripslashes(\"$calendar[4]\"); // Couleur de fond de la journée quand c'est un dimanche
\$calendar[5] = stripslashes(\"$calendar[5]\"); // Police du calendrier
\$calendar[6] = stripslashes(\"$calendar[6]\"); // Taille de la police du calendrier
\$calendar[7] = stripslashes(\"$calendar[7]\"); // Couleurs de la police des chiffres
\$calendar[8] = stripslashes(\"$calendar[8]\"); // Couleurs de la police des jours de la semaine
\$calendar[9] = stripslashes(\"$calendar[9]\"); // Taille des bordures du calendrier
\$calendar[10] = stripslashes(\"$calendar[10]\"); // Couleur des bordures du calendrier
\$calendar[11] = stripslashes(\"$calendar[11]\"); // Largeur du calendrier dans sa boîte

\$citation[0] = stripslashes(\"$citation[0]\"); // Police des citations
\$citation[1] = stripslashes(\"$citation[1]\"); // Taille de la police des citations
\$citation[2] = stripslashes(\"$citation[2]\"); // Couleur de la police des citations

\$presform[0] = stripslashes(\"$presform[0]\"); // Couleur des textes dans les boites de choix et boutons de commande
\$presform[1] = stripslashes(\"$presform[1]\"); // Couleur des boites de choix
\$presform[2] = stripslashes(\"$presform[2]\"); // Couleur des boutons de commande
\$presform[3] = stripslashes(\"$presform[3]\"); // Couleur des zone de texte
\$presform[4] = stripslashes(\"$presform[4]\"); // Police dans la présentation des formulaires
\$presform[5] = stripslashes(\"$presform[5]\"); // Taille de la police dans la présentation des formulaires
\$presform[6] = stripslashes(\"$presform[6]\"); // Couleur de fond des textarea
\$presform[7] = stripslashes(\"$presform[7]\"); // Taille de la bordure
\$presform[8] = stripslashes(\"$presform[8]\"); // Couleur de la bordure

\$editobox[0] = stripslashes(\"$editobox0\"); // Première boite page d'accueil
\$editobox[1] = stripslashes(\"$editobox1\"); // Seconde boite page d'accueil
\$editobox[2] = stripslashes(\"$editobox2\"); // Troisième boite page d'accueil
\$editobox[3] = stripslashes(\"$editobox3\"); // Quatrième boite page d'accueil
?>"; ?>
<?
  WriteFullDB($config,$mettre);
}

function MigrateData($inf,$sup) {
  global $dbbase, $incext, $config,
         $typ_art,$typ_banner,$typ_dnload,$typ_faq,$typ_footer,$typ_forum,
         $typ_freebox1,$typ_freebox2,$typ_freebox3,$typ_freebox4,$typ_guestbk,
         $typ_homepg,$typ_links,$typ_news,$typ_photo,$typ_react,$typ_reco,
         $typ_special,$typ_think,
         $type,$fileid,$status,$creadate,$moddate,$author,$email,
         $fielda1,$fielda2,$fieldb1,$fieldb2,$fieldc1,$fieldc2,$fieldd1,$fieldd2;
  include($config);
  for ($i = $inf; $i <= $sup; $i++) {
    if (FileDBExist($dbbase.$i.$incext)) {
      ReadDoc($i);
      if ($type == "art") {
        $type = $typ_art;
      }
      elseif ($type == "banner") {
        $type = $typ_banner;
      }
      elseif ($type == "dnload") {
        $type = $typ_dnload;
      }
      elseif ($type == "faq") {
        $type = $typ_faq;
      }
      elseif ($type == "footer") {
        $type = $typ_footer;
      }
      elseif ($type == "forum") {
        $type = $typ_forum;
        if ($fielda2 == "new") {
          $fielda2 = "0";
        }
      }
      elseif ($type == "freebox") {
        $type = $typ_freebox1;
      }
      elseif ($type == "guestbk") {
        $type = $typ_guestbk;
      }
      elseif ($type == "homepg") {
        $type = $typ_homepg;
      }
      elseif ($type == "links") {
        $type = $typ_links;
      }
      elseif ($type == "news") {
        $type = $typ_news;
      }
      elseif ($type == "photo") {
        $type = $typ_photo;
      }
      elseif ($type == "react") {
        $type = $typ_react;
      }
      elseif ($type == "reco") {
        $type = $typ_reco;
      }
      elseif ($type == "special") {
        $type = $typ_special;
      }
      elseif ($type == "think") {
        $type = $typ_think;
      }
      if ($site[19] == "U1") {
        $creadate = substr($creadate,6,4).substr($creadate,0,2).substr($creadate,3,2).substr($creadate,13,2).substr($creadate,16,2);
        $moddate = substr($moddate,6,4).substr($moddate,0,2).substr($moddate,3,2).substr($moddate,13,2).substr($moddate,16,2);
      }
      else {
        $creadate = substr($creadate,6,4).substr($creadate,3,2).substr($creadate,0,2).substr($creadate,13,2).substr($creadate,16,2);
        $moddate = substr($moddate,6,4).substr($moddate,3,2).substr($moddate,0,2).substr($moddate,13,2).substr($moddate,16,2);
      }
      $fielda1 = addslashes($fielda1);
      $fielda2 = addslashes($fielda2);
      $fieldb1 = addslashes($fieldb1);
      $fieldb2 = addslashes($fieldb2);
      $fieldc1 = addslashes($fieldc1);
      $fieldc2 = addslashes($fieldc2);
      $fieldd1 = addslashes($fieldd1);
      $fieldd2 = addslashes($fieldd2);
      WriteDoc();
    }
  }
}

function MigrateFreeBox() {
  global $chemin,$datarep,$incext,$dbfreebox1,$dbfreebox2,$dbfreebox3,$dbfreebox4,
         $dbspecial,$dbhomepage,$dbfoot;
  rename($chemin.$datarep."special".$incext,$dbspecial);
  rename($chemin.$datarep."homepage".$incext,$dbhomepage);
  rename($chemin.$datarep."foot".$incext,$dbfoot);
  rename($chemin.$datarep."freebox".$incext,$dbfreebox1);
  $freetitle = "Free Box";
  $freetext = "";
  $txt = "<?
\$freetitle1 = stripslashes(\"$freetitle\");
\$freetitle2 = stripslashes(\"$freetitle\");
\$freetext1 = stripslashes(\"$freetext\");
\$freetext2 = stripslashes(\"$freetext\");
?>"; ?> <?
  WriteFullDB($dbfreebox2,$txt);
  WriteFullDB($dbfreebox3,$txt);
  WriteFullDB($dbfreebox4,$txt);
}

function MigrateMainIndex() {
  global $docid,
         $typ_art,$typ_banner,$typ_dnload,$typ_faq,$typ_footer,$typ_forum,
         $typ_freebox1,$typ_freebox2,$typ_freebox3,$typ_freebox4,$typ_guestbk,
         $typ_homepg,$typ_links,$typ_news,$typ_photo,$typ_react,$typ_reco,
         $typ_special,$typ_think;
  $db = ReadDBFields($docid);
  for ($i = 0; $i < count($db); $i++) {
    if ($db[$i][0] == "art") {
      $db[$i][0] = $typ_art;
    }
    elseif ($db[$i][0] == "banner") {
      $db[$i][0] = $typ_banner;
    }
    elseif ($db[$i][0] == "dnload") {
      $db[$i][0] = $typ_dnload;
    }
    elseif ($db[$i][0] == "faq") {
      $db[$i][0] = $typ_faq;
    }
    elseif ($db[$i][0] == "footer") {
      $db[$i][0] = $typ_footer;
    }
    elseif ($db[$i][0] == "forum") {
      $db[$i][0] = $typ_forum;
    }
    elseif ($db[$i][0] == "freebox") {
      $db[$i][0] = $typ_freebox1;
    }
    elseif ($db[$i][0] == "guestbk") {
      $db[$i][0] = $typ_guestbk;
    }
    elseif ($db[$i][0] == "homepg") {
      $db[$i][0] = $typ_homepg;
    }
    elseif ($db[$i][0] == "links") {
      $db[$i][0] = $typ_links;
    }
    elseif ($db[$i][0] == "news") {
      $db[$i][0] = $typ_news;
    }
    elseif ($db[$i][0] == "photo") {
      $db[$i][0] = $typ_photo;
    }
    elseif ($db[$i][0] == "react") {
      $db[$i][0] = $typ_react;
    }
    elseif ($db[$i][0] == "reco") {
      $db[$i][0] = $typ_reco;
    }
    elseif ($db[$i][0] == "special") {
      $db[$i][0] = $typ_special;
    }
    elseif ($db[$i][0] == "think") {
      $db[$i][0] = $typ_think;
    }
  }
  WriteDBFields($docid,$db);
}

function MigrateIndex() {
  global $chemin,$datarep,$dbext,$dbreact,
         $typ_art,$typ_banner,$typ_dnload,$typ_faq,$typ_footer,$typ_forum,
         $typ_freebox1,$typ_freebox2,$typ_freebox3,$typ_freebox4,$typ_guestbk,
         $typ_homepg,$typ_links,$typ_news,$typ_photo,$typ_react,$typ_reco,
         $typ_special,$typ_think;

  @chmod($chemin.$datarep."art".$dbext,0777);
  @unlink($chemin.$datarep."art".$dbext);
  UpdateDBdtb($typ_art);

  @chmod($chemin.$datarep."dnload".$dbext,0777);
  @unlink($chemin.$datarep."dnload".$dbext);
  UpdateDBdtb($typ_dnload);
  
  @chmod($chemin.$datarep."links".$dbext,0777);
  @unlink($chemin.$datarep."links".$dbext);
  UpdateDBdtb($typ_links);
  
  @chmod($chemin.$datarep."photo".$dbext,0777);
  @unlink($chemin.$datarep."photo".$dbext);
  UpdateDBdtb($typ_photo);

  WriteFullDB($dbreact,"");
  UpdateDBdtb($typ_faq);
}

function MigrateForumIndex() {
  global $chemin,$datarep,$dbext,$dbforumcounter,$dbforumcat;
  WriteCounter($dbforumcounter,0);
  rename($chemin.$datarep."forumcat".$dbext,$dbforumcat);
  @chmod($chemin.$datarep."forum".$dbext,0777);
  unlink($chemin.$datarep."forum".$dbext);
  @chmod($chemin.$datarep."thread".$dbext,0777);
  unlink($chemin.$datarep."thread".$dbext);
  UpdateDBforum("mod",0);
}

function CreateUserMsg() {
  global $userep;
  mkdir ($userep, 0755);
  copy("backindex.php",$userep."index.php");
}

function WriteNewVersion() {
  global $chemin,$datarep,$version;
  $txt = "<?
\$DBversion = \"$version\";
?>"; ?> <?
  WriteFullDB($chemin.$datarep."dbversion.php",$txt);
}
?>
<html>
<head>
<title><? echo $clean1; ?></title>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
<SCRIPT LANGUAGE="JavaScript">
  function redir(param) {
    window.location = param;
  }
</SCRIPT>
</head>
<body bgcolor="#FFFFFF">
<p align="center"><img src="gylogo.gif"></p>
<?
if (empty($form)) {
?>
<p align="center"><a href="Javascript: redir('<? echo $scriptname ?>?lng=fr'); "><img src="<? echo $chemin; ?>inc/lang/fr.gif" width="24" height="16" border="0"></a>&nbsp;&nbsp;&nbsp;&nbsp;<a href="Javascript: redir('<? echo $scriptname ?>?lng=en'); "><img src="<? echo $chemin; ?>inc/lang/en.gif" width="24" height="16" border="0"></a></p>
<?
  DisplayTitre($clean1,$clean2."<br><br>".$clean3);
?>
<form name="instal0" action="<? echo $scriptname ?>?lng=<? echo $lng; ?>" method="POST">
<input type="hidden" name="form" value="1">
<center><input type="submit" value="<? echo $clean4; ?>"></center>
</form>
<?
}
elseif ($form == "1") {
  DisplayTitre($clean5,$clean6);
?>
<form name="instal1" action="<? echo $scriptname ?>?lng=<? echo $lng; ?>" method="POST">
<input type="hidden" name="form" value="2">
<center><input type="submit" value="<? echo $clean4; ?>"></center>
</form>
<?
}
elseif ($form == "2") {
  if (empty($doing)) {
    MigrateConfig();
    DisplayProcess($clean5,$clean7,$clean8);
    $nextstep = $scriptname."?lng=".$lng."&form=2&doing=1";
  }
  elseif ($doing == "1") {
    if ($num == "end") {
      DisplayProcess($clean5,$clean7,$clean8."<br>".$clean11);
      $nextstep = $scriptname."?lng=".$lng."&form=2&doing=2";
      $dodo = 1;
    }
    else {
      $max = ReadCounter($nextid);
      $maxi = Min($num+9,$max);
      MigrateData($num,$maxi);
      $maxi++;
      $max++;
      DisplayProcess($clean5,$clean7,$clean8."<br>".$clean9.$maxi."/".$max.$clean10);
      $nextstep = $scriptname."?lng=".$lng."&form=2&doing=1&num=";
      if ($maxi == $max) {
        $nextstep .= "end";
      }
      else {
        $nextstep .= $maxi;
      }
      $dodo = 0;
    }
  }
  elseif ($doing == "2") {
    MigrateFreeBox();
    DisplayProcess($clean5,$clean7,$clean8."<br>".$clean11."<br>".$clean12);
    $nextstep = $scriptname."?lng=".$lng."&form=2&doing=3";
  }
  elseif ($doing == "3") {
    MigrateMainIndex();
    DisplayProcess($clean5,$clean7,$clean8."<br>".$clean11."<br>".$clean12."<br>".$clean13);
    $nextstep = $scriptname."?lng=".$lng."&form=2&doing=4";
  }
  elseif ($doing == "4") {
    MigrateIndex();
    DisplayProcess($clean5,$clean7,$clean8."<br>".$clean11."<br>".$clean12."<br>".$clean13."<br>".$clean14);
    $nextstep = $scriptname."?lng=".$lng."&form=2&doing=5";
  }
  elseif ($doing == "5") {
    MigrateForumIndex();
    DisplayProcess($clean5,$clean7,$clean8."<br>".$clean11."<br>".$clean12."<br>".$clean13."<br>".$clean14."<br>".$clean15);
    $nextstep = $scriptname."?lng=".$lng."&form=2&doing=6";
  }
  elseif ($doing == "6") {
    CreateUserMsg();
    DisplayProcess($clean5,$clean7,$clean8."<br>".$clean11."<br>".$clean12."<br>".$clean13."<br>".$clean14."<br>".$clean15."<br>".$clean16);
    $nextstep = $scriptname."?lng=".$lng."&form=2&doing=7";
  }
  elseif ($doing == "7") {
    $nf = DatasToPhp5('data');
    DisplayProcess($clean5,$clean20,$nf.$clean21);
    $nextstep = $scriptname."?lng=".$lng."&form=2&doing=8";
  }
  elseif ($doing == "8") {
    WriteNewVersion();
    DisplayProcess($clean5,$clean18."<br>",$clean17);
    $nextstep = $scriptname."?lng=".$lng."&form=3";
    $dodo = 2;
  }
}
elseif ($form == "3") {
  DisplayTitre($clean1,$clean18);
?>
<form name="instal3" action="<? echo $scriptname ?>?lng=<? echo $lng; ?>" method="POST">
<input type="hidden" name="form" value="4">
<center><input type="submit" value="<? echo $clean19; ?>"></center>
</form>
<?
}
else {
  $nextstep = "migrate30.php?lng=".$lng;
  $dodo = 0;
}
?>
<p align="center">&nbsp;</p>
<p align="center"><img border="0" src="gyslogo.gif"></p>
<p align="center">GuppY v<? echo $version; ?><br>CeCILL free Licence - © 2004-2006</p>
</body></html>
<?
if ($nextstep != "") {
  if ($dodo != 0) {
    sleep($dodo);
  }
?>
<script language="JavaScript">
  redir('<? echo $nextstep; ?>');
</script>
<?
}
?>
