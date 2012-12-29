<?php
/*
    Functions - GuppY PHP Script - version 3.0
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002) : initial release
      v1.1 (02 January 2003)  : added AppendDBFields() function
                                replaced WriteDBFields() by AppendDBFields() where appropriate
                                  (in order to avoid overwrites when more users perform "add" simultaneously)
      v1.2 (05 January 2003)   : created database art.dtb for quicker display
                                   this new database is managed by the UpdateDBart() function => see update v1.7
                                 created databases thread.dtb and forum.dtb for quicker display of forum threads
                                   these new databases are managed by the UpdateDBforum() function
      v1.3 (06 January 2003)   : moved InitDBlog() function from log.inc
                                 added eMailTo() function
      v1.4 (07 January 2003)   : introduced logh.dtb for not loosing all of logd.dtb data
                                   in case of accidental erasal of logd.dtb file
      v1.5 (10 January 2003)   : no change
      v1.6 (23 January 2003)   : added option to hide on the site the e-mail address of poster
                                   that is insertion of a new field ($fieldd1) in database and
                                   update in UpdateDBforum() and ActionOnFields() functions
                                 added StartTimer() and StopTimer() functions
      v1.7 (28 January 2003)   : updated the eMailTo() function to add destination e-mail for recommend to a friend option
                                 created databases links.dtb and dnload.dtb files for category sorting of links and downloads
                                   these new databases (and art.dtb) are managed by the UpdateDBdtb() function
                                   insertion of a new field ($fieldd2) in database
                                 migrated news.dat management from admin.inc and upgraded it
      v1.8 (05 February 2003)  : added category for forum
                                   that is update in UpdateDBforum() function
      v1.9 (11 February 2003)  : moved make_seed() function (renamed as MakeSeed) from boxcita.inc (also used by
                                   the new boxban.inc banner management)
      v2.0 (27 February 2003)  : added advanced photo service, that is ActionOnFields() function small update
                                 added BreakEMail() function
      v2.1 (10 March 2003)     : no change
      v2.2 (22 April 2003)     : added INCREP variable (needed for boxes free positionning)
                                 updated UpdateDBdtb() function for left and right articles boxes management
                                 upgraded CompteVisites() function to have it compliant to the GuppY DB
                                 added bmp type in IsImage() function
                                 updated souriez array definition for management of smileys themes
                                 added DrawSmileys() function
                                 cleanup in the images organization (Smileys)
      v2.3 (27 July 2003)      : replaced mtitre class by titre class in htable1()
                                 background of central boxes also change color according to mouse move in htable()
                                 removed link on counters numbers in counter box in the AfficheCompteur() function
                                 added US date format management
                                 modified DrawSmileys() function
                                 added PathToImage() function
                                 added $ special character management in PutHR()
      v2.4 (24 September 2003) : upgraded CompteVisites() function to capture user pseudo of registered users
                                 added SplitText() function
                                 added react to an article option , that is new UpdateDBreact() function
                                 slightly upgraded the FileSizeInKb() function
                                 upgraded eMailTo() function to accept additional specific e-mailing according to webhosters
                                 added ReadDoc() and WriteDoc() functions and upgraded all required functions accordingly
                                 added ReadDocCounter(), WriteDocCounter() and UpdateDocCounter() functions
                                 created many new $d[something] variables and upgraded all required functions accordingly
                                 added GetCurrentDateTime(), FormatDate() and FormatDateStamp() functions to ease various date and time formatings
                                 reviewed all Files Read & Write functions
                                 added lookup for png and bmp images in IsImage() function
                                 added FileDBExist() and DestroyDBFile() functions
                                 added RemoveQuote() function
                                 added 3 additional free boxes (by Nicolas Alves and Laurent Duveau)
                                 created $typ_[name] variables and updated all scripts & functions accordingly
                                 upgraded forum indexes for a smaller size
                                 moved DejaVote() function from poll.php to functions.php (now also used for documents counters)
                                   and upgraded CompteVisites() function accordingly
      v3.0 (25 February 2004)  : added CheckDB1Field(), CheckDB2Fields(), CountDBFields(), DeleteDBFieldById(), CutLongWords() and WrapLongWords() functions
                                 added GenerateUID() and KeepGoodChars() function
                                 modified ReadDoc() and ReadDocCounter() functions to take into account new forum archiving module, upgraded in all scripts accordingly
                                 news are now published in the RSS standard Web content syndication format instead of a GuppY specific format
      v4.6.10 (7 September 2009)    : corrected #272
*/

if (stristr($_SERVER["SCRIPT_NAME"], "functions30.php")) {
  header("location:../index.php");
  die();
}

define("CONNECTOR", "||");

define("TYP_ART", "ar");
define("TYP_BANNER", "ba");
define("TYP_DNLOAD", "dn");
define("TYP_FAQ", "fa");
define("TYP_FOOTER", "ft");
define("TYP_FORUM", "fr");
define("TYP_THREAD", "frth");
define("TYP_FREEBOX1", "f1");
define("TYP_FREEBOX2", "f2");
define("TYP_FREEBOX3", "f3");
define("TYP_FREEBOX4", "f4");
define("TYP_GUESTBK", "gb");
define("TYP_HOMEPG", "ed");
define("TYP_LINKS", "li");
define("TYP_NEWS", "ne");
define("TYP_NWL", "nl");
define("TYP_PHOTO", "ph");
define("TYP_REACT", "ra");
define("TYP_RECO", "re");
define("TYP_RSS", "rs");
define("TYP_SPECIAL", "sp");
define("TYP_THINK", "ci");
define("TYP_AGENDA", "ag");

