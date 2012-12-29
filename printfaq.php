<?php
/*
    Printfaq - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.5 (19 February 2005)     : initial release (by Nico)
      v4.6.5 (05 December 2007)  : added stop illegal value for bad faq item (by Icare)
      v4.6.17(21 October 2011)  : added private management (by Laroche)
*/
define("CHEMIN", "");
include("inc/includes.inc");
include("inc/func_groups.php");

$pg = strip_tags($pg);
if ($pg != "" && is_numeric($pg) && @file_exists(DBBASE.$pg.INCEXT)) {
  // Test si groupe autorisé
  $usercookie = "GuppYUser";
  $userprefs = array();
  if (!empty($_COOKIE[$usercookie])) {
    $userprefs = explode("||",$_COOKIE[$usercookie]);
    $userprefs[0] = strip_tags($userprefs[0]);
    $userprefs[1] = preg_replace("![^a-zA-Z0-9_]!i","",substr(strip_tags($userprefs[1]),0,20));    
  }
  include(DBBASE.$pg.INCEXT);
    
  if ($type == TYP_FAQ && (CheckGroup($fieldmod, $userprefs[1]) || $fieldmod == '')) {    
    if ($lng == $lang[0]) {
      $txt1 = $fieldb1;
      $txt2 = $fieldc1;
      $txt3 = $fielda1;
    }
    else {
      $txt1 = $fieldb2;
      $txt2 = $fieldc2;
      $txt3 = $fielda2;
    }
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<title><?php echo $site[0].' - '.$txtprt.' - '.$web23; ?></title>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset; ?>">
<meta name="Robots" content="NONE">
<style type="text/css">
P { font-family: Arial, Helvetica, sans-serif; }
a { color: <?php echo $lien[0]; ?>; text-decoration: underline; }
a:hover { color: <?php echo $lien[1]; ?>; text-decoration: underline; }
</style>
<script language="javascript">
 window.print();
</script>
</head>
<body bgcolor="#FFFFFF" text="#000000">
<h1 align="center"><?php echo $site[0]; ?></h1>
<p align="center"><?php echo $site[3]; ?></p>
<?php
if ($txt3 != "") {
?>
<h3 align="center"><?php echo $web21; ?> <?php echo $txt3; ?><br /></h3>
<?php
}
?>
<h3 align="center"><?php echo $txt1; ?><br /></h3>
<p><?php echo $txt2; ?></p>
</body>
</html>
<?php
  } else {
   die('STOP ! Illegal value');
  }
} else {
  die('STOP ! Illegal value');
}