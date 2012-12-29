<?php
/*
    Forum for PDA - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v2.3 (27 July 2003)        : initial release (thanks Palmipod)
      v2.4 (24 September 2003)   : added number of times a forum thread was read (by Nicolas Alves and Laurent Duveau)
                                   added ReadDocCounter() and WriteDocCounter() functions
                                   added GetCurrentDateTime() and FormatDate() function to ease various date and time formatings
                                   reviewed all Files Read & Write functions
                                   secured transfered parameters
                                   upgraded forum indexes for a smaller size
      v3.0 (25 February 2004)    : date format display fix (by B@lou)
      v4.0 (06 December 2004)    : modified page title (by Jean-Mi)
      v4.6.17 (21 October 2011)  : added private management (by Saxbar)
      v4.6.18 (09 February 2012) : corrected private management (by Saxbar)
      v4.6.22 (29 December 2012) : added pseudo-private group for members (by Saxbar) 	  
*/

header("Pragma: no-cache");
define("CHEMIN", "../");
include CHEMIN."inc/includes.inc";
include_once CHEMIN.'inc/func_groups.php';

if ($serviz[13] != "on") {
  exit($web143);
}

$section_index = 5;
$section_name = $lng == $lang[0] ? $nom[22] : $nom[23];
include('inc/members.inc');
if ($section_access) {

    $pg = strip_tags($pg);
    $cat = strip_tags($cat);
    $id = strip_tags($id);

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

    function SelectDBForumByCat($Fields,$ct) {
      $DataDB = array();
      $k = 0;
      for ($i = 0; $i < count($Fields); $i++) {
        if ($Fields[$i][12] == $ct) {
          for ($j = 0 ; $j < count($Fields[$i]); $j++) {
            $DataDB[$k][$j] = $Fields[$i][$j];
          }
          $k++;
        }
      }
      return $DataDB;
    }

	/// début modif accès privé
	$dbwork = array();
    if (!empty($pg)) {
      $dbw = SelectDBForumByID(ReadDBFields(DBFORUM),$pg);
    }
    elseif (!empty($cat)) {
      $dbw = SelectDBForumByCat(ReadDBFields(DBFORUM),$cat);
    }
    else {
      $dbw = ReadDBFields(DBFORUM);
    }
	
	foreach ($dbw as $item) {
      $acces = 'ok';
	  if (IsPrivateForumCat($item[12])) {
        $acces = "no";
        if ($userprefs[1] != '') {    
          if (CheckGroup($item[12], $userprefs[1])) $acces = 'ok';
        }
      }
	  if ($acces == 'ok') $dbwork[] = $item;
    }
	/// fin modif accès privé

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
    include("inc/hpalm.inc");
    if ($lng == $lang[0]) {
      $i = 0;
    }
    else {
      $i = 1;
    }
    if ($serviz[18] != "on") {
    	if (!empty($catxt)) {
        echo "<center><b>".$nom[$i+22]." - ".$catxt."</b></center><hr />";
      }
      else {
        echo "<center><b>".$nom[$i+22]."</b></center><hr />";
      }
    }
    else {
    	if (!empty($catxt)) {
        echo "<center><b>"."<a href=\"fortopic.php?lng=".$lng."\">".$nom[$i+22]."</a> - ".$catxt."</b></center><hr />";
      }
      else {
        echo "<center><b>"."<a href=\"fortopic.php?lng=".$lng."\">".$nom[$i+22]."</a>"."</b></center><hr />";
      }
    }
    if (empty($id)) {
      $id = 1;
    }
    if (!empty($dbwork)) {
			/// début modif accès privé
			$dbworkcat = ReadDBFields(DBFORUMCAT);
      for ($i = $serviz[17]*($id-1); $i < Min($serviz[17]*$id, count($dbwork)); $i++) {
				$acces = "no";
				for ($j=0; $j<count($dbworkcat); $j++) {
					$prcat = explode(',', $dbworkcat[$j][0]);
					if ($prcat[0] == $dbwork[$i][12]) {
						$acces = "ok";
						break;
					}
				}
				if ($acces == "ok") {
				/// fin modif accès privé
					if ($serviz[34] == "on") {
						$threadcounter = ReadDocCounter(DBBASE.$dbwork[$i][2]);
					}
					?>
					<a href="thread.php?lng=<?php echo $lng; ?>&pg=<?php echo $dbwork[$i][2]; ?>&fid=<?php echo $id; if (!empty($cat)) {echo "&cat=".$cat;} ?>"><?php echo $web63.$dbwork[$i][1]; ?></a>&nbsp;-&nbsp;
					<a href="thread.php?lng=<?php echo $lng; ?>&pg=<?php echo $dbwork[$i][2]; ?>&fid=<?php echo $id; if (!empty($cat)) {echo "&cat=".$cat;} ?>"><b><?php echo $dbwork[$i][5]; ?></b></a>
					<br>&nbsp;&nbsp;&nbsp;&nbsp;-&nbsp;
					<?php
					echo $web6." ";
					echo "<b>".$dbwork[$i][3]."</b>";
					echo " ".$web7." ".FormatDate($dbwork[$i][6]);
					if ($dbwork[$i][7] != 0) {
						$formail = "<b>".$dbwork[$i][8]."</b>";
						if ($dbwork[$i][7] == 1) {
							?>
							<br>&nbsp;&nbsp;&nbsp;&nbsp;-&nbsp;<?php echo $web93." ".$formail." ".$web94." ".FormatDate($dbwork[$i][0]).")"; ?>
							<?php
						}	else {
							?>
							<br>&nbsp;&nbsp;&nbsp;&nbsp;-&nbsp;<?php echo $dbwork[$i][7]." ".$web66." ".$formail." ".$web94." ".FormatDate($dbwork[$i][0]).")"; ?>
							<?php
						}
					}	else {
						?>
						<br>&nbsp;&nbsp;&nbsp;&nbsp;-&nbsp;<?php echo $web67; ?>
						<?php
					}
					if ($serviz[34] == "on") {
					  if ($threadcounter <= 1) {
							$txtcount = $web188;
						}	else {
							$txtcount = $web189;
						}
						?>
						<br>&nbsp;&nbsp;&nbsp;&nbsp;-&nbsp;<?php echo $web217; ?> <?php echo $threadcounter." ".$txtcount; ?>
						<?php
					}
					?>
					<br>
					<?php
					if ($i < Min($serviz[17]*$id, count($dbwork))-1) {
						echo "<hr />";
					}
		    } /// fin accès privé
      }
    }
    if (count($dbwork)>$serviz[17])
    {
    ?>
    <hr />
    <center>
    <?php
     if ($serviz[18] == "on") {
      if (count($dbwork)>$serviz[17]) {
        echo '<hr />'.GetNavBar("forum.php?lng=".$lng."&amp;id=", count($dbwork), $id, $serviz[17]);
      }
    ?>
    <center>[ <a href="fortopic.php?lng=<?php echo $lng; ?>"><?php echo $web134; ?></a> ]</center>
    <?php
     }
    }
    include("inc/bpalm.inc");
}
?>
