<?php
/*
    Free Boxes - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v1.9 (11 February 2003)     : initial release
      v2.2 (22 April 2003)        : cleanup in the images organization
      v2.3 (27 July 2003)         : changed str_replace to PathToImage() function
      v2.4 (24 September 2003)    : created $dbfreebox variable
                                    added 3 additional free boxes (by Nicolas Alves and Laurent Duveau)
      v3.0 (25 February 2004)     : added skin management (by Nicolas Alves)
      v4.0 (06 December 2004)     : added the box specific style (by Isa)
      v4.6.0 (04 June 2007)       : special box can be added under center box (by Ghaz)
      v4.6.10 (7 September 2009)  : corrected #274
      v4.6.15 (30 June 2011)      : added private group management (by Icare)
	  v4.6.20 (24 May 2012)       : corrected btable1, btable (by Saxbar)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "boxfree1.inc")) {
  header("location:../index.php");
  die();
}

include(DBFREEBOX1);
if ($lng == $lang[0]) {
  $titfree = $freetitle1;
  $txtfree = $freetext1;
}
else {
  $titfree = $freetitle2;
  $txtfree = $freetext2;
}
/// début modif accès réservé
$acces = "ok";
if ($freegroup != "") {
  $acces = "no";
  if ($userprefs[1] != "") {
    include_once (CHEMIN.'inc/func_groups.php');
    if (CheckGroup($freegroup, $userprefs[1])) $acces ="ok";
  }
}
if ($acces == "ok") {
/// fin modif accès privé
  $txtfree = PathToImage($txtfree);

  if ( $onemenu == "1") htable1($titfree, "100%");
  else htable($titfree, "100%");

?>
  <div class="box"><?php echo $txtfree; ?></div>
<?php
  if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $drtuser[26]=="on")) {
?>
    <p align="right"><a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=freebox1"><img src="<?php echo CHEMIN; ?>inc/img/general/edit.gif" border="0" alt="<?php echo $web308; ?>" title="<?php echo $web308; ?>" /></a></p>
<?php
  }
  if ($onemenu == "1") btable1($titfree);
  else btable($titfree);
} /// modif accès privé
?>
