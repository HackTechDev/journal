<?php
/*
    Admin Routine - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.6 (23 January 2003)   : added news.dat file for news publishing by external sites
      v1.7 (28 January 2003)   : migrated news.dat management to functions.php
                                 added $bnouveau and $qnouveau, as well as their management for links and downloads
      v1.8 (05 February 2003)  : added category for forum
                                 corrected hide e-mail bug
      v1.9 (11 February 2003)  : added banners management and extra free box
                                 corrected a bug that would hide right boxes content whith
                                   guestbook, banner and forum because of language hard coding change
      v2.0 (27 February 2003)  : added photos management
      v2.1 (10 March 2003)     : click on smiley copies smiley to text (by Nicolas Alves and Laurent Duveau)
                                 focus on first field in new content input form (by B@lou and Laurent Duveau)
      v2.2 (22 April 2003)     : added management of two articles boxes (by Nicolas Alves)
                                 added editor assistant (by Nicolas Alves and Laurent Duveau)
                                 changed source code for all accesses to the pathinfo() PHP function for compatibility with PHP3 as pathinfo() only works with PHP4
                                 slightly modified the PopupWindow() Javascript function (resizable parameter) for use with the new editor assistant
                                 use of DrawSmileys() function
                                 cleanup in the images organization
      v2.3 (27 July 2003)      : added forms style management (by Nicolas Alves)
                                 AddSmiley1() and AddSmiley2() functions upgraded
                                 added basic editor capabilities for user input (by Nicolas Alves)
      v2.3p1 (03 August 2003)  : Bug correction: replaced include("minieditor.inc") by include("inc/minieditor.inc") in admin.inc (thanks Eddie)
      v2.4 (24 September 2003) : added an icon for articles and news
                                 added access to image Picker
                                 added react to an article option
                                 smileys now appear when content's text needs to be displayed in the documents' list (thanks Pavol)
                                 Box belonging (1st or 2nd) given for articles in the list of documents (thanks Pavol)
                                 slightly modified the PopupWindow() Javascript function (scrollbars parameter) for use with the new mini message functionality
                                 created $dbhomepage, $dbfoot, $dbspecial and $dbfreebox variables
                                 added 3 additional free boxes (by Nicolas Alves and Laurent Duveau)
                                 created $typ_[name] variables
      v3.0 (25 February 2004)     : added newsletter (by Nicolas Alves)
                                    added skins management (by Nicolas Alves)
                                    added RSS News management
      v4.0 (06 December 2004)     : added new wisiwig editor for IE/Mozilla
	                                updated text editor for other browsers (by Icare)
	                                changes in display of the articles list (by Icare and Isa)
	                                added alt tags to img and removed border tag for non-linked img,
	                                removed P tags around forms because of some changes in CSS (by Isa)
				                         added agenda-planner management (by Nicolas Alves)
				                         added sort upon ID or description for lists,
				                         added page title (by Jean-Mi)
				                         updated sort management, changed & by &amp; (by Icare)
      v4.5 (15 June 2005)           : updated editor management (by Icare)
				                         added pagination & fast actions & banner in flash (by Jean-Mi)
				                         added preview in admin textarea, strings for other browsers (by Djchouix)
	  v4.5.4 (01 September 2005)    : disabled RemoveBr() for textareas (by Icare)
	  v4.6.0 (15 March 2007)        : added new textareaeditor and browse subdirectories (by Djchouix)
			                          changed TypetTool editor by FCKEditor xhtml compliant (by Djchouix)
			                          added new items for forum and blog management (by Icare)
			                          corrected bad list when an article was missing (thanks xina)
			                          added email hidden option when writing news (thanks Laroche)
      v4.6.1 (02 July 2007)         : corrected xhtml tags (by Icare)
      v4.6.3 (30 August 2007)       : added object duplication (thanks JeanMi)
                                      corrected 2nd language and licence for downloads (by Icare)
      v4.6.5 (05 December 2007)     : corrected read $fieldd1 error in fast admin and $admin915, thanks JeanMi
      v4.6.6 (06 January 2008)      : added putBR() to $contenu1 and $contenu2 for better readability of minieditor,
                                      added select box to chose categories (by Icare)
      v4.6.8 (24 May 2008)          : corrected names in blog comments management (by Icare)
                                      changed include by include_once for funcrss.php (by Icare)
      v4.6.9 (25 December 2008)     : added field "URL of the site" in the administration of the forum #241
      v4.6.9e (29 December 2008)    : corrected warning headers already sent
      v4.6.10 (7 September 2009)    : corrected #268 #271 and #274
                                      improvement of duplication #282 (by Icare)
                                      added duplcation of the events of the diary #284 (by Icare)
      v4.6.11 (11 December 2009)    : corrected #304, added  search option for downloads #310 (thanks Linuxmr)
      v4.6.12 (01 May 2010)         : corrected #314
      v4.6.14(14 February 2011      : delete <br /> (thanks Chloe29)
	                                  added article title in addition reactions(thanks fm76)
      v4.6.15 (30 June 2011)        : added group management (by Icare)
      v4.6.16 (02 September 2011)   : corrected bad file in 4.6.15
      v4.6.17 (21 October 2011)     : added editors functions (by Jchouix)
	                                  corrected display events (by Saxbar)
      v4.6.18 (09 February 2012)    : added wide choice editor (by Saxbar)										  
	  v4.6.19 (30 March 2012)       : add social networks by Saxbar
	  v4.6.22 (29 December 2012)    : added pseudo-private group for members (by Saxbar)
	                                  added ReadGroups() (thanks JeanMi)	  
*/

if (stristr($_SERVER["SCRIPT_NAME"], "admin.inc")) {
  header("location:../index.php");
  die();
}

$nbresult = 25;

if (!empty($userprefs[1])) {
	$myname = $userprefs[1];
	$myemail = $userprefs[2];
}
else {
	$myname = $user[0];
	$myemail = $user[1];
}

$idpg = strip_tags($idpg);
if ($qtype == TYP_FORUM) {
  $dbcat = ReadDBFields(DBFORUMCAT);
  $ilng = ($lng == $lang[0] ? 1 : 2);
  for ($i = 0; $i < count($dbcat); $i++) {
    $prcat = explode(',', $dbcat[$i][0]);
    $dbfcat[$i][0] = $prcat[0];
    $dbfcat[$i][1] = $dbcat[$i][$ilng];
  }
  unset($dbcat);
}
require CHEMIN.'admin/editors/editors_functions.php';
$contenu1 = PathAbsoluteRelative($contenu1);
$contenu2 = PathAbsoluteRelative($contenu2);

