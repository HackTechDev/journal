<?php
/*
    About window - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v1.9 (11 February 2003)    : initial release
      v2.0 (27 February 2003)    : reformated layout and added credits information
                                   added WriteMailTo() javascript function - encryption of email @ (SPAM protection)
      v2.1 (10 March 2003)       : updated the Credits information
      v2.2 (22 April 2003)       : updated the Credits information (added Isabelle and changed Columbia to Cambodia for Nicolas => sorry Nicolas!)
                                   cleanup in the images organisation
      v2.3 (27 July 2003)        : upgraded WriteMailTo() function for better SPAM protection (thanks Michel)
      v2.4 (24 September 2003)   : slightly upgraded the look & feel of this about box
      v4.0 (06 December 2004)    : added alt tags to img and removed border tag for non-linked img (by Isa)
	                               updated credits and licence information (by Icare)
	  v4.6.0 (04 June 2007)      : updated credits(by Icare)
      v4.6.9 (25 December 2008)  : added corrections for validation of W3C
	  V4.6.14 (14 February 2011) : updated licence information
	  v4.6.18 (09 February 2012) : added $mpcopyright (by Saxbar)
	                               corrected credits information (thanks Corrector)
      v4.6.21 (18 October 2012)  : updated credits information (by Papinou)								   
	  
*/
if (stristr($_SERVER["SCRIPT_NAME"], "about.inc")) {
  header("location:../index.php");
  die();
}
include(CHEMIN."inc/hpage.inc");
htable($admin277, "100%");
?>
<center>
<table align="center" width="520" cellspacing='1' cellpadding='1' border='0'>
<tr>
	<td style="width:30%; padding-right:10px;"><img src="<?php echo CHEMIN; ?>admin/inc/img/general/gylogo.gif" alt="gylogo.gif" /></td>
	<td><p align="left"><font size="+2"><strong>GuppY v<?php echo $mpversion; ?></strong></font><br />
	<?php echo $mpdate; ?><br />
	CeCILL Copyright&nbsp; <font size="4"><strong>&copy;</strong></font>&nbsp; <?php echo $mpcopyright; ?> :
	<strong>Laurent Duveau</strong><br />
        Initiated by Laurent Duveau and Nicolas Alves</p></td>
</tr>
</table>
<br />
<p>GuppY's Web site&nbsp;:&nbsp;&nbsp;<a href="http://www.freeguppy.org/">http://www.freeguppy.org/</a></p>
<br />

<p align="center"><strong>===&nbsp; Credits &nbsp;===</strong></p>
<div id="credit" class="rep" style="padding:8px;width:480px;height:130px;overflow:auto; text-align:left;">
 The GuppY Team is made up of volunteers who give of their leisure time.
 Thanks to all of you guys and girls!<br />
<br />
As many people have given a hand in this project, I just cannot write something about all of them, so <b>let me just focus on the team</b> and <b>look at the scrolling area below.</b><br />
<br />
<strong>aldweb</strong> (that's me!, from France)<br />
- GuppY's creator and main developper.<br />
<br />
<strong>JeandePeyrat</strong> (The "Servers'servant!")<br />
- JeandePeyrat,  GuppY Team administrator, president of the association freeGuppY,<br />
  forum moderator,  freeGuppY servers maintenance has no secrets for Jean.<br />
<br />
<strong>Papinou</strong> (The "The wizard of CSS")<br />
- Papinou, administrator GuppY Team, Treasurer of the association freeGuppY,<br />
  forum moderator, interested in everything concerning CSS style sheets and not bad at all at English!<br />
<br />
<strong>Saxbar</strong> (the "composer and musician" of php)<br />
- Saxbar, Since August 2011 all GuppY versions rose from his keyboard,<br />
  and this will not surprise you as computing, php and javascript writing and last but not least music are his passions<br />
<br />
<strong>Djchouix</strong> (The scientist)<br />
- Djchouix, a great developper has been working noiselessy for so many years.<br />
  He is the author of the new GuppY editors. <br />
<br />
<strong>Corrector</strong> (The"king of translation")<br />
- Corrector, the English language is his second mother tongue, but the corrections<br />
  of the French language are also his line. He is especially hard on Frenglish.<br />
<br />
<strong>La Vache Qui Rêve -the dreaming cow! as she has named herself- But she is so much more feminine and subtle than that!-</strong> (GuppYed, tutos)<br />
- GuppYed administrator and tutorials specialist in addition to keeping our stable tidy.<br />
<br />
<strong>Fred68</strong> (GuppYed, tutos)<br />
- GuppYed administrator and  tutorials specialist, an excellent tutorial for CKEditor is one of his major works.<br />
<br />
<strong>Pascal31</strong> (GuppYLand)<br />
- GuppYLand administrator, designer of the homepage presentation.<br />
<br />
<strong>jerlal</strong> (GuppYLand)<br />
-  GuppYLand administrator, alpha versions beta-tester , or fierce squeak-buster ...<br />
<br />
Thanks to <strong>Alex</strong> historically the first to join me, <strong>Nicolas</strong>
 who made plenty of developments <strong>Icare</strong> originator of the GuppY new look and <strong>JeanMi</strong> great PHP specialist (Mister Plugin).<br />
<br />
Let's also thank  <b>all the GuppY Team</b>, people who come up with translations into various languages and all those who
provided the GuppY Team with help, nice comments and improvement ideas.<br /><br />
</div>
<p align="center">
  <iframe src="<?php echo CHEMIN; ?>admin/generic.htm" width="490" height="200" frameborder="1"  scrolling="no"></iframe>
</p>
<p align="center"><strong>===&nbsp; Licence &nbsp;===</strong></p>
<div id="licence" class="rep" style="padding:8px;width:480px;height:168px;overflow:auto; text-align:left;">
This software is free, so you can distribute it and/or modify it accordingly to the CeCILL License.<br />
CEA  CNRS and INRIA, great French organisations released CeCILL in July 2004.
CeCILL is the first license defining the principles of use and dissemination of Free Software in conformance with French law, following the principles of the GNU GPL.<br />
<br />
This software is distributed because we believe it might be useful and interesting, but it comes WITHOUT ANY WARRANTY OF ANYKIND, either expressed or implied, including, but not limited to, the implied warranties of merchantability and fitness for a particular purpose. Please refer to <a href="http://www.cecill.info/index.en.html" target="blank">http://www.cecill.info/index.en.html</a> for more detailed information.<br />
<br />
You should have received a copy of the CeCILL free License at the same time you received this software ; if this was not the case, please send an e-mail to "info@cecill.info".<br />
 </div>
<?php echo '<div style="padding:8px;width:480px;">'; include("infos.inc"); echo '</div>'; ?>
<hr />
<p align="center">
	<a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b></p>
</center>
	<?php
	btable();
	include(CHEMIN."inc/bpage.inc");
?>
