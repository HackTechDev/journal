<?php
/*
    Admin Main page - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.7 (28 January 2003)   : added Recommend to a Friend admin icon
      v1.8 (05 February 2003)  : added category for forum
      v1.9 (11 February 2003)  : added banners and free box
                                 added about popup window call
      v2.0 (27 February 2003)  : the admin cookie is now automatically unactivated when closing the browser
                                 added photos admin icon
      v2.1 (10 March 2003)     : focus on first field in password input form (by B@lou and Laurent Duveau)
      v2.2 (22 April 2003)     : added Boxes Config (now a dedicated option)
                                 slightly modified the PopupWindow() Javascript function (resizable parameter) for use with the new editor assistant
                                 moved images from img/ to inc/img/admin/
      v2.3 (27 July 2003)      : fixed security issue (thanks frog-m@n)
                                 added forms style management (by Nicolas Alves)
                                 changed the order of icons from French alphabeutical to kind of logical (thanks B@lou)
      v2.4 (24 September 2003) : added new config3 and moved config3 to config4, config4 to config5 and config5 to config6
                                 added react to an article option
                                 slightly modified the PopupWindow() Javascript function (scrollbars parameter) for use with the new mini message functionality
                                 secured $pg transfered parameter
      v3.0 (25 February 2004)  : added newsletter and logbook (by Nicolas Alves)
                                 added skins management (by Nicolas Alves)
                                 added Plugin Management
                                 compatibility with php.ini register_globals=off parameter (thanks JonnyQuest)
      v4.0 (06 December 2004)  : added page title (by Jean-Mi)
  	                             added optionnal writer (by Icare)
  	                             put cellpadding to 1 and cellspacing to 3 instead of 0 (Isa)
        				                 export admin area into administrateur.php and redac area into adminredac.php (by Nicolas Alves)
      v4.5 (06 June 2005)      : display only admin pass or writer login, optimized identity check process (by Icare)
      v4.5.1 (07 July 2005)    : fixed writer connexion if writer service not checked (by Icare)
      v4.6.0 (15 March 2007)   : Add writer's access to the plugins (by Hpsam)
                                 Export (and extend) forum config to config7 (by Icare)
                                 Member registration can be needed for admin and connexion menu is the same for all (by Icare)
      v4.6.10 (7 Septembre 2009) : corrected validation W3C
      v4.6.11 (11 Décembre 2009) : changed adminstrateur.php by administrateur.php (by Icare)
	  v4.6.22 (29 December 2012) : added pseudo-private group for members (by Saxbar)
*/
header("Pragma: no-cache");
define("CHEMIN", "../");
$topmess = "Administration";

// include(CHEMIN."inc/reglobals.inc");
include(CHEMIN."inc/includes.inc");
include_once CHEMIN.'inc/func_groups.php';
if ($userprefs[10] == "") $userprefs[10] = $page[14]; //default skin
if (isset($selskin)) $userprefs[10] = $selskin;
if (import('pass', 'GET') != NULL) die('STOP ! Variable $pass: illegal origine !');

$portalname="GuppyAdmin";

if ($logout == 1) {
  setcookie($portalname, "");
  echo "<script language='JavaScript' type='text/javascript'>
        document.location.href='".CHEMIN."index.php?lng=".$lng."';
        </script>";
}
if (!isset($try)) $try = "0";
switch ($action) {
 case 'admin':
  header("location:admin.php?lng=".$lng."&wri=admin&try=1");
 break;

 case 'redac':
  header("location:admin.php?lng=".$lng."&wri=".$wri."&try=1");
 break;

 default:
}

include ("action.php");
if ($wri == "admin") {
  include("mdp.php");
}
else {
  if (FileDBExist(REDACREP.$wri.INCEXT)) {
    include(REDACREP.$wri.INCEXT);
    $mdp=md5($drtuser[38]);
  }
}
if (md5($pass) == $mdp)  {
  setcookie($portalname, crc32($mdp));
}
$pg = strip_tags($pg);