define("DATAREP", "data/");
define("ARCHREP", CHEMIN.DATAREP."archive/");
define("CACHEREP", CHEMIN.DATAREP."cache/");
define("USEREP", CHEMIN.DATAREP."usermsg/");

define("INCREP", "inc/");
define("DBEXT", ".dtb");
define("INCEXT", ".inc");

define("DBBASE", CHEMIN.DATAREP."doc");
define("DBIPBASE", CHEMIN.DATAREP."ipdoc");

define("DBPLUGIN", CHEMIN.DATAREP."plugin".DBEXT);
define("CONFIG", CHEMIN.DATAREP."config".INCEXT);
define("NEXTID", CHEMIN.DATAREP."nextid".DBEXT);
define("DOCID", CHEMIN.DATAREP."docid".DBEXT);

define("DBNEWSLETTER", CHEMIN.DATAREP."nwlist".DBEXT);
define("DBNEWS", CHEMIN.DATAREP."news");
define("DBLOGBOOK", CHEMIN.DATAREP."logbook".DBEXT);

define("DBART", CHEMIN.DATAREP.TYP_ART.DBEXT);
define("DBDNLOAD", CHEMIN.DATAREP.TYP_DNLOAD.DBEXT);
define("DBFAQ", CHEMIN.DATAREP.TYP_FAQ.DBEXT);
define("DBFORUMCAT", CHEMIN.DATAREP.TYP_FORUM."cat".DBEXT);
define("DBFORUM", CHEMIN.DATAREP.TYP_FORUM.DBEXT);
define("DBFORUMCOUNTER", CHEMIN.DATAREP.TYP_FORUM."count".DBEXT);
define("DBTHREAD", CHEMIN.DATAREP.TYP_THREAD.DBEXT);

define("DBFORUMARCHDATE", ARCHREP.TYP_FORUM."arch".DBEXT);
define("DBFORUMARCH", ARCHREP.TYP_FORUM.DBEXT);
define("DBTHREADARCH", ARCHREP.TYP_THREAD.DBEXT);

define("DBLINKS", CHEMIN.DATAREP.TYP_LINKS.DBEXT);
define("DBPHOTO", CHEMIN.DATAREP.TYP_PHOTO.DBEXT);
define("DBPOLL", CHEMIN.DATAREP."poll".DBEXT);
define("DBIPPOLL", CHEMIN.DATAREP."ippoll".DBEXT);
define("DBREACT", CHEMIN.DATAREP.TYP_REACT.DBEXT);
define("DBRSS", CHEMIN.DATAREP.TYP_RSS.DBEXT);

define("DBCOUNTER", CHEMIN.DATAREP."counter".DBEXT);
define("DBSTATS", CHEMIN.DATAREP."stats".DBEXT);
define("DBSTATSBK", CHEMIN.DATAREP."statsbk".DBEXT);
define("DBIPSTATS", CHEMIN.DATAREP."ipstats".DBEXT);

define("DBLOGH", CHEMIN.DATAREP."logh".DBEXT);
define("DBLOGD", CHEMIN.DATAREP."logd".DBEXT);
define("DBLOGM", CHEMIN.DATAREP."logm".DBEXT);
define("DBLOGY", CHEMIN.DATAREP."logy".DBEXT);
define("DBLOGP", CHEMIN.DATAREP."logp".DBEXT);

define("DBHOMEPAGE", CHEMIN.DATAREP.TYP_HOMEPG.INCEXT);
define("DBFOOT", CHEMIN.DATAREP.TYP_FOOTER.INCEXT);
define("DBSPECIAL", CHEMIN.DATAREP.TYP_SPECIAL.INCEXT);
define("DBFREEBOX1", CHEMIN.DATAREP.TYP_FREEBOX1.INCEXT);
define("DBFREEBOX2", CHEMIN.DATAREP.TYP_FREEBOX2.INCEXT);
define("DBFREEBOX3", CHEMIN.DATAREP.TYP_FREEBOX3.INCEXT);
define("DBFREEBOX4", CHEMIN.DATAREP.TYP_FREEBOX4.INCEXT);

define("HIT_TIME", 1800);

$couleurs = array("bleu", "jaune", "marron", "or", "orange", "outremer", "rose", "rouge", "vert", "violet");
$souriez = array(
	         array("|:-)", "inc/img/smileys/cool.gif"),
	         array(";-)", "inc/img/smileys/wink.gif"),
	         array(":-))", "inc/img/smileys/biggrin.gif"),
	         array(":-)", "inc/img/smileys/smile.gif"),
	         array(":-o", "inc/img/smileys/frown.gif"),
             array(":o)", "inc/img/smileys/eek.gif"),
	         array(":-((", "inc/img/smileys/mad.gif"),
	         array(":-(", "inc/img/smileys/confused.gif"),
	         array("8-)", "inc/img/smileys/rolleyes.gif"),
	         array(":-p", "inc/img/smileys/tongue.gif"),
	         array(";-(", "inc/img/smileys/cry.gif")
           );

