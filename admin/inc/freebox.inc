<?php
/*
    Admin extra Free Boxes - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.9 (11 February 2003)  : initial release
      v2.0 (27 February 2003)  : no change
      v2.1 (10 March 2003)     : no change
      v2.2 (22 April 2003)     : no change
      v2.3 (27 July 2003)      : no change
      v2.4 (24 September 2003) : added 3 additional free boxes (by Nicolas Alves and Laurent Duveau)
      v3.0 (25 February 2004)  : no change
      v4.0 (06 December 2004)  : changed cellpadding to 3 (Isa)
	                             added page title (by Jean-Mi)
				                 added multi-admin management (by Nicolas Alves)
      v4.6.10 (7 September 2009)    : corrected #274
*/

if (stristr($_SERVER["SCRIPT_NAME"], "freebox.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[26]=="") {
    $nomzone=$admin270;
    include("access.inc");
    exit();
  }
}
header("Pragma: no-cache");
$topmess = $admin271;
include(CHEMIN."inc/hpage.inc");
$freetitle1 = "";
$freetitle2 = "";
include(DBFREEBOX1);
 if ($lng == $lang[0]) {
 $titfree1 = $freetitle1;
}
else {
 $titfree1 = $freetitle2;
}
 if (trim($titfree1) != "") {
 $titfree1 = "(".$titfree1.")";
}
$freetitle1 = "";
$freetitle2 = "";
include(DBFREEBOX2);
 if ($lng == $lang[0]) {
 $titfree2 = $freetitle1;
}
 if (trim($titfree2) != "") {
 $titfree2 = "(".$titfree2.")";
}
else {
 $titfree2 = $freetitle2;
 }
$freetitle1 = "";
$freetitle2 = "";
include(DBFREEBOX3);
 if ($lng == $lang[0]) {
 $titfree3 = $freetitle1;
}
else {
 $titfree3 = $freetitle2;
}
 if (trim($titfree3) != "") {
 $titfree3 = "(".$titfree3.")";
}
$freetitle1 = "";
$freetitle2 = "";
include(DBFREEBOX4);
 if ($lng == $lang[0]) {
 $titfree4 = $freetitle1;
}
else {
 $titfree4 = $freetitle2;
}
 if (trim($titfree4) != "") {
 $titfree4 = "(".$titfree4.")";
}
htable($admin271, "100%");
?>
<div align="center">
<?php echo $admin272; ?>
<hr />
[ <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b> ]<hr />
</div><br />
<table cellspacing="0" cellpadding="3" align="center" border="0" summary="">
<tr align="center">
<td style="white-space:npowrap;"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=freebox1"><img src="inc/img/admin/freebox.gif" alt="<?php echo $admin365; ?>" border="0" /><br /><?php echo $admin365."<br />".$titfree1; ?></a></td>
<td style="white-space:npowrap;"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=freebox2"><img src="inc/img/admin/freebox.gif" alt="<?php echo $admin496; ?>" border="0" /><br /><?php echo $admin496."<br />".$titfree2; ?></a></td>
</tr><tr align="center">
<td style="white-space:npowrap;"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=freebox3"><img src="inc/img/admin/freebox.gif" alt="<?php echo $admin497; ?>" border="0" /><br /><?php echo $admin497."<br />".$titfree3; ?></a></td>
<td style="white-space:npowrap;"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=freebox4"><img src="inc/img/admin/freebox.gif" alt="<?php echo $admin498; ?>" border="0" /><br /><?php echo $admin498."<br />".$titfree4; ?></a></td>
</tr></table>
<div align="center"><hr />
[ <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b> ]
</div>
<?php
btable();
include(CHEMIN."inc/bpage.inc");

?>
