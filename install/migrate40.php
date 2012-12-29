<?php
/*
  Migrate from previous version - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v2.0 (27 February 2003)  : initial release
      v2.2 (22 April 2003)     : full rewrite
      v2.3 (27 July 2003)      : upgraded the installation / migration script
      v2.4 (24 September 2003) : added $config variable
                                 upgrade for v2.4 compatibility
      v3.0 (25 February 2004)  : upgrade for v3.0 compatibility
                                 added $finalstep variable
      v4.0 (06 December 2004)  : added alt tag to img and removed border tag for unlinked img (by Isa)
                                 corrected include & added step 5 (by Jean-Mi)
	  v4.6.19 (30 March 2012)  : set datas in conformity with php5 by Saxbar
*/

header("Pragma: no-cache");
define("CHEMIN", "../");
include(CHEMIN."inc/includes.inc");
$version = "4.0";
$scriptname = "migrate40.php";
$finalstep = "migrate45.php?lng=".$lng;   // to be replaced with in next release by: $finalstep = "migrate[nn].php?lng=".$lng;

if ($lng == "en") {
  $clean1 = "MIGRATE GUPPY TO VERSION ".$version;
  $clean2 = "<CENTER>This script is ment:</CENTER><UL><LI>for migrating to GuppY version ".$version." from a version 3.0</UL>";
  $clean3 = "<CENTER><U>IMPORTANT:</U> make sure that you carefully read the <A HREF=\"../readme.html\">readme.html</A> file (I even advise you to print it) before going on.</CENTER>";
  $clean4 = "Let's go!";
  $clean5 = "Migration to version ".$version;
  $clean6 = "<CENTER>You are about to launch a migration to version ".$version."</CENTER>";
  $clean7 = "<CENTER>Migration to version ".$version." ON GOING.</CENTER>";
  $clean8 = "<CENTER>Step #1/5: Parametrization migrated.</CENTER>";
  $clean9 = "<CENTER>Step #2/5: Creation of data/archive/ directory done.</CENTER>";
  $clean10 = "<CENTER>Step #3/5: Creation of data/cache/ directory done.</CENTER>";
  $clean11 = "<CENTER>Step #4/5: Creation of data/usermsg and data/countmsg done.</CENTER>";
  $clean12 = "<CENTER>Step #5/5: Creation of new database indexes done.</CENTER>";
  $clean13 = 'Setting in conformity datas to php 5';
  $clean14 = ' files processed.';

  $clean17 = "<CENTER>Migration to version ".$version." DONE.</CENTER>";
  $clean18 = "<CENTER>The migration to version ".$version." of GuppY is now over.</CENTER>";
  $clean19 = "Next";
}
else {
  $lng = "fr";
  $clean1 = "MIGRATION DE GUPPY EN VERSION ".$version;
  $clean2 = "<CENTER>Ce script permet :</CENTER><UL><LI>de migrer � la version ".$version." de GuppY � partir d'une version 3.0</UL>";
  $clean3 = "<CENTER><U>IMPORTANT :</U> assurez-vous de bien avoir lu le fichier <A HREF=\"../lisezmoi.html\">lisezmoi.html</A> (je vous conseille m�me de l'imprimer) avant de poursuivre.</CENTER>";
  $clean4 = "Allons-y !";
  $clean5 = "Migration � la version ".$version;
  $clean6 = "<CENTER>Vous �tes sur le point de lancer une migration � la version ".$version."</CENTER>";
  $clean7 = "<CENTER>Migration � la version ".$version." EN COURS.</CENTER>";
  $clean8 = "<CENTER>Etape n�1/5 : Migration du param�trage termin�e.</CENTER>";
  $clean9 = "<CENTER>Etape n�2/5 : Cr�ation du r�pertoire data/archive/ effectu�e.</CENTER>";
  $clean10 = "<CENTER>Etape n�3/5 : Cr�ation du r�pertoire data/cache/ effectu�e.</CENTER>";
  $clean11 = "<CENTER>Etape n�4/5 : Cr�ation des r�pertoires data/usermsg et data/countmsg effectu�es.</CENTER>";
  $clean12 = "<CENTER>Etape n�5/5 : Cr�ation des nouveaux index de la base de donn�e effectu�e.</CENTER>";
  $clean13 = 'Mise en conformit� des datas au php 5';
  $clean14 = ' fichiers trait�s.';

  $clean17 = "<CENTER>Migration � la version ".$version." TERMINEE.</CENTER>";
  $clean18 = "<CENTER>La migration en version ".$version." de GuppY est maintenant termin�e.</CENTER>";
  $clean19 = "Suivant";
}

$nextstep = "";
$dodo = 1;

