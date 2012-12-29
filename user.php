<?php
/*
    User preferencies - GuppY PHP Script -  version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v2.3 (27 July 2003)        : initial release
      v2.4 (24 September 2003)   : show user name option & tiny message option (by Nicolas Alves and Laurent Duveau)
                                   added forum personalized signature
                                   upgraded checks for unwanted characters like ' in pseudo, with the use of the new RemoveQuote() function
                                   secured transfered parameters
      v3.0 (25 February 2004)    : added skins (by Nicolas Alves)
                                   added possibility to put all boxes on the right side
                                   added UID management for Tiny Messages and check if Pseudo is already taken
                                   added limit Pseudo to basic [a-Z][0-9] characters and check e-mail syntax
                                   bug fix that would hide forum signature in some cases (thanks HubbY)
      v3.0p1 (26 Feb 2004)       : bug fix, now checks e-mail correctly in the VerifyForm() function
      v4.0 (06 December 2004)    : upgrade management UID,
                                   added page title (by Jean-Mi)
                                   added avatars management (by Nicolas Alves)
                                   added new look with td css class (by Icare)
                                   corrected avatars table and W3C compliance (by Icare)
      v4.5 (21 Mai 2005)         : corrected box title (by Icare)
                                   $ushow default checked (by Icare)
      v4.5.8 (05 November 2005)  : corrected return on error pseudo and redirect to compte.php (by Icare)
      v4.6.0 (04 June 2007)      : added editor choice for better accessibility (by Icare)
      v4.6.1 (02 July 2007)      : corrected xhtml compliance (thanks hpsam)
      v4.6.10 (7 September 2009) : corrected #266 and #274
      v4.6.14 (14 February 2011) : corrected $uwebsite (thanks jchouix)
      v4.6.15 (30 June 2011)     : new management of members's subscription (by Icare)
      v4.6.18 (09 February 2012) : corrected $uwebsite, display welcome message (by Laroche, Saxbar)
	                               deleted old fields (thanks JeanMi)
      v4.6.20 (24 May 2012)      : added $avatar (by Saxbar)					   
								   
*/
header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");

if ($serviz[28] != "on") {
  exit($web143);
}
$setusercookie = strip_tags($setusercookie);
$unreg = strip_tags($unreg);
$ulang = strip_tags($ulang);
$upseudo = KeepGoodChars(RemoveConnector(RemoveQuote(stripslashes(CutLongWord(strip_tags($upseudo),20)))));
$uemail = CutLongWord(strip_tags($uemail));
$uboxes = strip_tags($uboxes);
$ureadlang = strip_tags($ureadlang);
$ushow = strip_tags($ushow);
$usign = WrapLongWords(stripslashes(strip_tags($usign)));
$uuid = strip_tags($uuid);
$uwebsite = checkUserWebsiteUrl(strip_tags($uwebsite));
$udesign = strip_tags($udesign);
$avatar = IsImage(substr($avatar, -3)) ? strip_tags($avatar) : 'unknown';
$usermess = "";
$pseudok = 1;
$suite = stripslashes(strip_tags($suite));
$modif = strip_tags($modif);
$new = isset($_GET['cnt']) ? strip_tags($_GET['cnt']) : strip_tags($_POST['new']);

$usermess = '';

if ($members[19] == '0' && !isset($_COOKIE[$usercookie])) {
    exit('<p align="center"><br><strong>'.$web447.'</strong></p>');
}

