<?php
/*
    User info Box - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v2.3 (27 July 2003)        : initial release
      v2.4 (24 September 2003)   : show pseudo of registered users
                                   "Become a member" button label becomes "Your preferences" if user registered (by Nicolas Alves)
                                    show user name option (by Nicolas Alves)
                                    tiny message option (by Nicolas Alves and Laurent Duveau)
                                    slightly modified the PopupWindow() Javascript function (scrollbars parameter) for use with the new mini message functionality
                                    created $dbstats, $dbipstats, $dbstatsbk and $dbcounter variables
                                    added FileDBExist() function
      v3.0 (25 February 2004)     : added skin management (by Nicolas Alves)
                                    added UID management for Tiny Messages
      v4.0 (06 December 2004)     : added the sideboxes specific style (by Isa)
                                    correction on line 75 (by Isa)
      v4.6.0 (04 June 2007)       : new ascii sort for online visitors (by Icare)
      v4.6.18(09 February 2012)   : change control registration members (by Saxbar)
	  v4.6.20 (24 May 2012)       : added $boxtitle (by Saxbar)
                                    corrected btable1 (by Saxbar)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "boxuser.inc")) {
  header("location:../index.php");
  die();
}

if ($lng == $lang[0]) {
  $boxtitle = $nom[34];
}
else {
  $boxtitle = $nom[35];
}
htable1($boxtitle, "100%");
echo "<div align='center' style='margin-top:0px;'>";

if (!empty($userprefs[1])) {
  ?>
  <form name="userpref" action="<?php echo CHEMIN; ?>compte.php?lng=<?php echo $lng; ?>" method="post">
  <div align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $web212; ?>"><?php echo $web212; ?></button><?php echo $boutonright; ?></div>
  </form>
  <form name="usermsg" action="<?php echo CHEMIN; ?>tinymsg.php?lng=<?php echo $lng; ?>" method="post">
  <input type="hidden" name="action" value="3"/>
  <div align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $web318; ?>"><?php echo $web318; ?></button><?php echo $boutonright; ?></div>
  </form>
  <form name="userout" action="<?php echo CHEMIN; ?>connect.php?lng=<?php echo $lng; ?>" method="post">
  <input type="hidden" name="connect" value="off"/>
  <div align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $web372; ?>"><?php echo $web372; ?></button><?php echo $boutonright; ?></div>
  </form>
  <?php
}
else {
  ?>
  <form name="usernew" action="<?php echo CHEMIN; ?>connect.php?lng=<?php echo $lng; ?>" method="post">
  <input type="hidden"  name="connect" value="on"/>
  <input type="hidden"  name="new" value="on"/>
  <?php echo $boutonleft; ?><button type="submit" title="<?php echo $web160; ?>"><?php echo $web160; ?></button><?php echo $boutonright; ?>
  </form>
  <hr />
  <?php echo "<b>".$web373."</b><br />---<br />"; ?>
  <form name="userin" action="<?php echo CHEMIN; ?>connect.php?lng=<?php echo $lng; ?>" method="post">
  <input type="hidden"  name="connect" value="on"/>
  <input type="hidden"  name="new" value="off"/>
  <p align="center"><?php echo $web49; ?><br />
  <input class="texte" type="text" name="pseudo" size="18" value=""/>
  <br /><?php echo $web300; ?><br />
  <input class="texte" type="password" name="uid" size="18" value=""/>
  <br /><?php echo $boutonleft; ?><button type="submit" title="<?php echo $web52; ?>"><?php echo $web52; ?></button><?php echo $boutonright; ?>
  </p>
  </form>
  <?php
}
echo "</div>";
 $nbrmsg = array();
 if (FileDBExist(USEREP.$userprefs[1].DBEXT)) {
    $dbmsg = ReadDBFields(USEREP.$userprefs[1].DBEXT);
    if ($dbmsg[0][0] == $userprefs[7]) {
    for ($i = 2; $i < count($dbmsg); $i++) {
        if ($dbmsg[$i][3]=="new") {
        $nbrmsg[]=$dbmsg[$i][3];
   }
  }
 }
}
if (count($nbrmsg)!=0) {
?>
<div align="center"><a class="box" href="<?php echo CHEMIN; ?>tinymsg.php?lng=<?php echo $lng; ?>&action=3"><img src="<?php echo CHEMIN; ?>inc/img/general/newmsg.gif" border="0" alt="<?php echo $web319; ?>" title="<?php echo $web319; ?>"/></a>
<embed src="<?php echo CHEMIN;?>inc/mail/mail.wav" hidden="true" autostart="true" loop="0" height="10" width="10"></embed>
</div>
<?php
 }
?>
<hr />
<?php
 $dossier_users=USEREP;
 $file_users=opendir($dossier_users);
 $nbr_membres=0;
 while ($nomfichier=readdir($file_users)) {
 if( substr($nomfichier,-3)=="dtb" ) {
 $nbr_membres++;
  }
 }
closedir($file_users);
  if ($nbr_membres >1) {
  $text_nbr_membres=$web321;
  }
  else {
  $text_nbr_membres=$web322;
  }
?>
<div class="box">&nbsp;<img src="<?php echo CHEMIN; ?>inc/img/general/nbrmembres.gif" border="0" alt="<?php echo $web320; ?>" title="<?php echo $web320; ?>"/>&nbsp;<?php echo $nbr_membres." ".$text_nbr_membres; ?></div>
<p class="box" align="center"><br /><b><?php echo $web175; ?></b><br /><br /></p>
<?php
 $regusers = ReadDBFields(DBIPSTATS);
 $usersonline = array();
 for ($i = 0; $i < count($regusers); $i++) {
  if (!empty($regusers[$i][2])) {
    $usersonline[] = $regusers[$i][2];
  }
}
@usort($usersonline,'AsciiCompare');
?>
<div class="box" align="left">
<?php
 if (empty($usersonline)) {
 echo $web176;
}
else {
  $uniqueusers = array();
  $uniqueusers[] = $usersonline[0];
 for ($i = 1; $i < count($usersonline); $i++) {
    if ($usersonline[$i] != $usersonline[$i-1]) {
      $uniqueusers[] = $usersonline[$i];
    }
  }
  for ($i = 0; $i < count($uniqueusers); $i++) {
if ($userprefs[1] != "" && $userprefs[1] != $uniqueusers[$i]) {
      $from = $userprefs[1];
?>
&nbsp;&nbsp;<img src="<?php echo CHEMIN; ?>inc/img/general/puce1.gif" border="0" alt="<?php echo $web321; ?>" title="<?php echo $web321; ?>"/><a href="<?php echo CHEMIN; ?>tinymsg.php?lng=<?php echo $lng; ?>&amp;action=1&amp;to=<?php echo $uniqueusers[$i]; ?>&amp;from=<?php echo $from; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/mail.gif" border="0" alt="<?php echo $web214." ".$uniqueusers[$i]; ?>" title="<?php echo $web214." ".$uniqueusers[$i]; ?>" /></a>&nbsp;&nbsp;<?php echo $uniqueusers[$i]; ?><br />
<?php
}
else {
?>
&nbsp;&nbsp;<img src="<?php echo CHEMIN; ?>inc/img/general/puce2.gif" border="0" alt="<?php echo $web321; ?>" title="<?php echo $web321; ?>"/><?php echo $uniqueusers[$i]; ?><br />
<?php
    }
  }
}
?>
</div>
<?php
btable1($boxtitle);
?>
