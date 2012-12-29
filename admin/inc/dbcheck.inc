<?php
/*
    DataBase Integrity Check - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.9 (11 February 2003)  : initial release
      v2.0 (27 February 2003)  : added advanced photo index rebuild
                                 added auxiliary indexes rebuild in index database rebuild
      v2.1 (10 March 2003)     : rewrote this script from scratch, to include DB check and indexes rebuild in one
                                 single routine, with a range of docs to check (to avoid time out in script exec)
      v2.2 (22 April 2003)     : no change
      v2.3 (27 July 2003)      : added forms style management (by Nicolas Alves)
      v2.4 (24 September 2003) : added react to an article option
                                 fixed a bug that occured when the last document was created but not recorded in the indexes
                                 added ReadDoc() and WriteDoc() functions
                                 added FileDBExist() function
                                 created $typ_[name] variables
      v3.0 (25 February 2004)  : added skins management (by Nicolas Alves)
                                 moved CheckDBmp() from this new file to new funcdbchk.inc for batch processin
      v4.0 (06 December 2004)  : added multi-admin management (by Nicolas Alves)
	                               added page title (by Jean-Mi)
	    v4.6.1 (02 July 2007)    : corrected test for CheckDBmP()  (thanks JeanMi)
      v4.6.10 (7 September 2009)    : corrected W3C
*/

if (stristr($_SERVER["SCRIPT_NAME"], "dbcheck.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[8]=="") {
    $nomzone=$admin278;
    include("access.inc");
    exit();
  }
}
  include("inc/funcdbchk.inc");
  $topmess = $admin281;
  include(CHEMIN."inc/hpage.inc");
  htable($admin281, "100%");
  ?>
  <p align="center"><?php echo $admin280.$admin305; ?></p>
  <p>&nbsp;</p>
  <?php
  $max1 = ReadCounter(NEXTID);
  $max2 = 10*ceil(($max1+10)/10);
  switch ($integr) {
  case 1 :
    echo $admin295;
    echo $admin296;
    if (empty($range1)) {
      $range1 = 1;
    }
    else {
      $range1 = Min($range1, $max1);
    }
    if (empty($range2)) {
      $range2 = $max2;
    }
    if ($range2 < $range1) {
      $range2 = $range1;
    }
    if (CheckDBmP($range1, $range2) == 0) {
      echo "<div align='center' style='padding:10px;'><span class='forum2'><b>".$admin297."</b></span></div>";
    }
    echo $admin298;
    break;
  case 2 :
    if (empty($delta)) {
      $delta = 100;
    }
    else {
      $delta = min(1000, max($delta, 1));
    }
    echo $admin685;
    ?>
    <script type="text/javascript">
      PopupWindow('inc/dbbatch.php?lng=<?php echo $lng ?>&range1=<?php echo $range1 ?>&range2=<?php echo $range2 ?>&delta=<?php echo $delta ?>&checkit=<?php echo $range1 ?>','dbbatch',400,200,'no','no')
    </script>
    <?php
    break;
  default :
    $delta = 100;
  }
  ?>
  <p>&nbsp;</p>
  <form name="integrity1" action="admin.php" method="post">
  <input type="hidden" name="lng" value="<?php echo $lng; ?>" />
  <input type="hidden" name="pg" value="dbcheck" />
  <input type="hidden" name="integr" value="1" />
  <fieldset>
  <table cellspacing="0" cellpadding="2" align="center" border="0" summary="">
  <tr><td><p><?php echo $admin333; ?></p></td><td><input name="range1" class="texte" type="text" value="1" size="10" /></td><td><p> (1)</p></td></tr>
  <tr><td><p><?php echo $admin334; ?></p></td><td><input name="range2" class="texte" type="text" value="<?php echo $max1; ?>" size="10" /></td><td><p> (<?php echo $max1; ?>)</p></td></tr>
  </table>
  <p>&nbsp;</p>
  <p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin279; ?>"><?php echo $admin279; ?></button><?php echo $boutonright; ?></p>
  </fieldset>
  </form>
  <br />
  <form name="integrity2" action="admin.php" method="post">
  <input type="hidden" name="lng" value="<?php echo $lng; ?>" />
  <input type="hidden" name="pg" value="dbcheck" />
  <input type="hidden" name="integr" value="2" />
  <fieldset>
  <table cellspacing="0" cellpadding="2" align="center" border="0" summary="">
  <tr><td><p><?php echo $admin333; ?></p></td><td><input name="range1" class="texte" value="1" type="text" size="10" /></td><td></td></tr>
  <tr><td><p><?php echo $admin334; ?></p></td><td><input name="range2" class="texte" value="<?php echo $max2; ?>" type="text" size="10" /></td><td></td></tr>
  <tr><td><p><?php echo $admin686; ?></p></td><td><input name="delta" class="texte" value="<?php echo $delta; ?>" type="text" size="10" /></td><td></td></tr>
  </table>
  <p>&nbsp;</p>
  <p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin575; ?>"><?php echo $admin575; ?></button><?php echo $boutonright; ?></p>
  </fieldset>
  </form>

  <hr /><p align="center">
  <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b></p>
  <?php
  btable();
  include(CHEMIN."inc/bpage.inc");

?>
