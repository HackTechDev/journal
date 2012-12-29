<?php
/*
    Stats - GuppY PHP Script -  version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.1 (02 January 2003)   : added $statactor variable
                                 (in order to avoid overwrites of Stats database when more users
                                  ask for Stats simultaneously. Now only Admin can compact the stats database)
      v1.2 (05 January 2003)   : complete rewrite of Stats module
      v2.4 (24 September 2003) : added section icon in central boxes
                                 secured transfered parameters
      v4.0 (06 December 2004)  : added page title (by Jean-Mi)
                                 added alt tags to img and removed border tag for non-linked img (by Isa)
                                 added members management (by Nicolas Alves)
      v4.6.9 (25 December 2008): addition/correction of the statistics for the Blog and Admin pages #216
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");

if ($serviz[15] != "on") {
  exit($web143);
}
$per = strip_tags($per);
$anal = strip_tags($anal);

if (empty($per)) {
  $per = 1;
}
$show_stat_admin = false;
include("inc/statcalc.inc");

if ($lng == $lang[0]) {
  $i = 0;
}
else {
  $i = 1;
}
$topmess = strip_tags($nom[$i+26]);
if ($page[9] != "") {
  $topmess = "<img src=\"".CHEMIN."inc/img/icons/".$page[9]."/stats.gif\" align=\"right\" width=\"32\" height=\"32\" alt=\"stats.gif\"/>".$topmess;
}
include("inc/hpage.inc");
htable($topmess, "100%");
echo "<br /><br />";
if ($members[0]=="on" && $userprefs[1]=="" && $members[6]=="on"){
    echo "<p align=\"center\">".$web342."</p><br />";
    echo "<p align=\"center\">[ <a href=\"".CHEMIN."user.php?lng=".$lng."\">".$web343."</a> ]</p><br />";
}
else {
include("inc/statshow.inc");
}
btable();
include("inc/bpage.inc");
?>
