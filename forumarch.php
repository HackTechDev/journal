<?php
/*
    Forum Archive - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v3.0 (25 February 2004)     : initial release
      v4.0 (06 December 2004)     : added page title (by Jean-Mi)
                                    added alt tags to img and removed border tag for non-linked img (by Isa)
                                    added the forum style management, replaced & by &amp; for W3C compliance (by Isa)
      v4.6.6 (14 April 2008)      : added urlencode in WriteMailto() (by JeanMi)
      v4.6.10 (7 September 2009)  : corrected #274
      v4.6.18 (09 February 2012)  : corrected for archiving private forum (by Saxbar)
	  v4.6.22 (29 December 2012)  : added pseudo-private group for members (by Saxbar)
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");
include("inc/funcarch.php");

if ($serviz[13] != "on") {
  exit($web143);
}

$pg = strip_tags($pg);
$cat = strip_tags($cat);
$id = strip_tags($id);

function SelectDBForumByID($Fields,$id) {
  $DataDB = array();
  $k = 0;
  for ($i = 0; $i < count($Fields); $i++) {
    if ($Fields[$i][2] == $id) {
      for ($j = 0 ; $j < count($Fields[$i]); $j++) {
        $DataDB[$k][$j] = $Fields[$i][$j];
      }
      $k++;
    }
  }
  return $DataDB;
}

function SelectDBForumByCat($Fields,$ct) {
  $DataDB = array();
  $k = 0;
  for ($i = 0; $i < count($Fields); $i++) {
    if ($Fields[$i][12] == $ct) {
      for ($j = 0 ; $j < count($Fields[$i]); $j++) {
        $DataDB[$k][$j] = $Fields[$i][$j];
      }
      $k++;
    }
  }
  return $DataDB;
}

if (!empty($pg)) {
  $dbwork = SelectDBForumByID(ReadDBFields(DBFORUMARCH),$pg);
  if (count($dbwork) == 0) {
    $dbwork = array();
  }
}
elseif (!empty($cat)) {
  $dbwork = SelectDBForumByCat(ReadDBFields(DBFORUMARCH),$cat);
}
else {
  $dbwork = ReadDBFields(DBFORUMARCH);
}
if ($lng == $lang[0]) {
  $i = 0;
}
else {
  $i = 1;
}
if ($serviz[18] != "on") {
  if (!empty($cat)) {
    $dbworkcat = ReadDBFields(DBFORUMCAT);
    for ($k = 0; $k < count($dbworkcat); $k++) {
	  $prcat = explode(',', $dbworkcat[$k][0]);
      if ($prcat[0] == $cat) {
        $catxt = $dbworkcat[$k][1+$i];
      }
    }
    $topmess = $web226." - ".$catxt;
  }
  else {
    $topmess =$web226;
  }
}
else {
  if (!empty($cat)) {
    $dbworkcat = ReadDBFields(DBFORUMCAT);
    for ($k = 0; $k < count($dbworkcat); $k++) {
	  $prcat = explode(',', $dbworkcat[$k][0]);
      if ($prcat[0] == $cat) {
        $catxt = $dbworkcat[$k][1+$i];
      }
    }
    $topmess = "<a href=\"fortopicarch.php?lng=".$lng."\">".$web226."</a> - ".$catxt;
  }
  else {
    $topmess = "<a href=\"fortopicarch.php?lng=".$lng."\">".$web226."</a>";
  }
}
if ($page[9] != "") {
  $topmess = "<img src=\"".CHEMIN."inc/img/icons/".$page[9]."/forum.gif\" align=\"right\" width=\"32\" height=\"32\" alt=\"forum.gif\">".$topmess;
}
include("inc/hpage.inc");
htable($topmess, "100%");
/// debut modif accès privé
include_once (CHEMIN.'inc/func_groups.php');
$acces = "no";  
if (IsValidForumCat($cat)) {
	$acces = "ok"; 
}
if (IsPrivateForumCat($cat)) {
    $acces = "no";
    if ($userprefs[1] != "") {    
        if (CheckGroup($cat, $userprefs[1])) $acces = "ok";
    }
}

if ($acces != "ok") {
    echo "<p style='text-align:center;font-weight:bold;padding-bottom:48px;'><br />".$web443."</strong><br /></p>";
} else {
/// fin modif accès privé
 if ($serviz[18] != "on") {
     $archdate = ReadCounter(DBFORUMARCHDATE);
 if ($archdate > 0) {
?>
<p align="center"><?php echo $web225." ".FormatDate($archdate); ?>.<br />
<?php echo $web224; ?> <a href="forum.php?lng=<?php echo $lng; ?>"><?php echo $web223; ?></a>.<br /><hr /></p>
<?php
 }
 }
 if (empty($id)) {
 $id = 1;
 }
 if (!empty($dbwork)) {
 for ($i = $serviz[17]*($id-1); $i < Min($serviz[17]*$id, count($dbwork)); $i++) {
 if ($serviz[34] == "on") {
     $threadcounter = ReadDocCounter(ARCHDBBASE.$dbwork[$i][2]);
 }
?>
<table cellspacing="1" border="0">
<tr><td class="forum2" nowrap><a href="threadarch.php?lng=<?php echo $lng; ?>&amp;pg=<?php echo $dbwork[$i][2]; ?>&amp;fid=<?php echo $id; if (!empty($cat)) { echo "&amp;cat=".$cat; } ?>"><?php echo $web63.$dbwork[$i][1]; ?></a></td>
<td class="quest" width="100%"><a href="threadarch.php?lng=<?php echo $lng; ?>&amp;pg=<?php echo $dbwork[$i][2]; ?>&amp;fid=<?php echo $id; if (!empty($cat)) { echo "&amp;cat=".$cat; } ?>"><b><?php echo $dbwork[$i][5]; ?></b></a>
<br />&nbsp;&nbsp;&nbsp;&nbsp;-&nbsp;
<?php
 echo $web6." ";
      if ($dbwork[$i][10] != "on") {
      $em = BreakEMail($dbwork[$i][4]);
?>
<b><a href="JavaScript:WriteMailTo('<?php echo addslashes(urlencode($dbwork[$i][3])); ?>','<?php echo $em[0]; ?>','<?php echo $em[1]; ?>','<?php echo $em[2]; ?>')"><?php echo addslashes($dbwork[$i][3]); ?></a></b>
<?php
}
else {
     echo "<b>".$dbwork[$i][3]."</b>";
     }
     echo " ".$web7." ".FormatDate($dbwork[$i][6]);
     if ($dbwork[$i][7] != 0) {
     if ($dbwork[$i][11] != "on") {
        $em = BreakEMail($dbwork[$i][9]);
        $formail = "<b><a href=\"JavaScript:WriteMailTo('".addslashes(urlencode($dbwork[$i][8]))."','".$em[0]."','".$em[1]."','".$em[2]."')\">".addslashes($dbwork[$i][8])."</a></b>";
     }
     else {
         $formail = "<b>".$dbwork[$i][8]."</b>";
     }
     if ($dbwork[$i][7] == 1) {
?>
<br />&nbsp;&nbsp;&nbsp;&nbsp;-&nbsp;<?php echo $web93." ".$formail." ".$web94." ".FormatDate($dbwork[$i][0]).")"; ?>
<?php
}
else {
?>
<br />&nbsp;&nbsp;&nbsp;&nbsp;-&nbsp;<?php echo $dbwork[$i][7]." ".$web66." ".$formail." ".$web94." ".FormatDate($dbwork[$i][0]).")"; ?>
<?php
}
}
else {
?>
<br />&nbsp;&nbsp;&nbsp;&nbsp;-&nbsp;<?php echo $web67; ?>
<?php
    }
    if ($serviz[34] == "on") {
      if ($threadcounter <= 1) {
        $txtcount = $web188;
      }
      else {
        $txtcount = $web189;
      }
?>
<br />&nbsp;&nbsp;&nbsp;&nbsp;-&nbsp;<?php echo $web217; ?> <?php echo $threadcounter." ".$txtcount; ?>
<?php
 }
?>
<br /></td></tr></table>
<?php
    if ($i < Min($serviz[17]*$id, count($dbwork))-1) {
      echo "<hr />";
    }
  }
}
if (count($dbwork)>$serviz[17])
{
  echo '<hr />'.GetNavBar("forumarch.php?lng=".$lng."&amp;cat=".$cat."&amp;id=", count($dbwork), $id, $serviz[17]);
}
if ($serviz[18] == "on") {
 if (count($dbwork)<=$serviz[17]) {
 echo "<hr />";
 }
?>
<p align="center">[ <a href="fortopicarch.php?lng=<?php echo $lng; ?>"><?php echo $web134; ?></a> ]</p>
<?php
	}
}
btable();
include("inc/bpage.inc");
?>
