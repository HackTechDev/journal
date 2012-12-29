<?php
/*
    Admin Acces - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2008 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
	v4.0 (06 December 2004)  : initial release by Nicolas Alves
	v4.6.9 (25 December 2008): correction name of file (line 14) #232
*/

if (stristr($_SERVER["SCRIPT_NAME"], "access.inc")) {
  header("location:../index.php");
  die();
}

include(CHEMIN."inc/hpage.inc");
htable($admin848, "100%");
?>
<p align="center"><?php echo $admin847."<b> ".$nomzone."</b>"; ?><br /></p><br />
<p align="center"><a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b></p>
<?php
btable();
include(CHEMIN."inc/bpage.inc");
?>
