<?php
/*
    Admin Configuration Logs - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v3.0 (25 February 2004)  : initial release by B@lou, Nicolas Alves and Laurent Duveau (real team work!)
      v4.0 (06 December 2004)  : added page title (by Jean-Mi)
	                             added multi-admin management (by Nicolas Alves)
	  v4.5 (21 April 2005)     : corrected according new security rules (by JeanMi)
	  v4.6.0 (04 June 2007)    : added blog stats, thanks B@lou
      v4.6.10 (7 September 2009)    : corrected #274
*/

if (stristr($_SERVER["SCRIPT_NAME"], "logconfig.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[35]=="") {
    $nomzone=$admin553;
    include("access.inc");
    exit();
  }
}
header("Pragma: no-cache");
define("CHEMIN", "../");
$topmess = $admin556;
include(CHEMIN."inc/hpage.inc");
htable($admin556, "100%");
?>
<p align="center"><?php echo $admin566."<br /><br /><br />"; ?></p><hr />
<?php
if ($regit == 1) {
  include(CONFIG);
  $configlog[0] = $configlog0; // Nombre des messages visibles dans l'admin log
  $configlog[1] = $configlog1; // Inclure les logs de la page Index / Accueil
  $configlog[2] = $configlog2; // Inclure les logs de la page Nouvelles
  $configlog[3] = $configlog3; // Inclure les logs de la page Photos
  $configlog[4] = $configlog4; // Inclure les logs de la page Téléchargement
  $configlog[5] = $configlog5; // Inclure les logs de la page Liens
  $configlog[6] = $configlog6; // Inclure les logs de la page FAQ
  $configlog[7] = $configlog7; // Inclure les logs de la page Livre d'or
  $configlog[8] = $configlog8; // Inclure les logs de la page Forum
  $configlog[9] = $configlog9; // Inclure les logs de la page Stats
  $configlog[10] = $configlog10; // Inclure les logs de la page Admin
  $configlog[11] = $configlog11; // Inclure les logs de la page Blog
  include("inc/confupdt.inc");
}
include(CONFIG);
?>
<form name="logconfig" action="admin.php?lng=<?php echo $lng; ?>" method="post">
<input type="hidden" name="pg" value="logconfig" />
<input type="hidden" name="regit" value="1" />
<table cellspacing="5" cellpadding="2" align="center" width="80%" border="0" summary="">
<tr><td>&bull; <?php echo $admin565; ?></td><td><select name="configlog0">
<option value="10"<?php if ($configlog[0] == "10") { echo " selected='selected'"; } ?>>10</option>
<option value="50"<?php if ($configlog[0] == "50") { echo " selected='selected'"; } ?>>50</option>
<option value="75"<?php if ($configlog[0] == "75") { echo " selected='selected'"; } ?>>75</option>
<option value="100"<?php if ($configlog[0] == "100") { echo " selected='selected'"; } ?>>100</option>
<option value="125"<?php if ($configlog[0] == "125") { echo " selected='selected'"; } ?>>125</option>
<option value="150"<?php if ($configlog[0] == "150") { echo " selected='selected'"; } ?>>150</option>
<option value="175"<?php if ($configlog[0] == "175") { echo " selected='selected'"; } ?>>175</option>
<option value="200"<?php if ($configlog[0] == "200") { echo " selected='selected'"; } ?>>200</option>
<option value="225"<?php if ($configlog[0] == "225") { echo " selected='selected'"; } ?>>225</option>
<option value="250"<?php if ($configlog[0] == "250") { echo " selected='selected'"; } ?>>250</option>
<option value="300"<?php if ($configlog[0] == "300") { echo " selected='selected'"; } ?>>300</option>
</select></td></tr>
<tr><td>&bull; <?php echo $admin567; ?></td><td><input type="checkbox" name="configlog1" <?php if ($configlog[1]) echo "checked='checked'"; ?> /></td></tr>
<tr><td>&bull; <?php echo $admin568; ?></td><td><input type="checkbox" name="configlog2" <?php if ($configlog[2]) echo "checked='checked'"; ?> /></td></tr>
<tr><td>&bull; <?php echo $admin569; ?></td><td><input type="checkbox" name="configlog3" <?php if ($configlog[3]) echo "checked='checked'"; ?> /></td></tr>
<tr><td>&bull; <?php echo $admin570; ?></td><td><input type="checkbox" name="configlog4" <?php if ($configlog[4]) echo "checked='checked'"; ?> /></td></tr>
<tr><td>&bull; <?php echo $admin571; ?></td><td><input type="checkbox" name="configlog5" <?php if ($configlog[5]) echo "checked='checked'"; ?> /></td></tr>
<tr><td>&bull; <?php echo $admin572; ?></td><td><input type="checkbox" name="configlog6" <?php if ($configlog[6]) echo "checked='checked'"; ?> /></td></tr>
<tr><td>&bull; <?php echo $admin573; ?></td><td><input type="checkbox" name="configlog7" <?php if ($configlog[7]) echo "checked='checked'"; ?> /></td></tr>
<tr><td>&bull; <?php echo $admin574; ?></td><td><input type="checkbox" name="configlog8" <?php if ($configlog[8]) echo "checked='checked'"; ?> /></td></tr>
<tr><td>&bull; <?php echo $admin552; ?></td><td><input type="checkbox" name="configlog9" <?php if ($configlog[9]) echo "checked='checked'"; ?> /></td></tr>
<tr><td>&bull; <?php echo $admin551; ?></td><td><input type="checkbox" name="configlog10" <?php if ($configlog[10]) echo "checked='checked'"; ?> /></td></tr>
<tr><td>&bull; <?php echo $admin780; ?></td><td><input type="checkbox" name="configlog11" <?php if ($configlog[11]) echo "checked='checked'"; ?> /></td></tr>
</table>
<table cellspacing="1" width="100%" border="0" summary="">
<tr><td colspan="2" align="center"><p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin66; ?>"><?php echo $admin66; ?></button><?php echo $boutonright; ?></p></td></tr>
</table>
</form>
<hr />
<p align="center">
[ <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=logbook"><?php echo $admin564; ?></a> || <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b> ]</p>
<?php
btable();
include(CHEMIN."inc/bpage.inc");

?>
