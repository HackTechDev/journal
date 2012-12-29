<?php
/*
   Counter Plugin is GPL  Copyright (C) 2004 by Nicolas Alves
      Web site = http://cambodiaplus.com/
      e-mail   = nico@cambodiaplus.com

    Version History :
      v1.0 (29 June 2004)     : Version initiale
      v2.0 (22 july 2004)     : Ai intégré un compteur de nombre d’articles, téléchargements et messages forums
      			        Correction d'une faute d’orthographe, merci RV.
      v4.0 (06 December 2004) : added multi-admin management (by Nicolas Alves)
      v4.6.10 (7 September 2009)    : corrected #274
*/

if (stristr($_SERVER["SCRIPT_NAME"], "countforum.inc")) {
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
  $dbwork = ReadDBFields(DBFORUM);
  htable($admin655, "100%");
  ?>
  <div align="center">
  <?php echo $admin658."<b> ".count($dbwork)."</b> ".$admin659; ?>
  <hr />
  [ <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=count"><?php echo $admin657; ?></a> || <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b> ]
  <hr /></div><br />
  <table cellpadding="2" width="95%" align="center" border="0" summary="">
    <tr class="forum" align="center">
      <td width="100%"><b><?php echo $admin253; ?></b></td>
      <td nowrap="nowrap"><b><?php echo $admin665; ?></b></td>
      <td nowrap="nowrap"><b><?php echo $admin144; ?></b></td>
      <td nowrap="nowrap"><b><?php echo $admin663; ?></b></td>
    </tr>
  <?php
  for ($i = 0; $i < count($dbwork); $i++) {
    $dbcounter=ReadCounter(DBBASE.$dbwork[$i][2].DBEXT);
    if ($dbcounter > 1) {
      $txtcount = $admin662;
    }
    else {
      $txtcount = $admin661;
    }
    if ($i % 2 == 0)
      echo "<tr>";
    else
      echo "<tr class=\"rep\">";
    ?>
    <td><?php echo $texte[3]; ?><?php echo $dbwork[$i][5]; ?></td>
    <td align="center" nowrap><?php echo $dbcounter." ".$txtcount; ?></td>
    <td>[ <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=gestcounter&amp;mod=1&amp;id=<?php echo $dbwork[$i][2]; ?>&amp;cnum=3"><?php echo $admin144; ?></a> ]</td>
    <td>[ <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=gestcounter&amp;del=1&amp;id=<?php echo $dbwork[$i][2]; ?>&amp;cnum=3"><?php echo $admin663; ?></a> ]</td></tr>
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
