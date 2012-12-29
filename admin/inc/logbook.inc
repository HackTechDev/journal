<?php
/*
    Admin Log - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v3.0 (25 February 2004)  : initial release by B@lou, Nicolas Alves and Laurent Duveau (real team work!)
      v4.0 (06 December 2004)  : added alt tags to img and removed border tag for non-linked img,
                                 changed cellpadding to 3 for nice displaying (Isa)
				                 added multi-admin management (by Nicolas Alves)
				                 added page title (by Jean-Mi)
      v4.6.10 (7 September 2009)    : corrected #274
*/

if (stristr($_SERVER["SCRIPT_NAME"], "logbook.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[35]=="") {
    $nomzone=$admin553;
    include("access.inc");
    exit();
  }
}
header("Pragma: no-cache");
$topmess = $admin556;
include(CHEMIN."inc/hpage.inc");
htable($admin556, "100%");
?>
<p align="center"><?php echo $admin555; ?></p><hr />
<table cellspacing="0" cellpadding="3" align="center" border="0" summary="">
  <tr>
    <td nowrap="nowrap"><p align="center"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=logconfig"><img src="inc/img/admin/eye.gif" width="32" height="32" alt="<?php echo $admin7; ?>" title="<?php echo $admin7; ?>" border="0" /><br /><?php echo $admin7 ?></a></p></td>
    <td></td><td nowrap="nowrap"><p align="center"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=logread"><img src="inc/img/admin/eye.gif" width="32" height="32" alt="<?php echo $admin554; ?>" title="<?php echo $admin554; ?>" border="0" /><br /><?php echo $admin554; ?></a></p></td>
  </tr>
</table>
<hr />
<p align="center">
[ <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b> ]</p>
<?php
btable();
include(CHEMIN."inc/bpage.inc");

?>
