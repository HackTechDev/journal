<?php
/*
	Load Includes - GuppY PHP Script - version 4.6
	CeCILL Copyright (C) 2004-2012 by Laurent Duveau
	Initiated by Laurent Duveau and Nicolas Alves
	  Web site = http://www.freeguppy.org/
	  e-mail   = guppy@freeguppy.org

	Version History :
	  v1.0 (30 December 2002)   : initial release
	  v1.3 (06 January 2003)    : added $mpversion variable
	  v1.6 (23 January 2003)    : updated $mpversion
								  added page loaded in n.nn seconds information
	  v1.7 (28 January 2003)    : updated $mpversion
								  added $endurl variable to switch language without going back to index page (thanks Alex)
	  v1.8 (05 February 2003)   : updated $mpversion
	  v1.9 (11 February 2003)   : updated $mpversion and added $mpdate
	  v2.0 (27 February 2003)   : updated $mpversion and $mpdate
	  v2.1 (10 March 2003)      : updated $mpversion and $mpdate
	  v2.2 (22 April 2003)      : updated $mpversion and $mpdate
								  split of language file in two xx-web.inc and xx-admin.inc for faster loading
	  v2.3 (27 July 2003)       : updated $mpversion and $mpdate
								  added user prefs management by cookie
	  v2.4 (24 September 2003)  : updated $mpversion and $mpdate
								  secured the lng command line parameter (Secunia Advisory: SA8750)
								  secured cookie & $endurl parameters
	  v2.4p1 (26 Sept. 2003)     : updated $mpversion and $mpdate
	  v2.4p3 (29 Sept. 2003)     : updated $mpversion and $mpdate
	  v2.4p4 (04 October 2003)   : Cookie security correction (by frog-m@n, http://www.phpsecure.info, thanks)
								   updated $mpversion and $mpdate
	  v3.0 (25 February 2004)    : updated $mpversion and $mpdate
								   added skin management
							       added UID management for Tiny Messages
								   compatibility with php.ini register_globals=off parameter (thanks JonnyQuest)
							       replaced $REQUEST_URI global variable by $SCRIPT_NAME for IIS compatibility (thanks Erik)
							       added limit Pseudo to basic [a-Z][0-9] characters and to 20 characters
	  v3.0p1 (26 Feb 2004)       : updated $mpversion and $mpdate
								   include only once reglobals (time saving when in admin)
	  v3.0p2 (09 April 2004)     : updated $mpversion and $mpdate
								   compatibility fix: now GuppY is fully compatible with Abyss webserver and IIS
	  v3.0p3 (29 July 2004)      : security patch - thanks to L0rd L4m3R
								   updated $mpversion and $mpdate
	  v3.0p4 (06 September 2004) : added CutLongWord to limit the size of the inputs
	  v4.0  (06 December 2004)   : updated $mpversion and $mpdate
								    added browser test (by Icare)
								    updated language control (by Jean-Mi)
								    added $lang array - thanks KnoB
								    added userpref[8] to [10] (by Nico)
								    added maintain option (by Nico)
	  v4.5 (30 March 2005)        : new update (by Jean-Mi)
	  v4.5.12 (09 March 2006)     : corrected parameters test (by JeanMi)
	  v4.6.0 (04 June 2007)       : added preferences deletion if user is no longer member (by Icare)
						            config.inc is now in two parts: config.inc and skin/confskin.inc
						            added uid checking (by Icare)
	  v4.6.1 (08 June 2007)       : correctd uid ckeck (by Icare)
	  v4.6.4 (04 November 2007)   : new secured release (by Hpsam-Ghazette and jchouix)
	  v4.6.9 (25 December 2008)   : added a test of security on the numeric parameters #242
      v4.6.10 (7 September 2009)  : corrected #272
      v4.6.13 (22 May 2010)       : corrected #286
      v4.6.14 (14 February 2011)  : updated $mpversion and $mpdate
      v4.6.15 (30 June 2011)      : updated $mpversion and $mpdate
      v4.6.16 (02 September 2011) : updated $mpversion and $mpdate
      v4.6.17 (21 October 2011)   : updated $mpversion and $mpdate
	  v4.6.18 (09 February 2012)  : added width parameter editor (by Saxbar)
                                    added $mpcopyright (by Saxbar)
	                                added time zone (by Saxbar and JeanMi)
	                                updated $mpversion and $mpdate
	  v4.6.19 (30 March 2012)     : updated $mpversion and $mpdate
	  v4.6.20 (24 May 2012)       : corrected parameters test (by Saxbar and JeanMi)
	                                updated $mpversion and $mpdate
	  v4.6.21 (18 October 2012)   : updated $mpversion and $mpdate
	  v4.6.21a (23 October 2012)  : updated $mpversion and $mpdate
	  v4.6.22 (29 December 2012)  : updated $mpversion and $mpdate		  
*/

