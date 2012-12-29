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
if(!preg_match("`^[-a-z0-9_]+$`i",$lng)) $lng = 'en';
define('PATH_PGEDITOR', 'inc/pgeditor/');		//Chemin relatif de l'éditeur
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
<title><?php echo $lang_color_pgeditor[18]; ?></title>
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
	margin-top:50px;
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
	width:25%;
}
td.view {
	text-align:center;
	padding:3px;
}
p.warning {
	text-align:left;
}
span.warning {
	text-decoration:underline;
	font-size: large;
}
</style>
</head>
<body>
<?php
//Liste des 16 couleurs HTML officielles + 1 rajoutée dans le CSS 2.1
$colorWebSafe = array( 
	'black' => array('#000000',$lang_color_pgeditor[1]), 'gray' => array('#808080',$lang_color_pgeditor[2]), 'silver' => array('#C0C0C0',$lang_color_pgeditor[3]), 'white' => array('#FFFFFF',$lang_color_pgeditor[4]), 'red' => array('#FF0000',$lang_color_pgeditor[6]), 'maroon' => array('#800000',$lang_color_pgeditor[5]),
	'orange' => array('#FFA500',$lang_color_pgeditor[7]), 'yellow' => array('#FFFF00',$lang_color_pgeditor[8]), 'lime' => array('#00FF00',$lang_color_pgeditor[9]), 'green' => array('#008000',$lang_color_pgeditor[10]), 'olive' => array('#808000',$lang_color_pgeditor[11]), 'aqua' => array('#00FFFF',$lang_color_pgeditor[12]),
	'blue' => array('#0000FF',$lang_color_pgeditor[13]), 'teal' => array('#008080',$lang_color_pgeditor[14]), 'navy' => array('#000080',$lang_color_pgeditor[15]), 'fuchsia' => array('#FF00FF',$lang_color_pgeditor[16]), 'purple' => array('#800080',$lang_color_pgeditor[17])			
);		

echo '
	<h1>'.$lang_color_pgeditor[0].'</h1>
	<table cellspacing="0" cellpadding="0">
	<tbody>
	<tr>
	<th>'.$lang_color_pgeditor[19].'&nbsp;('.$lang_color_pgeditor[22].')</th>
    <th>'.$lang_color_pgeditor[20].'</th>
    <th class="view">'.$lang_color_pgeditor[21].'</th>
    </tr>
';
foreach($colorWebSafe as $nameColor => $color) {
	echo '
		<tr>
		<td title="'.$color[1].'">'.$nameColor.'&nbsp;('.$color[1].')</td>
		<td title="'.$color[1].'">'.$color[0].'</td>
		<td class="view" bgcolor="'.$nameColor.'" title="'.$color[1].'">'.$nameColor.'</td>
		</tr>
	';
}
echo '
	</tbody>
	</table>
';
unset($colorWebSafe);

