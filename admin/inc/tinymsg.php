<?php
/*
    Send general tinymsg - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2008 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
	  v4.0 (06 December 2004)     : initial release by Nicolas Alves
    v4.6.0 (25 September 2006)  : corrected &amp in $nextstep (by Jchouix)
    v4.6.5 (05 December 2007)   : added origin control (by Icare)
    v4.6.6 (23 April 2008)      : deletion of putBR on $dbmsg items (by Icare)
*/

header("Pragma: no-cache");
define("CHEMIN", "../../");
include(CHEMIN."inc/includes.inc");
include(CHEMIN.'admin/action.php');
if ($wri == "admin") {
    if (FileDBExist(CHEMIN."admin/mdp.php")) {
        include(CHEMIN."admin/mdp.php");
	} else {
	    $mdp="bad";
	}
} else {
    if (FileDBExist(CHEMIN.'admin/'.REDACREP.$wri.INCEXT)) {
        include(CHEMIN.'admin/'.REDACREP.$wri.INCEXT);
        $mdp=md5($drtuser[38]);
    } else {
        $mdp="bad";
    }
}
$portalname="GuppyAdmin";
if (empty($_COOKIE[$portalname]) || $_COOKIE[$portalname] != crc32($mdp)) {
    die(' Procédure non autorisée -- illegal process');
}
include(CHEMIN.INCREP."lang/".$lng."-admin".INCEXT);
$dbusers = array();
$j = 0;
$file_users=opendir(USEREP);
while ($nomfichier=readdir($file_users)) {
  if( substr($nomfichier,-3)=="dtb" && $nomfichier!=$userprefs[1].DBEXT) {
  $dbusers[$j][0] = str_replace(substr($nomfichier,-4),"",$nomfichier);
  $j++;
  }
}
closedir($file_users);
@sort($dbusers);
if (!isset($lsn)) {
  //$lsn = 0;
   die('Illegal action');
}
?>
<html>
<head>
<title><?php echo $admin691 ?></title>
<script language="javascript" type="text/javascript">
 function PopupWindow(page,titre,largeur,hauteur,resizeyn,scrollb) {
  var top=(screen.height-hauteur)/2;
  var left=(screen.width-largeur)/2;
  window.open(page,titre,"top="+top+", left="+left+", width="+largeur+", height="+hauteur+", directories=no, menubar=no, status=no, resizable="+resizeyn+", scrollbars="+scrollb+",location=no");
 }
</script>
</head>
<body bgcolor="<?php echo $page[0]; ?>" leftmargin="5" topmargin="5" style="overflow: hidden;">
<fieldset>
<p>&nbsp;</p>
<p align="center"><?php echo $admin692 ?></p>
<p align="center"><?php echo Min($lsn+1,count($dbusers))." / ".count($dbusers)." ".$admin516; ?></p>
<?php
if (FileDBExist(USEREP.$userprefs[1].DBEXT)) {
  $dbmsg = ReadDBFields(USEREP.$userprefs[1].DBEXT);
}
if($redige==1) {
  include(CHEMIN.DATAREP."sendtinymsg.inc");
    if($tinymsg2 != "") {
    $tinymsgsend = $tinymsg1."<br /><hr /><br />".$tinymsg2;
  }
  else {
    $tinymsgsend = $tinymsg1;
  }
  $dbmsg = Array();
  $dbmsg[0] = $admin690;
  $dbmsg[1] = GetCurrentDateTime();
  $dbmsg[2] = RemoveConnector(stripslashes($tinymsgsend));
  $dbmsg[3] = "lu";
  $dbmsg[4] = "send";
  $dbmsg[5] = RemoveConnector(stripslashes($ancienmsg));
  $dbmsg[6] = $anciendate;
  $dbmsg[7] = $userprefs[8];
  AppendDBFields(USEREP.$userprefs[1].DBEXT,$dbmsg);
}
if ($lsn < count($dbusers)) {
  include(CHEMIN.DATAREP."sendtinymsg.inc");
  if($tinymsg2 != "") {
    $tinymsgsend = $tinymsg1."<br /><hr /><br />".$tinymsg2;
  }
  else {
    $tinymsgsend = $tinymsg1;
  }
  $dbmsg = Array();
  $dbmsg[0] = $userprefs[1];
  $dbmsg[1] = GetCurrentDateTime();
  $dbmsg[2] = RemoveConnector(stripslashes($tinymsgsend));
  $dbmsg[3] = "new";
  $dbmsg[4] = "";
  $dbmsg[5] = RemoveConnector(stripslashes($ancienmsg));
  $dbmsg[6] = $anciendate;
  $dbmsg[7] = $userprefs[8];
  AppendDBFields(USEREP.$dbusers[$lsn][0].DBEXT,$dbmsg);
  $lsn++;
  $nextstep = "PopupWindow(\"tinymsg.php?lng=".$lng."&lsn=".$lsn."\",\"tinymsg\",400,250,\"no\",\"no\")";
} else {
  ?>
  <hr />
  <p align="center"><b><?php echo $admin693 ?></b></p>
  <p>&nbsp;</p>
  <?php
  $nextstep = "";
}
?>
</fieldset></body></html>
<?php
if ($nextstep != "") {
  ?>
  <script language="javascript" type="text/javascript">
  <?php echo $nextstep; ?>
  </script>
  <?php
}
?>
