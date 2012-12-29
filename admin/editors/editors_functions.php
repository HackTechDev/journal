<?php
/*
    Editors functions file - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
	v4.6.14 (06 December 2004)  : initial release by jchouix
	v4.6.17 (21 October 2011)   : added ck editor by jchouix
	v4.6.22 (29 December 2012)  : deleted fck editor by Saxbar
*/
if (stristr($_SERVER["SCRIPT_NAME"], "editors_functions.php")) {
  header("location:../index.php");
  die();
}

/**
 * Affiche l'�diteur dans la partie administration 
 * 
 * @param string  $name    Nom de l'�diteur
 * @param string  $width   Largeur de l'�diteur (voir fichier de condif)
 * @param string  $height  Hauteur de l'�diteur
 * @param string  $content Contenu de l'�diteur
 * @param boolean $wysiwyg Editeur wysiwyg (true) ou non (false)
 * @param array   $params  Param�tres optionnels
 * @return string
 */
function display_admin_editor($name, $width, $height, $content, $wysiwyg = TRUE, $params = array())
{
    $path_editors = 'admin/editors/';
    
    if ($wysiwyg) {
        WYSIWYG_admin_editor($name, $width, $height, $content, $params, $path_editors);
    } else {
        TEXTAREA_admin_editor($name, $width, $height, $content, $params, $path_editors);   
    }
}

// --------------------------------------------------------------------

/**
 * Affiche un �diteur WYSIWYG 
 * 
 * @param string $name Nom de l'�diteur
 * @param string $width Largeur de l'�diteur (voir fichier de condif)
 * @param string $height Hauteur de l'�diteur
 * @param string $value Contenu de l'�diteur
 * @param 
 * @return string
 */
function WYSIWYG_admin_editor($name, $width, $height, $value, $params = array(), $path_editors = '')
{
    settype($params, 'array');
    
    /**
     * Editeur CKEditor
     */
    if (is_file(CHEMIN.'inc/ckeditor/ckeditor.php'))
    {
        require_once CHEMIN.'inc/ckeditor/ckeditor.php';
        
        $path = 'inc/ckeditor/';
        $toolbarName = empty($params['toolbarName'])? 'Guppy_in' : $params['toolbarName'];
     
        return CKeditor($name, $path, $width, $height, $value, $toolbarName, $path_editors);
    }
    //
    
    return FALSE;   
}

// --------------------------------------------------------------------

/**
 * Affiche un �diteur NON WYSIWYG 
 * 
 * @param string $name Nom de l'�diteur
 * @param string $width Largeur de l'�diteur (voir fichier de condif)
 * @param string $height Hauteur de l'�diteur
 * @param string $value Contenu de l'�diteur
 * @return string
 */
function TEXTAREA_admin_editor($name, $width, $height, $value, $params = array(), $path_editors = '')
{    
	global 	$site,$pathDirMinieditor,$serviz,$lng,$lang_minieditor,$titre,$texte,$bordure,
			$typeFONT,$sizeFONT,$baliseHTML,$classCSS,$targetURL,$alignIMG,$baliseBonus,$colorTextTextarea,$colorFondTextarea,
			$colorFondMenu,$colorFondMenuOver,$colorTextTitre,$colorFondTitre,$tagBeginMinieditor,$tagEndMinieditor,
			$colorTextCorp,$colorFondCorp,$styleBordureCorp,$path_minieditortextarea_config,$pathFilesMinieditor,$IEPopupColor,
			$minieditorStyleMenu,$minieditorStyleSelect,$minieditorStyleTextarea,$minieditorStyleSmiley,$minieditorStyleImgSmiley,$minieditorStyleBR,
			$useTagSPAN;

    $pathMinieditor = $path_editors.'minieditortextarea/minieditortextarea.inc';
    
    if (is_file(CHEMIN.$pathMinieditor))
    {
    	static $editor_id = 1;

//        $path_minieditortextarea_config = $path_editors.'minieditortextarea/';
		$path_minieditortextarea_config ='admin/editors/guppy_config/';
        require_once CHEMIN.$pathMinieditor;

        $formName = empty($params['formName'])? 'adminsend' : $params['formName'];
        $value = ReplaceHTMLEntities($value);
        
        MiniEditorTextarea($editor_id, $formName, $name, $width, $height, $value);
        
        $editor_id++;
    }
    
    return FALSE;   
}

