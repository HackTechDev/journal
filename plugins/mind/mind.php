<?php
/*
    Mind Plugin - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    This is a sample external PHP script that integrates with GuppY

    Version History :
      v1.7 (28 January 2003)   : initial release
      v2.3 (27 July 2003)      : Passage du tutoiement au vouvoiement
      v3.0 (25 February 2004)  : changed into Plugin
                                 added skin management
      v4.0 (25 December 2004)  : added alt tag to img and removed border tag for unlinked img (by Isa)
      v4.0.4 (Février 2005)    : corrected the name of function WriteTable (by Jean-Mi)
*/

header("Pragma: no-cache");
define("CHEMIN", "../../");
include(CHEMIN."inc/includes.inc");

if ($lng == "fr") {
  include("fr-mind.inc");
}
else {
  include("en-mind.inc");
}

include(CHEMIN."inc/hpage.inc");
$alphaArray = array("a", "n", "b", "d", "f", "h", "{", "i", "l", "v", "x", "z", "I", "J", "M", "N", "o", "O", "R", "S", "T", "U", "m", "6", "^", "u", "_", "[", "]");

function init_seed() {
  list($usec, $sec) = explode(' ', microtime());
  return (float) $sec + ((float) $usec * 100000);
}

function ChooseMind() {
  srand(init_seed());
  $ax = rand(0,26);
  return $ax;
}

/// Fonction renommée pour éviter un conflit avec mes plugins
function WriteMindTable($ax) {
  global $alphaArray;
  $tablo = "<table border=0 cellspacing=1 cellpadding=1 width='100%'><tr>";
  $j = 1;
  for ($i = 99 ; $i >= 0 ; $i-- ) {
    $a = rand(0,26);
    if ($i%9 == 0 &&  $i < 89) {
      $a = $ax;
    }
    $tablo .= "<td><font color='red' face='verdana'>".$i."</font></td><td><font color='blue' face='wingdings'>".$alphaArray[$a]."</font></td>";
    if ($j%10 == 0) {
      $tablo .= "</tr><tr>";
    }
	$j++;
  }
  $tablo .= "</table>";
  return $tablo;
}

$mindtitle = "<img src=\"mind.gif\" width=\"32\" height=\"32\" align=\"right\" alt=\"mind.gif\" />".$mind10;
htable($mindtitle, "100%");

if ($guess == 0) {
  $rndax = ChooseMind();
?>
<p><?php echo $mind3; ?></p>
<p><?php echo $mind11; ?><br />
<?php echo $mind12; ?><br />
<?php echo $mind13; ?><br />
<?php echo $mind14; ?><br /><br /></p>
<?php echo WriteMindTable($rndax); ?>
<form name="guessmind1" action="mind.php?lng=<?php echo $lng; ?>&amp;guess=<?php echo $rndax+1; ?>" method="post">
<center>
<?php echo $boutonleft; ?><input class="bouton" type="submit" value="<?php echo $mind15; ?>" title="<?php echo $mind15; ?>" /><?php echo $boutonright; ?><br />
</center>
</form>
<?php
}
else {
?>
<p><?php echo $mind16; ?><font size='+2' color='blue' face='wingdings'><?php echo $alphaArray[$guess-1]; ?></font><p>
<form name="guessmind2" action="mind.php?lng=<?php echo $lng; ?>&amp;guess=0" method="post">
<center>
<?php echo $boutonleft; ?><input class="bouton" type="submit" value="<?php echo $mind17; ?>" title="<?php echo $mind17; ?>" /><?php echo $boutonright; ?><br />
</center>
</form>
<?php
}
btable();
include(CHEMIN."inc/bpage.inc");
?>
