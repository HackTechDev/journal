<?php
/*
     MinieditorTextarea réalisé par Djchouix - Licence CeCILL
     Web site = http://lebrikabrak.free.fr/
     e-mail   = lebrikabrak@free.fr
	 version 1.6.1 (3 mars 2006) compatibilité avec guppy v4.5.x
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

//CONFIGURATION DES REPERTOIRES ACCESSIBLE POUR UPLOAD PAR DEFAUT
$accessRepUpload = array('img','photo','file','pages','flash');  //Répertoire où l'on a accès pour uploader

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

//CONTROLE DES REPERTOIRES ECRITS DANS LA VARIABLE $accessRepUpload et CREATION DU REPERTOIRE SI NECESSAIRE
include(CHEMIN.$pathDirMinieditor.'upload/functions_upload.inc');
$accessRepUpload = controlNameRepUpload($accessRepUpload);

?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<meta http-equiv="Content-Style-Type" content="text/css" />
<title><?php echo $lang_minieditor[19]; ?></title>
<?php
if (file_exists($meskin."style.css")){ 
    echo '<link type="text/css" rel="stylesheet" href="'.$meskin.'style.css" />';
} else {
    echo "<style type=\"text/css\">";
    if(file_exists($meskin."style.inc")) {
	    include($meskin."style.inc");
	} else {
	    include(CHEMIN."inc/style.inc");
	}
    echo "</style>";
}

echo '</head>';
echo '<body style="margin:0px; padding:15px; color:'.$texte[0].'; background-color:'.$texte[2].'; background-image:none; font-family:'.$page[1].'; font-size:'.$page[2].';" >';
?>
<script type="text/javascript">
    //Récupération du code
    var IPATH = "<?php echo str_replace('/','\/',$site[3]); ?>";
<?php
    if (isset($nametextarea) && isset($nameform)) {
        echo 'editorvalue = window.opener.document.forms[\''.$nameform.'\'].elements[\''.$nametextarea.'\'].value;';
    } else {
		echo 'alert(\'Une erreur est survenue car les noms du form et du textarea ne sont pas définis\');';
    }

	echo 'editorvalue = editorvalue.replace (/src=\"inc\//gi,"src=\"" + IPATH + "inc/");'."\n";
	foreach($accessRepUpload as $nameRepUp) {
		echo 'editorvalue = editorvalue.replace (/src=\"'.$nameRepUp.'\//gi,"src=\"" + IPATH + "'.$nameRepUp.'/");'."\n";
		echo 'editorvalue = editorvalue.replace (/src='.$nameRepUp.'\//gi,"src=" + IPATH + "'.$nameRepUp.'/");'."\n";
		echo 'editorvalue = editorvalue.replace (/href=\"'.$nameRepUp.'\//gi,"href=\"" + IPATH + "'.$nameRepUp.'/");'."\n";
		echo 'editorvalue = editorvalue.replace (/value=\"'.$nameRepUp.'\//gi,"value=\"" + IPATH + "'.$nameRepUp.'/");'."\n";
		echo 'editorvalue = editorvalue.replace (/data=\"'.$nameRepUp.'\//gi,"data=\"" + IPATH + "'.$nameRepUp.'/");'."\n";
	}
?>
    document.write(editorvalue);
</script>
<!--
<hr style="margin-top:15px;" />
<div style="text-align:right;"><button onclick="window.close();"><?php echo $lang_minieditor[70]; ?></button></div>
-->
</body>
</html>
<?php
}
