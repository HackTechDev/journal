<?php
/*
    Admin Forum and Categories - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :

      v4.6.0 (15 March 2007)     : initial release by Icare
			                       added forum rules redaction (by Icare)
      v4.6.6 (14 April 2008)     : corrected bad end of fieldset (by Icare)
      v4.6.10(7 September 2009)  : corrected W3C
      v4.6.14(14 February 2011)  : corrected display (thanks Cloe29)
      v4.6.15(30 June 2011)      : new display with three distinctive parts (by Icare)
      v4.6.16(02 September 2011) : control private forum created categories (by Laroche)
      v4.6.17(02 November 2011)  : addition and processing check box for definition private classes (by Laroche)
                                   corrected for compatibility php 4 (by Laroche)
      v4.6.18 (09 February 2012) : corrected for compatibility php 4 (by Laroche)
      v4.6.22 (29 December 2012) : added pseudo-private group for members (by Saxbar)
                                   corrected include(CHEMIN.'skin/no_skin/confskin.inc') (thanks JeanMi)	  
*/

if (stristr($_SERVER["SCRIPT_NAME"], "config7.inc")) {
  header("location:../index.php");
  die();
}
// création automatique des groupes privés associés au forum
include_once (CHEMIN.'inc/func_groups.php');

// FONCTIONS DE MISE EN PAGE /////////////////////////////////////////////////////////////////////////
function legend($legend) {
	return '<legend style="font-weight:bold;margin-left:30px;padding:0 4px;">'.$legend.'</legend>'."\n";
}
//////////////////////////////////////////////////////////////////////////////////////////////////////

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[24]=="") {
    $nomzone=$admin253;
    include("access.inc");
    exit();
  }
}
if ($regit == 1) {
  include(CONFIG);
    if (is_file ($meskin."confskin.inc")) include ($meskin."confskin.inc");
    else include(CHEMIN.'skin/no_skin/confskin.inc');
  $forum[3] = $forum3; // Forum pleine page
  $serviz[18] = $serviz18; // Catégories Forum ON / OFF
  $serviz[34] = $serviz34; // Compteur de lecture Threads Forum
  $forum[4] = $forum4; // Nombre de catégories
  $forum[5] = $forum5; // Durée up en heures
  $forum[6] = $forum6; // Durée au top en jours
  $forum[7] = $forum7; // Echelle
  $forum[8] = $forum8; // Durée nouveau en jours
  $forum[9] = $forum9; // Affichage charte du forum

  include("inc/confupdt.inc");
  include("inc/confskin.inc");
}
if (!empty($upd)) {
  $j = 0;
  for ($i = 0; $i < count($r); $i++) {
    if (!empty($r[$i])) {
	  if ($pr[$i] != '') {
	    $mettre[$j][0] = $v[$i].','.$pr[$i];
		//AddGroup('PR'. $v[$i]);
	  } else {
		$mettre[$j][0] = preg_replace('`[^0-9]`','',$v[$i]);	  	  
	  }
      $mettre[$j][1] = stripSlashes(RemoveConnector($r[$i]));
      $mettre[$j][2] = stripSlashes(RemoveConnector($s[$i]));
      $mettre[$j][3] = stripSlashes(RemoveConnector($t[$i]));
      $mettre[$j][4] = stripSlashes(RemoveConnector($u[$i]));
      $j++;
    }
  }
  WriteDBFields(DBFORUMCAT,$mettre);  
}
include(CONFIG);
include ($meskin."confskin.inc");
$dbwork = ReadDBFields(DBFORUMCAT);
for ($i = 0; $i < count($dbwork); $i++) {
  $z = explode(',', $dbwork[$i][0]);
  $v[$i] = $z[0];
  $w[$i] = empty($z[1])? '': $z[1];
  $r[$i] = $dbwork[$i][1];
  $s[$i] = $dbwork[$i][2];
  $t[$i] = $dbwork[$i][3];
  $u[$i] = $dbwork[$i][4];
}
$topmess = $admin254;
include(CHEMIN."inc/hpage.inc");
htable($admin254, "100%");
?>
<div align="center" style="width:100%;">
  <p style="text-align:center;padding:10px 0;"><?php echo $admin257."<strong>".$admin934."</strong>."; ?></p>
  <hr />
  <br />
  <?php
  if($act == "1") { // config générale
  ?>
    <form action="admin.php?lng=<?php echo $lng; ?>" method="post">
    <input type="hidden" name="regit" value="1" />
    <input type="hidden" name="pg" value="config7" />
    <fieldset>
    <?php
    echo legend($admin863);
    ?>
    <br />
    <table align="center" style="width:75%" summary="">
    <tr><td width="80%"><p>&bull; <?php echo $admin869; ?></p></td><td><p><input type="checkbox" name="forum9"  <?php if ($forum[9]) echo 'checked="checked"'; ?> /></p></td></tr>
    <tr><td width="80%"><p>&bull; <?php echo $admin768; ?></p></td><td><p><input type="checkbox" name="forum3"  <?php if ($forum[3]) echo 'checked="checked"'; ?> /></p></td></tr>
    <tr><td><p>&bull; <?php echo $admin252; ?></p></td><td><p><input type="checkbox" name="serviz18" <?php if ($serviz[18]) echo 'checked="checked"'; ?> /></p></td></tr>
    <tr><td><p>&bull; <?php echo $admin483; ?></p></td><td><p><input type="checkbox" name="serviz34" <?php if ($serviz[34]) echo 'checked="checked"'; ?> /></p></td></tr>
    <tr><td><p>&bull; <?php echo $admin864; ?></p></td><td><p><input type="text" name="forum4"  size="1" value="<?php echo $forum[4]; ?>" /></p></td></tr>
    <tr><td><p>&bull; <?php echo $admin855; ?></p></td><td><p><select name="forum8">
    <option value=""<?php if ($forum[8] == "") { echo ' selected="selected"'; } ?>><?php echo "&nbsp;"; ?></option>
    <option value="1"<?php if ($forum[8] == "1") { echo ' selected="selected"'; } ?>><?php echo "1"; ?></option>
    <option value="2"<?php if ($forum[8] == "2") { echo ' selected="selected"'; } ?>><?php echo "2"; ?></option>
    <option value="3"<?php if ($forum[8] == "3") { echo ' selected="selected"'; } ?>><?php echo "3"; ?></option>
    </select></p></td></tr>
    <tr><td><p>&bull; <?php echo $admin856; ?></p></td><td><p><select name="forum5">
    <option value=""<?php if ($forum[5] == "") { echo ' selected="selected"'; } ?>><?php echo "&nbsp;"; ?></option>
    <option value="1"<?php if ($forum[5] == "1") { echo ' selected="selected"'; } ?>><?php echo "1"; ?></option>
    <option value="2"<?php if ($forum[5] == "2") { echo ' selected="selected"'; } ?>><?php echo "2"; ?></option>
    <option value="3"<?php if ($forum[5] == "3") { echo ' selected="selected"'; } ?>><?php echo "3"; ?></option>
    </select></p></td></tr>
    <tr><td><p>&bull; <?php echo $admin857; ?></p></td><td><p><select name="forum6">
    <option value=""<?php if ($forum[6] == "") { echo ' selected="selected"'; } ?>><?php echo "&nbsp;"; ?></option>
    <option value="1"<?php if ($forum[6] == "1") { echo ' selected="selected"'; } ?>><?php echo "1"; ?></option>
    <option value="2"<?php if ($forum[6] == "2") { echo ' selected="selected"'; } ?>><?php echo "2"; ?></option>
    <option value="3"<?php if ($forum[6] == "3") { echo ' selected="selected"'; } ?>><?php echo "3"; ?></option>
    </select></p></td></tr>
    </table>
    </fieldset>
    <br />
    <fieldset>
    <?php
    echo legend($admin862);
    ?>
    <br />
    <table align="center" style="width:483px;" summary="">
    <tr style="text-align:center"><td><?php echo $admin858; ?></td>
    <td><img src="<?php echo CHEMIN; ?>inc/img/general/rank1.gif" border="0" alt=" * " /></td>
    <td><img src="<?php echo CHEMIN; ?>inc/img/general/rank2.gif" border="0" alt="**" /></td>
    <td><img src="<?php echo CHEMIN; ?>inc/img/general/rank3.gif" border="0" alt="***" /></td>
    <td><img src="<?php echo CHEMIN; ?>inc/img/general/rank4.gif" border="0" alt="****" /></td>
    <td><img src="<?php echo CHEMIN; ?>inc/img/general/rank5.gif" border="0" alt="*****" /></td>
    <td>&nbsp;</td>
    </tr>
    <tr class="quest" style="text-align:center">
    <td><?php echo $admin766; ?></td><td>&nbsp;</td><td>&nbsp;</td><td>&nbsp;</td><td>&nbsp;</td><td>&nbsp;</td>
    <td><input type="radio" name="forum7" value="" <?php if ($forum[7]=="") echo 'checked="checked"'; ?> /></td>
    </tr>
    <tr class="rep" style="text-align:center">
    <td><?php echo $admin859; ?></td><td>10</td><td>30</td><td>60</td><td>100</td><td>+ 100</td>
    <td><input type="radio" name="forum7" value="10-30-60-100" <?php if ($forum[7]=="10-30-60-100") echo 'checked="checked"'; ?> /></td>
    </tr>
    <tr class="quest" style="text-align:center">
    <td><?php echo $admin860; ?></td><td>10</td><td>50</td><td>100</td><td>200</td><td>+ 200</td>
    <td><input type="radio" name="forum7" value="10-50-100-200" <?php if ($forum[7]=="10-50-100-200") echo 'checked="checked"'; ?> /></td>
    </tr>
    <tr class="rep" style="text-align:center">
    <td><?php echo $admin861; ?></td><td>20</td><td>100</td><td>200</td><td>300</td><td>+ 300</td>
    <td><input type="radio" name="forum7" value="20-100-200-300" <?php if ($forum[7]=="20-100-200-300") echo 'checked="checked"'; ?> /></td>
    </tr>
    </table>
    <br />
    </fieldset>
    <br />
    <p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin66; ?>"><?php echo $admin66; ?></button><?php echo $boutonright; ?></p>
    </form>
    <br />
    <hr />
    <br />
    <p align="center"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=config7"><?php echo $admin799; ?></a></p>
  <?php
  } elseif($act == "2") { // config catégories
  ?>
    <br />
    <p style="text-align:center;"><?php echo $admin933."<br />"; ?></p>
    <form action="admin.php?lng=<?php echo $lng; ?>" method="post">
    <input type="hidden" name="pg" value="config7" />
    <input type="hidden" name="upd" value="1" />
    <br />
    <fieldset>
    <?php
    echo legend($admin864);
    ?>
    <br />
      <div align="center">
      <table class="bord" cellpadding="5" cellspacing="0" border="0" align="center" width="504" summary="">
      <tr><td width="100" align="center"><b><?php echo $admin256; ?></b></td>
      <td align="center"><b><?php echo $admin255; ?></b></td></tr>
      </table>
        <div class="bord" style="height:450px;width:500px;position:relative;;overflow:auto;padding:opx;">
        <table cellpadding="5" cellspacing="0" width="483" border="0" summary="">
        <?php
        for ($i = 0; $i < $forum[4]; $i++) {
        if ($i %2 == 0) $color="rep"; else $color="quest"; 
        ?>
        <tr class="<?php echo $color; ?>"><td width="70" nowrap="nowrap"><b><?php echo $admin255." ".($i+1); ?> : </b></td>
        <td width="40" style="vertical-align:middle"><input class="texte" type="text" readonly="readonly" name="v[<?php echo $i; ?>]" size="2" value="<?php if ($v[$i] == "") echo $i+1; else echo preg_replace('`[^0-9]`','',$v[$i]); ?>" /></td>
        <td>
        <?php
        if ($lang[1] != "") {
        echo '<img style="vertical-align:middle" src="'.$flag1.'" width="24" height="16" alt="'.$flag1.'" />&nbsp;';
        }
        ?>
        <input class="texte" type="text" name="r[<?php echo $i; ?>]" size="28" value="<?php echo $r[$i]; ?>" />
		</td>
        </tr>
        <tr class="<?php echo $color; ?>"><td colspan="2" align="right"> - <?php echo $admin767 ?></td>
        <td>
		<input class="texte" type="text" name="t[<?php echo $i; ?>]" size="66" value="<?php echo $t[$i]; ?>" />
		</td>
        </tr>
        <?php
          if ($lang[1] != "") {
          ?>
        <tr class="<?php echo $color; ?>"><td colspan="2" nowrap="nowrap">&nbsp;</td>
        <td><img style="vertical-align:middle" src="<?php echo $flag2; ?>" width="24" height="16" alt="<?php echo $flag2; ?>" /> &nbsp;<input class="texte" type="text" name="s[<?php echo $i; ?>]" size="28" value="<?php echo $s[$i]; ?>" /></td>
        </tr>
        <tr class="<?php echo $color; ?>"><td colspan="2" align="right"> - <?php echo $admin767 ?></td>
        <td><input class="texte" type="text" name="u[<?php echo $i; ?>]" size="66" value="<?php echo $u[$i]; ?>" /></td>
        </td>
        </tr>
          <?php
          } // sélection du groupe privé
		?>  
		<tr class="<?php echo $color; ?>"><td>&nbsp;</td>
		<td colspan="2" align="left" nowrap="nowrap">
		<?php
		$dbgroup = ReadGroups();
		echo $admin932.' :&nbsp;
		<select name="pr['.$i.']" style="width:100px;">';
		echo '
		  <option value = ""> -- '.$web314.' -- </option>';
		echo '
		  <option value = "all_members"'.('all_members' == $w[$i] ? ' selected="selected" ': '').'>all_members</option>';
		foreach($dbgroup as $grp => $mbrs) {
		  echo '
		  <option value = "'.$grp.'"'.($grp == $w[$i] ? ' selected="selected" ': '').'>'.$grp.'</option>'."\n";
		}
		echo '
		</select>';
		?>
		</td>
		</tr>
        <?php
		}
        ?>
        </table>
      </div>
    <br />
    </fieldset>
    <div>
    <p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin38." ".$admin255."s"; ?>"><?php echo $admin38." ".$admin255."s"; ?></button><?php echo $boutonright; ?></p>
    </div>
    </form>
    <br />
    <hr />
    <br />
    <p align="center"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=config7"><?php echo $admin799; ?></a></p>
  <?php
  } else { // icônes
  ?>
  <table cellspacing="0" cellpadding="5" align="center" border="0" summary="" style="width:90%">
  <tr align="center">
  <td nowrap="nowrap"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=rules"><img src="inc/img/admin/config7.gif" alt="<?php echo $admin868 ?>" border="0"/><br /><?php echo $admin868 ?></a></td>
  <td nowrap="nowrap"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=config7&amp;act=1"><img src="inc/img/admin/config7.gif" alt="<?php echo $admin253 ?>" border="0"/><br /><?php echo $admin253 ?></a></td>
  <td nowrap="nowrap"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=config7&amp;act=2"><img src="inc/img/admin/config7.gif" alt="<?php echo ucfirst($admin934); ?>" border="0"/><br /><?php echo ucfirst($admin934); ?></a></td>
  </tr>
  </table>
  <br />
  <hr />
  <br />

  <?php
  }
  ?>
</div>
<p align="center"> [ <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b> ]</p>
<?php
btable();
include(CHEMIN."inc/bpage.inc");

?>
