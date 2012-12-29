<?php
/*
    Forum - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.2 (05 January 2003)   : created databases thread.dtb and forum.dtb for quicker display of forum threads
      v1.6 (23 January 2003)   : display 10 forum messages rather than 5
                                 added option to hide on the site the e-mail address of poster
      v1.7 (28 January 2003)   : corrected a forum bug the m returned value was false in version 1.6
      v1.8 (05 February 2003)  : added forum category management
      v2.0 (27 February 2003)  : added links to jump back in thread and forum (by Alex)
      v2.1 (10 March 2003)     : added addslashes() to var in Javascript functions (to avoid errors)
      v2.2 (22 April 2003)     : option for choosing the number of items to display in news, forum threads, links, downloads, FAQ and Guestbook
                                 replaced <P><CENTER> by <P align="center"> otherwise IE takes the default font instead of the required one (Thanks Michel)
                                 cleanup in the images organization
      v2.3 (27 July 2003)      : added direct jump to pages (by Nicolas Alves and Laurent Duveau)
                                 upgraded WriteMailTo() function for better SPAM protection (thanks Michel)
      v2.4 (24 September 2003) : added section icon in central boxes
                                 added number of times a forum thread was read (by Nicolas Alves and Laurent Duveau)
                                 added ReadDocCounter(), WriteDocCounter() and UpdateDocCounter() functions
                                 added GetCurrentDateTime() and FormatDate() function to ease various date and time formatings
                                 reviewed all Files Read & Write functions
                                 secured transfered parameters
                                 created $typ_[name] variables
                                 upgraded forum indexes for a smaller size
      v3.0 (25 February 2004)  : added link to Forum Archive
      v4.0 (06 December 2004)  : added page title (by Jean-Mi)
                                 added background-colors, new appearance and img buttons (by Icare)
                                 added alt tags to img and removed border tag for non-linked img,
                                 added the forum style management, replaced & by &amp; for W3C compliance (by Isa)
                                 added new navigation, avatars, optionnal quick admin and Read last msg (by Nicolas Alves)
      v4.5 (30 March 2005)     : replacing navigation bar (by Jean-Mi)
      v4.6.0 (04 June 2007)    : added state column: open closed or on top, added new bottom line (by Icare)
      v4.6.1 (02 July 2007)    : added missing link towards last message when author's email hidden (by Icare)
      v4.6.5 (05 December 2007): added navbar in top of forum, corrected end of test counter that was not at the good place,
                                 now column topic read is not displayed when counter is disabled (by Icare)
      v4.6.6 (14 April 2008)   : corrected date for thread on top and new (by Icare)
                                 added urlencode in WriteMailTo() (by JeanMi)
      v4.6.10 (7 September 2009)  : corrected #274
      v4.6.11 (11 December 2009)  : corrected #307
      v4.6.15 (30 June 2011)      : added private forum management (by Icare)
      v4.6.16 (02 September 2011) : corrected private management (by jchouix, Laroche, Pascal31)
	                                div style display shell correction (thanks Jean-Mi)
      v4.6.17 (21 October 2011)   : test a class if the private groups are activated (by Laroche)
      v4.6.22 (29 December 2012)  : added pseudo-private group for members (by Saxbar)	  
 */

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");
include_once (CHEMIN.'inc/func_groups.php');  // déplacé

if ($serviz[13] != "on") {
  exit($web143);
}
$pg = strip_tags($pg);
$cat = strip_tags($cat);
$id = strip_tags($id);

