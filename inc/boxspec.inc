<?php
/*
    Special Box - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v1.0 (30 December 2002)     : initial release
      v1.7 (28 January 2003)      : upgraded relative linking to smileys (for scripts run in file/ directory)
      v2.2 (22 April 2003)        : cleanup in the images organization
      v2.3 (27 July 2003)         : changed str_replace to PathToImage() function
      v2.4 (24 September 2003)    : created $dbspecial variable
      v3.0 (25 February 2004)     : added skin management (by Nicolas Alves)
      v4.0 (06 December 2004)     : added the sideboxes specific style (by Isa)
      v4.6.0 (04 June 2007)       : special box can be added under center box (thanks Ghaz)
      v4.6.3 (30 August 2007)     : added gift img when it is dispayed in center box (by Icare)
      v4.6.5 (05 December 2007)   : changed $topmess by $sp_title (by Icare)
      v4.6.15 (30 June 2011)      : added private group management (by Icare)
	  v4.6.20 (24 May 2012)       : corrected btable1, btable (by Saxbar)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "boxspec.inc")) {
  header("location:../index.php");
  die();
}

include(DBSPECIAL);
if ($lng == $lang[0]) {
  $sp_title = $nom[5];
  $txtspe = $special1;
}
else {
  $sp_title = $nom[15];
  $txtspe = $special2;
}
/// début modif accès réservé
$acces = "ok";
if ($specialgroup != "") {
  $acces = "no";
  if ($userprefs[1] != "") {
    include_once (CHEMIN.'inc/func_groups.php');
    if (CheckGroup($specialgroup, $userprefs[1])) $acces ="ok";
  }
}
if ($acces == "ok") {
/// fin modif accès privé
  $txtspe = PathToImage($txtspe);
  if ( $onemenu == "1") {
    htable1($sp_title, "100%");
  }
  else {
    if ($page[9] != "") {
 	    $sp_title = "<img src=\"".CHEMIN."img/cadeau.gif\" align=\"right\" alt=\"cadeau.gif\" />".$sp_title;
    }
    htable($sp_title, "100%");
  }
?>
  <div class="box"><?php echo $txtspe; ?></div>
<?php
  if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $drtuser[17]=="on")) {
?>
    <p align="right"><a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=special"><img src="<?php echo CHEMIN; ?>inc/img/general/edit.gif" border="0" alt="<?php echo $web308; ?>" title="<?php echo $web308; ?>" /></a></p>
<?php
  }
  if ( $onemenu == "1") btable1($sp_title);
  else btable($sp_title);
} /// modif accès privé
?>
