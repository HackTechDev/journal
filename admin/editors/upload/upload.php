<?php
/*
     MinieditorTextarea réalisé par Djchouix - Licence CeCILL
     Web site = http://lebrikabrak.free.fr/
     e-mail   = lebrikabrak@free.fr
	 version 1.6.2 (22 avril 2006) compatibilité avec guppy v4.5.x
	 
      v4.6.10 (7 September 2009)  : corrected #266 and #272
      v4.6.11 (11 December 2009)  : corrected #305
      v4.6.12 (01 May 2010)       : corrected #320
      v4.6.13 (22 May 2010)       : corrected #320
	  v4.6.20 (24 May 2012)       : corrected insertion image to Chrome (by djchouix)
*/
header("Pragma: no-cache");
define("CHEMIN", "../../../");
include(CHEMIN."inc/includes.inc");
//PROTECTION CONTRE LES PETITS CURIEUX
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
//FIN PROTECTION

//RECUPERATION ET CONTROL DES VARIABLES PASSEES EN PARAMETRE
$pathRepUploadConfig = isset($_POST['pathconfig']) ? $_POST['pathconfig'] : (isset($_GET['pathconfig']) ? $_GET['pathconfig'] : '');
if(!preg_match("!^[a-z]{2,3}$!i",$lng) || ($pathRepUploadConfig != '' && !preg_match("!^[-a-z0-9_]{1}[-a-z0-9_\/]*\/$!i",$pathRepUploadConfig))) die('Erreur dans la valeur des variables. Veuillez contacter le webmaster du site.');
$uptype = isset($_POST['uptype']) ? $_POST['uptype'] : (isset($_GET['uptype']) ? $_GET['uptype'] : 'Image');
if ($uptype != 'Link' && $uptype != 'Image' && $uptype != 'Flash' && $uptype != 'Media') die('Erreur dans la valeur de la variable uptype.Veuillez contacter le webmaster du site.');
$nameRepUploadConfig = isset($_POST['namerepconfig']) ? $_POST['namerepconfig'] : (isset($_GET['namerepconfig']) ? $_GET['namerepconfig'] : NULL);
if (!preg_match('!^[-a-z0-9_\/]+$!i',$nameRepUploadConfig)) die('Erreur dans le nom du répertoire qui contient les fichiers de configuration (variable $namerepconfig).Vous devez utiliser uniquement des lettres et/ou de chiffres et/ou les caractères(-_).Veuillez corriger');
$upvalid = isset($_POST['upvalid']) ? $_POST['upvalid'] : NULL;
if ($upvalid != NULL && $upvalid != 'ok' ) die('Erreur dans la valeur de la variable upvalid.Veuillez contacter l\'administrateur du site.');
$creatrep = isset($_POST['creatrep']) ? strip_tags($_POST['creatrep']) : NULL;	     
$fnewname = isset($_GET['fnewname']) ? strip_tags($_GET['fnewname']) : NULL;	     
$foldname = isset($_GET['foldname']) ? strip_tags($_GET['foldname']) : NULL;	     
$del = isset($_GET['del']) ? strip_tags($_GET['del']) : NULL;
$pathDirMinieditor = 'admin/editors/';    //chemin relatif du répertoire du miniéditeur (à ne pas modifier pour ne pas perdre la compatibilité avec les autres plugins)

//INITIALISATION DES VARIABLES DE CONFIGURATION POUR UPLOAD (A NE SURTOUT PAS MODIFIER !!)
$pathRepUpload = 'admin/editors/';
$allowedUpload = false;
$allowedCreateRep = false;
$allowedRenameRepFile = false;
$allowedDeleteRepFile = false;
$allowedExtFileUpload = array();
$deniedExtFileUpload = array();
$accessRepUpload = array('img','photo','file','pages','flash');
$accessRepUploadImage = array('img','photo');
$accessRepUploadLink = array('file','img','photo','pages','flash');
$accessRepUploadFlash = array('flash','img');
$accessRepUploadMedia = array('flash','img');
$allowedExtImage = array('.jpg','.gif','.png','.bmp','.jpeg');
$deniedExtLink = array();
$allowedExtFlash = array('.swf','.fla','.flv');
$allowedExtMedia = array('.avi','.mp3');
$colorTextTitre = $titre[0];
$colorFondTitre = $titre[1];
$styleBordureTitre = '1px solid '.$bordure[0];
$colorTextCorp = $texte[0];
$colorFondCorp = $texte[2];
$styleBordureCorp = '1px solid '.$bordure[0];
$colorBodyUpload = $texte[1];
$colorFondFileUpload = $texte[2];
$colorFondFileUploadOver = $forum[2];
$colorFileUploadOff = $lien[0];
$colorFileUploadOn = $lien[1];

