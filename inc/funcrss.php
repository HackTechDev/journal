<?php
/*
    RSS News Publication Functions - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v3.0 (25 February 2004)  : initial release
      v4.0 (06 December 2004)  : no change
      v4.6.8 (24 May 2008)     : deletion of strip_tags() in EncodeIso function (by Icare)
      v4.6.9 (25 December 2008): correction of email into RSS #225
                                 addition of the field pubDate in flows RSS #240
      v4.6.10 (7 September 2009)    : corrected #253
      v4.6.15 (30 June 2011): no feed for private document (by Icare)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "funcrss.inc")) {
  header("location:../index.php");
  die();
}

function EncodeISO($textin,$code) {
  if ($code == "88591") {
    $textout = htmlentities($textin);
    //$textout = str_replace("&quot;",  "&#34;",$textout);
    $textout = str_replace("&nbsp;",  "&#160;",$textout);
    $textout = str_replace("&iexcl;", "&#161;",$textout);
    $textout = str_replace("&cent;",  "&#162;",$textout);
    $textout = str_replace("&pound;", "&#163;",$textout);
    $textout = str_replace("&curren;","&#164;",$textout);
    $textout = str_replace("&yen;",   "&#165;",$textout);
    $textout = str_replace("&brvbar;","&#166;",$textout);
    $textout = str_replace("&sect;",  "&#167;",$textout);
    $textout = str_replace("&uml;",   "&#168;",$textout);
    $textout = str_replace("&copy;",  "&#169;",$textout);
    $textout = str_replace("&ordf;",  "&#170;",$textout);
    $textout = str_replace("&laquo;", "&#171;",$textout);
    $textout = str_replace("&not;",   "&#172;",$textout);
    $textout = str_replace("&shy;",   "&#173;",$textout);
    $textout = str_replace("&reg;",   "&#174;",$textout);
    $textout = str_replace("&macr;",  "&#175;",$textout);
    $textout = str_replace("&deg;",   "&#176;",$textout);
    $textout = str_replace("&plusmn;","&#177;",$textout);
    $textout = str_replace("&sup2;",  "&#178;",$textout);
    $textout = str_replace("&sup3;",  "&#179;",$textout);
    $textout = str_replace("&acute;", "&#180;",$textout);
    $textout = str_replace("&micro;", "&#181;",$textout);
    $textout = str_replace("&para;",  "&#182;",$textout);
    $textout = str_replace("&middot;","&#183;",$textout);
    $textout = str_replace("&cedil;", "&#184;",$textout);
    $textout = str_replace("&sup1;",  "&#185;",$textout);
    $textout = str_replace("&ordm;",  "&#186;",$textout);
    $textout = str_replace("&raquo;", "&#187;",$textout);
    $textout = str_replace("&frac14;","&#188;",$textout);
    $textout = str_replace("&frac12;","&#189;",$textout);
    $textout = str_replace("&frac34;","&#190;",$textout);
    $textout = str_replace("&iquest;","&#191;",$textout);
    $textout = str_replace("&Agrave;","&#192;",$textout);
    $textout = str_replace("&Aacute;","&#193;",$textout);
    $textout = str_replace("&Acirc;", "&#194;",$textout);
    $textout = str_replace("&Atilde;","&#195;",$textout);
    $textout = str_replace("&Auml;",  "&#196;",$textout);
    $textout = str_replace("&Aring;", "&#197;",$textout);
    $textout = str_replace("&AElig;", "&#198;",$textout);
    $textout = str_replace("&Ccedil;","&#199;",$textout);
    $textout = str_replace("&Egrave;","&#200;",$textout);
    $textout = str_replace("&Eacute;","&#201;",$textout);
    $textout = str_replace("&Ecirc;", "&#202;",$textout);
    $textout = str_replace("&Euml;",  "&#203;",$textout);
    $textout = str_replace("&Igrave;","&#204;",$textout);
    $textout = str_replace("&Iacute;","&#205;",$textout);
    $textout = str_replace("&Icirc;", "&#206;",$textout);
    $textout = str_replace("&Iuml;",  "&#207;",$textout);
    $textout = str_replace("&ETH;",   "&#208;",$textout);
    $textout = str_replace("&Ntilde;","&#209;",$textout);
    $textout = str_replace("&Ograve;","&#210;",$textout);
    $textout = str_replace("&Oacute;","&#211;",$textout);
    $textout = str_replace("&Ocirc;", "&#212;",$textout);
    $textout = str_replace("&Otilde;","&#213;",$textout);
    $textout = str_replace("&Ouml;",  "&#214;",$textout);
    $textout = str_replace("&times;", "&#215;",$textout);
    $textout = str_replace("&Oslash;","&#216;",$textout);
    $textout = str_replace("&Ugrave;","&#217;",$textout);
    $textout = str_replace("&Uacute;","&#218;",$textout);
    $textout = str_replace("&Ucirc;", "&#219;",$textout);
    $textout = str_replace("&Uuml;",  "&#220;",$textout);
    $textout = str_replace("&Yacute;","&#221;",$textout);
    $textout = str_replace("&THORN;", "&#222;",$textout);
    $textout = str_replace("&szlig;", "&#223;",$textout);
    $textout = str_replace("&agrave;","&#224;",$textout);
    $textout = str_replace("&aacute;","&#225;",$textout);
    $textout = str_replace("&acirc;", "&#226;",$textout);
    $textout = str_replace("&atilde;","&#227;",$textout);
    $textout = str_replace("&auml;",  "&#228;",$textout);
    $textout = str_replace("&aring;", "&#229;",$textout);
    $textout = str_replace("&aelig;", "&#230;",$textout);
    $textout = str_replace("&ccedil;","&#231;",$textout);
    $textout = str_replace("&egrave;","&#232;",$textout);
    $textout = str_replace("&eacute;","&#233;",$textout);
    $textout = str_replace("&ecirc;", "&#234;",$textout);
    $textout = str_replace("&euml;",  "&#235;",$textout);
    $textout = str_replace("&igrave;","&#236;",$textout);
    $textout = str_replace("&iacute;","&#237;",$textout);
    $textout = str_replace("&icirc;", "&#238;",$textout);
    $textout = str_replace("&iuml;",  "&#239;",$textout);
    $textout = str_replace("&eth;",   "&#240;",$textout);
    $textout = str_replace("&ntilde;","&#241;",$textout);
    $textout = str_replace("&ograve;","&#242;",$textout);
    $textout = str_replace("&oacute;","&#243;",$textout);
    $textout = str_replace("&ocirc;", "&#244;",$textout);
    $textout = str_replace("&otilde;","&#245;",$textout);
    $textout = str_replace("&ouml;",  "&#246;",$textout);
    $textout = str_replace("&divide;","&#247;",$textout);
    $textout = str_replace("&oslash;","&#248;",$textout);
    $textout = str_replace("&ugrave;","&#249;",$textout);
    $textout = str_replace("&uacute;","&#250;",$textout);
    $textout = str_replace("&ucirc;", "&#251;",$textout);
    $textout = str_replace("&uuml;",  "&#252;",$textout);
    $textout = str_replace("&yacute;","&#253;",$textout);
    $textout = str_replace("&thorn;", "&#254;",$textout);
    $textout = str_replace("&yuml;",  "&#255;",$textout);
  }
  return $textout;
}

function PubDate($creadate) {
    return date('r',
        mktime(
            substr($creadate, 8, 2),
            substr($creadate, 10, 2),
            0,
            substr($creadate, 4, 2),
            substr($creadate, 6, 2),
            substr($creadate, 0, 4)
        ));
}

function UpdateDBnews() {
  global $mpversion,$site,$user,$lang,$lng,$site,$serviz,$type,$fileid,$status,$creadate,$moddate,$author,$email,$fielda1,$fielda2,$fieldb1,$fieldb2,$fieldc1,$fieldc2,$fieldd1,$fieldd2,$fieldmod;
  $ISOcode = "88591";
  if ($serviz[16] == "on") {
    $dbwork1 = SelectDBFields(TYP_NEWS,"a","");
    @rsort($dbwork1);
    if ($lang[1] != "") {
      include(CHEMIN."inc/lang/".$lang[1]."-web".INCEXT);
      $par2 = $web6;
      $le2 = $web7;
    }
    include(CHEMIN."inc/lang/".$lang[0]."-web".INCEXT);
    $par1 = $web6;
    $le1 = $web7;
    include(CHEMIN."inc/lang/".$lng."-web".INCEXT);
    $sito = $site[3];
    if ($sito[strlen($sito)-1] != "/") {
      $sito .= "/";
    }
    $rsstxt1 = "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\n"; ?><?php
    $rsstxt1 .= "<!-- RSS generated by GuppY v".$mpversion." on ".EncodeISO(FormatDate(GetCurrentDateTime()),$ISOcode)." -->\n";
    $rsstxt1 .= "<rss version=\"2.0\">\n";
    $rsstxt1 .= " <channel>\n";
    $rsstxt1 .= "   <title>".EncodeISO($site[0],$ISOcode)."</title>\n";
    $rsstxt1 .= "   <link>".$sito."</link>\n";
    $rsstxt1 .= "   <description>".EncodeISO($site[1],$ISOcode)."</description>\n";
    $rsstxt2 = "   <docs>http://blogs.law.harvard.edu/tech/rss</docs>\n";
    $rsstxt2 .= "   <generator>GuppY v".$mpversion."</generator>\n";
    $rsstxt2 .= "   <managingEditor>".EncodeISO($site[11],$ISOcode)." (".EncodeISO($user[0],$ISOcode).")</managingEditor>\n";
    $rsstxt2 .= "   <webMaster>".EncodeISO($site[11],$ISOcode)." (".EncodeISO($user[0],$ISOcode).")</webMaster>\n";
    $rsstxtl1 = $rsstxt1."   <language>".$lang[0]."</language>\n".$rsstxt2;
    if ($lang[1] != "") {
      $rsstxtl2 = $rsstxt1."   <language>".$lang[1]."</language>\n".$rsstxt2;
    }

    for ($i = 0; $i < Min(count($dbwork1),$serviz[37]); $i++) {
      ReadDoc(DBBASE.$dbwork1[$i][1]);
      if ($fieldmod === "") { /// modif accès privé
        $fieldc1 = ForceToAbsolute($fieldc1);
        $fieldc2 = ForceToAbsolute($fieldc2);
        $rsstxtl1 .= "   <item>\n";
        $rsstxtl1 .= "     <title>".EncodeISO($fieldb1." - ".$par1." ".$author." ".$le1." ".FormatDate($creadate),$ISOcode)."</title>\n";
        $rsstxtl1 .= "     <link>".$sito."news.php?lng=".$lang[0]."&amp;pg=".$fileid."</link>\n";
        $rsstxtl1 .= "     <guid>".$sito."news.php?lng=".$lang[0]."&amp;pg=".$fileid."</guid>\n";
        $rsstxtl1 .= "     <description>".EncodeISO($fieldc1,$ISOcode)."</description>\n";
        $rsstxtl1 .= "     <pubDate>".PubDate($creadate)."</pubDate>\n";
        $rsstxtl1 .= "   </item>\n";
        if ($lang[1] != "") {
          $rsstxtl2 .= "   <item>\n";
          $rsstxtl2 .= "     <title>".EncodeISO($fieldb2." - ".$par2." ".$author." ".$le2." ".FormatDate($creadate),$ISOcode)."</title>\n";
          $rsstxtl2 .= "     <link>".$sito."news.php?lng=".$lang[1]."&amp;pg=".$fileid."</link>\n";
          $rsstxtl2 .= "     <guid>".$sito."news.php?lng=".$lang[1]."&amp;pg=".$fileid."</guid>\n";
          $rsstxtl2 .= "     <description>".EncodeISO($fieldc2,$ISOcode)."</description>\n";
          $rsstxtl2 .= "     <pubDate>".PubDate($creadate)."</pubDate>\n";
          $rsstxtl2 .= "   </item>\n";
        }
      } /// modif accès privé
    }
    $rsstxt3 = " </channel>\n";
    $rsstxt3 .= "</rss>\n";
    $rsstxtl1 .= $rsstxt3;
    if ($lang[1] != "") {
      $rsstxtl2 .= $rsstxt3;
    }
    WriteFullDB(DBNEWS.$lang[0].".xml",$rsstxtl1);
    if ($lang[1] != "") {
      WriteFullDB(DBNEWS.$lang[1].".xml",$rsstxtl2);
    }
  }
  else {
    WriteFullDB(DBNEWS.$lang[0].".xml","\n");
    if ($lang[1] != "") {
      WriteFullDB(DBNEWS.$lang[1].".xml","\n");
    }
  }
}

function UpdateDBblog() {
  global $mpversion,$site,$user,$lang,$lng,$site,$serviz,$type,$fileid,$status,$creadate,$moddate,$author,$email,$fielda1,$fielda2,$fieldb1,$fieldb2,$fieldc1,$fieldc2,$fieldd1,$fieldd2,$fieldmod;
  $ISOcode = "88591";
  if ($serviz[54] == "on") {
    $dbwork2 = SelectDBFields(TYP_BLOG,"a","");
    @rsort($dbwork2);
    if ($lang[1] != "") {
      include(CHEMIN."inc/lang/".$lang[1]."-web".INCEXT);
      $par2 = $web6;
      $le2 = $web7;
    }
    include(CHEMIN."inc/lang/".$lang[0]."-web".INCEXT);
    $par1 = $web6;
    $le1 = $web7;
    include(CHEMIN."inc/lang/".$lng."-web".INCEXT);
    $sito = $site[3];
    if ($sito[strlen($sito)-1] != "/") {
      $sito .= "/";
    }
    $rsstxt1 = "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\n"; ?><?php
    $rsstxt1 .= "<!-- RSS generated by GuppY v".$mpversion." on ".EncodeISO(FormatDate(GetCurrentDateTime()),$ISOcode)." -->\n";
    $rsstxt1 .= "<rss version=\"2.0\">\n";
    $rsstxt1 .= " <channel>\n";
    $rsstxt1 .= "   <title>".EncodeISO($site[0],$ISOcode)."</title>\n";
    $rsstxt1 .= "   <link>".$sito."</link>\n";
    $rsstxt1 .= "   <description>".EncodeISO($site[1],$ISOcode)."</description>\n";
    $rsstxt2 = "   <docs>http://blogs.law.harvard.edu/tech/rss</docs>\n";
    $rsstxt2 .= "   <generator>GuppY v".$mpversion."</generator>\n";
    $rsstxt2 .= "   <managingEditor>".EncodeISO($site[11],$ISOcode)." (".EncodeISO($user[0],$ISOcode).")</managingEditor>\n";
    $rsstxt2 .= "   <webMaster>".EncodeISO($site[11],$ISOcode)." (".EncodeISO($user[0],$ISOcode).")</webMaster>\n";
    $rsstxtl1 = $rsstxt1."   <language>".$lang[0]."</language>\n".$rsstxt2;
    if ($lang[1] != "") {
      $rsstxtl2 = $rsstxt1."   <language>".$lang[1]."</language>\n".$rsstxt2;
    }

    for ($i = 0; $i < Min(count($dbwork2),$serviz[56]); $i++) {
      ReadDoc(DBBASE.$dbwork2[$i][1]);
      if ($fieldmod === "") { /// modif accès privé
        $fieldc1 = ForceToAbsolute($fieldc1);
        $fieldc2 = ForceToAbsolute($fieldc2);
        $rsstxtl1 .= "   <item>\n";
        $rsstxtl1 .= "     <title>".EncodeISO($fieldb1." - ".$par1." ".$author." ".$le1." ".FormatDate($creadate),$ISOcode)."</title>\n";
        $rsstxtl1 .= "     <link>".$sito."blog.php?lng=".$lang[0]."&amp;sel=pg&amp;pg=".$fileid."</link>\n";
        $rsstxtl1 .= "     <guid>".$sito."blog.php?lng=".$lang[0]."&amp;sel=pg&amp;pg=".$fileid."</guid>\n";
        $rsstxtl1 .= "     <description>".EncodeISO($fieldc1,$ISOcode)."</description>\n";
        $rsstxtl1 .= "     <pubDate>".PubDate($creadate)."</pubDate>\n";
        $rsstxtl1 .= "   </item>\n";
        if ($lang[1] != "") {
          $rsstxtl2 .= "   <item>\n";
          $rsstxtl2 .= "     <title>".EncodeISO($fieldb2." - ".$par2." ".$author." ".$le2." ".FormatDate($creadate),$ISOcode)."</title>\n";
          $rsstxtl2 .= "     <link>".$sito."blog.php?lng=".$lang[1]."&amp;sel=pg&amp;pg=".$fileid."</link>\n";
          $rsstxtl2 .= "     <guid>".$sito."blog.php?lng=".$lang[1]."&amp;sel=pg&amp;pg=".$fileid."</guid>\n";
          $rsstxtl2 .= "     <description>".EncodeISO($fieldc2,$ISOcode)."</description>\n";
          $rsstxtl2 .= "     <pubDate>".PubDate($creadate)."</pubDate>\n";
          $rsstxtl2 .= "   </item>\n";
        }
      } /// modif accès privé
    }
    $rsstxt3 = " </channel>\n";
    $rsstxt3 .= "</rss>\n";
    $rsstxtl1 .= $rsstxt3;
    if ($lang[1] != "") {
      $rsstxtl2 .= $rsstxt3;
    }
    WriteFullDB(CHEMIN.DATAREP."blog".$lang[0].".xml",$rsstxtl1);
    if ($lang[1] != "") {
      WriteFullDB(CHEMIN.DATAREP."blog".$lang[1].".xml",$rsstxtl2);
    }
  }
  else {
    WriteFullDB(CHEMIN.DATAREP."blog".$lang[0].".xml","\n");
    if ($lang[1] != "") {
      WriteFullDB(CHEMIN.DATAREP."blog".$lang[1].".xml","\n");
    }
  }
}
function UpdateDBart() {
  global $mpversion,$site,$user,$lang,$lng,$site,$serviz,$type,$fileid,$status,$creadate,$moddate,$author,$email,$fielda1,$fielda2,$fieldb1,$fieldb2,$fieldc1,$fieldc2,$fieldd1,$fieldd2,$fieldmod;
  $ISOcode = "88591";
  if ($serviz[60] == "on") {
    $dbwork3 = SelectDBFields(TYP_ART,"a","");
    @rsort($dbwork3);
    if ($lang[1] != "") {
      include(CHEMIN."inc/lang/".$lang[1]."-web".INCEXT);
      $par2 = $web6;
      $le2 = $web7;
    }
    include(CHEMIN."inc/lang/".$lang[0]."-web".INCEXT);
    $par1 = $web6;
    $le1 = $web7;
    include(CHEMIN."inc/lang/".$lng."-web".INCEXT);
    $sito = $site[3];
    if ($sito[strlen($sito)-1] != "/") {
      $sito .= "/";
    }
    $rsstxt1 = "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\n"; ?><?php
    $rsstxt1 .= "<!-- RSS generated by GuppY v".$mpversion." on ".EncodeISO(FormatDate(GetCurrentDateTime()),$ISOcode)." -->\n";
    $rsstxt1 .= "<rss version=\"2.0\">\n";
    $rsstxt1 .= " <channel>\n";
    $rsstxt1 .= "   <title>".EncodeISO($site[0],$ISOcode)."</title>\n";
    $rsstxt1 .= "   <link>".$sito."</link>\n";
    $rsstxt1 .= "   <description>".EncodeISO($site[1],$ISOcode)."</description>\n";
    $rsstxt2 = "   <docs>http://blogs.law.harvard.edu/tech/rss</docs>\n";
    $rsstxt2 .= "   <generator>GuppY v".$mpversion."</generator>\n";
    $rsstxt2 .= "   <managingEditor>".EncodeISO($site[11],$ISOcode)." (".EncodeISO($user[0],$ISOcode).")</managingEditor>\n";
    $rsstxt2 .= "   <webMaster>".EncodeISO($site[11],$ISOcode)." (".EncodeISO($user[0],$ISOcode).")</webMaster>\n";
    $rsstxtl1 = $rsstxt1."   <language>".$lang[0]."</language>\n".$rsstxt2;
    if ($lang[1] != "") {
      $rsstxtl2 = $rsstxt1."   <language>".$lang[1]."</language>\n".$rsstxt2;
    }

    for ($i = 0; $i < Min(count($dbwork3),$serviz[37]); $i++) {
      ReadDoc(DBBASE.$dbwork3[$i][1]);
      if ($fieldmod === "") { /// modif accès privé
        $fieldc1 = ForceToAbsolute($fieldc1);
        $fieldc2 = ForceToAbsolute($fieldc2);
        $rsstxtl1 .= "   <item>\n";
        $rsstxtl1 .= "     <title>".EncodeISO($fieldb1." - ".$par1." ".$author." ".$le1." ".FormatDate($creadate),$ISOcode)."</title>\n";
        $rsstxtl1 .= "     <link>".$sito."articles.php?lng=".$lang[0]."&amp;pg=".$fileid."</link>\n";
        $rsstxtl1 .= "     <guid>".$sito."articles.php?lng=".$lang[0]."&amp;pg=".$fileid."</guid>\n";
        $rsstxtl1 .= "     <description>".EncodeISO($fieldc1,$ISOcode)."</description>\n";
        $rsstxtl1 .= "     <pubDate>".PubDate($creadate)."</pubDate>\n";
        $rsstxtl1 .= "   </item>\n";
        if ($lang[1] != "") {
          $rsstxtl2 .= "   <item>\n";
          $rsstxtl2 .= "     <title>".EncodeISO($fieldb2." - ".$par2." ".$author." ".$le2." ".FormatDate($creadate),$ISOcode)."</title>\n";
          $rsstxtl2 .= "     <link>".$sito."articles.php?lng=".$lang[1]."&amp;pg=".$fileid."</link>\n";
          $rsstxtl2 .= "     <guid>".$sito."articles.php?lng=".$lang[1]."&amp;pg=".$fileid."</guid>\n";
          $rsstxtl2 .= "     <description>".EncodeISO($fieldc2,$ISOcode)."</description>\n";
          $rsstxtl2 .= "     <pubDate>".PubDate($creadate)."</pubDate>\n";
          $rsstxtl2 .= "   </item>\n";
        }
      } /// modif accès privé
    }
    $rsstxt3 = " </channel>\n";
    $rsstxt3 .= "</rss>\n";
    $rsstxtl1 .= $rsstxt3;
    if ($lang[1] != "") {
      $rsstxtl2 .= $rsstxt3;
    }
    WriteFullDB(CHEMIN.DATAREP."art".$lang[0].".xml",$rsstxtl1);
    if ($lang[1] != "") {
      WriteFullDB(CHEMIN.DATAREP."art".$lang[1].".xml",$rsstxtl2);
    }
  }
  else {
    WriteFullDB(CHEMIN.DATAREP."art".$lang[0].".xml","\n");
    if ($lang[1] != "") {
      WriteFullDB(CHEMIN.DATAREP."art".$lang[1].".xml","\n");
    }
  }
}
?>
