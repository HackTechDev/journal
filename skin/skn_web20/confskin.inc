<?php
if (stristr($_SERVER["SCRIPT_NAME"], "confskin.inc")) {
  header("location:../index.php");
  die();
}
$page[0] = stripslashes("#E4EDEF"); // Arrière-plan du site
$page[1] = stripslashes("Arial, Helvetica, sans-serif"); // Police des boites centrales
$page[2] = stripslashes("12px"); // Taille des textes des boites centrales
$page[3] = stripslashes(""); // Image de fond du site
$page[4] = stripslashes("gylogo.gif"); // Logo du site
$page[5] = stripslashes("#FFC800"); // Arrière-plan du bandeau
$page[6] = stripslashes(""); // Image de fond du bandeau
$page[7] = stripslashes(""); // Transition entre pages
$page[8] = stripslashes("on"); // Affichage Temps de chargement de page ON / OFF
$page[9] = stripslashes(""); // Thème d'icônes
$page[10] = stripslashes(""); // Image de fond fixe / mouvante
$page[11] = stripslashes(""); // Thème de compteur de visites
 // Thème smileys for site is in config.inc
$page[13] = stripslashes(""); // Image Page en cours de chargement
 // Default Thème skins is in config.inc
$page[15] = stripslashes("on"); // Effet animation liens
$page[16] = stripslashes("Arial, Helvetica, sans-serif"); // Police des boites latérales
$page[17] = stripslashes("11px"); // Taille des textes des boites latérales
$page[18] = stripslashes("Arial, Helvetica, sans-serif"); // Police du menu de navigation
$page[19] = stripslashes("11px"); // Taille des liens du menu de navigation
$page[20] = stripslashes(""); // Rollover sur les icônes
$page[21] = stripslashes(""); // Image de fond du menu
$page[22] = stripslashes("on"); // utilisation titres longs
 // Thème avatars for the site is in config.inc
$page[24] = stripslashes(""); // Curseur dans body

$titre[0] = stripslashes("#FFFFFF"); // Couleur du titre des boites centrales
$titre[1] = stripslashes("#88c81a"); // Arrière-plan du titre des boites centrales
$titre[2] = stripslashes("Arial, Helvetica, sans-serif"); // Police des titres des boites centrales
$titre[3] = stripslashes("18px"); // Taille des titres des boites centrales
$titre[4] = stripslashes("#526eb0"); // Couleur du titre des boites latérales
$titre[5] = stripslashes("#FFC800"); // Arrière-plan du titre des boites latérales
$titre[6] = stripslashes("Arial, Helvetica, sans-serif"); // Police des titres des boites latérales
$titre[7] = stripslashes("15px"); // Taille des titres des boites latérales
$titre[8] = stripslashes(""); // Image de fond titre des boites centrales
$titre[9] = stripslashes(""); // Image de fond titre des boites latérales

$texte[0] = stripslashes("#000000"); // Couleur des textes des boites centrales
$texte[1] = stripslashes("#FFFFFF"); // Arrière-plan OFF des boites centrales
$texte[2] = stripslashes("#FFFFFF"); // Arrière-plan ON des boites centrales

$texte[4] = stripslashes("1px"); // Taille des bordures
$texte[5] = stripslashes("#000000"); // Couleur des textes des boites latérales
$texte[6] = stripslashes("#FFFFFF"); // Arrière-plan OFF des boites latérales
$texte[7] = stripslashes("#FFFFFF"); // Arrière-plan ON des boites latérales
$texte[8] = stripslashes("inherit"); // Couleur des textes de bas de page

$bordure[0] = stripslashes("#AEDAFC"); // Couleur des bordures
$bordure[1] = stripslashes("#FFFFFF"); // Couleur de la base de la barre de défilement
$bordure[2] = stripslashes("#88c81a"); // Couleur des flèches de la barre de défilement

$lien[0] = stripslashes("#526eb0"); // Liens OFF des boites centrales
$lien[1] = stripslashes("#88c81a"); // Liens ON des boites centrales
$lien[2] = stripslashes("#526eb0"); // Liens OFF des boites latérales
$lien[3] = stripslashes("#88c81a"); // Liens ON des boites latérales
$lien[4] = stripslashes("#526eb0"); // Liens OFF de la barre de menu haute
$lien[5] = stripslashes("#88c81a"); // Liens ON de la barre de menu haute

$barre[0] = stripslashes("#000000"); // Couleur des HR
$barre[1] = stripslashes("0px"); // Taille des HR
$barre[2] = stripslashes("inset"); // Style des HR

$forum[0] = stripslashes("#FFFFFF"); // Arrière plan entêtes
$forum[1] = stripslashes("#ECF7FF"); // Arrière plan question
$forum[2] = stripslashes("#ECF7FF"); // Arrière plan réponse

$calendar[0] = stripslashes("inherit"); // Couleur de fond des jours libres du mois
$calendar[1] = stripslashes("#FFFFFF"); // Couleur de fond des jours
$calendar[2] = stripslashes("#33CCCC"); // Couleur de fond de la journée
$calendar[3] = stripslashes("#FFC800"); // Couleur de fond des dimanches
$calendar[4] = stripslashes("#88c81a"); // Couleur de fond de la journée si dimanche
$calendar[5] = stripslashes("Arial, Helvetica, sans-serif"); // Police du calendrier
$calendar[6] = stripslashes("12px"); // Taille de la police du calendrier
$calendar[7] = stripslashes("#000000"); // Couleurs de la police des chiffres
$calendar[8] = stripslashes("#000000"); // Couleurs de la police des jours de la semaine
$calendar[9] = stripslashes("1px"); // Taille des bordures du calendrier
$calendar[10] = stripslashes("#FF6699"); // Couleur évènement
$calendar[11] = stripslashes("#FFFFFF"); // Couleur de fond du calendrier

