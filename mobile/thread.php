<?php
/*
    Forum Thread for PDA - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v2.3 (27 July 2003)      : initial release (thanks Palmipod)
      v2.4 (24 September 2003) : added number of times a forum thread was read (by Nicolas Alves and Laurent Duveau)
                                 added ReadDoc() function
                                 added ReadDocCounter(), WriteDocCounter() and UpdateDocCounter() functions
                                 added GetCurrentDateTime() and FormatDate() function to ease various date and time formatings
                                 reviewed all Files Read & Write functions
                                 secured transfered parameters
                                 upgraded forum indexes for a smaller size
      v4.0 (06 December 2004)   : modified page title (by Jean-Mi)
      v4.6.17 (21 October 2011) : added private management (by Saxbar)
      v4.6.22 (29 December 2012): added pseudo-private group for members (by Saxbar) 	  
*/

header("Pragma: no-cache");
define("CHEMIN", "../");
include(CHEMIN."inc/includes.inc");

if ($serviz[13] != "on") {
  exit($web143);
}

$section_index = 5;
$section_name = $lng == $lang[0] ? $nom[22] : $nom[23];
include('inc/members.inc');
if ($section_access) {

	$pg = strip_tags($pg);
	$thrd = strip_tags($thrd);
	$cat = strip_tags($cat);
	$id = strip_tags($id);
	$fid = strip_tags($fid);

	function SelectDBThreadByThread($Fields,$id) {
		$DataDB = array();
		$k = 0;
		for ($i = 0; $i < count($Fields); $i++) {
			if ($Fields[$i][1] == $id && $Fields[$i][2] != "0") {
				for ($j = 0 ; $j < count($Fields[$i]); $j++) {
					$DataDB[$k][$j] = $Fields[$i][$j];
				}
				$k++;
			}
		}
		return $DataDB;
	}

	function SelectDBForumByID($Fields,$id) {
		$DataDB = array();
		$k = 0;
		for ($i = 0; $i < count($Fields); $i++) {
			if ($Fields[$i][2] == $id) {
				for ($j = 0 ; $j < count($Fields[$i]); $j++) {
					$DataDB[$k][$j] = $Fields[$i][$j];
				}
				$k++;
			}
		}
		return $DataDB;
	}

	$thread = 0;
	if (!empty($pg)) {
		$dbwork = SelectDBForumByID(ReadDBFields(DBFORUM),$pg);
		if (count($dbwork) != 0) {
			$thread = $dbwork[0][1];
			$cat = $dbwork[$i][12];
		}
	}
	elseif (!empty($thrd)) {
		$dbwork = ReadDBFields(DBTHREAD);
		for ($i = 0; $i < count($dbwork); $i++) {
			if ($dbwork[$i][1] == $thrd && $dbwork[$i][2] == "0") {
				$thread = $thrd;
				$pg = $dbwork[$i][3];
				$cat = $dbwork[$i][8];
			}
		}
	}

	if ($serviz[34] == "on") {
		$threadcounter = UpdateDocCounter($pg);
	}

	$dbthrd = SelectDBThreadByThread(ReadDBFields(DBTHREAD),$thread);
	@sort($dbthrd);

	if (!empty($cat)) {
		$dbworkcat = ReadDBFields(DBFORUMCAT);
		for ($k = 0; $k < count($dbworkcat); $k++) {
			$prcat = explode(',', $dbworkcat[$k][0]);
			if ($prcat[0] == $cat) {
				if ($lng == $lang[0]) {
					$topmess = $nom[22];
					if (!empty($dbworkcat[$k][1])) $topmess .= " - ".$dbworkcat[$k][1];
				} else {
					$topmess = $nom[23];
					if (!empty($dbworkcat[$k][2])) $topmess .= " - ".$dbworkcat[$k][2];
				}
				break;
			}
		}
	} 
	else {
		$dbwork = ReadDBFields(DBTHREAD);
		for ($i = 0; $i < count($dbwork); $i++) {
			if ($pg == $dbwork[$i][3]) {
				$cat = $dbwork[$i][8];
				break;
			}
		}
	}
	ReadDoc(DBBASE.$pg);
	
	/// début modif accès privé
	$acces ="ok";
	if (preg_match('/^pr/i', $cat)) {
		$acces = "no";
		if ($userprefs[1] != "") {
			include_once (CHEMIN.'inc/func_groups.php');
			if (CheckGroup($cat, $userprefs[1])) $acces ="ok";
		}
	}
	if ($acces == "ok") {
	/// fin modif accès privé
		
    $topmess .= " - ".$web63.$fielda1;
    include("inc/hpalm.inc");
    if ($lng == $lang[0]) {
      $i = 0;
    }
    else {
      $i = 1;
    }

    if ($serviz[18] != "on") {
      echo "<center><b>"."<a href=\"forum.php?lng=".$lng."&id=".$fid."\">".$nom[$i+22]."</a> - ".$web63.$fielda1."</b></center><hr />";
    }
    else {
    	if (!empty($catxt)) {
        echo "<center><b>"."<a href=\"fortopic.php?lng=".$lng."\">".$nom[$i+22]."</a> - <a href=\"forum.php?lng=".$lng."&id=".$fid."&cat=".$cat."\">".$catxt."</a> - ".$web63.$fielda1."</b></center><hr />";
      }
      else {
        echo "<center><b>"."<a href=\"fortopic.php?lng=".$lng."\">".$nom[$i+22]."</a> - ".$web63.$fielda1."</b></center><hr />";
      }
    }
    ?>
    <b><?php echo $web63.$fielda1; ?>&nbsp;</b>&nbsp;-&nbsp;
    <b><?php echo $fieldb1; ?></b>
    <br>&nbsp;&nbsp;&nbsp;&nbsp;-&nbsp;
    <?php
    echo $web6." ";
    echo "<b>".$author."</b>";
    echo " ".$web7." ".FormatDate($creadate);
    ?>
    <br><br><?php echo PathToImage($fieldc1); ?><br><hr />
    <?php
    if (empty($id)) {
      $id = 1;
    }
    if (!empty($dbthrd)) {
      for ($i = $serviz[20]*($id-1); $i < Min($serviz[20]*$id, count($dbthrd)); $i++) {
        ReadDoc(DBBASE.$dbthrd[$i][3]);
        echo $web68.$fielda2;
    ?>
    <br>&nbsp;&nbsp;&nbsp;&nbsp;-&nbsp;
    <?php
        echo $web6." ";
        echo "<b>".$author."</b>";
        echo " ".$web7." ".FormatDate($creadate);
    ?>
    <br><br><?php echo PathToImage($fieldc1); ?><br><hr />
    <?php
     }
      }
       if (count($dbthrd)>$serviz[20])
      {
      echo GetNavBar("thread.php?lng=".$lng."&amp;cat=".$cat."&amp;pg=".$pg."&amp;id=", count($dbthrd), $id, $serviz[20]);
     }
    ?>
    <center>[ <a href="forum.php?lng=<?php echo $lng; ?>&id=<?php echo $fid; if (!empty($cat)) {echo "&cat=".$cat;} ?>"><?php echo $web70; ?></a> ]</center>
    <?php
    include("inc/bpalm.inc");
	} /// fin accès privé
}
?>
