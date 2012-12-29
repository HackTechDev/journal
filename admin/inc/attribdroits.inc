<?php
/*
    Admin Droits - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v4.0 (06 December 2004)     : initial release by Nicolas Alves
      v4.6.0 (04 June 2007)       : added right management for plugins (by Hpsam)
                                    administrator (or writer) cannot add writer rights to himself or to the webmaster (by Icare)
                                    extract writer's password from data/usermsg (by Ghazette)
                                    added writers's functions database and fixed bugs in writer's rights (by Icare)
                                    added fieldset and reordered icons list, new ascii sort (by Icare)
                                    added global select (by djchouix)
      v4.6.5 (05 December 2007)   : corrected user select combo (by Icare)
	  v4.6.9e (29 December 2008)  : corrected warning headers already sent
      v4.6.10 (7 September 2009)  : corrected #266
	  v4.6.18 (09 February 2012)  : corrected display active services and plugins (by Saxbar)
	  v4.6.19 (30 March 2012)     : add social networks (by Saxbar)
	  v4.6.20 (24 May 2012)       : corrected $pluginlist (by Saxbar)
	  v4.6.21 (18 October 2012)   : corrected $pluginlist (thanks linuxmr)
	  v4.6.22 (29 December 2012)  : corrected $pluginlist (thanks linuxmr, JeanMi)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "attribdroits.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[12]=="") {
    $nomzone=$admin818;
    include("access.inc");
    exit();
  }
}
  include(CHEMIN."inc/hpage.inc");
  htable($admin819, "100%");
  if ($namedroits == "") $etape = 1;
  if ($etape == 3) {
    if ($drtuser42 == "modo") {
		$drtuser23 = "on";
    }
	
	$drtuser7  = $serviz[13] == 'on' ? $drtuser7  : '';
	$drtuser12 = $serviz[42] == 'on' ? $drtuser12 : '';
	$drtuser14 = $serviz[8]  == 'on' ? $drtuser14 : '';
	$drtuser16 = $serviz[29] == 'on' ? $drtuser16 : '';
	$drtuser18 = $serviz[9]  == 'on' ? $drtuser18 : '';
	$drtuser19 = $serviz[10] == 'on' ? $drtuser19 : '';
	$drtuser20 = $serviz[11] == 'on' ? $drtuser20 : '';
	$drtuser21 = $serviz[14] == 'on' ? $drtuser21 : '';
	$drtuser22 = $serviz[12] == 'on' ? $drtuser22 : '';
	$drtuser23 = $serviz[13] == 'on' ? $drtuser23 : '';
	$drtuser24 = $serviz[13] == 'on' ? $drtuser24 : '';
	$drtuser25 = $serviz[23] == 'on' ? $drtuser25 : '';
	$drtuser27 = $serviz[19] == 'on' ? $drtuser27 : '';
	$drtuser28 = $serviz[0]  == 'on' ? $drtuser28 : '';
	$drtuser33 = $serviz[36] != ''   ? $drtuser33 : '';
	$drtuser34 = $serviz[27] == 'on' ? $drtuser34 : '';
	$drtuser37 = $serviz[47] == 'on' ? $drtuser37 : '';
	$drtuser39 = $serviz[53] == 'on' ? $drtuser39 : '';
	$drtuser40 = $serviz[53] == 'on' ? $drtuser40 : '';
	$drtuser41 = $serviz[53] == 'on' ? $drtuser41 : '';
	
    $filedroit = REDACREP.$namedroits.INCEXT;
	
    $mettre = "<?php
\$drtuser[0] = \"$drtuser0\"; // Accès à config générale
\$drtuser[1] = \"$drtuser1\"; // Accès à config site
\$drtuser[2] = \"$drtuser2\"; // Accès à config accueil
\$drtuser[3] = \"$drtuser3\"; // Accès à config section
\$drtuser[4] = \"$drtuser4\"; // Accès à Config services
\$drtuser[5] = \"$drtuser5\"; // Accès à Config boites
\$drtuser[6] = \"$drtuser6\"; // Accès à Maintenance
\$drtuser[7] = \"$drtuser7\"; // Accès à Archivage Forum
\$drtuser[8] = \"$drtuser8\"; // Accès à Contrôle d'intégrité DB
\$drtuser[9] = \"\"; // Accès à Mot de passe Admin
\$drtuser[10] = \"$drtuser10\"; // Accès à Config zone membres
\$drtuser[11] = \"$drtuser11\"; // Accès à Travaux
\$drtuser[12] = \"$drtuser12\"; // Accès à Droits
\$drtuser[13] = \"$drtuser13\"; // Accès à Editorial
\$drtuser[14] = \"$drtuser14\"; // Accès à Nouvelles
\$drtuser[15] = \"$drtuser15\"; // Accès à Articles
\$drtuser[16] = \"$drtuser16\"; // Accès à Réactions Articles
\$drtuser[17] = \"$drtuser17\"; // Accès à Spécial
\$drtuser[18] = \"$drtuser18\"; // Accès à Photos
\$drtuser[19] = \"$drtuser19\"; // Accès à Téléchargements
\$drtuser[20] = \"$drtuser20\"; // Accès à Liens
\$drtuser[21] = \"$drtuser21\"; // Accès à FAQ
\$drtuser[22] = \"$drtuser22\"; // Accès à Livre d'or
\$drtuser[23] = \"$drtuser23\"; // Accès à Forum
\$drtuser[24] = \"$drtuser24\"; // Accès à Config Forum
\$drtuser[25] = \"$drtuser25\"; // Accès à Sondage
\$drtuser[26] = \"$drtuser26\"; // Accès à Boites libres
\$drtuser[27] = \"$drtuser27\"; // Accès à Bannières
\$drtuser[28] = \"$drtuser28\"; // Accès à Citations
\$drtuser[29] = \"$drtuser29\"; // Accès à Pied de page
\$drtuser[30] = \"$drtuser30\"; // Accès à Recommander
\$drtuser[31] = \"$drtuser31\"; // Accès à Compteur
\$drtuser[32] = \"$drtuser32\"; // Accès à Statistiques
\$drtuser[33] = \"$drtuser33\"; // Accès à Newsletter
\$drtuser[34] = \"$drtuser34\"; // Accès à Nouvelles RSS
\$drtuser[35] = \"$drtuser35\"; // Accès à Logs
\$drtuser[36] = \"$drtuser36\"; // Accès à Fichiers
\$drtuser[37] = \"$drtuser37\"; // Accès à Agenda
\$drtuser[38] = \"$drtuser38\"; // Password
\$drtuser[39] = \"$drtuser39\"; // Accès à Blogs
\$drtuser[40] = \"$drtuser40\"; // Accès à Réactions Blogs
\$drtuser[41] = \"$drtuser41\"; // Accès à Blog RSS
\$drtuser[42] = \"$drtuser42\"; // Fonction
\$drtuser[43] = \"$drtuser43\"; // Accès à Config Style
\$drtuser[44] = \"$drtuser44\"; // Accès à Réseaux sociaux";
    $i=0;
    $listplug = explode("::",$listplug);
    foreach ($listplug as $value) {
      $mettre .= "
\$drtuserplg['".$value."'] = \"".$drtuserplgform[$i]."\"; // Accès plugin ".$value;
    $i++;
    }
    $mettre .="
";
    WriteFullDB($filedroit,$mettre);
    /// modif albert: écrire base admins ---------------
    $adm = array($namedroits, $drtuser42, $drtuser23);
    $dbadm = ReadDBFields(DBADMIN);
    for ($k = 0; $k < count($dbadm); $k++) {
      if ($dbadm[$k][0] == $namedroits) {
        unset($dbadm);
        DeleteDBFieldById(DBADMIN, $id=$k);
        break;
      }
    }
    AppendDBFields(DBADMIN,$adm);
    /// fin modif albert -------------------------------
  }
  if($etape==1) {
    ?>
    <p align="center"><?php echo $admin822; ?></p>
    <form action="admin.php?lng=<?php echo $lng; ?>" method="post">
    <input type="hidden" name="lng" value="<?php echo $lng; ?>" />
    <input type="hidden" name="pg" value="attribdroits" />
    <input type="hidden" name="etape" value="2" />
    <p>&nbsp;</p>
    <table cellspacing="0" cellpadding="0" align="center" border="0">
    <tr><td align="center"><select name="namedroits" onchange="submit();">
    <?php
    $dbusersmsg = array();
    $file_users=opendir(USEREP);
    while ($nomfichier=readdir($file_users)) {
      if( substr($nomfichier,-3)=="dtb" ) {
        $dbusersmsg[] = str_replace(substr($nomfichier,-4),"",$nomfichier);
      }
    }
    closedir($file_users);
    @usort($dbusersmsg,'AsciiCompare');
    echo '<option value="" select="selected">'.$admin823.'</option>';
    for ($i = 0; $i < count($dbusersmsg); $i++) {
      if ($dbusersmsg[$i] != $userprefs[1] && $dbusersmsg[$i] != $user[0]) {
        echo "<option value=\"".$dbusersmsg[$i]."\">".$dbusersmsg[$i]."</option>\n";
     }
    }
    ?>
    </select></td></tr>
    </table></form>
    <?php
  }
  if ($etape == 2 || $etape == 3) {
    if (FileDBExist(REDACREP.$namedroits.INCEXT)) {
		include(REDACREP.$namedroits.INCEXT);
    }
    else {
		$drtuser = array();
    }
/************************************************************************************************/
	//Listing des plugins présents
    $pluginlist = ExploreDir('plugins/');
	for ($i = 0; $i < count($pluginlist); $i++) {
		if (!is_file('plugins/'.$pluginlist[$i].'/plugin.inc')) {
			unset($pluginlist[$i]);
		}
	}

	/* Fonctions Javascript */