// --------------------------------------------------------------------

/**
 * Affiche l'�diteur WYSIWYG CKEditor
 * 
 * @param string $name Nom de l'�diteur
 * @param string $path Chemin relatif du r�pertoire contenant l'�diteur
 * @param string $width Largeur de l'�diteur (voir fichier de condif)
 * @param string $height Hauteur de l'�diteur
 * @param string $value Contenu de l'�diteur
 * @param string $toolbarname Nom de la barre d'outil de l'�diteur
 * @param string $pathDirMinieditor Chemin relatif du r�pertoire contenant la configuration de l'�diteur
 * @return string
 */
function CKeditor($name, $path, $width, $height, $value, $toolbarname, $pathDirMinieditor)
{
	global $site, $lng;

	/**
     * Cr�ation de l'�diteur
     */
	$oCKeditor = new CKeditor() ;
	$oCKeditor -> basePath = $site[3].$path;
//    $oCKeditor -> config['width'] = (strpos($_SERVER['HTTP_USER_AGENT'], "WebKit") !== false)? '577px' : $width;   // Correction bug avec Safari et Chrome
    $oCKeditor -> config['width'] = $width;
	$oCKeditor -> config['height'] = $height;
	$oCKeditor -> config['baseHref'] = $site[3];
	$oCKeditor -> config['customConfig'] = $site[3].$pathDirMinieditor.'ckeditor_config/guppy_ckconfig.js';
	$oCKeditor -> config['contentsCss'] = $site[3].$pathDirMinieditor.'ckeditor_config/custom/guppy_contents.css';
	$oCKeditor -> config['language'] = is_file(CHEMIN.'inc/ckeditor/lang/'.$lng.'.js')? $lng : 'en';	
	$oCKeditor -> config['toolbar'] = $toolbarname;
	$oCKeditor -> config['smiley_path'] = $site[3].'img/smileys/';
	$oCKeditor -> config['filebrowserBrowseUrl'] = $site[3].$pathDirMinieditor.'upload/upload.php?lng='.$lng.'&uptype=Link&namerepconfig=ckeditor_config&pathconfig='.$pathDirMinieditor ; //r�cup�ration du r�pertoire file, img, photo, pages et flash de guppy
	$oCKeditor -> config['filebrowserImageBrowseUrl'] = $site[3].$pathDirMinieditor.'upload/upload.php?lng='.$lng.'&uptype=Image&namerepconfig=ckeditor_config&pathconfig='.$pathDirMinieditor; //r�cup�ration du r�pertoire img et photo de guppy
	$oCKeditor -> config['filebrowserImageBrowseLinkUrl'] = $site[3].$pathDirMinieditor.'upload/upload.php?lng='.$lng.'&uptype=Link&namerepconfig=ckeditor_config&pathconfig='.$pathDirMinieditor ; //r�cup�ration du r�pertoire file, img, photo, pages et flash de guppy
	$oCKeditor -> config['filebrowserFlashBrowseUrl'] = $site[3].$pathDirMinieditor.'upload/upload.php?lng='.$lng.'&uptype=Flash&namerepconfig=ckeditor_config&pathconfig='.$pathDirMinieditor; //r�cup�ration du r�pertoire flash de guppy
    //
    
    // Affichage de l'�diteur
    echo '<div style="text-align:center;">'.$oCKeditor -> editor($name, $value).'</div>';
	//
    
	// Affichage de la barre de smileys pour l'�diteur
    echo get_toolbar_guppy_smileys($name);    
}

