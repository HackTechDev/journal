<?php
/*
    Forum Thread Archive - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v3.0 (25 February 2004)     : initial release
      v4.0 (06 December 2004)     : added page title (by jmmis)
                                    added alt tags to img and removed border tag for non-linked img,
				                    added the forum management style, replaced & by &amp; to W3C compliant (by Isa)
	  v4.5 (15 February 2005)     : corrected bug for text of thread (by Jean-Mi)
	  v4.6.6 (14 April 2008)      : added urlencode to $author (by JeanMi)
      v4.6.10 (7 September 2009)  : corrected #274
      v4.6.11 (11 December 2009)  : changed width by style=width for cells
      v4.6.18 (09 February 2012)  : correction for archiving private forum (by Saxbar)
	  v4.6.22 (29 December 2012)  : added pseudo-private group for members (by Saxbar)
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");
include("inc/funcarch.php");
include_once (CHEMIN.'inc/func_groups.php'); // ajouté pour groupes privés
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Modif Editeur PGEditor
define('PATH_PGEDITOR', 'inc/pgeditor/');		//Chemin relatif de l'éditeur (ne pas modifier)
define('PATH_CONFIG_PGEDITOR','inc/config_pgeditor_guppy/'); //Chemin relatif du fichier de configuration de l'éditeur
include CHEMIN.PATH_PGEDITOR.'pgeditor.php';    //Fichier contenant toutes les fonctions nécessaires pour intégration de l'éditeur
include CHEMIN.PATH_PGEDITOR.'syntaxcolor/syntaxcolor.php'; //Coloration syntaxique
//Fin modif Editeur PGEditor
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

if ($serviz[13] != "on") {
  exit($web143);
}

$pg = strip_tags($pg);
$thrd = strip_tags($thrd);
$cat = strip_tags($cat);
$id = strip_tags($id);
$fid = strip_tags($fid);

function SelectDBThreadByThread($Fields,$id) {
  $DataDB = array();
  $k = 0;
  for ($i = 0; $i < count($Fields); $i++) {
    if ($Fields[$i][1] == $id && $Fields[$i][2] != "0") {
      for ($j = 0 ; $j < count($Fields[$i]); $j++) {
        $DataDB[$k][$j] = $Fields[$i][$j];
      }
      $k++;
    }
  }
  return $DataDB;
}

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

$thread = 0;
if (!empty($pg)) {
  $dbwork = SelectDBForumByID(ReadDBFields(DBFORUMARCH),$pg);
  if (count($dbwork) != 0) {
    $thread = $dbwork[0][1];
  }
}
elseif (!empty($thrd)) {
  $dbwork = ReadDBFields(DBTHREADARCH);
  for ($i = 0; $i < count($dbwork); $i++) {
    if ($dbwork[$i][1] == $thrd && $dbwork[$i][2] == "0") {
      $thread = $thrd;
      $pg = $dbwork[$i][3];
    }
  }
}

if ($serviz[34] == "on") {
  $threadcounter = UpdateDocCounterArch($pg);
}

$dbthrd = SelectDBThreadByThread(ReadDBFields(DBTHREADARCH),$thread);
@sort($dbthrd);

/// Include déplacé pour corrigé le contenu erroné du sujet
include("inc/hpage.inc");
if ($lng == $lang[0]) {
  $i = 0;
}
else {
  $i = 1;
}
ReadDoc(ARCHDBBASE.$pg);
if ((CheckGroup($cat, $userprefs[1]) != 1) && (!is_numeric($cat) && $CatForumOn))  { 
	header("location:index.php");
	die();
}
if (preg_match('/^pr/i', $fieldb2) && (CheckGroup($fieldb2, $userprefs[1]) != 1)) {
	header("location:index.php");
	die();
}

if ($serviz[18] != "on") {
  $topmess = "<a href=\"forumarch.php?lng=".$lng."&amp;id=".$fid."\">".$web226."</a> - ".$web63.$fielda1;
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
    $topmess = "<a href=\"fortopicarch.php?lng=".$lng."\">".$web226."</a> - <a href=\"forumarch.php?lng=".$lng."&amp;id=".$fid."&amp;cat=".$cat."\">".$catxt."</a> - ".$web63.$fielda1;
  }
  else {
    $topmess = "<a href=\"fortopicarch.php?lng=".$lng."\">".$web226."</a> - ".$web63.$fielda1;
  }
}
if ($page[9] != "") {
  $topmess = "<img src=\"".CHEMIN."inc/img/icons/".$page[9]."/forum.gif\" align=\"right\" width=\"32\" height=\"32\" alt=\"forum.gif\">".$topmess;
}
htable($topmess, "100%");
?>
<table width="100%" border="0" summary=""><tr>
<td class="forum" style="width:15%"><?php echo $web63.$fielda1; ?></td>
<td class="forum2" height="42" style="width:85%"><b><?php echo $fieldb1; ?></b>
<br />&nbsp;&nbsp;&nbsp;
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
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Modif Editeur PGEditor
$fieldc1 = colorCode($fieldc1); //Coloration syntaxique
//Fin modif Editeur PGEditor
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
?>
</td></tr>
<tr><td class="quest" colspan="2"><?php echo $fieldc1; ?></td></tr>
</table>
<hr />
<?php
 if (empty($id)) {
 $id = 1;
 }
 if (!empty($dbthrd)) {
 for ($i = $serviz[20]*($id-1); $i < Min($serviz[20]*$id, count($dbthrd)); $i++) {
 ReadDoc(ARCHDBBASE.$dbthrd[$i][3]);
?>
<table width="100%" border="0" summary="">
<tr><td class="quest" style="width:15%" align="center"><?php echo $web68.$fielda2; ?></td>
<td class="quest" style="width:85%">
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
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Modif Editeur PGEditor
$fieldc1 = colorCode($fieldc1); //Coloration syntaxique
//Fin modif Editeur PGEditor
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
?>
</td></tr>
<tr><td class="rep" colspan="2"><?php echo $fieldc1; ?></td>
</tr>
</table>
<?php
 }
 }
 if (count($dbthrd)>$serviz[20])
 {
echo '<hr />'.GetNavBar("threadarch.php?lng=".$lng."&amp;cat=".$cat."&amp;pg=".$pg."&amp;id=", count($dbthrd), $id, $serviz[20]);
}
?>
<p align="center">[ <a href="forumarch.php?lng=<?php echo $lng; ?>&amp;id=<?php echo $fid; if (!empty($cat)) { echo "&amp;cat=".$cat; } ?>"><?php echo $web70; ?></a> ]</p>
<?php
btable();
include("inc/bpage.inc");
?>
