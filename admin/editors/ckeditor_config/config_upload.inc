<?php
/*
 * Plugin CKeditor
 * Version  : 4.6.5.2.6.4 (2009/06/20)
 * Compatibility : Guppy v4.6.x
 * Author   : j�r�me CROUX (djchouix)
 * Web site : http://lebrikabrak.info/
 * E-mail   : lebrikabrak@free.fr
 * Licence  : GNU Lesser General Public License
 *
 * v4.6.22 (29 December 2012)    : corrected for ck editor (by Saxbar) 
 */

if (stristr($_SERVER["SCRIPT_NAME"], "config_upload.inc")) {
	header("location:../index.php");
	die();
}
	$pathRepUpload ='admin/editors/';  //chemin relatif du r�pertoire Upload ( � modifier si vous voulez placer ce r�pertoire ailleurs Ici)
		
	$allowedUpload = true;  //Autorisation (TRUE) ou NON (FALSE) pour Upload
	$allowedCreateRep = true;  //Autorisation (TRUE) ou NON (FALSE) pour la Cr�ation de R�pertoire
	$allowedRenameRepFile = true;  //Autorisation (TRUE) ou NON (FALSE) pour Renommer des R�pertoires ou des Fichiers
	$allowedDeleteRepFile = true;  //Autorisation (TRUE) ou NON (FALSE) pour la Suppression des R�pertoires ou des Fichiers

	$allowedExtFileUpload = array();  //Extensions des fichiers UNIQUEMENT autoris�s � �tre upload�s (laisser vide pour autoriser toutes les extensions)
	$deniedExtFileUpload = array();  //Extensions des fichiers NON autoris�s � �tre upload�s (laisser vide pour autoriser toutes les extensions)

	$accessRepUpload = array('file','img','photo','pages','flash');	//Nom des r�pertoires � la racine de Guppy accessibles pour le fichier Upload	(cr�ation si n�cessaire) 
																			//Attention: pour les noms de r�pertoire, seuls les caract�res alphanum�riques (a-z A-Z 0-9) ainsi que les caract�res (-  _)	sont autoris�s et vous ne devez pas mettre d'espace.	
	$accessRepUploadImage = array('img','photo');	//Nom des r�pertoires � la racine de Guppy accessibles via le menu pour l'insertion d'Images.(acc�s avec variable $uptype='Image')
													//Attention: vous devez choisir les r�pertoires uniquement parmi la liste des r�pertoires contenus dans la variable $accessRepUpload ci-dessus
	$accessRepUploadLink = array('file','img','photo','pages','flash');	//Nom des r�pertoires � la racine de Guppy accessibles via le menu pour l'insertion de Liens (acc�s avec variable $uptype='Link')
																		//Attention: vous devez choisir les r�pertoires uniquement parmi la liste des r�pertoires contenus dans la variable $accessRepUpload ci-dessus
	$accessRepUploadFlash = array('flash','img');	//Nom des r�pertoires � la racine de Guppy accessibles via le menu pour l'insertion de documents Flash	(acc�s avec variable $uptype='Flash')
													//Attention: vous devez choisir les r�pertoires uniquement parmi la liste des r�pertoires contenus dans la variable $accessRepUpload ci-dessus
	$accessRepUploadMedia = array('flash','img');	//Acc�s aux r�pertoires � la racine de Guppy pour les fichiers Audio et Video (acc�s avec variable $uptype='Media')
															//Attention: vous devez choisir les r�pertoires uniquement parmi la liste des r�pertoires contenus dans la variable $accessRepUpload ci-dessus

	$allowedExtImage = array('.jpg','.gif','.png','.bmp','.jpeg');  //Extensions UNIQUEMENT autoris�es pour r�cup�rer URL des Images (acc�s avec variable $uptype='Image')
	$deniedExtLink = array();  //Extensions NON autoris�es pour r�cup�rer URL des Liens (laisser vide pour autoriser toutes les extensions) (acc�s avec variable $uptype='Link')
	$allowedExtFlash = array('.swf','.fla','.flv');  //Extensions UNIQUEMENT autoris�es pour r�cup�rer URL des fichiers Flash (acc�s avec variable $uptype='Flash')
	$allowedExtMedia = array(); //Extensions UNIQUEMENT autoris�es pour r�cup�rer URL des fichiers Audio et Video (acc�s avec variable $uptype='Media')
	
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