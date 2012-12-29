<?php
/*
    Agenda - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.0 (06 December 2004)  : initial release (by Nicolas Alves)
                                 changed table bgcolor by class, optimized code and look (by Icare)
      v4.5 (22 April 2005)     : replacing navigation bar (by Jean-Mi)
      v4.6.2 (22 July 2007)    : deleted useless p tag (thanks Shadow)
      v4.6.10 (7 September 2009)  : corrected #274
                                    display many events on the diary #284 (by Icare)
      v4.6.11 (11 December 2009)  : corrected Agenda can display all types of documents #294 (by hpsam)
      v4.6.15 (30 June 2011)   : added private group management (by Icare)
                                              corrected agenda date headder when using date format other than d-m-y (by Quefer)
      v4.6.17(21 October 2011) :  corrected display events (by Saxbar)											  
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");

if ($serviz[47] != "on") {
    exit($web143);
}

$agv = strip_tags($agv);
$pg = strip_tags($pg);
$id = strip_tags($id);
$an = strip_tags($an);
$mois = strip_tags($mois);
$idpg = strip_tags($idpg);

if ($members[0]=="on" && $userprefs[1]=="" && $members[14]=="on") {
  include("inc/hpage.inc");
  htable($web287, '100%');
  echo "<p align=\"center\">$web342</p><br />";
  echo "<p align=\"center\">[ <a href=\"".CHEMIN."user.php?lng=".$lng."\">$web343</a> ]</p><br />";
  btable();
  include("inc/bpage.inc");
} else {
  if (empty($id)) {
    $id = 1; $wag = array();
  }
  $monthlist = array("$web268", "$web269", "$web270", "$web271", "$web272", "$web273", "$web274", "$web275", "$web276", "$web277", "$web278", "$web279");
  if ($agv == 1) {  // si jour choisi
    include_once (CHEMIN.'inc/func_groups.php'); /// modif accès privé
    $pgid = explode("/", $idpg);
    $wag = array();
    for ($a = 0; $a < count($pgid)-1; $a++) {
      if (!is_file(DBBASE.$pgid[$a].INCEXT)) continue;
      ReadDoc(DBBASE.$pgid[$a]);
      if ($type != TYP_AGENDA) continue;
      $wag[$a][0] = $fielda2;
      $wag[$a][1] = $fileid;
    }
    if (empty($wag)) {
        die('STOP ! Variable $idpg : illegal value !');
    }
    sort($wag);
    
    for ($jj = 0; $jj < count($wag); $jj++) {
      ReadDoc(DBBASE.$wag[$jj][1]);

      if ($site[19] == "E1" || $site[19] == "E2") {
        $agtxt1 = substr($fielda1, 0, 2);    //originale
        $agtxt2 = substr($fielda1, 3, 2);    //originale
        $agtxt3 = substr($fielda1, -4);    //originale
   }
      elseif ($site[19] == "U1" || $site[19] == "U2") {
        $agtxt1 = substr($fielda1, 3, 2);
        $agtxt2 = substr($fielda1, 0, 2);
        $agtxt3 = substr($fielda1, -4);
     }
      elseif ($site[19] == "C1" || $site[19] == "C2") {
        $agtxt1 = substr($fielda1, -2);
        $agtxt2 = substr($fielda1, 5, 2);
        $agtxt3 = substr($fielda1, 0,4);
     }
      
/// début modif accès privé
      $agtxt4 = $fieldmod;
      $acces = "ok";
      if ($agtxt4 != "") {
        $acces = "no";
        if ($userprefs[1] != "") {
          if (CheckGroup($agtxt4, $userprefs[1])) $acces ="ok";
        }
      }
      if ($acces == "ok") {
/// fin modif accès privé
      $agtime = array();
      $agtime = explode("-", $fielda2);
      if ($agtime[0] < "10:00") $agtime[0] = substr($agtime[0], 1, 7);
      if ($agtime[1] < "10:00") $agtime[1] = substr($agtime[1], 1, 7);
      if ($site[22] == "H2"){
        $agtime[0] = str_replace(":", "h", $agtime[0]);
        $agtime[1] = str_replace(":", "h", $agtime[1]);
      }
      if ($agtime[0] != "" && $agtime[1] != "") $til = "<br />&darr;<br />";
      elseif ($agtime[0] != "" && $agtime[1] == "") $til= "<br />&darr;<br />&#133;";
      elseif ($agtime[0] == "" && $agtime[1] != "") $til = "&#133;<br />&darr;<br />";
      else $til = "";
      $mthname = $monthlist[$agtxt2-1];
      if ($lng == $lang[0]) {
        $agtxt4 = $fieldc1;
      } else {
        $agtxt4 = empty($fieldc2) ? "<em>$web442</em><br /><br />$fieldc1" : $fieldc2;
      }
      if ($jj == 0 ){
        if ($web284 == "0") {
          $datecountry = $web285." ".$agtxt1." ".$mthname." ".$agtxt3;
        }
        if ($web284 == "1") {
          $datecountry = $web285." ".$mthname." ".$agtxt1." ".$agtxt3;
        }
        if ($web284 == "2") {
          $datecountry = $web285." ".$agtxt3." ".$mthname." ".$agtxt1;
        }
		include("inc/hpage.inc");
		htable($datecountry, "100%");
		echo "<br />\n";
	  }
    ?>
    <table class="bord" cellspacing="1" cellpadding="0" width="98%" align="center" border="0" summary="">
    <tr><td class="quest" style="width:70px;font-weight:bold;text-align:center;vertical-align:top;padding-top:10px;"><?php echo $agtime[0].$til.$agtime[1]; ?></td>
      <td class="rep" style="vertical-align:top;"><?php echo $agtxt4; ?>
      <?php
      if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $drtuser[37]=="on")) {
        echo "
        <p align='right'><a href='".CHEMIN."admin/admin.php?lng=".$lng."&amp;pg=agenda&amp;form=2&amp;id=".$pgid[$jj]."'>
        <img src='".CHEMIN."inc/img/general/edit.gif' border='0' alt='".$web308."' title='".$web308."' /></a></p>\n";
        }
      ?>
      </td>
    </tr>
    </table>
    <?php
    } /// modif accès privé
    }
    ?>
    <p align="center">[ <a href="agenda.php?lng=<?php echo $lng; ?>&amp;mois=<?php echo $agtxt2; ?>&amp;an=<?php echo $agtxt3; ?>&amp;agv=2"><?php echo $web286." ".$mthname." ".$agtxt3; ?></a> ]</p>
    <br />
    <?php
    if ($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) {
    ?>
    <p align="right"><a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=agenda&amp;form=2&amp;id=<?php echo $pg; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/edit.gif" border="0" alt="<?php echo $web308; ?>" title="<?php echo $web308; ?>" /></a></p>
    <?php
    }
    btable();
    include("inc/bpage.inc");
    }
    elseif ($agv == 2) {
      if (!$mois && !$an) {
        $mois = date("m");
        $an = date("Y");
      }
      if ($mois < 1) {
        $mois = 12;
        $an--;
      }
      if ($mois > 12) {
        $mois = 1;
        $an++;
      }
      $mthname = $monthlist[$mois-1];
      include("inc/hpage.inc");
      include_once (CHEMIN.'inc/func_groups.php'); /// modif accès privé
      htable($web287." ".$mthname." ".$an, "100%");
      $dbwork = ReadDBFields(DBAGENDA);
      @sort($dbwork);
      ?>
      <br />
      <table cellspacing="1" cellpadding="4" align="center" border="0" summary="">
      <tr>
      <td><a href="agenda.php?lng=<?php echo $lng; ?>&amp;mois=<?php echo $mois-1; ?>&amp;an=<?php echo $an; ?>&amp;agv=2">
      <img border="0" src="<?php echo CHEMIN; ?>inc/img/general/calendarg.gif" width="14" height="11" alt="<?php echo $web289; ?>" /></a></td>
      <td><b><?php echo $mthname." ".$an; ?></b></td>
      <td><a href="agenda.php?lng=<?php echo $lng; ?>&amp;mois=<?php echo $mois+1; ?>&amp;an=<?php echo $an; ?>&amp;agv=2">
      <img border="0" src="<?php echo CHEMIN; ?>inc/img/general/calendard.gif" width="14" height="11" alt="<?php echo $web288; ?>" /></a></td>
      </tr>
      </table>
      <?php
      $mthag = array();
      for ($i = 0; $i < count($dbwork); $i++) {
        if ($dbwork[$i][2] == $mois.$an) {
          $mthag[] = $dbwork[$i][4];
        }
      }
      $controle = CheckDB1Field(DBAGENDA, $mois.$an, 2);
      if ($controle) {
        $lastday = ""; $currentday = ""; $k=0;
        for ($i = $serviz[46]*($id-1); $i < Min($serviz[46]*$id, count($mthag)); $i++) {
          $k++;
          ReadDoc(DBBASE.$mthag[$i]);
/// début modif accès privé
          $acces = "ok";
            if ($fieldmod != "") {
              $acces = "no";
              if ($userprefs[1] != "") {
                if (CheckGroup($fieldmod, $userprefs[1])) $acces = "ok";
              }
            }
          if ($acces == "ok") {
/// fin modif accès privé
          $currentday = $fielda1;
          $agtime = array();
          $agtime = explode("-", $fielda2);
          if ($agtime[0] < "10:00") $agtime[0] = substr($agtime[0], 1, 7);
          if ($agtime[1] < "10:00") $agtime[1] = substr($agtime[1], 1, 7);
          if ($site[22] == "H2"){
            $agtime[0] = str_replace(":", "h", $agtime[0]);
            $agtime[1] = str_replace(":", "h", $agtime[1]);
          }
          if ($agtime[0] != "" && $agtime[1] != "") $til = "<br />&darr;<br />";
          elseif ($agtime[0] != "" && $agtime[1] == "") $til= "<br />&darr;<br />&#133;";
          elseif ($agtime[0] == "" && $agtime[1] != "") $til = "&#133;<br />&darr;<br />";
          else $til = "";
          switch($site[19][0]) {
          case "E" :
            $agtxt1 = substr($fielda1,0,2);
            $agtxt2 = substr($fielda1,3,2);
            $agtxt3 = substr($fielda1,-4);
          break;
          case "U" :
            $agtxt2 = substr($fielda1,0,2);
            $agtxt1 = substr($fielda1,3,2);
            $agtxt3 = substr($fielda1,-4);
          break;
          case "C" :
            $agtxt1 = substr($fielda1,-2);
            $agtxt2 = substr($fielda1,5,2);
            $agtxt3 = substr($fielda1,0,4);
          break;
          }
          if ($lng == $lang[0]) {
            $agtxt4 = $fieldc1;
          } else {
            $agtxt4 = empty($fieldc2) ? "<em>$web442</em><br /><br />$fieldc1" : $fieldc2;
          }
          if ($web284=="0") {
            $datecountry=$agtxt1." ".$mthname." ".$agtxt3;
          }
          if ($web284=="1") {
            $datecountry=$mthname." ".$agtxt1." ".$agtxt3;
          }
          if ($web284=="2") {
            $datecountry=$agtxt3." ".$mthname." ".$agtxt1;
          }
          if ($currentday != $lastday) {
        echo "
        <table class='bord' cellspacing='1' cellpadding='0' width='98%' align='center' border='0' summary=''>
        <tr><td class='forum2' colspan='2'><b>".$datecountry."</b></td></tr>
        </table>";
        }
        echo "
        <table class='bord' cellspacing='1' cellpadding='0' width='98%' align='center' border='0' summary=''>
        <tr><td class='quest' style='width:70px;font-weight:bold;text-align:center;vertical-align:top;padding-top:10px;'>".$agtime[0].$til.$agtime[1]."<br /></td>
            <td class='rep' style='width:auto;vertical-align:top;'>".$agtxt4."\n";
        if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $drtuser[37]=="on")) {
          echo "            <p align='right'><a href='".CHEMIN."admin/admin.php?lng=".$lng."&amp;pg=agenda&amp;form=2&amp;id=".$mthag[$i]."'>
            <img src='".CHEMIN."inc/img/general/edit.gif' border='0' alt='".$web308."' title='".$web308."' /></a></p>";
        }
        echo "
        </td></tr>
        </table>\n";
        $lastday = $currentday;
        } /// modif accès privé
      }
      if ($k < 1) echo "<p align=\"center\">$web290</p>"; /// modif accès privé
    } else {
      echo "<p align=\"center\">$web290</p>";
    }
    echo GetNavBar("agenda.php?lng=".$lng."&amp;mois=".$mois."&amp;an=".$an."&amp;agv=2&amp;id=", count($mthag), $id, $serviz[46]);
    btable();
    include("inc/bpage.inc");
  } else {
        die("STOP : Invalid value of agv ('$agv') !");
  }
}
?>
