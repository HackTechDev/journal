<?php
/* 
correction lignes 16 à 21 et ligne 53 (thanks linuxmr)
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");

include("inc/hpage.inc");
htable("Contrôle des données de l'agenda", "100%");

$corrige = ($corrige == "corrige");
$dbagenda = ReadDBFields(DBAGENDA);
$nerr = 0;
for($i = 0; $i < count($dbagenda); $i++) {
  $idxag = &$dbagenda[$i];
  ReadDoc(DBBASE.$idxag[4]);
  if (preg_match ('`(\d{4})\/(\d{1,2})\/(\d{1,2})`', $fielda1, $res)){
    $annee = $res[1];
    $mois = $res[2];
    $day = $res[3];
  }
    elseif (preg_match ('`(\d{1,2})\/(\d{1,2})\/(\d{4})`', $fielda1, $res)) {
    $jm1 = $res[1];
    $jm2 = $res[2];
    $annee = $res[3];
    if ($jm1 > 12) {
      $mois = $jm2;
      $day = $jm1;
    }
    elseif ($jm2 > 12) {
      $mois = $jm1;
      $day = $jm2;
    }
    elseif ($site[19][0] == "E") {
      $day = $jm1;
      $mois = $jm2;
    }
    else {
      $mois = $jm1;
      $day = $jm2;
    }
  }

  $err1 = ($idxag[0] != $fielda1);
  $err2 = ($idxag[1] != "" || $fielda2 != "");
  $err3 = ($idxag[3] != "" || $fieldb2 != "");
  $err4 = ($idxag[2] != $mois.$annee);
  $err5 = ($fieldb1 != $mois.$annee);
  $err6 = ($fielda1 != substr(FormatDate($annee.$mois.$day."00000"), 0, 10));
  $err  = $err1||$err2||$err3||$err4||$err5||$err6;
  if ($err) $nerr++;
  if ($corrige && $err) {
    $fielda1 = substr(FormatDate($annee.$mois.$day."00000"), 0, 10);
    $fielda2 = $fielda2;
    $fieldb1 = $mois.$annee;
    $fieldb2 = "";
    $fieldc1 = addslashes($fieldc1);
    $fieldc2 = addslashes($fieldc2);
    WriteDoc();
    $idxag[0] = $fielda1;
    $idxag[1] = "";
    $idxag[2] = $mois.$annee;
    $idxag[3] = "";
    $err = false;
  }
  echo "$idxag[4] - $fielda1 - $fieldb1 - ".stripslashes($fieldc1)." : ".($err?'<br /><b style="color:red">Evénement : à mettre à jour</b>':'<br /><b style="color:green">Evénement : Ok</b>')." <hr />";
}
if ($corrige) WriteDBFields(DBAGENDA,$dbagenda);
if (!$corrige && $nerr > 0) {
  echo <<<HTML
<form name="maj_agenda" method="post" action="MAJ_AGENDA.PHP">
<input type="hidden" name="corrige" value="corrige">
<center><input type="submit" value="Mettre à jour les événements..."></center>
</form>
HTML;
}

btable();
include("inc/bpage.inc");

?>
