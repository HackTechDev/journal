<?php
/*
     MinieditorTextarea réalisé par Djchouix - Licence CeCILL
     Web site = http://lebrikabrak.free.fr/
     e-mail   = lebrikabrak@free.fr
	 version 1.6.3 (24 février 2007) compatibilité avec guppy v4.5.x
*/
if (stristr($_SERVER["SCRIPT_NAME"], "en_minieditortextarea.inc")) {
  header("location:../index.php");
  die();
}

$version_minieditor = "Version 1.6.3";
$lang_minieditor[0] = 'Ok';
$lang_minieditor[1] = 'Close';
$lang_minieditor[2] = 'New';
$lang_minieditor[3] = 'Font';
$lang_minieditor[4] = 'Size';
$lang_minieditor[5] = 'Text Color';
$lang_minieditor[6] = 'Background Color';
$lang_minieditor[7] = 'Left Justify';
$lang_minieditor[8] = 'Center Justify';
$lang_minieditor[9] = 'Right Justify';
$lang_minieditor[10] = 'Block Justify';
$lang_minieditor[11] = 'Bold';
$lang_minieditor[12] = 'Italic';
$lang_minieditor[13] = 'Underline';
$lang_minieditor[14] = 'Strike Through';
$lang_minieditor[15] = 'Subscript';
$lang_minieditor[16] = 'Superscript';
$lang_minieditor[17] = 'Insert Image';
$lang_minieditor[18] = 'Insert Link';
$lang_minieditor[19] = 'Preview';
$lang_minieditor[20] = 'Wysiwyg Editor';
$lang_minieditor[21] = 'Tag HTML';
$lang_minieditor[22] = 'Class CSS';
$lang_minieditor[23] = 'Path';
$lang_minieditor[24] = 'relative';
$lang_minieditor[25] = 'absolute';
$lang_minieditor[26] = 'URL';
$lang_minieditor[27] = 'Browse server';
$lang_minieditor[28] = 'Target';
$lang_minieditor[29] = 'Alt';
$lang_minieditor[30] = 'Width (px)';
$lang_minieditor[31] = 'Height (px)';
$lang_minieditor[32] = 'Border (px)';
$lang_minieditor[33] = 'HSpace (px)';
$lang_minieditor[34] = 'Vspace (px)';
$lang_minieditor[35] = 'Align';
$lang_minieditor[36] = 'Select a Color';
$lang_minieditor[37] = 'Color';
$lang_minieditor[38] = "Paste text here";
$lang_minieditor[39] = 'Please, write the URL .';
$lang_minieditor[40] = 'The code of the color isn\' t valid.\nYou must write #XXXXXX with X = 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E ou F.\nPlease correct.';
$lang_minieditor[41] = "An error has occured. Please try again or contact plugin's author.";
$lang_minieditor[42] = 'Title';
$lang_minieditor[43] = 'Insert BR tag';
$lang_minieditor[44] = 'None';
$lang_minieditor[45] = 'Insert Favorite tag';
$lang_minieditor[46] = 'Undo';
$lang_minieditor[47] = 'Redo';
$lang_minieditor[48] = 'Insert Flash Animation';
$lang_minieditor[49] = 'Id';
$lang_minieditor[50] = 'Quality';
$lang_minieditor[51] = 'By default';
$lang_minieditor[52] = 'High';
$lang_minieditor[53] = 'AutoLow';
$lang_minieditor[54] = 'Low';
$lang_minieditor[55] = 'Loop';
$lang_minieditor[56] = 'AutoPlay';
$lang_minieditor[57] = 'Menu';
$lang_minieditor[58] = 'Scale';
$lang_minieditor[59] = 'No border';
$lang_minieditor[60] = 'Exact fit';
$lang_minieditor[61] = "<br /><br />Error because a directory name in string <strong>\$nameRepPath</strong> in the file <strong>minieditortextarea_config.inc</strong> has unavailable characters.<br /><span style='font-weight:bold;text-decoration:underline;'>NOTICE:</span><br />For directory name, you may only use <strong>letters</strong> and/or <strong>numerics</strong> and/or <strong>tiret ( - )</strong> et <strong>underline ( _ )</strong>.<br />All other characters including space are forbidden.<br />Correct that and try again.";
$lang_minieditor[62] = '<a href="http://www.macromedia.com/go/getflashplayer" target="_blank"><img src="flash\/document_Flash.gif" alt="Get FlashPlayer" title="Get FlashPlayer" width="114" height="21" border="0" /><\/a>';
$lang_minieditor[63] = 'The Width isn\'t correct.\nYou must to write a number.\nPlease correct.';
$lang_minieditor[64] = 'The Height isn\'t correct.\nYou must to write a number.\nPlease correct.';
$lang_minieditor[65] = 'The Horizontal Space isn\'t correct.\nYou must to write a number.\nPlease correct.';
$lang_minieditor[66] = 'The Vertical Space isn\'t correct.\nYou must to write a number.\nPlease correct.';
$lang_minieditor[67] = 'The border isn\'t correct.\nYou must to write a number.\nPlease correct.';
$lang_minieditor[68] = 'About';
$lang_minieditor[69] = 'Insert Smiley';
$lang_minieditor[70] = 'Close';
$lang_minieditor[71] = 'Insert Special Character';
