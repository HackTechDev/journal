<?php
/*
     MinieditorTextarea r�alis� par Djchouix - Licence CeCILL
     Web site = http://lebrikabrak.free.fr/
     e-mail   = lebrikabrak@free.fr
	 version 1.6 (24 f�vrier 2006) compatibilit� avec guppy v4.5.x
	 
*/
if (stristr($_SERVER["SCRIPT_NAME"], "jscript_upload.inc")) {
	header("location:../index.php");
	die();
}
?>
//R�cup�ration de l'URL du fichier
function openURL(url,type,alt,width,height) {
	//Icon and banner
	if (type == 'img') {
	   url = url.replace(/^.+\/img\//,'');
              id = window.name;
	    window.opener.document.getElementById(id).value = url;
	}
	//Download
	if (type == 'file') {
      url = url.replace(/^.+\/file\//,'file/');
              id = window.name;
	    window.opener.document.getElementById(id).value = url;
	}
	//Photo
    if (type == 'media') {
		url = url.replace(/^.+\/photo\//,'');
	    window.opener.document.getElementById("nouveau1").value = url;
	}
    window.close();
}