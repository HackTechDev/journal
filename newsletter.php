<?php
/*
    Newsletter - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v3.0 (25 February 2004)     : initial release by Nicolas Alves and Laurent Duveau
      v3.0p1 (26 Feb 2004)        : ergonomic fixes in the e-mails sent when a user subscribes to the newsletter
      v4.0 (06 December 2004)     : added page title (by Jean-Mi)
      v4.6.0 (04 June 2007)       : updated email checking (by Icare)
                                    corrected function IsValidMail (by djchouix and hpsam)
                                    corrected bad remove (by hpsam)
      v4.6.2 (22 July 2007)       : new function isValidMail() (by Icare)
      v4.6.3 (30 August 2007)     : test email server become optionnal (by Icare)
      v4.6.5 (10 November 2007)   : added nwlist.tmp and mail to confirm subscription, check only domain (by Icare)
      v4.6.10 (7 September 2009)  : corrected #272
      v4.6.18 (09 February 2012)  : added dialog to confirm unsubscribing of the newsletter (by Saxbar)
	  v4.6.20 (24 May 2012)       : corrected field registration newsletter (by Saxbar)
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");

if ($serviz[36] == "") {
  exit($web143);
}
if (!isset($nlpseudo)) {
  header("location:index.php?lng=".$lng);
}

function isValidEmail($email, $verify, $return_errors=true) {
  $error = "";
  # Check syntax with regex
  if (preg_match('/^([a-zA-Z0-9\._\+-]+)\@((\[?)[a-zA-Z0-9\-\.]+\.([a-zA-Z]{2,7}|[0-9]{1,3})(\]?))$/', $email, $matches)) {
    $user = $matches[1];
    $domain = $matches[2];
    if ($verify == "on") {
      echo "Checking ".$domain." ......<br />";
      $ipname = gethostbyname($domain);
      if ($ipname == $domain) {
        $error = "Domaine inconnu - No such a domain";
      }
    }
  } else {
    $error = 'Email est mal formé - Email is not properly formatted';
  }
  if ($return_errors) {
    if(isset($error)) return htmlentities($error); else return true;
  }
}

if (preg_match('!^(http|ftp|Votre|Your)!i', $nlpseudo)) die('STOP ! illegal pseudo');
$nlpseudo = KeepGoodChars(CutLongWord(strip_tags(stripslashes($nlpseudo)),20));
$nlmail   = strip_tags(stripslashes($nlmail));
$topmess  = $web222;
include("inc/hpage.inc");
htable($web222, "100%");

switch ($action) {
case "sub" :
  $nlmail = strip_tags(stripslashes($nlmail));
  echo "<p style='text-align:left'>Checking &nbsp;".$nlmail." ......<br /><br /></p>";
  $error = "";
  if(($nlpseudo == "") or ($nlpseudo == KeepGoodChars($web259))) {
    $error = '<p align="justify"> - '.$web252.'</p>';
  }
  if ((!preg_match("!^(.+)@(.+)\\.(.+)$!",$nlmail)) || ($nlmail == "") || ($nlmail == $web260)) {
    $error .= "<p align=\"justify\"> - ".$web251."</p>";
  }
  if ($error == "") {
    $controle = CheckDB1Field(DBNEWSLETTER,$nlpseudo,0);
    if ($controle) {
    $error = $web405;
    }
    else{
      $controle = CheckDB1Field(DBNEWSLETTER,$nlmail,1);
      if ($controle) {
        $error = $web250;
      }
    }
    // verify tmp list
    if (FileDBExist(CHEMIN.DATAREP.'nwlist.tmp')) {
      $tmplist = ReadDBFields(CHEMIN.DATAREP."nwlist.tmp");
      for ($k = count($tmplist); $k >= 0; $k--) {
        if ($tmplist[$k][0] !="" && $tmplist[$k][0] != $nlpseudo && $tmplist[$k][3] < date("YmdHi")) {
          DeleteDBFieldById(CHEMIN.DATAREP."nwlist.tmp", $id=$k);
        }
      }
      unset($tmplist);
      $tmplist = ReadDBFields(CHEMIN.DATAREP."nwlist.tmp");
      for ($k = 0; $k < count($tmplist); $k++) {
        if ($tmplist[$k][0] == $nlpseudo) {
          unset($tmplist);
          ?>
          <script language="javascript" type="text/javascript">
          alert('<?php echo addslashes($web433); ?>'); // message "Veuillez répondre à notre mail pour confirmation, merci."
          document.location.href='<?php CHEMIN."index.php?lng=".$lng; ?>';
          </script>
		      <?php die ('STOP !');
		    }
      }
      unset($tmplist);
    }
    if (!$controle) {
      $valemail = IsValidEmail($nlmail, $serviz[36]);
      if ($valemail) {
        $controle = false;
        $error = $valemail;
      }
    }
    if (!$controle && !$valemail) {
      $nllist = array();
      $nllist[0] = $nlpseudo;
      $nllist[1] = $nlmail;
      $nllist[2] = $lng;
      $nllist[3] = date("YmdHi",time()+900); //délai 15 mn
      AppendDBFields(CHEMIN.DATAREP."nwlist.tmp",$nllist);
      echo '<p>'.$web245.'<b> '.$nlpseudo.'</b> '.$web431.$site[0].'<br />'.$web433.'</p>';
      $to = $nlmail;
      $sujet = $site[0]." - ".$web246;
      $body  = $web245." ".$nlpseudo." ".$web431.$site[0]."<br /><br />";
      $body .= $web432."<br />";
      $body .= '<a href="'.$site[3].'newsletter.php?lng='.$lng.'&action=confsub&nlpseudo='.$nlpseudo.'&nlmail='.$nlmail.'">'.$site[3].'newsletter.php?lng='.$lng.'&action=confsub&nlpseudo='.$nlpseudo.'&nlmail='.$nlmail.'</a>';
      $body .= "<hr />".$web235."<br />".$user[0]." <br />".$site[3];
      eMailHtmlTo($sujet,$body,$to);
    } else {
      echo '<br /><p>'.$error.'</p><br />';
    }
  } else {
    echo '<p align="justify"><b>'.$web256.'</b></p><br />'.$error;
  }
break;
case "confsub" :
	$error = "";
    echo "<p style='text-align:left'>Checking &nbsp;".$nlmail." ...<br /><br /></p>";
    if(($nlpseudo == "") or ($nlpseudo == KeepGoodChars($web259))) {
      $error = '<p align="justify"> - '.$web252.'</p>';
    }
    if ((!preg_match("!^(.+)@(.+)\\.(.+)$!",$nlmail)) || ($nlmail == "") || ($nlmail == $web260)) {
      $error .= "<p align=\"justify\"> - ".$web251."</p>";
    }
    if ($error == "") {
      $controle = CheckDB1Field(DBNEWSLETTER,$nlpseudo,0);
      if ($controle) {
        $error = $web405;
      } else{
        $controle = CheckDB1Field(DBNEWSLETTER,$nlmail,1);
        if ($controle) {
          $error = $web250;
        }
      }
      // update tmp list
      if (FileDBExist(CHEMIN.DATAREP.'nwlist.tmp')) {
        $tmplist = ReadDBFields(CHEMIN.DATAREP."nwlist.tmp");
        for ($k = 0; $k < count($tmplist); $k++) {
          if ($tmplist[$k][0] == $nlpseudo && $tmplist[$k][3] > date("YmdHi")) {
            unset($tmplist);
            DeleteDBFieldById(CHEMIN.DATAREP."nwlist.tmp", $id=$k);
            break;
		      }
        }
      }
      if (!$controle) {
        $valemail = IsValidEmail($nlmail, $user[1], $serviz[36]);
        if ($valemail) {
          $controle = false;
          $error = $valemail;
        }
      }
      if (!$controle && !$valemail) {
        echo '<p>'.$web249.'<b> '.$nlpseudo.'</b><br /><br />'.$web50.'<b> '.$nlmail.'</b> '.$web248.'</p><br />';
        $nllist = array();
        $nllist[0] = $nlpseudo;
        $nllist[1] = $nlmail;
        $nllist[2] = $lng;
        AppendDBFields(DBNEWSLETTER,$nllist);
        $to = $nlmail;
        $sujet = $site[0]." - ".$web246;
        $body  = $web245." ".$nlpseudo.$web244." ".$site[0]."<br /><br />";
        $body .= $web235."<br />".$user[0]."<br />".$site[3]."<hr />";
        $body .= $web243."<br />";
        $body .= '<a href="'.$site[3].'newsletter.php?lng='.$lng.'&action=unsub&nlpseudo='.$nlpseudo.'&nlmail='.$nlmail.'">'.$site[3].'newsletter.php?lng='.$lng.'&action=unsub&nlpseudo='.$nlpseudo.'&nlmail='.$nlmail.'</a>';
        eMailHtmlTo($sujet,$body,$to);
        if ($supervision[7] == "on") {
          $body  = $nlpseudo.' ('.$nlmail.') '.$web242.' '.$site[0]."<hr />";
          $body .= $web241.":<br />";
          $body .= '<a href="'.$site[3].'newsletter.php?lng='.$lng.'&action=unsub&nlpseudo='.$nlpseudo.'&nlmail='.$nlmail.'">'.$site[3].'newsletter.php?lng='.$lng.'&action=unsub&nlpseudo='.$nlpseudo.'&nlmail='.$nlmail.'</a>';
          eMailHtmlTo($sujet,$body,"");
        }
      } else {
        echo '<br /><p>'.$error.'</p><br />';
      }
    } else {
      echo '<p align="justify"><b>'.$web256.'</b></p><br />'.$error;
    }

break;
case "unsub" :
  $error = "";
  if (($nlpseudo == "") || ($nlpseudo == KeepGoodChars($web259))) {
    $error = '<p align="justify"> - '.$web252.'</p>';
  }
  if ((!preg_match("!^(.+)@(.+)\\.(.+)$!",$nlmail)) || ($nlmail == "") || ($nlmail == $web260)) {
    $error .= '<p align="justify"> - '.$web251.'</p>';
  }
  if (empty($nlconfirm)) {
    echo '
  <div class="box">
    <div style="margin:12px 0;text-align:center;">'.$web463.'</div>
    <div style="text-align:center;">
      <span style="margin-right:8px;">'.$boutonleft.'
        <input class="bouton" type="button" name="nlyes"  value="'.$web313.'" 
          onClick="self.location.href=\''.CHEMIN.'newsletter.php?lng='.$lng.'&amp;nlconfirm=on&amp;action=unsub&amp;nlpseudo='.$nlpseudo.'&amp;nlmail='.$nlmail.'\'">'.$boutonright.'
      </span>
      <span style="margin-left:8px;">'.$boutonleft.'
        <input class="bouton" type="button" name="nlno"  value="'.$web314.'" 
          onClick="self.location.href=\''.CHEMIN.'index.php?lng='.$lng.'\'">'.$boutonright.'
      </span>
    </div>
  </div>';
  }
  if ($nlconfirm == 'on') {
      if ($error == "") {
        $controle = CheckDB2Fields(DBNEWSLETTER,$nlpseudo,0,$nlmail,1);
        if ($controle) {
          $nlpseudo = stripslashes($nlpseudo);
          $newdb = array();
          $dbwork = ReadDBFields(DBNEWSLETTER);
          for ($i = 0; $i < count($dbwork); $i++) {
            if ($dbwork[$i][1] == $nlmail) {
              if ($dbwork[$i][0] != $nlpseudo)
                $newdb[] = $dbwork[$i];
            } else {
              $newdb[] = $dbwork[$i];
            }
          }
          WriteDBFields(DBNEWSLETTER,$newdb);
          echo '<p>'.$web253.'<b> '.$nlpseudo.'</b><br /><br />'.$web255.'<b> '.$nlmail.'</b> '.$web254.'</p><br />';
          if ($supervision[7] == "on") {
            $to = $nlmail;
            $sujet  = $site[0]." - ".$web241;
            $body  = $web240." ".$nlpseudo.$web239." ".$site[0]."<hr />";
            $body .= $web235."<br />".$user[0]."<br />".$site[3]."<hr />";
            $body .= $web234."<br />";
            $body .= '<a href="'.$site[3].'newsletter.php?lng='.$lng.'&action=sub&nlpseudo='.$nlpseudo.'&nlmail='.$nlmail.'">'.$site[3].'newsletter.php?lng='.$lng.'&action=sub&nlpseudo='.$nlpseudo.'&nlmail='.$nlmail.'</a>';
            eMailHtmlTo($sujet,$body,$to);
            $body  = $nlpseudo." (".$nlmail.") ".$web238." ".$site[0]."\n";
            eMailHtmlTo($sujet,$body,"");
          }
        } else {
          echo '<br /><p>'.$web255.' <b>'.$nlmail.'</b> '.$web233.'</p><br />';
        }
      } else {
        echo '<p align="justify"><b>'.$web256.'</b></p><br />'.$error;
      }
  }
break;
}
btable();
include("inc/bpage.inc");
?>
