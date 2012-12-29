<?php
/*
    Admin Droits- GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
       v4.0 (06 December 2004)  : initial release by Nicolas Alves
*/

if (stristr($_SERVER["SCRIPT_NAME"], "droits.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[12]=="") {
    $nomzone=$admin818;
    include("access.inc");
    exit();
  }
}
include(CHEMIN."inc/hpage.inc");
htable($admin819, "100%");
?>
<div align="center"><br />
<table align="center" cellspacing="0" cellpadding="0" border="0">
<tr>
<td nowrap style="width:40%; text-align:center"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=attribdroits&amp;etape=1"  title="<?php echo $admin820; ?>"><img src="inc/img/admin/droits.gif" alt="<?php echo $admin820; ?>" border="0" /><br /><?php echo $admin820; ?></a></td>
<td nowrap style="width:40%; text-align:center"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=gestredac" title="<?php echo $admin821; ?>"><img src="inc/img/admin/droits.gif" alt="<?php echo $admin821; ?>" border="0" /><br /><?php echo $admin821; ?></a></td>
</tr>
</table>
<hr />
<a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b>
</div>
<?php
btable();
include(CHEMIN."inc/bpage.inc");

?>
