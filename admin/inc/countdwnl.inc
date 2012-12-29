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
	                        added high navigation bar, added lines color and optimized html tags (by Icare)
      v4.6.10 (7 September 2009)    : corrected #274
*/

if (stristr($_SERVER["SCRIPT_NAME"], "countdwnl.inc")) {
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
  $dbwork = ReadDBFields(DBDNLOAD);
  @sort($dbwork);
  htable($admin656, "100%");
  ?>
  <div align="center"><?php echo $admin658."<b> ".count($dbwork)."</b> ".$admin659; ?><hr />
  [ <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=count"><?php echo $admin657; ?></a> || <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b> ]
  <hr /><br />
  <table cellpadding="2" width="98%" border="0" summary="">
  <tr class="forum">
  <td width="100%"><?php echo $admin18; ?></td>
  <td nowrap="nowrap"><?php echo $admin664; ?></td>
  <td nowrap="nowrap"><?php echo $admin144; ?></td>
  <td nowrap="nowrap"><?php echo $admin663; ?></td>
  </tr>
  <?php
  for ($i = 0; $i < count($dbwork); $i++) {
    ReadDoc(DBBASE.$dbwork[$i][4]);
    if ($lng == $lang[0]) {
      $txt1 = $fieldb1;
    }
    else {
      $txt1 = $fieldb2;
    }
    $dbcounter=ReadCounter(DBBASE.$dbwork[$i][4].DBEXT);
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
    <td><?php echo $texte[3]; ?><?php echo $txt1; ?></td>
    <td align="center"><?php echo $dbcounter." ".$txtcount; ?></td>
    <td nowrap="nowrap" align="center">[<a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=gestcounter&amp;mod=1&amp;id=<?php echo $dbwork[$i][4]; ?>&amp;cnum=1"><?php echo $admin144; ?></a>]</td>
    <td nowrap="nowrap" align="center">[<a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=gestcounter&amp;del=1&amp;id=<?php echo $dbwork[$i][4]; ?>&amp;cnum=1"><?php echo $admin663; ?></a>]</td></tr>
    <?php
  }
  ?>
  </table>
  <hr />
  [ <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=count"><?php echo $admin657; ?></a> || <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b> ]
  </div>
  <?php
  btable();
  include(CHEMIN."inc/bpage.inc");

?>
