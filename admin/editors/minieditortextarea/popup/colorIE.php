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
if(!preg_match("!^[a-z]+$!i",$lng) || !preg_match("!^[-a-z0-9_]+$!i",$nameform) || !preg_match("!^[-a-z0-9_]+$!i",$nametextarea)) die("Erreur dans le nom des variables passées dans l'URL !!");
$stylecolor = isset($_GET['stylecolor']) ? $_GET['stylecolor'] : NULL;
if($stylecolor != 'color' && $stylecolor != 'background-color') die('Erreur dans le nom des variables !!');

$pathDirMinieditor = 'admin/editors/';    //chemin relatif du répertoire du miniéditeur (à ne pas modifier pour ne pas perdre la compatibilité avec les autres plugins)
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
<title><?php echo $lang_minieditor[36]; ?></title>
<style type="text/css" >
body {
 	font-size:12pt;
 	font-family:"Times New Roman" , Arial, sans-serif;
 	color:<?php echo $colorTextCorp; ?>; 
 	background-color:<?php echo $colorFondCorp; ?>;
	margin:0px;
 	padding:0px;
}

form {
	margin:0px;
}

table {
	text-align:center;
	margin-left:auto;
	margin-right:auto;
	cursor:pointer;
	margin:15px;
	color:#000000;
	background-color:#000000;
}

td {
 height:10px;
 width:10px;
}

input {
	margin-left:2px;
	width:65px;
}

div.corps1 {
	text-align:center;
	margin:0px;
	padding-top:5px;
	padding-bottom:15px; 
	padding-left:20px;
}

div.corps2 {
	text-align:center;
}

#f_preview {
	float:right;
	height: 30px;
	width:30px;
	border:1px solid #000000;
	background-color: #000000;
	color:#000000;
	margin-right:15px;
}

#linkOK {
	width:70px;
	font-size:10pt;
	cursor:pointer;
}

#linkCancel {
	width:70px;
	font-size:10pt;
	margin-left:15px;
	cursor:pointer;
}
</style>
<?php
include(CHEMIN.$pathDirMinieditor.'minieditortextarea/popup/jscript_popup.inc');  //FONCTION JAVASCRIPT

echo '</head>';
echo '<body style="color:'.$colorTextCorp.'; background-color:'.$colorFondCorp.';">';
	echo '<form name="addcolortext" id="addcolortext" action ="self" method="post">';
    	echo '<table class="corps" cellspacing="1" cellpadding="0" border="0">';
    	echo '<tr>';
    	$col_r = 0;
    	$col_g = 0;
    	$col_b = 0;
    	$row_return = 0;
    	$block_return = 0;
    	while($col_r <= 255) {
       		$col_g = 0;
       		$block_return++;
      		while($col_g <= 255) {
           		$col_b = 0;
           		while($col_b <= 255) {
               		$red = strtoupper(dechex($col_r));
               		$green = strtoupper(dechex($col_g));
               		$blue = strtoupper(dechex($col_b));
               		$color = str_pad($red,2,'0',STR_PAD_LEFT)."".str_pad($green,2,'0',STR_PAD_LEFT)."".str_pad($blue,2,'0',STR_PAD_LEFT);
               		echo '<td  style="background-color:#'.$color.';" onmouseover="ColorPreview(\''.$color.'\');" onmouseout="ColorPreview(\'000000\');" onclick="AddColor(\''.$stylecolor.'\',\''.$nameform.'\',\''.$nametextarea.'\');"></td>';
               		$row_return++;
               		if($row_return == 18) {
                  		echo "</tr><tr>";
                  		$row_return = 0;
               		}
               		$col_b += 51;
          		}
          		$col_g += 51;
      		}
      		$col_r += 51;
    	}
    	$col = 15;
    	while($col <= 255) {
        	$red = strtoupper(dechex($col));
        	$green = strtoupper(dechex($col));
        	$blue = strtoupper(dechex($col));
        	$color = str_pad($red,2,'0',STR_PAD_LEFT)."".str_pad($green, 2,'0',STR_PAD_LEFT)."".str_pad($blue,2,'0',STR_PAD_LEFT);
        	echo '<td style="background-color:#'.$color.';" onmouseover="ColorPreview(\''.$color.'\');" onmouseout="ColorPreview(\'000000\');" onclick="AddColor(\''.$stylecolor.'\',\''.$nameform.'\',\''.$nametextarea.'\');"></td>';
        	$col += 14;
    	}
    	echo '</tr>';
    	echo '</table>';
		echo '<div id="f_preview" >&nbsp;</div>';
		echo '<div class="corps1" >';
		echo $lang_minieditor[37].' : <input type="text" name="f_color" id="f_color" value="#000000" onkeyup="document.getElementById(\'f_preview\').style.backgroundColor = document.getElementById(\'f_color\').value;" />'."\n";
		echo '</div>';
		echo '<div class="corps2" >';
		echo '<input type="button" name="linkOK" id="linkOK" onclick="AddColor(\''.$stylecolor.'\',\''.$nameform.'\',\''.$nametextarea.'\');" value="'.$lang_minieditor[0].'" />';
		echo '<input type="button" name="linkCancel" id="linkCancel" onclick="window.close();" value="'.$lang_minieditor[1].'" />';
		echo '</div>';
	echo '</form>';
?>
</body>
</html>
<?php
}
