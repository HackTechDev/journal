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
	  v4.6.19 (30 March 2012)  : set datas in conformity with php5 by Saxbar
*/

header("Pragma: no-cache");
define("CHEMIN", "../");
include(CHEMIN."inc/reglobals.inc");
$version = "2.2";
$scriptname = "migrate22.php";

include("functions22.php");

if ($lng == "fr") {
  $clean1 = "MIGRATION DE MINIPORTAIL EN VERSION ".$version;
  $clean2 = "<CENTER>Ce script permet :</CENTER><UL><LI>de migrer à la version ".$version." de miniPortail à partir d'une version 1.8 ou ultérieure</UL>";
  $clean3 = "<CENTER><U>IMPORTANT :</U> assurez-vous de bien avoir lu le fichier <A HREF=\"../lisezmoi.html\">lisezmoi.html</A> (je vous conseille même de l'imprimer) avant de poursuivre.</CENTER>";
  $clean4 = "Allons-y !";
  $clean5 = "Migration à la version ".$version;
  $clean6 = "<CENTER>Vous êtes sur le point de lancer une migration à la version ".$version."</CENTER>";
  $clean7 = "<CENTER>Migration à la version ".$version." EN COURS.</CENTER>";
  $clean8 = "<CENTER>Etape n°1/5 : Migration du paramétrage terminée.</CENTER>";
  $clean9 = "<CENTER>Etape n°2/5 : Migration de la base de données principale terminée.</CENTER>";
  $clean10 = "<CENTER>Migration à la version ".$version." TERMINEE.</CENTER>";
  $clean11 = "<CENTER>Etape n°2/5 : Migration de la base de données principale en cours (";
  $clean12 = ")<CENTER>";
  $clean13 = "<CENTER>Etape n°3/5 : Migration de la base de données secondaire terminée.</CENTER>";
  $clean14 = "<CENTER>Etape n°4/5 : Migration des index terminée.</CENTER>";
  $clean15 = "<CENTER>La migration en version ".$version." de miniPortail est maintenant terminée.</CENTER>";
  $clean16 = "Suivant";
  $clean17 = "<CENTER>Step #5/5: Migration de la base de donnée du forum terminée.</CENTER>";
  $clean18 = 'Setting in conformity datas to php 5';
  $clean19 = ' files processed.';
}
else {
  $lng = "en";
  $clean1 = "MIGRATE MINIPORTAIL TO VERSION ".$version;
  $clean2 = "<CENTER>This script is ment:</CENTER><UL><LI>for migrating to miniPortail version ".$version." from a version 1.8 or later</UL>";
  $clean3 = "<CENTER><U>IMPORTANT:</U> make sure that you carefully read the <A HREF=\"../readme.html\">readme.html</A> file (I even advise you to print it) before going on.</CENTER>";
  $clean4 = "Let's go!";
  $clean5 = "Migration to version ".$version;
  $clean6 = "<CENTER>You are about to launch a migration to version ".$version."</CENTER>";
  $clean7 = "<CENTER>Migration to version ".$version." ON GOING.</CENTER>";
  $clean8 = "<CENTER>Step #1/5: Parametrization migrated.</CENTER>";
  $clean9 = "<CENTER>Step #2/5: Main database migrated.</CENTER>";
  $clean10 = "<CENTER>Migration to version ".$version." DONE.</CENTER>";
  $clean11 = "<CENTER>Step #2/5: Main database being migrated (";
  $clean12 = ")<CENTER>";
  $clean13 = "<CENTER>Step #3/5: Secondary database migrated.</CENTER>";
  $clean14 = "<CENTER>Step #4/5: Indexes migrated.</CENTER>";
  $clean15 = "<CENTER>The migration to version ".$version." of miniPortail is now over.</CENTER>";
  $clean16 = "Next";
  $clean17 = "<CENTER>Step #5/5: Forum database migrated.</CENTER>";
  $clean18 = 'Mise en conformité des datas au php 5';
  $clean19 = ' fichiers traités.';
}

