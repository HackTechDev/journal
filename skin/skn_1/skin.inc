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
      v4.0 (06 December 2004)     : added background image for box title, border size,
	                                added $tabcita, $tabmenu and $tabfoot to extend presentation (by Icare)
	                                update to follow the CSS changes (class tbl1, tbl1box, titre, titrebox, tbl2, tbl2over, tbl3, tbl3over et padding) (by Isa)
      v4.5 (25 April 2005)        : added htable2() and btable2() to optimize header and footer optionnal boxes (by Icare)
      v4.6.10 (7 september 2009)  : corrected #274
      v4.6.11 (11 December 2009)  : added boxwidth used by blog boxes to suit with optimized width htable1() by Icare
	  V4.6.16 (02 September 2011) : optimizing display block quote (by Papinou)
      v4.6.19 (30 March 2012)     : Title display boxes if there (by Saxbar)
      v4.6.20 (24 May 2012)       : corrected $boxwidth (by Saxbar and Papinou)
                                    added $size (by Saxbar)
	                                corrected display block quote (by Saxbar)
      v4.6.22 (29 December 2012)  : optimized $meskin (thanks JeanMi)									
*/

$skn_name = "skn_1";                           // Skin name
$meskin = CHEMIN.'skin/'.basename(dirname(__FILE__)).'/';  //skin path
$screen_choice = "";    // "fix" (page width fixed by skin) otherwise "" (user can choose 800px, 1024px or full screen size)
$size = "10";
$skn_logo = "";         // Specific logo
$skn_hr = "";           // Flag tag <hr> (if "off" disabled)
$skn_top = "";          // Top arrow (if "" standard arrow)
$headinc = "";          // Insert point in header section
  //   ----------   CUSTOMIZATION BUTTONS ---------   //
  $boutonleft = "";			// Left Image for submit buttons
  $boutonright = "";			// Right Image for submit buttons
  $boutoncenter = "../../img/fond7.gif";			// Center Image for submit buttons
  //   ----------   OPTIONNAL BOXES ---------   //
  $imgtabup = "";
  $tabup = "on";                                  // Top of Header Box
  $tabcita = "on";                                // Bottom of Header Box
  $tabmenu = "";
  $boxban = "";                                   // Box for banner
  $tabfoot = "";                                  // Footer Box
  $tabdown = "";
  $imgtabdown = "";
  $boxwidth = "166px";                              // width for lateral and blog boxes

function htable($tblti, $largeur) {	// Top and Left design for Center Boxes
  global $meskin, $size;
  echo '
  <table class="htable" cellspacing="0" cellpadding="0" align="center" width="'.$largeur.'" border="0" summary="">
  <tr>
   <td width="'.$size.'" height="'.$size.'"><img src="'.$meskin.'tab_hg.gif" alt="" /></td>
   <td height="'.$size.'" style="background-image:url('.$meskin.'tab_hc.gif)"></td>
   <td width="'.$size.'" height="'.$size.'"><img src="'.$meskin.'tab_hd.gif" alt="" /></td></tr>
  <tr>
   <td rowspan="2"  width="'.$size.'" style="background-image:url('.$meskin.'tab_gc.gif)"></td>';
  if (trim($tblti) != '') 
	echo '
   <td class="titre" width="100%">'.$tblti.'</td>';
  else
	echo '
   <td width="100%"></td>';
    echo '
   <td rowspan="2"  width="'.$size.'" style="background-image:url('.$meskin.'tab_dc.gif)" ></td></tr>
  <tr>
   <td class="tbl" onmouseover="this.className = \'tblover\'" onmouseout="this.className = \'tbl\'">';
}

