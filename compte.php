<?php
/*
    Account - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v4.0 (06 December 2004)     : initial release (by Nicolas Alves)
      v4.6.0 (04 June 2007)       : corrected boxes position (by Icare)
      v4.6.10 (7 September 2009)  : corrected #272 and #274
      v4.6.15 (30 June 2011)      : added private group management (by Icare)
      v4.6.18 (09 February 2012)  : change control registration members (by Saxbar)  
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");

 if ($serviz[28] != "on") {
 exit($web143);
}

include("inc/hpage.inc");

 if ($lng == $lang[0]) {
  $i = 0;
  }
  else {
  $i = 1;
}
 htable($web317." - ".$userprefs[1], "100%");
?>
<p>&nbsp;</p>
<?php
 if (!empty($usermess)) {
?>
<p align="center"><b><?php echo $usermess; ?></b></p>
<p>&nbsp;</p>
<?php
 }
?>
<table class="bord" cellspacing="2" cellpadding="1" align="center" width="98%" border="0" summary="">
<tr><td class="forum2"><p><?php echo $web49; ?></p></td><td class="rep"><b><?php echo $userprefs[1]; ?></b></td></tr>
<?php
if ($members[0]!="on") {
 if($userprefs[5]!="") {
?>
<tr><td class="forum2"><p><?php echo $web312; ?></p></td><td class="rep"><b><?php echo $web313; ?></b></td></tr>
<?php
 }
else {
?>
<tr><td class="forum2"><p><?php echo $web312; ?></p></td><td class="rep"><b><?php echo $web314; ?></b></td></tr>
<?php
 }
}
$textout = preg_replace("![a-zA-Z0-9_]!","&#149",$userprefs[7]);
?>
<tr><td class="forum2"><p><?php echo $web300; ?></p></td><td class="rep"><b><?php echo $textout; ?></b></td></tr>
<tr><td class="forum2"><p><?php echo $web50; ?></p></td><td class="rep"><b><?php echo $userprefs[2]; ?></b></td></tr>
<?php
 if ($userprefs[9]=="") {
?>
<tr><td class="forum2"><p><?php echo $web51; ?></p></td><td class="rep"><b><?php echo $web316; ?></b></td></tr>
<?php
}
else {
?>
<tr><td class="forum2"><p><?php echo $web51; ?></p></td><td class="rep"><b><?php echo $userprefs[9]; ?></b></td></tr>

<?php
 }
 if($userprefs[6]!="") {
?>
<tr><td class="forum2"><p><?php echo $web219; ?></p></td><td class="rep"><b><?php echo stripslashes($userprefs[6]); ?></b></td></tr>
<?php
 }
 else {
?>
<tr><td class="forum2"><p><?php echo $web219; ?></p></td><td class="rep"><b><?php echo $web309; ?></b></td></tr>
<?php
 }
?>
 <tr><td class="forum2"><p><?php echo $web155; ?></p></td><td class="rep"><b><?php echo $userprefs[0]; ?></b></td></tr>
<?php
  if ($userprefs[10]!="") {
?>
<tr><td class="forum2"><p><?php echo $web310; ?></p></td><td class="rep"><b><?php echo $userprefs[10]; ?></b></td></tr>
<?php
}
else {
?>
<tr><td class="forum2"><p><?php echo $web310; ?></p></td><td class="rep"><b><?php echo $web315; ?></b></td></tr>
<?php
}
if ($userprefs[3] == "L") {
  $textpos = $web166;
}
if ($userprefs[3] == "R") {
  $textpos= $web232;
}
if ($userprefs[3] == "LR") {
  $textpos= $web165;
}
if ((empty($posbox[1]) && empty($posbox[3]) && empty($posbox[5]) && empty($posbox[7]) && empty($posbox[9]) && empty($posbox[11]) && empty($posbox[13]) && empty($posbox[15]) && empty($posbox[17]) && empty($posbox[19])) ||
  (empty($posbox[0]) && empty($posbox[2]) && empty($posbox[4]) && empty($posbox[6]) && empty($posbox[8]) && empty($posbox[10]) && empty($posbox[12]) && empty($posbox[14]) && empty($posbox[16]) && empty($posbox[18]))) {
$textpos .= " (fix)";
}
?>
<tr><td class="forum2"><p><?php echo $web164; ?></td><td class="rep"><b><?php echo $textpos; ?></b></td></tr>
<?php
 if($userprefs[11]!="") {
?>
<tr><td class="forum2"><p><?php echo $web375; ?></p></td><td class="rep"><b><?php echo $web313; ?></b></td></tr>
<?php
}
else {
?>
<tr><td class="forum2"><p><?php echo $web375; ?></p></td><td class="rep"><b><?php echo $web314; ?></b></td></tr>
<?php
 }
 if ($userprefs[8]!="") {
?>
<tr><td class="forum2"><p><?php echo $web311; ?></p></td><td class="rep"><img border="0" src="<?php echo CHEMIN; ?>inc/img/avatars/<?php echo $page[23]; ?>/<?php echo $userprefs[8]; ?>" alt="<?php echo $userprefs[1]; ?>" title="<?php echo $userprefs[1]; ?>" /></td></tr>

<?php
 }
 else {
?>

<tr><td class="forum2"><p><?php echo $web311; ?></p></td><td class="rep"><img border="0" src="<?php echo CHEMIN; ?>inc/img/avatars/unknow.gif" alt="<?php echo $web305; ?>" title="<?php echo $web305; ?>" /></td></tr>
<?php
 }
?>
</table>
<div align="center">
  <form name="userpref" action="<?php echo CHEMIN; ?>user.php?lng=<?php echo $lng; ?>" method="post">
  <input type="hidden" name="modif" value="1" />
  <input type="hidden" name="new" value="off" />
  <?php echo $boutonleft; ?><button type="submit" title="<?php echo $web308; ?>"><?php echo $web308; ?></button><?php echo $boutonright; ?>
  </form>
  <form name="userbye" action="<?php echo CHEMIN; ?>user.php?lng=<?php echo $lng; ?>" method="post">
  <input type="hidden" name="unreg" value="1" />
  <?php echo $boutonleft; ?><button type="submit" title="<?php echo $web162; ?>"><?php echo $web162; ?></button><?php echo $boutonright; ?>
  </form>

</div>
<?php
btable();
include("inc/bpage.inc");
?>
