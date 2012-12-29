<?php
/*
    Last News - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v2.4 (24 September 2003)    : initial release
      v4.0 (06 December 2004)     : removed the trans pixel (by Isa)
      v4.6.5 (05 December 2007)   : no display if no news,
                                    display real number of news is less than site[4] (by Icare)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "boxnews.inc")) {
  header("location:../index.php");
  die();
}
$nbnews = count(SelectDBFields(TYP_NEWS,"a",$pg));
if ($serviz[8] == "on" && $site[4] > 0 && $nbnews > 0) {
  if ($nbnews == 1 ) {
    $topmess = $web145;
  }
  elseif ($site[4] == 1) {
    $topmess = $web145;
  }
  elseif ($nbnews < $site[4]) {
    $topmess = $web2." ".$nbnews." ".$web3;
  }
  else {
    $topmess = $web2." ".$site[4]." ".$web3;
  }
  $indexnews = 1;

  include("inc/news.inc");
}
?>
