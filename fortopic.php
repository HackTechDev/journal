<?php
/*
    Forum Topics - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v1.8 (05 February 2003)  : initial release
      v2.0 (27 February 2003)  : added encryption of webmaster's e-mail @ (SPAM protection)
      v2.1 (10 March 2003)     : added addslashes() to var in Javascript functions (to avoid errors)
      v2.2 (22 April 2003)     : no change
      v2.3 (27 July 2003)      : upgraded WriteMailTo() function for better SPAM protection (thanks Michel)
      v2.4 (24 September 2003) : added section icon in central boxes
                                 added GetCurrentDateTime() and FormatDate() function to ease various date and time formatings
                                 upgraded forum indexes for a smaller size
      v3.0 (25 February 2004)  : added link to Forum Archive
      v4.0 (06 December 2004)  : added page title (by Jean-Mi)
                                 modified bgcolor and look (by Icare)
                                 added alt tags to img and removed border tag for non-linked img, added the forum style management (by Isa)
                                 added optionnal quick admin (by Nicolas Alves)
      v4.6.0 (04 June 2007)    : new table organization, added optionnal page width, extended quick admin to writers,
                                 added icons legend and optionnal forum charter (by Icare)
      v4.6.1 (02 July 2007)    : added missing link towards last message when author's email hidden (by Icare)
      v4.6.6 (14 April 2008)   : added urlencode to WriteMailTo() (by JeanMi)
      v4.6.8 (24 May 2008)     : optimized display (by Icare)
      v4.6.10 (7 September 2009)  : corrected #274
      v4.6.11 (11 December 2009)  : corrected #307
      v4.6.15 (30 June 2011)      : added private forum management (by Icare)
      v4.6.16 (02 September 2011) : corrected display (by Laroche)
      v4.6.22 (29 December 2012)  : added pseudo-private group for members (by Saxbar)
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");

if ($serviz[13] != "on" || $serviz[18] != "on") {
  exit($web143);
}

$dbwork = ReadDBFields(DBFORUMCAT);
$dbworkcat = ReadDBFields(DBFORUM);
for ($i = 0; $i < count($dbwork); $i++) {
  $dbcat[$i][0] = $dbwork[$i][3]; //titre fr
  $dbcat[$i][1] = $dbwork[$i][4]; //titre en
  $dbwork[$i][3] = 0;
  $dbwork[$i][4] = 0;
  $prcat = explode(',', $dbwork[$i][0]);
  for ($j = 0; $j < count($dbworkcat); $j++) {
    if ($dbworkcat[$j][12] == $prcat[0]) {
      $dbwork[$i][3]++;
      $dbwork[$i][4] = $dbwork[$i][4] + $dbworkcat[$j][7] + 1;
      if (empty($dbwork[$i][5])) {
        if (!empty($dbworkcat[$j][8])) {
          $dbwork[$i][5] = $dbworkcat[$j][8]; //pseudo rep ou rien
          if ($dbworkcat[$j][11] != "on") {
            $dbwork[$i][6] = $dbworkcat[$j][9]; // mail rep
          }
          else {
            $dbwork[$i][6] = "";
          }
          $dbwork[$i][7] = $dbworkcat[$j][0]; //date forum
        }
        else {
          $dbwork[$i][5] = $dbworkcat[$j][3]; // pseudo auteur
          if ($dbworkcat[$j][10] != "on") {
            $dbwork[$i][6] = $dbworkcat[$j][4]; //mail auteur
          }
          else {
            $dbwork[$i][6] = "";
          }
          $dbwork[$i][7] = $dbworkcat[$j][0]; // date forum
        }
        $dbwork[$i][8] = $dbworkcat[$j][1]; // n° sujet
        $dbwork[$i][9] = $dbworkcat[$j][7]; // nb rep
        $dbwork[$i][10] = (ceil($dbworkcat[$j][7]/ $serviz[20]));
        $dbwork[$i][11] = $dbworkcat[$j][2]; // id doc
        $dbwork[$i][12] = $dbworkcat[$j][12]; // n° cat
      }
    }
  }
}
  unset($dbworkcat);
if ($lng == $lang[0]) {
  $k = 0;
}
else {
  $k = 1;
}
$topmess = strip_tags($nom[$k+22]);
if ($page[9] != "") {
  $topmess = "<img src=\"".CHEMIN."inc/img/icons/".$page[9]."/forum.gif\" align=\"right\" width=\"32\" height=\"32\" alt=\"forum.gif\" />".$topmess;
}
if ($userprefs[3] =="" || $userprefs[3] == "LR") $userprefs[3] = "L";
$widepage = $forum[3];
$forumname = $nom[$k+22];
include("inc/hpage.inc");
if ($lng == $lang[0]) {
  $k = 0;
}
else {
  $k = 1;
}
htable($topmess, "100%");
if ($members[0]=="on" && $userprefs[1]=="" && $members[5]=="on") {
  echo "<p align=\"center\">".$web342."</p><br />";
  echo "<p align=\"center\">[<a href=\"".CHEMIN."user.php?lng=".$lng."\">".$web343."</a>]</p><br />";
}
else {
  $archdate = ReadCounter(DBFORUMARCHDATE);
  if ($archdate > 0) {
    ?>
    <p align="center"><?php echo $web228." ".FormatDate($archdate); ?>.<br />
    <?php echo $web227; ?> <a href="fortopicarch.php?lng=<?php echo $lng; ?>"><?php echo $web226; ?></a>.<br /><br /></p>
    <?php
  }
  echo '<div align="center" style="width:100%;text-align:center;margin:8px 0;">';
  if ($forum[3] == "on") include("inc/topforum.inc");
  if (!empty($dbwork)) {
    ?>
    <center>
    <br />
    <table class="bord" cellspacing="1" cellpadding="4" align="center" width="100%" border="0" summary="">
    <tr class="forum2" style="height:32px;text-align:center">
    <td colspan="2"><?php echo $web130; ?></td>
    <td style="width:20%"><?php echo $web131; ?></td>
    <td style="width:20%"><?php echo $web132; ?></td>
    <td style="width:20%"><?php echo $web133; ?></td></tr>
    <?php
	$ii = 1 ;
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
      if ($acces == "ok"){
	  $ii++ ;
      if ($ii %2 == 0) {$color="rep";} else {$color="quest";}
      ?>
      <tr class="<?php echo $color; ?>" align="center">
      <td width="26"><img src="<?php echo CHEMIN ?>inc/img/general/msg_a.gif" style="vertical-align:middle" alt="<?php echo $web367; ?>" title="<?php echo $web367; ?>" /></td>
      <td style="text-align:left">
      <?php
      echo '<a href="forum.php?lng='.$lng.'&amp;cat='.$prcat[0].'" title="'.$dbwork[$i][1].'"><b>'.$dbwork[$i][1+$k].'</b></a><br />'."\n";
      echo ($lng == $lang[0]) ? "<i>".$dbcat[$i][0]."</i>" : "<i>".$dbcat[$i][1]."</i>" ; 
      /// fin modif forum privé
      echo "</td>";
      ?>
      <td style="text-align:center"><?php echo $dbwork[$i][3]; ?></td>
      <td style="text-align:center"><?php echo $dbwork[$i][4]; ?></td>
      <td>
      <?php
	  }
      if ($acces == "ok"){  /// debut modif forum privé
        if ($dbwork[$i][6] != "") {
          echo $web6." ";
          $em = BreakEMail($dbwork[$i][6]);
          ?>
          <b><a href="JavaScript:WriteMailTo('<?php echo addslashes(urlencode($dbwork[$i][5])); ?>','<?php echo $em[0]; ?>','<?php echo $em[1]; ?>','<?php echo $em[2]; ?>')"><?php echo addslashes($dbwork[$i][5]); ?></a></b>
          <?php
          echo "<a href=\"thread.php?lng=".$lng."&amp;pg=".$dbwork[$i][11]."&amp;id=".$dbwork[$i][10]."&amp;cat=".$dbwork[$i][12]."#".$dbwork[$i][9]."\" title =\"".$web297."\">
         &nbsp;<img src='".CHEMIN."inc/img/general/tolist.gif' border='0' alt='".$web297."' /></a>";
        } elseif ($dbwork[$i][5] != "") { //pseudo
          echo $web6." <b>".$dbwork[$i][5]."</b>";
          echo "<a href=\"thread.php?lng=".$lng."&amp;pg=".$dbwork[$i][11]."&amp;id=".$dbwork[$i][10]."&amp;cat=".$dbwork[$i][12]."#".$dbwork[$i][9]."\" title =\"".$web297."\">
        &nbsp;<img src='".CHEMIN."inc/img/general/tolist.gif' border='0' alt='".$web297."' /></a>";
        }
        if ($dbwork[$i][7] != "") { //date si rep
          $top="";
          $dbth = array();
          $dbth = ReadDBFields(DBTHREAD);
          for ($l = 0; $l < count($dbth); $l++) {
            if ($dbth[$l][1] == $dbwork[$i][8] && $dbth[$l][2] == $dbwork[$i][9]) {
              //$lastdate = $dbth[$l][0];
              $idth = $dbth[$l][3];
              break;
            }
          }
          ReadDoc(DBBASE.$idth);
          $lastdate = $creadate;
          echo "<br />".$web7." ".FormatDate($lastdate);
        }
      } /// fin modif forum privé 
      echo "</td></tr>";
    }
    ?>
    </table>
   <div align="center" class="bord" style="width:auto;padding:6px 4px 0px;margin:8px auto;text-align:left;vertical-align:middle;">
    <?php
    if ($forum[9] =="on") {
      echo "<br /><p class='titre' style='text-align:center;text-transform:uppercase;'><u>".$web409."</u></p><br />";
      echo "<div style='margin:5px 40px; height:300px; overflow:auto;'>";
      include(CHEMIN.DATAREP.TYP_RULES.INCEXT);
      if ($lng == $lang[0]) {
        echo $rule1;
      }
      else {
        echo $rule2;
      }
      echo "<hr /></div>";
      if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32] == "on" && $drtuser[24] == "on")) {
				echo '<div align="right" style="cursor:pointer;">';
        echo '<a href="'.CHEMIN.'admin/admin.php?lng='.$lng.'&amp;pg=rules"><img src="'.CHEMIN.'inc/img/general/edit.gif" border="0" alt="'.$web308.'" title="'.$web308.'" /></a>';
				echo '</div>'."\n";
      }
    }
    ?>
    <p class="titre" style="text-align:center; text-decoration:underline;"><?php echo $web410; ?></p><br />
    <p><?php echo "<b>".$web411."</b><br />"; ?>
    <img src="<?php echo CHEMIN ?>inc/img/general/msg_a.gif" style="vertical-align:-4px" alt= "<?php echo $web367; ?>" /> <?php echo $web366.$web367; ?> &nbsp;
    <img src="<?php echo CHEMIN ?>inc/img/general/msg_c.gif" style="vertical-align:-4px" alt= "<?php echo $web368; ?>" /> <?php echo $web366.$web368; ?> &nbsp;
    <img src="<?php echo CHEMIN ?>inc/img/general/msg_t.gif" style="vertical-align:-4px" alt= "<?php echo $web370; ?>" /> <?php echo $web370; ?> &nbsp;
    <img src="<?php echo CHEMIN ?>inc/img/general/msg_n.gif" style="vertical-align:-4px" alt= "<?php echo $web371; ?>" /> <?php echo $web371.$web334; ?> <br /><br />
    <?php echo $web412."<br />"; ?>
    <img src="<?php echo CHEMIN ?>inc/img/general/edit.gif" style="vertical-align:-1px" alt= "<?php echo $web369; ?>" /> <?php echo $web369." ".$web334; ?> &nbsp;
    <img src="<?php echo CHEMIN ?>inc/img/general/lock.gif" style="vertical-align:-1px" alt= "<?php echo $web363; ?>" /> <?php echo $web363.$web366; ?> &nbsp;
    <img src="<?php echo CHEMIN ?>inc/img/general/lockup.gif" style="vertical-align:-1px" alt= "<?php echo $web364; ?>" /> <?php echo $web364.$web366; ?><br /><br /></p>
  </div>
  </center>
    <?php
  }
  echo "</div>";
}
btable();
include("inc/bpage.inc");
?>
