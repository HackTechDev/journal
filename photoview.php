<?php
/*
    Photoview - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v4.5 (19 April 2005)      : initial release (by Icare)
      v4.6.6 (14 April 2008)    : corrected bad double " in body tag, thanks agab
      v4.6.9 (25 December 2008) : added corrections for validation of W3C
      v4.6.15 (30 June 2011)    : added private management
	  v4.6.20 (24 May 2012)     : corrected GET['pg'] (by Saxbar)
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");
if ($serviz[9] != "on") { 
  exit($web143); 
}
$pg = strip_tags($pg);
$id = strip_tags($id);
if (!empty($pg)) {
   ReadDoc(DBBASE.$pg);
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
      $txt4 = $fieldd1;
	  $extn = substr($fieldd1, -3);
	  if (isImage($extn)) {
		  $txt5 = getimagesize(CHEMIN."photo/".$fieldd1);
		  /// début modif accès réservé
		  $txt6 = $fieldmod;
		  $acces = "ok";
		  if ($txt6 != "") {
			$acces = "no";
			if ($userprefs[1] != "") {
			  include_once (CHEMIN.'inc/func_groups.php');
			  if (CheckGroup($txt6, $userprefs[1])) $acces ="ok";
			}
		  }
	  } else {
		$acces = "no";
	  }
      if ($acces == "no") {
        die('STOP !  illegal action !!!!');
      }
      /// fin modif accès réservé
   ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>Photo</title>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset; ?>" />
<meta name="Robots" content="None" />
<?php
if(file_exists($meskin."style.css")) {
  echo "<link type=\"text/css\" rel=\"stylesheet\" href=\"".$meskin."style.css\" />";
}
else {
  echo "<style type=\"text/css\">";
  if(file_exists($meskin."style.inc")) {
    include($meskin."style.inc");
  }
  else {
    include(CHEMIN."inc/style.inc");
  }
  echo "</style>";
}
?>
</head>
<body style="background-image: none; margin:0px; cursor:pointer;" class="tblbox" onclick="window.close();"  onblur="window.close();">
    <div class="bord2">
    <div class="rep" style="margin:2px; text-align:center">
    <img src="<?php echo CHEMIN ?>photo/<?php echo $txt4 ?>" <?php echo $txt5[3]; ?> alt="<?php echo $web57 ?>" title="<?php echo $web57 ?>" /><br />
    <p style="font-size: 11px;"><b><?php echo $txt2; ?></b></p><br />
    </div>
    </div>
</body>
</html>
<?php
}
?>
