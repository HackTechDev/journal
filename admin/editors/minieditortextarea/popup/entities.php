<?php
/*
     MinieditorTextarea réalisé par Djchouix - Licence CeCILL
     Web site = http://lebrikabrak.free.fr/
     e-mail   = lebrikabrak@free.fr
	 version 1.6.3 (24 février 2007) compatibilité avec guppy v4.5.x
     v4.6.10 (7 september 2009)   : corrected #272
     v4.6.11 (11 December 2009)   :corrected #311
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

//Construction du tableau
function displayTableEntities($nameform, $nametextarea)
{
	$entities = array();
	for($i = 160; $i < 256; $i++) {
		$entities['&#'.$i.';'] = '&#'.$i.';';
	}

	$i = 0;
	$table = '<table cellspacing="0" cellpadding="0" border="1"><tr>';
	foreach($entities as $entitie => $codevalue) {
		$table .= '<td class="entity" onclick="AddEntities(\''.$codevalue.'\',\''.$nameform.'\',\''.$nametextarea.'\');" onmouseover="this.className=\'hover\';" onmouseout="this.className=\'entity\';">'.$entitie.'</td>';

		if($i == 15) {
			$table .= '</tr><tr>';
			$i = 0;
		} else {
			$i++;
		}
	}
	$table .= '</tr><table>';

	return $table;
}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<meta http-equiv="Content-Style-Type" content="text/css" />
<title><?php echo $lang_minieditor[71]; ?></title>
<?php
if(file_exists(CHEMIN.$pathDirMinieditor.'minieditortextarea/popup/'.$lng.'_style_popup.css')) { //FEUILLE DE STYLE
	echo '<link type="text/css" rel="stylesheet" href="'.CHEMIN.$pathDirMinieditor.'minieditortextarea/popup/'.$lng.'_style_popup.css"  />'."\n";
} else {
	echo '<link type="text/css" rel="stylesheet" href="'.CHEMIN.$pathDirMinieditor.'minieditortextarea/popup/en_style_popup.css"  />'."\n";
}
include(CHEMIN.$pathDirMinieditor.'minieditortextarea/popup/jscript_popup.inc');  //FONCTION JAVASCRIPT
?>
</head>
<body class="entities" style="color:<?php echo $colorTextCorp; ?>; background-color:<?php echo $colorFondCorp; ?>;">
<?php echo displayTableEntities($nameform, $nametextarea); ?>
</body>
</html>
<?php
}
