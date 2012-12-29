<?php
/*
    Reaction box - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v2.4 (24 September 2003)    : initial release
      v3.0p2 (09 April 2004)      : removed the empty URL link display (thanks Realia)
      v4.0 (06 December 2004)     : added alt tags to img and removed border tag for non-linked img (by Isa)
                                    removed the trans pixel (by Isa)
                                    replaced & by &amp; for more standards compliance (by Isa)
      v4.5 (30 March 2005)        : replacing navigation bar (by Jean-Mi)
      v4.6.1 (02 July 2007)       : removed a duplicate p tag (by Icare)
      v4.6.2 (30 August 2007)     : display only active reactions (by Icare)
      v4.6.6 (14 April 2008)      : added urlencode to $author (by JeanMi)
      v4.6.10 (7 September 2009)  : corrected #274
      v4.6.11 (11 December 2009)  : changing hr by class bord, width by style=width (by Icare)
      v4.6.15 (30 June 2011)      : added private group management (by Icare)
	  v4.6.17 (21 October 2011)   : fixed print view (by Saxbar)
	  v4.6.20 (24 May 2012)       : corrected btable (by Saxbar)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "boxreact.inc")) {
  header("location:../index.php");
  die();
}

if ($serviz[29] == "") {
  exit($web143);
}
$react = strip_tags($react);
$id = strip_tags($id);

$dbwork = array();
if (!empty($react)) {
  $dbwork[0] = $react;
}
elseif (!empty($pg)) {
  $dbreaction = ReadDBFields(DBREACT);
  for ($i = 0; $i < count($dbreaction); $i++) {
    if ($dbreaction[$i][1] == $pg) {
      $dbwork[] = $dbreaction[$i][0];
    }
  }
}
@rsort($dbwork);
$topmess = $web184;
if ($page[9] != "") {
  $topmess = "<img src=\"".CHEMIN."inc/img/icons/".$page[9]."/react.gif\" align=\"right\" alt=\"react.gif\" />".$topmess;
}
?>
<?php
htable($topmess, "100%");
if (!isset($prt)) {
?>
<form name="react" action="postguest.php?lng=<?php echo $lng;?>" method="post">
<input type="hidden" name="typ" value="<?php echo TYP_REACT; ?>"/>
<input type="hidden" name="pg" value="<?php echo $pg; ?>"/>
<p align="center">
<?php echo $boutonleft; ?><button type="submit" title="<?php echo $web181; ?>"><?php echo $web181; ?></button><?php echo $boutonright; ?></p>
</form>
<?php
}
if (empty($id)) {
  $id = 1;
}
if (isset($prt)) $serviz[30] = 999999;
if (!empty($dbwork)) {
  for ($i = $serviz[30]*($id-1); $i < Min($serviz[30]*$id, count($dbwork)); $i++) {
    ReadDoc(DBBASE.$dbwork[$i]);
    /// début modif accès réservé
    $acces = "ok";
    if ($fieldmod != "") {
      $acces = "no";
      if ($userprefs[1] != "") {
        include_once (CHEMIN.'inc/func_groups.php');
        if (CheckGroup($fieldmod, $userprefs[1])) $acces ="ok";
      }
    }
    if ($acces == "ok") {
    /// fin modif accès réservé
    if ($status == "a") {
?>
    <br />
    <table class="bord" cellpadding="0" cellspacing="0" width="100%" border="0" summary="">
    <tr class="rep"><td nowrap="nowrap" style="width:15%;vertical-align:top;"><p><?php echo $web185.$fielda1; ?>&nbsp;</p></td>
    <td style="width:85%">
<?php
    echo $web6." ";
    if ($fieldd1 != "on") {
      $em = BreakEMail($email);
?>
      <b><a href="JavaScript:WriteMailTo('<?php echo addslashes(urlencode($author)); ?>','<?php echo $em[0]; ?>','<?php echo $em[1]; ?>','<?php echo $em[2]; ?>')"><?php echo addslashes($author); ?></a></b>
<?php
    }
    else {
      echo "<b>".$author."</b>";
    }
    echo " ".$web7." ".FormatDate($creadate);
    echo "</td></tr>\n";
    echo "<tr><td colspan='2'><br />".$fieldc1."\n";
    if ((($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $serviz[29]=="on" && $drtuser[16]=="on")) && !isset($prt)) {
?>
      </td></tr><tr><td colspan="2" style="text-align:right;">
      <p align="right">
      <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=react&amp;form=2&amp;id=<?php echo $dbwork[$i]; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/edit.gif" border="0" alt="<?php echo $web308; ?>" title="<?php echo $web308; ?>" /></a>
      <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=react&amp;act=i&amp;id=<?php echo $dbwork[$i]; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/desact.gif" border="0" alt="<?php echo $web333; ?>" title="<?php echo $web333; ?>" /></a>
      <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=react&amp;del=<?php echo $dbwork[$i]; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/del.gif" border="0" alt="<?php echo $web324; ?>" title="<?php echo $web324; ?>" /></a></p>
<?php
    }
?>
    </td></tr>
    </table>
<?php
    }
    } /// fin accès privé
  }
}
else {
?>
<table align="center" border="0" summary=""><tr><td><p align="center"><?php echo $web186; ?></p></td></tr></table>
<?php
 }
echo GetNavBar("articles.php?lng=".$lng."&amp;pg=".$pg."&amp;id=", count($dbwork), $id, $serviz[30]);
btable($topmess);
?>
