<?php
/*
     MinieditorTextarea réalisé par Djchouix - Licence CeCILL
     Web site = http://lebrikabrak.free.fr/
     e-mail   = lebrikabrak@free.fr
	 version 1.6.2 (22 avril 2006) compatibilité avec guppy v4.5.x
	 version 1.6.3  (25 septembre 2012)  correction des instructions utilisateurs en anglais - Corrector
*/
if (stristr($_SERVER["SCRIPT_NAME"], "en_upload.inc")) {
  header("location:../index.php");
  die();
}

$lang_upload[1] = "Error in creation because a directory with the same name already exists.<br /><br />Please change the directory's name.";
$lang_upload[2] = "Error because a file with the same name already exists.<br /><br />Please change the file's name.";
$lang_upload[3] = "Error because a directory with the same name already exists.<br /><br />Please change the directory's name.";
$lang_upload[4] = "Error in deleting directory because the server doesn't autorize this.<br /><br />Please delete the directory by FTP.";
$lang_upload[5] = "Error in uploading because it \'s not a valid file (filename.ext)";
$lang_upload[6] = "Error in uploading because a file with the same name already exists.<br /><br />Please change the file's name for uploading.";
$lang_upload[7] = "From here you can manage the files and the directories on your site.<br /><img src='img/explorer.gif' alt='Open' title='Open' border='0' style='vertical-align:middle;' /> : opens the directory<br /><img src='img/look.gif' alt='See' title='See' border='0' style='vertical-align:middle;' /> : shows the file.<br /><img src='img/edit.gif' alt='Rename' title='Rename' border='0' style='vertical-align:middle;' /> : renames the file or the directory.<br /><img src='img/sup.gif' alt='Delete' title='Delete' border='0' style='vertical-align:middle;' /> : deletes the file or the directory.<br />";
$lang_upload[8] = "Create directory";
$lang_upload[9] = "Directory's name";
$lang_upload[10] = "Create";
$lang_upload[11] = "Click here to show help";  
$lang_upload[12] = "Click here to mask help";
$lang_upload[13] = "Upload a file";
$lang_upload[14] = "Directory";
$lang_upload[15] = "File";
$lang_upload[16] = "Size (octet)";
$lang_upload[17] = "Action";
$lang_upload[18] = "Upload on the site";
$lang_upload[19] = "To retrieve the URL, please click its name.";
$lang_upload[20] = 'You must fill the field';
$lang_upload[21] = "You don't have permission to upload this type of file. Please contact website's administrator.";
$lang_upload[22] = "Preview";
$lang_upload[23] = "You are deleting the file";
$lang_upload[24] = "You are deleting the directory";
$lang_upload[25] = "with all files and subdirectories";
$lang_upload[26] = 'Be carefull, deleting is irreversible.\n Please confirm this deleting if you really want to delete.';
$lang_upload[27] = "Please, write a new file\'s name";
$lang_upload[28] = "Write here the new file\'s name without the extension";
$lang_upload[29] = "Please, write a new name for this directory";
$lang_upload[30] = "Write here the new directory\'s name";
$lang_upload[31] = "Be carefull, you must use only letters and/or numbers and/or characters (-_) without space in the name.";
$lang_upload[32] = "Open";
$lang_upload[33] = "Return";
$lang_upload[34] = "Parent Directory";
$lang_upload[35] = "See";
$lang_upload[36] = "Rename";
$lang_upload[37] = "Delete";
$lang_upload[38] = "Select";