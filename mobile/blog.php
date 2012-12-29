<?php
/*
    Blog for PDA - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.6.0 (04 June 2007)    : initial release (by Icare)
      v4.6.6 (14 April 2008)   : added header("HTTP/1.0 404 Not found") in the event of pages not found (by JeanMi, thanks eDada)
      v4.6.17 (21 October 2011) : added private management (by Saxbar)	  
*/

header("Pragma: no-cache");
define("CHEMIN", "../");
include(CHEMIN."inc/includes.inc");

if ($serviz[53] != "on") {
  exit($web143);
}

$section_index = 15;
$section_name = $lng == $lang[0] ? $nom[42] : $nom[43];
include('inc/members.inc');
if ($section_access) {

	$pg = strip_tags($pg);
	$prt = strip_tags($prt);
	$id = strip_tags($id);

	if (count(SelectDBFields(TYP_BLOG,"a",$pg)) == 1) {
		ReadDoc(DBBASE.$pg);
		$countit = 1;
		if ($lng == $lang[0]) {
			$txtart1 = $fieldb1;
			$txtart2 = PathToImage($fieldc1);
			$txtart3 = $fielda1;
		}	else {
			$txtart1 = $fieldb2;
			$txtart2 = PathToImage($fieldc2);
			$txtart3 = $fielda2;
		}
		$txtart4 = FormatDate($moddate);
		$txtart5 = FormatDate($creadate);
		$txtart6 = $author;
		/// début modif accès privé
		$txtart7 = $fieldmod;
		/// fin modif accès privé
	}	else {
		$countit = 0;
		$txtart1 = $web35;
		$txtart2 = $web36;
		$txtart3 = $web37;
		$txtart4 = $web37;
		$txtart5 = $web37;
		/// début modif accès privé
		$txtart7 = "";
		/// fin modif accès privé
		header('HTTP/1.0 404 Not Found');
	}

	/// début modif accès privé
	$acces ="ok";
	if ($txtart7 != "") {
		$acces = "no";
		if ($userprefs[1] != "") {
			include_once (CHEMIN.'inc/func_groups.php');
			if (CheckGroup($txtart7, $userprefs[1])) $acces ="ok";
		}
	}
	if ($acces == "ok") {
	/// fin modif accès privé

		$topmess = $txtart1;
		include("inc/hpalm.inc");
		$doc = array();
		$dbblog = ReadDBFields(DBBLOG);
		if (count($dbblog) > 1) {
			for ($i = 0; $i < count($dbblog); $i++){
				$doc[$i] = $dbblog[$i][4];
				if ($doc[$i] == $pg) {
					$docp = $dbblog[$i-1][4];
					$docn = $dbblog[$i+1][4];
				}
			}
			?>
			<p align="center">
			<?php
			if ($pg == $dbblog[count($dbblog)-1][4]) {$docn = $dbblog[count($dbblog)-1][4]; $f = "_n";}
			?>
			<a href="blog.php?lng=<?php echo $lng; ?>&amp;pg=<?php echo $doc[count($dbblog)-1]; ?>" title="<?php echo $web339; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/debut<?php echo $f; ?>.gif" border="0" alt="<?php echo $web339; ?>" /></a>
			<a href="blog.php?lng=<?php echo $lng; ?>&amp;pg=<?php echo $docn; ?>" title="<?php echo $web32; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/precedent<?php echo $f; ?>.gif" border="0" alt="<?php echo $web32; ?>" /></a>
			<?php
			echo "<b>".$txtart1."</b>";
			if ($pg == $dbblog[0][4]) {$docp = $dbblog[0][4]; $d = "_n";}
			?>
			<a href="blog.php?lng=<?php echo $lng; ?>&amp;pg=<?php echo $docp; ?>" title="<?php echo $web34; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/suivant<?php echo $d; ?>.gif" border="0" alt="<?php echo $web34; ?>" /></a>
			<a href="blog.php?lng=<?php echo $lng; ?>&amp;pg=<?php echo $doc[0]; ?>" title="<?php echo $web338; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/fin<?php echo $d; ?>.gif" border="0" alt="<?php echo $web338; ?>" /></a></p>
			<?php
		}
		echo $web393." <b>".$txtart3."</b> - ".$web6." <b>".$txtart6."</b> <br>";
		echo "<hr />";
		echo $txtart2."<hr />";
		echo $web95." ".$txtart5."<br>";
		if ($serviz[33] == "on" && $countit == 1) {
			$artcounter = UpdateDocCounter($pg);
			if ($artcounter <= 1) {
				$txtcount = $web188;
			}	else {
				$txtcount = $web189;
			}
			echo $web190." ".$artcounter." ".$txtcount."<br>";
		}
		if ($serviz[57] == "on" && $countit == 1) {
			$dbreaction = ReadDBFields(DBREBLOG);
			for ($i = 0; $i < count($dbreaction); $i++) {
				if ($dbreaction[$i][1] == $pg) {
					$dbwork[] = $dbreaction[$i][0];
				}
			}
			@rsort($dbwork);
			echo "<hr /><center><b>".$web407."</b></center><hr />";
			if (empty($id)) {
				$id = 1;
			}
			if (!empty($dbwork)) {
				for ($i = $serviz[30]*($id-1); $i < Min($serviz[30]*$id, count($dbwork)); $i++) {
					ReadDoc(DBBASE.$dbwork[$i]);
					echo "<b>".$web185.$fielda1."</b>&nbsp;";
					echo $web6." ";
					echo "<b>".$author."</b>";
					echo " ".$web7." ".FormatDate($creadate)."<br><br>";
					echo PathToImage($fieldc1)."<br>";
					if ($i < Min($serviz[30]*$id, count($dbwork))-1) {
						echo "<hr />";
					}
				}
			}	else {
				echo $web186."<br>";
			}
			if (count($dbwork)>$serviz[30])
			{
			echo '<hr />'.GetNavBar("blog.php?lng=".$lng."&amp;pg=".$pg."&amp;id=", count($dbwork), $id, $serviz[30]);  $idp = $id-1;
			}
		}
		include("inc/bpalm.inc");
	} /// fin accès privé
}
?>
