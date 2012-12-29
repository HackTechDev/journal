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
if(!preg_match("`^[-a-z0-9_]+$`i",$lng) || !preg_match("`^[-a-z0-9_][-a-z0-9_/]+/$`i",$configpath)) die('erreur dans les variables passées en paramètre !');
$headinc = '';
define('PATH_PGEDITOR', 'inc/pgeditor/');		//Chemin relatif de l'éditeur
define('PATH_CONFIG_PGEDITOR', $configpath); 	//Chemin relatif du fichier de configuration 
include(CHEMIN.PATH_PGEDITOR.'pgeditor.php');
$allowedExtImage = explode('|', ALLOWED_EXTIMG);
//Insertion fichier de langue
if(file_exists(CHEMIN.PATH_PGEDITOR.'lang/'.$lng.'_pgeditor.inc')) {
	include(CHEMIN.PATH_PGEDITOR.'lang/'.$lng.'_pgeditor.inc');
} else {
	include(CHEMIN.PATH_PGEDITOR.'lang/en_pgeditor.inc');
}	
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title><?php echo $lang_smiley_pgeditor[0]; ?></title>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset; ?>" />
<meta http-equiv="Content-Style-Type" content="text/css" />
<style type="text/css">
body {
	text-align:center;
	color:#000000;
	background-color:#ECE9D8;
}
h1 {
	text-align:left;
	font-size:x-large;
}
hr {
	margin-top:30px;
	border:1px solid #ECE9D8;
}
table {
	padding:0px;
	width:90%;
	border:1px solid #000000;
	margin:0px auto 20px;
	background-color:#FDFDFD;
	color:#000000;
	text-align:left;
}
th {
	background-color:#F5F5DC;
	color:#000000;
	border-bottom:1px solid #000000;
	padding:2px 15px;
}
td {
	padding:5px 15px;
}
th.view {
	text-align:center;
	background-color:#F5F5DC;
	color:#000000;
	border-bottom:1px solid #000000;
	padding:3px;
}
td.view {
	text-align:center;
	padding:3px;
}
span.name {
	color:red;
	font-weight:bold;
}
</style>
</head>
<body>
<?php
/**
* Liste des 11 smileys de base de Guppy
**/
$smileyGuppy = array(
				'cool' => $lang_smiley_pgeditor[1], 'wink' => $lang_smiley_pgeditor[2], 'biggrin' => $lang_smiley_pgeditor[3],
				'smile' => $lang_smiley_pgeditor[4], 'frown' => $lang_smiley_pgeditor[5], 'eek' => $lang_smiley_pgeditor[6],
				'mad' => $lang_smiley_pgeditor[7], 'confused' => $lang_smiley_pgeditor[8], 'rolleyes' => $lang_smiley_pgeditor[9],
				'tongue' => $lang_smiley_pgeditor[10], 'cry' => $lang_smiley_pgeditor[11]
				);
echo '
	<h1>'.$lang_smiley_pgeditor[12].'</h1>
	<table cellspacing="0" cellpadding="0">
	<tbody>
	<tr>
	<th>'.$lang_smiley_pgeditor[13].'</th>
    <th>'.$lang_smiley_pgeditor[14].'</th>
    <th class="view">'.$lang_smiley_pgeditor[15].'</th>
    </tr>
';
foreach($smileyGuppy as $name => $trad) {
	if(file_exists(CHEMIN.PATH_GUPPYSMILEY.$name.'.gif')) { 
		$imgSize = getimagesize(CHEMIN.PATH_GUPPYSMILEY.$name.'.gif');
		echo '
			<tr>
			<td title="'.$trad.'"><span class="name">'.$name.'</span></td>
			<td>&lt;img=<span class="name">'.$name.'</span>&gt;</td>
			<td class="view"><img src="'.CHEMIN.PATH_GUPPYSMILEY.$name.'.gif" '.$imgSize[3].' alt="'.$name.'" title="'.$name.'" /></td>
			</tr>
		';
	}
}
echo '
	</tbody>
	</table>
';
unset($smileyGuppy);

/**
* Liste des autres smileys disponibles
**/
$smileys = array();
$i = 0;
$dir = opendir(CHEMIN.PATH_SMILEY);
while (false !== ($file = readdir($dir))) {
	if(is_file(CHEMIN.PATH_SMILEY.$file) && ($file != 'index.php') &&  in_array(substr(strrchr($file,'.'),1), $allowedExtImage)) {
		$smileys[$i][0] = $file;			
		$smileys[$i][1] = substr_replace($file,'',strrpos($file,'.'));
		$imgSize = getimagesize(CHEMIN.PATH_SMILEY.$smileys[$i][0]);
		$smileys[$i][2] = $imgSize[3];
		$i++;	
	}		
}
closedir($dir);
if(count($smileys)>0) {
	echo '
		<hr />
		<h1>'.$lang_smiley_pgeditor[16].'</h1>
		<table cellpadding="0" cellspacing="0">
		<tbody>
		<tr>
		<th>'.$lang_smiley_pgeditor[13].'</th>
    	<th>'.$lang_smiley_pgeditor[14].'</th>
    	<th class="view">'.$lang_smiley_pgeditor[15].'</th>
   	 	</tr>
	';
	for ($i = 0; $i < count($smileys); $i++) {
		echo '
			<tr>
			<td title="'.$smileys[$i][0].'"><span class="name">'.$smileys[$i][0].'</span></td>
			<td>&lt;img=<span class="name">'.$smileys[$i][0].'</span>&gt;</td>
			<td class="view"><img src="'.CHEMIN.PATH_SMILEY.$smileys[$i][0].'" '.$smileys[$i][2].' title="'.$smileys[$i][0].'" alt="'.$smileys[$i][0].'" /></td>
			</tr>
		';
	}
	echo '
		</tbody>
		</table>
	';
}
unset($smileys);
?>
</body>
</html>