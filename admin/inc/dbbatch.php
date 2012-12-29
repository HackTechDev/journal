<?php
/*
    BATCH DataBase Integrity Check - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v3.0 (25 February 2004)  : initial release
      v4.0 (06 December 2004)  : no change
	  v4.5 (22 April 2005)     : changed constants management (by Jean-Mi)
	                             changed Close by $web57 (by Icare)
*/

header("Pragma: no-cache");
define("CHEMIN", "../../");
include(CHEMIN."inc/includes.inc");
include("funcdbchk.inc");

if (empty($checkid)) {
  if (empty($range1)) {
    $range1 = 1;
  }
  else {
    $range1 = Min($range1,ReadCounter(NEXTID));
  }
  if (empty($range2)) {
    $range2 = ReadCounter(NEXTID)+10;
  }
  if ($range2 < $range1) {
    $range2 = $range1;
  }
  $checkid = $range1;
  if (empty($delta)) {
    $delta = 100;
  }
  else {
    $delta = min(1000, max($delta, 1));
  }
}
?>
<html>
<head>
<title><?php echo strip_tags($admin278); ?></title>
<?php
	if (file_exists($meskin."style.css")){
		echo '<link type="text/css" rel="stylesheet" href="'.$meskin.'style.css" />';
	} else {
		echo '<style type="text/css">';
		if(file_exists($meskin."style.inc")) {
			include $meskin.'style.inc';
		} else {
			include CHEMIN.'inc/style.inc';
		}
		echo '</style>';
	}
?>
<script language="javascript">
  function PopupWindow(page,titre,largeur,hauteur,resizeyn,scrollb) {
  var top=(screen.height-hauteur)/2;
  var left=(screen.width-largeur)/2;
  window.open(page,titre,"top="+top+", left="+left+", width="+largeur+", height="+hauteur+", directories=no, menubar=no, status=no, resizable="+resizeyn+", scrollbars="+scrollb+",location=no"); }
</script>
</head>
<body class="tbl" leftmargin="5" topmargin="5" style="overflow: hidden;">
<fieldset>
<p>&nbsp;</p>
<p align="center"><?php echo $admin295; ?></p>
<p align="center"><?php echo "[ ".$range1." / <b>".Min($checkid,$range2)."</b> / ".$range2." ]"; ?></p>
<?php
if ($checkid <= $range2) {
  $checkerr = $checkerr + CheckDBmP($checkid, $checkid + $delta, $checkquiet);
  $checkid += $delta;
  $nextstep = "setTimeout('PopupWindow(\"dbbatch.php?lng=".$lng."&range1=".$range1."&range2=".$range2."&checkquiet=".$checkquiet."&checkid=".$checkid."&checkerr=".$checkerr."&delta=".$delta."\",\"dbbatch\",400,250,\"no\",\"no\")', 1)";
}
else {
  ?>
  <hr />
  <p align="center"><b><?php echo $admin298; ?></b></p>
  <?php
  if ($checkquiet != 1) {
    if ($checkerr == 0) {
       $dbresult = $admin297;
    }
    else {
       $dbresult = $checkerr." ".$admin576;
    }
    ?>
    <p align="center"><?php echo $dbresult; ?></p>
    <p align="right"><a href="#" onclick="window.close();"><b><?php echo $web57 ?>&nbsp;</b></a></p>
    <?php
  }
  $nextstep = "";
}
?>
</fieldset></body></html>
<?php
if ($nextstep != "") {
  ?>
  <script language="javascript">
   <?php echo $nextstep; ?>
  </script>
<?php
}
?>
