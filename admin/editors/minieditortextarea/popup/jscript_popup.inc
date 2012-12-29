<?php
/*
     MinieditorTextarea réalisé par Djchouix - Licence CeCILL
     Web site = http://lebrikabrak.free.fr/
     e-mail   = lebrikabrak@free.fr
	 version 1.6.3 (24 février 2007) compatibilité avec guppy v4.5.x
     v4.6.10 (7 September 2009)    : corrected #272
*/
if (stristr($_SERVER["SCRIPT_NAME"], "jscript_popup.inc")) {
  header("location:../index.php");
  die();
}

if(!preg_match("!^[a-z]{2,3}$!i",$lng)) die("Erreur dans le nom de la variable de langue!!");
$pathDirMinieditor = 'admin/editors/';    //chemin relatif du répertoire du miniéditeur (à ne pas modifier pour ne pas perdre la compatibilité avec les autres plugins)
// Insertion du fichier de langue
if(file_exists(CHEMIN.$pathDirMinieditor.'minieditortextarea/lang/'.$lng.'_minieditortextarea.inc')) {
	include(CHEMIN.$pathDirMinieditor.'minieditortextarea/lang/'.$lng.'_minieditortextarea.inc');
} else {
	include(CHEMIN.$pathDirMinieditor.'minieditortextarea/lang/en_minieditortextarea.inc'); // fichier de langue par défaut
}

?>
<script type="text/javascript">
//INSERTION CODE
function AddCodePopup(code1,code2,nameform,nametextarea) {
	var textarea = opener.document.forms[nameform].elements[nametextarea];
	//IE et OPERA 8
	if (document.selection) {
     	var str = opener.document.selection.createRange().text;
		//OPERA 8 (MODIF CAR PERTE DE LA SELECTION LORS DU CLICK SUR BOUTON)
		if(navigator.userAgent.indexOf('Opera') != -1 && str == '') {
			var nb_caract = opener.document.getElementById('nb_caract').value.length; //nb de caractère à remplacer
			var pos_cursor = opener.document.getElementById('pos_cursor').value.length; //position du curseur

     		var startPos = pos_cursor;
     		var endPos = startPos + nb_caract;
     		var chaine = textarea.value;
     		textarea.value = chaine.substring(0, startPos) + code1 + chaine.substring(startPos, endPos) + code2 + chaine.substring(endPos, chaine.length);
		}
		//IE
		else {
     		textarea.focus();
     		var sel = opener.document.selection.createRange();
     		sel.text = code1 + str + code2;
		} 
    }
	//MOZILLA 1.7.x/FIREFOX 1.x/NETSCAPE 7.1+
	else if (textarea.selectionStart || textarea.selectionStart == 0) {
     	var startPos = textarea.selectionStart;
     	var endPos = textarea.selectionEnd;
		//Position et hauteur de la scrollbar
		if(textarea.scrollHeight) {
			var oldScrollPos = textarea.scrollTop;	
			var oldScrollHeight = textarea.scrollHeight;
		}
		//Modification de la valeur du textarea
     	var chaine = textarea.value;
		var code = code1 + chaine.substring(startPos, endPos) + code2;
     	textarea.value = chaine.substring(0, startPos) + code + chaine.substring(endPos, chaine.length);
        textarea.selectionStart = startPos + code.length ;
        textarea.selectionEnd = startPos + code.length ;
		//Nouvelle position et hauteur de la scollbar
		if(textarea.scrollHeight) {
			var newScrollHeight = textarea.scrollHeight - oldScrollHeight;
			textarea.scrollTop = oldScrollPos + newScrollHeight;
		}
	}
    //AUTRES NAVIGATEURS
	else {
      	var chaine = textarea.value;
		var message = (code2 == '')? '' :  '<?php echo $lang_minieditor[38]; ?>';
      	textarea.value = chaine + code1 + message + code2;
	}
	textarea.focus();
    return;	
}

function popup_upload(URL,title,largeur,hauteur,scrollbars) {
    var top=(screen.height-hauteur)/2;
    var left=(screen.width-largeur)/2;
    window.open(URL, title, 'top='+top+', left='+left+', width='+largeur+', height='+hauteur+', resizable=yes,menubar=no,location=no,directories=no,status=no,copyhistory=no,toolbar=no,scrollbars='+scrollbars+'');
}

//INSERTION LIEN
function AddLink(nameform,nametextarea) {

	var url = ' href="' + document.getElementById('f_href').value + '"';
	var title = document.forms['addlink'].elements['f_title'].value;
		title = (title !='')? ' title="' + title + '"' : '';
	var target = document.forms['addlink'].elements['f_target'].value;
		target = (target !='')? ' target="' + target + '"' : '';		

	var code1 = '<a' + url + title + target + '>';
	var code2 = '<\/a>';
	
	if (document.getElementById('f_href').value != '') {
		AddCodePopup(code1,code2,nameform,nametextarea);
		//réinitialisation
		document.getElementById('f_href').value = '';
		document.forms['addlink'].elements['f_target'].value = document.forms['addlink'].elements['f_target'].options[0].value; 
		//fermeture popup
		window.close();
		return true;
	} else {
		alert("<?php echo $lang_minieditor[39]; ?>");
		return false;
	}
}