$nextstep = "";
$dodo = 1;
$oldsmile = array("inc/img/lunettes.gif",
                  "inc/img/clin.gif",
                  "inc/img/dents.gif",
                  "inc/img/content.gif",
                  "inc/img/couteau.gif",
                  "inc/img/debile.gif",
                  "inc/img/enerve.gif",
                  "inc/img/decu.gif",
                  "inc/img/hallucine.gif",
                  "inc/img/langue.gif",
                  "inc/img/pleure.gif");
$newsmile = array("inc/img/smileys/cool.gif",
                  "inc/img/smileys/wink.gif",
                  "inc/img/smileys/biggrin.gif",
                  "inc/img/smileys/smile.gif",
                  "inc/img/smileys/frown.gif",
                  "inc/img/smileys/eek.gif",
                  "inc/img/smileys/mad.gif",
                  "inc/img/smileys/confused.gif",
                  "inc/img/smileys/rolleyes.gif",
                  "inc/img/smileys/tongue.gif",
                  "inc/img/smileys/cry.gif");

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
	global $page, $titre, $texte, $service;
  include(CHEMIN.DATAREP."config.inc");
  $nom30 = "";
  $nom31 = "";
  if ($page[11] == "") {
    $page11 = "miniportail_1";
  }
  else {
    $page11 = $page[11];
  }
  $page12 = "miniportail_1";
  if ($titre[2] == "Time New Roman, serif") {
    $titre2 = "Times New Roman, serif";
  }
  else {
    $titre2 = $titre[2];
  }
  $texte3 = "";
  $serviz2 = "5";
  $serviz4 = "5";
  $serviz5 = "5";
  $serviz6 = "5";
  $serviz7 = "5";
  $serviz17 = "10";
  $serviz20 = "5";
  $serviz22 = "";
  $posbox0 = "";
  $posbox1 = "";
  $posbox2 = "";
  $posbox3 = "";
  $posbox4 = "";
  $posbox5 = "";
  $posbox6 = "";
  $posbox7 = "";
  $posbox8 = "";
  $posbox9 = "";
  $posbox10 = "";
  $posbox11 = "";
  $posbox12 = "";
  $posbox13 = "";
  $posbox14 = "";
  $posbox15 = "";
  $posbox16 = "";
  $posbox17 = "";
  if ($texte[3] == "rightleft") {
    if ($service[2] == "on") {
      $posbox0 = "boxspec";
    }
    if ($service[20] == "on") {
      $posbox1 = "boxfree";
    }
    if ($service[4] == "on") {
      $posbox2 = "boxsearch";
    }
    if ($service[5] == "on") {
      $posbox3 = "boxpoll";
    }
    if ($service[3] == "on") {
      $posbox9 = "boxartg";
    }
    if ($service[6] == "on") {
      $posbox10 = "boxwebm";
    }
    if ($service[17] == "on") {
      $posbox11 = "boxreco";
    }
    if ($service[7] == "on") {
      $posbox12 = "boxcount";
    }
  }
  else {
    if ($service[2] == "on") {
      $posbox9 = "boxspec";
    }
    if ($service[3] == "on") {
      $posbox10 = "boxartg";
    }
    if ($service[20] == "on") {
      $posbox11 = "boxfree";
    }
    if ($service[4] == "on") {
      $posbox12 = "boxsearch";
    }
    if ($service[5] == "on") {
      $posbox13 = "boxpoll";
    }
    if ($service[6] == "on") {
      $posbox14 = "boxwebm";
    }
    if ($service[17] == "on") {
      $posbox15 = "boxreco";
    }
    if ($service[7] == "on") {
      $posbox16 = "boxcount";
    }
  }
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
\$nom[30] = stripslashes(\"$nom30\"); // Boite des articles droite langue principale
\$nom[31] = stripslashes(\"$nom31\"); // Boite des articles droite deuxième langue

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
\$page[11] = stripslashes(\"$page11\"); // Thème de compteur de visites
\$page[12] = stripslashes(\"$page12\"); // Thème smileys

\$titre[0] = stripslashes(\"$titre[0]\"); // Couleur du titre
\$titre[1] = stripslashes(\"$titre[1]\"); // Arrière-plan du titre
\$titre[2] = stripslashes(\"$titre2\"); // Police des titres
\$titre[3] = stripslashes(\"$titre[3]\"); // Taille des titres

\$texte[0] = stripslashes(\"$texte[0]\"); // Couleur des textes dans les cadres
\$texte[1] = stripslashes(\"$texte[1]\"); // Arrière-plan des textes dans les cadres OFF
\$texte[2] = stripslashes(\"$texte[2]\"); // Arrière-plan des textes dans les cadres ON
\$texte[3] = stripslashes(\"$texte3\"); // *** Position des cadres ***
\$texte[4] = stripslashes(\"$texte[4]\"); // Taille des bordures de cadres

\$bordure[0] = stripslashes(\"$bordure[0]\"); // Couleur des bordures
\$bordure[1] = stripslashes(\"$bordure[1]\"); // Couleur de la base de la barre de défilement
\$bordure[2] = stripslashes(\"$bordure[2]\"); // Couleur des flèches de la barre de défilement

\$lien[0] = stripslashes(\"$lien[0]\"); // Lien OFF
\$lien[1] = stripslashes(\"$lien[1]\"); // Lien ON

\$serviz[0] = stripslashes(\"$service[0]\"); // Citations ON / OFF
\$serviz[1] = stripslashes(\"$service[1]\"); // Accueil Editorial ON / OFF
\$serviz[2] = stripslashes(\"$serviz2\"); // Nb de news / page
\$serviz[3] = stripslashes(\"$service[3]\"); // Boite Articles gauche ON / OFF
\$serviz[4] = stripslashes(\"$serviz4\"); // Nb de téléchargements / page
\$serviz[5] = stripslashes(\"$serviz5\"); // Nb de liens / page
\$serviz[6] = stripslashes(\"$serviz6\"); // Nb de FAQ / page
\$serviz[7] = stripslashes(\"$serviz7\"); // Nb de messages Guestbook / page
\$serviz[8] = stripslashes(\"$service[8]\"); // Nouvelles ON / OFF
\$serviz[9] = stripslashes(\"$service[9]\"); // Photos ON / OFF
\$serviz[10] = stripslashes(\"$service[10]\"); // Téléchargements ON / OFF
\$serviz[11] = stripslashes(\"$service[11]\"); // Liens ON / OFF
\$serviz[12] = stripslashes(\"$service[12]\"); // Livre d'or ON / OFF
\$serviz[13] = stripslashes(\"$service[13]\"); // Forum ON / OFF
\$serviz[14] = stripslashes(\"$service[14]\"); // FAQ ON / OFF
\$serviz[15] = stripslashes(\"$service[15]\"); // Statistiques ON / OFF
\$serviz[16] = stripslashes(\"$service[16]\"); // Publication Nouvelles ON / OFF
\$serviz[17] = stripslashes(\"$serviz17\"); // Nb de messages Forum / page
\$serviz[18] = stripslashes(\"$service[18]\"); // Catégories Forum ON / OFF
\$serviz[19] = stripslashes(\"$service[19]\"); // Bannières ON / OFF
\$serviz[20] = stripslashes(\"$serviz20\"); // Nb de messages Thread / page
\$serviz[21] = stripslashes(\"$service[21]\"); // Photorama avancé ON /OFF
\$serviz[22] = stripslashes(\"$serviz22\"); // Boite Articles droit ON / OFF
\$serviz[23] = stripslashes(\"$service[5]\"); // Sondage ON / OFF
\$serviz[24] = stripslashes(\"$service[4]\"); // Recherche ON / OFF

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
\$supervision[5] = stripslashes(\"$supervision[5]\"); // Type d'e-mail PHP
?>"; ?>
<?php
  WriteFullDB(CHEMIN.DATAREP."config.inc",$mettre);
}

function MigrateData($inf,$sup) {
  global $oldsmile, $newsmile, $type;
  for ($i = $inf; $i <= $sup; $i++) {
    if (is_file(DBBASE.$i.INCEXT)) {
      include(DBBASE.$i.INCEXT);
      for ($j = 0; $j < count($oldsmile); $j++) {
        $fielda1 = str_replace($oldsmile[$j],$newsmile[$j],$fielda1);
        $fielda2 = str_replace($oldsmile[$j],$newsmile[$j],$fielda2);
        $fieldb1 = str_replace($oldsmile[$j],$newsmile[$j],$fieldb1);
        $fieldb2 = str_replace($oldsmile[$j],$newsmile[$j],$fieldb2);
        $fieldc1 = str_replace($oldsmile[$j],$newsmile[$j],$fieldc1);
        $fieldc2 = str_replace($oldsmile[$j],$newsmile[$j],$fieldc2);
        $fieldd1 = str_replace($oldsmile[$j],$newsmile[$j],$fieldd1);
        $fieldd2 = str_replace($oldsmile[$j],$newsmile[$j],$fieldd2);
      }
      $fielda1 = addslashes($fielda1);
      $fielda2 = addslashes($fielda2);
      $fieldb1 = addslashes($fieldb1);
      $fieldb2 = addslashes($fieldb2);
      $fieldc1 = addslashes($fieldc1);
      $fieldc2 = addslashes($fieldc2);
      if ($type == "art") {
        $fieldd1 = "left";
      }
      else {
        $fieldd1 = addslashes($fieldd1);
      }
      $fieldd2 = addslashes($fieldd2);
      $rec = "<?php
\$type = \"$type\";
\$fileid = \"$fileid\";
\$status = \"$status\";
\$creadate = \"$creadate\";
\$moddate = \"$moddate\";
\$author = stripslashes(\"$author\");
\$email = stripslashes(\"$email\");
\$fielda1 = stripslashes(\"$fielda1\");
\$fielda2 = stripslashes(\"$fielda2\");
\$fieldb1 = stripslashes(\"$fieldb1\");
\$fieldb2 = stripslashes(\"$fieldb2\");
\$fieldc1 = stripslashes(\"$fieldc1\");
\$fieldc2 = stripslashes(\"$fieldc2\");
\$fieldd1 = stripslashes(\"$fieldd1\");
\$fieldd2 = stripslashes(\"$fieldd2\");
?>"; ?> <?php
      WriteFullDB(DBBASE.$i.INCEXT,$rec);
    }
  }
}

function MigrateSpecial() {
  global $oldsmile,$newsmile;
  include (CHEMIN.DATAREP."foot".INCEXT);
  for ($j = 0; $j < count($oldsmile); $j++) {
    $foot1 = str_replace($oldsmile[$j],$newsmile[$j],$foot1);
    $foot2 = str_replace($oldsmile[$j],$newsmile[$j],$foot2);
  }
  $foot1 = addslashes($foot1);
  $foot2 = addslashes($foot2);
  $txt = "<?php
\$foot1 = stripslashes(\"$foot1\");
\$foot2 = stripslashes(\"$foot2\");
?>"; ?> <?php
  WriteFullDB(CHEMIN.DATAREP."foot".INCEXT,$txt);
  include (CHEMIN.DATAREP."freebox".INCEXT);
  for ($j = 0; $j < count($oldsmile); $j++) {
    $freetitle1 = str_replace($oldsmile[$j],$newsmile[$j],$freetitle1);
    $freetitle2 = str_replace($oldsmile[$j],$newsmile[$j],$freetitle2);
    $freetext1 = str_replace($oldsmile[$j],$newsmile[$j],$freetext1);
    $freetext2 = str_replace($oldsmile[$j],$newsmile[$j],$freetext2);
  }
  $freetitle1 = addslashes($freetitle1);
  $freetitle2 = addslashes($freetitle2);
  $freetext1 = addslashes($freetext1);
  $freetext2 = addslashes($freetext2);
  $txt = "<?php
\$freetitle1 = stripslashes(\"$freetitle1\");
\$freetitle2 = stripslashes(\"$freetitle2\");
\$freetext1 = stripslashes(\"$freetext1\");
\$freetext2 = stripslashes(\"$freetext2\");
?>"; ?> <?php
  WriteFullDB(CHEMIN.DATAREP."freebox".INCEXT,$txt);
  include (CHEMIN.DATAREP."homepage".INCEXT);
  for ($j = 0; $j < count($oldsmile); $j++) {
    $home1 = str_replace($oldsmile[$j],$newsmile[$j],$home1);
    $home2 = str_replace($oldsmile[$j],$newsmile[$j],$home2);
  }
  $home1 = addslashes($home1);
  $home2 = addslashes($home2);
  $txt = "<?php
\$home1 = stripslashes(\"$home1\");
\$home2 = stripslashes(\"$home2\");
?>"; ?> <?php
  WriteFullDB(CHEMIN.DATAREP."homepage".INCEXT,$txt);
  include (CHEMIN.DATAREP."special".INCEXT);
  for ($j = 0; $j < count($oldsmile); $j++) {
    $special1 = str_replace($oldsmile[$j],$newsmile[$j],$special1);
    $special2 = str_replace($oldsmile[$j],$newsmile[$j],$special2);
  }
  $special1 = addslashes($special1);
  $special2 = addslashes($special2);
  $txt = "<?php
\$special1 = stripslashes(\"$special1\");
\$special2 = stripslashes(\"$special2\");
?>"; ?> <?php
  WriteFullDB(CHEMIN.DATAREP."special".INCEXT,$txt);
}

function MigrateIndex() {
	global $serviz;
  UpdateDBdtb("art");
  UpdateDBdtb("dnload");
  UpdateDBdtb("links");
  UpdateDBdtb("photo");
  include(CHEMIN.DATAREP."config.inc");
  if ($serviz[16] == "on") {
    UpdateDBnews();
  }
}

function MigrateForumIndex() {
  UpdateDBforum("mod",0);
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
    $nextstep = $scriptname."?lng=".$lng."&form=2&doing=1&num=0";
  }
  elseif ($doing == "1") {
    if ($num == "end") {
      DisplayProcess($clean5,$clean7,$clean8."<br />".$clean9);
      $nextstep = $scriptname."?lng=".$lng."&form=2&doing=2";
    }
    else {
      $max = ReadCounter(NEXTID);
      $maxi = Min($num+9,$max);
      MigrateData($num,$maxi);
      $maxi++;
      $max++;
      DisplayProcess($clean5,$clean7,$clean8."<br />".$clean11.$maxi."/".$max.$clean12);
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
    MigrateSpecial();
    DisplayProcess($clean5,$clean7,$clean8."<br />".$clean9."<br />".$clean13);
    $nextstep = $scriptname."?lng=".$lng."&form=2&doing=3";
  }
  elseif ($doing == "3") {
    MigrateIndex();
    DisplayProcess($clean5,$clean7,$clean8."<br />".$clean9."<br />".$clean13."<br />".$clean14);
    $nextstep = $scriptname."?lng=".$lng."&form=2&doing=4";
  }
  elseif ($doing == "4") {
    MigrateForumIndex();
    DisplayProcess($clean5,$clean7,$clean8."<br />".$clean9."<br />".$clean13."<br />".$clean14."<br />".$clean17);
    $nextstep = $scriptname."?lng=".$lng."&form=2&doing=5";
  }
  elseif ($doing == "5") {
    $nf = DatasToPhp5('data');
    DisplayProcess($clean5,$clean18,$nf.$clean19);
    $nextstep = $scriptname."?lng=".$lng."&form=2&doing=2";
  }
  elseif ($doing == "6") {
    WriteNewVersion();
    DisplayProcess($clean5,$clean10."<br />",$clean8."<br />".$clean9."<br />".$clean13."<br />".$clean14."<br />".$clean17);
    $nextstep = $scriptname."?lng=".$lng."&form=3";
    $dodo = 2;
  }
}
elseif ($form == "3") {
  DisplayTitre($clean1,$clean15);
?>
<form name="instal3" action="<?php echo $scriptname ?>?lng=<?php echo $lng; ?>" method="POST">
<input type="hidden" name="form" value="4">
<center><input type="submit" value="<?php echo $clean16; ?>">
</form>
<?php
}
else {
  $nextstep = "migrate23.php?lng=".$lng;
  $dodo = 0;
}
?>
<p align="center">&nbsp;</p>
<p align="center"><img border="0" src="mpslogo.gif" width="88" height="31"></p>
<p align="center">miniPortail v<?php echo $version; ?><br />CeCILL free Licence - © 2004-2007</p>
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
