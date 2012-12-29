<?php
/*
    Admin Newsletter - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v3.0 (25 February 2004)  : initial release by Nicolas Alves
      v4.0 (06 December 2004)  : changed cellpadding to 3 for nice display (Isa)
	                             added page title (by Jean-Mi)
				                 added multi-admin management (by Nicolas Alves)
      v4.6.10 (7 September 2009)    : corrected #274
*/

if (stristr($_SERVER["SCRIPT_NAME"], "newsletter.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[33]=="") {
    $nomzone=$admin546;
    include("access.inc");
    exit();
  }
}
header("Pragma: no-cache");
$topmess = $admin545;
include(CHEMIN."inc/hpage.inc");
htable($admin545, "100%");
?>
<p align="center"><?php echo $admin532; ?></p><hr />
<table cellspacing="0" cellpadding="3" align="center" border="0" summary="">
<tr>
<td nowrap="nowrap"><p align="center"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=nwllist" title="<?php echo $admin540; ?>"><img src="inc/img/admin/newsletter.gif" alt="<?php echo $admin540; ?>" border="0"/><br /><?php echo $admin540; ?></a></p></td>
<td nowrap="nowrap"><p align="center"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=nwl" title="<?php echo $admin538; ?>"><img src="inc/img/admin/newsletter.gif" alt="<?php echo $admin538; ?>" border="0"/><br /><?php echo $admin538 ?></a></p></td>
<td nowrap="nowrap"><p align="center"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=nwlsend" title="<?php echo $admin534; ?>"><img src="inc/img/admin/newsletter.gif" alt="<?php echo $admin534; ?>" border="0"/><br /><?php echo $admin534; ?></a></p></td>
</tr></table>
<p>&nbsp;</p>
<p align="center">
[ <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b> ]</p>
<?php
btable();
include(CHEMIN."inc/bpage.inc");

?>
