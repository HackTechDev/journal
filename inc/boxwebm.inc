<?php
/*
    Webmaster info Box - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v1.0 (30 December 2002)    : initial release
      v2.0 (27 February 2003)    : added encryption of webmaster's e-mail @ (SPAM protection)
      v2.3 (27 July 2003)        : added forms style management (by Nicolas Alves)
                                   upgraded WriteMailTo() function for better SPAM protection (thanks Michel)
      v2.4 (24 September 2003)   : no change
      v3.0 (25 February 2004)    : added skin management (by Nicolas Alves)
      v4.0 (06 December 2004)    : added the sideboxes specific style (by Isa)
                                   added mail type choice and recommend (by Icare)
      v4.5 (27 May 2005)         : changed link for reco and mail webmaster (by Icare)
      v4.5.1 (06 July 2005)      : deleted email test for mail to webmaster (by Icare)
      v4.6.0 (04 June 2007)      : changed ICQ by live messenger choice, thanks ghazette
      v4.6.6 (14 April 2008)     : added urlencode in writeMailTo() (by JeanMi)
      v4.6.9 (25 December 2008)  : added $serviz[62] to control the function To recommend ON/OFF #20
      v4.6.10 (7 September 2009) : corrected #272
      v4.6.17(21 October 2011)   : corrected display (by Saxbar)
	  v4.6.20 (24 May 2012)      : added $wmtitle (by Saxbar)
                                   corrected htable1, btable1 (by Saxbar)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "boxwebm.inc")) {
  header("location:../index.php");
  die();
}

if (!function_exists('BreakIRC')) {
    function BreakIRC($ircinput) {
      $ircinput = trim($ircinput);
  $idirc = explode('@', $ircinput, 2);
  $ircoutput[0] = $idirc[0];
  $idtemp = explode('.', $idirc[1], 9);
      $ircoutput[1] = $idtemp[0];
      $ircoutput[2] = $idtemp[1];
      return $ircoutput;
    }
}
$wmtitle = $lng==$lang[0] ? $nom[40] : $nom[41];
htable1($wmtitle, "100%");
$em = BreakEMail($user[1]);
?>
<div class="box" style="text-align: left; padding-left:4px;">
<img src="<?php echo CHEMIN ?>inc/img/general/mail.gif" alt="<?php echo "$web173 $user[0]"; ?>" title="<?php echo "$web173 $user[0]"; ?>" />
<?php
 if ($user[3] == "on")
 {
?>
<a class="box" href="<?php echo CHEMIN ?>postguest.php?lng=<?php echo $lng ?>&amp;typ=<?php echo TYP_MAIL ?>" title="<?php echo "$web173 $user[0]"; ?>">&nbsp;<?php echo $web11; ?></a>
<?php
}
else {
?>
<a class="box" href="JavaScript:WriteMailTo('<?php echo addslashes(urlencode($user[0])); ?>','<?php echo $em[0]; ?>','<?php echo $em[1]; ?>','<?php echo $em[2]; ?>')" title="<?php echo "$web173 $user[0]"; ?>">&nbsp;<?php echo $web11; ?></a>
<?php
 }
if (!empty($user[2])) $irc = BreakIRC($user[2]);
switch ($user[4]) {
  case 'ICQ':
    echo "<a class=\"box\" href=\"JavaScript:ContactMe('".$user[4]."','".$user[0]."','".$irc[0]."','".$irc[1]."','".$irc[2]."')\" title='".$web422.$user[4]."'>";
    echo '<img style="padding-left:5px;" src="'.CHEMIN.'inc/img/browser/icq.gif" alt="'.$web422.$user[4].'" title="'.$web422.$user[4].'" border="0" /></a>';
  break;
  case 'MSN':
    echo "<a class=\"box\" href=\"JavaScript:ContactMe('".$user[4]."','".$user[0]."','".$irc[0]."','".$irc[1]."','".$irc[2]."')\" title='".$web422.$user[4]."'>";
    echo '<img style="padding-left:5px;" src="'.CHEMIN.'inc/img/browser/msn.gif" alt="'.$web422.$user[4].'" title="'.$web422.$user[4].'" border="0" /></a>';
  break;
  case 'Yahoo':
    echo "<a class=\"box\" href=\"JavaScript:ContactMe('".$user[4]."','".$user[0]."','".$irc[0]."','".$irc[1]."','".$irc[2]."')\" title='".$web422.$user[4]."'>";
    echo '<img style="padding-left:5px;" src="'.CHEMIN.'inc/img/browser/yahoo.gif" alt="'.$web422.$user[4].'" title="'.$web422.$user[4].'" border="0" /></a>';
  break;
  case 'Gtalk':
    echo "<a class=\"box\" href=\"JavaScript:ContactMe('".$user[4]."','".$user[0]."','".$irc[0]."','".$irc[1]."','".$irc[2]."')\" title='".$web422.$user[4]."'>";
    echo '<img style="padding-left:5px;" src="'.CHEMIN.'inc/img/browser/googletalk.gif" alt="'.$web422.$user[4].'" title="'.$web422.$user[4].'" border="0" /></a>';
  break;
  case 'Skype':
    echo "<a class=\"box\" href=\"JavaScript:ContactMe('".$user[4]."','".$user[0]."','".$irc[0]."','".$irc[1]."','".$irc[2]."')\" title='".$web422.$user[4]."'>";
    echo '<img style="padding-left:5px;" src="'.CHEMIN.'inc/img/browser/skype.gif" alt="'.$web422.$user[4].'" title="'.$web422.$user[4].'" border="0" /></a>';
  break;
  case 'AIM':
    echo "<a class=\"box\" href=\"JavaScript:ContactMe('".$user[4]."','".$user[0]."','".$irc[0]."','".$irc[1]."','".$irc[2]."')\" title='".$web422.$user[4]."'>";
    echo '<img style="padding-left:5px;" src="'.CHEMIN.'inc/img/browser/aim.gif" alt="'.$web422.$user[4].'" title="'.$web422.$user[4].'" border="0" /></a>';
  break;
  case 'Teamspeak':
    echo "<a class=\"box\" href=\"JavaScript:ContactMe('".$user[4]."','".$user[0]."','".$irc[0]."','".$irc[1]."','".$irc[2]."')\" title='".$web422.$user[4]."'>";
    echo '<img style="padding-left:5px;" src="'.CHEMIN.'inc/img/browser/teamspeak.gif" alt="'.$web422.$user[4].'" title="'.$web422.$user[4].'" border="0" /></a>';
  default:
}
?>
<br />
<img src="<?php echo CHEMIN ?>inc/img/general/favori.gif" alt="<?php echo $web92; ?>" title="<?php echo $web92; ?>" /> <a class="box" href="#" onclick="javascript:AddFavo()" title="<?php echo $web92; ?>">&nbsp;<?php echo $web119; ?></a>
<?php
if ($serviz[62] == 'on') {
?>
<br />
<img src="<?php echo CHEMIN ?>inc/img/general/reco.gif" alt="<?php echo $web124; ?>" title="<?php echo $web124; ?>" /> <a class="box" href="<?php echo CHEMIN; ?>postguest.php?lng=<?php echo $lng ?>&amp;typ=<?php echo TYP_RECO ?>" title="<?php echo $web124; ?>">&nbsp;<?php echo $web120; ?></a>
<?php
}
if (is_dir(CHEMIN."mobile")) {
?>
<br />
<img src="<?php echo CHEMIN ?>inc/img/general/mobile.gif" alt="<?php echo $web295; ?>" title="<?php echo $web295; ?>" /> <a class="box" href="<?php echo CHEMIN; ?>mobile?lng=<?php echo $lng ?>" title="<?php echo $web295; ?>" target="_blank">&nbsp;<?php echo $web295; ?></a>

<?php
}
?>
</div>
<?php
if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $drtuser[30]=="on")) {
?>
<p align="right"><a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=reco"><img src="<?php echo CHEMIN; ?>inc/img/general/edit.gif" border="0" alt="<?php echo $web308; ?>" title="<?php echo $web308; ?>" /></a></p>
<?php
}
btable1($wmtitle);
?>