function souriez($chaine) {
  global $souriez;
  $traite = str_replace($souriez[0][0], "<img src=\\\"".$souriez[0][1]."\\\" border=\\\"0\\\">", $chaine);
  $traite = str_replace($souriez[1][0], "<img src=\\\"".$souriez[1][1]."\\\" border=\\\"0\\\">", $traite);
  $traite = str_replace($souriez[2][0], "<img src=\\\"".$souriez[2][1]."\\\" border=\\\"0\\\">", $traite);
  $traite = str_replace($souriez[3][0], "<img src=\\\"".$souriez[3][1]."\\\" border=\\\"0\\\">", $traite);
  $traite = str_replace($souriez[4][0], "<img src=\\\"".$souriez[4][1]."\\\" border=\\\"0\\\">", $traite);
  $traite = str_replace($souriez[5][0], "<img src=\\\"".$souriez[5][1]."\\\" border=\\\"0\\\">", $traite);
  $traite = str_replace($souriez[6][0], "<img src=\\\"".$souriez[6][1]."\\\" border=\\\"0\\\">", $traite);
  $traite = str_replace($souriez[7][0], "<img src=\\\"".$souriez[7][1]."\\\" border=\\\"0\\\">", $traite);
  $traite = str_replace($souriez[8][0], "<img src=\\\"".$souriez[8][1]."\\\" border=\\\"0\\\">", $traite);
  $traite = str_replace($souriez[9][0], "<img src=\\\"".$souriez[9][1]."\\\" border=\\\"0\\\">", $traite);
  $traite = str_replace($souriez[10][0], "<img src=\\\"".$souriez[10][1]."\\\" border=\\\"0\\\">", $traite);
  return $traite;
}

function replaceimg($chaine) {
  global $souriez,$site;
  $traite = str_replace($souriez[0][0],"<img src=".$site[3].$souriez[0][1]." border=0>", $chaine);
  $traite = str_replace($souriez[1][0],"<img src=".$site[3].$souriez[1][1]." border=0>", $traite);
  $traite = str_replace($souriez[2][0],"<img src=".$site[3].$souriez[2][1]." border=0>", $traite);
  $traite = str_replace($souriez[3][0],"<img src=".$site[3].$souriez[3][1]." border=0>", $traite);
  $traite = str_replace($souriez[4][0],"<img src=".$site[3].$souriez[4][1]." border=0>", $traite);
  $traite = str_replace($souriez[5][0],"<img src=".$site[3].$souriez[5][1]." border=0>", $traite);
  $traite = str_replace($souriez[6][0],"<img src=".$site[3].$souriez[6][1]." border=0>", $traite);
  $traite = str_replace($souriez[7][0],"<img src=".$site[3].$souriez[7][1]." border=0>", $traite);
  $traite = str_replace($souriez[8][0],"<img src=".$site[3].$souriez[8][1]." border=0>", $traite);
  $traite = str_replace($souriez[9][0],"<img src=".$site[3].$souriez[9][1]." border=0>", $traite);
  $traite = str_replace($souriez[10][0],"<img src=".$site[3].$souriez[10][1]." border=0>", $traite);
  return $traite;
} 

function DrawSmileys($num) {
  global $souriez;
  echo "<p align=\"center\">\n";
  for ($i = 0; $i < count($souriez); $i++) {
    echo "<img src=\"".CHEMIN.$souriez[$i][1]."\" class=\"clsCursor\" border=\"0\" alt=\"".$souriez[$i][0]."\" onClick=\"JavaScript:AddSmiley".$num."('".$souriez[$i][0]."')\">&nbsp;\n";
  }
  echo "</p>";
}

function AfficheCompteur($chemino, $hits, $grow = 1) {
  $spot = "";
  for ($lecon = 0; $lecon < $grow - strlen($hits); $lecon++ ) {
    $spot .= "<IMG SRC=\"".$chemino."cnt0.gif\" BORDER=0>";
  }
  for ($lecon = 0; $lecon < strlen($hits); $lecon++) {
    $cols = substr($hits, $lecon, 1);
    $spot .= "<IMG SRC=\"".$chemino."cnt".$cols.".gif\" BORDER=0>";
  }
  echo $spot;
}

function DejaVote($file_ip, $d_time = 0) {
  global $REMOTE_ADDR, $userprefs;
  $remoteadr = $REMOTE_ADDR;
  $nbr_connect = 0;
  $var_bool = false;
  $user_bool = false;
  $subdata = array();
  $var_ip = array();
  $k = 0;
  if ($d_time == 0) {
    $d_time = HIT_TIME;
  }
  $subdata = ReadDBFields($file_ip);
  $now_time = time();
  for ($i = 0; $i < count($subdata); $i++) {
    list($jour, $mois, $annee) = explode("/", substr($subdata[$i][1], 0, 10));
    list($heure, $minute, $seconde) = explode(":", substr($subdata[$i][1], 10, 18));
    if ($now_time < mktime($heure, $minute, $seconde, $mois, $jour, $annee) + $d_time) {
      $nbr_connect++;
      $var_ip[$k][0] = $subdata[$i][0];
      if ($remoteadr == $subdata[$i][0]) {
        $var_bool = true;
      }
      $var_ip[$k][1] = $subdata[$i][1];
      if ($userprefs[5] != "") {
        $uprefname = $userprefs[1];
      }
      else {
        $uprefname = "";
      }
      if ($remoteadr == $subdata[$i][0] && $uprefname != $subdata[$i][2]) {
        $user_bool = true;
        $var_ip[$k][2] = $uprefname;
      }
      else {
        $var_ip[$k][2] = $subdata[$i][2];
      }
      $k++;
    }
  }
  if (!$var_bool) {
    $var_ip[$k][0] = $remoteadr;
    $var_ip[$k][1] = date("d/m/Y H:i:s");
    $var_ip[$k][2] = $userprefs[1];
    WriteDBFields($file_ip,$var_ip);
    $nbr_connect++;
  }
  elseif ($user_bool) {
    WriteDBFields($file_ip,$var_ip);
  }
  $retcmpt[0] = $var_bool;
  $retcmpt[1] = $nbr_connect;
  return $retcmpt;
}

function CompteVisites($file_ip, $file_counter) {
  $subdata = DejaVote($file_ip);
  $nbr_visit = ReadCounter($file_counter);	
  if (!$subdata[0]) {
    $nbr_visit++;
    WriteCounter($file_counter,$nbr_visit);
  }
  $retcmpt[0] = $nbr_visit;
  $retcmpt[1] = $subdata[1];
  return $retcmpt;
}

