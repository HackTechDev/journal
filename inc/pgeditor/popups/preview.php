<?php
/*
     Plugin PostGuestEditor
	 Version  : 2.5.0b2 (2006/12/05)
	 Compatibility : Guppy v4.5.x
	 Licence  : GNU Lesser General Public License
	 Author   : jérôme CROUX (Djchouix)
     Web site : http://lebrikabrak.info/
     E-mail   : jchouix@wanadoo.fr
*/

header('Pragma: no-cache');
define('CHEMIN', '../../../');
include CHEMIN.'inc/includes.inc';
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
define('PATH_PGEDITOR', 'inc/pgeditor/');		//Chemin relatif de l'éditeur
define('PATH_CONFIG_PGEDITOR', $configpath); //Chemin relatif du fichier de configuration
define('WYSIWYG', $wysiwyg);		//Type d'éditeur
include CHEMIN.PATH_PGEDITOR.'pgeditor.php';
include CHEMIN.PATH_PGEDITOR.'syntaxcolor/syntaxcolor.php'; //Coloration syntaxique

$send = isset($_POST['send'])? $_POST['send'] : null;
if ($send == 'ok') {
	$ptxt = recupCodePGEditor('code');
	$ptxt = parseCodePGEditor($ptxt);
//	$ptxt = str_replace(' src="',' src="'.BASEPATH, $ptxt);
	$ptxt = preg_replace_callback(	// Path des images
		'` src="([^"]+)"`',
		create_function(
            '$matches',	
			'return (strpos($matches[1], "http://") === FALSE)? " src=\"".BASEPATH.$matches[1]."\"" : $matches[0];'
        ),
        $ptxt
	);

	$ptxt = colorCode($ptxt); //Coloration syntaxique
}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title><?php echo $lang_pgeditor[19]; ?></title>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset; ?>" />
<meta http-equiv="Content-Style-Type" content="text/css" />
<link type="text/css" rel="stylesheet" href="<?php echo CHEMIN.PATH_CSS_PGEDITOR; ?>pgeditor.css" />
<!-- compliance patch for microsoft browsers -->
<!--[if lt IE 7]>
	<link rel="stylesheet" type="text/css" media="screen" href="<?php echo CHEMIN.PATH_CSS_PGEDITOR; ?>pgeditor-ie.css" />
<![endif]-->
<link type="text/css" rel="stylesheet" href="<?php echo CHEMIN.PATH_CSS_PGEDITOR; ?>syntaxcolor.css" />  <!-- Coloration syntaxique -->
<?php
if (file_exists($meskin."style.css")) {
   echo '<link type="text/css" rel="stylesheet" href="'.$meskin.'style.css" />'."\n";
} else {
   echo '<style type="text/css">'."\n";
   $meskin = file_exists($meskin.'style.inc')? $meskin : CHEMIN;
   include($meskin.'style.inc');
   echo '</style>'."\n";
}

if ($send != 'ok') {
	echo '
		<script type="text/javascript">
		function Preview()
		{	
	';
	if ($wysiwyg) {
		echo '
			var htmlcode = window.opener.document.getElementById("'.$nameditor.'_WYSIWYG_PGEditor").contentWindow.document.body.innerHTML;
			htmlcode = opener.'.$nameditor.'.parseImage(htmlcode);
			document.forms["preview"].elements["code_content"].value = htmlcode;
		';
	} else {
		echo '
			var htmlcode = window.opener.document.forms["'.$nameform.'"].elements["'.$nametextarea.'"].value;
			document.forms["preview"].elements["code"].value = htmlcode;
		';
	}
	echo '
			document.preview.submit();
		}
		</script>
	';
}
?>
</head>
<body class="tblbox">
<?php
if ($send == 'ok') {
	echo '
		<div class="preview">
			<div class="content">
	 		'.$ptxt.'
			</div>
		</div>
		<hr style="margin-top:15px;" />
		<div style="text-align:right;"><button title="'.$lang_pgeditor[1].'" onclick="window.close();">'.$lang_pgeditor[1].'</button></div>
	'."\n";
} else {
	$nameContent = ($wysiwyg)? 'code_content' : 'code';
	
	echo '
  		<form name="preview" action="preview.php?lng='.$lng.'&amp;wysiwyg='.$wysiwyg.'&amp;configpath='.$configpath.'" method="post">
  		<input type="hidden" name="send" value="ok" />
		<input type="hidden" name="'.$nameContent.'" value="" />
  		</form>
  		<script type="text/javascript"> 
    		Preview();
 		</script>
  	'."\n";
}
?>
</body>
</html>
