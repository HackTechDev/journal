<?php
/*
    Admin Counter- GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.9 (11 February 2003)  : added update of statsbk.dtb and reset of ipstats.dtb when the counter value is manually changed
      v2.3 (27 July 2003)      : added forms style management (by Nicolas Alves)
      v2.4 (24 September 2003) : created $dbstats, $dbipstats, $dbstatsbk and $dbcounter variables
      v3.0 (25 February 2004)  : added skins management (by Nicolas Alves)
      v4.0 (06 December 2004)  : added page title, counter management (by Jean-Mi)
                                 added alt tags to img and removed border tag for non-linked img (by Isa)
				                 added multi-admin management, updated counter management (by Nicolas Alves)
	  v4.5 (22 April 2005)       : corrected actions "vider" and "reduire" (by Jean-Mi)
								   corrected function DiffDate to prevent division by 0 (by Jean-Mi)
      v4.6.10 (07 September 2009)    : corrected #274
      v4.6.16 (02 September 2011) : corrected display booster (by Papinou)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "counter.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[31]=="") {
    $nomzone=$admin17;
    include("access.inc");
    exit();
  }
}
	switch($actlog) {
		case "vider" :
			$tmplog1 = file(DBLOGSTATS);
			$tmplog2 = array();
			/// Corrigé borne basse de la boucle
			for($i = max(0, count($tmplog1)-2); $i < count($tmplog1); $i++) {
				$tmplog2[][0] = $tmplog1[$i];
			}
			WriteDBFields(DBLOGSTATS, $tmplog2);
			break;
		case "reduire" :
			$tmplog1 = file(DBLOGSTATS);
			$tmplog2 = array();
			/// Corrigé borne basse de la boucle
			for($i = max(0, count($tmplog1)-9); $i < count($tmplog1); $i++) {
				$tmplog2[][0] = $tmplog1[$i];
			}
			WriteDBFields(DBLOGSTATS, $tmplog2);
			break;
	}
	if ($visites == 1) {
    if ($numeric < 1) $numeric = 1;
	  WriteCounter(DBSTATS,$numeric);
	  WriteCounter(DBSTATSBK,$numeric);
	  WriteFullDB(DBIPSTATS,"\n");
		$tmpdate = ReadCounter(DBLOGDATE);
		$tmplog1 = file(DBLOGSTATS);
		$tmplog2 = array();
		for($i = 0; $i < count($tmplog1)-1; $i++) {
			$tmplog2[][0] = $tmplog1[$i];
		}
		WriteDBFields(DBLOGSTATS, $tmplog2);
		WriteCounter(DBLOGDATE, "");
	}
	$pgvues = ReadCounter(DBSTATS);
	$topmess = $admin141;
	include(CHEMIN."inc/hpage.inc");
	htable($admin141, "100%");
?>
<div align="center">
<a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=count"><?php echo $admin657; ?></a> || <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b>
<hr /><br />
<form action="admin.php?lng=<?php echo $lng; ?>" method="post">
<input type="hidden" name="lng" value="<?php echo $lng; ?>" />
<input type="hidden" name="pg" value="counter"/>
<input type="hidden" name="visites" value="1"/>
<table cellspacing="0" cellpadding="0" align="center" border="0" summary="">
<tr><td align="center"><?php echo $admin142; ?></td></tr>
<tr><td align="center"><input class="texte" type="text" name="numeric" size="9" value="<?php echo $pgvues; ?>"/>&nbsp;<?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin144; ?>"><?php echo $admin144; ?></button><?php echo $boutonright; ?></td></tr>
</table></form>
<?php
	if (is_file(DBLOGSTATS)) {
		function DiffDate($d1, $d2) {
			list($j1, $m1, $a1) = explode("/", $d1);
			list($j2, $m2, $a2) = explode("/", $d2);
			$result = (mktime(0, 0, 0, $m1, $j1, $a1) - mktime(0, 0, 0, $m2, $j2, $a2))/86400;
			/// Corrigé la valeur de retour pour eviter tout risque de division par un nombre < 1
			return max(1, $result);
		}
		$dblog1 = file(DBLOGSTATS);
		if (count($dblog1) > 2) {
			for($i=0; $i<count($dblog1); $i++) {
			$dblog2 = explode(";", $dblog1[$i]);
			$dblog3[$i][0] = $dblog2[0];
			$dblog3[$i][1] = $dblog2[1];
			$dblog3[$i][2] = ($i == 0 ? 0 : ($dblog2[1] - $dblog3[$i - 1][1])/DiffDate($dblog2[0], $dblog3[$i - 1][0]));
			}
			$countmax = 1;
			for($i=1; $i<count($dblog3); $i++) {
				$dblog3[$i][2] = ($dblog3[$i][1] - $dblog3[$i - 1][1])/DiffDate($dblog3[$i][0],$dblog3[$i - 1][0]);
				if ($dblog3[$i][2] < 0) {
					$dblog3[$i][1] = $dblog3[$i-1][1]+$dblog3[$i-1][2]*($dblog3[$i][0]-$dblog3[$i-1][0]);
					$dblog3[$i][2] = $dblog3[$i-1][2];
					$dblog3[$i][3] = " style='color:red'";
					$dblog3[$i][4] = CHEMIN."inc/img/bars/rouge.gif";
				}
				else {
					$dblog3[$i][3] = "";
					$dblog3[$i][4] = CHEMIN."inc/img/bars/vert.gif";
				}
				$countmax = max($countmax, $dblog3[$i][1]);
			}
			$countmax = max(1, $countmax);
			$countmin = 999999999;
			for($i=count($dblog3)-1; $i>max(count($dblog3)-16, 0); $i--) {
				$countmin = min($countmin, $dblog3[$i][1]);
			}
			echo "<p>&nbsp;</p><hr /><table cellspacing='10' cellpadding='0' align='center' width='95%' border='0' summary=''>";
			echo "<tr><td colspan='3' align='center'>".$admin750."</td></tr>";
			echo "<tr align='center'><td width='15%'>".$admin751."</td><td width='15%'>".$admin752."</td><td width='70%'>".$admin753."</td></tr>";
			for($i=count($dblog3)-1; $i>max(count($dblog3)-16, 0); $i--) {
				$pourcent = floor(20 + ($dblog3[$i][1] - $countmin)/max(1, ($countmax - $countmin))*80);
				echo "<tr><td align='center'>".$dblog3[$i][0]."</td><td align='center' ".$dblog3[$i][3].">".$dblog3[$i][1]."</td><td align='left'><img src='".$dblog3[$i][4]."' height='10' width='".$pourcent."%' alt='".$pourcent."%' /></td></tr>";
			}
			echo "</table>";
			echo "<p align='center'><a href='".CHEMIN."admin/admin.php?lng=".$lng."&amp;pg=counter&amp;actlog=vider'>$admin754</a> || <a href='".CHEMIN."admin/admin.php?lng=".$lng."&amp;pg=counter&amp;actlog=reduire'>$admin755</a></p>";
			echo "<hr />";
		}
	}
?>
<a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=count"><?php echo $admin657; ?></a> || <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b>
</div>
<?php
	btable();
	include(CHEMIN."inc/bpage.inc");

?>
