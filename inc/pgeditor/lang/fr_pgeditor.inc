<?php
/*
     Plugin PostGuestEditor
	 Version  : 2.5.1 (2010/11/05)
	 Compatibility : Guppy v4.5.x et Guppy v4.6.x
	 Licence  : GNU Lesser General Public License
	 Author   : Jérôme CROUX (jchouix)
     Web site : http://lebrikabrak.info/
     E-mail   : jchouix@wanadoo.fr
*/

if (stristr($_SERVER['SCRIPT_NAME'], 'fr_pgeditor.inc')) {
  header('location:../index.php');
  die();
}

$version_pgeditor = "Version 2.5.1";
$charset = 'iso-8859-1';

$lang_pgeditor[0]  = 'fr';
$lang_pgeditor[1]  = 'Fermer';
$lang_pgeditor[2]  = 'Couleur du Texte';
$lang_pgeditor[3]  = 'Couleur de Fond';
$lang_pgeditor[4]  = 'Gras';
$lang_pgeditor[5]  = 'Italique';
$lang_pgeditor[6]  = 'Souligné';
$lang_pgeditor[7]  = 'Insérer une Citation';
$lang_pgeditor[8]  = 'Insérer du Code';
$lang_pgeditor[9]  = 'Aligner à Gauche';
$lang_pgeditor[10] = 'Centrer';
$lang_pgeditor[11] = 'Aligner à Droite';
$lang_pgeditor[12] = 'Insérer un Lien';
$lang_pgeditor[13] = 'Supprimer un Lien';
$lang_pgeditor[14] = 'Liste numérotée';
$lang_pgeditor[15] = 'Liste à puce';
$lang_pgeditor[16] = 'Annuler';
$lang_pgeditor[17] = 'Répeter';
$lang_pgeditor[18] = 'Insérer un Smiley (popup)';
$lang_pgeditor[19] = 'Prévisualiser (popup)';
$lang_pgeditor[20] = 'Affichage HTML';
$lang_pgeditor[21] = 'URL :';
$lang_pgeditor[22] = 'Auteur :';
$lang_pgeditor[23] = 'Citation :'; //attention à ne pas introduire de caractères spéciaux
$lang_pgeditor[24] = 'Langage du code :';
$lang_pgeditor[25] = 'Code :'; //attention à ne pas introduire de caractères spéciaux
$lang_pgeditor[26] = 'Veuillez cliquer pour résoudre un bug avec le navigateur Opera 9';
$lang_pgeditor[27] = 'Afficher l\'aide';
$lang_pgeditor[28] = 'Masquer l\'aide';
$lang_pgeditor[29] = 'Aucune';
$lang_pgeditor[30] = 'Zone d\'édition';
$lang_pgeditor[31] = 'Ok';
$lang_pgeditor[32] = 'Annuler';
$lang_pgeditor[33] = 'autre...';
$lang_pgeditor[34] = 'Aucun';
$lang_pgeditor[35]  = 'Insérer une image';