function IsImage($extn) {
  $imgok = 0;
  $extn = strtolower($extn);
  if ($extn == "gif" || $extn == "jpg" || $extn == "jpeg" || $extn == "png" || $extn == "bmp") {
    $imgok = 1;
  }
  return $imgok;
}

function ExtImage($extn){
  $extn = strtolower($extn);
  if ($extn == "php"){ return "php"; }
  if ($extn == "php3"){ return "php"; }
  if ($extn == "phtml"){ return "php"; }
  if ($extn == "htm"){ return "html"; }
  if ($extn == "html"){ return "html"; }
  if ($extn == "js"){ return "js"; }
  if ($extn == "css"){ return "css"; }

  if ($extn == "gif"){ return "gif"; }
  if ($extn == "jpg"){ return "jpg"; }
  if ($extn == "jpeg"){ return "jpg"; }
  if ($extn == "png"){ return "png"; }
  if ($extn == "bmp"){ return "bmp"; }

  if ($extn == "cab"){ return "zip"; }
  if ($extn == "zip"){ return "zip"; }
  if ($extn == "ace"){ return "zip"; }
  if ($extn == "tgz"){ return "zip"; }
  if ($extn == "gz"){ return "zip"; }
  if ($extn == "tar"){ return "zip"; }
  if ($extn == "rar"){ return "zip"; }

  if ($extn == "wav"){ return "wav"; }
  if ($extn == "mid"){ return "mid"; }
  if ($extn == "mp3"){ return "mp3"; }

  if ($extn == "exe"){ return "exe"; }
  if ($extn == "bat"){ return "bat"; }
  if ($extn == "com"){ return "com"; }
  if ($extn == "pif"){ return "com"; }

  if ($extn == "mov"){ return "wav"; }
  if ($extn == "avi"){ return "wav"; }
  if ($extn == "mpg"){ return "wav"; }
  if ($extn == "mpeg"){ return "wav"; }
  if ($extn == "swf"){ return "swf"; }

  if ($extn == "txt"){ return "txt"; }
  if ($extn == "nfo"){ return "txt"; }
  return "inconnu";
}

function PathToImage($pathin) {
  $pathout = str_replace("img/",CHEMIN."img/",$pathin);
  $pathout = str_replace("inc/".CHEMIN."img/",CHEMIN."inc/img/",$pathout);
  return $pathout;
}

function SplitText($textin,$textlen) {
  $textout = array();
  $out1 = $textin;
  $out2 = "";
  if (strlen($textin) > $textlen) {
    $tempout = strrpos(substr($textin,0,$textlen)," ");
    if ($tempout < 1) {
      $tempout = strpos($textin," ");
    }
    if ($tempout > 0) {
      $out1 = substr($textin,0,$tempout);
      $out2 = substr($textin,$tempout+1,strlen($textin)-$tempout);
    }
  }
  $textout[0] = $out1;
  $textout[1] = $out2;
  return $textout;
}

function CutLongWord($textin,$textlen=50) {
  $textout = substr($textin,0,$textlen);
  return $textout;
}

function WrapLongWords($textin,$textlen=50,$textrep=" ") {
  $textout = wordwrap($textin,$textlen,$textrep,1);
  return $textout;
}

function FormatDateStamp($datein) {
  global $site;
  if ($site[19] == "E1") {
    $formatout = "d/m/Y";
  }
  elseif ($site[19] == "E2") {
    $formatout = "d.m.Y";
  }
  elseif ($site[19] == "U1") {
    $formatout = "m/d/Y";
  }
  elseif ($site[19] == "U2") {
    $formatout = "m.d.Y";
  }
  elseif ($site[19] == "C1") {
    $formatout = "Y/m/d";
  }
  else {  // $site[19] == "C2"
    $formatout = "Y.m.d";
  }
  $formatout .= " ".$site[23]." ";
  if ($site[22] == "H1") {
    $formatout .= "H:i";
  }
  elseif ($site[22] == "H2") {
    $formatout .= "H\hi";
  }
  else {  // $site[22] == "H3"
    $formatout .= "h:i A";
  }
  $dateout = date($formatout,$datein);
  return $dateout;
}

function FormatDate($datein) {
  global $site;
    $jour = substr($datein,6,2);
    $mois = substr($datein,4,2);
    $annee = substr($datein,0,4);
    $heure = substr($datein,8,2);
    $minute = substr($datein,10,2);
    if ($site[19] == "E1") {
      $dateout = $jour."/".$mois."/".$annee;
    }
    elseif ($site[19] == "E2") {
      $dateout = $jour.".".$mois.".".$annee;
    }
    elseif ($site[19] == "U1") {
      $dateout = $mois."/".$jour."/".$annee;
    }
    elseif ($site[19] == "U2") {
      $dateout = $mois.".".$jour.".".$annee;
    }
    elseif ($site[19] == "C1") {
      $dateout = $annee."/".$mois."/".$jour;
    }
    else {  // $site[19] == "C2"
      $dateout = $annee.".".$mois.".".$jour;
    }
    $dateout .= " ".$site[23]." ";
    if ($site[22] == "H1") {
      $dateout .= $heure.":".$minute;
    }
    elseif ($site[22] == "H2") {
      $dateout .= $heure."h".$minute;
    }
    else {  // $site[22] == "H3"
      if ($heure < 12) {
        $dateout .= $heure.":".$minute." AM";
      }
      else {
        $dateout .= ($heure-12).":".$minute." PM";
      }
    }
  return $dateout;
}

function GetCurrentDateTime() {
  $dateout = date("YmdHi");
  return $dateout;
}

function FileSizeInKb($fic) {
  $taille=@filesize($fic);
  if ($taille !== false) {
    $taille = round($taille/1024);
  }
  return $taille;
}

