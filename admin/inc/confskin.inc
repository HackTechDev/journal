<?php
/*
    Config Skin - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.6.0 (04 June 2007)        : initial release by Icare
      v4.6.10 (7 September 2009)  : corrected some $serviz

*/
if (stristr($_SERVER["SCRIPT_NAME"], "confskin.inc")) {
  header("location:../index.php");
  die();
}

$mettre = '<?php
if (stristr($_SERVER["SCRIPT_NAME"], "confskin.inc")) {
  header("location:../index.php");
  die();
}
$page[0] = stripslashes("'.$page[0].'"); // Arrière-plan du site
$page[1] = stripslashes("'.$page[1].'"); // Police des boites centrales
$page[2] = stripslashes("'.$page[2].'"); // Taille des textes des boites centrales
$page[3] = stripslashes("'.$page[3].'"); // Image de fond du site
$page[4] = stripslashes("'.$page[4].'"); // Logo du site
$page[5] = stripslashes("'.$page[5].'"); // Arrière-plan du bandeau
$page[6] = stripslashes("'.$page[6].'"); // Image de fond du bandeau
$page[7] = stripslashes("'.$page[7].'"); // Transition entre pages
$page[8] = stripslashes("'.$page[8].'"); // Affichage Temps de chargement de page ON / OFF
$page[9] = stripslashes("'.$page[9].'"); // Thème d\'icônes
$page[10] = stripslashes("'.$page[10].'"); // Image de fond fixe / mouvante
$page[11] = stripslashes("'.$page[11].'"); // Thème de compteur de visites
 // Thème smileys for site is in config.inc
$page[13] = stripslashes("'.$page[13].'"); // Image Page en cours de chargement
 // Default Thème skins is in config.inc
$page[15] = stripslashes("'.$page[15].'"); // Effet animation liens
$page[16] = stripslashes("'.$page[16].'"); // Police des boites latérales
$page[17] = stripslashes("'.$page[17].'"); // Taille des textes des boites latérales
$page[18] = stripslashes("'.$page[18].'"); // Police du menu de navigation
$page[19] = stripslashes("'.$page[19].'"); // Taille des liens du menu de navigation
$page[20] = stripslashes("'.$page[20].'"); // Rollover sur les icônes
$page[21] = stripslashes("'.$page[21].'"); // Image de fond du menu
$page[22] = stripslashes("'.$page[22].'"); // utilisation titres longs
 // Thème avatars for the site is in config.inc
$page[24] = stripslashes("'.$page[24].'"); // Curseur dans body

$titre[0] = stripslashes("'.$titre[0].'"); // Couleur du titre des boites centrales
$titre[1] = stripslashes("'.$titre[1].'"); // Arrière-plan du titre des boites centrales
$titre[2] = stripslashes("'.$titre[2].'"); // Police des titres des boites centrales
$titre[3] = stripslashes("'.$titre[3].'"); // Taille des titres des boites centrales
$titre[4] = stripslashes("'.$titre[4].'"); // Couleur du titre des boites latérales
$titre[5] = stripslashes("'.$titre[5].'"); // Arrière-plan du titre des boites latérales
$titre[6] = stripslashes("'.$titre[6].'"); // Police des titres des boites latérales
$titre[7] = stripslashes("'.$titre[7].'"); // Taille des titres des boites latérales
$titre[8] = stripslashes("'.$titre[8].'"); // Image de fond titre des boites centrales
$titre[9] = stripslashes("'.$titre[9].'"); // Image de fond titre des boites latérales

$texte[0] = stripslashes("'.$texte[0].'"); // Couleur des textes des boites centrales
$texte[1] = stripslashes("'.$texte[1].'"); // Arrière-plan OFF des boites centrales
$texte[2] = stripslashes("'.$texte[2].'"); // Arrière-plan ON des boites centrales

$texte[4] = stripslashes("'.$texte[4].'"); // Taille des bordures
$texte[5] = stripslashes("'.$texte[5].'"); // Couleur des textes des boites latérales
$texte[6] = stripslashes("'.$texte[6].'"); // Arrière-plan OFF des boites latérales
$texte[7] = stripslashes("'.$texte[7].'"); // Arrière-plan ON des boites latérales
$texte[8] = stripslashes("'.$texte[8].'"); // Couleur des textes de bas de page

$bordure[0] = stripslashes("'.$bordure[0].'"); // Couleur des bordures
$bordure[1] = stripslashes("'.$bordure[1].'"); // Couleur de la base de la barre de défilement
$bordure[2] = stripslashes("'.$bordure[2].'"); // Couleur des flèches de la barre de défilement

$lien[0] = stripslashes("'.$lien[0].'"); // Liens OFF des boites centrales
$lien[1] = stripslashes("'.$lien[1].'"); // Liens ON des boites centrales
$lien[2] = stripslashes("'.$lien[2].'"); // Liens OFF des boites latérales
$lien[3] = stripslashes("'.$lien[3].'"); // Liens ON des boites latérales
$lien[4] = stripslashes("'.$lien[4].'"); // Liens OFF de la barre de menu haute
$lien[5] = stripslashes("'.$lien[5].'"); // Liens ON de la barre de menu haute

$barre[0] = stripslashes("'.$barre[0].'"); // Couleur des HR
$barre[1] = stripslashes("'.$barre[1].'"); // Taille des HR
$barre[2] = stripslashes("'.$barre[2].'"); // Style des HR

$forum[0] = stripslashes("'.$forum[0].'"); // Arrière plan entêtes
$forum[1] = stripslashes("'.$forum[1].'"); // Arrière plan question
$forum[2] = stripslashes("'.$forum[2].'"); // Arrière plan réponse

