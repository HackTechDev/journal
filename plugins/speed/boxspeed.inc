<?php
/*
    Speed Box - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.6.3 (30 August 2007)     : initial release by Icare
	  v47.6.20 (24 May 2012)      : corrected display btable1, btable (by Saxbar)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "boxspeed.inc")) {
  header("location:../index.php");
  die();
}
define("CHEMIN", "../../");

if ($lng == "fr") {
  include("fr-speed.inc");
}
else {
  include("en-speed.inc");
}
$speedtitle = "<img src=\"".CHEMIN."inc/img/icons/".$page[9]."/stats.gif\" align=\"right\" alt=\"speed.gif\" />".$speed7;
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
    res='';
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
if ( $onemenu == "1") htable1($speedtitle, "100%");
else htable($speedtitle, "100%");
?>
<div class="box">
<p align="center"><h3><?php echo $speed16; ?></h3></p>
<p><?php echo $speed17; ?></p>
<form name="countkos" action="speed.php?lng=<?php echo $lng; ?>"><center>
<?php echo $boutonleft; ?><input class="bouton" type="button" value="<?php echo $speed18; ?>" title="<?php echo $speed18; ?>" onClick="Checkkos()" /><?php echo $boutonright; ?><br />
<?php echo $speed19; ?><input type="text" name="info" size="40">
</center>
</form>
</div>
<?php
if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $drtuser[17]=="on")) {
?>
<p align="right"><a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=special"><img src="<?php echo CHEMIN; ?>inc/img/general/edit.gif" border="0" alt="<?php echo $web308; ?>" title="<?php echo $web308; ?>" /></a></p>
<?php
}
if ( $onemenu == "1") btable1($speedtitle);
else btable($speedtitle);
?>
