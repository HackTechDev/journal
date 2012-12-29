<?php
/*
    Stats calculation - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)     : initial release
      v1.1 (02 January 2003)      : added $statactor variable (in order to avoid overwrites of Stats database when more users ask for Stats simultaneously. Now only Admin can compact the Stats database)
      v1.2 (05 January 2003)      : complete rewrite of Stats module
      v1.4 (07 January 2003)      : introduced logh.dtb
      v1.5 (10 January 2003)      : replaced Lynx and WebTV browsers by DA and iCab
      v4.6.5 (05 December 2007)   : added blog (by Icare)
      v4.6.6 (14 April 2008)      : $nmonth has now the real number of days in the month (by Icare)
      v4.6.9 (25 December 2008)   : addition/correction of the statistics for the Blog and Admin pages #216
      v4.6.12 (01 May 2010)      : added display stats of previous month (by Icare)
      v4.6.14 (02 April 2011)     : correction of the number of days for previous month (by Jchouix)
      v4.6.15 (30 June 2011)     : correction of the number of days for previous month (by Jchouix)	  
*/

if (stristr($_SERVER["SCRIPT_NAME"], "statcal.inc")) {
  header("location:../index.php");
  die();
}

$nnav = array("Netscape", "MSIE", "Mozilla", "DA", "Opera", "iCab", "Konqueror", "Robot", "Other");
$nos = array("Windows", "Mac", "Linux", "FreeBSD", "SunOS", "IRIX", "BeOS", "OS/2", "AIX", "Other");

// $npage = array("articles", "download", "faq", "forum", "guestbook", "index", "links", "news", "photos", "poll", "search", "stats", "admin", "blog");
if ($lng == $lang[0]) {
    $npage = array($web169, $nom[1], $nom[24], $nom[22], $nom[9], $nom[0], $nom[3], $nom[7], $nom[2], $nom[6], $nom[20], $nom[26], $web144, $nom[42]);
} else {
    $npage = array($web169, $nom[11], $nom[25], $nom[23], $nom[19], $nom[10], $nom[13], $nom[17], $nom[12], $nom[16], $nom[21], $nom[27], $web144, $nom[43]);
}

$nlang = array($lang[0], $lang[1]);
$nhour = array("0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23");
$nmonthM = array('jan', 'feb', 'mar', 'apr','may', 'jun', 'jul', 'aug', 'sep', 'oct', 'nov', 'dec');

$currentMonth = strtolower(date('M'));

if ($per == '5') {
    $key = array_search($currentMonth, $nmonthM);
    $currentMonth = ($key > 0) ? $nmonthM[$key -1] : 'dec';  
}
 
if (in_array($currentMonth, array('jan', 'mar', 'may', 'jul', 'aug', 'oct', 'dec'))) {
    $nbDays = 31;    
} elseif (in_array($currentMonth, array('apr', 'jun', 'sep', 'nov'))) {
    $nbDays = 30;
} else {
    $nybiss = date('L');
    $nbDays = empty($nybiss)? 28 : 29; 
}
    
for ($n = 0; $n < $nbDays; $n++) {
    $nmonth[$n] = $n + 1;
}
$nyear = array("1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12");

