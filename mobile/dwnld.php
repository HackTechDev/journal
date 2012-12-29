<?php
/*
    Dwnld - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v2.4 (24 September 2003) : initial release (by Nicolas Alves and Laurent Duveau)
      v4.0 (06 December 2004)  : no change
      v4.6.17 (21 October 2011) : added private management (by Saxbar)	  
*/

header("Pragma: no-cache");
define("CHEMIN", "../");
include(CHEMIN."inc/includes.inc");

if ($serviz[35] != "on") {
  exit($web143);
}

$section_index = 7;
$section_name = $lng == $lang[0] ? $nom[1] : $nom[11];
include('inc/members.inc');
if ($section_access) {

	$pg = strip_tags($pg);
	$id = strip_tags($id);

	function CalcDownloadTime($file_size,$modem_speed) {
		global $web37,$web202,$web203;
		if ($file_size == $web37) {
			$calctime = $web37;
		}
		else {
			$secondes=round($file_size/($modem_speed/10));
			$minutes=intval($secondes/60);
			$secondes=$secondes-60*$minutes;
			$calctime = $minutes." ".$web202." ".$secondes." ".$web203;
		}
		return $calctime;
	}

	if (!empty($pg)) {
    ReadDoc(DBBASE.$pg);
		/// début modif accès privé
		$acces = "ok";
		if ($fieldmod != "") {
			$acces = "no";
			if ($userprefs[1] != "") {
				include_once (CHEMIN.'inc/func_groups.php');
				if (CheckGroup($fieldmod, $userprefs[1])) $acces ="ok";
			}
		}
		if ($acces == "ok") {
		/// fin modif accès privé
      if ($lng == $lang[0]) {
        $urldw = $fieldd1;
        $nomdw = $fieldb1;
      }
      else {
        $urldw = $fieldd2;
        $nomdw = $fieldb2;
      }
      if (substr($urldw, 0, 5) == "file/") {
        $urldw = CHEMIN.$urldw;
      }
      $nomfl = basename ($urldw);
      $sizefl = FileSizeInKb($urldw);
      if ($sizefl === false) {
        $sizefl = $web37;
      }
      else {
        $sizefl .= " ".$web28;
      }
      $modfl = @filemtime($urldw);
      if ($modfl === false) {
        $modfl = $web37;
      }
      else {
        $modfl = FormatDateStamp($modfl);
      }
      $dnldfl = @filemtime(DBBASE.$pg.DBEXT);
      if ($dnldfl === false) {
        $dnldfl = $web37;
      }
      else {
        $dnldfl = FormatDateStamp($dnldfl);
      }
      $dnldcounter = ReadDocCounter(DBBASE.$pg);
      UpdateDocCounter($pg);
      if ($dnldcounter <= 1) {
        $txtcount = $dnldcounter." ".$web188;
      }
      else {
        $txtcount = $dnldcounter." ".$web189;
      }
      include("inc/hpalm.inc");
      if ($lng == $lang[0]) {
        $i = 0;
      }
      else {
        $i = 10;
      }
			?>
			<center><b><a href="download.php?lng=<?php echo $lng; ?>&id=<?php echo $id; ?>"><?php echo $nom[$i+1]; ?></a> - <?php echo $nomdw; ?></b></center><hr />
			<?php echo $web218; ?>&nbsp;<b><?php echo $nomdw; ?></b><br>
			<?php echo $web194; ?>&nbsp;<b><a href="<?php echo $urldw; ?>"><?php echo $nomfl; ?></a></b><br>
			<?php echo $web196; ?>&nbsp;<?php echo $modfl; ?><br>
			<?php echo $web199; ?>&nbsp;<?php echo $txtcount; ?><br>
			<?php echo $web197; ?>&nbsp;<?php echo $dnldfl; ?><br>
			<?php echo $web195; ?>&nbsp;<?php echo $sizefl; ?><br>
			<?php echo $web198; ?>&nbsp;<?php echo CalcDownloadTime($sizefl,512); ?><br>
			<?php echo $web200; ?>&nbsp;<?php echo CalcDownloadTime($sizefl,56); ?><br>
			<?php echo $web201; ?>&nbsp;<?php echo CalcDownloadTime($sizefl,33.6); ?><br>
			<?php
			include("inc/bpalm.inc");
		} /// fin accès privé
  }
}
?>
