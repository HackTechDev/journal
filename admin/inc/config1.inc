<?php
/*
    Admin Configuration - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.3 (06 January 2003)   : moved Showing of users' news ($site[5]) configuration
                                   to Services config
                                 added site's supervision options
      v1.6 (23 January 2003)   : added news publishing by external sites option
                                 added transition effect between pages (for IE browser only)
                                 corrected bug that would not save ICQ number
                                 added "page loaded in n.nn seconds" option
      v1.7 (28 January 2003)   : added Recommend to a Friend box
                                 changed the basename() function call to have GuppY compatible with PHP version < 4.1.0
      v1.8 (05 February 2003)  : added category for forum
                                 upgraded language change (in case main language is changed and no alternative language is chosen)
      v1.9 (11 February 2003)  : added Banners service and free box
                                 added Icon themes
      v2.0 (27 February 2003)  : added Meta Tags by Nicolas Alves & Laurent Duveau
                                 added fixed background image option
                                 added advanced photo service
                                 modified slogan and start using it
      v2.1 (10 March 2003)     : bug fix = inverted Site URL and Meta Identifier URL
                                 manage ErrorDocument parameter in .htaccess file (for Apache server based web sites)
                                 color management for the side scroll bar (by Nicolas Alves)
                                 counter theme management (by Nicolas Alves)
      v2.2 (22 April 2003)     : let webmaster decide how to place side boxes (by Nicolas Alves)
                                 left and right articles boxes (by Nicolas Alves)
                                 split of language file in two xx-web.inc and xx-admin.inc for faster loading
                                 replaced foreach() with for() function (PHP3 compatibility issue)
                                 changed source code for all accesses to the pathinfo() PHP function for compatibility with PHP3 as pathinfo() only works with PHP4
      v2.3 (27 July 2003)      : added dynamic menu option
                                 added a calendar box (by Nicolas Alves)
                                 added quotations style management (by Nicolas Alves and Isabelle)
                                 added forms style management (by Nicolas Alves)
                                 added user prefs management by cookie
                                 added US date format management
                                 added user news submission option (no more mandatory)
                                 removed automated ErrorDocument management in .htaccess file (for Apache servers)
      v2.4 (24 September 2003) : added "Page loading" popup
                                 added forum summary in home page (last threads)
                                 moved homepage parametrization from General config to Services config
                                 added Guestbook's favourite message on home page
                                 added homepage's choice of central boxes
                                 added react to an article option
                                 recycled $texte[3] to Articles mark (was no more used)
                                 added Hide Admin Button (by Nicolas Alves)
                                 added Quick Article Admin Access (by Nicolas Alves)
                                 added number of times an article was read (by Nicolas Alves and Laurent Duveau)
                                 added number of times a forum thread was read (by Nicolas Alves and Laurent Duveau)
                                 added number of times a file was downloaded (by Nicolas Alves and Laurent Duveau)
                                 added new dates formats and created time formats
                                 created shared Config Update script
      v3.0 (25 February 2004)  : added copyright notice on all pages
                                 added option for compression of pages
      v4.0 (06 December 2004)  : clean up in the table syntax and comments,
                                 added alt tags to img and removed border tag for non-linked img (by Isa)
				                 added page title (by Jean-Mi)
								 added automatic site URL update (by Icare)
				 				 added type email webmaster (by Icare)
      v4.5 (22 April 2005)       : changed carspec and symbol management,
	                               show default site URL if not defined (by Icare)
      v4.6.0 (15 March 2007)     : WAI compatibility enhancement (by Olivier)
      v4.6.5 (10 November 2007)  : if empty set default value for URL and meta URL (by Icare)
      v4.6.6 (14 April 2008)     : added optionnal display of W3C validator's icons (by Icare)
      v4.6.10(7 September 2009)  : corrected W3C
	  v4.6.18(09 February 2012)  : added time zone (by Saxbar and JeanMi)
      v4.6.20(24 May 2012)       : corrected $site['TZ'] (by Saxbar and JeanMi)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "config1.inc")) {
  header("location:../index.php");
  die();
}

// FONCTIONS DE MISE EN PAGE /////////////////////////////////////////////////////////////////////////
function checkboxConfigGuppy($inputName, $inputValue, $libelle = '', $lang = 'fr', $flag = '') {
	$chaine = '<div style="margin-top:10px;">'."\n";
	$chaine .= '<span style="float:left;width:200px;text-align:left;padding:2px 0px;margin-left:15px;">';
	$chaine .= ($flag != '')? '<img src="'.$flag.'" width="24" height="16" alt="'.$lang.'" title="'.$lang.'" border="0" style="vertical-align:middle;margin-right:5px;" />' : '';
	$chaine .= $libelle.'</span>'."\n";
	$chaine .= '<div style="padding-left:205px;text-align:left;"><input type="checkbox" name="'.$inputName.'" id="'.$inputName.'" '.(($inputValue)? ' checked="checked" ' : '' ).' /></div>';
	$chaine .= '<div style="clear:left;"></div>'."\n";
	$chaine .= '</div>'."\n";

	return $chaine;
}

function inputConfigGuppy($inputName, $inputValue, $width, $libelle = '', $lang = 'fr', $flag = '') {
	$chaine = '<div style="margin-top:10px;">'."\n";
	$chaine .= '<span style="float:left;width:200px;text-align:left;padding:2px 0px;margin-left:15px;">';
	$chaine .= ($flag != '')? '<img src="'.$flag.'" width="24" height="16" alt="'.$lang.'" title="'.$lang.'" border="0" style="vertical-align:middle;margin-right:5px;" />' : '';
	$chaine .= $libelle.'</span>'."\n";
	$chaine .= '<div style="padding-left:205px;text-align:left;"><input class="texte" type="text" name="'.$inputName.'" id="'.$inputName.'" value="'.htmlentities($inputValue).'" style="vertical-align:middle;width:'.$width.';" /></div>'."\n";
	$chaine .= '<div style="clear:left;"></div>'."\n";
	$chaine .= '</div>'."\n";

	return $chaine;
}

function inputURLConfigGuppy($inputName, $inputValue, $width, $libelle = '', $lang = 'fr', $flag = '') {
    global $realurl, $lng, $admin919, $admin920;
    if ($realurl == $inputValue) {
        $msg = '';
    } else {
        $msg =
'<img src="inc/img/general/info.gif" alt="" title="" style="vertical-align:middle;font-weight:bold;" /> '
.$admin919.'<span style="font-weight:bold;">'.$realurl.'</span> '.
'<a href="admin.php?lng='.$lng.'&amp;pg=config1&amp;replace='.$inputName.'" title="'.$admin920.'"> '.
'<img src="inc/img/general/run.gif" alt="'.$admin920.'" title="'.$admin920.'" style="border-style:none;vertical-align:middle;" /> '.
'</a>';
    }
	$chaine = '<div style="margin-top:10px;">'."\n";
	$chaine .= '<span style="float:left;width:200px;text-align:left;padding:2px 0px;margin-left:15px;">';
	$chaine .= ($flag != '')? '<img src="'.$flag.'" width="24" height="16" alt="'.$lang.'" title="'.$lang.'" border="0" style="vertical-align:middle;margin-right:5px;" />' : '';
	$chaine .= $libelle.'</span>'."\n";
	$chaine .= '<div style="padding-left:205px;text-align:left;"><input class="texte" type="text" name="'.$inputName.'" id="'.$inputName.'" value="'.htmlentities($inputValue).'" style="vertical-align:middle;width:'.$width.';" /></div>'."\n";
	$chaine .= '<div style="clear:left;background-color:#F66;color:#ff0;margin:0 15px;">'.$msg.'</div>'."\n";
	$chaine .= '</div>'."\n";

	return $chaine;
}

function textareaConfigGuppy($textareaName, $textareaValue, $width, $height, $libelle = '', $lang = 'fr', $flag = '') {
	$chaine = '<div style="margin-top:10px;">'."\n";
	$chaine .= '<span style="float:left;width:200px;text-align:left;padding:5px 0px;margin-left:15px;">';
	$chaine .= ($flag != '')? '<img src="'.$flag.'" width="24" height="16" alt="'.$lang.'" title="'.$lang.'" border="0" style="vertical-align:middle;margin-right:5px;" />' : '';
	$chaine .= $libelle.'</span>'."\n";
	$chaine .= '<div style="padding-left:205px;text-align:left;">';
	$chaine .= '<textarea name="'.$textareaName.'" id="'.$textareaName.'" style="vertical-align:middle;width:'.$width.';height:'.$height.';margin-right:5px;" rows="6" cols="30">'.$textareaValue.'</textarea>'."\n";
	$chaine .= '</div>'."\n";
	$chaine .= '<div style="clear:left;"></div>'."\n";
	$chaine .= '</div>'."\n";

	return $chaine;
}

function selectConfigGuppy($selectName,$options,$optionsValueSelect = '',$libelle = '', $lang = 'fr', $flag = '') {
	$chaine = '<div style="margin-top:10px;">'."\n";
	$chaine .= '<span style="float:left;width:200px;text-align:left;padding:5px 0px;margin-left:15px;">';
	$chaine .= ($flag != '')? '<img src="'.$flag.'" width="24" height="16" alt="'.$lang.'" title="'.$lang.'" border="0" style="vertical-align:middle;margin-right:5px;" />' : '';
	$chaine .= $libelle.'</span>'."\n";
	$chaine .= '<div style="padding-left:205px;text-align:left;">';
	$chaine .= '<select id="'.$selectName.'" name="'.$selectName.'" size="1">'."\n";
	foreach($options as $optionsName => $optionsValue) {
		$optionsName = strip_tags(str_replace("<!--", "", str_replace("-->", " ", $optionsName)));
		$chaine .= '<option value="'.htmlentities($optionsValue).'" '.($optionsValueSelect == stripslashes($optionsValue) ? ' selected="selected" ' : '' ).'>'.stripslashes($optionsName).'</option>'."\n";
	}
	$chaine .= '</select>'."\n";
	$chaine .= '</div>'."\n";
	$chaine .= '<div style="clear:left;"></div>'."\n";
	$chaine .= '</div>'."\n";

	return $chaine;
}

function legend($legend) {
	return '<legend style="font-weight:bold;margin-left:30px;padding:0 4px;">'.$legend.'</legend>'."\n";
}
//////////////////////////////////////////////////////////////////////////////////////////////////////

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[0]=="") {
    $nomzone=$admin7;
    include("access.inc");
    exit();
  }
}

$realurl = "http://".str_replace("/admin","/",$_SERVER['HTTP_HOST'].dirname($_SERVER['PHP_SELF'])); //real site url

function checkURL($actual) {
    global $realurl;
    if (empty($actual)) {
        /// URL vide => on change
        return $realurl;
    }
    $actual .= '/' != $actual[strlen($actual) - 1] ? '/' : '';
    if ($realurl == $actual) {
        return $actual;
    } else {
        if (strpos($realurl, 'http://localhost/') !== 0
        and
           (strpos($actual, 'http://127.0.0.1/') === 0
        or  strpos($actual, 'http://localhost/') === 0))
        {   /// Le site n'est pas en local, mais l'url est resté en local => on change
            return $realurl;
        } else {
            return $actual;
        }
    }
}

if ($regit == 1) {
	include(CONFIG);
	$site[0] = $site0; // Titre du site pour l'Editorial
	$site[1] = RemoveBR($site1); // Meta Description du site
	$site[2] = RemoveBR($site2); // Meta Mots-clés du site
	$site[3] = checkURL($site3);
	$site[6] = $site6; // Meta Titre du site pour les moteurs de recherche
	$site[7] = $site7; // Meta Méthode d'indexation du site pour les robots
	$site[8] = $site8; // Meta Délai d'attente du robot avant une prochaine indexation
	$site[9] = $site9; // Meta Auteur du site
	$site[10] = $site10; // Meta Propriétaire du site
	$site[11] = $site11; // Meta Adresse e-mail principale de l'auteur du site
	$site[12] = $site12; // Meta Catégorie du public visé
	$site[13] = $site13; // Meta Mode de diffusion du site
	$site[14] = $site14; // Meta Copyright de l'auteur du site
	$site[15] = $site15; // Meta language
	$site[16] = checkURL($site16);
	$site[17] = addslashes($site17); // Slogan défilant langue principale
	$site[18] = addslashes($site18); // Slogan défilant deuxième langue
	$site[19] = $site19; // Format Dates
	$site[22] = $site22; // Format Heure
	$site[23] = $site23; // Séparateur Date & Heure
	$site[24] = $site24; // Logo Copyright
	$site[25] = $site25; // Position Logo Copyright
	$site[26] = $site26; // Compression des Pages
	$site[32] = $site32; // Icônes validator W3C
	$site['TZ'] = $siteTZ; // Fuseau horaire

	$lang[0] = $lang0; // Langue principale du site
	$lang[1] = $lang1; // Deuxième langue du site
	$user[0] = $user0; // Webmaster
	$user[1] = $user1; // e-mail du responsable du site
 	$user[2] = $user2; // Identifiant messagerie instantanée
	$user[3] = $user3; // formulaire mail PHP  ON / OFF
	$user[4] = $user4; // messagerie instantanée
	include("inc/confupdt.inc");
	if ($lng != $lang0 && $lng != $lang1) {
  		$lng = $lang0;
	}
} else {
    $site[3] = checkURL($site[3]);
    $site[16] = checkURL($site[16]);
    if ('site3' == $replace) {
        $site[3] = $site[16] = $realurl;
    } elseif ('site16' == $replace) {
        $site[16] = $realurl;
    }
    if ('CeCILL Free License - (C) ' == substr($site[14], 0, 26)) $site[14] = substr($site[14], 26);
    if (!isset($site['TZ'])) $site['TZ'] = 'Europe/Paris';
	include("inc/confupdt.inc");
}

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
include(CONFIG);
if (is_file ($meskin."confskin.inc")) include ($meskin."confskin.inc");
else include(CHEMIN."skin/no_skin/confskin.inc");
$topmess = $admin46;
include(CHEMIN."inc/hpage.inc");
htable($admin46, "100%");
  	
?>
<p align="center"><?php $admin47; ?><br /><br /><?php echo $admin318; ?></p>
<hr style="margin-top:15px;" />
<div style="text-align:center;">
  <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><strong><?php echo $admin19; ?></strong></a>
</div>
<hr />
<form name="conf1" action="admin.php?lng=<?php echo $lng; ?>" method="post">
  <input type="hidden" name="pg" value="config1" />
  <input type="hidden" name="regit" value="1" />
  <p style="margin-top:15px;text-align:center;"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin66; ?>"><?php echo $admin66; ?></button><?php echo $boutonright; ?></p>
  <div style="text-align:center;min-width:514px;">
    <div style="margin-right:auto;margin-left:auto;width:514px;">

<?php

//OPTIMISATION VITESSE
echo '<fieldset style="margin-top:15px;padding:0px;padding-bottom:5px;">'."\n";
echo legend($admin506);
echo checkboxConfigGuppy('site26', $site[26], '&bull;&nbsp;'.$admin505);
echo '</fieldset>';

//TIMEZONE
if (version_compare(phpversion(), '5.2', '>=')) {
	echo '<fieldset style="margin-top:15px;padding:0px;padding-bottom:5px;">'."\n";
	echo legend($admin943);

	$menuOptionsSelect = array();
	$list_TZ = DateTimeZone::listIdentifiers();
	foreach($list_TZ as $TZ) {
		$menuOptionsSelect[$TZ] = $TZ;
	}

	echo selectConfigGuppy('siteTZ', $menuOptionsSelect, $site['TZ'], '&bull;&nbsp;'.$admin944);
	echo '</fieldset>';
}

//INFOS SUR LE SITE
echo '<fieldset style="margin-top:15px;padding:0px;padding-bottom:5px;">'."\n";
echo legend($admin49);
echo inputConfigGuppy('site0', $site[0], '260px', '&bull;&nbsp;'.$admin50);
echo inputURLConfigGuppy('site3', $site[3], '260px', '&bull;&nbsp;'.$admin53);

$menuOptionsSelect = array();
for ($i = 0; $i < count($langue); $i++) {
	$menuOptionsSelect[$langue[$i]] = $langue[$i];
}
echo selectConfigGuppy('lang0',$menuOptionsSelect,$lang[0], '&bull;&nbsp;'.$admin54);

$menuOptionsSelect[$admin57] = '';
echo selectConfigGuppy('lang1',$menuOptionsSelect,$lang[1], '&bull;&nbsp;'.$admin56);

echo inputConfigGuppy('site17', $site[17], '260px', '&bull;&nbsp;'.$admin339, $lang[0], $flag1);
if ($lang[1] != "") {
	echo inputConfigGuppy('site18', $site[18], '260px', '&bull;&nbsp;'.$admin339, $lang[1], $flag2);
}

$menuOptionsSelect = array($admin452 => 'E1', $admin485 => 'E2', $admin453 => 'U1', $admin486 => 'U2', $admin487 => 'C1', $admin488 => 'C2');
echo selectConfigGuppy('site19',$menuOptionsSelect,$site[19], '&bull;&nbsp;'.$admin451);

$menuOptionsSelect = array($admin490 => 'H1', $admin491 => 'H2', $admin492 => 'H3');
echo selectConfigGuppy('site22',$menuOptionsSelect,$site[22], '&bull;&nbsp;'.$admin489);

$menuOptionsSelect = array("&nbsp;" => " ","!" => "!","#" => "#","*" => "*","+" => "+","-" => "-","." => ".",":" => ":","&lt;" => "&lt;",
							"=" => "=","&gt;" => "&gt;","@" => "@","^" => "^","~" => "~","&deg;" => "&deg;","&curren;" => "&curren;",
							"&middot;" => "&middot;","&ordm;" => "&ordm;","&plusmn;" => "&plusmn;","&raquo;" => "&raquo;","&times;" => "&times;","&bull;" => "&bull;");
echo selectConfigGuppy('site23',$menuOptionsSelect,$site[23], '&bull;&nbsp;'.$admin493);
echo '</fieldset>';

//INFOS SUR LE Webmestre
echo '<fieldset style="margin-top:15px;padding:0px;padding-bottom:5px;">'."\n";
echo legend($admin62);
echo inputConfigGuppy('user0', $user[0], '230px', '&bull;&nbsp;'.$admin63);
echo inputConfigGuppy('user1', $user[1], '230px', '&bull;&nbsp;'.$admin64);
echo checkboxConfigGuppy('user3', $user[3], '&nbsp;&nbsp;&nbsp; -&nbsp;'.$admin232);

$menuOptionsSelect = array('&nbsp;' => '', 'ICQ' => 'ICQ', 'MSN' => 'MSN', 'Yahoo' => 'Yahoo', 'Gtalk' => 'Gtalk', 'Skype' => 'Skype', 'Teamspeak' => 'Teamspeak', 'AIM' => 'AIM');
echo selectConfigGuppy('user4',$menuOptionsSelect,$user[4], '&bull;&nbsp;'.$admin730);

echo inputConfigGuppy('user2', $user[2], '230px', '&nbsp;&nbsp;&nbsp; -&nbsp;'.$admin65);
echo '</fieldset>';

//BALISES META
echo '<fieldset style="margin-top:15px;padding:0px;padding-bottom:5px;">'."\n";
echo legend($admin308);

$menuOptionsSelect = array();
for ($i = 0; $i < count($langue); $i++) {
	$menuOptionsSelect[$langue[$i]] = $langue[$i];
}
echo selectConfigGuppy('site15',$menuOptionsSelect,$site[15], '&bull;&nbsp;'.$admin319);

echo inputConfigGuppy('site6', $site[6], '260px', '&bull;&nbsp;'.$admin309);
echo textareaConfigGuppy('site1', $site[1], '260px', '150px', '&bull;&nbsp;'.$admin51);
echo textareaConfigGuppy('site2', $site[2], '260px', '150px', '&bull;&nbsp;'.$admin52);
echo inputURLConfigGuppy('site16', $site[16], '230px', '&bull;&nbsp;'.$admin320);

$menuOptionsSelect = array('Index, Follow' => 'Index, Follow', 'Index, NoFollow' => 'Index, NoFollow', 'All' => 'All', 'None' => 'None');
echo selectConfigGuppy('site7',$menuOptionsSelect,$site[7], '&bull;&nbsp;'.$admin310);

$menuOptionsSelect = array('14 days' => '14 days', '21 days' => '21 days', '30 days' => '30 days', '60 days' => '60 days');
echo selectConfigGuppy('site8',$menuOptionsSelect,$site[8], '&bull;&nbsp;'.$admin311);

echo inputConfigGuppy('site9', $site[9], '230px', '&bull;&nbsp;'.$admin312);
echo inputConfigGuppy('site10', $site[10], '230px', '&bull;&nbsp;'.$admin313);
echo inputConfigGuppy('site11', $site[11], '230px', '&bull;&nbsp;'.$admin314);

$menuOptionsSelect = array('General' => 'General', 'Mature' => 'Mature', 'Restricted' => 'Restricted');
echo selectConfigGuppy('site12',$menuOptionsSelect,$site[12], '&bull;&nbsp;'.$admin315);

$menuOptionsSelect = array('Global' => 'Global', 'Local' => 'Local');
echo selectConfigGuppy('site13',$menuOptionsSelect,$site[13], '&bull;&nbsp;'.$admin316);

echo inputConfigGuppy('site14', $site[14], '230px', '&bull;&nbsp;'.$admin317);
echo '</fieldset>';

//COPYRIGHT GUPPY
echo '<fieldset style="margin-top:15px;padding:0px;padding-bottom:5px;">'."\n";
echo legend($admin515);

$menuOptionsSelect = array($admin513 => 'N', $admin512 => '', $admin511 => 's', $admin510 => 't');
echo selectConfigGuppy('site24',$menuOptionsSelect,$site[24], '&bull;&nbsp;'.$admin514);

$menuOptionsSelect = array($admin508 => 'T', $admin494 => 'L', $admin495 => 'R', $admin507 => 'B');
echo selectConfigGuppy('site25',$menuOptionsSelect,$site[25], '&bull;&nbsp;'.$admin509);

echo checkboxConfigGuppy('site32', $site[32], '&bull;&nbsp;Logos validator W3C :');
echo '</fieldset>';
?>

    </div>
  </div>
  <p style="margin-top:15px;text-align:center;"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin66; ?>"><?php echo $admin66; ?></button><?php echo $boutonright; ?></p>
</form>
<hr style="margin-top:15px;" />
<div style="text-align:center;">
  <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><strong><?php echo $admin19; ?></strong></a>
</div>
<?php

btable();
include(CHEMIN."inc/bpage.inc");
