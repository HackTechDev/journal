<?php
/*
    Statistics - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.1 (02 January 2003)   : added $statactor variable
                                   (in order to avoid overwrites of Stats database when more users
                                    ask for Stats simultaneously. Now only Admin can compact the
                                    Stats database)
      v1.2 (05 January 2003)   : complete rewrite of Stats module
      v2.2 (22 April 2003)     : bug fix: now current hour stats are also reset
                                 replaced <P><CENTER> by <P align="center"> otherwise IE takes the default font instead of the required one (Thanks Michel)
      v2.3 (27 July 2003)      : added forms style management (by Nicolas Alves)
      v3.0 (25 February 2004)  : added skins management (by Nicolas Alves)
      v4.0 (06 December 2004)  : added multi-admin management (by Nicolas Alves)
      v4.6.12 (01 May 2010) : #317 added display stats of previous month (by Icare)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "stats.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[32]=="") {
    $nomzone=$admin212;
    include("access.inc");
    exit();
  }
}
 if ($purge == 1) {
 $dbh = InitDBlog(1);
 WriteDBFields(DBLOGH,$dbh);
 $dbd = InitDBlog(24);
 WriteDBFields(DBLOGD,$dbd);
 $dbm = InitDBlog(31);
 WriteDBFields(DBLOGM,$dbm);
 WriteDBFields(DBLOGL,$dbm);
 $dby = InitDBlog(12);
 WriteDBFields(DBLOGY,$dby);
 WriteDBFields(DBLOGP,$dby);
 }
 if (empty($per)) {
 $per = 1;
 }
include(CHEMIN."inc/statcalc.inc");
$topmess = $admin214;
include(CHEMIN."inc/hpage.inc");
htable($admin214, "100%");
$pyr = date("Y")-2;
?>
<form name="statraz" action="admin.php?lng=<?php echo $lng ?>" method="post">
<input type="hidden" name="pg" value="stats" />
<input type="hidden" name="purge" value="1" />
<p align="center"><b><?php echo $admin216; ?></b></p>
<p align="center"><b><?php echo $admin26; ?></b> <?php echo $admin48; ?></p>
<p>&nbsp;</p>
<p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin218; ?>"><?php echo $admin218; ?></button><?php echo $boutonright; ?></p>
</form><hr />
<p align="center"><b><?php echo $admin219; ?></b></p>
<?php
include(CHEMIN."inc/statshow.inc");
?>
<hr />
<p align="center">
[ <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b> ]</p>
<?php
btable();
include(CHEMIN."inc/bpage.inc");

?>
