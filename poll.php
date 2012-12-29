<?php
/*
    Poll - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v2.1 (10 March 2003)     : added addslashes() to var in Javascript functions (to avoid errors)
      v2.2 (22 April 2003)     : replaced $serviz[] exit by new value
                                 access to ippoll.dtb standardized
                                 cleanup in the images organization
      v2.4 (24 September 2003) : created $dbpoll and $dbippoll variables
                                 moved DejaVote() function from poll.php to functions.php (now also used for documents counters)
                                 and upgraded CompteVisites() function accordingly
      v4.0 (06 December 2004)  : added page title (by Jean-Mi)
                                 added alt tags to img and removed border tag for non-linked img (by Isa)
                                 arranged the margins for better display (by Isa)
      v4.6.0 (04 June 2007)    : corrected mistaken return on error (by Djchouix)
      v4.6.5 (05 December 2007)  : deletion of useless $topmess and second language test (by Icare)
      v4.6.6 (14 April 2008)     : corrected language test and $topmess, thanks JeanMi
      v4.6.10 (7 September 2009)    : corrected #274
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");
 if ($serviz[23] != "on") {
    exit($web143);
}
if (!empty($choix)) {
  $vote = DejaVote(DBIPPOLL, 3600*24*7);
  if ($vote[0] == false) {
    $ter = ReadDBFields(DBPOLL);
    if ($choix > 0 && $choix < count($ter)) {
      $ter[$choix][3] = $ter[$choix][3]+1;
      WriteDBFields(DBPOLL, $ter);
    }
  }
}
include("inc/poll.inc");
$bar = 200/$maxval;
$topmess = ($lng == $lang[0] ? $nom[6].' - '.$commun[0][0] : $nom[16].' - '.$commun[0][1]);
include("inc/hpage.inc");
htable(($lng == $lang[0] ? $nom[6].' - '.$commun[0][0] : $nom[16].' - '.$commun[0][1]), "100%");
$j = ($lng == $lang[0] ? 0 : 1);
?>
<table cellspacing="0" cellpadding="0" align="center" border="0" summary="">
<?php
 for ($k = 1; $k < $lignes; $k++) {
 echo "<tr>\n";
 echo "<td><p><b>".$commun[$k][$j]."</b></p></td>\n";
 echo "<td nowrap=\"nowrap\"><img src=\"inc/img/bars/".$commun[$k][2].".gif\" width=\"".round($commun[$k][3]*$bar)."\" height=\"10\" hspace=\"5\" alt=\"".$commun[$k][4]."%\" /></td>\n";
 echo "<td nowrap=\"nowrap\"><p>".$commun[$k][4]."%</p></td>\n";
 if (empty($commun[$k][3])) {
    $nbvotes = 0;
}
else {
 $nbvotes = $commun[$k][3];
}
 echo "<td nowrap=\"nowrap\"><p>&nbsp;(".$nbvotes." ".$web24.")</p></td>\n";
 echo "</tr>\n";
}
?>
</table>
<p align="center"><?php echo $web25; ?> <b><?php echo $total; ?></b> <?php echo $web24; ?>.</p>
<?php
 if ($vote[0] == true) {
?>
<script type="text/javascript">
 alert('<?php echo addslashes($web26); ?>');
</script>
<?php
}
btable();
include("inc/bpage.inc");
?>
