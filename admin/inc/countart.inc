<?php
/*
   Counter Plugin- GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Nicolas Alves
      Web site = http://cambodiaplus.com/
      e-mail   = nico@cambodiaplus.com

    Version History :
      v1.0 (29 June 2004)     : Version initiale
      v2.0 (22 july 2004)     : Ai intégré un compteur de nombre d’articles, téléchargements et messages forums
      			        Correction d'une faute d’orthographe, merci RV.
      v4.0 (06 December 2004) : added multi-admin management (by Nicolas Alves)
	                        added high navigation links (by Icare)
      v4.6.10 (7 September 2009)    : corrected #274
*/

if (stristr($_SERVER["SCRIPT_NAME"], "countart.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[31]=="") {
    $nomzone=$admin17;
    include("access.inc");
    exit();
  }
}
  header("Pragma: no-cache");
  include(CHEMIN."inc/hpage.inc");
  htable($admin654, "100%");
  $dbwork = ReadDBFields(DBART);
  ?>
  <div align="center">
  <?php echo $admin658."<b> ".count($dbwork)."</b> ".$admin659; ?>
  <hr />
  [ <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=count"><?php echo $admin657; ?></a> || <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b> ]
  <hr /></div><br />
  <table cellpadding="2" width="98%" border="0" align="center" summary="">
  <tr><td width="50%"><b><?php echo $admin5; ?></b></td>
  <td width="12%" align="center"><b><?php echo $admin673; ?></b></td>
  <td width="12%" align="center"><b><?php echo $admin144; ?></b></td>
  <td width="26%" align="center"><b><?php echo $admin663; ?></b></td></tr>
  <tr><td colspan="4"><br /></td></tr>
  <?php
  if ($lng == $lang[0]) {
    $j = 0;
  }
  else {
    $j = 1;
  }
  $k = 0;
  $arttbl = array();
  for ($i = 0; $i < count($dbwork); $i++) {
    $arttbl[$k][0] = $dbwork[$i][0+$j];
    $arttbl[$k][1] = $dbwork[$i][2+$j];
    $arttbl[$k][2] = $dbwork[$i][4];
    $k++;
  }
  for ($i = 0; $i < count($arttbl); $i++) {
    $dbcounter = ReadCounter(DBBASE.$arttbl[$i][2].DBEXT);
    if ($dbcounter > 1) {
      $txtcount = $admin662;
    }
    else {
      $txtcount = $admin661;
    }
    ?>
    <tr>
      <td><?php echo $texte[3]; ?> <?php echo $arttbl[$i][1]; ?></td>
      <td align="center"><?php echo $dbcounter." ".$txtcount; ?></td>
      <td align="center">[ <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=gestcounter&amp;mod=1&amp;id=<?php echo $arttbl[$i][2]; ?>&amp;cnum=2" title=""><?php echo $admin144; ?></a> ]</td>
      <td align="center">[ <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=gestcounter&amp;del=1&amp;id=<?php echo $arttbl[$i][2]; ?>&amp;cnum=2" title=""><?php echo $admin663; ?></a> ]</td>
    </tr>
    <?php
  }
  ?>
  </table>
  <div align="center"><hr />
  [ <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=count"><?php echo $admin657; ?></a> || <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b> ]
  </div>
  <?php
  btable();
  include(CHEMIN."inc/bpage.inc");

?>
