<?php
/*
     Plugin PostGuestEditor
	 Version  : 2.0 (2006/12/05)
	 Compatibility : Guppy v4.5.x
	 Licence  : GNU Lesser General Public License
	 Author   : jérôme CROUX (Djchouix)
     Web site : http://lebrikabrak.info/
     E-mail   : jchouix@wanadoo.fr
*/

header('Pragma: no-cache');
define('CHEMIN', '../../../');
//include CHEMIN.'inc/includes.inc';
include CHEMIN.'data/config.inc';
$lng = isset($_GET['lng'])? $_GET['lng'] : 'en';
$configpath = isset($_GET['configpath'])? $_GET['configpath'] : null;
$wysiwyg = isset($_GET['wysiwyg'])? (boolean) $_GET['wysiwyg'] : false;
if ($wysiwyg) {
	$nameditor = isset($_GET['nameditor'])? $_GET['nameditor'] : null;
	if (!preg_match("`^[-a-z0-9_]+$`i", $lng.$nameditor) || !preg_match("`^[-a-z0-9_][-a-z0-9_/]+/$`i", $configpath)) die('erreur dans les variables passées en paramètre !');
} else {
	$nameform = isset($_GET['nameform'])? $_GET['nameform'] : null;
	$nametextarea = isset($_GET['nametextarea'])? $_GET['nametextarea'] : null;
	if (!preg_match("`^[-a-z0-9_]+$`i", $lng.$nameform.$nametextarea) || !preg_match("`^[-a-z0-9_][-a-z0-9_/]+/$`i", $configpath)) die('erreur dans les variables passées en paramètre !');
}
$headinc = '';
define('PATH_PGEDITOR', 'inc/pgeditor/');		//Chemin relatif de l'éditeur
define('PATH_CONFIG_PGEDITOR', $configpath); 	//Chemin relatif du fichier de configuration 
include CHEMIN.PATH_PGEDITOR.'pgeditor.php';
$allowedExtImage = explode('|', ALLOWED_EXTIMG);
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title><?php echo $lang_pgeditor[18]; ?></title>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset; ?>" />
<meta http-equiv="Content-Style-Type" content="text/css" />
<link rel="stylesheet" type="text/css" media="screen" href="<?php echo CHEMIN.PATH_CSS_PGEDITOR ?>pgeditor_popup.css" />
<!--//Patch CSS for IE browsers-->
<!--[if lte IE 7]>
<link rel="stylesheet" type="text/css" media="screen" href="<?php echo CHEMIN.PATH_CSS_PGEDITOR ?>pgeditor_popup-ie.css" />
<![endif]-->
<style type="text/css">
html, body {
	margin:0px;
	padding:0px;
	text-align:center;
}
.corpsEmoticon {
	margin-left:auto;
	margin-right:auto;
}
.imageEmoticon {
	vertical-align:middle;
	cursor:pointer;
	margin:2px;
	border: none;
}
</style>
</head>
<body class="popupSmileys" onload="window.focus()">
<div class="corpsEmoticon">
<?php
$smileys = array();
$i = 0;
$dir = opendir(CHEMIN.PATH_SMILEY);
while (false !== ($file = readdir($dir))) {
	if (is_file(CHEMIN.PATH_SMILEY.$file) && ($file != 'index.php') &&  in_array(substr(strrchr($file, '.'),1), $allowedExtImage)) {
		$smileys[$i][0] = $file;			
		$smileys[$i][1] = substr_replace($file, '', strrpos($file, '.'));
		$imgSize = getimagesize(CHEMIN.PATH_SMILEY.$smileys[$i][0]);
		$smileys[$i][2] = $imgSize[3];
		$i++;	
	}		
}
closedir($dir);
if ($wysiwyg) {
	for ($i = 0; $i < count($smileys); $i++) {
		echo '<img src="'.BASEPATH.PATH_SMILEY.$smileys[$i][0].'" '.$smileys[$i][2].' class="imageEmoticon" title="'.$smileys[$i][1].'" alt="'.$smileys[$i][1].'" onclick="opener.'.$nameditor.'.addImage(\''.BASEPATH.PATH_SMILEY.$smileys[$i][0].'\')" />&nbsp;'."\n";
	}
} else {
	for ($i = 0; $i < count($smileys); $i++) {
		echo '<a href="javascript:opener.AddSmiley(\'%3Cimg='.$smileys[$i][0].'%3E\',\''.$nameform.'\',\''.$nametextarea.'\');window.close();" title="smiley '.$smileys[$i][1].'"><img src="'.BASEPATH.PATH_SMILEY.$smileys[$i][0].'" '.$smileys[$i][2].' class="imageEmoticon" title="'.$smileys[$i][1].'" alt="'.$smileys[$i][1].'" onclick="opener.AddSmiley(\'<img='.$smileys[$i][0].'>\', \''.$nameform.'\', \''.$nametextarea.'\'); window.close(); return false;" /></a>&nbsp;'."\n";
	}
}
unset($smileys);
?>
</div>
</body>
</html>
