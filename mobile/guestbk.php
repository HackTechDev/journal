<?php
/*
    Guestbook for PDA - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v2.3 (27 July 2003)      : initial release (thanks Palmipod)
      v2.4 (24 September 2003) : added ReadDoc() function
                                 added GetCurrentDateTime() and FormatDate() function to ease various date and time formatings
                                 secured transfered parameters
                                 created $typ_[name] variables
      v4.0 (06 December 2004)  : added page title (by Jean-Mi)
            		             added alt tag to img and removed border tag for unlinked img (by Isa)
*/

header("Pragma: no-cache");
define("CHEMIN", "../");
include(CHEMIN."inc/includes.inc");

if ($serviz[12] != "on") {
  exit($web143);
}

$section_index = 12;
$section_name = $lng == $lang[0] ? $nom[9] : $nom[19];
include('inc/members.inc');
if ($section_access) {

    $id = strip_tags($id);

    $dbwork = SelectDBFields(TYP_GUESTBK,"a","");
    @rsort($dbwork);

    if ($lng == $lang[0]) {
      $topmess = $nom[9];
    } else {
      $topmess = $nom[19];
    }
    include("inc/hpalm.inc");
    if ($lng == $lang[0]) {
      $i = 0;
    }
    else {
      $i = 10;
    }
    echo "<center><b>".$nom[$i+9]."</b></center><hr />";
    if (empty($id)) {
      $id = 1;
    }
    if (!empty($dbwork)) {
      for ($i = $serviz[7]*($id-1); $i < Min($serviz[7]*$id, count($dbwork)); $i++) {
        ReadDoc(DBBASE.$dbwork[$i][1]);
    ?>
    <b><?php echo $web39.$fielda1; ?></b>&nbsp;
    <?php
        echo $web6." ";
        echo "<b>".$author."</b>";
        echo " ".$web7." ".FormatDate($creadate);
        $txt1 = PathToImage($fieldc1);
    ?>
    <br>&nbsp;&nbsp;&nbsp;&nbsp;
    <img src="<?php echo CHEMIN; ?>inc/img/general/gbkurl.gif" width="17" height="17" alt="" />&nbsp;&nbsp;<a href="<?php echo $fieldb1; ?>" target="_blank"><?php echo $fieldb1; ?></a><br><br>
    <?php echo $txt1; ?><br>
    <?php
        if ($i < Min($serviz[7]*$id, count($dbwork))-1) {
          echo "<hr />";
        }
      }
    }
    if (count($dbwork)>$serviz[7])
    {
      echo '<hr />'.GetNavBar("guestbk.php?lng=".$lng."&amp;id=", count($dbwork), $id, $serviz[7]);
    }
    include("inc/bpalm.inc");
}
?>
