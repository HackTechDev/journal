<?php
/*
    Admin preview popup - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :

      v4.6.0 (15 February 2007)   : initial release by Djchouix
*/

header("Pragma: no-cache");
define("CHEMIN", "../");
include CHEMIN."inc/includes.inc";

include CHEMIN.'admin/action.php';
if ($wri == 'admin') {
    if (FileDBExist(CHEMIN.'admin/mdp.php')) {
        include CHEMIN.'admin/mdp.php';
	} else {
	    $mdp = 'bad';
	}
} else {
    if (FileDBExist(CHEMIN.'admin/'.REDACREP.$wri.INCEXT)) {
        include(CHEMIN.'admin/'.REDACREP.$wri.INCEXT);
        $mdp = md5($drtuser[38]);
    } else {
        $mdp = 'bad';
    }
}
$portalname = 'GuppyAdmin';
if (empty($_COOKIE[$portalname]) || $_COOKIE[$portalname] != crc32($mdp)) {
    die('Une erreur d\'identification est survenue. Veuillez contacter l\'administrateur du site.');
} else {

	/*************************************************************************************************************************
	 * Initialisation des variables et fonctions
	 */
	$lng = isset($_GET['lng']) ? strip_tags($_GET['lng']) : NULL; //langue
	$cat = isset($_GET['cat']) ? strip_tags($_GET['cat']) : NULL; //categorie
	$opt = isset($_GET['opt']) ? strip_tags($_GET['opt']) : NULL; //option

	if (!preg_match("`^[-a-z0-9_]+$`i", $lng.$cat.$opt)) {
		die('ERROR in $lng or $cat or $opt');
	}

	/**
	 * display_img()
	 * Affiche les fichiers images contenu dans un répertoire
	 * @param $cat string Catégorie sélectionnée
	 * @param $opt string Nom du fichier ou du répertoire selon la catégorie choisi
	 * @return $html string Code HTML destiné à être affiché
	 */
	function display_img($cat, $name)
	{
		$html = '';

		switch($cat) {
			case 'skin_preview' :
				$imgPath = CHEMIN.'skin/'.$name.'/'.$name.'.jpg';
				if (is_file($imgPath)) {
					$imgSize = @getimagesize($imgPath);
					$html .= '<img src="'.$imgPath.'" '.$imgSize[3].' alt="'.$name.'" />';
				} else {
					$html .= '
						<p>Nous sommes désolé mais la prévisualition de cette skin n\'est pas possible car le fichier image <strong class="notice">'.$name.'.jpg</strong> n\'existe pas dans le répertoire du skin <strong class="notice">'.$name.'</strong>.</p>
						<p>Veuillez contacter l\'auteur de la skin pour la lui demander.</p>
					';
				}
				break;
			case 'smileys_preview' :
				$dirPath = CHEMIN.'inc/img/smileys/'.$name.'/';
				$html .= constructTagImg($dirPath);
				break;
			case 'avatars_preview' :
				$dirPath = CHEMIN.'inc/img/avatars/'.$name.'/';
				$html .= constructTagImg($dirPath);
				break;
			case 'icons_preview' :
				$dirPath = CHEMIN.'inc/img/icons/'.$name.'/';
				$html .= constructTagImg($dirPath);
				break;
			case 'counter_preview' :
				$dirPath = CHEMIN.'inc/img/counter/'.$name.'/';
				$html .= constructTagImg($dirPath);
				break;

			default :
				$html = '';
		}

		return $html;
	}

	/**
	 * constructTagImg()
	 * Contruit les tags html des images contenues dans un répertoire
	 * @param $dirPath string Url du répertoire
	 * @return $html string Code html des images
	 */
	function constructTagImg($dirPath)
	{
		$html = '';
		$imgName = listImgFiles($dirPath);
		for($i = 0; $i < count($imgName); $i++) {
			$imgPath = $dirPath.$imgName[$i];
			$imgSize = @getimagesize($imgPath);
			$html .= '<img src="'.$imgPath.'" '.$imgSize[3].' alt="'.$imgName[$i].'" style="margin:3px;" />';
		}
		return $html;
	}

	/**
	 * listImgFiles()
	 * Liste les fichiers images contenu dans un répertoire parent
	 * @param $dirPath string Url du répertoire parent
	 * @return $fileNames array Tableau contenant les noms des fichiers images listés dans le répertoire parent
	 */
	function listImgFiles($dirPath)
	{
		$extAllowed = array('.gif','.png','.jpg','.jpeg');
		$fileNames = array();
		$dossier = opendir($dirPath);
		while (false !== ($fichier = readdir($dossier))) {
			$ext = strrchr($fichier, '.');
			if (is_file($dirPath.$fichier) && in_array($ext, $extAllowed)) {
				$fileNames[] = $fichier;
			}
		}
		closedir($dossier);

		return $fileNames;
	}


	/*************************************************************************************************************************
	 * Construction de la page
	 */
?>
	<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
	<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
	<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset; ?>" />
	<meta http-equiv="Content-Style-Type" content="text/css" />
	<title><?php echo 'Prévisualition'; ?></title>
<?php
	if (file_exists($meskin."style.css")){
		echo '<link type="text/css" rel="stylesheet" href="'.$meskin.'style.css" />';
	} else {
		echo '<style type="text/css">';
		if(file_exists($meskin."style.inc")) {
			include $meskin.'style.inc';
		} else {
			include CHEMIN.'inc/style.inc';
		}
		echo '</style>';
	}
?>
	<script type="text/javascript">
		function init()
		{
			var size = getSizeBlock("preview");
			var blockWidth = size[0];
			var blockHeight = size[1];

    		if (blockWidth <= 600 && blockHeight <= 400) {
				var windowHeight = getWindowHeight(blockHeight); //Hauteur de la fenêtre
				window.resizeTo(blockWidth, windowHeight); //Redimensionnment
				moveWindowToMiddleScreen(blockWidth, windowHeight); //Recentrage
			}
		};

		/**
		 * getSizeBlock
		 * récupère la taille (largeur et hauteur) d'un block
		 * @return array  array(width, height)
		 */
		function getSizeBlock(id)
		{
			var size = new Array();
			if (document.getElementById(id)) {
				size[0] = document.getElementById(id).offsetWidth; //Width
				size[1] = document.getElementById(id).offsetHeight; //Height
			}

			return size;
		};

		/**
		 * getWindowHeight
		 * récupère la hauteur de la fenêtre en tenant compte des barres d'adresse des navigateurs
		 * @param height integer hauteur du block dans la fenêtre
		 */
		function getWindowHeight(blockHeight)
		{
			var windowHeight = blockHeight;

			if (typeof(document.all) == 'object' && typeof(window.opera) != 'object') { //IE
				if (navigator.userAgent.indexOf("MSIE 7") != -1) { //IE 7
					windowHeight += 83;
				} else { //IE 5.x et 6
					windowHeight += 62;
				}
			} else if (typeof(window.sidebar) == 'object' && typeof(window.opera) != 'object' && navigator.userAgent.indexOf("Konqueror") == -1) { //Gecko
				windowHeight += 62;
			} else if (typeof(window.opera) == 'object') { //Opera
				windowHeight += 50;
			} else if (navigator.userAgent.indexOf("Safari") != -1 ) { //Safari
				windowHeight += 24;
			} else if (navigator.userAgent.indexOf("Konqueror") != -1 ) { //Konqueror
				windowHeight += 35;
			}

			return windowHeight;
		}

		/**
		 * moveWindowToMiddleScreen
		 * positionne la fenêtre au milieu de l'écran
		 * @param width integer largeur de la fenêtre
		 * @param height integer hauteur de la fenêtre
		 */
		function moveWindowToMiddleScreen(width, height)
		{
			var deltaX = (window.screen.availWidth - width) / 2;;
			var deltaY = (window.screen.availHeight - height) / 2;

			if (typeof(window.opera) != 'object') { //Correction navigateurs sauf opera
				deltaY += 60;
			}

			window.moveTo(Math.floor(deltaX), Math.floor(deltaY));
		}
	</script>
	</head>
	<body onload="init()" style="margin:0; padding:0; color:<?php echo $texte[0]; ?>; background-color:<?php echo $texte[2]; ?>; background-image:none; font-family:<?php echo $page[1]; ?>; font-size:<?php echo $page[2]; ?>;" >
	<div id="preview" style="margin:0;padding:15px;text-align:center;cursor:pointer;" onclick="window.close();" title="Fermer la fenêtre en cliquant dessus">
		<?php echo display_img($cat, $opt); ?>
	</div>
	</body>
	</html>
<?php
}
?>
