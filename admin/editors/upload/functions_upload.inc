<?php
/*
     MinieditorTextarea r�alis� par Djchouix - Licence CeCILL
     Web site = http://lebrikabrak.free.fr/
     e-mail   = lebrikabrak@free.fr
	 version 1.6 (24 f�vrier 2006) compatibilit� avec guppy v4.5.x
	 
      v4.6.10 (7 September 2009)    : corrected #266 and #272
*/
if (stristr($_SERVER["SCRIPT_NAME"], "functions_upload.inc")) {
  header("location:../index.php");
  die();
}

//Fonction pour contr�ler et corriger le nom d'un r�pertoire ou d'un fichier
function cleanName($name,$up=false) {
	$nameclean = trim($name);
	$nameclean = str_replace(' ','_',$nameclean);
	$nameclean = str_replace('�','a',$nameclean);
	$nameclean = preg_replace('![���]!','e',$nameclean);
	$nameclean = preg_replace('![��]!','i',$nameclean);
	$nameclean =($up)? preg_replace('![^-a-zA-Z0-9_\.]!','',$nameclean) : preg_replace('![^-a-zA-Z0-9_]!','',$nameclean);
	return $nameclean;
}

//Fonction pour cr�er un r�pertoire accessible � l'upload s'il n'existe pas
function createNewRep($newrep) {
    @mkdir(CHEMIN.$newrep,0755);
	@copy(CHEMIN."data/index.php", CHEMIN.$newrep."/index.php");
	@chmod(CHEMIN.$newrep."/index.php", 0644);
};

//Fonction pour controler la validit� des r�pertoires accessible � l'upload
function controlNameRepUpload($nameRepUp) {
	$nbRepUp = count($nameRepUp);
	for ($i=0; $i<$nbRepUp; $i++) {
		if($nameRepUp[$i] == '' || !preg_match('!^[-a-z0-9_]+$!i',$nameRepUp[$i]) ) {
			unset($nameRepUp[$i]);
		} else {
			if ($nameRepUp[$i] == "0" ) {$nameRepUp[$i] = "0_";}
			if(!is_dir(CHEMIN.$nameRepUp[$i])) createNewRep($nameRepUp[$i]);
		}
	}
	if(count($nameRepUp) > 0) {
		$nameRepUp = array_values($nameRepUp);
		return $nameRepUp;
	} else {
		return die('Erreur dans la variable $accessRepUpload..Veuillez v�rifier qu\'elle n\'est pas vide ou que les noms des r�pertoires sont �crits correctement.');
	}
}

//Fonction pour controler la validit� des r�pertoires accessible � l'upload
function controlAccessRepUpload($accessRepUploadType,$accessRepUpload,$type) {
	$nbRepUp = count($accessRepUploadType);
	for ($i=0; $i<$nbRepUp; $i++) {
		if ($accessRepUploadType[$i] == "0" ) {$accessRepUploadType[$i] = "0_";}
		if(!in_array($accessRepUploadType[$i],$accessRepUpload) || $accessRepUploadType[$i] == '' || !preg_match('!^[-a-z0-9_]+$!i',$accessRepUploadType[$i]) ) unset($accessRepUploadType[$i]);
	}
	if(count($accessRepUploadType) > 0) {
		$accessRepUploadType = array_values($accessRepUploadType);
		return $accessRepUploadType;
	} else {
		return die('Erreur dans la variable $accessRepUpload'.$type.'.Veuillez v�rifier qu\'elle n\'est pas vide ou que les noms des r�pertoires sont �crits correctement.');
	}
}

//Fonction qui permet de supprimer des sous-r�pertoires
function DelSubRep($sous_dossier) { 
	$d = opendir($sous_dossier); 
	while ($f = readdir($d)) {
        if(is_file($sous_dossier.$f)) {
            @unlink($sous_dossier.$f);
		}	
        if($f != '.' && $f != '..' && is_dir($sous_dossier.$f)) {
		    DelSubRep($sous_dossier.$f.'/');
            @rmdir($sous_dossier.$f);			 
		}
	}
	closedir($d);
}