<?php
/*
    Statistics Reporting - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)     : initial release
      v2.2 (22 April 2003)        : replaced <P><CENTER> by <P align="center"> otherwise IE takes the default font instead of the required one (Thanks Michel)
                                    cleanup in the images organization
      v2.3 (27 July 2003)         : added forms style management (by Nicolas Alves)
      v3.0 (25 February 2004)     : added skin management (by Nicolas Alves)
      v4.0 (06 December 2004)     : added alt tags to img and removed border tag for non-linked img (by Isa)
      v4.5 (15 February 2005)     : corrected name of variable $barre (by Jean-Mi)
      v4.6.10 (7 September 2009)  : corrected #274
      v4.6.12 (01 May 2010) : #317 added display stats of previous month (by Icare)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "statshow.inc")) {
  header("location:../index.php");
  die();
}

if (CHEMIN == "") {
?>
<form name="chgestat" action="stats.php?lng=<?php echo $lng ?>" method="post">
<?php
}
else {
?>
<form name="chgstat" action="admin.php?lng=<?php echo $lng ?>&amp;pg=stats" method="post">
<?php
 }
?>
<table cellspacing="0" cellpadding="5" align="center" border="0" summary="">
<tr align="center"><td><p><b><?php echo $web71; ?></b></p>
<select name="per">
<option value="1" <?php if ($per == "1") { echo "selected='selected'"; } ?>><?php echo $web72; ?></option>
<option value="2" <?php if ($per == "2") { echo "selected='selected'"; } ?>><?php echo $web73; ?></option>
<option value="5" <?php if ($per == "5") { echo "selected='selected'"; } ?>><?php echo $web289; ?></option>
<option value="3" <?php if ($per == "3") { echo "selected='selected'"; } ?>><?php echo $web74; ?></option>
<option value="4" <?php if ($per == "4") { echo "selected='selected'"; } ?>><?php echo $web75; ?></option>
</select></td></tr>
<tr align="center"><td><p><b><?php echo $web76; ?></b></p>
<select name="anal">
<option value="1" <?php if ($anal == "1") { echo "selected='selected'"; } ?>><?php echo $web77; ?></option>
<option value="2" <?php if ($anal == "2") { echo "selected='selected'"; } ?>><?php echo $web78; ?></option>
<option value="3" <?php if ($anal == "3") { echo "selected='selected'"; } ?>><?php echo $web79; ?></option>
</select></td></tr>
<tr align="center"><td><?php echo $boutonleft; ?><input class="bouton" type="submit" value="<?php echo $web80; ?>" title="<?php echo $web80; ?>"/><?php echo $boutonright; ?></td></tr>
</table>
</form>
<?php
 if (!empty($anal)) {
  echo "<hr />";
 }
if ($anal == "1") {
 if ($per == "1") {
   $txt = $web81;
  }
  elseif ($per == "2" || $per == "5") {
   $txt = $web82;
  }
  else {
   $txt = $web83;
  }
?>
<p align="center"><b><?php echo $txt; ?></b></p>
<table cellspacing="0" cellpadding="0" align="center" border="0" summary="">
<?php

  $bar = 200/$maxshit;
  echo "<tr>\n";
  for ($k = 0; $k < count($shit); $k++) {
    echo "<td nowrap='nowrap' align=\"center\" valign=\"bottom\"><p>".$shit[$k][0]."<br /><img src=\"".CHEMIN."inc/img/bars/vertbleu.gif\" width=\"10\" hspace=\"2\" height=\"".round($shit[$k][0]*$bar)."\" alt=\"".$shit[$k][0]."\"/></p></td>";
  }
  echo "</tr><tr>\n";
  for ($k = 0; $k < count($shit); $k++) {
    echo "<td nowrap='nowrap' align=\"center\"><p><b>".$shit[$k][1]."</b></p></td>\n";
  }
  echo "</tr>\n";
  if ($per == "1") {
    $txt = $web84;
  }
  elseif ($per == "2" || $per == "5") {
    $txt = $web85;
  }
  else {
    $txt = $web86;
  }
?>
</table>
<p>&nbsp;</p><p align="center"><b><?php echo $txt; ?></b></p>
<table cellspacing="0" cellpadding="0" align="center" border="0" summary="">
<?php

  $bar = 200/$maxsnbpage;
  echo "<tr>\n";
  for ($k = 0; $k < count($snbpage); $k++) {
    echo "<td nowrap='nowrap' align=\"center\" valign=\"bottom\"><p>".$snbpage[$k][0]."<br /><img src=\"".CHEMIN."inc/img/bars/vertviolet.gif\" width=\"10\" hspace=\"2\" height=\"".round($snbpage[$k][0]*$bar)."\" alt=\"".$snbpage[$k][0]."\"/></p></td>";
  }
  echo "</tr><tr>\n";
  for ($k = 0; $k < count($snbpage); $k++) {
    echo "<td nowrap='nowrap' align=\"center\"><p><b>".$snbpage[$k][1]."</b></p></td>\n";
  }
  echo "</tr>\n";
?>
</table>
<?php
 }
 if ($anal == "2") {
?>
<p>&nbsp;</p><p align="center"><b><?php echo $web87; ?></b></p>
<table cellspacing="0" cellpadding="0" align="center" border="0" summary="">
<?php

  $bar = 250/$maxslang;
  for ($k = 0; $k < count($slang); $k++) {
    echo "<tr>\n";
    echo "<td><p><b>".$slang[$k][1]." </b></p></td>\n";
    echo "<td nowrap='nowrap'><p><img src=\"".CHEMIN."inc/img/bars/vert.gif\" width=\"".round($slang[$k][0]*$bar)."\" height=\"10\" hspace=\"5\" alt=\"".$slang[$k][1]."\"/>";
    echo $slang[$k][0]."</p></td>\n";
    echo "</tr>\n";
  }
?>
</table>
<p>&nbsp;</p><p align="center"><b><?php echo $web88; ?></b></p>
<table cellspacing="0" cellpadding="0" align="center" border="0" summary="">
<?php

  $bar = 250/$maxspage;
  for ($k = 0; $k < count($spage); $k++) {
    echo "<tr>\n";
    echo "<td><p><b>".$spage[$k][1]." </b></p></td>\n";
    echo "<td nowrap='nowrap'><p><img src=\"".CHEMIN."inc/img/bars/orange.gif\" width=\"".round($spage[$k][0]*$bar)."\" height=\"10\" hspace=\"5\" alt=\"".$spage[$k][1]." \"/>";
    echo $spage[$k][0]."</p></td>\n";
    echo "</tr>\n";
 }
?>
</table>
<?php
 }
 if ($anal == "3") {
?>
<p>&nbsp;</p><p align="center"><b><?php echo $web89; ?></b></p>
<table cellspacing="0" cellpadding="0" align="center" border="0" summary="">
<?php

  $bar = 250/$maxsnav;
  for ($k = 0; $k < count($snav); $k++) {
    echo "<tr>\n";
    echo "<td><p><b>".$snav[$k][1]." </b></p></td>\n";
    echo "<td nowrap='nowrap'><p><img src=\"".CHEMIN."inc/img/bars/rouge.gif\" width=\"".round($snav[$k][0]*$bar)."\" height=\"10\" hspace=\"5\" alt=\"".$snav[$k][1]."\"/>";
    echo $snav[$k][0]."</p></td>\n";
    echo "</tr>\n";
  }
?>
</table>
<p>&nbsp;</p><p align="center"><b><?php echo $web90; ?></b></p>
<table cellspacing="0" cellpadding="0" align="center" border="0" summary="">
<?php

  $bar = 250/$maxsos;
  for ($k = 0; $k < count($sos); $k++) {
    echo "<tr>\n";
    echo "<td><p><b>".$sos[$k][1]." </b></p></td>\n";
    echo "<td nowrap='nowrap'><p><img src=\"".CHEMIN."inc/img/bars/bleu.gif\" width=\"".round($sos[$k][0]*$bar)."\" height=\"10\" hspace=\"5\" alt=\"".$sos[$k][1]."\"/> ";
    echo $sos[$k][0]."</p></td>\n";
    echo "</tr>\n";
  }
?>
</table>
<?php
}
?>
