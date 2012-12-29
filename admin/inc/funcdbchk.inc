<?php
/*
    DataBase Integrity Check - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2008 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v3.0 (25 February 2004)  : moved CheckDBmp() from dbcheck.inc to this new file for batch processing
                                 corrected a bug in this function
      v4.0 (06 December 2004)  : no change
      v4.5 (10 April 2005)     : added security control, deletion of orphan files (by Jean-Mi)
      v4.6.1 (02 July 2007)    : added checking blog and reblog (thanks JeanMi)
      v4.6.6 (14 April 2008)   : added include funcrss.php (by JeanMi)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "funcdbchk.inc")) {
  header("location:../index.php");
  die();
}

function CheckDBmP($docmin,$docmax,$quiet=0) {
  global $admin282,$admin283,$admin284,$admin285,$admin286,$admin287,$admin288,
         $admin289,$admin290,$admin291,$admin292,$admin293,$admin294,$admin299,
         $admin300,$admin301,$admin302,$admin303,$admin304,$admin332,$admin479,
         $admin911,$admin912,$admin913,$admin914,$serviz,
         $type,$fileid,$status,$creadate,$moddate,$author,$email,
         $fielda1,$fielda2,$fieldb1,$fieldb2,$fieldc1,$fieldc2,
         $fieldd1,$fieldd2,$fieldweb,$fieldmail,$fieldmod;
  $dbnewdocid = array();
  $timenow = time();
  $j = 0;
  for ($i = $docmin; $i <= $docmax; $i++) {
    if (FileDBExist(DBBASE.$i.INCEXT)) {
      ReadDoc(DBBASE.$i);
      if ($type == '' || $fileid == '' || $status == '') {
        DestroyDBFile(DBBASE.$i.INCEXT);
        DestroyDBFile(DBBASE.$i.DBEXT);
        DestroyDBFile(DBIPBASE.$i.DBEXT);
        continue;
      }
      $dbnewdocid[$j][0] = $type;
      $dbnewdocid[$j][1] = $fileid;
      $dbnewdocid[$j][2] = $status;
      $j++;

      if (FileDBExist(DBIPBASE.$i.DBEXT)) {
        $timefile = filemtime(DBIPBASE.$i.DBEXT);
        if ($timenow - $timefile > HIT_TIME) {
          DestroyDBFile(DBIPBASE.$i.DBEXT);
        }
      }
    }
    else {

      if (FileDBExist(DBBASE.$i.DBEXT)) {
        DestroyDBFile(DBBASE.$i.DBEXT);
      }
      if (FileDBExist(DBIPBASE.$i.DBEXT)) {
        DestroyDBFile(DBIPBASE.$i.DBEXT);
      }
    }
  }
  $dbdocid = array();
  $dbdocid = ReadDBFields(DOCID);
  $tempdocid = array();
  $i = 0; // index $dbnewdocid
  $j = 0; // index $dbdocid
  $k = 0; // index tempodocid
  $onerror = 0;
  if (count($dbnewdocid) == 0) {
    for ($j = 0; $j < count($dbdocid); $j++) {
      if ($dbdocid[$j][1] >= $docmin && $dbdocid[$j][1] <= $docmax) {
        $onerror++;
        if ($quiet == 0) {
          echo $admin282.$dbdocid[$j][1].$admin288;
          echo $admin284.$dbdocid[$j][1].$admin285.$dbdocid[$j][0].$admin286.$dbdocid[$j][2].$admin287;
        }
        switch ($dbdocid[$j][0]) {
        case TYP_ART    : $restart = 1;   break;
        case TYP_LINKS  : $reslink = 1;   break;
        case TYP_DNLOAD : $resdnload = 1; break;
        case TYP_FORUM  : $resforum = 1;  break;
        case TYP_NEWS   : $resnews = 1;   break;
        case TYP_PHOTO  : $resphoto = 1;  break;
        case TYP_REACT  : $resreact = 1;  break;
        case TYP_FAQ    : $resfaq = 1;    break;
        case TYP_AGENDA : $resagenda = 1; break;
        case TYP_BLOG   : $resblog = 1;   break;
        case TYP_REBLOG : $resreblog = 1; break;
        }
      }
      else {
        $tempdocid[$k][0] = $dbdocid[$j][0];
        $tempdocid[$k][1] = $dbdocid[$j][1];
        $tempdocid[$k][2] = $dbdocid[$j][2];
        $k++;
      }
    }
  }
  else {
    if ($docmax > $dbdocid[count($dbdocid)-1][1] && $dbnewdocid[count($dbnewdocid)-1][1] < $dbdocid[count($dbdocid)-1][1]) {
      $whiletoomuch = 1;
    }
    else {
      $whiletoomuch = 0;
    }
    $docmax = $dbnewdocid[count($dbnewdocid)-1][1];
    if ($quiet == 0) {
      echo $admin301.$docmin.$admin302.$docmax.$admin303;
    }
    $restart = 0;
    $reslinks = 0;
    $resdnload = 0;
    $resforum = 0;
    $resnews = 0;
    $resphoto = 0;
    $resreact = 0;
    $resfaq = 0;
    $resagenda = 0;
    $resblog = 0;
    $resreblog = 0;
    $whiletest = 0;
    $whileloop = Max($docmax,$dbdocid[count($dbdocid)-1][1]);
    while ($whiletest < $whileloop && ($j < count($dbdocid) || $i < count($dbnewdocid)))  {
      if ($j == count($dbdocid)) {
        $dbdocid[$j][1] = "999999999999";
      }
      $i = Min($i,count($dbnewdocid));
      if ($dbdocid[$j][1] < $docmin) {
        $tempdocid[$k][0] = $dbdocid[$j][0];
        $tempdocid[$k][1] = $dbdocid[$j][1];
        $tempdocid[$k][2] = $dbdocid[$j][2];
        $k++;
        $j++;
      }
      elseif ($dbdocid[$j][1] > $docmax && $whiletoomuch == 0 && $dbdocid[$j][1] != "999999999999" && $i != (count($dbnewdocid)-1)) {
        $tempdocid[$k][0] = $dbdocid[$j][0];
        $tempdocid[$k][1] = $dbdocid[$j][1];
        $tempdocid[$k][2] = $dbdocid[$j][2];
        $k++;
        $j++;
      }
      elseif ($dbdocid[$j][0] == $dbnewdocid[$i][0] && $dbdocid[$j][1] == $dbnewdocid[$i][1] && $dbdocid[$j][2] == $dbnewdocid[$i][2]) {
        $tempdocid[$k][0] = $dbdocid[$j][0];
        $tempdocid[$k][1] = $dbdocid[$j][1];
        $tempdocid[$k][2] = $dbdocid[$j][2];
        $k++;
        $j++;
        $i++;
      }
      else {
        $onerror++;
        if ($dbdocid[$j][0] == $dbnewdocid[$i][0] && $dbdocid[$j][1] == $dbnewdocid[$i][1]) {
          if ($quiet == 0) {
            echo $admin282.$dbnewdocid[$i][1].$admin299;
            echo $admin284.$dbnewdocid[$i][1].$admin285.$dbnewdocid[$i][0].$admin286.$dbnewdocid[$i][2].$admin287;
          }
          switch ($dbnewdocid[$i][0]) {
          case TYP_ART    : $restart = 1;   break;
          case TYP_LINKS  : $reslink = 1;   break;
          case TYP_DNLOAD : $resdnload = 1; break;
          case TYP_FORUM  : $resforum = 1;  break;
          case TYP_NEWS   : $resnews = 1;   break;
          case TYP_PHOTO  : $resphoto = 1;  break;
          case TYP_REACT  : $resreact = 1;  break;
          case TYP_FAQ    : $resfaq = 1;    break;
          case TYP_AGENDA : $resagenda = 1; break;
          case TYP_BLOG   : $resblog = 1;   break;
          case TYP_REBLOG : $resreblog = 1; break;
          }
          $tempdocid[$k][0] = $dbnewdocid[$i][0];
          $tempdocid[$k][1] = $dbnewdocid[$i][1];
          $tempdocid[$k][2] = $dbnewdocid[$i][2];
          $i++;
          $j++;
          $k++;
        }
        elseif ($dbdocid[$j][1] == $dbnewdocid[$i][1] && $dbdocid[$j][2] == $dbnewdocid[$i][2]) {
          if ($quiet == 0) {
            echo $admin282.$dbnewdocid[$i][1].$admin300;
            echo $admin284.$dbnewdocid[$i][1].$admin285.$dbnewdocid[$i][0].$admin286.$dbnewdocid[$i][2].$admin287;
          }
          switch ($dbnewdocid[$i][0]) {
          case TYP_ART    : $restart = 1;   break;
          case TYP_LINKS  : $reslink = 1;   break;
          case TYP_DNLOAD : $resdnload = 1; break;
          case TYP_FORUM  : $resforum = 1;  break;
          case TYP_NEWS   : $resnews = 1;   break;
          case TYP_PHOTO  : $resphoto = 1;  break;
          case TYP_REACT  : $resreact = 1;  break;
          case TYP_FAQ    : $resfaq = 1;    break;
          case TYP_AGENDA : $resagenda = 1; break;
          case TYP_BLOG   : $resblog = 1;   break;
          case TYP_REBLOG : $resreblog = 1; break;
          }
          switch ($dbdocid[$j][0]) {
          case TYP_ART    : $restart = 1;   break;
          case TYP_LINKS  : $reslink = 1;   break;
          case TYP_DNLOAD : $resdnload = 1; break;
          case TYP_FORUM  : $resforum = 1;  break;
          case TYP_NEWS   : $resnews = 1;   break;
          case TYP_PHOTO  : $resphoto = 1;  break;
          case TYP_REACT  : $resreact = 1;  break;
          case TYP_FAQ    : $resfaq = 1;    break;
          case TYP_AGENDA : $resagenda = 1; break;
          case TYP_BLOG   : $resblog = 1;   break;
          case TYP_REBLOG : $resreblog = 1; break;
          }
          $tempdocid[$k][0] = $dbnewdocid[$i][0];
          $tempdocid[$k][1] = $dbnewdocid[$i][1];
          $tempdocid[$k][2] = $dbnewdocid[$i][2];
          $i++;
          $j++;
          $k++;
        }
        elseif ($dbdocid[$j][1] < $dbnewdocid[$i][1] || ($dbdocid[$j][1] > $docmax && $whiletoomuch == 1)) {
          if ($quiet == 0) {
            echo $admin282.$dbdocid[$j][1].$admin288;
            echo $admin284.$dbdocid[$j][1].$admin285.$dbdocid[$j][0].$admin286.$dbdocid[$j][2].$admin287;
          }
          switch ($dbdocid[$j][0]) {
          case TYP_ART    : $restart = 1;   break;
          case TYP_LINKS  : $reslink = 1;   break;
          case TYP_DNLOAD : $resdnload = 1; break;
          case TYP_FORUM  : $resforum = 1;  break;
          case TYP_NEWS   : $resnews = 1;   break;
          case TYP_PHOTO  : $resphoto = 1;  break;
          case TYP_REACT  : $resreact = 1;  break;
          case TYP_FAQ    : $resfaq = 1;    break;
          case TYP_AGENDA : $resagenda = 1; break;
          case TYP_BLOG   : $resblog = 1;   break;
          case TYP_REBLOG : $resreblog = 1; break;
          }
          $j++;
        }
        elseif ($dbdocid[$j][1] > $dbnewdocid[$i][1]) {
          if ($quiet == 0) {
            echo $admin282.$dbnewdocid[$i][1].$admin283;
            echo $admin284.$dbnewdocid[$i][1].$admin285.$dbnewdocid[$i][0].$admin286.$dbnewdocid[$i][2].$admin287;
          }
          switch ($dbnewdocid[$i][0]) {
          case TYP_ART    : $restart = 1;   break;
          case TYP_LINKS  : $reslink = 1;   break;
          case TYP_DNLOAD : $resdnload = 1; break;
          case TYP_FORUM  : $resforum = 1;  break;
          case TYP_NEWS   : $resnews = 1;   break;
          case TYP_PHOTO  : $resphoto = 1;  break;
          case TYP_REACT  : $resreact = 1;  break;
          case TYP_FAQ    : $resfaq = 1;    break;
          case TYP_AGENDA : $resagenda = 1; break;
          case TYP_BLOG   : $resblog = 1;   break;
          case TYP_REBLOG : $resreblog = 1; break;
          }
          $tempdocid[$k][0] = $dbnewdocid[$i][0];
          $tempdocid[$k][1] = $dbnewdocid[$i][1];
          $tempdocid[$k][2] = $dbnewdocid[$i][2];
          $i++;
          $k++;
        }
      }
      $whiletest = $tempdocid[$k-1][1];
    }
  }
  if (ReadCounter(NEXTID) != $tempdocid[count($tempdocid)-1][1]) {
    WriteCounter(NEXTID, $tempdocid[count($tempdocid)-1][1]);
    if ($quiet == 0) {
      echo $admin304." (".$tempdocid[count($tempdocid)-1][1].")<br />";
    }
    $onerror++;
  }
  if ($onerror > 0) {
    WriteDBFields(DOCID, $tempdocid);
    if ($quiet == 0) {
      echo $admin289;
    }
    if ($restart == 1) {
      UpdateDBdtb(TYP_ART);
      if ($quiet == 0) {
        echo $admin290;
      }
    }
    if ($reslink == 1) {
      UpdateDBdtb(TYP_LINKS);
      if ($quiet == 0) {
        echo $admin291;
      }
    }
    if ($resdnload == 1) {
      UpdateDBdtb(TYP_DNLOAD);
      if ($quiet == 0) {
        echo $admin292;
      }
    }
    if ($resphoto == 1) {
      UpdateDBdtb(TYP_PHOTO);
      if ($quiet == 0) {
        echo $admin332;
      }
    }
    if ($resnews == 1 && $serviz[16] == "on") {
      include(CHEMIN.INCREP."funcrss.php");
      UpdateDBnews();
      if ($quiet == 0) {
        echo $admin293;
      }
    }
    if ($resforum == 1) {
      UpdateDBforum("mod", 0);
      if ($quiet == 0) {
        echo $admin294;
      }
    }
    if ($resreact == 1) {
      UpdateDBreact("mod", 0);
      if ($quiet == 0) {
        echo $admin479;
      }
    }
    if ($resfaq == 1) {
      UpdateDBdtb(TYP_FAQ);
      if ($quiet == 0) {
        echo $admin912;
      }
    }
   if ($resagenda == 1) {
      UpdateDBdtb(TYP_AGENDA);
      if ($quiet == 0) {
        echo $admin913;
      }
    }
   if ($resblog == 1) {
      UpdateDBdtb(TYP_BLOG);
      if ($quiet == 0) {
        echo $admin911;
      }
    }
   if ($resreblog == 1) {
      UpdateDBreblog("mod", 0);
      if ($quiet == 0) {
        echo $admin914;
      }
    }
  }
  return $onerror;
}
?>
