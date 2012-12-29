<?php
/*
    Admin Configuration - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v4.6.0 (04 June 2007)      : initial release extracted form config2 by Icare
      v4.6.10 (07 September 2009): corrected #266 and W3C
	  v4.6.19 (30 March 2012)    : remove cursor in body by Saxbar (thanks tonton_christian)
      v4.6.22 (29 December 2012) : corrected include(CHEMIN.'skin/no_skin/confskin.inc') (thanks JeanMi)		  
*/

if (stristr($_SERVER["SCRIPT_NAME"], "config9.inc")) {
    header("location:../index.php");
    die();
}

// FONCTIONS DE MISE EN PAGE /////////////////////////////////////////////////////////////////////////
function legend($legend) {
	return '<legend style="font-weight:bold;margin-left:30px;padding:0 4px;">'.$legend.'</legend>'."\n";
}
//////////////////////////////////////////////////////////////////////////////////////////////////////

if (!isset($selskin)) $selskin = $page[14];

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
    include(REDACREP.$userprefs[1].INCEXT);
    if ($drtuser[1]=="") {
        $nomzone=$admin888;
        include("access.inc");
        exit();
    }
}

if ($regit == 1) {
    $messreg = " OK";
    include(CONFIG);
    $meskin = CHEMIN."skin/".$selskin."/";
    if (is_file ($meskin."confskin.inc"))
        include ($meskin."confskin.inc");
    else
        include(CHEMIN.'skin/no_skin/confskin.inc');

    if ($page12 != $page[12]) {
        copy(CHEMIN."inc/img/smileys/".$page12."/cool.gif", CHEMIN."inc/img/smileys/cool.gif");
        copy(CHEMIN."inc/img/smileys/".$page12."/wink.gif", CHEMIN."inc/img/smileys/wink.gif");
        copy(CHEMIN."inc/img/smileys/".$page12."/biggrin.gif", CHEMIN."inc/img/smileys/biggrin.gif");
        copy(CHEMIN."inc/img/smileys/".$page12."/smile.gif", CHEMIN."inc/img/smileys/smile.gif");
        copy(CHEMIN."inc/img/smileys/".$page12."/frown.gif", CHEMIN."inc/img/smileys/frown.gif");
        copy(CHEMIN."inc/img/smileys/".$page12."/eek.gif", CHEMIN."inc/img/smileys/eek.gif");
        copy(CHEMIN."inc/img/smileys/".$page12."/mad.gif", CHEMIN."inc/img/smileys/mad.gif");
        copy(CHEMIN."inc/img/smileys/".$page12."/confused.gif", CHEMIN."inc/img/smileys/confused.gif");
        copy(CHEMIN."inc/img/smileys/".$page12."/rolleyes.gif", CHEMIN."inc/img/smileys/rolleyes.gif");
        copy(CHEMIN."inc/img/smileys/".$page12."/tongue.gif", CHEMIN."inc/img/smileys/tongue.gif");
        copy(CHEMIN."inc/img/smileys/".$page12."/cry.gif", CHEMIN."inc/img/smileys/cry.gif");
    }

    $page[9] = $page9; // Thème d'icônes
    $page[11] = $page11; // Thème de compteur de visites
    $page[20] = $page20; // Rollover sur les icnes

    include("inc/confskin.inc");
    $page[12] = $page12; // Thème smileys
    $page[14] = $page14; // Thème skins
    $page[23] = $page23; // Thème avatars
    include("inc/confupdt.inc");

}
include(CONFIG);
$meskin = CHEMIN."skin/".$selskin."/";
if (is_file ($meskin."confskin.inc"))
    include ($meskin."confskin.inc");
else
    include(CHEMIN.'skin/no_skin/confskin.inc');
$topmess = $admin67;
include(CHEMIN."inc/hpage.inc");


$theme = ExploreDir('inc/img/icons/');
$countheme = ExploreDir('inc/img/counter/');
$smileystheme = ExploreDir('inc/img/smileys/');
$skintheme = ExploreDir('skin/');
$progbartheme = ExploreDir('inc/img/progbar/');
$avatartheme = ExploreDir('inc/img/avatars/');
$cursorbody = ExploreFile('inc/img/cursor/');


htable($admin67, "100%");
function GetSelector($inputename='idselector', $default='') {
    return "<input size=\"8\" class=\"texte\" type=\"text\" id=\"".$inputename."\" name=\"".$inputename."\" value=\"".$default."\" /><input id=\"".$inputename."btn\" name=\"".$inputename."btn\" type=\"button\" value=\"    \" onClick=\"opencolorselector('".$inputename."', event)\" style=\"background:".$default."\" />\n";
}

if (isset($selskin)) $skn = "&amp;selskin=".$selskin;
?>
<script type="text/javascript">
	function preview(formName, selectName, buttonName)
	{
		var optSel = document.forms[formName].elements[selectName].selectedIndex;
		optSel = (optSel != -1)? optSel : 0;
		var optVal = document.forms[formName].elements[selectName].options[optSel].value;

		PopupWindow('<?php echo CHEMIN; ?>admin/preview.php?lng=<?php echo $lng; ?>&cat=' + buttonName +'&opt=' + optVal, 'preview', 320, 280, 'yes', 'yes');
		return;
	}