//Aide
$lang_help_pgeditor[0] = 'Aide :';
$lang_help_pgeditor[1] = 'Pour plus de détails...';
//Syntaxe
$lang_help_pgeditor[2] = 'Syntaxe du code :';
$lang_help_pgeditor[3] = '<strong>&lt;color=<span class="tag_value">CodeHexadécimale</span>&gt;&lt;/color&gt;</strong> permet de colorer un texte.<br /><em>Remarque :</em> Vous pouvez préciser à la place du code hexadécimal (<span class="tag_value">#??????</span>), le nom de la couleur (<span class="tag_value">red, yellow, orange, green, blue,</span> etc...).'.$lang_help_pgeditor[1];
$lang_help_pgeditor[4] = '<strong>&lt;bgcolor=<span class="tag_value">CodeHexadécimale</span>&gt;&lt;/bgcolor&gt;</strong> permet de surligner en couleur un texte.<br /><em>Remarque :</em> Vous pouvez préciser à la place du code hexadécimal (<span class="tag_value">#??????</span>), le nom de la couleur (<span class="tag_value">red, yellow, orange, green, blue,</span> etc...).'.$lang_help_pgeditor[1];
$lang_help_pgeditor[5] = '<strong>&lt;b&gt;&lt;/b&gt;</strong> permet de mettre en gras un texte.';
$lang_help_pgeditor[6] = '<strong>&lt;i&gt;&lt;/i&gt;</strong> permet de mettre en italique un texte.';
$lang_help_pgeditor[7] = '<strong>&lt;u&gt;&lt;/u&gt;</strong> permet de souligner un texte.';
$lang_help_pgeditor[8] = '<strong>&lt;cite&gt;&lt;/cite&gt;</strong> permet d\'insérer une citation.<br /><em>Remarque :</em> Vous pouvez préciser le nom de l\'auteur de la citation en écrivant <strong>&lt;cite<span class="tag_value">=Auteur</span>&gt;</strong>';
$lang_help_pgeditor[9] = '<strong>&lt;code&gt;&lt;/code&gt;</strong> permet d\'insérer du code.<br /><em>Remarque :</em> Vous pouvez préciser le langage en écrivant <strong>&lt;code<span class="tag_value">=NomduLangage</span>&gt;</strong>';
$lang_help_pgeditor[10] = '<strong>&lt;left&gt;&lt;/left&gt;</strong> permet d\'aligner à gauche.';
$lang_help_pgeditor[11] = '<strong>&lt;center&gt;&lt;/center&gt;</strong> permet d\'aligner au centre.';
$lang_help_pgeditor[12] = '<strong>&lt;right&gt;&lt;/right&gt;</strong> permet d\'aligner à droite.';
$lang_help_pgeditor[13] = '<strong>&lt;link&gt;&lt;/link&gt;</strong> permet d\'insérer un lien.<br /><em>Remarque :</em> Vous pouvez préciser l\'url du lien en écrivant <strong>&lt;link<span class="tag_value">=URL</span>&gt;texte&lt;/link&gt;</strong>. Si vous ne précisez pas l\'url du lien, l\'url sera ce qui se trouve entre les deux balises.<strong>&lt;link&gt;<span class="tag_value">URL</span>&lt;/link&gt;</strong>';
$lang_help_pgeditor[14] = '<strong>&lt;img=<span class="tag_value">NomduSmiley</span>&gt;</strong> permet d\'insérer un smiley.<br /><em>Remarque :</em> Les noms des smileys de base disponibles sont : <span class="tag_value">cool, wink, biggrin, smile, frown, eek, mad, confused, rolleyes, tongue, cry</span>.'.$lang_help_pgeditor[1];
//Raccourcis clavier
$lang_help_pgeditor[15] = 'Raccourcis clavier (sous Windows) :';
$lang_help_pgeditor[16] = 'Touche <strong>SHIFT + flèche (droite ou gauche)</strong> permet de sélectionner du texte';
$lang_help_pgeditor[17] = 'Touche <strong>ALT + 2</strong> permet de sélectionner la barre d\'outils';
$lang_help_pgeditor[18] = 'Touche <strong>ALT + 3</strong> permet de sélectionner la zône d\'édition';
$lang_help_pgeditor[19] = 'Touche <strong>ALT + 4</strong> permet d\'afficher l\'aide';
$lang_help_pgeditor[20] = 'Touche <strong>ALT + 5</strong> permet de masquer l\'aide';
$lang_help_pgeditor[21] = 'Touche <strong>TAB</strong> permet de passer d\'une sélection à la suivante';
$lang_help_pgeditor[22] = 'Touche <strong>SHIFT + TAB</strong> permet de passer d\'une sélection à la précédente';
$lang_help_pgeditor[23] = 'Touche <strong>ALT + flèche (vers le bas ou vers le haut)</strong> permet de déplier le menu sélectionné';
$lang_help_pgeditor[24] = 'Touche <strong>ALT + flèche (vers le bas ou vers le haut)</strong> permet de replier un menu déplié';
$lang_help_pgeditor[25] = 'Touche <strong>flèche (vers le bas ou vers le haut)</strong> permet de naviguer dans un menu déplié';
$lang_help_pgeditor[26] = 'Touche <strong>ALT + s</strong> permet d\'envoyer le formulaire';
//
$lang_help_pgeditor[27] = 'Informations à propos du code des couleurs du Web';
$lang_help_pgeditor[28] = 'Informations à propos du code pour insérer les smileys';
$lang_help_pgeditor[29] = ' (ouverture dans une nouvelle fenêtre)';

