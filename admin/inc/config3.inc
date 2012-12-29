<?php
/*
    Admin Configuration - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.3 (06 January 2003)   : moved Showing of users' news ($site[5]) configuration
                                   from General config
                                 added site's supervision options
      v1.6 (23 January 2003)   : added news publishing by external sites option
                                 added transition effect between pages (for IE browser only)
                                 added "page loaded in n.nn seconds" option
      v1.7 (28 January 2003)   : added Recommend to a Friend box
                                 added call to UpdateDBnews() for service[16] update
      v1.8 (05 February 2003)  : added category for forum
      v1.9 (11 February 2003)  : category for forum presentation slighly changed for showing better
                                   that it is a sub option of Forum area
                                 added Banners service and free box
                                 added Icon themes
      v2.0 (27 February 2003)  : added Meta Tags by Nicolas Alves & Laurent Duveau
                                 added fixed background image option
                                 added advanced photo service
                                 modified slogan and start using it
      v2.1 (10 March 2003)     : color management for the side scroll bar (by Nicolas Alves)
                                 counter theme management (by Nicolas Alves)
      v2.2 (22 April 2003)     : removed boxes services (now in a dedicated option)
      v2.3 (27 July 2003)      : added dynamic menu option
                                 moved number of items per service from config2 to config4
                                 added a calendar box (by Nicolas Alves)
                                 added quotations style management (by Nicolas Alves and Isabelle)
                                 added forms style management (by Nicolas Alves)
                                 added user prefs management by cookie
                                 added US date format management
                                 added user news submission option (no more mandatory)
      v2.4 (24 September 2003) : added "Page loading" popup
                                 added forum summary in home page (last threads)
                                 moved homepage parametrization from General config to Services config
                                 added Guestbook's favourite message on home page
                                 added homepage's choice of central boxes
                                 config4 renamed to config5
                                 added react to an article option
                                 recycled $texte[3] to Articles mark (was no more used)
                                 added Hide Admin Button (by Nicolas Alves)
                                 added Quick Article Admin Access (by Nicolas Alves)
                                 added number of times an article was read (by Nicolas Alves and Laurent Duveau)
                                 added number of times a forum thread was read (by Nicolas Alves and Laurent Duveau)
                                 added number of times a file was downloaded (by Nicolas Alves and Laurent Duveau)
                                 added new dates formats and created time formats
                                 created shared Config Update script
       v4.0 (06 December 2004) : clean up in table syntax (by Isa)
	                               added page title (by Jean-Mi)
				                         added multi-admin management (by Nicolas Alves)
			 v4.6.0 (15 March 2007)  : added fieldset (by Icare)
			 v4.6.3 (30 August 2007) : added optionnal plugin box, thanks JeanMi
			                           added editobox[5] and optimized code (by Icare)
      v4.6.10 (7 September 2009)    : corrected W3C
                                #275 added freebox
*/

if (stristr($_SERVER["SCRIPT_NAME"], "config3.inc")) {
  header("location:../index.php");
  die();
}

// FONCTIONS DE MISE EN PAGE /////////////////////////////////////////////////////////////////////////
function legend($legend) {
	return '<legend style="font-weight:bold;margin-left:30px;padding:0 4px;">'.$legend.'</legend>'."\n";
}
//////////////////////////////////////////////////////////////////////////////////////////////////////

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[2]=="") {
    $nomzone=$admin469;
    include("access.inc");
    exit();
  }
}

if ($regit == 1) {
  include(CONFIG);
  $site[4] = $site4; // Nouvelles sur la page d'accueil
  $site[20] = $site20; // Messages Forum sur la page d'accueil
  $site[21] = $site21; // ID du message Livre d'or préféré
  $site[29] = $site29; // Longueur en caractères des nouvelles/blogs en page d'accueil (140 par défaut)
  $site[31] = $site31; // Blogs sur la page d'accueil
  $editobox[0] = $editobox0; // Première boite page d'accueil
  $editobox[1] = $editobox1; // Seconde boite page d'accueil
  $editobox[2] = $editobox2; // Troisième boite page d'accueil
  $editobox[3] = $editobox3; // Quatrième boite page d'accueil
  $editobox[4] = $editobox4; // Cinquième boite page d'accueil
  $editobox[5] = $editobox5; // Sixièmeème boite page d'accueil
  include("inc/confupdt.inc");
}

