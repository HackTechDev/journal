<?php
/*
   Counter Plugin - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Nicolas Alves
      Web site = http://cambodiaplus.com/
      e-mail   = nico@cambodiaplus.com

    Version History :
      v1.0 (29 Juin 2004)     : Version initiale
      v2.0 (22 juillet 2004)  : Ai intégré un compteur de nombre d’articles, téléchargements et messages forums
                                Correction d'une faute d’orthographe, merci RV.
      v4.0 (06 December 2004) : added multi-admin management (by Nicolas Alves)
	                            updated html tags (by Icare)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "count.inc")) {
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
include(CHEMIN."inc/hpage.inc");
htable($admin652, "100%");
?>
<p align="center"><?php echo $counter_admin7; ?></p>
<hr />
<table cellspacing="10" cellpadding="1" align="center" border="0" summary="">
<tr align="center">
<td nowrap="nowrap"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=counter"><img src="inc/img/admin/counter.gif" width="32" height="32" alt="<?php echo $admin653; ?>" border="0" /><br /><?php echo $admin653; ?></a></td>
<td nowrap="nowrap"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=countart"><img src="inc/img/admin/counter.gif" width="32" height="32" alt="<?php echo $admin654; ?>" border="0" /><br /><?php echo $admin654; ?></a></td>
<td nowrap="nowrap"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=countforum"><img src="inc/img/admin/counter.gif" width="32" height="32" alt="<?php echo $admin655; ?>" border="0" /><br /><?php echo $admin655; ?></a></td>
<td nowrap="nowrap"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=countdwnl"><img src="inc/img/admin/counter.gif" width="32" height="32" alt="<?php echo $admin656; ?>" border="0" /><br /><?php echo $admin656; ?></a></td>
</tr></table>
<div align="center">
<hr />
[ <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b> ]
</div>
<?php
btable();
include(CHEMIN."inc/bpage.inc");

?>
