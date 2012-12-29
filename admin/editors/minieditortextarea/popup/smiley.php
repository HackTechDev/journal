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
<title><?php echo $lang_minieditor[69]; ?></title>
<style type="text/css">
html, body {
	margin:0px;
	padding:0px;
	text-align:center;
	background-color:<?php echo $colorFondCorp; ?>;
}
.corpsEmoticon {
	width:100%;
	margin-left:auto;
	margin-right:auto;
	border:0px solid #CC0033;
	height:250px;
 	width:300px;
	overflow:auto;
}
.imageEmoticon {
	vertical-align:middle;
	cursor:pointer;
	margin:2px;
}
</style>
<?php
include(CHEMIN.$pathDirMinieditor.'minieditortextarea/popup/jscript_popup.inc');  //FONCTION JAVASCRIPT
?>
</head>
<body>
<div class="corpsEmoticon">
<?php
	$smileys = array();
	$i = 0;
	$dir = opendir(CHEMIN.$nameRepSmiley);
	while ($file = readdir($dir)) {
        if(is_file(CHEMIN.$nameRepSmiley.$file) && ($file != 'index.php') && preg_match('!\.(gif|jpg|png|jpeg)$!i', $file)) {
			$smileys[$i][0] = $nameRepSmiley.$file;			
			$smileys[$i][1] = substr($file,0,(strlen($file)-4));
			$image_size = getimagesize(CHEMIN.$smileys[$i][0]);
			$smileys[$i][2] = $image_size[0];
			$smileys[$i][3] = $image_size[1];
			$smileys[$i][4] = $image_size[3];
			$i++;	
		}		
 	}
	closedir($dir);
	for ($i = 0; $i < count($smileys); $i++) {
    	echo '<img src="'.CHEMIN.$smileys[$i][0].'" '.$smileys[$i][4].' class="imageEmoticon" border="0" title="'.$smileys[$i][1].'" alt="'.$smileys[$i][1].'" onclick="AddSmileys(\''.$smileys[$i][0].'\',\''.$smileys[$i][1].'\',\''.$smileys[$i][2].'\',\''.$smileys[$i][3].'\',\''.$nameform.'\',\''.$nametextarea.'\');" />&nbsp;'."\n";
    }
	unset($smileys);
?>
</div>
</body>
</html>
<?php
}
