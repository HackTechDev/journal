<?php
/*
    Download- GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v2.4 (24 September 2003)    : initial release (by Nicolas Alves and Laurent Duveau)
      v4.5.12 (09 March 2006)     : added numeric control of $pg (by JeanMi)
      v4.6.0 (04 June 2007)       : added openning of documents in a resizable window (by JeanMi)
                                    changed serviz[35] by serviz[10]] (thanks OpenGuppy)
      v4.6.3 (30 August 2007)     : corrected 2nd language and licence (by Icare)
      v4.6.9 (25 December 2008)   : added corrections for validation of W3C
      v4.6.11 (11 December 2009)  : changed timeout delay by 24000
      v4.6.15 (30 June 2011)      : added private management of download (by Icare)
                                    added control of $pg type (by Icare)
      v4.6.16 (02 September 2011) : corrected private management of download (by Laroche)
      v4.6.20 (24 May 2012)       : corrected $li (by Saxbar)	  
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");

if ($serviz[10] != "on") {
    exit($web143);
}
$pg = strip_tags($pg);
$li = htmlentities(strip_tags($li), ENT_QUOTES);
if (!is_numeric($pg)) {
    die('STOP ! Variable $pg : illegal value ('.$pg.')');
}
if (import('dn', 'GET') != NULL) die('STOP ! Variable $dn: illegal origine !');

/// Ajout du paramètre $delay (== 0 sinon 5)
$delay = strip_tags($delay) == 0 ? 5 : 0;

function CalcDownloadTime($file_size,$modem_speed) {
    global $web37,$web202,$web203;
    if ($file_size == $web37) {
        $calctime = $web37;
    }
    else {
        $secondes=round($file_size/($modem_speed/10));
        $minutes=intval($secondes/60);
        $secondes=$secondes-60*$minutes;
        $calctime = $minutes." ".$web202." ".$secondes." ".$web203;
    }
    return $calctime;
}

if (!empty($pg)) {
    ReadDoc(DBBASE.$pg);
if ($type != "dn") {
    die('STOP ! Variable $pg : illegal value ('.$pg.')');
}
    /// début accès réservé groupe privé
    $acces = "ok";
    if ($fieldmod != "") {
      $acces = "no";
      if ($userprefs[1] != "") {
        include_once (CHEMIN.'inc/func_groups.php');
        if (CheckGroup($fieldmod, $userprefs[1])) $acces ="ok";
      }
    }
    /// fin accès réservé
  if($acces == 'ok') {
    if ($lng == $lang[0]) {
        $nomdw = $fieldb1;
        $urldw = $fieldd1;
    }
    else {
        $nomdw = $fieldb2;
        $urldw = $fieldd2;
        if (stristr($urldw, 'file') === false) $urldw =  $fieldd1; //compatibility 4.6
    }
    $licence = $li; // licence name
    $nomfl = basename ($urldw);
    $sizefl = FileSizeInKb($urldw);
    if ($sizefl === false) {
        $sizefl = $web37;
    }
    else {
        $sizefl .= " ".$web28;
    }
    $modfl = @filemtime($urldw);
    if ($modfl === false) {
        $modfl = $web37;
    }
    else {
        $modfl = FormatDateStamp($modfl);
    }
    $dnldfl = @filemtime(DBBASE.$pg.DBEXT);
    if ($dnldfl === false) {
        $dnldfl = $web37;
    }
    else {
        $dnldfl = FormatDateStamp($dnldfl);
    }
    $dnldcounter = ReadDocCounter(DBBASE.$pg);
    UpdateDocCounter($pg);
    if ($dnldcounter <= 1) {
        $txtcount = $dnldcounter." ".$web188;
    }
    else {
        $txtcount = $dnldcounter." ".$web189;
    }
    echo '
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>'.$web192.'</title>

<meta http-equiv="Content-Type" content="text/html; charset='.$charset.'" />
<meta name="Robots" content="None" />';
if (isset($dn) || $licence == "") {
echo'<meta http-equiv="Refresh" CONTENT="'.$delay.'; URL='.$urldw.'" />';}

    if (file_exists($meskin."style.css")) {
        echo '
<link type="text/css" rel="stylesheet" href="'.$meskin.'style.css" />';
    }
    else {
        echo '
<style type="text/css">';
        if (file_exists($meskin."style.inc")) {
            include($meskin."style.inc");
        }
        else {
            include(CHEMIN."inc/style.inc");
        }
        echo '
</style>';
    }
    echo '</head>';
// début modif licence
if (!isset($dn) && $licence !=""){
  echo '<body style="padding:4px;">';
  echo "<br /><div class='bord2 rep' style='padding:5px; margin:2px; height:240px; overflow:auto;'>";
  include(CHEMIN."inc/dwnld.inc");
  echo "</div>";
  ?>
  <form name="choice" action="dwnld.php?pg=<?php echo $pg; ?>" method="post">
  <input type="hidden" name="lng" value="<?php echo $lng; ?>" />
  <input type="hidden" name="pg" value="<?php echo $pg; ?>" />
  <input type="hidden" name="dn" value="yes" />
  <div style="text-align:right"><br />
  <?php echo $boutonleft; ?><button type="submit" title="<?php echo $web414; ?>"  onclick="javascript:window.close();"><?php echo $web414; ?></button><?php echo $boutonright; ?>
  &nbsp;&nbsp;
  <?php echo $boutonleft; ?><button type="submit" title="<?php echo $web415; ?>"><?php echo $web415; ?></button><?php echo $boutonright; ?>
  &nbsp;
  </div>
  </form>

  <?php
}
else {
echo '<body style="padding-top:40px;" onLoad="setTimeout(\'self.close();\',24000)">';
// fin modif
  echo '
  <fieldset>
  <p align="center">'.$web193.'</p>
  <br />
  <div align="center">
  <table>
  <tr><td align="right" nowrap>'.$web218.'&nbsp;</td>
  <td align="left" nowrap><b>'.$nomdw.'</b></td></tr>
  <tr><td align="right" nowrap>'.$web194.'&nbsp;</td>
  <td align="left" nowrap><b><a href="'.$urldw.'" target="mainFrame"><b>'.$nomfl.'</a></b></td></tr>
  <tr><td align="right" nowrap>'.$web196.'&nbsp;</td>
  <td align="left" nowrap>'.$modfl.'</td></tr>
  <tr><td align="right" nowrap>'.$web199.'&nbsp;</td>
  <td align="left" nowrap>'.$txtcount.'</td></tr>
  <tr><td align="right" nowrap>'.$web197.'&nbsp;</td>
  <td align="left" nowrap>'.$dnldfl.'</td></tr>
  <tr><td align="right" noWrap>'.$web195.'&nbsp;</td>
  <td align="left" nowrap>'.$sizefl.'</td></tr>
  <tr><td align="right" nowrap>'.$web198.'&nbsp;</td>
  <td align="left" nowrap>'.CalcDownloadTime($sizefl,512).'</td></tr>
  <tr><td align="right" nowrap>'.$web200.'&nbsp;</td>
  <td align="left" nowrap>'.CalcDownloadTime($sizefl,56).'</td></tr>
  <tr><td align="right" nowrap>'.$web201.'&nbsp;</td>
  <td align="left" nowrap>'.CalcDownloadTime($sizefl,33.6).'</td></tr>
  </table>
  </div>
  </fieldset>';
}
echo '</body>
</html>';
  }
}
?>
