<?php
/*
    Search Box - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.7 (28 January 2003)   : bug fix (a $chemin variable was badly passed to the HTML rendering)
      v2.2 (22 April 2003)     : cleanup in the images organization
      v2.3 (27 July 2003)      : added forms style management (by Nicolas Alves)
                                 added "Search in" only one type of content option
      v2.4 (24 September 2003) : added Search in one language only option
                                 added react to an article option
                                 created $typ_[name] variables
      v2.4p2 (28 Sept. 2003)   : fixed bug in which the search engine would return no answer if site was monolingual
      v3.0 (25 February 2004)  : added skin management (by Nicolas Alves)
                                 fixed bug in search non working for News and Photos
      v4.0 (06 December 2004)  : reduced the trans image's width to 1 to prevent the deformation of the box (by Isa)
                                 added alt tags to img and removed border tag for non-linked img (by Isa)
                                 corrected a quote that had been forgotten (by Isa)
      v4.5 (27 February 2005)  : changed initialisation for searchlng (by Jean-Mi)
      v4.6.6 (14 April 2008)   : changed serviz[21] by serviz[9] for searching photos (by JeanMi)
      v4.6.7 (23 April 2008)   : new release (by JeanMi)
      v4.6.8 (10 May 2008)     : corrected select list (by JeanMi)
      v4.6.9 (25 December 2008): move of the function SearchOption to functions.php #219
	  v4.6.20 (24 May 2012)    : added $boxtitle (by Saxbar)
                                 corrected btable1 (by Saxbar)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "boxsearch.inc")) {
  header("location:../index.php");
  die();
}

if ($lng == $lang[0]) {
  $i = 0;
  $j = 0;
}
else {
  $i = 1;
  $j = 10;
}

$options = '';
$options .= SearchOption($serviz[3]  == "on" || $serviz[22] == "on", $members[1] != 'on', TYP_ART, $web169);
$options .= SearchOption($serviz[29] == "on", $members[1]  != 'on', TYP_REACT, $web187);
$options .= SearchOption($serviz[10] == "on", $members[7]  != 'on', TYP_DNLOAD, $nom[1+$j]);
$options .= SearchOption($serviz[14] == "on", $members[4]  != 'on', TYP_FAQ, $nom[24+$i]);
$options .= SearchOption($serviz[13] == "on", $members[5]  != 'on', TYP_FORUM, $nom[22+$i]);
$options .= SearchOption($serviz[12] == "on", $members[12] != 'on', TYP_GUESTBK, $nom[9+$j]);
$options .= SearchOption($serviz[11] == "on", $members[3]  != 'on', TYP_LINKS, $nom[3+$j]);
$options .= SearchOption($serviz[8]  == "on", $members[13] != 'on', TYP_NEWS, $nom[7+$j]);
$options .= SearchOption($serviz[53] == "on", $members[15] != 'on', TYP_BLOG, $nom[42+$i]);
$options .= SearchOption($serviz[9]  == "on", $members[2]  != 'on', TYP_PHOTO, $nom[2+$j]);
$options .= SearchOption($serviz[47] == "on", $members[14] != 'on', TYP_AGENDA, $web436);

$boxtitle = $nom[$i+20];
htable1($boxtitle, "100%");

echo '
<form action="'.CHEMIN.'search.php" method="post" name="formS">
  <input type="hidden" name="lng" value="'.$lng.'" />
  <p align="center">
    <input name="search" class="texte" type="text" size="18" />
    <br />
    <select name="searchin">';
echo '
      <option value="" selected="selected">'.$web168.'</option>';
echo $options;
echo '
    </select>';
if ($lang[1] != "") {
?>
<br />
<select name="searchlng">
<option value=""><?php echo "[".$lang[0]."] ".$web177." [".$lang[1]."]"; ?></option>
<option value="<?php echo $lang[0]; ?>"<?php echo ($lng == $lang[0] ? " selected='selected'" : ""); ?>><?php echo "[".$lang[0]."] ".$web178; ?></option>
<option value="<?php echo $lang[1]; ?>"<?php echo ($lng == $lang[1] ? " selected='selected'" : ""); ?>><?php echo "[".$lang[1]."] ".$web178; ?></option>
</select>
<?php
}
else {
?>
<input type="hidden" name="searchlng" value="<?php echo $lang[0]; ?>"/>
<?php
 }
?>
<br /><?php echo $boutonleft; ?><button type="submit" title="<?php echo $web58; ?>" onclick="javascript:document.formS.submit();"><?php echo $web58; ?></button><?php echo $boutonright; ?>
</p></form>
<?php
btable1($boxtitle);
?>