if (is_file(TEMPREP.$upseudo.DBEXT)) {
    $dbmsg = ReadDBFields(TEMPREP.$upseudo.DBEXT);
    switch($suite) {
		case '' : // inscription en attente
            include('inc/hpage.inc');
            htable($web458, '100%');
            echo '
<br />
<p style="text-align:center;"><strong>'.$web466.'</strong></p>';
            btable();
            include 'inc/bpage.inc';
            break;
        case 'ok' : // confirmation mail
            if ($uuid == $dbmsg[0][0]){
                WriteDBFields(USEREP.$upseudo.DBEXT, $dbmsg);
                $userdata = implode(CONNECTOR, $dbmsg[1]);
                setcookie($usercookie, $userdata, time() + 157680000);
                DestroyDBFile(TEMPREP.$upseudo.DBEXT);
                unset($dbmsg);
                header('location:'.CHEMIN.'index.php?lng='.$lng);
            } else {
                die('STOP : bad password !!!');
            }
            break;
        case 'go' : // confirmation webmaster
            include('inc/hpage.inc');
            htable($web458, '100%');
            WriteDBFields(USEREP.$upseudo.DBEXT, $dbmsg);
            DestroyDBFile(TEMPREP.$upseudo.DBEXT);
            echo '<br />
            <p style="text-align:center;font-weight:bold;"><br />'
            .$web317.' '.$web322.' '.$upseudo.' ... '.$web367.' !!!<br /></p>';
            $to = $uemail;
            $sujet = $site[0].' - '.$web450;
            $body  = $web245.' '.$upseudo.', '.$web451.' '.$site[0].'<br /><br />';
            $body .= $web49.' '.$upseudo.'<br />'.$web300.' : '.$dbmsg[0][0].'<br />';
            $body .= $web452.'<a href="'.$site[3].'index.php?lng='.$lng.'">'.$site[0].'</a><br />';
            $body .= $web235.'<br />'.$user[0].'<br />';
            eMailHtmlTo($sujet,$body,$to);
            btable();
            include 'inc/bpage.inc';
            break;
        case 'no' : // refus
            include('inc/hpage.inc');
            htable($web458, '100%');
            DestroyDBFile(TEMPREP.$upseudo.DBEXT);
            $to = $uemail;
            $sujet = $site[0].' - '.$web453;
            $body  = $web240.' '.$web454.', '.$upseudo.', '.$site[0].'<br /><br />';
            $body .= $web235.'<br />'.$user[0].'<br />';
            eMailHtmlTo($sujet,$body,$to);
            btable();
            include 'inc/bpage.inc';
            break;
        default: /// attente de confirmation
            include('inc/hpage.inc');
            htable($web458, '100%');
            switch($members[19]) {
            case 1 :
                echo '
<br />
<p style="text-align:center;"><strong>'.$web448.'</strong></p>';
                break;
            case 2 :
                echo '
<br />
<p style="text-align:center;"><strong>'.$web449.'</strong></p>';
                break;
            }
            btable();
            include('inc/bpage.inc');
            exit();
    }
} elseif ($suite != '') {
    switch($suite) {
        case 'ok' : // confirmation mail
            header('location:'.CHEMIN.'connect.php?lng='.$lng);
			break;
        case 'go' : // confirmation webmaster
        case 'no' : // refus
            include('inc/hpage.inc');
            htable($web458, '100%');
            echo '
<br />
<p style="text-align:center;"><strong>'.$web459.'</strong></p>';
            btable();
            include('inc/bpage.inc');
			break;
		default :
            header('location:'.CHEMIN.'index.php?lng='.$lng);
	}
	exit();
} elseif ($setusercookie == 1) {
	$dbmail  = array();
	$dossier = opendir(USEREP);
	while ($fichier = readdir($dossier)) {
		if (is_file(USEREP.$fichier) && substr(basename($fichier), -3) == 'dtb') {
			$userdb = ReadDBFields(USEREP.$fichier);
			$dbmail[] = $userdb[1][3];
			if (basename($fichier) == $upseudo.DBEXT) {
				$curmail = $userdb[1][3];
				if ($new == 'on') {
					$pseudok = 0;
					$msg     = $web231;
					break;
				}
				if (($userdb[0][0] != $userprefs[7]) && ($userdb[0][0] != $uuid) && $new != 'on') {
					$pseudok = 0;
					$msg     = $web231;
					break;
				}
			}
		}
	}
	closedir($dossier);
	$dossier = opendir(TEMPREP);
	while ($fichier = readdir($dossier)) {
		if (is_file(TEMPREP.$fichier) && substr(basename($fichier), -3) == 'dtb') {
			$userdb = ReadDBFields(TEMPREP.$fichier);
			$dbmail[] = $userdb[1][3];
			if (basename($fichier) == $upseudo.DBEXT) {
				if ($new == 'on') {
					$pseudok = 0;
					$msg     = $web231;
					break;
				}
			}
		}
	}
	closedir($dossier);
	if ($pseudok && ($new == 'on' || ($modif == 1 && $curmail != $uemail)) && in_array($uemail, $dbmail)) {
		$pseudok = 0;
		$msg     = $web465;
	}
	unset($userdb);
    if ($pseudok) {
		if ($modif == 1) {
			$userdb = ReadDBFields(USEREP.$upseudo.DBEXT);
		}
        $lng          = $ulang;
        $usertemp[0]  = $ulang;
        $usertemp[1]  = $upseudo;
        $usertemp[2]  = $uemail;
        $usertemp[3]  = $uboxes;
        $usertemp[4]  = $ulang;
        $usertemp[5]  = $ushow;
        $usertemp[6]  = RemoveConnector(stripslashes($usign));
        $usertemp[6]  = str_replace(chr(10), "\n", $usertemp[6]);
        $usertemp[7]  = empty($uuid) ? GenerateUID() : $uuid;
        $usertemp[8]  = trim($avatar);
        $usertemp[9]  = $uwebsite == 'http://' ? '' : $uwebsite;
        $usertemp[10] = $udesign;
        $usertemp[11] = $ueditor;
		$userdb[0][0] = $usertemp[7];
        unset($userdb[1]);
		$userdb[1][0] = '0';
		$userdb[1][1] = $usertemp[0].CONNECTOR.$usertemp[1].CONNECTOR.$usertemp[2].CONNECTOR.$usertemp[3].CONNECTOR.$usertemp[4].CONNECTOR.$usertemp[5].CONNECTOR.$usertemp[6].CONNECTOR.$usertemp[7].CONNECTOR.$usertemp[8].CONNECTOR.$usertemp[9].CONNECTOR.$usertemp[10].CONNECTOR.$usertemp[11];
        if ($serviz[31] != '' && $new == 'on') {
            $userdb[2][0] = $serviz[31].CONNECTOR.GetCurrentDateTime().CONNECTOR.'&nbsp; '.
            $web253.' '.$usertemp[1].$web167.' '.$site[0].CONNECTOR.'new'.CONNECTOR.''.
                CONNECTOR.''.CONNECTOR.''.CONNECTOR.$serviz[43];
        }
		
        if ($members[19] == '' || $modif == '1') {        
            WriteDBFields(USEREP.$usertemp[1].DBEXT, $userdb);
            $userdata = implode(CONNECTOR, $usertemp);
            setcookie($usercookie, $userdata, time() + 157680000);
            $usermess = $web161;
            if (!empty($userprefs[4])) {
                include(CHEMIN.'inc/lang/'.$userprefs[4].'-web'.INCEXT);
            } else {
                include(CHEMIN.'inc/lang/'.$lng.'-web'.INCEXT);
            }
            include('inc/hpage.inc');
            htable($topmess, '100%');
            echo '
<br />
<p align="center"><b>'.$usermess.'</b></p>
<p align="center"><a href="'.CHEMIN.'compte.php?lng='.$lng.'">'.$web467.'</a></p>';
            btable();
            include 'inc/bpage.inc';
            echo '
<script type="text/javascript">
setTimeout(window.location="'.CHEMIN.'compte.php?lng='.$lng.'", 80000);
</script>';
			echo '
            <noscript>';
            header('location:'.CHEMIN.'compte.php?lng='.$lng);
            echo '</noscript>';
            exit();
        } else {
        WriteDBFields(TEMPREP.$usertemp[1].DBEXT, $userdb);
        if ($members[19] == '1'){ // confirmation par mail
            $to = $uemail;
            $sujet = $site[0].' - '.$web458;
            $body  = $web245.' '.$upseudo.', '.$web451.$site[0].'<br /><br />';
            $body .= $web49.' '.$upseudo.'<br />'.$web300.' : '.$uuid.'<br />';
            $body .= $web452;
            $body .= '<a href="'.$site[3].'user.php?lng='.$lng.'&suite=ok&upseudo='.$upseudo.'&uuid='.$uuid.'">'.$site[0].'</a><br />';
            $body .= $web235.'<br />'.$user[0].'<br />';
            eMailHtmlTo($sujet,$body,$to);
            $response = '<br /><p style="text-align:center;"><strong>'.$web459.'<br />'.$web433.'</strong></p>';
        } elseif ($members[19] == '2'){ // confirmation webmaster
            $sujet = $site[0].' - '.$web458;
            $body  = $upseudo.' ('.$uemail.') '.$web455.$site[0].'<hr /><br />';
            $body .= $web456.' : ';
            $body .= '<a href="'.$site[3].'user.php?lng='.$lng.'&suite=go&upseudo='.$upseudo.'&uemail='.$uemail.'">'.$site[3].'user.php?lng='.$lng.'&suite=go&upseudo='.$upseudo.'&uemail='.$uemail.'</a><br /><br />';
            $body .= $web457.' : ';
            $body .= '<a href="'.$site[3].'user.php?lng='.$lng.'&suite=no&upseudo='.$upseudo.'&uemail='.$uemail.'">'.$site[3].'user.php?lng='.$lng.'&suite=no&upseudo='.$upseudo.'&uemail='.$uemail.'</a>';
            eMailHtmlTo($sujet,$body,"");
            $response = '<br /><p style="text-align:center;"><strong>'.$web459.'<br />'.$web460.'</strong></p>';        }
        }
        include('inc/hpage.inc');
        htable($web458, '100%');
        echo $response;
        btable();
        include('inc/bpage.inc');
        exit();

    } else {
    ?>
    <script type="text/javascript">
      alert('<?php echo addslashes($msg); ?>');
      history.back();
    </script>
    <?php
  }
}
elseif ($unreg == 1) {
	if (FileDBExist(USEREP.$userprefs[1].DBEXT)) {
		$dbmsg = ReadDBFields(USEREP.$userprefs[1].DBEXT);
		if ($dbmsg[0][0] == $userprefs[7]) {
			DestroyDBFile(USEREP.$userprefs[1].DBEXT);
		}
	}
	if (FileDBExist(FILECOUNTMSG.$userprefs[1].DBEXT)) {
		DestroyDBFile(FILECOUNTMSG.$userprefs[1].DBEXT);
	}
	$userprefs[0] = "";
	$userprefs[1] = "";
	$userprefs[2] = "";
	$userprefs[3] = "";
	$userprefs[4] = "";
	$userprefs[5] = "";
	$userprefs[6] = "";
	$userprefs[7] = "";
	$userprefs[8] = "";
	$userprefs[9] = "";
	$userprefs[10] = "";
	$userprefs[11] = "";
	setcookie($usercookie, "", time() - 3600);
	$usermess = $web163;
	include("inc/hpage.inc");
	if ($lng == $lang[0]) {
		$i = 0;
	}
	else {
		$i = 1;
	}
    htable($nom[$i+34], "100%");
    echo "<p align='center'><br /><b>".$userprefs[1]." ".$web163."...!</b><br /></p>";
    btable();
    include("inc/bpage.inc");
    exit();
} else {
	if (empty($userprefs[7])) $userprefs[7] = GenerateUID();
	$langue = array();
	$dossier = opendir(CHEMIN."inc/lang/");
	while ($fichier = readdir($dossier)) {
		if (is_file(CHEMIN."inc/lang/".$fichier)) {
			$basefic = basename($fichier);
			$path_parts = substr($basefic,strrpos($basefic,".")+1);
			if ($path_parts == "inc") {
				if (strpos($basefic, "-web") !== false) {
					$langue[] = substr($basefic,0,strlen($basefic)-8);
				}
			}
		}
	}
	closedir($dossier);
	@sort($langue);
	include("inc/hpage.inc");

	?>
<script type="text/javascript">
 function VerifyForm() {
    var sto = '';
    var erreur = false;
    regexp = /^[a-zA-Z0-9_]{2,20}$/;
    if (!regexp.test(document.userprefnow.upseudo.value)) {
      sto += '  - <?php echo addslashes($web266); ?>\n';
      erreur = true;
    }
    regexp = /^[a-zA-Z0-9]{5,20}$/;
    if (!regexp.test(document.userprefnow.uuid.value)) {
      sto += '  - <?php echo addslashes($web302); ?>\n';
      erreur = true;
    }
    regexp = /^[^\.\s]+(\.[^\.\s]+)*@[^\.\s]+(\.[^\.\s]+)+$/;
    if (!regexp.test(document.userprefnow.uemail.value)) {
      sto += '  - <?php echo addslashes($web42); ?>\n';
      erreur = true;
    }
    if (erreur == true) {
      sto = '<?php echo addslashes($web265); ?>\n' + sto;
      alert(sto);
    }
    else {
      document.userprefnow.submit();
    }
  }
</script>
	<?php

	if ($lng == $lang[0]) {
		$i = 0;
	}
	else {
		$i = 1;
	}
	htable($nom[$i+34], "100%");
	?>
	<div align="center" style="width:96%;margin-left:auto;margin-right:auto;">
	<div style="padding-left:4px;margin-left:auto;margin-right:auto;text-align:left;">
	<form name="userprefnow" action="user.php?lng=<?php echo $lng; ?>" method="post" onsubmit="VerifyForm(); return false;">
	<p align="center"><?php echo $web156; ?></p>
	<p align="center"><?php echo $web157; ?></p>
	<p>&nbsp;</p>
	<?php
	if (!empty($usermess)) {
		?>
		<p align="center"><b><?php echo $usermess; ?></b></p>
		<p>&nbsp;</p>
		<?php
	}
	if ($userprefs[1]!="") $value_pseudo = 'value="'.$userprefs[1].'" readonly';
	else $value_pseudo = 'value="'.$upseudo.'"';
	if ($modif == '1') {
		echo '
	  <input type="hidden" name="modif" value="1" />
	  <input type="hidden" name="new" value="off" />';
	} else
		echo '
	  <input type="hidden" name="new" value="'.$new.'" />';
	?>

	<input type="hidden" name="setusercookie" value="1" />
	<fieldset><legend><?php echo $web377 ?></legend>
	<br />
	<table align="center" cellspacing="0" cellpadding="0" width="98%" border="0" summary="">
	<tr><td width="45%"><p>&bull; <?php echo $web49; ?></p></td>
	<td><input type="text"  class="texte" name="upseudo" size="30" <?php echo $value_pseudo;?> /></td></tr>
	<?php
	if ($members[0]=="on") {
		?>
		<tr><td colspan="2"><p><input type="hidden" name="ushow" value="on" />&nbsp;&nbsp;</p></td></tr>
		<?php
	}
	else {
		?>
		<tr><td colspan="2"><p align="center"><?php echo $web213; ?><input type="checkbox" name="ushow" <?php if (!$userprefs[5] || $userprefs[5] =="on") echo 'checked="checked"'; ?> /></p></td></tr>
		<?php
	}
	?>
	<tr><td><p>&bull; <?php echo $web300; ?></p></td>
	<td><input type="password" class="texte" name="uuid" size="30" value="<?php echo ($userprefs[1]!="" ? $userprefs[7] : $uuid); ?>" /></td></tr>
	<tr><td><p>&bull; <?php echo $web50; ?></p></td>
	<td><input type="text" class="texte" name="uemail" size="40" value="<?php echo $userprefs[2]; ?>" /></td></tr>
	<tr><td><p>&bull; <?php echo $web51; ?></p></td>
	<td><input type="text" class="texte" name="uwebsite" size="40" value="<?php if ($userprefs[9]) echo $userprefs[9]; else echo "http://" ?>" /></td></tr>
	<tr><td><p>&bull; <?php echo $web219; ?></p></td>
	<td><textarea name="usign" rows="2" cols="30"><?php echo stripslashes($userprefs[6]); ?></textarea></td></tr>
	</table>
	<br />
	</fieldset>
	<br />
	<fieldset><legend><?php echo $web378 ?></legend>
	<table align="center" cellspacing="0" cellpadding="0" width="98%" border="0" summary="">
	<?php
	if ($lang[1] != "") {
		?>
		<tr><td width="45%"><p>&bull; <?php echo $web155; ?></p></td>
		<td><p><select name="ulang">
		<option value="<?php echo $lang[0]; ?>" <?php if ($userprefs[0] == $lang[0]) { echo "selected='selected'"; } ?>><?php echo $lang[0]; ?></option>
		<option value="<?php echo $lang[1]; ?>" <?php if ($userprefs[0] == $lang[1]) { echo "selected='selected'"; } ?>><?php echo $lang[1]; ?></option>
		</select></p>
		</td></tr>
		<?php
	}
	else {
		?>
		<input type="hidden" name="ulang" value="<?php echo $lang[0]; ?>" />
		<?php
	}
	$uskintheme = ExploreDir('skin/');
	?>
	<tr><td><p>&bull; <?php echo $web307; ?></p></td>
	<td><select name="udesign">
	<option value=""><?php echo $web315; ?></option>
	<?php
	for ($i = 0; $i < count($uskintheme); $i++) {
		if ($userprefs[10] == $uskintheme[$i]) {
			$sel = ' selected="selected"';
		}
		else {
			$sel = "";
		}
		echo "<option value=\"".$uskintheme[$i]."\"".$sel.">".$uskintheme[$i]."</option>\n";
	}
	?>
	</select></td></tr>
	<tr><td><p>&bull; <?php echo $web164; ?></p></td>
	<td>
	  <p><select name="uboxes">
	  <option value="LR" <?php if ($userprefs[3] == "LR") { echo "selected='selected'"; } ?>><?php echo $web165; ?></option>
	  <option value="L" <?php if ($userprefs[3] == "L") { echo "selected='selected'"; } ?>><?php echo $web166; ?></option>
	  <option value="R" <?php if ($userprefs[3] == "R") { echo "selected='selected'"; } ?>><?php echo $web232; ?></option>
	  </select></p>
	</td></tr>
	<tr><td><p>&bull; <?php echo $web375 ?></p></td>
	<td><p><input type="checkbox" name="ueditor" <?php if ($userprefs[11]=="on") echo "checked='checked'"; ?> /></p></td></tr>
	<tr><td colspan="2" align="center">
	<?php
	if ($page[23]!="") {
		$imgavatars = array();
		$dossier = opendir(CHEMIN."inc/img/avatars/".$page[23]."/");
		while ($fichier = readdir($dossier)) {
			if (is_file(CHEMIN."inc/img/avatars/".$page[23]."/".$fichier)) {
				$path_parts = basename($fichier);
				$path_parts = substr($path_parts,strrpos($path_parts,".")+1);
				if (Isimage($path_parts)) {
					$imgavatars[] = $fichier;
				}
			}
		}
		closedir($dossier);
		@sort($imgavatars);
		?>
		<fieldset><legend><?php echo $web303; ?></legend>
		<table align="center" cellspacing="4" cellpadding="4" width="60%" border="0" summary="">
		<tr>
		<?php
		$nbrimgavatar = 0; $j= count($imgavatars);
		for ($i = 0; $i < count($imgavatars); $i++) {
			?>
			<td align="center"><img border="0" src="<?php echo CHEMIN; ?>inc/img/avatars/<?php echo $page[23]; ?>/<?php echo $imgavatars[$i] ?>" alt="<?php echo $imgavatars[$i] ?>" title="<?php echo $imgavatars[$i] ?>" /><br />
			<input type="radio" value="<?php echo $imgavatars[$i]; ?>" name="avatar" <?php if ($userprefs[8]==$imgavatars[$i]) echo 'checked="checked"'; ?> /></td>
			<?php
			$nbrimgavatar++; $j--;
			if ($nbrimgavatar == 5 && $j != 0) {
				$nbrimgavatar = 0;
				echo "</tr><tr>\n";
			}
		}
		$vid = 5 - count($imgavatars)%5 ;
		if ($vid != 0) { echo "<td colspan=\"$vid\"></td>"; }
		?>
		</tr>
		</table>
		</fieldset>
		<?php
	}
	?>
	</td></tr>
	</table>
	</fieldset>
	<p>&nbsp;</p>
	<p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $web154; ?>"><?php echo $web154; ?></button><?php echo $boutonright; ?></p>
	</form>
	</div>
	</div>
	<div align="center">
	<form name="userbye" action="<?php echo CHEMIN; ?>user.php?lng=<?php echo $lng; ?>" method="post">
	<input type="hidden" name="unreg" value="1" />
	<?php echo $boutonleft; ?><button type="submit" title="<?php echo $web162; ?>"><?php echo $web162; ?></button><?php echo $boutonright; ?>
	</form>
	</div>
	<?php
	btable();
	include("inc/bpage.inc");
}
?>