//RECUPERATION DE LA CONFIGURATION DES VARIABLES DE L'UPLOAD SI ELLE EXISTE
if($pathRepUploadConfig !='' && file_exists(CHEMIN.$pathRepUploadConfig.$nameRepUploadConfig.'/config_upload.inc')) {  
	include(CHEMIN.$pathRepUploadConfig.$nameRepUploadConfig.'/config_upload.inc');  //CONFIGURATION UPLOAD PLUGIN
} elseif(file_exists(CHEMIN.$pathDirMinieditor.'minieditortextarea/config_upload.inc')) {
	include(CHEMIN.$pathDirMinieditor.'minieditortextarea/config_upload.inc');  //CONFIGURATION UPLOAD MINIEDITEUR
}
// RECUPERATION DES FICHIER DE LANGUE
if(file_exists(CHEMIN.$pathRepUpload.'upload/lang/'.$lng.'_upload.inc')) {
	include(CHEMIN.$pathRepUpload.'upload/lang/'.$lng.'_upload.inc');
} else {
	include(CHEMIN.$pathRepUpload.'upload/lang/en_upload.inc'); // FICHIER PAR DEFAUT
}
//FONCTIONS UTILISEES DANS LE SCRIPT
include(CHEMIN.$pathRepUpload.'upload/functions_upload.inc');

//CONTROLE DES REPERTOIRES ECRITS DANS LES VARIABLES $accessRepUpload $accessRepUploadImage $accessRepUploadLink et $accessRepUploadFlash
$accessRepUpload = controlNameRepUpload($accessRepUpload);
$accessRepUploadImage = controlAccessRepUpload($accessRepUploadImage,$accessRepUpload,'Image');
$accessRepUploadLink = controlAccessRepUpload($accessRepUploadLink,$accessRepUpload,'Link');
$accessRepUploadFlash = controlAccessRepUpload($accessRepUploadFlash,$accessRepUpload,'Flash');
$accessRepUploadMedia = controlAccessRepUpload($accessRepUploadMedia,$accessRepUpload,'Media');

//RECUPERATION ET AFFICHAGE DU REPERTOIRE PAR DEFAUT
switch($uptype) {
	case 'Image':
		$repdefault = $accessRepUploadImage[0];
	break;
	case 'Link':
		$repdefault = $accessRepUploadLink[0];
	break;
	case 'Flash':
		$repdefault = $accessRepUploadFlash[0];
	break;
	case 'Media':
		$repdefault = $accessRepUploadMedia[0];
	break;
	default :
		$repdefault = 'img';
}
$rep = isset($_POST['rep']) ? strip_tags($_POST['rep']) : (isset($_GET['rep']) ? strip_tags($_GET['rep']) : $repdefault);

