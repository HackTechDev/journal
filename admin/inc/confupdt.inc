<?php
/*
    Config Update - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v2.4 (24 September 2003)    : initial release
      v3.0 (25 February 2004)     : added Newsletter
                                    added logbook
                                    added RSS News
      v4.0 (06 December 2004)     : added submit option for guestbook and forum (by Jean-Mi)
  	                                added forum-table background colors (by Icare)
  	                                added HR config and nav menu config,
                                    added a rollover effect option on menu bar (by Isa)
                                    splitted style of the central and side boxes / links / titles (by Isa)
                                    added CSS extension to be included in the stylesheet if skin_css selected (by Isa)
        				                    added icons theme, agenda, cursor, maintain and avatars (by Nicolas Alves)
        				                    added editor choice (by Icare)
      v4.5 (06 June 2005)         : set default site url if not defined (by Icare)
      v4.6.0 (04 June 2007)       : added forum config items, boxes title items (by Icare)
      v4.6.2 (10 July 2007)       : added mail supervision for comments on blog (by Icare)
      v4.6.6 (14 April 2008)      : added optionnal W3C validator icons (by Icare)
      v4.6.9 (25 December 2008)   : added $serviz[62] to control the function To recommend ON/OFF #20
      v4.6.9e (29 December 2008)  : corrected warning headers already sent
      v4.6.10 (7 September 2009)  : corrected some $serviz
      v4.6.15 (30 June 2011)      : added $members[19] (by Icare)
      v4.6.18 (09 February 2012)  : added $supervision[10] (thanks tonton_christian)
      v4.6.19 (30 March 2012)     : add social networks by Saxbar
*/
if (stristr($_SERVER["SCRIPT_NAME"], "confupdt.inc")) {
  header("location:../index.php");
  die();
}
if ($site[3] =="") {
  $site[3] = "http://".str_replace("/admin","/",$_SERVER['HTTP_HOST'].dirname($PHP_SELF)); //real site url
}
$mettre = "<?php
if (stristr(\$_SERVER[\"SCRIPT_NAME\"], \"config.inc\")) {
  header(\"location:../index.php\");
  die();
}

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
\$site[19] = stripslashes(\"$site[19]\"); // Format Dates
\$site[20] = stripslashes(\"$site[20]\"); // Messages Forum sur la page d'accueil
\$site[21] = stripslashes(\"$site[21]\"); // ID du message Livre d'or préféré
\$site[22] = stripslashes(\"$site[22]\"); // Format Heure
\$site[23] = stripslashes(\"$site[23]\"); // Séparateur Date & Heure
\$site[24] = stripslashes(\"$site[24]\"); // Logo Copyright
\$site[25] = stripslashes(\"$site[25]\"); // Position Logo Copyright
\$site[26] = stripslashes(\"$site[26]\"); // Compression des Pages
\$site[27] = stripslashes(\"$site[27]\"); // Temps d'attente popup postage
\$site[28] = stripslashes(\"$site[28]\"); // Barre de progression attente popup postage
\$site[29] = stripslashes(\"$site[29]\"); // Nombre de caractères des nouvelles en page d'accueil
\$site[30] = stripslashes(\"$site[30]\"); // Activation du Blog ou pas
\$site[31] = stripslashes(\"$site[31]\"); // Blog sur la page d'accueil
\$site[32] = stripslashes(\"$site[32]\"); // Icônes validator W3C
\$site['TZ'] = stripslashes(\"".$site['TZ']."\"); // Fuseau horaire

\$page[12] = stripslashes(\"$page[12]\"); // Thème smileys
\$page[14] = stripslashes(\"$page[14]\"); // Thème skins
\$page[23] = stripslashes(\"$page[23]\"); // Thème avatars

\$texte[3] = stripslashes(\"$texte[3]\"); // Puce articles

\$lang[0] = stripslashes(\"$lang[0]\"); // Langue principale du site
\$lang[1] = stripslashes(\"$lang[1]\"); // Deuxième langue du site

\$user[0] = stripslashes(\"$user[0]\"); // Webmaster
\$user[1] = stripslashes(\"$user[1]\"); // e-mail du responsable du site
\$user[2] = stripslashes(\"$user[2]\"); // Identifiant messagerie instantanée
\$user[3] = stripslashes(\"$user[3]\"); // e-mail PHP
\$user[4] = stripslashes(\"$user[4]\"); // Messagerie instantanée

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
\$nom[36] = stripslashes(\"$nom[36]\"); // Boite RSS langue principale
\$nom[37] = stripslashes(\"$nom[37]\"); // Boite RSS deuxième langue
\$nom[38] = stripslashes(\"$nom[38]\"); // Boite Newsletter langue principale
\$nom[39] = stripslashes(\"$nom[39]\"); // Boite Newsletter deuxième langue
\$nom[40] = stripslashes(\"$nom[40]\"); // Boite Webmaster - Infos langue principale
\$nom[41] = stripslashes(\"$nom[41]\"); // Boite Webmaster - Infos deuxième langue
\$nom[42] = stripslashes(\"$nom[42]\"); // Blog langue principale
\$nom[43] = stripslashes(\"$nom[43]\"); // Blog deuxième langue
\$nom[44] = stripslashes(\"$nom[44]\"); // Boîte Menu langue principale
\$nom[45] = stripslashes(\"$nom[45]\"); // Boîte Menu deuxième langue
\$nom[46] = stripslashes(\"$nom[46]\"); // Boîte Réseaux sociaux langue principale
\$nom[47] = stripslashes(\"$nom[47]\"); // Boîte Réseaux sociaux deuxième langue

\$serviz[0] = \"on\"; // Citations ON
\$serviz[1] = stripslashes(\"$serviz[1]\"); // Choix Page d'accueil-Blog ON / OFF
\$serviz[2] = stripslashes(\"$serviz[2]\"); // Nb de news / page
// serviz[3] is now in confskin.inc // Boite Articles gauche ON / OFF
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
\$serviz[16] = stripslashes(\"$serviz[16]\"); // Publication Nouvelles RSS ON / OFF
\$serviz[17] = stripslashes(\"$serviz[17]\"); // Nb de messages Forum / page
\$serviz[18] = stripslashes(\"$serviz[18]\"); // Catégories Forum ON / OFF
\$serviz[19] = \"on\"; // Bannières ON
\$serviz[20] = stripslashes(\"$serviz[20]\"); // Nb de messages Thread / page
\$serviz[21] = stripslashes(\"$serviz[21]\"); // Photorama avancé ON /OFF
// serviz[22] is in confskin.inc  // Boite Articles droit ON / OFF
// serviz[23] is in confskin.inc  // Sondage ON / OFF
\$serviz[24] = \"on\"; // Recherche ON
\$serviz[25] = stripslashes(\"$serviz[25]\"); // Menu dynamique Articles gauche
\$serviz[26] = stripslashes(\"$serviz[26]\"); // Menu dynamique Articles droit
\$serviz[27] = stripslashes(\"$serviz[27]\"); // Billets RSS des amis ON /OFF
// serviz[28] is in confskin.inc  // Préférences visiteurs
\$serviz[29] = stripslashes(\"$serviz[29]\"); // Réactions aux articles ON / OFF / Ok Admin
\$serviz[30] = stripslashes(\"$serviz[30]\"); // Nb Commentaires blog - Réactions aux articles / page
\$serviz[31] = stripslashes(\"$serviz[31]\"); // Pseudo préférences webmaster
\$serviz[32] = stripslashes(\"$serviz[32]\"); // Accès à l'administration rapide
\$serviz[33] = stripslashes(\"$serviz[33]\"); // Compteur de lecture Articles
\$serviz[34] = stripslashes(\"$serviz[34]\"); // Compteur de lecture Threads Forum
\$serviz[35] = stripslashes(\"$serviz[35]\"); // Compteur de Nb de téléchargements
\$serviz[36] = stripslashes(\"$serviz[36]\"); // Newsletter ON / OFF /TEST
\$serviz[37] = stripslashes(\"$serviz[37]\"); // Nb de news publiées
// \$serviz[38] is in confskin.inc  // RSS News ON / OFF
\$serviz[39] = stripslashes(\"$serviz[39]\"); // Durée Cache RSS
\$serviz[40] = stripslashes(\"$serviz[40]\"); // Publication dans livre d'or
\$serviz[41] = stripslashes(\"$serviz[41]\"); // Publication dans forum
\$serviz[42] = stripslashes(\"$serviz[42]\"); // Option Rédacteur ON / OFF
\$serviz[43] = stripslashes(\"$serviz[43]\"); // Avatar préférences webmaster
\$serviz[44] = stripslashes(\"$serviz[44]\"); // Mise en maintenance du site
\$serviz[45] = stripslashes(\"$serviz[45]\"); // Masquer l'icône Admin
\$serviz[46] = stripslashes(\"$serviz[46]\"); // Nb de messages Agenda / page
\$serviz[47] = stripslashes(\"$serviz[47]\"); // Agenda ON / OFF
\$serviz[48] = stripslashes(\"$serviz[48]\"); // Nb de messages maximum dans Tinymessage
\$serviz[49] = stripslashes(\"$serviz[49]\"); // Choix editeur
\$serviz[50] = stripslashes(\"$serviz[50]\"); // Nb maxi de fichiers dans data/error
\$serviz[51] = stripslashes(\"$serviz[51]\"); // Nb maxi de lignes dans l'anti-spam
\$serviz[52] = stripslashes(\"$serviz[52]\"); // Durée maxi de validité du code anti-spam
\$serviz[53] = stripslashes(\"$serviz[53]\"); // Blog ON / OFF
\$serviz[54] = stripslashes(\"$serviz[54]\"); // Publication Blog RSS ON / OFF
\$serviz[55] = stripslashes(\"$serviz[55]\"); // Nb de Blogs / page
\$serviz[56] = stripslashes(\"$serviz[56]\"); // Nb de blogs publiés
\$serviz[57] = stripslashes(\"$serviz[57]\"); // Commentaires sur Blog ON / OFF / Ok Admin
\$serviz[58] = stripslashes(\"$serviz[58]\"); // Blog pleine page ON / OFF
\$serviz[59] = stripslashes(\"$serviz[59]\"); // Menu dynamique Blog
\$serviz[60] = stripslashes(\"$serviz[60]\"); // Publication Articles RSS ON / OFF
\$serviz[61] = stripslashes(\"$serviz[61]\"); // Nb de billets récents/commentaires / page
\$serviz[62] = stripslashes(\"$serviz[62]\"); // Recommander ON/OFF
\$serviz[63] = stripslashes(\"$serviz[63]\"); // Largeur de l'éditeur

\$forum[3] = stripslashes(\"$forum[3]\"); // Forum pleine page ON / OFF
\$forum[4] = stripslashes(\"$forum[4]\"); // Nombre de catégories
\$forum[5] = stripslashes(\"$forum[5]\"); // Durée thread up (heures)
\$forum[6] = stripslashes(\"$forum[6]\"); // Durée thread au top (jours)
\$forum[7] = stripslashes(\"$forum[7]\"); // Echelle des messages
\$forum[8] = stripslashes(\"$forum[8]\"); // Durée nouveau
\$forum[9] = stripslashes(\"$forum[9]\"); // Affichage charte du forum ON / OFF

\$supervision[0] = stripslashes(\"$supervision[0]\"); // e-mail compteur
\$supervision[1] = stripslashes(\"$supervision[1]\"); // incrément de compteur pour e-mail
\$supervision[2] = stripslashes(\"$supervision[2]\"); // e-mail publication nouvelle
\$supervision[3] = stripslashes(\"$supervision[3]\"); // e-mail publication livre d'or
\$supervision[4] = stripslashes(\"$supervision[4]\"); // e-mail publication forum
\$supervision[5] = stripslashes(\"$supervision[5]\"); // Type d'e-mail PHP
\$supervision[6] = stripslashes(\"$supervision[6]\"); // e-mail réagir aux articles
\$supervision[7] = stripslashes(\"$supervision[7]\"); // e-mail inscription ou résiliation Newsletter
\$supervision[8] = stripslashes(\"$supervision[8]\"); // e-mail publication blog
\$supervision[9] = stripslashes(\"$supervision[9]\"); // e-mail commentaire blog
\$supervision[10] = stripslashes(\"$supervision[10]\"); // e-mail publication forum aux modérateurs ON/OFF

\$editobox[0] = stripslashes(\"$editobox[0]\"); // Première boite page d'accueil
\$editobox[1] = stripslashes(\"$editobox[1]\"); // Seconde boite page d'accueil
\$editobox[2] = stripslashes(\"$editobox[2]\"); // Troisième boite page d'accueil
\$editobox[3] = stripslashes(\"$editobox[3]\"); // Quatrième boite page d'accueil
\$editobox[4] = stripslashes(\"$editobox[4]\"); // Cinquième boite page d'accueil
\$editobox[5] = stripslashes(\"$editobox[5]\"); // Sixième boite page d'accueil

\$configlog[0] = stripslashes(\"$configlog[0]\"); // Nombre des messages visibles dans l'admin log
\$configlog[1] = stripslashes(\"$configlog[1]\"); // Inclure les logs de la page Index/Accueil
\$configlog[2] = stripslashes(\"$configlog[2]\"); // Inclure les logs de la page Nouvelles
\$configlog[3] = stripslashes(\"$configlog[3]\"); // Inclure les logs de la page Photos
\$configlog[4] = stripslashes(\"$configlog[4]\"); // Inclure les logs de la page Liens
\$configlog[5] = stripslashes(\"$configlog[5]\"); // Inclure les logs de la page Téléchargement
\$configlog[6] = stripslashes(\"$configlog[6]\"); // Inclure les logs de la page Livre d'or
\$configlog[7] = stripslashes(\"$configlog[7]\"); // Inclure les logs de la page FAQ
\$configlog[8] = stripslashes(\"$configlog[8]\"); // Inclure les logs de la page Forum
\$configlog[9] = stripslashes(\"$configlog[9]\"); // Inclure les logs de la page Stats
\$configlog[10] = stripslashes(\"$configlog[10]\"); // Inclure les logs de la page Admin
\$configlog[11] = stripslashes(\"$configlog[11]\"); // Inclure les logs de la page Blog

\$members[0] = stripslashes(\"$members[0]\"); // Activation de la zone membres
\$members[1] = stripslashes(\"$members[1]\"); // Zone membre accès à la section Articles
\$members[2] = stripslashes(\"$members[2]\"); // Zone membre accès à la section Photo
\$members[3] = stripslashes(\"$members[3]\"); // Zone membre accès à la section Liens
\$members[4] = stripslashes(\"$members[4]\"); // Zone membre accès à la section FAQ
\$members[5] = stripslashes(\"$members[5]\"); // Zone membre accès à la section Forum
\$members[6] = stripslashes(\"$members[6]\"); // Zone membre accès à la section Statistiques
\$members[7] = stripslashes(\"$members[7]\"); // Zone membre accès à la section Téléchargement
\$members[8] = stripslashes(\"$members[8]\"); // Zone membre accès publication Nouvelles
\$members[9] = stripslashes(\"$members[9]\"); // Zone membre accès publication Livre d'Or
\$members[10] = stripslashes(\"$members[10]\"); // Zone membre accès publication Forum
\$members[11] = stripslashes(\"$members[11]\"); // Zone membre accès publication Reactions aux articles
\$members[12] = stripslashes(\"$members[12]\"); // Zone membre accès à la section Livre d'Or
\$members[13] = stripslashes(\"$members[13]\"); // Zone membre accès à la section Nouvelles
\$members[14] = stripslashes(\"$members[14]\"); // Zone membre accès à la section Agenda
\$members[15] = stripslashes(\"$members[15]\"); // Zone membre accès à la section Blog
\$members[16] = stripslashes(\"$members[16]\"); // Zone membre accès publication Blog
\$members[17] = stripslashes(\"$members[17]\"); // Zone membre accès publication Commentaires blog
\$members[18] = stripslashes(\"$members[18]\"); // Zone membre accès inscription Newsletter
\$members[19] = stripslashes(\"$members[19]\"); // Inscriptions membres on /off / ok mail / ok webmaster
";

WriteFullDB(CONFIG,$mettre);