if (@preg_match("!//|/\*|#|:/|\.\./|%2E\./|\.%2E/|%2E%2E/|document.cookie|/script!i", $_SERVER["QUERY_STRING"])
	|| @preg_match('!script|%3C|%3E!i', $_SERVER['HTTP_REFERER'])
	|| @preg_match('!script|%3C|%3E!i', $_SERVER['REMOTE_ADDR'])) {
    die('Requête non autorisée - Request not allowed');
}
if (stristr($_SERVER["SCRIPT_NAME"], "includes.inc")) {
    header("location:../index.php");
    die();
}
$mpversion   = "4.6.22";
$mpdate      = "29 December 2012";
$mpcopyright = '2004-2012';

$lang = array("","");
include(CHEMIN."inc/reglobals.inc");
include(CHEMIN."data/config.inc");
if (substr($serviz[63], -1) != '%' && substr($serviz[63], -2) != 'px') $serviz[63] = '560px';

if (version_compare(phpversion(), '5.2', '>=')) {
	date_default_timezone_set($site['TZ']);
}

/// Test et nettoyage des paramétres qui doivent être des entiers positifs ou nuls
function TestInteger($name) {
    global ${$name};
    $n = preg_match('!^([0-9]+)!', ${$name}, $res);
    if ($n == 0 || $res[1] == '')
        unset(${$name});
    else
        ${$name} = $res[1];
}
TestInteger('pg');
TestInteger('id');
TestInteger('num');

$usercookie = "GuppYUser";
$userprefs = array();
if (!empty($_COOKIE[$usercookie])) {
    $userprefs = explode("||",$_COOKIE[$usercookie]);
    $userprefs[0] = strip_tags($userprefs[0]);
    $userprefs[1] = preg_replace("![^a-zA-Z0-9_]!i","",substr(strip_tags($userprefs[1]),0,20));
    $userprefs[2] = strip_tags($userprefs[2]);

    $userprefs[3] = strip_tags($userprefs[3]);
    $userprefs[4] = strip_tags($userprefs[4]);
    $userprefs[5] = strip_tags($userprefs[5]);
    $userprefs[6] = str_replace("\n","<br />",strip_tags($userprefs[6]));
    if (($userprefs[0] == $lang[0] || $userprefs[0] == $lang[1]) && empty($lng)) {
        $lng = $userprefs[0];
    }
    $userprefs[7] = strip_tags($userprefs[7]);
    $userprefs[8] = strip_tags($userprefs[8]);
    $userprefs[9] = strip_tags($userprefs[9]);
    $userprefs[10] = strip_tags($userprefs[10]);
}

$lng = strip_tags($lng);
if (empty($lng)) {
    $lng = $lang[0];
} elseif (($lng != $lang[0]) && ($lng != $lang[1])) {
    $lng = $lang[0];
}

include(CHEMIN."inc/functions.php");

if ($userprefs[1] != "" && FileDBExist(USEREP.$userprefs[1].DBEXT)) {
    $dbmsg = ReadDBFields(USEREP.$userprefs[1].DBEXT);
    if ($userprefs[7] != $dbmsg[0][0]) {
        for ($i = 0; $i < 12; $i++) {
            $userprefs[$i] = "";
        }
        setcookie($usercookie, "");
?>
<script type="text/javascript" language="javascript">
alert('illegal cookie values or bad password');
window.location="<?php echo CHEMIN.'user.php?lng='.$lng; ?>";
</script>
<?php
        header("location:".CHEMIN."user.php?lng=".$lng);
    }
} else {
    $userprefs[0] = "";
    $userprefs[1] = "";
    $userprefs[2] = "";
    $userprefs[3] = "";
    $userprefs[4] = "";
    $userprefs[5] = "";
    $userprefs[6] = "";
    $userprefs[7] = "";
    $userprefs[8] = "";
    $userprefs[9] = "";
    $userprefs[10] = "";
    $userprefs[11] = "";
    setcookie($usercookie, "");
}

