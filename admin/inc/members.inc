<?php
/*
    Zone members configuration - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v4.0.0 (06 December 2004)   : initial release by Nicolas Alves
      v4.6.0 (04 June 2007)       : added fieldset (by Icare)
                                    added blog area (by Icare)
                                    corrected &amp; when calling tinymsg popup (by Jchouix)
                                    added subscription to newsletter (by Icare)
                                    corrected sort of members (by Icare)
      v4.6.5 (05 December 2007)   : added rich text in general message (by Icare)
      v4.6.7 (23 April 2008)      : corrected $msg1 and $msg2 tags (by Icare)
      v4.6.8 (24 May 2008)        : corrected $msg2 in line 230-231 (by Icare)
      v4.6.10 (07 September 2009) : corrected W3C
      v4.6.12 (01 May 2010)       : corrected #317
      v4.6.13 (22 May 2010)       : corrected #323
      v4.6.15 (30 June 2011)      : corrected #nnn, added groups management (by Icare)
      v4.6.16 (02 September 2011) : change management members registration (by Laroche)
      v4.6.17 (21 October 2011)   : addition of members in a group (by Saxbar)
	  v4.6.18 (09 February 2012)  : corrected short tag in line 236 (by Laroche)
      v4.6.22 (29 December 2012)  : corrected include(CHEMIN.'skin/no_skin/confskin.inc') (thanks JeanMi)		  
*/

if (stristr($_SERVER["SCRIPT_NAME"], "members.inc")) {
    header("location:../index.php");
    die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[10]=="") {
    $nomzone=$admin816;
    include("access.inc");
    exit();
  }
}
if ($regit == 1) {
  include(CONFIG);
  if ($act == 2) {
	$members[19] = $members19; // Ne modifier que l'inscription membres
  } else {
	$members[0] = $members0; // Activation de la zone membres
	$members[1] = $members1; // Zone membre accès à la section Articles
	$members[2] = $members2; // Zone membre accès à la section Photo
	$members[3] = $members3; // Zone membre accès à la section Liens
	$members[4] = $members4; // Zone membre accès à la section FAQ
	$members[5] = $members5; // Zone membre accès à la section Forum
	$members[6] = $members6; // Zone membre accès à la section Statistiques
	$members[7] = $members7; // Zone membre accès à la section Téléchargement
	$members[8] = $members8; // Zone membre accès publication Nouvelles
	$members[9] = $members9; // Zone membre accès publication Livre d'Or
	$members[10] = $members10; // Zone membre accès publication Forum
	$members[11] = $members11; // Zone membre accès publication Réactions aux articles
	$members[12] = $members12; // Zone membre accès à la section Livre d'Or
	$members[13] = $members13; // Zone membre accès à la section Nouvelles
	$members[14] = $members14; // Zone membre accès à la section Agenda
	$members[15] = $members15; // Zone membre accès à la section Blog
	$members[16] = $members16; // Zone membre accès publication Blog
	$members[17] = $members17; // Zone membre accès à publication Commentaires blogs
	$members[18] = $members18; // Zone membre accès à inscription Newsletter
  }
  include("inc/confupdt.inc");
}
include(CONFIG);
if (is_file ($meskin."confskin.inc")) include ($meskin."confskin.inc");
  else include(CHEMIN.'skin/no_skin/confskin.inc');
include(CHEMIN."inc/hpage.inc");