?>
	<script type="text/javascript">
		function selectAllDroits(opt)
		{
			var option = opt.name;
			var allSelected = opt.checked;
			switch (option) {
				case 'droitsGeneral' :
					var dtrName = 'drtuser';
					var dtrId = new Array(0, 2, 3, 4, 6, 7, 8, 10, 11, 12, 24);
					break;
				case 'droitsSkin' :
					var dtrName = 'drtuser';
					var dtrId = new Array(1, 5, 43);
					break;
				case 'droitsData' :
					var dtrName = 'drtuser';
					var dtrId = new Array(13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 39, 40, 41, 44);
					var dtrName = 'drtuser';
					break;
				case 'droitsPlugin' :
					var dtrName = '';
					var dtrId = new Array();
					var nbPlug = <?php echo count($pluginlist) ?>;
					for(i = 0; i < nbPlug; i++) {
						dtrId[i] = 'drtuserplgform['+ i +']';
					}
					break;
				default :
					return false;
			}

			if (dtrId.length != undefined) {
				for (i = 0; i < dtrId.length; i++) {
					document.forms['droitsUser'].elements[dtrName + dtrId[i]].checked = (allSelected)? true : false;
				}
			}
			return false;
		}
	</script>
<?php
	$maxcol = 4;
	function DisplayService($drt, $lbl, $img, $actif=true) {
	global $cntcol, $maxcol, $drtuser;
		$disp = '';
		if ($actif) {
			if ($cntcol == 0) {
				$disp .= '
    <tr align="center" valign="top">';
			}
			$chk = $drtuser[$drt] == 'on' ? ' checked="checked"' : '';
			$disp .= '
    <td style="width:'.intval(100 / $maxcol).'%">
	  <label>
	    <img src="inc/img/admin/'.$img.'" alt="'.$lbl.'" border="0" />
	    <br />'.$lbl.'<br />
	    <input type="checkbox" name="drtuser'.$drt.'"'.$chk.'. />
	  </label>
	</td>';
			$cntcol++;
			if ($cntcol == $maxcol) {
				$cntcol = 0;
				$disp .= '
    </tr>';
			}
		}
		return $disp;
	}
	function DisplayEndTable() {
	global $cntcol, $maxcol;
		$disp = '';
		if ($cntcol != 0) {
			for ($c = $maxcol; $c > $cntcol; $c--)
				$disp .= '
	<td style="width:'.intval(100 / $maxcol).'%">&nbsp;</td>';
			$disp .= '
	</tr>';
		}
		return $disp;
	}
