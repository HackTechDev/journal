<?php
/*
    RSS News Box - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v3.0 (25 February 2004)  : initial release
      v4.0 (06 December 2004)  : added the sideboxes specific style (by Isa)
                                 corrected the link format : closing </a> tag was missing (by Isa)
                                 replaced & by &amp; in URL for standard compliance (by Isa)
	  v4.6.20 (24 May 2012)    : added $boxtitle (by Saxbar)
                                 corrected btable1 (by Saxbar)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "boxrss.inc")) {
  header("location:../index.php");
  die();
}

if ($lng == $lang[0]) {
  $i = 0;
}
else {
  $i = 1;
}
$dbrss = ReadDBFields(DBRSS);
sort($dbrss);
$boxtitle = $nom[$i+36];
htable1($boxtitle, "100%");
for ($j = 0; $j < count($dbrss); $j++) {
  ?>
  <div align="center"><a class="box" href="<?php echo CHEMIN; ?>newsrss.php?lng=<?php echo $lng; ?>&amp;id=<?php echo $dbrss[$j][4]; ?>"><?php echo $dbrss[$j][$i]; ?></a></div>
  <?php
}
if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $drtuser[34]=="on")) {
?>
<p align="right"><a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=rss"><img src="<?php echo CHEMIN; ?>inc/img/general/edit.gif" border="0" alt="<?php echo $web308; ?>" title="<?php echo $web308; ?>" /></a></p>
<?php
}
btable1($boxtitle);
?>
