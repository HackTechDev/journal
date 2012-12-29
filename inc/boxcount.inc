<?php
/*
    Counter Box - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.3 (06 January 2003)   : added send supervision e-mail
      v1.4 (07 January 2003)   : avoid sending supervision e-mail more than one time
      v1.5 (10 January 2003)   : introduced statsbk.dtb for not loosing the main counter's
                                   value in case of accidental delete of stats.dtb file
      v1.8 (05 February 2003)  : bug correction in the eMailTo() function call
      v2.1 (10 March 2003)     : counter theme management (by Nicolas Alves)
      v2.2 (22 April 2003)     : replaced <P><CENTER> by <P align="center"> otherwise IE takes the default font instead of the required one (Thanks Michel)
                                 cleanup in the images organization
      v2.3 (27 July 2003)      : removed link on counters numbers
      v2.4 (24 September 2003) : moved counter upgrade from inc/boxcount.inc to inc/log.inc
      v4.0 (06 December 2004)  : added the box specific style (by Isa)
                                 added a non graphical counter option (by Isa)
	  v4.6.20 (24 May 2012)    : added $boxtitle (by Saxbar)
                                 corrected htable1, btable1 (by Saxbar)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "boxcount.inc")) {
  header("location:../index.php");
  die();
}

 if ($lng == $lang[0]) {
    $i = 0;
}
else {
 $i = 10;
}
$boxtitle = $nom[$i+8];
htable1($boxtitle, "100%");
echo "<p class=\"box\" align=\"left\">&nbsp;";
 if ($page[11] =="") {
    echo $tabcounter[0];
 echo "&nbsp;";
}
else {
 AfficheCompteur(CHEMIN."inc/img/counter/".$page[11]."/", $tabcounter[0]);
 echo "&nbsp;&nbsp;";
}
 if ($tabcounter[0] == 1) {
    echo $web15;
}
else {
 echo $web16;
}
 echo "</p><p class=\"box\" align=\"left\">&nbsp;";
 if ($page[11] =="") {
    echo $tabcounter[1];
 echo "&nbsp;";
}
else {
 AfficheCompteur(CHEMIN."inc/img/counter/".$page[11]."/", $tabcounter[1]);
 echo "&nbsp;&nbsp;";
}
 if ($tabcounter[1] == 1) {
    echo $web17;
}
else {
 echo $web18;
}
 echo "</p>";
 if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $drtuser[31]=="on")) {
?>
<p align="right"><a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=count"><img src="<?php echo CHEMIN; ?>inc/img/general/edit.gif" border="0" alt="<?php echo $web308; ?>" title="<?php echo $web308; ?>"/></a></p>
<?php
}
btable1($boxtitle);
?>