$citation[0] = stripslashes("Arial, Helvetica, sans-serif"); // Police des citations
$citation[1] = stripslashes("12px"); // Taille de la police des citations
$citation[2] = stripslashes("#526eb0"); // Couleur de la police des citations

$presform[0] = stripslashes("#000000"); // Couleur des textes dans les boites de choix et boutons de commande
$presform[1] = stripslashes("#FFFFFF"); // Couleur des boites de choix
$presform[2] = stripslashes("#FFFFFF"); // Couleur des boutons de commande
$presform[3] = stripslashes("#FFFFFF"); // Couleur des zone de texte
$presform[4] = stripslashes("Arial, Helvetica, sans-serif"); // Police dans la présentation des formulaires
$presform[5] = stripslashes("11px"); // Taille de la police dans la présentation des formulaires
$presform[6] = stripslashes("#FFFFFF"); // Couleur de fond des textarea
$presform[7] = stripslashes("1px"); // Taille de la bordure
$presform[8] = stripslashes("#FFC800"); // Couleur de la bordure

$serviz[3] = stripslashes("on"); // Boite Articles gauche ON / OFF
$serviz[22] = stripslashes("on"); // Boite Articles droit ON / OFF
$serviz[23] = stripslashes("on"); // Sondage ON / OFF
$serviz[24] = stripslashes("on"); // Recherche ON / OFF
$serviz[28] = stripslashes("on"); // Préférences visiteurs
// serviz36 is now in config.inc: Newsletter ON / OFF / TEST
$serviz[38] = stripslashes("on"); // RSS News ON / OFF

$posbox[0] = stripslashes(""); // Première boite à gauche
$posbox[1] = stripslashes("inc/boxuser"); // Première boite à droite
$posbox[2] = stripslashes("inc/boxartg"); // Seconde boite à gauche
$posbox[3] = stripslashes("inc/boxfree2"); // Seconde boite à droite
$posbox[4] = stripslashes("inc/boxartd"); // Troisième boite à gauche
$posbox[5] = stripslashes("inc/boxsearch"); // Troisième boite à droite
$posbox[6] = stripslashes(""); // Quatrième boite à gauche
$posbox[7] = stripslashes("inc/boxpoll"); // Quatrième boite à droite
$posbox[8] = stripslashes("inc/boxwebm"); // Cinquième boite à gauche
$posbox[9] = stripslashes("inc/boxcal"); // Cinquième boite à droite
$posbox[10] = stripslashes("inc/boxnewslet"); // Sixième  boite à gauche
$posbox[11] = stripslashes("plugins/mind/boxmind"); // Sixième  boite à droite
$posbox[12] = stripslashes("inc/boxcount"); // Septième  boite à gauche
$posbox[13] = stripslashes("inc/boxrss"); // Septième  boite à droite
$posbox[14] = stripslashes(""); // Huitième  boite à gauche
$posbox[15] = stripslashes(""); // Huitième  boite à droite
$posbox[16] = stripslashes(""); // Neuvième  boite à gauche
$posbox[17] = stripslashes(""); // Neuvième  boite à droite
$posbox[18] = stripslashes(""); // Dixième boite à gauche
$posbox[19] = stripslashes(""); // Dixième  boite à droite
$posbox[20] = stripslashes("inc/boxspec"); // Boîte supplémentaire au centre
$posbox[21] = stripslashes(""); // Boîte supplémentaire au dessous

$posbox[30] = stripslashes("inc/boxban"); // Emplacement logo 1
$posbox[31] = stripslashes("inc/boxlogo"); // Emplacement bannières
$posbox[32] = stripslashes("inc/boxmenu"); // Emplacement citations
$posbox[33] = stripslashes(""); // Emplacement logo 2
$posbox[34] = stripslashes(""); // Emplacement menu icônes


$xposbox["L"][0] = stripslashes("");
$xposbox["L"][1] = stripslashes("inc/boxartg");
$xposbox["L"][2] = stripslashes("inc/boxartd");
$xposbox["L"][3] = stripslashes("");
$xposbox["L"][4] = stripslashes("inc/boxwebm");
$xposbox["L"][5] = stripslashes("inc/boxnewslet");
$xposbox["L"][6] = stripslashes("inc/boxcount");
$xposbox["L"][7] = stripslashes("");
$xposbox["L"][8] = stripslashes("");
$xposbox["L"][9] = stripslashes("");
$xposbox["R"][0] = stripslashes("inc/boxuser");
$xposbox["R"][1] = stripslashes("inc/boxfree2");
$xposbox["R"][2] = stripslashes("inc/boxsearch");
$xposbox["R"][3] = stripslashes("inc/boxpoll");
$xposbox["R"][4] = stripslashes("inc/boxcal");
$xposbox["R"][5] = stripslashes("plugins/mind/boxmind");
$xposbox["R"][6] = stripslashes("inc/boxrss");
$xposbox["R"][7] = stripslashes("");
$xposbox["R"][8] = stripslashes("");
$xposbox["R"][9] = stripslashes("");
$xposbox["C"][0] = stripslashes("inc/boxspec");
$xposbox["C"][1] = stripslashes("");
$xposbox["C"][2] = stripslashes("");
$xposbox["B"][0] = stripslashes("");
$xposbox["B"][1] = stripslashes("");

?>