function FileDBExist($fic) {
  $filetest = is_file($fic);
  return $filetest;
}

function DestroyDBFile($fic) {
  @chmod($fic,0755);
  @chmod($fic,0777);
  @unlink($fic);
}

function ReadCounter($fic) {
  $DataDB = 0;
  if (FileDBExist($fic)) {
    $fhandle = fopen($fic, "r");
    $DataDB = trim(fgets($fhandle, filesize($fic)));
    fclose($fhandle);
  }
  return $DataDB;
}

function WriteCounter($fic,$DataDB) {
  $fhandle = fopen($fic, "w");
  fputs($fhandle, $DataDB."\n");
  fclose($fhandle);
}

function ReadFullDB($fic) {
  $DataDB = Array();
  if (FileDBExist($fic)) {
    $DataDB = implode("", file($fic));
  }
  return $DataDB;
}
      
function WriteFullDB($fic,$DataDB) {
  $fhandle = fopen($fic, "w");
  fputs($fhandle, $DataDB);
  fclose($fhandle);
}

function AppendFullDB($fic,$DataDB) {
  $fhandle = fopen($fic, "a");
  fputs($fhandle, $DataDB);
  fclose($fhandle);
}

function CountDBFields($fic) {
  $DataNB = 0;
  if (FileDBExist($fic)) {
    $DataDB = file($fic);
    $DataNB = count($DataDB);
  }
  return $DataNB;
}

function ReadDBFields($fic) {
  $DataDB = Array();
  if (FileDBExist($fic)) {
    $DataDB = file($fic);
    for ($i = 0; $i < count($DataDB); $i++) {
      $Fields[$i] = explode(CONNECTOR,trim($DataDB[$i]));
    }
  }
  return $Fields;
}

function WriteDBFields($fic,$Fields) {
  $fhandle = fopen($fic, "w");
  $DataDB = "";
  for ($i = 0; $i < count($Fields); $i++) {
    for ($j = 0 ; $j < (count($Fields[$i])-1); $j++) {
      $DataDB .= trim($Fields[$i][$j]).CONNECTOR;
    }
    $DataDB .= trim($Fields[$i][count($Fields[$i])-1])."\n";
  }
  fputs($fhandle, $DataDB);
  fclose($fhandle);
}

function AppendDBFields($fic,$Fields) {
  $fhandle = fopen($fic, "a");
  $DataDB = "";
  for ($i = 0 ; $i < (count($Fields)-1); $i++) {
    $DataDB .= trim($Fields[$i]).CONNECTOR;
  }
  $DataDB .= trim($Fields[count($Fields)-1])."\n";
  fputs($fhandle, $DataDB);
  fclose($fhandle);
}

function DeleteDBFieldById($fic, $id=0) {
  //Efface une ligne selon l'id et reconstruit le fichier
  $array = explode("\n", fread(fopen($fic, "r"), filesize($fic)));
  $delete = array_pop($array);
  unset($array[$id]);			
  $newarray = array_values($array);					
  $fhandle = fopen($fic,"w");
  for($i=0; $i< count($newarray); $i++){
    fwrite($fhandle,$newarray[$i]."\n");
  }
  fclose($fhandle);		
}

function CheckDB1Field($fic,$submit,$FieldNB) {
  $controle = False;
  if (FileDBExist($fic)) {
    $DataDB = ReadDBFields($fic);
    for ($i = 0; $i < count($DataDB); $i++) {
      if (@stristr($DataDB[$i][$FieldNB],$submit)) {
        $controle = True;
      }
    }
  }
  return $controle;
}

function CheckDB2Fields($fic,$submit1,$FieldNB1,$submit2,$FieldNB2) {
  $controle = False;
  if (FileDBExist($fic)) {
    $DataDB = ReadDBFields($fic);
    for ($i = 0; $i < count($DataDB); $i++) {
      if (@stristr($DataDB[$i][$FieldNB1],$submit1) && @stristr($DataDB[$i][$FieldNB2],$submit2)) {
        $controle = True;
      }
    }
  }
  return $controle;
}

function SelectDBFieldsByID($Fields,$id) {
  $DataDB = array();
  $k = 0;
  for ($i = 0; $i < count($Fields); $i++) {
    if ($Fields[$i][1] == $id) {
      for ($j = 0 ; $j < count($Fields[$i]); $j++) {
        $DataDB[$k][$j] = $Fields[$i][$j];
      }
      $k++;
    }
  }
  return $DataDB;
}

function SelectDBFieldsByType($Fields,$type) {
  $DataDB = array();
  $k = 0;
  for ($i = 0; $i < count($Fields); $i++) {
    if ($Fields[$i][0] == $type) {
      for ($j = 0 ; $j < count($Fields[$i]); $j++) {
        $DataDB[$k][$j] = $Fields[$i][$j];
      }
      $k++;
    }
  }
  return $DataDB;
}

function SelectDBFieldsByNotStatus($Fields,$status) {
  $DataDB = array();
  $k = 0;
  for ($i = 0; $i < count($Fields); $i++) {
    if ($Fields[$i][2] != $status) {
      for ($j = 0 ; $j < count($Fields[$i]); $j++) {
        $DataDB[$k][$j] = $Fields[$i][$j];
      }
    $k++;
    }
  }
  return $DataDB;
}

function SelectDBFieldsByStatus($Fields,$status) {
  $DataDB = array();
  $k = 0;
  for ($i = 0; $i < count($Fields); $i++) {
    if ($Fields[$i][2] == $status) {
      for ($j = 0 ; $j < count($Fields[$i]); $j++) {
        $DataDB[$k][$j] = $Fields[$i][$j];
      }
      $k++;
    }
  }
  return $DataDB;
}

