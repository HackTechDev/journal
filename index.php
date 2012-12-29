<?php
/*
    Site Index - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.8 (05 February 2003)  : show news on homepage only if the number of news
                                   to show is higher than 0
      v2.3 (27 July 2003)      : added case of only ONE news displayed on homepage (thanks Laurent Roger)
      v2.4 (24 September 2003) : added forum summary in home page (last messages)
                                 added Guestbook's favourite message on home page
                                 added homepage's choice of central boxes
      v4.0 (06 December 2004)  : added page title (by Jean-Mi)
      v4.6.0 (04 June 2007)    : added editobox[4] (by Icare)
      v4.6.3 (30 August 2007)  : added editobox[5] (by Icare)
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");
if ($serviz[1] == "" && $serviz[53] !=""){ //blog en accueil
header("location:".CHEMIN."blogs.php?lng=".$lng);}
else {
$topmess = "";
include("inc/hpage.inc");

$onemenu = 0;
if (!empty($editobox[0])) {
  include(CHEMIN.$editobox[0].INCEXT);
}
if (!empty($editobox[1])) {
  include(CHEMIN.$editobox[1].INCEXT);
}
if (!empty($editobox[2])) {
  include(CHEMIN.$editobox[2].INCEXT);
}
if (!empty($editobox[3])) {
  include(CHEMIN.$editobox[3].INCEXT);
}
if (!empty($editobox[4])) {
  include(CHEMIN.$editobox[4].INCEXT);
}
if (!empty($editobox[5])) {
  include(CHEMIN.$editobox[5].INCEXT);
}
include("inc/bpage.inc");
}
?>
