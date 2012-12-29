<?php
/*
    Guest Post Routine - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v1.0 (30 December 2002)   : initial release
      v1.1 (02 January 2003)    : modified Smileys and Allowed Tags for better rendering with screen resolutions inferior to 1024x768
      v1.2 (05 January 2003)    : created databases thread.dtb and forum.dtb for quicker display of forum threads
      v1.3 (06 January 2003)    : added send supervision e-mail
                                  use databases thread.dtb and forum.dtb introduced with v1.2 for quicker work
                                   on forum threads posts
      v1.4 (07 January 2003)    : stripslashes(text) in supervision e-mails
      v1.6 (23 January 2003)    : slightly updated the supervision e-mail formating sent for guestbook
                                  added option to hide on the site the e-mail address of poster
      v1.7 (28 January 2003)    : updated the VerifyForm() javascript function to take into account all possible cases
                                  added Recommend to a Friend box
      v1.8 (05 February 2003)   : added forum category management
                                  bug correction in the eMailTo() function call
      v1.9 (11 February 2003)   : added category information in forum supervision mail sending
      v2.0 (27 February 2003)   : debugged the VerifyForm() javascript function for undefined verified variables
                                  removed input form on postguest form return & added back button to it
                                  added protection against SPAM notice
      v2.1 (10 March 2003)      : added addslashes() to var in Javascript functions (to avoid errors)
                                  click on smiley copies smiley to text (by Nicolas Alves)
                                  focus on first field in input form (by B@lou and Laurent Duveau)
                                  removed Title from Thread answer in supervision e-mail (returned "ptit" instead of nothing)
      v2.2 (22 April 2003)      : added answer's text reminder (by Nicolas Alves)
                                  small update of the layout for e-mail sent to the webmaster in case of new thread
                                  replaced <P><CENTER> by <P align="center"> otherwise IE takes the default font instead of the required one (Thanks Michel)
                                  click on text formating tag copies tag to text
                                  use of DrawSmileys() function
                                  focus back to text after inserting a Smiley or a tag
      v2.3 (27 July 2003)       : user news post: even if written in one language, put the news in both languages (until the webmaster translates it)
                                  bug correction: accepts e-mails like "firstname-lastname@site.com (accept "-" character)
                                  the check for the e-mail is not as exhaustive as it used to be but it checks for most bad input cases
                                  added forms style management (by Nicolas Alves)
                                  added user prefs management by cookie
                                  added US date format management
                                  added basic editor capabilities for user input (by Nicolas Alves and Laurent Duveau)
                                  AddSmiley() function upgraded
      v2.4 (24 September 2003)  : added react to an article option
                                  added backup counter for next forum thread number
                                  added forum personalized signature
                                  added ReadDoc() function
                                  added GetCurrentDateTime() and FormatDate() function to ease various date and time formatings
                                  reviewed all Files Read & Write functions
                                  secured transfered parameters
                                  created $typ_[name] variables
      v2.4p1 (26 Sept. 2003)    : bug correction = now [ back] works after forum thread posting
      v2.4p2 (28 Sept. 2003)    : XSS security correction in the posting module (by Das, http://www.echu.org, thanks)
      v2.4p4 (04 October 2003)  : XSS security correction in the posting module (by frog-m@n, http://www.phpsecure.info, thanks)
      v3.0 (25 February 2004)   : added skins (by Nicolas Alves)
                                  added check for (, ) and ; characters Javascript attempts in URL (security correction)
                                  added check for too long words (to avoid screen disalignment)
                                  added check for valid forum category (security enhancement)
                                  added a "Please Wait..." message while a post is being processed and a check to avoid redundant posting (thanks Icare)
                                  automated return after posting (thanks Icare)
      v4.0 (06 December 2004)   : added page title, modified forum engine,
  	                              added admin agree for guestbook and forum (by Jean-Mi)
                                  added new wisiwig editor for IE or Mozilla
    		                          upgrade mini-editor for other browsers and export pseudo-tags control in javascript (by Icare)
  	                              added alt tags to img and removed border tag for non-linked img,
  	                              cleaning code : removed P tags redunding with  forms style (by Isa)
        				                  added WrapLongWords in textareas (by Albweb)
        				                  added members management (by Nicolas Alves)
                                  added mail to watch on post answer (by Nicolas Alves)
        				                  added quotation insert on response (by Icare)
      v4.5 (27 May 2005)        : added links in supervision mail (by Jean-Mi)
  	                              changed popup by div for message "in progress" (by Icare)
                								  changed textarea ancienptxt by div (by Icare)
                								  updated reco and return process, added mail to webmaster (by Icare)
      v4.5.1 (06 July 2005)     : corrected e-mail sending errors (by Icare)
      v4.5.4 (01 September 2005): changed &amp; by & in $backurl (by Icare)
      v4.6.0 (04 June 2007)     : added forum facilities and blog fonctionnalities, display message for reactions (by Icare)
                                  new wysiwyg editor xhtml compliant(by Icare and Djchouix)
                                  changed $pseudo controls by KeepGoodchars() (by Icare)
                                  import function transfered to functions.php (by Icare)
                                  added controls for inactive services, changed increase nextid by function IncrNext()  (by JeanMi)
                                  corrected control for empty areas (by Djchouix)
      v4.6.1 (02 July 2007)     : corrected bad action value on links of supervision mails,
                                  corrected return message in verifyForm() (thanks hpsam)
                                  bypass validJSCodePGEditor() if $mod=up or top (by Icare)
                                  corrected user illegal answer on closed thread and
                                  bad option value in select of blog categorie (by Icare)
      v4.6.3 (30 August 2007)   : corrected links in supervision mails(thanks Hpsam)
                                  added moderation for reactions to articles and comments on blog (by Icare)
      v4.6.5 (05 December 2007) : added referer control (by Icare)
      v4.6.6 (14 April 2008)    : corrected bad frcount when serviz[41] is on (by Icare)
                                  corrected checking thread status on answer (by Icare)
      v4.6.7 (23 April 2008)    : corrected <br/> (by Icare)
      v4.6.8 (24 May 2008)      : corrected checking HTTP_REFERER, illegal entry if $num=0 (by JeanMi)
                                  no mail send to thread subscriber when $serviz[41] is on (by Icare)
                                  updated supervision messages (thanks JeanMi)
                                  corrected empty value of $catthread (by JeanMi)
                                  new release of pgeditor (by jchouix)
      v4.6.9 (25 December 2008) : improvement of control on $num #203
	                                added $serviz[62] to control the function To recommend ON/OFF #20
	                                added $user[3] to control the function Email PHP ON/OFF #20
	                                conservation of the inputs in the event of pseudo already used (suggestions box #160)
      v4.6.10 (7 September 2009)   : corrected #253, #256, #272, #274 and #283
      v4.6.11 (11 December 2009)   : changed width by style=width in cells
      v4.6.14 (14 February 2011)   : corrected $purl (thanks jchouix)
      v4.6.15 (30 June 2011)       : added private forum management (by Icare)
      v4.6.18 (09 February 2012)   : corrected management response forum thread (thanks linuxmr, Saxbar)
	                                 added send message to all moderators at the request of the administrator (thanks tonton_christian, Saxbar)
	  v4.6.21 (18 October 2012)    : corrected display $web111 (thanks JeanMi)
                                     corrected subscription for maj thread (by Saxbar)
	  v4.6.22 (29 December 2012)   : added pseudo-private group for members (by Saxbar)
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");

function getmicrotime(){
  list($usec, $sec) = explode(" ",microtime());
  return ((float)$usec + (float)$sec);
}

function FindIndexDBFields($fic, $submit0, $submit1, $submit2) {
  if (FileDBExist($fic)) {
    $DataDB = ReadDBFields($fic);
    for ($i = 0; $i < count($DataDB); $i++) {
      if (@stristr($DataDB[$i][0],$submit0)
      &&  @stristr($DataDB[$i][1],$submit1)
      &&  @stristr($DataDB[$i][2],$submit2)) {
        return $i;
      }
    }
  }
  return false;
}
/// début modif accès privé
function SelectDBForumByNum($Fields,$id) {
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
/// fin modif accès privé
if (!isset($serviz[51]) || !is_numeric($serviz[51]) || $serviz[51] < 50) $serviz[51] = ANTISPAM_COUNT;
if (!isset($serviz[52]) || !is_numeric($serviz[52]) || $serviz[52] < 10) $serviz[52] = ANTISPAM_DELAY;

if (import('add', 'GET') != NULL) die('STOP ! Variable $add : illegal origine !');
$add      = import('add', 'POST');

switch ($add) {
case NULL :
  $lng      = import('lng');
  $typ      = import('typ');
  break;
case 1 :
  $lng      = import('lng', 'POST');
  $typ      = import('typ', 'POST');
  break;
default :
  die('STOP ! Variable $add : illegal value ('.$add.')');
}

switch ($typ) {
case TYP_FORUM :
case TYP_THREAD :
  if ($serviz[13] == '') {
    die('STOP ! Forum is not active !');
  }
  break;
case TYP_GUESTBK :
  if ($serviz[12] == '') {
    die('STOP ! Guest book is not active !');
  }
  break;
case TYP_NEWS :
  if ($serviz[8] == '' || $site[5] == 2) {
    die('STOP ! News submit is not active !');
  }
  break;
case TYP_BLOG :
  if ($serviz[53] == '' || $site[30] == 2) {
    die('STOP ! Blog submit is not active !');
  }
  break;
case TYP_REACT :
  if ($serviz[29] == '') {
    die('STOP ! Reaction is not active !');
  }
  break;
case TYP_REBLOG :
  if ($serviz[57] == '') {
    die('STOP ! Comment is not active !');
  }
  break;
case TYP_RECO :
  if ($serviz[62] == '') {
    die('STOP ! Recommander is not active !');
  }
  break;
case TYP_MAIL :
  if ($user[3] == '') {
    die('STOP ! Mail is not active !');
  }
  break;
default :
  die('STOP ! Variable $typ : illegal value ('.$typ.')');
}

switch ($lng) {
case $lang[0] :
case $lang[1] :
  break;
default :
  die('STOP ! Variable $lng : illegal value ('.$lng.')');
}

$pseudo   = import('pseudo', 'POST');
$pemail   = import('pemail', 'POST');
$pehide   = import('pehide', 'POST');
$pfmail   = import('pfmail', 'POST');
$ptit     = import('ptit', 'POST');
$purl     = import('purl', 'POST');
$cat      = import('cat');
$catforum = import('catforum', 'POST');
$rub      = import('rub', 'POST');
$pg       = import('pg');
$num      = import('num');
$antispam = import('antispam', 'POST');
$mod      = import('mod');
$group    = import('group');
$pseudo   = KeepGoodChars($pseudo);
$pemail   = CutLongWord(checkEmail($pemail));
$pfmail   = CutLongWord(checkEmail($pfmail));
$purl     = checkUserWebsiteUrl(CutLongWord($purl,80));
$ptit     = WrapLongWords(CutLongWord($ptit,100));

if(empty($ptit) && empty($mod)) $add = null; // Test si le titre est vide

define('PATH_PGEDITOR', 'inc/pgeditor/');		//Chemin relatif de l'éditeur (ne pas modifier)
define('PATH_CONFIG_PGEDITOR','inc/config_pgeditor_guppy/'); //Chemin relatif du fichier de configuration de l'éditeur
if ($typ == TYP_FORUM || $typ == TYP_THREAD || $typ == TYP_BLOG || $typ == TYP_REBLOG) {
$dbmsg = ($userprefs[1] != "" && FileDBExist(USEREP.$userprefs[1].DBEXT)) ? ReadDBFields(USEREP.$userprefs[1].DBEXT) : NULL;
$icon_img = (isset($dbmsg) && $userprefs[7] == $dbmsg[0][0]) ? 'image|' : '';
	define('TOOLBAR_MENU', 'color|bgcolor|bold|italic|underline|cite|code|left|center|right|'.$icon_img.'link|unlink|ordlist|bullist|undo|redo|smiley|preview|help');  //Barre Outils du menu	//Modif FORK PGEditor
} else {
	define('TOOLBAR_MENU', 'color|bgcolor|bold|italic|underline|left|center|right|link|unlink|ordlist|bullist|undo|redo|smiley|preview|help');  //Barre Outils du menu
}
if ($userprefs[11] == 'on') define('WYSIWYG', false);
include CHEMIN.PATH_PGEDITOR.'pgeditor.php';    //Fichier contenant toutes les fonctions nécessaires pour intégration de l'éditeur

$ptxt = recupCodePGEditor('ptxt');
$ptxt = parseCodePGEditor($ptxt);
if(empty($ptxt) && empty($mod)) $add = null;
$ptxt = WrapLongWords(CutLongWord($ptxt,5000),150);
$pmess = str_replace("inc/img",$site[3]."inc/img",$ptxt);
$ok = $web45;
$infos = 'IP: '.$REMOTE_ADDR.' ('.gethostbyaddr($REMOTE_ADDR).')<br />Referer : '.$HTTP_REFERER.'<br />Browser : '.$HTTP_USER_AGENT;

if ($add == 1) {

    if (!empty($_SERVER['HTTP_REFERER'])) {
        $url = parse_url($_SERVER['HTTP_REFERER']);
        $host = $url['host'];
        $ip = gethostbyname($host);
        if ($ip != $host) {
            if ($host != $_SERVER['SERVER_NAME']) {
                die("STOP ! Illegal action from '$host' (IP=$ip)");
            }
        }
    }

  if (empty($pseudo) || empty($pemail)) die('STOP ! Variable pseudo or email : illegal value ...');
  if ((is_file(USEREP.$pseudo.DBEXT)) && ($pseudo != $userprefs[1])) {
    ?>
    <script language="javascript" type="text/javascript">
    alert('<?php echo addslashes($web392); ?>');
    </script>
	<?php
  }
  else {
  $index = FindIndexDBFields(DBANTISPAM, $antispam, $REMOTE_ADDR, $typ);
  if ($index === false) {
    // Ajoutez l'action que vous souhaitez (par exemple : courriel à l'administrateur, inscription dans un fichier...)
    // Add any action you want (for example: emailing the administrator, writing into a file...)
    die('STOP ! Anti-SPAM !');
  }
  else {
    DeleteDBFieldById(DBANTISPAM, $index);
    if ($typ == TYP_THREAD && !preg_match('!^[1-9][0-9]*$!', $num)) {
        die('STOP ! num : '.$num.' illegal value!');
    }
    if ($members[0] == 'on' && $userprefs[1] == '') {
      switch ($typ) {
      case TYP_NEWS :
        if ($members[8] == 'on') die('STOP ! News : '.$web343.' !');
        break;
      case TYP_BLOG :
        if ($members[16] == 'on') die('STOP ! Blog : '.$web343.' !');
        break;
      case TYP_GUESTBK :
        if ($members[9] == 'on') die('STOP ! Guest book : '.$web343.' !');
        break;
      case TYP_FORUM :
      case TYP_THREAD :
        if ($members[10] == 'on') die('STOP ! Forum : '.$web343.' !');
        break;
      case TYP_REACT :
        if ($members[11] == 'on' || $members[1] == 'on') die('STOP ! Reaction : '.$web343.' !');
        break;
      case TYP_REBLOG :
        if ($members[17] == 'on' || $members[17] == 'on') die('STOP ! Comments : '.$web343.' !');
        break;
      }
    }
  }
  if (!empty($site[28]) && JAVASCRIPT) {
    $show_progbar = true;
  }

  if ($mod == "") { // cas normal
  	if ($typ == TYP_THREAD && $serviz[41] == "") {
    	$dbworkmail = ReadDBFields(DBFORUM);
	  	for ($i = 0; $i < count($dbworkmail); $i++) {
      	if ($num==$dbworkmail[$i][1]){
       		$sujetthread=$dbworkmail[$i][5];
    	 		$catthread=$dbworkmail[$i][12];
    	 		break;
		  	}
    	}
    	$dbmailuniq = Array();
    	$dbworkuniq = ReadDBFields(DBTHREAD);
    	for ($i = 0; $i < count($dbworkuniq); $i++) {
      	if ($num==$dbworkuniq[$i][1] && $dbworkuniq[$i][2]==0) {
       		$pgview=$dbworkuniq[$i][3];
      	}
      	if ($num==$dbworkuniq[$i][1] && $dbworkuniq[$i][9]=="on") {
       		$dbmailuniq[]=$dbworkuniq[$i][5];
      	}
    	}
    	$mailuniq = ValUnique($dbmailuniq);
    	for ($i = 0; $i < count($mailuniq); $i++) {
		    $to = $mailuniq[$i];
		    $sujet = $web345.$sujetthread;
		    $body  = $web346.$sujetthread."<br /><br />";
		    $body .= $web109.'<hr />'.ForceToAbsolute(stripslashes($ptxt)).'<hr /><br />';
		    $body .= $web347."<br />";
		    $body .= '<a href="';
		    $body .= $site[3]."thread.php?lng=".$lng."&pg=".$pgview."&cat=".$catthread;
		    $body .= '">';
		    $body .= $site[3]."thread.php?lng=".$lng."&pg=".$pgview."&cat=".$catthread;
		    $body .= '</a><br /><br />';
		    $body .= $web348."<br />".$user[0];
		    eMailHtmlTo($sujet, $body, $to);
		  }
  	}
  	if (($typ == TYP_FORUM || $typ == TYP_THREAD) && ($serviz[18] == "on")) {
		$dbworkcat = ReadDBFields(DBFORUMCAT);
		$catok = 0;
		for ($i = 0; $i < count($dbworkcat); $i++) {
		  $prcat = explode(',', $dbworkcat[$i][0]);
		  if ($prcat[0] == $catforum) {
			$catok = 1;
		  }
		}
		if ($catok == 0) {
		}
	}
	 if ($typ == TYP_NEWS || $typ == TYP_BLOG || $typ == TYP_GUESTBK || $typ == TYP_FORUM || $typ == TYP_THREAD || $typ == TYP_RECO || $typ == TYP_REACT || $typ == TYP_REBLOG) {
		if ($typ == TYP_THREAD) {
		  $data[0] = TYP_FORUM;
		}
		else {
		  $data[0] = $typ;
		}
		$data[1] = "";
		if (!empty($site[5]) && $typ == TYP_NEWS) {
		 $data[2] = "i";
		 $ok = $web48;
		}
		elseif (!empty($site[30]) && $typ == TYP_BLOG) {
		 $data[2] = "i";
		 $ok = $web48;
		}
		elseif ($serviz[12] && $typ == TYP_GUESTBK) {
		  if ($serviz[40]) {
			$data[2] = "i";
			$ok = $web48;
		  }
		  else {
			$data[2] = "a";
			$ok = "";
		  }
		}
		elseif ($serviz[13] && (($typ == TYP_FORUM) || ($typ == TYP_THREAD))) {
		  if ($serviz[41]) {
			$data[2] = "i";
			$ok = $web48;
		  }
		  else {
			$data[2] = "a";
			$ok = "";
		  }
		}
		elseif ($serviz[29] == "ok" && $typ == TYP_REACT) {
			$data[2] = "i";
			$ok = $web48;
		}
		elseif ($serviz[57] == "ok" && $typ == TYP_REBLOG) {
			$data[2] = "i";
			$ok = $web48;
		}
    else {
      $data[2] = "a";
      $ok = "";
    }
    $data[3] = "";
    $data[4] = "";
    $data[5] = $pseudo;
    $data[6] = $pemail;
    if ($typ == TYP_GUESTBK) {
      $dbwork = SelectDBFields($typ,"","");
      @rsort($dbwork);
      $id = $dbwork[0][1];
      if (!empty($id)) {
      ReadDoc(DBBASE.$id);
      $data[7] = $fielda1+1;
      }
      else {
        $data[7] = 1;
      }
    }
   elseif ($typ == TYP_BLOG) {
      $data[7] = $rub;
    }
    elseif ($typ == TYP_REACT) {
      $dbwork = ReadDBFields(DBREACT);
      $maxreact = 1;
      for ($i = 0; $i < count($dbwork); $i++) {
        if ($dbwork[$i][1] == $pg) {
          $maxreact++;
        }
      }
      $data[7] = $maxreact;
    }
    elseif ($typ == TYP_REBLOG) {
      $dbwork = ReadDBFields(DBREBLOG);
      $maxreact = 1;
      for ($i = 0; $i < count($dbwork); $i++) {
        if ($dbwork[$i][1] == $pg) {
          $maxreact++;
        }
      }
      $data[7] = $maxreact;
    }
    elseif ($typ == TYP_FORUM) {
      $catthread = empty($catthread) ? $catforum : $catthread;
      if ($serviz[41]) {
        $data[7] = 1;
        $dbwork = SelectDBFieldsByNotStatus(SelectDBFields(TYP_FORUM, "", ""), "d");
        if (count($dbwork) > 0) {
          $data[7] = ReadCounter(DBFORUMCOUNTER)+1;
          WriteCounter(DBFORUMCOUNTER,$data[7]);
        }
      }
      else {
        $dbthrd = array();
        $dbwork = ReadDBFields(DBFORUM);
        for ($i = 0; $i < count($dbwork); $i++) {
          $dbthrd[] = $dbwork[$i][1];
        }
        @rsort($dbthrd);
        if (!empty($dbthrd)) {
          $data[7] = $dbthrd[0]+1;
          WriteCounter(DBFORUMCOUNTER,$data[7]);
        }
        else {
          $data[7] = ReadCounter(DBFORUMCOUNTER)+1;
          WriteCounter(DBFORUMCOUNTER,$data[7]);
        }
      }
    }
    elseif ($typ == TYP_THREAD) {
      $data[7] = $num;
    }
    else {
    $data[7] = "";
    }
    if ($typ == TYP_FORUM) {
      $data[8] = "0";
    }
    elseif ($typ == TYP_THREAD) {
      if ($serviz[41]) {
        $data[8] = 1;
        $dbwork = SelectDBFieldsByNotStatus(SelectDBFields(TYP_FORUM, "", ""), "d");
        rsort($dbwork);
        if (count($dbwork) > 0) {
          for ($i=0; $i<count($dbwork); $i++) {
           ReadDoc(DBBASE.$dbwork[$i][1]);
           if ($fielda1 == $data[7]) {
             $data[8] = $fielda2 + 1;
              break;
            }
          }
        }
      }
      else {
        $dbthrd = array();
        $dbwork = ReadDBFields(DBFORUM);
        $j = 0;
  	    for ($i = 0; $i < count($dbwork); $i++) {
          if ($dbwork[$i][1] == $num) {
            $j = $dbwork[$i][7];
            break;
          }
        }
        $data[8] = $j+1;
      }
    }
    elseif ($typ == TYP_BLOG) {
      $data[8] = addslashes(stripslashes($rub));
    }
    elseif ($typ == TYP_REACT || $typ == TYP_REBLOG) {
      $data[8] = $pg;
    }
    else {
      $data[8] = "";
    }
    if ($typ == TYP_GUESTBK) {
      if (trim($purl) == "http://") {
        $purl = "";
      }
      $data[9] = $purl;
      $data[10] = "";
      $data[11] = PutBR($ptxt);
      $data[12] = "";
    }
    elseif ($typ == TYP_FORUM) {
      $data[9] = $ptit;
      $data[10] = $catforum;
      if (!empty($userprefs[6])) {
        $data[11] = PutBR($ptxt)."<p align=\"right\"><br />".$userprefs[6]."</p>";
      }
      else {
        $data[11] = PutBR($ptxt);
      }
      $data[12] = $userprefs[8];
      if (!empty($userprefs[1])) {
        $idcountmsg = ReadCounter(FILECOUNTMSG.$pseudo.DBEXT) + 1;
      }
      else {
        $idcountmsg="v";
      }
      $data[14] = $idcountmsg;
      $data[15] = $userprefs[9];
      $data[16] = $replymail;
      $data[17] = "";
    }
    elseif ($typ == TYP_THREAD) {
      $data[9] = "";
	  $data[10] = $catforum; 

      if (!empty($userprefs[6])) {
        $data[11] = PutBR($ptxt)."<p align=\"right\"><br />".$userprefs[6]."</p>";
      }
      else {
        $data[11] = PutBR($ptxt);
      }
      $data[12] = $userprefs[8];
      if (!empty($userprefs[1])) {
        $idcountmsg = ReadCounter(FILECOUNTMSG.$pseudo.DBEXT) + 1;
      }
      else {
        $idcountmsg="v";
      }
      $data[14] = $idcountmsg;
      $data[15] = $userprefs[9];
      $data[16] = $replymail;
      $data[17] = "";
    }
    elseif ($typ == TYP_RECO) {
      $data[9] = $pfmail;
      $data[10] = "";
      $data[11] = PutBR($ptxt);
      $data[12] = "";
    }
    elseif ($typ == TYP_REACT || $typ == TYP_REBLOG) {
      $data[9] = "";
      $data[10] = "";
      $data[11] = PutBR($ptxt);
      $data[12] = "";
    }
    else {
      if ($site[5] == "0") {
        $data[9] = $ptit;
        $data[10] = $ptit;
        $data[11] = PutBR($ptxt);
        $data[12] = PutBR($ptxt);
      }
      else {
        if ($lng == $lang[0]) {
          $data[9] = $ptit;
          $data[10] = "";
          $data[11] = PutBR($ptxt);
          $data[12] = "";
        }
        else {
          $data[9] = "";
          $data[10] = $ptit;
          $data[11] = "";
          $data[12] = PutBR($ptxt);
        }
      }
    }
    $data[13] = $pehide;
    if ($typ != TYP_FORUM && $typ != TYP_THREAD) {
      $data[14] = "";
      $data[15] = "";
    }
    if ($typ == TYP_REACT || $typ == TYP_REBLOG) {
      $data[17] = $group; /// added for groups
    }
    if ($typ == TYP_BLOG) {
      include_once (CHEMIN.'inc/func_groups.php');
      if (CheckGroup($rub, $pseudo)) {
        $data[17] = $rub;
      }
    }
    if (($typ == TYP_FORUM) || ($typ == TYP_THREAD) && (!empty($userprefs[1]))) {
      $idcountmsg = ReadCounter(FILECOUNTMSG.$pseudo.DBEXT) + 1;
      WriteCounter(FILECOUNTMSG.$pseudo.DBEXT,$idcountmsg);
    }
    if (($serviz[41]) && (($typ == TYP_FORUM) || ($typ == TYP_THREAD))) {
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
      $fieldc1 = addslashes(stripslashes(replaceimg(PutHR(PutBR($data[11])))));
      $fieldc2 = addslashes(stripslashes($data[12]));
      $fieldd1 = addslashes(stripslashes($data[13]));
      $fieldd2 = $idcountmsg;
      $fieldweb = $data[15];
      $fieldmail = $data[16];
      $fieldmod = $data[17];
      WriteDoc();
    }
    else {
      $id = ActionOnFields("add",$data);
    }
    $ok = $web46.(empty($ok) ? '' : "<br />".$ok);
  }
  else {
    $ok = $web47;
  }
  if ($typ == TYP_MAIL) {
    $ok = $web46;
  }
  }

  else { // cas modif thread
  include("inc/mod_thread.inc");
   $ok = $web46;
  }

  $datefrmt = FormatDate(GetCurrentDateTime());
  if ($supervision[2] == "on" && $typ == TYP_NEWS) {
    $eSub = $site[0]." ".$web106;
    $eMsg = $site[0]." - ".$web106.", ".$web104." ".$datefrmt.".<br />";
    $eMsg .= $web107.stripslashes($pseudo)." (".stripslashes($pemail).").<br />";
    $eMsg .= $web108.stripslashes($ptit)."<br />";
    $eMsg .= '<hr />'.$web109.'<br />'.ForceToAbsolute(stripslashes($ptxt));
    $eMsg .= "<hr />".$web349." : ".$web354.$id;
    $eMsg .= "<br />".$web360.'<a href="'.$site[3]."news.php?lng=".$lng."&pg=".$id.'">'.$site[3]."news.php?lng=".$lng."&pg=".$id.'</a>';
    $eMsg .= "<br />".$web350.'<a href="'.$site[3]."admin/admin.php?lng=".$lng."&pg=news&form=2&id=".$id.'">'.$site[3]."admin/admin.php?lng=".$lng."&pg=news&form=2&id=".$id.'</a>';
    if ($site[5] == "1") {
      $eMsg .= "<br />".$web351.'<a href="'.$site[3]."admin/admin.php?lng=".$lng."&pg=news&act=a&id=".$id.'">'.$site[3]."admin/admin.php?lng=".$lng."&pg=news&act=a&id=".$id.'</a>';
    } else {
      $eMsg .= "<br />".$web352.'<a href="'.$site[3]."admin/admin.php?lng=".$lng."&pg=news&act=i&id=".$id.'">'.$site[3]."admin/admin.php?lng=".$lng."&pg=news&act=i&id=".$id.'</a>';
    }
    $eMsg .= "<br />".$web353.'<a href="'.$site[3]."admin/admin.php?lng=".$lng."&pg=news&del=".$id.'">'.$site[3]."admin/admin.php?lng=".$lng."&pg=news&del=".$id.'</a>';
    $eMsg .= "<hr />".$infos;
    eMailHtmlTo($eSub,$eMsg,"");
  }
  if ($supervision[8] == "on" && $typ == TYP_BLOG) {
    $eSub = $site[0]." ".$web396;
    $eMsg = $site[0]." - ".$web396.", ".$web104." ".$datefrmt.".<br />";
    $eMsg .= $web107.stripslashes($pseudo)." (".stripslashes($pemail).").<br />";
    $eMsg .= $web108.stripslashes($ptit)."<br />";
    $eMsg .= '<hr />'.$web109.'<br />'.ForceToAbsolute(stripslashes($ptxt));
    $eMsg .= "<hr />".$web349." : ".$web354.$id;
    $eMsg .= "<br />".$web360.'<a href="'.$site[3]."blog.php?lng=".$lng."&pg=".$id.'">'.$site[3]."blog.php?lng=".$lng."&pg=".$id.'</a>';
    $eMsg .= "<br />".$web350.'<a href="'.$site[3]."admin/admin.php?lng=".$lng."&pg=blog&form=2&id=".$id.'">'.$site[3]."admin/admin.php?lng=".$lng."&pg=blog&form=2&id=".$id.'</a>';
    if ($site[30] == "1") {
    $eMsg .= "<br />".$web351.'<a href="'.$site[3]."admin/admin.php?lng=".$lng."&pg=blog&act=a&id=".$id.'">'.$site[3]."admin/admin.php?lng=".$lng."&pg=blog&act=a&id=".$id.'</a>';
    } else {
    $eMsg .= "<br />".$web352.'<a href="'.$site[3]."admin/admin.php?lng=".$lng."&pg=blog&act=i&id=".$id.'">'.$site[3]."admin/admin.php?lng=".$lng."&pg=blog&act=i&id=".$id.'</a>';
    }
    $eMsg .= "<br />".$web353.'<a href="'.$site[3]."admin/admin.php?lng=".$lng."&pg=blog&del=".$id.'">'.$site[3]."admin/admin.php?lng=".$lng."&pg=blog&del=".$id.'</a>';
    $eMsg .= "<hr />".$infos;
    eMailHtmlTo($eSub,$eMsg,"");
  }
  elseif ($supervision[9] == "on" && $typ == TYP_REBLOG) {
    $eSub = $site[0]." ".$web379." ".$web381;
    $eMsg = $site[0]." - ".$web379." ".$web381.", ".$web104." ".$datefrmt.".<br />";
    $eMsg .= $web107.stripslashes($pseudo)." (".stripslashes($pemail).").<br />";
    ReadDoc(DBBASE.$pg);
    $eMsg .= $web183." - ".$fieldb1."<br />";
    $eMsg .= '<hr />'.$web109.'<br />'.ForceToAbsolute(stripslashes($ptxt));
    $eMsg .= "<hr />".$web349." : ".$web39.$data[7]." - ".$web355.$fileid." - ".$web356.$id;
    $eMsg .= "<br />".$web360.'<a href="'.$site[3]."blog.php?lng=".$lng."&pg=".$fileid."&reblog=".$id.'">'.$site[3]."blog.php?lng=".$lng."&pg=".$fileid."&reblog=".$id.'</a>';
    $eMsg .= "<br />".$web350.'<a href="'.$site[3]."admin/admin.php?lng=".$lng."&pg=reblog&form=2&id=".$id.'">'.$site[3]."admin/admin.php?lng=".$lng."&pg=reblog&form=2&id=".$id.'</a>';
    if ($serviz[57] == "ok") {
    $eMsg .= "<br />".$web351.'<a href="'.$site[3]."admin/admin.php?lng=".$lng."&pg=reblog&act=a&id=".$id.'">'.$site[3]."admin/admin.php?lng=".$lng."&pg=reblog&act=a&id=".$id.'</a>';
    } else {
    $eMsg .= "<br />".$web352.'<a href="'.$site[3]."admin/admin.php?lng=".$lng."&pg=reblog&act=i&id=".$id.'">'.$site[3]."admin/admin.php?lng=".$lng."&pg=reblog&act=i&id=".$id.'</a>';
    }
    $eMsg .= "<br />".$web353.'<a href="'.$site[3]."admin/admin.php?lng=".$lng."&pg=reblog&del=".$id.'">'.$site[3]."admin/admin.php?lng=".$lng."&pg=reblog&del=".$id.'</a>';
    $eMsg .= "<hr />".$infos;
    eMailHtmlTo($eSub,$eMsg,"");
  }
  elseif ($supervision[3] == "on" && $typ == TYP_GUESTBK) {
    $eSub = $site[0]." ".$web113;
    $eMsg = $site[0]." - ".$web113.", ".$web104." ".$datefrmt.".<br />";
    $eMsg .= $web107.stripslashes($pseudo)." (".stripslashes($pemail).").<br />";
    $eMsg .= $web112.stripslashes($purl)."<br />";
    $eMsg .= '<hr />'.$web109.'<br />'.ForceToAbsolute(stripslashes($ptxt));
    $eMsg .= "<hr />".$web349." : ".$web39.$data[7]." - ".$web354.$id;
    $eMsg .= "<br />".$web360.'<a href="'.$site[3]."guestbk.php?lng=".$lng."&pg=".$id.'">'.$site[3]."guestbk.php?lng=".$lng."&pg=".$id.'</a>';
    $eMsg .= "<br />".$web350.'<a href="'.$site[3]."admin/admin.php?lng=".$lng."&pg=guestbk&form=2&id=".$id.'">'."admin/admin.php?lng=".$lng."&pg=guestbk&form=2&id=".$id.'</a>';
    if ($serviz[40] != "") {
      $eMsg .= "<br />".$web351.'<a href="'.$site[3]."admin/admin.php?lng=".$lng."&pg=guestbk&act=a&id=".$id.'">'."admin/admin.php?lng=".$lng."&pg=guestbk&act=a&id=".$id.'</a>';
    } else {
      $eMsg .= "<br />".$web352.'<a href="'.$site[3]."admin/admin.php?lng=".$lng."&pg=guestbk&act=i&id=".$id.'">'."admin/admin.php?lng=".$lng."&pg=guestbk&act=i&id=".$id.'</a>';
    }
    $eMsg .= "<br />".$web353.'<a href="'.$site[3]."admin/admin.php?lng=".$lng."&pg=guestbk&del=".$id.'">'."admin/admin.php?lng=".$lng."&pg=guestbk&del=".$id.'</a>';
    $eMsg .= "<hr />".$infos;
    eMailHtmlTo($eSub,$eMsg,"");
  }
  elseif ($supervision[6] == "on" && $typ == TYP_REACT) {
    $eSub = $site[0]." ".$web182;
    $eMsg = $site[0]." - ".$web182.", ".$web104." ".$datefrmt.".<br />";
    $eMsg .= $web107.stripslashes($pseudo)." (".stripslashes($pemail).").<br />";
    ReadDoc(DBBASE.$pg);
    $eMsg .= $web183." - ".$fieldb1."<br />";
    $eMsg .= '<hr />'.$web109.'<br />'.ForceToAbsolute(stripslashes($ptxt));
    $eMsg .= "<hr />".$web349." : ".$web39.$data[7]." - ".$web355.$fileid." - ".$web356.$id;
    $eMsg .= "<br />".$web360.'<a href="'.$site[3]."articles.php?lng=".$lng."&pg=".$fileid."&react=".$id.'">'.$site[3]."articles.php?lng=".$lng."&pg=".$fileid."&react=".$id.'</a>';
    $eMsg .= "<br />".$web350.'<a href="'.$site[3]."admin/admin.php?lng=".$lng."&pg=react&form=2&id=".$id.'">'.$site[3]."admin/admin.php?lng=".$lng."&pg=react&form=2&id=".$id.'</a>';
    if ($serviz[29] == "ok") {
    $eMsg .= "<br />".$web351.'<a href="'.$site[3]."admin/admin.php?lng=".$lng."&pg=react&act=a&id=".$id.'">'.$site[3]."admin/admin.php?lng=".$lng."&pg=react&act=a&id=".$id.'</a>';
    } else {
    $eMsg .= "<br />".$web352.'<a href="'.$site[3]."admin/admin.php?lng=".$lng."&pg=react&act=i&id=".$id.'">'.$site[3]."admin/admin.php?lng=".$lng."&pg=react&act=i&id=".$id.'</a>';
    }
    $eMsg .= "<br />".$web353.'<a href="'.$site[3]."admin/admin.php?lng=".$lng."&pg=react&del=".$id.'">'.$site[3]."admin/admin.php?lng=".$lng."&pg=react&del=".$id.'</a>';
    $eMsg .= "<hr />".$infos;
    eMailHtmlTo($eSub,$eMsg,"");
  }
  elseif (($supervision[4] == "on" || $supervision[10] == "on") && ($typ == TYP_FORUM || $typ == TYP_THREAD)) {
    $eSub = $site[0]." ".$web114;
    $eMsg = $site[0]." - ".$web114.", ".$web104." ".$datefrmt.".<br />";
    $eMsg .= $web107.stripslashes($pseudo)." (".stripslashes($pemail).").<br />";
    if ($serviz[18] == "on") {
      $dbforcat = ReadDBFields(DBFORUMCAT);
      for ($i = 0; $i < count($dbforcat); $i++) {
		$prcat = explode(',', $dbforcat[$i][0]);
        if ($catforum == $prcat[0]) {
	        if ($lng == $lang[0]) {
		  	    $eMsg .= $web130." : ".$dbforcat[$i][1];
			    }
			    else {
            $eMsg .= $web130." : ".$dbforcat[$i][2];
		      }
		      break;
        }
      }
    }
    if ($typ == TYP_FORUM) {
      $eMsg .= " - ".$web110."<br />";
      $eMsg .= $web108.stripslashes($ptit)."<br />";
    }
    else {
      $eMsg .= " - ".$web111."<br />";
    }
    $eMsg .= '<hr />'.$web109.'<br />'.ForceToAbsolute(stripslashes($ptxt));
    $eMsg .= "<hr />".$web349." : ".$web63.$data[7]." - ".$web354.$fileid;
    $eMsg .= "<br />".$web360.'<a href="'.$site[3]."thread.php?lng=".$lng."&thrd=".$data[7].'&cat='.$catthread.($data[8]==0? "" : "&id=".ceil($data[8]/$serviz[20]))."#".$data[8].'">'.$site[3]."thread.php?lng=".$lng."&thrd=".$data[7].'&cat='.$catthread.($data[8]==0? "" : "&id=".ceil($data[8]/$serviz[20]))."#".$data[8].'</a>';
    $eMsg .= "<br />".$web350.'<a href="'.$site[3]."admin/admin.php?lng=".$lng."&pg=forum&form=2&id=".$fileid.'&cat='.$catthread.'">'.$site[3]."admin/admin.php?lng=".$lng."&pg=forum&form=2&id=".$fileid.'</a>';
    if ($serviz[41] != "") {
      $eMsg .= "<br />".$web351.'<a href="'.$site[3]."admin/admin.php?lng=".$lng."&pg=forum&act=a&id=".$fileid.'&cat='.$catthread.'">'.$site[3]."admin/admin.php?lng=".$lng."&pg=forum&act=a&id=".$fileid.'</a>';
    } else {
      $eMsg .= "<br />".$web352.'<a href="'.$site[3]."admin/admin.php?lng=".$lng."&pg=forum&act=i&id=".$fileid.'&cat='.$catthread.'">'.$site[3]."admin/admin.php?lng=".$lng."&pg=forum&act=i&id=".$fileid.'</a>';
    }
    $eMsg .= "<br />".$web353.'<a href="'.$site[3]."admin/admin.php?lng=".$lng."&pg=forum&del=".$fileid.'">'.$site[3]."admin/admin.php?lng=".$lng."&pg=forum&del=".$fileid.'</a>';
    $eMsg .= "<hr />".$infos;

    if ($supervision[4] == "on") { eMailHtmlTo($eSub,$eMsg,"");} // message administrateur 
// si l'administrateur l'a demandé,
// envoi un message à TOUS les modérateurs qui sont aussi administrateurs du forum,
// lorsqu'un message ou une réponse est envoyé sur le forum 
	  if ($supervision[10] == "on") {
	  	$cpl_droits = ReadDBFields(DBADMIN);
			for ($cpl_i = 0; $cpl_i < count($cpl_droits); $cpl_i++) {
				if ($cpl_droits[$cpl_i][1] == "modo" && $cpl_droits[$cpl_i][2] == "on") {
					$cpl_user = ReadDBFields(USEREP.$cpl_droits[$cpl_i][0].DBEXT);
					$cpl_to = trim($cpl_user[1][2])." <".trim($cpl_user[1][3]).">";      
					$cpl_from = $site[0]." <".$user[1].">"; 
					eMailHtmlTo($eSub,$eMsg,$cpl_to,$cpl_from); 
    	  }
			}
		}
	}
  elseif ($typ == TYP_RECO) {
    $eSub = $web125." ".$pseudo;
    $eMsg = $web125." ".$pseudo.", ".$web104." ".$datefrmt.".<br /><br />";
    $eMsg .= $pseudo." - <a href=\"mailto:".$pemail."\">".stripslashes($pemail)."</a> - ".$web126;
    $eMsg .= " ".$site[0]." (<a href='".$site[3]."'>".$site[3]."</a>).<br />";
    $eMsg .= $web127." - <a href='mailto:".$pemail."'>".stripslashes($pemail)."</a> - ".$web128."<br /><br />";
    $eMsg .= $web129." ".$pseudo.":<br />";
    $eMsg .= '<hr />'.ForceToAbsolute(stripslashes($pmess));
    eMailHtmlTo($eSub,$eMsg,$pfmail);
  }
  elseif ($typ == TYP_MAIL) {
    $eSub = $ptit;
    $eMsg = $site[0]." - ".$web330." ".$pseudo." - <a href=\"mailto:".$pemail."\">".stripslashes($pemail)."</a> - ".$web104." ".$datefrmt.".<hr />";
    $eMsg .= "<br />".ForceToAbsolute(stripslashes($pmess));
    eMailHtmlTo($eSub,$eMsg,$pfmail,$pemail);
  }
}
}
else {
  $antispam = md5(uniqid(rand()));
  $antispams = ReadDBFields(DBANTISPAM);
  $timestamp = getmicrotime();
  array_push($antispams, array($antispam, $REMOTE_ADDR, $typ, $timestamp));
  $timestamp -= $serviz[52] * 60;
  while($antispams[0][3] < $timestamp) array_shift($antispams);
  if (count($antispams) > $serviz[51]) array_shift($antispams);
  WriteDBFields(DBANTISPAM, $antispams);
}
if (!empty($userprefs[1])) {
  $pseudo = $userprefs[1];
}
if (!empty($userprefs[2])) {
  $pemail = $userprefs[2];
}
if ($typ == TYP_GUESTBK) {
  $title = $web41;
}
elseif ($typ == TYP_NEWS) {
  $title = $web4;
}
elseif ($typ == TYP_BLOG) {
  $title = $web386;
}
elseif ($typ == TYP_FORUM) {
  $title = $web19;
}
elseif ($typ == TYP_RECO) {
  $title = $web124;
}
elseif ($typ == TYP_REACT) {
  $title = $web182;
}
elseif ($typ == TYP_REBLOG) {
  $title = $web380;
}
elseif ($typ == TYP_MAIL) {
  $title = $web215."  &nbsp;".$web11;
}
elseif ($mod != "") {
  $title = $web308."  ".$web334;
}
else {
  $title = $web65;
}
$topmess = $title;

switch ($typ){
case TYP_THREAD :
case TYP_FORUM :
if ($userprefs[3] =="" || $userprefs[3] == "LR") $userprefs[3] = "L";
$widepage = $forum[3];
break;
case TYP_BLOG :
case TYP_REBLOG :
if ($userprefs[3] == "" || $userprefs[3] == "LR") $userprefs[3] = "L";
$widepage = $serviz[58];
default:
}
include("inc/hpage.inc");
htable($title, "100%");

  ?>
  <script language="javascript" type="text/javascript">
  var clic = 0;
  function VerifyForm() {
    var sto = '';
    var messok = '';
    var erreur = false;
    var largeur = 300;
    var progbar = '<?php echo $site[28]; ?>';

    regexp = /^[a-zA-Z0-9_]{2,20}$/;
    if (!regexp.test(document.rapporter.pseudo.value)) {
      sto += '  - <?php echo addslashes($web266); ?>\n';
      erreur = true;
    }
	regexp = /^[-a-z0-9!#$%&\'*+\\/=?^_`{|}~]+(\.[-a-z0-9!#$%&\'*+\\/=?^_`{|}~]+)*@(([a-z0-9à-ö]([-a-z0-9à-ö]*[a-z0-9à-ö]+)?){1,63}\.)+([a-z0-9]([-a-z0-9]*[a-z0-9]+)?){2,63}$/i;
    if (!regexp.test(document.rapporter.pemail.value)) {
      sto += '  - <?php echo addslashes($web42); ?>\n';
      erreur = true;
    }
    if (!regexp.test(document.rapporter.pfmail.value)) {
      sto += '  - <?php echo addslashes($web122); ?>\n';
      erreur = true;
    }
<?php
if ($mod != "up" || $mod != "top"){
  echo validJSCodePGEditor("rapporter", "ptxt", "validation");
  echo '
	if (!validation) {
		sto += "  - '.addslashes($web43).'\n";
		erreur = true;
    }
  ';
}
?>
    if (document.rapporter.ptit.value.search(/\w/) == -1) {
      sto += '  - <?php echo addslashes($web123); ?>\n';
    erreur = true;
    }
<?php
if ($typ == TYP_GUESTBK) {
  echo '
	regexp = /(http:\/\/|https:\/\/)?(www.)?(([a-zA-Z0-9à-ö-]){2,}\.){1,4}([a-zA-Zà-ö]){2,6}(\/([a-zA-Zà-ö-_\/\.0-9#:?=&;,]*)?)?/;
    if ((document.rapporter.purl.value != "") && (document.rapporter.purl.value != "http://")) { 
	  if (!regexp.test(document.rapporter.purl.value)) {
        sto += "  - '.addslashes($web229).'\n";
        erreur = true;
      }
	}
  ';
}
?>
    if (erreur) {
      sto = '<?php echo addslashes($web44); ?>\n' + sto;
      alert(sto);
	  return false;
    }
    else {
      clic++;
      var messok = '<?php echo $site[27]; ?>';
      if (clic == 1) {
         return true;
      }
      else {
         sto = '<?php echo addslashes($web220); ?>' + sto;
         alert(sto);
		 return false;
      }
    }
  }
</script>
  <?php
if ($typ == TYP_NEWS && $members[0]=="on" && $members[8]=="on" && $userprefs[1]=="") {
  echo "<p align=\"center\">".$web342."</p><br />";
  echo "<p align=\"center\">[ <a href=\"".CHEMIN."user.php?lng=".$lng."\">".$web343."</a> ]</p><br />";
}
elseif ($typ == TYP_BLOG && $members[0]=="on" && $members[16]=="on" && $userprefs[1]=="") {
  echo "<p align=\"center\">".$web342."</p><br />";
  echo "<p align=\"center\">[ <a href=\"".CHEMIN."user.php?lng=".$lng."\">".$web343."</a> ]</p><br />";
}
elseif ($typ == TYP_GUESTBK && $members[0]=="on" && $members[9]=="on" && $userprefs[1]=="") {
  echo "<p align=\"center\">".$web342."</p><br />";
  echo "<p align=\"center\">[ <a href=\"".CHEMIN."user.php?lng=".$lng."\">".$web343."</a> ]</p><br />";
}
elseif (($typ == TYP_FORUM || $typ ==TYP_THREAD) && $members[0]=="on" && ($members[10]=="on" || $members[5]=="on") && $userprefs[1]=="" ) {
  echo "<p align=\"center\">".$web342."</p><br />";
  echo "<p align=\"center\">[ <a href=\"".CHEMIN."user.php?lng=".$lng."\">".$web343."</a> ]</p><br />";
}
elseif ($typ == TYP_REACT && $members[0]=="on" && ($members[11]=="on" || $members[1]=="on") && $userprefs[1]=="" ) {
  echo "<p align=\"center\">".$web342."</p><br />";
  echo "<p align=\"center\">[ <a href=\"".CHEMIN."user.php?lng=".$lng."\">".$web343."</a> ]</p><br />";
}
elseif ($typ == TYP_REBLOG && $members[0]=="on" && ($members[17]=="on" || $members[1]=="on") && $userprefs[1]=="" ) {
  echo "<p align=\"center\">".$web342."</p><br />";
  echo "<p align=\"center\">[ <a href=\"".CHEMIN."user.php?lng=".$lng."\">".$web343."</a> ]</p><br />";
}
else {
  if ($ok == $web45) {
  /// début modif forum privé
    $acces = "ok";
    if ($typ == TYP_FORUM || $typ == TYP_THREAD) {
      if (!empty($pg) && $typ == TYP_THREAD) {
        $dbpg = SelectDBForumByNum(ReadDBFields(DBFORUM),$num);
        if (count($dbpg) != 0) {
          $cat = $dbpg[0][12];
        }
      }
      if (preg_match('/^pr/i', $cat)) {
        $acces = "no";
        if ($userprefs[1] != "") {
          include_once (CHEMIN.'inc/func_groups.php');
          if (CheckGroup($cat, $userprefs[1])) $acces ="ok";
        }
      }
    }
    if ($acces == "no") {
      echo "<p style='text-align:center;font-weight:bold;padding-bottom:48px;'><br />".$web443."</strong><br /></p>";
    } else {
  /// fin modif forum privé
    ?>
    <p align="center"><strong><?php echo $ok ?></strong></p>
    <form name="rapporter" action="postguest.php" method="post" onsubmit="return VerifyForm(); return false;">
    <input type="hidden" name="lng" value="<?php echo $lng; ?>" />
    <input type="hidden" name="typ" value="<?php echo $typ; ?>" />
    <input type="hidden" name="antispam" value="<?php echo $antispam; ?>" />
    <input type="hidden" name="add" value="1" />
    <?php
    if ($typ == TYP_FORUM && !empty($cat)) {
      ?>
	  <input type="hidden" name="cat" value="<?php echo $cat; ?>" />
      <input type="hidden" name="catforum" value="<?php echo $cat; ?>" />
      <?php
    }
    if ($typ == TYP_THREAD) {
      ?>
   	  <input type="hidden" name="cat" value="<?php echo $cat; ?>" />
      <input type="hidden" name="catforum" value="<?php echo $cat; ?>" />
      <input type="hidden" name="num" value="<?php echo $num; ?>" />
      <?php
    }
    if ($typ != TYP_RECO && $typ != TYP_MAIL) {
      ?>
      <input type="hidden" name="pfmail" value="pf@mail.fr" />
      <?php
    }
    if ($typ == TYP_MAIL) {
      ?>
      <input type="hidden" name="pfmail" value="<?php echo $user[1]; ?>" />
      <?php
    }
    if ($typ == TYP_GUESTBK || $typ == TYP_RECO || $typ == TYP_THREAD || $typ == TYP_REACT  || $typ == TYP_REBLOG) {
      ?>
      <input type="hidden" name="ptit" value="ptit" />
      <?php
    }
    if ($typ == TYP_REACT || $typ == TYP_REBLOG) {
      ?>
      <input type="hidden" name="pg" value="<?php echo $pg; ?>" />
      <?php
    }
    if ($typ != TYP_GUESTBK) {
      ?>
      <input type="hidden" name="purl" value="http://fake" />
      <?php
    }
    ?>
    <table cellspacing="0" cellpadding="0" align="center" width="98%" border="0" summary="">
    <tr><td align="center"><p><?php echo $web49; ?></p></td></tr>
    <tr><td align="center"><input class="texte" type="text" name="pseudo" value="<?php echo $pseudo; ?>" size="40" maxlength="20" /></td></tr>
    <tr><td align="center"><p><?php echo $web50; ?></p></td></tr>
    <tr><td align="center"><input class="texte" type="text" name="pemail" value="<?php echo $pemail; ?>" size="40" /></td></tr>
    <?php
    if ($typ != TYP_RECO && $typ != TYP_MAIL) {
      ?>
      <tr><td align="center"><?php echo $web115; ?>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type="checkbox" name="pehide" /></td></tr>
      <tr><td align="center"><?php echo $web30; ?></td></tr>
      
      <?php
    }
    if ($typ == TYP_MAIL) {
      ?>
      <tr><td align="center" colspan="2"><p><?php echo $web281; ?></p></td></tr>
      <tr><td align="center" style="width:100%;"><input class="texte" type="text" name="ptit" value="<?php echo $ptit; ?>" size="45" /></td></tr>
      <tr><td align="center" colspan="2"><p><?php echo $web56; ?></p></td></tr>
      <?php
    }
    if ($typ == TYP_NEWS) {
      ?>
      <tr><td align="center" colspan="2"><p><?php echo $web54; ?></p></td></tr>
      <tr><td align="center" style="width:100%;"><input class="texte" type="text" name="ptit" value="<?php echo $ptit; ?>" size="45" /></td></tr>
      <tr><td align="center" colspan="2"><p><?php echo $web55; ?></p></td></tr>
      <?php
    }
    if ($typ == TYP_BLOG) {
      ?>
      <tr><td align="center" colspan="2"><p><?php echo $web21; ?></p></td></tr>
      <tr><td align="center" style="width:100%;">
      <?php
      $dbw = ReadDBFields(DBBLOG);
      sort($dbw);
      if (!empty($dbw)) {
        echo "<p><select name='rub' style='width:240px;'>";
	      $j = ($lng == $lang[0])? 0 : 1 ;
        $bi_rub = array();
        $curr_rub = "";
        $k = 0;
        for ($i = 0; $i < count($dbw); $i++) {
          if ($dbw[$i][$j] != "" && $dbw[$i][$j] != $curr_rub) {
            $bi_rub[$k] = $dbw[$i][$j];
            $curr_rub = $dbw[$i][$j];
            /// début modif blog privé
            $acces = "no";
            include_once (CHEMIN.'inc/func_groups.php');
            if (CheckGroup($dbw[$i][6], $userprefs[1]) || $dbw[$i][6] == "") $acces = "ok";
            if ($acces == "ok") {
			  // correction FS#388
              echo "<option value='".$bi_rub[$k]."'".($rub==$bi_rub[$k]?' selected="selected"':'').">".$bi_rub[$k]."</option>";
			  // fin correction FS#388
              $k++;
            }
            /// fin modif blog privé
          }
        }
        echo "</select></p>";
      }
      else {
          echo "<input class=\"texte\" type=\"text\" name=\"rub\" size=\"45\" value=\"$rub\"/>";
      }
      ?>
      </td></tr>
      <tr><td align="center" colspan="2"><p><?php echo $web387; ?></p></td></tr>
      <tr><td align="center" style="width:100%;"><input class="texte" type="text" name="ptit" value="<?php echo $ptit; ?>" size="45" /></td></tr>
      <tr><td align="center" colspan="2"><p><?php echo $web388; ?></p></td></tr>
      <?php
    }
    if ($typ == TYP_REBLOG || $typ == TYP_REACT) {
      echo "<tr><td align='center'>";
      ReadDoc(DBBASE.$pg);
      $txtbl = ($lng == $lang[0])? $fieldc1 : $fieldc2 ;
      echo $web384."<br /><br />";
      echo "<div class='rep' style='width:500px; height:160px; overflow:auto; border-style:groove;text-align:left'>";
      echo stripslashes($txtbl)."</div>";
      echo "<br /><b>".$web56."</b><br /><br /></td></tr>";
    }
    if ($typ == TYP_GUESTBK) {
      ?>
      <tr><td align="center" colspan="2"><p><?php echo $web51; ?></p></td></tr>
      <tr><td align="center" style="width:100%;"><input class="texte" type="text" name="purl" size="45" value="<?php echo ($purl != '') ? $purl : "http://"; ?>" /></td></tr>
      <tr><td align="center" colspan="2"><p><?php echo $web56; ?></p></td></tr>
      <?php
    }
    if ($typ == TYP_FORUM) {
      ?>
      <tr><td align="center"><p><?php echo $web344 ?> :&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type="checkbox" name="replymail"<?php echo ($replymail!="on") ?"" : ' checked="checked"'; ?> /></p></td></tr>
      <tr><td align="center" colspan="2"><p><?php echo $web64; ?></p></td></tr>
      <tr><td align="center" style="width:100%;"><input class="texte" type="text" name="ptit" value="<?php echo $ptit; ?>" size="45" /></td></tr>
      <tr><td align="center" colspan="2"><p><?php echo $web56; ?></p></td></tr>
      <?php
    }
    if ($typ == TYP_RECO) {
      ?>
      <tr><td align="center" colspan="2"><p><br /><?php echo $web121; ?></p></td></tr>
      <tr><td align="center" style="width:100%;"><input class="texte" type="text" name="pfmail" size="40" value="<?php echo $pfmail; ?>" /></td></tr>
      <tr><td align="center" colspan="2"><p><?php echo $web56; ?></p></td></tr>
      <?php
    }
    if ($typ == TYP_THREAD) {
      if (!empty($pg)) {
        $rank = ReadDBFields(DBADMIN);
        $modadm=""; $moduser = "";
        for ($y = 0; $y < count($rank); $y++) {
          if ($rank[$y][0] == $userprefs[1] && $rank[$y][2] == "on") {
            $modadm = "yes";
            break;
          }
        }
        if ($userprefs[1] == $serviz[31]) $modadm = "yes";

        if (count(SelectDBFields(TYP_FORUM,"a",$pg)) != 0) {
          $dbtmp = ReadDBFields(DBTHREAD);
          for ($i = 0; $i < count($dbtmp); $i++) { // search topic id
            if ($dbtmp[$i][3] == $pg) {
              $idth = $dbtmp[$i][1];
              break;
            }
          }
          for ($i = 0; $i < count($dbtmp); $i++) {
            if ($dbtmp[$i][1] == $idth && $dbtmp[$i][6] != "") { // read topic
              ReadDoc(DBBASE.$dbtmp[$i][3]);
              $st = explode("#",$fieldmod);
              if ($st[0] == "c" || $st[0] == "s" || $fielda1 != $num) { // if topic closed
                if ($modadm != "yes" || $mod != "maj") {
                  ?>
                  <script language="javascript" type="text/javascript">
                  alert('<?php echo addslashes($web47); ?>');
                  window.history.back();
                  </script>
		              <?php die ('STOP !'.$web47);
                }
              }
              unset($dbtmp);
              break;
            }
          }
          ReadDoc(DBBASE.$pg);
        }
        ?>
        <tr><td align="center"><p><?php echo $web344 ?> :&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type="checkbox" name="replymail" /></p></td></tr>
		<?php
        if ($mod == "")  { // cas normal
          ?>
          <tr><td align="center" colspan="2"><p><?php echo $web141; ?> <strong><?php echo $author; ?></strong> <?php echo $web142; ?></p></td></tr>
          <tr><td align="center" colspan="2"></td></tr>
          <tr><td colspan="2"><br /><center>
          <div class="rep" style="position:relative; width:500px; height:160px; overflow:auto; border-style:groove;text-align:left">
          <?php echo stripslashes($fieldc1); ?>
          </div><br /></center>
          </td></tr>
          <?php
        }
        else { // cas maj-cloture-up...

          if (WYSIWYG && (($author == $userprefs[1]) || $modadm == "yes" || (!empty($serviz[31]) && $serviz[31]==$userprefs[1]))) {
            echo "<tr><td colspan=\"2\" align=\"center\">";
            echo "<div class=\"bord\" style=\"width:95%;padding:5px\">";
            $ptit = $fieldb1;
            $fieldc1 = str_replace(array("\n", "\r"), "", $fieldc1);
            $ptxt = addslashes(unparseCodePGEditor($fieldc1));
            if ($mod == "maj") { //cas maj
              echo "<input type=\"hidden\" name=\"mod\" value=\"maj\" />";
              $text = "<strong>".$web369." ".$web7." ".$web334."</strong><br />";
              if ($ptit != "") {$text .= "<br /><span class='rep'>".$ptit."</span><br /><br />";}
            }
            elseif ($mod == "stop") {
              echo "<input type=\"hidden\" name=\"mod\" value=\"stop\" />";
              $text = "<strong>".$web390."</strong><br /><br />";
              if ($ptit != "") {$text .= "<br /><span class='rep'>".$ptit."</span><br /><br />";}
            }
            else { //cas lock-up-top
              $text = "<strong>".$web7."  ".$web334."</strong><br /><br /><span class='rep'>".$ptit."</span><br /><br />";
              if ($mod == "lock") {
                echo "<input type=\"hidden\" name=\"mod\" value=\"lock\" /><b>".$web363."</b>&nbsp;";
              }
              else {
                if ($forum[5] != "") {
                  echo "<input type=\"radio\" name=\"mod\" value=\"up\" checked=\"checked\" /><b>".$web364." </b>&nbsp;";
                }
                if ($forum[6] != "" && $mod == "top") {
                  echo "<input type=\"radio\" name=\"mod\" value=\"top\" /> <b>".$web365."</b><br />";
                }
              }
            }
            echo $text;
            echo "<input type=\"hidden\" name=\"pg\" value=".$pg." />";
            echo "</div><br />";
            if ($mod == "stop") echo "<p><strong>".$userprefs[1]." , ".$web391."</strong></p><br />";
            echo "</td></tr>";
          }
          else {
            echo "</table><br /><br /><p align='center'>";
		        ?>
            <script language="javascript" type="text/javascript">
            alert('<?php echo addslashes($web416); ?>');
            window.history.back();
            </script>
		        <?php die ('STOP !');
          }
        }
      }
    }
    ?>
    <tr><td align="center">
    <?php
    if ($mod =="" || $mod == "maj" || $mod == "stop") { // pas d'éditeur pour lock, up et top
      ?>
      <table cellspacing="0" summary="">
      <tr><td colspan="2" align="center">
      <?php
      echo displayPGEditor('rapporter', 'ptxt', 520, 300, $ptxt);
      ?>
      </td></tr>
      </table>
      <?php
    }
    ?>
    </td></tr>
    <tr><td align="center" colspan="2"><p><br /></p><?php echo $boutonleft; ?><button type="submit" title="<?php echo $web52; ?>"><?php echo $web52; ?></button><?php echo $boutonright; ?></td></tr>
    <tr><td>&nbsp;</td></tr>
    </table>
    </form>
    <script language="javascript" type="text/javascript">
    document.rapporter.pseudo.focus();
    </script>
    <?php
    } /// modif privé
  }
  else {
    ?>
<p align="center"><strong><?php echo $ok; ?></strong></p>
    <?php
    if ($typ == TYP_NEWS) {
      $backurl = "news.php?lng=".$lng;
    }
    elseif ($typ == TYP_BLOG) {
      $backurl = "blogs.php?lng=".$lng;
    }
    elseif ($typ == TYP_REBLOG) {
      $backurl = "blog.php?lng=".$lng."&pg=".$pg;
    }
    elseif ($typ == TYP_GUESTBK) {
      $backurl = "guestbk.php?lng=".$lng;
    }
    elseif ($typ == TYP_FORUM) {
      if (!empty($catforum)) {
        $backurl = "forum.php?lng=".$lng."&cat=".$catforum;
      }
      else {
        $backurl = "forum.php?lng=".$lng;
      }
    }
    elseif ($typ == TYP_THREAD) {
      $dbwork = array();
      $dbwork = ReadDBFields(DBFORUM);
      for ($i = 0; $i < count($dbwork); $i++) {
        if ($dbwork[$i][1] == $num) {
          $catforum = $dbwork[$i][12];
        }
      }
      if (!empty($catforum)) {
        $backurl = "forum.php?lng=".$lng."&cat=".$catforum;
      }
      else {
        $backurl = "forum.php?lng=".$lng;
      }
    }
    elseif ($typ == TYP_REACT) {
      $backurl = "articles.php?lng=".$lng."&pg=".$pg;
    }
    elseif ($typ == TYP_RECO || $typ == TYP_MAIL) {
      $backurl = "index.php?lng=".$lng;
    }
    echo "<hr />
<p align='center'>[ <a href='".htmlentities($backurl, ENT_COMPAT, $charset)."'>".$web135."</a> ]</p>
";
    ?>
<script type="text/javascript" language="javascript">
  var type = '<?php echo $typ; ?>';
  var messok = '<?php echo $site[27]; ?>'; messok++;
  if (type == "<?php echo TYP_RECO; ?>" || type == "<?php echo TYP_MAIL; ?>") {
    setTimeout("window.history.go(-2);",2000*messok);
  }
  else {
    setTimeout("window.location='<?php echo $backurl; ?>';",2000*messok);
  }
</script>
    <?php
  }
}
btable();
include("inc/bpage.inc");
?>