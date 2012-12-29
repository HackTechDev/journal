<?php
/*
    Connect  - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v4.6.0  (04 June 2007)        : initial release (by Icare)
      v4.6.10 (7 September 2009)    : corrected #274
      v4.6.15 (30 June 2011)        : corrected cookie delete (by Icare)
      v4.6.18 (09 February 2012)    : change control registration members (by Saxbar)
	  v4.6.20 (24 May 2012)         : corrected control registration (by Saxbar)
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");

$connect = import('connect');
$pseudo  = import('pseudo');
$pseudo  = KeepGoodChars(RemoveConnector(RemoveQuote(stripslashes(CutLongWord(strip_tags($pseudo),20)))));
$uid     = import('uid');
$topmess = $nom[($lng == $lang[0] ? 34 : 35)];

if ($serviz[28] != "on") {
  exit($web143);
}

@unlink(USEREP.'.dtb');

switch ($connect) {
case 'on':
    if ($members[19] == '0' && !FileDBExist(USEREP.$pseudo.DBEXT)) {
        exit('<br /><p align="center"><strong>'.$web447.'</strong></p>');
    }
    if (is_file(TEMPREP.$pseudo.DBEXT)) {
        include('inc/hpage.inc');
        htable($topmess, '100%');
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
    } else {
		if (!empty($pseudo) && FileDBExist(USEREP.$pseudo.DBEXT)) {
			$userdb = ReadDBFields(USEREP.$pseudo.DBEXT);
			if ($uid == $userdb[1][8] && $pseudo != "") {
				$userprefs[0] = $userdb[1][1];
				$userprefs[1] = $userdb[1][2];
				$userprefs[2] = $userdb[1][3];
				$userprefs[3] = $userdb[1][4];
				$userprefs[4] = $userdb[1][5];
				$userprefs[5] = $userdb[1][6];
				$userprefs[6] = $userdb[1][7];
				$userprefs[7] = $userdb[1][8];
				$userprefs[8] = $userdb[1][9];
				$userprefs[9] = $userdb[1][10];
				$userprefs[10] = $userdb[1][11];
				$userprefs[11] = $userdb[1][12];
				$userdata = $userprefs[0].CONNECTOR.$userprefs[1].CONNECTOR.$userprefs[2].CONNECTOR.$userprefs[3].CONNECTOR.$userprefs[4].CONNECTOR.$userprefs[5].CONNECTOR.
							$userprefs[6].CONNECTOR.$userprefs[7].CONNECTOR.$userprefs[8].CONNECTOR.$userprefs[9].CONNECTOR.$userprefs[10].CONNECTOR.$userprefs[11];
				$cpt = $userdb[1][0]; // ATTENTION voir si plusieurs users...
				$userdb[0][0] = $userprefs[7];
				$userdb[1][0] = $cpt;
				WriteDBFields(USEREP.$userprefs[1].DBEXT, $userdb);
				setcookie($usercookie, $userdata, time() + 157680000);
				include("inc/hpage.inc");
				if ($lng == $lang[0]) {
					$i = 0;
				}
				else {
					$i = 1;
				}
				htable($nom[$i+34], "100%");
				echo "<p align='center'><br /><b>".$userprefs[1].$web167." ".$site[0]."...!</b><br /></p>";
				btable();
				include("inc/bpage.inc");
			}
			elseif ($uid == $userdb[0][0] && $pseudo != "") { //cookie perdu ou reconnexion
				?>
				<script type="text/javascript" language="javascript">
				  alert('<?php echo $pseudo.addslashes(stripslashes($web374)); ?>');
				  window.location="<?php echo CHEMIN; ?>user.php?lng=<?php echo $lng; ?>&upseudo=<?php echo $pseudo; ?>";
				</script>
				<?php
			}
			elseif ($pseudo != "") {
				?>
				<script language='JavaScript' type='text/javascript'>
				  alert('<?php echo addslashes($web231); ?>');
				  history.back();
				</script>
				<?php
			}
		}
		else {
			?>
			<script language='JavaScript' type='text/javascript'>
			  window.location="<?php echo CHEMIN; ?>user.php?lng=<?php echo $lng; ?>&upseudo=<?php echo $pseudo; ?>&uuid=<?php echo $uid; ?>&cnt=on";
			</script>
			<?php
		}
	}
	break;
case 'off':
	/// corrected cookie delete
	$dbuser = $userprefs[1];
	$userdb = ReadDBFields(USEREP.$userprefs[1].DBEXT);
	$cpt = "0";
	$userdb[1] = $cpt;
	WriteDBFields(USEREP.$userprefs[1].DBEXT,$userdb);
	$userdb = ReadDBFields(USEREP.$userprefs[1].DBEXT);
	$userdb[1][1] = $userprefs[0].CONNECTOR.$userprefs[1].CONNECTOR.$userprefs[2].CONNECTOR.$userprefs[3].CONNECTOR.$userprefs[4].CONNECTOR.$userprefs[5].CONNECTOR.$userprefs[6].CONNECTOR.$userprefs[7].CONNECTOR.$userprefs[8].CONNECTOR.$userprefs[9].CONNECTOR.$userprefs[10].CONNECTOR.$userprefs[11];
	WriteDBFields(USEREP.$userprefs[1].DBEXT,$userdb);
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
	setcookie($usercookie, "");
	include("inc/hpage.inc");
	if ($lng == $lang[0]) {
		$i = 0;
	}
	else {
		$i = 1;
	}
    htable($nom[$i+34], "100%");
    echo "<p align='center'><br /><b>".$web376.$dbuser."...!</b><br /></p>";
    btable();
    include("inc/bpage.inc");
    exit();
	break;
default:
	include("inc/hpage.inc");
	if ($lng == $lang[0]) {
		$i = 0;
	}
	else {
		$i = 1;
	}
	htable($nom[$i+34], "100%");
	?>
	<form name="userin" action="connect.php?lng=<?php echo $lng; ?>" method="post">
	<input type="hidden"  name="connect" value="on" />
	<table cellspacing="0" cellpadding="0" align="center" width="98%" border="0" summary="">
	<tr><td><p align="center"><?php echo $web49; ?></p></td></tr>
	<tr><td align="center"><input class="texte" type="text" name="pseudo" size="40" value="" /></td></tr>
	<tr><td><p align="center"><?php echo $web300; ?></p></td></tr>
	<tr><td align="center"><input class="texte" type="password" name="uid" size="40" value="" /></td></tr>
	<tr><td><p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $web52; ?>"><?php echo $web52; ?></button><?php echo $boutonright; ?></p>
	</table>
	</form>
	<?php
	btable();
	include("inc/bpage.inc");
}
?>
