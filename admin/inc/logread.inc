<?php
/*
    ReadLog - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v3.0 (25 February 2004)   : initial release by B@lou, Nicolas Alves and Laurent Duveau (real team work!)
      v4.0 (06 December 2004)   : added alt tags to img and removed border tag for non-linked img (by Isa)
	                              added page title (by Jean-Mi)
			                      added multi-admin management (by Nicolas Alves)
      v4.6.9 (25 December 2008) : corrected the background color of the cells #249
      v4.6.10(7 September 2009) : corrected #274
      v4.6.17(21 October 2011)  : corrected characters after the last point of domain (thanks François)
	  v4.6.18(09 February 2012) : corrected bad file (by Papinou)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "logread.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[35]=="") {
    $nomzone=$admin553;
    include("access.inc");
    exit();
  }
}
define("CHEMIN", "../");
$topmess = $admin556;
include(CHEMIN."inc/hpage.inc");
?>
<script type="text/javascript">
 function ConfirmDeleteAll(url) {
 if (confirm("<?php echo $admin559; ?>")) location.href=url;
 }
</script>
<?php
 if ($action == "delall") {
 DestroyDBFile(DBLOGBOOK);
?>
<script type="text/javascript">
 window.location='admin.php?lng=<?php echo $lng; ?>&amp;pg=logbook';
</script>
<?php
 }
 $amsglog = ReadDBFields(DBLOGBOOK);
htable($admin556, "100%");
?>
<p align="center"><?php echo $admin557." ".$REMOTE_ADDR; ?></p>
<?php
 if (empty($amsglog)) {
?>
<table width="100%" summary="">
  <tr>
    <td align="center"><img src="<?php echo CHEMIN; ?>inc/img/smileys/rolleyes.gif" alt="8-)" title="8-)" />
<b><?php echo $admin558; ?></b>
    </td>
  </tr>
</table>
<?php
}
else {
?>
<table width="100%" cellspacing="1" cellpadding="0" style="background-color:<?php echo $page[5]; ?>" border="0" summary="">
  <tr class="forum2">
    <td align="center" width="15%" height="20">&nbsp;<b><?php echo $admin521; ?></b>&nbsp;</td>
    <td align="center" width="15%">&nbsp;<b><?php echo $admin518; ?></b>&nbsp;</td>
    <td align="center" width="30%">&nbsp;<b><?php echo $admin560; ?></b>&nbsp;</td>
    <td align="center" width="20%">&nbsp;<b><?php echo $admin561; ?></b>&nbsp;</td>
    <td align="center" width="10%">&nbsp;<b><?php echo $admin562; ?></b>&nbsp;</td>
    <td align="center" width="10%">&nbsp;<b><?php echo $admin563; ?></b>&nbsp;</td>
  </tr>
<?php
$nnav = array("netscape", "msie", "mozilla", "da", "opera", "icab", "konqueror", "robot", "unknown", "safari", "chrome");
for ($i = count($amsglog)-1; $i >= 0; $i--) {
    if (file_exists(CHEMIN."inc/lang/".substr(strrchr($amsglog[$i][3],"."),1).".gif")) {
        $imgflag = (substr(strrchr($amsglog [$i] [3],"."),1).".gif");
    }
    else {
        $imgflag = ("unknown.gif");
    }
    $xurl = str_replace('&', '&amp;', $amsglog[$i][2]);
    $xurl = empty($xurl) ? '&nbsp;' : '&nbsp;<a href="'.$xurl.'" target="_blank" title="'.$xurl.'">'.$xurl.'</a>';
?>
  <tr class="rep">
    <td width="15%" align="center" height="40">&nbsp;&nbsp;<?php echo FormatDate($amsglog[$i][0]); ?></td>
    <td width="15%" align="left">&nbsp;<?php echo $amsglog[$i][1]; ?></td>
    <td width="30%"><?php echo $xurl; ?></td>
    <td width="20%">&nbsp;<?php echo $amsglog[$i][3]; ?></td>
    <td width="10%" align="center">&nbsp;<img src="<?php echo CHEMIN; ?>inc/lang/<?php echo $imgflag; ?>" width="24" height="16" alt="<?php echo $imgflag; ?>" title="<?php echo $imgflag; ?>" /></td>
    <td width="10%" align="center">&nbsp;<img src="<?php echo CHEMIN; ?>inc/img/browser/<?php echo $nnav[$amsglog[$i][4]].".gif"; ?>" width="16" height="16" alt="<?php echo $nnav[$amsglog[$i][4]].".gif"; ?>" title="<?php echo $nnav[$amsglog[$i][4]].".gif"; ?>" /></td>
  </tr>
<?php
 }
?>
</table>
<hr />
<p align="center">
<?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin218; ?>"  onclick="ConfirmDeleteAll('admin.php?lng=<?php echo $lng; ?>&amp;pg=logread&amp;action=delall')"><?php echo $admin218; ?></button><?php echo $boutonright; ?>
</p>

<?php
 }
?>
<p>&nbsp;</p>
<p align="center">
[ <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=logbook"><?php echo $admin564; ?></a> || <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b> ]</p>
<?php
btable();
include(CHEMIN."inc/bpage.inc");

?>