//Liste des 140 couleurs "non officielles"
$colorWebExtend = array(
	//Gris
	$lang_color_pgeditor[2] => array(
		'black' => '#000000', 'slategray' => '#708090', 'lightslategray' => '#778899', 'dimgray' => '#696969',
		'gray' => '#808080', 'darkgray' => '#A9A9A9', 'silver' => '#C0C0C0', 'lightgrey' => '#D3D3D3',
		'gainsboro' => '#DCDCDC', 'whitesmoke' => '#F5F5F5', 'white' => '#FFFFFF'						
	),
	//Marron			
	$lang_color_pgeditor[5] => array(
		'brown' => '#A52A2A', 'maroon' => '#800000', 'darkred' => '#8B0000', 'sienna' => '#A0522D',
		'chocolate' => '#D2691E', 'saddlebrown' => '#8B4513', 'peru' => '#CD853F', 'tan' => '#D2B48C',
		'burlywood' => '#DEB887', 'goldenrod' => '#DAA520', 'darkgoldenrod' => '#B8860B'
	),
	//Rouge
	$lang_color_pgeditor[6] => array(
		'snow' => '#FFFAFA', 'rosybrown' => '#BC8F8F', 'lightcoral' => '#F08080', 'indianred' => '#CD5C5C',
		'red' => '#FF0000', 'mistyrose' => '#FFE4E1', 'salmon' => '#FA8072', 'darksalmon' => '#E9967A',
		'firebrick' => '#B22222', 'lightsalmon' => '#FFA07A', 'tomato' => '#FF6347', 'crimson' => '#DC143C'
	),
	//Orange
	$lang_color_pgeditor[7] => array(
		'orangered' => '#FF4500', 'coral' => '#FF7F50', 'seashell' => '#FFF5EE', 'peachpuff' => '#FFDAB9',
		'linen' => '#FAF0E6', 'bisque' => '#FFE4C4', 'darkorange' => '#FF8C00', 'antiquewhite' => '#FAEBD7',
		'navajowhite' => '#FFDEAD', 'papayawhip' => '#FFEFD5', 'sandybrown' => '#F4A460', 'blanchedalmond' => '#FFEBCD',
		'moccasin' => '#FFE4B5', 'floralwhite' => '#FFFAF0', 'oldlace' => '#FDF5E6', 'wheat' => '#F5DEB3', 'orange' => '#FFA500'
	),
	//Jaune
	$lang_color_pgeditor[8] => array(
		'cornsilk' => '#FFF8DC', 'gold' => '#FFD700', 'lemonchiffon' => '#FFFACD', 'khaki' => '#F0E68C',
		'palegoldenrod' => '#EEE8AA', 'darkkhaki' => '#BDB76B', 'ivory' => '#FFFFF0', 'beige' => '#F5F5DC',
		'lightyellow' => '#FFFFE0', 'lightgoldenrodyellow' => '#FAFAD2', 'yellow' => '#FFFF00'
	),
	//Vert
	$lang_color_pgeditor[10] => array(
		'olive' => '#808000', 'olivedrab' => '#6B8E23', 'yellowgreen' => '#9ACD32', 'darkolivegreen' => '#556B2F',
		'greenyellow' => '#ADFF2F', 'lawngreen' => '#7CFC00', 'chartreuse' => '#7FFF00', 'honeydew' => '#F0FFF0',
		'darkseagreen' => '#8FBC8F', 'lightgreen' => '#90EE90', 'palegreen' => '#98FB98', 'forestgreen' => '#228B22',
		'limegreen' => '#32CD32', 'darkgreen' => '#006400', 'green' => '#008000', 'lime' => '#00FF00', 'mediumseagreen' => '#3CB371',
		'seagreen' => '#2E8B57', 'mintcream' => '#F5FFFA', 'springgreen' => '#00FF7F', 'mediumspringgreen' => '#00FA9A'
	),
	//Bleu
	$lang_color_pgeditor[13] => array(
		'mediumaquamarine' => '#66CDAA', 'aquamarine' => '#7FFFD4', 'turquoise' => '#40E0D0', 'lightseagreen' => '#20B2AA',
		'mediumturquoise' => '#48D1CC', 'azure' => '#F0FFFF', 'lightcyan' => '#E0FFFF', 'paleturquoise' => '#AFEEEE',
		'teal' => '#008080', 'darkcyan' => '#008B8B', 'darkturquoise' => '#00CED1', 'aqua' => '#00FFFF', 'darkslategray' => '#2F4F4F', 'cadetblue' => '#5F9EA0',
		'powderblue' => '#B0E0E6', 'lightblue' => '#ADD8E6', 'deepskyblue' => '#00BFFF', 'skyblue' => '#87CEEB',
		'lightskyblue' => '#87CEFA', 'aliceblue' => '#F0F8FF', 'steelblue' => '#4682B4', 'dodgerblue' => '#1E90FF',
		'lightsteelblue' => '#B0C4DE', 'cornflowerblue' => '#6495ED', 'royalblue' => '#4169E1', 'ghostwhite' => '#F8F8FF',
		'lavender' => '#E6E6FA', 'midnightblue' => '#191970', 'navy' => '#000080', 'darkblue' => '#00008B', 'mediumblue' => '#0000CD',
		'blue' => '#0000FF', 'darkslateblue' => '#483D8B', 'slateblue' => '#6A5ACD','mediumslateblue' => '#7B68EE'
	),
	//Violet
	$lang_color_pgeditor[17] => array(
		'mediumpurple' => '#9370DB', 'blueviolet' => '#8A2BE2', 'indigo' => '#4B0082', 'darkorchid' => '#9932CC', 
		'darkviolet' => '#9400D3', 'mediumorchid' => '#BA55D3', 'thistle' => '#D8BFD8', 'plum' => '#DDA0DD', 'violet' => '#EE82EE',
		'purple' => '#800080', 'darkmagenta' => '#8B008B', 'fuchsia' => '#FF00FF', 'orchid' => '#DA70D6',
		'mediumvioletred' => '#C71585', 'deeppink' => '#FF1493', 'hotpink' => '#FF69B4', 'lavenderblush' => '#FFF0F5',
		'palevioletred' => '#DB7093', 'pink' => '#FFC0CB', 'lightpink' => '#FFB6C1'
	)
);
		
echo '
	<hr />
	<h1>'.$lang_color_pgeditor[23].'</h1>
	<p class="warning">'.$lang_color_pgeditor[24].'</p>
';

$i = 0;
foreach($colorWebExtend as $cat => $colors) {
	echo '
		<h2>'.$cat.'</h2>
		<table cellspacing="0" cellpadding="0">
		<tbody>
		<tr>
		<th>'.$lang_color_pgeditor[19].'</th>
    	<th>'.$lang_color_pgeditor[20].'</th>
    	<th class="view">'.$lang_color_pgeditor[21].'</th>
    	</tr>
	';
	foreach($colors as $nameColor => $codeColor ) {
		echo '
			<tr>
			<td>'.$nameColor.'</td>
			<td title="'.$nameColor.'">'.$codeColor.'</td>
			<td class="view" bgcolor="'.$nameColor.'">'.$nameColor.'</td>
			</tr>
		';
	}
	echo '
		</tbody>
		</table>
	';
}
?>
</body>
</html>
