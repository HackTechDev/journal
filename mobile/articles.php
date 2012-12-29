<?php
/*
    Papers for PDA - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v2.3 (27 July 2003)      : initial release (thanks Palmipod)
      v2.4 (24 September 2003) : added react to an article option
                                 added number of times an article was read (by Nicolas Alves and Laurent Duveau)
                                 added ReadDoc() function
                                 added ReadDocCounter(), WriteDocCounter() and UpdateDocCounter() functions
                                 added GetCurrentDateTime() and FormatDate() function to ease various date and time formatings
                                 reviewed all Files Read & Write functions
                                 secured transfered parameters
                                 created $typ_[name] variables
      v4.0 (06 December 2004)  : added page title (by Jean-Mi)
	  v4.5 (28 April 2005)       : made code w3c compliant (by Icare)
      v4.6.6 (14 April 2008)   : added header("HTTP/1.0 404 Not found") in the event of pages not found (by JeanMi, thanks eDada)
      v4.6.17 (21 October 2011) : added private management (by Saxbar)
*/

header("Pragma: no-cache");
define("CHEMIN", "../");
include(CHEMIN."inc/includes.inc");

if ($serviz[3] != "on" && $serviz[22] != "on") {
  exit($web143);
}

$section_index = 1;
$section_name = $web169;
include('inc/members.inc');
if ($section_access) {

	$pg = strip_tags($pg);
	$prt = strip_tags($prt);
	$id = strip_tags($id);

	if (count(SelectDBFields(TYP_ART,"a",$pg)) == 1) {
		ReadDoc(DBBASE.$pg);
		$countit = 1;
		if ($lng == $lang[0]) {
			$txtart1 = $fieldb1;
			$txtart2 = PathToImage($fieldc1);
			$txtart3 = $fielda1;
		} else {
			$txtart1 = $fieldb2;
			$txtart2 = PathToImage($fieldc2);
			$txtart3 = $fielda2;
		}
		$txtart4 = FormatDate($moddate);
		$txtart5 = FormatDate($creadate);
		$txtart6 = $fieldmod;
	} else {
		$countit = 0;
		$txtart1 = $web35;
		$txtart2 = $web36;
		$txtart3 = $web37;
		$txtart4 = $web37;
		$txtart5 = $web37;
		$txtart6 = "";
		header('HTTP/1.0 404 Not Found');
	}

	/// début modif accès privé
	$acces ="ok";
	if ($txtart6 != "") {
		$acces = "no";
		if ($userprefs[1] != "") {
			include_once (CHEMIN.'inc/func_groups.php');
			if (CheckGroup($txtart6, $userprefs[1])) $acces ="ok";
		}
	}
	if ($acces == "ok") {
	/// fin modif accès privé
	
    $topmess = $txtart1;
    include("inc/hpalm.inc");
    echo "<center><b>".$txtart1."</b></center><hr />";
    echo $txtart2."<hr />";
    echo $web95." ".$txtart5."<br>";
    echo $web20." ".$txtart4."<br>";
    echo $web21." ".$txtart3."<br>";
    if ($serviz[33] == "on" && $countit == 1) {
      $artcounter = UpdateDocCounter($pg);
      if ($artcounter <= 1) {
        $txtcount = $web188;
      }
      else {
        $txtcount = $web189;
      }
      echo $web190." ".$artcounter." ".$txtcount."<br>";
    }
    if ($serviz[29] == "on" && $countit == 1) {
      $dbreaction = ReadDBFields(DBREACT);
      for ($i = 0; $i < count($dbreaction); $i++) {
        if ($dbreaction[$i][1] == $pg) {
          $dbwork[] = $dbreaction[$i][0];
        }
      }
      @rsort($dbwork);
      echo "<hr /><center><b>".$web184."</b></center><hr />";
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
      }
      else {
        echo $web186."<br>";
      }
      if (count($dbwork)>$serviz[30])
      {
      echo '<hr />'.GetNavBar("articles.php?lng=".$lng."&amp;pg=".$pg."&amp;id=", count($dbwork), $id, $serviz[30]);  $idp = $id-1;
      }
    }
    include("inc/bpalm.inc");
	} /// fin accès privé
}
?>