if ((CheckGroup($cat, $userprefs[1]) != 1) && (!is_numeric($cat) && $serviz[18] != '' )) { 
	header("location:index.php");
	die();
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

if (!empty($pg)) {
  $dbwork = SelectDBForumByID(ReadDBFields(DBFORUM),$pg);
  if (count($dbwork) == 0) {
    $dbwork = array();
  }
}
elseif (!empty($cat)) {
  $dbwork = SelectDBForumByCat(ReadDBFields(DBFORUM),$cat);
}
else {
  $dbwork = ReadDBFields(DBFORUM);
}
if ($lng == $lang[0]) {
  $i = 0;
}
else {
  $i = 1;
}
if ($serviz[18] != "on") {
  if (!empty($cat)) {
    $dbworkcat = ReadDBFields(DBFORUMCAT);
    for ($k = 0; $k < count($dbworkcat); $k++) {
	  $prcat = explode(',', $dbworkcat[$k][0]);
      if ($prcat[0] == $cat) {
        $catxt = $dbworkcat[$k][1+$i];
      }
    }
    $topmess = strip_tags($nom[$i+22])." - ".$catxt;
  }
  else {
    $topmess = strip_tags($nom[$i+22]);
  }
}
else {
  if (!empty($cat)) {
    $dbworkcat = ReadDBFields(DBFORUMCAT);
    for ($k = 0; $k < count($dbworkcat); $k++) {
	  $prcat = explode(',', $dbworkcat[$k][0]);
      if ($prcat[0] == $cat) {
        $catxt = $dbworkcat[$k][1+$i];
      }
    }
    $topmess = "<a href=\"fortopic.php?lng=".$lng."\">".$nom[$i+22]."</a> - ".$catxt;
  }
  else {
    $topmess = "<a href=\"fortopic.php?lng=".$lng."\">".$nom[$i+22]."</a>";
  }
}
if ($page[9] != "") {
  $topmess = "<img src=\"".CHEMIN."inc/img/icons/".$page[9]."/forum.gif\" align=\"right\" width=\"32\" height=\"32\" alt=\"forum.gif\"/>".$topmess;
}

if ($userprefs[3] =="" || $userprefs[3] == "LR") $userprefs[3] = "L";
$widepage = $forum[3];
$forumname = strip_tags($nom[$i+22]);

include("inc/hpage.inc");
htable($topmess, "100%");
echo "<br />";
if ($members[0]=="on" && $userprefs[1]=="" && $members[5]=="on") {
  echo "<p align=\"center\">".$web342."</p><br />";
  echo "<p align=\"center\">[ <a href=\"".CHEMIN."user.php?lng=".$lng."\">".$web343."</a> ]</p><br />";
}
else {
  /// debut modif accès privé
  $acces = "";  
  if (IsValidForumCat($cat)) {
	$acces = "ok"; 
  }
  
  if (IsPrivateForumCat($cat)) {
    $acces = "no";
    if ($userprefs[1] != "") {    
        if (CheckGroup($cat, $userprefs[1])) $acces ="ok";
    }
  }
  if ($acces == "no") {
    echo "<p style='text-align:center;font-weight:bold;padding-bottom:48px;'><br />".$web443."</strong><br /></p>";
  } else {
/// fin modif accès privé
  if ($serviz[18] != "on") {
    $archdate = ReadCounter(DBFORUMARCHDATE);
    if ($archdate > 0) {
      ?>
      <p align="center"><?php echo $web228." ".FormatDate($archdate); ?>.<br />
      <?php echo $web227; ?> <a href="forumarch.php?lng=<?php echo $lng ?>"><?php echo $web226 ?></a>.<br /></p>
      <?php
    }
  }
  if ($forum[3] == "on") include("inc/topforum.inc");

  echo "<table align='center' style='width:100%;' summary=''><tr><td style='text-align:left;width:50%;'>";
  if ($forum[9] == "on") {
    echo '<span style="font-weight:bold;"><a href="javascript:PopupWindow(\'rules.php?lng='.$lng.'\',\'rules\',800,500,\'yes\',\'yes\');" title="'.$web409.'">';
    echo "<img src=\"".CHEMIN."inc/img/general/charte.gif\" border=\"0\" alt=\"".$web409."\"/> - ".$web409."</a></span><br />";
  }
  $title = "<span style='font-weight:bold;'><a href=\"fortopic.php?lng=".$lng."\" title=\"".$forumname."\"><img src=\"".CHEMIN."inc/img/general/dir.gif\" border=\"0\" style=\"vertical-align:middle\" alt=\"".$forumname."\"/> - ".$forumname."</a></span><br />";
  if ($catxt != ""){
  echo $title."<span style='margin-left:28px; font-weight:bold;'><img src=\"".CHEMIN."inc/img/general/dir1.gif\" style=\"vertical-align:middle\" alt=\"".$catxt."\" title=\"".$catxt."\"/> - ".$catxt."</span>";
  }
  echo "</td><td style='text-align:right;width:50%;'>";
  ?>
  <form action="<?php echo CHEMIN ?>postguest.php?lng=<?php echo $lng."&amp;typ=".TYP_FORUM; if (!empty($cat)) { echo "&amp;cat=".$cat; } ?>" method="post">
  <p align="right"><img src="<?php echo CHEMIN; ?>inc/img/general/b_post.gif" alt="[" style="vertical-align:top;" /><button type="submit" style="background:transparent url(<?php echo CHEMIN; ?>inc/img/general/b_ton.gif) repeat-x;border:none;height:22px;margin:0px;cursor:pointer;" title="<?php echo $web19; ?>"><?php echo $web19; ?></button><img src="<?php echo CHEMIN; ?>inc/img/general/b_right.gif" alt="]" style="vertical-align:top;" /></p>
  </form>
  <?php
  echo "</td>";
  echo "</tr></table>";
  if (empty($id)) {
    $id = 1;
  }
  echo GetNavBar("forum.php?lng=".$lng."&amp;cat=".$cat."&amp;id=", count($dbwork), $id, $serviz[17]);

  ?>
  <center>
  <table cellspacing="1" cellpadding="5" class="bord" width="100%" summary="">
  <tr class="forum2" style="height:32px;text-align:center">
  <td width="30%"><?php echo $web298; ?></td>
  <td width="10%"><?php echo $web63; ?></td>
  <td width="20%"><?php echo $web299; ?></td>
  <?php
  if ($serviz[34] == "on") {
  echo "<td width='10%'>".$web217."</td>\n";
  }
  ?>
  <td width="10%"><?php echo $web67 ?></td>
  <td width="20%"><?php echo $web66 ?></td>
  </tr>
  <?php
  if (!empty($dbwork)) {
    $newdate = date("YmdHi",time()-(86400*$forum[8])); // d?i pour nouveau
    for ($i = $serviz[17]*($id-1); $i < Min($serviz[17]*$id, count($dbwork)); $i++) {
      if ($i %2 == 0) {$color="rep";}  else {$color="quest";}
      if ($serviz[34] == "on") {
        $threadcounter = ReadDocCounter(DBBASE.$dbwork[$i][2]);
      }
      ReadDoc(DBBASE.$dbwork[$i][2]);
      $st = explode("#",$fieldmod);
      if ($st[0] == "c") $etat = $web368." ".$web6." ".$st[1]." ".$web7." ".FormatDate($st[2]);
      elseif ($st[0] == "s") {$st[0] = "c"; $etat = $web368." ".$web6." ".$st[1]." ".$web7." ".FormatDate($st[2]);}
      elseif ($st[0] == "t" && $moddate > date("YmdHi")) $etat = "Top ".$web6." ".$st[1];
      elseif ($st[0] == "u" && $moddate > date("YmdHi")) {$st[0] = "t"; $etat = "Up ".$web6." ".$st[1]." ".$web7." ".FormatDate($st[2]);}
      elseif ($newdate < $creadate) {$st[0] = "n"; $etat = $web371;}
      else {$st[0] = "a"; $etat = $web367;}
      ?>
      <tr class="<?php echo $color; ?>" style="text-align:center;">
      <td width="30%" style="text-align:left;">
      <img src="<?php echo CHEMIN ?>inc/img/general/msg_<?php echo $st[0]; ?>.gif" style="vertical-align:middle;" alt="<?php echo $etat; ?>" title="<?php echo $etat; ?>"/>
      <a href="thread.php?lng=<?php echo $lng ?>&amp;pg=<?php echo $dbwork[$i][2] ?>&amp;fid=<?php echo $id; if (!empty($cat)) { echo "&amp;cat=".$cat; } ?>"  title="<?php echo $etat; ?>"><b><?php echo $dbwork[$i][5]; ?></b></a></td>
      <td width="10%"><a href="thread.php?lng=<?php echo $lng ?>&amp;pg=<?php echo $dbwork[$i][2] ?>&amp;fid=<?php echo $id; if (!empty($cat)) { echo "&amp;cat=".$cat; } ?>"><b><?php echo $dbwork[$i][1]; ?></b></a></td>
      <td width="20%">
      <?php
      if ($dbwork[$i][10] != "on") {
        $em = BreakEMail($dbwork[$i][4]);
        ?>
        <b><a href="JavaScript:WriteMailTo('<?php echo addslashes(urlencode($dbwork[$i][3])); ?>','<?php echo $em[0]; ?>','<?php echo $em[1]; ?>','<?php echo $em[2]; ?>')"><?php echo addslashes($dbwork[$i][3]); ?></a></b>
        <?php
      }
      else {
        echo "<b>".$dbwork[$i][3]."</b>";
      }
      ReadDoc(DBBASE.$dbwork[$i][2]);
       ?>
      <br /><?php echo FormatDate($creadate); ?>
      </td>
      <?php
      if ($serviz[34] == "on") {
        echo "<td width='10%'>\n";
        if ($threadcounter <= 1) {
        $txtcount = $web188;
      }
      else {
        $txtcount = $web189;
      }
      echo $threadcounter." ".$txtcount;
      echo "</td>\n";
    }
    echo "<td width='10%'>";
    echo $dbwork[$i][7];
    echo "</td><td width='20%'>";
    if ($dbwork[$i][7] != 0) {
      $idder=(ceil($dbwork[$i][7]/ $serviz[20]));
      if ($dbwork[$i][11] != "on") {
        $em = BreakEMail($dbwork[$i][9]);
        $formail = "<b><a href=\"JavaScript:WriteMailTo('".addslashes(urlencode($dbwork[$i][8]))."','".$em[0]."','".$em[1]."','".$em[2]."')\">".addslashes($dbwork[$i][8])."</a></b>";
        $formail .= "<a href=\"thread.php?lng=".$lng."&amp;pg=".$fileid."&amp;id=".$idder."&amp;cat=".$cat."#".$dbwork[$i][7]."\" title =\"".$web297."\"> &nbsp;<img src='".CHEMIN."inc/img/general/tolist.gif' border='0' alt='".$web297."' /></a>";
      }
      else {
        $formail = "<b>".$dbwork[$i][8]."</b>";
        $formail .= "<a href=\"thread.php?lng=".$lng."&amp;pg=".$fileid."&amp;id=".$idder."&amp;cat=".$cat."#".$dbwork[$i][7]."\" title =\"".$web297."\"> &nbsp;<img src='".CHEMIN."inc/img/general/tolist.gif' border='0' alt='".$web297."' /></a>";
      }
      echo $formail."<br />";
        $dbth = array();
        $dbth = ReadDBFields(DBTHREAD);
        for ($j = 0; $j < count($dbth); $j++) {
          if ($dbth[$j][1] == $dbwork[$i][1] && $dbth[$j][2] == $dbwork[$i][7]) {
            $th_id = $dbth[$j][3];
            break;
          }
        }
        ReadDoc(DBBASE.$th_id);
        echo FormatDate($creadate);
    }
    else {
      echo "&nbsp;";
    }
    echo "</td>";
    echo "</tr>";
  }
}
echo "</table>";
echo GetNavBar("forum.php?lng=".$lng."&amp;cat=".$cat."&amp;id=", count($dbwork), $id, $serviz[17]);

if ($serviz[18] == "on") {
  if (count($dbwork)<=$serviz[17]) {
// ajout l?nde
  }
  ?>
  <div style='width:100%; padding:16px 0;'>
   
    <div class="bord" style="text-align:left;vertical-align:middle;float:left;padding:4px;">
    <img src="<?php echo CHEMIN ?>inc/img/general/msg_a.gif" alt= "<?php echo $web367; ?>" style="vertical-align:middle" /> <?php echo $web366.$web367; ?> &nbsp;&nbsp;
    <img src="<?php echo CHEMIN ?>inc/img/general/msg_c.gif" alt= "<?php echo $web368; ?>" style="vertical-align:middle" /> <?php echo $web366.$web368; ?> &nbsp;&nbsp;
    <img src="<?php echo CHEMIN ?>inc/img/general/msg_t.gif" alt= "<?php echo $web370; ?>" style="vertical-align:middle" /> <?php echo $web370; ?> &nbsp;&nbsp;
    <img src="<?php echo CHEMIN ?>inc/img/general/msg_n.gif" alt= "<?php echo $web371; ?>" style="vertical-align:middle" /> <?php echo $web371.$web334; ?>
    </div>
    <div style="text-align:right;float:right;width:250px;padding-top:2px;">
    <form action="<?php echo CHEMIN ?>fortopic.php?lng=<?php echo $lng ?>" method="post">
    <img src="<?php echo CHEMIN; ?>inc/img/general/b_list.gif" alt="[" style="vertical-align:top;" /><button type="submit" style="background:transparent url(<?php echo CHEMIN; ?>inc/img/general/b_ton.gif) repeat-x;border:none;height:22px;margin:0px;cursor:pointer;" title="<?php echo $web134; ?>"><?php echo $web134; ?></button><img src="<?php echo CHEMIN; ?>inc/img/general/b_right.gif" style="vertical-align:top;" alt="]" />
    </form>
    </div>

  </div>

</center>
<br />
  <?php
  }
  }
}
btable();
include("inc/bpage.inc");
?>
