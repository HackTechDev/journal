<?php
/*
    Poll Box - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)      : initial release
      v2.1 (10 March 2003)         : added addslashes() to var in Javascript functions (to avoid errors)
      v2.2 (22 April 2003)         : cleanup in the images organization
      v2.3 (27 July 2003)          : added forms style management (by Nicolas Alves)
      v3.0 (25 February 2004)      : added skin management (by Nicolas Alves)
      v4.0 (06 December 2004)      : added the sidebox specific style (by Isa)
      v4.6.5 (05 December 2007)    : reorganization of language test, deletion of unused $topmess (by Icare)
      v4.6.10 (7 September 2009)   : corrected #274
	  v4.6.20 (24 May 2012)        : added $boxtitle (by Saxbar)
                                     corrected btable1 (by Saxbar)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "boxpoll.inc")) {
  header("location:../index.php");
  die();
}

include(CHEMIN."inc/poll.inc");
 if ($lng == $lang[0]) {
 $i = 0;
 $j = 0;
 $txt = $commun[0][0];
}
else {
 $i = 10;
 $j = 1;
 $txt = $commun[0][1];
}
$boxtitle = $nom[$i+6];
htable1($boxtitle, "100%");
?>
<form action="<?php echo CHEMIN; ?>poll.php?lng=<?php echo $lng; ?>" method="post" name="formV">
<table cellspacing="0" cellpadding="0" align="center" border="0" summary="">
<tr><td class="box" align="center" colspan="2"><?php echo $txt; ?></td></tr>
<tr><td>&nbsp;</td></tr>
<?php
 for ($k = 1; $k < $lignes; $k++) {
  echo "<tr valign=\"top\"><td align=\"center\"><input type=\"radio\" name=\"choix\" value=\"".$k."\"/></td><td class=\"box\" style=\"text-indent: 6px;text-align:left\">".$commun[$k][$j]."</td></tr>\n";
 }
?>
<tr><td colspan="2" align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $web9; ?>"><?php echo $web9; ?></button><?php echo $boutonright; ?></td></tr>
<tr><td colspan="2" align="center"><a class="box" href="<?php echo CHEMIN; ?>poll.php?lng=<?php echo $lng; ?>"><?php echo $web10; ?></a></td></tr>
</table>
</form>
<?php
if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $drtuser[25]=="on")) {
?>
<p align="right"><a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=poll"><img src="<?php echo CHEMIN; ?>inc/img/general/edit.gif" border="0" alt="<?php echo $web308; ?>" title="<?php echo $web308; ?>"/></a></p>
<?php
}
btable1($boxtitle);
?>
