<?php
/*
     MinieditorTextarea r�alis� par Djchouix - Licence CeCILL
     Web site = http://lebrikabrak.free.fr/
     e-mail   = lebrikabrak@free.fr
	 version 1.6.2 (22 avril 2006) compatibilit� avec guppy v4.5.x
*/
if (stristr($_SERVER["SCRIPT_NAME"], "fr_upload.inc")) {
  header("location:../index.php");
  die();
}

$lang_upload[1] = "Echec de la cr�ation car un r�pertoire portant le m�me nom existe d�j�.<br /><br />Veuillez recommencer en changeant le nom du r�pertoire � cr�er";
$lang_upload[2] = "Echec car un fichier portant le m�me nom existe d�j�.<br /><br />Veuillez recommencer en changeant le nom du fichier";
$lang_upload[3] = "Echec car un r�pertoire portant le m�me nom existe d�j�.<br /><br />Veuillez recommencer en changeant le nom du r�pertoire";
$lang_upload[4] = "Echec de la suppression du r�pertoire car le serveur ne l'autorise pas.<br /><br />Veuillez le supprimer en utilisant votre logiciel FTP.";
$lang_upload[5] = "Echec de l'upload car ce n'est pas un fichier de la forme \"nom_du_fichier.ext\" ";
$lang_upload[6] = "Echec de l'upload car un fichier portant le m�me nom existe d�j�.<br /><br />Veuillez recommencer en changeant le nom du fichier � uploader";
$lang_upload[7] = "C'est ici que vous g�rez les fichiers et les r�pertoires sur votre site.<br /><img src='img/explorer.gif' alt='Ouvrir' title='Ouvrir' border='0' style='vertical-align:middle;' /> : permet d'ouvrir le r�pertoire<br /><img src='img/look.gif' alt='Voir' title='Voir' border='0' style='vertical-align:middle;' /> : permet de visualiser le fichier.<br /><img src='img/edit.gif' alt='Renommer' title='Renommer' border='0' style='vertical-align:middle;' /> : permet de renommer le fichier ou le r�pertoire<br /><img src='img/sup.gif' alt='Supprimer' title='Supprimer' border='0' style='vertical-align:middle;' /> : permet de supprimer le fichier ou le r�pertoire.<br />";
$lang_upload[8] = "Cr�er un r�pertoire";
$lang_upload[9] = "Nom du r�pertoire";
$lang_upload[10] = "Cr�er";
$lang_upload[11] = 'Cliquer ici pour afficher l\'aide';
$lang_upload[12] = 'Cliquer ici pour masquer l\'aide';
$lang_upload[13] = "Charger un fichier";
$lang_upload[14] = "R�pertoire";
$lang_upload[15] = "Fichier";
$lang_upload[16] = "Taille (octet)";
$lang_upload[17] = "Action";
$lang_upload[18] = "Charger sur le site";
$lang_upload[19] = "Quand on clique sur le nom du fichier, on l'int�gre au document ouvert dans CKEditor.";
$lang_upload[20] = 'Vous devez remplir le champ';
$lang_upload[21] = "Vous n'�tes pas autoris� � uploader ce type de fichier. Veuillez contacter l'administrateur du site.";
$lang_upload[22] = 'Aper�u';
$lang_upload[23] = 'Vous �tes sur le point de supprimer le fichier';
$lang_upload[24] = 'Vous �tes sur le point de supprimer le r�pertoire';
$lang_upload[25] = 'ainsi que tout son contenu (fichiers et sous-r�pertoires)';
$lang_upload[26] = 'Attention, la suppression est irr�versible.\n Veuillez confirmer cette suppression pour qu\'elle devienne effective.';
$lang_upload[27] = 'Veuillez rentrer le nouveau nom du fichier';
$lang_upload[28] = 'Tapez ici le nouveau nom du fichier sans l\'extension';
$lang_upload[29] = 'Veuillez rentrer le nouveau nom du r�pertoire';
$lang_upload[30] = 'Tapez ici le nouveau nom du r�pertoire';
$lang_upload[31] = 'Attention, vous devez utiliser uniquement des caract�res non accentu�s et/ou des chiffres et/ou des caract�res(- _) sans espace dans le nom.';
$lang_upload[32] = "Ouvrir";
$lang_upload[33] = "Retour";
$lang_upload[34] = "R�pertoire Parent";
$lang_upload[35] = "Voir";
$lang_upload[36] = "Renommer";
$lang_upload[37] = "Supprimer";
$lang_upload[38] = "S�lectionner";