<?php
/*
     MinieditorTextarea r?is?ar Djchouix - Licence CeCILL
     Web site = http://lebrikabrak.free.fr/
     e-mail   = lebrikabrak@free.fr
	 version 1.6.4 (10/01/2008) compatibilit?vec guppy v4.6.x
     v4.6.10 (7 September 2009)    : corrected #272
     v4.6.22 (29 December 2012)    : corrected for ck editor (by Saxbar) 
*/
if (stristr($_SERVER["SCRIPT_NAME"], "minieditortextarea.inc")) {
  header("location:../index.php");
  die();
}

$pathDirMinieditor = 'admin/editors/';    //chemin relatif du répertoire du miniéditeur (ne pas modifier pour ne pas perdre la compatibilité avec les autres plugins)
//CONFIGURATION MINIEDITEUR
if(file_exists(CHEMIN.$pathDirMinieditor.'minieditortextarea/minieditortextarea_config.inc')) {
	include(CHEMIN.$pathDirMinieditor.'minieditortextarea/minieditortextarea_config.inc');  //CONFIGURATION MINIEDITEUR PAR DEFAUT
} else {
	die('Une erreur est survenue car il manque le ficher "'.$pathDirMinieditor.'minieditortextarea/minieditortextarea_config.inc "');
}
if(isset($path_minieditortextarea_config) && $path_minieditortextarea_config != '' && preg_match("!^[-a-z0-9_]{1}[-a-z0-9_\/]*\/$!i",$path_minieditortextarea_config) && file_exists(CHEMIN.$path_minieditortextarea_config.'minieditortextarea_config.inc')) {
	include(CHEMIN.$path_minieditortextarea_config.'minieditortextarea_config.inc');
}

//FICHIER DE LANGUE
if(!preg_match("!^[a-z]{2,3}$!i",$lng)) die("Erreur dans le nom de la variable de langue!!");
if(file_exists(CHEMIN.$pathDirMinieditor.'minieditortextarea/lang/'.$lng.'_minieditortextarea.inc')) {
	include(CHEMIN.$pathDirMinieditor.'minieditortextarea/lang/'.$lng.'_minieditortextarea.inc');
} else {
	include(CHEMIN.$pathDirMinieditor.'minieditortextarea/lang/en_minieditortextarea.inc'); // fichier de langue par d?ut
}
//DETECTION NAVIGATEUR COMPATIBLE MINIEDITOR
function detectBrowser_Minieditor()
{
	$userAgent = $_SERVER['HTTP_USER_AGENT'];
	if (strpos($userAgent, 'MSIE 6.0') !== false && strpos($userAgent, 'compatible') !== false && strpos($userAgent, 'Opera') === false && strpos($userAgent, 'mac') === false && strpos($userAgent, 'Gecko') === false && strpos($userAgent, 'Konqueror') === false && strpos($userAgent, 'Safari') === false) {
		return 'IE6';	
	} elseif (strpos($userAgent, 'MSIE') !== false && strpos($userAgent, 'compatible') !== false && strpos($userAgent, 'Opera') === false && strpos($userAgent, 'mac') === false && strpos($userAgent, 'Gecko') === false && strpos($userAgent, 'Konqueror') === false && strpos($userAgent, 'Safari') === false) {
		return 'IE';
	} elseif (strpos($userAgent, 'Gecko') !== false && strpos($userAgent, 'Opera') === false && strpos($userAgent, 'Konqueror') === false && strpos($userAgent, 'Safari') === false) {
		return 'Gecko';
	} elseif (strpos($userAgent, 'Opera') !== false) {
		return 'Opera';
	} elseif (strpos($userAgent, 'Konqueror') !== false) {
  		return 'Konqueror';
	} elseif (strpos($userAgent, 'Safari') !== false) {
  		return 'Safari';
	} else {
  		return 'KO';
	}
}
define('BROWSER_MINIEDITOR', detectBrowser_Minieditor());
//$browserMinieditor = BROWSER_MINIEDITOR;

// DETECTION NAVIGATEUR COMPATIBLE CKEDITOR
function detectBrowserWIW_FCK()
{
	$userAgent = $_SERVER['HTTP_USER_AGENT'];
	
	switch (BROWSER_MINIEDITOR) {
		case 'IE' :
		case 'IE6' :
			$version = (float)substr($userAgent, strpos($userAgent, 'MSIE') + 5, 3);
			return ($version >= 5.5)? true : false;
			break;

		case 'Gecko' :
			$version = (int)substr($userAgent, strpos($userAgent, 'Gecko/') + 6, 8);
			return ($version >= 20030210)? true : false;
			break;

		case 'Opera' :
			$version = (float)substr($userAgent, strpos($userAgent, 'Opera/') + 6, 3);
			return ($version >= 9.5)? true : false;
			break;

		case 'Safari' :
			$version = (int)substr($userAgent, strpos($userAgent, 'WebKit/') + 7, 3);
			print_r($version);
			return ($version >= 523)? true : false;

		case 'Konqueror' :
			return false;
			
		default :
			return false;
	}
}
define('BROWSER_FCK', detectBrowserWIW_FCK());

