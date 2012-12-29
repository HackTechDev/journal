<?php
/*
    News - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.7 (28 January 2003)   : fixed bug that first language title would popup all the time
      v4.0 (06 December 2004)  : added page title (by Jean-Mi)
      v4.6.6 (6 January 2008)  : added header("HTTP/1.0 404 Not found") in the event of pages not found (by JeanMi, thanks eDada)
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");

if ($serviz[8] != "on") {
  exit($web143);
}
if ($lng == $lang[0]) {
  $topmess = strip_tags($nom[7]);
}
else {
  $topmess = strip_tags($nom[17]);
}
if (!empty($pg) && count(SelectDBFields(TYP_NEWS,"a",$pg)) == 0) {
  header('HTTP/1.0 404 Not Found');
}
//$topmess = $txt;
include("inc/hpage.inc");
//$txt = $topmess;
$indexnews = 0;

include("inc/news.inc");

include("inc/bpage.inc");
?>
