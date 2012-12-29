<?php
/*
    Checking install dir - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.6.11 (11 December 2009)  : initial release
*/

if (stristr($_SERVER["SCRIPT_NAME"], "check_install.inc")) {
  header("location:../index.php");
  die();
}

if (strpos($site[3], "localhost") || strpos($site[3], "127.0.0.1")) {
// do nothing
} else {
  $txtnow = (($lng == $lang[0])? "maintenant" : "now");
  if (file_exists(CHEMIN."data/chk_install.dtb")) {
    $date_chk = ReadCounter(CHEMIN."data/chk_install.dtb");
  } else {
    $date_chk = fopen(CHEMIN."data/chk_install.dtb", "w+");
  }
  if ($date_chk != date("Y-m-d")) {
    @chmod(CHEMIN."data/chk_install.dtb", 0666);
    WriteCounter(CHEMIN."data/chk_install.dtb", date("Y-m-d"));
    echo '
    <div id="note" class="bord notice" style="width:440px;position:absolute;top:166px;left:30%;z-index:100;">
      <div style="float:left;padding:5px;"><img src="inc/img/general/attention.gif" alt="Attention !!!" /></div>
      <div style="float:right;text-align:center;width:370px;padding-top:16px;"><br />
      <span style="text-decoration:blink; font:bold 18px Arial, Helvetica, sans-serif;">
      *** ATTENTION -- WARNING ***</span></div>
      <div style="clear:both;"></div>
    <hr />
    <strong>N\'oubliez pas de supprimer le répertoire install...<br />
    Votre site peut être détruit (ou vidé) à tout moment !!!</strong>
    <br /><br />
    <p><strong>Don\'t forget to remove the install directory...<br />
    Your site can still be destroyed at any time !!!</strong>
    </p>
    <p style="text-align:right">
    <a href="'.CHEMIN.'install/delete.php?lng='.$lng.'" title="'.$admin186.' '.$web7.' '.$admin182.' Install '.$txtnow.'">
    <img src="inc/img/general/poubelle.png" border="0" alt="supprimer" style="vertical-align:middle" /></a>&nbsp;
     <a href="#" onclick="document.getElementById(\'note\').style.visibility = \'hidden\'" title="'.$admin458.'">
    <img src="inc/img/files/sup.gif" border="0" alt="Close" style="vertical-align:bottom" /></a>
    </p>
    </div>';
  }
}

?>
