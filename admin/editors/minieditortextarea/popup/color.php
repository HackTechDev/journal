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

//Control des variable
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

div input {
	vertical-align:middle;
}

div.corps {
	text-align:center;
	margin-left:auto;
	margin-right:auto;
	margin-top:15px;
	width:198px;
	border-left:1px solid #000000;
	border-top:1px solid #000000;
	cursor:pointer;
}

div.color {
	float:left;
	height:10px;
	width:10px;
	border-bottom:1px solid #000000;
	border-right:1px solid #000000; 
}

hr {
	clear:left;
	background-color:transparent;
	color:transparent;
	border:0px none transparent;
}

div.corps0 {
	margin-top:15px;
	text-align:center;
	margin-left:auto;
	margin-right:auto;
	width:200px;
}

div.corps1 {
	padding-top:5px;
}

div.corps2 {
	text-align:center;
	margin-top:15px;
}

#f_color {
	margin-left:2px;
	margin-right:2px;
	width:65px;
}

#f_preview {
	float:right;
	height:30px;
	width:30px;
	border:1px solid #000000;
	margin-right:8px;
	background-color: #000000;
	color:#000000;
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
?>
<script type="text/javascript">
function palettecouleur() {
	var baseColorWeb = new Array('00','33','66','99','CC','FF');
	var codeCouleur = ''; 
	var i = 0;
	var j = 0;
	var k = 0;
	for(i = 0; i < baseColorWeb.length; i++) { 
		for(j = 0; j < baseColorWeb.length; j++) { 
			for(k = 0; k < baseColorWeb.length; k++) { 
				codeCouleur = baseColorWeb[i] + baseColorWeb[j] + baseColorWeb[k]; 
               	document.write('<div class="color" style="background-color:#'+ codeCouleur +';  color:#'+ codeCouleur +';" onmouseover="ColorPreview(\''+ codeCouleur +'\');" onmouseout="ColorPreview(\'000000\');" onclick="AddColor(\'<?php echo $stylecolor; ?>\',\'<?php echo $nameform; ?>\',\'<?php echo $nametextarea; ?>\');"></div>');
			}
		}
	}
	var baseColorGray = new Array('0F','1D','2B','39','47','55','63','71','7F','8D','9B','A9','B7','C5','D3','E1','EF','FD');
	for(i = 0; i < baseColorGray.length; i++) { 
		codeCouleur = baseColorGray[i] + baseColorGray[i] + baseColorGray[i]; 
        document.write('<div class="color" style="background-color:#'+ codeCouleur +';  color:#'+ codeCouleur +';" onmouseover="ColorPreview(\''+ codeCouleur +'\');" onmouseout="ColorPreview(\'000000\');" onclick="AddColor(\'<?php echo $stylecolor; ?>\',\'<?php echo $nameform; ?>\',\'<?php echo $nametextarea; ?>\');"></div>');
	}
}
</script>
</head>
<body style="color:<?php echo $colorTextCorp; ?>; background-color:<?php echo $colorFondCorp; ?>;">
<form name="addcolortext" id="addcolortext" action ="self" method="post">
<div class="corps">
<script type="text/javascript">
	palettecouleur();
</script>
</div>
<hr />
<div class="corps0">		
<div id="f_preview"></div>	
<div class="corps1" >
<?php echo $lang_minieditor[37]; ?> : <input type="text" name="f_color" id="f_color" value="#000000" onkeyup="document.getElementById('f_preview').style.backgroundColor = document.getElementById('f_color').value;" />
</div>
</div>
<div class="corps2" >
<input type="button" name="linkOK" id="linkOK" onclick="AddColor('<?php echo $stylecolor; ?>','<?php echo $nameform; ?>','<?php echo $nametextarea; ?>');" value="<?php echo $lang_minieditor[0]; ?>" />
<input type="button" name="linkCancel" id="linkCancel" onclick="window.close();" value="<?php echo $lang_minieditor[1]; ?>" />
</div>
</form>
</body>
</html>
<?php
}