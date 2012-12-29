<?php
/*
    Clock Sample Plugin - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    This is a sample external PHP script that integrates with GuppY

    Version History :
      v2.3 (27 July 2003)      : initial release (by Isabelle)
      v2.4 (24 September 2003) : added hideLoadingPage() Javascript function call for "Page loading" popup compatibility
      v3.0 (25 February 2004)  : changed into Plugin
      v3.1 (18 July 2004)      : added alt tag to img and removed border tag for unlinked img (by Isa)
      v4.0 (06 December 2004)  : no change
*/

header("Pragma: no-cache");
define("CHEMIN", "../../");
include(CHEMIN."inc/includes.inc");

if ($lng == "fr") {
  include("fr-clock.inc");
}
else {
  include("en-clock.inc");
}
$clocktitle = "<img src=\"clock.gif\" width=\"32\" height=\"32\" align=\"right\" alt=\"clock.gif\" />".$clock7;

include(CHEMIN."inc/hpage.inc");
htable($clocktitle, "100%");
?>

<br />
<div id="clock" align="center">

<?php
 if (!empty($page[13])) {
?>

<script type="text/javascript" language="javascript">
 hideLoadingPage();
</script>

<?php
 }
?>

<script type="text/javascript" language="javascript">
<!-- DEBUT DE CONFIGURATION -->
// Largeur des cellules en pixels (points qui marquent l'heure)
var cellwidth=7;
// Hauteur des cellules en pixels (points qui marquent l'heure)
var cellheight=7;
// Taille de la fonte qui affiche le texte. Attention de ne pas la mettre trop grande
var fontsize=10;
// Couleur de la fonte qui affiche le texte
var fontcolor="black";
// Style de la fonte gras = bold - italique = italic - aucun style = none
var fontstyle="none";
// Couleur des cellules actives
var oncolor="#d7d71e";
// Couleur des cellules inactives
var offcolor="#d3766b";
<!-- FIN DE CONFIGURATION -->
//************** Ne rien éditer ci-dessous *************//
var NS4 = (document.layers)? true : false;
var IE4 = (document.all && !document.getElementById)? true : false;
var NS6 = (document.getElementById && navigator.appName.indexOf("Netscape")>=0 )? true: false;
var binclk;
var now;
var t='<table cellspacing="1" cellpadding="0" border="0"><tr><td align="center"> </td>';
for(i=0;i<=58;i+=2)t+='<td align="left" colspan="2"><font style="font-size:'+fontsize+'px; font-weight:'+fontstyle+'; color: '+fontcolor+'">'+i+'<br /> |</font></td>';
t+='<td> </td></tr><tr><td align="center"><font style="font-size:'+fontsize+'px; font-weight:'+fontstyle+'; color: '+fontcolor+'">H : </font></td>';
for(i=0;i<=23;i++)t+=(NS4)? '<td><ilayer name="hrs'+i+'" height="'+cellheight+'" width="'+cellwidth+'" bgcolor="'+offcolor+'"></ilayer></td>' : '<td><div id="hrs'+i+'" style="position:relative; width:'+cellwidth+'px; font-size:1px; height:'+cellheight+'px; background-color:'+offcolor+'"></div></td>';
t+='<td colspan="36"><td> </td></tr><tr><td align="center"><font style="font-size:'+fontsize+'px; font-weight:'+fontstyle+'; color: '+fontcolor+'">M : </font></td>';
for(i=0;i<=59;i++)t+=(NS4)? '<td><ilayer name="min'+i+'" width="'+cellwidth+'" height="'+cellheight+'" bgcolor="'+offcolor+'"></ilayer></td>' : '<td><div id="min'+i+'" style="position:relative; width:'+cellwidth+'px; font-size:1px; height:'+cellheight+'px; background-color:'+offcolor+'"></div></td>';
t+='<td> </td></tr><tr><td align="center"><font style="font-size:'+fontsize+'px; font-weight:'+fontstyle+'; color: '+fontcolor+'">S : </font></td>';
for(i=0;i<=59;i++)t+=(NS4)? '<td><ilayer name="sec'+i+'" width="'+cellwidth+'" height="'+cellheight+'" bgcolor="'+offcolor+'"></ilayer></td>' : '<td><div id="sec'+i+'" style="position:relative; width:'+cellwidth+'px; font-size:1px; height:'+cellheight+'px; background-color:'+offcolor+'"></div></td>';
t+='<td> </td></tr><tr><td> </td><td> </td>';
for(i=1;i<=59;i+=2)t+='<td align="left" colspan="2"><font style="font-size:'+fontsize+'px; font-weight:'+fontstyle+'; color: '+fontcolor+'"> |<br />'+i+'</font></td>';
t+='</tr></table>';
document.write(t);

function getvals() {
now=new Date();
now.s=now.getSeconds();
now.h=now.getHours();
now.m=now.getMinutes();
}

function setclock() {
getvals();
if((now.h==0)&&(now.m==0)) for(i=1;i<=23;i++)setbgcolor('hrs'+i, offcolor);
if((now.s==0)&&(now.m==0)) for (i=1;i<=59;i++)setbgcolor('min'+i, offcolor);
if(now.s==0) for(i=1;i<=59;i++)setbgcolor('sec'+i, offcolor);
setbgcolor('hrs'+now.h, oncolor);
setbgcolor('min'+now.m, oncolor);
setbgcolor('sec'+now.s, oncolor);
}

function setbgcolor(idstr, color) {
if(IE4)document.all[idstr].style.backgroundColor=color;
else if(NS4)document.layers[idstr].bgColor=color;
else document.getElementById(idstr).style.backgroundColor=color;
}

window.onload=function() {
  getvals();
  for(i=0;i<=now.h;i++)setbgcolor('hrs'+i, oncolor);
  for(i=0;i<=now.m;i++)setbgcolor('min'+i, oncolor);
  for(i=0;i<=now.s;i++)setbgcolor('sec'+i, oncolor);
  setInterval('setclock()', 100);
}

window.onresize=function() {
  if(NS4)setTimeout('history.go(0)',400);
}
</script>
</div><br />

<?php
btable();
include(CHEMIN."inc/bpage.inc");
?>