//INSERTION IMAGE
function AddImage(nameform,nametextarea) {
	//Déclaration des variables
<?php
	$ImgAttribut = array('url','alt','border','classCSS','title','width','height','hspace','vspace','id','align');
	for ($i = 0; $i < count($ImgAttribut); $i++) {
		echo 'var '.$ImgAttribut[$i].' = document.getElementById(\'f_'.$ImgAttribut[$i].'\').value;'."\n";
	} 
	for ($i = 4; $i < count($ImgAttribut); $i++) {
		echo $ImgAttribut[$i].' = ('.$ImgAttribut[$i].' != \'\')? \' '.$ImgAttribut[$i].'="\'+ '.$ImgAttribut[$i].' +\'"\' : \'\';'."\n";
	}
?>		
	border = (border != '')? ' border="'+ border +'"' : ' border="0"';
	classCSS = (classCSS != '')? ' class="'+ classCSS +'"' : '';
	
    var code1 = '<img src="'+ url +'" alt="'+ alt +'"'+ title + width + height + border + hspace + vspace + align + id + classCSS +' \/>';
	var code2 = '';

	var error = false;
	if(document.getElementById('f_url').value == '') {
		alert("<?php echo $lang_minieditor[39]; ?>");
		error = true;	
	}
	if(document.getElementById('f_width').value == '' || (document.getElementById('f_width').value != '' && document.getElementById('f_width').value.search(/^[0-9]+$/i) == -1)) {
		error = true;
		alert("<?php echo $lang_minieditor[63]; ?>");
	}
	if(document.getElementById('f_height').value == '' || (document.getElementById('f_height').value != '' && document.getElementById('f_height').value.search(/^[0-9]+$/i) == -1)) {
		error = true;
		alert("<?php echo $lang_minieditor[64]; ?>");	
	}
	if(document.getElementById('f_hspace').value != '' && document.getElementById('f_hspace').value.search(/^[0-9]+$/i) == -1) {
		error = true;
		alert("<?php echo $lang_minieditor[65]; ?>");	
	}
	if(document.getElementById('f_vspace').value != '' && document.getElementById('f_vspace').value.search(/^[0-9]+$/i) == -1) {
		error = true;
		alert("<?php echo $lang_minieditor[66]; ?>");	
	}
	if(document.getElementById('f_border').value != '' && document.getElementById('f_border').value.search(/^[0-9]+$/i) == -1) {
		error = true;
		alert("<?php echo $lang_minieditor[67]; ?>");	
	}
	
	if (error == false) {
		AddCodePopup(code1,code2,nameform,nametextarea);
		//réinitialisation
<?php
		$ImgAttribut = array('url','alt','border','classCSS','title','width','height','hspace','vspace','id');
		for ($i = 0; $i < count($ImgAttribut); $i++) {
			echo 'document.getElementById(\'f_'.$ImgAttribut[$i].'\').value = \'\';'."\n";
		}
		unset($ImgAttribut); 
?>
		document.forms['addimage'].elements['f_align'].value = document.forms['addimage'].elements['f_align'].options[0].value;
		window.close();
		return true;
	} else {
		return false;
	}
}

