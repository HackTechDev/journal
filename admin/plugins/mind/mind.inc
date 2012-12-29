<?php
/*
    Admin Samples Plugin - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
	v3.0 (25 February 2004)  : initial release
	v4.0 (06 December 2004)  : no change

*/

if (stristr($_SERVER["SCRIPT_NAME"], "mind.inc")) {
  header("location:../index.php");
  die();
}

if ($lng == "fr") {
  include(CHEMIN."plugins/mind/fr-mind.inc");
}
else {
  include(CHEMIN."plugins/mind/en-mind.inc");
}

include(CHEMIN."inc/hpage.inc");
htable($mind1, "100%");
?>

<p><?php echo $mind2; ?></p><hr />
<p><?php echo $mind3; ?><br /><br />
<u><?php echo $mind4; ?></u><br />
<?php echo $mind5; ?> <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin346; ?></a><br /><br />
<u><?php echo $mind6; ?></u> <a href="<?php echo CHEMIN; ?>plugins/mind/mind.php?lng=<?php echo $lng; ?>" target="_blank"><?php echo $mind7; ?></a></p>
<p>&nbsp;</p>
<p align="center"><a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b></p>

<?php
btable();
include(CHEMIN."inc/bpage.inc");
?>
