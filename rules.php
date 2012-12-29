<?php
/*
    CHARTER reading Module - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.6.0 (04 June 2007)       : initial release by Icare

*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<title><?php echo $web409; ?></title>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset; ?>">
<meta name="Robots" content="None">
<?php
if(file_exists($meskin."style.css")) {
  echo "<link type=\"text/css\" rel=\"stylesheet\" href=\"".$meskin."style.css\">";
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
<body style="margin:0px; padding:0px; background-image:none; border:0px;" class="tblbox">

<?php
  if (is_file(DBRULES))
  include(DBRULES);

?>
<br />
<?php
echo "<div class='bord' style='padding:5px;margin:2px;text-align:left;'>";
if ($lng == $lang[0]) {
  echo $rule1;
}
else {
  echo $rule2;
}
echo "</div>";
echo '<p align="right" style="margin:2px;"><a class="box" href="javascript:window.close();">'.$web57.'</a></p>';
echo '</body>';
?>