$canduplicate = array('art', 'news', 'blog', 'photo', 'dnload', 'links', 'faq', 'nwl', 'agenda');
if ($act == "fast") {

  $dbids = explode(" ", trim($ids));
  $data = array();
  for ($ij = 0; $ij < count($dbids); $ij++) {
    $ii = $dbids[$ij];
    if (${"a_".$ii} == "on") {
      $data[] = array($qtype, $ii, "a");
    }
    elseif (${"i_".$ii} == "on") {
      $data[] = array($qtype, $ii, "i");
    }
    elseif (${"d_".$ii} == "on") {
      $data[] = array($qtype, $ii, "d");
    }
  }
  unset($dbids);

  $dbdocid = ReadDBFields(DOCID);
  foreach($dbdocid as $i=>$d) {
    $idx[$d[1]] =  $i;
  }
  for ($i = 0; $i < count($data); $i++) {
    ReadDoc(DBBASE.$data[$i][1]);
    $status  = $data[$i][2];
    $author  = addslashes($author);
    $email   = addslashes($email);
    $fielda1 = addslashes($fielda1);
    $fielda2 = addslashes($fielda2);
    $fieldb1 = addslashes($fieldb1);
    $fieldb2 = addslashes($fieldb2);
    $fieldc1 = addslashes($fieldc1);
    $fieldc2 = addslashes($fieldc2);
    $fieldd1 = addslashes($fieldd1);
    $fieldd2 = addslashes($fieldd2);
    $fieldweb  = addslashes($fieldweb);
    $fieldmail = addslashes($fieldmail);
    $fieldmod = addslashes($fieldmod);
    WriteDoc();
    $dbdocid[$idx[$data[$i][1]]][2] = $data[$i][2];
  }
  unset($idx);
  if (count($data) > 0) {
    usort($dbdocid, "compare_id1");
    WriteDBFields(DOCID, $dbdocid);
    unset($dbdocid, $data);
    if (in_array($qtype, array(TYP_ART, TYP_LINKS, TYP_DNLOAD, TYP_PHOTO, TYP_FAQ, TYP_RSS, TYP_BSS, TYP_AGENDA, TYP_SOCNET))) {
      UpdateDBdtb($qtype);
      if ($qtype == TYP_ART) {
        include_once(CHEMIN.INCREP."funcrss.php");
        UpdateDBart();
      }
    }
    elseif ($qtype == TYP_BLOG) {
      UpdateDBdtb($qtype);
      include_once(CHEMIN.INCREP."funcrss.php");
      UpdateDBblog();
    }
    elseif ($qtype == TYP_NEWS) {
        include_once(CHEMIN.INCREP."funcrss.php");
      UpdateDBnews();
    }
    elseif ($qtype == TYP_REACT) {
      UpdateDBreact("", 0);
    }
    elseif ($qtype == TYP_REBLOG) {
      UpdateDBreblog("", 0);
    }
    elseif ($qtype == TYP_FORUM) {
      $db1 = SelectDBFields(TYP_FORUM, "a", "");
      sort($db1);
      for ($i = 0; $i < count($db1); $i++) {
        ReadDoc(DBBASE.$db1[$i][1]);
        $db2[$i][0] = $creadate;
        $db2[$i][1] = $fielda1;
        $db2[$i][2] = $fielda2;
        $db2[$i][3] = $fileid;
        $db2[$i][4] = RemoveConnector($author);
        $db2[$i][5] = RemoveConnector($email);
        $db2[$i][6] = RemoveConnector($fieldb1);
        $db2[$i][7] = $fieldd1;
        $db2[$i][8] = $fieldb2;
        $db2[$i][9] = $fieldmail;
        if ($db2[$i][2] == "0") {
          $id3[$db2[$i][1]] = $j;
          $db3[$j][0] = $db2[$i][0];
          $db3[$j][1] = $db2[$i][1];
          $db3[$j][2] = $db2[$i][3];
          $db3[$j][3] = $db2[$i][4];
          $db3[$j][4] = $db2[$i][5];
          $db3[$j][5] = $db2[$i][6];
          $db3[$j][6] = $db2[$i][0];
          $db3[$j][7] = 0;
          $db3[$j][8] = "";
          $db3[$j][9] = "";
          $db3[$j][10] = $db2[$i][7];
          $db3[$j][11] = "";
          $db3[$j][12] = $db2[$i][8];
          $j++;
        }
        else {
          $k = $id3[$db2[$i][1]];
          $db3[$k][7]++;
          if ($db3[$k][0] < $db2[$i][0]) {
            $db3[$k][0]  = $db2[$i][0];
            $db3[$k][8]  = $db2[$i][4];
            $db3[$k][9]  = $db2[$i][5];
            $db3[$k][11] = $db2[$i][7];
          }
        }
      }
      unset($db1);
      @sort($db2,SORT_REGULAR);
      WriteDBFields(DBTHREAD, $db2);
      unset($db2);
      @rsort($db3,SORT_REGULAR);
      WriteDBFields(DBFORUM, $db3);
      unset($db3);
    }
  }
}
elseif ($act == "a" || $act == "i") {
  $data[0] = $qtype;
  $data[1] = $id;
  $data[2] = $act;
  $data[3] = "";
  $data[4] = "";
  $data[5] = "";
  $data[6] = "";
  $data[7] = "";
  $data[8] = "";
  $data[9] = "";
  $data[10] = "";
  $data[11] = "";
  $data[12] = "";
  $data[13] = "";
  $data[14] = "";
  $data[15] = "";
  $data[16] = ""; /// added with groups
  $data[17] = ""; /// added with groups
  ActionOnFields("act", $data);
}
elseif (!empty($del)) {
  if ($qtype == TYP_FORUM && $fieldb1 == "") {
    $countforum = ReadCounter(DBFORUMCOUNTER)-1;
    WriteCounter(DBFORUMCOUNTER,$countforum);
  }
  $data[0] = $qtype;
  $data[1] = $del;
  $data[2] = "d";
  $data[3] = "";
  $data[4] = "";
  $data[5] = "";
  $data[6] = "";
  $data[7] = "";
  $data[8] = "";
  $data[9] = "";
  $data[10] = "";
  $data[11] = "";
  $data[12] = "";
  $data[13] = "";
  $data[14] = "";
  $data[15] = "";
  $data[16] = ""; /// added with groups
  $data[17] = ""; /// added with groups
  ActionOnFields("del",$data);
}
elseif ($add == 1) {
  $data[0] = $qtype;
  $data[1] = "";
  $data[2] = $status == 'on' ? "a" : "i";
  $data[3] = "";
  $data[4] = "";
  if ($bname == 0) {
    $data[5] = $myname;
  } else {
    $data[5] = $pseudo1;
  }
  if ($bemail == 0) {
    $data[6] = $myemail;
  } else {
    $data[6] = $email1;
  }
  $data[7] = $cat1;
  if ($qtype == TYP_AGENDA) {
    if ($site[22] == "H3") {
      if ($hh1 < "00" || $hh1 > "12") $hh1 = "00";
    } else {
      if ($hh1 < "00" || $hh1 > "24") {
        $hh1 = "00";
      }
      $sth1 = "";
    }
    $hh1 = substr("00".$hh1, -2);
    $mn1 = substr("00".$mn1, -2);
    if ($mn1 < "00" || $mn1 > "60") $mn1 = "00";
    if ($hh1.$mn1 == "0000") $dated  = "";
    else $dated = $hh1.":".$mn1.$sth1;

    if ($site[22] == "H3") {
      if ($hh2 < "00" || $hh2 > "12") $hh2 = "00";
    } else {
      if ($hh2 < "00" || $hh2 > "24") $hh2 = "00"; $sth2 = "";
    }
    $hh2 = substr("00".$hh2, -2);
    $mn2 = substr("00".$mn2, -2);
    if ($mn2 < "00" || $mn2 > "60") $mn2 = "00";
    if ($site[22] == "H3") {
      if ($hh2.$mn2 < $hh1.$mn1 && $sth2 <= $sth1 ||$hh2.$mn2 == "00") {
       $datef = "";
      } else {
      $datef = $hh2.":".$mn2.$sth2;
      }
    } else {
      if ($hh2.$mn2 < $hh1.$mn1 || $hh2.$mn2 == "0000") {
        $datef  = "";
      } else {
      $datef = $hh2.":".$mn2;
      }
    }
    $cat2 = $dated."-".$datef;
  }
  $data[8] = $cat2;
  $data[9] = $titre1;
  $data[10] = $titre2;
  $data[11] = $qtype == TYP_SOCNET ? $contenu1 : putBR($contenu1);
  $data[12] = $qtype == TYP_SOCNET ? $contenu2 : putBR($contenu2);
  $data[13] = $nouveau1;
  $data[14] = $qtype == TYP_SOCNET ? putBR($nouveau2) : $nouveau2;
  $data[15] = $fieldweb;
  $data[16] = $fieldmail; /// added with groups
  if (isset($group)) $data[17] = $group; /// added with groups
  else $data[17] = $fieldmod;
  $id = ActionOnFields("add", $data);
  if ($dup == 2) {
    $form = 0;
  }
}
elseif ($mod == 1) {
  $data[0] = $qtype;
  $data[1] = $id;
  $data[2] = "";
  $data[3] = "";
  $data[4] = "";
  if ($bname == 0) {
      $data[5] = $myname;
  } else {
      $data[5] = $pseudo1;
  }
  if ($bemail == 0) {
      $data[6] = $myemail;
  } else {
      $data[6] = $email1;
  }
  $data[7] = $cat1;
  if ($qtype == TYP_AGENDA) {
    if ($site[22] == "H3") {
      if ($hh1 < "00" || $hh1 > "12") $hh1 = "00";
    } else {
      if ($hh1 < "00" || $hh1 > "24") {
        $hh1 = "00";
      }
      $sth1 = "";
    }
    $hh1 = substr("00".$hh1, -2);
    $mn1 = substr("00".$mn1, -2);
    if ($mn1 < "00" || $mn1 > "60") $mn1 = "00";
    if ($hh1.$mn1 == "0000") $dated  = "";
    else $dated = trim($hh1.":".$mn1).$sth1;
    
    if ($site[22] == "H3") {
      if ($hh2 < "00" || $hh2 > "12") $hh2 = "00";
    } else {
      if ($hh2 < "00" || $hh2 > "24") {
        $hh2 = "00";
        $sth2 = "";
      }
    }
    $hh2 = substr("00".$hh2, -2);
    $mn2 = substr("00".$mn2, -2);
    if ($mn2 < "00" || $mn2 > "60") $mn2 = "00";
    if ($site[22] == "H3") {
      if ($hh2.$mn2 < $hh1.$mn1 && $sth2 <= $sth1 ||$hh2.$mn2 == "00") {
       $datef = "";
      } else {
      $datef = trim($hh2.":".$mn2).$sth2;
      }
    } else {
      if ($hh2.$mn2 < $hh1.$mn1 || $hh2.$mn2 == "0000") {
        $datef  = "";
      } else {
      $datef = trim($hh2.":".$mn2);
      }
    }
    $cat2 = $dated."-".$datef;
  }
  $data[8] = $cat2;
  $data[9] = $titre1;
  $data[10] = $titre2;
  $data[11] = $qtype == TYP_SOCNET ? $contenu1 : putBR($contenu1);
  $data[12] = $qtype == TYP_SOCNET ? $contenu2 : putBR($contenu2);
  $data[13] = $nouveau1;
  $data[14] = $qtype == TYP_SOCNET ? putBR($nouveau2) : $nouveau2;
  $data[15] = $fieldweb;
  $data[16] = $fieldmail;
  $data[17] = $fieldmod;
  ActionOnFields("mod", $data);
  if ($qtype == TYP_HOMEPG) {
    ReadDoc(DBBASE.$id);
    $fieldc1 = addslashes(stripslashes($fieldc1));
    $fieldc2 = addslashes(stripslashes($fieldc2));
    $txt = "<?php
\$home1 = stripslashes(\"$fieldc1\");
\$home2 = stripslashes(\"$fieldc2\");
";
    WriteFullDB(DBHOMEPAGE,$txt);
  }
  elseif ($qtype == TYP_FOOTER) {
    ReadDoc(DBBASE.$id);
    $fieldc1 = addslashes(stripslashes($fieldc1));
    $fieldc2 = addslashes(stripslashes($fieldc2));
    $txt = "<?php
\$foot1 = stripslashes(\"$fieldc1\");
\$foot2 = stripslashes(\"$fieldc2\");
";
    WriteFullDB(DBFOOT,$txt);
  }
  elseif ($qtype == TYP_RULES) {
    ReadDoc(DBBASE.$id);
    $fieldc1 = addslashes(stripslashes($fieldc1));
    $fieldc2 = addslashes(stripslashes($fieldc2));
    $txt = "<?php
\$rule1 = stripslashes(\"$fieldc1\");
\$rule2 = stripslashes(\"$fieldc2\");
";
    WriteFullDB(DBRULES,$txt);
  }
  elseif ($qtype == TYP_SPECIAL) {
    ReadDoc(DBBASE.$id);
    $fieldc1 = addslashes(stripslashes($fieldc1));
    $fieldc2 = addslashes(stripslashes($fieldc2));
    $fieldmod = $fieldmod;
    $txt = "<?php
\$special1 = stripslashes(\"$fieldc1\");
\$special2 = stripslashes(\"$fieldc2\");
\$specialgroup = stripslashes(\"$fieldmod\");
";
    WriteFullDB(DBSPECIAL,$txt);
  }
  elseif ($qtype == TYP_FREEBOX1 || $qtype == TYP_FREEBOX2 || $qtype == TYP_FREEBOX3 || $qtype == TYP_FREEBOX4) {
    ReadDoc(DBBASE.$id);
    $fieldb1 = addslashes(stripslashes($fieldb1));
    $fieldb2 = addslashes(stripslashes($fieldb2));
    $fieldc1 = addslashes(stripslashes($fieldc1));
    $fieldc2 = addslashes(stripslashes($fieldc2));
    $fieldmod = $fieldmod;
    $txt = "<?php
\$freetitle1 = stripslashes(\"$fieldb1\");
\$freetitle2 = stripslashes(\"$fieldb2\");
\$freetext1 = stripslashes(\"$fieldc1\");
\$freetext2 = stripslashes(\"$fieldc2\");
\$freegroup = stripslashes(\"$fieldmod\");
";
    if ($qtype == TYP_FREEBOX1) {
        WriteFullDB(DBFREEBOX1,$txt);
    }
    elseif ($qtype == TYP_FREEBOX2) {
        WriteFullDB(DBFREEBOX2,$txt);
    }
    elseif ($qtype == TYP_FREEBOX3) {
        WriteFullDB(DBFREEBOX3,$txt);
    }
    elseif ($qtype == TYP_FREEBOX4) {
        WriteFullDB(DBFREEBOX4,$txt);
    }
  }
  $form = 0;
}

$pgreturn[TYP_AGENDA] = "agenda";
$pgreturn[TYP_ART] = "art";
$pgreturn[TYP_BANNER] = "banner";
$pgreturn[TYP_DNLOAD] = "dnload";
$pgreturn[TYP_FAQ] = "faq";
$pgreturn[TYP_FOOTER] = "footer";
$pgreturn[TYP_FORUM] = "forum";
$pgreturn[TYP_FREEBOX1] = "freebox1";
$pgreturn[TYP_FREEBOX2] = "freebox2";
$pgreturn[TYP_FREEBOX3] = "freebox3";
$pgreturn[TYP_FREEBOX4] = "freebox4";
$pgreturn[TYP_GUESTBK] = "guestbk";
$pgreturn[TYP_HOMEPG] = "homepg";
$pgreturn[TYP_LINKS] = "links";
$pgreturn[TYP_NEWS] = "news";
$pgreturn[TYP_BLOG] = "blog";
$pgreturn[TYP_NWL] = "nwl";
$pgreturn[TYP_PHOTO] = "photo";
$pgreturn[TYP_REACT] = "react";
$pgreturn[TYP_REBLOG] = "reblog";
$pgreturn[TYP_RECO] = "reco";
$pgreturn[TYP_RULES] = "rules";
$pgreturn[TYP_RSS] = "rss";
$pgreturn[TYP_BSS] = "bss";
$pgreturn[TYP_SPECIAL] = "special";
$pgreturn[TYP_THINK] = "think";
$pgreturn[TYP_SOCNET] = 'socnet';
global $wri;

$topmess = $qtitle;

include(CHEMIN."inc/hpage.inc");
$langue0 = $lang[0];
$langue1 = $lang[1];

if (in_array($qtype, array(TYP_ART, TYP_BLOG, TYP_FAQ, TYP_DNLOAD, TYP_LINKS, TYP_PHOTO))) {
  ?>
  <script language="javascript" type="text/javascript">
    function set(form) {
      form.cat1.value = form.list1.value;
    }
    function set2(form) {
      selindex = form.list1.selectedIndex;
      form.list2.selectedIndex=selindex;
      form.cat1.value = form.list1.value;
      form.cat2.value = form.list2.value;
    }
  </script>
  <?php
}
if ($qtype == TYP_GUESTBK || $qtype == TYP_FORUM || $qtype == TYP_REACT || $qtype == TYP_REBLOG) {
  $flag1 = CHEMIN."inc/lang/lang.gif";
  $lang[0] = "lang";
  $lang[1] = "";
}
htable($qtitle, "100%");
if ($qformonly == 2) {
  $form = 2;
}
echo '<div align="center">';
if ($qintro != "") {
  echo $qintro."<br />
  <hr />";

  if ($qtype == TYP_NWL) {
  ?>
  <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=newsletter"><?php echo $admin535; ?></a> ||
  <?php
  }
  ?>
  <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <strong><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></strong>
  <hr /><br />
  <?php
}
if ($qseeall != "") {
  if ($qtype == TYP_FREEBOX1 || $qtype == TYP_FREEBOX2 || $qtype == TYP_FREEBOX3 || $qtype == TYP_FREEBOX4) {
  ?>
  <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=freebox"><?php echo $qseeall; ?></a>
  <?php
  }
  else {
    ?>
    <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=<?php echo $pgreturn[$qtype]; ?>&amp;tri=<?php echo $tri; ?>"><?php echo $qseeall; ?></a>
    <?php
  }
  if ($qwrite != "" && $qtype == TYP_AGENDA) {
    ?>
    || <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=<?php echo $pgreturn[$qtype]; ?>&amp;tri=<?php echo $tri; ?>&amp;form=3"><?php echo $qwrite; ?></a>
    <?php
  }
  elseif($qwrite != "" ) {
    ?>
    || <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=<?php echo $pgreturn[$qtype]; ?>&amp;tri=<?php echo $tri; ?>&amp;form=1"><?php echo $qwrite; ?></a>
    <?php
  }
  echo '
<br /><br />';
}
if ($form == 3) {
  if ($dup == 2) {
    echo '
 -------------- <br />
<b>'.ucfirst($admin915).' '.$admin922.'</b>
<br /><br />';
  }
  include("inc/cal.inc");
}
if (empty($form)) {
  if (empty($tri)) $tri="-id";
    $dbwork = SelectDBFieldsByNotStatus(SelectDBFieldsByType(ReadDBFields(DOCID),$qtype),"d");
    @rsort($dbwork);
    $tmpi=0;
    $tmp[0] = array();
    $tmp[1] = array();
    $tmp[2] = array();
    $flng = ($lng == $lang[0]);
    $format_nextid = "%".ceil(log10(ReadCounter(NEXTID)))."u";
    $format_fr = "%".ceil(log10(ReadCounter(DBFORUMCOUNTER)))."u";
    for ($i = 0; $i < count($dbwork); $i++) {
      ReadDoc(DBBASE.$dbwork[$i][1]);
      $fielda2 = strip_tags(str_replace("<!--", "", str_replace("-->", " ", $fielda2)));
      ReadDoc(DBBASE.$fielda2);
      $titre_art_=$fieldb1;
      ReadDoc(DBBASE.$dbwork[$i][1]);	  
      $fielda1 = strip_tags(str_replace("<!--", "", str_replace("-->", " ", $fielda1)));
      $fielda2 = strip_tags(str_replace("<!--", "", str_replace("-->", " ", $fielda2)));
      $fieldb1 = strip_tags(str_replace("<!--", "", str_replace("-->", " ", $fieldb1)));
      $fieldb2 = strip_tags(str_replace("<!--", "", str_replace("-->", " ", $fieldb2)));
      $fieldc1 = strip_tags(str_replace("<!--", "", str_replace("-->", " ", $fieldc1)));
      $fieldc2 = strip_tags(str_replace("<!--", "", str_replace("-->", " ", $fieldc2)));
      $champs0 = "";
      $champs1 = "";
      $champs2 = "";
      if ($fileid != $dbwork[$i][1] || $type != $dbwork[$i][0]) {
        $fileid = "*".$dbwork[$i][1];
        $champs0 = $admin796.": ";
        $champs1 = $admin797;
      }
      switch ($type) {
        case TYP_GUESTBK :
          $champs1 = $admin175.$fielda1." - ";
          $champs2 = $author;
        break;
        case TYP_BANNER :
          $champs0 = $fielda1." - ";
          $champs1 = $fieldb1." - ";
          $champs2 = $fieldd1;
        break;
        case TYP_REACT :
         $champs0 = $admin175.Formatage($format_nextid, $fielda2)." : ".$titre_art_;
         $champs1 = " - ";
         $champs2 = $web6." ".$author;
       break;		
        case TYP_REBLOG :
          $champs0 = $admin175.Formatage($format_nextid, $fielda2)." - ";
          $champs1 = $web379.Formatage("%2u", $fielda1)." - ";
          $champs2 = $web6." ".$author;
        break;
        case TYP_NEWS :
        case TYP_BLOG :
          $champs0 = ($flng ? $fielda1 : $fielda2)." - ";
          $champs1 = ($flng ? $fieldb1 : $fieldb2)." - ";
          $champs2 = $author;
        break;
		case TYP_SOCNET :
        case TYP_NWL :
          $champs1 = ($flng ? $fieldb1 : $fieldb2);
        break;
        case TYP_FORUM :
          if ($fielda2 == "0") {
            $champs1 = $admin208.Formatage($format_fr, $fielda1)." + ";
            $champs2 = "<strong>".$fieldb1."</strong>";
          }
          else {
            $champs1 = $admin208.Formatage($format_fr, $fielda1)." - ";
            $champs2 = $admin209.Formatage("%2u", $fielda2);
          }
        break;
        case TYP_ART :
          if ($serviz[3] == "on" && $serviz[22] == "on") {
            if ($fieldd1 == "right") {
              $champs0 = $admin353." ";
            }
            else {
              $champs0 = $admin352." ";
            }
            if (empty($fielda1)) {
              $champs0 = $admin681." ";
            }
          }
          $champs1 = ($flng ? $fielda1 : $fielda2)." - ";
          $champs2 = ($flng ? $fieldb1 : $fieldb2);
        break;
        case TYP_DNLOAD :
        case TYP_FAQ :
        case TYP_LINKS :
        case TYP_PHOTO :
        case TYP_BSS :
        case TYP_RSS :
          $champs1 = ($flng ? $fielda1 : $fielda2)." - ";
          $champs2 = ($flng ? $fieldb1 : $fieldb2);
        break;
        case TYP_THINK :
          $champs1 = ($flng ? $fieldb1 : $fieldb2)." - ";
          $champs2 = ($flng ? $fieldc1 : $fieldc2);
        break;
        case TYP_RECO :
          $champs1 = $fieldb1." - ";
          $champs2 = ($flng ? $fieldc1 : $fieldc2);
        break;
        case TYP_AGENDA :
          $champs1 = $fielda1." - ";
          if ($fielda2 == "" || $fielda2 == "-") {
            $champs1 = $fielda1." - ";
          } else {
            $champs1 = $fielda1." - ".$fielda2." - ";
          }
          $champs2 = ($flng ? $fieldc1 : $fieldc2);
          if (strlen($champs2) > 142) $champs2 = CutLongWord($champs2,142)." .../...";
        break;
      }
      $tmp[0][$tmpi] = $champs0."<strong>".$champs1."</strong>".$champs2;
      $tmp[1][$tmpi] = $fileid;
      $tmp[2][$tmpi] = $status;
      $tmpi++;
    }
    unset($dbwork);
    if ($tmpi > 0) {
      $href = CHEMIN."admin/admin.php?lng=".$lng."&amp;pg=".$pg;
    	switch ($tri) {
      	case "id" :
      		$cr = array_multisort($tmp[1], SORT_NUMERIC, SORT_ASC, $tmp[0], $tmp[2]);
      		echo "<p align='center'><a href=\"".$href."&amp;tri=id\"><strong>".$admin674."</strong></a> - <a href=\"".$href."&amp;tri=-id\">".$admin675."</a><br /><a href=\"".$href."&amp;tri=ch\">".$admin676."</a> - <a href=\"".$href."&amp;tri=-ch\">".$admin677."</a></p> ";
    		break;
        case "-id" :
  		    echo "<p align='center'><a href=\"".$href."&amp;tri=id\">".$admin674."</a> - <a href=\"".$href."&amp;tri=-id\"><strong>".$admin675."</strong></a><br /><a href=\"".$href."&amp;tri=ch\">".$admin676."</a> - <a href=\"".$href."&amp;tri=-ch\">".$admin677."</a></p> ";
  		    break;
  	    case "ch" :
  		    $cr = array_multisort($tmp[0], SORT_ASC, $tmp[1], $tmp[2]);
  		    echo "<p align='center'><a href=\"".$href."&amp;tri=id\">".$admin674."</a> - <a href=\"".$href."&amp;tri=-id\">".$admin675."</a><br /><a href=\"".$href."&amp;tri=ch\"><strong>".$admin676."</strong></a> - <a href=\"".$href."&amp;tri=-ch\">".$admin677."</a></p> ";
  		    break;
  	    case "-ch" :
  		    $cr = array_multisort($tmp[0], SORT_DESC, $tmp[1], $tmp[2]);
  		    echo "<p align='center'><a href=\"".$href."&amp;tri=id\">".$admin674."</a> - <a href=\"".$href."&amp;tri=-id\">".$admin675."</a><br /><a href=\"".$href."&amp;tri=ch\">".$admin676."</a> - <a href=\"".$href."&amp;tri=-ch\"><strong>".$admin677."</strong></a></p> ";
  		    break;
      }
    }
    if (empty($idpg)) {
      $idpg = 1;
    }
    else {
      while ($tmpi <= ($idpg - 1)* $nbresult) $idpg--;
    }
	  if ($tmpi - ($nbresult*($idpg-1)) > $nbresult) {
	   $maxresult = $nbresult;
    }
    else {
      $maxresult = $tmpi - ($nbresult*($idpg-1));
    }
		if ($tmpi > 0) {
      $navbar = GetNavBar("admin.php?lng=".$lng."&amp;pg=".$pgreturn[$qtype]."&amp;tri=".$tri."&amp;idpg=", $tmpi, $idpg, $nbresult);
      echo '<hr />'.$navbar;
      echo "<form name=\"fast_actions\" action=\"admin.php?lng=".$lng."&amp;idpg=".$idpg."&amp;pg=".$pgreturn[$qtype]."&amp;id=".$id."&amp;tri=".$tri."&amp;act=fast\" method=\"post\">";
      echo "<div align=\"right\" style=\"width:90%; padding-right:50px\">".$boutonleft."<input class=\"bouton\" type=\"submit\" value=\"".$web361."\" />".$boutonright;
  	  echo " <img src=\"".CHEMIN."inc/img/general/bas.gif\" alt=\"\" title=\"\" /></div>";
      echo "<table cellpadding=\"4\" cellspacing=\"1\" width=\"90%\" summary=\"\">";
      echo "<tr class=\"forum\">";
  	  echo "<td>".$admin678."</td><td>".$admin679."</td><td>".$admin680."</td></tr>";
  	  $ids = "";
      for ($i = $nbresult*($idpg-1); $i < Min($nbresult*$idpg, $tmpi); $i++) {
  		  $fileid = $tmp[1][$i];
  		  $status = $tmp[2][$i];
  		  if ($i %2 == 0)
  			  echo "<tr class=\"rep\">";
  		  else
  			echo "<tr class=\"quest\">";
  		echo "<td>".$tmp[1][$i]." </td>";
  		echo "<td style=\"width:100%;text-align:left;\">";
      echo '<span style="float:left"><a href="admin.php?lng='.$lng.'&amp;pg='.$pgreturn[$qtype].'&amp;tri='.$tri .'&amp;form=2&amp;idpg='.$idpg.'&amp;id='.$fileid.'" title="'.$admin33.'"><img src="inc/img/files/edit.gif" border="0" alt="'.$admin33.'" title="'.$admin33.'" />';
      echo ' '.$tmp[0][$i].'</a></span>';
      if (in_array($pg, $canduplicate)) {
        if ($pg == "agenda") {
          echo '<span style="float:right;padding-left:4px;"> <a href="admin.php?lng='.$lng.'&amp;pg='.$pgreturn[$qtype].'&amp;tri='.$tri.'&amp;form=3&amp;idpg='.$idpg.'&amp;id='.$fileid.'&amp;dup=2" title="'.$admin915.'"><img src="inc/img/files/paste.gif" border="0" alt="'.$admin915.'" title="'.$admin915.'" /></a></span>'."\n";
        } else {
          echo '<span style="float:right;padding-left:4px;"> <a href="admin.php?lng='.$lng.'&amp;pg='.$pgreturn[$qtype].'&amp;tri='.$tri.'&amp;form=2&amp;idpg='.$idpg.'&amp;id='.$fileid.'&amp;dup=1" title="'.$admin915.'"><img src="inc/img/files/paste.gif" border="0" alt="'.$admin915.'" title="'.$admin915.'" /></a></span>';
        }
      }
      echo '<div style="clear:both"></div></td>';
      echo '<td style="white-space:nowrap;text-align:center;">';
  		if ($status == "a") {
        MakeRadioGroup(array( array("a", "i", $fileid), array("a", "d", $fileid) ));
  		}
  		elseif ($status == "i") {
        MakeRadioGroup(array( array("i", "a", $fileid), array("i", "d", $fileid) ));
      }
  		elseif ($status == "d") {
        MakeRadioGroup(array( array("d", "s", $fileid), array("d", "i", $fileid) ));
  		}
  		else {
        echo '<a href="'.CHEMIN.'admin/admin.php?lng='.$lng.'&amp;pg=dbcheck" title="'.$admin278.'"><img src="inc/img/admin/dbcheck.gif" border="0" /></a>';
      }
      echo "</td>";
  		echo "</tr>";
  		$ids .= $tmp[1][$i]." ";
  	}
  	echo "</table>";
  	echo "<p align=\"center\"><input type=\"hidden\" name=\"ids\" value=\"".$ids."\" /></p>";
  	echo "<div align=\"right\" style=\"width:90%; padding-right:42px;\">".$boutonleft."<input class=\"bouton\" type=\"submit\" value=\"".$web361."\" />".$boutonright;
  	echo " <img src=\"".CHEMIN."inc/img/general/up1.gif\" alt=\"\" style=\"padding-bottom: 3px;\" /></div>";
  	echo "</form>";
  	echo $navbar.'<hr />';
	}
	else {
	  echo '<p style="text-align:center">'.$admin854.'</p><hr />';
	}
}
elseif ($form == 1) {
  ?>
  <form name="adminsend" id="adminsend" action="admin.php?lng=<?php echo $lng; ?>" method="post">
  <input type="hidden" name="add" value="1" />
  <input type="hidden" name="pg" value="<?php echo $pgreturn[$qtype]; ?>" />
  <input type="hidden" name="tri" value="<?php echo $tri ?>" />
  <input type="hidden" name="idpg" value="<?php echo $idpg ?>" />
  <p><?php echo $admin764; ?>
    <select name="status" style="vertical-align:middle">
      <option value="on" selected="selected"><?php echo $admin765; ?></option>
      <option value=""><?php echo $admin766; ?></option>
    </select>
  </p>
  <table cellspacing="0" cellpadding="0" align="center" border="0" summary="">
  <?php
  /// début modif accès réservé
  if ($qtype == TYP_ART || $qtype == TYP_AGENDA || $qtype == TYP_BLOG || $qtype == TYP_DNLOAD || $qtype == TYP_FAQ || $qtype == TYP_LINKS 
      || $qtype == TYP_NEWS || $qtype == TYP_NWL || $qtype == TYP_PHOTO || $qtype == TYP_SOCNET) {
	$dbgroup = ReadGroups();
	echo "<p>".$admin932." :&nbsp;
	<select name='group' style='width:100px;'>\n";
	echo "<option value = ''> -- ".$web314." -- </option>\n";
	echo "<option value = 'all_members'>".$admin960."</option>\n";
	foreach($dbgroup as $grp => $mbrs) {
	  echo '<option value = "'.$grp.'">'.$grp.'</option>'."\n";
	}
    echo "</select>
  </p>\n"; 
  } /// fin modif accès réservé
  if ($bname == 1) {
    ?>
    <tr><td align="center"><p align="center"><?php echo $admin114; ?></p></td></tr>
    <tr><td align="center"><input class="texte" type="text" name="pseudo1" size="40" value="<?php echo $myname; ?>" /></td></tr>
    <?php
  }
  if ($bemail == 1) {
    ?>
    <tr><td align="center"><p align="center"><?php echo $admin115; ?></p></td></tr>
    <tr><td align="center"><input class="texte" type="text" name="email1" size="40" value="<?php echo $myemail; ?>" /></td></tr>
    <?php
  }
  if ($bnouveau == 2 && $qtype == TYP_NEWS) {
    ?>
    <tr><td align="center"><p align="center"><?php echo $qnouveau; ?>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type="checkbox" name="nouveau1" <?php if ($fieldd1 == "on") echo 'checked="checked"'; ?> /></p></td></tr>
    <?php
  }
  if ($bcat == 1 && $qtype != TYP_AGENDA && $qtype != TYP_SOCNET) {
    ?>
    <tr><td align="center"><p align="center"><?php echo $qcat; ?></p></td></tr>
    <?php
    if ($qtype == TYP_BANNER) {
		  echo '
  <tr>
    <td align="center">
      <img src="'.$flag1.'" alt="'.$flag1.'" style="vertical-align:middle" />
      <input id="cat1" name="cat1" style="vertical-align:middle;" type="text" value="" />
      <input type="button" class="bouton" style="vertical-align:middle;" name="browserver1" id="browserver1" onclick="PopupWindow(\''.CHEMIN.'admin/editors/upload/upload.php?lng='.$lng.'&amp;uptype=Image&amp;namerepconfig=guppy_config&amp;pathconfig=admin/editors/\',\'cat1\',\'700\',\'515\', \'yes\');" value="'.$admin793.'" />';
        if ($lang[1] != "") {
          echo '
    </td>
  </tr>
  <tr>
    <td align="center">
      <img src="'.$flag2.'" alt="'.$flag2.'" style="vertical-align:middle" />
      <input id="cat2" name="cat2" style="vertical-align:middle;" type="text" value="" />
      <input type="button" class="bouton" style="vertical-align:middle;" name="browserver2" id="browserver2" onclick="PopupWindow(\''.CHEMIN.'admin/editors/upload/upload.php?lng='.$lng.'&amp;uptype=Image&amp;namerepconfig=guppy_config&amp;pathconfig=admin/editors/\',\'cat2\',\'700\',\'515\', \'yes\');" value="'.$admin793.'" />';
        }
		echo '
    </td>
  </tr>';
    }
    elseif ($qtype == TYP_BSS || $qtype == TYP_RSS){
      echo "<tr><td style='text-align:center;'>\n";
      echo '<img src="'.$flag1.'" alt="'.$flag1.'" style="vertical-align:middle" />'."\n";
      echo '<input class="texte" type="text" name="cat1" value="" size="38" />'."\n";
      if ($lang[1] != "") {
        echo "</td></tr><tr><td style='text-align:center;'>\n";
        echo '<img src="'.$flag2.'" alt="'.$flag2.'" style="vertical-align:middle" />'."\n";
        echo '<input class="texte" type="text" name="cat2" value="" size="38" />'."\n";
      }
      echo '</td></tr>'."\n";
    }
    else {
      echo "<tr><td style='text-align:center;'>\n";
      $cat1 = ""; $cat2 = "";
      echo '<img src="'.$flag1.'" alt="'.$flag1.'" style="vertical-align:middle" />&nbsp;'."\n";
      if ($lang[1] != "") $nlg = 2;
      echo " <select name='list1' id='list1' onchange='set".$nlg."(this.form);' style='width:220px;'>\n";
      echo ' <option value="" selected="selected"> -- '.$admin917.' -- </option>'."\n";
      $dbw = ReadDBFields(CHEMIN.DATAREP.$qtype.DBEXT);
      sort($dbw);
      if (!empty($dbw)) {
        $curr_cat = "";
        for ($i = 0; $i < count($dbw); $i++) {
          if ($dbw[$i][0].$dbw[$i][1] != $curr_cat) {
            $cat = str_replace('<!--', '&#60;!--', str_replace('-->', '--&#62;', $dbw[$i][0]));
            $curr_cat = $dbw[$i][0].$dbw[$i][1];
            echo ' <option value="'.htmlspecialchars($dbw[$i][0], ENT_QUOTES, $charset).'">'.$cat."</option>\n";
          }
        }
      }
      echo " </select> >> \n";
      echo ' <input class="texte" type="text" name="cat1" value="'.htmlspecialchars($cat1, ENT_QUOTES, $charset).'" size="38" onfocus="this.value=\'\';this.form.list1.selectedIndex=0;" />'."\n";
      echo '</td></tr>'."\n";
      if ($lang[1] != "") {
        echo "<tr><td style='text-align:center;vertical-align:middle;white-space:nowrap;'>\n";
        echo '<img src="'.$flag2.'" alt="'.$flag2.'" style="vertical-align:middle" />&nbsp;'."\n";
        echo " <select name='list2' id='list2' onchange='form.list1.selectedIndex=form.list2.selectedIndex;set".$nlg."(this.form);' style='width:220px;'>\n";
        echo ' <option value="" selected="selected"> -- '.$admin917.' -- </option>'."\n";
        if (!empty($dbw)) {
          reset($dbw);
          $curr_cat = "";
          for ($i = 0; $i < count($dbw); $i++) {
            if ($dbw[$i][0].$dbw[$i][1] != $curr_cat) {
              $cat = str_replace('<!--', '&#60;!--', str_replace('-->', '--&#62;', $dbw[$i][1]));
              $curr_cat = $dbw[$i][0].$dbw[$i][1];
              echo '<option value="'.htmlspecialchars($dbw[$i][1], ENT_QUOTES, $charset).'">'.$cat."</option>\n";
            }
          }
        }
        echo " </select> >> \n";
        echo '<input class="texte" type="text" name="cat2" value="'.htmlspecialchars($cat2, ENT_QUOTES, $charset).'" size="38" onfocus="this.value=\'\';this.form.list2.selectedIndex=0;" />'."\n";
        echo '</td></tr>'."\n";
      }
    }
  }
  elseif ($bcat == 1 && $qtype == TYP_AGENDA) {
    ?>
    <tr><td><p align="center"><?php echo $qtitre; ?><?php echo $admin630; ?><br />
    <input class="texte" type="text" name="cat1" size="45" value="<?php echo substr(FormatDate($annee.$mois.$day."00000"), 0, 10); ?>" readonly="readonly" />
    <input type="hidden" name="titre1" size="45" value="<?php echo $mois.$annee; ?>" /></p></td></tr>
<?php
echo '
    <tr><td>'.$admin923.'
    <input class="texte" type="texte" name="hh1" value="" maxlength="2" style="width:20px;" /> :&nbsp;
    <input class="texte" type="texte" name="mn1" value="" maxlength="2" style="width:20px;" />';
    if ($site[22] == "H3") {
    echo '
    <select name="sth1" class="select" style="vertical-align:middle">
      <option value=" AM" selected="selected">AM</option>
      <option value=" PM">PM</option>
    </select>';
    }
    echo '</td></tr>';
    echo '<tr><td>'.$admin924.'
    <input class="texte" type="texte" name="hh2" value="" maxlength="2" style="width:20px;" /> :&nbsp;
    <input class="texte" type="texte" name="mn2" value="" maxlength="2" style="width:20px;" />';
    if ($site[22] == "H3") {
    echo '
    <select name="sth2" class="select" style="vertical-align:middle">
      <option value=" AM" selected="selected">AM</option>
      <option value=" PM">PM</option>
    </select>';
    }
    echo '</td></tr>';
  }
  if ($btitre >= 1) {
    $flg1 = $qtype != TYP_SOCNET ? $flag1 : $lng == $lang[0] ? $flag1 : $flag2;
    ?>
    <tr><td align="center"><p align="center"><?php echo $qtitre; ?></p></td></tr>
    <tr><td align="center"><img src="<?php echo $flg1; ?>" alt="<?php echo $flg1; ?>" style="vertical-align:middle" /> <input class="texte" type="text" name="titre1" size="45" /></td></tr>
    <?php
    if ($lang[1] != "" && $qtype != TYP_SOCNET) {
      ?>
      <tr><td align="center"><img src="<?php echo $flag2; ?>" alt="<?php echo $flag2; ?>" style="vertical-align:middle" /> <input class="texte" type="text" name="titre2" size="45" /></td></tr>
      <?php
    }
  }
  if ($bnouveau == 1) {
    if ($qtype == TYP_PHOTO) {
      ?>
      <tr><td align="center"><p align="center"><?php echo $qnouveau; ?></p></td></tr>
      <?php
		  echo '<tr><td align="center">';
		  echo '<input id="nouveau1" name="nouveau1" style="vertical-align:middle;" type="text" value="" />';
		  echo '<input type="button" class="bouton" style="vertical-align:middle;" name="browserver" id="browserver" onclick="PopupWindow(\''.CHEMIN.'admin/editors/upload/upload.php?lng='.$lng.'&amp;uptype=Media&amp;namerepconfig=guppy_config&amp;pathconfig=admin/editors/\',\'upload_photo\',\'700\',\'515\', \'yes\');" value="'.$admin793.'" />'."\n";
		  echo '</td></tr>';
    }
    elseif ($qtype == TYP_ART) {
      ?>
      <tr><td align="center"><p><?php echo $admin456; ?></p><select name="nouveau1" />
      <option value="left" <?php if ($fieldd1 == "left" || $fieldd1 == "") { echo 'selected="selected"'; } ?>><?php echo $admin348; ?></option>
      <option value="right" <?php if ($fieldd1 == "right") { echo 'selected="selected"'; } ?>><?php echo $admin349; ?></option>
      </select></td></tr>
      <?php
    }
    elseif ($qtype == TYP_DNLOAD) {
      echo '<tr><td align="center"><p align="center">'.$qnouveau.'</p></td></tr>';
		  echo '<tr><td align="center">';
      if ($lang[1] != "") {
        echo '<img src="'.$flag1.'" alt="'.$flag1.'" style="vertical-align:middle" /> ';
      }
		  echo '<input class="texte" id="nouveau1" name="nouveau1" style="vertical-align:middle;width:240px;" type="text" value="" /> ';
		  echo '<input type="button" class="bouton" style="vertical-align:middle;" name="browserver" id="browserver" onclick="PopupWindow(\''.CHEMIN.'admin/editors/upload/upload.php?lng='.$lng.'&amp;uptype=Link&amp;namerepconfig=guppy_config&amp;pathconfig=admin/editors/\',\'nouveau1\',\'700\',\'515\', \'yes\');" value="'.$admin793.'" />'."\n";

      echo '</td></tr>';
		  if ($lang[1] != "") {
        echo '<tr><td align="center">
        <img src="'.$flag2.'" alt="'.$flag2.'" style="vertical-align:middle" /> ';
		    echo '<input class="texte" id="nouveau2" name="nouveau2" style="vertical-align:middle;width:240px;" type="text" value="" /> ';
		    echo '<input type="button" class="bouton" style="vertical-align:middle;" name="browserver" id="browserver" onclick="PopupWindow(\''.CHEMIN.'admin/editors/upload/upload.php?lng='.$lng.'&amp;uptype=Link&amp;namerepconfig=guppy_config&amp;pathconfig=admin/editors/\',\'nouveau2\',\'700\',\'515\', \'yes\');" value="'.$admin793.'" />'."\n";
		    echo '</td></tr>';
      }
    }
    elseif ($qtype == TYP_SOCNET) {
		$flg1 = $lng == $lang[0] ? $flag1 : $flag2;
        echo '
      <tr><td align="center"><p align="center">'.$qnouveau.'</p></td></tr>
      <tr>
        <td align="center"><img src="'.$flg1.'" alt="'.$flg1.'" style="vertical-align:middle" />
          <input class="texte" type="text" name="nouveau1" size="45" />
        </td>
      </tr>
      <tr><td align="center"><p align="center">'.$admin955.'</p></td></tr>
      <tr>
        <td align="center">
          <textarea name="nouveau2" cols="48" rows="6">'.$nouveau2.'</textarea>
        </td>
      </tr>';
	}
    else {
      ?>
      <tr><td align="center"><p align="center"><?php echo $qnouveau; ?></p></td></tr>
      <tr><td align="center"><img src="<?php echo $flag1; ?>" alt="<?php echo $flag1; ?>" style="vertical-align:middle" /> <input class="texte" type="text" name="nouveau1" size="45" /></td></tr>
      <?php
      if ($lang[1] != "") {
        ?>
        <tr><td align="center"><img src="<?php echo $flag2; ?>" alt="<?php echo $flag2; ?>" style="vertical-align:middle" /> <input class="texte" type="text" name="nouveau2" size="45" /></td></tr>
        <?php
      }
    }
    if ($qtype == TYP_DNLOAD) {
      ?>
      <tr><td align="center"><p><?php echo $admin717; ?></p>
      <select name="fieldweb">
        <option value="" <?php if ($fieldweb == "") { echo 'selected="selected"'; } ?>><?php echo $web314; ?></option>
        <option value="CeCILL" <?php if ($fieldweb == "CeCILL") { echo 'selected="selected"'; } ?>><?php echo "CeCILL"; ?></option>
        <option value="GNU_GPL" <?php if ($fieldweb == "GNU_GPL") { echo 'selected="selected"'; } ?>><?php echo "GNU_GPL"; ?></option>
        <option value="GNU_LGPL" <?php if ($fieldweb == "GNU_LGPL") { echo 'selected="selected"'; } ?>><?php echo "GNU_LGPL"; ?></option>
        <option value="Creative_Commons" <?php if ($fieldweb == "Creative_Commons") { echo 'selected="selected"'; } ?>><?php echo "Creative_Commons"; ?></option>
      </select></td></tr>
      <?php
    }
  }
  if ($qtype == TYP_ART || $qtype == TYP_NEWS || $qtype == TYP_BLOG || $qtype == TYP_SOCNET) {
	switch ($qtype) {        
	case TYP_ART     : 
	case TYP_BLOG    : $label = $admin461;  $fname = 'nouveau2'; break;
	case TYP_NEWS    : $label = $admin462;  $fname = 'nouveau2'; break;
	case TYP_SOCNET  : $label = $admin953;  $fname = 'contenu2'; break;
	}
    ?>
    <tr>
    <td align="center">
    <p><?php echo $label; ?></p>
    <?php
	echo '<input id="'.$fname.'" name="'.$fname.'" style="vertical-align:middle;" type="text" value="" />';
	echo '<input type="button" class="bouton" style="vertical-align:middle;" name="browserver" id="browserver" 
	  onclick="PopupWindow(\''.CHEMIN.'admin/editors/upload/upload.php?lng='.$lng.'&amp;uptype=Image&amp;namerepconfig=guppy_config&amp;pathconfig=admin/editors/\',\''.$fname.'\',\'700\',\'515\', \'yes\');" value="'.$admin793.'" />'."\n";
	echo '</td></tr>';
  }
  if ($bcontenu == 1) {
    if ($qtype == TYP_SOCNET) {
        echo '
      <tr>
        <td align="center">
          <p>'.$qcontenu.'
            <select name="contenu1">
              <option value="_SELF"'.Selected($contenu1 == '_SELF').'>'.$admin956.'</option>
              <option value="_BLANK"'.Selected($contenu1 == '_BLANK').'>'.$admin957.'</option>';
		echo '
              <option value="_POPUP"'.Selected($contenu1 == '_POPUP').'>'.$admin958.'</option>';
        echo '
            </select>
          </p>
        </td>
      </tr>
	</table>';
	}
	else {
    ?>
    <tr><td align="center"><p align="center"><?php echo $qcontenu; ?></p><br /></td></tr>
    <tr><td align="center">
    <img src="<?php echo $flag1; ?>" alt="<?php echo $lang[0] ?>" style="vertical-align:middle" /><br /><br />
    </td></tr>
    </table>
    <?php
    display_admin_editor('contenu1', $serviz[63], '480px', '', $serviz[49]);    

    if ($lang[1] != "") {
      ?>
      <br /><br />
      <table cellspacing="0" cellpadding="0" align="center" border="0" summary="">
      <tr><td align="center">
      <img src="<?php echo $flag2; ?>" alt="<?php echo $lang[1] ?>" style="vertical-align:middle" /><br /><br />
      </td></tr>
      </table>
      <?php
      display_admin_editor('contenu2', $serviz[63], '480px', '', $serviz[49]);
    }
	}
  } else {
    ?>
    </table>
    <?php
  }
  ?>
  <p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin38; ?>"><?php echo $admin38; ?></button><?php echo $boutonright; ?></p>
  </form>
  <?php
}
elseif ($form == 2) {
    ReadDoc(DBBASE.$id);
  ?>
  <form name="adminsend" id="adminsend" action="admin.php?lng=<?php echo $lng; ?>" method="post">
  <input type="hidden" name="pg" value="<?php echo $pgreturn[$qtype]; ?>" />
  <input type="hidden" name="tri" value="<?php echo $tri ?>" />
<?php
  if ($dup == 1 || $dup == 2) {
      echo '
  <p>'.$admin921.'
    <input type="hidden" name="dup" value="2" />
    <select name="status" style="vertical-align:middle">
      <option value="on" selected="selected">'.$admin765.'</option>
      <option value="">'.$admin766.'</option>\n
    </select>
  </p>
  <input type="hidden" name="add" value="1" />';
  } else {
    echo '
  <input type="hidden" name="mod" value="1" />';
  }
?>
  <input type="hidden" name="form" value="2" />
  <input type="hidden" name="idpg" value="<?php echo $idpg ?>" />
  <input type="hidden" name="id" value="<?php echo $id; ?>" />
  <?php
  if ($bcat == 1 && $qtype == TYP_AGENDA) {
    if ($dup == 2) {
      $fieldb1 = $mois.$annee;
    }
    echo '
  <input type="hidden" name="titre1" value="'.$fieldb1.'" />';
  }

  if ($qtype == TYP_GUESTBK || $qtype == TYP_FORUM || $qtype == TYP_REACT || $qtype == TYP_REBLOG) {
    ?>
  <input type="hidden" name="cat1" value="<?php echo $fielda1; ?>" />
    <?php
  }
  if ($qtype == TYP_FORUM || $qtype == TYP_REACT || $qtype == TYP_REBLOG) {
    ?>
  <input type="hidden" name="cat2" value="<?php echo $fielda2; ?>" />
    <?php
  }
  ?>
  <table cellspacing="0" cellpadding="0" align="center" border="0" summary="">
  <?php
  if ($bname == 1) {
    ?>
    <tr><td align="center"><p align="center"><?php echo $admin114; ?></p></td></tr>
    <tr><td align="center"><input class="texte" type="text" name="pseudo1" size="40" value="<?php echo $author; ?>" /></td></tr>
    <?php
  }
  if ($bemail == 1) {
    ?>
    <tr><td align="center"><p align="center"><?php echo $admin115; ?></p></td></tr>
    <tr><td align="center"><input class="texte" type="text" name="email1" size="40" value="<?php echo $email; ?>" /></td></tr>
    <?php
  }
  if ($bnouveau == 2) {
    ?>
    <tr><td align="center"><p align="center"><?php echo $qnouveau; ?>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type="checkbox" name="nouveau1" <?php if ($fieldd1 == "on") echo 'checked="checked"'; ?> /></p></td></tr>
    <?php
  }
      /// début modif accès privé
      if ($qtype == TYP_ART || $qtype == TYP_AGENDA || $qtype == TYP_BLOG || $qtype == TYP_DNLOAD || $qtype == TYP_FAQ || $qtype == TYP_LINKS || $qtype == TYP_NEWS || $qtype == TYP_NWL ||
 	    $qtype == TYP_PHOTO || $qtype == TYP_SPECIAL || $qtype == TYP_FREEBOX1 || $qtype == TYP_FREEBOX2 || $qtype == TYP_FREEBOX3 || $qtype == TYP_FREEBOX4 || $qtype == TYP_SOCNET) {
      //if (!$qtype == TYP_GUESTBK || !$qtype == TYP_HOMEPG) {
		$dbgroup = ReadGroups();
		echo "<tr><td align='center'>
		<p>".$admin932." :&nbsp;
		<select name='fieldmod' style='width:100px;'>\n";
		echo "<option value = ''> -- ".$web314." -- </option>\n";
	    if ($fieldmod == 'all_members') $sel = ' selected="selected"'; else $sel = '';
		echo '<option value = "all_members"'.$sel.'>all_members</option>';
		foreach($dbgroup as $grp => $mbrs) {
		  if ($fieldmod == $grp) $sel = ' selected="selected"'; else $sel = '';
			echo '<option value = "'.$grp.'"'.$sel.'>'.$grp.'</option>'."\n";
		}
        echo "</select>\n
        </p>\n";
        echo "</td></tr>";
      }
       /// fin modif accès privé

  if ($bcat == 1) {
    $agenda_prive = "on";
    if ($qtype == TYP_AGENDA) {
      if ($dup == 2) {
        $fielda1 = substr(FormatDate($annee.$mois.$day."00000"), 0, 10);
      }
      ?>
      <tr><td align="center"><p align="center"><?php echo $qcat; ?></p></td></tr>
      <tr><td align="center"><input class="texte" type="text" name="cat1" size="40" value="<?php echo $fielda1; ?>" readonly="readonly" /></td></tr>
      <?php
      $timeag = explode("-", $fielda2);
      if ($site[22] == "H3") {
      $sthh1 = explode(" ", $timeag[0]);
      $timed = explode(":", $sthh1[0]);
      $sthh2 = explode(" ", $timeag[1]);
      $timef = explode(":", $sthh2[0]);
      }else {
      $timed = explode(":", $timeag[0]);
      $timef = explode(":", $timeag[1]);
      }
      echo '
      <tr><td>'.$admin923.'
      <input class="texte" type="texte" name="hh1" size="2" value="'.$timed[0].'" maxlength="2" style="width:30px;" /> :&nbsp;
      <input class="texte" type="texte" name="mn1" size="2" value="'.$timed[1].'" maxlength="2" style="width:30px;" />';
      if ($site[22] == "H3") {
      ?>
      <select name="sth1" class="select">
        <option value=" AM"<?php if ($sthh1[1] == " AM") { echo " selected='selected'"; } ?>><?php echo "AM"; ?></option>
        <option value=" PM"<?php if ($sthh1[1] == " PM") { echo " selected='selected'"; } ?>><?php echo "PM"; ?></option>
      </select>
      <?php
      }
      echo '</td></tr>
      <tr><td>'.$admin924.'
      <input class="texte" type="texte" name="hh2" size="2" value="'.$timef[0].'" maxlength="2" style="width:30px;" /> :&nbsp;
      <input class="texte" type="texte" name="mn2" size="2" value="'.$timef[1].'" maxlength="2" style="width:30px;" />';
      if ($site[22] == "H3") {
      ?>
      <select name="sth2" class="select">
        <option value=" AM"<?php if ($sthh2[1] == " AM") { echo " selected='selected'"; } ?>><?php echo "AM"; ?></option>
        <option value=" PM"<?php if ($sthh2[1] == " PM") { echo " selected='selected'"; } ?>><?php echo "PM"; ?></option>
      </select>
      <?php
      }
    }
    elseif ($qtype != TYP_FORUM) {
      ?>
      <tr><td align="center"><p align="center"><?php echo $qcat; ?></p></td></tr>
      <?php
    if ($qtype == TYP_BANNER) {
		  echo '
  <tr>
    <td align="center">
      <img src="'.$flag1.'" alt="'.$flag1.'" style="vertical-align:middle" />
      <input id="cat1" name="cat1" style="vertical-align:middle;" type="text" value="'.$fielda1.'" />
      <input type="button" class="bouton" style="vertical-align:middle;" name="browserver1" id="browserver1" onclick="PopupWindow(\''.CHEMIN.'admin/editors/upload/upload.php?lng='.$lng.'&amp;uptype=Image&amp;namerepconfig=guppy_config&amp;pathconfig=admin/editors/\',\'cat1\',\'700\',\'515\', \'yes\');" value="'.$admin793.'" />';
        if ($lang[1] != "") {
          echo '
    </td>
  </tr>
  <tr>
    <td align="center">
      <img src="'.$flag2.'" alt="'.$flag2.'" style="vertical-align:middle" />
      <input id="cat2" name="cat2" style="vertical-align:middle;" type="text" value="'.$fielda2.'" />
      <input type="button" class="bouton" style="vertical-align:middle;" name="browserver2" id="browserver2" onclick="PopupWindow(\''.CHEMIN.'admin/editors/upload/upload.php?lng='.$lng.'&amp;uptype=Image&amp;namerepconfig=guppy_config&amp;pathconfig=admin/editors/\',\'cat2\',\'700\',\'515\', \'yes\');" value="'.$admin793.'" />';
        }
		echo '
    </td>
  </tr>';
    }
      elseif ($qtype == TYP_BSS || $qtype == TYP_RSS) {
        echo "<tr><td style='text-align:center;'>\n";
        echo '<img src="'.$flag1.'" alt="'.$flag1.'" style="vertical-align:middle" />'."\n";
        echo '<input class="texte" type="text" name="cat1" value="'.$fielda1.'" size="38" />'."\n";
          if ($lang[1] != "") {
            echo "</td></tr><tr><td style='text-align:center;'>\n";
            echo '<img src="'.$flag2.'" alt="'.$flag2.'" style="vertical-align:middle" />'."\n";
            echo '<input class="texte" type="text" name="cat2" value="'.$fielda2.'" size="38" />'."\n";
          }
        echo '</td></tr>'."\n";
      } elseif ($qtype != TYP_NEWS) { /// modif accès privé
        echo "<tr><td style='text-align:center;'>\n";
        echo '<img src="'.$flag1.'" alt="'.$flag1.'" style="vertical-align:middle" />&nbsp;'."\n";
        if ($lang[1] != "") $nlg = 2;
        echo " <select name='list1' id='list1' style='width:220px;' onchange='set".$nlg."(this.form);'>\n";
        echo '<option value=""> -- '.$admin917.' -- </option>'."\n";
        $dbw = ReadDBFields(CHEMIN.DATAREP.$qtype.DBEXT);
        sort($dbw);
        if (!empty($dbw)) {
          $curr_cat = "";
          for ($i = 0; $i < count($dbw); $i++) {
            if ($dbw[$i][0].$dbw[$i][1] != $curr_cat) {
              $sel= "";
              $cat = str_replace('<!--', '&#60;!--', str_replace('-->', '--&#62;', $dbw[$i][0]));
              $curr_cat = $dbw[$i][0].$dbw[$i][1];
              if ($dbw[$i][0].$dbw[$i][1] == $fielda1.$fielda2) $sel = " selected='selected'";
              echo '<option value="'.htmlspecialchars($dbw[$i][0], ENT_QUOTES, $charset).'"'.$sel.'>'.$cat."</option>\n";
            }
          }
        }
        echo " </select> >> \n";
        echo '<input class="texte" type="text" name="cat1" value="'.htmlspecialchars($fielda1, ENT_QUOTES, $charset).'" size="36" onfocus="this.value=\'\';this.form.list1.selectedIndex=0;" />'."\n";
        echo '</td></tr>'."\n";
        if ($lang[1] != "") {
          echo "<tr><td style='text-align:center;white-space:nowrap;'>\n";
          echo '<img src="'.$flag2.'" alt="'.$flag2.'" style="vertical-align:middle" />&nbsp;'."\n";
          echo " <select name='list2' id='list2' style='width:220px;' onchange='form.list1.selectedIndex=form.list2.selectedIndex;set".$nlg."(this.form);'>\n";
          echo '<option value=""> -- '.$admin917.' -- </option>'."\n";
          if (!empty($dbw)) {
            reset($dbw);
            $curr_cat = "";
            for ($i = 0; $i < count($dbw); $i++) {
              if ($dbw[$i][0].$dbw[$i][1] != $curr_cat) {
                $sel= "";
                $cat = str_replace('<!--', '&#60;!--', str_replace('-->', '--&#62;', $dbw[$i][1]));
                $curr_cat = $dbw[$i][0].$dbw[$i][1];
                if ($dbw[$i][0].$dbw[$i][1] == $fielda1.$fielda2) $sel = " selected='selected'";
                echo '<option value="'.htmlspecialchars($dbw[$i][1], ENT_QUOTES, $charset).'"'.$sel.'>'.$cat."</option>\n";
              }
            }
          }
          echo " </select> >> \n";
          echo '<input class="texte" type="text" name="cat2" value="'.htmlspecialchars($fielda2, ENT_QUOTES, $charset).'" size="36" onfocus="this.value=\'\';this.form.list2.selectedIndex=0;" />'."\n";
          echo '</td></tr>'."\n";
        }
      }
    }
    elseif ($fielda2 == "0") {
      ?>
      <tr><td align="center"><p align="center"><?php echo $admin260; ?></p></td></tr>
      <tr><td align="center"><select name="titre2">
      <option value=""><?php echo $admin259; ?></option>
      <?php
      for ($i = 0; $i < count($dbfcat); $i++) {
        if ($dbfcat[$i][0] == $fieldb2) {
          $sel = " selected='selected'";
        }
        else {
          $sel = "";
        }
        echo "<option value=\"".$dbfcat[$i][0]."\"".$sel.">".$dbfcat[$i][1]."</option>\n";
      }
      ?>
      </select></td></tr>
      <?php
    }
  }
  if ($btitre >= 1 && ($qtype != TYP_FORUM || ($qtype == TYP_FORUM && $fielda2 == "0"))) {
    $fieldb1 = str_replace('"','&#34;',$fieldb1);
    $flg1 = $qtype != TYP_SOCNET ? $flag1 : $lng == $lang[0] ? $flag1 : $flag2;
    ?>
    <tr><td align="center"><p align="center"><?php echo $qtitre; ?></p></td></tr>
    <tr><td align="center"><img src="<?php echo $flg1; ?>" alt="<?php echo $flg1; ?>" style="vertical-align:middle" /> <input class="texte" type="text" name="titre1" size="45" value="<?php echo $fieldb1; ?>" /></td></tr>
    <?php
    if ($lang[1] != "" && $qtype != TYP_SOCNET) {
      $fieldb2 = str_replace('"','&#34;',$fieldb2);
      ?>
      <tr><td align="center"><img src="<?php echo $flag2; ?>" alt="<?php echo $flag2; ?>" style="vertical-align:middle" /> <input class="texte" type="text" name="titre2" size="45" value="<?php echo $fieldb2; ?>" /></td></tr>
      <?php
    }
  }
  if ($bnouveau == 1) {
    if ($qtype == TYP_PHOTO) {
      ?>
      <tr><td align="center"><p align="center"><?php echo $qnouveau; ?></p></td></tr>
      <?php
		  echo '<tr><td align="center">';
		  echo '<input id="nouveau1" name="nouveau1" style="vertical-align:middle;" type="text" value="'.$fieldd1.'" />';
		  echo '<input type="button" class="bouton" style="vertical-align:middle;" name="browserver" id="browserver" onclick="PopupWindow(\''.CHEMIN.'admin/editors/upload/upload.php?lng='.$lng.'&amp;uptype=Media&amp;namerepconfig=guppy_config&amp;pathconfig=admin/editors/\',\'upload_photo\',\'700\',\'515\', \'yes\');" value="'.$admin793.'" />'."\n";
		  echo '</td></tr>';
    }
    elseif ($qtype == TYP_ART) {
      ?>
      <tr><td align="center"><p><?php echo $admin456; ?></p><select name="nouveau1" />
      <option value="left" <?php if ($fieldd1 == "left" || $fieldd1 == "") { echo 'selected="selected"'; } ?>><?php echo $admin348; ?></option>
      <option value="right" <?php if ($fieldd1 == "right") { echo 'selected="selected"'; } ?>><?php echo $admin349; ?></option>
      </select></td></tr>
      <?php
    }
    elseif ($qtype == TYP_DNLOAD) {
      echo '<tr><td align="center"><p align="center">'.$qnouveau.'</p></td></tr>';
		  echo '<tr><td align="center">';
      if ($lang[1] != "") {
        echo '<img src="'.$flag1.'" alt="'.$flag1.'" style="vertical-align:middle" /> ';
      }
		  echo '<input id="nouveau1" name="nouveau1" style="vertical-align:middle;width:240px;" type="text" value="'.$fieldd1.'" /> ';
		  echo '<input type="button" class="bouton" style="vertical-align:middle;" name="browserver" id="browserver" onclick="PopupWindow(\''.CHEMIN.'admin/editors/upload/upload.php?lng='.$lng.'&amp;uptype=Link&amp;namerepconfig=guppy_config&amp;pathconfig=admin/editors/\',\'nouveau1\',\'700\',\'515\', \'yes\');" value="'.$admin793.'" />'."\n";
		  echo '</td></tr>';
		  if ($lang[1] != "") {
        echo '<tr><td align="center">
        <img src="'.$flag2.'" alt="'.$flag2.'" style="vertical-align:middle" /> ';
		    echo '<input id="nouveau2" name="nouveau2" style="vertical-align:middle;width:240px;" type="text" value="'.$fieldd2.'" /> ';
		    echo '<input type="button" class="bouton" style="vertical-align:middle;" name="browserver" id="browserver" onclick="PopupWindow(\''.CHEMIN.'admin/editors/upload/upload.php?lng='.$lng.'&amp;uptype=Link&amp;namerepconfig=guppy_config&amp;pathconfig=admin/editors/\',\'nouveau2\',\'700\',\'515\', \'yes\');" value="'.$admin793.'" />'."\n";
		    echo '</td></tr>';
      }
    }
    elseif ($qtype == TYP_SOCNET) {
		$flg1 = $lng == $lang[0] ? $flag1 : $flag2;
        echo '
      <tr><td align="center"><p align="center">'.$qnouveau.'</p></td></tr>
      <tr>
        <td align="center"><img src="'.$flg1.'" alt="'.$flg1.'" style="vertical-align:middle" />
          <input class="texte" type="text" name="nouveau1" size="45" value="'.$fieldd1.'" />
        </td>
      </tr>
      <tr><td align="center"><p align="center">'.$admin955.'</p></td></tr>
      <tr>
        <td align="center">
          <textarea name="nouveau2" cols="48" rows="6">'.$fieldd2.'</textarea>
        </td>
      </tr>';
	}
    else {
      ?>
      <tr><td align="center"><p align="center"><?php echo $qnouveau; ?></p></td></tr>
      <tr><td align="center"><img src="<?php echo $flag1; ?>" alt="<?php echo $flag1; ?>" style="vertical-align:middle" /> <input class="texte" type="text" name="nouveau1" size="55" value="<?php echo $fieldd1; ?>" /></td></tr>
      <?php
      if ($lang[1] != "") {
        ?>
        <tr><td align="center"><img src="<?php echo $flag2; ?>" alt="<?php echo $flag2; ?>" style="vertical-align:middle" /> <input class="texte" type="text" name="nouveau2" size="55" value="<?php echo $fieldd2; ?>" /></td></tr>
        <?php
      }
    }
    if ($qtype == TYP_DNLOAD) {
    ?>
      <tr><td align="center"><p><?php echo "Logiciel sous licence"; ?></p><select name="fieldweb">
      <option value="" <?php if ($fieldweb == "") { echo 'selected="selected"'; } ?>><?php echo $web314; ?></option>
      <option value="CeCILL" <?php if ($fieldweb == "CeCILL") { echo 'selected="selected"'; } ?>><?php echo "CeCILL"; ?></option>
      <option value="GNU_GPL" <?php if ($fieldweb == "GNU_GPL") { echo 'selected="selected"'; } ?>><?php echo "GNU_GPL"; ?></option>
      <option value="GNU_LGPL" <?php if ($fieldweb == "GNU_LGPL") { echo 'selected="selected"'; } ?>><?php echo "GNU_LGPL"; ?></option>
      <option value="Creative_Commons" <?php if ($fieldweb == "Creative_Commons") { echo 'selected="selected"'; } ?>><?php echo "Creative_Commons"; ?></option>
      </select></td></tr>
    <?php
    }
  }
  if ($qtype == TYP_FORUM) {
  ?>
    <tr><td align="center">
    <input class="texte" type="hidden" name="contenu2" size="55" value="<?php echo $fieldc2; ?>" />
    <input class="texte" type="hidden" name="nouveau2" size="55" value="<?php echo $fieldd2; ?>" />
    <input class="texte" type="hidden" name="fieldweb" size="55" value="<?php echo $fieldweb; ?>" />
    <input class="texte" type="hidden" name="fieldmod" size="55" value="<?php echo $fieldmod; ?>" /></td></tr>
  <?php
  }
  if ($qtype == TYP_ART || $qtype == TYP_NEWS || $qtype == TYP_BLOG || $qtype == TYP_SOCNET) {
	switch ($qtype) {        
	case TYP_ART     : 
	case TYP_BLOG    : $label = $admin461;  $fname = 'nouveau2'; $value = $fieldd2; break;
	case TYP_NEWS    : $label = $admin462;  $fname = 'nouveau2'; $value = $fieldd2; break;
	case TYP_SOCNET  : $label = $admin953;  $fname = 'contenu2'; $value = $fieldc2; break;
	}
    ?>
      <tr><td align="center"><p><?php echo $label; ?></p>
    <?php
    echo '<input id="'.$fname.'" name="'.$fname.'" style="vertical-align:middle;" type="text" value="'.$value.'" />';
    echo '<input type="button" class="bouton" style="vertical-align:middle;" name="browserver" id="browserver" 
	  onclick="PopupWindow(\''.CHEMIN.'admin/editors/upload/upload.php?lng='.$lng.'&amp;uptype=Image&amp;namerepconfig=guppy_config&amp;pathconfig=admin/editors/\',\''.$fname.'\',\'700\',\'515\', \'yes\');" value="'.$admin793.'" />'."\n";
    echo '</td></tr>';
  }
  if ($bcontenu == 1) {
    if ($qtype == TYP_SOCNET) {
        function GetTargetSN($snid) {
			global $fieldc1;
            ReadDoc(DBBASE.$snid);
            return strtoupper($fieldc1);
        }
		$target = GetTargetSN($id);
        echo '
      <tr>
        <td align="center">
          <p>'.$qcontenu.'
            <select name="contenu1">
              <option value="_SELF"'.Selected($target == '_SELF').'>'.$admin956.'</option>
              <option value="_BLANK"'.Selected($target == '_BLANK').'>'.$admin957.'</option>
              <option value="_POPUP"'.Selected($target == '_POPUP').'>'.$admin958.'</option>
            </select>
          </p>
        </td>
      </tr>';
        echo '
    </table>';
    }
	else {
    ?>
    <tr><td align="center"><p align="center"><?php echo $qcontenu; ?></p><br /></td></tr>
    <tr><td align="center">
    <img src="<?php echo $flag1; ?>" alt="<?php echo $lang[0] ?>" style="vertical-align:middle" /><br /><br />
    </td></tr></table>
    <?php
      display_admin_editor('contenu1', $serviz[63], '480px', $fieldc1, $serviz[49]);

      if ($qtype == TYP_FORUM && $fieldb1 != ""){
        echo "<p align='center'>".$web206." : ";
        echo "<select name='fieldmod' style='vertical-align:middle'>";
        if ($fieldmod == "") {
          echo "<option value=\"\" selected='selected'>".$web367."</option>\n";
          echo "<option value=\"c\">".$web368."</option>\n";
        }
        else {
          echo "<option value=\"\">".$web367."</option>\n";
          echo "<option value=\"c\" selected='selected'>".$web368."</option>\n";
        }
        echo "</select></p>";
      }
      if ($qtype == TYP_FORUM) {
        echo '
    <p align="center">'.$admin173.' <input type="text" name="fieldweb" value="'.$fieldweb.'" size="60" /></p>';
      }
      if ($lang[1] != "") {
        ?>
      <br /><br />
      <table cellspacing="0" cellpadding="0" align="center" summary="">
      <tr><td align="center">
      <img src="<?php echo $flag2; ?>" alt="<?php echo $lang[1] ?>" style="vertical-align:middle" /><br /><br />
      </td></tr>
      </table>
        <?php
        display_admin_editor('contenu2', $serviz[63], '480px', $fieldc2, $serviz[49]);
      }
	}
  } else {
    ?>
    </table>
    <?php
  }
  ?>
  <p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin38; ?>"><?php echo $admin38; ?></button><?php echo $boutonright; ?></p>
  </form>
  <?php
}
?>
</div>
<?php
if ($qtype == TYP_NWL) {
  ?>
  <p align="center"><a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=newsletter"><?php echo $admin535; ?></a> || <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <strong><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></strong></p>
  <?php
  }
else {
  ?>
  <p align="center"><a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <strong><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></strong></p>
  <?php
}
btable();
$lang[0] = $langue0;
$lang[1] = $langue1;
include(CHEMIN."inc/bpage.inc");
?>
