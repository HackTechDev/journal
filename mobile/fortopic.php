<?php
/*
    Forum Topics for PDA - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v2.3 (27 July 2003)       : initial release (thanks Palmipod)
      v2.4 (24 September 2003)  : added GetCurrentDateTime() and FormatDate() function to ease various date and time formatings
                                  upgraded forum indexes for a smaller size
      v4.0 (06 December 2004)   : added page title (by Jean-Mi)
      v4.6.17 (21 October 2011) : added private management (by Saxbar)
      v4.6.22 (29 December 2012): added pseudo-private group for members (by Saxbar)
*/

header("Pragma: no-cache");
define("CHEMIN", "../");
include(CHEMIN."inc/includes.inc");

if ($serviz[13] != "on" || $serviz[18] != "on") {
  exit($web143);
}

$section_index = 5;
$section_name = $lng == $lang[0] ? $nom[22] : $nom[23];
include('inc/members.inc');
if ($section_access) {

	$dbwork = ReadDBFields(DBFORUMCAT);
	$dbworkcat = ReadDBFields(DBFORUM);
	for ($i = 0; $i < count($dbwork); $i++) {
	    $prcat = explode(',', $dbwork[$i][0]);
	    if (empty($prcat[1])) $prcat[1] = '';
        /// début modif forum privé
        $acces ="ok";
        if (!empty($prcat[1])) {
          $acces = "no";
          if ($userprefs[1] != "") {
            include_once (CHEMIN.'inc/func_groups.php');
            if (CheckGroup($prcat[1], $userprefs[1])) $acces ="ok";
          }
        }
		$dbwork[$i][8] = $acces;
		if ($acces == "ok") {
		/// fin modif accès privé
			$dbwork[$i][0] = $prcat[0];
			$dbwork[$i][3] = 0;
			$dbwork[$i][4] = 0;
			for ($j = 0; $j < count($dbworkcat); $j++) {
				if ($dbworkcat[$j][12] == $prcat[0]) {
					$dbwork[$i][3]++;
					$dbwork[$i][4] = $dbwork[$i][4] + $dbworkcat[$j][7] + 1;
					if (empty($dbwork[$i][5])) {
						if (!empty($dbworkcat[$j][8])) {
							$dbwork[$i][5] = $dbworkcat[$j][8];
							if ($dbworkcat[$j][11] != "on") {
								$dbwork[$i][6] = $dbworkcat[$j][9];
							}
							else {
								$dbwork[$i][6] = "";
							}
							$dbwork[$i][7] = $dbworkcat[$j][0];
						}
						else {
							$dbwork[$i][5] = $dbworkcat[$j][3];
							if ($dbworkcat[$j][10] != "on") {
								$dbwork[$i][6] = $dbworkcat[$j][4];
							}
							else {
								$dbwork[$i][6] = "";
							}
							$dbwork[$i][7] = $dbworkcat[$j][0];
						}
					}
				}
			}
		} /// fin accès privé
	}

	if ($lng == $lang[0]) {
		$topmess = $nom[22];
	} else {
		$topmess = $nom[23];
	}
	include("inc/hpalm.inc");
	if ($lng == $lang[0]) {
		$k = 0;
	}	else {
		$k = 1;
	}
	echo "<center><b>".$nom[$k+22]."</b></center><hr />";
	if (!empty($dbwork)) {
		for ($i = 0; $i < count($dbwork); $i++) {
			/// début modif accès privé
			if ($dbwork[$i][8] == "ok") {
			/// fin modif accès privé
				?>
				<a href="forum.php?lng=<?php echo $lng; ?>&cat=<?php echo $dbwork[$i][0]; ?>"><b><?php echo $dbwork[$i][1+$k]; ?></b></a><br>
				&nbsp;&nbsp;<?php echo $web131." : ".$dbwork[$i][3]; ?><br>
				&nbsp;&nbsp;<?php echo $web132." : ".$dbwork[$i][4]; ?><br>
				&nbsp;&nbsp;<?php echo $web133." : "; ?>
				<?php
				if ($dbwork[$i][5] != "") {
					echo $web6." <b>".$dbwork[$i][5]."</b> ";
				}
				if ($dbwork[$i][7] != "") {
					echo $web7." ".FormatDate($dbwork[$i][7]);
				}
				echo "<br>";
			} /// fin accès privé
		}
	}

	include("inc/bpalm.inc");
}
?>
