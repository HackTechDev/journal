<?php
if (stristr($_SERVER["SCRIPT_NAME"], "confskin.inc")) {
  header("location:../index.php");
  die();
}
$page[0] = stripslashes("#DBE9F7"); // Arri�re-plan du site
$page[1] = stripslashes("Arial, Helvetica, sans-serif"); // Police des boites centrales
$page[2] = stripslashes("12px"); // Taille des textes des boites centrales
$page[3] = stripslashes(""); // Image de fond du site
$page[4] = stripslashes("gylogo.gif"); // Logo du site
$page[5] = stripslashes("transparent"); // Arri�re-plan du bandeau
$page[6] = stripslashes(""); // Image de fond du bandeau
$page[7] = stripslashes(""); // Transition entre pages
$page[8] = stripslashes("on"); // Affichage Temps de chargement de page ON / OFF
$page[9] = stripslashes(""); // Th�me d'ic�nes
$page[10] = stripslashes(""); // Image de fond fixe / mouvante
$page[11] = stripslashes(""); // Th�me de compteur de visites
 // Th�me smileys for site is in config.inc
$page[13] = stripslashes(""); // Image Page en cours de chargement
 // Default Th�me skins is in config.inc
$page[15] = stripslashes("on"); // Effet animation liens
$page[16] = stripslashes("Arial, Helvetica, sans-serif"); // Police des boites lat�rales
$page[17] = stripslashes("12px"); // Taille des textes des boites lat�rales
$page[18] = stripslashes("Arial, Helvetica, sans-serif"); // Police du menu de navigation
$page[19] = stripslashes("11px"); // Taille des liens du menu de navigation
$page[20] = stripslashes(""); // Rollover sur les ic�nes
$page[21] = stripslashes(""); // Image de fond du menu
$page[22] = stripslashes("on"); // utilisation titres longs
 // Th�me avatars for the site is in config.inc
$page[24] = stripslashes(""); // Curseur dans body

$titre[0] = stripslashes("#330099"); // Couleur du titre des boites centrales
$titre[1] = stripslashes("#C5DCF5"); // Arri�re-plan du titre des boites centrales
$titre[2] = stripslashes("Arial, Helvetica, sans-serif"); // Police des titres des boites centrales
$titre[3] = stripslashes("15px"); // Taille des titres des boites centrales
$titre[4] = stripslashes("#330099"); // Couleur du titre des boites lat�rales
$titre[5] = stripslashes("#C5DCF5"); // Arri�re-plan du titre des boites lat�rales
$titre[6] = stripslashes("Arial, Helvetica, sans-serif"); // Police des titres des boites lat�rales
$titre[7] = stripslashes("15px"); // Taille des titres des boites lat�rales
$titre[8] = stripslashes(""); // Image de fond titre des boites centrales
$titre[9] = stripslashes(""); // Image de fond titre des boites lat�rales

$texte[0] = stripslashes("#330099"); // Couleur des textes des boites centrales
$texte[1] = stripslashes("#DBE9F7"); // Arri�re-plan OFF des boites centrales
$texte[2] = stripslashes("#E6EDFC"); // Arri�re-plan ON des boites centrales

$texte[4] = stripslashes("0px"); // Taille des bordures
$texte[5] = stripslashes("#330099"); // Couleur des textes des boites lat�rales
$texte[6] = stripslashes("inherit"); // Arri�re-plan OFF des boites lat�rales
$texte[7] = stripslashes("#E6EDFC"); // Arri�re-plan ON des boites lat�rales
$texte[8] = stripslashes("#6600CC"); // Couleur des textes de bas de page

$bordure[0] = stripslashes("inherit"); // Couleur des bordures
$bordure[1] = stripslashes("#A3C2E6"); // Couleur de la base de la barre de d�filement
$bordure[2] = stripslashes("#330099"); // Couleur des fl�ches de la barre de d�filement

$lien[0] = stripslashes("#0033CC"); // Liens OFF des boites centrales
$lien[1] = stripslashes("#FF3366"); // Liens ON des boites centrales
$lien[2] = stripslashes("#0066CC"); // Liens OFF des boites lat�rales
$lien[3] = stripslashes("#FF3366"); // Liens ON des boites lat�rales
$lien[4] = stripslashes("#3300CC"); // Liens OFF de la barre de menu haute
$lien[5] = stripslashes("#FFCC00"); // Liens ON de la barre de menu haute

$barre[0] = stripslashes("#99CCFF"); // Couleur des HR
$barre[1] = stripslashes("1px"); // Taille des HR
$barre[2] = stripslashes("inset"); // Style des HR

$forum[0] = stripslashes("#FFDA25"); // Arri�re plan ent�tes
$forum[1] = stripslashes("#4CA2D4"); // Arri�re plan question
$forum[2] = stripslashes("#FFFFFF"); // Arri�re plan r�ponse

$calendar[0] = stripslashes("#DBE9F7"); // Couleur de fond des jours libres du mois
$calendar[1] = stripslashes("#C5DCF5"); // Couleur de fond des jours
$calendar[2] = stripslashes("#4A9FAC"); // Couleur de fond de la journ�e
$calendar[3] = stripslashes("#77A7D3"); // Couleur de fond des dimanches
$calendar[4] = stripslashes("#4A9FAC"); // Couleur de fond de la journ�e si dimanche
$calendar[5] = stripslashes("Arial, Helvetica, sans-serif"); // Police du calendrier
$calendar[6] = stripslashes("12px"); // Taille de la police du calendrier
$calendar[7] = stripslashes("#3300CC"); // Couleurs de la police des chiffres
$calendar[8] = stripslashes("#330099"); // Couleurs de la police des jours de la semaine
$calendar[9] = stripslashes("1px"); // Taille des bordures du calendrier
$calendar[10] = stripslashes("#97B7BF"); // Couleur �v�nement
$calendar[11] = stripslashes("#DBE9F7"); // Couleur de fond du calendrier