//INSERTION COULEUR
function AddColor(style,nameform,nametextarea) {
	//on vérifie la validité de la couleur
	var couleur = document.getElementById('f_color').value;
	var code1 = '<span style="' + style + ':' + couleur + ';">';
	var code2 = '<\/span>';

	if(couleur.search(/^#[0-9ABCDEF]{6}$/gi) == -1) {
		alert("<?php echo $lang_minieditor[40]; ?>");
		return false;
	} else {
		AddCodePopup(code1,code2,nameform,nametextarea);
		//réinitialisation
		document.getElementById('f_color').value = '#000000';
		document.getElementById('f_preview').style.backgroundColor = '#000000'; 
		//fermeture popup
		window.close();
		return true;
	}
}

function ColorPreview(color) {
  document.getElementById('f_preview').style.backgroundColor = '#' + color;
  document.getElementById('f_color').value = '#' + color;
}

//INSERTION ANIMATION FLASH
function AddFlash(nameform,nametextarea) {
	//Déclaration des variables
<?php
	$FlashAttribut = array('url','classCSS','width','height','hspace','vspace','id','align');
	for ($i = 0; $i < count($FlashAttribut); $i++) {
		echo 'var '.$FlashAttribut[$i].' = document.getElementById(\'f_'.$FlashAttribut[$i].'\').value;'."\n";
	} 
	for ($i = 2; $i < count($FlashAttribut); $i++) {
		echo $FlashAttribut[$i].' = ('.$FlashAttribut[$i].' != \'\')? \' '.$FlashAttribut[$i].'="\'+ '.$FlashAttribut[$i].' +\'"\' : \'\';'."\n";
	}
	$FlashAttribut = array('loop','play','menu');
	for ($i = 0; $i < count($FlashAttribut); $i++) {
		echo 'var '.$FlashAttribut[$i].' = (!document.forms[\'addflash\'].elements[\'f_'.$FlashAttribut[$i].'\'].checked)? \'<param name="'.$FlashAttribut[$i].'" value="false" />\' : \'\';'."\n";
	}
	$FlashAttribut = array('quality','scale','bgcolor');
	for ($i = 0; $i < count($FlashAttribut); $i++) {
		echo 'var '.$FlashAttribut[$i].' = document.getElementById(\'f_'.$FlashAttribut[$i].'\').value;'."\n";
		echo 'var '.$FlashAttribut[$i].' = ('.$FlashAttribut[$i].' != \'\')? \'<param name="'.$FlashAttribut[$i].'" value="\'+ '.$FlashAttribut[$i].' +\'" />\' : \'\';'."\n";
	}

?>		
	classCSS = (classCSS != '')? ' class="'+ classCSS +'"' : '';
	
	var	code1 = '<object data="'+ url +'"'+ width + height + hspace + vspace + align + id + classCSS +' type="application/x-shockwave-flash">';
		code1 += '<param name="movie" value="'+ url +'" />';
		code1 += quality + scale + loop + play + menu + bgcolor;
		code1 += '<param name="pluginurl" value="http://www.macromedia.com/go/getflashplayer" />';
		code1 += '<?php echo $lang_minieditor[62]; ?>';
    	code1 += '<\/object>';
	var code2 = '';
		
	var error = false;
	if(document.getElementById('f_url').value == '') {
		alert("<?php echo $lang_minieditor[39]; ?>");
		error = true;	
	}
	if(document.getElementById('f_width').value == '' || (document.getElementById('f_width').value != '' && document.getElementById('f_width').value.search(/^[0-9]+$/i) == -1)) {
		error = true;
		alert("<?php echo $lang_minieditor[63]; ?>");
	}
	if(document.getElementById('f_height').value == '' || (document.getElementById('f_height').value != '' && document.getElementById('f_height').value.search(/^[0-9]+$/i) == -1)) {
		error = true;
		alert("<?php echo $lang_minieditor[64]; ?>");	
	}
	if(document.getElementById('f_hspace').value != '' && document.getElementById('f_hspace').value.search(/^[0-9]+$/i) == -1) {
		error = true;
		alert("<?php echo $lang_minieditor[65]; ?>");	
	}
	if(document.getElementById('f_vspace').value != '' && document.getElementById('f_vspace').value.search(/^[0-9]+$/i) == -1) {
		error = true;
		alert("<?php echo $lang_minieditor[66]; ?>");	
	}
	if(document.getElementById('f_bgcolor').value != '' && document.getElementById('f_bgcolor').value.search(/^#[0-9abcdef]{6}$/i) == -1) {
		error = true;
		alert("<?php echo $lang_minieditor[40]; ?>");	
	}

	if(error == false) {
		AddCodePopup(code1,code2,nameform,nametextarea);
		//réinitialisation
<?php
		$FlashAttribut = array('url','classCSS','width','height','hspace','vspace','id','bgcolor');
		for ($i = 0; $i < count($FlashAttribut); $i++) {
			echo 'document.getElementById(\'f_'.$FlashAttribut[$i].'\').value = \'\';'."\n";
		}
		unset($FlashAttribut); 
?>
		document.forms['addflash'].elements['f_align'].value = document.forms['addflash'].elements['f_align'].options[0].value;
		document.forms['addflash'].elements['f_quality'].value = document.forms['addflash'].elements['f_quality'].options[0].value;
		document.forms['addflash'].elements['f_scale'].value = document.forms['addflash'].elements['f_scale'].options[0].value;
		document.forms['addflash'].elements['f_loop'].checked;
		document.forms['addflash'].elements['f_play'].checked;
		document.forms['addflash'].elements['f_menu'].checked;

		window.close();
		return true;
	} else {
		return false;
	}
}

//INSERTION SMILEY
function AddSmileys(url,alt,width,height,nameform,nametextarea) {
    var code1 = '<img src="'+ url +'" alt="'+ alt +'" title="'+ alt +'" width="'+ width +'" height="'+ height +'" border="0" \/>';
	var code2 = '';
	AddCodePopup(code1,code2,nameform,nametextarea);
	window.close();
	return true;
}

//INSERTION ENTITIES
function AddEntities(entitie,nameform,nametextarea) {
    var code1 = entitie;
	var code2 = '';
	AddCodePopup(code1,code2,nameform,nametextarea);
	window.close();
	return true;
}

</script>
