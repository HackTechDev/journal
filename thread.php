<?php
/*
    Forum Thread - GuppY PHP Script -  version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.2 (05 January 2003)   : created databases thread.dtb and forum.dtb for quicker display of forum threads
      v1.6 (23 January 2003)   : added option to hide on the site the e-mail address of poster
      v1.8 (05 February 2003)  : corrected bug for $thrd input (when coming from Search box)
                                 added forum category management
      v2.0 (27 February 2003)  : added links to jump back in thread and forum (by Alex)
                                 added encryption of webmaster's e-mail @ (SPAM protection)
      v2.1 (10 March 2003)     : added addslashes() to var in Javascript functions (to avoid errors)
      v2.2 (22 April 2003)     : added answer's text reminder (by Nicolas Alves)
                                 option for choosing the number of items to display in news, forum threads, links, downloads, FAQ and Guestbook
                                 replaced <P><CENTER> by <P align="center"> otherwise IE takes the default font instead of the required one (Thanks Michel)
                                 cleanup in the images organization
      v2.3 (27 July 2003)      : added direct jump to pages (by Nicolas Alves and Laurent Duveau)
                                 upgraded WriteMailTo() function for better SPAM protection (thanks Michel)
      v2.4 (24 September 2003) : added section icon in central boxes
                                 added number of times a forum thread was read (by Nicolas Alves and Laurent Duveau)
                                 added ReadDoc() function
                                 added ReadDocCounter(), WriteDocCounter() and UpdateDocCounter() functions
                                 added GetCurrentDateTime() and FormatDate() function to ease various date and time formatings
                                 reviewed all Files Read & Write functions
                                 secured transfered parameters
                                 created $typ_[name] variables
                                 upgraded forum indexes for a smaller size
      v4.0 (06 December 2004)  : added page title (by Jean-Mi)
                                 added bgcolor and new disposition (by Icare)
                                 added alt tags to img and removed border tag for non-linked img, added the forum management style (by Isa)
                                 added new colored appearance and submit buttons, changed & by &amp; for W3C compliance (by Icare)
                                 added new navigation, avatars and optionnal quick admin (by Nicolas Alves)
      v4.5 (22 March 2005)     : replacing navigation bar (by Jean-Mi)
      v4.6.0 (15 Févier 2007)  : new presentation, added correct, lock, up and on-top icons(by Icare)
                                 added user rank and enlarged thread management to moderator and all admins (by Ghazette and Icare)
      v4.6.5 (05 December 2007)  : added omited strip_tags() to title (by Icare)
      v4.6.6 (14 April 2008)     : replacing Topic n° xx by Topic: , corrected thread new and on top (by Icare)
                                   added urlencode in WriteMailTo() (by JeanMi)
      v4.6.8 (24 May 2008)       : added number to topic (by JeanMi),
                                   deletion of duplicated topmess process, back to forum if $pg empty (by Icare)
      v4.6.9 (25 December 2008)  : added redirection in forum archives or subject not found #237
      v4.6.10 (7 September 2009) : corrected #274 and #289
      v4.6.11 (11 December 2009) : corrected #307
      v4.6.15 (30 June 2011): added private management (by Icare)	
      v4.6.16 (02 September 2011) : corrected private management (by Laroche)	  
      v4.6.17 (21 October 2011)   : test a class if the private groups are activated (by Laroche)
	  v4.6.22 (29 December 2012)  : added pseudo-private group for members (by Saxbar)
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");
define('PATH_PGEDITOR', 'inc/pgeditor/');		//Chemin relatif de l'éditeur (ne pas modifier)
define('PATH_CONFIG_PGEDITOR','inc/config_pgeditor_guppy/'); //Chemin relatif du fichier de configuration de l'éditeur
include CHEMIN.PATH_PGEDITOR.'pgeditor.php';    //Fichier contenant toutes les fonctions n?ssaires pour int?ation de l'éditeur
include CHEMIN.PATH_PGEDITOR.'syntaxcolor/syntaxcolor.php'; //Coloration syntaxique
include_once (CHEMIN.'inc/func_groups.php'); // ajouté pour groupes privés
if ($serviz[13] != "on") {
  exit($web143);
}
$CatForumOn = ($serviz[18] != "") ? True : False;
$pg = strip_tags($pg);
$thrd = strip_tags($thrd);
$cat = strip_tags($cat);
$id = strip_tags($id);
$fid = strip_tags($fid);

ReadDoc(DBBASE.$pg);
if ((CheckGroup($cat, $userprefs[1]) != 1) && (!is_numeric($cat) && $CatForumOn))  { 
	header("location:index.php");
	die();
}
if (preg_match('/^pr/i', $fieldb2) && (CheckGroup($fieldb2, $userprefs[1]) != 1)) {
	header("location:index.php");
	die();
}

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
  }
}
elseif (!empty($thrd)) {
  $dbwork = ReadDBFields(DBTHREAD);
  for ($i = 0; $i < count($dbwork); $i++) {
    if ($dbwork[$i][1] == $thrd && $dbwork[$i][2] == "0") {
      $thread = $thrd;
      $pg = $dbwork[$i][3];
      break;
    }
  }
}
if (empty($pg)) {
header("location:".CHEMIN."forum.php?lng=".$lng);
}

if ($thread === 0) {
    /// Le sujet n'existe pas !!!
    /// Existe-t-il dans les archives du forum ?
    $threadarch = 0;
    $dbworkarch = SelectDBForumByID(ReadDBFields(DBFORUMARCH), $pg);
    if (count($dbworkarch) != 0) {
        $threadarch = $dbwork[0][1];
    }
    if ($threadarch !== 0) {
        /// Le sujet est archivé !! Redirection vers les archives du forum
        header("location:threadarch.php?lng=$lng&pg=$pg&fid=$fid&cat=$cat");
        exit;
    }
    /// Le sujet n'existe pas dans le forum, ni dans les archives du forum !!!
    header('HTTP/1.0 404 Not Found');
    $topmess = $lng == $lang[0] ? $nom[22] : $nom[23];
    include("inc/hpage.inc");
    htable($topmess, "100%");
    echo '<p>'.$web36.'</p>';
    btable();
    include("inc/bpage.inc");
}
else {
    /// Le sujet existe bien !!!

    if ($serviz[34] == "on") {
      $threadcounter = UpdateDocCounter($pg);
    }

    $dbthrd = SelectDBThreadByThread(ReadDBFields(DBTHREAD),$thread);

    if ($lng == $lang[0]) {
      $i = 0;
    }
    else {
      $i = 1;
    }

    ReadDoc(DBBASE.$pg);

    if ($serviz[18] != "on") {
      $topmess = "<a href=\"forum.php?lng=".$lng."&amp;id=".$fid."\">".$nom[$i+22]."</a>";
    }
    else {
      if (!empty($cat)) {
        $dbworkcat = ReadDBFields(DBFORUMCAT);		
		$dbworkcat_allowed = array();
		// Tester et filtrer les groupes autorisés
		for ($k = 0; $k < count($dbworkcat); $k++) {
			$prcat = explode(',', $dbworkcat[$k][0]);
			$dbworkcat[$k][0] = $prcat[0];
			if ( (is_numeric($dbworkcat[$k][0])) || ( CheckGroup($dbworkcat[$k][0], $userprefs[1]) == true) ) {				
				$dbworkcat_allowed[] = $dbworkcat[$k];
			}
		}
        for ($k = 0; $k < count($dbworkcat_allowed); $k++) {
          if ($dbworkcat_allowed[$k][0] == $cat) {
            $catxt = $dbworkcat_allowed[$k][1+$i];
          }
        }
		// fin test et filtrage
        $topmess = "<a href=\"fortopic.php?lng=".$lng."\">".$nom[$i+22]."</a> - <a href=\"forum.php?lng=".$lng."&amp;id=".$fid."&amp;cat=".$cat."\">".$catxt."</a> - ".$web63.$fielda1;
      }
      else {
        $topmess = "<a href=\"fortopic.php?lng=".$lng."\">".$nom[$i+22]."</a> - ".$web63.$fielda1;
      }
    }
    if ($page[9] != "") {
      $topmess = "<img src=\"".CHEMIN."inc/img/icons/".$page[9]."/forum.gif\" align=\"right\" width=\"32\" height=\"32\" alt=\"forum.gif\" />".$topmess;
    }
    if ($userprefs[3] =="" || $userprefs[3] == "LR") $userprefs[3] = "L";
    $widepage = $forum[3];
    $forumname = strip_tags($nom[$i+22]);

    include("inc/hpage.inc");
    htable($topmess, "100%");

    ReadDoc(DBBASE.$pg);
    echo "<br />";
    if ($forum[3] == "on") include("inc/topforum.inc"); //large forum
    if ($forum[9] == "on") {
      echo '<span style="margin-left:8px; font-weight:bold;"><a href="javascript:PopupWindow(\'rules.php?lng='.$lng.'\',\'rules\',800,500,\'yes\',\'yes\');" title="'.$web409.'">';
      echo "<img src=\"".CHEMIN."inc/img/general/charte.gif\" border=\"0\" alt=\"".$web409."\" /> - ".$web409."</a></span><br />";
    }
    if ($serviz[18] == "on") {
    $title = "<span style='margin-left:8px; font-weight:bold;'><a href=\"fortopic.php?lng=".$lng."\" title=\"".$forumname."\"><img src=\"".CHEMIN."inc/img/general/dir.gif\" border=\"0\" style=\"vertical-align:middle\" alt=\"".$forumname."\" /> - ".$forumname."</a></span><br />";
    $title .= "<span style='margin-left:28px; font-weight:bold;'><a href=\"forum.php?lng=".$lng."&amp;cat=".$cat."\" title=\"".$catxt."\">";
    $title .= "<img src=\"".CHEMIN."inc/img/general/dir1.gif\" border=\"0\" style=\"vertical-align:middle\" alt=\"".$catxt."\"/> - ".$catxt."</a></span><br />";
    }
    else {
    $title = "<span style='margin-left:8px; font-weight:bold;'><a href=\"forum.php?lng=".$lng."\" title=\"".$forumname."\"><img src=\"".CHEMIN."inc/img/general/dir.gif\" border=\"0\" style=\"vertical-align:middle\" alt==\"".$forumname."\" />  - ".$forumname."</a></span><br />";
    }
    echo "<p align='left'>".$title."</p>";

    if ($members[0]=="on" && $userprefs[1]=="" && $members[5]=="on") {
      echo "<p align=\"center\">".$web342."</p><br />";
      echo "<p align=\"center\">[<a href=\"".CHEMIN."user.php?lng=".$lng."\">".$web343."</a>]</p><br />";
    }
    else {
  /// debut modif accès privé  
  if ($CatForumOn) {
	$acces = "no";
	if (IsValidForumCat($cat)) {
		$acces = "ok"; 
	}
	if (IsPrivateForumCat($cat)) {
		$acces = "no";
		if ($userprefs[1] != "") {    
			if (CheckGroup($cat, $userprefs[1])) $acces ="ok";
		}
	}
  }
  if ($acces == "no") {
    echo "<p style='text-align:center;font-weight:bold;padding-bottom:48px;'><br />".$web443."</strong><br /></p>";
  } else {
/// fin modif accès privé	
            $newdate = date("YmdHi",time()-(86400*$forum[8])); // délai pour nouveau
            $st = explode("#",$fieldmod);
            if ($st[0] == "c") {$etat = $web368." ".$web6." ".$st[1]." ".$web7." ".FormatDate($st[2]);}
            elseif ($st[0] == "s") {$st[0] = "c"; $etat = $web368." ".$web6." ".$st[1]." ".$web7." ".FormatDate($st[2]);}
            elseif ($st[0] == "t" && $moddate > date("YmdHi")) {$etat = $web370." ".$web6." ".$st[1]." ".$web7." ".FormatDate($st[2]);}
            elseif ($st[0] == "u" && $moddate > date("YmdHi")) {$st[0] = "t"; $etat = "Up ".$web6." ".$st[1]." ".$web7." ".FormatDate($st[2]);}
            elseif ($newdate < $creadate) {$st[0] = "n"; $etat = $web371;}
            else {$st[0] = "a"; $etat = $web367;}
      ?>
      <center>
      <br />
      <table align="center" width="100%" class="bord" style="margin-bottom:6px;" summary="">
      <tr class="forum2">
      <td height="32" style="width:20%;min-width:136px;text-align:center;white-space:nowrap;"><img src="<?php echo CHEMIN ?>inc/img/general/msg_<?php echo $st[0]; ?>.gif" style="vertical-align:middle" alt="<?php echo $etat; ?>" title="<?php echo $etat; ?>" />&nbsp;&nbsp;<b><?php echo $web63.' '.$thread; ?></b></td>
      <td colspan="2" style="text-align:left;"><b>&nbsp;<?php echo $fieldb1; ?></b></td></tr>
      <tr style="vertical-align:top">
      <td class="rep" rowspan="2" style="text-align:center;min-width:136px;white-space:nowrap;">
      <?php
      if ($fieldd2!="v" && $fieldd2!="") {
        if($fieldd2>1) {
          $nbrpostmsg = $fieldd2." ".$web335;
        }
        else {
          $nbrpostmsg = $fieldd2." ".$web334;
        }
      }
      else {
        $nbrpostmsg="";
      }
      $max = explode("-", $forum[7]);
      if ($fieldd2=="v") {
        $inscrit = $web15;
      }
      elseif($forum[7] == "") {
      $inscrit = "";
      }
      elseif($fieldd2 >= $max[3]) {
        $inscrit = "<img src=\"inc/img/general/rank5.gif\" border=\"0\" alt=\"".$nbrpostmsg."\" title=\"".$nbrpostmsg."\" />";
      }
      elseif($fieldd2 >= $max[2]) {
        $inscrit = "<img src=\"inc/img/general/rank4.gif\" border=\"0\" alt=\"".$nbrpostmsg."\" title=\"".$nbrpostmsg."\" />";
      }
      elseif($fieldd2 >= $max[1]) {
        $inscrit = "<img src=\"inc/img/general/rank3.gif\" border=\"0\" alt=\"".$nbrpostmsg."\" title=\"".$nbrpostmsg."\" />";
      }
      elseif($fieldd2 >= $max[0]) {
        $inscrit = "<img src=\"inc/img/general/rank2.gif\" border=\"0\" alt=\"".$nbrpostmsg."\" title=\"".$nbrpostmsg."\" />";
      }
      else {
        $inscrit = "<img src=\"inc/img/general/rank1.gif\" border=\"0\" alt=\"".$nbrpostmsg."\" title=\"".$nbrpostmsg."\" />";
      }
      if($fieldc2=="") {
        $fieldc2="<img src=\"inc/img/avatars/unknow.gif\" border=\"0\" alt=\"".$web305."\" title=\"".$web305."\" />";
      }
      else {
        $fieldc2="<img src=\"inc/img/avatars/".$page[23]."/".$fieldc2."\" border=\"0\" alt=\"".$author."\" title=\"".$author."\" />";
      }
      echo "<br />".$web7." ".FormatDate($creadate)."<br />";
      echo $web6." <b>".addslashes($author)."</b><br />";
      echo "<br />".$fieldc2."<br /><br />";
      $rank = ReadDBFields(DBADMIN);
      $modadmin="";
      for ($y = 0; $y < count($rank); $y++) {
        if ($rank[$y][0] == $userprefs[1] && $rank[$y][2] == "on") {
          $modadmin = "yes";
          break;
        }
      }
      if ($userprefs[1] == $serviz[31]) $modadmin = "yes";
      for ($y = 0; $y < count($rank); $y++) {
          if ($rank[$y][0] == $author) {
            switch ($rank[$y][1]) {
            case admin :
              echo $web418."<br />";
            break;
            case modo :
              echo $web420."<br />";
            break;
            case redac :
              echo $web419."<br />";
            break;
            case webm :
              echo $web11."<br />";
            break;
            }
          }
      }
      if ($author == $serviz[31]) {
        echo $web418."<br />";
      }
      if ($fieldd2 != "v") { 
        echo $inscrit;
      }
      else {
        echo $web15;
      }

      switch($st[0]){
      case "c":
      case "s":
        if ((WYSIWYG && $userprefs[11] != "on" && $modadmin == "yes") || (WYSIWYG && $userprefs[11] != "on" && $userprefs[1] == $serviz[31])) {
          echo "&nbsp;<a href=\"postguest.php?lng=".$lng."&amp;typ=".TYP_THREAD."&amp;mod=maj&amp;num=".$thread."&amp;pg=".$fileid."\" title=\"".$web369."\"><img src='".CHEMIN."inc/img/general/edit.gif' border='0'alt='".$web369."' /></a>";
        }
      break;
      case "t":
      case "u";
        if ($modadmin == "yes" || $userprefs[1] == $serviz[31]) {
          if (WYSIWYG && $userprefs[11] != "on") {
            echo "&nbsp;<a href=\"postguest.php?lng=".$lng."&amp;typ=".TYP_THREAD."&amp;mod=maj&amp;num=".$thread."&amp;pg=".$fileid."\" title=\"".$web369."\"><img src='".CHEMIN."inc/img/general/edit.gif' border='0'alt='".$web369."' /></a>";
            echo "&nbsp;<a href=\"postguest.php?lng=".$lng."&amp;typ=".TYP_THREAD."&amp;mod=stop&amp;num=".$thread."&amp;pg=".$fileid."\" title=\"".$web390."\"><img src='".CHEMIN."inc/img/general/lock.gif' border='0'alt='".$web390."' /></a>";
          }
        }
        elseif ($userprefs[1] == $author) {
          if (WYSIWYG && $userprefs[11] != "on") {
            echo "&nbsp;<a href=\"postguest.php?lng=".$lng."&amp;typ=".TYP_THREAD."&amp;mod=maj&amp;num=".$thread."&amp;pg=".$fileid."\" title=\"".$web369."\"><img src='".CHEMIN."inc/img/general/edit.gif' border='0'alt='".$web369."' /></a>";
          }
          echo "&nbsp;<a href=\"postguest.php?lng=".$lng."&amp;typ=".TYP_THREAD."&amp;mod=lock&amp;num=".$thread."&amp;pg=".$fileid."\" title=\"".$web363."\"><img src='".CHEMIN."inc/img/general/lock.gif' border='0'alt='".$web363."' /></a>";
        }
      break;
      default:
        if ($modadmin == "yes" || $userprefs[1] == $serviz[31]) {
          if (WYSIWYG && $userprefs[11] != "on") {
            echo "&nbsp;<a href=\"postguest.php?lng=".$lng."&amp;typ=".TYP_THREAD."&amp;mod=maj&amp;num=".$thread."&amp;pg=".$fileid."\" title=\"".$web369."\"><img src='".CHEMIN."inc/img/general/edit.gif' border='0'alt='".$web369."' /></a>";
            echo "&nbsp;<a href=\"postguest.php?lng=".$lng."&amp;typ=".TYP_THREAD."&amp;mod=stop&amp;num=".$thread."&amp;pg=".$fileid."\" title=\"".$web390."\"><img src='".CHEMIN."inc/img/general/lock.gif' border='0'alt='".$web390."' /></a>";
          }
          if ($forum[6] != "") {
            echo "&nbsp;<a href=\"postguest.php?lng=".$lng."&amp;typ=".TYP_THREAD."&amp;mod=top&amp;num=".$thread."&amp;pg=".$fileid."\" title=\"".$web364."\"><img src='".CHEMIN."inc/img/general/lockup.gif' border='0'alt='".$web364."' /></a>";
          }
        }
        elseif ($userprefs[1] == $author) {
          if (WYSIWYG && $userprefs[11] != "on") {
            echo "&nbsp;<a href=\"postguest.php?lng=".$lng."&amp;typ=".TYP_THREAD."&amp;mod=maj&amp;num=".$thread."&amp;pg=".$fileid."\" title=\"".$web369."\"><img src='".CHEMIN."inc/img/general/edit.gif' border='0'alt='".$web369."' /></a>";
          }
          echo "&nbsp;<a href=\"postguest.php?lng=".$lng."&amp;typ=".TYP_THREAD."&amp;mod=lock&amp;num=".$thread."&amp;pg=".$fileid."\" title=\"".$web363."\"><img src='".CHEMIN."inc/img/general/lock.gif' border='0'alt='".$web363."' /></a>";
          if ($forum[5] != "") {
            echo "&nbsp;<a href=\"postguest.php?lng=".$lng."&amp;typ=".TYP_THREAD."&amp;mod=up&amp;num=".$thread."&amp;pg=".$fileid."\" title=\"".$web364."\"><img src='".CHEMIN."inc/img/general/lockup.gif' border='0'alt='".$web364."' /></a>";
          }
        }
      }
    echo "<br />";
    $fieldc1 = colorCode($fieldc1);
    ?>
    </td>
    <td class="rep" colspan="2" height="120" style="padding:4px;text-align:left;"><br /><?php echo $fieldc1; ?></td></tr>
    <tr><td height="28" style="text-align:left">
    <?php
    if ($fieldd1 != "on") {
      $em = BreakEMail($email);
      ?>
      <a href="JavaScript:WriteMailTo('<?php echo addslashes(urlencode($author)); ?>','<?php echo $em[0]; ?>','<?php echo $em[1]; ?>','<?php echo $em[2]; ?>')">
      <img src="inc/img/general/email.gif" alt="<?php echo "$web173 $author"; ?>" title="<?php echo "$web173 $author"; ?>" border="0" /></a>
      <?php
    }
    echo "&nbsp;";
    if ($fieldweb!="") {
      ?>
      <a href="<?php echo $fieldweb; ?>" target="_blank"><img src="inc/img/general/site.gif" alt="<?php echo "$web304 $author"; ?>" title="<?php echo "$web304 $author"; ?>" border="0" /></a>
      <?php
    }
    echo "</td><td style='text-align:right'>";
    if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32] && $drtuser[23]=="on")) {
      ?>
      <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=forum&amp;form=2&amp;id=<?php echo $fileid; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/edit.gif" border="0" alt="<?php echo $web369; ?>" title="<?php echo $web369; ?>" /></a>
      <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=forum&amp;act=i&amp;id=<?php echo $fileid; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/desact.gif" border="0" alt="<?php echo $web333; ?>" title="<?php echo $web333; ?>" /></a>
      <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=forum&amp;del=<?php echo $fileid; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/del.gif" border="0" alt="<?php echo $web324; ?>" title="<?php echo $web324; ?>" /></a>
      <?php
    }
    if ($st[0] != "c") {
      ?>
      <a href="postguest.php?lng=<?php echo $lng."&amp;typ=".TYP_THREAD."&amp;num=".$thread."&amp;pg=".$fileid; ?>">
      <img src="inc/img/general/reponse.gif" alt="<?php echo $web65; ?>" title="<?php echo $web65; ?>" border="0" /></a>&nbsp;
      <?php
    }
    else {
      echo "<img src=\"inc/img/general/rep_lock.gif\" alt=\"".$web366.$web368."\" title=\"".$web366.$web368."\" />&nbsp;";
    }
    ?>
    <a href="#top"><img src="inc/img/general/haut.gif" width="12" height="11" alt="<?php echo $web136; ?>" title="<?php echo $web136; ?>" border="0" /></a>
    </td></tr>
    </table>
    <?php
    $dbder = ReadDBFields(DBFORUM);
    for ($i = 0; $i < count($dbder); $i++) {
      if($fielda1==$dbder[$i][1] && $dbder[$i][7] > 3) {
        $idder=(ceil(count($dbthrd)/ $serviz[20]));
      echo "<form action=\"".CHEMIN."thread.php?lng=".$lng."&amp;pg=".$pg."&amp;id=".$idder."&amp;cat=".$cat."#".$dbder[$i][7]."\" method=\"post\">
          <p align=\"right\"><img src=\"".CHEMIN."inc/img/general/b_last.gif\" style=\"vertical-align:top;\" alt=\"[\" /><button type='submit' style='background:transparent url(".CHEMIN."inc/img/general/b_ton.gif) repeat-x;border:none;height:22px;margin:0px;cursor:pointer;' title='".$web283."'>".$web283."</button><img src=\"".CHEMIN."inc/img/general/b_right.gif\" style=\"vertical-align:top;\" alt=\"]\" />&nbsp; &nbsp;</p>
          </form>";
      }
    }

    if (empty($id)) { $id = 1; }
    if (!empty($dbthrd)) {
    echo GetNavBar("thread.php?lng=".$lng."&amp;cat=".$cat."&amp;pg=".$pg."&amp;id=", count($dbthrd), $id, $serviz[20]);
      for ($i = $serviz[20]*($id-1); $i < Min($serviz[20]*$id, count($dbthrd)); $i++) {
        ReadDoc(DBBASE.$dbthrd[$i][3]);
        if ($fieldd2!="v" && $fieldd2!="") {
          if($fieldd2>1) {
            $nbrpostmsg=$fieldd2." ".$web335;
          }
          else {
            $nbrpostmsg=$fieldd2." ".$web334;
          }
        }
        else {
          $nbrpostmsg="";
        }
        if ($fieldd2=="v" || !FileDBExist(CHEMIN.DATAREP."usermsg/".$author.DBEXT)) {
          $inscrit = $web15;
        }
        elseif($forum[7] == "") {
        $inscrit = "";
        }
        elseif($fieldd2 >= $max[3]) {
          $inscrit = "<img src=\"inc/img/general/rank5.gif\" border=\"0\" alt=\"".$nbrpostmsg."\" title=\"".$nbrpostmsg."\" />";
        }
        elseif($fieldd2 >= $max[2]) {
          $inscrit = "<img src=\"inc/img/general/rank4.gif\" border=\"0\" alt=\"".$nbrpostmsg."\" title=\"".$nbrpostmsg."\" />";
        }
        elseif($fieldd2 >= $max[1]) {
          $inscrit = "<img src=\"inc/img/general/rank3.gif\" border=\"0\" alt=\"".$nbrpostmsg."\" title=\"".$nbrpostmsg."\" />";
        }
        elseif($fieldd2 >= $max[0]) {
          $inscrit = "<img src=\"inc/img/general/rank2.gif\" border=\"0\" alt=\"".$nbrpostmsg."\" title=\"".$nbrpostmsg."\" />";
        }
        else {
          $inscrit = "<img src=\"inc/img/general/rank1.gif\" border=\"0\" alt=\"".$nbrpostmsg."\" title=\"".$nbrpostmsg."\" />";
        }
        if($fieldc2=="") {
          $fieldc2="<img src=\"inc/img/avatars/unknow.gif\" border=\"0\" alt=\"".$web305."\" title=\"".$web305."\" />";
        }
        else {
        $fieldc2="<img src=\"inc/img/avatars/".$page[23]."/".$fieldc2."\" border=\"0\" alt=\"".$author."\" title=\"".$author."\" />";
        }
        ?>
        <a name="<?php echo $fielda2; ?>"></a>
        <table width="100%" align="center" class="bord" style="margin-top:8px;" summary="">
        <tr>
        <td class="rep" rowspan="2" align="center" style="width:20%;min-width:136px;text-align:center;vertical-align:top;min-width:136px;white-space:nowrap">
        <?php
        $newdate = date("YmdHi",time()-(86400*$forum[8]));
        if ($newdate < $creadate) {
        echo "<img src='".CHEMIN."inc/img/general/msg_n.gif' style='vertical-align:middle' alt='".$web371."' title='".$web171."' /> ";
        }
        echo "<b>".$web68." ".$fielda2."</b><br />";
        echo "--------<br /> ".$web7." ".FormatDate($creadate)."<br />";
        echo $web6." <b>".addslashes($author)."</b><br /><br />";
        echo $fieldc2."<br /><br />";
        for ($y = 0; $y < count($rank); $y++) {
          if ($rank[$y][0] == $author) {
            switch ($rank[$y][1]) {
              case modo :
                echo $web420."<br />";
              break;
              case redac :
                echo $web419."<br />";
              break;
              case webm :
                echo $web11."<br />";
              break;
            }
          }
        }
        if ($author == $serviz[31]) {
          echo $web418."<br />";
        }
        if ($fieldd2 != "v" && $fieldd2 !="") {
          echo $inscrit;
        } else {
          echo $web15;
        }
        if (WYSIWYG && $userprefs[11] != "on" && $st[0] != "c" && $st[0] != "s") {
        if ($author == $userprefs[1] || $modadmin == "yes" || $serviz[31]==$userprefs[1]) { //  ajout de test si r?cteur
          if ($browser == "OK" && $userprefs[11] != "on" && $st[0] != "c" && $st[0] != "s") {
               echo "&nbsp;<a href=\"postguest.php?lng=".$lng."&amp;typ=".TYP_THREAD."&amp;mod=maj&amp;num=".$thread."&amp;pg=".$fileid."\" title=\"".$web369."\"><img src='".CHEMIN."inc/img/general/edit.gif' border='0'alt='".$web369."' /></a>";
          }
        }
        }
        echo "<br />";
        $fieldc1 = stripslashes($fieldc1);
        $fieldc1 = colorCode($fieldc1);
        ?>
        </td>
        <td class="rep" colspan="2" height="130" style="vertical-align:top;text-align:left;"><?php echo $fieldc1; ?></td></tr>
        <tr>
        <td height="28" style="text-align:left">
        <?php
        if ($fieldd1 != "on") {
          $em = BreakEMail($email);
          ?>
          <a href="JavaScript:WriteMailTo('<?php echo addslashes(urlencode($author)); ?>','<?php echo $em[0]; ?>','<?php echo $em[1]; ?>','<?php echo $em[2]; ?>')">
          <img src="inc/img/general/email.gif" alt="<?php echo "$web173 $author"; ?>" title="<?php echo "$web173 $author"; ?>" border="0" /></a>
          <?php
        }
        echo "&nbsp;";
        if ($fieldweb!="") {
          ?>
          <a href="<?php echo $fieldweb; ?>" target="_blank"><img src="inc/img/general/site.gif" alt="<?php echo "$web304 $author"; ?>" title="<?php echo "$web304 $author"; ?>" border="0" /></a>
          <?php
        }
        ?>
        </td>
        <td style="text-align:right">
        <?php
        if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($drtuser[23]=="on")) {
          ?>
          <a href="admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=forum&amp;form=2&amp;id=<?php echo $fileid; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/edit.gif" border="0" alt="<?php echo $web369; ?>" title="<?php echo $web369; ?>" /></a>
          <a href="admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=forum&amp;act=i&amp;id=<?php echo $fileid; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/desact.gif" border="0" alt="<?php echo $web333; ?>" title="<?php echo $web333; ?>" /></a>
          <a href="admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=forum&amp;del=<?php echo $fileid; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/del.gif" border="0" alt="<?php echo $web324; ?>" title="<?php echo $web324; ?>" /></a>
          <?php
        }
        if ($st[0] != "c") { // si thread clos pas de r?nse
        ?>
        <a href="postguest.php?lng=<?php echo $lng."&amp;typ=".TYP_THREAD."&amp;num=".$thread."&amp;pg=".$fileid; ?>">
        <img src="inc/img/general/reponse.gif" alt="<?php echo $web65; ?>" title="<?php echo $web65; ?>" border="0" /></a>&nbsp;
        <?php
        }
        else {
          echo "<img src=\"inc/img/general/rep_lock.gif\" alt=\"".$etat."\" title=\"".$etat."\" />&nbsp;";
        }

        ?>
        <a href="#top"><img src="inc/img/general/haut.gif" width="12" height="11" alt="<?php echo $web136; ?>" title="<?php echo $web136; ?>" border="0" /></a></td></tr>
        </table>
        <?php
      }
    }
    echo GetNavBar("thread.php?lng=".$lng."&amp;cat=".$cat."&amp;pg=".$pg."&amp;id=", count($dbthrd), $id, $serviz[20]);
    if (empty($fid)) { $fid = 1; }
      ?>
       <div align="center" class="bord" style="width:auto;padding:4px;margin:4px auto 0 0;text-align:left;height:30px">
        <div style="float:left;vertical-align:middle;padding:4px;">
        <img src="<?php echo CHEMIN ?>inc/img/general/msg_a.gif" style="vertical-align:middle" alt="<?php echo $web367; ?>" /> <?php echo $web366.$web367; ?> &nbsp;
        <img src="<?php echo CHEMIN ?>inc/img/general/msg_c.gif" style="vertical-align:middle" alt="<?php echo $web368; ?>" /> <?php echo $web366.$web368; ?> &nbsp;
        <img src="<?php echo CHEMIN ?>inc/img/general/msg_t.gif" style="vertical-align:middle" alt="<?php echo $web370; ?>" /> <?php echo $web370; ?> &nbsp;
        <img src="<?php echo CHEMIN ?>inc/img/general/msg_n.gif" style="vertical-align:middle" alt="<?php echo $web371; ?>" /><?php echo $web371.$web334; ?> &nbsp;&nbsp;-&nbsp;&nbsp;
        <img src="<?php echo CHEMIN ?>inc/img/general/edit.gif" style="vertical-align:middle" alt="<?php echo $web369; ?>" /> <?php echo $web369." ".$web334; ?> &nbsp;
        <img src="<?php echo CHEMIN ?>inc/img/general/lock.gif" style="vertical-align:middle" alt="<?php echo $web363; ?>" /> <?php echo $web363.$web366; ?> &nbsp;
        <img src="<?php echo CHEMIN ?>inc/img/general/lockup.gif" style="vertical-align:middle" alt="<?php echo $web364; ?>" /> <?php echo $web364; ?>
        </div>
      </div>
      <div style="width:100%;">
        <div style="float:right;text-align:right;padding:6px 0px 6px 8px;line-height: 22px;">
         <form action="forum.php?lng=<?php echo $lng.'&amp;id='.$fid; ?><?php if (!empty($cat)) { echo "&amp;cat=".$cat; } ?>" method="post">
         <img src="<?php echo CHEMIN; ?>inc/img/general/b_list.gif" style="vertical-align:top;" alt="[" /><button type="submit" style="background:transparent url(<?php echo CHEMIN; ?>inc/img/general/b_ton.gif) repeat-x;border:none;height:22px;margin:0px;cursor:pointer;vertical-align:top;" title="<?php echo $web70; ?>"><?php echo $web70; ?></button><img src="<?php echo CHEMIN; ?>inc/img/general/b_right.gif" style="vertical-align:top;" alt="]" />
         </form>
        </div>
        <?php
      if ($serviz[18] == "on") {
        ?>
        <div style="float:right;width:300px;text-align:right;padding:4px 6px;line-height:22px;">
         <form method="post" action ="forum.php?lng=<?php echo $lng; ?>">
         <span style="margin-left:8px;vertical-align:middle;padding: 4px 6px 4px 0"><a href="fortopic.php?lng=<?php echo $lng; ?>" title="<?php echo $web130; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/dir.gif" border="0" style="vertical-align:middle" alt="<?php echo $web130; ?>" /> &nbsp;<b><?php echo $forumname; ?></b></a></span>&nbsp;
         <select name="cat" onchange="this.form.submit();" style="vertical-align:middle">
         <?php
         for ($k = 0; $k < count($dbworkcat_allowed); $k++) { // uniquement les catégories autorisées
           echo "<option value=\"".$dbworkcat_allowed[$k][0]."\">".$dbworkcat_allowed[$k][1]."</option>";
         }
         ?>
         </select>
         </form>
        </div>
        <?php
      }
      echo "</div><br /></center><br /><br />";
    }
	}
    btable();
    include("inc/bpage.inc");
}
?>
