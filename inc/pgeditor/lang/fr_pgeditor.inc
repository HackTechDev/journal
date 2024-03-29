<?php
/*
     Plugin PostGuestEditor
	 Version  : 2.5.1 (2010/11/05)
	 Compatibility : Guppy v4.5.x et Guppy v4.6.x
	 Licence  : GNU Lesser General Public License
	 Author   : J�r�me CROUX (jchouix)
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
$lang_pgeditor[6]  = 'Soulign�';
$lang_pgeditor[7]  = 'Ins�rer une Citation';
$lang_pgeditor[8]  = 'Ins�rer du Code';
$lang_pgeditor[9]  = 'Aligner � Gauche';
$lang_pgeditor[10] = 'Centrer';
$lang_pgeditor[11] = 'Aligner � Droite';
$lang_pgeditor[12] = 'Ins�rer un Lien';
$lang_pgeditor[13] = 'Supprimer un Lien';
$lang_pgeditor[14] = 'Liste num�rot�e';
$lang_pgeditor[15] = 'Liste � puce';
$lang_pgeditor[16] = 'Annuler';
$lang_pgeditor[17] = 'R�peter';
$lang_pgeditor[18] = 'Ins�rer un Smiley (popup)';
$lang_pgeditor[19] = 'Pr�visualiser (popup)';
$lang_pgeditor[20] = 'Affichage HTML';
$lang_pgeditor[21] = 'URL :';
$lang_pgeditor[22] = 'Auteur :';
$lang_pgeditor[23] = 'Citation :'; //attention � ne pas introduire de caract�res sp�ciaux
$lang_pgeditor[24] = 'Langage du code :';
$lang_pgeditor[25] = 'Code :'; //attention � ne pas introduire de caract�res sp�ciaux
$lang_pgeditor[26] = 'Veuillez cliquer pour r�soudre un bug avec le navigateur Opera 9';
$lang_pgeditor[27] = 'Afficher l\'aide';
$lang_pgeditor[28] = 'Masquer l\'aide';
$lang_pgeditor[29] = 'Aucune';
$lang_pgeditor[30] = 'Zone d\'�dition';
$lang_pgeditor[31] = 'Ok';
$lang_pgeditor[32] = 'Annuler';
$lang_pgeditor[33] = 'autre...';
$lang_pgeditor[34] = 'Aucun';
$lang_pgeditor[35]  = 'Ins�rer une image';

//Aide
$lang_help_pgeditor[0] = 'Aide :';
$lang_help_pgeditor[1] = 'Pour plus de d�tails...';
//Syntaxe
$lang_help_pgeditor[2] = 'Syntaxe du code :';
$lang_help_pgeditor[3] = '<strong>&lt;color=<span class="tag_value">CodeHexad�cimale</span>&gt;&lt;/color&gt;</strong> permet de colorer un texte.<br /><em>Remarque :</em> Vous pouvez pr�ciser � la place du code hexad�cimal (<span class="tag_value">#??????</span>), le nom de la couleur (<span class="tag_value">red, yellow, orange, green, blue,</span> etc...).'.$lang_help_pgeditor[1];
$lang_help_pgeditor[4] = '<strong>&lt;bgcolor=<span class="tag_value">CodeHexad�cimale</span>&gt;&lt;/bgcolor&gt;</strong> permet de surligner en couleur un texte.<br /><em>Remarque :</em> Vous pouvez pr�ciser � la place du code hexad�cimal (<span class="tag_value">#??????</span>), le nom de la couleur (<span class="tag_value">red, yellow, orange, green, blue,</span> etc...).'.$lang_help_pgeditor[1];
$lang_help_pgeditor[5] = '<strong>&lt;b&gt;&lt;/b&gt;</strong> permet de mettre en gras un texte.';
$lang_help_pgeditor[6] = '<strong>&lt;i&gt;&lt;/i&gt;</strong> permet de mettre en italique un texte.';
$lang_help_pgeditor[7] = '<strong>&lt;u&gt;&lt;/u&gt;</strong> permet de souligner un texte.';
$lang_help_pgeditor[8] = '<strong>&lt;cite&gt;&lt;/cite&gt;</strong> permet d\'ins�rer une citation.<br /><em>Remarque :</em> Vous pouvez pr�ciser le nom de l\'auteur de la citation en �crivant <strong>&lt;cite<span class="tag_value">=Auteur</span>&gt;</strong>';
$lang_help_pgeditor[9] = '<strong>&lt;code&gt;&lt;/code&gt;</strong> permet d\'ins�rer du code.<br /><em>Remarque :</em> Vous pouvez pr�ciser le langage en �crivant <strong>&lt;code<span class="tag_value">=NomduLangage</span>&gt;</strong>';
$lang_help_pgeditor[10] = '<strong>&lt;left&gt;&lt;/left&gt;</strong> permet d\'aligner � gauche.';
$lang_help_pgeditor[11] = '<strong>&lt;center&gt;&lt;/center&gt;</strong> permet d\'aligner au centre.';
$lang_help_pgeditor[12] = '<strong>&lt;right&gt;&lt;/right&gt;</strong> permet d\'aligner � droite.';
$lang_help_pgeditor[13] = '<strong>&lt;link&gt;&lt;/link&gt;</strong> permet d\'ins�rer un lien.<br /><em>Remarque :</em> Vous pouvez pr�ciser l\'url du lien en �crivant <strong>&lt;link<span class="tag_value">=URL</span>&gt;texte&lt;/link&gt;</strong>. Si vous ne pr�cisez pas l\'url du lien, l\'url sera ce qui se trouve entre les deux balises.<strong>&lt;link&gt;<span class="tag_value">URL</span>&lt;/link&gt;</strong>';
$lang_help_pgeditor[14] = '<strong>&lt;img=<span class="tag_value">NomduSmiley</span>&gt;</strong> permet d\'ins�rer un smiley.<br /><em>Remarque :</em> Les noms des smileys de base disponibles sont : <span class="tag_value">cool, wink, biggrin, smile, frown, eek, mad, confused, rolleyes, tongue, cry</span>.'.$lang_help_pgeditor[1];
//Raccourcis clavier
$lang_help_pgeditor[15] = 'Raccourcis clavier (sous Windows) :';
$lang_help_pgeditor[16] = 'Touche <strong>SHIFT + fl�che (droite ou gauche)</strong> permet de s�lectionner du texte';
$lang_help_pgeditor[17] = 'Touche <strong>ALT + 2</strong> permet de s�lectionner la barre d\'outils';
$lang_help_pgeditor[18] = 'Touche <strong>ALT + 3</strong> permet de s�lectionner la z�ne d\'�dition';
$lang_help_pgeditor[19] = 'Touche <strong>ALT + 4</strong> permet d\'afficher l\'aide';
$lang_help_pgeditor[20] = 'Touche <strong>ALT + 5</strong> permet de masquer l\'aide';
$lang_help_pgeditor[21] = 'Touche <strong>TAB</strong> permet de passer d\'une s�lection � la suivante';
$lang_help_pgeditor[22] = 'Touche <strong>SHIFT + TAB</strong> permet de passer d\'une s�lection � la pr�c�dente';
$lang_help_pgeditor[23] = 'Touche <strong>ALT + fl�che (vers le bas ou vers le haut)</strong> permet de d�plier le menu s�lectionn�';
$lang_help_pgeditor[24] = 'Touche <strong>ALT + fl�che (vers le bas ou vers le haut)</strong> permet de replier un menu d�pli�';
$lang_help_pgeditor[25] = 'Touche <strong>fl�che (vers le bas ou vers le haut)</strong> permet de naviguer dans un menu d�pli�';
$lang_help_pgeditor[26] = 'Touche <strong>ALT + s</strong> permet d\'envoyer le formulaire';
//
$lang_help_pgeditor[27] = 'Informations � propos du code des couleurs du Web';
$lang_help_pgeditor[28] = 'Informations � propos du code pour ins�rer les smileys';
$lang_help_pgeditor[29] = ' (ouverture dans une nouvelle fen�tre)';

//Popup Aide Insertion Couleur
$lang_color_pgeditor[0] = 'Les noms des (16 + 1) couleurs de base du HTML et du CSS 2.1 sp�cifi�es par le W3C';
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
$lang_color_pgeditor[20] = 'Code hexad�cimal';
$lang_color_pgeditor[21] = 'Visualisation';
$lang_color_pgeditor[22] = 'traduction';
$lang_color_pgeditor[23] = 'Les noms des 140 couleurs "non officielles" du web';
$lang_color_pgeditor[24] = '<span class="warning">Attention :</span> ces noms de couleurs sont support�es par les navigateurs Netscape 2.0+, Internet Explorer 3.0+ ainsi que la plupart des navigateurs modernes (Firefox, Safari, etc...) mais leur support par tous les navigateurs respectueux des standarts n\'est pas garanti car ces noms de couleurs ne font pas partie des recommandations officielles du W3C.';

//Popup Aide Insertion Smiley
$lang_smiley_pgeditor[0] = 'Nom des smileys';
$lang_smiley_pgeditor[1] = 'smiley tranquille';
$lang_smiley_pgeditor[2] = 'smiley complice';
$lang_smiley_pgeditor[3] = 'smiley content';
$lang_smiley_pgeditor[4] = 'smiley souriant';
$lang_smiley_pgeditor[5] = 'smiley sid�r�';
$lang_smiley_pgeditor[6] = 'smiley perturb�';
$lang_smiley_pgeditor[7] = 'smiley en col�re';
$lang_smiley_pgeditor[8] = 'smiley m�content';
$lang_smiley_pgeditor[9] = 'smiley �tonn�';
$lang_smiley_pgeditor[10] = 'smiley moqueur';
$lang_smiley_pgeditor[11] = 'smiley malheureux';
$lang_smiley_pgeditor[12] = 'Les smileys de base de Guppy';
$lang_smiley_pgeditor[13] = 'Nom du smiley';
$lang_smiley_pgeditor[14] = 'Code pour ins�rer le smiley';
$lang_smiley_pgeditor[15] = 'Visualisation';
$lang_smiley_pgeditor[16] = 'Les autres smileys disponibles';
?>