//CREATION D'UN SOUS-REPERTOIRE
if($allowedCreateRep == true) {  //AUTORISATION
	if (isset($creatrep) && trim($creatrep) != "") {
		$creatrep = cleanName($creatrep);
    	if ($creatrep == "0" ) {$creatrep = "0_";}
	
        if (stristr($creatrep, 'script') !== false) {
            echo '
<script type="text/javascript">
    alert("Nom de répertoire interdit - Forbidden directory name !!!");
    history.back();
</script>';
        } else {
    		if(is_dir(CHEMIN.$rep.'/'.$creatrep)){
    	    	$pagerror = 1;
    			$erreur = $lang_upload[1];
        	} else {
    			createNewRep($rep.'/'.$creatrep);
    	  	}
	  	}
	}
}
//RENOMMER UN FICHIER OU UN REPERTOIRE			
if($allowedRenameRepFile == true) { //AUTORISATION
	if (isset($fnewname) && trim($fnewname) != "") {
		$fnewname = cleanName($fnewname);
	
		$fext = strrchr($foldname,'.');
		if(is_file(CHEMIN.$rep.'/'.$foldname)) {	    
	    	if (file_exists(CHEMIN.$rep.'/'.$fnewname.$fext)){
	  	   		$pagerror = 1; 
		   		$erreur = $lang_upload[2];
	    	} else {	      
              	@rename(CHEMIN.$rep.'/'.$foldname , CHEMIN.$rep.'/'.$fnewname.$fext);
			  	@chmod(CHEMIN.$rep.'/'.$fnewname.$fext,0644);
	      	}
		} else if(is_dir(CHEMIN.$rep.'/'.$foldname)) {
	    	if ($fnewname == "0" ){$fnewname = "0_";}	    
	    	if (is_dir(CHEMIN.$rep.'/'.$fnewname)){
	  	   		$pagerror = 1; 
		   		$erreur = $lang_upload[3];
	    	} else {	                
	          	@rename(CHEMIN.$rep.'/'.$foldname , CHEMIN.$rep.'/'.$fnewname);
			  	@chmod(CHEMIN.$rep.'/'.$fnewname,0755);
	       	}	
      	}
	}
}
//SUPPRIMER UN FICHIER OU UN REPERTOIRE
if($allowedDeleteRepFile == true) { //AUTORISATION
	if (isset($del) && trim($del) != "") {
  		if(is_file(CHEMIN.$rep."/".$del)) {
      		@unlink(CHEMIN.$rep."/".$del);
  		}
  		if(is_dir(CHEMIN.$rep."/".$del)) {
      		DelSubRep(CHEMIN.$rep."/".$del."/");
	  		if(rmdir(CHEMIN.$rep."/".$del) == false) {
	  	 		$pagerror = 1;
		 		$erreur = $lang_upload[4]; 
	  		}
  		}      	  
	}
}
//UPLOAD DES FICHIERS
if($allowedUpload == true) { //AUTORISATION
	if (isset($_FILES['ficup']['name']) && trim($_FILES['ficup']['name']) != "" && $upvalid == "ok") {
    	$pagerror = 0;
		$_FILES['ficup']['name'] = strip_tags($_FILES['ficup']['name']);
		$_FILES['ficup']['name'] = cleanName($_FILES['ficup']['name'],true);

		if (!preg_match('!^([-a-z0-9_]+)(\.)([a-z0-9]{2,4})$!i',$_FILES['ficup']['name'])){ //CONTROL SI NOM FICHIER VALIDE
	     	$pagerror = 1;
		 	$erreur = $lang_upload[5]; 
		}
		if (file_exists(CHEMIN.$rep.'/'.$_FILES['ficup']['name'])){ //CONTROL SI NOM DU FICHIER DEJA PRESENT
	     	$pagerror = 1; 
		 	$erreur = $lang_upload[6];
		}
		if((count($allowedExtFileUpload) > 0 && !in_array(strrchr($_FILES['ficup']['name'],'.'),$allowedExtFileUpload)) || (count($deniedExtFileUpload) > 0 && in_array(strrchr($_FILES['ficup']['name'],'.'),$deniedExtFileUpload))) { //AUTORISATION EXTENSION DU FICHIER
	     	$pagerror = 1; 
		 	$erreur = $lang_upload[21];	
		}
		if($pagerror != 1) {	//UPLOAD	
    		if (move_uploaded_file($_FILES['ficup']['tmp_name'], CHEMIN.$rep.'/'.$_FILES['ficup']['name'])) {
	   			@chmod(CHEMIN.$rep.'/'.$_FILES['ficup']['name'], 0644);
    		}
		}
	}
}
//CREATION DE L'INDEX DES FICHIERS
$dbdir = array();
$dbfiles = array();
$i = 0;
$dossier = opendir(CHEMIN.$rep);
while ($fichier = readdir($dossier)) {
    if($fichier != '.' && $fichier != '..' && is_dir(CHEMIN.$rep.'/'.$fichier)) {
    	$dbdir[$i][0] = $fichier;
      	$dbdir[$i][1] = $pathRepUpload.'upload/img/directory.gif';
      	$dbdir[$i][2] = 'dir';
	} else if (is_file(CHEMIN.$rep.'/'.$fichier) && $fichier != 'index.php') {
      	$dbfiles[$i][0] = $fichier;
		$path_parts = strtolower(substr(strrchr($fichier,'.'), 1));
	  	if(file_exists(CHEMIN.$pathRepUpload.'upload/img/'.$path_parts.'.gif')) {
      	  	$dbfiles[$i][1] = $pathRepUpload.'upload/img/'.$path_parts.'.gif';
	  	} else {
      	  	$dbfiles[$i][1] = $pathRepUpload.'upload/img/default.gif';	  
	 	}
	  	$filesize = filesize(CHEMIN.$rep.'/'.$fichier);
	  	$dbfiles[$i][2] = number_format($filesize,0,',',' ');
  	}
	$i++;
}
closedir($dossier);
if(count($dbdir) > 0) sort($dbdir);
if(count($dbfiles) > 0) sort($dbfiles);
$dbfiles = array_merge($dbdir,$dbfiles);

//PAGE HTML
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title><?php echo $lang_upload[13]; ?></title>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset; ?>" />
<meta http-equiv="Content-Style-Type" content="text/css" />
<?php
//INSERTION STYLE CSS
if(file_exists(CHEMIN.$pathRepUploadConfig.$nameRepUploadConfig.'/style_upload.css')) {
  echo '<link type="text/css" rel="stylesheet" href="'.CHEMIN.$pathRepUploadConfig.$nameRepUploadConfig.'/style_upload.css" />';
} elseif(file_exists(CHEMIN.$pathRepUploadConfig.$nameRepUploadConfig.'/style_upload.inc')){
	echo '<style type="text/css">';
	include(CHEMIN.$pathRepUploadConfig.$nameRepUploadConfig.'/style_upload.inc');
	echo '</style>';
} else {
  echo '<link type="text/css" rel="stylesheet" href="'.CHEMIN.$pathRepUpload.'upload/style_upload.css" />';  //STYLE PAR DEFAUT
}
//INSERTION FONCTIONS JAVASCRIPT
?>
<script type="text/javascript">
//REDIMENSIONNEMENT POPUP UPLOAD
function popupUploadSize() {
<?php
	if(!$allowedUpload && !$allowedCreateRep) {
		echo 'window.resizeTo(700,430);';
	} elseif(!$allowedUpload || !$allowedCreateRep){
		echo 'window.resizeTo(700,490);';
	} else {
		echo 'window.resizeTo(700,580);';
	}
?>
}
//AFFICHAGE FICHIER IMAGE DANS POPUP
function popupImgUp(chemin) {
    var hauteurScreen= window.screen.height;
    var largeurScreen= window.screen.width;		
	
    FenImg = window.open("","","directories=0, menubar=0, status=0, resizable=1, scrollbars=0,location=0");
	FenImg.document.open();	
	
	var html = '<html><head><title><?php echo $lang_upload[22]; ?><\/title>'
		html = html+'<script type="text\/javascript">';
		html = html+'function ajustsize()  {';
		html = html+'var hauteurImg = document.images[0].height; var largeurImg = document.images[0].width; var top = ('+hauteurScreen+'- hauteurImg)/2; var left = ('+largeurScreen+'- largeurImg)/2; ';
		html = html+' if (document.images[0].complete) {  window.resizeTo(largeurImg+40,hauteurImg+70); window.moveTo(left,top); window.focus();} else { setTimeout("ajustsize();",500) } }<\/script>';
        html = html+'<\/head><body onload="ajustsize();"><div style="text-align:center; vertical-align:middle;"><img src="'+chemin+'" alt="" onclick="window.close();" /><\/div><\/body><\/html>';

	FenImg.document.write(html);
	FenImg.document.close();
	}	