StartTimer();

if (!isset($_SERVER['REQUEST_URI'])) {
    $REQUEST_URI = $_SERVER['SCRIPT_NAME']."?".$_SERVER['QUERY_STRING'];
}

$endurl = strip_tags($REQUEST_URI);

if (!empty($userprefs[4]) and ($userprefs[4] == $lng)) {
    include(CHEMIN.INCREP."lang/".$userprefs[4]."-web".INCEXT);
}
else {
    include(CHEMIN.INCREP."lang/".$lng."-web".INCEXT);
}
if (strpos($endurl, "/admin/") !== false) {
    include(CHEMIN.INCREP."lang/".$lng."-admin".INCEXT);
    include(CHEMIN.INCREP."lang/".$lng."-web".INCEXT); // corrected with 4.6.14g
}

$flag1 = CHEMIN.INCREP."lang/".$lang[0].".gif";
$flag2 = CHEMIN.INCREP."lang/".$lang[1].".gif";

if (!headers_sent()) header("Content-type: text/html; charset=$charset;");

if (stristr($_SERVER['SCRIPT_NAME'], "calendar.php") === false) {
    include(CHEMIN.INCREP."log.inc");
}

$xposbox = array();

if($userprefs[10]!="") {
    $page[14]=$userprefs[10];
}
if (isset($selskin)) {
    $page[14] = preg_replace("`[^-a-z0-9_]`i","",$selskin);
}
if (is_file(CHEMIN."skin/".$page[14]."/skin".INCEXT)) {
    include(CHEMIN."skin/".$page[14]."/skin".INCEXT);
} else {
    include(CHEMIN."skin/no_skin/skin".INCEXT);
}
if (is_file(CHEMIN."skin/".$page[14]."/confskin".INCEXT)) {
    include(CHEMIN."skin/".$page[14]."/confskin".INCEXT);
} else {
    include(CHEMIN."skin/no_skin/confskin".INCEXT);
}

if ($userprefs[3] == '') {
    $left_empty = true;
    foreach($xposbox['L'] as $emplac) {
        if (!empty($emplac)) {
            $left_empty = false;
            break;
        }
    }
    if ($left_empty) {
        $userprefs[3] = 'R';
    } else {
        $right_empty = true;
        foreach($xposbox['R'] as $emplac) {
            if (!empty($emplac)) {
                $right_empty = false;
                break;
            }
        }
        if ($right_empty) {
            $userprefs[3] = 'L';
        } else {
            $userprefs[3] = 'LR';
        }
    }
}

$userAgent = $_SERVER['HTTP_USER_AGENT'];
if ((strpos($userAgent,  "MSIE") !== false) and (strpos($userAgent, "compatible") !== false)
and (strpos($userAgent, "Opera")=== false) and (strpos($userAgent, "Gecko") === false)
and (strpos($userAgent, "Konqueror") === false))
    $browser = "OK";
elseif ((strpos($userAgent, "Gecko") !== false) and (strpos($userAgent, "Safari") === false) and (strpos($userAgent, "Konqueror") === false))
    $browser = "OK";
elseif (strpos($userAgent, "Konqueror") !== false)
    $browser = "OK";
elseif (strpos($userAgent, "Safari") !== false)
    $browser = "OK";
elseif (strpos($userAgent, "Opera") !== false) {
    $version = (float)substr($userAgent, strpos($userAgent, 'Opera/') + 6, 3);
    $browser = $version >= 9.0 ? "OK" : "KO";
}
else
  $browser = "KO";
  
if (strpos($endurl, "/admin/") === false) {
    if ($serviz[44] == "on" &&  ($userprefs[1] == '' || ( $serviz[31] != '' && $serviz[31] != $userprefs[1]))) {
        header('Location: maintenance.php');
    }
}