$citation[0] = stripslashes("Arial, Helvetica, sans-serif"); // Police des citations
$citation[1] = stripslashes("12px"); // Taille de la police des citations
$citation[2] = stripslashes("#3300CC"); // Couleur de la police des citations

$presform[0] = stripslashes("#000099"); // Couleur des textes dans les boites de choix et boutons de commande
$presform[1] = stripslashes("#CFE5F9"); // Couleur des boites de choix
$presform[2] = stripslashes("#CFE5F9"); // Couleur des boutons de commande
$presform[3] = stripslashes("#CFE5F9"); // Couleur des zone de texte
$presform[4] = stripslashes("Arial, Helvetica, sans-serif"); // Police dans la pr�sentation des formulaires
$presform[5] = stripslashes("11px"); // Taille de la police dans la pr�sentation des formulaires
$presform[6] = stripslashes("#CFE5F9"); // Couleur de fond des textarea
$presform[7] = stripslashes("1px"); // Taille de la bordure
$presform[8] = stripslashes("#AECBED"); // Couleur de la bordure

$serviz[3] = stripslashes("on"); // Boite Articles gauche ON / OFF
$serviz[22] = stripslashes("on"); // Boite Articles droit ON / OFF
$serviz[23] = stripslashes("on"); // Sondage ON / OFF
$serviz[28] = stripslashes("on"); // Pr�f�rences visiteurs
$serviz[38] = stripslashes("on"); // RSS News ON / OFF

$posbox[0] = stripslashes(""); // Premi�re boite � gauche
$posbox[1] = stripslashes("inc/boxuser"); // Premi�re boite � droite
$posbox[2] = stripslashes("inc/boxartg"); // Seconde boite � gauche
$posbox[3] = stripslashes("inc/boxwebm"); // Seconde boite � droite
$posbox[4] = stripslashes("inc/boxartd"); // Troisi�me boite � gauche
$posbox[5] = stripslashes(""); // Troisi�me boite � droite
$posbox[6] = stripslashes("inc/boxpoll"); // Quatri�me boite � gauche
$posbox[7] = stripslashes("inc/boxnewslet"); // Quatri�me boite � droite
$posbox[8] = stripslashes("inc/boxfree1"); // Cinqui�me boite � gauche
$posbox[9] = stripslashes("inc/boxrss"); // Cinqui�me boite � droite
$posbox[10] = stripslashes("inc/boxfree2"); // Sixi�me  boite � gauche
$posbox[11] = stripslashes("inc/boxsearch"); // Sixi�me  boite � droite
$posbox[12] = stripslashes("inc/boxcount"); // Septi�me  boite � gauche
$posbox[13] = stripslashes(""); // Septi�me  boite � droite
$posbox[14] = stripslashes("inc/boxcal"); // Huiti�me  boite � gauche
$posbox[15] = stripslashes(""); // Huiti�me  boite � droite
$posbox[16] = stripslashes(""); // Neuvi�me  boite � gauche
$posbox[17] = stripslashes(""); // Neuvi�me  boite � droite
$posbox[18] = stripslashes(""); // Dixi�me boite � gauche
$posbox[19] = stripslashes(""); // Dixi�me  boite � droite
$posbox[20] = stripslashes("inc/boxspec"); // Bo�te suppl�mentaire au centre
$posbox[21] = stripslashes(""); // Bo�te suppl�mentaire au dessous

$posbox[30] = stripslashes("inc/boxlogo"); // Emplacement logo 1
$posbox[31] = stripslashes("inc/boxban"); // Emplacement banni�res
$posbox[32] = stripslashes("inc/boxcita"); // Emplacement citations
$posbox[33] = stripslashes("inc/boxmenu"); // Emplacement logo 2
$posbox[34] = stripslashes(""); // Emplacement menu ic�nes


$xposbox["L"][0] = stripslashes("");
$xposbox["L"][1] = stripslashes("inc/boxartg");
$xposbox["L"][2] = stripslashes("inc/boxartd");
$xposbox["L"][3] = stripslashes("inc/boxpoll");
$xposbox["L"][4] = stripslashes("inc/boxfree1");
$xposbox["L"][5] = stripslashes("inc/boxfree2");
$xposbox["L"][6] = stripslashes("inc/boxcount");
$xposbox["L"][7] = stripslashes("inc/boxcal");
$xposbox["L"][8] = stripslashes("");
$xposbox["L"][9] = stripslashes("");
$xposbox["L"][10] = stripslashes("");
$xposbox["R"][0] = stripslashes("inc/boxuser");
$xposbox["R"][1] = stripslashes("inc/boxwebm");
$xposbox["R"][2] = stripslashes("");
$xposbox["R"][3] = stripslashes("inc/boxnewslet");
$xposbox["R"][4] = stripslashes("inc/boxrss");
$xposbox["R"][5] = stripslashes("inc/boxsearch");
$xposbox["R"][6] = stripslashes("");
$xposbox["R"][7] = stripslashes("");
$xposbox["R"][8] = stripslashes("");
$xposbox["R"][9] = stripslashes("");
$xposbox["R"][10] = stripslashes("");
$xposbox["C"][0] = stripslashes("inc/boxspec");
$xposbox["C"][1] = stripslashes("");
$xposbox["C"][2] = stripslashes("");
$xposbox["B"][0] = stripslashes("");
$xposbox["B"][1] = stripslashes("");