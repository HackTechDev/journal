<?php
/*
    Search- GuppY PHP Script -  version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v2.0 (27 February 2003)  : added freebox and photo search
      v2.2 (22 April 2003)     : replaced $serviz[] exit by new value
                                 replaced <P><CENTER> by <P align="center"> otherwise IE takes the default font instead of the required one (Thanks Michel)
                                 cleanup in the images organization
      v2.3 (27 July 2003)      : added direct jump to pages (by Nicolas Alves and Laurent Duveau)
                                 minor font and text formating changes in search, quotations, general pages (thanks Isabelle)
                                 added "Search in" only one type of content option
      v2.4 (24 September 2003) : added Search in one language only option
                                 added react to an article option
                                 added ReadDoc() function
                                 removed call to freebox.inc file
                                 added GetCurrentDateTime() and FormatDate() function to ease various date and time formatings
                                 corrected bug which would always say that articles found were in the 1st box (thanks Pavol)
                                 secured transfered parameters
                                 added 3 additional free boxes (by Nicolas Alves and Laurent Duveau)
                                 created $typ_[name] variables
      v3.0p2 (09 April 2004)   : removed 2 debug information lines forgotten during v3.0 development
      v4.0 (06 December 2004)  : added page title (by Jean-Mi)
                                 added alt tags to img and removed border tag for non-linked img (by Isa)
      v4.5 (22 March 2005)     : revision of the search engine (by Jean-Mi)
                                 replacing navigation bar (by Jean-Mi)
                                 added restrictive search for member only (by hpsam)
      v4.6.1 (02 July 2007)    : added search on blog and blog comments (by Icare, thanks Jean-Mi for correction)
      v4.6.7 (23 April 2008)   : added alt and title on links or img (by Icare)
      v4.6.8 (10 May 2008)     : revision of search engine (by JeanMi)
      v4.6.9 (25 December 2008): correction of the initialization of $searchfor (line 54) #233
      v4.6.10 (7 September 2009) : corrected #274
      v4.6.15 (30 June 2011)     : added private management (by Icare)
      v4.6.17(21 October 2011)   : removed all direct links to print or download (by Laroche) 
                                   corrected links for agenda and forum (by Saxbar)
	  v4.6.22 (29 December 2012) : added pseudo-private group for members (by Saxbar)							   
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");

if ($serviz[24] != "on") {
  exit($web143);
}

$search = strip_tags($search);
$searchin = strip_tags($searchin);
$searchlng = strip_tags($searchlng);

$restricted = false;
if ($userprefs[1] == '' && $members[0] == 'on') {
  if ($searchin != '') {
    $searchfor = array($searchin);
    $illegal = false;
    switch ($searchin) {
    case TYP_ART :
    case TYP_REACT :
      if ($members[1] == 'on') $illegal = true;
      break;
    case TYP_BLOG :
    case TYP_REBLOG :
      if ($members[15] == 'on') $illegal = true;
      break;
    case TYP_DNLOAD :
      if ($members[7] == 'on') $illegal = true;
      break;
    case TYP_FAQ :
      if ($members[4] == 'on') $illegal = true;
      break;
    case TYP_FORUM :
      if ($members[5] == 'on') $illegal = true;
      break;
    case TYP_GUESTBK :
      if ($members[12] == 'on') $illegal = true;
      break;
    case TYP_LINKS :
      if ($members[3] == 'on') $illegal = true;
      break;
    case TYP_NEWS :
      if ($members[13] == 'on') $illegal = true;
      break;
    case TYP_PHOTO :
      if ($members[2] == 'on') $illegal = true;
      break;
    case TYP_AGENDA :
      if ($members[14] == 'on') $illegal = true;
      break;
    }
    if ($illegal) {
      die('STOP ! Illegal search !');
    }
  } else {
    $searchall = array (TYP_ART, TYP_DNLOAD, TYP_FAQ, TYP_FORUM, TYP_FREEBOX1, TYP_FREEBOX2, TYP_FREEBOX3, TYP_FREEBOX4, TYP_GUESTBK, TYP_HOMEPG, TYP_LINKS, TYP_NEWS, TYP_PHOTO, TYP_SPECIAL, TYP_REACT, TYP_AGENDA, TYP_BLOG, TYP_REBLOG);
    $searchfor = array();
    foreach ($searchall as $typ) {
      switch ($typ) {
      case TYP_ART :
      case TYP_REACT :
        if ($members[1] != 'on') $searchfor[] = $typ; else $restricted = true;
        break;
      case TYP_BLOG :
      case TYP_REBLOG :
        if ($members[15] != 'on') $searchfor[] = $typ; else $restricted = true;
        break;
      case TYP_DNLOAD :
        if ($members[7] != 'on') $searchfor[] = $typ; else $restricted = true;
        break;
      case TYP_FAQ :
        if ($members[4] != 'on') $searchfor[] = $typ; else $restricted = true;
        break;
      case TYP_FORUM :
        if ($members[5] != 'on') $searchfor[] = $typ; else $restricted = true;
        break;
      case TYP_GUESTBK :
        if ($members[12] != 'on') $searchfor[] = $typ; else $restricted = true;
        break;
      case TYP_LINKS :
        if ($members[3] != 'on') $searchfor[] = $typ; else $restricted = true;
        break;
      case TYP_NEWS :
        if ($members[13] != 'on') $searchfor[] = $typ; else $restricted = true;
        break;
      case TYP_PHOTO :
        if ($members[2] != 'on') $searchfor[] = $typ; else $restricted = true;
        break;
      case TYP_AGENDA :
        if ($members[14] != 'on') $searchfor[] = $typ; else $restricted = true;
        break;
      default :
        $searchfor[] = $typ;
      }
      unset($searchall);
    }
  }
} else {
  $searchfor = array (TYP_ART, TYP_DNLOAD, TYP_FAQ, TYP_FORUM, TYP_FREEBOX1, TYP_FREEBOX2, TYP_FREEBOX3, TYP_FREEBOX4, TYP_GUESTBK, TYP_HOMEPG, TYP_LINKS, TYP_NEWS, TYP_PHOTO, TYP_SPECIAL, TYP_REACT, TYP_AGENDA, TYP_BLOG, TYP_REBLOG);
}

function Rechercher($tokens, $string) {
  $res = 0;
  for ($i=0; $i < count($tokens); $i++) {
    $r = preg_match_all("\"".$tokens[$i]."\"", $string, $x);
    if (($r !== false) && ($r > 0)) $res += (10 + max(10-$i, 1))*(9 + min($r, 10));
  }
  return $res;
}
$longword = 100;
$longbarre = 75;
$nbresult = 10;

$search = stripslashes(trim($search));
$found = array();

$search = str_replace(array("^", "[", "]", ".", "+", "?", "*", "|"), "", $search);
$search = str_replace(array('(', ')'), ' ', $search);

if (!empty($search)) {
  $searchlower = strtolower($search);

  $nbres = preg_match_all('/[ \t]*"([^ \t"]+[^"]*[^ \t"]+)"[ \t]*|[ \t]*([^ \t]+)[ \t]*/', $searchlower, $res);
  if (($nbres !== false) && ($nbres > 0)) {
    $search = "";
    for ($i=0; $i < count($res[1]); $i++) {
      if (empty($res[1][$i])) {
        $tokens[] = str_replace(array("/", "\""), array("\/", ""), trim($res[0][$i]));
        $search .= $tokens[$i]." " ;
      }
      else {
        $tokens[] = str_replace("/", "\/", $res[1][$i]);
        $search .= '"'.$tokens[$i].'" ';
      }
    }
    $search = trim($search);

    if (!empty($searchin)) {
      $dbwork = SelectDBFields($searchin,"a","");
    }
    else {
      $dbwork = SelectDBFieldsByStatus(ReadDBFields(DOCID),"a");
    }
    @rsort($dbwork);

    $type_unilingue = array(TYP_GUESTBK, TYP_REACT, TYP_REBLOG, TYP_FORUM);
    $searchlng0 = (empty($searchlng) || $searchlng == $lang[0]);
    $searchlng1 = (empty($searchlng) || $searchlng == $lang[1]);

    $j = 0;
    for ($i = 0; $i < count($dbwork); $i++) {
      ReadDoc(DBBASE.$dbwork[$i][1]);
      /// début modif accès réservé
      $acces = "ok";
      if ($fieldmod != "") {
        $acces = "no";
        if ($userprefs[1] != "") {
          include_once (CHEMIN.'inc/func_groups.php');
          if (CheckGroup($fieldmod, $userprefs[1])) $acces ="ok";
        }
      }
      if ($acces == "ok") {
      /// fin modif accès réservé
      if ((empty($type)) || (!in_array($type,$searchfor))) continue;
      $unilingue = in_array($type, $type_unilingue);
      if ($searchlng0 || $unilingue) {
        $txt = strtolower($fielda1." ".$fieldb1." ".$fieldc1);
        $note = Rechercher($tokens, $txt);
        if ($note > 0) {
          $found[0][$j] = $note;
          $found[1][$j] = (empty($moddate) ? $creadate : $moddate);
          $found[2][$j] = ($unilingue ? 0 : 1);
          $found[3][$j] = $type;
          $found[4][$j] = $dbwork[$i][1];
          $j++;
        }
      }
      if ($searchlng1) {
        $txt = strtolower($fielda2." ".$fieldb2." ".$fieldc2);
        $note = Rechercher($tokens, $txt);
        if ($note > 0) {
          $found[0][$j] = $note;
          $found[1][$j] = (empty($moddate) ? $creadate : $moddate);
          $found[2][$j] = 2;
          $found[3][$j] = $type;
          $found[4][$j] = $dbwork[$i][1];
          $j++;
        }
      }
      }/// fin accès réservé
    }
    unset($dbwork);

    if (count($found) > 0) {
      array_multisort($found[0], SORT_DESC, SORT_NUMERIC, $found[1], SORT_DESC, $found[2], SORT_ASC, $found[3], $found[4]);

      if (empty($searchin) || $searchin == TYP_FORUM) {
        $cattitle = array();
        if ($serviz[18] == "on") {
          $catwork = ReadDBFields(DBFORUMCAT);
          for ($i=0; $i<count($catwork); $i++){
		    $prcat = explode(',', $catwork[$i][0]);
            $cattitle[$prcat[0]][1] = $catwork[$i][1];
            $cattitle[$prcat[0]][2] = $catwork[$i][2];
          }
          unset($catwork);
        }
      }

      if (empty($searchin) || $searchin == TYP_FORUM) {
        $fridthd = array();
        $frtitle = array();
        $fridcat = array();
        $frwork = ReadDBFields(DBFORUM);
        for ($i=0; $i<count($frwork); $i++) {
          $fridthd[$frwork[$i][1]] = $frwork[$i][2];
          $frtitle[$frwork[$i][1]] = $frwork[$i][5];
          $fridcat[$frwork[$i][1]] = $frwork[$i][12];
        }
        unset($frwork);
      }
    }
  }
}

