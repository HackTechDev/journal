<?php
/*
    Thread update routine - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2008 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.6.0 (04 June 2007)       : initial release by Icare
                                    added note on bottom of corrected post (by Icare)
      v4.6.1 (02 July 2007)       : deleted bad echo of id number (thanks hpsam)
      v4.6.6 (14 April 2008)      : corrected $fieldmod value (by Icare)
                                    added values to correct empty items in supervision mails (thanks JeanMi)
      v4.6.8 (24 May 2008)        : updated supervision messages (thanks JeanMi)
                                    added $catthread, corrected code (by JeanMi)
      v4.6.21(18 October 2012)    : added subscription for maj thread (by Saxbar)								
*/

if (stristr($_SERVER["SCRIPT_NAME"], "mod_thread.inc")) {
    header("location:../index.php");
    die();
}
if (!empty($pg)) {
    $th_id = "";
    ReadDoc(DBBASE.$pg);
    $fileid = $pg;
    if ($mod == "up" ) {
        $moddate = date("YmdHi",time()+(3600*$forum[5]));
        $fieldmod =  "u#".$userprefs[1]."#".date("YmdHi");
        $web111 .= " : ".$web364;
    }
    elseif ($mod == "top" ) {
        $moddate = date("YmdHi",time()+(86400*$forum[6]));
        $fieldmod =  "t#".$userprefs[1]."#".$moddate;
        $web111 .= "  : ".$web365;
    }
    elseif ($mod == "lock" ) {
        $fieldmod =  "c#".$userprefs[1]."#".date("YmdHi");
        $web111 .= " : ".$web363;
    }
    elseif ($mod == "stop" ) {
        $fieldmod =  "s#".$userprefs[1]."#".date("YmdHi");
        $web111 .= " : ".$web363;
    }
    elseif ($mod == "maj" ) {
        $fieldmod = "";
        $web111 .= " : ".$web369;
    }
    $fieldb1 = addslashes($fieldb1);
    if ($mod == "maj") {
        $note = "<hr /><u>".$web417."</u> ".$web6." ".$userprefs[1]." ".$web7." ".FormatDate(date("YmdHi"));
        $fieldc1 = addslashes(stripslashes(replaceimg(PutHR(PutBR($ptxt))))).$note;
    } elseif ($mod == "stop") {
        $fieldc1 = addslashes(stripslashes(replaceimg(PutHR(PutBR($ptxt)))));
    } else {
        $fieldc1 = addslashes(stripslashes($fieldc1));
    }
    WriteDoc($pg);
    $data[7] = $fielda1; // n° thread
    $data[8] = $fielda2; // n° response
    if ($typ == TYP_FORUM) {
        $catthread = $fieldb2; // n° id category
    } else {
        $dbf = ReadDBFields(DBFORUM);
        for ($i = 0; $i < count($dbf); $i++) {
            if ($dbf[$i][1] == $num) {
                $catthread = $dbf[$i][12]; // n° id category
                break;
            }
        }
        unset($dbf);
    }

    if ($mod == "up" || $mod == "top") { // maj date de modif forum-thread
        $newdate = $moddate;
        $dbf = ReadDBFields(DBFORUM);
        for ($i = 0; $i < count($dbf); $i++) {
            if ($dbf[$i][2] == $pg) {
            $dbf[$i][0] = $moddate;
            $n_th = $dbf[$i][1];
            $n_re = $dbf[$i][7];
            break;
            }
        }
        @rsort($dbf,SORT_REGULAR);
        WriteDBFields(DBFORUM,$dbf);
        $dbth = ReadDBFields(DBTHREAD);
        for ($i = 0; $i < count($dbth); $i++) {
            if ($dbth[$i][1] == $n_th && $dbth[$i][2] == $n_re) {
                $dbth[$i][0] = $moddate;
                $th_id = $dbth[$i][3];
            }
        }
        WriteDBFields(DBTHREAD,$dbth);

        ReadDoc(DBBASE.$th_id); //maj topic
        $fileid = $th_id;
        $moddate = $newdate;
        $fieldb1 = addslashes(stripslashes($fieldb1));
        $fieldb2 = addslashes(stripslashes($fieldb2));
        $fieldc1 = addslashes(stripslashes($fieldc1));
        $fieldc2 = addslashes(stripslashes($fieldc2));
        if ($mod == "up" ) {
            $fieldmod =  "u#".$userprefs[1]."#".date("YmdHi");
        } else {
            $fieldmod =  "t#".$userprefs[1]."#".$newdate;
        }
        WriteDoc($th_id);
    }
	if ($mod == 'maj') {
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
    unset($dbf, $dbth);
}