include(CONFIG);
  if (is_file ($meskin."confskin.inc")) include ($meskin."confskin.inc");
  else include(CHEMIN.DATAREP."confskin.inc");
$topmess = $admin470;
include(CHEMIN."inc/hpage.inc");
htable($admin470, "100%");
$editolabelslist = array($admin335, $admin8, $admin466, $admin467, $admin468, $admin779, $admin363, $admin365, $admin496, $admin497, $admin498);
$editoboxeslist = array("","inc/boxhome","inc/boxforum","inc/boxguest","inc/boxnews","inc/boxblog","inc/boxspec", 'inc/boxfree1', 'inc/boxfree2', 'inc/boxfree3', 'inc/boxfree4');
$editoboxnblist = array("$admin352","$admin353","$admin354","$admin355","$admin356","$admin357");
include('plugins/plugbox.inc');
?>

<div align="center">
<p><?php echo $admin471; ?></p><hr />
<a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b>
<hr /><br />
</div>
<div style="margin-right:auto;margin-left:auto;width:90%;">
<form name="conf3" action="admin.php?lng=<?php echo $lng; ?>" method="post">

<input type="hidden" name="pg" value="config3" />
<input type="hidden" name="regit" value="1" />
<fieldset>
<?php
echo legend($admin464);
?>
<br />
<table width="100%" cellspacing="0" cellpadding="2" align="center" border="0" summary="">
<?php
for ($j = 0; $j < count($editoboxnblist); $j++){
  echo "<tr style='text-align:left;'><td><p>&bull; ".$editoboxnblist[$j]."</p></td>\n";
  echo "<td><select name='editobox".$j."'>\n";

  for ($i = 0; $i < count($editoboxeslist); $i++) {
    if ($editobox[$j] == $editoboxeslist[$i]) {
      $sel = ' selected="selected"';
    }
    else {
      $sel = "";
    }
    echo "<option value=\"".$editoboxeslist[$i]."\"".$sel.">".$editolabelslist[$i]."</option>\n";
  }
  echo "</select></td></tr>\n";
}
?>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin58; ?></p></td><td><input class="texte" type="text" name="site4" size="3" value="<?php echo $site[4]; ?>" /></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin778; ?></p></td><td><input class="texte" type="text" name="site31" size="3" value="<?php echo $site[31]; ?>" /></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin684; ?></p></td><td><input class="texte" type="text" name="site29" size="7" value="<?php echo $site[29]; ?>" /></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin463; ?></p></td><td><input class="texte" type="text" name="site20" size="3" value="<?php echo $site[20]; ?>" /></td></tr>
<tr style="text-align:left;"><td><p>&bull; <?php echo $admin465; ?></p></td><td><p><select name="site21">
<?php
$dbwork = SelectDBFields(TYP_GUESTBK,"a","");
for ($i = 0; $i < count($dbwork); $i++) {
  ReadDoc(DBBASE.$dbwork[$i][1]);
  $txt = CutLongWord(strip_tags($fieldc1),50);
  if ($site[21] == $fileid) {
    $sel = ' selected="selected"';
  }
  else {
    $sel = "";
  }
  echo "<option value=\"".$fileid."\"".$sel.">".$fileid." : ".$txt." ...</option>\n";
}
?>
</select></p></td></tr>
</table>
</fieldset>
<p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin66; ?>"><?php echo $admin66; ?></button><?php echo $boutonright; ?></p>
</form>
</div>
<div align="center"><hr />
<a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b>
</div>
<?php
btable();
include(CHEMIN."inc/bpage.inc");

?>
