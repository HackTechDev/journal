<?php
/*
    Forum Topics Archive - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v3.0 (25 February 2004)     : initial release
      v4.0 (06 December 2004)     : added page title (by Jean-Mi)
                                    added alt tags to img and removed border tag for non-linked img,
                                    added the forum style management (by Isa)
                                    replaced the & by &amp; fot standard compliance (by Isa)
      v4.6.6 (14 April 2008)      : added urlencode in WriteMailTo() (by JeanMi)
      v4.6.10 (7 September 2009)  : corrected #274
      v4.6.18 (09 February 2012)  : corrected for archiving private forum (by Saxbar)
	  v4.6.22 (29 December 2012)  : added pseudo-private group for members (by Saxbar)
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");
include("inc/funcarch.php");

if ($serviz[13] != "on" || $serviz[18] != "on") {
  exit($web143);
}

$dbwork = ReadDBFields(DBFORUMCAT);
$dbworkcat = ReadDBFields(DBFORUMARCH);
for ($i = 0; $i < count($dbwork); $i++) {
  $dbwork[$i][3] = 0;
  $dbwork[$i][4] = 0;
  $prcat = explode(',', $dbwork[$i][0]);
  for ($j = 0; $j < count($dbworkcat); $j++) {
    if ($dbworkcat[$j][12] == $prcat[0]) {
      $dbwork[$i][3]++;
      $dbwork[$i][4] = $dbwork[$i][4] + $dbworkcat[$j][7] + 1;
      if (empty($dbwork[$i][5])) {
        if (!empty($dbworkcat[$j][8])) {
          $dbwork[$i][5] = $dbworkcat[$j][8];
          if ($dbworkcat[$j][11] != "on") {
            $dbwork[$i][6] = $dbworkcat[$j][9];
          }
          else {
            $dbwork[$i][6] = "";
          }
          $dbwork[$i][7] = $dbworkcat[$j][0];
        }
        else {
          $dbwork[$i][5] = $dbworkcat[$j][3];
          if ($dbworkcat[$j][10] != "on") {
            $dbwork[$i][6] = $dbworkcat[$j][4];
          }
          else {
            $dbwork[$i][6] = "";
          }
          $dbwork[$i][7] = $dbworkcat[$j][0];
        }
      }
    }
  }
}
include("inc/hpage.inc");
if ($lng == $lang[0]) {
  $k = 0;
}
else {
  $k = 1;
}
$topmess = $web226;
if ($page[9] != "") {
  $topmess = "<img src=\"".CHEMIN."inc/img/icons/".$page[9]."/forum.gif\" align=\"right\" width=\"32\" height=\"32\" alt=\"forum.gif\" />".$topmess;
}
htable($topmess, "100%");
$archdate = ReadCounter(DBFORUMARCHDATE);
if ($archdate > 0) {
?>
<p align="center"><?php echo $web225." ".FormatDate($archdate); ?>.<br />
<?php echo $web224; ?> <a href="fortopic.php?lng=<?php echo $lng; ?>"><?php echo $web223; ?></a>.<br /><br /></p>
<?php
 }
 if (!empty($dbwork)) {
?>
<table class="bord" cellspacing="1" align="center" width="98%" summary="">
<tr align="center">
<td class="forum"><?php echo $web130; ?></td>
<td class="forum"><?php echo $web131; ?></td>
<td class="forum"><?php echo $web132; ?></td>
<td class="forum"><?php echo $web133; ?></td></tr>
<?php
for ($i = 0; $i < count($dbwork); $i++) {
	$prcat = explode(',', $dbwork[$i][0]);
	if (empty($prcat[1])) $prcat[1] = '';
    /// début modif forum privé
    $acces ="ok";
    if (!empty($prcat[1])) {
      $acces = "no";
      if ($userprefs[1] != "") {
        include_once (CHEMIN.'inc/func_groups.php');
        if (CheckGroup($prcat[1], $userprefs[1])) $acces ="ok";
      }
    }
    if ($acces == "ok") {
?>
<tr align="center">
<td class="quest"><a href="forumarch.php?lng=<?php echo $lng; ?>&amp;cat=<?php echo $prcat[0]; ?>"><b><?php echo $dbwork[$i][1+$k]; ?></b></a></td>
<td class="quest"><?php echo $dbwork[$i][3]; ?></td>
<td class="quest"><?php echo $dbwork[$i][4]; ?></td>
<td class="quest">
<?php
    if ($dbwork[$i][6] != "") {
      echo $web6." ";
      $em = BreakEMail($dbwork[$i][6]);
?>
<b><a href="JavaScript:WriteMailTo('<?php echo addslashes(urlencode($dbwork[$i][5])); ?>','<?php echo $em[0]; ?>','<?php echo $em[1]; ?>','<?php echo $em[2]; ?>')"><?php echo addslashes($dbwork[$i][5]); ?></a></b>
<?php
    }
    elseif ($dbwork[$i][5] != "") {
      echo $web6." <b>".$dbwork[$i][5]."</b>";
    }
    if ($dbwork[$i][7] != "") {
      echo "<br />".$web7." ".FormatDate($dbwork[$i][7]);
    }
?>
</td></tr>
<?php
	}
}
?>
</table>
<?php
}
btable();
include("inc/bpage.inc");
?>
