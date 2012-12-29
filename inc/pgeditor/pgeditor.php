<?php
/*
     Plugin PostGuestEditor
	 Version  : 2.6 (2012/10/15)
	 Compatibility : Guppy v4.5.x et Guppy v4.6.x
	 Licence  : GNU Lesser General Public License
	 Author   : jérôme CROUX (jchouix)
     Web site : http://lebrikabrak.info/
     E-mail   : jchouix@wanadoo.fr
*/

if (stristr($_SERVER['SCRIPT_NAME'], 'pgeditor.php')) {
  header('location:../index.php');
  die();
}

/**************************************************************************************
*   INITIALISATION
***************************************************************************************/
/**
 *   detectBrowser
 *	Détection des navigateurs
 */
function detectBrowser()
{
	$userAgent = $_SERVER['HTTP_USER_AGENT'];
	if (strpos($userAgent, 'MSIE') !== false && strpos($userAgent, 'compatible') !== false && strpos($userAgent, 'Opera') === false && strpos($userAgent, 'mac') === false && strpos($userAgent, 'Gecko') === false && strpos($userAgent, 'Konqueror') === false && strpos($userAgent, 'Safari') === false) {		
		$version = (float)substr($userAgent, strpos($userAgent, 'MSIE') + 5, 3);
		return ($version < 9.0)? 'IE' : 'IE9';
	} elseif (strpos($userAgent, 'Gecko') !== false && strpos($userAgent, 'Opera') === false && strpos($userAgent, 'Konqueror') === false && strpos($userAgent, 'Safari') === false) {
		return 'Gecko';
	} elseif (strpos($userAgent, 'Opera') !== false) {
		return 'Opera';
	} elseif (strpos($userAgent, 'Konqueror') !== false) {
  		return 'Konqueror';
	} elseif (strpos($userAgent, 'Safari') !== false) {
  		return 'Safari';
	} else {
  		return 'Other';
	}
}

/**
 *   detectBrowserWIW
 *	Détection des navigateurs compatibles avec l'éditeur wysiwyg
 */
function detectBrowserWIW()
{
	$userAgent = $_SERVER['HTTP_USER_AGENT'];
	switch (BROWSER) {
		case 'IE' :
        case 'IE9' :
			$version = (float)substr($userAgent, strpos($userAgent, 'MSIE') + 5, 3);
			return ($version >= 5.5)? true : false;
			break;

		case 'Gecko' :
			$version = (int)substr($userAgent, strpos($userAgent, 'Gecko/') + 6, 8);
            if (strlen($version)== 8) {
            return ((int)$version >= 20030210)? true : false;   
            } else {
            return ((int)$version >= 17)? true : false;   
            }
			break;

		case 'Opera' :
			$version = (float)substr($userAgent, strpos($userAgent, 'Opera/') + 6, 3);
			return ($version >= 9.0)? true : false;
			break;

		case 'Safari' :
			$version = (int)substr($userAgent, strpos($userAgent, 'WebKit/') + 7, 3);
			return ($version >= 522)? true : false;

		case 'Konqueror' :
			return false;
			
		default :
			return false;
	}
}

/**
 *   detectJS
 *	Détection du JavaScript activé ou non
 */
function detectJS()
{
	$js = isset($_POST['js']) ? $_POST['js'] : null;
	if ($js != 'ko') {
		return true;
	} else {
		return false;
	}
}

/**
 *   DEFINITION CONSTANTES DE CONFIGURATION
 */
define('BROWSER', detectBrowser());            						//Navigateur
define('JAVASCRIPT', detectJS());            						//JavaScript activé ou non
define('BASEPATH', $site[3]);                  						//URL du site
if (!defined('PATH_PGEDITOR')) 			define('PATH_PGEDITOR', 'inc/pgeditor/'); 		 	//Chemin relatif de l'éditeur
if (!defined('PATH_CONFIG_PGEDITOR')) 	define('PATH_CONFIG_PGEDITOR','inc/pgeditor/');		//Chemin relatif du fichier de configuration par défaut
if (file_exists(CHEMIN.PATH_CONFIG_PGEDITOR.'config_pgeditor.php')) {						//Fichier de configuration
	include CHEMIN.PATH_CONFIG_PGEDITOR.'config_pgeditor.php';
} else {
	die('ERREUR: Le fichier de configuration est absent ou n\'est pas à l\'adresse indiquée.');
}
if (!defined('WYSIWYG')) 				define('WYSIWYG', detectBrowserWIW());  				//Navigateur compatible wysiwyg
if (!defined('LANG_PGEDITOR')) 			define('LANG_PGEDITOR', 'en'); 					 		// Langue de l'éditeur
if (!defined('PATH_CSS_PGEDITOR')) 		define('PATH_CSS_PGEDITOR', 'inc/pgeditor/style/'); 	// Chemin relatif du fichier CSS
if (!defined('PATH_GUPPYSMILEY')) 		define('PATH_GUPPYSMILEY', 'inc/img/smileys/'); 		// Chemin relatif des smileys de guppy (toolbar)
if (!defined('PATH_SMILEY')) 			define('PATH_SMILEY', 'img/smileys/');          	 	// Chemin relatif des smileys (popup)
if (!defined('ALLOWED_EXTIMG')) 		define('ALLOWED_EXTIMG', 'gif|png|jpg|jpeg');   	 	// Extension autorisée pour les images (smileys popup)
if (!defined('ALLOWED_INSERT_IMG')) 	define('ALLOWED_INSERT_IMG', false); 					// Autorisation pour insérer des images externes
if (!defined('ALLOWED_MAX_WIDTH_IMG'))	define('ALLOWED_MAX_WIDTH_IMG', 400); 					// Largeur maximale Autorisée pour les images
if (!defined('TOOLBAR_MENU')) 			define('TOOLBAR_MENU', 'color|bgcolor|bold|italic|underline|cite|code|left|center|right|image|link|unlink|ordlist|bullist|undo|redo|smiley|preview|help');  //Barre Outils du menu
if (!defined('LANGUAGE_CODE')) 			define('LANGUAGE_CODE', 'xhtml|css|javascript|php');	// Language dans menu de la popup "Insertion de code"

/**
 *   INSERTION DES FICHIERS DE LANGUE
 */
if (file_exists(CHEMIN.PATH_PGEDITOR.'lang/'.LANG_PGEDITOR.'_pgeditor.inc')) {
	include CHEMIN.PATH_PGEDITOR.'lang/'.LANG_PGEDITOR.'_pgeditor.inc';
} else {
	include CHEMIN.PATH_PGEDITOR.'lang/en_pgeditor.inc';
}

/**
 *   headPGEditor
 *   Insère les fichiers CSS et JavaScript dans l'entête de Guppy
 */
function headPGEditor()
{
	//Patch correctif pour pallier la mauvaise interprétation de la propriété overflow sur le block <pre> lorsque width est en %
	$patchOverflowPreCSS = '<link rel="stylesheet" type="text/css" media="screen" href="'.CHEMIN.PATH_CSS_PGEDITOR.'pgeditor_patch_overflow.css" />';

	$jscriptPGEditor = (WYSIWYG)? 'wysiwyg_editor' : 'textarea_editor';

	$head = '
		<link rel="stylesheet" type="text/css" media="screen" href="'.CHEMIN.PATH_CSS_PGEDITOR.'pgeditor.css" />
        <!-- compliance patch for microsoft browsers -->
       	<!--[if lte IE 7]>
            <link rel="stylesheet" type="text/css" media="screen" href="'.CHEMIN.PATH_CSS_PGEDITOR.'pgeditor-ie.css" />
        <![endif]-->
		'.$patchOverflowPreCSS.'
		<link rel="stylesheet" type="text/css" media="screen" href="'.CHEMIN.PATH_CSS_PGEDITOR.'syntaxcolor.css" />
		<script type="text/javascript" src="'.CHEMIN.PATH_PGEDITOR.'jscript/'.$jscriptPGEditor.'.js"></script>
	';
	return $head;
}
$headinc .= headPGEditor(); //Insertion dans guppy

/**
 *   recupCodePGEditor
 *   Récupère le code envoyé par la méthode POST lors de la validation du formulaire
 *   @param $nameEditor string  le nom assigné à l'éditeur lors de sa création
 *	 Par exemple : le nom est 'ptxt' si vous avez écrit : displayPGEditor('send', 'ptxt', 515, 400);
 */
function recupCodePGEditor($nameEditor)
{
	$code = isset($_POST[$nameEditor]) ? $_POST[$nameEditor] : null;
	$code_content = isset($_POST[$nameEditor.'_content']) ? $_POST[$nameEditor.'_content'] : null;

	if ($code === null && $code_content !== null) {
		$in = array(
				"`^(&nbsp;|<p>(<br>|&nbsp;|\s)+</p>|<br/?>|\s)+`i",   //Suppression des espaces au début
				"`(&nbsp;|<p>(<br>|&nbsp;|\s)+</p>|<br/?>|\s)+$`i"    //Suppression des espaces à la fin
		);
		$out = array(
				'',
				''
		);
		$code = preg_replace($in, $out, $code_content);
	}

	if (get_magic_quotes_gpc()) $code = stripslashes($code);  //Magic_quotes = On
	return trim($code);
}

/**
 *   validJSCodePGEditor
 *   Vérifie si le code envoyé est valide (non vide) ou non avant la soumission du formulaire (fonction javascript)
 *   @param $nameForm  string   le nom assigné au formulaire (attribut name)
 *   @param $nameEditor string  le nom assigné à l'éditeur lors de sa création
 *   @param $nameFlag   string  le nom assigné à la variable javascript qui contiendra le résultat de la validation (true si valide ou false si non valide) .
 */
function validJSCodePGEditor($nameForm, $nameEditor, $nameFlag)
{
	if (WYSIWYG) {
		$js = 'var '.$nameFlag.' = '.$nameEditor.'.submitContent();';
	} else {
		$js = 'var '.$nameFlag.' = submitPGEditor("'.$nameForm.'", "'.$nameEditor.'")';
	}
	return $js;
}

