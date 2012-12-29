<?php
/*
    Citation Box - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.9 (11 February 2003)  : moved make_seed() function (renamed as MakeSeed) to functions.php (also used by the new boxban.inc banner management)
      v2.0 (27 February 2003)  : no change
      v2.1 (10 March 2003)     : no change
      v2.2 (22 April 2003)     : cleanup in the images organization
      v2.3 (27 July 2003)      : minor font and text formating changes in search, quotations, general pages (thanks Isabelle)
                                 changed str_replace to PathToImage() function
      v2.4 (24 September 2003) : added ReadDoc() function, created $typ_[name] variables
      v3.0 (25 February 2004)  : added skins (by Nicolas Alves)
      v4.0 (06 December 2004)  : optimisation, replacing table by hr (by Icare)
                                 clean up and changes in the display (by Isa)
                                 added class=band and bgcolor to the second table (by Isa)
      v4.6.15 (30June 2011)    : validation error correction (thanks jchouix)
	  v4.6.20 (24 May 2012)    : corrected display block quote (by Saxbar)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "boxcita.inc")) {
  header("location:../index.php");
  die();
}

$dbw = SelectDBFields(TYP_THINK,"a","");
if (count($dbw)>0) {
  srand(MakeSeed());
  $i = rand(0,count($dbw)-1);
  ReadDoc(DBBASE.$dbw[$i][1]);
if ($lng == $lang[0]) {
  $txt1 = PathToImage($fieldc1);
  $txt2 = $fieldb1;
}
else {
  $txt1 = PathToImage($fieldc2);
  $txt2 = $fieldb2;
}
$txt1 = str_ireplace('<p>', ' ', $txt1);
$txt1 = str_ireplace('</p>', ' ', $txt1);
echo '<div class="quote">';
if ($skn_hr == "") {
  echo " <hr />\n";
}
echo '<span class="labelcita">'.$web5.'&nbsp;&nbsp;</span><span class="cita">'.$txt1.'&nbsp;&nbsp;</span><span class="author">'.$txt2.'</span>';
if ($skn_hr =="") {
  echo " <hr />\n";
}
if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $drtuser[28]=="on")) {
  echo "<p align='right' style='padding-right: 4px;'><a href='".CHEMIN."admin/admin.php?lng=".$lng."&amp;pg=think'><img src='".CHEMIN."inc/img/general/edit.gif' border='0' alt='".$web308."' title='".$web308."' /></a></p>\n";
}
echo "</div>\n";
}
?>
