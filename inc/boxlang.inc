<?php
/*
    Language choose Box - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alvès,
    followed by Albert Aymard, Jean Michel Misrachi and all the Team
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.7 (28 January 2003)   : added $endurl variable to switch language without going back to index page (thanks Alex)
      v2.2 (22 April 2003)     : replaced <P><CENTER> by <P align="center"> otherwise IE takes the default font instead of the required one (Thanks Michel)
                                 cleanup in the images organization
      v2.3 (27 July 2003)      : added dynamic menu option management ($pg not in URL)
      v2.4 (24 September 2003) : added alternative label for language flag
      v3.0 (25 February 2004)  : simplified language switch parametrization
      v4.0 (06 December 2004)  : added alt tags to img and removed border tag for non-linked img (by Isa)
                                 removed an empty cell (by Isa)
      v4.5 (30 April 2005)       : corrected flags alignment, thanks to Ricsen (by Icare)
      v4.6.0 (04 June 2007)      : new release(by Djchouix))
      v4.6.3 (30 August 2007)    : display only the necessary lang flag (by Icare)
      v4.6.5 (10 November 2007)  : corrected bad title for flag2 (by Icare)
      v4.6.10 (7 September 2009) : corrected #262
	  v4.6.18 (09 February 2012) : added $hflags and $varget (by Saxbar)
	  v4.6.20 (24 May 2012)      : corrected border (by Saxbar)
	  v4.6.21 (18 October 2012)  : corrected display flag (by Saxbar)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "boxlang.inc")) {
  header("location:../index.php");
  die();
}

if (!isset($onemenu) || $onemenu == 0) { //Menu horizontal
	$flags = (($page[9] != '') ? '<br />' : '');
	$flags .= '
<form name="uflagsh" method="post" action="">'.$hflags;
	if ($lng == $lang[0]) {
		$flags .= '
  <input type="hidden" name="lng" value="'.$lang[1].'" />
  <input type="image" src="'.$flag2.'" alt="'.$web87.': '.$lang[1].'" style="border:none;" title="'.$web87.': '.$lang[1].'" />';
	} else {
		$flags .= '
  <input type="hidden" name="lng" value="'.$lang[0].'" />
  <input type="image" src="'.$flag1.'" alt="'.$web87.': '.$lang[0].'" style="border:none;" title="'.$web87.': '.$lang[0].'" />';
	}
	$flags .= '
</form>';
} else { //Menu boite latérale
    $title_menu = '
<form name="uflagsv" method="post" action="">'.$hflags;
    if ($lng == $lang[0]) {
        $title_menu .= '
  <input type="hidden" name="lng" value="'.$lang[1].'" />
  <input type="image" src="'.$flag2.'" alt="'.$web87.': '.$lang[1].'" style="border:none;vertical-align:middle;" title="'.$web87.': '.$lang[1].'" />';
    } else {
        $title_menu .= '
  <input type="hidden" name="lng" value="'.$lang[0].'" />
  <input type="image" src="'.$flag1.'" alt="'.$web87.': '.$lang[0].'" style="border:none;vertical-align:middle;" title="'.$web87.': '.$lang[0].'" />';
    }
    $title_menu .= '&nbsp;&nbsp;'.$nom[$j + 44].'
</form>';
}
?>