if (($_COOKIE[$portalname] == crc32($mdp) || md5($pass) == $mdp) && empty($pg)) {
  $topmess = $admin1;
  include(CHEMIN."inc/hpage.inc");
  htable($admin1, "100%");

  if (FileDBExist(REDACREP.$wri.INCEXT) && ($_COOKIE[$portalname] == crc32($mdp)) && $serviz[42] == "on") {
    include("adminredac.php");
  }
  elseif (($wri == "admin") && ($_COOKIE[$portalname] == crc32($mdp))) {
    include("administrateur.php");
  }
  else {
      ?>
      <p>&nbsp;</p>
      <p align="center"><b><?php echo $admin849; ?></b></p>
      <?php

  }
  if ($wri =="admin") {
    include("plugins/plugins.inc");
  }
  ?>
  <div align="center"><hr /><b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b></div>
  <?php
  btable();
  include(CHEMIN."inc/bpage.inc");
}
elseif ($_COOKIE[$portalname] == crc32($mdp) && !empty($pg)) {
  if (($pg == "plugin") && (file_exists("plugins/".$plug.".inc"))) {
    $plugindir = substr($plug,0,strpos($plug,"/"));
    include("plugins/".$plugindir."/plugin.inc");
    if(FileDBExist(REDACREP.$userprefs[1].INCEXT) && $drtuserplg[$plugindir] == "") {
      $nomzone = $plugin_admin_name;
      include("inc/access.inc");
    }
    else {
    	include("plugins/".$plug.".inc");
    }
  }
  elseif (file_exists("inc/".$pg.".inc")) {
    include("inc/".$pg.".inc");
  }
  else {
    ?>
    <p align="center"><b><?php echo $admin20; ?></b> <?php echo $admin21; ?></p>
    <p>&nbsp;</p>
    <p align="center"><a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a></p>
    <?php
  }
}
else {
  /// modif albert: vérif pass
  if ($try != "0")  {
    ?>
    <script type="text/javascript" language="javascript">
    alert('<?php echo $admin24." ".$admin20; ?>');
    window.location="admin.php?lng=<?php echo $lng; ?>";
    </script>
    <?php
    die('STOP ! Variable $pass : illegal value ('.$pass.')');
  }
  /// fin modif
  include(CHEMIN."inc/hpage.inc");
  htable($admin23, "100%");
  /// début modif albert: si pas membre et pas de droits
  if (!FileDBExist(USEREP.$userprefs[1].DBEXT) && $serviz[42] == "on") {
    ?>
    <script type="text/javascript" language="javascript">
    alert('<?php echo $admin716; ?>');
    window.location="<?php echo CHEMIN; ?>user.php?lng=<?php echo $lng; ?>";
    </script>
    <?php
    echo $admin716;
    echo "</div></td></tr></table></div></div></body></html>";
    exit();
  }

  $pseudo = $userprefs[1];
  ?>
  <br />  <hr />
  <form name="login" action="admin.php?lng=<?php echo $lng; ?>" method="post">
  <table cellspacing="0" cellpadding="0" align="center" border="0" summary="">
  <tr><td align="center" nowrap="nowrap"><p align="center" style="font-weight:bold"><?php echo $admin710."</p><br />---<br /><br />"; ?>
  <?php
  if ($serviz[42] == "on" && (FileDBExist(REDACREP.$userprefs[1].INCEXT))) {
    echo "<b>".$pseudo."</b>,<br /><br />".$admin713." <b>".$admin24."</b><br />";
    echo '<input type="hidden" name="action" value="redac">';
  }
  else {
    echo "<b>".$admin714."</b>,<br /><br />".$admin713." <b>".$admin24."</b><br />";
    echo '<input type="hidden" name="action" value="admin" />';
  }
  echo '<input type="hidden" name="try" value="1" />';
  ?>
  <input class="texte" type="password" name="pass" size="15" /><br /><br />
  <?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin25; ?>"><?php echo $admin25; ?></button><?php echo $boutonright; ?></td></tr>
  </table>
  </form>
  <script language="javascript" type="text/javascript">
    document.login.pass.focus()
  </script>
  <div align="center"><hr /><p><b><?php echo $admin26; ?></b> <?php echo $admin27; ?><br /><?php echo $admin28; ?></p></div>
  <?php
  btable();
  include(CHEMIN."inc/bpage.inc");
}
?>