// --------------------------------------------------------------------

/**
 * D�fini le chemin du r�pertoire contenant les smileys de guppy
 */
define('PATH_GUPPYSMILEY', 'inc/img/smileys/');	

// --------------------------------------------------------------------

/**
 * Retourne la barre de smileys de guppy pour �tre int�grer dans l'�diteur
 * 
 * @param string Nom de l'�diteur
 * @return string
 */
function get_toolbar_guppy_smileys($name)
{
	$smileyGuppy = array('cool', 'wink', 'biggrin', 'smile', 'frown', 'eek', 'mad', 'confused', 'rolleyes', 'tongue', 'cry');
	
    $html = '<div class="guppy_smileys" style="text-align:center; margin-top:10px;">';
    
	for ($i = 0; $i < count($smileyGuppy); $i++) {
		$smileyPath = CHEMIN.PATH_GUPPYSMILEY.$smileyGuppy[$i].'.gif';
		if (is_file($smileyPath)) { 
			$imgSize = getimagesize($smileyPath);
			$html .= '<img class="icon" src="'.$smileyPath.'" '.$imgSize[3].' alt="'.$smileyGuppy[$i].'" title="'.$smileyGuppy[$i].'" onclick="insert_smiley_in_editor(\''.$name.'\', \''.PATH_GUPPYSMILEY.$smileyGuppy[$i].'.gif\', \''.$smileyGuppy[$i].'\', \''.$imgSize[0].'\', \''.$imgSize[1].'\');" onmouseover="this.className=\'icon_hover\'" onmouseout="this.className=\'icon_out\'" />'."\n";
		}
	}
    
    $html .= '</div>';
    
	return $html;
}

// --------------------------------------------------------------------

/**
 * Ins�re les fonctions javascripts n�cessaires pour les �diteurs
 */ 
$headinc .= '<script type="text/javascript" src="'.CHEMIN.'admin/editors/editors_scripts.js"></script>';

// --------------------------------------------------------------------

/**
 * Transforme un chemin relatif en chemin absolu pour images et liens
 * (fonction obsol�te)
 */ 
function PathRelativeAbsolute($chaine) {
	return $chaine;
}

// --------------------------------------------------------------------

/**
 * Transforme un chemin absolu en chemin relatif pour images et liens
 */
function PathAbsoluteRelative($chaine)
{
	global $site;

	$str = $chaine;
	
	$in = array(
				'\\',
				'<p>&nbsp;</p>',
				'<br type="_moz" />',
				'<u>',
				'</u>',
				'style="TEXT-DECORATION: underline"',
				'="'.$site[3]
	);
	$out = array(
				'',
				'<br />',
				'',
				'<span style="text-decoration:underline;">',
				'</span>',
				'style="text-decoration: underline;"',
				'="'
	);

	$str = str_replace($in, $out, $str);
	$str = preg_replace("` src=\"(?:\.\.\/)+`", ' src="', $str);
	$str = preg_replace('`(<br />|&#160;)$`', '', $str);
	
	return $str;
}

// --------------------------------------------------------------------

/**
 * Permet de conserver l'affichage de quelques entit�s HTML dans le textarea du minieditor
 * 
 * @param $chaine string contient la chaine � traiter
 * @return string chaine trait�e
 */
function ReplaceHTMLEntities($chaine)
{
	$str = $chaine;
    
	$in = array(
		'&amp;',
		'&',
		'&amp;amp;lt;',
		'&amp;amp;gt;',
		'&amp;amp;nbsp;',
		'&amp;amp;#'
	);

	$out = array(
		'&',
		'&amp;amp;',
		'&amp;lt;',
		'&amp;gt;',
		'&amp;nbsp;',
		'&amp;#'
	);

	return empty($str)? $str : str_replace($in, $out, $str);
}

// --------------------------------------------------------------------
