<?php
/*
    Admin functions file - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
	v4.6.0 (06 December 2004)  : initial release by Djchouix
	v4.6.8 (24 May 2008)       : corrected change \ (by jchouix)
	v4.6.10 (7 September 2009)       : corrected #267 #287 (by jchouix)
*/
if (stristr($_SERVER["SCRIPT_NAME"], "function.php")) {
  header("location:../index.php");
  die();
}

//Fonction Transformation chemin relatif --> chemin absolu pour images et liens
function PathRelativeAbsolute($chaine) {
	return $chaine;
}

//Fonction Transformation chemin absolu --> chemin relatif pour images et liens
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

/**
 * FCKeditor
 * Affiche l'�diteur FCKEditor
 * @param string $name Nom de l'�diteur FCKEditor
 * @param string $path Chemin relatif du r�pertoire contenant l'�diteur
 * @param string $width Largeur de l'�diteur FCKEditor
 * @param string $height Hauteur de l'�diteur FCKEditor
 * @param string $value Contenu de l'�diteur FCKEditor
 * @param string $toolbarname Nom de la barre d'outil de l'�diteur FCKEditor
 * @param string $pathDirMinieditor Chemin relatif du r�pertoire contenant le minieditor 
 * @return string
 */
function FCKeditor($name, $path, $width, $height, $value, $toolbarname, $pathDirMinieditor)
{
	global $site, $lng;

	// Editeur
	echo '<div style="text-align:center;">';
	$oFCKeditor1 = new FCKeditor($name) ;
	$oFCKeditor1 -> BasePath = $site[3].$path;
	$oFCKeditor1 -> Width	= $width;
	$oFCKeditor1 -> Height = $height;
	$oFCKeditor1 -> Value = $value;
	$oFCKeditor1 -> Config['BaseHref'] = $site[3];
	$oFCKeditor1 -> Config['CustomConfigurationsPath'] = $site[3].$pathDirMinieditor.'fckeditor_config/guppy_fckconfig.js';
	$oFCKeditor1 -> Config['EditorAreaCSS'] = $site[3].$pathDirMinieditor.'fckeditor_config/custom/guppy_fckeditorarea.css';
	$oFCKeditor1 -> Config["AutoDetectLanguage"] = is_file(CHEMIN.'inc/fckeditor/editor/lang/'.$lng.'.js')? false : true;
	$oFCKeditor1 -> Config['DefaultLanguage'] = is_file(CHEMIN.'inc/fckeditor/editor/lang/'.$lng.'.js')? $lng : 'en';	
	$oFCKeditor1 -> Config['StylesXmlPath'] = $site[3].$pathDirMinieditor.'fckeditor_config/custom/guppy_fckstyles.xml';
	$oFCKeditor1->Config['TemplatesXmlPath'] = $site[3].$pathDirMinieditor.'fckeditor_config/custom/guppy_fcktemplates.xml';
	$oFCKeditor1 -> Config['SkinPath'] = $site[3].$pathDirMinieditor.'fckeditor_config/custom/skin_guppy/';
	$oFCKeditor1 -> ToolbarSet = $toolbarname;
	$oFCKeditor1 -> Config['SmileyPath'] = $site[3].'img/smileys/';
	$oFCKeditor1 -> Config['ImageBrowserURL'] = $site[3].$pathDirMinieditor.'upload/upload.php?lng='.$lng.'&uptype=Image&namerepconfig=fckeditor_config&pathconfig='.$pathDirMinieditor; //r�cup�ration du r�pertoire img et photo de guppy
	$oFCKeditor1 -> Config['LinkBrowserURL'] = $site[3].$pathDirMinieditor.'upload/upload.php?lng='.$lng.'&uptype=Link&namerepconfig=fckeditor_config&pathconfig='.$pathDirMinieditor ; //r�cup�ration du r�pertoire file, img, photo, pages et flash de guppy
	$oFCKeditor1 -> Config['FlashBrowserURL'] = $site[3].$pathDirMinieditor.'upload/upload.php?lng='.$lng.'&uptype=Flash&namerepconfig=fckeditor_config&pathconfig='.$pathDirMinieditor; //r�cup�ration du r�pertoire flash de guppy

	$oFCKeditor1 -> Create() ;
	echo '</div>';
	
	// Smileys
    echo '<div style="text-align:center; margin-top:10px;">'.FCK_addGuppySmileys($name).'</div>'."\n";
}

// Chemin du r�pertoire contenant les smileys de guppy
define('PATH_GUPPYSMILEY', 'inc/img/smileys/');	

/**
 * FCK_addGuppySmileys
 * Affiche les smileys de guppy pour �tre int�grer dans l'�diteur FCKEditor
 * @param string $name Nom de l'�diteur FCKEditor
 * @return string
 */
function FCK_addGuppySmileys($name)
{
	$smileyGuppy = array('cool', 'wink', 'biggrin', 'smile', 'frown', 'eek', 'mad', 'confused', 'rolleyes', 'tongue', 'cry');
	$html = '';
	for ($i = 0; $i < count($smileyGuppy); $i++) {
		$smileyPath = CHEMIN.PATH_GUPPYSMILEY.$smileyGuppy[$i].'.gif';
		if (is_file($smileyPath)) { 
			$imgSize = getimagesize($smileyPath);
			$html .= '<img class="icon" src="'.$smileyPath.'" '.$imgSize[3].' alt="'.$smileyGuppy[$i].'" title="'.$smileyGuppy[$i].'" onclick="insertSmiley(\''.$name.'\', \''.PATH_GUPPYSMILEY.$smileyGuppy[$i].'.gif\', \''.$smileyGuppy[$i].'\', \''.$imgSize[0].'\', \''.$imgSize[1].'\');" onmouseover="this.className=\'icon_hover\'" onmouseout="this.className=\'icon_out\'" />'."\n";
		}
	}
	return $html;
}


// Ajout de la fonction javascript qui permet d'ins�rer un smiley dans l'�diteur FCKEditor 
$headinc .= '<script type="text/javascript">
function insertSmiley(instanceName, src, alt, width, height)
{
	var oEditor = FCKeditorAPI.GetInstance(instanceName);
	
	if (oEditor.EditMode == FCK_EDITMODE_WYSIWYG) {
		oImg = oEditor.CreateElement( "IMG" );
		oImg.src = src ;
		oImg.setAttribute("_fcksavedurl", src) ;
		oImg.alt = alt;
		oImg.title = alt;
		oImg.width = width;
		oImg.height = height;
		oImg.border = 0;
	} else {
		return false;
	}
};
</script>
';


/**
 * ReplaceHTMLEntities
 * Permet de conserver l'affichage de quelques entit�s HTML dans le textarea du minieditor
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

	$str = str_replace($in, $out, $str);

	return $str;
}
?>
