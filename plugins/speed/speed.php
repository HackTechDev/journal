<?php
/*
    Speed Plugin - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    This is a sample external PHP script that integrates with GuppY

    Version History :
      v1.7 (28 January 2003)   : initial release
      v2.2 (22 April 2003)     : replaced <P><CENTER> by <P align="center"> otherwise IE takes the default font instead of the required one (Thanks Michel)
      v3.0 (25 February 2004)  : changed into Plugin
                                 added skins management
      v4.0 (06 December 2004)  : no change
      v4.6.14(14 February 2011)   : corrected display icon(thanks Jean-Mi)	  
*/

header("Pragma: no-cache");
define("CHEMIN", "../../");
include(CHEMIN."inc/includes.inc");
if ($lng == "fr") {
  include("fr-speed.inc");
}
else {
  include("en-speed.inc");
}
$speedtitle = "<img src=\"speed.gif\" align=\"right\" alt=\"speed.gif\" />".$speed7;
include(CHEMIN."inc/hpage.inc");
?>

<script language="javascript">
    var tjs_img;
    var tjs_src="<?php echo CHEMIN; ?>img/robot.gif";
    var tjs_size=19925;
    var tjs_delai=100;
    var tjs_nb=-1;
    var tjs_delai_max=20000;
    var timer1=0; var timer2=0;
    var tjs_fin="";

function Checkkos() {
    tjs_img=new Image();
    timer1=new Date();
    timer1=timer1.getTime();
    tjs_img.src=tjs_src+"?dummy="+timer1;
    tjs_nb=0;
    document.countkos.info.value="<?php echo $speed9; ?>";
    setTimeout("Timerkos()",tjs_delai);
  }

function Timerkos() {
    var anim="-"
    tjs_nb++;
    document.countkos.info.value="<?php echo $speed9; ?>";
    if (tjs_nb*tjs_delai>=tjs_delai_max) {
      tjs_fin=EvalConnexion(0);
      document.countkos.info.value=tjs_fin;
    }
    else {
      if (tjs_img.complete) {
        timer2=new Date(); timer2=timer2.getTime();
        tjs_fin=EvalConnexion(tjs_size/(timer2-timer1));
        document.countkos.info.value=tjs_fin;
      }
      else {
        setTimeout("Timerkos()",tjs_delai);
      }
    }
  }

function EvalConnexion(kos) {
    tjs_nb=-1;
    res="";
    if (kos==0) { res="<?php echo $speed10; ?>"; }
    if ((kos>0)&&(kos<3)) { res="<?php echo $speed11; ?>"; }
    if ((kos>3)&&(kos<6)) { res="<?php echo $speed12; ?>"; }
    if ((kos>6)&&(kos<100)) { res="<?php echo $speed13; ?>"; }
    if (kos>100) { res="<?php echo $speed14; ?>"; }
    kos=Math.round(kos*10)/10;
    return res+" (" + kos +" <?php echo $speed15; ?>)";
 }
</script>
<?php
htable($speedtitle, "100%");
?>
<p align="center"><h3><?php echo $speed16; ?></h3></p>
<p><?php echo $speed17; ?></p>
<form name="countkos" action="speed.php?lng=<?php echo $lng; ?>"><center>
<?php echo $boutonleft; ?><input class="bouton" type="button" value="<?php echo $speed18; ?>" title="<?php echo $speed18; ?>" onClick="Checkkos()" /><?php echo $boutonright; ?><br />
<?php echo $speed19; ?><input type="text" name="info" size="40">
</center>
</form>
<?php
btable();
include(CHEMIN."inc/bpage.inc");
?>