$topmess = $web59." - ".$search;
include("inc/hpage.inc");
htable($web59." - ".$search, "100%");
if (empty($id)) {
  $id = 1;
}
if (count($found[0]) != 0) {
  if (count($found[0]) == 1) {
    echo "<p align=\"center\"><strong>1</strong> ".$web60." <strong>".$search."</strong></p>";
  }
  else {
    echo "<p align=\"center\"><strong>".count($found[0])."</strong> ".$web61." <strong>".$search."</strong></p><hr /> ";
  }
  if (count($found[0]) - ($nbresult*($id-1)) >$nbresult) {
    $maxresult = $nbresult;
  } else {
    $maxresult = count($found[0]) - ($nbresult*($id-1));
  }
  $ilng = ($lng != $lang[1] ? 0 : 1);
  $prive = 0; /// modif accès privé
  for ($i = $nbresult*($id-1); $i < Min($nbresult*$id, count($found[0])); $i++) {

  ReadDoc(DBBASE.$found[4][$i]);
  /// début modif accès réservé
  $acces = "ok";
  if ($fieldmod != "") {
    $acces = "no";
    if ($userprefs[1] != "") {
      include_once (CHEMIN.'inc/func_groups.php');
      if (CheckGroup($fieldmod, $userprefs[1])) $acces ="ok";
    }
  }
  /// fin modif accès réservé
  $doctit = "";
  $doclnk = "";
  $doctxt = "";
  $docinv = "";
  switch ($found[2][$i]) {
  case 0 :
    $doclang = "lang";
    switch ($found[3][$i]) {
    case TYP_GUESTBK :
      $doctit = "<strong>".$nom[9 + 10 * $ilng]." :</strong> ".$web39." <strong>".$fielda1."</strong> - ".$web6." ".$author." ".$web7." ".FormatDate($creadate);
      $doclnk = "guestbk.php?lng=".$lng."&amp;pg=".$fileid;
      break;
    case TYP_REACT :
      $doctit0 = "<strong>".$web187." :</strong> ";
      $doctit2 = $web185.$fielda1." - ".$web6." ".$author." ".$web7." ".FormatDate($creadate);
      $doclnk = "articles.php?lng=".$lng."&amp;pg=".$fielda2."&amp;react=".$fileid;
      ReadDoc(DBBASE.$fielda2);
      $doctit1 = ($lng == $lang[0] ? $fieldb1 : $fieldb2);
      $doctit = $doctit0." <strong>".$doctit1." :</strong> ".$doctit2;
      break;
    case TYP_REBLOG :
      $doctit0 = "<strong>".$web381." - ".$web379." :</strong> ";
      $doctit2 = $web185.$fielda1." - ".$web6." ".$author." ".$web7." ".FormatDate($creadate);
      $doclnk = "blog.php?lng=".$lng."&amp;pg=".$fielda2."&amp;react=".$fileid;
      ReadDoc(DBBASE.$fielda2);
      $doctit1 = ($lng == $lang[0] ? $fieldb1 : $fieldb2);
      $doctit = $doctit0." <strong>".$doctit1." :</strong> ".$doctit2;
      break;
    case TYP_FORUM :
      /// début modif accès réservé
      $acces = "ok";
      if (preg_match('/^pr/i', $fridcat[$fielda1])) {
        $acces = "no";
        if ($userprefs[1] != "") {
          include_once (CHEMIN.'inc/func_groups.php');
          if (CheckGroup($fridcat[$fielda1], $userprefs[1])) $acces ="ok";
        }
      }
      /// fin modif accès réservé
      $doctit  = "<strong>".$nom[22 + $ilng]."</strong>";
      if ($serviz[18] == "on") {
        $doctit .= " : <strong>".$cattitle[$fridcat[$fielda1]][1 + $ilng]."</strong>";
      }
      if (!empty($fieldb1)) {
        $doctit .= " : ".$web63." ".$fielda1." <strong>".$fieldb1."</strong>";
        $doclnk = "thread.php?lng=".$lng."&amp;pg=".$fileid."&amp;cat=".$fieldb2;  
      } else {
        $doctit .= " : ".$web63." ".$fielda1." <strong>".$frtitle[$fielda1]."</strong> - ".$web68.$fielda2;
        $doclnk = "thread.php?lng=".$lng."&amp;pg=".$fridthd[$fielda1]."&amp;id=".ceil($fielda2/$serviz[20])."&cat=".$fridcat[$fielda1]."#".$fielda2;
      }
      $doctit .= " - ".$web6." ".$author." ".$web7." ".FormatDate($creadate);
      break;
    }
    $doctxt = WrapLongWords(CutLongWord(strip_tags($fieldc1), $longword));
    $doctxtlong = $fieldc1;
    break;
  case 1 :
    $doclang = $lang[0];
    switch ($found[3][$i]) {
    case TYP_ART :
      switch($fieldd1) {
      case 'right' :
        $doctit = "<strong>".$nom[30]." :</strong> ";
        break;
      case 'left' :
        $doctit = "<strong>".$nom[4]." :</strong> ";
        break;
      default :
        $doctit = "<strong>??? :</strong> ";
      }
      if (!empty($fielda1))
        $doctit .= " <strong>".$fielda1."</strong> - ";
      $doctit .= "<strong>".$fieldb1."</strong>";
      $doctit .= " - ".$web6." ".$author." ".$web7." ".FormatDate($moddate);
      $doclnk = "articles.php?lng=".$lang[0]."&amp;pg=".$fileid;
      break;
    case TYP_DNLOAD :
      $doctit = "<strong>".$nom[1]." :</strong> ".$fieldb1;
      $doctit .= " - ".$web6." ".$author." ".$web7." ".FormatDate($moddate);
      $doclnk = "download.php?lng=".$lang[0]."&amp;pg=".$fileid;
      break;
    case TYP_HOMEPG :
      $doctit = "<strong>".$nom[0]."</strong>";
      $doctit .= " - ".$web6." ".$author." ".$web7." ".FormatDate($moddate);
      $doclnk = "index.php?lng=".$lang[0];
        break;
    case TYP_LINKS :
      $doctit = "<strong>".$nom[3]." :</strong> ".$fieldb1;
      $doclnk = "links.php?lng=".$lang[0]."&amp;pg=".$fileid;
      break;
    case TYP_NEWS :
      $doctit = "<strong>".$nom[7]." :</strong> <strong>".$fieldb1."</strong>";
      $doctit .= " - ".$web6." ".$author." ".$web7." ".FormatDate($moddate);
      $doclnk = "news.php?lng=".$lang[0]."&amp;pg=".$fileid;
      break;
    case TYP_BLOG :
      $doctit = "<strong>".$nom[42]." :</strong> <strong>".$fieldb1."</strong>";
      $doctit .= " - ".$web6." ".$author." ".$web7." ".FormatDate($moddate);
      $doclnk = "blog.php?lng=".$lang[0]."&amp;pg=".$fileid;
      break;
    case TYP_SPECIAL :
      $doctit = "<strong>".$nom[5]."</strong>";
      $doclnk = "index.php?lng=".$lang[0];
      break;
    case TYP_FREEBOX1 :
    case TYP_FREEBOX2 :
    case TYP_FREEBOX3 :
    case TYP_FREEBOX4 :
      $doctit = "<strong>".$fieldb1."</strong>";
      $doctit .= " - ".$web6." ".$author." ".$web7." ".FormatDate($moddate);
      $doclnk = "index.php?lng=".$lang[0];
      break;
    case TYP_FAQ :
      $doctit = "<strong>".$nom[24]." :</strong> ".$fieldb1;
      $doclnk = "faq.php?lng=".$lang[0]."&amp;pg=".$fileid;
      break;
    case TYP_PHOTO :
      $doctit = "<strong>".$nom[2]." :</strong> ".$fieldb1;
      $doclnk = "photorama.php?lng=".$lang[0]."&amp;pg=".$fileid;
      break;
    case TYP_AGENDA :
      $doctit = $web287." ".$fieldb1;
      $doclnk = "agenda.php?lng=".$lang[0]."&amp;idpg=".$fileid."/&amp;pg=".$fileid."&agv=1";
      break;
    }
    $doctxt = WrapLongWords(CutLongWord(strip_tags($fieldc1), $longword));
    $doctxtlong = $fieldc1;
    break;
  case 2 :
    $doclang = $lang[1];
    switch ($found[3][$i]) {
    case TYP_ART :
      switch($fieldd1) {
      case 'right' :
        $doctit = "<strong>".$nom[31]." :</strong> ";
        break;
      case 'left' :
        $doctit = "<strong>".$nom[14]." :</strong> ";
        break;
      default :
        $doctit = "<strong>??? :</strong> ";
      }
      if (!empty($fielda2))
        $doctit .= " <strong>".$fielda2."</strong> - ";
      $doctit .= "<strong>".$fieldb2."</strong>";
      $doctit .= " - ".$web6." ".$author." ".$web7." ".FormatDate($moddate);
      $doclnk = "articles.php?lng=".$lang[1]."&amp;pg=".$fileid;
      break;
    case TYP_DNLOAD :
      $doctit = "<strong>".$nom[11]." :</strong> ".$fieldb2;
      $doctit .= " - ".$web6." ".$author." ".$web7." ".FormatDate($moddate);
      $doclnk = "download.php?lng=".$lang[1]."&amp;pg=".$fileid;
      break;
    case TYP_HOMEPG :
      $doctit = "<strong>".$nom[10]."</strong>";
      $doctit .= " - ".$web6." ".$author." ".$web7." ".FormatDate($moddate);
      $doclnk = "index.php?lng=".$lang[1];
      break;
    case TYP_LINKS :
      $doctit = "<strong>".$nom[13]." :</strong> ".$fieldb1;
      $doclnk = "links.php?lng=".$lang[1]."&amp;pg=".$fileid;
      break;
    case TYP_BLOG :
      $doctit = "<strong>".$nom[42]." :</strong> <strong>".$fieldb1."</strong>";
      $doclnk = "blog.php?lng=".$lang[0]."&amp;pg=".$fileid;
      break;
    case TYP_NEWS :
      $doctit = "<strong>".$nom[17]." :</strong> <strong>".$fieldb2."</strong> - ".$web6." ".$author." ".$web7." ".FormatDate($moddate);
      $doclnk = "news.php?lng=".$lang[1]."&amp;pg=".$fileid;
      break;
   case TYP_SPECIAL :
      $doctit = "<strong>".$nom[15]."</strong>";
      $doclnk = "index.php?lng=".$lang[1];
      break;
    case TYP_FREEBOX1 :
    case TYP_FREEBOX2 :
    case TYP_FREEBOX3 :
    case TYP_FREEBOX4 :
      $doctit = "<strong>".$fieldb2."</strong>";
      $doclnk = "index.php?lng=".$lang[1];
      break;
    case TYP_FAQ :
      $doctit = "<strong>".$nom[25]." :</strong> ".$fieldb2;
      $doclnk = "faq.php?lng=".$lang[1]."&amp;pg=".$fileid;
      break;
    case TYP_PHOTO :
      $doctit = "<strong>".$nom[12]." :</strong> ".$fieldb2;
      $doclnk = "photorama.php?lng=".$lang[1]."&amp;pg=".$fileid;
      break;
    case TYP_AGENDA :
      $doctit = $web287." ".$fieldb1;
      $doclnk = "agenda.php?lng=".$lang[0]."&amp;idpg=".$fileid."/&amp;pg=".$fileid."&agv=1";
      break;
    }
    $doctxt = WrapLongWords(CutLongWord(strip_tags($fieldc2), $longword));
    $doctxtlong = $fieldc2;
    break;
  }
  for ($j=0; $j<count($tokens); $j++) {
    $doctxt = preg_replace("/(".$tokens[$j].")/i", "<strong>\\1</strong>", $doctxt);
  }

  $doctit = strip_tags($doctit, "<strong>");

  $pourcent = ceil($found[0][$i]/$found[0][0]*$longbarre);
  /// debut modif privé
  if ($acces == "ok") {
  /// fin modif privé
  echo "\n<table class=\"bord\" summary=\"\">";
  echo "\n<tr style=\"margin:0px; background-color:".$forum[1]."\">";
  echo "\n<td><img src=\"".CHEMIN."inc/img/bars/vert.gif\" alt=\"\" style=\"width:".$pourcent."px; height:16px; vertical-align:middle\" />";
  if ($pourcent <$longbarre) {
    echo "<img src=\"".CHEMIN."inc/img/bars/jaune.gif\" alt=\"\" style=\"width:".($longbarre-$pourcent)."px; height:16px; vertical-align:middle\" />";
  }
  echo "&nbsp;<img src=\"inc/lang/".$doclang.".gif\" alt=\"".$doclang."\" style=\"width:24px; height:16px; vertical-align:middle\" /></td>";
  echo "\n<td style=\"width:100%\">&nbsp;<a href=\"".$doclnk."\" alt=\"".$web326."\" title=\"".$web326."\">".$doctit."</a></td></tr>";
  echo "\n<tr><td colspan=\"2\" style=\"padding:4px; background-color:".$forum[2]."\">";
/// Version courte
  echo "\n<div id=\"court".$i."\">";
  echo "\n<img src=\"inc/img/general/plus.gif\" alt=\"".$web429."\" title=\"".$web429."\" style=\"height:16px; width:15px; vertical-align:middle; cursor:pointer\" onclick=\"ActiveMenu('court','long',".$nbresult*($id-1).",".$maxresult.",".$i.")\" />";
  echo "\n &nbsp; ".$doctxt." ...</div>";
/// Version longue
  echo "\n<div id=\"long".$i."\" style=\"display:none\"><div>";
  echo "\n<img src=\"inc/img/general/minus.gif\" alt=\"".$web57."\" title=\"".$web57."\" style=\"height:16px; width:15px; vertical-align:middle; cursor:pointer\" onclick=\"DesactiveItem('court','long',".$i.")\" />";
  echo "\n</div>";
  if (strlen($doctxtlong) > 750) {
    echo "\n<div style=\"overflow:auto; height:300px;\">".$doctxtlong."</div></div>";
  } else {
    echo "\n<div>".$doctxtlong."</div></div>";
  }
  echo "\n</td></tr></table><br />";
  } else {$prive++;}
  ///fin accès réservé
}
}
else {
  echo "<p align=\"center\">".$web62."</p>";
}
echo GetNavBar(
  "search.php?lng=".$lng.(!empty($cat)? "&amp;cat=".$cat : "")."&amp;search=".$search."&amp;searchin=".$searchin."&amp;searchlng=".$searchlng."&amp;id=",
  count($found[0]), $id, $nbresult);
/// début modif accès privé
if ($prive > 0) {
  echo '<hr />
<p style="text-align:center"><strong>... '.$web446.'</strong></p>';
}
/// fin modif accès privé
if ($restricted) {
    echo '
<hr />
<p style="text-align:center">'.$web441.'</p>
<p align="center">[ <a href="'.CHEMIN.'user.php?lng='.$lng.'" title="'.$web343.'">'.$web343.'</a> ]</p>';
}
btable();
include("inc/bpage.inc");
?>
