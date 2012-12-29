<?php
/*
     MinieditorTextarea réalisé par Djchouix - Licence CeCILL
     Web site = http://lebrikabrak.free.fr/
     e-mail   = lebrikabrak@free.fr
	 version 1.6.3 (24 février 2007) compatibilité avec guppy v4.5.x
*/
if (stristr($_SERVER["SCRIPT_NAME"], "fr_minieditortextarea.inc")) {
  header("location:../index.php");
  die();
}

$version_minieditor = "Version 1.6.3";
$lang_minieditor[0] = 'Ok';
$lang_minieditor[1] = 'Fermer';
$lang_minieditor[2] = 'Nouveau';
$lang_minieditor[3] = 'Police';
$lang_minieditor[4] = 'Taille';
$lang_minieditor[5] = 'Couleur des Caractères';
$lang_minieditor[6] = 'Couleur du Fond';
$lang_minieditor[7] = 'Aligné à Gauche';
$lang_minieditor[8] = 'Centré';
$lang_minieditor[9] = 'Aligné à Droite';
$lang_minieditor[10] = 'Justifié';
$lang_minieditor[11] = 'Gras';
$lang_minieditor[12] = 'Italique';
$lang_minieditor[13] = 'Souligné';
$lang_minieditor[14] = 'Barré';
$lang_minieditor[15] = 'Indice';
$lang_minieditor[16] = 'Exposant';
$lang_minieditor[17] = 'Insérer une Image';
$lang_minieditor[18] = 'Insérer un Lien';
$lang_minieditor[19] = 'Prévisualiser';
$lang_minieditor[20] = 'Editeur Wysiwyg';
$lang_minieditor[21] = 'Balise HTML';
$lang_minieditor[22] = 'Class CSS';
$lang_minieditor[23] = 'Chemin';
$lang_minieditor[24] = 'relatif';
$lang_minieditor[25] = 'absolu';
$lang_minieditor[26] = 'URL';
$lang_minieditor[27] = 'Parcourir le serveur';
$lang_minieditor[28] = 'Target';
$lang_minieditor[29] = 'Alt';
$lang_minieditor[30] = 'Largeur (px)';
$lang_minieditor[31] = 'Hauteur (px)';
$lang_minieditor[32] = 'Bordure (px)';
$lang_minieditor[33] = 'Espacement Horiz. (px)';
$lang_minieditor[34] = 'Espacement Vert. (px)';
$lang_minieditor[35] = 'Alignement';
$lang_minieditor[36] = 'Sélectionner une Couleur';
$lang_minieditor[37] = 'Couleur';
$lang_minieditor[38] = "Coller le texte ici";
$lang_minieditor[39] = 'Veuillez indiquer l\'URL du document.';
$lang_minieditor[40] = 'Le code couleur n\'est pas correctement écrit.\nIl doit être de la forme #XXXXXX où X = 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E ou F.\nVeuillez corriger.';
$lang_minieditor[41] = "Une erreur est survenue. Veuillez recommencer ou contacter l'auteur du plugin.";
$lang_minieditor[42] = 'Title';
$lang_minieditor[43] = 'Insérer un saut de ligne';
$lang_minieditor[44] = 'Aucun';
$lang_minieditor[45] = 'Insérer votre balise favorite';
$lang_minieditor[46] = 'Annuler';
$lang_minieditor[47] = 'Refaire';
$lang_minieditor[48] = 'Insérer une Animation Flash';
$lang_minieditor[49] = 'Id';
$lang_minieditor[50] = 'Qualité';
$lang_minieditor[51] = 'Par défaut';
$lang_minieditor[52] = 'Haute';
$lang_minieditor[53] = 'Basse auto';
$lang_minieditor[54] = 'Basse';
$lang_minieditor[55] = 'Boucle';
$lang_minieditor[56] = 'Lecture auto';
$lang_minieditor[57] = 'Menu';
$lang_minieditor[58] = 'Echelle';
$lang_minieditor[59] = 'Aucune bordure';
$lang_minieditor[60] = 'Taille exacte';
$lang_minieditor[61] = "<br /><br />Erreur car le nom d'un répertoire dans la variable <strong>\$nameRepPath</strong> situé dans le fichier <strong>minieditortextarea_config.inc</strong> contient des caractères non valides.<br /><span style='font-weight:bold;text-decoration:underline;'>RAPPEL:</span><br />Pour le choix du nom d'un répertoire, vous devez utiliser uniquement des <strong>lettres</strong> et/ou des <strong>chiffres</strong> et/ou les caractères <strong>tiret ( - )</strong> et <strong>souligné ( _ )</strong>.<br />Tous les autres caractères ainsi que les espaces blancs sont interdits.<br />Veuillez corriger et recommencer.";
$lang_minieditor[62] = '<a href="http://www.macromedia.com/go/getflashplayer" target="_blank"><img src="flash\/document_Flash.gif" alt="Get FlashPlayer" title="Get FlashPlayer" width="114" height="21" border="0" /><\/a>';
$lang_minieditor[63] = 'La largeur n\'est pas écrite correctement.\nVous devez mettre un nombre.\nVeuillez corriger.';
$lang_minieditor[64] = 'La hauteur n\'est pas écrite correctement.\nVous devez mettre un nombre.\nVeuillez corriger.';
$lang_minieditor[65] = 'L\'espacement horizontal n\'est pas écrit pas correctement.\nVous devez mettre un nombre.\nVeuillez corriger.';
$lang_minieditor[66] = 'L\'espacement vertical n\'est pas écrit correctement.\nVous devez mettre un nombre.\nVeuillez corriger.';
$lang_minieditor[67] = 'L\'épaisseur de la bordure n\'est pas écrite correctement.\nVous devez mettre un nombre.\nVeuillez corriger.';
$lang_minieditor[68] = 'A propos';
$lang_minieditor[69] = 'Insérer un Smiley';
$lang_minieditor[70] = 'Fermer';
$lang_minieditor[71] = 'Insérer un caractère spécial';
?>