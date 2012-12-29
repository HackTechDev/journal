<?php
/*
     MinieditorTextarea réalisé par Djchouix - Licence CeCILL
     Web site = http://lebrikabrak.free.fr/
     e-mail   = lebrikabrak@free.fr
	 version 1.6 (24 février 2006) compatibilité avec guppy v4.5.x
	 
      v4.6.10 (7 September 2009)    : corrected #266 and #272
*/
if (stristr($_SERVER["SCRIPT_NAME"], "functions_upload.inc")) {
  header("location:../index.php");
  die();
}

//Fonction pour contrôler et corriger le nom d'un répertoire ou d'un fichier
function cleanName($name,$up=false) {
	$nameclean = trim($name);
	$nameclean = str_replace(' ','_',$nameclean);
	$nameclean = str_replace('à','a',$nameclean);
	$nameclean = preg_replace('![éèê]!','e',$nameclean);
	$nameclean = preg_replace('![îï]!','i',$nameclean);
	$nameclean =($up)? preg_replace('![^-a-zA-Z0-9_\.]!','',$nameclean) : preg_replace('![^-a-zA-Z0-9_]!','',$nameclean);
	return $nameclean;
}

//Fonction pour créer un répertoire accessible à l'upload s'il n'existe pas
function createNewRep($newrep) {
    @mkdir(CHEMIN.$newrep,0755);
	@copy(CHEMIN."data/index.php", CHEMIN.$newrep."/index.php");
	@chmod(CHEMIN.$newrep."/index.php", 0644);
};

//Fonction pour controler la validité des répertoires accessible à l'upload
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
		return die('Erreur dans la variable $accessRepUpload..Veuillez vérifier qu\'elle n\'est pas vide ou que les noms des répertoires sont écrits correctement.');
	}
}

//Fonction pour controler la validité des répertoires accessible à l'upload
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
		return die('Erreur dans la variable $accessRepUpload'.$type.'.Veuillez vérifier qu\'elle n\'est pas vide ou que les noms des répertoires sont écrits correctement.');
	}
}

//Fonction qui permet de supprimer des sous-répertoires
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