//AFFICHAGE FICHIER AUTRE QUE IMAGE DANS POPUP
function popupFileUp(chemin) {
    var hauteur = 500;
    var largeur = 700;
    var top=(screen.height-hauteur)/2;
    var left=(screen.width-largeur)/2;
    window.open(chemin, '', 'top='+top+', left='+left+', width='+largeur+', height='+hauteur+', resizable=yes,menubar=no,location=no,directories=no,status=no,copyhistory=no,toolbar=no,scrollbars=yes');
}
<?php
//RENOMMER UN FICHIER OU UN REPERTOIRE
if($allowedRenameRepFile == true) { //AUTORISATION
?>
function renameFile(rep,file,type) {
    if (type == 'file') {
	    message = '<?php echo $lang_upload[27]; ?> "'+file+'".\n';
		message2 = "<?php echo $lang_upload[28]; ?>";
	}
    if (type == 'dir') {
	    message = '<?php echo $lang_upload[29]; ?> "'+file+'".\n';
		message2 = '<?php echo $lang_upload[30]; ?>';
	}
	message = message + '<?php echo $lang_upload[31]; ?>';
	x = null;
    x = window.prompt(message,message2);
	//control de la variable
	erreur = false;
	if(x.search(/^[-a-z0-9_]+$/gi) == -1) erreur = true;
	if (x != null && erreur == false) {
	   window.location = "upload.php?lng=<?php echo $lng; ?>&uptype=<?php echo $uptype; ?>&namerepconfig=<?php echo $nameRepUploadConfig; ?>&pathconfig=<?php echo $pathRepUploadConfig; ?>&rep="+rep+"&foldname="+file+"&fnewname="+x;
	} else {
		  alert('<?php echo $lang_upload[31]; ?>');
	      return false;
	 }
}
<?php
}
//SUPPRIMER UN FICHIER OU UN REPERTOIRE	
if($allowedDeleteRepFile == true) { //AUTORISATION
?>
function confirmDelFile(rep,file,type) {
    if (type == 'file') message = '<?php echo $lang_upload[23]; ?> " '+file+' ".\n';
    if (type == 'dir') message = '<?php echo $lang_upload[24]; ?> " '+file+' " <?php echo $lang_upload[25]; ?>\n';
	message = message + " <?php echo $lang_upload[26]; ?>";
	x = false;
    x = window.confirm(message);
	if (x == true) {
	   window.location = "upload.php?lng=<?php echo $lng; ?>&uptype=<?php echo $uptype; ?>&namerepconfig=<?php echo $nameRepUploadConfig; ?>&pathconfig=<?php echo $pathRepUploadConfig; ?>&rep="+rep+"&del="+file;
	} else {
	      return false;
	}
}
<?php
}
?>
//RETOUR AU REPERTOIRE PARENT
function RepParent(directory) {
	  dir = directory.split("/");
	  dir.length--;
      directory = dir.join("/");
	  x = document.forms["changedir"].elements["rep"].selectedIndex;
	  document.forms["changedir"].elements["rep"].options[x].value = directory;
	  document.forms["changedir"].submit();
}
//RECUPERATION DE L'URL
<?php
if(file_exists(CHEMIN.$pathRepUploadConfig.$nameRepUploadConfig.'/jscript_upload.inc')) {
	include(CHEMIN.$pathRepUploadConfig.$nameRepUploadConfig.'/jscript_upload.inc');
} else {
	echo 'function openURL(url,type,alt,width,height) {window.close();}'."\n";
}
?>
//AFFICHER/MASQUER AIDE
function OpenCloseHelp() {
   if (document.getElementById('helpClose') == null) {
    document.getElementById('help').style.display = 'block';
	document.getElementById('helpOpen').value = "<?php echo $lang_upload[12]; ?>";	
	document.getElementById('helpOpen').id = 'helpClose';	
	} else {
    document.getElementById('help').style.display = 'none';
	document.getElementById('helpClose').value = "<?php echo $lang_upload[11]; ?>";	
	document.getElementById('helpClose').id = 'helpOpen';	
	}
}
//AFFICHER ELEMENT SURVOLE
function MouseOverFile(y,x,z) {
    if (y == 'yes') {
        document.getElementById(x).id = z;
	} else {
        document.getElementById(z).id = x;
	}
}
//VERIFICATION AVANT SOUMISSION POUR UPLOAD
function UploadValid(h,champ) {
	erreur = false;
	msg_erreur = '';
	if(h.elements[champ].value == "") {
	 	erreur = true;
	 	msg_erreur += "<?php echo $lang_upload[20]; ?>\n";
	}
	if(champ == 'ficup') {
		if(h.elements[champ].value.search(/(\\|\/)?([-a-z0-9_]+)(\.)([a-z0-9]{2,4})$/gi) == -1) {
	 		erreur = true;
	 		msg_erreur += "<?php echo $lang_upload[31]; ?>";
		}
	} else {
		if(h.elements[champ].value.search(/^[-a-z0-9_]+$/gi) == -1) {
	 		erreur = true;
	 		msg_erreur += "<?php echo $lang_upload[31]; ?>";
		}	
	}
    if (erreur == false) {
	   return true;
	} else {
	   alert(msg_erreur);
	   return false;
	}
}
</script>
</head>
<body onload="popupUploadSize();">
<?php
switch ($pagerror) {
    case "1" :
        echo '<form name="pbupload" action="upload.php?lng='.$lng.'" method="post" style="margin:0px;">';
		echo '<input type="hidden" name="pg" value="upload" />';
		echo '<input type="hidden" name="rep" value="'.$rep.'" />';
		echo '<input type="hidden" name="uptype" value="'.$uptype.'" />';
		echo '<input type="hidden" name="pathconfig" value="'.$pathRepUploadConfig.'" />';
		echo '<input type="hidden" name="namerepconfig" value="'.$nameRepUploadConfig.'" />';
		echo '<div style="text-align:center; font-weight:bold; margin-top:15px;">'.$erreur.'</div>';
	    echo '<div style="text-align:center; margin-top:15px; margin-bottom:15px;"><input type="submit" class="bouton" id="retour" name="retour" value="'.$lang_upload[33].'" /></div>';    
        echo '</form>';
        break;
    default :
?>
        <div id="help" class="help"><?php echo $lang_upload[7].$lang_upload[19]; ?></div>
        <form name="changedir" action="upload.php?lng=<?php echo $lng; ?>" method="post">
		<input type="hidden" name="uptype" value="<?php echo $uptype; ?>" />
		<input type="hidden" name="pathconfig" value="<?php echo $pathRepUploadConfig; ?>" />
		<input type="hidden" name="namerepconfig" value="<?php echo $nameRepUploadConfig; ?>" />
        <div class="upload">
		<img src="<?php echo CHEMIN.$pathRepUpload; ?>upload/img/directory.gif" width="16" height="16" alt="<?php echo $lang_upload[14]; ?>" title="<?php echo $lang_upload[14]; ?>" /><?php echo $lang_upload[14]; ?>&nbsp;: 
	    <select name="rep" onchange="document.changedir.submit();">
<?php
		switch($uptype) {
			case 'Image' :
				foreach($accessRepUploadImage as $nameRepUploadImage) {
					$repselected = ($rep == $nameRepUploadImage)? ' selected="selected"' : '';
					echo '<option value="'.$nameRepUploadImage.'"'.$repselected.'>'.$nameRepUploadImage.'</option>';
				}
			break;
			case 'Link' :
				foreach($accessRepUploadLink as $nameRepUploadLink) {
					$repselected = ($rep == $nameRepUploadLink)? ' selected="selected"' : '';
					echo '<option value="'.$nameRepUploadLink.'"'.$repselected.'>'.$nameRepUploadLink.'</option>';
				}
			break;
			case 'Flash' :
				foreach($accessRepUploadFlash as $nameRepUploadFlash) {
					$repselected = ($rep == $nameRepUploadFlash)? ' selected="selected"' : '';
					echo '<option value="'.$nameRepUploadFlash.'"'.$repselected.'>'.$nameRepUploadFlash.'</option>';
				}
			break;
			case 'Media':
				foreach($accessRepUploadMedia as $nameRepUploadMedia) {
					$repselected = ($rep == $nameRepUploadMedia)? ' selected="selected"' : '';
					echo '<option value="'.$nameRepUploadMedia.'"'.$repselected.'>'.$nameRepUploadMedia.'</option>';
				}
			break;
			default :
				die("Erreur 202");
		}          
		if (!in_array($rep,$accessRepUpload)) echo  '<option value="" selected="selected">'.$rep.'</option>';
?>			
        </select>
		<input id="helpOpen" class="bouton" type="button" value="<?php echo $lang_upload[11]; ?>" onclick="OpenCloseHelp()" />	    
		</div>
		<div style="text-align:center;">
		<div <?php if(count($dbfiles) > 8) echo 'class="corpsFileScroll"'; else echo 'class="corpsFilenoScroll"'; ?>> 
<?php
		echo '<table cellpadding="0" cellspacing="0" border="0">';		
		echo '<tr class="forum">';
        echo '<td id="forumName" nowrap="nowrap">'.$lang_upload[15].'</td><td id="forumSize" nowrap="nowrap" width="15%">'.$lang_upload[16].'</td><td id="forumAction" nowrap="nowrap" width="15%">'.$lang_upload[17].'</td>';
		echo '</tr>';
        if (!in_array($rep,$accessRepUpload)) {
			echo '<tr class="quest" id="trdir" onmouseover="MouseOverFile(\'yes\',\'trdir\',\'trsurvol\');" onmouseout="MouseOverFile(\'no\',\'trdir\',\'trsurvol\');" >';
			echo '<td class="fileName"><img src="'.CHEMIN.$pathRepUpload.'upload/img/parent_directory.gif" width="16" height="16" border="0" alt="'.$lang_upload[34].'" title="'.$lang_upload[34].'" class="imgName" onclick="RepParent(\''.$rep.'\');" /><a href="javascript:RepParent(\''.$rep.'\');" title="'.$lang_upload[32].'"><strong>..</strong></a></td>';
			echo '<td class="fileSize">dir</td>';
			echo '<td class="fileAction"><img id="on" src="'.CHEMIN.$pathRepUpload.'upload/img/explorer.gif" border="0" width="16" height="16" alt="'.$lang_upload[32].'" title="'.$lang_upload[32].'" class="imgAction2" onclick="RepParent(\''.$rep.'\');" onmouseover="MouseOverFile(\'yes\',\'on\',\'imgsurvol\');" onmouseout="MouseOverFile(\'no\',\'on\',\'imgsurvol\');" /></td>';
            echo '</tr>';
        }
        for ($i = 0; $i < count($dbfiles); $i++) {
			$n = ($i/2);
		    if (is_integer($n)) {
				echo '<tr class="rep" id="tr'.$i.'" onmouseover="MouseOverFile(\'yes\',\'tr'.$i.'\',\'trsurvol\');" onmouseout="MouseOverFile(\'no\',\'tr'.$i.'\',\'trsurvol\');">';
			}else {
			    echo '<tr class="quest" id="tr'.$i.'" onmouseover="MouseOverFile(\'yes\',\'tr'.$i.'\',\'trsurvol\');" onmouseout="MouseOverFile(\'no\',\'tr'.$i.'\',\'trsurvol\');">';
			}
            if ($dbfiles[$i][2] == 'dir') {
				echo '<td class="fileName"><a href="upload.php?lng='.$lng.'&amp;rep='.$rep.'/'.$dbfiles[$i][0].'&amp;uptype='.$uptype.'&amp;pathconfig='.$pathRepUploadConfig.'&amp;namerepconfig='.$nameRepUploadConfig.'" class="imgName"><img src="'.CHEMIN.$dbfiles[$i][1].'" width="16" height="16" alt="'.$lang_upload[14].'" title="'.$lang_upload[14].'" border="0" class="imgName" /></a><a href="upload.php?lng='.$lng.'&amp;rep='.$rep.'/'.$dbfiles[$i][0].'&amp;uptype='.$uptype.'&amp;pathconfig='.$pathRepUploadConfig.'&amp;namerepconfig='.$nameRepUploadConfig.'" title="'.$lang_upload[32].'">'.$dbfiles[$i][0].'</a></td>';		
				echo '<td class="fileSize">'.$dbfiles[$i][2].'</td>';
				echo '<td class="fileAction">';
				echo '<a href="upload.php?lng='.$lng.'&amp;rep='.$rep.'/'.$dbfiles[$i][0].'&amp;uptype='.$uptype.'&amp;pathconfig='.$pathRepUploadConfig.'&amp;namerepconfig='.$nameRepUploadConfig.'"><img id="on'.$i.'" src="'.CHEMIN.$pathRepUpload.'upload/img/explorer.gif" border="0" width="16" height="16" alt="'.$lang_upload[32].'" title="'.$lang_upload[32].'" class="imgAction" onmouseover="MouseOverFile(\'yes\',\'on'.$i.'\',\'imgsurvol\');" onmouseout="MouseOverFile(\'no\',\'on'.$i.'\',\'imgsurvol\');" /></a>';
				if($allowedRenameRepFile == true) { //AUTORISATION RENOMMER
					echo '<img id="nom'.$i.'" src="'.CHEMIN.$pathRepUpload.'upload/img/edit.gif" border="0" width="16" height="16" alt="'.$lang_upload[36].'" title="'.$lang_upload[36].'" class="imgAction2"  onclick=\'renameFile("'.$rep.'","'.$dbfiles[$i][0].'","dir");\' onmouseover="MouseOverFile(\'yes\',\'nom'.$i.'\',\'imgsurvol\');" onmouseout="MouseOverFile(\'no\',\'nom'.$i.'\',\'imgsurvol\');" />';											
				} //FIN AUTORISATION
				if($allowedDeleteRepFile == true) { //AUTORISATION SUPPRESSION
					echo '<img id="sup'.$i.'" src="'.CHEMIN.$pathRepUpload.'upload/img/sup.gif" border="0" width="16" height="16" alt="'.$lang_upload[37].'" title="'.$lang_upload[37].'" class="imgAction"  onclick=\'confirmDelFile("'.$rep.'","'.$dbfiles[$i][0].'","dir");\' onmouseover="MouseOverFile(\'yes\',\'sup'.$i.'\',\'imgsurvol\');" onmouseout="MouseOverFile(\'no\',\'sup'.$i.'\',\'imgsurvol\');" />';
				} //FIN AUTORISATION
				echo '</td>';
			} else {
				$ext = strrchr($dbfiles[$i][0],'.');
				echo '<td class="fileName">';
 				switch ($uptype) {
					case 'Image' :
					    if (count($allowedExtImage) > 0 && in_array($ext,$allowedExtImage)) {
							echo '<img src="'.CHEMIN.$dbfiles[$i][1].'" width="16" height="16" alt="'.$rep.'/'.$dbfiles[$i][0].'" title="'.$rep.'/'.$dbfiles[$i][0].'" border="0" class="imgName" onclick=\'openURL("'.$site[3].$rep.'/'.$dbfiles[$i][0].'","img","'.$dbfiles[$i][0].'","'.$image_size[0].'","'.$image_size[1].'");\' />';
						    $image_size = getimagesize(CHEMIN.$rep.'/'.$dbfiles[$i][0]);
					        echo '<a name="file'.$i.'" title="'.$lang_upload[38].'" href="#file'.$i.'" onclick=\'openURL("'.$site[3].$rep.'/'.$dbfiles[$i][0].'","img","'.$dbfiles[$i][0].'","'.$image_size[0].'","'.$image_size[1].'");\' >'.$dbfiles[$i][0].'</a>';						
						} else {
							echo '<img src="'.CHEMIN.$dbfiles[$i][1].'" width="16" height="16" alt="'.$rep.'/'.$dbfiles[$i][0].'" title="'.$rep.'/'.$dbfiles[$i][0].'" border="0" class="imgName" />';
							echo $dbfiles[$i][0];
						}
					break;
					case 'Link' :
						if(count($deniedExtLink) > 0 && in_array($ext,$deniedExtLink)) {
							echo '<img src="'.CHEMIN.$dbfiles[$i][1].'" width="16" height="16" alt="'.$rep.'/'.$dbfiles[$i][0].'" title="'.$rep.'/'.$dbfiles[$i][0].'" border="0" class="imgName" />';
							echo $dbfiles[$i][0];
						} else {
							echo '<img src="'.CHEMIN.$dbfiles[$i][1].'" width="16" height="16" alt="'.$rep.'/'.$dbfiles[$i][0].'" title="'.$rep.'/'.$dbfiles[$i][0].'" border="0" class="imgName" onclick=\'openURL("'.$site[3].$rep.'/'.$dbfiles[$i][0].'","file","'.$dbfiles[$i][0].'","","");\' />';
					    	echo '<a name="file'.$i.'" title="'.$lang_upload[38].'" href="#file'.$i.'" onclick=\'openURL("'.$site[3].$rep.'/'.$dbfiles[$i][0].'","file","'.$dbfiles[$i][0].'","","");\' >'.$dbfiles[$i][0].'</a>';
						}
					break;
					case 'Flash' :
					    if (count($allowedExtFlash) > 0 && in_array($ext,$allowedExtFlash)) {
							echo '<img src="'.CHEMIN.$dbfiles[$i][1].'" width="16" height="16" alt="'.$rep.'/'.$dbfiles[$i][0].'" title="'.$rep.'/'.$dbfiles[$i][0].'" border="0" class="imgName" onclick=\'openURL("'.$site[3].$rep.'/'.$dbfiles[$i][0].'","flash","'.$dbfiles[$i][0].'","","");\' />';
					        echo '<a name="file'.$i.'" title="'.$lang_upload[38].'" href="#file'.$i.'" onclick=\'openURL("'.$site[3].$rep.'/'.$dbfiles[$i][0].'","flash","'.$dbfiles[$i][0].'","","");\' >'.$dbfiles[$i][0].'</a>';
						} else {
							echo '<img src="'.CHEMIN.$dbfiles[$i][1].'" width="16" height="16" alt="'.$rep.'/'.$dbfiles[$i][0].'" title="'.$rep.'/'.$dbfiles[$i][0].'" border="0" class="imgName" />';
							echo $dbfiles[$i][0];
						}
					break;
					case 'Media' :
					    if (count($allowedExtMedia) > 0 && in_array($ext,$allowedExtMedia)) {
							echo '<img src="'.CHEMIN.$dbfiles[$i][1].'" width="16" height="16" alt="'.$rep.'/'.$dbfiles[$i][0].'" title="'.$rep.'/'.$dbfiles[$i][0].'" border="0" class="imgName" onclick=\'openURL("'.$site[3].$rep.'/'.$dbfiles[$i][0].'","media","'.$dbfiles[$i][0].'","","");\' />';
					        echo '<a name="file'.$i.'" title="'.$lang_upload[38].'" href="#file'.$i.'" onclick=\'openURL("'.$site[3].$rep.'/'.$dbfiles[$i][0].'","media","'.$dbfiles[$i][0].'","","");\' >'.$dbfiles[$i][0].'</a>';
						} else {
							echo '<img src="'.CHEMIN.$dbfiles[$i][1].'" width="16" height="16" alt="'.$rep.'/'.$dbfiles[$i][0].'" title="'.$rep.'/'.$dbfiles[$i][0].'" border="0" class="imgName" />';
							echo $dbfiles[$i][0];
						}
					break;
					default :
						echo '<img src="'.CHEMIN.$dbfiles[$i][1].'" width="16" height="16" alt="'.$rep.'/'.$dbfiles[$i][0].'" title="'.$rep.'/'.$dbfiles[$i][0].'" border="0" class="imgName" />';
				        echo $dbfiles[$i][0];						    
				}				
				echo '</td>';		
		        echo '<td class="fileSize">'.$dbfiles[$i][2].'</td>';
				if (in_array($ext,$allowedExtImage)) {
                	echo '<td class="fileAction"><img id="on'.$i.'" src="'.CHEMIN.$pathRepUpload.'upload/img/look.gif" width="16" height="16" border="0" alt="'.$lang_upload[35].'" title="'.$lang_upload[35].'" class="imgAction" onclick=\'popupImgUp("'.CHEMIN.$rep.'/'.$dbfiles[$i][0].'");\' onmouseover="MouseOverFile(\'yes\',\'on'.$i.'\',\'imgsurvol\');" onmouseout="MouseOverFile(\'no\',\'on'.$i.'\',\'imgsurvol\');" />';
				} else{
                    echo '<td class="fileAction"><img id="on'.$i.'" src="'.CHEMIN.$pathRepUpload.'upload/img/look.gif" width="16" height="16" border="0" alt="'.$lang_upload[35].'" title="'.$lang_upload[35].'" class="imgAction" onclick=\'popupFileUp("'.CHEMIN.$rep.'/'.$dbfiles[$i][0].'");\' onmouseover="MouseOverFile(\'yes\',\'on'.$i.'\',\'imgsurvol\');" onmouseout="MouseOverFile(\'no\',\'on'.$i.'\',\'imgsurvol\');" />';
				}
				if($allowedRenameRepFile == true) { //AUTORISATION RENOMMER
					echo '<img id="nom'.$i.'" src="'.CHEMIN.$pathRepUpload.'upload/img/edit.gif" border="0" width="16" height="16" alt="'.$lang_upload[36].'" title="'.$lang_upload[36].'" class="imgAction2"  onclick=\'renameFile("'.$rep.'","'.$dbfiles[$i][0].'","file");\' onmouseover="MouseOverFile(\'yes\',\'nom'.$i.'\',\'imgsurvol\');" onmouseout="MouseOverFile(\'no\',\'nom'.$i.'\',\'imgsurvol\');" />';											
				}  //FIN AUTORISATION
				if($allowedDeleteRepFile == true) { //AUTORISATION SUPPRESSION
					echo '<img id="sup'.$i.'" src="'.CHEMIN.$pathRepUpload.'upload/img/sup.gif" border="0" width="16" height="16" alt="'.$lang_upload[37].'" title="'.$lang_upload[37].'" class="imgAction"  onclick=\'confirmDelFile("'.$rep.'","'.$dbfiles[$i][0].'","file");\' onmouseover="MouseOverFile(\'yes\',\'sup'.$i.'\',\'imgsurvol\');" onmouseout="MouseOverFile(\'no\',\'sup'.$i.'\',\'imgsurvol\');" />';
				} //FIN AUTORISATION
				echo '</td>';
			}			
            echo '</tr>';
        }
        echo '</table>';
?>		
		</div>
		</div>
        </form>
<?php
		//UPLOAD DES FICHIERS
		if($allowedUpload == true) {  //AUTORISATION		
        	echo '<form name="uploadit" enctype="multipart/form-data" action="upload.php?lng='.$lng.'" method="post" onsubmit="return UploadValid(this,\'ficup\');" >';
        	echo '<input type="hidden" name="rep" value="'.$rep.'" />';
			echo '<input type="hidden" name="upvalid" value="ok" />';
			echo '<input type="hidden" name="uptype" value="'.$uptype.'" />';
			echo '<input type="hidden" name="pathconfig" value="'.$pathRepUploadConfig.'" />';
			echo '<input type="hidden" name="namerepconfig" value="'.$nameRepUploadConfig.'" />';
        	echo '<div class="labelupload"><img src="'.CHEMIN.$pathRepUpload.'upload/img/upload.gif" width="16" height="16" border="0" alt="'.$lang_upload[13].'" title="'.$lang_upload[13].'" />'.$lang_upload[13].'</div>';
        	echo '<div class="upload"><input type="file" name="ficup" size="27" /><input class="bouton" type="submit" value="'.$lang_upload[18].'" /></div>';
        	echo '</form>';
		}		
		//CREATION D'UN SOUS-REPERTOIRE	
		if($allowedCreateRep == true) {  //AUTORISATION	
			echo '<form name="createdit"  action="upload.php?lng='.$lng.'" method="post" onsubmit="return UploadValid(this,\'creatrep\');">';
        	echo '<input type="hidden" name="rep" value="'.$rep.'" />';
        	echo '<input type="hidden" name="uptype" value="'.$uptype.'" />';
			echo '<input type="hidden" name="pathconfig" value="'.$pathRepUploadConfig.'" />';
        	echo '<input type="hidden" name="namerepconfig" value="'.$nameRepUploadConfig.'" />';
        	echo '<div class="labelupload"><img src="'.CHEMIN.$pathRepUpload.'upload/img/directory.gif" width="16" height="16" border="0" alt="'.$lang_upload[8].'" title="'.$lang_upload[8].'" />'.$lang_upload[8].'</div>';
        	echo '<div class="upload">'.$lang_upload[9].'&nbsp;:&nbsp;<input type="text" name="creatrep" size="30" value="" /><input class="bouton" type="submit" value="'.$lang_upload[10].'" /></div>';
        	echo '</form>';
		}
}		
?>
</body>
</html>
<?php
}
