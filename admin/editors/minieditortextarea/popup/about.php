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
$lng = isset($_GET['lng']) ? $_GET['lng'] : NULL;
if(!preg_match("!^[a-z]{2,3}$!i",$lng)) die("Erreur dans le nom des variables passées dans l'URL !!");
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
<title><?php echo $lang_minieditor[68]; ?></title>
<style type="text/css">
body {
	font-size: 16px;
 	font-family: "Times New Roman" , Arial, sans-serif;
 	color:<?php echo $colorTextTitre; ?>; 
 	background-color:<?php echo $colorFondTitre; ?>;
}
h4 {
	margin:15px;
	font-weight:bold;
}
div.version {
	margin-left:auto;
	margin-right:auto;
	margin-bottom:15px;
	padding:10px;
	text-align:center;
	width:100px;
	background-color:<?php echo $colorFondCorp; ?>;
	color:<?php echo $colorTextCorps; ?>;
	border:<?php echo $styleBordureCorp; ?>;
	font-weight:bold; 
}
div.corpsinfos {
	margin-left:auto;
	margin-right:auto;
	margin-bottom:15px;
	width:100%;
}
div.label {
	width:120px;
	float:left;
	text-align:right;
	font-weight:bold;
}
div.infos {
	padding-left:135px;
	text-align:left;
}
a {
 	color:<?php echo $colorTextTitre; ?>;
	text-decoration:none;
}
a:hover {
 	color:#FF0000;
	text-decoration:underline;
}
</style>
</head>
<body>
<div style="text-align:center;">
<h4>Minieditor</h4>
<div class="version">
<?php echo $version_minieditor; ?>
</div>
<div class="corpsinfos">
<div class="label">
Auteur&nbsp;:<br />
Email&nbsp;:<br />
Site Web&nbsp;:<br />
Licence&nbsp;:<br />
</div>
<div class="infos">
Jérôme CROUX (alias jchouix)<br />
<a href="mailto:lebrikabrak@free.fr" target="_blank">lebrikabrak@free.fr</a><br />
<a href="http://lebrikabrak.free.fr" target="_blank">http://lebrikabrak.info</a><br />
<a href="lgpl.html" target="_blank">GNU Lesser General Public License</a><br />
</div>
</div>
</div>
</body>
</html>
<?php
}