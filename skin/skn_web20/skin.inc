<?php
/*
    Customization - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by GuppY Team
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Skin History :
      v1.0 (01 May 2007)           :  Initial release (by deherve "GuppY Design")
      v4.6.10 (07 September 2009)  :  Corrected boxwidth (by Icare)
                                      Corrected #mainContent and div#page, thanks Papinou
	  V4.6.16 (02 September 2011)  :  Optimizing display block quote (by Papinou)
      v4.6.19 (30 March 2012)      :  Title display boxes if there (by Saxbar)
	  v4.6.20 (24 May 2012)        :  Corrected $boxwidth (by Saxbar and Papinou)
	                                  Corrected display block quote (by Saxbar)
	                                  Corrected display headTop (by Papinou)
      v4.6.22 (29 December 2012)   :  Optimized $meskin (thanks	JeanMi)								  
*/

  $skn_name = "web 20";                           // Skin name (further release)
  $meskin = CHEMIN.'skin/'.basename(dirname(__FILE__)).'/';  //skin path
  $mod_css = "off";                                  // Look config (if "off" no change permitted in css and skin)
  $screen_choice = "";                            // Page width (if "fix" width fixed by skin otherwise "" user can choose 1024px or full size)
  $screen_icon = "img/screen.png";                // alternate screen icon if not empty
  $skn_logo = $meskin."logo.png";                 // Specific logo
  $skn_hr = "";                                   // Flag tag <hr> (if "off" disabled)
  $skn_top = "";                                  // Top arrow (if "" standard arrow)
  $headinc = "";                                  // Insert point in header section

// [ CUSTOMIZATION BUTTONS ]
  $boutonleft = "";                               // Left Image for submit buttons
  $boutonright = "";                              // Right Image for submit buttons
  $boutoncenter = "";                             // Center Image for submit buttons
  $boxwidth = '172px';
  
  // WIDEPAGE FOR ADMIN, BLOG AND FORUM
  if (strstr($endurl, "admin/")) $widepage = "";
  $forum[3] = "on";
  $serviz[58] = "2cols";  

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