/*************************************************************************************************/
   ?>
    <div align="center">
    <b><?php echo $admin824." ".$namedroits; ?></b><br /><?php echo $admin825; ?>
    <hr />
    [ <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=droits"><?php echo $admin826; ?></a> || <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b> ]<br />
    <hr />
    </div>
    <br />
    <form  name="droitsUser" action="admin.php?lng=<?php echo $lng; ?>" method="post">
    <input type="hidden" name="lng" value="<?php echo $lng; ?>" />
    <input type="hidden" name="pg" value="attribdroits" />
    <input type="hidden" name="namedroits" value="<?php echo $namedroits; ?>" />
    <input type="hidden" name="etape" value="3" />
    <?php
    if (is_file(USEREP.$namedroits.DBEXT)) {
      $userdb = ReadDBFields(USEREP.$namedroits.DBEXT);
      $drtuser[38] = $userdb[0][0];
    }
    ?>
    <p align="center"><?php echo "<b>$admin715 : </b> $namedroits<br /><br />"; ?>
    <input type ="hidden" name="drtuser38" value="<?php echo $drtuser[38]; ?>" size="15" />
    <?php echo "<b> ".$web437." : </b> "; ?>
    <select name="drtuser42">
    <option value="<?php echo "redac"; ?>"<?php if ($drtuser[42] == "redac") { echo " selected"; } ?>><?php echo $admin715; ?></option>
    <option value="<?php echo "modo"; ?>"<?php if ($drtuser[42] == "modo") { echo " selected"; } ?>><?php echo $admin712; ?></option>
    <option value="<?php echo "webm"; ?>"<?php if ($drtuser[42] == "webm") { echo " selected"; } ?>><?php echo $admin718; ?></option>
    <option value="<?php echo "admin"; ?>"<?php if ($drtuser[42] == "admin") { echo " selected"; } ?>><?php echo $admin714; ?></option>
    </select></p>
    <hr />
    <br />
    <fieldset>
	<legend align="center" style="font-weight: lighter;">
	<?php echo $admin725; ?>
	<input type="checkbox" name="droitsSkin" title="<?php echo $admin893; ?>" style="vertical-align:middle"
<?php
	if ($drtuser[1] && $drtuser[5] && $drtuser[43]) {
		echo ' checked="checked"';
	}
?>
	 onclick="selectAllDroits(this)" />
	</legend>
    <table width="90%" cellspacing="1" cellpadding="5" align="center" border="0">
	<?php
	$cntcol = 0;
	echo 
	DisplayService(1,  $admin45,  'config2.gif').
	DisplayService(5,  $admin346, 'config6.gif').
	DisplayService(43, $admin719, 'css.gif').
	DisplayEndTable();
	?>
	</table>
    </fieldset>
    <br />
    <fieldset>
	<legend align="center" style="font-weight: lighter">
	<?php echo $admin881; ?>
	<input type="checkbox" name="droitsGeneral" title="<?php echo $admin893; ?>" style="vertical-align:middle" 
<?php
	if ($drtuser[0] && $drtuser[2] && $drtuser[3] && $drtuser[4] && $drtuser[6] && ($drtuser[7] || $serviz[13] == '') && $drtuser[8] && $drtuser[10] &&
		$drtuser[11] && ($drtuser[12] || $serviz[42] == '') && ($drtuser[24] || $serviz[13] == '')) {
		echo ' checked="checked"';
	}
?>
	 onclick="selectAllDroits(this)" />
	</legend>
    <table width="90%" cellspacing="1" cellpadding="5" align="center" border="0">
	<?php
	$cntcol = 0;
	echo 
	DisplayService(0,  $admin7,   'config1.gif').
	DisplayService(4,  $admin169, 'config5.gif').
	DisplayService(3,  $admin166, 'config4.gif').
	DisplayService(2,  $admin469, 'config3.gif').
	DisplayService(24, $admin253, 'config7.gif', $serviz[13] == 'on').
	DisplayService(7,  $admin577, 'archive.gif', $serviz[13] == 'on').
	DisplayService(10, $admin816, 'members.gif').
	DisplayService(12, $admin818, 'droits.gif',  $serviz[42] == 'on').
	DisplayService(8,  $admin278, 'dbcheck.gif').
	DisplayService(6,  $admin170, 'maintain.gif').
	DisplayService(11, $admin816, 'maintenance.gif').
	DisplayEndTable();
	?>
    </table>
    </fieldset>
    <br />
    <fieldset>
	<legend align="center" style="font-weight: lighter">
	<?php echo $admin882; ?>
<?php
	$chk = '';
	if ($drtuser[13] && ($drtuser[14] || $serviz[8] == '') && $drtuser[15] && ($drtuser[16] || $serviz[29] == '') && $drtuser[17] && ($drtuser[18] || $serviz[9] == '') && 
		($drtuser[19] || $serviz[10] == '') && ($drtuser[20] || $serviz[11] == '') && ($drtuser[21] || $serviz[14] == '') && ($drtuser[22] || $serviz[12] == '') && 
		($drtuser[23] || $serviz[13] == '') && ($drtuser[25] || $serviz[23] == '') && $drtuser[26] && ($drtuser[27] || $serviz[19] == '') && ($drtuser[28] || $serviz[0] == '') && 
		$drtuser[29] && $drtuser[30] && $drtuser[31] && $drtuser[32] && ($drtuser[33] || $serviz[36] == '') && ($drtuser[34] || $serviz[27] == '') && $drtuser[35] && $drtuser[36] && 
		($drtuser[37] || $serviz[47] == '') && ($drtuser[39] || $serviz[53] == '') && ($drtuser[40] || $serviz[53] == '') && ($drtuser[41] || $serviz[53] == '') && $drtuser[44]) {
		$chk = ' checked="checked"';
	}
?>
	<input type="checkbox" name="droitsData" title="<?php echo $admin893; ?>"<?php echo $chk; ?> style="vertical-align:middle" onclick="selectAllDroits(this)" />
	</legend>
    <table width="90%" cellspacing="1" cellpadding="5" align="center" border="0">
	<?php
	$cntcol = 0;
	echo 
	DisplayService(13, $admin8,   'edito.gif').
	DisplayService(14, $admin13,  'news.gif',       $serviz[8]  == 'on').
	DisplayService(15, $admin5,   'article.gif').
	DisplayService(16, $admin476, 'react.gif',      $serviz[29] == 'on').
	DisplayService(17, $admin16,  'spe.gif').
	DisplayService(18, $admin322, 'photo.gif',      $serviz[9]  == 'on').
	DisplayService(19, $admin18,  'download.gif',   $serviz[10] == 'on').
	DisplayService(20, $admin10,  'links.gif',      $serviz[11] == 'on').
	DisplayService(21, $admin206, 'faq.gif',        $serviz[14] == 'on').
	DisplayService(22, $admin11,  'guestbook.gif',  $serviz[12] == 'on').
	DisplayService(23, $admin9,   'forum.gif',      $serviz[13] == 'on').
	DisplayService(25, $admin15,  'poll.gif',       $serviz[23] == 'on').
	DisplayService(26, $admin270, 'freebox.gif').
	DisplayService(44, $admin952, 'socnet.gif').
	DisplayService(27, $admin263, 'banner.gif',     $serviz[19] == 'on').
	DisplayService(28, $admin6,   'think.gif',      $serviz[0]  == 'on').
	DisplayService(29, $admin14,  'foot.gif').
	DisplayService(30, $admin249, 'reco.gif').
	DisplayService(31, $admin17,  'counter.gif').
	DisplayService(32, $admin212, 'stats.gif').
	DisplayService(33, $admin546, 'newsletter.gif', $serviz[36] != '').
	DisplayService(34, $admin602, 'newsrss.gif',    $serviz[27] == 'on').
	DisplayService(35, $admin553, 'eye.gif').
	DisplayService(36, $admin171, 'upload.gif').
	DisplayService(37, $admin624, 'agenda.gif',     $serviz[47] == 'on').
	DisplayService(39, $admin770, 'blog.gif',       $serviz[53] == 'on').
	DisplayService(40, $admin774, 'reblog.gif',     $serviz[53] == 'on').
	DisplayService(41, $admin791, 'blogrss.gif',    $serviz[53] == 'on').
	DisplayEndTable();
	?>
	</table>
    </fieldset>
    <br />
    <?php
    if (!empty($pluginlist)) {
      ?>
    <fieldset>
	<legend align="center" style="font-weight: lighter">
	<?php echo $admin883; ?>
	<input type="checkbox" name="droitsPlugin" title="<?php echo $admin893; ?>" style="vertical-align:middle" onclick="selectAllDroits(this)" />
	</legend>
    <table width="90%" cellspacing="1" cellpadding="5" align="center" border="0">
    <tr align="center" valign="top">
		<?php
		$listplug     = "";
		$nr_col       = 0;
		$dtrAllPplugs = true;
		$jplug = 0;
		foreach($pluginlist as $plugin) {
			include("plugins/".$plugin."/plugin.inc");
			$nr_col +=1; 
			if ($nr_col > 4) {
				$nr_col = 1; 
				echo "</tr><tr align='center' valign='top'>";
			}
        ?>
    <td style="width:<?php echo intval(100 / $maxcol); ?>%">
      <label>
        <img src="plugins/<?php echo $plugin_admin_icon; ?>" alt="<?php echo $plugin_admin_name; ?>" border="0">
        <br /><?php echo $plugin_admin_name; ?><br />
        <input type="checkbox" name="drtuserplgform[<?php echo $jplug; ?>]" 
			<?php 
			if (FileDBExist(REDACREP.$namedroits.INCEXT) && $drtuserplg[$plugin]) { 
				echo "checked='checked'"; 
			} else { 
				$dtrAllPplugs = false; 
			} 
			?>>
      </label>
</td>
			<?php
			$jplug++;
			if ($listplug != "") $listplug .= "::";
			$listplug .= $plugin;
		}
		while ($nr_col < 4) {echo "<td style='width:25%'>&nbsp;</td>";$nr_col +=1;}
		?>
    </tr></table>
    </fieldset>
<?php
	if($dtrAllPplugs) {
		echo '
			<script type="text/javascript">
			document.forms["droitsUser"].elements["droitsPlugin"].checked = true;
			</script>
		';
	}
?>
    <input type="hidden" name="listplug" value="<?php echo $listplug; ?>" />
    <br />
      <?php
    }
    ?>
    <p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin38; ?>"><?php echo $admin38; ?></button><?php echo $boutonright; ?></p>
    </form>
    <br />
    <?php
  }
  ?>
  <div align="center">
  <hr />
  [ <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=droits"><?php echo $admin826; ?></a> || <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b> ]<br />
  </div>
  <?php
  btable();
  include(CHEMIN."inc/bpage.inc");
?>
