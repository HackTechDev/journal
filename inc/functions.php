<?php
/*
    Functions - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

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
      v4.0 (06 December 2004)  : added new function Drawsmileys2() for new wywiwyg editors (by Icare)
  	                             added new items and updated  write and read functions for planner management (by Nicolas Alves)
        				                 added new items and updated  write and read functions for mails forum management (by Nicolas Alves)
        				                 added name of smiley in souriez (by Icare)
        				                 corrected PathToImage() (by Icare)
        				                 added mail $eFrom (webmaster e-mail) in eMailTo function to prevent ineffective mail
    	 	                         and added Content-Type to prevent excessive xmailer tags in the message (by Icare)
     v4.5 (07 June 2005)       : corrected function readDoc(),
                                 conversion of "constant" variables in constants PHP,
                                 added IsFlash(), compare_XXX(), MakeRadioGroup() and GetNavBar() (by Jean-Mi)
                                 updated eMailTo, added optimized eMailHtmlTo (by JeanMi and Icare)
     v4.6.0 (04 June 2007)      : updated ReadDoc(), WriteDoc(), UpdateDBforum() and ActionOnField for forum management (by Icare)
                                 added accents replacement in KeepGoodChars() function (by Icare)
                                 added incrnextNextid() (by JeanMi)
                                 new PathToImage() calling new PathAbs() (by Djchouix)
                                 added AsciiCompare() function (by Icare)
     v4.6.1 (18 June 2004)      : corrected PathAbs (by jchouix)
     v4.6.3 (30 August 2007)    : corrected function ActionOnFields (by Icare)
     v4.6.6 (14 April 2008)     : added new field for TYP_BLOG in function updateDBdtb (by Icare)
                                  corrected putHR() (by jchouix), corrected putBR() (by Icare)
     v4.6.8 (24 May 2008)       : added action to function PathToImage() (by jchouix)
     v4.6.9 (25 December 2008)  : move of the function ShowBlock to functions.php #221
                                  move of the function SearchOption to functions.php #219
                                  correction of function ShowBlock #230
                                  correction of function InitDbLog #216
     v4.6.9d (28 December 2008) : corrected
     v4.6.10 (7 September 2009) : corrected #266, #253, #272 et #274
     v4.6.11 (xx november 2009) : corrected #297 in ForceToAbsolute_callback() #301 selectDBFieldsBy...
     v4.6.12 (01 May 2010)       :  #317 added display stats of previous month (by Icare)
     v4.6.14(14 February 2011)   :  added checkUserWebsiteUrl (thanks jchouix)
     v4.6.15 (30 June 2011)      :  added private group namagement (by Icare)
	                                corrected function putHR #340 (thanks jchouix)
				                    corrected function checkUserWebsiteUrl (thanks jchouix)
     v4.6.16 (02 September 2011) :  corrected creative directory temp (thanks Hpsam)				  
	 v4.6.19 (30 March 2012)     :  add social networks by Saxbar
	                                corrected function WriteDoc() (thanks jchouix)
     v4.6.21a(23 October 2012)   :  corrected control input email, url	(thanks jchouix, Saxbar)
     v4.6.22 (29 December 2012)  :  changed include funcrss by include_once in ActionOnFields()	(thanks Icare)								
*/

if (stristr($_SERVER["SCRIPT_NAME"], "functions.php")) {
  header("location:../index.php");
  die();
}

define("CONNECTOR", "||");
define("TYP_ART", "ar");
define("TYP_BANNER", "ba");
define("TYP_BLOG", "bl");
define("TYP_DNLOAD", "dn");
define("TYP_DISCLAIM", "di");
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
define("TYP_MAIL", "ma");
define("TYP_NEWS", "ne");
define("TYP_NWL", "nl");
define("TYP_PHOTO", "ph");
define("TYP_REACT", "ra");
define("TYP_REBLOG", "rb");
define("TYP_RULES", "ru");
define("TYP_RECO", "re");
define("TYP_RSS", "rs");
define("TYP_BSS", "bs");
define("TYP_SPECIAL", "sp");
define("TYP_THINK", "ci");
define("TYP_AGENDA", "ag");
define('TYP_SOCNET', 'sn');
define("DATAREP", "data/");
define("ARCHREP", CHEMIN.DATAREP."archive/");
define("CACHEREP", CHEMIN.DATAREP."cache/");
define("USEREP", CHEMIN.DATAREP."usermsg/");
define("TEMPREP", CHEMIN.DATAREP."temp/");
define("FILECOUNTMSG", CHEMIN.DATAREP."countmsg/");
define("REDACREP", "redac/");
define("INCREP", "inc/");
define("DBEXT", ".dtb");
define("INCEXT", ".inc");
define("DBBASE", CHEMIN.DATAREP."doc");
define("DBIPBASE", CHEMIN.DATAREP."ipdoc");
define("DBPLUGIN", CHEMIN.DATAREP."plugin".DBEXT);
define("CONFIG", CHEMIN.DATAREP."config".INCEXT);
define("NEXTID", CHEMIN.DATAREP."nextid".DBEXT);
define("NEXTIDBK", CHEMIN.DATAREP."nextidbk".DBEXT);
define("DOCID", CHEMIN.DATAREP."docid".DBEXT);
define("DBNEWSLETTER", CHEMIN.DATAREP."nwlist".DBEXT);
define("DBNEWS", CHEMIN.DATAREP."news");
define("DBLOGBOOK", CHEMIN.DATAREP."logbook".DBEXT);
define("DBAGENDA", CHEMIN.DATAREP.TYP_AGENDA.DBEXT);
define("DBART", CHEMIN.DATAREP.TYP_ART.DBEXT);
define("DBBLOG", CHEMIN.DATAREP.TYP_BLOG.DBEXT);
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
define("DBREBLOG", CHEMIN.DATAREP.TYP_REBLOG.DBEXT);
define("DBRSS", CHEMIN.DATAREP.TYP_RSS.DBEXT);
define("DBBSS", CHEMIN.DATAREP.TYP_BSS.DBEXT);
define("DBCOUNTER", CHEMIN.DATAREP."counter".DBEXT);
define("DBSTATS", CHEMIN.DATAREP."stats".DBEXT);
define("DBSTATSBK", CHEMIN.DATAREP."statsbk".DBEXT);
define("DBIPSTATS", CHEMIN.DATAREP."ipstats".DBEXT);
define("DBLOGH", CHEMIN.DATAREP."logh".DBEXT);
define("DBLOGD", CHEMIN.DATAREP."logd".DBEXT);
define("DBLOGM", CHEMIN.DATAREP."logm".DBEXT);
define("DBLOGL", CHEMIN.DATAREP."logl".DBEXT);
define("DBLOGY", CHEMIN.DATAREP."logy".DBEXT);
define("DBLOGP", CHEMIN.DATAREP."logp".DBEXT);
define("DBLOGDATE", CHEMIN.DATAREP."log_date".DBEXT);
define("DBLOGFILES", CHEMIN.DATAREP."log_files".DBEXT);
define("DBLOGSTATS", CHEMIN.DATAREP."log_stats".DBEXT);
define("DBDISCLAIM", CHEMIN.DATAREP.TYP_DISCLAIM.INCEXT);
define("DBHOMEPAGE", CHEMIN.DATAREP.TYP_HOMEPG.INCEXT);
define("DBFOOT", CHEMIN.DATAREP.TYP_FOOTER.INCEXT);
define("DBRULES", CHEMIN.DATAREP.TYP_RULES.INCEXT);
define("DBSPECIAL", CHEMIN.DATAREP.TYP_SPECIAL.INCEXT);
define("DBFREEBOX1", CHEMIN.DATAREP.TYP_FREEBOX1.INCEXT);
define("DBFREEBOX2", CHEMIN.DATAREP.TYP_FREEBOX2.INCEXT);
define("DBFREEBOX3", CHEMIN.DATAREP.TYP_FREEBOX3.INCEXT);
define("DBFREEBOX4", CHEMIN.DATAREP.TYP_FREEBOX4.INCEXT);
define('DBSOCNET', CHEMIN.DATAREP.TYP_SOCNET.DBEXT);
define("DBADMIN", CHEMIN.DATAREP."admins".DBEXT);
define("DBANTISPAM", CHEMIN.DATAREP."antispam".DBEXT);
define("HIT_TIME", 1800);
define('ANTISPAM_COUNT', 100);
define('ANTISPAM_DELAY', 30);