function btable() {			// Right and Bottom design for Center Boxes
  global $meskin, $size;
  ?>
  </td></tr>
  <tr>
   <td width="<?php echo $size; ?>" height="<?php echo $size; ?>"><img src="<?php echo $meskin; ?>tab_bg.gif" alt=" " /></td>
   <td height="<?php echo $size; ?>" style="background-image:url(<?php echo $meskin; ?>tab_bc.gif);"></td>
   <td width="<?php echo $size; ?>" height="<?php echo $size; ?>"><img src="<?php echo $meskin; ?>tab_bd.gif" alt=" " /></td>
  </tr>
  </table>
  <?php
}

function htable1($tblti) {		// Top and Left design for Lateral Boxes
  global $meskin, $size;
	echo '
  <table class="htable1" cellspacing="0" cellpadding="0" align="center" width="196" border="0">
  <tr>
   <td width="'.$size.'" height="'.$size.'"><img src="'.$meskin.'tab_hg.gif" alt=" " /></td>
   <td height="'.$size.'" style="background-image:url('.$meskin.'tab_hc.gif);"></td>
   <td width="'.$size.'" height="'.$size.'"><img src="'.$meskin.'tab_hd.gif" alt=" " /></td></tr>
  <tr>
   <td rowspan="2" width="'.$size.'" style="background-image:url('.$meskin.'tab_gc.gif)"></td>';
  if (trim($tblti) != '') 
	echo '
   <td class="titrebox">'.$tblti.'</td>';
  else
	echo '
   <td></td>';
    echo '
   <td rowspan="2" width="'.$size.'" style="background-image:url('.$meskin.'tab_dc.gif)"></td></tr>
  <tr>
  <td class="tblbox" onmouseover="this.className = \'tblboxover\'" onmouseout="this.className = \'tblbox\'">';
}

function btable1() {			// Right and Bottom design for Lateral Boxes
  global $meskin, $size;
  ?>
  </td></tr>
  <tr>
   <td width="<?php echo $size; ?>" height="<?php echo $size; ?>"><img src="<?php echo $meskin; ?>tab_bg.gif" alt=" " /></td>
   <td height="<?php echo $size; ?>" style="background-image:url(<?php echo $meskin; ?>tab_bc.gif)"></td>
   <td width="<?php echo $size; ?>" height="<?php echo $size; ?>"><img src="<?php echo $meskin; ?>tab_bd.gif" alt=" " /></td>
  </tr>
  </table>
  <?php
}
function htable2() {                        // Top and Left design for other Boxes (header, footer...)
  global $meskin, $size;
  ?>
  <table class="htable2" cellspacing="0" cellpadding="0" align="center" width="100%" border="0">
   <tr>
    <td width="<?php echo $size; ?>" height="<?php echo $size; ?>"><img src="<?php echo $meskin; ?>tab_hg.gif" alt="*" title="*" /></td>
    <td width="100%" height="<?php echo $size; ?>" style="background-image:url(<?php echo $meskin; ?>tab_hc.gif);"></td>
    <td width="<?php echo $size; ?>" height="<?php echo $size; ?>"><img src="<?php echo $meskin; ?>tab_hd.gif" alt="*" title="*" /></td></tr>
   <tr>
    <td width="<?php echo $size; ?>" style="background-image: url(<?php echo $meskin; ?>tab_gc.gif);"></td>
    <td width="100%" class="titre" style="padding:0px; border:0px;">
  <?php
  }

function btable2() {                              // Right and Bottom design for other Boxes
  global $meskin, $size;
  ?>
    </td><td width="<?php echo $size; ?>" style="background-image: url(<?php echo $meskin; ?>tab_dc.gif);"></td></tr>
   <tr>
    <td width="<?php echo $size; ?>" height="<?php echo $size; ?>"><img src="<?php echo $meskin; ?>tab_bg.gif" alt="*" /></td>
    <td width="100%" height="<?php echo $size; ?>" style="background-image: url(<?php echo $meskin; ?>tab_bc.gif);"></td>
    <td width="<?php echo $size; ?>" height="<?php echo $size; ?>"><img src="<?php echo $meskin; ?>tab_bd.gif" alt="*" title="*" /></td></tr>
  </table>
  <?php
}
?>
