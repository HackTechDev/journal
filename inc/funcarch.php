<?php
/*
    Archives Specific Functions - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v3.0 (25 February 2004)  : initial release
      v4.0 (06 December 2004)  : no change
*/

if (stristr($_SERVER["SCRIPT_NAME"], "funcarch.php")) {
  header("location:../index.php");
  die();
}

define("ARCHDBBASE", ARCHREP."doc");
define("ARCHDBIPBASE", ARCHREP."ipdoc");
define("DOCIDARCH", ARCHREP."docid".DBEXT);
define("DBFORUMARCH", ARCHREP.TYP_FORUM.DBEXT);
define("DBTHREADARCH", ARCHREP.TYP_THREAD.DBEXT);

function UpdateDocCounterArch($id) {
  $DataDB = ReadDocCounter(ARCHDBBASE.$id);
  $vote = DejaVote(ARCHDBIPBASE.$id.DBEXT,300);
  if ($vote[0] == false) {
    $DataDB++;
    WriteDocCounter(ARCHDBBASE.$id,$DataDB);
  }
  return $DataDB;
}

function UpdateDBforumArch() {
  global $site,$type,$fileid,$status,$creadate,$moddate,$author,$email,
         $fielda1,$fielda2,$fieldb1,$fieldb2,$fieldc1,$fieldc2,$fieldd1,$fieldd2;
  $db = array();
  $db = ReadDBFields(DOCIDARCH);
  @sort($db);
  $dbf = array();
  $j = 0;
  for ($i = 0; $i < count($db); $i++) {
    if ($db[$i][2] == "a") {
      ReadDoc(ARCHDBBASE.$db[$i][1]);
      $dbf[$j][0] = $creadate;
      $dbf[$j][1] = $fielda1;
      $dbf[$j][2] = $fielda2;
      $dbf[$j][3] = $fileid;
      $dbf[$j][4] = RemoveConnector($author);
      $dbf[$j][5] = RemoveConnector($email);
      $dbf[$j][6] = RemoveConnector($fieldb1);
      $dbf[$j][7] = $fieldd1;
      $dbf[$j][8] = $fieldb2;
      $j++;
    }
  }
  @sort($dbf,SORT_REGULAR);
  WriteDBFields(DBTHREADARCH,$dbf);
  $db = array();
  $db = ReadDBFields(DBTHREADARCH);
  $dbf = array();
  $j = 0;
  for ($i = 0; $i < count($db); $i++) {
    if ($db[$i][2] == "0") {
      $dbf[$j][0] = $db[$i][0];
      $dbf[$j][1] = $db[$i][1];
      $dbf[$j][2] = $db[$i][3];
      $dbf[$j][3] = $db[$i][4];
      $dbf[$j][4] = $db[$i][5];
      $dbf[$j][5] = $db[$i][6];
      $dbf[$j][6] = $db[$i][0];
      $dbf[$j][7] = 0;
      $dbf[$j][8] = "";
      $dbf[$j][9] = "";
      $dbf[$j][10] = $db[$i][7];
      $dbf[$j][11] = "";
      $dbf[$j][12] = $db[$i][8];
      for ($k = $i+1; $k < count($db); $k++) {
        if ($db[$k][1] == $dbf[$j][1]) {
          $dbf[$j][0] = $db[$k][0];
          $dbf[$j][7] = $dbf[$j][7]+1;
          $dbf[$j][8] = $db[$k][4];
          $dbf[$j][9] = $db[$k][5];
          $dbf[$j][11] = $db[$k][7];
        }
      }
      $j++;
    }
  }
  @rsort($dbf,SORT_REGULAR);
  WriteDBFields(DBFORUMARCH,$dbf);
}
?>