$calendar[0] = stripslashes("'.$calendar[0].'"); // Couleur de fond des jours libres du mois
$calendar[1] = stripslashes("'.$calendar[1].'"); // Couleur de fond des jours
$calendar[2] = stripslashes("'.$calendar[2].'"); // Couleur de fond de la journée
$calendar[3] = stripslashes("'.$calendar[3].'"); // Couleur de fond des dimanches
$calendar[4] = stripslashes("'.$calendar[4].'"); // Couleur de fond de la journée si dimanche
$calendar[5] = stripslashes("'.$calendar[5].'"); // Police du calendrier
$calendar[6] = stripslashes("'.$calendar[6].'"); // Taille de la police du calendrier
$calendar[7] = stripslashes("'.$calendar[7].'"); // Couleurs de la police des chiffres
$calendar[8] = stripslashes("'.$calendar[8].'"); // Couleurs de la police des jours de la semaine
$calendar[9] = stripslashes("'.$calendar[9].'"); // Taille des bordures du calendrier
$calendar[10] = stripslashes("'.$calendar[10].'"); // Couleur évènement
$calendar[11] = stripslashes("'.$calendar[11].'"); // Couleur de fond du calendrier

$citation[0] = stripslashes("'.$citation[0].'"); // Police des citations
$citation[1] = stripslashes("'.$citation[1].'"); // Taille de la police des citations
$citation[2] = stripslashes("'.$citation[2].'"); // Couleur de la police des citations

$presform[0] = stripslashes("'.$presform[0].'"); // Couleur des textes dans les boites de choix et boutons de commande
$presform[1] = stripslashes("'.$presform[1].'"); // Couleur des boites de choix
$presform[2] = stripslashes("'.$presform[2].'"); // Couleur des boutons de commande
$presform[3] = stripslashes("'.$presform[3].'"); // Couleur des zone de texte
$presform[4] = stripslashes("'.$presform[4].'"); // Police dans la présentation des formulaires
$presform[5] = stripslashes("'.$presform[5].'"); // Taille de la police dans la présentation des formulaires
$presform[6] = stripslashes("'.$presform[6].'"); // Couleur de fond des textarea
$presform[7] = stripslashes("'.$presform[7].'"); // Taille de la bordure
$presform[8] = stripslashes("'.$presform[8].'"); // Couleur de la bordure

$serviz[3] = stripslashes("'.$serviz[3].'"); // Boite Articles gauche ON / OFF
$serviz[22] = stripslashes("'.$serviz[22].'"); // Boite Articles droit ON / OFF
$serviz[23] = stripslashes("'.$serviz[23].'"); // Sondage ON / OFF
$serviz[28] = stripslashes("'.$serviz[28].'"); // Préférences visiteurs
$serviz[38] = stripslashes("'.$serviz[38].'"); // RSS News ON / OFF

$posbox[0] = stripslashes("'.$posbox[0].'"); // Première boite à gauche
$posbox[1] = stripslashes("'.$posbox[1].'"); // Première boite à droite
$posbox[2] = stripslashes("'.$posbox[2].'"); // Seconde boite à gauche
$posbox[3] = stripslashes("'.$posbox[3].'"); // Seconde boite à droite
$posbox[4] = stripslashes("'.$posbox[4].'"); // Troisième boite à gauche
$posbox[5] = stripslashes("'.$posbox[5].'"); // Troisième boite à droite
$posbox[6] = stripslashes("'.$posbox[6].'"); // Quatrième boite à gauche
$posbox[7] = stripslashes("'.$posbox[7].'"); // Quatrième boite à droite
$posbox[8] = stripslashes("'.$posbox[8].'"); // Cinquième boite à gauche
$posbox[9] = stripslashes("'.$posbox[9].'"); // Cinquième boite à droite
$posbox[10] = stripslashes("'.$posbox[10].'"); // Sixième  boite à gauche
$posbox[11] = stripslashes("'.$posbox[11].'"); // Sixième  boite à droite
$posbox[12] = stripslashes("'.$posbox[12].'"); // Septième  boite à gauche
$posbox[13] = stripslashes("'.$posbox[13].'"); // Septième  boite à droite
$posbox[14] = stripslashes("'.$posbox[14].'"); // Huitième  boite à gauche
$posbox[15] = stripslashes("'.$posbox[15].'"); // Huitième  boite à droite
$posbox[16] = stripslashes("'.$posbox[16].'"); // Neuvième  boite à gauche
$posbox[17] = stripslashes("'.$posbox[17].'"); // Neuvième  boite à droite
$posbox[18] = stripslashes("'.$posbox[18].'"); // Dixième boite à gauche
$posbox[19] = stripslashes("'.$posbox[19].'"); // Dixième  boite à droite
$posbox[20] = stripslashes("'.$posbox[20].'"); // Boîte supplémentaire au centre
$posbox[21] = stripslashes("'.$posbox[21].'"); // Boîte supplémentaire au dessous

$posbox[30] = stripslashes("'.$posbox[30].'"); // Emplacement logo 1
$posbox[31] = stripslashes("'.$posbox[31].'"); // Emplacement bannières
$posbox[32] = stripslashes("'.$posbox[32].'"); // Emplacement citations
$posbox[33] = stripslashes("'.$posbox[33].'"); // Emplacement logo 2
$posbox[34] = stripslashes("'.$posbox[34].'"); // Emplacement menu icônes

';

foreach (array("L", "R", "C", "B") as $subarray) {
  foreach ($xposbox[$subarray] as $key=>$value) {
    $mettre .= '
$xposbox["'.$subarray.'"]['.$key.'] = stripslashes("'.$value.'");';
  }
}

WriteFullDB($meskin."confskin.inc", $mettre); //add config to skin
