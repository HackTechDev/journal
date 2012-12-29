<?php
/*
     MinieditorTextarea réalisé par Djchouix - Licence CeCILL
     Web site = http://lebrikabrak.free.fr/
     e-mail   = lebrikabrak@free.fr
	 version 1.6.1 (3 mars 2006) compatibilité avec guppy v4.5.x
*/
if (stristr($_SERVER["SCRIPT_NAME"], "default_config_upload.inc")) {
	header("location:../index.php");
	die();
}
	$pathRepUpload ='admin/editors/';  //chemin relatif du répertoire Upload ( à modifier si vous voulez placer ce répertoire ailleurs)
		
	$allowedUpload = true;  //Autorisation (TRUE) ou NON (FALSE) pour Upload
	$allowedCreateRep = true;  //Autorisation (TRUE) ou NON (FALSE) pour la Création de Répertoire
	$allowedRenameRepFile = true;  //Autorisation (TRUE) ou NON (FALSE) pour Renommer des Répertoires ou des Fichiers
	$allowedDeleteRepFile = true;  //Autorisation (TRUE) ou NON (FALSE) pour la Suppression des Répertoires ou des Fichiers

	$allowedExtFileUpload = array();  //Extensions des fichiers UNIQUEMENT autorisés à être uploadés (laisser vide pour autoriser toutes les extensions)
	$deniedExtFileUpload = array();  //Extensions des fichiers NON autorisés à être uploadés (laisser vide pour autoriser toutes les extensions)

	$accessRepUpload = array('file','img','photo','pages','flash');	//Nom des répertoires à la racine de Guppy accessibles pour le fichier Upload	(création si nécessaire) 
																			//Attention: pour les noms de répertoire, seuls les caractères alphanumériques (a-z A-Z 0-9) ainsi que les caractères (-  _)	sont autorisés et vous ne devez pas mettre d'espace.	
	$accessRepUploadImage = array('img','photo');	//Nom des répertoires à la racine de Guppy accessibles via le menu pour l'insertion d'Images.(accès avec variable $uptype='Image')
													//Attention: vous devez choisir les répertoires uniquement parmi la liste des répertoires contenus dans la variable $accessRepUpload ci-dessus
	$accessRepUploadLink = array('file','img','photo','pages','flash');	//Nom des répertoires à la racine de Guppy accessibles via le menu pour l'insertion de Liens (accès avec variable $uptype='Link')
																		//Attention: vous devez choisir les répertoires uniquement parmi la liste des répertoires contenus dans la variable $accessRepUpload ci-dessus
	$accessRepUploadFlash = array('flash','img');	//Nom des répertoires à la racine de Guppy accessibles via le menu pour l'insertion de documents Flash	(accès avec variable $uptype='Flash')
													//Attention: vous devez choisir les répertoires uniquement parmi la liste des répertoires contenus dans la variable $accessRepUpload ci-dessus
	$accessRepUploadMedia = array('flash','img');	//Accès aux répertoires à la racine de Guppy pour les fichiers Audio et Video (accès avec variable $uptype='Media')
															//Attention: vous devez choisir les répertoires uniquement parmi la liste des répertoires contenus dans la variable $accessRepUpload ci-dessus

	$allowedExtImage = array('.jpg','.gif','.png','.bmp','.jpeg');  //Extensions UNIQUEMENT autorisées pour récupérer URL des Images (accès avec variable $uptype='Image')
	$deniedExtLink = array();  //Extensions NON autorisées pour récupérer URL des Liens (laisser vide pour autoriser toutes les extensions) (accès avec variable $uptype='Link')
	$allowedExtFlash = array('.swf','.fla','.flv');  //Extensions UNIQUEMENT autorisées pour récupérer URL des fichiers Flash (accès avec variable $uptype='Flash')
	$allowedExtMedia = array('.avi','.mp3'); //Extensions UNIQUEMENT autorisées pour récupérer URL des fichiers Audio et Video (accès avec variable $uptype='Media')
	
	//STYLE CSS DE LA POPUP UPLOAD
	$colorTextTitre = $titre[0];  //couleur du titre
	$colorFondTitre = $titre[1];  //couleur de fond du titre
	$styleBordureTitre = '1px solid '.$bordure[0];  //bordure du titre
	$colorTextCorp = $texte[0];   //couleur du texte
	$colorFondCorp = $texte[2];   //couleur du fond de page
	$styleBordureCorp = '1px solid '.$bordure[0];  //bordure du corps
	$colorBodyUpload = $texte[1];  //couleur de fond de page (popup upload)
	$colorFondFileUpload = $texte[2]; //couleur du fond du tableau (popup upload)
	$colorFondFileUploadOver = $forum[2];  //couleur de fond des fichiers lors du survol de la souris (popup upload)
	$colorFileUploadOff = $lien[0];  //couleur des liens off (popup upload)
	$colorFileUploadOn = $lien[1];  //couleur des liens on (popup upload)