/**************************************************************************************
*   POSTGUEST EDITOR
***************************************************************************************/
/**
 *   displayPGEditor
 *   Affiche l'éditeur wysiwyg ou non selon le navigateur détecté
 *   @param  $nameForm       string  le nom assigné au formulaire (attribut name)
 *   @param  $namePGEditor   string  le nom assigné à l'éditeur
 *   @param  $width          number  la largeur de l'éditeur (en pixels)
 *   @param  $height         number  la hauteur de l'éditeur (en pixels)
 *   @param  $content        string  la contenu de l'éditeur lors du chargement (vide par défaut)
 */
function displayPGEditor($nameForm, $namePGEditor, $width, $height, $content = '')
{
	$display = '
		<div id="pgeditorIE_'.$namePGEditor.'" class="pgeditorIE">
			<!--[  PostGuestEditor v2.5.1 GNU GPL Copyright (C) 2006-2010 by Jerome CROUX - http://lebrikabrak.info/  ]-->
			<div id="pgeditor_'.$namePGEditor.'" class="pgeditor">
	';

	if (WYSIWYG) {
 		$display .= displayPGEditorWIW($namePGEditor, $width, $height, $content);
		$display .= '
			<noscript class="pgeditor">
				<input id="js_'.$namePGEditor.'" name="js" type="hidden" value="ko" />
				'.displayPGEditorTA($nameForm, $namePGEditor, $width, $height, $content).'
			</noscript>
		';
   	} else {
		$display .= displayPGEditorTA($nameForm, $namePGEditor, $width, $height, $content);
		$display .= '
			<noscript class="pgeditor">
				<input id="js_'.$namePGEditor.'" name="js" type="hidden" value="ko" />
			</noscript>
		';
   	}
	$display .= smileyPGEditor($nameForm, $namePGEditor, $width);
	$display .= '
			</div>
		</div>
	';
	return $display;
}

/**
 *   displayPGEditorWIW (TTWEDITOR)
 *   Affiche l'éditeur wysiwyg
 *   @param  $namePGEditor   string  le nom assigné à l'éditeur
 *   @param  $width          number  la largeur de l'éditeur (en pixels)
 *   @param  $height         number  la hauteur de l'éditeur (en pixels)
 *   @param  $content        string  la contenu de l'éditeur lors du chargement (vide par défaut)
 */
function displayPGEditorWIW($namePGEditor, $width, $height, $content = '')
{
	global $lang_pgeditor;

	$content = str_replace(array("\n", "\r"), '', $content);	

    $display = '
		<script type="text/javascript">
		 '.$namePGEditor.' = new WYSIWYG_PGEditor(\''.$namePGEditor.'\', \''.$content.'\', \''.CHEMIN.PATH_PGEDITOR.'\', '.$width.', '.$height.', \''.CHEMIN.PATH_CSS_PGEDITOR.'pgeditor\', \''.PATH_CONFIG_PGEDITOR.'\');
		 '.$namePGEditor.'.allow_mode_toggle = true;	//Affichage (true) ou non (false) du code source
		 '.$namePGEditor.'.isSupported = true;  //Wysiwyg supporté par le navigateur
		 '.$namePGEditor.'.lang = ["'.implode('","', $lang_pgeditor).'"];
		 '.$namePGEditor.'.menu = ["'.str_replace('|', '","', TOOLBAR_MENU).'"];
		 '.$namePGEditor.'.language_code = ["'.str_replace('|', '","', LANGUAGE_CODE).'"];
		 '.$namePGEditor.'.base_path = "'.BASEPATH.'";
		 '.$namePGEditor.'.allow_insert_img = "'.ALLOWED_INSERT_IMG.'";
		 '.$namePGEditor.'.display();
    	</script>
	';
	return $display;
}

/**
 *   displayPGEditorTA
 *   Affiche l'éditeur NON wysiwyg (textarea)
 *   @param  $nameForm       string  le nom assigné au formulaire (attribut name)
 *   @param  $namePGEditor   string  le nom assigné à l'éditeur (attribut name du textarea)
 *   @param  $width          number  la largeur de l'éditeur (en pixels)
 *   @param  $height         number  la hauteur de l'éditeur (en pixels)
 *   @param  $content        string  la contenu de l'éditeur lors du chargement (vide par défaut)
 */
function displayPGEditorTA($nameForm, $namePGEditor, $width, $height, $content = '')
{
	global $lang_pgeditor;

	//Aide
	$display = '
		<hr style="display:none;" />
		<div id="helpTA_'.$namePGEditor.'" class="helpTA"  style="width:'.$width.'px;">
		'.displayHelpPGEditorTA().'
		</div>
		<hr style="display:none;" />
	';

	//Toobars
	$toolbar = '';
	$menu = explode('|', TOOLBAR_MENU);
	for ($i = 0; $i < count($menu); $i++) {
		switch ($menu[$i]) {
			case 'color' :
				$toolbar .= selectColorPGEditorTA($nameForm, $namePGEditor, 'color', 'color').'&nbsp;|&nbsp;'."\n";
				break;
			case 'bgcolor' :
				$toolbar .= selectColorPGEditorTA($nameForm, $namePGEditor, 'bgcolor', 'background-color').'&nbsp;|&nbsp;'."\n";
				break;
			case 'bold' :
				$toolbar .= '<a href="javascript:AddTagFormat(\'b\',\''.$nameForm.'\',\''.$namePGEditor.'\');"  title="'.$lang_pgeditor[4].'"><img alt="'.$lang_pgeditor[4].'" title="'.$lang_pgeditor[4].'" class="icon" border="0" width="23" height="23" src="'.CHEMIN.PATH_PGEDITOR.'images/bold.gif" onclick="AddTagFormat(\'b\', \''.$nameForm.'\', \''.$namePGEditor.'\'); return false;" /></a>&nbsp;'."\n";
				break;
			case 'italic' :
				$toolbar .= '<a href="javascript:AddTagFormat(\'i\',\''.$nameForm.'\',\''.$namePGEditor.'\');"  title="'.$lang_pgeditor[5].'"><img alt="'.$lang_pgeditor[5].'" title="'.$lang_pgeditor[5].'" class="icon" border="0" width="23" height="23" src="'.CHEMIN.PATH_PGEDITOR.'images/italic.gif" onclick="AddTagFormat(\'i\', \''.$nameForm.'\', \''.$namePGEditor.'\'); return false;" /></a>&nbsp;'."\n";
				break;
			case 'underline' :
				$toolbar .= '<a href="javascript:AddTagFormat(\'u\',\''.$nameForm.'\',\''.$namePGEditor.'\');"  title="'.$lang_pgeditor[6].'"><img alt="'.$lang_pgeditor[6].'" title="'.$lang_pgeditor[6].'" class="icon" border="0" width="23" height="23" src="'.CHEMIN.PATH_PGEDITOR.'images/underline.gif" onclick="AddTagFormat(\'u\', \''.$nameForm.'\', \''.$namePGEditor.'\'); return false;" /></a>&nbsp;'."\n";
				break;
			case 'cite' :
				$toolbar .= '<a href="javascript:AddTagFormatPrompt(\'cite\',\''.rawurlencode($lang_pgeditor[22]).'\',\''.$nameForm.'\',\''.$namePGEditor.'\');"  title="'.$lang_pgeditor[7].'"><img alt="'.$lang_pgeditor[7].'" title="'.$lang_pgeditor[7].'" class="icon" border="0" width="23" height="23" src="'.CHEMIN.PATH_PGEDITOR.'images/cite.gif" onclick="AddTagFormatPrompt(\'cite\', \''.$lang_pgeditor[22].'\', \''.$nameForm.'\', \''.$namePGEditor.'\'); return false;" /></a>&nbsp;'."\n";
				break;
			case 'code' :
				$toolbar .= selectLanguageCodePGEditorTA($nameForm, $namePGEditor);
				break;
			case 'left' :
				$toolbar .= '<a href="javascript:AddTagFormat(\'left\',\''.$nameForm.'\',\''.$namePGEditor.'\');"  title="'.$lang_pgeditor[9].'"><img alt="'.$lang_pgeditor[9].'" title="'.$lang_pgeditor[9].'" class="icon" border="0" width="23" height="23" src="'.CHEMIN.PATH_PGEDITOR.'images/left.gif" onclick="AddTagFormat(\'left\', \''.$nameForm.'\', \''.$namePGEditor.'\'); return false;" /></a>&nbsp;'."\n";
				break;
			case 'center' :
				$toolbar .= '<a href="javascript:AddTagFormat(\'center\',\''.$nameForm.'\',\''.$namePGEditor.'\');"  title="'.$lang_pgeditor[10].'"><img alt="'.$lang_pgeditor[10].'" title="'.$lang_pgeditor[10].'" class="icon" border="0" width="23" height="23" src="'.CHEMIN.PATH_PGEDITOR.'images/center.gif" onclick="AddTagFormat(\'center\', \''.$nameForm.'\', \''.$namePGEditor.'\'); return false;" /></a>&nbsp;'."\n";
				break;
			case 'right' :
				$toolbar .= '<a href="javascript:AddTagFormat(\'right\',\''.$nameForm.'\',\''.$namePGEditor.'\');"  title="'.$lang_pgeditor[11].'"><img alt="'.$lang_pgeditor[11].'" title="'.$lang_pgeditor[11].'" class="icon" border="0" width="23" height="23" src="'.CHEMIN.PATH_PGEDITOR.'images/right.gif" onclick="AddTagFormat(\'right\', \''.$nameForm.'\', \''.$namePGEditor.'\'); return false;" /></a>&nbsp;'."\n";
				break;
			case 'link' :
				$toolbar .= '<a href="javascript:AddTagFormatPrompt(\'link\',\''.rawurlencode($lang_pgeditor[21]).'\',\''.$nameForm.'\',\''.$namePGEditor.'\');"  title="'.$lang_pgeditor[12].'"><img alt="'.$lang_pgeditor[12].'" title="'.$lang_pgeditor[12].'" class="icon" border="0" width="23" height="23" src="'.CHEMIN.PATH_PGEDITOR.'images/link.gif" onclick="AddTagFormatPrompt(\'link\', \''.$lang_pgeditor[21].'\', \''.$nameForm.'\', \''.$namePGEditor.'\'); return false;" /></a>&nbsp;'."\n";
				break;
			case 'image' :
				if (ALLOWED_INSERT_IMG) {	// Autorisation (voir config)
					$toolbar .= '<a href="javascript:AddTagExternalImg(\'img\',\''.rawurlencode($lang_pgeditor[21]).'\',\''.$nameForm.'\',\''.$namePGEditor.'\');"  title="'.$lang_pgeditor[35].'"><img alt="'.$lang_pgeditor[35].'" title="'.$lang_pgeditor[35].'" class="icon" border="0" width="23" height="23" src="'.CHEMIN.PATH_PGEDITOR.'images/image.gif" onclick="AddTagExternalImg(\'img\', \''.$lang_pgeditor[21].'\', \''.$nameForm.'\', \''.$namePGEditor.'\'); return false;" /></a>&nbsp;'."\n";
				}
				break;
			case 'smiley' :
				$toolbar .= '<a href="javascript:popupPGEditor(\''.CHEMIN.PATH_PGEDITOR.'popups/smileys.php?lng='.$lang_pgeditor[0].'&amp;wysiwyg=0&amp;configpath='.PATH_CONFIG_PGEDITOR.'&amp;nameform='.$nameForm.'&amp;nametextarea='.$namePGEditor.'\',\'Smileys\',\'200\',\'200\',\'no\',\'no\',\''.$nameForm.'\',\''.$namePGEditor.'\');"  title="'.$lang_pgeditor[18].'"><img alt="'.$lang_pgeditor[18].'" title="'.$lang_pgeditor[18].'" class="icon" border="0" width="23" height="23" src="'.CHEMIN.PATH_PGEDITOR.'images/smiley.gif" onclick="popupPGEditor(\''.CHEMIN.PATH_PGEDITOR.'popups/smileys.php?lng='.$lang_pgeditor[0].'&amp;wysiwyg=0&amp;configpath='.PATH_CONFIG_PGEDITOR.'&amp;nameform='.$nameForm.'&amp;nametextarea='.$namePGEditor.'\', \'Smileys\', \'200\', \'200\', \'no\', \'no\', \''.$nameForm.'\', \''.$namePGEditor.'\'); return false;" /></a>&nbsp;'."\n";
				break;
			case 'preview' :
				$toolbar .= '<a href="javascript:popupPGEditor(\''.CHEMIN.PATH_PGEDITOR.'popups/preview.php?lng='.$lang_pgeditor[0].'&amp;wysiwyg=0&amp;configpath='.PATH_CONFIG_PGEDITOR.'&amp;nameform='.$nameForm.'&amp;nametextarea='.$namePGEditor.'\',\'Preview\',\'615\',\'400\',\'yes\',\'yes\',\''.$nameForm.'\',\''.$namePGEditor.'\');"  title="'.$lang_pgeditor[19].'"><img alt="'.$lang_pgeditor[19].'" title="'.$lang_pgeditor[19].'" class="icon" border="0" width="23" height="23" src="'.CHEMIN.PATH_PGEDITOR.'images/preview.gif" onclick="popupPGEditor(\''.CHEMIN.PATH_PGEDITOR.'popups/preview.php?lng='.$lang_pgeditor[0].'&amp;wysiwyg=0&amp;configpath='.PATH_CONFIG_PGEDITOR.'&amp;nameform='.$nameForm.'&amp;nametextarea='.$namePGEditor.'\', \'Preview\', \'615\', \'400\', \'yes\', \'yes\', \''.$nameForm.'\', \''.$namePGEditor.'\'); return false;" /></a>&nbsp;'."\n";
				break;
			case 'help' :
				$toolbar .= '<a accesskey="4" href="javascript:displayHelp(true,\''.$nameForm.'\',\''.$namePGEditor.'\');"  title="'.$lang_pgeditor[27].'"><img id="iconHelpOpen_'.$namePGEditor.'" alt="'.$lang_pgeditor[27].'" title="'.$lang_pgeditor[27].'" class="icon" border="0" width="23" height="23" src="'.CHEMIN.PATH_PGEDITOR.'images/help.gif" style="display:inline;" onclick="displayHelp(true, \''.$nameForm.'\', \''.$namePGEditor.'\'); return false;" /></a>&nbsp;'."\n";
				$toolbar .= '<a accesskey="5" href="javascript:displayHelp(false,\''.$nameForm.'\',\''.$namePGEditor.'\');" title="'.$lang_pgeditor[28].'"><img id="iconHelpClose_'.$namePGEditor.'" alt="'.$lang_pgeditor[28].'" title="'.$lang_pgeditor[28].'" class="icon" border="0" width="23" height="23" src="'.CHEMIN.PATH_PGEDITOR.'images/help_off.gif" style="display:none;" onclick="displayHelp(false, \''.$nameForm.'\', \''.$namePGEditor.'\'); return false;" /></a>&nbsp;';
				break;
			default :
		}
	}
	//Editeur
	$display .= '
		<div id="toolbarIconsTA_'.$namePGEditor.'" class="toolbarIconsTA" style="width:'.$width.'px;">
		  '.$toolbar.'
		</div>
		<div id="contentTA_'.$namePGEditor.'" class="contentTA" style="width:'.$width.'px; height:'.$height.'px;">
		  	<textarea id="'.$namePGEditor.'" name="'.$namePGEditor.'" style="width:'.$width.'px; height:'.$height.'px;" accesskey="3" cols="60" rows="20" onselect="selectext(\''.$nameForm.'\',\''.$namePGEditor.'\');" onclick="selectext(\''.$nameForm.'\',\''.$namePGEditor.'\');">'.$content.'</textarea>
		</div>
	';

	//JavaScript
	$display .= '
		<script type="text/javascript">
			displayBlockById("toolbarIconsTA_'.$namePGEditor.'", "block");
			displayBlockById("helpTA_'.$namePGEditor.'", "none");
			document.forms["'.$nameForm.'"].elements["'.$namePGEditor.'"].focus();
			selectext("'.$nameForm.'", "'.$namePGEditor.'");
		</script>
	';
	return $display;
}

/**
 *   displayHelpPGEditorTA
 *   Affiche l'aide dans l'éditeur NON wysiwyg
 */
function displayHelpPGEditorTA()
{
	global $lang_help_pgeditor;
	
	$lang = $lang_help_pgeditor;
	
	//Liens vers popup aide couleur et smiley
	$lang[3] = str_replace($lang_help_pgeditor[1], ' <a href="'.CHEMIN.PATH_PGEDITOR.'popups/color_help.php?lng='.LANG_PGEDITOR.'" title="'.$lang_help_pgeditor[27].$lang_help_pgeditor[29].'" target="_blank" onclick="popupPGEditor(\''.CHEMIN.PATH_PGEDITOR.'popups/color_help.php?lng='.LANG_PGEDITOR.'\', \''.$lang_help_pgeditor[27].'\', \'615\', \'400\', \'yes\', \'yes\', \''.$nameForm.'\', \''.$namePGEditor.'\'); return false;">'.$lang_help_pgeditor[1].'</a>', $lang_help_pgeditor[3]);
	$lang[4] = str_replace($lang_help_pgeditor[1], ' <a href="'.CHEMIN.PATH_PGEDITOR.'popups/color_help.php?lng='.LANG_PGEDITOR.'" title="'.$lang_help_pgeditor[27].$lang_help_pgeditor[29].'" target="_blank" onclick="popupPGEditor(\''.CHEMIN.PATH_PGEDITOR.'popups/color_help.php?lng='.LANG_PGEDITOR.'\', \''.$lang_help_pgeditor[27].'\', \'615\', \'400\', \'yes\', \'yes\', \''.$nameForm.'\', \''.$namePGEditor.'\'); return false;">'.$lang_help_pgeditor[1].'</a>', $lang_help_pgeditor[4]);
	$lang[14] = str_replace($lang_help_pgeditor[1], ' <a href="'.CHEMIN.PATH_PGEDITOR.'popups/smiley_help.php?lng='.LANG_PGEDITOR.'&amp;configpath='.PATH_CONFIG_PGEDITOR.'" title="'.$lang_help_pgeditor[28].$lang_help_pgeditor[29].'" target="_blank" onclick="popupPGEditor(\''.CHEMIN.PATH_PGEDITOR.'popups/smiley_help.php?lng='.LANG_PGEDITOR.'&amp;configpath='.PATH_CONFIG_PGEDITOR.'\', \''.$lang_help_pgeditor[28].'\', \'615\', \'400\', \'yes\', \'yes\', \''.$nameForm.'\', \''.$namePGEditor.'\'); return false;">'.$lang_help_pgeditor[1].'</a>', $lang_help_pgeditor[14]);
	
	//Syntax du code
	$listSyntax = '';
	for($i = 3; $i < 15 ; $i++) {
		$listSyntax .= '<li>'.$lang[$i].'</li>'."\n";
	}
	
	//Raccourcis clavier
	$listAccesskey = '';
	for($j = 16; $j < 27 ; $j++) {
		$listAccesskey .= '<li>'.$lang[$j].'</li>'."\n";
	}
	
	//Aide
	$display = '
			<h3>'.$lang[0].'</h3>
		 	<h4>'.$lang[2].'</h4>
		 	<ul>
		 	'.$listSyntax.'
		 	</ul>
		 	<h4>'.$lang[15].'</h4>
		 	<ul>
		 	'.$listAccesskey.'
		 	</ul>
	';
	
	return $display;
}

/**
 *   selectColorPGEditorTA
 *   Affiche les menus pour le choix des couleurs dans l'éditeur NON wysiwyg
 *   @param  $nameForm       string  le nom assigné au formulaire (attribut name)
 *   @param  $namePGEditor   string  le nom assigné à l'éditeur (attribut name du textarea)
 *   @param  $nameTag        string  le nom assigné au menu
 *   @param  $styleCSS       string  le nom de la propriété CSS
 */
function selectColorPGEditorTA($nameForm, $namePGEditor, $nameTag, $styleCSS)
{
	global $lang_pgeditor, $lang_color_pgeditor;
	//Couleurs
	$colorWebSafe = array(
						'black' => $lang_color_pgeditor[1], 'gray' => $lang_color_pgeditor[2], 'silver' => $lang_color_pgeditor[3], 'white' => $lang_color_pgeditor[4], 'red' => $lang_color_pgeditor[6], 'maroon' => $lang_color_pgeditor[5],
						'orange' => $lang_color_pgeditor[7], 'yellow' => $lang_color_pgeditor[8], 'lime' => $lang_color_pgeditor[9], 'green' => $lang_color_pgeditor[10], 'olive' => $lang_color_pgeditor[11], 'aqua' => $lang_color_pgeditor[12],
						'blue' => $lang_color_pgeditor[13], 'teal' => $lang_color_pgeditor[14], 'navy' => $lang_color_pgeditor[15], 'fuchsia' => $lang_color_pgeditor[16], 'purple' => $lang_color_pgeditor[17]
	);
	$lang = ($nameTag == 'color')? $lang_pgeditor[2] : $lang_pgeditor[3];  	//Intitulé
	$accesskey = ($nameTag == 'color')? 'accesskey="2"' : ''; 				//Raccourcis clavier
	//Options
	$options = '<option value="" selected="selected">'.$lang_pgeditor[29].'</option>'."\n";
	foreach ($colorWebSafe as $color => $nameColor) {
		$options .= '<option value="'.$color.'" style="'.$styleCSS.':'.$color.'" title="'.$color.'">'.$nameColor.'</option>'."\n";
	}
	//Menu
	$menu = '
		<label for="'.$nameTag.'_'.$namePGEditor.'" '.$accesskey.' title="'.$lang.'">
		<img alt="'.$lang.'" title="'.$lang.'" class="icon_color" border="0" width="23" height="23" src="'.CHEMIN.PATH_PGEDITOR.'images/'.$nameTag.'.gif" />
		</label>&nbsp;
		<select id="'.$nameTag.'_'.$namePGEditor.'" name="'.$nameTag.'_'.$namePGEditor.'" size="1" class="icon_color" onchange="AddTagColor(\''.$nameTag.'_'.$namePGEditor.'\',\''.$nameTag.'\',\''.$nameForm.'\',\''.$namePGEditor.'\');">
		'.$options.'
		</select>
	';
	return $menu;
}

/**
 *   selectLanguageCode
 *   Affiche le menu pour le choix du langage du code inséré dans l'éditeur NON wysiwyg
 *   @param  $nameForm       string  le nom assigné au formulaire (attribut name)
 *   @param  $namePGEditor   string  le nom assigné à l'éditeur (attribut name du textarea)
 *   @param  $nameTag        string  le nom assigné au menu
 */
function selectLanguageCodePGEditorTA($nameForm, $namePGEditor, $nameTag = 'code')
{
	global $lang_pgeditor;
	//Language Code
	$languageCode = explode('|', LANGUAGE_CODE);

	//Options
	$options = '<option value="none" selected="selected">'.$lang_pgeditor[34].'</option>'."\n";
	for ($i = 0; $i < count($languageCode); $i++) {
		$options .= '<option value="'.$languageCode[$i].'" title="'.$languageCode[$i].'">'.$languageCode[$i].'</option>'."\n";
	}
	$options .= '<option value="">'.$lang_pgeditor[33].'</option>'."\n";

	//Menu
	$menu = '
		<label for="'.$nameTag.'_'.$namePGEditor.'" title="'.$lang_pgeditor[8].'">
		<img alt="'.$lang_pgeditor[8].'" title="'.$lang_pgeditor[8].'" class="icon_color" border="0" width="23" height="23" src="'.CHEMIN.PATH_PGEDITOR.'images/'.$nameTag.'.gif" />
		</label>&nbsp;
		<select id="'.$nameTag.'_'.$namePGEditor.'" name="'.$nameTag.'_'.$namePGEditor.'" size="1" class="icon_color" onchange="AddTagCode(\''.$nameTag.'_'.$namePGEditor.'\',\''.$nameTag.'\',\''.$nameForm.'\',\''.$namePGEditor.'\');">
		'.$options.'
		</select>
	';
	return $menu;
}

/**
 *   smileyPGEditor
 *   Affiche la barre des smileys dans l'éditeur wysiwyg ou non
 *   @param  $nameForm       string  le nom assigné au formulaire (attribut name)
 *   @param  $namePGEditor   string  le nom assigné à l'éditeur
 */
function smileyPGEditor($nameForm, $namePGEditor, $width)
{
	global $lang_smiley_pgeditor;
	$smiley = array(
					'cool' => $lang_smiley_pgeditor[1], 'wink' => $lang_smiley_pgeditor[2], 'biggrin' => $lang_smiley_pgeditor[3],
					'smile' => $lang_smiley_pgeditor[4], 'frown' => $lang_smiley_pgeditor[5], 'eek' => $lang_smiley_pgeditor[6],
					'mad' => $lang_smiley_pgeditor[7], 'confused' => $lang_smiley_pgeditor[8], 'rolleyes' => $lang_smiley_pgeditor[9],
					'tongue' => $lang_smiley_pgeditor[10], 'cry' => $lang_smiley_pgeditor[11]
	);

    $display = '<div id="toolbarSmileys_'.$namePGEditor.'" class="toolbarSmileys" style="width:'.$width.'px;">'."\n";
	foreach ($smiley as $name => $alt) {
		if (file_exists(CHEMIN.PATH_GUPPYSMILEY.$name.'.gif')) {
			$imgSize = getimagesize(CHEMIN.PATH_GUPPYSMILEY.$name.'.gif');
			if (WYSIWYG) {
    			$display .= '<a href="javascript:void(0);"><img class="icon" src="'.CHEMIN.PATH_GUPPYSMILEY.$name.'.gif'.'" '.$imgSize[3].' border="0" title="'.$alt.'" alt="'.$alt.'" onclick="'.$namePGEditor.'.addImage(\''.BASEPATH.PATH_GUPPYSMILEY.$name.'.gif'.'\'); return false;" /></a>&nbsp;'."\n";
			} else {
        		$display .= '<a href="javascript:AddSmiley(\'%3Cimg='.$name.'%3E\',\''.$nameForm.'\',\''.$namePGEditor.'\');" title="'.$alt.'"><img class="icon" src="'.CHEMIN.PATH_GUPPYSMILEY.$name.'.gif'.'" '.$imgSize[3].' border="0" title="'.$alt.'" alt="'.$alt.'" onclick="AddSmiley(\'&lt;img='.$name.'&gt;\', \''.$nameForm.'\', \''.$namePGEditor.'\'); return false;" /></a>&nbsp;'."\n";
			}
		}
    }
	$display .= '</div>';
	//JavaScript
    $display .= '
		<script type="text/javascript">
		'.((WYSIWYG)? $namePGEditor.'.' : '').'displayBlockById("toolbarSmileys_'.$namePGEditor.'", "block");
		</script>
	';
	return $display;
}

/**************************************************************************************
*   PARSER XHTML POUR POSTGUEST EDIT0R
***************************************************************************************/
/**
 *   parseCodePGEditor
 *   Analyse et corrige le code envoyé par l'éditeur wysiwyg ou non
 *   @param  $content  string  le contenu de l'éditeur
 */
function parseCodePGEditor($content)
{
	if (WYSIWYG) {
		$content = (JAVASCRIPT)? parseCodePGEditorWIW($content) : parseCodePGEditorTA($content);
	} else {
		$content = parseCodePGEditorTA($content);
	}
	$content = str_replace('\\', '&#92;', $content); //affichage des antislashs

	return $content;
}

/**
 *   parseCodePGEditorWIW
 *   Analyse et corrige le code envoyé par l'éditeur wysiwyg
 *   @param  $content  string  le contenu de l'éditeur
 */
function parseCodePGEditorWIW($content)
{
	global $lang_pgeditor;
	switch (BROWSER) {
		case 'IE' :
			$content = str_replace(array('[',']'), array('&#91;','&#93;'), $content);
			$content = str_replace(array('<BR>', '<HR>'), array('[br /]', '[hr /]'), $content);
			$tag = array(
						  "`<DIV class=code><SPAN class=code>".$lang_pgeditor[25]."( [-0-9a-zA-Z_]+)?</SPAN><PRE><CODE>(.+)</CODE></PRE></DIV>`sU" => 'convertCodeXHTML',
						  "`<DIV class=cite><SPAN class=cite>".$lang_pgeditor[23]."( [-0-9a-zA-Z_]+)?</SPAN>[^<]+<P><CITE>(.+)</CITE></P></DIV>`sU" => 'convertCiteXHTML',
						  "`<IMG src=\"".BASEPATH."((?:[-0-9a-zA-Z_/]*)([-0-9a-zA-Z_]+)\.(?:".ALLOWED_EXTIMG."))\">`" => 'convertImgXHTML',
						  "`<IMG src=\"http://([^>\"\s]+)\">`" => 'convertExternalImgXHTML',
						  "`<A href=\"([^\"]+)\"(?: target=_blank)?>(.+)</A>`sU" => 'convertLinkXHTML', // Target Blank
						  /*"`<A href=\"([^\"]+)\">(.+)</A>`sU" => 'convertLinkXHTML',*/
						  "`<(OL|UL)>[^<]+((?:<LI>.+</LI>)+)</\\1>`sU" => 'convertListeXHTML',
						  "`<(P|DIV)(?: align=(center|left|right))?>(.+)</\\1>`sU" => 'convertBlockXHTML'
			);
			foreach($tag as $modele => $callback) {
				$content = preg_replace_callback($modele, $callback, $content);
			}
			$content = convertTagXHTML("`<FONT( style=\"BACKGROUND-COLOR: #[0-9a-fA-F]{6}\")?( color=#[0-9a-fA-F]{6})?>(.+)</FONT>`sU", 'convertFontXHTML', $content);  //IE
			$content = convertTagXHTML("`<SPAN style=\"((?:BACKGROUND-COLOR|COLOR): #[0-9a-fA-F]{6}|TEXT-DECORATION: underline)\">(.+)</SPAN>`sU", 'convertSpanXHTML', $content);

			$tagIN = array(
							"`<STRONG>(.+)</STRONG>`sU",
							"`<EM>(.+)</EM>`sU",
							"`<U>(.+)</U>`sU"
			);
			$tagOUT = array(
							'[strong]$1[/strong]',
							'[em]$1[/em]',
							'[span style="text-decoration:underline;"]$1[/span]'
			);
			$content = preg_replace($tagIN, $tagOUT, $content);
			$content = strip_tags($content);
			$content = str_replace(array('<','>','$'), array(' &lt;','&gt; ','&#36;'), $content);
			$content = str_replace(array('[',']'), array('<','>'), $content);
			break;

		case 'IE9' :
			$content = str_replace(array('[',']'), array('&#91;','&#93;'), $content);
			$content = str_replace(array('<br>', '<hr>'), array('[br /]', '[hr /]'), $content);
			$tag = array(
						  "`<div class=\"code\"><span class=\"code\">".$lang_pgeditor[25]."( [-0-9a-zA-Z_]+)?</span><pre><code>(.+)</code></pre></div>`sU" => 'convertCodeXHTML',
						  "`<div class=\"cite\"><span class=\"cite\">".$lang_pgeditor[23]."( [-0-9a-zA-Z_]+)?</span><p><cite>(.+)</cite></p></div>`sU" => 'convertCiteXHTML',
						  "`<img src=\"".BASEPATH."((?:[-0-9a-zA-Z_/]*)([-0-9a-zA-Z_]+)\.(?:".ALLOWED_EXTIMG."))\">`" => 'convertImgXHTML',
						  "`<img src=\"http://([^>\"\s]+)\">`" => 'convertExternalImgXHTML',
						  "`<a href=\"([^\"]+)\"(?: target=_blank)?>(.+)</a>`sU" => 'convertLinkXHTML', // Target Blank
						  /*"`<A href=\"([^\"]+)\">(.+)</A>`sU" => 'convertLinkXHTML',*/
						  "`<(ol|ul)>((?:<li>.+</li>)+)</\\1>`sU" => 'convertListeXHTML',
						  "`<(p|div)(?: align=(center|left|right))?>(.+)</\\1>`sU" => 'convertBlockXHTML'
			);
			foreach($tag as $modele => $callback) {
				$content = preg_replace_callback($modele, $callback, $content);
			}

            $content = convertTagXHTML("`<font( style=\"background-color: rgb\([0-9, ]+\);\")?( color=\"#[0-9a-fA-F]{6}\")?>(.+)</font>`sU", 'convertFontXHTML', $content);  //IE9

			$tagIN = array(
							"`<strong>(.+)</strong>`sU",
							"`<em>(.+)</em>`sU",
							"`<u>(.+)</u>`sU"
			);
			$tagOUT = array(
							'[strong]$1[/strong]',
							'[em]$1[/em]',
							'[span style="text-decoration:underline;"]$1[/span]'
			);
			$content = preg_replace($tagIN, $tagOUT, $content);
			$content = strip_tags($content);
			$content = str_replace(array('<','>','$'), array(' &lt;','&gt; ','&#36;'), $content);
			$content = str_replace(array('[',']'), array('<','>'), $content);
			break;

		case 'Gecko' :
			$content = preg_replace("`^(&nbsp;|<br>)+`i", '', $content);
			$content = str_replace(array('[',']'), array('&#91;','&#93;'), $content);
			$content = str_replace(array('<br>', '<hr>'), array('[br /]', '[hr /]'), $content);
			$tag = array(
						  "`<div class=\"code\"><span class=\"code\">".$lang_pgeditor[25]."( [-0-9a-zA-Z_]+)?</span><pre><code>(.+)</code></pre></div>`sU" => 'convertCodeXHTML',
						  "`<div class=\"cite\"><span class=\"cite\">".$lang_pgeditor[23]."( [-0-9a-zA-Z_]+)?</span><p><cite>(.+)</cite></p></div>`sU" => 'convertCiteXHTML',
						  "`<img src=\"".BASEPATH."((?:[-0-9a-zA-Z_/]*)([-0-9a-zA-Z_]+)\.(?:".ALLOWED_EXTIMG."))\">`" => 'convertImgXHTML',
						  "`<img src=\"http://([^>\"\s]+)\">`" => 'convertExternalImgXHTML',
						  "`<a href=\"([^\"]+)\"(?: target=\"_blank\")?>(.+)</a>`sU" => 'convertLinkXHTML', // Target Blank
						  /*"`<a href=\"([^\"]+)\">(.+)</a>`sU" => 'convertLinkXHTML',*/
						  "`<(ol|ul)( style=\"[-0-9a-iklnor-uwxy\:;, \(\)]+\")?>((?:<li(?: style=\"[-0-9a-iklnor-uwxy\:;, \(\)]+\")?>.+</li>)+)</\\1>`sU" => 'convertListeXHTML',
			);
			foreach($tag as $modele => $callback) {
				$content = preg_replace_callback($modele, $callback, $content);
			}
			$content = convertTagXHTML("`<(span|div) style=\"([\-0-9a-iklnor-uwxyA-F\:;,# \(\)]+)\">(.+)</\\1>`sU",'[$1 style="$2"]$3[/$1]', $content);
			$content = convertTagXHTML("`<font color=\"(#[0-9a-fA-F]{6})\">(.+)</font>`sU",'[span style="color:$1;"]$2[/span]', $content);
			$content = convertTagXHTML("`<div align=\"(center|left|right)\">(.+)</div>`sU",'[div style="text-align:$1;"]$2[/div]', $content);
			$content = convertTagXHTML("`<p( style=\"text-align:(center|left|right);\")?>(.+)</p>`sU",'[p$1]$3[/p]', $content);

			$tagIN = array(
							"`<(b|strong)>(.+)</\\1>`sU",
							"`<(i|em)>(.+)</\\1>`sU",
							"`<u>(.+)</u>`sU"
			);
			$tagOUT = array(
							'[strong]$2[/strong]',
							'[em]$2[/em]',
							'[span style="text-decoration:underline;"]$1[/span]'
			);
			$content = preg_replace($tagIN, $tagOUT, $content);
			$content = strip_tags($content);
			$content = str_replace(array('<','>','$'), array(' &lt;','&gt; ','&#36;'), $content);
			$content = str_replace(array('[',']'), array('<','>'), $content);
			break;

		case 'Opera' :
			$content = str_replace(array('[',']'), array('&#91;','&#93;'), $content);
			$content = str_replace(array('<br>', '<BR>', '<BR/>', '<hr>', '<HR>', '<HR/>'), array('[br /]', '[br /]', '[hr /]', '[hr /]'), $content);
			$tag = array(
						  "`<DIV class=\"code\"><SPAN class=\"code\">".$lang_pgeditor[25]."( [-0-9a-zA-Z_]+)?</SPAN><PRE><CODE>(.+)</CODE></PRE></DIV>`isU" => 'convertCodeXHTML',
						  "`<DIV class=\"cite\"><SPAN class=\"cite\">".$lang_pgeditor[23]."( [-0-9a-zA-Z_]+)?</SPAN><P><CITE>(.+)</CITE></P></DIV>`isU" => 'convertCiteXHTML',
						  "`<IMG src=\"".BASEPATH."((?:[-0-9a-zA-Z_/]*)([-0-9a-zA-Z_]+)\.(?:".ALLOWED_EXTIMG."))\"/?>`i" => 'convertImgXHTML',
						  "`<IMG src=\"http://([^>\"\s]+)\"/?>`i" => 'convertExternalImgXHTML',
						  "`<A href=\"([^\"]+)\"(?: target=\"_blank\")?>(.+)</A>`isU" => 'convertLinkXHTML', // Target Blank
						  /*"`<A href=\"([^\"]+)\">(.+)</A>`isU" => 'convertLinkXHTML',*/
						  "`<(OL|UL)(?: align=\"(center|left|right)\")?>((?:<LI(?: align=\"(?:center|left|right)\")?>.+</LI>)+)</\\1>`isU" => 'convertListeXHTML',
						  "`<(P)(?: align=\"(center|left|right)\")?>(.+)</\\1>`isU" => 'convertBlockXHTML'	// Ajout compatibilité Opera 9.50
			);
			foreach($tag as $modele => $callback) {
				$content = preg_replace_callback($modele, $callback, $content);
			}
			$content = convertTagXHTML("`<DIV align=\"(center|left|right)\">(.+)</DIV>`isU",'[div style="text-align:$1;"]$2[/div]', $content);
//			$content = convertTagXHTML("`<SPAN STYLE='background-color: #([0-9abcdefABCDEF]{6})'>(.+)</SPAN>`sU",'[span style="background-color:#$1;"]$2[/span]', $content);
			$content = convertTagXHTML("`<SPAN STYLE=(?:'|\")background-color:(?: )?#([0-9abcdefABCDEF]{6});?(?:'|\")>(.+)</SPAN>`isU",'[span style="background-color:#$1;"]$2[/span]', $content);	// Modif compatibilité Opera 9.50

			$tagIN = array(
							"`<FONT color=\"#([0-9abcdefABCDEF]{6})\">(.+)</FONT>`isU",
							"`<STRONG>(.+)</STRONG>`isU",
							"`<(I|EM)>(.+)</\\1>`isU",	// Modif compatibilité Opera 9.50
							"`<U>(.+)</U>`isU"
			);
			$tagOUT = array(
							'[span style="color:#$1;"]$2[/span]',
							'[strong]$1[/strong]',
							'[em]$2[/em]',	// Modif compatibilité Opera 9.50
							'[span style="text-decoration:underline;"]$1[/span]'
			);
			$content = preg_replace($tagIN, $tagOUT, $content);
			$content = strip_tags($content);
			$content = str_replace(array('<','>','$'), array(' &lt;','&gt; ','&#36;'), $content);
			$content = str_replace(array('[',']'), array('<','>'), $content);
			break;
		
		case 'Safari' :
			$content = str_replace(array('[',']'), array('&#91;','&#93;'), $content);
			$content = str_replace(array(' class="Apple-style-span"', ' class="webkit-block-placeholder"', ' id=""'), '', $content);
			$content = str_replace(array('<div><br></div>', '<br>', '<hr>'), array('[br /]', '[br /]', '[hr /]'), $content);
			$tag = array(
						  "`<div class=\"code\"><span class=\"code\">".$lang_pgeditor[25]."( [-0-9a-zA-Z_]+)?</span><pre><code>(.+)</code></pre></div>`sU" => 'convertCodeXHTML',
						  "`<div class=\"cite\"><span class=\"cite\">".$lang_pgeditor[23]."( [-0-9a-zA-Z_]+)?</span><p><cite>(.+)</cite></p></div>`sU" => 'convertCiteXHTML',
						  "`<img src=\"".BASEPATH."((?:[-0-9a-zA-Z_/]*)([-0-9a-zA-Z_]+)\.(?:".ALLOWED_EXTIMG."))\">`" => 'convertImgXHTML',
						  "`<img src=\"http://([^>\"\s]+)\">`" => 'convertExternalImgXHTML',
						  "`<a href=\"([^\"]+)\"(?: target=\"_blank\")?>(.+)</a>`sU" => 'convertLinkXHTML', // Target Blank
						  /*"`<a href=\"([^\"]+)\">(.+)</a>`sU" => 'convertLinkXHTML',*/
						  "`<(ol|ul)( style=\"[-0-9a-iklnor-uwxy\:;, \(\)]+\")?>((?:<li(?: style=\"[-0-9a-iklnor-uwxy\:;, \(\)]+\")?>.+</li>)+)</\\1>`sU" => 'convertListeXHTML'
			);
			foreach($tag as $modele => $callback) {
				$content = preg_replace_callback($modele, $callback, $content);
			}
			$content = convertTagXHTML("`<span style=\"([-0-9a-iklnor-uwxy\:;, \(\)]+)\">(.+)</span>`sU",'[span style="$1"]$2[/span]', $content);
			$content = convertTagXHTML("`<div( style=\"[-0-9a-iklnor-uwxy\:;, \(\)]+\")?>([^\s\xA0]+)</div>`sU",'[div$1]$2[/div]', $content);

			$tagIN = array(
							"`<(b|strong)>(.+)</\\1>`sU",
							"`<(i|em)>(.+)</\\1>`sU",
							"`<font color=\"(#[0-9a-fA-F]{6})\">(.+)</font>`sU",
							"`<u>(.+)</u>`sU"
			);
			$tagOUT = array(
							'[strong]$2[/strong]',
							'[em]$2[/em]',
							'[span style="color:$1"]$2[/span]',
							'[span style="text-decoration:underline;"]$1[/span]'			
			);
			$content = preg_replace($tagIN, $tagOUT, $content);
			$content = strip_tags($content);
			$content = str_replace(array('<','>','$'), array(' &lt;','&gt; ','&#36;'), $content);
			$content = str_replace(array('[',']'), array('<','>'), $content);
			
			// On nettoie les espaces au début et la fin du message
			$tagIN = array(
					"`^(<br />|\s)+`",   //Suppression des espaces au début
					"`(<br />|\s)+$`"    //Suppression des espaces à la fin
			);
	
			$tagOUT = array(
					'',
					''
			);
			$content = preg_replace($tagIN, $tagOUT, $content);			
			break;

		default :
			$content = '';
	}

	return $content;
}

/**
 *   parseCodePGEditorTA
 *   Analyse et corrige le code envoyé par l'éditeur NON wysiwyg (textarea)
 *   @param  $content  string  le contenu de l'éditeur
 */
function parseCodePGEditorTA($content)
{
	global $lang_smiley_pgeditor;
	$content = str_replace(array('&','[',']'), array('&amp;','&#91;','&#93;'), $content);
	$content = str_replace(array(chr(13).chr(10), chr(10), chr(13)), array('[br /]'), $content);	//remplacement \r\n, \r et \n par <br />
	$tag = array(
				  "`<code(?:=([-0-9a-z_]+))?>(.+)</code>`sU" => 'convertCodeXHTML',
				  "`<cite(?:=([-0-9a-zA-Z_]+))?>(.+)</cite>`sU" => 'convertCiteXHTML',
				  "`<img=(([-0-9a-zA-Z_]+)\.(".ALLOWED_EXTIMG."))>`sU" => 'convertImgXHTML',
				  "`<img=http://([^>\s]+)>`i" => 'convertExternalImgXHTML',
				  "`<link(?:=([^>]+))?>(.+)</link>`sU" => 'convertLinkXHTML'
//				  "`<(listnumber|listpuce)>(<\*>.+</\*>)+)</\\1>`sU" => 'convertListeXHTML'  // TODO
	);
	foreach($tag as $modele => $callback) {
		$content = preg_replace_callback($modele, $callback, $content);
	}
	$content = convertTagXHTML("`<b>(.+)</b>`isU",'[strong]$1[/strong]', $content);
	$content = convertTagXHTML("`<i>(.+)</i>`isU",'[em]$1[/em]', $content);
	$content = convertTagXHTML("`<u>(.+)</u>`isU",'[span style="text-decoration:underline;"]$1[/span]', $content);
	$content = convertTagXHTML("`<color=(\#[abcdef0-9]{3,6}|[a-z]+)>(.+)</color>`isU", '[span style="color:$1;"]$2[/span]', $content);
	$content = convertTagXHTML("`<bgcolor=(\#[abcdef0-9]{3,6}|[a-z]+)>(.+)</bgcolor>`isU", '[span style="background-color:$1;"]$2[/span]', $content);
	$content = convertTagXHTML("`<(left|center|right)>(.+)</\\1>`sU",'[div style="text-align:$1;"]$2[/div]', $content);
	$smileyIn = array(
					'<img=cool>','<img=wink>','<img=biggrin>','<img=smile>','<img=frown>','<img=eek>',
					'<img=mad>','<img=confused>','<img=rolleyes>','<img=tongue>','<img=cry>'
	);
	$smileyOut = array(
					'[img src="'.PATH_GUPPYSMILEY.'cool.gif" alt="'.$lang_smiley_pgeditor[1].'" title="'.$lang_smiley_pgeditor[1].'" border="0" /]',
					'[img src="'.PATH_GUPPYSMILEY.'wink.gif" alt="'.$lang_smiley_pgeditor[2].'" title="'.$lang_smiley_pgeditor[2].'" border="0" /]',
					'[img src="'.PATH_GUPPYSMILEY.'biggrin.gif" alt="'.$lang_smiley_pgeditor[3].'" title="'.$lang_smiley_pgeditor[3].'" border="0" /]',
					'[img src="'.PATH_GUPPYSMILEY.'smile.gif" alt="'.$lang_smiley_pgeditor[4].'" title="'.$lang_smiley_pgeditor[4].'" border="0" /]',
					'[img src="'.PATH_GUPPYSMILEY.'frown.gif" alt="'.$lang_smiley_pgeditor[5].'" title="'.$lang_smiley_pgeditor[5].'" border="0" /]',
					'[img src="'.PATH_GUPPYSMILEY.'eek.gif" alt="'.$lang_smiley_pgeditor[6].'" title="'.$lang_smiley_pgeditor[6].'" border="0" /]',
					'[img src="'.PATH_GUPPYSMILEY.'mad.gif" alt="'.$lang_smiley_pgeditor[7].'" title="'.$lang_smiley_pgeditor[7].'" border="0" /]',
					'[img src="'.PATH_GUPPYSMILEY.'confused.gif" alt="'.$lang_smiley_pgeditor[8].'" title="'.$lang_smiley_pgeditor[8].'" border="0" /]',
					'[img src="'.PATH_GUPPYSMILEY.'rolleyes.gif" alt="'.$lang_smiley_pgeditor[9].'" title="'.$lang_smiley_pgeditor[9].'" border="0" /]',
					'[img src="'.PATH_GUPPYSMILEY.'tongue.gif" alt="'.$lang_smiley_pgeditor[10].'" title="'.$lang_smiley_pgeditor[10].'" border="0" /]',
					'[img src="'.PATH_GUPPYSMILEY.'cry.gif" alt="'.$lang_smiley_pgeditor[11].'" title="'.$lang_smiley_pgeditor[11].'" border="0" /]'
	);
	$content = str_replace($smileyIn, $smileyOut, $content);
	$content = strip_tags($content);
	$content = str_replace(array('<','>','$'), array(' &lt;','&gt; ','&#36;'), $content);
	$content = str_replace(array('[',']'), array('<','>'), $content);

	return $content;
}

/**
 *   convertImgXHTML
 *   Analyse et corrige le code correspondant aux images envoyé par l'éditeur wysiwyg ou non
 *   @param  $matches  array  le tableau contenant l'ensemble des motifs capturés par l'expression régulière
 */
function convertImgXHTML($matches)
{
	if (WYSIWYG) { //WYSIWYG
		switch (BROWSER) {
			case 'IE' :
            case 'IE9' :
			case 'Gecko' :
			case 'Opera' :
			case 'Safari' :
				if (is_file(CHEMIN.$matches[1])) {
					$imgSize = getimagesize(CHEMIN.$matches[1]);
					
					if ($imgSize) {
						list($imgSize[0], $imgSize[1]) = checkImageSize($imgSize[0], $imgSize[1]);		
						$matches[0] = '[img src="'.$matches[1].'" width="'.$imgSize[0].'" height="'.$imgSize[1].'" alt="'.$matches[2].'" title="'.$matches[2].'" border="0" /]';
					} else {
						$matches[0] = '';
					}
				} else {
					$matches[0] = '';
				}
				break;

			default :
		}
	} else { //TEXTAREA
		if (is_file(CHEMIN.PATH_SMILEY.$matches[1])) {
			$imgSize = getimagesize(CHEMIN.PATH_SMILEY.$matches[1]);
			
			if ($imgSize) {
				list($imgSize[0], $imgSize[1]) = checkImageSize($imgSize[0], $imgSize[1]);
				$matches[0] = '[img src="'.PATH_SMILEY.$matches[1].'" width="'.$imgSize[0].'" height="'.$imgSize[1].'" alt="'.$matches[2].'" title="'.$matches[2].'" border="0" /]';
			} else {
				$matches[0] = '';
			}
		} else {
			$matches[0] = '';
		}
	}
	return $matches[0];
}

/**
 * convertExternalImgXHTML
 * Analyse et corrige le code correspondant aux images externes envoyé par l'éditeur wysiwyg ou non
 * @param  $matches  array  le tableau contenant l'ensemble des motifs capturés par l'expression régulière
 * @return string
 * @access private
 */
function convertExternalImgXHTML($matches)
{
	if (!ALLOWED_INSERT_IMG || !in_array('image', explode('|', TOOLBAR_MENU))) {
		return '';
	}

	if (WYSIWYG) { //WYSIWYG
		switch (BROWSER) {
			case 'IE' :
            case 'IE9' :
			case 'Gecko' :
			case 'Opera' :
			case 'Safari' :
				$allowedExt = explode('|', ALLOWED_EXTIMG);
				$imgSize = getimagesize('http://'.$matches[1]);

				if ($imgSize && in_array($imgSize[2], getImageType($allowedExt))) {
					list($imgSize[0], $imgSize[1]) = checkImageSize($imgSize[0], $imgSize[1]);
					$matches[0] = '[img src="http://'.$matches[1].'" width="'.$imgSize[0].'" height="'.$imgSize[1].'" alt="'.$matches[2].'" title="'.$matches[2].'" border="0" /]';
				} else {
					$matches[0] = '';
				}
				break;

			default :
		}
	} else { //TEXTAREA
		$allowedExt = explode('|', ALLOWED_EXTIMG);
		$imgSize = getimagesize('http://'.$matches[1]);

		if ($imgSize && in_array($imgSize[2], getImageType($allowedExt))) {
			list($imgSize[0], $imgSize[1]) = checkImageSize($imgSize[0], $imgSize[1]);
			$matches[0] = '[img src="http://'.$matches[1].'" width="'.$imgSize[0].'" height="'.$imgSize[1].'" alt="'.$matches[2].'" title="'.$matches[2].'" border="0" /]';
		} else {
			$matches[0] = '';
		}
	}
	return $matches[0];
}

/**
 * getImageType
 * Renvoie les identifiants associées au type des images correspondant à leur extension
 * @param  $ext  array  Tableau contenant les extensions des images dont on veut récupérer le type
 * @return array
 * @access  private
 */
function getImageType($ext)
{
	$imageType = array( 'gif' => IMAGETYPE_GIF, 'jpg' => IMAGETYPE_JPEG, 'jpeg' => IMAGETYPE_JPEG, 'png' => IMAGETYPE_PNG,
						'bmp' => IMAGETYPE_BMP);

	settype($ext, 'array');
	$idType = array();
	
	foreach ($ext as $val) {
		if (array_key_exists($val, $imageType)) {
			$idType[] = $imageType[$val];
		}
	}
	
	return $idType;
}

/**
 * checkImageSize
 * renvoie la taille des images après leur vérification
 * @param $width integer Largeur originale de l'image
 * @param $height integer Hauteur originale de l'image
 * @return array Taille de l'image après vérification
 * @access  private
 */
function checkImageSize($width, $height)
{
	settype($width, 'integer');
	settype($height, 'integer');
	
	$ratio = ( $height / $width );
	
	if (ALLOWED_MAX_WIDTH_IMG && ($width > ALLOWED_MAX_WIDTH_IMG)) {	// Largeur max
		$width = (int) ALLOWED_MAX_WIDTH_IMG;
		$height = round($width * $ratio);
	}
		
	return array($width, $height);
}

/**
 *   convertLinkXHTML
 *   Analyse et corrige le code correspondant aux liens envoyé par l'éditeur wysiwyg ou non
 *   @param  $matches  array  le tableau contenant l'ensemble des motifs capturés par l'expression régulière
 */
function convertLinkXHTML($matches)
{
	if (WYSIWYG) { //WYSIWYG
		switch (BROWSER) {
			case 'IE' :
            case 'IE9' :
			case 'Gecko' :
			case 'Opera' :
			case 'Safari' :
				if(preg_match("`(\s|\.\./|\'|%|<|¼|&lt;?|&#0*60;?|&#x0*3c;?|\x3c|^\bjavascript\b|\(|document\.cookie)`i", $matches[1])) {
					$matches[0] = '';
				} else {
					$matches[0] = '[a href="'.$matches[1].'" target="_blank"]'.wordwrap($matches[2], 100," ",1).'[/a]'; // Target Blank
					//$matches[0] = '[a href="'.$matches[1].'"]'.wordwrap($matches[2],50," ",1).'[/a]'; 
				}
				break;

			default :
		}
	} else { //TEXTAREA
		if (isset($matches[1]) && trim($matches[1]) != '') {
			if (preg_match("`(\s|\.\./|\'|%|<|¼|&lt;?|&#0*60;?|&#x0*3c;?|\x3c|^\bjavascript\b|\(|document\.cookie)`", $matches[1])) {
				$matches[0] = '';
			} else {
				$matches[0] = '[a href="'.$matches[1].'" target="_blank"]'.wordwrap($matches[2], 100," ",1).'[/a]'; // Target Blank
				//$matches[0] = '[a href="'.$matches[1].'"]'.wordwrap($matches[2],50," ",1).'[/a]';
			}
		} elseif (isset($matches[2]) && trim($matches[2]) != '') {
			if (preg_match("`(\s|\.\./|\'|%|<|¼|&lt;?|&#0*60;?|&#x0*3c;?|\x3c|^\bjavascript\b|\(|document\.cookie)`", $matches[2])) {
				$matches[0] = '';
			} else {
				$matches[0] = '[a href="'.$matches[2].'" target="_blank"]'.wordwrap($matches[2], 100," ",1).'[/a]'; // Target Blank
				//$matches[0] = '[a href="'.$matches[2].'"]'.wordwrap($matches[2],50," ",1).'[/a]';
			}
		}
	}
	return $matches[0];
}

/**
 *   convertCodeXHTML
 *   Analyse et corrige le code correspondant aux balises <code> envoyé par l'éditeur wysiwyg ou non
 *   @param  $matches  array  le tableau contenant l'ensemble des motifs capturés par l'expression régulière
 */
function convertCodeXHTML($matches)
{
	global $lang_pgeditor;
	if (WYSIWYG) { //WYSIWYG
		switch (BROWSER) {
			case 'IE' :
            case 'IE9' :
			case 'Gecko' :
			case 'Opera' :
			case 'Safari' :
				$matches[2] = str_replace(array('<','>','"','$'),array('&lt;','&gt;','&quot;','&#36;'),$matches[2]);
				break;

			default :
		}
	} else { //TEXTAREA
		$matches[1] = (isset($matches[1]) && trim($matches[1]) != '')? ' '.$matches[1] : '';
		$matches[2] = str_replace(array('<','>','"','$'), array(' &lt;','&gt; ','&quot;','&#36;'), $matches[2]);
	}
	//Coloration syntaxique du code
/*	if(file_exists(CHEMIN.PATH_PGEDITOR.'syntaxcolor/'.trim($matches[1]).'.php')) {
		include_once(CHEMIN.PATH_PGEDITOR.'syntaxcolor/'.trim($matches[1]).'.php');
		$matches[2] = colorSyntaxCode($matches[2]);
	}
*/	//
	$matches[0] = '[div class="code"][span class="code"]'.$lang_pgeditor[25].$matches[1].'[/span][pre][code]'.$matches[2].'[/code][/pre][/div]';
	return $matches[0];
}

/**
 *   convertCiteXHTML
 *   Analyse et corrige le code correspondant aux balises <cite> envoyé par l'éditeur wysiwyg ou non
 *   @param  $matches  array  le tableau contenant l'ensemble des motifs capturés par l'expression régulière
 */
function convertCiteXHTML($matches)
{
	global $lang_pgeditor;
    
	if (WYSIWYG) { //WYSIWYG
		switch (BROWSER) {
			case 'IE' :
            case 'IE9' :
			case 'Gecko' :
			case 'Opera' :
			case 'Safari' :
				$matches[2] = str_replace('&nbsp;', ' ', $matches[2]);
				break;
			default :
		}
	} else { //TEXTAREA
		$matches[1] = (isset($matches[1]) && trim($matches[1]) != '')? ' '.$matches[1] : '';
	}
	$matches[0] = '[div class="cite"][span class="cite"]'.$lang_pgeditor[23].$matches[1].'[/span][p][cite]'.$matches[2].'[/cite][/p][/div]';
	return $matches[0];
}

/**
 *   convertFontXHTML
 *   Analyse et corrige le code correspondant aux balises <font> envoyé par l'éditeur wysiwyg ou non (IE concerné uniquement)
 *   @param  $matches  array  le tableau contenant l'ensemble des motifs capturés par l'expression régulière
 */
function convertFontXHTML($matches)
{
    if (WYSIWYG) { //WYSIWYG
		switch (BROWSER) {
			case 'IE' :
				$bgcolor = !empty($matches[1])? str_replace(array('style="BACKGROUND-COLOR','"'), array('background-color',''), $matches[1]).';' : '';
				$color = !empty($matches[2])? str_replace('color=','color:', $matches[2]).';' : '';
				$matches[0] = '[span style="'.$color.$bgcolor.'"]'.$matches[3].'[/span]';
				break;

			case 'IE9' :
				$bgcolor = !empty($matches[1])? str_replace(array('style="background-color','"'), array('background-color',''), $matches[1]) : '';
				$color = !empty($matches[2])? str_replace(array('color="','"'), array('color:',''), $matches[2]).';' : '';
				$matches[0] = '[span style="'.$color.$bgcolor.'"]'.$matches[3].'[/span]';
				break;

			case 'Gecko' :
			case 'Opera' :
			case 'Safari' :
			default :
		}
	} else { //TEXTAREA
		// TODO
	}
    
	return $matches[0];
}

/**
 *   convertSpanXHTML
 *   Analyse et corrige le code correspondant aux balises <span> envoyé par l'éditeur wysiwyg ou non (IE concerné uniquement)
 *   @param  $matches  array  le tableau contenant l'ensemble des motifs capturés par l'expression régulière
 */
function convertSpanXHTML($matches)
{
	if (WYSIWYG) { //WYSIWYG
		switch (BROWSER) {
			case 'IE' :
				$matches[0] = '[span style="'.$matches[1].'"]'.$matches[2].'[/span]';
				break;

			case 'Gecko' :
			case 'Opera' :
			case 'Safari' :
			default :
		}
	} else { //TEXTAREA
		// TODO
	}
	return $matches[0];
}

/**
 *   convertListeXHTML
 *   Analyse et corrige le code correspondant aux listes (UL, OL) envoyé par l'éditeur wysiwyg ou non
 *   @param  $matches  array  le tableau contenant l'ensemble des motifs capturés par l'expression régulière
 */
function convertListeXHTML($matches)
{
	if (WYSIWYG) { //WYSIWYG
		switch (BROWSER) {
			case 'IE' :
				$matches[1] = strtolower($matches[1]);
				$matches[2] = str_replace('<LI>', '</LI><LI>', $matches[2]);	//correction bug IE 7			
				$matches[2] = preg_replace("`<LI>(.+)</LI>`sU", '[li]$1[/li]', $matches[2]);
				$matches[0] = '['.$matches[1].']'.$matches[2].'[/'.$matches[1].']';
				break;

			case 'IE9' :
				$matches[1] = strtolower($matches[1]);
				$matches[2] = preg_replace("`<li>(.+)</li>`sU", '[li]$1[/li]', $matches[2]);
				$matches[0] = '['.$matches[1].']'.$matches[2].'[/'.$matches[1].']';
				break;

			case 'Gecko' :
				$matches[3] = preg_replace("`<li( style=\"[-0-9a-iklnor-uwxy\:;, \(\)]+\")?>(.+)</li>`sU", '[li$1]$2[/li]', $matches[3]);
				$matches[0] = '['.$matches[1].$matches[2].']'.$matches[3].'[/'.$matches[1].']';
				break;

			case 'Opera' :
				$matches[1] = strtolower($matches[1]);
				$matches[2] = !empty($matches[2])? ' style="text-align:'.$matches[2].';"' : '';
				$matches[3] = str_replace('<LI align="','<LI style="text-align:', $matches[3]);
				$matches[3] = preg_replace("`<LI( style=\"text-align:(?:center|left|right)\")?>(.+)</LI>`isU", '[li$1]$2[/li]', $matches[3]);
				$matches[0] = '['.$matches[1].$matches[2].']'.$matches[3].'[/'.$matches[1].']';
				break;

			case 'Safari' :
				$matches[3] = preg_replace("`<li( style=\"[-0-9a-iklnor-uwxy\:;, \(\)]+\")?>(.+)</li>`sU", '[li$1]$2[/li]', $matches[3]);
				$matches[0] = '['.$matches[1].$matches[2].']'.$matches[3].'[/'.$matches[1].']';
				break;

			default :
		}
	} else { //TEXTAREA
		// TODO
	}
	return $matches[0];
}

/**
 *   convertBlockXHTML
 *   Analyse et corrige le code correspondant aux blocs (<div> et <p>) envoyé par l'éditeur wysiwyg ou non (IE concerné uniquement)
 *   @param  $matches  array  le tableau contenant l'ensemble des motifs capturés par l'expression régulière
 */
function convertBlockXHTML($matches)
{
	if (WYSIWYG) { //WYSIWYG
		switch (BROWSER) {
			case 'IE' :
            case 'IE9' :
            case 'Gecko' :
			case 'Opera' : // Modif compatibilité Opera 9.50
				$matches[1] = strtolower($matches[1]);
				$matches[2] = !empty($matches[2])? ' style="text-align:'.$matches[2].';"' : '';
				$matches[0] = '['.$matches[1].$matches[2].']'.$matches[3].'[/'.$matches[1].']';
				break;

			case 'Gecko' :
			//case 'Opera' :
			case 'Safari' :
			default :
		}
	} else { //TEXTAREA
		// TODO
	}
	return $matches[0];
}

/**
 *   convertTagXHTML
 *   Analyse et corrige le code correspondant aux listes (UL, OL) envoyé par l'éditeur wysiwyg ou non
 *   @param  $in       string (array)  motif de capture de l'expression régulière
 *   @param  $out      string (array)  motif de remplacement de l'expression régulière
 *   @param  $content  string          chaine à analyser
 */
function convertTagXHTML($in, $out, $content)
{
	if (WYSIWYG) { //WYSIWYG
		switch (BROWSER) {
			case 'IE' :
            case 'IE9' :
				while (preg_match($in, $content)) {
					$content = preg_replace_callback($in, $out, $content);
				}
				break;

			case 'Gecko' :
			case 'Opera' :
			case 'Safari' :
            case 'IE9' :
				while (preg_match($in, $content)) {
					$content = preg_replace($in, $out, $content);
				}
				break;

			default :
		}
	} else { //TEXTAREA
		while (preg_match($in, $content)) {
			$content = preg_replace($in, $out, $content);
		}
	}
	return $content;
}

/**************************************************************************************
*   UNPARSER XHTML POUR POSTGUEST EDIT0R
***************************************************************************************/

/**
 *   unparseCodePGEditor
 *   Analyse et corrige le code pour être affiché dans l'éditeur wysiwyg ou non
 *   @param  $content  string  le contenu du code à afficher
 */
function unparseCodePGEditor($content)
{
	if (WYSIWYG) {
		$content = (JAVASCRIPT)? unparseCodePGEditorWIW($content) : unparseCodePGEditorTA($content);
	} else {
		$content = unparseCodePGEditorTA($content);
	}

	return $content;
}

/**
 *   unparseCodePGEditorWIW
 *   Analyse et corrige le code pour être affiché dans l'éditeur wysiwyg
 *   @param  $content  string  le contenu du code à afficher
 */
function unparseCodePGEditorWIW($content)
{
	global $lang_pgeditor;
	switch (BROWSER) {
		case 'IE' :
        case 'IE9' :
			$content = preg_replace_callback("`<img src=\"([^\"]+)\"[^>]*/?>`i",'unparseImgXHTML', $content);
			break;
			
		case 'Gecko' :
			$content = preg_replace_callback("`<img src=\"([^\"]+)\"[^>]*/?>`i",'unparseImgXHTML', $content);
			break;
			
		case 'Opera' :
			$content = preg_replace_callback("`<img src=\"([^\"]+)\"[^>]*/?>`i",'unparseImgXHTML', $content);
			$content = convertTagXHTML("`<SPAN STYLE=(?:'|\")color:#([0-9abcdefABCDEF]{6});?(?:'|\")>(.+)</SPAN>`isU",'<FONT color="#$1">$2</FONT>', $content);	// Modif compatibilité Opera 9.50
			break;
					
		case 'Safari' :
			$content = preg_replace_callback("`<img src=\"([^\"]+)\"[^>]*/?>`i",'unparseImgXHTML', $content);
			break;

		default :
			$content = '';
	}

	return $content;
}

/**
 * unparseImgXHTML
 * Analyse et corrige le code correspondant aux images externes affiché dans l'éditeur wysiwyg ou non
 * @param  $matches  array  le tableau contenant l'ensemble des motifs capturés par l'expression régulière
 * @return string
 * @access private
 */
function unparseImgXHTML($matches)
{
	if (WYSIWYG) { //WYSIWYG
		switch (BROWSER) {
			case 'IE' :
            case 'IE9' :
			case 'Gecko' :
			case 'Opera' :
			case 'Safari' :
				if ( strpos($matches[1], 'http://') !== 0 ) {
					$matches[1] = BASEPATH.$matches[1];
				}
				$matches[0] = '<img src="'.$matches[1].'">';
				break;

			default :
		}
	} else { //TEXTAREA
		// TODO
	}
	return $matches[0];
}


/**
 *   unparseCodePGEditorTA
 *   Analyse et corrige le code pour être affiché dans l'éditeur NON wysiwyg (textarea)
 *   @param  $content  string  le contenu du code à afficher
 */
function unparseCodePGEditorTA($content)
{
	// TODO
	return FALSE;
}
?>
