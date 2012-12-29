<?php
/*
     MinieditorTextarea réalisé par Djchouix - Licence CeCILL
     Web site = http://lebrikabrak.free.fr/
     e-mail   = lebrikabrak@free.fr
	 version 1.6 (24 février 2006) compatibilité avec guppy v4.5.x
     v4.6.10 (7 September 2009)    : corrected #272
*/
header("Pragma: no-cache");
define("CHEMIN", "../../../../");
include(CHEMIN."inc/includes.inc");
//Protection contre les petits curieux
include(CHEMIN.'admin/editors/action.php');
if ($wri == "admin") {
    if (FileDBExist(CHEMIN."admin/mdp.php")) {
        include(CHEMIN."admin/mdp.php");
	} else {
	    $mdp="bad";
	}
} else {
    if (FileDBExist(CHEMIN.'admin/'.REDACREP.$wri.INCEXT)) {
        include(CHEMIN.'admin/'.REDACREP.$wri.INCEXT);
        $mdp=md5($drtuser[38]);
    } else {
        $mdp="bad";
    }
}
$portalname="GuppyAdmin";
if (empty($_COOKIE[$portalname]) || $_COOKIE[$portalname] != crc32($mdp)) {
    die('Une erreur d\'identification est survenue. Veuillez contacter l\'administrateur du site.');
} else {
//Fin de protection

//Control des variables passées en argument
$lng = isset($_GET['lng']) ? $_GET['lng'] : NULL;
$nameform = isset($_GET['nameform']) ? $_GET['nameform'] : NULL;
$nametextarea = isset($_GET['nametextarea']) ? $_GET['nametextarea'] : NULL;
if(!preg_match("!^[a-z]{2,3}$!i",$lng) || !preg_match("!^[-a-z0-9_]+$!i",$nameform) || !preg_match("!^[-a-z0-9_]+$!i",$nametextarea)) die("Erreur dans le nom des variables passées dans l'URL !!");

$pathDirMinieditor = 'admin/editors/';    //chemin relatif du répertoire du miniéditeur (à ne pas modifier pour ne pas perdre la compatibilité avec les autres plugins)
$nameRepConfig = 'minieditortextarea';   //nom du répertoire par défaut situé dans admin/editors/ qui contient la config du miniéditeur et de l'upload 

// Insertion du fichier de langue
if(file_exists(CHEMIN.$pathDirMinieditor.'minieditortextarea/lang/'.$lng.'_minieditortextarea.inc')) {
	include(CHEMIN.$pathDirMinieditor.'minieditortextarea/lang/'.$lng.'_minieditortextarea.inc');
} else {
	include(CHEMIN.$pathDirMinieditor.'minieditortextarea/lang/en_minieditortextarea.inc'); // fichier de langue par défaut
}

//Récupération de la config du miniéditor
if(file_exists(CHEMIN.$pathDirMinieditor.'minieditortextarea/minieditortextarea_config.inc')) {
	include(CHEMIN.$pathDirMinieditor.'minieditortextarea/minieditortextarea_config.inc');  //CONFIGURATION MINIEDITEUR PAR DEFAUT
} else {
	die('Une erreur est survenue car il manque le ficher "'.$pathDirMinieditor.'minieditortextarea/minieditortextarea_config.inc "');
}
$path_minieditortextarea_config = isset($_GET['pathconfig']) ? $_GET['pathconfig'] : NULL;
$path_minieditortextarea_config = strip_tags($path_minieditortextarea_config);
if(isset($path_minieditortextarea_config) && $path_minieditortextarea_config != '' && preg_match("!^[-a-z0-9_]{1}[-a-z0-9_\/]*\/$!i",$path_minieditortextarea_config) && file_exists(CHEMIN.$path_minieditortextarea_config.'minieditortextarea_config.inc')) {
	include(CHEMIN.$path_minieditortextarea_config.'minieditortextarea_config.inc');  //CONFIGURATION MINIEDITEUR
}

?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<meta http-equiv="Content-Style-Type" content="text/css" />
<title><?php echo $lang_minieditor[48]; ?></title>
<?php
if(file_exists(CHEMIN.$pathDirMinieditor.'minieditortextarea/popup/'.$lng.'_style_popup.css')) { //FEUILLE DE STYLE
	echo '<link type="text/css" rel="stylesheet" href="'.CHEMIN.$pathDirMinieditor.'minieditortextarea/popup/'.$lng.'_style_popup.css"  />';
} else {
	echo '<link type="text/css" rel="stylesheet" href="'.CHEMIN.$pathDirMinieditor.'minieditortextarea/popup/en_style_popup.css"  />';
}
include(CHEMIN.$pathDirMinieditor.'minieditortextarea/popup/jscript_popup.inc');  //FONCTION JAVASCRIPT

echo '</head>';
echo '<body style="color:'.$colorTextCorp.'; background-color:'.$colorFondCorp.';">';
	echo '<form name="addflash" id="addflash" action ="self" method="post">';
		echo '<div class="titre" style="background-color:'.$colorFondTitre.'; color:'.$colorTextTitre.'; border-top:'.$styleBordureTitre.'; border-bottom:'.$styleBordureTitre.';" >'.$lang_minieditor[48].'</div>';
		echo '<div class="corps0">';
		echo '<div class="corpsURL">';
		echo $lang_minieditor[26].' :<input name="f_url" id="f_url" class="zoneUrl" type="text" value="" />'."\n";
		echo '</div>';
		echo '</div>';
		echo '<div  class="corps1">';
		echo '<div class="corpsTag">';
		if($pathDirMinieditor != '' && preg_match("!^[-a-z0-9_]+\/[-a-z0-9_\/]+\/$!i",$pathDirMinieditor) && file_exists(CHEMIN.$pathDirMinieditor.'upload/upload.php')) {
			echo '<input type="button" name="browserver" id="browserver" onclick="popup_upload(\''.CHEMIN.$pathDirMinieditor.'upload/upload.php?lng='.$lng.'&amp;uptype=Flash&amp;namerepconfig='.str_replace('&','',$nameRepConfig).'&amp;pathconfig='.$pathFilesMinieditor.'\',\'upload_flash\',\'700\',\'515\', \'yes\');" value="'.$lang_minieditor[27].'" />'."\n";
		}
		echo '</div>';
		echo '</div>';
		echo '<div class="corpsPropriete1" >';
		echo '<div class="corpsTag">'.$lang_minieditor[30].' :<input name="f_width" id="f_width" type="text" class="zoneTag" value="" /></div>'."\n";
		echo '<div class="corpsTag">'.$lang_minieditor[31].' :<input name="f_height" id="f_height" type="text" class="zoneTag" value="" /></div>'."\n";
		echo '<div class="corpsTag">';
		echo $lang_minieditor[35].' : <select name="f_align" id="f_align" size="1" >'."\n";
		echo '<option value="" selected="selected">'.$lang_minieditor[44].'</option>'."\n";
		for ($i = 0; $i < count($alignIMG); $i++) {
			echo '<option value="'.$alignIMG[$i].'">'.$alignIMG[$i].'</option>'."\n";
		}
		echo '</select>'."\n";
		echo '</div>';
		echo '<div class="corpsTag">'.$lang_minieditor[55].' :<input name="f_loop" id="f_loop" type="checkbox" value="" checked="checked" /></div>'."\n";
		echo '<div class="corpsTag">'.$lang_minieditor[57].' :<input name="f_menu" id="f_menu" type="checkbox" value="" checked="checked" /></div>'."\n";
		echo '<div class="corpsTag">'.$lang_minieditor[49].' :<input name="f_id" id="f_id" type="text" class="zoneTagIdClass" value="" /></div>'."\n";
		echo '<div>'.$lang_minieditor[22].' :<input name="f_classCSS" id="f_classCSS" type="text" class="zoneTagIdClass" value="" /></div>'."\n";
		echo '</div>';
		echo '<div class="corpsPropriete2" >';
		echo '<div class="corpsTag">'.$lang_minieditor[33].' :<input name="f_hspace" id="f_hspace" type="text" class="zoneTag" value="" /></div>'."\n";
		echo '<div class="corpsTag">'.$lang_minieditor[34].' :<input name="f_vspace" id="f_vspace" type="text" class="zoneTag" value="" /></div>'."\n";
		echo '<div class="corpsTag">';
		echo $lang_minieditor[50].' : <select name="f_quality" id="f_quality" size="1" >'."\n";
		echo '<option value="" selected="selected">'.$lang_minieditor[51].'</option>'."\n";
		echo '<option value="high">'.$lang_minieditor[52].'</option>'."\n";
		echo '<option value="autolow">'.$lang_minieditor[53].'</option>'."\n";
		echo '<option value="low">'.$lang_minieditor[54].'</option>'."\n";
		echo '</select>'."\n";
		echo '</div>';
		echo '<div class="corpsTag">'.$lang_minieditor[6].' :<input name="f_bgcolor" id="f_bgcolor" type="text" class="zoneTagIdClass" value="" /></div>'."\n";
		echo '<div class="corpsTag">'.$lang_minieditor[56].' :<input name="f_play" id="f_play" type="checkbox" value="" checked="checked" /></div>'."\n";
		echo '<div class="corpsTag">';
		echo $lang_minieditor[58].' : <select name="f_scale" id="f_scale" class="scale" size="1" >'."\n";
		echo '<option value="" selected="selected">'.$lang_minieditor[51].'</option>'."\n";
		echo '<option value="noborder">'.$lang_minieditor[59].'</option>'."\n";
		echo '<option value="exactfit">'.$lang_minieditor[60].'</option>'."\n";
		echo '</select>'."\n";
		echo '</div>';
		echo '</div>';
		echo '<div class="corps3">';
		echo '<input type="button" id="linkOK" name="linkOK" onclick="AddFlash(\''.$nameform.'\',\''.$nametextarea.'\');" value="'.$lang_minieditor[0].'" />';
		echo '<input type="button" name="linkCancel" id="linkCancel" onclick="window.close();" value="'.$lang_minieditor[1].'" />';
		echo '</div>';
	echo '</form>';		
?>
</body>
</html>
<?php
}
