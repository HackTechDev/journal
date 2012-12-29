<?php
/*
    Customization - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v3.0 (25 February 2004)     : initial release
      v4.0 (06 December 2004)     : update to follow the CSS changes (class tbl, tblbox, titre, titrebox, tbl2, tblover, tbl and padding) (by Isa)
                                    simplification by minimum table use (by Icare)
      v4.6.0 (04 June 2007)       : replace table by div (by Icare)
	  V4.6.16 (02 September 2011) : optimized display block quote (by Papinou)
      v4.6.19 (30 March 2012)     : Title display boxes if there (by Saxbar)
	  v4.6.20 (24 May 2012)       : corrected $boxwidth (by Saxbar and Papinou)
	                                corrected display block quote (by Saxbar)
      v4.6.22 (29 December 2012)  : optimized $meskin (thanks JeanMi)									
*/

$skn_name = "no_skin";                           // Skin name
$meskin = CHEMIN.'skin/'.basename(dirname(__FILE__)).'/';  //skin path
$screen_choice = "";    // if "" user can choose 1024px or full screen size) otherwise enter 800, 1024 or 1280 to fix screen width
$screen_icon = "";          // alternate screen icon if not empty
$skn_logo = "";         // Specific logo
$skn_hr = "";           // Flag tag <hr> (if "off" disabled)
$skn_top = "";          // Top arrow (if "" standard arrow)
$headinc = "";          // Insert point in header section
  //   ----------   CUSTOMIZATION BUTTONS ---------   //
  $boutonleft = "";			// Left Image for submit buttons
  $boutonright = "";			// Right Image for submit buttons
  $boutoncenter = "";			// Center Image for submit buttons
  //   ----------   OPTIONNAL BOXES ---------   //
  $imgtabup = "";
  $tabup = "";                                  // Top of Header Box
  $tabcita = "";                                // Bottom of Header Box
//  if ($posbox[30] == "" && $posbox[31] == "" && $posbox[32] == "") {$tabup = ""; $tabcita = "";} // no header frame if no boxes
  $tabmenu = "";
  $boxban = "";                                   // Box for banner
  $tabfoot = "";                                  // Footer Box
  $tabdown = "";
  $imgtabdown = "";
  $boxwidth = "166px";                              // width for lateral and blog boxes

function htable($tblti, $largeur) {
  global $texte;
  if (trim($tblti) != '') 
	echo '
  <div class="titre" style="width:auto;">'.$tblti.'</div>
  <div class="tbl" onmouseover="this.className = \'tblover\'" onmouseout="this.className = \'tbl\'">';
  else
	echo '
  <div style="margin-bottom:4px;">';
}

function btable() {
  echo "</div><br />\n";
}

function htable1($tblti) {
  global $boxwidth;
  if (trim($tblti) != '')
    echo '
<div class="titrebox" style="width:'.$boxwidth.';">'.$tblti.'</div>
<div class="tblbox" onmouseover="this.className=\'tblboxover\'" onmouseout="this.className=\'tblbox\'" style="width:'.$boxwidth.';">';
  else
    echo '
<div style="margin-bottom:4px;">';
}

function btable1() {
  echo "</div>\n";
}
?>
