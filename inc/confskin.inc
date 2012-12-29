<?php
if (stristr($_SERVER["SCRIPT_NAME"], "confskin.inc")) {
  header("location:../index.php");
  die();
}
$page[0] = stripslashes("#CADEF0"); // Arrière-plan du site
$page[1] = stripslashes("Arial, Helvetica, sans-serif"); // Police des boites centrales
$page[2] = stripslashes("12px"); // Taille des textes des boites centrales
$page[3] = stripslashes("dolphins.jpeg"); // Image de fond du site
$page[4] = stripslashes("gylogo.gif"); // Logo du site
$page[5] = stripslashes(""); // Arrière-plan du bandeau
$page[6] = stripslashes(""); // Image de fond du bandeau
$page[7] = stripslashes(""); // Transition entre pages
$page[8] = stripslashes("on"); // Affichage Temps de chargement de page ON / OFF
$page[9] = stripslashes("ico_rol"); // Thème d'icônes
$page[10] = stripslashes(""); // Image de fond fixe / mouvante
$page[11] = stripslashes("cnt_3"); // Thème de compteur de visites
$page[12] = stripslashes("sml_1"); // Thème smileys
$page[13] = stripslashes(""); // Image Page en cours de chargement
 // Thème skins default in in config.inc
$page[15] = stripslashes("on"); // Effet animation liens
$page[16] = stripslashes("Arial, Helvetica, sans-serif"); // Police des boites latérales
$page[17] = stripslashes("11px"); // Taille des textes des boites latérales
$page[18] = stripslashes("Arial, sans-serif"); // Police du menu de navigation
$page[19] = stripslashes("11px"); // Taille des liens du menu de navigation
$page[20] = stripslashes("on"); // Rollover sur les icônes
$page[21] = stripslashes("fond7.gif"); // paramètre inutilisé
$page[22] = stripslashes("on"); // utilisation titres longs
$page[23] = stripslashes("ava_1"); // Thème avatars
$page[24] = stripslashes(""); // Curseur dans body

$titre[0] = stripslashes("#330099"); // Couleur du titre des boites centrales
$titre[1] = stripslashes("#A3C2E6"); // Arrière-plan du titre des boites centrales
$titre[2] = stripslashes("Comic sans MS, Arial, sans-serif"); // Police des titres des boites centrales
$titre[3] = stripslashes("15px"); // Taille des titres des boites centrales
$titre[4] = stripslashes("#330099"); // Couleur du titre des boites latérales
$titre[5] = stripslashes("#A3C2E6"); // Arrière-plan du titre des boites latérales
$titre[6] = stripslashes("Comic sans MS, Arial, sans-serif"); // Police des titres des boites latérales
$titre[7] = stripslashes("15px"); // Taille des titres des boites latérales
$titre[8] = stripslashes("fond7.gif"); // Image de fond titre des boites centrales
$titre[9] = stripslashes("fond7.gif"); // Image de fond titre des boites latérales

$texte[0] = stripslashes("#330099"); // Couleur des textes des boites centrales
$texte[1] = stripslashes("#DBE5F9"); // Arrière-plan OFF des boites centrales
$texte[2] = stripslashes("#E6EDFC"); // Arrière-plan ON des boites centrales
$texte[3] = stripslashes("&curren;"); // Puce articles
$texte[4] = stripslashes("1px"); // Taille des bordures
$texte[5] = stripslashes("#330099"); // Couleur des textes des boites latérales
$texte[6] = stripslashes("#DBE5F9"); // Arrière-plan OFF des boites latérales
$texte[7] = stripslashes("#E6EDFC"); // Arrière-plan ON des boites latérales

$bordure[0] = stripslashes("#A6C4E0"); // Couleur des bordures
$bordure[1] = stripslashes("#A3C2E6"); // Couleur de la base de la barre de défilement
$bordure[2] = stripslashes("#330099"); // Couleur des flèches de la barre de défilement

$lien[0] = stripslashes("#0033CC"); // Liens OFF des boites centrales
$lien[1] = stripslashes("#FF3366"); // Liens ON des boites centrales
$lien[2] = stripslashes("#0066CC"); // Liens OFF des boites latérales
$lien[3] = stripslashes("#FF3366"); // Liens ON des boites latérales
$lien[4] = stripslashes("#CCFFFF"); // Liens OFF de la barre de menu haute
$lien[5] = stripslashes("#FFCC00"); // Liens ON de la barre de menu haute

$barre[0] = stripslashes("#6666CC"); // Couleur des HR
$barre[1] = stripslashes("1px"); // Taille des HR
$barre[2] = stripslashes("inset"); // Style des HR

$forum[0] = stripslashes("#AECBED"); // Arrière plan entêtes
$forum[1] = stripslashes("#C5DCF5"); // Arrière plan question
$forum[2] = stripslashes("#CFE5F9"); // Arrière plan réponse
$forum[3] = stripslashes(""); // Forum pleine page ON / OFF
$forum[4] = stripslashes("12"); // Nombre de catégories
$forum[5] = stripslashes("1"); // Durée thread up (heures)
$forum[6] = stripslashes("1"); // Durée thread au top (jours)
$forum[7] = stripslashes("10-30-60-100"); // Echelle des messages
$forum[8] = stripslashes("1"); // Durée nouveau
$forum[9] = stripslashes(""); // Affichage charte du forum ON / OFF

$calendar[0] = stripslashes(""); // Couleur de fond des jours libres du mois
$calendar[1] = stripslashes("#BED6EE"); // Couleur de fond des jours
$calendar[2] = stripslashes("#4A9FAC"); // Couleur de fond de la journée
$calendar[3] = stripslashes("#77A7D3"); // Couleur de fond des dimanches
$calendar[4] = stripslashes("#4A9FAC"); // Couleur de fond de la journée si dimanche
$calendar[5] = stripslashes("Comic sans MS, Arial, sans-serif"); // Police du calendrier
$calendar[6] = stripslashes("12px"); // Taille de la police du calendrier
$calendar[7] = stripslashes("#3300CC"); // Couleurs de la police des chiffres
$calendar[8] = stripslashes("#330099"); // Couleurs de la police des jours de la semaine
$calendar[9] = stripslashes("1px"); // Taille des bordures du calendrier
$calendar[10] = stripslashes("#97B7BF"); // Couleur évènement
$calendar[11] = stripslashes("#A9C5EB"); // Couleur de fond du calendrier

$citation[0] = stripslashes("Arial, Helvetica, sans-serif"); // Police des citations
$citation[1] = stripslashes("12px"); // Taille de la police des citations
$citation[2] = stripslashes("#CCFFFF"); // Couleur de la police des citations

$presform[0] = stripslashes("#000099"); // Couleur des textes dans les boites de choix et boutons de commande
$presform[1] = stripslashes("#CFE5F9"); // Couleur des boites de choix
$presform[2] = stripslashes("#CFE5F9"); // Couleur des boutons de commande
$presform[3] = stripslashes("#CFE5F9"); // Couleur des zone de texte
$presform[4] = stripslashes("Trebuchet MS, Helvetica, sans-serif"); // Police dans la présentation des formulaires
$presform[5] = stripslashes("11px"); // Taille de la police dans la présentation des formulaires
$presform[6] = stripslashes("#CFE5F9"); // Couleur de fond des textarea
$presform[7] = stripslashes("1px"); // Taille de la bordure
$presform[8] = stripslashes("#AECBED"); // Couleur de la bordure

?>