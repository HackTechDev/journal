<?php
/*
    Calendar for Blog - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v2.3 (27 July 2003)         : initial release (by Nicolas Alves and Laurent Duveau)
      v4.6.0 (15 Février 2007)    : special release for blog (by Icare)
      v4.6.6 (14 April 2008)      : corrected notes select (by Icare)
      v4.6.9 (25 December 2008)   : added the limitation of the calendar of the first ticket to now #221
      v4.6.10 (7 september 2009)  : corrected #274 and #288
      v4.6.11 (11 December 2009)  : get same size as the calendar
      v4.6.15 (30 June 2011)      : corrected > in line 215
	  v4.6.20 (24 May 2012)       : corrected $boxwidth (by Saxbar)
      v4.6.22 (29 December 2012)  : box created using htable1()/btable1() (thanks Icare)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "blogcalendar.inc")) {
  header("location:../index.php");
  die();
}

if ($lng == $lang[0]) {
    $i = 0;
}
else {
    $i = 1;
}

include(CHEMIN."inc/lang/".$lng."-special.inc");

if (empty($date)) {
    $annee = date("Y");
    $mois = date("m");
}
else {
    $annee = substr($date, 0, 4);
    $mois = substr($date, 4, 2);
}
$jour = date("d");
$joursmois = date("t",mktime(0,0,0,$mois,1,$annee));
$premierjour = date("w",mktime(0,0,0,$mois,1,$annee));
$mois = date("m",mktime(0,0,0,$mois,1,$annee));
$annee = date("Y",mktime(0,0,0,$mois,1,$annee));
$jourj = date("d",mktime(0,0,0,$mois,$jour,$annee));
if ($premierjour == 0) {
    $premierjour = 7;
}
$semainepays = $web153;
if ($semainepays == 0) {
    $joursemaine = array(1 => "$web147","$web148","$web149","$web150","$web151","$web152","$web146");
}
else {
    $joursemaine = array(1 => "$web146","$web147","$web148","$web149","$web150","$web151","$web152");
}
$moispays = array(1 => "$web268","$web269","$web270","$web271","$web272","$web273","$web274","$web275","$web276","$web277","$web278","$web279");
$nommois = $moispays[$mois*$mois/$mois];
$date = getdate(time());
$mois_ci = $date["mon"];
if ($mois_ci <10) {
    $mois_ci = "0".$mois_ci;
}
$ann_ci = $date["year"];
if ($mois == 1) {
    $mois_p = 12;
    $ann_p = $annee - 1;
}
else {
    $mois_p = $mois - 1;
    $ann_p = $annee;
}
if ($mois_p <10) {
    $mois_p = "0".$mois_p;
}
if ($mois == 12) {
    $mois_s = 1; $ann_s = $annee + 1;
}
else {
    $mois_s = $mois + 1;
    $ann_s = $annee;
}
if ($mois_s <10) {
    $mois_s = "0".$mois_s;
}
$nbjours = date("d",mktime(0,0,0,$mois_s,0,$annee));

if (!function_exists('MyMonth')) {
    function MyMonth($month, $year, $separator = '-') {
        global $site;
        if (($site[19] == "E1") || ($site[19] == "E2")) {
            return $month . $separator . $year;
        } else {
            return $year . $separator . $month;
        }
    }
}
$dat_max = date("Y") . date("m");
$dbwork = ReadDBFields(DBBLOG);
$dat_min = count($dbwork) == 0 ? $dat_max : substr($dbwork[0][5], 0, 6);
$dat_p = $ann_p . $mois_p;
$dat_s = $ann_s . $mois_s;
$widthbox = !isset($boxwidth) ? "172px" : strpos($boxwidth, 'px') === false ? '172px' : $boxwidth;
htable1($web399);
  if ($dat_p >= $dat_min) {
    $tdleft = "<a href='blogs.php?lng=".$lng."&amp;sel=mois&amp;date=".$ann_p.$mois_p."' title='".MyMonth($mois_p, $ann_p)."'><img src='".CHEMIN."inc/img/bars/left.gif' border='0' alt='".$mois_p."-".$ann_p."'/></a>";
} else {
    $tdleft = "<img src='".CHEMIN."inc/img/bars/left.gif' border='0' alt='".$mois_p."-".$ann_p."'/>";
}

if ($dat_s <= $dat_max) {
    $tdright = "<a href='blogs.php?lng=".$lng."&amp;sel=mois&amp;date=".$ann_s.$mois_s."' title='".MyMonth($mois_s, $ann_s)."'><img src='".CHEMIN."inc/img/bars/right.gif' border='0' alt='".MyMonth($mois_s, $ann_s)."'/></a>";
} else {
    $tdright = "<img src='".CHEMIN."inc/img/bars/right.gif' border='0' alt='".MyMonth($mois_s, $ann_s)."'/>";
}
echo "
     <table class=\"cal\" align=\"center\" cellpadding=\"1\" width=\"156\" summary=\"\">
      <tr>
       <td class='cal3'>".$tdleft."</td>
       <td colspan='5' align='center' nowrap='nowrap' class='cal3'>
        <strong><a href='blogs.php?lng=".$lng."&amp;sel=mois&amp;date=".$ann_ci.$mois_ci."' title='>> ".MyMonth($mois_ci, $ann_ci)."'>".$nommois." ".$annee."</a></strong>
       </td>
       <td class='cal3'>".$tdright."</td>
      </tr>
      <tr>";

for ($nbrejours = 1; $nbrejours < 8; $nbrejours++) {
echo '
       <td class="cals" align="center"><strong>'.$joursemaine[$nbrejours].'</strong></td>';
}

echo '
      </tr>
      <tr>';
if ((($joursmois + $premierjour + $semainepays - 1) % 7) == 0 )
    $max = 7*floor(($joursmois + $premierjour + $semainepays)/7);
else
    $max = 7*ceil(($joursmois + $premierjour + $semainepays)/7);

for ($i = 1; $i <= $max; $i++) {
    $a = $i - $premierjour + 1 - $semainepays;
    $jour = $i - $premierjour + 1 - $semainepays;
    if (strlen($a) == 0) {
        $a = "$a";
    }
    if ($i < $premierjour || $jour > $joursmois || $a == "") {
        if  (!($premierjour == 7 && $semainepays == 1)) {
            $textecal = "&nbsp;";
            echo "
       <td class=\"cal0\">".$textecal."</td>";   // jours vides
        }
    }
    elseif ($jour > $nbjours) {
        $textecal = "&nbsp;";
        echo "
       <td class=\"cal0\">".$textecal."</td>";   // jours vides
    }
    else {
        if ($a <10) {
            $a = "0".$a;
        }
        if ($jour <10) {
            $jour = "0".$jour;
        }
        if ((cal_ferie($jour,$mois,$annee)) == "oui") {
            $textecal = "$a";
            if (($mois == $mois_ci) && ($jourj == $a))
                $stylecal = "cal4";
            else
                $stylecal = "cal3";
        }
        else {
            $textecal = "$a";
            if (($jourj == $a)) {
                if (($i%7) == $semainepays) {
                    if ($mois == $mois_ci) {
                        $stylecal = "cal4";
                    }
                    else {
                        $stylecal = "cal3";
                    }
                }
                else {
                    if ($mois == $mois_ci && $annee == $ann_ci) {
                        $stylecal = "cal2";
                    }
                    else {
                        $stylecal = "cal1";
                    }
                }
            }
            else {
                if (($i%7) == $semainepays) {
                    $stylecal = "cal3";
                }
                else {
                    $stylecal = "cal1";
                }
            }
        }
        $jok="0";
//        $dbwork = ReadDBFields(DBBLOG);
        
        for ($k = 0; $k < count($dbwork); $k++) {
            $datebi = CutLongWord($dbwork[$k][5], 8);
            if ($datebi == $annee.$mois.$a) {
                $jok="1";
                $datej=$datebi;
                break;
            }
        }
        if ($jok=="1") {
echo '
       <td class="calevt">
        <a href="'.CHEMIN.'blogs.php?lng='.$lng.'&amp;sel=jour&amp;datej='.$datej.'" title="'.substr(formatDate($datej), 0, 10).'">'.$textecal.'</a>
       </td>';
        }
        elseif($jgok!="1") {
            echo "
       <td class=\"".$stylecal."\">".$textecal."</td>";
        }
    }
    if (($i%7) == 0 and $i != $max) {
        echo "
      </tr>
      <tr>";
    }
}
echo '
      </tr>
     </table>';
  btable1();
