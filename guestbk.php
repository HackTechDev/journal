<?php
/*
    Guestbook - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.5 (10 January 2003)   : addeed target=_new in user's url
      v1.6 (23 January 2003)   : added option to hide on the site the e-mail address of poster
      v2.0 (27 February 2003)  : added encryption of webmaster's e-mail @ (SPAM protection)
      v2.1 (10 March 2003)     : added addslashes() to var in Javascript functions (to avoid errors)
      v2.2 (22 April 2003)     : option for choosing the number of items to display in news, forum threads, links, downloads, FAQ and Guestbook
                                 replaced <P><CENTER> by <P align="center"> otherwise IE takes the default font instead of the required one (Thanks Michel)
                                 cleanup in the images organization
      v2.3 (27 July 2003)      : added direct jump to pages (by Nicolas Alves and Laurent Duveau)
                                 upgraded WriteMailTo() function for better SPAM protection (thanks Michel)
      v2.4 (24 September 2003) : added section icon in central boxes
                                 added ReadDoc() function
                                 added GetCurrentDateTime() and FormatDate() function to ease various date and time formatings
                                 reviewed all Files Read & Write functions
                                 secured transfered parameters
                                 created $typ_[name] variables
      v4.0 (06 December 2004)  : added page title (by Jean-Mi)
                                 added alt tags to img and removed border tag for non-linked img, replaced & by &amp; for better compliance to standards (by Isa)
                                 added new appearance (by Icare)
                                 added new navigation and optionnal quick admin (by Nicolas Alves)
      v4.5 (22 April 2005)     : replacing navigation bar (by Jean-Mi)
      v4.6.6 (14 April 2008)   : added urlencode to WriteMailTo() (by JeanMi)
                                 added header("HTTP/1.0 404 Not found") in the event of pages not found (by JeanMi, thanks eDada)
      v4.6.10 (7 September 2009)    : corrected #274
      v4.6.11 (11 December 2009)    : changed width by style=width in cells (by Icare)
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");

if ($serviz[12] != "on") {
  exit($web143);
}

$pg = strip_tags($pg);
$id = strip_tags($id);

if (!empty($pg)) {
  if (count(SelectDBFields(TYP_GUESTBK,"a",$pg)) != 0) {
    $dbwork = SelectDBFields(TYP_GUESTBK,"a",$pg);
  }
  else {
    $dbwork = array();
    header('HTTP/1.0 404 Not Found');
  }
}
else {
  $dbwork = SelectDBFields(TYP_GUESTBK,"a","");
}
@rsort($dbwork);

if ($lng == $lang[0]) {
  $i = 0;
}
else {
  $i = 10;
}
$topmess = strip_tags($nom[$i+9]);
if ($page[9] != "") {
  $topmess = "<img src=\"".CHEMIN."inc/img/icons/".$page[9]."/guestbook.gif\" align=\"right\" width=\"32\" height=\"32\" alt=\"guestbook.gif\"/>".$topmess;
}
include("inc/hpage.inc");
htable($topmess, "100%");
echo "<br /><br />";
if ($members[0]=="on" && $userprefs[1]=="" && $members[12]=="on") {
  echo "<p align=\"center\">".$web342."</p><br />";
  echo "<p align=\"center\">[ <a href=\"".CHEMIN."user.php?lng=".$lng."\">".$web343."</a> ]</p><br />";
}
else {
  ?>
  <form action="<?php echo CHEMIN ?>postguest.php?lng=<?php echo $lng; ?>" method="post">
  <input type="hidden" name="typ" value="<?php echo TYP_GUESTBK; ?>"/>
  <p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $web41; ?>"><?php echo $web41; ?></button><?php echo $boutonright; ?></p>
  </form>
  <hr />
  <?php
  if (empty($id)) {
    $id = 1;
  }
  if (!empty($dbwork)) {
    for ($i = $serviz[7]*($id-1); $i < Min($serviz[7]*$id, count($dbwork)); $i++) {
      ReadDoc(DBBASE.$dbwork[$i][1]);
      ?>
      <table align="center" width="98%" class="bord" summary="">
      <tr><td style="width:12%" class="forum"><?php echo $web39.$fielda1; ?></td>
      <td class="quest">
      <?php
      echo $web6." ";
      if ($fieldd1 != "on") {
        $em = BreakEMail($email);
        ?>
        <b><a href="JavaScript:WriteMailTo('<?php echo addslashes(urlencode($author)); ?>','<?php echo $em[0]; ?>','<?php echo $em[1]; ?>','<?php echo $em[2]; ?>')"><?php echo addslashes($author); ?></a></b>
        <?php
      }
      else {
        echo "<b>".$author."</b>";
      }
      echo " ".$web7." ".FormatDate($creadate);
      if ($fieldb1 != "") {
        echo "<br />
        <img src=\"inc/img/general/gbkurl.gif\" width=\"17\" height=\"17\" align=\"middle\" alt=\" \"/>&nbsp;&nbsp;<a href=\"".$fieldb1."\" target=\"_blank\">".$fieldb1."</a>";
      }
      ?>
      </td></tr><tr><td colspan="2" class="rep"><?php echo $fieldc1; ?>
      <?php
      if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $drtuser[22]=="on")) {
        ?>
        <p align="right">
        <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=guestbk&amp;form=2&amp;id=<?php echo $dbwork[$i][1]; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/edit.gif" border="0" alt="<?php echo $web308; ?>" title="<?php echo $web308; ?>"/></a>
        <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=guestbk&amp;act=i&amp;id=<?php echo $dbwork[$i][1]; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/desact.gif" border="0" alt="<?php echo $web333; ?>" title="<?php echo $web333; ?>"/></a>
        <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=guestbk&amp;del=<?php echo $dbwork[$i][1]; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/del.gif" border="0" alt="<?php echo $web324; ?>" title="<?php echo $web324; ?>"/></a></p>
        <?php
      }
      ?>
      </td></tr>
      </table>
      <?php
      if ($i < Min($serviz[7]*$id, count($dbwork))-1) {
        echo "<hr />";
      }
    }
  } else if (!empty($pg)) {
        echo '<p>'.$web36.'</p>';
  }
  echo GetNavBar("guestbk.php?lng=".$lng."&amp;pg=".$pg."&amp;id=", count($dbwork), $id, $serviz[7]);
}
btable();
include("inc/bpage.inc");
?>
