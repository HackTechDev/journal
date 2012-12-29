<?php
/*
    Welcome Box - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.3 (06 January 2003)   : replaced title bar with site's title ($site[0])
                                   instead of slogan ($site[1])
      v2.2 (22 April 2003)     : small bug fix "inc/img/trans.gif" instead of "/inc/img/trans.gif" (thanks Michel)
                                 cleanup in the images organization
      v2.3 (27 July 2003)      : added user prefs management by cookie
      v2.4 (24 September 2003) : added section icon in central boxes
                                 added homepage's choice of central boxes
                                 created $dbhomepage variable
      v4.0 (06 December 2004)  : removed the trans pixel (by Isa)
      v4.0.4 (February 2005)   : added RemoveBR et RemoveHR (by Jean-Mi)
	  v4.6.20 (24 May 2012)    : corrected btable (by Saxbar)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "boxhome.inc")) {
  header("location:../index.php");
  die();
}

  if ($userprefs[1] != "") {
    $welcomemess = $userprefs[1].$web167;
  }
  else {
    $welcomemess = $web1;
  }
  if ($page[9] != "") {
    $welcomemess = "<img src=\"".CHEMIN."inc/img/icons/".$page[9]."/home.gif\" align=\"right\" width=\"32\" height=\"32\" alt=\"home.gif\"/>".$welcomemess;
  }
  htable($welcomemess." ".$site[0], "100%");
  include(DBHOMEPAGE);
  // $home1 = RemoveBR(RemoveHR($home1));
  // $home2 = RemoveBR(RemoveHR($home2));
?>
<br />
<?php
  echo "<div class='bord' style='padding:5px;margin:2px;text-align:left;'>";
  if ($lng == $lang[0]) {
    echo $home1;
  }
  else {
    echo $home2;
  }
  echo "</div>";
  if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $drtuser[13]=="on")) {
?>
<p align="right"><a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=homepg"><img src="<?php echo CHEMIN; ?>inc/img/general/edit.gif" border="0" alt="<?php echo $web308; ?>" title="<?php echo $web308; ?>"/></a></p>
<?php
  }
  btable($welcomemess);
?>
