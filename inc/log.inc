<?php
/*
    Activity Log - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2008 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.2 (05 January 2003)   : complete rewrite of Stats module
      v1.3 (06 January 2003)   : bug correction (use of strlen() instead of count()
                                   in $log1 string length calculation)
                                 moved InitDBlog() function to functions.php
                                 upgraded initial logd.dtb file integrity check
      v1.4 (07 January 2003)   : introduced logh.dtb for not loosing all of logd.dtb data
                                   in case of accidental delete of logd.dtb file
                                 bug correction in trapping hits
      v1.5 (10 January 2003)   : replaced Lynx and WebTV browsers by DA and iCab
      v2.0 (27 February 20O3)  : added fortopic.php log (I forgot it in v1.9) and photorama.php log
      v2.1 (10 March 2003)     : no change
      v2.2 (22 April 2003)     : access to ipstats.dtb standardized
      v2.4 (24 September 2003) : moved counter upgrade from inc/boxcount.inc to inc/log.inc
                                 created $dbstats, $dbipstats, $dbstatsbk and $dbcounter variables
                                 added FileDBExist() function
                                 secured $log1 parameter
      v2.4p1 (26 Sept. 2003)   : bug correction = now counts back Number of Visitors in Stats Module
      v2.4p2 (28 Sept. 2003)   : bug correction = counter follow-up e-mail sends back counter value
      v3.0 (25 February 2004)  : added logbook management (by B@lou, Nicolas Alves and Laurent Duveau, real team work!)
                                 replaced $REQUEST_URI global variable by $SCRIPT_NAME for IIS compatibility (thanks Erik)
      v3.0p2 (09 April 2004)   : compatibility fix: now GuppY is fully compatible with Abyss webserver and IIS
      v4.0 (06 December 2004)  : no change
      v4.5 (15 Fébruary 2005)  : corrected initialisation (by Jean-Mi)
                                 no log stats for calendar.php (by Jean-Mi)
      v4.5.1 (06 July 2002)    : corrected sending mail (by Icare)
      v4.6.9 (25 December 2008): correction of the inconsistency of the statistics #218
                                 addition/correction of the statistics for the pages Blog and Admin #216
                                 correction of the conflict of variables with the planner #250
      v4.6.13 (22 May 2010) : file forgotten into 4.6.12
      v4.6.14 (14 February 2011)   : corrected $log2 
      v4.6.17 (21 October 2011) : added browser Safari, Chrome (thanks François)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "log.inc")) {
  header("location:../index.php");
  die();
}

if (!isset($_SERVER['REQUEST_URI'])) {
  $REQUEST_URI = $_SERVER['SCRIPT_NAME']."?".$_SERVER['QUERY_STRING'];
}
$log1 = strip_tags($REQUEST_URI);

$log2=$_SERVER["HTTP_USER_AGENT"];
if((strstr($log2, "Nav")) || (strstr($log2, "Gold")) || (strstr($log2, "X11")) || (strstr($log2, "Netscape")) AND (!strstr($log2, "MSIE"))) $browser = 0;
elseif(strstr($log2, "MSIE")) $browser = 1;
elseif(strstr($log2, "Mozilla")) $browser = 2;
elseif(strstr($log2, "DA")) $browser = 3;
elseif(strstr($log2, "Opera")) $browser = 4;
elseif(strstr($log2, "iCab")) $browser = 5;
elseif(strstr($log2, "Konqueror")) $browser = 6;
elseif(strstr($log2, "Safari")) $browser = 9;
elseif(strstr($log2, "Chrome")) $browser = 10;
elseif((strstr($log2, "bot")) || (strstr($log2, "Google")) || (strstr($log2, "Slurp")) || (strstr($log2, "Scooter")) || (strstr($log2, "Spider")) || (strstr($log2, "Infoseek"))) $browser = 7;
else $browser = 8;

$log3 = $REMOTE_ADDR;
$yr = (integer) date("Y");
$mh = (integer) date("m");
$dy = (integer) date("d");
$hr = (integer) date("H");

$dblog = array();
$lognum = 0;
while ($dblog[7][0] != 1 && $lognum < 10) {
  if (FileDBExist(DBLOGH)) {
    $dblog = ReadDBFields(DBLOGH);
  }
  else {
    $dblog = InitDBlog(1);
    $dblog[0][0] = $hr;
  }
  $lognum++;
}
if ($lognum == 10) {
  $dblog = InitDBlog(1);
  $dblog[0][0] = $hr;
}

if ($hr != $dblog[0][0]) {
  $dblog[7][0] = 0;
  WriteDBFields(DBLOGH,$dblog);
  if (FileDBExist(DBLOGD)) {
    $dblod = ReadDBFields(DBLOGD);
  }
  else {
    $dblod = InitDBlog(24);
    $dblod[0][0] = $dy;
  }
  for ($i = 0; $i < 14; $i++) {$dblod[1][$i] = $dblod[1][$i]+$dblog[1][$i];}
  for ($i = 0; $i < 2; $i++) {$dblod[2][$i] = $dblod[2][$i]+$dblog[2][$i];}
  for ($i = 0; $i < 9; $i++) {$dblod[3][$i] = $dblod[3][$i]+$dblog[3][$i];}
  for ($i = 0; $i < 10; $i++) {$dblod[4][$i] = $dblod[4][$i]+$dblog[4][$i];}
  $dblod[5][$dblog[0][0]] = $dblod[5][$dblog[0][0]]+$dblog[5][0];
  $dblod[6][$dblog[0][0]] = $dblod[6][$dblog[0][0]]+$dblog[6][0];
  WriteDBFields(DBLOGD,$dblod);
  $dblog = InitDBlog(1);
  $dblog[0][0] = $hr;
  WriteDBFields(DBLOGH,$dblog);
  if ($dy != $dblod[0][0]) {
    if (FileDBExist(DBLOGM)) {
      $dblom = ReadDBFields(DBLOGM);
    }
    else {
      $dblom = InitDBlog(31);
      $dblom[0][0] = $mh;
    }
    for ($i = 0; $i < 14; $i++) {$dblom[1][$i] = $dblom[1][$i]+$dblod[1][$i];}
    for ($i = 0; $i < 2; $i++) {$dblom[2][$i] = $dblom[2][$i]+$dblod[2][$i];}
    for ($i = 0; $i < 9; $i++) {$dblom[3][$i] = $dblom[3][$i]+$dblod[3][$i];}
    for ($i = 0; $i < 10; $i++) {$dblom[4][$i] = $dblom[4][$i]+$dblod[4][$i];}
    for ($i = 0; $i < 24; $i++) {$dblom[5][$dblod[0][0]-1] = $dblom[5][$dblod[0][0]-1]+$dblod[5][$i];}
    for ($i = 0; $i < 24; $i++) {$dblom[6][$dblod[0][0]-1] = $dblom[6][$dblod[0][0]-1]+$dblod[6][$i];}
    WriteDBFields(DBLOGM,$dblom);
    $dblod = InitDBlog(24);
    $dblod[0][0] = $dy;
    WriteDBFields(DBLOGD,$dblod);
    if ($mh != $dblom[0][0]) {
      WriteDBFields(DBLOGL,$dblom);
      if (FileDBExist(DBLOGY)) {
        $dbloy = ReadDBFields(DBLOGY);
      }
      else {
        $dbloy = InitDBlog(12);
        $dbloy[0][0] = $yr;
      }
      for ($i = 0; $i < 14; $i++) {$dbloy[1][$i] = $dbloy[1][$i]+$dblom[1][$i];}
      for ($i = 0; $i < 2; $i++) {$dbloy[2][$i] = $dbloy[2][$i]+$dblom[2][$i];}
      for ($i = 0; $i < 9; $i++) {$dbloy[3][$i] = $dbloy[3][$i]+$dblom[3][$i];}
      for ($i = 0; $i < 10; $i++) {$dbloy[4][$i] = $dbloy[4][$i]+$dblom[4][$i];}
      for ($i = 0; $i < 31; $i++) {$dbloy[5][$dblom[0][0]-1] = $dbloy[5][$dblom[0][0]-1]+$dblom[5][$i];}
      for ($i = 0; $i < 31; $i++) {$dbloy[6][$dblom[0][0]-1] = $dbloy[6][$dblom[0][0]-1]+$dblom[6][$i];}
      WriteDBFields(DBLOGY,$dbloy);
      $dblom = InitDBlog(31);
      $dblom[0][0] = $mh;
      WriteDBFields(DBLOGM,$dblom);
      if ($yr != $dbloy[0][0]) {
        WriteDBFields(DBLOGP,$dbloy);
        $dbloy = InitDBlog(12);
        $dbloy[0][0] = $yr;
        WriteDBFields(DBLOGY,$dbloy);
      }
    }
  }
}
$pag_bool = true;
if(strstr($log1, "articles.php")) $pgtype = 0;
elseif(strstr($log1, "download.php")) $pgtype = 1;
elseif(strstr($log1, "faq.php")) $pgtype = 2;
elseif(strstr($log1, "forum.php") || strstr($log1, "thread.php") || strstr($log1, "fortopic.php")) $pgtype = 3;
elseif(strstr($log1, "guestbk.php")) $pgtype = 4;
elseif(strstr($log1, "index.php") || $log1[strlen($log1)-1] == "/") $pgtype = 5;
elseif(strstr($log1, "links.php")) $pgtype = 6;
elseif(strstr($log1, "news.php")) $pgtype = 7;
elseif(strstr($log1, "photos.php") || strstr($log1, "photorama.php")) $pgtype = 8;
elseif(strstr($log1, "poll.php")) $pgtype = 9;
elseif(strstr($log1, "search.php")) $pgtype = 10;
elseif(strstr($log1, "stats.php")) $pgtype = 11;
elseif(strstr($log1, "admin.php")) $pgtype = 12;
elseif(strstr($log1, "blog.php") || strstr($log1, "blogs.php")) $pgtype = 13;
else {
  $pag_bool = false;
}

if (
    ($pgtype == 5)  && ($configlog[1]  == "on") || // accueil
    ($pgtype == 7)  && ($configlog[2]  == "on") || // news
    ($pgtype == 8)  && ($configlog[3]  == "on") || // photos
    ($pgtype == 1)  && ($configlog[4]  == "on") || // download
    ($pgtype == 6)  && ($configlog[5]  == "on") || // links
    ($pgtype == 2)  && ($configlog[6]  == "on") || // faq
    ($pgtype == 4)  && ($configlog[7]  == "on") || // guestbook
    ($pgtype == 3)  && ($configlog[8]  == "on") || // forum
    ($pgtype == 11) && ($configlog[9]  == "on") || // stats
    ($pgtype == 12) && ($configlog[10] == "on") || // admin
    ($pgtype == 13) && ($configlog[11] == "on") || // blog
    $pgtype == 0 || $pgtype == 9 || $pgtype == 10  // articles | sondage | recherche
   ) {
  $loguser = Array();
  if (FileDBExist(DBLOGBOOK)) {
    $loguser[0] = GetCurrentDateTime();
    $loguser[1] = $log3;
    $loguser[2] = $HTTP_REFERER;
    $loguser[3] = @gethostbyaddr($log3);
    $loguser[4] = $browser;
    AppendDBFields(DBLOGBOOK,$loguser);
  }
  else {
    $loguser[0][0] = GetCurrentDateTime();
    $loguser[0][1] = $log3;
    $loguser[0][2] = $HTTP_REFERER;
    $loguser[0][3] = @gethostbyaddr($log3);
    $loguser[0][4] = $browser;
    WriteDBFields(DBLOGBOOK,$loguser);
  }
  $amsglog = CountDBFields(DBLOGBOOK);
  while ($amsglog > $configlog[0]) {
    DeleteDBFieldById(DBLOGBOOK);
    $amsglog = CountDBFields(DBLOGBOOK);
  }
}

if ($pag_bool == true) {
  $dblog[1][$pgtype]++;
  $dblog[5][0]++;

  if(empty($lang[1]))
    $dblog[2][0]++;
  elseif(strstr($log1, "lng=".$lang[1]))
    $dblog[2][1]++;
  else
    $dblog[2][0]++;

  $var_bool = false;
  $subdata = array();
  $subdata = ReadDBFields(DBIPSTATS);
  for ($i = 0; $i < count($subdata); $i++) {
    if ($log3 == $subdata[$i][0]) {
      $now_time = time();
      list($zjour, $zmois, $zannee) = explode("/", substr($subdata[$i][1], 0, 10));
      list($zheure, $zminute, $zseconde) = explode(":", substr($subdata[$i][1], 10, 18));
      if ($now_time < mktime($zheure, $zminute, $zseconde, $zmois, $zjour, $zannee) + HIT_TIME) {
        $var_bool = true;
      }
    }
  }
  if ($var_bool == false) {
    $dblog[6][0]++;
    $dblog[3][$browser]++;

    if(strstr($log2, "Win")) $dblog[4][0]++;
    elseif((strstr($log2, "Mac")) || (strstr($log2, "PPC"))) $dblog[4][1]++;
    elseif(strstr($log2, "Linux")) $dblog[4][2]++;
    elseif(strstr($log2, "FreeBSD")) $dblog[4][3]++;
    elseif(strstr($log2, "SunOS")) $dblog[4][4]++;
    elseif(strstr($log2, "IRIX")) $dblog[4][5]++;
    elseif(strstr($log2, "BeOS")) $dblog[4][6]++;
    elseif(strstr($log2, "OS/2")) $dblog[4][7]++;
    elseif(strstr($log2, "AIX")) $dblog[4][8]++;
    else $dblog[4][9]++;
  }
  WriteDBFields(DBLOGH,$dblog);
}
$tabcounter = CompteVisites(DBIPSTATS, DBSTATS);
if ($tabcounter[0] > 0 && ($tabcounter[0]/10) == intval($tabcounter[0]/10)) {
  WriteCounter(DBSTATSBK, $tabcounter[0]);
}
if ($tabcounter[0] < 10) {
  $oldcount = ReadCounter(DBSTATSBK);
  if ($oldcount > 10) {
    WriteCounter(DBSTATS,$oldcount);
    $tabcounter[0] = $oldcount;
  }
}
if ($supervision[0] == "on" && $supervision[1] > 0) {
  if (($tabcounter[0]/$supervision[1]) == intval($tabcounter[0]/$supervision[1])) {
    $old_count = ReadCounter(DBCOUNTER);
    if ($tabcounter[0] != $old_count) {
      WriteCounter(DBCOUNTER,$tabcounter[0]);
      $eSub = $site[0]." - ".$web102;
      $eMsg = $site[0]." - ".$web103." ".$web102." ".$web104." ".date("d/m/Y H:i:s").".<br />";
      $eMsg .= $web105." ".$tabcounter[0].".";
      eMailHtmlTo($eSub,$eMsg,"");
    }
  }
}
?>