</script>
<div align="center"><p><br /><?php echo $admin889; ?><br /><br /></p>
<hr />
<a href="admin.php?lng=<?php echo $lng.$skn; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b>
<hr />
</div>
<div align="center" style="width:514px;margin-left:auto;margin-right:auto;">
<br />
<form name="conf9" action="admin.php?lng=<?php echo $lng; ?>" method="post">
<input type="hidden" name="pg" value="config9" />
<input type="hidden" name="regit" value="1" />
<fieldset>
<?php
echo legend($admin344);
?>
<table cellspacing="0" cellpadding="4" align="center" border="0" width="100%" summary="">
<tr style="text-align:left;"><td colspan="2">
<p class="forum2" style="text-align:center;"> --------- <?php echo $admin891 ?> ----------</p><br /></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin550; ?></p></td>
<td><select name="page14">
<?php
for ($i = 0; $i < count($skintheme); $i++) {
 if ($page[14] == $skintheme[$i]) {
 $sel = ' selected="selected"';
}
else {
 $sel = "";
 }
 echo "<option value=\"".$skintheme[$i]."\"".$sel.">".$skintheme[$i]."</option>\n";
 }
?>
</select></td></tr>
<tr style="text-align:left;vertical-align:middle;"><td><p>&bull; <?php echo $admin370; ?></p></td>
<td><select name="page12">
<?php
for ($i = 0; $i < count($smileystheme); $i++) {
 if ($page[12] == $smileystheme[$i]) {
 $sel = ' selected="selected"';
}
else {
 $sel = "";
 }
 echo "<option value=\"".$smileystheme[$i]."\"".$sel.">".$smileystheme[$i]."</option>\n";
 }
?>
</select>
&nbsp;<button type="button" style="border:0px;background-color: transparent;" name="smileys_preview" onclick="preview('conf9', 'page12', this.name);" title="<?php echo $web297; ?>"><img src="<?php echo CHEMIN.'inc/img/general/look.gif'; ?>" alt="<?php echo $web297; ?>" /></button></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin809; ?></p></td>
<td><select name="page23">
<?php
for ($i = 0; $i < count($avatartheme); $i++) {
 if ($page[23] == $avatartheme[$i]) {
 $sel = ' selected="selected"';
}
else {
 $sel = "";
 }
 echo "<option value=\"".$avatartheme[$i]."\"".$sel.">".$avatartheme[$i]."</option>\n";
 }
?>
</select>
&nbsp;<button type="button" name="avatars_preview" onclick="preview('conf9', 'page23', this.name);" style=" border:0px;background-color: transparent;" title="<?php echo $web297; ?>"><img src="<?php echo CHEMIN.'inc/img/general/look.gif'; ?>" alt="<?php echo $web297; ?>" /></button></td></tr>
<tr style="text-align:left;"><td colspan="2">
<br /><p class="forum2" style="text-align:center;"> --------- <?php echo $admin888." : <b>".$selskin."</b>"; ?> ----------</p><br /></td></tr>

<tr style="text-align:left;"><td width="50%"><p>&bull; <?php echo $admin306; ?></p></td>
<td width="50%"><select name="page9">
<option value=""><?php echo $admin307; ?></option>
<?php
for ($i = 0; $i < count($theme); $i++) {
 if ($page[9] == $theme[$i]) {
 $sel = ' selected="selected"';
}
else {
 $sel = "";
 }
 echo "<option value=\"".$theme[$i]."\"".$sel.">".$theme[$i]."</option>\n";
 }
?>
</select>
&nbsp;<button type="button" name="icons_preview" onclick="preview('conf9', 'page9', this.name);" style=" border:0px;background-color: transparent;" title="<?php echo $web297; ?>"><img src="<?php echo CHEMIN.'inc/img/general/look.gif'; ?>" alt="<?php echo $web297; ?>" /></button>
<br /><?php echo $admin807; ?> <input type="checkbox" name="page20" <?php if ($page[20]) echo "checked"; ?> /></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin345; ?></p></td>
<td><select name="page11">
<option value=""><?php echo $admin513; ?></option>
<?php
for ($i = 0; $i < count($countheme); $i++) {
 if ($page[11] == $countheme[$i]) {
 $sel = ' selected="selected"';
}
else {
 $sel = "";
 }
 echo "<option value=\"".$countheme[$i]."\"".$sel.">".$countheme[$i]."</option>\n";
 }
?>
</select>
&nbsp;<button type="button" name="counter_preview" onclick="preview('conf9', 'page11', this.name);" style=" border:0px;background-color: transparent;" title="<?php echo $web297; ?>"><img src="<?php echo CHEMIN.'inc/img/general/look.gif'; ?>" alt="<?php echo $web297; ?>" /></button>
</td></tr>
</table>
</fieldset>
<input type="hidden" name="selskin" value="<?php echo $selskin; ?>" />
<p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin66; ?>"><?php echo $admin66; ?></button><?php echo $boutonright; ?></p>
</form>
</div>
<br />
<div align="center"><hr />
<?php if (isset($selskin)) $skn = "&amp;selskin=".$selskin; ?>
<a href="admin.php?lng=<?php echo $lng.$skn; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b>
</div>
<?php
btable();
include(CHEMIN."inc/bpage.inc");
?>