<?php
/*
     MinieditorTextarea réalisé par Djchouix - Licence CeCILL
     Web site = http://lebrikabrak.free.fr/
     e-mail   = lebrikabrak@free.fr
	 version 1.6 (24 février 2006) compatibilité avec guppy v4.5.x
*/
if (stristr($_SERVER["SCRIPT_NAME"], "jscript_upload.inc")) {
	header("location:../index.php");
	die();
}
?>
//Récupération de l'URL du fichier
function openURL(url,type,alt,width,height) {
    if (type == 'file') {
	    opener.document.getElementById("f_href").value = url;
        opener.document.getElementById("f_title").focus();
	}
	if (type == 'img') {
	    opener.document.getElementById("f_url").value = url;
	    opener.document.getElementById("f_alt").value = alt;
		opener.document.getElementById("f_width").value = width;
		opener.document.getElementById("f_height").value = height;
        opener.document.getElementById("f_alt").focus();
	}
	if (type == 'flash') {
	    opener.document.getElementById("f_url").value = url;
	}
    window.close();
}
