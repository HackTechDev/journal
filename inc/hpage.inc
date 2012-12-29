<?php
/*
    Site Index Top & Left of Page - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.6 (23 January 2003)   : added PopupWindow() javascript function
                                 added transition effect option between pages
                                   (for IE browser only, no effect on the other browsers)
      v1.7 (28 January 2003)   : added Recommend to a Friend box
      v1.8 (05 February 2003)  : added category for forum
                                 added charset management
      v1.9 (11 February 2003)  : updated version showing as HTML comment with $mpversion (was previously hard coded!)
                                 added banners management and freebox
                                 added icons theme management (case when no icons should be displayed)
      v2.0 (27 February 2003)  : added Meta Tags by Nicolas Alves & Laurent Duveau
                                 no logo option added
                                 added advanced photo service
                                 added slogan display
                                 added WriteMailTo() javascript function - encryption of e-mail @ (SPAM protection)
                                 upgraded the Icon themes management (thanks Alex)
      v2.1 (10 March 2003)     : added addslashes() to var in Javascript functions (to avoid errors)
                                 color management for the side scroll bar (by Nicolas Alves)
                                 counter theme management (by Nicolas Alves)
      v2.2 (22 April 2003)     : new side boxes management (by Nicolas Alves)
                                 slightly modified the PopupWindow() Javascript function (resizable parameter) for use with the new editor assistant, cleanup in the images organization
      v2.3 (27 July 2003)      : minor font and text formating changes in search, quotations, general pages (thanks Isabelle)
                                 replaced mtitre class by titre class in htable1(), so mtitre class no more useful
                                 added forms style management (by Nicolas Alves)
                                 added user prefs management by cookie
                                 upgraded WriteMailTo() function for better SPAM protection (thanks Michel)
      v2.4 (24 September 2003) : added "Page loading" popup
                                 changed mailto box to default pages' bgcolor
                                 added character set management in e-mail popup
                                 added alternative label for site's logo image (name of the site)
                                 added Hide Admin Button (by Nicolas Alves)
                                 slightly modified the PopupWindow() Javascript function (scrollbars parameter) for use with the new mini message functionality
                                 removed style sheet CSS from inc/hpage.inc and put it in a new inc/style.inc file
      v2.4p1 (26 Sept. 2003)   : some users could not post messages in the guestbook or forum, it is fixed now
      v2.4p2 (28 Sept. 2003)   : fixed bug where buttons bar would not appear correctly (centered instead of left aligned) if Stats button not displayed (Thanks Raiponce)
      v2.4p3 (29 Sept. 2003)   : upgraded the ob_gzhandler functionality (compression of pages), now is done only if relevant (do not trust PHP and browsers anymore)
      v3.0 (25 February 2004)  : added skin management (by Nicolas Alves)
                                 added possibility to put all boxes on the right side
                                 added option for compression of pages
                                 updated sideboxes display because of new plugins manager
                                 added Plugins management
                                 added Title meta tag (thanks Tanet and Realia)
      v4.0 (06 December2004)   : added specific page title (by Jean-Mi)
                                 added log_stats (by Jean-Mi)
                                 added hidepage width for compatibility (by Icare)
                                 optimization table use (by Icare)
                                 added the nav menu navigation style and its optional rollover effect (by Isa)
                                 added alt tags to img and removed border tag for non-linked img (by Isa)
                                 removed the transparent pixel (skins have to use the htable and htable1 classes to set up the space between boxes (by Isa)
                                 optimization of the code : used the CSS class "menu" to set up the menu bar appearence (by Isa)
                                 some changes in order the code is more standards compliant (by Isa)
                                 changes in the writemail function so that it is standard compliant (thanks Djchouix)
                                 removed two javascripts in the head (they were between the head and the body (by Isa)
                                 added auto-select of css file: external style.css, usual inc/style.inc or skin/style.inc (by Icare)
                                 added auto-close on blur in WriteMailTo (by Icare)
                                 updated metatag Robots (by Jean-Mi)
      v4.5 (30 march 2005)       : exported javascripts in hpage.js (by JeanMi)
	                               updated optionnal header box facility (by Icare)
      v4.6.0 (04 June 2007)      : added $widepage for wide forum and blog (by Icare)
                                   new boxes and boxes reorganization for top and left  (by Icare)
      v4.6.5 (05 December 2007)  : corrected xhtml mismatch (thanks JeanMi) and change headTop table by divs (by Icare)
      v4.6.6 (14 April 2008)     : added test $tabmenu for external custom (by Icare)
      v4.6.9 (25 December 2008)  : added the header HTTP Content-Type with correct charset #245
                                   added directory inc/jshead for the automatic loading of javascript in part HEAD of the page #246
      v4.6.10 (7 September 2009) : corrected #272, #274 and #290
      v4.6.14 (14 February 2011) : corrected years in copyright
      v4.6.17 (21 October 2011)  : added directory inc/inchead for automatic include scripts php or html at the top of the page (by Saxbar)
	                               fixed print view (by Saxbar)
      v4.6.18 (09 February 2012) : added $mpcopyright (by Saxbar)
                                   corrected site[14] (thanks JeanMi)
                                   $site['TZ'] initialized to "Europe/Paris" (thanks JeanMi)						   
                                   added $hflags,$varget for screen_choice and language flags (by Saxbar)
	  v4.6.22 (29 December 2012) : added $allcss for csshead (thanks JeanMi)
	                               corrected treatment style.css (thanks  JeanMi)
								   corrected treatment js (thanks JeanMi)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "hpage.inc")) {
  header("location:../index.php");
  die();
}

$obgo = false;
if (($site[26] == "on") && (substr(phpversion(),0,1) >= 4)) {
  if (!strstr($endurl, "admin/") && !strstr($endurl, "postguest.php")) {
    if (extension_loaded(zlib)>0) {
      if (strstr($_SERVER['HTTP_ACCEPT_ENCODING'], 'gzip')) {
        $obgo = ob_start();
      }
    }
  }
}
$style = "";
if ($screen_choice == "fix") $style = "auto"; //for fixed skin 4.6.0
elseif ($screen_choice != "") $style = $screen_choice;
else {
  $userstyle = "Guppystyle";
  if (isset($_COOKIE[$userstyle])) {$style=$_COOKIE[$userstyle];}
  else {$style="auto";}
  if (isset($_POST['style'])) {
    setcookie($userstyle, $_POST['style'], time()+(365*24*3600));
    $style=$_POST['style'];
  }
}

$toppage = $site[0];
if (($page[22]) && (!empty($topmess)))
  $toppage .= " - ".strip_tags($topmess);
if ($serviz[32] == "on" && $serviz[42] == "on" && FileDBExist(CHEMIN."admin/redac/".$userprefs[1].INCEXT)) {
  include(CHEMIN."admin/redac/".$userprefs[1].INCEXT);
}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<?php

	///////////////////////////////////////////////////////////////////////////////////
	//                                                                               //
	//                GuppY is protected by the CeCILL FREE LICENSE.                 //
	//  REMOVING OR MODIFYING THE FOLLOWING COPYRIGHT NOTICE IS STRICTLY FORBIDDEN.  //
	//                                                                               //
	///////////////////////////////////////////////////////////////////////////////////

?>

  <!--[  GuppY v<?php echo $mpversion; ?> CeCILL Copyright (C) <?php echo $mpcopyright; ?> by Laurent Duveau - http://www.freeguppy.org/  ]-->

<head>
<title><?php echo $toppage; ?></title>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset; ?>" />
<meta name="Description" lang="<?php echo $site[15]; ?>" content="<?php echo $site[1]; ?>" />
<meta name="Keywords" lang="<?php echo $site[15]; ?>" content="<?php echo $site[2]; ?>" />
<meta name="Identifier-url" content="<?php echo $site[16]; ?>" />
<?php
if (!preg_match("!admin/|postguest|newsrss|error!", $endurl)) {
  ?>
  <meta name="Robots" content="<?php echo $site[7]; ?>" />
  <meta name="Revisit-After" content="<?php echo $site[8]; ?>" />
  <?php
}
else {
  ?>
  <meta name="Robots" content="NONE" />
  <?php
}
?>
<meta name="Author" content="<?php echo $site[9]; ?>" />
<meta name="Owner" content="<?php echo $site[10]; ?>" />
<meta name="Reply-To" content="<?php echo $site[11]; ?>" />
<meta name="Rating" content="<?php echo $site[12]; ?>" />
<meta name="Distribution" content="<?php echo $site[13]; ?>" />
<meta name="Copyright" content="CeCILL Free License - (C) <?php echo $mpcopyright.' - '.$site[14]; ?>" />
<meta name="Language" content="<?php echo $site[15]; ?>" />
<meta name="Title" content="<?php echo $site[6]; ?>" />
<meta name="Generator" content="GuppY"/>
<?php
if ($page[7] == "on") {
  ?>
  <meta http-equiv="Page-Enter" content="blendTrans(Duration=1.0)" />
  <?php
}
?>
<link rel="shortcut icon" href="<?php echo $site[3]; ?>guppy.ico" />
<?php
if ($serviz[16] == "on") {
	echo '
<link rel="alternate" type="application/rss+xml" title="'.$site[0].' : '.(($lng == $lang[0])?strip_tags($nom[7]):strip_tags($nom[17])).'" hreflang="'.$lng.'" href="'.$site[3].DATAREP.'news'.$lng.'.xml" />'."\n";
}
if ($serviz[54] == "on") {
	echo '
<link rel="alternate" type="application/rss+xml" title="'.$site[0].' : '.(($lng == $lang[0])?strip_tags($nom[42]):strip_tags($nom[43])).'" hreflang="'.$lng.'" href="'.$site[3].DATAREP.'blog'.$lng.'.xml" />'."\n";
}
if ($serviz[60] == "on") {
	echo '
<link rel="alternate" type="application/rss+xml" title="'.$site[0].' : '.$web169.'" hreflang="'.$lng.'" href="'.$site[3].DATAREP.'art'.$lng.'.xml" />'."\n";
}
if (file_exists($meskin."style.css")) {
	echo '
<link type="text/css" rel="stylesheet" href="'.$meskin.'style.css" />';
}
else {
	echo '
<link type="text/css" rel="stylesheet" href="no_skin/style.css" />';
}
if (file_exists(CHEMIN.'inc/'.$style.'.css')) {
    echo '
<style type="text/css" media="screen">
    @import url('.CHEMIN.'inc/'.$style.'.css);
</style>';
}

if (file_exists(CHEMIN.'inc/print.css')) {
    echo '
<style type="text/css"'.((isset($prt) && $prt == 2) ? ' media="all"' : ' media="print"').'>
    @import url('.CHEMIN.'inc/print.css);
</style>';
}

include(CHEMIN."inc/log_stats.inc");
if ($lng == $lang[0]) {
  $defil = $site[17];
}
else {
  $defil = $site[18];
}
if ($page[20] != "") {
  echo "<script language=\"javascript\" type=\"text/javascript\" src=\"".CHEMIN."inc/rollover.js\"></script>";
}
?>
<script language="javascript" type="text/javascript">
var texte='      <?php echo addslashes($defil); ?>      ';
var charset = <?php echo '"'.$charset.'"'; ?>;
var site0 = <?php echo '"'.$site[0].'"'; ?>;
var site3 = <?php echo '"'.$site[3].'"'; ?>;
</script>
<script language="javascript" type="text/javascript" src="<?php echo CHEMIN; ?>inc/hpage.js"></script>
<?php

$loader = "";
$unloader = "";
if (!empty($defil)) {
  $loader .= "msgdefil();";
  $unloader .= "clearTimeout(vitessedefil);";
}
if (!empty($page[13])) {
  $loader .= "hideLoadingPage();";
}

// CSS located in directory inc/csshead are automatically charged in part HEAD of the page
$allcss = glob(CHEMIN.'inc/csshead/*{.css,.css.php}', GLOB_BRACE);
if (FALSE !== $allcss) {
	sort($allcss);
	foreach ($allcss as $onecss) {
		echo '
<link type="text/css" rel="stylesheet" href="'.$onecss.'" />';
	}
	unset($allcss, $onecss);
}

// javascript located in directory inc/jshead are automatically charged in part HEAD of the page
$alljs = glob(CHEMIN.'inc/jshead/*{.js,.js.php}', GLOB_BRACE);
if (FALSE !== $alljs) {
	sort($alljs);
	foreach ($alljs as $onejs) {
		echo '
<script language="javascript" type="text/javascript" src="'.$onejs.'"></script>';
	}
	unset($alljs, $onejs);
}

echo $headinc; // to insert something in head section
if (isset($prt) && $prt == 2) {
    echo '
<script type="text/javascript">
 window.print();
</script>
';
}
?>
</head>
<body<?php if (!empty($loader)) { echo " onload=\"".$loader."\""; } if (!empty($unloader)) { echo " onunload=\"".$unloader."\""; } ?>>
<?php
if ($show_progbar) {
    echo '<div id="mess" class="forum" style="z-index:50; position: absolute; left: 33%; top: 360px; width: 300px; padding: 20px; border: 4px inset;">
<p align="center"><strong>'.$web220.'</strong><br /><br />
<img src="'.CHEMIN.'inc/img/progbar/'.$site[28].'" border="0" alt="" />
</p></div>
';
}
?>
<div id="page">
<?php

// php or html scripts located in directory inc/inchead are automatically include at the top of the page
if (is_dir(CHEMIN."inc/inchead") && !isset($prt)) { 
	$bd = opendir(CHEMIN."inc/inchead");
	while ($file = readdir($bd)) { 
		$cr = pathinfo(CHEMIN."inc/inchead/".$file);
		if ($cr["extension"] == "inc") include(CHEMIN."inc/inchead/".$file);
	}
}

$hflags = $varget = '';
while (list($var, $val) = each($_POST)) {
	if (!is_array($val) && !in_array($var, array('style', 'x', 'y'))) {
		$hflags .= '<input type="hidden" name="'.$var.'" value="'.strip_tags($val).'" />';
		$varget .= '&'.$var.'='.strip_tags($val);
	}
}

if ($screen_choice == "") {
	?>
  <div id="screen_choice" style="display: block; cursor:pointer;" align="center">
   <form name="ustyle" method="post" action="<?php $_SERVER['PHP_SELF'] ?>">
   <?php
	$screen_icon = ($screen_icon != "") ? $meskin.$screen_icon : CHEMIN."inc/img/general/screen.png";
	if ($style == "auto") {
		echo "<input type='hidden' name='style' value='1024'/>\n";
		echo "<input type='image' src='".$screen_icon."' alt='[Full]->1024px' title='[Full]->1024px' />\n";
	} else {
		echo "<input type='hidden' name='style' value='auto'/>\n";
		echo "<input type='image' src='".$screen_icon."' alt='[1024px]->Full' title='[1024px]->Full' />\n";
	}
	echo $hflags;
	?>
   </form>
  </div>
	<?php
}
?>
<a name="top"></a>
<?php
if ($serviz[44] == "on") {
  echo '
<div style="padding:10px; color:red; background-color:yellow; border:3px solid red; text-align:center; font-weight:bold; font-size:larger;">
ATTENTION : site en travaux - CAUTION: work in progress</div>';
}
if (!empty($page[13])) {
   echo "<div id='hidepage' style='position: absolute; left: 20%; top: 28px; width: 240px; padding: 5px; border: 1px solid; background-color: #EEEEFF'>";
   ?>
   <p align="center"><?php echo $web174; ?><br /><br />
   <img src="<?php echo CHEMIN; ?>inc/img/progbar/<?php echo $page[13]; ?>" border="0" alt=" " />
   </p>
   <?php
   echo "</div>";
}

echo $imgtabup;
echo "<div id='headTop'>";
if (($posbox[30] == "") && ($posbox[31] == "") && ($posbox[32] == "")) {$tabup = ""; $tabcita = "";}
if ($tabup == "on") {htable2("100%");} else {echo $tabup;}              // No frame header if no boxes
// ----------entête----------------
if (($posbox[30] != '') || ($posbox[31] != '')) {
  if ($posbox[30] != ""  && $posbox[31] != "") {
    echo '<div style="float:left;">'."\n";
    include(CHEMIN.$posbox[30].INCEXT);
    echo '</div>'."\n";
    echo '<div style="float:right;">'."\n";
    include(CHEMIN.$posbox[31].INCEXT);
    echo '</div><div style="clear:both;"></div>'."\n";
  }
  elseif ($posbox[30] != "" && $posbox[31] == "") {
    echo '<div style="float:left;">'."\n";
    include(CHEMIN.$posbox[30].INCEXT);
    echo '</div><div style="clear:both;"></div>'."\n";
  }
  else {
    echo '<div style="width:100%">'."\n";
    include(CHEMIN.$posbox[31].INCEXT);
    echo '</div>'."\n";
  }
}
if ($posbox[32]!="") {
  include(CHEMIN.$posbox[32].INCEXT);
}
if ($tabcita == "on") btable2(); else echo $tabcita;         // Bottom of header box
$tmpstyle = "";
echo "</div>";
if ($posbox[33] != "" || $posbox[34] != "") {
echo "<div id='headBottom'>\n";
echo '<table width="100%" cellspacing="0" cellpadding="0" border="0" summary=""><tr>'."\n";
if ($posbox[33] != "") {
  echo '<td class="logo">';
  include(CHEMIN.$posbox[33].INCEXT);
  echo '</td>'."\n";
}
if ($posbox[34] != ""){
  echo '<td>'."\n";
  include(CHEMIN.$posbox[34].INCEXT);
  echo '</td>'."\n";
}
echo '</tr></table>'."\n";
echo "</div>\n";
}

if ($menu_icon != "") {$page[9] = $sav_icon;} // restaure icons for center box

echo '<div id="mainContent">'."\n";
if ($tabmenu == "on") btable2(); elseif ($tabmenu == "") echo $tabmenu; // Optionnal bottom of header box
if ($tabmenu == "template") include($meskin."template1.inc");
else {
?>
<table width="100%" align="center" cellspacing="7" cellpadding="0" border="0" summary="">
<tr>
<?php
if ($widepage == "" && $userprefs[3] != 'R') {
  echo "<td valign=\"top\">";
  include(CHEMIN."inc/boxleft.inc");
  echo "</td>";
}
echo "<td width='100%' valign='top'>\n";
}
