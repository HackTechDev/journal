<?php
/*
    Admin Speed Sample Plugin - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
	v3.0 (25 February 2004)  : initial release
	v4.0 (06 December 2004)  : no change
      
*/

if (stristr($_SERVER["SCRIPT_NAME"], "speed.inc")) {
  header("location:../index.php");
  die();
}

if ($lng == "fr") {
  include(CHEMIN."plugins/speed/fr-speed.inc");
}
else {
  include(CHEMIN."plugins/speed/en-speed.inc");
}

include("plugins/funcplug.inc");

if ($regit == 1) {
  if ($speedy == "on") {
    if (!PluginRegistered("speed")) {
      RegisterPlugin("speed");
    }
  }
  else {
    UnregisterPlugin("speed");
  }
}

include(CHEMIN."inc/hpage.inc");
htable($speed1, "100%");
?>

<p><?php echo $speed2; ?></p><hr />
<p><?php echo $speed3; ?><br /><br />
<u><?php echo $speed4; ?></u><br />
<?php echo $speed5; ?><br /><br />
<u><?php echo $speed6; ?></u> <a href="<?php echo CHEMIN; ?>plugins/speed/speed.php?lng=<?php echo $lng; ?>" target="_blank"><?php echo $speed7; ?></a></p>
<form name="speed" action="admin.php?lng=<?php echo $lng; ?>&amp;pg=plugin&amp;plug=speed/speed" method="post">
<input type="hidden" name="regit" value="1">
<table cellspacing="1" cellpadding="5" align="center" border="1"><tr><td>
<table cellspacing="0" cellpadding="2" align="center" border="0">
<tr><td><p><?php echo $speed8; ?>&nbsp;&nbsp;<input type="checkbox" name="speedy" <?php if (PluginRegistered("speed")) echo "checked"; ?>></p></td></tr>
</table>
<p align="center"><?php echo $boutonleft; ?><input class="bouton" type="submit" value="<?php echo $admin66; ?>" title="<?php echo $admin66; ?>"><?php echo $boutonright; ?></p>
</td></tr></table>
</form>
<p>&nbsp;</p>
<p align="center"><a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b></p>

<?php
btable();
include(CHEMIN."inc/bpage.inc");
?>
