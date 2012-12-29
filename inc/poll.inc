<?php
/*
    Poll calculation - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v2.4 (24 September 2003) : created $dbpoll and $dbippoll variables
      v4.0 (06 December 2004)  : no change
*/

if (stristr($_SERVER["SCRIPT_NAME"], "poll.inc")) {
  header("location:../index.php");
  die();
}

$total = 0;
$maxval = 1;
$commun = ReadDBFields(DBPOLL);
$lignes = count($commun);
for ($i = 1; $i < $lignes; $i++) {
  $total = $total + $commun[$i][3];
  $maxval = Max($maxval,$commun[$i][3]);
}
for ($i = 1; $i < $lignes; $i++) {
  if ($commun[$i][3] != 0) {
    $commun[$i][4] = round($commun[$i][3]/$total*10000)/100;
  }
  else {
    $commun[$i][4] = 0;
  }
}
?>
