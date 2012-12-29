<?php
/*
    Customization - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v3.0 (25 February 2004)     : initial release
      v3.0p2 (09 April 2004)      : bug fix in the GuppY skins which fooled Netscape (by Icare)
      v4.0 (06 December 2004)     : new complete management without tables, according to it's own css (by Isa)
      v4.6.0 (15 Février 2007)    : deleted div spacer2 (by Icare)
      v4.6.10 (02 september 2009) : corrected boxwidth (by Icare)
	  V4.6.16 (02 september 2011) : optimizing display block quote (by Papinou)	
      v4.6.19 (30 March 2012)     : title display boxes if there (by Saxbar)
      v4.6.20 (24 May 2012)       : corrected $boxwidth (by Saxbar and Papinou)
	                                corrected display block quote (by Saxbar)
      v4.6.22 (29 December 2012)  : optimized $meskin (thanks JeanMi)									
*/

$skn_name = "skn_css";                           // Skin name
$meskin = CHEMIN.'skin/'.basename(dirname(__FILE__)).'/';  //skin path
$screen_choice = "";    // "fix" (page width fixed by skin) otherwise "" (user can choose 800px, 1024px or full screen size)
$topmargin = "0px";             // Top margin (px)
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
//  if ($posbox[30] == "" && $posbox[31] == "" &&$posbox[32]) {$tabup = ""; $tabcita = "";} // no header frame if no boxes
  $tabmenu = "";
  $boxban = "";                                   // Box for banner
  $tabfoot = "";                                  // Footer Box
  $tabdown = "";
  $imgtabdown = "";
  $boxwidth = "170px";

function htable($tblti, $largeur) {     // Top and Left design for Center Box
  global $meskin;
  if (trim($tblti) != '') 
	echo '
  <div align="left" class="spacer">
  <span class="titre">'.$tblti.'</span>
  <div class="tbl" style="padding-top: 20px;padding-bottom : 16px;">';
  else
	echo '
  <div>
  <div style="margin-bottom:4px;padding-top: 20px;padding-bottom : 16px;">';
}

function btable() {             // Right and Bottom design for Center Box
  global $meskin;
?>
</div></div>
<?php
}

function htable1($tblti) {          // Top and Left design for Side Box
  global $meskin, $boxwidth;
  if (trim($tblti) != '') 
	echo '
  <div align="left" class="spacer">
  <span class="titrebox">'.$tblti.'</span>
  <div class="tblbox"  style="width:'.$boxwidth.';padding-top:14px;">';
  else
	echo '
  <div>
  <div style="width:'.$boxwidth.';padding-top:14px;margin-bottom:4px;">';
}

function btable1() {                // Right and Bottom design for Side Box
  global $meskin;
?>
</div></div>
<?php
}
?>
