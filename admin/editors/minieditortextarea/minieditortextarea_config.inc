<?php
/*
     MinieditorTextarea r�alis� par Djchouix - Licence CeCILL
     Web site = http://lebrikabrak.free.fr/
     e-mail   = lebrikabrak@free.fr
	 version 1.6 (24 f�vrier 2006) compatibilit� avec guppy v4.5.x
     v4.6.22 (29 December 2012)    : corrected for ck editor (by Saxbar) 	 
*/
if (stristr($_SERVER["SCRIPT_NAME"], "minieditortextarea_config.inc")) {
	header("location:../index.php");
	die();
}

	$pathFilesMinieditor = 'admin/editors/';  //chemin relatif du fichier image du miniediteur (icones) ainsi que des popups et des fichiers des �diteurs CKeditor et HTMLArea (� ne pas modifier)

	$nameRepConfig = 'minieditortextarea';   //nom du r�pertoire situ� dans admin/editors/ qui contient la config du mini�diteur et de l'upload (pour des raisons de compatibilit� avec les autres plugins veuillez respester le sch�ma suivant pour le choix du nom: "nomduplugin_config")

	$nameRepSmiley = 'img/smileys/';   //nom du r�pertoire qui contient les smileys affich�s dans la popup du mini�diteur

	//MENU POLICE
	$typeFONT = array('Arial, Helvetica, sans-serif','Comic sans MS, Arial, sans-serif','Courier New, Courier, monospace','Georgia, Times New Roman, serif','Times New Roman, Times, serif','Verdana, Bitstream Vera Sans, sans-serif','Trebuchet MS, Helvetica, sans-serif');
	 	   
	//MENU TAILLE
	$sizeFONT = array('xx-small','x-small','small','medium','large','x-large','xx-large'); 
	   	
	//MENU BALISE HTML
	$baliseHTML = array('div','p','span','br','hr','h1','h2','h3','h4','h5','h6','ol','ul','li','table','tr','td','pre','cite','code'); 
	   
	//MENU CLASS CSS    
	$classCSS = array('surlign','titre1'); 
		   
	//MENU CHEMIN ABSOLU RELATIF
	$nameRepPath = array('file','img','photo','pages','flash');	//Nom des r�pertoires � la racine de Guppy pris en compte pour la transformation chemin relatif <-> chemin absolu 
																//Attention: pour les noms de r�pertoire, seuls les caract�res alphanum�riques (a-z A-Z 0-9) ainsi que les caract�res (-  _) sont autoris�s et vous ne devez pas mettre d'espace.	

	//MENU POPUP LINK
	$targetURL = array('_blank','_parent','_self');
	
	//MENU POPUP IMAGE
	$alignIMG = array('left','center','right','top','middle','bottom');
	
	//BALISE COUP DE COEUR
	$baliseBonus = 'p';    //permet d'avoir un raccourci dans la barre de menu pour une balise HTML de la forme <balise></balise>
							// si vous n'en voulez pas, laisser la variable vide
	
	//STYLE CSS DU MINIEDITEUR
	$colorFondMenu = $titre[1];  //couleur de fond du mini�diteur
	$colorFondMenuOver = $texte[2];  //couleur lors du survol de la souris sur une icone du menu
	$colorFondTextarea = $texte[2];  //couleur de fond du textarea
	$colorTextTextarea = $texte[0];  ////couleur du texte du textarea
	
	//STYLE CSS DES POPUPS
	$colorTextTitre = $titre[0];  //couleur du titre
	$colorFondTitre = $titre[1];  //couleur de fond du titre
	$styleBordureTitre = '1px solid '.$bordure[0];  //bordure du titre
	$colorTextCorp = $texte[0];   //couleur du texte
	$colorFondCorp = $texte[2];   //couleur du fond de page
	$styleBordureCorp = '1px solid '.$bordure[0];  //bordure du corps