//Popup Aide Insertion Couleur
$lang_color_pgeditor[0] = 'Les noms des (16 + 1) couleurs de base du HTML et du CSS 2.1 spécifiées par le W3C';
$lang_color_pgeditor[1] = 'noir';
$lang_color_pgeditor[2] = 'gris';
$lang_color_pgeditor[3] = 'argent';
$lang_color_pgeditor[4] = 'blanc';
$lang_color_pgeditor[5] = 'marron';
$lang_color_pgeditor[6] = 'rouge';
$lang_color_pgeditor[7] = 'orange';
$lang_color_pgeditor[8] = 'jaune';
$lang_color_pgeditor[9] = 'citron vert';
$lang_color_pgeditor[10] = 'vert';
$lang_color_pgeditor[11] = 'olive';
$lang_color_pgeditor[12] = 'cyan';
$lang_color_pgeditor[13] = 'bleu';
$lang_color_pgeditor[14] = 'bleu gris';
$lang_color_pgeditor[15] = 'bleu marine';
$lang_color_pgeditor[16] = 'magenta';
$lang_color_pgeditor[17] = 'pourpre';
$lang_color_pgeditor[18] = 'Nom des couleurs web';
$lang_color_pgeditor[19] = 'Nom HTML de la couleur';
$lang_color_pgeditor[20] = 'Code hexadécimal';
$lang_color_pgeditor[21] = 'Visualisation';
$lang_color_pgeditor[22] = 'traduction';
$lang_color_pgeditor[23] = 'Les noms des 140 couleurs "non officielles" du web';
$lang_color_pgeditor[24] = '<span class="warning">Attention :</span> ces noms de couleurs sont supportées par les navigateurs Netscape 2.0+, Internet Explorer 3.0+ ainsi que la plupart des navigateurs modernes (Firefox, Safari, etc...) mais leur support par tous les navigateurs respectueux des standarts n\'est pas garanti car ces noms de couleurs ne font pas partie des recommandations officielles du W3C.';

//Popup Aide Insertion Smiley
$lang_smiley_pgeditor[0] = 'Nom des smileys';
$lang_smiley_pgeditor[1] = 'smiley tranquille';
$lang_smiley_pgeditor[2] = 'smiley complice';
$lang_smiley_pgeditor[3] = 'smiley content';
$lang_smiley_pgeditor[4] = 'smiley souriant';
$lang_smiley_pgeditor[5] = 'smiley sidéré';
$lang_smiley_pgeditor[6] = 'smiley perturbé';
$lang_smiley_pgeditor[7] = 'smiley en colère';
$lang_smiley_pgeditor[8] = 'smiley mécontent';
$lang_smiley_pgeditor[9] = 'smiley étonné';
$lang_smiley_pgeditor[10] = 'smiley moqueur';
$lang_smiley_pgeditor[11] = 'smiley malheureux';
$lang_smiley_pgeditor[12] = 'Les smileys de base de Guppy';
$lang_smiley_pgeditor[13] = 'Nom du smiley';
$lang_smiley_pgeditor[14] = 'Code pour insérer le smiley';
$lang_smiley_pgeditor[15] = 'Visualisation';
$lang_smiley_pgeditor[16] = 'Les autres smileys disponibles';
?>