//VARIABLE NB CARACTERE TEXTE SELECTION (NECESSAIRE OPERA 8)
if (in_array(BROWSER_MINIEDITOR, array('IE6', 'IE', 'Opera'))) {
	echo '<input type="hidden" id="nb_caract" name="nb_caract" value="" />'."\n";
	echo '<input type="hidden" id="pos_cursor" name="pos_cursor" value="" />'."\n";
}

//COMPATIBILITE AFFICHAGE ICONES MINIEDITOR
function tagBeginMinieditor($nameImgMenu,$alt)
{
	global $pathDirMinieditor;
	
	if (BROWSER_MINIEDITOR == 'IE6') {	
		$tagBegin = '<img src="'.CHEMIN.$pathDirMinieditor.'minieditortextarea/img/'.$nameImgMenu.'.gif" alt="'.$alt.'" ';
	} elseif(in_array(BROWSER_MINIEDITOR, array('IE', 'Gecko', 'Opera'))) {   //compatibilité, MOZILLA et OPERA 8
		$tagBegin = '<input type="button" value="" ';
	} else {  //compatibilité KONQUEROR (ET LES AUTRES A TESTER)
		$tagBegin = '<div ';
	}
	return $tagBegin;
}

function tagEndMinieditor() {
	global $pathDirMinieditor;
	
	if (BROWSER_MINIEDITOR == 'IE6') {
		$tagEnd = ' />'."\n";
	} elseif(in_array(BROWSER_MINIEDITOR, array('IE', 'Gecko', 'Opera'))) {   //compatibilité, MOZILLA et OPERA 8
		$tagEnd = ' />'."\n";
	} else {  //compatibilité KONQUEROR (ET LES AUTRES A TESTER)
		$tagEnd = '></div>'."\n";
	}
	return $tagEnd;
}

//COMPATIBILITE AFFICHAGE POPUP COLOR MINIEDITOR
$IEPopupColor = ((BROWSER_MINIEDITOR == "IE6") || (BROWSER_MINIEDITOR == "IE")) ? 'IE' : '';

//INSERTION FONCTIONS JAVASCRIPT
if(file_exists(CHEMIN.$pathDirMinieditor.'minieditortextarea/jscript.inc')) {
   	include(CHEMIN.$pathDirMinieditor.'minieditortextarea/jscript.inc');
} else {
	die('Une erreur est survenue car il manque le fichier jscript dans le r?rtoire '.$pathDirMinieditor.'minieditortextarea/');
}
//STYLE CSS DU MINIEDITEUR
$minieditorStyleMenu = 'text-align:left; margin-left:auto; margin-right:auto; padding-left:5px; padding-bottom:5px; background-color:'.$colorFondMenu.';';

function minieditorStyleIcon($posWidth,$posHeight,$width='21px',$height='21px')
{
	global $site,$pathFilesMinieditor;
	
	if(BROWSER_MINIEDITOR == "IE6") {
		$margin = ($width=='25px')? 'margin-right:2px' :'';
		$StyleIcon = 'border:none; cursor:pointer; background-color:transparent; width:21px; height:21px; vertical-align:middle; margin-top:5px;'.$margin;
	} elseif(!in_array(BROWSER_MINIEDITOR, array('IE', 'Gecko', 'Opera'))) { // compatibilite Konqueror (safari a tester)
		$StyleIcon .= 'border:none; cursor:pointer; background-color:transparent; width:'.$width.'; height:'.$height.'; vertical-align:middle;background-position:'.$posWidth.' '.$posHeight.'; background-image:url(\''.$site[3].$pathFilesMinieditor.'minieditortextarea/img/minieditortextarea.gif\'); background-repeat: no-repeat; float:left; margin-bottom:5px; margin-top:3px;';
	} else {
		$StyleIcon .= 'border:none; cursor:pointer; background-color:transparent; width:'.$width.'; height:'.$height.'; vertical-align:middle;background-position:'.$posWidth.' '.$posHeight.'; background-image:url(\''.$site[3].$pathFilesMinieditor.'minieditortextarea/img/minieditortextarea.gif\'); background-repeat: no-repeat; margin-top:5px;';
	}
	return $StyleIcon;
}

$minieditorStyleSelect = 'cursor:pointer; vertical-align:middle; margin-top:4px; margin-bottom:0px; ';
if(!in_array(BROWSER_MINIEDITOR, array('IE6', 'IE', 'Gecko', 'Opera'))) { // compatibilite Konqueror (safari a tester)
	$minieditorStyleSelect .= 'float:left;height:21px;margin-right:5px;'."\n";
}