if ($per == "1") {
  $statslog = ReadDBFields(DBLOGD);
  $dbt1 = ReadDBFields(DBLOGH);

  for ($i = 0; $i < 14; $i++) { $statslog[1][$i] = $statslog[1][$i]+$dbt1[1][$i]; }
  for ($i = 0; $i < 2; $i++) { $statslog[2][$i] = $statslog[2][$i]+$dbt1[2][$i]; }
  for ($i = 0; $i < 9; $i++) { $statslog[3][$i] = $statslog[3][$i]+$dbt1[3][$i]; }
  for ($i = 0; $i < 10; $i++) { $statslog[4][$i] = $statslog[4][$i]+$dbt1[4][$i]; }
  $statslog[5][$dbt1[0][0]] = $statslog[5][$dbt1[0][0]]+$dbt1[5][0];
  $statslog[6][$dbt1[0][0]] = $statslog[6][$dbt1[0][0]]+$dbt1[6][0];
}
elseif ($per == "2") {
  $statslog = ReadDBFields(DBLOGM);
  $dbt1 = ReadDBFields(DBLOGH);
  $dbt2 = ReadDBFields(DBLOGD);

  for ($i = 0; $i < 14; $i++) { $dbt2[1][$i] = $dbt2[1][$i]+$dbt1[1][$i]; }
  for ($i = 0; $i < 2; $i++) { $dbt2[2][$i] = $dbt2[2][$i]+$dbt1[2][$i]; }
  for ($i = 0; $i < 9; $i++) { $dbt2[3][$i] = $dbt2[3][$i]+$dbt1[3][$i]; }
  for ($i = 0; $i < 10; $i++) { $dbt2[4][$i] = $dbt2[4][$i]+$dbt1[4][$i]; }
  $dbt2[5][$dbt1[0][0]] = $dbt2[5][$dbt1[0][0]]+$dbt1[5][0];
  $dbt2[6][$dbt1[0][0]] = $dbt2[6][$dbt1[0][0]]+$dbt1[6][0];

  for ($i = 0; $i < 14; $i++) { $statslog[1][$i] = $statslog[1][$i]+$dbt2[1][$i]; }
  for ($i = 0; $i < 2; $i++) { $statslog[2][$i] = $statslog[2][$i]+$dbt2[2][$i]; }
  for ($i = 0; $i < 9; $i++) { $statslog[3][$i] = $statslog[3][$i]+$dbt2[3][$i]; }
  for ($i = 0; $i < 10; $i++) { $statslog[4][$i] = $statslog[4][$i]+$dbt2[4][$i]; }
  for ($i = 0; $i < 24; $i++) { $statslog[5][$dbt2[0][0]-1] = $statslog[5][$dbt2[0][0]-1]+$dbt2[5][$i]; }
  for ($i = 0; $i < 24; $i++) { $statslog[6][$dbt2[0][0]-1] = $statslog[6][$dbt2[0][0]-1]+$dbt2[6][$i]; }
}
elseif ($per == "5") {
  $statslog = ReadDBFields(DBLOGL);

}
elseif ($per == "3") {
  $statslog = ReadDBFields(DBLOGY);
  $dbt1 = ReadDBFields(DBLOGH);
  $dbt2 = ReadDBFields(DBLOGD);
  $dbt3 = ReadDBFields(DBLOGM);

  for ($i = 0; $i < 14; $i++) { $dbt2[1][$i] = $dbt2[1][$i]+$dbt1[1][$i]; }
  for ($i = 0; $i < 2; $i++) { $dbt2[2][$i] = $dbt2[2][$i]+$dbt1[2][$i]; }
  for ($i = 0; $i < 9; $i++) { $dbt2[3][$i] = $dbt2[3][$i]+$dbt1[3][$i]; }
  for ($i = 0; $i < 10; $i++) { $dbt2[4][$i] = $dbt2[4][$i]+$dbt1[4][$i]; }
  $dbt2[5][$dbt1[0][0]] = $dbt2[5][$dbt1[0][0]]+$dbt1[5][0];
  $dbt2[6][$dbt1[0][0]] = $dbt2[6][$dbt1[0][0]]+$dbt1[6][0];

  for ($i = 0; $i < 14; $i++) { $dbt3[1][$i] = $dbt3[1][$i]+$dbt2[1][$i]; }
  for ($i = 0; $i < 2; $i++) { $dbt3[2][$i] = $dbt3[2][$i]+$dbt2[2][$i]; }
  for ($i = 0; $i < 9; $i++) { $dbt3[3][$i] = $dbt3[3][$i]+$dbt2[3][$i]; }
  for ($i = 0; $i < 10; $i++) { $dbt3[4][$i] = $dbt3[4][$i]+$dbt2[4][$i];}
  for ($i = 0; $i < 24; $i++) { $dbt3[5][$dbt2[0][0]-1] = $dbt3[5][$dbt2[0][0]-1]+$dbt2[5][$i]; }
  for ($i = 0; $i < 24; $i++) { $dbt3[6][$dbt2[0][0]-1] = $dbt3[6][$dbt2[0][0]-1]+$dbt2[6][$i]; }

  for ($i = 0; $i < 14; $i++) { $statslog[1][$i] = $statslog[1][$i]+$dbt3[1][$i]; }
  for ($i = 0; $i < 2; $i++) { $statslog[2][$i] = $statslog[2][$i]+$dbt3[2][$i]; }
  for ($i = 0; $i < 9; $i++) { $statslog[3][$i] = $statslog[3][$i]+$dbt3[3][$i]; }
  for ($i = 0; $i < 10; $i++) { $statslog[4][$i] = $statslog[4][$i]+$dbt3[4][$i]; }
  for ($i = 0; $i < 31; $i++) { $statslog[5][$dbt3[0][0]-1] = $statslog[5][$dbt3[0][0]-1]+$dbt3[5][$i]; }
  for ($i = 0; $i < 31; $i++) { $statslog[6][$dbt3[0][0]-1] = $statslog[6][$dbt3[0][0]-1]+$dbt3[6][$i]; }
}
else {
  $statslog = ReadDBFields(DBLOGP);
}