function SelectDBFields($type,$status,$id) {
  $DataDB = array();
  if (!empty($status) && !empty($id)) {
    $DataDB = SelectDBFieldsByID(SelectDBFieldsByStatus(SelectDBFieldsByType(ReadDBFields(DOCID),$type),$status),$id);
  }
  elseif (!empty($status)) {
    $DataDB = SelectDBFieldsByStatus(SelectDBFieldsByType(ReadDBFields(DOCID),$type),$status);
  }
  elseif (!empty($id)) {
    $DataDB = SelectDBFieldsByID(SelectDBFieldsByType(ReadDBFields(DOCID),$type),$id);
  }
  else {
    $DataDB = SelectDBFieldsByType(ReadDBFields(DOCID),$type);
  }
  return $DataDB;
}

function RemoveQuote($chaine) {
  $traite = str_replace("'", "", $chaine);
  return $traite;
}

function RemoveConnector($chaine) {
  $traite = str_replace(CONNECTOR, "", $chaine);
  return $traite;
}

function RemoveBR($chaine) {
  $traite = str_replace("<br />", "\n", $chaine);
  $traite = str_replace("<br />", "\n", $traite);
  $traite = str_replace("<br />", "\n", $traite);
  $traite = str_replace("<br />", "\n", $traite);
  return $traite;
}
    
function PutBR($chaine) {
  $traite = str_replace(chr(10),"<br />",$chaine);
  $traite = str_replace(chr(13),"",$traite);
  return $traite;
}

function RemoveHR($chaine) {
  $traite = str_replace("</p><hr /><p>", "<hr />", $chaine);
  return $traite;
}

function PutHR($chaine) {
  $traite = str_replace("<hr />", "</p><hr /><p>", $chaine);
  $traite = str_replace("<hr />", "</p><hr /><p>", $traite);
  $traite = str_replace("<hr />", "</p><hr /><p>", $traite);
  $traite = str_replace("<hr />", "</p><hr /><p>", $traite);
  $traite = str_replace("$","$&shy;",$traite);
  return $traite;
}

function ReadDocCounter($dirid) {
  $DataDB = ReadCounter($dirid.DBEXT);
  return $DataDB;
}

function WriteDocCounter($dirid,$DataDB) {
  WriteCounter($dirid.DBEXT,$DataDB);
}

function UpdateDocCounter($id) {
  $DataDB = ReadDocCounter(DBBASE.$id);
  $vote = DejaVote(DBIPBASE.$id.DBEXT,300);
  if ($vote[0] == false) {
    $DataDB++;
    WriteDocCounter(DBBASE.$id,$DataDB);
  }
  return $DataDB;
}


function ReadDoc($dirid) {
  global $type,$fileid,$status,$creadate,$moddate,$author,$email,
         $fielda1,$fielda2,$fieldb1,$fieldb2,$fieldc1,$fieldc2,$fieldd1,$fieldd2;
  if (FileDBExist($dirid.INCEXT)) {
    include($dirid.INCEXT);
  }
}