$minieditorStyleTextarea = 'margin-top:0px; color:'.$colorTextTextarea.'; background-color:'.$colorFondTextarea.';';

$minieditorStyleSmiley = 'text-align:center; padding-top:5px; padding-bottom:5px; margin-left:auto; margin-right:auto;';

$minieditorStyleImgSmiley = 'vertical-align:middle; cursor:pointer;';

if(!in_array(BROWSER_MINIEDITOR, array('IE6', 'IE', 'Gecko', 'Opera'))) { // compatibilite Konqueror (safari a tester)
	$minieditorStyleBR = ' style="clear:left;"';
} else {
	$minieditorStyleBR = '';
}
//INSERTION IMAGE POUR MISE EN CACHE (NECESSAIRE POUR IE)
echo '<div style="display:none;"><img src="'.$site[3].$pathDirMinieditor.'minieditortextarea/img/minieditortextarea.gif" alt="" width="210" height="84" border="0" /></div>';

///////////////////////////////////////////////////////////////
/////////////FONCTION MINIEDITEUR///////////////////////////////
///////////////////////////////////////////////////////////////

function MiniEditorTextarea($numbertextarea,$nameform,$nametextarea,$widthtextarea,$heightextarea,$fieldtextarea){
	global 	$site,$pathDirMinieditor,$serviz,$lng,$lang_minieditor,
			$typeFONT,$sizeFONT,$baliseHTML,$classCSS,$targetURL,$alignIMG,$baliseBonus,$colorTextTextarea,$colorFondTextarea,
			$colorFondMenu,$colorFondMenuOver,$colorTextTitre,$colorFondTitre,$tagBeginMinieditor,$tagEndMinieditor,
			$colorTextCorp,$colorFondCorp,$styleBordureCorp,$path_minieditortextarea_config,$pathFilesMinieditor,$IEPopupColor,
			$minieditorStyleMenu,$minieditorStyleSelect,$minieditorStyleTextarea,$minieditorStyleSmiley,$minieditorStyleImgSmiley,$minieditorStyleBR;

	//FONCTION JAVASCRIPT UNDO ET REDO
?>
	<script type="text/javascript">
		var textareaValue<?php echo $numbertextarea; ?> = new Array();
		var nbTextareaValue<?php echo $numbertextarea; ?> = 0;
		var rangTextareaValue<?php echo $numbertextarea; ?> = 0;

		function recupTextareaValue<?php echo $numbertextarea; ?>(nameform,nametextarea) {
			nbTextareaValue<?php echo $numbertextarea; ?> = textareaValue<?php echo $numbertextarea; ?>.length;
			if(document.forms[nameform].elements[nametextarea].value != textareaValue<?php echo $numbertextarea; ?>[nbTextareaValue<?php echo $numbertextarea; ?>-1]) {
				textareaValue<?php echo $numbertextarea; ?>.push(document.forms[nameform].elements[nametextarea].value);
				nbTextareaValue<?php echo $numbertextarea; ?> = textareaValue<?php echo $numbertextarea; ?>.length;
				rangTextareaValue<?php echo $numbertextarea; ?> = nbTextareaValue<?php echo $numbertextarea; ?>;
			}
		}

		function Undo<?php echo $numbertextarea; ?>(nameform,nametextarea) {
			if(textareaValue<?php echo $numbertextarea; ?>[rangTextareaValue<?php echo $numbertextarea; ?>-1] != undefined) {
				document.forms[nameform].elements[nametextarea].value = textareaValue<?php echo $numbertextarea; ?>[rangTextareaValue<?php echo $numbertextarea; ?>-1];
				if(rangTextareaValue<?php echo $numbertextarea; ?> == nbTextareaValue<?php echo $numbertextarea; ?>) {
					rangTextareaValue<?php echo $numbertextarea; ?> = nbTextareaValue<?php echo $numbertextarea; ?>-1;
				} else {
					rangTextareaValue<?php echo $numbertextarea; ?> = rangTextareaValue<?php echo $numbertextarea; ?>-1;
				}
			} else {
				return false;
			}
 		}

		function Redo<?php echo $numbertextarea; ?>(nameform,nametextarea) {
			if(textareaValue<?php echo $numbertextarea; ?>[rangTextareaValue<?php echo $numbertextarea; ?>+1] != undefined) {
				document.forms[nameform].elements[nametextarea].value = textareaValue<?php echo $numbertextarea; ?>[rangTextareaValue<?php echo $numbertextarea; ?>+1];
				rangTextareaValue<?php echo $numbertextarea; ?> = rangTextareaValue<?php echo $numbertextarea; ?>+1;
			} else {
				return false;
			}
		}
	</script>
<?php
    //MENU DU MINIEDITEUR
		echo '<div style="text-align:center;">'."\n";
		echo '<div style="width:'.$widthtextarea.';'.$minieditorStyleMenu.'">'."\n";
		echo tagBeginMinieditor('newpage',$lang_minieditor[2]).' id="button'.$numbertextarea.'1" title="'.$lang_minieditor[2].'" style="'.minieditorStyleIcon('-21px','-42px').'" onmouseover="MouseOverFile(\'button'.$numbertextarea.'1\',\''.$colorFondMenuOver.'\');" onmouseout="MouseOverFile(\'button'.$numbertextarea.'1\',\'transparent\');" onclick="NewPage(\''.$nameform.'\',\''.$nametextarea.'\'); recupTextareaValue'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');"'.tagEndMinieditor();  //NOUVELLE PAGE
		//MENU POLICE
		echo '<select name="Font'.$numbertextarea.'" size="1" style="width:95px;'.$minieditorStyleSelect.'" onchange="AddFont(\'Font'.$numbertextarea.'\',\''.$nameform.'\',\''.$nametextarea.'\');">'."\n";
		echo '<option value="" selected="selected">'.$lang_minieditor[3].'</option>'."\n";
		for ($i = 0; $i < count($typeFONT); $i++) {
			echo '<option value="font-family:'.$typeFONT[$i].'">'.$typeFONT[$i].'</option>'."\n";
		}
		echo '</select>'."\n";
		//MENU TAILLE
		echo '<select name="Size'.$numbertextarea.'" size="1" style="width:85px;'.$minieditorStyleSelect.'" onchange="AddFont(\'Size'.$numbertextarea.'\',\''.$nameform.'\',\''.$nametextarea.'\');">'."\n";
		echo '<option value="" selected="selected">'.$lang_minieditor[4].'</option>'."\n";
		for ($i = 0; $i < count($sizeFONT); $i++) {
			echo '<option value="font-size:'.$sizeFONT[$i].'">'.$sizeFONT[$i].'</option>'."\n";
		}
		echo '</select>'."\n";
		//ICONES
		echo tagBeginMinieditor('textcolor',$lang_minieditor[5]).' id="button'.$numbertextarea.'2" title="'.$lang_minieditor[5].'" style="'.minieditorStyleIcon('-147px','0px').'" onmouseover="MouseOverFile(\'button'.$numbertextarea.'2\',\''.$colorFondMenuOver.'\');" onmouseout="MouseOverFile(\'button'.$numbertextarea.'2\',\'transparent\');" onblur="recupTextareaValue'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');" onclick="popup_minieditortextarea(\''.$site[3].$pathFilesMinieditor.'minieditortextarea/popup/color'.$IEPopupColor.'.php?lng='.$lng.'&amp;stylecolor=color&amp;nameform='.$nameform.'&amp;nametextarea='.$nametextarea.'&amp;pathconfig='.$path_minieditortextarea_config.'\',\'color\',\'230\', \'250\', \'no\',\'no\', \''.$nameform.'\',\''.$nametextarea.'\');"'.tagEndMinieditor();  //COULEUR TEXTE
		echo tagBeginMinieditor('bgcolor',$lang_minieditor[6]).' id="button'.$numbertextarea.'3" title="'.$lang_minieditor[6].'" style="'.minieditorStyleIcon('-168px','0px').'" onmouseover="MouseOverFile(\'button'.$numbertextarea.'3\',\''.$colorFondMenuOver.'\');" onmouseout="MouseOverFile(\'button'.$numbertextarea.'3\',\'transparent\');" onblur="recupTextareaValue'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');" onclick="popup_minieditortextarea(\''.$site[3].$pathFilesMinieditor.'minieditortextarea/popup/color'.$IEPopupColor.'.php?lng='.$lng.'&amp;stylecolor=background-color&amp;nameform='.$nameform.'&amp;nametextarea='.$nametextarea.'&amp;pathconfig='.$path_minieditortextarea_config.'\',\'color\',\'230\', \'250\', \'no\',\'no\', \''.$nameform.'\',\''.$nametextarea.'\');"'.tagEndMinieditor();   //COULEUR SURLIGNAGE
		echo tagBeginMinieditor('justifyleft',$lang_minieditor[7]).' id="button'.$numbertextarea.'4" title="'.$lang_minieditor[7].'" style="'.minieditorStyleIcon('0px','0px').'" onmouseover="MouseOverFile(\'button'.$numbertextarea.'4\',\''.$colorFondMenuOver.'\');" onmouseout="MouseOverFile(\'button'.$numbertextarea.'4\',\'transparent\');" onclick="AddFormat(\'p\',\'text-align:left\',\''.$nameform.'\',\''.$nametextarea.'\'); recupTextareaValue'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');"'.tagEndMinieditor();  //PARAGRAPHE GAUCHE
		echo tagBeginMinieditor('justifycenter',$lang_minieditor[8]).' id="button'.$numbertextarea.'5" title="'.$lang_minieditor[8].'" style="'.minieditorStyleIcon('-21px','0px').'" onmouseover="MouseOverFile(\'button'.$numbertextarea.'5\',\''.$colorFondMenuOver.'\');" onmouseout="MouseOverFile(\'button'.$numbertextarea.'5\',\'transparent\');" onclick="AddFormat(\'p\',\'text-align:center\',\''.$nameform.'\',\''.$nametextarea.'\'); recupTextareaValue'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');"'.tagEndMinieditor();  //PARAGRAPHE CENTRE
		echo tagBeginMinieditor('justifyright',$lang_minieditor[9]).' id="button'.$numbertextarea.'6" title="'.$lang_minieditor[9].'" style="'.minieditorStyleIcon('-42px','0px').'" onmouseover="MouseOverFile(\'button'.$numbertextarea.'6\',\''.$colorFondMenuOver.'\');" onmouseout="MouseOverFile(\'button'.$numbertextarea.'6\',\'transparent\');" onclick="AddFormat(\'p\',\'text-align:right\',\''.$nameform.'\',\''.$nametextarea.'\'); recupTextareaValue'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');"'.tagEndMinieditor();  //PARAGRAPHE DROIT
		echo tagBeginMinieditor('justifyfull',$lang_minieditor[10]).' id="button'.$numbertextarea.'7" title="'.$lang_minieditor[10].'" style="'.minieditorStyleIcon('-63px','0px').'" onmouseover="MouseOverFile(\'button'.$numbertextarea.'7\',\''.$colorFondMenuOver.'\');" onmouseout="MouseOverFile(\'button'.$numbertextarea.'7\',\'transparent\');" onclick="AddFormat(\'p\',\'text-align:justify\',\''.$nameform.'\',\''.$nametextarea.'\'); recupTextareaValue'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');"'.tagEndMinieditor();  //PARAGRAPHE JUSTIFIE
		echo tagBeginMinieditor('bold',$lang_minieditor[11]).' id="button'.$numbertextarea.'8" title="'.$lang_minieditor[11].'" style="'.minieditorStyleIcon('-84px','0px').'" onmouseover="MouseOverFile(\'button'.$numbertextarea.'8\',\''.$colorFondMenuOver.'\');" onmouseout="MouseOverFile(\'button'.$numbertextarea.'8\',\'transparent\');" onclick="AddFormat(\'span\',\'font-weight:bold\',\''.$nameform.'\',\''.$nametextarea.'\'); recupTextareaValue'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');"'.tagEndMinieditor();  //TEXTE GRAS
		echo tagBeginMinieditor('italic',$lang_minieditor[12]).' id="button'.$numbertextarea.'9" title="'.$lang_minieditor[12].'" style="'.minieditorStyleIcon('-105px','0px').'" onmouseover="MouseOverFile(\'button'.$numbertextarea.'9\',\''.$colorFondMenuOver.'\');" onmouseout="MouseOverFile(\'button'.$numbertextarea.'9\',\'transparent\');" onclick="AddFormat(\'span\',\'font-style:italic\',\''.$nameform.'\',\''.$nametextarea.'\'); recupTextareaValue'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');"'.tagEndMinieditor();  //TEXTE ITALIC
		echo tagBeginMinieditor('underline',$lang_minieditor[13]).' id="button'.$numbertextarea.'10" title="'.$lang_minieditor[13].'" style="'.minieditorStyleIcon('-126px','0px').'" onmouseover="MouseOverFile(\'button'.$numbertextarea.'10\',\''.$colorFondMenuOver.'\');" onmouseout="MouseOverFile(\'button'.$numbertextarea.'10\',\'transparent\');" onclick="AddFormat(\'span\',\'text-decoration:underline\',\''.$nameform.'\',\''.$nametextarea.'\'); recupTextareaValue'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');"'.tagEndMinieditor();  //TEXTE SOULIGNE
		echo tagBeginMinieditor('strikethrough',$lang_minieditor[14]).' id="button'.$numbertextarea.'11" title="'.$lang_minieditor[14].'" style="'.minieditorStyleIcon('-189px','-21px').'" onmouseover="MouseOverFile(\'button'.$numbertextarea.'11\',\''.$colorFondMenuOver.'\');" onmouseout="MouseOverFile(\'button'.$numbertextarea.'11\',\'transparent\');" onclick="AddFormat(\'span\',\'text-decoration:line-through\',\''.$nameform.'\',\''.$nametextarea.'\'); recupTextareaValue'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');"'.tagEndMinieditor();  //TEXTE BARRE
		echo tagBeginMinieditor('subscript',$lang_minieditor[15]).' id="button'.$numbertextarea.'12" title="'.$lang_minieditor[15].'" style="'.minieditorStyleIcon('-63px','-21px').'" onmouseover="MouseOverFile(\'button'.$numbertextarea.'12\',\''.$colorFondMenuOver.'\');" onmouseout="MouseOverFile(\'button'.$numbertextarea.'12\',\'transparent\');" onclick="AddFormat(\'span\',\'vertical-align:sub\',\''.$nameform.'\',\''.$nametextarea.'\'); recupTextareaValue'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');"'.tagEndMinieditor();  //TEXTE INDICE
		echo tagBeginMinieditor('superscript',$lang_minieditor[16]).' id="button'.$numbertextarea.'13" title="'.$lang_minieditor[16].'" style="'.minieditorStyleIcon('-84px','-21px').'" onmouseover="MouseOverFile(\'button'.$numbertextarea.'13\',\''.$colorFondMenuOver.'\');" onmouseout="MouseOverFile(\'button'.$numbertextarea.'13\',\'transparent\');" onclick="AddFormat(\'span\',\'vertical-align:super\',\''.$nameform.'\',\''.$nametextarea.'\'); recupTextareaValue'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');"'.tagEndMinieditor();  //TEXTE EXPOSANT
		echo tagBeginMinieditor('br',$lang_minieditor[43]).' id="button'.$numbertextarea.'18" title="'.$lang_minieditor[43].'" style="'.minieditorStyleIcon('-82px','-42px','25px').'" onmouseover="MouseOverFile(\'button'.$numbertextarea.'18\',\''.$colorFondMenuOver.'\');" onmouseout="MouseOverFile(\'button'.$numbertextarea.'18\',\'transparent\');" onclick="AddFormat(\'br\',\'\',\''.$nameform.'\',\''.$nametextarea.'\'); recupTextareaValue'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');"'.tagEndMinieditor();  //BALISE BR
		if(isset($baliseBonus) && $baliseBonus != '') {
			echo tagBeginMinieditor('bonus',$lang_minieditor[45]).' id="button'.$numbertextarea.'19" title="'.$lang_minieditor[45].' <'.$baliseBonus.'>" style="'.minieditorStyleIcon('-124px','-42px','25px').'" onmouseover="MouseOverFile(\'button'.$numbertextarea.'19\',\''.$colorFondMenuOver.'\');" onmouseout="MouseOverFile(\'button'.$numbertextarea.'19\',\'transparent\');" onclick="AddFormat(\''.$baliseBonus.'\',\'\',\''.$nameform.'\',\''.$nametextarea.'\'); recupTextareaValue'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');"'.tagEndMinieditor();  //BALISE ICONE COEUR
		}
		echo tagBeginMinieditor('link',$lang_minieditor[18]).' id="button'.$numbertextarea.'15" title="'.$lang_minieditor[18].'" style="'.minieditorStyleIcon('0px','-21px').'" onmouseover="MouseOverFile(\'button'.$numbertextarea.'15\',\''.$colorFondMenuOver.'\');" onmouseout="MouseOverFile(\'button'.$numbertextarea.'15\',\'transparent\');" onblur="recupTextareaValue'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');" onclick="popup_minieditortextarea(\''.$site[3].$pathFilesMinieditor.'minieditortextarea/popup/link.php?lng='.$lng.'&amp;nameform='.$nameform.'&amp;nametextarea='.$nametextarea.'&amp;pathconfig='.$path_minieditortextarea_config.'\',\'link\',\'450\', \'157\', \'no\',\'no\', \''.$nameform.'\',\''.$nametextarea.'\');"'.tagEndMinieditor();  //INSERTION LIEN
		echo tagBeginMinieditor('image',$lang_minieditor[17]).' id="button'.$numbertextarea.'14" title="'.$lang_minieditor[17].'" style="'.minieditorStyleIcon('-189px','0px').'" onmouseover="MouseOverFile(\'button'.$numbertextarea.'14\',\''.$colorFondMenuOver.'\');" onmouseout="MouseOverFile(\'button'.$numbertextarea.'14\',\'transparent\');" onblur="recupTextareaValue'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');" onclick="popup_minieditortextarea(\''.$site[3].$pathFilesMinieditor.'minieditortextarea/popup/image.php?lng='.$lng.'&amp;nameform='.$nameform.'&amp;nametextarea='.$nametextarea.'&amp;pathconfig='.$path_minieditortextarea_config.'\',\'image\',\'450\', \'287\', \'no\',\'no\', \''.$nameform.'\',\''.$nametextarea.'\');"'.tagEndMinieditor();  //INSERTION IMAGE
		echo tagBeginMinieditor('flash',$lang_minieditor[48]).' id="button'.$numbertextarea.'22" title="'.$lang_minieditor[48].'" style="'.minieditorStyleIcon('-21px','-63px').'" onmouseover="MouseOverFile(\'button'.$numbertextarea.'22\',\''.$colorFondMenuOver.'\');" onmouseout="MouseOverFile(\'button'.$numbertextarea.'22\',\'transparent\');" onblur="recupTextareaValue'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');" onclick="popup_minieditortextarea(\''.$site[3].$pathFilesMinieditor.'minieditortextarea/popup/flash.php?lng='.$lng.'&amp;nameform='.$nameform.'&amp;nametextarea='.$nametextarea.'&amp;pathconfig='.$path_minieditortextarea_config.'\',\'flash\',\'450\', \'340\', \'no\',\'no\', \''.$nameform.'\',\''.$nametextarea.'\');"'.tagEndMinieditor();  //INSERTION FLASH
		echo tagBeginMinieditor('smiley',$lang_minieditor[69]).' id="button'.$numbertextarea.'24" title="'.$lang_minieditor[69].'" style="'.minieditorStyleIcon('-126px','-21px').'" onmouseover="MouseOverFile(\'button'.$numbertextarea.'24\',\''.$colorFondMenuOver.'\');" onmouseout="MouseOverFile(\'button'.$numbertextarea.'24\',\'transparent\');" onblur="recupTextareaValue'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');" onclick="popup_minieditortextarea(\''.$site[3].$pathFilesMinieditor.'minieditortextarea/popup/smiley.php?lng='.$lng.'&amp;nameform='.$nameform.'&amp;nametextarea='.$nametextarea.'&amp;pathconfig='.$path_minieditortextarea_config.'\',\'smiley\',\'300\', \'250\', \'no\',\'no\', \''.$nameform.'\',\''.$nametextarea.'\');"'.tagEndMinieditor();  //INSERTION SMILEY

		echo tagBeginMinieditor('entity',$lang_minieditor[71]).' id="button'.$numbertextarea.'25" title="'.$lang_minieditor[71].'" style="'.minieditorStyleIcon('-0px','-63px').'" onmouseover="MouseOverFile(\'button'.$numbertextarea.'25\',\''.$colorFondMenuOver.'\');" onmouseout="MouseOverFile(\'button'.$numbertextarea.'25\',\'transparent\');" onblur="recupTextareaValue'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');" onclick="popup_minieditortextarea(\''.$site[3].$pathFilesMinieditor.'minieditortextarea/popup/entities.php?lng='.$lng.'&amp;nameform='.$nameform.'&amp;nametextarea='.$nametextarea.'&amp;pathconfig='.$path_minieditortextarea_config.'\',\'entities\',\'350\', \'150\', \'yes\',\'no\', \''.$nameform.'\',\''.$nametextarea.'\');"'.tagEndMinieditor();  //INSERTION ENTITIES

		echo tagBeginMinieditor('undo',$lang_minieditor[46]).' id="button'.$numbertextarea.'20" title="'.$lang_minieditor[46].'" style="'.minieditorStyleIcon('-63px','-42px').'" onmouseover="MouseOverFile(\'button'.$numbertextarea.'20\',\''.$colorFondMenuOver.'\');" onmouseout="MouseOverFile(\'button'.$numbertextarea.'20\',\'transparent\');" onclick="Undo'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');"'.tagEndMinieditor();  //UNDO
		echo tagBeginMinieditor('redo',$lang_minieditor[47]).' id="button'.$numbertextarea.'21" title="'.$lang_minieditor[47].'" style="'.minieditorStyleIcon('-105px','-42px').'" onmouseover="MouseOverFile(\'button'.$numbertextarea.'21\',\''.$colorFondMenuOver.'\');" onmouseout="MouseOverFile(\'button'.$numbertextarea.'21\',\'transparent\');" onclick="Redo'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');"'.tagEndMinieditor();  //REDO
		//echo '<br'.$minieditorStyleBR.' />'."\n";
		//MENU BALISEHTML
		echo '<select name="HTMLbalise'.$numbertextarea.'" size="1" style="'.$minieditorStyleSelect.'" onchange="AddBalise(\'HTMLbalise'.$numbertextarea.'\',\''.$nameform.'\',\''.$nametextarea.'\');">'."\n";
		echo '<option value="" selected="selected">'.$lang_minieditor[21].'</option>'."\n";
		for ($i = 0; $i < count($baliseHTML); $i++) {
			echo '<option value="'.$baliseHTML[$i].'">'.$baliseHTML[$i].'</option>'."\n";
		}
		echo '</select>'."\n";
		//MENU CLASS CSS
		echo '<select name="CSSclass'.$numbertextarea.'" size="1" style="'.$minieditorStyleSelect.'" onchange="AddCSS(\'CSSclass'.$numbertextarea.'\',\''.$nameform.'\',\''.$nametextarea.'\');">'."\n";
		echo '<option value="" selected="selected">'.$lang_minieditor[22].'</option>'."\n";
		for ($i = 0; $i < count($classCSS); $i++) {
			echo '<option value="'.$classCSS[$i].'">'.$classCSS[$i].'</option>'."\n";
		}
		echo '</select>'."\n";
		//MENU CHEMIN URL LIEN ET IMAGE
		echo '<select name="URLpath'.$numbertextarea.'" size="1" style="'.$minieditorStyleSelect.'" onchange="ChangeURLPath(\'URLpath'.$numbertextarea.'\',\''.$nameform.'\',\''.$nametextarea.'\');">'."\n";
			echo '<option value="" selected="selected">'.$lang_minieditor[23].'</option>'."\n";
			echo '<option value="relatif">'.$lang_minieditor[24].'</option>'."\n";
			echo '<option value="absolu">'.$lang_minieditor[25].'</option>'."\n";
		echo '</select>'."\n";
		//APERCU
		echo tagBeginMinieditor('preview',$lang_minieditor[19]).' id="button'.$numbertextarea.'16" title="'.$lang_minieditor[19].'" style="'.minieditorStyleIcon('-21px','-21px').'" onmouseover="MouseOverFile(\'button'.$numbertextarea.'16\',\''.$colorFondMenuOver.'\');" onmouseout="MouseOverFile(\'button'.$numbertextarea.'16\',\'transparent\');" onblur="recupTextareaValue'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');" onclick="popup_minieditortextarea(\''.$site[3].$pathFilesMinieditor.'minieditortextarea/popup/preview.php?lng='.$lng.'&amp;nameform='.$nameform.'&amp;nametextarea='.$nametextarea.'&amp;pathconfig='.$path_minieditortextarea_config.'\', \'preview\', \'600\', \'450\', \'yes\',\'yes\',\''.$nameform.'\',\''.$nametextarea.'\');"'.tagEndMinieditor();
//		echo tagBeginMinieditor('about',$lang_minieditor[68]).' id="button'.$numbertextarea.'23" title="'.$lang_minieditor[68].'" style="'.minieditorStyleIcon('-168px','-21px').'" onmouseover="MouseOverFile(\'button'.$numbertextarea.'23\',\''.$colorFondMenuOver.'\');" onmouseout="MouseOverFile(\'button'.$numbertextarea.'23\',\'transparent\');" onclick="popup_minieditortextarea(\''.$site[3].$pathFilesMinieditor.'minieditortextarea/popup/about.php?lng='.$lng.'&amp;pathconfig='.$path_minieditortextarea_config.'\', \'about\', \'390\', \'210\', \'no\',\'no\',\''.$nameform.'\',\''.$nametextarea.'\');"'.tagEndMinieditor();  //A propos
		echo '<br'.$minieditorStyleBR.' />'."\n";
		echo '</div>'."\n";
		echo '</div>'."\n";

	//TEXTAREA DU MINIEDITEUR
		echo '<div style="text-align:center;"><textarea name="'.$nametextarea.'" id="'.$nametextarea.'" style="width:'.$widthtextarea.'; height:'.$heightextarea.';'.$minieditorStyleTextarea.'" cols="43" rows="20" onselect="selectext(\''.$nameform.'\',\''.$nametextarea.'\');" onblur="recupTextareaValue'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');" onclick="selectext(\''.$nameform.'\',\''.$nametextarea.'\'); recupTextareaValue'.$numbertextarea.'(\''.$nameform.'\',\''.$nametextarea.'\');" >'.$fieldtextarea.'</textarea></div>'."\n";

	//SMILEYS DU MINIEDITEUR
		echo '<div style="text-align:center;">';
    	echo '<div class="forum" style="width:'.$widthtextarea.';'.$minieditorStyleSmiley.'">'."\n";
		$souriez = array();
		$i = 0;
		$dir = opendir(CHEMIN.'inc/img/smileys/');
		while ($file = readdir($dir)) {
        	if(is_file(CHEMIN.'inc/img/smileys/'.$file) && ($file != 'index.php') && preg_match('!\.(gif|jpg|png|jpeg)$!i', $file)) {
				$souriez[$i][0] = 'inc/img/smileys/'.$file;
				$souriez[$i][1] = substr($file,0,(strlen($file)-4));
				$image_size = getimagesize(CHEMIN.$souriez[$i][0]);
				$souriez[$i][2] = $image_size[0];
				$souriez[$i][3] = $image_size[1];
				$souriez[$i][4] = $image_size[3];
				$i++;
			}
 		}
		closedir($dir);
	    for ($i = 0; $i < count($souriez); $i++) {
            echo '<img src="'.CHEMIN.$souriez[$i][0].'" '.$souriez[$i][4].' style="'.$minieditorStyleImgSmiley.'" border="0" title="'.$souriez[$i][1].'" alt="'.$souriez[$i][1].'" onclick="AddSmiley(\''.$souriez[$i][0].'\',\''.$souriez[$i][2].'\',\''.$souriez[$i][3].'\',\''.$souriez[$i][1].'\',\''.$nameform.'\',\''.$nametextarea.'\');" />&nbsp;'."\n";
        }
		unset($souriez);
		echo '</div>'."\n";
		echo '</div>'."\n";
}