if ($anal == "3") {
  $snav = array();
  $maxsnav = 1;
  $sos = array();
  $maxsos = 1;
  for ($j = 0; $j < count($nnav); $j++) {
    $snav[$j][0] = $statslog[3][$j];
    $snav[$j][1] = $nnav[$j];
    $maxsnav = Max($maxsnav,$snav[$j][0]);
  }
  for ($j = 0; $j < count($nos); $j++) {
    $sos[$j][0] = $statslog[4][$j];
    $sos[$j][1] = $nos[$j];
    $maxsos = Max($maxsos,$sos[$j][0]);
  }
  @rsort($snav);
  @rsort($sos);
}
elseif ($anal == "2") {
  $slang = array();
  $maxslang = 1;
  for ($j = 0; $j < count($nlang); $j++) {
    $slang[$j][0] = $statslog[2][$j];
    $slang[$j][1] = $nlang[$j];
    $maxslang = Max($maxslang,$slang[$j][0]);
  }
  @rsort($slang);

  $spage = array();
  $maxspage = 1;
  for ($j = 0; $j < count($npage); $j++) {
    $spage[$j][0] = $statslog[1][$j];
    $spage[$j][1] = $npage[$j];
    $maxspage = Max($maxspage,$spage[$j][0]);
  }
  if (isset($show_stat_admin) && !$show_stat_admin) {
    $spage[12] = $spage[13];
    unset($spage[13]);
  }
  @rsort($spage);
}
else {
  $shit = array();
  $snbpage = array();
  $maxshit = 1;
  $maxsnbpage = 1;
  if ($per == 1) {
    for ($j = 0; $j < count($nhour); $j++) {
      $shit[$j][0] = $statslog[6][$j];
      $shit[$j][1] = $nhour[$j];
      $maxshit = Max($maxshit,$shit[$j][0]);
      $snbpage[$j][0] = $statslog[5][$j];
      $snbpage[$j][1] = $nhour[$j];
      $maxsnbpage = Max($maxsnbpage,$snbpage[$j][0]);
    }
  }
  elseif ($per == 2 || $per == "5") {
    for ($j = 0; $j < count($nmonth); $j++) {
      $shit[$j][0] = $statslog[6][$j];
      $shit[$j][1] = $nmonth[$j];
      $maxshit = Max($maxshit, $shit[$j][0]);
      $snbpage[$j][0] = $statslog[5][$j];
      $snbpage[$j][1] = $nmonth[$j];
      $maxsnbpage = Max($maxsnbpage,$snbpage[$j][0]);
    }
  }
  else {
    for ($j = 0; $j < count($nyear); $j++) {
      $shit[$j][0] = $statslog[6][$j];
      $shit[$j][1] = $nyear[$j];
      $maxshit = Max($maxshit,$shit[$j][0]);
      $snbpage[$j][0] = $statslog[5][$j];
      $snbpage[$j][1] = $nyear[$j];
      $maxsnbpage = Max($maxsnbpage,$snbpage[$j][0]);
    }
  }
}
?>
