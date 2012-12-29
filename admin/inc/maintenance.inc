<?php
/*
    Admin maintenance - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.0 (06 December 2004)    : initial release by Nicolas Alves
      v4.6.10 (7 September 2009)    : corrected W3C
*/

if (stristr($_SERVER["SCRIPT_NAME"], "maintenance.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[11]=="") {
    $nomzone=$admin817;
    include("access.inc");
    exit();
  }
}
 if ($regit == 1) {
 include(CONFIG);
 $serviz[31] = $serviz31;
 $serviz[44] = $serviz44;
 include("inc/confupdt.inc");
}
include(CONFIG);
if (is_file(CHEMIN."skin/".$page[14]."/confskin".INCEXT)){
  include(CHEMIN."skin/".$page[14]."/confskin".INCEXT);
} else {
  include(CHEMIN."skin/no_skin/confskin".INCEXT);
}
include(CHEMIN."inc/hpage.inc");
htable($admin811, "100%");
?>
<p align="center"><?php echo $admin812; ?></p>
<form name="conf4" action="admin.php?lng=<?php echo $lng; ?>" method="post">
<input type="hidden" name="pg" value="maintenance" />
<input type="hidden" name="regit" value="1" />
<table cellspacing="0" cellpadding="2" align="center" width="90%" border="0" summary="">
<tr><td colspan="3"><p align="center"><b><?php echo $admin813; ?></b></p><p>&nbsp;</p></td></tr>
<tr><td><p style="padding-left:15px;"><?php echo $admin814; ?></p></td><td><p><input class="texte" type="text" name="serviz31" size="20" value="<?php echo $userprefs[1]; ?>" readonly="readonly" /></p></td></tr>
<tr><td><p style="padding-left:15px;"><?php echo $admin815; ?></p></td><td><p><input type="checkbox" name="serviz44" <?php if ($serviz[44]) echo 'checked="checked"'; ?> /></p></td></tr>
</table>
<p>&nbsp;</p>
<p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin66; ?>"><?php echo $admin66; ?></button><?php echo $boutonright; ?></p>
</form>
<hr />
<p align="center">
<a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b></p>
<?php
btable();
include(CHEMIN."inc/bpage.inc");

?>
