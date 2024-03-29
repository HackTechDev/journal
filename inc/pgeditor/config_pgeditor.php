<?php
/*
     Plugin PostGuestEditor
	 Version  : 2.5.0 (2007/01/23)
	 Compatibility : Guppy v4.5.x
	 Licence  : GNU Lesser General Public License
	 Author   : j�r�me CROUX (Djchouix)
     Web site : http://lebrikabrak.info/
     E-mail   : jchouix@wanadoo.fr
*/

if (stristr($_SERVER['SCRIPT_NAME'], 'config_pgeditor.php')) {
  header('location:../index.php');
  die();
}

/**
*   Configuration de PostGuest Editor
**/
define('LANG_PGEDITOR', $lng); 					    // Langue de l'�diteur
define('PATH_CSS_PGEDITOR', 'inc/pgeditor/style/'); // Chemin relatif du fichier CSS
define('PATH_GUPPYSMILEY', 'inc/img/smileys/'); 	// Chemin relatif des smileys de guppy (toolbar)
define('PATH_SMILEY', 'img/smileys/');          	// Chemin relatif des smileys (popup)
define('ALLOWED_EXTIMG', 'gif|png|jpg|jpeg');   	// Extension autoris�e pour les images (smileys popup)
define('ALLOWED_INSERT_IMG', false); 				// Autorisation pour ins�rer des images externes
define('ALLOWED_MAX_WIDTH_IMG', 400); 				// Largeur maximale Autoris�e pour les images
define('TOOLBAR_MENU', 'color|bgcolor|bold|italic|underline|cite|code|left|center|right|image|link|unlink|ordlist|bullist|undo|redo|smiley|preview|help');  //Barre Outils du menu
?>