/* optionnal variables init for skins*/
$meskin = "";
$screen_choice = ""; $screen_icon = ""; $skn_logo = ""; $skn_hr = "";$skn_top = "";$headinc = "";
// For buttons customization
$boutonleft = "";  $boutonright = ""; $boutoncenter = "";
// for optionnal boxes
$imgtabup = "";  $tabup = ""; $tabcita = ""; $tabmenu = ""; $boxban = ""; $endban = ""; $tabfoot = ""; $tabdown = ""; $imgtabdown = "";

$show_progbar = false;

$couleurs = array("bleu", "jaune", "marron", "or", "orange", "outremer", "rose", "rouge", "vert", "violet");
$souriez = array(
	         array("|:-)", "inc/img/smileys/cool.gif", "cool"),
	         array(";-)", "inc/img/smileys/wink.gif", "wink"),
	         array(":-))", "inc/img/smileys/biggrin.gif", "biggrin"),
	         array(":-)", "inc/img/smileys/smile.gif", "smile"),
	         array(":-o", "inc/img/smileys/frown.gif", "frown"),
           array(":o)", "inc/img/smileys/eek.gif", "eek"),
	         array(":-((", "inc/img/smileys/mad.gif", "mad"),
	         array(":-(", "inc/img/smileys/confused.gif", "confused"),
	         array("8-)", "inc/img/smileys/rolleyes.gif", "rolleyes"),
	         array(":-p", "inc/img/smileys/tongue.gif", "tongue"),
	         array(";-(", "inc/img/smileys/cry.gif", "cry")
		);

function souriez($chaine) {
  global $souriez;
$traite = str_replace($souriez[0][0], "<img src=\\\"".$souriez[0][1]."\\\" border=\\\"0\\\" title=\"cool\" alt=\"cool\" />", $chaine);
$traite = str_replace($souriez[1][0], "<img src=\\\"".$souriez[1][1]."\\\" border=\\\"0\\\" title=\"wink\" alt=\"wink\" />", $traite);
$traite = str_replace($souriez[2][0], "<img src=\\\"".$souriez[2][1]."\\\" border=\\\"0\\\" title=\"biggrin\" alt=\"biggrin\" />", $traite);
$traite = str_replace($souriez[3][0], "<img src=\\\"".$souriez[3][1]."\\\" border=\\\"0\\\" title=\"smile\" alt=\"smile\" />", $traite);
$traite = str_replace($souriez[4][0], "<img src=\\\"".$souriez[4][1]."\\\" border=\\\"0\\\" title=\"frown\" alt=\"frown\" />", $traite);
$traite = str_replace($souriez[5][0], "<img src=\\\"".$souriez[5][1]."\\\" border=\\\"0\\\" title=\"eek\" alt=\"eek\" />", $traite);
$traite = str_replace($souriez[6][0], "<img src=\\\"".$souriez[6][1]."\\\" border=\\\"0\\\" title=\"mad\" alt=\"mad\" />", $traite);
$traite = str_replace($souriez[7][0], "<img src=\\\"".$souriez[7][1]."\\\" border=\\\"0\\\" title=\"confused\" alt=\"confused\" />", $traite);
$traite = str_replace($souriez[8][0], "<img src=\\\"".$souriez[8][1]."\\\" border=\\\"0\\\" title=\"rolleyes\" alt=\"rolleyes\" />", $traite);
$traite = str_replace($souriez[9][0], "<img src=\\\"".$souriez[9][1]."\\\" border=\\\"0\\\" title=\"tongue\" alt=\"tongue\" />", $traite);
$traite = str_replace($souriez[10][0], "<img src=\\\"".$souriez[10][1]."\\\" border=\\\"0\\\" title=\"cry\" alt=\"cry\" />", $traite);
return $traite;
}