function DisplayTitre($titre,$texte) {
?>

<h3><center><?php echo $titre; ?></center></h3>
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
  include(CONFIG);

    $site[14] = stripslashes("CeCILL Free License - (C) 2004-2007"); // Meta Copyright de l'auteur du site

    $user[3] = stripslashes("on"); // e-mail PHP

    $page[16] = $page[1]; // Police des boites lat�rales
    $page[17] = $page[2]; // Taille des textes des boites lat�rales
    $page[18] = $page[1]; // Police du menu de navigation
    $page[19] = $page[2]; // Taille des liens du menu de navigation
    $page[20] = stripslashes(""); // Rollover sur les ic�nes
    $page[21] = stripslashes(""); // CSS extension � inclure si skin_css
    $page[22] = stripslashes("on"); // utilisation titres longs
    $page[23] = stripslashes("ava_2"); // Th�me avatars
    $page[24] = stripslashes(""); // Curseur dans body

    $titre[4] = $titre[0]; // Couleur du titre des boites lat�rales
    $titre[5] = $titre[1]; // Arri�re-plan du titre des boites lat�rales
    $titre[6] = $titre[2]; // Police des titres des boites lat�rales
    $titre[7] = $titre[3]; // Taille des titres des boites lat�rales

    $texte[5] = $texte[0]; // Couleur des textes des boites lat�rales
    $texte[6] = $texte[1]; // Arri�re-plan OFF des boites lat�rales
    $texte[7] = $texte[2]; // Arri�re-plan ON des boites lat�rales

    $serviz[40] = stripslashes(""); // Soumission dans livre d'or
    $serviz[41] = stripslashes(""); // Soumission dans forum
    $serviz[42] = stripslashes(""); // Option R�dacteur
    $serviz[43] = stripslashes(""); // Avatar pr�f�rences webmaster
    $serviz[44] = stripslashes(""); // Mise en maintenance du site
    $serviz[45] = stripslashes(""); // Masquer l'ic�ne Admin
    $serviz[46] = stripslashes("5"); // Nb de messages Agenda / page
    $serviz[47] = stripslashes(""); // Agenda ON / OFF
    $serviz[48] = stripslashes("20"); // Nb de messages maximum dans Tinymessage
    $serviz[49] = stripslashes("on"); // Editeur HTML compatible ON / OFF

    $lien[2] = $lien[0]; // Liens OFF des boites lat�rales
    $lien[3] = $lien[1]; // Liens ON des boites lat�rales
    $lien[4] = $lien[0]; // Liens OFF de la barre de menu haute
    $lien[5] = $lien[1]; // Liens ON de la barre de menu haute

    $barre[0] = stripslashes("#CCCCFF"); // Couleur des HR
    $barre[1] = stripslashes("1px"); // Taille des HR
    $barre[2] = stripslashes("dashed"); // Style des HR

    $forum[0] = stripslashes("#DFDFE0"); // Arri�re plan ent�tes
    $forum[1] = stripslashes("#E6E6E9"); // Arri�re plan question
    $forum[2] = stripslashes("#F0F0F0"); // Arri�re plan r�ponse

    $members[0] = stripslashes(""); // Activation de la zone membres
    $members[1] = stripslashes(""); // Zone membre acc�s � la section Articles
    $members[2] = stripslashes(""); // Zone membre acc�s � la section Photo
    $members[3] = stripslashes(""); // Zone membre acc�s � la section Liens
    $members[4] = stripslashes(""); // Zone membre acc�s � la section FAQ
    $members[5] = stripslashes(""); // Zone membre acc�s � la section Forum
    $members[6] = stripslashes(""); // Zone membre acc�s � la section Statistiques
    $members[7] = stripslashes(""); // Zone membre acc�s � la section T�l�chargement
    $members[8] = stripslashes(""); // Zone membre acc�s publication Nouvelles
    $members[9] = stripslashes(""); // Zone membre acc�s publication Livre d'Or
    $members[10] = stripslashes(""); // Zone membre acc�s publication Forum
    $members[11] = stripslashes(""); // Zone membre acc�s publication Reactions aux articles
    $members[12] = stripslashes(""); // Zone membre acc�s � la section Livre d'Or
    $members[13] = stripslashes(""); // Zone membre acc�s � la section Nouvelles
    $members[14] = stripslashes(""); // Zone membre acc�s � la section Agenda

    for ($i = 0; $i < count($posbox); $i++) {
      if ($posbox[$i] == "inc/boxreco") $posbox[$i] = "";
    }

  $mettre = "<?php
\$site[0] = stripslashes(\"$site[0]\"); // Titre du site pour l'Editorial
\$site[1] = stripslashes(\"$site[1]\"); // Meta Description du site
\$site[2] = stripslashes(\"$site[2]\"); // Meta Mots-cl�s du site
\$site[3] = stripslashes(\"$site[3]\"); // URL du site
\$site[4] = stripslashes(\"$site[4]\"); // Nouvelles sur la page d'accueil
\$site[5] = stripslashes(\"$site[5]\"); // Activation des news ou pas
\$site[6] = stripslashes(\"$site[6]\"); // Meta Titre du site pour les moteurs de recherche
\$site[7] = stripslashes(\"$site[7]\"); // Meta M�thode d'indexation du site pour les robots
\$site[8] = stripslashes(\"$site[8]\"); // Meta D�lai d'attente du robot avant une prochaine indexation
\$site[9] = stripslashes(\"$site[9]\"); // Meta Auteur du site
\$site[10] = stripslashes(\"$site[10]\"); // Meta Propri�taire du site
\$site[11] = stripslashes(\"$site[11]\"); // Meta Adresse e-mail principale de l'auteur du site
\$site[12] = stripslashes(\"$site[12]\"); // Meta Cat�gorie du public vis�
\$site[13] = stripslashes(\"$site[13]\"); // Meta Mode de diffusion du site
\$site[14] = stripslashes(\"$site[14]\"); // Meta Copyright de l'auteur du site
\$site[15] = stripslashes(\"$site[15]\"); // Meta language
\$site[16] = stripslashes(\"$site[16]\"); // Meta Identifier URL
\$site[17] = stripslashes(\"$site[17]\"); // Slogan d�filant langue principale
\$site[18] = stripslashes(\"$site[18]\"); // Slogan d�filant deuxi�me langue
\$site[19] = stripslashes(\"$site[19]\"); // Format Dates
\$site[20] = stripslashes(\"$site[20]\"); // Messages Forum sur la page d'accueil
\$site[21] = stripslashes(\"$site[21]\"); // ID du message Livre d'or pr�f�r�
\$site[22] = stripslashes(\"$site[22]\"); // Format Heure
\$site[23] = stripslashes(\"$site[23]\"); // S�parateur Date & Heure
\$site[24] = stripslashes(\"$site[24]\"); // Logo Copyright
\$site[25] = stripslashes(\"$site[25]\"); // Position Logo Copyright
\$site[26] = stripslashes(\"$site[26]\"); // Compression des Pages
\$site[27] = stripslashes(\"$site[27]\"); // Temps d'attente popup postage
\$site[28] = stripslashes(\"$site[28]\"); // Barre de progression attente popup postage
\$site[29] = stripslashes(\"$site[29]\"); // PHP Register Globals ON / OFF

\$lang[0] = stripslashes(\"$lang[0]\"); // Langue principale du site
\$lang[1] = stripslashes(\"$lang[1]\"); // Deuxi�me langue du site

\$user[0] = stripslashes(\"$user[0]\"); // Webmaster
\$user[1] = stripslashes(\"$user[1]\"); // e-mail du responsable du site
\$user[2] = stripslashes(\"$user[2]\"); // # ICQ
\$user[3] = stripslashes(\"$user[3]\"); // e-mail PHP

\$nom[0] = stripslashes(\"$nom[0]\"); // Nom de l'accueil langue principale
\$nom[1] = stripslashes(\"$nom[1]\"); // Page des t�l�chargements langue principale
\$nom[2] = stripslashes(\"$nom[2]\"); // Page des images langue principale
\$nom[3] = stripslashes(\"$nom[3]\"); // Page des liens langue principale
\$nom[4] = stripslashes(\"$nom[4]\"); // Boite des articles � gauche langue principale
\$nom[5] = stripslashes(\"$nom[5]\"); // Boite sp�ciale langue principale
\$nom[6] = stripslashes(\"$nom[6]\"); // Sondage langue principale
\$nom[7] = stripslashes(\"$nom[7]\"); // Nouvelles langue principale
\$nom[8] = stripslashes(\"$nom[8]\"); // Compteur langue principale
\$nom[9] = stripslashes(\"$nom[9]\"); // Livre d'or langue principale
\$nom[10] = stripslashes(\"$nom[10]\"); // Nom de l'accueil deuxi�me langue
\$nom[11] = stripslashes(\"$nom[11]\"); // Page des t�l�chargements deuxi�me langue
\$nom[12] = stripslashes(\"$nom[12]\"); // Page des images deuxi�me langue
\$nom[13] = stripslashes(\"$nom[13]\"); // Page des liens deuxi�me langue
\$nom[14] = stripslashes(\"$nom[14]\"); // Boite des articles � gauche deuxi�me langue
\$nom[15] = stripslashes(\"$nom[15]\"); // Boite sp�ciale deuxi�me langue
\$nom[16] = stripslashes(\"$nom[16]\"); // Sondage deuxi�me langue
\$nom[17] = stripslashes(\"$nom[17]\"); // Nouvelles deuxi�me langue
\$nom[18] = stripslashes(\"$nom[18]\"); // Compteur deuxi�me langue
\$nom[19] = stripslashes(\"$nom[19]\"); // Livre d'or deuxi�me langue
\$nom[20] = stripslashes(\"$nom[20]\"); // Recherche langue principale
\$nom[21] = stripslashes(\"$nom[21]\"); // Recherche deuxi�me langue
\$nom[22] = stripslashes(\"$nom[22]\"); // Forum langue principale
\$nom[23] = stripslashes(\"$nom[23]\"); // Forum deuxi�me langue
\$nom[24] = stripslashes(\"$nom[24]\"); // FAQ langue principale
\$nom[25] = stripslashes(\"$nom[25]\"); // FAQ deuxi�me langue
\$nom[26] = stripslashes(\"$nom[26]\"); // Statistiques langue principale
\$nom[27] = stripslashes(\"$nom[27]\"); // Statistiques deuxi�me langue
\$nom[28] = stripslashes(\"$nom[28]\"); // Recommander langue principale
\$nom[29] = stripslashes(\"$nom[29]\"); // Recommander deuxi�me langue
\$nom[30] = stripslashes(\"$nom[30]\"); // Boite des articles � droite langue principale
\$nom[31] = stripslashes(\"$nom[31]\"); // Boite des articles � droite deuxi�me langue
\$nom[32] = stripslashes(\"$nom[32]\"); // Boite Calendrier langue principale
\$nom[33] = stripslashes(\"$nom[33]\"); // Boite Calendrier deuxi�me langue
\$nom[34] = stripslashes(\"$nom[34]\"); // Boite pr�f�rences utilisateur langue principale
\$nom[35] = stripslashes(\"$nom[35]\"); // Boite pr�f�rences utilisateur deuxi�me langue
\$nom[36] = stripslashes(\"$nom[36]\"); // Boite RSS langue principale
\$nom[37] = stripslashes(\"$nom[37]\"); // Boite RSS deuxi�me langue
\$nom[38] = stripslashes(\"$nom[38]\"); // Boite Newsletter langue principale
\$nom[39] = stripslashes(\"$nom[39]\"); // Boite Newsletter deuxi�me langue
\$nom[40] = stripslashes(\"Webmaster - Infos\"); // Boite Webmaster - Infos langue principale
\$nom[41] = stripslashes(\"Webmaster - Infos\"); // Boite Webmaster - Infos deuxi�me langue

\$page[0] = stripslashes(\"$page[0]\"); // Arri�re-plan du site
\$page[1] = stripslashes(\"$page[1]\"); // Police des boites centrales
\$page[2] = stripslashes(\"$page[2]\"); // Taille des textes des boites centrales
\$page[3] = stripslashes(\"$page[3]\"); // Image de fond du site
\$page[4] = stripslashes(\"$page[4]\"); // Logo du site
\$page[5] = stripslashes(\"$page[5]\"); // Arri�re-plan du bandeau
\$page[6] = stripslashes(\"$page[6]\"); // Image de fond du bandeau
\$page[7] = stripslashes(\"$page[7]\"); // Transition entre pages
\$page[8] = stripslashes(\"$page[8]\"); // Affichage Temps de chargement de page ON / OFF
\$page[9] = stripslashes(\"$page[9]\"); // Th�me d'ic�nes
\$page[10] = stripslashes(\"$page[10]\"); // Image de fond fixe / mouvante
\$page[11] = stripslashes(\"$page[11]\"); // Th�me de compteur de visites
\$page[12] = stripslashes(\"$page[12]\"); // Th�me smileys
\$page[13] = stripslashes(\"$page[13]\"); // Image Page en cours de chargement
\$page[14] = stripslashes(\"$page[14]\"); // Th�me skins
\$page[15] = stripslashes(\"$page[15]\"); // Effet animation liens
\$page[16] = stripslashes(\"$page[16]\"); // Police des boites lat�rales
\$page[17] = stripslashes(\"$page[17]\"); // Taille des textes des boites lat�rales
\$page[18] = stripslashes(\"$page[18]\"); // Police du menu de navigation
\$page[19] = stripslashes(\"$page[19]\"); // Taille des liens du menu de navigation
\$page[20] = stripslashes(\"$page[20]\"); // Rollover sur les ic�nes
\$page[21] = stripslashes(\"$page[21]\"); // param�tre inutilis�
\$page[22] = stripslashes(\"$page[22]\"); // utilisation titres longs
\$page[23] = stripslashes(\"$page[23]\"); // Th�me avatars
\$page[24] = stripslashes(\"$page[24]\"); // Curseur dans body

\$titre[0] = stripslashes(\"$titre[0]\"); // Couleur du titre des boites centrales
\$titre[1] = stripslashes(\"$titre[1]\"); // Arri�re-plan du titre des boites centrales
\$titre[2] = stripslashes(\"$titre[2]\"); // Police des titres des boites centrales
\$titre[3] = stripslashes(\"$titre[3]\"); // Taille des titres des boites centrales
\$titre[4] = stripslashes(\"$titre[4]\"); // Couleur du titre des boites lat�rales
\$titre[5] = stripslashes(\"$titre[5]\"); // Arri�re-plan du titre des boites lat�rales
\$titre[6] = stripslashes(\"$titre[6]\"); // Police des titres des boites lat�rales
\$titre[7] = stripslashes(\"$titre[7]\"); // Taille des titres des boites lat�rales

\$texte[0] = stripslashes(\"$texte[0]\"); // Couleur des textes des boites centrales
\$texte[1] = stripslashes(\"$texte[1]\"); // Arri�re-plan OFF des boites centrales
\$texte[2] = stripslashes(\"$texte[2]\"); // Arri�re-plan ON des boites centrales
\$texte[3] = stripslashes(\"$texte[3]\"); // Puce articles
\$texte[4] = stripslashes(\"$texte[4]\"); // Taille des bordures
\$texte[5] = stripslashes(\"$texte[5]\"); // Couleur des textes des boites lat�rales
\$texte[6] = stripslashes(\"$texte[6]\"); // Arri�re-plan OFF des boites lat�rales
\$texte[7] = stripslashes(\"$texte[7]\"); // Arri�re-plan ON des boites lat�rales

\$bordure[0] = stripslashes(\"$bordure[0]\"); // Couleur des bordures
\$bordure[1] = stripslashes(\"$bordure[1]\"); // Couleur de la base de la barre de d�filement
\$bordure[2] = stripslashes(\"$bordure[2]\"); // Couleur des fl�ches de la barre de d�filement

\$lien[0] = stripslashes(\"$lien[0]\"); // Liens OFF des boites centrales
\$lien[1] = stripslashes(\"$lien[1]\"); // Liens ON des boites centrales
\$lien[2] = stripslashes(\"$lien[2]\"); // Liens OFF des boites lat�rales
\$lien[3] = stripslashes(\"$lien[3]\"); // Liens ON des boites lat�rales
\$lien[4] = stripslashes(\"$lien[4]\"); // Liens OFF de la barre de menu haute
\$lien[5] = stripslashes(\"$lien[5]\"); // Liens ON de la barre de menu haute

\$barre[0] = stripslashes(\"$barre[0]\"); // Couleur des HR
\$barre[1] = stripslashes(\"$barre[1]\"); // Taille des HR
\$barre[2] = stripslashes(\"$barre[2]\"); // Style des HR

\$forum[0] = stripslashes(\"$forum[0]\"); // Arri�re plan ent�tes
\$forum[1] = stripslashes(\"$forum[1]\"); // Arri�re plan question
\$forum[2] = stripslashes(\"$forum[2]\"); // Arri�re plan r�ponse

\$serviz[0] = stripslashes(\"$serviz[0]\"); // Citations ON / OFF
\$serviz[1] = stripslashes(\"$serviz[1]\"); // Accueil Editorial ON / OFF
\$serviz[2] = stripslashes(\"$serviz[2]\"); // Nb de news / page
\$serviz[3] = stripslashes(\"$serviz[3]\"); // Boite Articles gauche ON / OFF
\$serviz[4] = stripslashes(\"$serviz[4]\"); // Nb de t�l�chargements / page
\$serviz[5] = stripslashes(\"$serviz[5]\"); // Nb de liens / page
\$serviz[6] = stripslashes(\"$serviz[6]\"); // Nb de FAQ / page
\$serviz[7] = stripslashes(\"$serviz[7]\"); // Nb de messages Guestbook / page
\$serviz[8] = stripslashes(\"$serviz[8]\"); // Nouvelles ON / OFF
\$serviz[9] = stripslashes(\"$serviz[9]\"); // Photos ON / OFF
\$serviz[10] = stripslashes(\"$serviz[10]\"); // T�l�chargements ON / OFF
\$serviz[11] = stripslashes(\"$serviz[11]\"); // Liens ON / OFF
\$serviz[12] = stripslashes(\"$serviz[12]\"); // Livre d'or ON / OFF
\$serviz[13] = stripslashes(\"$serviz[13]\"); // Forum ON / OFF
\$serviz[14] = stripslashes(\"$serviz[14]\"); // FAQ ON / OFF
\$serviz[15] = stripslashes(\"$serviz[15]\"); // Statistiques ON / OFF
\$serviz[16] = stripslashes(\"$serviz[16]\"); // Publication Nouvelles ON / OFF
\$serviz[17] = stripslashes(\"$serviz[17]\"); // Nb de messages Forum / page
\$serviz[18] = stripslashes(\"$serviz[18]\"); // Cat�gories Forum ON / OFF
\$serviz[19] = stripslashes(\"$serviz[19]\"); // Banni�res ON / OFF
\$serviz[20] = stripslashes(\"$serviz[20]\"); // Nb de messages Thread / page
\$serviz[21] = stripslashes(\"$serviz[21]\"); // Photorama avanc� ON /OFF
\$serviz[22] = stripslashes(\"$serviz[22]\"); // Boite Articles droit ON / OFF
\$serviz[23] = stripslashes(\"$serviz[23]\"); // Sondage ON / OFF
\$serviz[24] = stripslashes(\"$serviz[24]\"); // Recherche ON / OFF
\$serviz[25] = stripslashes(\"$serviz[25]\"); // Menu dynamique Articles gauche
\$serviz[26] = stripslashes(\"$serviz[26]\"); // Menu dynamique Articles droit
\$serviz[27] = stripslashes(\"$serviz[27]\"); // Soumission de news
\$serviz[28] = stripslashes(\"$serviz[28]\"); // Pr�f�rences visiteurs
\$serviz[29] = stripslashes(\"$serviz[29]\"); // R�actions aux articles
\$serviz[30] = stripslashes(\"$serviz[30]\"); // Nb R�actions aux articles / page
\$serviz[31] = stripslashes(\"$serviz[31]\"); // Pseudo pr�f�rences webmaster
\$serviz[32] = stripslashes(\"$serviz[32]\"); // Acc�s � l'administration rapide
\$serviz[33] = stripslashes(\"$serviz[33]\"); // Compteur de lecture Articles
\$serviz[34] = stripslashes(\"$serviz[34]\"); // Compteur de lecture Threads Forum
\$serviz[35] = stripslashes(\"$serviz[35]\"); // Compteur de Nb de t�l�chargements
\$serviz[36] = stripslashes(\"$serviz[36]\"); // Newsletter ON / OFF
\$serviz[37] = stripslashes(\"$serviz[37]\"); // Nb de news publi�es
\$serviz[38] = stripslashes(\"$serviz[38]\"); // RSS News ON / OFF
\$serviz[39] = stripslashes(\"$serviz[39]\"); // Dur�e Cache RSS
\$serviz[40] = stripslashes(\"$serviz[40]\"); // Soumission dans livre d'or
\$serviz[41] = stripslashes(\"$serviz[41]\"); // Soumission dans forum
\$serviz[42] = stripslashes(\"$serviz[42]\"); // Option R�dacteur
\$serviz[43] = stripslashes(\"$serviz[43]\"); // Avatar pr�f�rences webmaster
\$serviz[44] = stripslashes(\"$serviz[44]\"); // Mise en maintenance du site
\$serviz[45] = stripslashes(\"$serviz[45]\"); // Masquer l'icone Admin
\$serviz[46] = stripslashes(\"$serviz[46]\"); // Nb de messages Agenda / page
\$serviz[47] = stripslashes(\"$serviz[47]\"); // Agenda ON / OFF
\$serviz[48] = stripslashes(\"$serviz[48]\"); // Nb de messages maximum dans Tinymessage
\$serviz[49] = stripslashes(\"$serviz[49]\"); // Editeur HTML compatible ON / OFF

\$posbox[0] = stripslashes(\"$posbox[0]\"); // Premi�re boite � droite
\$posbox[1] = stripslashes(\"$posbox[1]\"); // Seconde boite � droite
\$posbox[2] = stripslashes(\"$posbox[2]\"); // Troisi�me boite � droite
\$posbox[3] = stripslashes(\"$posbox[3]\"); // Quatri�me boite � droite
\$posbox[4] = stripslashes(\"$posbox[4]\"); // Cinqui�me boite � droite
\$posbox[5] = stripslashes(\"$posbox[5]\"); // Sixi�me boite � droite
\$posbox[6] = stripslashes(\"$posbox[6]\"); // Septi�me boite � droite
\$posbox[7] = stripslashes(\"$posbox[7]\"); // Huiti�me boite � droite
\$posbox[8] = stripslashes(\"$posbox[8]\"); // Neuvi�me boite � droite
\$posbox[9] = stripslashes(\"$posbox[9]\"); // Premi�re boite � gauche
\$posbox[10] = stripslashes(\"$posbox[10]\"); // Seconde boite � gauche
\$posbox[11] = stripslashes(\"$posbox[11]\"); // Troisi�me boite � gauche
\$posbox[12] = stripslashes(\"$posbox[12]\"); // Quatri�me boite � gauche
\$posbox[13] = stripslashes(\"$posbox[13]\"); // Cinqui�me boite � gauche
\$posbox[14] = stripslashes(\"$posbox[14]\"); // Sixi�me  boite � gauche
\$posbox[15] = stripslashes(\"$posbox[15]\"); // Septi�me  boite � gauche
\$posbox[16] = stripslashes(\"$posbox[16]\"); // Huiti�me  boite � gauche
\$posbox[17] = stripslashes(\"$posbox[17]\"); // Neuvi�me  boite � gauche

\$supervision[0] = stripslashes(\"$supervision[0]\"); // e-mail compteur
\$supervision[1] = stripslashes(\"$supervision[1]\"); // incr�ment de compteur pour e-mail
\$supervision[2] = stripslashes(\"$supervision[2]\"); // e-mail publication nouvelle
\$supervision[3] = stripslashes(\"$supervision[3]\"); // e-mail publication livre d'or
\$supervision[4] = stripslashes(\"$supervision[4]\"); // e-mail publication forum
\$supervision[5] = stripslashes(\"$supervision[5]\"); // Type d'e-mail PHP
\$supervision[6] = stripslashes(\"$supervision[6]\"); // e-mail r�agir aux articles
\$supervision[7] = stripslashes(\"$supervision[7]\"); // e-mail inscription ou r�siliation Newsletter

\$calendar[0] = stripslashes(\"$calendar[0]\"); // Couleur de fond des jours libre du mois
\$calendar[1] = stripslashes(\"$calendar[1]\"); // Couleur de fond du calendrier
\$calendar[2] = stripslashes(\"$calendar[2]\"); // Couleur de fond de la journ�e
\$calendar[3] = stripslashes(\"$calendar[3]\"); // Couleur de fond des dimanches
\$calendar[4] = stripslashes(\"$calendar[4]\"); // Couleur de fond de la journ�e quand c'est un dimanche
\$calendar[5] = stripslashes(\"$calendar[5]\"); // Police du calendrier
\$calendar[6] = stripslashes(\"$calendar[6]\"); // Taille de la police du calendrier
\$calendar[7] = stripslashes(\"$calendar[7]\"); // Couleurs de la police des chiffres
\$calendar[8] = stripslashes(\"$calendar[8]\"); // Couleurs de la police des jours de la semaine
\$calendar[9] = stripslashes(\"$calendar[9]\"); // Taille des bordures du calendrier
\$calendar[10] = stripslashes(\"$calendar[10]\"); // Couleur des bordures du calendrier
\$calendar[11] = stripslashes(\"$calendar[11]\"); // Largeur du calendrier dans sa bo�te

\$citation[0] = stripslashes(\"$citation[0]\"); // Police des citations
\$citation[1] = stripslashes(\"$citation[1]\"); // Taille de la police des citations
\$citation[2] = stripslashes(\"$citation[2]\"); // Couleur de la police des citations

\$presform[0] = stripslashes(\"$presform[0]\"); // Couleur des textes dans les boites de choix et boutons de commande
\$presform[1] = stripslashes(\"$presform[1]\"); // Couleur des boites de choix
\$presform[2] = stripslashes(\"$presform[2]\"); // Couleur des boutons de commande
\$presform[3] = stripslashes(\"$presform[3]\"); // Couleur des zone de texte
\$presform[4] = stripslashes(\"$presform[4]\"); // Police dans la pr�sentation des formulaires
\$presform[5] = stripslashes(\"$presform[5]\"); // Taille de la police dans la pr�sentation des formulaires
\$presform[6] = stripslashes(\"$presform[6]\"); // Couleur de fond des textarea
\$presform[7] = stripslashes(\"$presform[7]\"); // Taille de la bordure
\$presform[8] = stripslashes(\"$presform[8]\"); // Couleur de la bordure

\$editobox[0] = stripslashes(\"$editobox[0]\"); // Premi�re boite page d'accueil
\$editobox[1] = stripslashes(\"$editobox[1]\"); // Seconde boite page d'accueil
\$editobox[2] = stripslashes(\"$editobox[2]\"); // Troisi�me boite page d'accueil
\$editobox[3] = stripslashes(\"$editobox[3]\"); // Quatri�me boite page d'accueil

\$configlog[0] = stripslashes(\"$configlog[0]\"); // Nombre des messages visibles dans l'admin log
\$configlog[1] = stripslashes(\"$configlog[1]\"); // Inclure les logs de la page Index/Accueil
\$configlog[2] = stripslashes(\"$configlog[2]\"); // Inclure les logs de la page Nouvelles
\$configlog[3] = stripslashes(\"$configlog[3]\"); // Inclure les logs de la page Photos
\$configlog[4] = stripslashes(\"$configlog[4]\"); // Inclure les logs de la page Liens
\$configlog[5] = stripslashes(\"$configlog[5]\"); // Inclure les logs de la page T�l�chargement
\$configlog[6] = stripslashes(\"$configlog[6]\"); // Inclure les logs de la page Livre d'or
\$configlog[7] = stripslashes(\"$configlog[7]\"); // Inclure les logs de la page FAQ
\$configlog[8] = stripslashes(\"$configlog[8]\"); // Inclure les logs de la page Forum
\$configlog[9] = stripslashes(\"$configlog[9]\"); // Inclure les logs de la page Stats
\$configlog[10] = stripslashes(\"$configlog[10]\"); // Inclure les logs de la page Admin

\$members[0] = stripslashes(\"$members[0]\"); // Activation de la zone membres
\$members[1] = stripslashes(\"$members[1]\"); // Zone membre acc�s � la section Articles
\$members[2] = stripslashes(\"$members[2]\"); // Zone membre acc�s � la section Photo
\$members[3] = stripslashes(\"$members[3]\"); // Zone membre acc�s � la section Liens
\$members[4] = stripslashes(\"$members[4]\"); // Zone membre acc�s � la section FAQ
\$members[5] = stripslashes(\"$members[5]\"); // Zone membre acc�s � la section Forum
\$members[6] = stripslashes(\"$members[6]\"); // Zone membre acc�s � la section Statistiques
\$members[7] = stripslashes(\"$members[7]\"); // Zone membre acc�s � la section T�l�chargement
\$members[8] = stripslashes(\"$members[8]\"); // Zone membre acc�s publication Nouvelles
\$members[9] = stripslashes(\"$members[9]\"); // Zone membre acc�s publication Livre d'Or
\$members[10] = stripslashes(\"$members[10]\"); // Zone membre acc�s publication Forum
\$members[11] = stripslashes(\"$members[11]\"); // Zone membre acc�s publication Reactions aux articles
\$members[12] = stripslashes(\"$members[12]\"); // Zone membre acc�s � la section Livre d'Or
\$members[13] = stripslashes(\"$members[13]\"); // Zone membre acc�s � la section Nouvelles
\$members[14] = stripslashes(\"$members[14]\"); // Zone membre acc�s � la section Agenda
?>"; ?>
<?php
  WriteFullDB(CONFIG,$mettre);
}

function CreateArchiveDir() {
  @mkdir (ARCHREP, 0755);
  copy("backindex.php",ARCHREP."index.php");
  WriteFullDB(DBFORUMARCHDATE," ");
}

function CreateCacheDir() {
  @mkdir (CACHEREP, 0755);
  copy("backindex.php",CACHEREP."index.php");
}

/// Ajouter la cr�ation de usermsg & countmsg
function CreateUserDir() {
  @mkdir (USEREP, 0755);
  copy("backindex.php",USEREP."index.php");
  @mkdir (FILECOUNTMSG, 0755);
  copy("backindex.php",FILECOUNTMSG."index.php");
}

function CreateNewDB() {
  @chmod(DBNEWS.".dat",0777);
  @unlink(DBNEWS.".dat");
  /// Suppression des ic�nes de plugins (peut-�tre incompatible ?)
  WriteFullDB(DBPLUGIN,"");
  WriteFullDB(DBLOGDATE, date("d/m/y"));
  WriteFullDB(DBLOGFILES, "stats.dtb");
  WriteFullDB(DBLOGSTATS, date("d/m/y").";0;");
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
<script language="JavaScript">
  function redir(param) {
    window.location = param;
  }
</script>
</head>
<body bgcolor="#FFFFFF">
<p align="center"><img src="gylogo.gif" width="124" height="70" alt="gylogo.gif"></p>

<?php
 if (empty($form)) {
?>

<p align="center"><a href="Javascript: redir('<?php echo $scriptname ?>?lng=fr'); "><img src="<?php echo CHEMIN; ?>inc/lang/fr.gif" width="24" height="16" border="0" alt="fr"></a>&nbsp;&nbsp;&nbsp;&nbsp;<a href="Javascript: redir('<?php echo $scriptname ?>?lng=en'); "><img src="<?php echo CHEMIN; ?>inc/lang/en.gif" width="24" height="16" border="0" alt="en"></a></p>

<?php
 DisplayTitre($clean1,$clean2."<br /><br />".$clean3);
?>

<form name="instal0" action="<?php echo $scriptname ?>?lng=<?php echo $lng; ?>" method="post">
<input type="hidden" name="form" value="1">
<center><input type="submit" value="<?php echo $clean4; ?>"></center>
</form>

<?php
}
elseif ($form == "1") {
 DisplayTitre($clean5,$clean6);
?>

<form name="instal1" action="<?php echo $scriptname ?>?lng=<?php echo $lng; ?>" method="post">
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
    CreateArchiveDir();
    DisplayProcess($clean5,$clean7,$clean8."<br />".$clean9);
    $nextstep = $scriptname."?lng=".$lng."&form=2&doing=2";
  }
  elseif ($doing == "2") {
    CreateCacheDir();
    DisplayProcess($clean5,$clean7,$clean8."<br />".$clean9."<br />".$clean10);
    $nextstep = $scriptname."?lng=".$lng."&form=2&doing=3";
  }
  elseif ($doing == "3") {
    CreateNewDB();
    DisplayProcess($clean5,$clean7,$clean8."<br />".$clean9."<br />".$clean10."<br />".$clean11);
    $nextstep = $scriptname."?lng=".$lng."&form=2&doing=4";
  }
  elseif ($doing == "4") {
    CreateUserDir();
    DisplayProcess($clean5,$clean7,$clean8."<br />".$clean9."<br />".$clean10."<br />".$clean11."<br />".$clean12);
    $nextstep = $scriptname."?lng=".$lng."&form=2&doing=5";
  }
  elseif ($doing == "5") {
    $nf = DatasToPhp5('data');
    DisplayProcess($clean5,$clean13,$nf.$clean14);
    $nextstep = $scriptname."?lng=".$lng."&form=2&doing=6";
  }
  elseif ($doing == "6") {
    WriteNewVersion();
    DisplayProcess($clean5,$clean18."<br />",$clean17);
    $nextstep = $scriptname."?lng=".$lng."&form=3";
    $dodo = 2;
  }
}
elseif ($form == "3") {
  DisplayTitre($clean1,$clean18);
?>

<form name="instal3" action="<?php echo $scriptname ?>?lng=<?php echo $lng; ?>" method="post">
<input type="hidden" name="form" value="4">
<center><input type="submit" value="<?php echo $clean19; ?>"></center>
</form>

<?php
}
else {
  $nextstep = $finalstep;
  $dodo = 0;
}
?>

<p align="center">&nbsp;</p>
<p align="center"><img src="gyslogo.gif" width="104" height="39" alt="gyslogo.gif"></p>
<p align="center">GuppY v<?php echo $version; ?><br />CeCILL free Licence - � 2004-2007</p>
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