if($act == 1) { // config zone
  htable($admin829, "100%");
  ?>
  <br />
  <p align="center"><?php echo $admin830; ?></p>
  <br />
  <p>&nbsp;</p>
  <form name="members" action="admin.php?lng=<?php echo $lng; ?>" method="post">
  <input type="hidden" name="pg" value="members" />
  <input type="hidden" name="regit" value="1" />
  <table cellspacing="0" cellpadding="2" align="center" border="0" summary="">
  <tr><td colspan="2" align="center"><b><?php echo $admin832; ?></b><input type="checkbox" name="members0" <?php if ($members[0]) echo 'checked="checked"'; ?> /></td></tr>
  </table>
  <hr />
  <div style="width:82%;margin-left:auto;margin-right:auto;">
  <fieldset><legend><?php echo $admin831; ?></legend>
  <br />
  <table cellspacing="0" cellpadding="2" align="center" border="0" width="80%" summary="">
  <tr><td><p>&bull; <?php echo $admin833; ?></p></td><td><p><input type="checkbox" name="members1" <?php if ($members[1]) echo 'checked="checked"'; ?> /></p></td></tr>
  <tr><td><p>&bull; <?php echo $admin834; ?></p></td><td><p><input type="checkbox" name="members2" <?php if ($members[2]) echo 'checked="checked"'; ?> /></p></td></tr>
  <tr><td><p>&bull; <?php echo $admin835; ?></p></td><td><p><input type="checkbox" name="members3" <?php if ($members[3]) echo 'checked="checked"'; ?> /></p></td></tr>
  <tr><td><p>&bull; <?php echo $admin836; ?></p></td><td><p><input type="checkbox" name="members4" <?php if ($members[4]) echo 'checked="checked"'; ?> /></p></td></tr>
  <tr><td><p>&bull; <?php echo $admin837; ?></p></td><td><p><input type="checkbox" name="members5" <?php if ($members[5]) echo 'checked="checked"'; ?> /></p></td></tr>
  <tr><td><p>&bull; <?php echo $admin838; ?></p></td><td><p><input type="checkbox" name="members6" <?php if ($members[6]) echo 'checked="checked"'; ?> /></p></td></tr>
  <tr><td><p>&bull; <?php echo $admin839; ?></p></td><td><p><input type="checkbox" name="members7" <?php if ($members[7]) echo 'checked="checked"'; ?> /></p></td></tr>
  <tr><td><p>&bull; <?php echo $admin840; ?></p></td><td><p><input type="checkbox" name="members12" <?php if ($members[12]) echo 'checked="checked"'; ?> /></p></td></tr>
  <tr><td><p>&bull; <?php echo $admin841; ?></p></td><td><p><input type="checkbox" name="members13" <?php if ($members[13]) echo 'checked="checked"'; ?> /></p></td></tr>
  <tr><td><p>&bull; <?php echo $admin651; ?></p></td><td><p><input type="checkbox" name="members14" <?php if ($members[14]) echo 'checked="checked"'; ?> /></p></td></tr>
  <tr><td><p>&bull; <?php echo $admin770; ?></p></td><td><p><input type="checkbox" name="members15" <?php if ($members[15]) echo 'checked="checked"'; ?> /></p></td></tr>
  <tr><td><p>&bull; <?php echo $admin547; ?></p></td><td><p><input type="checkbox" name="members18" <?php if ($members[18]) echo 'checked="checked"'; ?> /></p></td></tr>
  </table>
  </fieldset>
  <br />
  <fieldset><legend><?php echo $admin842; ?></legend>
  <br />
  <table cellspacing="0" cellpadding="2" align="center" border="0" width="80%" summary="">
  <tr><td><p>&bull; <?php echo $admin843; ?></p></td><td><p><input type="checkbox" name="members8" <?php if ($members[8]) echo 'checked="checked"'; ?> /></p></td></tr>
  <tr><td><p>&bull; <?php echo $admin844; ?></p></td><td><p><input type="checkbox" name="members9" <?php if ($members[9]) echo 'checked="checked"'; ?> /></p></td></tr>
  <tr><td><p>&bull; <?php echo $admin845; ?></p></td><td><p><input type="checkbox" name="members10" <?php if ($members[10]) echo 'checked="checked"'; ?> /></p></td></tr>
  <tr><td><p>&bull; <?php echo $admin846; ?></p></td><td><p><input type="checkbox" name="members11" <?php if ($members[11]) echo 'checked="checked"'; ?> /></p></td></tr>
  <tr><td><p>&bull; <?php echo $admin773; ?></p></td><td><p><input type="checkbox" name="members16" <?php if ($members[16]) echo 'checked="checked"'; ?> /></p></td></tr>
  <tr><td><p>&bull; <?php echo $admin774; ?></p></td><td><p><input type="checkbox" name="members17" <?php if ($members[17]) echo 'checked="checked"'; ?> /></p></td></tr>
  </table>
  </fieldset>
  <p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin66; ?>"><?php echo $admin66; ?></button><?php echo $boutonright; ?></p>
  </div>
  </form>
  <div align="center"><hr />
  <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=members"><?php echo $admin687 ?></a> || <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b>
  </div>
  <?php
}
elseif ($act == 2) { // gestion membres, supp
  include_once (CHEMIN.'inc/func_groups.php');
  if (!empty($del)) { //supprimer membre
    @chmod(USEREP.$del.".dtb",0777);
    unlink(USEREP.$del.".dtb");
    // modif supprimer membre des groupes privés
    DestroyMember($del);
  }
  $dbuserspref = array();
  $file_users=opendir(USEREP);
  while ($nomfichier=readdir($file_users)) {
    if ( substr($nomfichier,-3) == "dtb") {
      $dbuserspref[] = str_replace(substr($nomfichier,-4),"",$nomfichier);
    }
  }
  closedir($file_users);
  @usort($dbuserspref,'AsciiCompare');
  htable($admin696, "100%"); // liste
    echo '  <br />
    <p align="center">'.$admin700.'</p><hr /><br />'."\n";
/// select mode
    echo '
<form name="membnew" action="admin.php?lng='.$lng.'&amp;pg=members" method="post">
  <p align="center"><strong>'.$web458.' :&nbsp;</strong>
  <input type="hidden" name="regit" value="1" />
  <input type="hidden" name="act" value="2" />
  <select name="members19" onchange="javascript:membnew.submit();">';
    echo '    <option value = ""'; if ($members[19] == "") {echo ' selected="selected"';} echo '>'.$admin935.'</option>';
    echo '    <option value = "0"'; if ($members[19] == "0") {echo ' selected="selected"';} echo '>'.$admin936.'</option>';
    echo '    <option value = "1"'; if ($members[19] == "1") {echo ' selected="selected"';} echo '>'.$admin937.'</option>';
    echo '    <option value = "2"'; if ($members[19] == "2") {echo ' selected="selected"';} echo '>'.$admin938.'</option>';
    echo '
  </select>
  <input type="image" src="'.CHEMIN.'inc/img/general/tolist.gif" alt="'.$admin144.'" title="'.$admin144.'" style="vertical-align:middle;" />
  </p>
</form><br />
  <hr />
  <p align="center"><br /><strong>'.$admin939.' :&nbsp;</strong></p>';
/// fin mode
    echo '<table class="bord" cellspacing="1" cellpadding="2" align="center" width="360" border="0" summary="">
    <tr class="forum2" style="padding: 8px 0;">
    <td width="50%"><b>'.$admin517.'</b></td>'."\n";
    echo '<td width="30%" style="text-align:left"><b>'.ucfirst($admin928).'</b></td>
    <td align="center"><b>'.$admin186.'</b></td></tr>'."\n";
    $grps = ReadGroups();
    for ($i = 0; $i < count($dbuserspref); $i++) {
      if ($i %2 == 0) echo "<tr class=\"rep\">";
      else echo "<tr class=\"quest\">";
      $userdb = ReadDBFields(USEREP.$dbuserspref[$i].".dtb");
      echo "<td style='vertical-align:top'>".$dbuserspref[$i]."</td>\n";
      echo "<td style='text-align:left;'>";
      $dbgroup = ReadDBFields(CHEMIN.DATAREP."groups.dtb");
      for ($x = 0; $x < count($dbgroup); $x++) {
        for ($m = 0; $m < count($dbgroup[$x]); $m++) {
          if ($dbgroup[$x][$m] == $dbuserspref[$i])
          echo $dbgroup[$x][0]."<br />";
        }
      }
      echo "</td><td style='text-align:center;vertical-align:top'>\n";
      echo "<a href=\"admin.php?lng=".$lng."&amp;pg=members&amp;act=2&amp;del=".$dbuserspref[$i]."\" title=\"".$admin186."\">
        <img src=\"inc/img/files/sup.gif\" width=\"14\" height=\"14\" alt=\"".$admin186."\" border=\"0\">
        </a></td>";
      echo "</tr>";
    }
    echo "</table><br />";
  ?>
  <hr />
  <p align="center"><br />
  <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=members"><?php echo $admin687 ?></a> || <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b></p>
  <?php
} elseif ($act == 3) { // rédiger message
  htable($admin697, "100%");
  ?>
  <br /><p align="center"><?php echo $admin698 ?><br /><?php echo $admin699 ?></p><hr />
  <script language="javascript" type="text/javascript" src="<?php echo CHEMIN; ?>admin/inc/tinymsg.js"></script>
  <form name="membmsg" action="admin.php?lng=<?php echo $lng; ?>" method="post">
  <input type="hidden" name="pg" value="members" />
  <input type="hidden" name="regit" value="2" />
  <input type="hidden" name="act" value="4" />
  <table cellspacing="0" cellpadding="2" align="center" border="0" summary="">
  <tr><td align="center">
  <img src="<?php echo $flag1; ?>" width="24" height="16" alt="<?php echo $lang[0] ?>"/><br />
  </td></tr>
  <tr><td bgcolor="#FFFFFF" align="center"><textarea cols="40" rows="10" name="msg1"></textarea></td></tr>
  <tr><td align="center" style="vertical-align:middle">
  <a href="javascript: format1('b')"><img class="clsCursor" border="0" src="<?php echo CHEMIN; ?>inc/pgeditor/images/bold.gif" alt="<?php echo $web98; ?>" title="<?php echo $web98; ?>" /></a>&nbsp;
  <a href="javascript: format1('i')"><img class="clsCursor" border="0" src="<?php echo CHEMIN; ?>inc/pgeditor/images/italic.gif" alt="<?php echo $web100; ?>" title="<?php echo $web100; ?>" /></a>&nbsp;
  <a href="javascript: format1('u')"><img class="clsCursor" border="0" src="<?php echo CHEMIN; ?>inc/pgeditor/images/underline.gif" alt="<?php echo $web99; ?>" title="<?php echo $web99; ?>" /></a>&nbsp;
  <a href="javascript: dolink1 ('href=http://<?php echo $admin457; ?>')"><img class="clsCursor" border="0" src="<?php echo CHEMIN; ?>inc/pgeditor/images/link.gif" alt="<?php echo $web170; ?>" title="<?php echo $web170; ?>" /></a>&nbsp;  &nbsp;
  <?php DrawSmileys("1"); ?></td></tr>
  <?php
  if ($lang[1] != "") {
    ?>
    <tr><td align="center">
    <img src="<?php echo $flag2; ?>" width="24" height="16" alt="<?php echo $lang[1] ?>"><br />
    </td></tr>
    <tr><td bgcolor="#FFFFFF" align="center"><textarea cols="40" rows="10" name="msg2"></textarea></td></tr>
    <tr><td align="center" style="vertical-align:middle">
    <a href="javascript: format2('b')"><img class="clsCursor" border="0" src="<?php echo CHEMIN; ?>inc/pgeditor/images/bold.gif" alt="<?php echo $web98; ?>" title="<?php echo $web98; ?>" /></a>&nbsp;
    <a href="javascript: format2('i')"><img class="clsCursor" border="0" src="<?php echo CHEMIN; ?>inc/pgeditor/images/italic.gif" alt="<?php echo $web100; ?>" title="<?php echo $web100; ?>" /></a>&nbsp;
    <a href="javascript: format2('u')"><img class="clsCursor" border="0" src="<?php echo CHEMIN; ?>inc/pgeditor/images/underline.gif" alt="<?php echo $web99; ?>" title="<?php echo $web99; ?>" /></a>&nbsp;
    <a href="javascript: dolink2 ('href=http://<?php echo $admin457; ?>')"><img class="clsCursor" border="0" src="<?php echo CHEMIN; ?>inc/pgeditor/images/link.gif" alt="<?php echo $web170; ?>" title="<?php echo $web170; ?>" /></a>&nbsp;  &nbsp;
    <?php DrawSmileys("2"); ?></td></tr>
    <?php
  }
  ?>
  </table>
  <p>&nbsp;</p>
  <p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin694; ?>"><?php echo $admin694; ?></button><?php echo $boutonright; ?></p>
  </form>
  <div align="center"><hr />
  <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=members"><?php echo $admin687 ?></a> || <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b>
  </div>
  <?php
}
elseif ($act == 4) { // envoyer message
  htable($admin691, "100%");
  if ($regit==2) { // enregistrer
    $msg1 = str_replace(chr(10),"<br />",$msg1);
    $msg1 = str_replace(chr(13),"",$msg1);
    $msg1 = str_replace("[b]","<b>",$msg1);
    $msg1 = str_replace("[/b]","</b>",$msg1);
    $msg1 = str_replace("[i]","<i>",$msg1);
    $msg1 = str_replace("[/i]","</i>",$msg1);
    $msg1 = str_replace("[u]","<u>",$msg1);
    $msg1 = str_replace("[/u]","</u>",$msg1);
    $msg1 = str_replace("[l]href=","<a href='",$msg1);
    $msg1 = str_replace("[/l]","' target='_blank'><img src='".CHEMIN."inc/img/general/site.gif' border='0' alt='".$web304."' /></a>",$msg1);
    $msg1 = str_replace("\"","'",$msg1);
    $msg2 = str_replace(chr(10),"<br />",$msg2);
    $msg2 = str_replace(chr(13),"",$msg2);
    $msg2 = str_replace("[b]","<b>",$msg2);
    $msg2 = str_replace("[/b]","</b>",$msg2);
    $msg2 = str_replace("[i]","<i>",$msg2);
    $msg2 = str_replace("[/i]","</i>",$msg2);
    $msg2 = str_replace("[u]","<u>",$msg2);
    $msg2 = str_replace("[/u]","</u>",$msg2);
    $msg2 = str_replace("[l]href=","<a href='",$msg2);
    $msg2 = str_replace("[/l]","' target='_blank'><img src='".CHEMIN."inc/img/general/site.gif' border='0' alt='".$web304."' /></a>",$msg2);
    $msg2 = str_replace("\"","'",$msg2);
    $rec = "<?php
\$tinymsg1 = stripslashes(\"$msg1\");
\$tinymsg2 = stripslashes(\"$msg2\");
?>";
?><?php
    WriteFullDB(CHEMIN.DATAREP."sendtinymsg.inc",$rec);
  }
  include(CHEMIN.DATAREP."sendtinymsg.inc");
  ?>
  <p align="center"><?php echo $admin689 ?><br />
  </p><hr />
  <p align="center"><img src="<?php echo $flag1 ?>" width="24" height="16" alt="<?php echo $lang[0] ?>"/></p>
  <div class='bord' style='width:80%;margin:0 auto;'>
  <?php
  echo PathToImage(replaceimg($tinymsg1)); //modif path image lien
  if ($lang[1] != "") {
    ?>
    </div>
    <p align="center"><br /><img src="<?php echo $flag2; ?>" width="24" height="16" alt="<?php echo $lang[1] ?>"/></p>
    <div class='bord' style='width:80%;margin:0 auto;'>
    <?php
    echo PathToImage(replaceimg($tinymsg2)); // modif path image lien
  }
  ?>
  </div>
  <div align="center"><?php echo $boutonleft; ?><input class="bouton" type="button" value="<?php echo $admin694 ?>" title="<?php echo $admin694 ?>" onClick="javascript:PopupWindow('inc/tinymsg.php?lng=<?php echo $lng ?>&redige=1&lsn=0','tinymsg',400,250,'no','no')" /><?php echo $boutonright; ?>
  <hr />
  <a href="javascript:history.back()"><?php echo $admin688 ?></a> ||<a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=members"><?php echo $admin687 ?></a> || <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b>
  </div>
  <?php
}
elseif ($act == 5) { // gestion groupes
    include_once (CHEMIN.'inc/func_groups.php');
    $mess = '';
    if ($regit == 5 && $group != "") { //ajouter groupe
        $group = preg_replace("! !", "_", $group);
        $mess = AddGroup($group,$obj)? ucfirst($admin928)." ".$group.$admin929." !" : ucfirst($admin928)." ".$group.$admin931;
    } elseif ($regit == 6) { // supprimer groupe
        $mess = DelGroup($group) ? ucfirst($admin928)." ".$group.$admin930." !" : ucfirst($admin928)." ".$group.' '.strtolower($web314).$admin930.' !';
    }
    $grps = ReadGroups();
    htable($admin925, "100%");
    echo '
<br /><p align="center">'.$admin926.'<br /></p>
<br /><hr />
<br />'.$mess.'<br />
<table class="bord" cellspacing="1" cellpadding="2" align="center" width="300" border="0" summary="">
  <tr class="forum">
    <td width="66%" style="text-align:left;"><b>'.ucfirst($admin928).'</b></td>
    <td colspan="2" align="center"><b>'.$admin680.'</b></td>
  </tr>';
    foreach ($grps as $grp=>$mbrs) {
    echo '
  <tr class="rep">
    <td width="33%" style="text-align:left;">'.$grp.'</td>
    <td style="text-align:center;"><a href="admin.php?lng='.$lng.'&amp;pg=members&amp;act=6&amp;group='.$grp.'" title="'.$admin144.' '.$grp.'"><img src="inc/img/files/edit.gif" alt="'.$admin144.'" border="0"/></a><br /></td>
    <td style="text-align:center;"><a href="admin.php?lng='.$lng.'&amp;pg=members&amp;act=5&amp;regit=6&amp;group='.$grp.'" title="'.$admin186.' '.$grp.'"><img src="inc/img/files/sup.gif" alt="'.$admin186.'" border="0" /></a><br /></td>
  </tr>';
    }
    unset($grps);
    echo '
</table><br />';
      ?>
      <form name="membgrp" action="admin.php?lng=<?php echo $lng; ?>" method="post">
      <input type="hidden" name="pg" value="members" />
      <input type="hidden" name="regit" value="5" />
      <input type="hidden" name="act" value="5" />
      <p style="text-align:center"><?php echo $web371." ".$admin928." : ";?>
      <input class="texte" type="text" name="group" value="" style="width:196px;" /><br />
      <!--<?php echo $admin767; ?>
               <input type="text" name="obj" value="" style="width:250px;" /><br /> -->
      <br /><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin38; ?>"><?php echo $admin38; ?></button><?php echo $boutonright; ?></p>
      </form><br />
  <hr />
  <p align="center"><br />
  <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=members"><?php echo $admin687 ?></a> || <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b></p>
  <?php
} elseif ($act == 6) { //gestion membres du groupe
    include_once (CHEMIN.'inc/func_groups.php');
    $mess = '';
    if ($regit == "add" && $group != "" && count($aMembers) > 0) { //ajouter membre
			foreach ($aMembers as $member) {
        $mess .= AddMember($group, $member) ? ucfirst($admin928)." ".$group." : ".$web322." ".$member.$admin929." !" : ucfirst($web322).' '.$member.$admin931;
				$mess .= '<br />';
			}
    } elseif ($regit == "del" && $group != "" && $member != "") { // supprimer membre
        $mess = DelMember($group, $member) ? ucfirst($admin928)." ".$group." : ".$web322." ".$member.$admin930." !" : ucfirst($web322).' '.$member.' '.strtolower($web314).$admin930.' !';
    }
    $grps = ReadGroups();
		$lst = $grps[$group];
    htable(ucfirst($admin928)." ".$group, "100%");
		if ($mess != "") 
    echo '
<br /><p align="center">'.$admin927.'</p>
<br /><hr />
<br />'.$mess.'<br /><br />'."\n";
    if (FileDBExist(CHEMIN.DATAREP."groups.dtb")) {
        echo '
<table class="bord" cellspacing="1" cellpadding="2" align="center" width="300" border="0" summary="">
  <tr class="forum">
    <td width="66%" style="text-align:left;"><b>Membres</b></td>
    <td align="center"><b>'.$admin186.'</b></td>
  </tr>';
        foreach ($grps[$group] as $mbr) {
            echo '
  <tr class="rep">
    <td width="33%" style="text-align:left;">'.$mbr.'</td>
    <td style="text-align:center;"><a href="admin.php?lng='.$lng.'&amp;pg=members&amp;act=6&amp;regit=del&amp;group='.$group.'&amp;member='.$mbr.'" title="'.$admin186.' '.$mbr.' de '.$group.'"><img src="inc/img/files/sup.gif" alt="'.$admin186.'" border="0" /></a><br /></td>
  </tr>';
          }
        unset($grps);
        echo '
</table><br />';
      ?>
      <form name="members" action="admin.php?lng=<?php echo $lng; ?>" method="post">
      <input type="hidden" name="pg" value="members" />
      <input type="hidden" name="regit" value="add" />
      <input type="hidden" name="act" value="6" />
      <input type="hidden" name="group" value="<?php echo $group; ?>" />
      <p style="text-align:center"><?php echo $web371." ".$web322." : ";?><br />
      <?php
  $dbuserspref = array();
  $file_users=opendir(USEREP);
  while ($nomfichier=readdir($file_users)) {
    if ( substr($nomfichier,-3) == "dtb") {
			$nomuser = str_replace(substr($nomfichier,-4),"",$nomfichier);
			if (!in_array($nomuser, $lst)) $dbuserspref[] = $nomuser;
    }
  }
  closedir($file_users);
  @usort($dbuserspref,'AsciiCompare');
	unset($lst);
  echo "<select id='aMembers' name='aMembers[]' style='width:140px;' size='20' multiple='multiple'>\n";
  for ($i = 0; $i < count($dbuserspref); $i++) {
    echo "<option value='".$dbuserspref[$i]."'>".$dbuserspref[$i]."</option>";
  }
  echo "</select><br />\n";
      ?>
      <br /><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin38; ?>"><?php echo $admin38; ?></button><?php echo $boutonright; ?>
      </form>
      <br /></p>
    <?php
    }
    ?>
  <br /><hr />
  <p align="center" style="padding:10px 0;">
  <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=members&amp;act=5"><?php echo $web135.' '.$admin925; ?></a><br />
  <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=members"><?php echo $admin687 ?></a> || <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b></p>
  <?php
} else {
  htable($admin829, "100%");
  ?>
  <div align="center">
  <br /><p><?php echo $admin701 ?></p>
  <br /><hr /></div><br />
  <table cellspacing="0" cellpadding="3" align="center" border="0" summary="" style="width:90%">
  <tr align="center">
  <td nowrap="nowrap"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=members&amp;act=1"><img src="inc/img/admin/members.gif" alt="<?php echo $admin695 ?>" border="0"/><br /><?php echo $admin695 ?></a></td>
  <td nowrap="nowrap"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=members&amp;act=5"><img src="inc/img/admin/members.gif" alt="<?php echo $admin697 ?>" border="0"/><br /><?php echo $admin925 ?></a></td>
  <td nowrap="nowrap"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=members&amp;act=2"><img src="inc/img/admin/members.gif" alt="<?php echo $admin696 ?>" border="0"/><br /><?php echo $admin696 ?></a></td>
  <td nowrap="nowrap"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=members&amp;act=3"><img src="inc/img/admin/members.gif" alt="<?php echo $admin697 ?>" border="0"/><br /><?php echo $admin697 ?></a></td>
  </tr>
  </table>
  <div align="center"><br /><hr /><br />
  <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b>
  </div>
  <?php
}
btable();
include(CHEMIN."inc/bpage.inc");
?>
