<?php
/*
    Integrated calender - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v2.3 (27 July 2003)         : initial release by Nicolas Alves and Laurent Duveau
      v2.4 (24 September 2003)    : no change
      v3.0 (25 February 2004)     : added skin management (by Nicolas Alves)
      v4.0 (06 December 2004)     : extracted from boxcal, added calendar navigation(by Icare)
                                    added alt tags to img and removed border tag for non-linked img (by Isa)
                                    included the style CSS ans its extension (by Isa)
                                    added agenda links (by Nicolas Alves)
                                    optimized css management according site style (by Icare)
      v4.5 (15 May 2005)          : optimized viewing links for agenda events (by Icare)
                                    included style management in style.inc (by Icare)
      v4.6.0 (04 June 2007)       : corrected february days number (by Icare)
      v4.6.6 (14 April 2008)  )   : added iframeHeight() from boxcal, thanks eDdada
      v4.6.9 (25 December 2008)   : added corrections for validation of W3C
      v4.6.10 (7 September 2009)  : corrected #274  added #284
      v4.6.11 (11 December 2009)  : correcred #299
      v4.6.15 (30 June 2011)      : added private management (by Icare)
      v4.6.17(21 October 2011)    : call function in moving boxcal.inc (by Laroche)
      v4.6.18(09 February 2012)   : corrected adjustment display iframe (by Saxbar)	  
*/

header("Pragma: no-cache");
define("CHEMIN", "../");
include(CHEMIN."inc/includes.inc");
include(CHEMIN."inc/lang/".$lng."-special.inc");
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>Calendar</title>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset; ?>" />
<meta name="Robots" content="None" />
<?php
if(file_exists($meskin."style.css")) {
  echo "<link type=\"text/css\" rel=\"stylesheet\" href=\"".$meskin."style.css\" />";
}
else {
  echo "<style type=\"text/css\">";
  if(file_exists($meskin."style.inc")) {
    include($meskin."style.inc");
  }
  else {
    include(CHEMIN."inc/style.inc");
  }
  echo "</style>";
}
?>
</head>
<body class="tblbox" style="margin:0px; padding:0px; background-image:none; border:0px;" onmouseover="this.className = 'tblboxover';" onmouseout="this.className = 'tblbox';" onload="parent.adjustMyFrameHeight();">
<?php
if ($lng == $lang[0]) {
  $i = 0;
}
else {
  $i = 1;
}

