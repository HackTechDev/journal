<?php
/*
    Admin Droits- GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
       v4.0 (06 December 2004)  : initial release by Nicolas Alves
       v4.6.0 (12 december 2006)  : added deletion writer from writer's function db, new ascii sort (by Icare)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "gestredac.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[12]=="") {
    $nomzone=$admin821;
    include("access.inc");
    exit();
  }
}
include(CHEMIN."inc/hpage.inc");
htable($admin819, "100%");
 if (!empty($del)) {
DestroyDBFile(REDACREP.$del.INCEXT);
/// modif albert: supp dans base admins -------------
$dbadm = ReadDBFields(DBADMIN);
  for ($k = 0; $k < count($dbadm); $k++) {
    if ($dbadm[$k][0] == $del) {
      unset($dbadm);
      DeleteDBFieldById(DBADMIN, $id=$k);
    }
  }
/// fin modif albert --------------------------------
}
?>
<center>
<p><?php echo $admin702 ?></p><br /><br />
<table cellspacing="0" cellpadding="2" width="50%" border="0">
<tr class="forum2"><td><b><?php echo $admin827; ?></b></td><td><b><?php echo $admin680; ?></b></td></tr>
<?php
$dbdrtredac = array();
$file_drtredac=opendir(REDACREP);
while ($nomfichier=readdir($file_drtredac)) {
 if( substr($nomfichier,-3)=="inc" ) {
$dbdrtredac[] = str_replace(substr($nomfichier,-4),"",$nomfichier);
 }
 }
closedir($file_drtredac);
@usort($dbdrtredac,'AsciiCompare');
for ($i = 0; $i < count($dbdrtredac); $i++) {
  if ($dbdrtredac[$i] != $userprefs[1]) {
    if ($i %2 == 0) echo "<tr>";
    else echo "<tr class=\"rep\">";
    ?>
    <td style="text-align:left;"><p><?php echo $dbdrtredac[$i];?></p></td>
    <td width="50" style="text-align:center;">
    <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=attribdroits&amp;etape=2&amp;namedroits=<?php echo $dbdrtredac[$i]; ?>"><img src="inc/img/files/edit.gif" alt="<?php echo $admin144; ?>" title="<?php echo $admin144; ?>" border="0"></a>&nbsp;&nbsp;
    <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=gestredac&amp;del=<?php echo $dbdrtredac[$i]; ?>"><img src="inc/img/files/sup.gif" alt="<?php echo $admin186; ?>" title="<?php echo $admin186; ?>" border="0"></a></td></tr>
    <?php
  }
}
?>
</table></center>
<div align="center"><br /><hr />
[ <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=droits"><?php echo $admin826; ?></a> || <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b> ]<br />
</div>
<?php
btable();
include(CHEMIN."inc/bpage.inc");

?>