function replaceimg($chaine) {
  global $souriez,$site;
  $traite = str_replace($souriez[0][0],"<img src=".$site[3].$souriez[0][1]." border=\"0\" title=\"cool\" alt=\"cool\" />", $chaine);
  $traite = str_replace($souriez[1][0],"<img src=".$site[3].$souriez[1][1]." border=\"0\" title=\"wink\" alt=\"wink\" />", $traite);
  $traite = str_replace($souriez[2][0],"<img src=".$site[3].$souriez[2][1]." border=\"0\" title=\"biggrin\" alt=\"biggrin\" />", $traite);
  $traite = str_replace($souriez[3][0],"<img src=".$site[3].$souriez[3][1]." border=\"0\" title=\"smile\" alt=\"smile\" />", $traite);
  $traite = str_replace($souriez[4][0],"<img src=".$site[3].$souriez[4][1]." border=\"0\" title=\"frown\" alt=\"frown\" />", $traite);
  $traite = str_replace($souriez[5][0],"<img src=".$site[3].$souriez[5][1]." border=\"0\" title=\"eek\" alt=\"eek\" />", $traite);
  $traite = str_replace($souriez[6][0],"<img src=".$site[3].$souriez[6][1]." border=\"0\" title=\"mad\" alt=\"mad\" />", $traite);
  $traite = str_replace($souriez[7][0],"<img src=".$site[3].$souriez[7][1]." border=\"0\" title=\"confused\" alt=\"confused\" />", $traite);
  $traite = str_replace($souriez[8][0],"<img src=".$site[3].$souriez[8][1]." border=\"0\" title=\"rolleyes\" alt=\"rolleyes\" />", $traite);
  $traite = str_replace($souriez[9][0],"<img src=".$site[3].$souriez[9][1]." border=\"0\" title=\"tongue\" alt=\"tongue\" />", $traite);
  $traite = str_replace($souriez[10][0],"<img src=".$site[3].$souriez[10][1]." border=\"0\" title=\"cry\" alt=\"cry\" />", $traite);
  return $traite;
}

function DrawSmileys($num) {
  global $souriez;
  for ($i = 0; $i < count($souriez); $i++) {
    echo "<a href=\"JavaScript:AddSmiley".$num."('".$souriez[$i][0]."')\""."><img src=\"".CHEMIN.$souriez[$i][1]."\" class=\"clsCursor\" border=\"0\" title=\"".$souriez[$i][0]."\" alt=\"".$souriez[$i][0]."\" /></a>&nbsp;";
  }
}

function DrawSmileys2() {
  global $souriez;
  echo "&nbsp;";
  for ($i = 0; $i < count($souriez); $i++) {
    echo "&nbsp;<img src=\"".CHEMIN.$souriez[$i][1]."\" alt=\"".$souriez[$i][2]."\" title=\"".$souriez[$i][2]."\" />";
  }
}