function WriteDoc() {
  global $type,$fileid,$status,$creadate,$moddate,$author,$email,
         $fielda1,$fielda2,$fieldb1,$fieldb2,$fieldc1,$fieldc2,$fieldd1,$fieldd2;
  $rec = "<?php
\$type = \"$type\";
\$fileid = \"$fileid\";
\$status = \"$status\";
\$creadate = \"$creadate\";
\$moddate = \"$moddate\";
\$author = stripslashes(\"$author\");
\$email = stripslashes(\"$email\");
\$fielda1 = stripslashes(\"$fielda1\");
\$fielda2 = stripslashes(\"$fielda2\");
\$fieldb1 = stripslashes(\"$fieldb1\");
\$fieldb2 = stripslashes(\"$fieldb2\");
\$fieldc1 = stripslashes(\"$fieldc1\");
\$fieldc2 = stripslashes(\"$fieldc2\");
\$fieldd1 = stripslashes(\"$fieldd1\");
\$fieldd2 = stripslashes(\"$fieldd2\");
?>"; ?> <?php
  WriteFullDB(DBBASE.$fileid.INCEXT,$rec);
}

function UpdateDBdtb($dtb) {
  global $type,$fileid,$status,$creadate,$moddate,$author,$email,
         $fielda1,$fielda2,$fieldb1,$fieldb2,$fieldc1,$fieldc2,$fieldd1,$fieldd2;
  $db = SelectDBFields($dtb,"a","");
  $dba = array();
  $j = 0;
  for ($i = 0; $i < count($db); $i++) {
    ReadDoc(DBBASE.$db[$i][1]);
    if (!($dtb == TYP_ART && trim($fielda1).trim($fielda2) == "")) {
      $dba[$j][0] = RemoveConnector($fielda1);
      $dba[$j][1] = RemoveConnector($fielda2);
      $dba[$j][2] = RemoveConnector($fieldb1);
      $dba[$j][3] = RemoveConnector($fieldb2);
      $dba[$j][4] = $fileid;
      if ($dtb == TYP_ART) {
        $dba[$j][5] = RemoveConnector($fieldd1);
      }
      $j++;
    }
  }
  WriteDBFields(CHEMIN.DATAREP.$dtb.DBEXT,$dba);
}

function UpdateDBreact($action,$id) {
  global $type,$fileid,$status,$creadate,$moddate,$author,$email,
         $fielda1,$fielda2,$fieldb1,$fieldb2,$fieldc1,$fieldc2,$fieldd1,$fieldd2;
  $db = array();
  if ($action == "add") {
    ReadDoc(DBBASE.$id);
    $db[0] = $fileid;
    $db[1] = $fielda2;
    AppendDBFields(DBREACT,$db);
  }
  else {
    $db = SelectDBFields(TYP_REACT,"a","");
    sort($db);
    $dbf = array();
    for ($i = 0; $i < count($db); $i++) {
      ReadDoc(DBBASE.$db[$i][1]);
      $dbf[$i][0] = $fileid;
      $dbf[$i][1] = $fielda2;
    }
    WriteDBFields(DBREACT,$dbf);
  }
}

function UpdateDBforum($action,$id) {
  global $site,$type,$fileid,$status,$creadate,$moddate,$author,$email,
         $fielda1,$fielda2,$fieldb1,$fieldb2,$fieldc1,$fieldc2,$fieldd1,$fieldd2;
  $db = array();
  if ($action == "add") {
    ReadDoc(DBBASE.$id);
    $db[0] = $creadate;                               // date @ heure du thread
    $db[1] = $fielda1;                                // numéro de thread
    $db[2] = $fielda2;                                // numéro de réponse ou "0" si nouveau thread
    $db[3] = $fileid;                                 // id du thread
    $db[4] = RemoveConnector($author);                // auteur
    $db[5] = RemoveConnector($email);                 // e-mail auteur
    $db[6] = RemoveConnector($fieldb1);               // titre
    $db[7] = $fieldd1;                                // show or hide e-mail auteur
    $db[8] = $fieldb2;                                // ID catégorie thread
    AppendDBFields(DBTHREAD,$db);
  }
  else {
    $db = SelectDBFields(TYP_FORUM,"a","");
    sort($db);
    $dbf = array();
    for ($i = 0; $i < count($db); $i++) {
      ReadDoc(DBBASE.$db[$i][1]);
      $dbf[$i][0] = $creadate;                        // date @ heure du thread
      $dbf[$i][1] = $fielda1;                         // numéro de thread
      $dbf[$i][2] = $fielda2;                         // numéro de réponse ou "0" si nouveau thread
      $dbf[$i][3] = $fileid;                          // id du thread
      $dbf[$i][4] = RemoveConnector($author);         // auteur
      $dbf[$i][5] = RemoveConnector($email);          // e-mail auteur
      $dbf[$i][6] = RemoveConnector($fieldb1);        // titre
      $dbf[$i][7] = $fieldd1;                         // show or hide e-mail auteur
      $dbf[$i][8] = $fieldb2;                         // ID catégorie thread
    }
    @sort($dbf,SORT_REGULAR);
    WriteDBFields(DBTHREAD,$dbf);
  }
  $db = array();
  $db = ReadDBFields(DBTHREAD);
  $dbf = array();
  $j = 0;
  for ($i = 0; $i < count($db); $i++) {
    if ($db[$i][2] == "0") {
      $dbf[$j][0] = $db[$i][0];            // date @ heure de la dernière réponse
      $dbf[$j][1] = $db[$i][1];            // numéro de thread
      $dbf[$j][2] = $db[$i][3];            // id de début du thread
      $dbf[$j][3] = $db[$i][4];            // auteur
      $dbf[$j][4] = $db[$i][5];            // e-mail auteur
      $dbf[$j][5] = $db[$i][6];            // titre
      $dbf[$j][6] = $db[$i][0];            // date @ heure de création du thread
      $dbf[$j][7] = 0;                     // nombre de réponses
      $dbf[$j][8] = "";                    // auteur de la dernière réponse
      $dbf[$j][9] = "";                    // e-mail auteur de la dernière réponse
      $dbf[$j][10] = $db[$i][7];           // show or hide e-mail auteur
      $dbf[$j][11] = "";                   // show or hide e-mail auteur de la dernière réponse
      $dbf[$j][12] = $db[$i][8];           // ID catégorie thread
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
  WriteDBFields(DBFORUM,$dbf);
}
function ActionOnFields($action,$data) {
  global $site,$type,$fileid,$status,$creadate,$moddate,$author,$email,
         $fielda1,$fielda2,$fieldb1,$fieldb2,$fieldc1,$fieldc2,$fieldd1,$fieldd2;
  if ($action == "del") {
    $id = $data[1];
    $db = ReadDBFields(DOCID);
    for ($i = 0; $i < count($db); $i++) {
      if ($db[$i][1] == $id) {
        $db[$i][2] = "d";
      }
    }
    WriteDBFields(DOCID,$db);
    ReadDoc(DBBASE.$id);
    $status = "d";
    $author = addslashes($author);
    $email = addslashes($email);
    $fielda1 = addslashes($fielda1);
    $fielda2 = addslashes($fielda2);
    $fieldb1 = addslashes($fieldb1);
    $fieldb2 = addslashes($fieldb2);
    $fieldc1 = addslashes($fieldc1);
    $fieldc2 = addslashes($fieldc2);
    $fieldd1 = addslashes($fieldd1);
    $fieldd2 = addslashes($fieldd2);
    WriteDoc();
  }
  elseif ($action == "act") {
    $id = $data[1];
    $db = ReadDBFields(DOCID);
    for ($i = 0; $i < count($db); $i++) {
      if ($db[$i][1] == $id) {
        $db[$i][2] = $data[2];
      }
    }
    WriteDBFields(DOCID,$db);
    ReadDoc(DBBASE.$id);
    $status = $data[2];
    $author = addslashes($author);
    $email = addslashes($email);
    $fielda1 = addslashes($fielda1);
    $fielda2 = addslashes($fielda2);
    $fieldb1 = addslashes($fieldb1);
    $fieldb2 = addslashes($fieldb2);
    $fieldc1 = addslashes($fieldc1);
    $fieldc2 = addslashes($fieldc2);
    $fieldd1 = addslashes($fieldd1);
    $fieldd2 = addslashes($fieldd2);
    WriteDoc();
  }
  elseif ($action == "add") {
	$id = ReadCounter(NEXTID);
	$id = $id+1;
	WriteCounter(NEXTID,$id);
	$db = array();
	$db[0] = $data[0];
    $db[1] = $id;
    $db[2] = $data[2];
	AppendDBFields(DOCID,$db);
    $type = $data[0];
    $fileid = $id;
    $status = $data[2];
    $creadate = GetCurrentDateTime();
    $moddate = $creadate;
    $author = addslashes(stripslashes($data[5]));
    $email = addslashes(stripslashes($data[6]));
    $fielda1 = addslashes(stripslashes($data[7]));
    $fielda2 = addslashes(stripslashes($data[8]));
    $fieldb1 = addslashes(stripslashes($data[9]));       
    $fieldb2 = addslashes(stripslashes($data[10]));
    if ($data[0] == TYP_NWL){
      $fieldc1 = addslashes(stripslashes(replaceimg(PutHR(PutBR($data[11])))));
      $fieldc2 = addslashes(stripslashes(replaceimg(PutHR(PutBR($data[12])))));
    }
    else{
      $fieldc1 = addslashes(stripslashes(souriez(PutHR(PutBR($data[11])))));
      $fieldc2 = addslashes(stripslashes(souriez(PutHR(PutBR($data[12])))));
    }
    $fieldd1 = addslashes(stripslashes($data[13]));
    $fieldd2 = addslashes(stripslashes($data[14]));
    WriteDoc();
  }
  elseif ($action == "mod") {
    $id = $data[1];
    ReadDoc(DBBASE.$id);
    $moddate = GetCurrentDateTime();
    $author = addslashes(stripslashes($data[5]));
    $email = addslashes(stripslashes($data[6]));
    $fielda1 = addslashes(stripslashes($data[7]));
    $fielda2 = addslashes(stripslashes($data[8]));
    $fieldb1 = addslashes(stripslashes($data[9]));
    $fieldb2 = addslashes(stripslashes($data[10]));
    if ($data[0] == TYP_NWL){
      $fieldc1 = addslashes(stripslashes(replaceimg(PutHR(PutBR($data[11])))));
      $fieldc2 = addslashes(stripslashes(replaceimg(PutHR(PutBR($data[12])))));
    }
    else{
      $fieldc1 = addslashes(stripslashes(souriez(PutHR(PutBR($data[11])))));
      $fieldc2 = addslashes(stripslashes(souriez(PutHR(PutBR($data[12])))));
	}
    $fieldd1 = addslashes(stripslashes($data[13]));
    $fieldd2 = addslashes(stripslashes($data[14]));
    WriteDoc();
  }
  if ($data[0] == TYP_ART || $data[0] == TYP_LINKS || $data[0] == TYP_DNLOAD || $data[0] == TYP_PHOTO || $data[0] == TYP_FAQ || $data[0] == TYP_RSS) {
    UpdateDBdtb($data[0]);
  }
  elseif ($data[0] == TYP_FORUM) {
    UpdateDBforum($action,$id);
  }
  elseif ($data[0] == TYP_NEWS) {
    include(CHEMIN.INCREP."funcrss.php");
    UpdateDBnews();
  }
  elseif ($data[0] == TYP_REACT) {
    UpdateDBreact($action,$id);
  }
}

function InitDBlog($typ) {
  $db = array();
  $db[0][0] = 0;
  for ($i = 0; $i < 12; $i++) {$db[1][$i] = 0;}
  for ($i = 0; $i < 2; $i++) {$db[2][$i] = 0;}
  for ($i = 0; $i < 9; $i++) {$db[3][$i] = 0;}
  for ($i = 0; $i < 10; $i++) {$db[4][$i] = 0;}
  for ($i = 0; $i < $typ; $i++) {$db[5][$i] = 0;}
  for ($i = 0; $i < $typ; $i++) {$db[6][$i] = 0;}
  $db[7][0] = 1;
  return $db;
}

function eMailTo($eSubject,$eMessage,$eTo) {
  global $supervision,$user;
  $eFrom = trim($user[1]);
  if ($eTo == "") {
    $eTo = trim($user[1]);
  }
  if ($supervision[5] == "standard") {
    @mail($eTo,$eSubject,$eMessage);
  }
  else {
    include (CHEMIN.INCREP."mail/".$supervision[5].INCEXT);
  }
}

function BreakEMail($eminput) {
  $eminput = trim($eminput);
  $em1 = strpos($eminput,"@");
  $em2 = strrpos($eminput,".");
  $emoutput[0] = substr($eminput,0,$em1);
  $emoutput[1] = substr($eminput,$em1+1,$em2-$em1-1);
  $emoutput[2] = substr($eminput,$em2+1);
  return $emoutput;
}

function StartTimer() {
 global $starttime;
 $mtime = microtime();
 $mtime = explode(' ', $mtime);
 $mtime = $mtime[1] + $mtime[0];
 $starttime = $mtime;
}

function StopTimer() {
  global $starttime;
  $mtime = microtime();
  $mtime = explode(' ', $mtime);
  $mtime = $mtime[1] + $mtime[0];
  $stoptime = round (($mtime - $starttime), 2);
  return $stoptime;
}

function MakeSeed() {
  list($usec, $sec) = explode(' ', microtime());
  return (float) $sec + ((float) $usec * 100000);
}

function GenerateUID() {
  srand(MakeSeed());
  $gene = rand(1,9);
  for ($i = 0; $i <9; $i++) {
    $gene .= rand(0,9);
  }
  return $gene;
}

function KeepGoodChars($textin) {
  $textout = preg_replace("![^a-zA-Z0-9_]!i","",$textin);
  return $textout;
}
?>
