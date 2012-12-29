<?php
/*
    Admin Calendar - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.0 (06 December 2004) : initial release by Nicolas Alves
      v4.1 (17 May 2005)      : updated css management and added special days (by Icare)
      v4.6.10 (7 September 2009)    : corrected #274
                                improvement of duplication #282 (by Icare)
                                added duplcation of the events of the diary #284 (by Icare)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "cal.inc")) {
  header("location:../index.php");
  die();
}
include(CHEMIN."inc/lang/".$lng."-special.inc");
if ($lng == $lang[0]) {$i = 0;}
else {$i = 1;}
if (empty($annee)) {$annee = date("Y");}
if (empty($mois)) {$mois = date("m");}
$jour = date("d");
$joursmois = date("t",mktime(0,0,0,$mois,1,$annee));
$premierjour = date("w",mktime(0,0,0,$mois,1,$annee));
$mois = date("m",mktime(0,0,0,$mois,1,$annee));
$annee = date("Y",mktime(0,0,0,$mois,1,$annee));
$jourj = date("d",mktime(0,0,0,$mois,$jour,$annee));
if ($premierjour == 0) {$premierjour = 7;}
$semainepays = $admin631;
if ($semainepays == 0) {
  $joursemaine = array(1 => "$admin633","$admin634","$admin635","$admin636","$admin637","$admin638","$admin632");
}
else {
  $joursemaine = array(1 => "$admin632","$admin633","$admin634","$admin635","$admin636","$admin637","$admin638");
}
$moispays = array(1 => "$admin639","$admin640","$admin641","$admin642","$admin643","$admin644","$admin645","$admin646","$admin647","$admin648","$admin649","$admin650");
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
if ($mois_p <10) {$mois_p = "0".$mois_p;}
if ($mois == 12) {
  $mois_s = 1;
  $ann_s = $annee + 1;
}
else {
  $mois_s = $mois + 1;
  $ann_s = $annee;
}
if ($mois_s <10) {$mois_s = "0".$mois_s;}
$nbjours = date("d",mktime(0,0,0,$mois_s,0,$annee));
$idn = "";
if ($dup == 2) {
  $dupid = "&amp;dup=2&amp;id=".$id;
}
echo "<center>
<table class=\"cal\" align=\"center\" cellpadding=\"1\" width=\"200\" summary=\"\"><tr class=\"cal\">";
if (($site[19] == "E1") || ($site[19] == "E2")) {
  echo "<td class='cal3'><a href='admin.php?pg=agenda&amp;lng=".$lng."&amp;form=3&amp;mois=".$mois_p."&amp;annee=".$ann_p.$dupid."' title='".$mois_p."-".$ann_p."'><img src='".CHEMIN."inc/img/bars/left.gif' border='0' alt='".$mois_p."-".$ann_p."' /></a></td>
  <td colspan='5' align='center' nowrap='nowrap' class='cal3'><b><a href='admin.php?pg=agenda&amp;lng=".$lng."&amp;form=3&amp;mois=".$mois_ci."&amp;annee=".$ann_ci.$dupid."' title='=&gt;".$mois_ci."-".$ann_ci."'>".$nommois." ".$annee."</a></b></td>
  <td class='cal3'><a href='admin.php?pg=agenda&amp;lng=".$lng."&amp;form=3&amp;mois=".$mois_s."&amp;annee=".$ann_s.$dupid."' title='".$mois_s."-".$ann_s."'><img src='".CHEMIN."inc/img/bars/right.gif' border='0' alt='".$mois_s."-".$ann_s."' /></a></td>";
}
else {
  echo "<td class='cal3'><a href='admin.php?pg=agenda&amp;lng=".$lng."&amp;form=3&amp;mois=".$mois_p."&amp;annee=".$ann_p."' title='".$ann_p."-".$mois_p.$dupid."'><img src='".CHEMIN."inc/img/bars/left.gif' border='0' alt='".$ann_p."-".$mois_p."' /></a></td>
  <td colspan='5' align='center' nowrap='nowrap' class='cal3'><b><a href='admin.php?pg=agenda&amp;lng=".$lng."&amp;form=3&amp;mois=".$mois_ci."&amp;annee=".$ann_ci.$dupid."' title='=&gt;".$ann_ci."-".$mois_ci."'>".$annee." ".$nommois."</a></b></td>
  <td class='cal3'><a href='admin.php?pg=agenda&amp;lng=".$lng."&amp;form=3&amp;mois=".$mois_s."&amp;annee=".$ann_s.$dupid."' title='".$ann_s."-".$mois_s."'><img src='".CHEMIN."inc/img/bars/right.gif' border='0' alt='".$ann_s."-".$mois_s."' /></a></td>";
}
echo "</tr><tr>";
for ($nbrejours = 1; $nbrejours < 8; $nbrejours++) {
  $couleurcal = "$calendar[0]";
  ?>
  <td class="cal0" align="center"><b><?php echo $joursemaine[$nbrejours]; ?></b></td>
  <?php
}
echo "</tr><tr>";
for ($i = 1; $i < $joursmois + $premierjour + $semainepays; $i++) {
  $a = $i - $premierjour + 1 - $semainepays;
  $jour = $i - $premierjour + 1 - $semainepays;
  if (strlen($a) == 0) {
    $a = "$a";
  }
  if ($i < $premierjour || $a == "") {
    if  (!($premierjour == 7 && $semainepays == 1)) {
      $textecal = "&nbsp;";
      ?>
      <td class="cal0"  style="background-image:none"><?php echo $textecal; ?></td>
      <?php
    }
  }
  elseif ($jour > $nbjours) {
    $textecal = "&nbsp;";
    echo "<td class=\"cal0\">".$textecal."</td>";   // jours vides
  }
  else {
    if ($a <10) {
      $a = "0".$a;
    }
    if ($jour <10) {
      $jour = "0".$jour;
    }
    $textecal = "$a";
    if ((cal_ferie($jour,$mois,$annee)) == "oui") {
      if (($mois == $mois_ci) && ($jourj == $a)) $stylecal = "cal4";
      else $stylecal = "cal3";
    }
    else {
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
          if ($mois == $mois_ci) {
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
    if (($site[19] == "E1") || ($site[19] == "E2")) {
      $agdt= ("day=".$a."&amp;mois=".$mois."&amp;annee=".$annee);
    }
    if (($site[19] == "U1") || ($site[19] == "U2")) {
      $agdt= ("mois=".$mois."&amp;day=".$a."&amp;annee=".$annee);
    }
    if (($site[19] == "C1") || ($site[19] == "C2")) {
      $agdt= ("annee=".$annee."&amp;mois=".$mois."&amp;day=".$a);
    }
    $jagok="0";
    $dbworkag = ReadDBFields(DBAGENDA);
    for ($k = 0; $k < count($dbworkag); $k++) {
      switch ($site[19]) {
      case "U1" :
      case "U2" :
        if($dbworkag[$k][0]==$mois."/".$a."/".$annee || $dbworkag[$k][0]==$mois.".".$a.".".$annee){
        $jagok="1";
        $pgag=$dbworkag[$k][4];
        }
      break;
      case "C1" :
      case "C2" :
        if($dbworkag[$k][0]==$annee."/".$mois."/".$a || $dbworkag[$k][0]==$annee.".".$mois.".".$a){
        $jagok="1";
        $pgag=$dbworkag[$k][4];
        }
      break;
      case "E1" :
      case "E2" :
        if($dbworkag[$k][0]==$a."/".$mois."/".$annee || $dbworkag[$k][0]==$a.".".$mois.".".$annee) {
        $jagok="1";
        $pgag=$dbworkag[$k][4];
        }
      }
    }
    if($jagok=="1") {
      if ($dup == 2) {
      ?>
      <td class="calevt"><span class="calevt"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=agenda&amp;form=2&amp;idn=<?php echo $pgag ?>&amp;<?php echo $agdt; ?>&amp;dup=2&amp;id=<?php echo $id; ?>"><?php echo $textecal; ?></a></span></td>
      <?php
      } else {
      ?>
      <td class="calevt"><span class="calevt"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=agenda&amp;form=1&amp;&amp;<?php echo $agdt; ?>"><?php echo $textecal; ?></a></span></td>
      <?php
      }
    }
    elseif($jagok!="1") {
      if ($dup == 2) {
      ?>
      <td class="<?php echo $stylecal; ?>"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=agenda&amp;form=2&amp;<?php echo $agdt.$dupid; ?>"><?php echo $textecal; ?></a></td>
      <?php
      } else {
      ?>
      <td class="<?php echo $stylecal; ?>"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=agenda&amp;form=1&amp;<?php echo $agdt; ?>"><?php echo $textecal; ?></a></td>
      <?php
      }
    }
  }
  if (($i%7) == 0) {
    echo "</tr><tr>";
  }
}
for ($i = $joursmois + $premierjour + $semainepays; $i < 43; $i++) {
  ?>
  <td class="cal0"><?php echo $joursemaine[$nbrejours]; ?></td>
  <?php
  if (($i%7) == 0 && $i != 42) {
    echo "</tr><tr>";
  }
}
echo "</tr></table></center>";
