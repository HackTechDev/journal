<?php
/*
    Maintenance - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v4.0 (06 December 2004)       :  initial release (by Nico - Icare)
      v4.6.1 (02 July 2007)         : corrected xhtml compliance (thanks balou)
      v4.6.10 (7 September 2009)    : corrected #274
      v4.6.11 (11 December 2009)    : changed width by style=width in cells (by Icare)
	  v4.6.18 (09 February 2012)    : corrected copyright (by Saxbar)
*/

include("data/config.inc");
$haut= (600- 600)/2;
$align= (800 - 480)/2;
?>
<html>
<head>
<title>maintenance</title>
<meta name="Robots" content="NONE">
<META http-equiv="Refresh" Content="60; index.php">
</head>
<body bgcolor="azure">
<center>
<div align="center" style='width: 540px; background-color: azure; border: 1px solid;'>
<table width="540" cellspacing="0" cellpadding="5" border="0" summary>
<tr align="center">
<td colspan="3"><strong><font face="Verdana, Arial, Helvetica, sans-serif" size="4">
*** &nbsp;&nbsp;<?php echo $site[0]; ?>&nbsp;&nbsp; ***</strong>&nbsp;&nbsp;</td>
</tr>
<tr align="center">
<td style="width:180px"><br /><br /><strong>
<p><font face="Verdana, Arial, Helvetica, sans-serif" size="3">Site en maintenance pour quelques minutes.</font></p>
<p>...</p>
<p><font face="Verdana, Arial, Helvetica, sans-serif" size="3">Nous sommes désolés pour la g&ecirc;ne occasionnée, à bientôt.<br /><br /></font></p></strong></td>
<td style="width:180px"><div align="center"><font size="2" face="Verdana, Arial, Helvetica, sans-serif">
<img src="inc/img/general/maintenance.gif" alt="Don't disturb" /></font></div></td>
<td style="width:180px"><br /><br /><strong>
<p><font face="Verdana, Arial, Helvetica, sans-serif" size="3">This Site is Currently Under Maintenance.</font></p>
<p>...</p>
<p><font face="Verdana, Arial, Helvetica, sans-serif" size="3">We apologize for the inconvenience. Please, come back soon...<br /><br /></font></p>
</strong></td></tr>
</table>
<p>&nbsp;</p>
<p><a href="http://www.freeguppy.org"><img src="inc/img/general/gyslogo.gif" alt="Guppy site" width="104" height="39" border="0" longdesc="http://www.freeguppy.org" /></a><br />
  <a class='copyright' href='http://www.freeguppy.org/' title=' -> freeguppy.org' target='_blank'><img src='inc/img/general/gypower.gif' border='0' valign='middle' /></a>
  &nbsp; © 2004-2012 &nbsp;
  <a class='copyright' href='http://www.cecill.info/index.en.html' title='More info ...' target='_blank'> <img src='inc/img/general/gycecill_e.gif' border='0' valign='middle' /></a>

</font></p>
</div>
</center>
</body>
</html>