if (empty($annee)) $annee = date("Y");
if (empty($mois))  $mois = date("m");
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
// modif agenda
$idpg ="";
// fin modif
echo "<table class=\"cal\" align=\"center\" cellpadding=\"1\" width=\"100%\" summary=\"\"><tr class=\"cal\">";
if (($site[19] == "E1") || ($site[19] == "E2")) {
  echo "<td class='cal3'><a href='?lng=".$lng."&amp;mois=".$mois_p."&amp;annee=".$ann_p."' title='".$mois_p."-".$ann_p."'><img src='".CHEMIN."inc/img/bars/left.gif' border='0' alt='".$mois_p."-".$ann_p."' /></a></td>
<td colspan='5' align='center' nowrap='nowrap' class='cal3'><strong><a href='".CHEMIN."agenda.php?lng=".$lng."&amp;mois=".$mois."&amp;an=".$annee."&amp;agv=2' target='_parent' title='".$web287." ".$mois."-".$annee."'>".$nommois." ".$annee."</a></strong></td>
<td class='cal3'><a href='?lng=".$lng."&amp;mois=".$mois_s."&amp;annee=".$ann_s."' title='".$mois_s."-".$ann_s."'><img src='".CHEMIN."inc/img/bars/right.gif' border='0' alt='".$mois_s."-".$ann_s."' /></a></td>";
}
else {
  echo "<td class='cal3'><a href='?lng=".$lng."&amp;mois=".$mois_p."&amp;annee=".$ann_p."' title='".$ann_p."-".$mois_p."'><img src='".CHEMIN."inc/img/bars/left.gif' border='0' alt='".$ann_p."-".$mois_p."' /></a></td>
<td colspan='5' align='center' nowrap class='cal3'><a href='".CHEMIN."agenda.php?lng=".$lng."&amp;mois=".$mois."&amp;an=".$annee."&amp;agv=2' target='_parent' title='".$web287." ".$annee."-".$mois."'>".$annee." ".$nommois."</a></td>
<td class='cal3'><a href='?lng=".$lng."&amp;mois=".$mois_s."&amp;annee=".$ann_s."' title='".$ann_s."-".$mois_s."'><img src='".CHEMIN."inc/img/bars/right.gif' border='0' alt='".$ann_s."-".$mois_s."' /></a></td>";
}
echo "</tr><tr>";
for ($nbrejours = 1; $nbrejours < 8; $nbrejours++) {
  // entête
?>
<td class="cals" align="center"><strong><?php echo $joursemaine[$nbrejours]; ?></strong></td>
<?php
}
?></tr><tr>
<?php
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
      echo "<td class=\"cal0\">".$textecal."</td>\n";   // jours vides
    }
  }
  elseif ($jour > $nbjours) {
    $textecal = "&nbsp;";
    echo "<td class=\"cal0\">".$textecal."</td>\n";   // jours vides
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
      if (($mois == $mois_ci) && ($jourj == $a)) $stylecal = "cal4";
      else $stylecal = "cal3";
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
    $jagok="0";
    // modif agenda: création table des id  correspondant au jour jagok
    $pgtab = array();
    $breve = array();
    /// début modif accès réservé
    $dbworkag = array();
    $dbwork = ReadDBFields(DBAGENDA);
    for ($z = 0; $z < count($dbwork); $z++) {
      if ($dbwork[$z][6] != "") {
        if ($userprefs[1] != "") {
          include_once (CHEMIN.'inc/func_groups.php');
          if (CheckGroup($dbwork[$z][6], $userprefs[1])) $dbworkag[] = $dbwork[$z];
        }
      } else {
        $dbworkag[] = $dbwork[$z];
      }
    }
    //$dbworkag = ReadDBFields(DBAGENDA);
    /// fin modif accès réservé
    for ($k = 0; $k < count($dbworkag); $k++) {
      switch ($site[19]) {
      case "U1" :
      case "U2" :
        if($dbworkag[$k][0]==$mois."/".$a."/".$annee || $dbworkag[$k][0]==$mois.".".$a.".".$annee) {
        $jagok="1";
        $pgtab[$jour].=$dbworkag[$k][4].'/';
        $pgag=$dbworkag[$k][4];
        ReadDoc(DBBASE.$pgag);
        $breve [$jour] .= "* ".CutLongWord(strip_tags($lng == $lang[0] ? $fieldc1 : $fieldc2), 25)."... ";
        }
      break;
      case "C1" :
      case "C2" :
        if($dbworkag[$k][0]==$annee."/".$mois."/".$a || $dbworkag[$k][0]==$annee.".".$mois.".".$a){
        $jagok="1";
        $pgtab[$jour].=$dbworkag[$k][4].'/';
        $pgag=$dbworkag[$k][4];
        ReadDoc(DBBASE.$pgag);
        $breve[$jour] .= "* ".CutLongWord(strip_tags($lng == $lang[0] ? $fieldc1 : $fieldc2), 25)."... ";
        }
      break;
      case "E1" :
      case "E2" :
        if($dbworkag[$k][0]==$a."/".$mois."/".$annee || $dbworkag[$k][0]==$a.".".$mois.".".$annee){
        $jagok="1";
        $pgtab[$jour].=$dbworkag[$k][4].'/';
        $pgag=$dbworkag[$k][4];
        ReadDoc(DBBASE.$pgag);
        $breve[$jour] .= "* ".CutLongWord(strip_tags($lng == $lang[0] ? $fieldc1 : $fieldc2), 30)."... ";
        }
      }
    }
    if ($jagok=="1") {
      ?>
      <td class="calevt"><span class="calevt">
      <a href="<?php echo CHEMIN; ?>agenda.php?lng=<?php echo $lng; ?>&amp;idpg=<?php echo $pgtab[$jour]; ?>&amp;pg=<?php echo $pgag; ?>&amp;agv=1" target="_parent" title="<?php echo $breve[$jour]; ?>">
      <?php echo $textecal; ?></a></span></td>
      <?php
    }
    elseif($jagok!="1") {
      echo "<td class=\"".$stylecal."\">".$textecal."</td>\n";
    }
  }
  if (($i%7) == 0 and $i != $max) {
    echo "</tr><tr>\n";
  }
}
?>
</tr>
</table>
</body>
</html>
