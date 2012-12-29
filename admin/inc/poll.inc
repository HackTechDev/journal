<?php
/*
    Admin Poll - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v2.3 (27 July 2003)      : added forms style management (by Nicolas Alves)
      v2.4 (24 September 2003) : created $dbpoll and $dbippoll variables
      v3.0 (25 February 2004)  : added skins management (by Nicolas Alves)
      v4.0 (06 December 2004)  : added alt tags to img and removed border tag for non-linked img (by Isa)
	                             added page title (by Jean-Mi)
				                 added multi-admin management (by Nicolas Alves)
      v4.6.10 (7 September 2009)    : corrected #274
      v4.6.12 (01 May 2010) : corrected #321
      v4.6.13 (22 May 2010) : corrected #324
*/
if (stristr($_SERVER["SCRIPT_NAME"], "poll.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[25]=="") {
    $nomzone=$admin15;
    include("access.inc");
    exit();
  }
}
$maxrep = 11; // Number of answers + 1
$couleurs = array($admin152,$admin153,$admin154,$admin155,$admin156,$admin157,$admin158,$admin159,$admin160,$admin161);

function ColorReturn($inp) {
 global $admin152,$admin153,$admin154,$admin155,$admin156,$admin157,$admin158,$admin159,$admin160,$admin161;
 if ($inp == $admin152) {
 $out = "bleu";
}
elseif ($inp == $admin153) {
 $out = "jaune";
}
elseif ($inp == $admin154) {
 $out = "marron";
}
elseif ($inp == $admin155) {
 $out = "or";
}
elseif ($inp == $admin156) {
 $out = "orange";
}
elseif ($inp == $admin157) {
 $out = "outremer";
}
elseif ($inp == $admin158) {
 $out = "rose";
}
elseif ($inp == $admin159) {
 $out = "rouge";
}
elseif ($inp == $admin160) {
 $out = "vert";
}
else {
 $out = "violet";
 }
 return $out;
 }
 if (!empty($qp1) || !empty($qp2)) {
 $mettre[0][0] = stripslashes($qp1);
 $mettre[0][1] = stripslashes($qp2);
 $j = 0;
 for ($i = 1; $i < count($r)+1; $i++) {
 if (!empty($r[$i])) {
      $j++;
      $mettre[$j][0] = stripSlashes(RemoveConnector($r[$i]));
      $mettre[$j][1] = stripSlashes(RemoveConnector($s[$i]));
      $mettre[$j][2] = ColorReturn($c[$i]);
      $mettre[$j][3] = $v[$i];
    }
  }
 WriteDBFields(DBPOLL,$mettre);
 WriteFullDB(DBIPPOLL,"");
 }

function tagSelect($id) {
 global $couleurs, $commun;
 global $admin152,$admin153,$admin154,$admin155,$admin156,$admin157,$admin158,$admin159,$admin160,$admin161;
 $com =  "<select name=\"c[$id]\">";
 for ($x = 0; $x < count($couleurs); $x++) {
 if ($commun[$id][2] == "bleu") {
     $out = $admin152;
}
elseif ($commun[$id][2] == "jaune") {
     $out = $admin153;
}
elseif ($commun[$id][2] == "marron") {
     $out = $admin154;
}
elseif ($commun[$id][2] == "or") {
     $out = $admin155;
}
elseif ($commun[$id][2] == "orange") {
     $out = $admin156;
}
elseif ($commun[$id][2] == "outremer") {
     $out = $admin157;
}
elseif ($commun[$id][2] == "rose") {
     $out = $admin158;
}
elseif ($commun[$id][2] == "rouge") {
     $out = $admin159;
}
elseif ($commun[$id][2] == "vert") {
     $out = $admin160;
}
else {
     $out = $admin161;
     }
 if ($out == $couleurs[$x]) {
     $sel = ' selected="selected"';
}
else {
     $sel = "";
     }
     $com = $com."<option value=\"$couleurs[$x]\"$sel>$couleurs[$x]</option>\n"; }
     $com = $com."</select>";
 return $com;
 }
include(CHEMIN."inc/poll.inc");
$topmess = $admin145;
include(CHEMIN."inc/hpage.inc");
htable($admin145, "100%");
?>
<div align="center"><?php echo $admin146; ?><hr />
[ <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b> ]
<hr /></div><br />
<form action="admin.php?lng=<?php echo $lng; ?>" method="post">
<input type="hidden" name="pg" value="poll" />
<input type="hidden" name="selskin" value="<?php echo $selskin; ?>" />
<table cellpadding="5" cellspacing="0" align="center" valign="top" border="0" summary="">
<tr><td colspan="5" align="center"><?php echo $admin147; ?> <img src="<?php echo $flag1; ?>" width="24" height="16" alt="<?php echo $flag1; ?>" /> <input class="texte" type="text" name="qp1" value="<?php echo $commun[0][0]; ?>" size="40" /></td></tr>
<?php
if ($lang[1] != "") {
?>
<tr><td colspan="5" align="center"><?php echo $admin147; ?> <img src="<?php echo $flag2; ?>" width="24" height="16" alt="<?php echo $flag2; ?>" /> <input class="texte" type="text" name="qp2" value="<?php echo $commun[0][1]; ?>" size="40" /></td></tr>
<?php
}
?>
<tr><td colspan="5" align="center"><hr /></td></tr>
<tr><td align="center"><?php echo $admin151; ?></td><td align="center"><?php echo $admin148; ?></td><td align="center"><?php echo $admin150; ?></td><td colspan="2" align="center"><?php echo $admin149; ?></td></tr>
<?php
for ($i = 1; $i < $maxrep; $i++) {
?>
<tr><td align="center"><?php echo $i; ?></td>
<td align="center"><input class="texte" type="text" name="v[<?php echo $i; ?>]" size="1" value="<?php echo $commun[$i][3]; ?>" /></td>
<td align="center"><?php echo tagSelect($i); ?></td>
<td align="center"><img src="<?php echo $flag1; ?>" style="vertical-align:middle" width="24" height="16" alt="<?php echo $flag1; ?>" /> <input class="texte" type="text" name="r[<?php echo $i; ?>]" size="15" value="<?php echo $commun[$i][0]; ?>" /></td>
<?php
 if ($lang[1] != "") {
?>
<td align="center"><img src="<?php echo $flag2; ?>" style="vertical-align:middle" width="24" height="16" alt="<?php echo $flag2; ?>" /> <input class="texte" type="text" name="s[<?php echo $i; ?>]" size="15" value="<?php echo $commun[$i][1]; ?>" /></td>
</tr>
<?php
    } else {
   echo '</tr>';
   }
}
?>
</table>
<p align="center">
<?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin38; ?>"><?php echo $admin38; ?></button><?php echo $boutonright; ?>
</p>
</form>
<div align="center"><hr />
[ <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b> ]
</div>
<?php
btable();
include(CHEMIN."inc/bpage.inc");

?>