function AfficheCompteur($chemino, $hits, $grow = 1) {
  $spot = "";
  for ($lecon = 0; $lecon < $grow - strlen($hits); $lecon++ ) {
    $spot .= "<img src=\"".$chemino."cnt0.gif\" alt=\"\"border=\"0\" />";
  }
  for ($lecon = 0; $lecon < strlen($hits); $lecon++) {
    $cols = substr($hits, $lecon, 1);
    $spot .= "<img src=\"".$chemino."cnt".$cols.".gif\" alt=\"\" border=\"0\" />";
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
  if (!$subdata[0] && ($nbr_visit > 0)) {
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

function IsFlash($extn) {
  $imgok = 0;
  $extn = strtolower($extn);
  if ($extn == "swf") {
    $imgok = 1;
  }
  return $imgok;
}

function ExtImage($extn){
    switch(strtolower($extn)) {
    case 'bat'  : return 'bat';
    case 'bmp'  : return 'bmp';
    case 'com'  : return 'com';
    case 'css'  : return 'css';
    case 'doc'  : return 'doc';
    case 'exe'  : return 'exe';
    case 'gif'  : return 'gif';
    case 'js'   : return 'js';
    case 'mid'  : return 'mid';
    case 'mp3'  : return 'mp3';
    case 'pdf'  : return 'pdf';
    case 'ppt'  : return 'ppt';
    case 'png'  : return 'png';
    case 'swf'  : return 'swf';
    case 'xls'  : return 'xls';

    case 'com'  :
    case 'pif'  : return 'com';

    case 'htm'  :
    case 'html' : return 'html';
    
    case 'jpeg' :
    case 'jpg'  : return 'jpg';
    
    case 'odf'  : // OpenOffice
    case 'odg'  :
    case 'odm'  :
    case 'odp'  :
    case 'ods'  :
    case 'odt'  : return 'ooo';

    case 'inc'  :
    case 'php'  :
    case 'php3' :
    case 'php4' :
    case 'php5' :
    case 'phtml' : return 'php';

    case 'dtb'  :
    case 'ini'  :
    case 'nfo'  :
    case 'txt'  : return 'txt';

    case 'avi'  :
    case 'mpeg' :
    case 'mpg'  :
    case 'mov'  :
    case 'wav'  : return 'wav';

    case 'ace'  :
    case 'cab'  :
    case 'gz'   :
    case 'rar'  :
    case 'tar'  :
    case 'tgz'  :
    case 'zip'  : return 'zip';
    
    default     : return 'inconnu';
    }
}

function PathAbs($matches) {
    if(!preg_match("`^(https?|ftp|mailto|javascript)\:`i", $matches[3])) {
        $matches[0] = $matches[1].$matches[2].CHEMIN.$matches[3];
    }
	return $matches[0];
}

function PathToImage($text) {
  return preg_replace_callback("`( href=| src=| action=)(\"|')?([^ >]+)`i", 'PathAbs', $text);
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
  else {
    $formatout = "Y.m.d";
  }
  $formatout .= " ".$site[23]." ";
  if ($site[22] == "H1") {
    $formatout .= "H:i";
  }
  elseif ($site[22] == "H2") {
    $formatout .= "H\hi";
  }
  else {
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
    else {
      $dateout = $annee.".".$mois.".".$jour;
    }
    $dateout .= " ".$site[23]." ";
    if ($site[22] == "H1") {
      $dateout .= $heure.":".$minute;
    }
    elseif ($site[22] == "H2") {
      $dateout .= $heure."h".$minute;
    }
    else {
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
	 if (filesize($fic)) {
	    $DataDB = trim(fgets($fhandle, filesize($fic)));
	 }
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
  $DataDB = array();
  $Fields = array();
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
    foreach ($Fields as $row) {
        if ($row[1] == $id) {
            $DataDB[] = $row;
        }
    }
    return $DataDB;
}

function SelectDBFieldsByType($Fields, $type) {
    $DataDB = array();
    foreach ($Fields as $row) {
        if ($row[0] == $type) {
            $DataDB[] = $row;
        }
    }
    return $DataDB;
}

function SelectDBFieldsByNotStatus($Fields, $status) {
    $DataDB = array();
    foreach ($Fields as $row) {
        if ($row[2] != $status) {
            $DataDB[] = $row;
        }
    }
    return $DataDB;
}

function SelectDBFieldsByStatus($Fields, $status) {
    $DataDB = array();
    foreach ($Fields as $row) {
        if ($row[2] == $status) {
            $DataDB[] = $row;
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
  $traite = preg_replace("!<br />!i", "\n", $chaine);
  return $traite;
}

function PutBR($chaine) {
  $traite = str_replace(chr(10),"\n",$chaine);
  $traite = str_replace(chr(13),"\r",$traite);
  return $traite;
}

function RemoveHR($chaine) {
  $traite = preg_replace("!</p><hr /><p>!i", "<hr />", $chaine);
  return $traite;
}

function PutHR($chaine) {
  $traite = $chaine;
  $traite = str_replace("$","&#36;",$traite);
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
         $fielda1,$fielda2,$fieldb1,$fieldb2,$fieldc1,$fieldc2,$fieldd1,$fieldd2,
         $fieldweb,$fieldmail,$fieldmod;
	$type = "";
	$fileid = "";
	$status = "";
	$creadate = "";
	$moddate = "";
	$author = "";
	$email = "";
	$fielda1 = "";
	$fielda2 = "";
	$fieldb1 = "";
	$fieldb2 = "";
	$fieldc1 = "";
	$fieldc2 = "";
	$fieldd1 = "";
	$fieldd2 = "";
	$fieldweb = "";
	$fieldmail = "";
	$fieldmod = "";
  if (FileDBExist($dirid.INCEXT)) {
    include($dirid.INCEXT);
  }
}

function WriteDoc() {
  global $type,$fileid,$status,$creadate,$moddate,$author,$email,
         $fielda1,$fielda2,$fieldb1,$fieldb2,$fieldc1,$fieldc2,$fieldd1,$fieldd2,
         $fieldweb,$fieldmail,$fieldmod;
  $rec = "<?php
\$type = '$type';
\$fileid = '$fileid';
\$status = '$status';
\$creadate = '$creadate';
\$moddate = '$moddate';
\$author = stripslashes('$author');
\$email = stripslashes('$email');
\$fielda1 = stripslashes('$fielda1');
\$fielda2 = stripslashes('$fielda2');
\$fieldb1 = stripslashes('$fieldb1');
\$fieldb2 = stripslashes('$fieldb2');
\$fieldc1 = stripslashes('$fieldc1');
\$fieldc2 = stripslashes('$fieldc2');
\$fieldd1 = stripslashes('$fieldd1');
\$fieldd2 = stripslashes('$fieldd2');
\$fieldweb = stripslashes('$fieldweb');
\$fieldmail = stripslashes('$fieldmail');
\$fieldmod = stripslashes('$fieldmod');
";
  WriteFullDB(DBBASE.$fileid.INCEXT,$rec);
}

function UpdateDBdtb($dtb) {
  global $type,$fileid,$status,$creadate,$moddate,$author,$email,
         $fielda1,$fielda2,$fieldb1,$fieldb2,$fieldc1,$fieldc2,$fieldd1,$fieldd2,$fieldweb,$fieldmail,$fieldmod;
  $db = SelectDBFields($dtb,"a","");
  $dba = array();
  $j = 0;
  for ($i = 0; $i < count($db); $i++) {
    ReadDoc(DBBASE.$db[$i][1]);
    if (!(($dtb == TYP_ART || $dtb == TYP_BLOG) && trim($fielda1).trim($fielda2) == "")) {
      $dba[$j][0] = RemoveConnector($fielda1);
      $dba[$j][1] = RemoveConnector($fielda2);
      $dba[$j][2] = RemoveConnector($fieldb1);
      $dba[$j][3] = RemoveConnector($fieldb2);
      $dba[$j][4] = $fileid;
      if ($dtb == TYP_ART) {
        $dba[$j][5] = RemoveConnector($fieldd1);
        $dba[$j][6] = $fieldmod; /// modif accès réservé
      }
      if ($dtb == TYP_BLOG || $dtb == TYP_SOCNET) {
        $dba[$j][5] = $creadate;
        $dba[$j][6] = $fieldmod; /// modif accès réservé
      }
       /// modif accès réservé
      if ($dtb == TYP_AGENDA || $dtb == TYP_FAQ || $dtb == TYP_PHOTO) {
        $dba[$j][5] = "";
        $dba[$j][6] = $fieldmod; /// modif accès réservé
      }
      $j++;
    }
  }
  WriteDBFields(CHEMIN.DATAREP.$dtb.DBEXT,$dba);
}

function UpdateDBreact($action,$id) {
  global $type,$fileid,$status,$creadate,$moddate,$author,$email,
         $fielda1,$fielda2,$fieldb1,$fieldb2,$fieldc1,$fieldc2,$fieldd1,$fieldd2,$fieldweb,$fieldmail;
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

function UpdateDBreblog($action,$id) {
  global $type,$fileid,$status,$creadate,$moddate,$author,$email,
         $fielda1,$fielda2,$fieldb1,$fieldb2,$fieldc1,$fieldc2,$fieldd1,$fieldd2,$fieldweb,$fieldmail;
  $db = array();
  if ($action == "add") {
    ReadDoc(DBBASE.$id);
    $db[0] = $fileid;
    $db[1] = $fielda2;
    AppendDBFields(DBREBLOG,$db);
  }
  else {
    $db = SelectDBFields(TYP_REBLOG,"a","");
    sort($db);
    $dbf = array();
    for ($i = 0; $i < count($db); $i++) {
      ReadDoc(DBBASE.$db[$i][1]);
      $dbf[$i][0] = $fileid;
      $dbf[$i][1] = $fielda2;
    }
    WriteDBFields(DBREBLOG,$dbf);
  }
}
function UpdateDBforum($action,$id) {
  global $site,$type,$fileid,$status,$creadate,$moddate,$author,$email,
         $fielda1,$fielda2,$fieldb1,$fieldb2,$fieldc1,$fieldc2,$fieldd1,$fieldd2,$fieldweb,$fieldmail;$fieldmod;
  $db = array();
  if ($action == "add") {
    ReadDoc(DBBASE.$id);
    $db[0] = $creadate;
    $db[1] = $fielda1;
    $db[2] = $fielda2;
    $db[3] = $fileid;
    $db[4] = RemoveConnector($author);
    $db[5] = RemoveConnector($email);
    $db[6] = RemoveConnector($fieldb1);
    $db[7] = $fieldd1;
    $db[8] = $fieldb2;
    $db[9] = $fieldmail;
    AppendDBFields(DBTHREAD,$db);
  }
  else {
    $db = SelectDBFields(TYP_FORUM,"a","");
    sort($db);
    $dbf = array();
    for ($i = 0; $i < count($db); $i++) {
      ReadDoc(DBBASE.$db[$i][1]);
      if ($db[$i][1] > date("YmdHi")) $dbf[$i][0] = $moddate; //thread on top
      else $dbf[$i][0] = $creadate;
      $dbf[$i][1] = $fielda1;
      $dbf[$i][2] = $fielda2;
      $dbf[$i][3] = $fileid;
      $dbf[$i][4] = RemoveConnector($author);
      $dbf[$i][5] = RemoveConnector($email);
      $dbf[$i][6] = RemoveConnector($fieldb1);
      $dbf[$i][7] = $fieldd1;
      $dbf[$i][8] = $fieldb2;
      $dbf[$i][9] = $fieldmail;
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
      $dbf[$j][0] = $db[$i][0];
      $dbf[$j][1] = $db[$i][1];
      $dbf[$j][2] = $db[$i][3];
      $dbf[$j][3] = $db[$i][4];
      $dbf[$j][4] = $db[$i][5];
      $dbf[$j][5] = $db[$i][6];
      if ($db[$i][3] == $fileid) $dbf[$j][6] = $creadate;
      else $dbf[$j][6] = $db[$i][0];
      $dbf[$j][7] = 0;
      $dbf[$j][8] = "";
      $dbf[$j][9] = "";
      $dbf[$j][10] = $db[$i][7];
      $dbf[$j][11] = "";
      $dbf[$j][12] = $db[$i][8];
      for ($k = $i+1; $k < count($db); $k++) {
        if ($db[$k][1] == $dbf[$j][1]) {
            if ($db[$k][0] > $dbf[$j][0]) { //garder date top
          $dbf[$j][0] = $db[$k][0];
          }
          else{
          $dbf[$j][0] = $dbf[$j][0];
          }
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
         $fielda1,$fielda2,$fieldb1,$fieldb2,$fieldc1,$fieldc2,$fieldd1,$fieldd2,
         $fieldweb,$fieldmail,$fieldmod;
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
    $fieldweb = addslashes($fieldweb);
    $fieldmail = addslashes($fieldmail);
    $fieldmod = addslashes($fieldmod);
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
    $fieldweb = addslashes($fieldweb);
    $fieldmail = addslashes($fieldmail);
    $fieldmod = addslashes($fieldmod);
    WriteDoc();
  }
  elseif ($action == "add") {
    $id = IncrNextID();
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
    if ($data[0] == TYP_NWL) {
      $fieldc1 = addslashes(stripslashes(replaceimg(PutHR(PutBR($data[11])))));
      $fieldc2 = addslashes(stripslashes(replaceimg(PutHR(PutBR($data[12])))));
    }
    else {
      $fieldc1 = addslashes(stripslashes(souriez(PutHR(PutBR($data[11])))));
      $fieldc2 = addslashes(stripslashes(souriez(PutHR(PutBR($data[12])))));
    }
    $fieldd1 = addslashes(stripslashes($data[13]));
    $fieldd2 = addslashes(stripslashes($data[14]));
    $fieldweb = addslashes(stripslashes($data[15]));
    $fieldmail=addslashes(stripslashes($data[16]));
    $fieldmod=addslashes(stripslashes($data[17]));
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
    if ($data[0] == TYP_NWL) {
      $fieldc1 = addslashes(stripslashes(replaceimg(PutHR(PutBR($data[11])))));
      $fieldc2 = addslashes(stripslashes(replaceimg(PutHR(PutBR($data[12])))));
    }
    else {
      $fieldc1 = addslashes(stripslashes(souriez(PutHR(PutBR($data[11])))));
      $fieldc2 = addslashes(stripslashes(souriez(PutHR(PutBR($data[12])))));
	}
    $fieldd1 = addslashes(stripslashes($data[13]));
    $fieldd2 = addslashes(stripslashes($data[14]));
    $fieldweb = addslashes(stripslashes($data[15]));
    $fieldmail=addslashes(stripslashes($data[16]));
    $fieldmod=addslashes(stripslashes($data[17]));
    WriteDoc();
  }
  if ($data[0] == TYP_LINKS || $data[0] == TYP_DNLOAD || $data[0] == TYP_PHOTO || $data[0] == TYP_FAQ || $data[0] == TYP_RSS || $data[0] == TYP_BSS || $data[0] == TYP_AGENDA || $data[0] == TYP_SOCNET) {
    UpdateDBdtb($data[0]);
  }
  elseif ($data[0] == TYP_ART) {
    UpdateDBdtb($data[0]);
    include_once(CHEMIN.INCREP."funcrss.php");
    UpdateDBart();
  }
  elseif ($data[0] == TYP_BLOG) {
    UpdateDBdtb($data[0]);
    include_once(CHEMIN.INCREP."funcrss.php");
    UpdateDBblog();
  }
  elseif ($data[0] == TYP_FORUM) {
    UpdateDBforum($action,$id);
  }
  elseif ($data[0] == TYP_NEWS) {
    include_once(CHEMIN.INCREP."funcrss.php");
    UpdateDBnews();
  }
  elseif ($data[0] == TYP_REACT) {
    UpdateDBreact($action,$id);
  }
  elseif ($data[0] == TYP_REBLOG) {
    UpdateDBreblog($action,$id);
  }
  return $id;
}

function InitDBlog($typ) {
  $db = array();
  $db[0][0] = 0;
  for ($i = 0; $i < 14; $i++) { $db[1][$i] = 0; }
  for ($i = 0; $i < 2; $i++) { $db[2][$i] = 0; }
  for ($i = 0; $i < 9; $i++) { $db[3][$i] = 0; }
  for ($i = 0; $i < 10; $i++) { $db[4][$i] = 0; }
  for ($i = 0; $i < $typ; $i++) { $db[5][$i] = 0; }
  for ($i = 0; $i < $typ; $i++) { $db[6][$i] = 0; }
  $db[7][0] = 1;
  return $db;
}

function eMailTo($eSubject, $eMessage, $eTo)  {
eMailHtmlTo($eSubject, "", $eTo, "", $eMessage);
}


function eMailHtmlTo($eSubject, $eMsgHtml, $eTo, $eFrom = "", $eMsgTxt = "")  {
  global $supervision, $user, $charset;
  if (empty($eFrom)) {
    $eFrom = trim($user[1]);
  }
  if ($eTo == "")  {
    $eTo = $eFrom;
  }
  if ($eMsgTxt == '')
    $eMsgText = strip_tags(preg_replace("!<br />|<br />|</p>!i", "\n", preg_replace("!<hr>|<hr />!i", "\n \n", $eMsgHtml)));

  if ($eMsgHtml == '')
    $eMsgHtml = str_replace("\n", "<br />", str_replace("\n \n", "<hr />", $eMsgTxt));

  $eHeadersText  = "Content-Type: text/plain; charset=".$charset."\n";
  $eHeadersText .= "Content-Transfer-Encoding: 8bit\r\n";
  $eHeadersHtml  = "Content-Type: text/html; charset=".$charset."\n";
  $eHeadersHtml .= "Content-Transfer-Encoding: 8bit\r\n";
  $eSeparator    = "==S=E=P=A=R=A=T=O=R==";
  $eHeadersMixt  = "MIME-Version: 1.0\n";
  $eHeadersMixt .= "Content-Type: multipart/alternative; boundary=\"".$eSeparator."\"\r\n";

  $eHeaders = $eHeadersMixt;
  $eMessage  = "--".$eSeparator."\n".$eHeadersText."\n".$eMsgText."\r\n";
  $eMessage .= "--".$eSeparator."\n".$eHeadersHtml."\n".$eMsgHtml."\r\n";
  $eMessage .= "--".$eSeparator."--\n";

  if ($supervision[5] == "standard")  {

    @mail($eTo, $eSubject, $eMessage, "From :".$eFrom."\r\n".$eHeaders);
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
  $textin = strtr($textin," àéèêëîï","_aeeeeii");
  $textout = preg_replace("![^a-zA-Z0-9_]!i","",$textin);
  return $textout;
}

function ValUnique($tableau) {
  for ($i = 0, $n = count($tableau); $i < $n; $i++)
    $NewTableau[$tableau[$i]] = 1;
    @reset($NewTableau);
  for ($i = 0, $n = count($NewTableau); $i < $n; $i++) {
    $KeyUnique[] = key($NewTableau);
    @next($NewTableau);
  }
  return $KeyUnique;
}

function compare_id1($a, $b) {
    return ($a[1] < $b[1] ? -1 : +1 );
}

function compare_db2($a, $b) {
    if ($a[1] == $b[1]) {
        return($a[2] < $b[2] ? -1 : +1);
    } else {
        return($a[1] < $b[1] ? -1 : +1);
    }
}

function GetNavBar(
    $url,
    $maxItem,
    $currentPage = 1,
    $nbItemPage = 10,
    $imgBegin = 'inc/img/general/debut.gif',
    $imgPrev = 'inc/img/general/precedent.gif',
    $imgNext = 'inc/img/general/suivant.gif',
    $imgEnd = 'inc/img/general/fin.gif',
    $imgBeginN = 'inc/img/general/debut_n.gif',
    $imgPrevN = 'inc/img/general/precedent_n.gif',
    $imgNextN = 'inc/img/general/suivant_n.gif',
    $imgEndN = 'inc/img/general/fin_n.gif',
    $imgMinus = 'inc/img/general/minuspg.gif',
    $imgPlus = 'inc/img/general/pluspg.gif',
    $decade = 10
    )
{
  global  $page, $web32, $web34, $web336, $web337, $web338, $web339, $web340, $web341;

  $out = '';
  if ($maxItem > $nbItemPage) {
    $nbPage=(ceil($maxItem/$nbItemPage));
    $out .= '<div style="text-align:center">';
    $out .= '<table cellspacing="0" cellpadding="5" align="center" border="0" summary=""><tr>';
    if ($currentPage > 1) {
      $out .= '<td><a href="'.$url.'1"><img src="'.CHEMIN.$imgBegin.'" style="border:none" alt="'.$web339.'" title="'.$web339.'" /></a></td>';
      $out .= '<td><a href="'.$url.($currentPage-1).'"><img src="'.CHEMIN.$imgPrev.'" style="border:none" alt="'.$web32.'" title="'.$web32.'" /></a></td>';
  	}
  	else {
      $out .= '<td><img src="'.CHEMIN.$imgBeginN.'" style="border:none" alt="'.$web339.'" title="'.$web339.'" /></td>';
      $out .= '<td><img src="'.CHEMIN.$imgPrevN.'" style="border:none" alt="'.$web32.'" title="'.$web32.'" /></td>';
  	}
  	$out .= '<td>';
    $nbpg = 1;
    $pgDebut = floor($currentPage / $decade) * $decade;
    $pgFin = ceil($currentPage / $decade) * $decade;
    if ($pgDebut == $pgFin) {
      $pgDebut = $pgFin - $decade;
    }
    if ($currentPage > $pgDebut && $currentPage <= $pgFin) {
      $decadeDebut = $pgDebut;
      $decadeFin   = $pgFin;
      if ($nbPage >= $decadeFin) {
        $paq = $decade;
      }
      else{
        $paq = $nbPage - $decadeDebut;
      }
    }
    if ($currentPage > $decade && $decadeDebut < $nbPage) {
      if ($nbPage - $decade + $decadeFin > $decade) {
        $nbPrevPage = $decade;
      }
      else {
        $nbPrevPage = $nbPage - $decade + $decadeFin;
      }
      if ($nbPrevPage > 1) {
        $txtPrevPage = $nbPrevPage." ".$web340;
      }
      else {
        $txtPrevPage = $nbPrevPage." ".$web341;
      }
      $out .= '<a href="'.$url.($currentPage + $decadeDebut - $decadeFin).'"><img src="'.CHEMIN.$imgMinus.'" alt="'.$txtPrevPage.'" title="'.$txtPrevPage.'" border="0" /></a>';
    }
    $out .= ' [ ';
    for($i = 1; $i <= $paq; $i++) {
      if ($i + $decadeDebut <> $currentPage) {
        $out .= '<a href="'.$url.($i + $decadeDebut).'">'.($nbpg + $decadeDebut).'</a> ';
      } else {
        $out .= '<span style="text-decoration:underline; font:bold '.($page[2]+2).'px '.$page[1].';">'.($nbpg + $decadeDebut).'</span> ';
   		}
      $nbpg++;
    }
    $out .= '] ';
  	if($currentPage <= $decadeFin && $decadeFin < $nbPage) {
  		if($nbPage - $decade - $decadeDebut > $decade) {
  			$nbSuivPage = $decade;
  		}
  		else {
  			$nbSuivPage = $nbPage - $decade - $decadeDebut;
  		}
  		if ($nbSuivPage > 1) {
  			$txtSuivPage = $nbSuivPage." ".$web337;
  		}
  		else {
  			$txtSuivPage = $nbSuivPage." ".$web336;
  		}
      $out .= '<a href="'.$url.$tri.($i + $decadeDebut).'"><img src="'.CHEMIN.$imgPlus.'" style="border:none" alt="'.$txtSuivPage.'" title="'.$txtSuivPage.'" /></a>';
    }
    $out .='</td>';
    if ($currentPage < $nbPage) {
      $out .= '<td><a href="'.$url.($currentPage + 1).'"><img src="'.CHEMIN.$imgNext.'" style="border:none" alt="'.$web34.'" title="'.$web34.'" /></a></td>';
      $out .= '<td><a href="'.$url.$nbPage.'"><img src="'.CHEMIN.$imgEnd.'" style="border:none" alt="'.$web338.'" title="'.$web338.'" /></a></td>';
    }
    else {
      $out .= '<td><img src="'.CHEMIN.$imgNextN.'" style="border:none" alt="'.$web34.'" title="'.$web34.'" /></td>';
      $out .= '<td><img src="'.CHEMIN.$imgEndN.'" style="border:none" alt="'.$web338.'" title="'.$web338.'" /></td>';
    }
    $out .= '</tr></table></div>';
  }
  return $out;
}

function MakeRadioGroup($groupe) {
  global $admin31, $admin32, $admin34, $admin60, $admin89;
  foreach ($groupe as $index=>$element) {
    $present = $element[0];
    $futur = $element[1];
    $id = $element[2];
    switch ($present.$futur) {
    case "ai" :
      $img1 = 'admin/inc/img/files/on1.gif';
      $img2 = 'admin/inc/img/files/off2.gif';
      $alt = $admin32;
      break;
    case "ia" :
      $img1 = 'admin/inc/img/files/off1.gif';
      $img2 = 'admin/inc/img/files/on2.gif';
      $alt = $admin34;
      break;
    case "ad" :
      $img1 = 'admin/inc/img/files/supa1.gif';
      $img2 = 'admin/inc/img/files/sup2.gif';
      $alt = $admin31;
      break;
    case "id" :
      $img1 = 'admin/inc/img/files/supi1.gif';
      $img2 = 'admin/inc/img/files/sup2.gif';
      $alt = $admin31;
      break;
    case "ds" :
      $img1 = 'admin/inc/img/files/sup1.gif';
      $img2 = 'admin/inc/img/files/sup2.gif';
      $alt = $admin60;
      break;
    case "di" :
      $img1 = 'admin/inc/img/files/save1.gif';
      $img2 = 'admin/inc/img/files/save2.gif';
      $alt = $admin89;
      break;
    }
    $name1 = $futur . '_' . $id;
    echo " <input type=\"hidden\" name=\"".$name1."\" id=\"".$name1."\" value=\"\" />";
    $args = "'rb".$id."o', 'rb".$id."x', 0, ".count($groupe).", ".$index.", 'inline'" ;
    $name = 'rb' . $id . 'o' . $index;
    echo "<img id=\"".$name."\" style=\"cursor:pointer\" src=\"".CHEMIN.$img1."\" onclick=\"ActiveMenu(".$args."); ToggleValue('".$name1."');\" alt=\"".$alt."\" title=\"".$alt."\" />";
    $args = "'rb".$id."o', 'rb".$id."x', ".$index.", 'inline'" ;
    $name = 'rb' . $id . 'x' . $index;
    echo "<img id=\"".$name."\" style=\"cursor:pointer; display:none\" src=\"".CHEMIN.$img2."\" onclick=\"DesactiveItem(".$args."); ToggleValue('".$name1."');\" alt=\"".$alt."\" title=\"".$alt."\" />";
  }
}

function attribut($attribut, $value) {
  if (!empty($value)) {
    return $attribut.'="'.$value.'"';
  }
  return "";
}

function Formatage($format, $in) {
  $out = "";
  if (!empty($in) && !empty($format))
    $out = str_replace(" ", "&nbsp;", sprintf($format, $in));
  return($out);
}

function import($name, $origine='', $striptags=true) {
  switch ($origine) {
  case 'post' :
  case 'POST' :
    $var = isset($_POST[$name]) ? $_POST[$name] : NULL ;
    break;
  case 'get':
  case 'GET':
    $var = isset($_GET[$name]) ? $_GET[$name] : NULL ;
    break;
  default :
    $var = isset($_POST[$name]) ? $_POST[$name] : (isset($_GET[$name]) ? $_GET[$name] : NULL) ;
  }
  return $striptags ? strip_tags($var) : $var;
}

function IncrNextID() {
  $nextidbk = ReadCounter(NEXTIDBK);
  $nextid = ReadCounter(NEXTID) + 1;
  if ($nextid < $nextidbk) $nextid = $nextidbk + 1;
  while (file_exists(DBBASE.$nextid.INCEXT)) $nextid++;
  WriteCounter(NEXTID, $nextid);
  if ($nextid > $nextidbk + 10) WriteCounter(NEXTIDBK, $nextid);
  return $nextid;
}

function AsciiCompare($left,$right) {
  return strcasecmp($left,$right);
}

function ShowBlock($name, $items, $skintheme=NULL) {
    global $lng, $page, $selskin, $admin725;
    $tmp = '
<fieldset>
  <legend>'.$name.'</legend>';

    $skn = '';
    if (isset($skintheme)) {
        if (count($skintheme) > 1) {
            $tmp .= '
    <div class="forum2" style="text-align:center">
      <form method="post" name="skin" action="admin.php?lng='.$lng.'">'.$admin725.' :
        <select name="selskin" style="vertical-align:middle;" onchange="submit(); return true;">';
            foreach ($skintheme as $skin){
                $tmp .= '
        <option value="'.$skin.'"'.($page[14]==$skin ? ' selected="selected"' : '').'>'.$skin.'</option>';
            }
            $tmp .= '
        </select>
        <input type="submit" value="Go" title="Go"  style="vertical-align:middle;"/>
      </form>
    </div>';
        } else {
            $tmp .= '
    <div class="forum2" style="text-align:center">'.$admin725.' : <strong>'.$selskin.'</strong>
    </div>';
        }
        $skn = '&amp;selskin='.$selskin;
    }
    $tmp .= '<div style="width:540px;margin:0 auto;">';
    foreach ($items as $item) {
        $href = 'admin.php?lng='.$lng.'&amp;pg='.$item['href'].$skn;
        $src  = empty($item['src']) ? $item['href'] : $item['src'];
        $src  = (strpos($item['src'], '/')  === false ? 'inc/img/admin/'.$src.'.gif' : $src);
        $txt  = $item['txt'];
        $tmp .= '
    <div style="float:left; width:115px; height:75px; text-align:center; padding:0 10px;">
      <a href="'.$href.'" title="'.$txt.'">
        <img src="'.$src.'" alt="'.$txt.'" title="'.$txt.'" style="border-style:none;" /><br />'.$txt.'
      </a>
    </div>';
    }

    $tmp .= '
  </div><div style="clear:both"></div>
</fieldset><br />';
    echo $tmp;
}

function SearchOption($serviz_actif, $members_inactif, $typ_code, $typ_nom) {
  global $userprefs, $members;
  if (!$serviz_actif) return;
  if ($userprefs[1] != '' || $members[0] != 'on' || $members_inactif) {
    return '
        <option value="'.$typ_code.'">'.$typ_nom.'</option>';
  }
}

function ExploreDir($dir) {
    $array = array();
    $dossier = opendir(CHEMIN.$dir);
    while ($fichier = readdir($dossier)) {
        if ($fichier != "." && $fichier != ".." && is_dir(CHEMIN.$dir.$fichier) ) {
            $array[] = $fichier;
        }
    }
    closedir($dossier);
    sort($array);
    return $array;
}

function ExploreFile($dir) {
    $array = array();
    $dossier = opendir(CHEMIN.$dir);
    while ($fichier = readdir($dossier)) {
        if (is_file(CHEMIN.$dir.$fichier) && $fichier != 'index.php') {
            $array[] = $fichier;
        }
    }
    closedir($dossier);
    sort($array);
    return $array;
}

function ExploreImg($dir) {
    $array = array();
    $dossier = opendir(CHEMIN.$dir);
    while ($fichier = readdir($dossier)) {
        if (is_file(CHEMIN.$dir.$fichier) && $fichier != 'index.php') {
            $path_parts = basename($fichier);
            $path_parts = substr($path_parts,strrpos($path_parts,".")+1);
            if (IsImage($path_parts)) {
            $array[] = $fichier;
            }
        }
    }
    closedir($dossier);
    sort($array);
    return $array;
}

function ForceToAbsolute_callback($m) {
    global $site;
    if (preg_match('!^(http|ftp|mailto)s?:!', $m[2])) {
        /// cas d'une URL absolue
        return $m[0];
    } else {
        if (strpos('#', $m[2]) === 0 ) {
            /// cas d'une ancre (href="#xxx")
            return $m[0];
        } else {
            /// cas d'une URL relative
            return $m[1].$site[3].$m[2];
        }
    }
}

function ForceToAbsolute($s) {
    $s = preg_replace_callback('!( src=")([^"]*")!', 'ForceToAbsolute_callback', $s);
    $s = preg_replace_callback('!( href=")([^"]*")!', 'ForceToAbsolute_callback', $s);
    return $s;
}

function checkUserWebsiteUrl($url) {
    $url = trim($url);
if (preg_match('/(http:\/\/|https:\/\/)?(www.)?(([a-zA-Z0-9à-ö-]){2,}\.){1,4}([a-zA-Zà-ö]){2,6}(\/([a-zA-Zà-ö-_\/\.0-9#:?=&;,]*)?)?/', $url)) {
        return $url;
    }
    return 'http://';    
}

function Checked($bool) {
    return $bool ? ' checked="checked"' : '';
}

function Selected($bool) {
    return $bool ? ' selected="selected"' : '';
}

function checkEmail($email) {
    
    $email = trim($email);
    
    // Auteur : bobocop (arobase) bobocop (point) cz
    // Le code suivant est la version du 2 mai 2005 qui respecte les RFC 2822 et 1035
    // http://www.faqs.org/rfcs/rfc2822.html
    // http://www.faqs.org/rfcs/rfc1035.html
    
    $atom   = '[-a-z0-9!#$%&\'*+\\/=?^_`{|}~]';   // caractères autorisés avant l'arobase
    $domain = '([a-z0-9à-ö]([-a-z0-9à-ö]*[a-z0-9à-ö]+)?)'; // caractères autorisés après l'arobase (nom de domaine)
                                   
    $regex = '/^' . $atom . '+' .   // Une ou plusieurs fois les caractères autorisés avant l'arobase
    '(\.' . $atom . '+)*' .         // Suivis par zéro point ou plus
                                    // séparés par des caractères autorisés avant l'arobase
    '@' .                           // Suivis d'un arobase
    '(' . $domain . '{1,63}\.)+' .  // Suivis par 1 à 63 caractères autorisés pour le nom de domaine
                                    // séparés par des points
    $domain . '{2,63}$/i';          // Suivi de 2 à 63 caractères autorisés pour le nom de domaine
    
    // test de l'adresse e-mail
    if (preg_match($regex, $email)) {
        return $email;
    } else {
        return '';
    }    
}

?>
