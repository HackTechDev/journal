<?php
/*
    BATCH Forum Archiving - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
	v3.0  (25 February 2004)  : initial release
	v4.0  (06 December 2004)  : no change
    v4.6.0  (04 June 2007)    : secured language file inclusion, thanks rgod
    v4.6.19 (30 March 2012)   : corrected close by $admin458 (thanks Icare)
*/

header("Pragma: no-cache");
define("CHEMIN", "../../");
include(CHEMIN."inc/reglobals.inc");
include(CHEMIN."inc/functions.php");
include(CHEMIN."inc/funcarch.php");
if (is_file(CHEMIN.INCREP."lang/".$lng."-admin".INCEXT)) include(CHEMIN.INCREP."lang/".$lng."-admin".INCEXT);
else die('BAD Language name !');
include(CONFIG);
/// nombre d'itération en phase d'archivage des fichiers ($followup = vide)
$delta1 = 100;
/// nombre d'itération en contrôle d'intégrité
$delta2 = 500;

function ArchiveOneFile($fic1,$fic2) {
  $archive1ok = false;
  if (@copy($fic1,$fic2)) {
    @chmod($fic1,0777);
    $archive1ok = @unlink($fic1);
  }
  return $archive1ok;
}

function ArchiveFile($id) {
  $archivedok = false;
  if (FileDBExist(DBBASE.$id.INCEXT)) {
    $archivedok = ArchiveOneFile(DBBASE.$id.INCEXT,ARCHDBBASE.$id.INCEXT);
    if ($archivedok) {
      $db = array();
      $db[0] = TYP_FORUM;
      $db[1] = $id;
      $db[2] = "a";
      AppendDBFields(DOCIDARCH,$db);
    }
    if (FileDBExist(DBBASE.$id.DBEXT)) {
      ArchiveOneFile(DBBASE.$id.DBEXT,ARCHDBBASE.$id.DBEXT);
    }
    if (FileDBExist(DBIPBASE.$id.DBEXT)) {
      ArchiveOneFile(DBIPBASE.$id.DBEXT,ARCHDBIPBASE.$id.DBEXT);
    }
  }
  return $archivedok;
}

if (empty($followup)) {
  $dbwork = ReadDBFields(DBTHREAD);
  @rsort($dbwork);
}
if (empty($checkid)) {
  $archdate = $archdate."0000";
  for ($i = 0; $i < count($dbwork); $i++) {
    $checkid = Max($checkid,$dbwork[$i][1]);
  }
}
/// Juste pour le cas où le script serait lancé à la main avec followup=1 ou  2
if (strlen($archdate) == 8)   $archdate .= "0000";

?>
<html>
<head>
<title><?php echo $admin577; ?></title>
<script language="javascript">
function PopupWindow(page,titre,largeur,hauteur,resizeyn,scrollb) {
var top=(screen.height-hauteur)/2;
var left=(screen.width-largeur)/2;
window.open(page,titre,"top="+top+", left="+left+", width="+largeur+", height="+hauteur+", directories=no, menubar=no, status=no, resizable="+resizeyn+", scrollbars="+scrollb+",location=no"); }
</script>
</head>
<body bgcolor="<?php echo $page[0]; ?>" leftmargin="5" topmargin="5" style="overflow: hidden;">
<fieldset><font color="<?php echo $texte[0]; ?>">
<p>&nbsp;</p>
<?php
if (empty($followup)) {
  ?>
  <p align="center"><?php echo $admin584.$checkid; ?></p>
  <?php
  $nbcheck = $delta1; /// Nombre d'itération sans archivage
  while ($checkid > 0 && $nbcheck > 0) {
    $checkit = 0;
    $i = 0;
    while (($i < count($dbwork)) && ($checkit == 0)) {
      if ($dbwork[$i][1] == $checkid) {
        $checkit = 1;
        if ($archdate >= $dbwork[$i][0]) {
          $nbcheck = 0; /// arrêt car archivage réalisé
          echo $admin585.$dbwork[$i][1]."<br />";
          for ($j = $i; $j < count($dbwork); $j++) {
            if ($dbwork[$j][1] == $checkid) {
              if ($dbwork[$j][2] == 0) {
                echo "&nbsp;&nbsp;- ".$admin592."<br />";
              }
              else {
                echo "&nbsp;&nbsp;- ".$admin586.$dbwork[$j][2]."<br />";
              }
              ArchiveFile($dbwork[$j][3]);
            }
          }
        }
      }
      $i++;
    }
    $checkid--;
    $nbcheck--;
  }
  if ($checkid > 0) {
    $nextstep = "PopupWindow(\"archbatch.php?lng=".$lng."&archdate=".$archdate."&checkid=".$checkid."\",\"archbatch\",400,300,\"no\",\"no\")";
  }
  else {
    $nextstep = "PopupWindow(\"archbatch.php?lng=".$lng."&archdate=".$archdate."&checkid=-1&followup=1\",\"archbatch\",400,300,\"no\",\"no\")";
  }
}
elseif ($followup == 1) {
  ?>
  <p align="center"><?php echo $admin587."<br /><br />"; ?></p>
  <?php
  $dbworknew = ReadDBFields(DOCIDARCH);
  @sort($dbworknew);
  WriteDBFields(DOCIDARCH,$dbworknew);
  $nextstep = "PopupWindow(\"archbatch.php?lng=".$lng."&archdate=".$archdate."&checkid=-1&followup=2\",\"archbatch\",400,300,\"no\",\"no\")";
}
elseif ($followup == 2) {
  ?>
  <p align="center"><?php echo $admin588."<br /><br />"; ?></p>
  <?php
  /// Attention : c'est une étape qui peut dépasser les 30 secondes d'exécution d'où le set_time_limit(0);
  /// en espérant que le safe_mode ne soit pas activé
  set_time_limit(0);
  UpdateDBforumArch();
  $nextstep = "PopupWindow(\"archbatch.php?lng=".$lng."&archdate=".$archdate."&checkid=-1&followup=3\",\"archbatch\",400,300,\"no\",\"no\")";
}
else {
  ?>
  <p align="center"><?php echo $admin589."<br /><br />"; ?></p>
  <?php
  WriteCounter(DBFORUMARCHDATE,$archdate);
  $nextstep = "PopupWindow(\"dbbatch.php?lng=".$lng."&checkquiet=1&delta=".$delta2."\",\"dbbatch\",400,300,\"no\",\"no\")";
}
?>
<p align="right"><a href="#" onclick="window.close();"><b><?php echo $admin458; ?>&nbsp;</b></a></p>
</fieldset></body></html>
<?php
if ($nextstep != "") {
  //  sleep(2);
  ?>
  <script language="javascript">
  <?php echo $nextstep; ?>
  </script>
  <?php
}
?>
