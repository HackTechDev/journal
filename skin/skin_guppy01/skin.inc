<?php
/*
    Customization - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2011 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
	  v4.6.13 (june 2010)          :  Original release for freeGuppY
	  V4.6.16 (02 September 2011)  :  Optimizing display block quote (by Papinou)
      v4.6.19 (30 March 2012)      :  Title display boxes if there (by Saxbar)
	  v4.6.20 (24 May 2012)        :  Corrected $boxwidth (by Saxbar and Papinou)
	                                  Corrected display block quote (by Saxbar)
      v4.6.22 (29 December 2012)   :  optimized $meskin (thanks JeanMi)									  

	   GuppY Design: Skins for Guppy - original release juin 2010
	   Design - Graphisme:  Sabine Guppy Team / CSS - Réglages:  Papinou GuppY Team
       Adaptation full screen Novembre 2012 (by Papinou)  	   
*/

  $skn_name = "guppy01";     // Skin name
  $meskin = CHEMIN.'skin/'.basename(dirname(__FILE__)).'/';  //skin path
  $screen_choice = "";      // if "" user can choose 1024px or full screen size) otherwise enter 800, 1024 or 1280 to fix screen width
  $screen_icon = "";          // alternate screen icon if not empty
  $mod_css = "off";             // off: no change permitted in css and skin look  
  $skn_logo = $meskin."img/logo.png";            // Specific logo
  $skn_hr = "off";           // Flag tag <hr> (if "off" disabled)
  $skn_top = "";          // Top arrow (if "" standard arrow)
  $headinc = "";          // Insert point in header section
  //   ----------   OPTIONNAL BOXES ---------   //
  $imgtabup = "";
  $tabup = "";                                  // Top of Header Box
  $tabcita = "";                                // Bottom of Header Box
  $tabmenu = "";
  $boxban = "";                                   // Box for banner
  $tabfoot = "";                                  // Footer Box
  $tabdown = "";
  $imgtabdown = "";
  $boxwidth = '172px';                              // width for lateral and blog boxes

   // widepage for admin, blog and forum
  if (strstr($endurl, "admin/")) $widepage = "";
  $forum[3] = "";
  $serviz[58] = "";  

function htable($tblti) {
  global $texte;
  if (trim($tblti) != '') 
	echo '
  <div class="titre" style="width:auto;">'.$tblti.'</div>
  <div class="tbl">';
  else
	echo '
  <div style="margin-bottom:4px;">';
}

function btable() {
  echo "</div>\n";
}

function htable1($tblti) {
  global $texte, $boxwidth;
  if (trim($tblti) != '') 
	echo '
  <div class="titrebox" style="width:'.$boxwidth.';">'.$tblti.'</div>
  <div class="tblbox"  style="width:'.$boxwidth.';">';
  else
	echo '
  <div style="width:'.$boxwidth.';margin-bottom:4px;">';
}

function btable1() {
  echo "</div>\n";
}
?>