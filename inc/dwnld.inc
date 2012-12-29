<?php
/*
    LICENCE reading Module - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.6.0 (04 June 2007)       : initial release by Icare

*/
if (stristr($_SERVER["SCRIPT_NAME"], "dwnld.inc")) {
  header("location:../index.php");
  die();
}
if ($lng == "fr") {
$url["CeCILL"] = "http://www.cecill.info/licences/Licence_CeCILL_V2-fr.html";
$url["GNU_GPL"] = "http://www.gnu.org/licenses/gpl.txt";
$url["GNU_LGPL"] = "http://www.gnu.org/licenses/lgpl.txt";
$url["Creative_Commons"] = "http://fr.creativecommons.org/contrats.htm";

$disclaim1 = '<span style="font-weight: bold;">ACCORD de LICENCE<br /><br /></span><hr style="width: 100%; height: 2px;" />';
$disclaim1 .= 'Ce logiciel est r&eacute;gi par la licence <strong>'.$licence.'</strong> respectant les principes de diffusion des logiciels libres. <br /><br />';
$disclaim1 .= 'Veuillez prendre connaissance des termes de cette licence avant de commencer le téléchargement de ce logiciel.<br /><br />';
$disclaim1 .= '<div style="text-align: center;"> &bull; <a title="Lire la licence" target="_blank" href="'.$url[$licence].'"><u>Lire la licence</u></a> &bull;<br />';
$disclaim1 .= '<div style="text-align: left;"><br />Vous pouvez utiliser, modifier et/ou redistribuer ce logiciel sous les conditions <span style="font-weight: bold;">expresses</span> de sa licence.<br /></div></div>';
}
else {
$url["CeCILL"] = "http://www.cecill.info/licences/Licence_CeCILL_V2-en.html";
$url["GNU_GPL"] = "http://www.gnu.org/licenses/gpl.txt";
$url["GNU_LGPL"] = "http://www.gnu.org/licenses/lgpl.txt";
$url["Creative_Commons"] = "http://creativecommons.org/about/licenses/meet-the-licenses";

$disclaim1 = '<span style="font-weight: bold;">LICENCE AGREEMENT<br /><br /></span><hr style="width: 100%; height: 2px;" />';
$disclaim1 .= 'That software is under <strong>'.$licence.'</strong> licence governing free software diffusion. <br /><br />';
$disclaim1 .= 'You must take a look at that licence terms prior to begin downloading the software.<br /><br />';
$disclaim1 .= '<div style="text-align: center;"> &bull; <a title="Read the licence" target="_blank" href="'.$url[$licence].'">Read the generic licence</a> &bull;<br />';
$disclaim1 .= '<div style="text-align: left;"><br />You can use, modify and/or redistribute that sofware under the <span style="font-weight: bold;">specific conditions</span><br />    of the licence.<br /></div></div>';

}
echo $disclaim1;
?>
