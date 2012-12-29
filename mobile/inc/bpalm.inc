<?php
/*
    Site Bottom of Page for PDA - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v2.3 (27 July 2003)        : initial release (thanks Palmipod)
      v2.4 (24 September 2003)   : created $dbfoot variable
      v3.0 (25 February 2004)    : added copyright notice on all pages
      v4.0 (06 December 2004)    : added alt tag to img and removed border tag for unlinked img (by Isa)
      v4.5 (01 June 2005)        : corrected copyright information (by Icare)
	  v4.6.18 (09 February 2012) : added $mpcopyright (by Saxbar)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "bpalm.inc")) {
  header("location:../index.php");
  die();
}

?>
<hr />
<center><a href="#top"><img src="<?php echo CHEMIN; ?>inc/img/general/up.gif" border="0" width="12" height="11" alt="up" /> <b><?php echo $web136; ?></b> <img src="<?php echo CHEMIN; ?>inc/img/general/up.gif" border="0" width="12" height="11" alt="up" /></a></center>
<hr />
<?php
include(DBFOOT);
if ($lng == $lang[0]) {
  $txtspe = PathToImage($foot1);
}
else {
  $txtspe = PathToImage($foot2);
}
echo $txtspe."<hr />";


	//////////////////////////////////////////////////////////////////////////////////
	//                                                                              //
	//               GuppY is protected by the CeCILL FREE LICENSE.                 //
	// IT IS STRICTLY FORBIDDEN TO REMOVE OR MODIFY THE FOLLOWING COPYRIGHT NOTICE. //
	//                                                                              //
	//////////////////////////////////////////////////////////////////////////////////


if ($lng == "fr") {
  $txtspe  = " <a href='http://www.freeguppy.org/' title='Le site GuppY' target='_blank'> Site propulsé par GuppY</a> - © ".$mpcopyright." - ";
  $txtspe .= " <a href='http://www.cecill.info/index.fr.html' title='En savoir plus ...' target='_blank'> Licence Libre CeCILL </a> ";
}
else {
  $txtspe  = " <a href='http://www.freeguppy.org/' title='GuppY site' target='_blank'> Site powered by GuppY</a> - © ".$mpcopyright." - ";
  $txtspe .= " <a href='http://www.cecill.info/index.en.html' title='More info ...' target='_blank'> CeCILL Free License </a> ";
}

$imgspe = "";
if ($site[24] != "N") {
  $imgspe = "<a href=\"http://www.freeguppy.org/\" target=\"_blank\"><img src=\"".CHEMIN.INCREP."img/general/gy".$site[24];
  $imgspe .= "logo.gif\" alt=\"GuppY - http://www.freeguppy.org/\" border=\"0\" align=\"center\"\" /></a>";
  if ($site[25] == "T") {
    $txtspe = $imgspe."<br>".$txtspe;
  }
  elseif ($site[25] == "L") {
    $txtspe = $imgspe."&nbsp;&nbsp;".$txtspe;
  }
  elseif ($site[25] == "R") {
    $txtspe = $txtspe."&nbsp;&nbsp;".$imgspe;
  }
  else {
    $txtspe = $imgspe."&nbsp;&nbsp;".$txtspe."&nbsp;&nbsp;".$imgspe;
  }
}
echo "<center>".$txtspe."</center>";
if ($page[8] == "on") {
  $timer = StopTimer();
  echo "<center><b>".$web116." ".$timer." ";
  if ($timer <= 1) {
    echo $web117;
  }
  else {
    echo $web118;
  }
  echo "</b></center>";
}
?>
</body>
</html>
