<?php
/*
    Photos - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v1.0 (30 December 2002)       : initial release
      v2.0 (27 February 2003)       : corrected image file size calculation
                                      merged the 2 boxes for photo displaying
      v2.2 (22 April 2003)          : changed source code for all accesses to the pathinfo() PHP function for compatibility with PHP3 as pathinfo() only works with PHP4
                                      cleanup in the images organization
      v2.4 (24 September 2003)      : added section icon in central boxes
                                      secured transfered parameters
      v4.0 (06 December 2004)       : added page title (by jmmis)
                                      added alt tags to img and removed border tag for non-linked img (by Isa)
                                      added members management (by Nicolas Alves)
      v4.5 (15 April 2005)          : optimization and new look (by Icare)
      v4.6.0 (04 June 2007)         : new release by Icare
      v4.6.10 (7 September 2009)    : corrected #274
      v4.6.11 (11 December 2009)    : changed width by style=width in cells (by Icare)
      v4.6.15 (30 June 2011): added private management for photos (by Icare)
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");

if ($serviz[9] != "on") {
  exit($web143);
}
$id = strip_tags($id);

$photo = array();
$dbwork = ReadDBFields(DBPHOTO);
@sort($dbwork);
for ($i = 0; $i < count($dbwork); $i++) {
  ReadDoc(DBBASE.$dbwork[$i][4]);
  /// début modif groupe privé
  $acces = "ok";
  if ($fieldmod  != "") {
    $acces = "no";
    if ($userprefs[1] != "") {
      include_once (CHEMIN.'inc/func_groups.php');
      if (CheckGroup($fieldmod , $userprefs[1])) $acces ="ok";
    }
  }
  if ($acces == "ok") {
  $photo[$i][0] = $fieldd1; //img
  if ($lng == $lang[0]) {
  $photo[$i][1] = $fieldb1; //name
  }
  else {
  $photo[$i][1] = $fieldb2; //name
  }
  $photo[$i][2] = $fileid; //id
  }
  /// fin modif groupe privé
}

sort($photo);
if ($lng == $lang[0]) {
  $topmess = strip_tags($nom[2]);
}
else {
  $topmess = strip_tags($nom[12]);
}
if ($page[9] != "") {
  $topmess = "<img src=\"".CHEMIN."inc/img/icons/".$page[9]."/photo.gif\" align=\"right\" width=\"32\" height=\"32\" alt=\"photo.gif\"/>".$topmess;
}
include("inc/hpage.inc");
htable($topmess, "100%");
echo "<br /><br />";
if ($members[0]=="on" && $userprefs[1]=="" && $members[2]=="on") {
   echo "<p align=\"center\">".$web342."</p><br />";
   echo "<p align=\"center\">[ <a href=\"".CHEMIN."user.php?lng=".$lng."\">".$web343."</a> ]</p><br />";
}
else {
   $d = ""; $f = ""; // for first and last img
   if (empty ($id)) {
     $id = 1;
   }
   $idp = $id-1;
   if ($idp < 1) {
      $idp = 0; $d = "_n";
   }
   $idn = $id+1;
   $idf = count($photo);
   if ($idn > count($photo)) {
      $idn = count($photo); $f = "_n";
   }
   $dim = getimagesize(CHEMIN."photo/".$photo[($id - 1)][0]);
   $popw = $dim[0]+28; //width popup
	 $poph = $dim[1]+72; //height popup
	 if ($dim[0] < $dim[1]) $dia ="height"; else $dia="width";
   ?>
   <center>
   <hr />
   <table align="center" border="0" style="margin:2px;padding:5px;" summary="">
   <tr valign="bottom">
   <td><p>
   <a href="photos.php?lng=<?php echo $lng; ?>&amp;id=1" title="<?php echo $web339; ?>"><img src="inc/img/general/debut<?php echo $d; ?>.gif" border="0" alt="<?php echo $web339; ?>" title="<?php echo $web339; ?>"/></a>&nbsp;
   <a href="photos.php?lng=<?php echo $lng; ?>&amp;id=<?php echo $idp; ?>" title="<?php echo $web32; ?>"><img src="inc/img/general/precedent<?php echo $d; ?>.gif" border="0" alt="<?php echo $web32; ?>" title="<?php echo $web32; ?>"/></a></p></td>
   <td style="width:210px">
   <table class="bord" align="center" style="margin:2px;padding:2px;vertical-align:bottom;" summary="">
   <tr><td class="quest" style="height:200px;width:200px;text-align:center;vertical-align:middle;">
   <a href="photoview.php?lng=<?php echo $lng; ?>&amp;pg=<?php echo $photo[($id - 1)][2]; ?>" onclick="javascript:PopupWindow('photoview.php?lng=<?php echo $lng; ?>&amp;pg=<?php echo $photo[($id - 1)][2]; ?>','Photo',<?php echo $popw; ?>,<?php echo $poph; ?>,'no','no');return false;" target="_blank" title="<?php echo $web297; ?>">
   <img src="<?php echo CHEMIN; ?>photo/<?php echo $photo[($id - 1)][0]; ?>" <?php echo $dia; ?>="150" border="0" style="vertical-align:middle" alt="<?php echo $web297; ?>" title="<?php echo $web297; ?>" /></a>
   </td></tr>
   </table>
   </td>
   <td><p>
   <a href="photos.php?lng=<?php echo $lng; ?>&amp;id=<?php echo $idn; ?>" title="<?php echo $web34; ?>"><img src="inc/img/general/suivant<?php echo $f; ?>.gif" border="0" alt="<?php echo $web34; ?>"/></a>&nbsp;
   <a href="photos.php?lng=<?php echo $lng; ?>&amp;id=<?php echo $idf; ?>" title="<?php echo $web338; ?>"><img src="inc/img/general/fin<?php echo $f; ?>.gif" border="0" alt="<?php echo $web338; ?>"/></a></p></td>
   </tr>
   </table>
   <p align="center"><b><?php echo $photo[($id - 1)][1]; ?></b></p>
   </center><hr />
   <?php
   if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $drtuser[18]=="on")) {

     ?>
     <div style="cursor:pointer;text-align:right">
       <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=photo&amp;form=2&amp;id=<?php echo $photo[($id - 1)][2]; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/edit.gif" border="0" alt="<?php echo $web308; ?>" title="<?php echo $web308; ?>"/></a>
       <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=photo&amp;act=i&amp;id=<?php echo $photo[($id - 1)][2]; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/desact.gif" border="0" alt="<?php echo $web333; ?>" title="<?php echo $web333; ?>"/></a>
       <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=photo&amp;del=<?php echo $photo[($id - 1)][2]; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/del.gif" border="0" alt="<?php echo $web324; ?>" title="<?php echo $web324; ?>"/></a>
     </div>
     <?php
   }
}
btable();
include("inc/bpage.inc");
?>
