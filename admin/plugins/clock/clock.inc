<?php
/*
    Admin Clock Sample Plugin - GuppY PHP Script - vversion 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
	v3.0 (25 February 2004)  : initial release
	v4.0 (06 December 2004)  : no change      
*/

if (stristr($_SERVER["SCRIPT_NAME"], "clock.inc")) {
  header("location:../index.php");
  die();
}

if ($lng == "fr") {
include(CHEMIN."plugins/clock/fr-clock.inc");
}
else {
include(CHEMIN."plugins/clock/en-clock.inc");
}
include(CHEMIN."inc/hpage.inc");
htable($clock1, "100%");
?>
<p><?php echo $clock2; ?></p><hr />
<p><?php echo $clock3; ?><br /><br />
<u><?php echo $clock4; ?></u><br />
<?php echo $clock5; ?><br />
&lt;a href="[<?echo $site[3]; ?>]plugins/clock/clock.php"&gt;<?php echo $clock7; ?>&lt;/a&gt;<br /><br />
<u><?php echo $clock6; ?></u> <a href="<?php echo CHEMIN; ?>plugins/clock/clock.php?lng=<?php echo $lng; ?>" target="_blank"><?php echo $clock7; ?></a></p>
<p>&nbsp;</p>
<p><i><?php echo $clock8; ?></i></p>
<p>&nbsp;</p>
<p align="center"><a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b></p>
<?php
btable();
include(CHEMIN."inc/bpage.inc");
?>
