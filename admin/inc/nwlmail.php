<?php
/*
    Send Newsletter - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v3.0 (25 February 2004)  : initial release by Nicolas Alves and Laurent Duveau
      v4.5 (30 March 2005)     : added security and html management (by Jean-Mi)
	                           : added correct image path (by Icare)
	  v4.6.0 (31 January 2007) : secured language file inclusion, thanks rgod
	  v4.6.9f (8 January 2009) : added conversion of the relative url in absolute url
    v4.6.10 (7 September 2009)    : corrected #253
    v4.6.15 (30 June 2011) : added newsletter for private group (by Icare)
*/

header("Pragma: no-cache");
define("CHEMIN", "../../");
include(CHEMIN."inc/reglobals.inc");
include(CHEMIN."inc/functions.php");

if (is_file(CHEMIN.INCREP."lang/".$lng."-admin".INCEXT)){
    include(CHEMIN.INCREP."lang/".$lng."-admin".INCEXT);
} else
    die('BAD Language name !');
include(CONFIG);

$listabon = ReadDBFields(DBNEWSLETTER);

if (empty($lsn)) {
    $lsn = 0; $lnb = 0;
}

echo '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>'.$admin546.'</title>
<meta http-equiv="Content-Type" content="text/html; charset='.$charset.'" />
<meta name="Robots" content="NONE" />
<script type="text/javascript" language="javascript">
function PopupWindow(page,titre,largeur,hauteur,resizeyn,scrollb) {
  var top=(screen.height-hauteur)/2;
  var left=(screen.width-largeur)/2;
  window.open(page,titre,"top="+top+", left="+left+", width="+largeur+", height="+hauteur+", directories=no, menubar=no, status=no, resizable="+resizeyn+", scrollbars="+scrollb+",location=no");
}
</script>
</head>
<body bgcolor="'.$page[0].'" leftmargin="5" topmargin="5" style="overflow: hidden;">
<fieldset>';
if ($lnb != 0) {
    echo '
<p align="center">'.$admin524.' :</p>
<p align="center">'.$lnb.'  '.$admin516.'</p>';

}elseif ($lsn != -1) {
    echo '
<p align="center">'.$admin524.'</p>
<p align="center">'.Min($lsn+1,count($listabon)).' '.$admin516.' / '.count($listabon).'</p>';
}
if ($lsn < count($listabon)) {
    ReadDoc(DBBASE.$id);
    if ($lsn != -1) {
        /// début modif groupe privé
        include_once (CHEMIN.'inc/func_groups.php');
        if (CheckGroup($fieldmod, $listabon[$lsn][0]) || $fieldmod == ""){
        /// fin modif groupe privé
            $to = $listabon[$lsn][1];
            if ($listabon[$lsn][2] == $lang[0]) {
                include(CHEMIN."inc/lang/".$lang[0]."-admin".INCEXT);
                include(CHEMIN."inc/lang/".$lang[0]."-web".INCEXT);
                $sujet = strip_tags($fieldb1);
                $body = ForceToAbsolute($fieldc1);
            } else {
                include(CHEMIN."inc/lang/".$lang[1]."-admin".INCEXT);
                include(CHEMIN."inc/lang/".$lang[1]."-web".INCEXT);
                $sujet = strip_tags($fieldb2);
                $body = ForceToAbsolute($fieldc2);
            }
            $body .= "<hr>".$admin549."<br />";
            $body .= '<a href="'.$site[3]."newsletter.php?lng=".$listabon[$lsn][2]."&action=unsub&nlpseudo=".$listabon[$lsn][0]."&nlmail=".$listabon[$lsn][1].'">';
            $body .= $site[3]."newsletter.php?lng=".$listabon[$lsn][2]."&action=unsub&nlpseudo=".$listabon[$lsn][0]."&nlmail=".$listabon[$lsn][1]."</a>";
            eMailHtmlTo($sujet,$body,$to);
        /// début modif groupe privé
            if ($fieldmod!= "") $lnb++;
        }
        $lsn++;
        $nextstep = "PopupWindow(\"nwlmail.php?lng=".$lng."&id=".$id."&lsn=".$lsn."&lnb=".$lnb."\",\"nwlmail\",400,225,\"no\",\"no\")";
        /// fin modif groupe privé
    } else {
        $to = $user[1];
        include(CHEMIN."inc/lang/".$lang[0]."-admin".INCEXT);
        include(CHEMIN."inc/lang/".$lang[0]."-web".INCEXT);
        $sujet = strip_tags($fieldb1);
        $body = ForceToAbsolute($fieldc1);
        $body .= "<hr>".$admin549."<br />";
        $body .= '<a href="'.$site[3]."newsletter.php?lng=".$lang[0]."&action=unsub&nlpseudo=".$user[0]."&nlmail=".$user[1].'">';
        $body .= $site[3]."newsletter.php?lng=".$lang[0]."&action=unsub&nlpseudo=".$user[0]."&nlmail=".$user[1]."</a>";
        eMailHtmlTo($sujet,$body,$to);
        if (!empty($lang[1])) {
            include(CHEMIN."inc/lang/".$lang[1]."-admin".INCEXT);
            include(CHEMIN."inc/lang/".$lang[1]."-web".INCEXT);
            $sujet = strip_tags($fieldb2);
            $body = ForceToAbsolute($fieldc2);
            $body .= "<hr>".$admin549."<br />";
            $body .= '<a href="'.$site[3]."newsletter.php?lng=".$lang[1]."&action=unsub&nlpseudo=".$user[0]."&nlmail=".$user[1].'">';
            $body .= $site[3]."newsletter.php?lng=".$lang[1]."&action=unsub&nlpseudo=".$user[0]."&nlmail=".$user[1]."</a>";
            eMailHtmlTo($sujet,$body,$to);
        }
        include(CHEMIN."inc/lang/".$lng."-admin".INCEXT);
        echo '
<p align="center">'.$admin758.'</p>
<p align="center">'.$admin759.$to.'</p>
<hr />
<p align="center"><b>'.$admin760.'</b></p>
<br />';
    }
} else {
    echo '
<hr />
<p align="center"><b>'.$admin522.'</b></p>';
/// début modif groupe privé
    ReadDoc(DBBASE.$id);
    if ($fieldmod != "") {
        include_once (CHEMIN.'inc/func_groups.php');
        $groups = ReadGroups();
        echo '
<p align="center"><b>'.ucfirst($admin928).' '.$fieldmod.'</b> : '.$lnb.' '.$admin516.' / '.count($groups[$fieldmod]).'</p>';
    }
/// fin modif groupe privé
    $nextstep = "";
}
echo '
</fieldset>';
if ($nextstep != "") {
    echo '
<script type="text/javascript" language="javascript">
'.$nextstep.'
</script>';
}
echo '<p style="text-align:right"><a href="#" onclick="javascritp:window.close();">'.$admin458.'</a></p>';
echo '
</body>
</html>';

