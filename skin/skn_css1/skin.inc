<?php
/*
    Customization - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v3.0 (25 February 2004)  : initial release
      v3.0p2 (09 April 2004)   : bug fix in the GuppY skins which fooled Netscape (by Icare)
      v4.0 (06 December 2004)  : 800 px new skin optimisation (by Ricsen)
      v4.6.0 (04 June 2007)    : optimization for 4.6 (by Icare)
      v4.6.10 (XX/YY 2009)    : corrected #274
      v4.6.11 (11 December 2009)  : added boxwidth to suit with blog (by Icare)
	  V4.6.16 (02 September 2011) : optimizing display block quote (by Papinou)
      v4.6.19 (30 March 2012)     : title display boxes if there (by Saxbar)
      v4.6.20 (24 May 2012)       : corrected $boxwidth (by Saxbar and Papinou)
	                                corrected display block quote (by Saxbar)
      v4.6.22 (29 December 2012)  : optimized $meskin (thanks JeanMi)									
*/

$skn_name = "skn_css1";                           // Skin name
$meskin = CHEMIN.'skin/'.basename(dirname(__FILE__)).'/';  //skin path
$screen_choice = "";    // "fix" (page width fixed by skin) otherwise "" (user can choose 800px, 1024px or full screen size)
$mod_css = "";          // off: no change permitted in css and skin look
$skn_logo = "";         // Specific logo
$skn_hr = "";           // Flag tag <hr> (if "off" disabled)
$skn_top = "";          // Top arrow (if "" standard arrow)
$headinc = "";          // Insert point in header section
  //   ----------   CUSTOMIZATION BUTTONS ---------   //
  $boutonleft = "";			// Left Image for submit buttons
  $boutonright = "";			// Right Image for submit buttons
  $boutoncenter = "";			// Center Image for submit buttons
  //   ----------   OPTIONNAL BOXES ---------   //

  $screen = "auto"; //page size
  $tabup = "";       // Header table with images for left, center and right corners
  $imgtabup = "";                                  // Top of Header Box
  $tabcita = "";                                // Bottom of Header Box
  $tabmenu = "";
  $boxban = "";                                   // Box for banner
  $tabfoot = "";                                  // Footer Box
  $imgtabdown = "";
  $tabdown ="";      // Footer table with images for left, center and right corners
  $boxwidth = "180px";

function htable($tblti, $largeur) {   // Top and Left design for Center Boxes
  echo '
<table cellspacing="0" cellpadding="0" border="0" align="center" width="'.$largeur.'" summary="">
<tr>
  <td class="box_tl"></td>
  <td class="box_t"></td>
  <td class="box_tr"></td></tr>
<tr>
  <td class="box_l" rowspan="2"></td>';
  if (trim($tblti) != '') 
	echo '
  <td class="titre"><b>'.$tblti.'</b></td>';
  else
	echo '
  <td></td>';
  echo '
  <td class="box_r" rowspan="2"></td></tr>
<tr>
  <td class="tbl" onmouseover="this.className = \'tblover\';" onmouseout="this.className = \'tbl\';">';
}

function btable() {                   // Right and Bottom design for Center Boxes
  global $meskin;
?>
</td></tr>
<tr>
  <td class="box_bl"></td>
  <td class="box_b"></td>
  <td class="box_br"></td>
</tr>
</table>
<div class="spacer"></div>
<?php
}

function htable1($tblti) {            // Top and Left design for Lateral Boxes
  echo '
<table cellspacing="0" cellpadding="0" border="0" align="center" width="210px">
<tr>
  <td class="box_tl"></td>
  <td class="box_t"></td>
  <td class="box_tr"></td></tr>
<tr>
  <td class="box_l" rowspan="2"></td>';
  if (trim($tblti) != '') 
	echo '
  <td class="titrebox"><b>'.$tblti.'</b></td>';
  else
	echo '
  <td></td>';
  echo '
  <td class="box_r" rowspan="2"></td></tr>
<tr>
  <td class="tblbox" onmouseover="this.className = \'tblboxover\';" onmouseout="this.className = \'tblbox\';">';
}

function btable1() {                  // Right and Bottom design for Lateral Boxes
  global $meskin;
?>
</td></tr>
<tr>
  <td class="box_bl"></td>
  <td class="box_b"></td>
  <td class="box_br"></td>
</tr>
</table>
<div class="spacer"></div>
<?php
}

function htable2($largeur) {            // Top and Left design for other Boxes (header, footer...)
 global $meskin;
?>
<table cellspacing="0" cellpadding="0" border="0" align="center" width="<?php echo $largeur; ?>">
<tr>
  <td class="box_tl"></td>
  <td class="box_t"></td>
  <td class="box_tr"></td></tr>
<tr>
  <td class="box_l"></td>
  <td class="titrebox">
<?php
}

function btable2() {                  // Right and Bottom design for other Boxes
  global $meskin;
?>
</td>
<td class="box_r"></td></tr></tr>
<?php
  if (trim($tblti) != '') 
	echo '
<tr>
  <td class="box_bl"></td>
  <td class="box_b"></td>
  <td class="box_br"></td>
</tr>';
?>
</table>
<?php
}
?>
