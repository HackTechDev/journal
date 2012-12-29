<?php
/*
    Mind Box - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v3.0 (25 February 2004)  : initial release
      v4.0 (06 December 2004)  : added sidebox specific style (by Isa)
	  v4.6.20 (24 May 2012)    : corrected btable1 (by Saxbar)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "boxmind.inc")) {
  header("location:../index.php");
  die();
}

if ($lng == "fr") {
  include(CHEMIN."plugins/mind/fr-mind.inc");
}
else {
  include(CHEMIN."plugins/mind/en-mind.inc");
}
htable1($mind7, "100%");
?>
<form action="<?php echo CHEMIN; ?>plugins/mind/mind.php?lng=<?php echo $lng; ?>" method="post" name="formMind">
<p class="box"><?php echo $mind3; ?></p>
<p align="center"><?php echo $boutonleft; ?><input class="bouton" type="button" value="<?php echo $mind9; ?>" title="<?php echo $mind9; ?>" onclick="javascript:document.formMind.submit();" /><?php echo $boutonright; ?></p>
</form>
<?php
btable1($mind7);
?>
