<?php
/*
    Social Networks - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v4.6.19 (30 March 2012)  : initial release by Saxbar
	  v4.6.20 (24 May 2012)    : added $toptitle (by Saxbar)
                                 corrected btable1 (by Saxbar)
*/

if (stristr($_SERVER['SCRIPT_NAME'], 'boxsocnet.inc')) {
  header('location:../index.php');
  die();
}
$toptitle = $lng == $lang[0] ? $nom[46] : $nom[47];
if ($onemenu == 1) htable1($toptitle, '100%'); else htable($toptitle, '100%');
$dbnet = ReadDBFields(DBSOCNET);
@sort($dbnet);
echo '<div class="box">';
for ($j = 0; $j < count($dbnet); $j++) {
	ReadDoc(DBBASE.$dbnet[$j][4]);
	if ($status == 'a') {
		echo '
<div align="center" style="float:left; padding:0 2px;">';
		if ($fieldd2 != '') {
			echo $fieldd2;
		} else {
			if (trim($fieldd1) != '') {
				if ($fieldc1 == '_POPUP') {
					echo '
  <a href="" onclick="PopupWindow(\''.$fieldd1.'\', \'sn'.$j.'\', 1024, 768, \'yes\', \'yes\');">';
				} else {
					echo '
  <a href="'.$fieldd1.'" target="'.$fieldc1.'">';
				}
			}
			echo '
  <img src="'.CHEMIN.'img/'.$fieldc2.'" alt="'.(strip_tags($fieldb1)).'" border="0" title="'.(strip_tags($fieldb1)).'" />';
			if (trim($fieldd1) != '') 
				echo '
  </a>';
		}
		echo '
</div>';
	}
}
echo '
<div style="clear:both;"></div>';
if (($serviz[32] == 'on' && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32] == 'on' && $drtuser[44] == 'on')) {
    echo '
<div align="right">
  <a href="'.CHEMIN.'admin/admin.php?lng='.$lng.'&amp;pg=socnet">
    <img src="'.CHEMIN.'inc/img/general/edit.gif" border="0" alt="'.$web308.'" title="'.$web308.'" />
  </a>
</div>';
}
echo '</div>';

if ($onemenu == 1) btable1($toptitle); else btable();
?>
