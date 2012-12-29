<?php
/*
    NewsLetter Box - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v3.0 (25 February 2004)       : initial release by Nicolas Alves and Laurent Duveau
      v4.0 (06 December 2004)       : added the box specific style and modified the table design (by Isa)
      v4.6.0 (04 June 2007)         : added optional registration to subscription (by Icare)
      v4.6.10 (7 September 2009)    : corrected #274
	  v4.6.20 (24 May 2012)         : added $boxtitle (by Saxbar)
                                      corrected btable1 (by Saxbar)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "boxnewslet.inc")) {
  header("location:../index.php");
  die();
}

if ($lng == $lang[0]) {
  $i = 0;
}
else {
  $i = 1;
}
if (($members[0]=="on" && $members[18]=="on") && ($userprefs[1]=="" )) {
/* pas d'accès à l'inscription - no subscription */
} else {
  $boxtitle = $nom[$i+38];
  htable1($boxtitle, "100%");
  $nabon = CountDBFields(DBNEWSLETTER);
  if ($nabon < 2) {
    $mot=$web257;
  }
  else {
    $mot = $web258;
  }
  if (!empty($userprefs[1])) {
    $txt1 = $userprefs[1];
  }
  else {
    $txt1 = $web259;
  }
  if (!empty($userprefs[2])) {
    $txt2 = $userprefs[2];
  }
  else {
    $txt2 = $web260;
  }
  ?>
  <form name="subscribe" action="<?php echo CHEMIN; ?>newsletter.php?lng=<?php echo $lng; ?>" method="post">
  <table cellspacing="0" cellpadding="0" align="center" border="0" summary="">
  <tr><td class="box" align="center"><?php echo $web247; ?></td></tr>
  <tr><td align="center"><input class="texte" type="text" name="nlpseudo" size="18" value="<?php echo $txt1; ?>" onfocus="this.value=''" /></td></tr>
  <tr><td align="center"><input class="texte" type="text" name="nlmail" size="18" value="<?php echo $txt2; ?>" onfocus="this.value=''" /></td></tr>
  </table>
  <table cellspacing="0" cellpadding="0" align="center" border="0" summary="">
  <tr><td><input type="radio" name="action" checked="checked" value="sub"/></td><td class="box"><?php echo $web237 ?></td></tr>
  <tr><td><input type="radio" name="action" value="unsub"/></td><td class="box"><?php echo $web236 ?></td></tr>
  <tr><td colspan="2" align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $web52; ?>"><?php echo $web52; ?></button><?php echo $boutonright; ?></td></tr>
  <tr><td colspan="2" class="box" align="center">
  <?php
  if ($nabon == 0) {
    ?>
    <b><?php echo $mot; ?><br /><?php echo $web176; ?></b><br /><img src="<?php echo CHEMIN; ?>inc/img/general/empty.gif" alt="Snif !!!" title="Snif !!!"/>
    <?php
  }
  else {
    echo $nabon." ".$mot;
  }
  ?>
  </td></tr>
  </table>
  </form>
  <?php
  if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $drtuser[33]=="on")) {
  ?>
  <p align="right"><a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=newsletter"><img src="<?php echo CHEMIN; ?>inc/img/general/edit.gif" border="0" alt="<?php echo $web308; ?>" title="<?php echo $web308; ?>"/></a></p>
  <?php
  }
  btable1($boxtitle);
}
?>
