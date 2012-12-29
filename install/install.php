<?php
/*
    Install - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v2.0 (27 February 2003)  : initial release
      v2.2 (22 April 2003)     : full rewrite
      v2.3 (27 July 2003)      : upgraded the installation / migration script
      v2.4 (24 September 2003) : upgrade for v2.4 compatibility
      v3.0 (25 February 2004)  : upgrade for v3.0 compatibility
      v4.0 (06 December 2004)  : added alt tags to img and removed border tag for non-linked img (by Isa)
                                 corrected include (by Jean-Mi)
      v4.5 (30 March 2005)     : corrected (by Jean-Mi)
      v4.6.11 (xx november 2009) : added no run button (by Icare)
*/

header("Pragma: no-cache");
define("CHEMIN", "../");
include(CHEMIN."inc/includes.inc");
$version = "4.6";

$DBversion = "";
include(CHEMIN.DATAREP."dbversion.php");
if ($DBversion == "") {
  $DBversion = "< 2.2";
}

if ($lng == "en") {
  $clean1 = "INSTALL OR MIGRATE GUPPY";
  $clean2 = "<CENTER>This script is ment:</CENTER><UL><LI>or for clearing the demo database shipped with GuppY version ".$version." and for preparing your empty database<LI>or for migrating to GuppY version ".$version." from a version 1.8 or later of miniPortail</UL><CENTER>Once you will have executed one of these two operations, you will be proposed to remove this install script from your server,<br />which is a MUST to avoid bad people from corrupting your GuppY web site.</CENTER>";
  $clean3 = "<CENTER><U>IMPORTANT:</U> make sure that you carefully read the <A HREF=\"../readme.html\">readme.html</A> file (I even advise you to print it) before going on.</CENTER>";
  $clean4 = "Let's go!";
  $clean5 = "<CENTER>You are in <B>version ".$DBversion."</B> of Guppy.<br /><br />Choose what you want to do:</CENTER>";
  $clean6 = "Clean install";
  $clean7 = "Migration";
  $clean8 = "Deletion of install files";
  $clean9 = "Go back to the home page of your site";
  $clean0 = "No...";
}
else {
  $lng = "fr";
  $clean1 = "INSTALLATION OU MIGRATION DE GUPPY";
  $clean2 = "<CENTER>Ce script permet :</CENTER><UL><LI>ou bien de vider la base de données de démonstration livrée avec GuppY version ".$version." et de préparer votre base de données vierge<LI>ou bien de migrer à la version ".$version." de GuppY à partir d'une version 1.8 ou ultérieure de miniPortail</UL><CENTER>Une fois l'une de ces opérations réalisée, il vous sera proposé de supprimer ce script d'installation de votre serveur,<br />opération INDISPENSABLE pour éviter que des personnes indélicates ne viennent corrompre votre site GuppY.</CENTER>";
  $clean3 = "<CENTER><U>IMPORTANT :</U> assurez-vous de bien avoir lu le fichier <A HREF=\"../lisezmoi.html\">lisezmoi.html</A> (je vous conseille même de l'imprimer) avant de poursuivre.</CENTER>";
  $clean4 = "Allons-y !";
  $clean5 = "<CENTER>Vous êtes en <B>version ".$DBversion."</B> de Guppy.<br /><br />Choisissez ce que vous désirez faire :</CENTER>";
  $clean6 = "Installation propre &nbsp;(effacement de la base de démonstration)";
  $clean7 = "Migration &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(passage à la nouvelle version)";
  $clean8 = "Suppression des fichiers d'installation/migration";
  $clean9 = "Retour à la page d'accueil de votre site";
  $clean0 = "Non...";
}

$nextstep = "";
$dodo = 1;

function DisplayTitre($titre,$texte) {
?>

<h3><center><?php echo $titre; ?></center></h3>
<table width="80%" align="center" cellpadding="0" cellspacing="0">
<tr><td bgcolor="#DDDDFF">
<br /><?php echo $texte; ?><br />
</td></tr>
</table>
<br />
<?php
 }
function DisplayProcess($titre,$processus,$resultat) {
 DisplayTitre($titre,$processus);
?>

<p align="center">&nbsp;</p>
<table width="480" align="center" cellpadding="0" cellspacing="0">
<tr><td bgcolor="#FF9933">
<br /><?php echo $resultat; ?><br />
</td></tr>
</table>

<?php
 }
?>

<html>
<head>
<title><?php echo $clean1; ?></title>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset; ?>">
<script language="JavaScript">
  function redir(param) {
    window.location = param;
  }
</script>
</head>
<body bgcolor="#FFFFFF">
<p align="center"><img src="gylogo.gif" alt="gylogo.gif"/></p>

<?php
 if (empty($form)) {
?>

<p align="center"><a href="Javascript: redir('install.php?lng=fr'); "><img src="<?php echo CHEMIN; ?>inc/lang/fr.gif" width="24" height="16" border="0" alt="fr"></a>&nbsp;&nbsp;&nbsp;&nbsp;<a href="Javascript: redir('install.php?lng=en'); "><img src="<?php echo CHEMIN; ?>inc/lang/en.gif" width="24" height="16" border="0" alt="en"/></a></p>

<?php
 DisplayTitre($clean1,$clean2."<br /><br />".$clean3);
?>

<form name="instal0" action="install.php?lng=<?php echo $lng; ?>" method="post">
<input type="hidden" name="form" value="1"/>
<center>
<input type="submit" value="<?php echo $clean4; ?>"/>
</center>
</form>

<?php
}
elseif ($form == "1") {
 DisplayTitre($clean1,$clean5);
?>

<form name="instal1" action="install.php?lng=<?php echo $lng; ?>" method="post">
<table width="480" align="center" cellpadding="0" cellspacing="0" style="background:#DDDDFF">

<?php
 if ($done != 1) {
?>

<tr><td bgcolor="#DDDDFF"><input type="radio" name="form" value="2"/>&nbsp;&nbsp;<?php echo $clean6; ?></td></tr>
<tr><td>&nbsp;</td>

<?php
 if ($DBversion != $version) {
?>

<tr><td bgcolor="#DDDDFF"><input type="radio" name="form" value="3"/>&nbsp;&nbsp;<?php echo $clean7; ?></tr></td>
<tr><td>&nbsp;</td>

<?php
 }
  }
?>

<tr><td bgcolor="#DDDDFF"><input type="radio" name="form" value="4"/>&nbsp;&nbsp;<?php echo $clean8; ?></tr></td>
<tr><td>&nbsp;</td>
<tr><td bgcolor="#DDDDFF"><hr /><input type="radio" name="form" value="5"/>&nbsp;&nbsp;<?php echo $clean9; ?></tr></td>
<tr><td>&nbsp;</td>
</table>
<center><input type="submit" value="<?php echo $clean4; ?>"/></center>
</form>

<?php
}
elseif ($form == "2") {
  $nextstep = "cleanup.php?lng=".$lng;
  $dodo = 0;
}
elseif ($form == "3") {
  if ($DBversion == "< 2.2") {
    $nextstep = "migrate22.php?lng=".$lng;
    $dodo = 0;
  }
  elseif ($DBversion == "2.2") {
    $nextstep = "migrate23.php?lng=".$lng;
    $dodo = 0;
  }
  elseif ($DBversion == "2.3") {
    $nextstep = "migrate24.php?lng=".$lng;
    $dodo = 0;
  }
  elseif ($DBversion == "2.4") {
    $nextstep = "migrate30.php?lng=".$lng;
    $dodo = 0;
  }
  elseif ($DBversion == "3.0") {
    $nextstep = "migrate40.php?lng=".$lng;
    $dodo = 0;
  }
  elseif ($DBversion == "4.0") {
    $nextstep = "migrate45.php?lng=".$lng;
    $dodo = 0;
  }
  elseif ($DBversion == "4.5") {
    $nextstep = "migrate46.php?lng=".$lng;
    $dodo = 0;
  }
}
elseif ($form == "4") {
  $nextstep = "delete.php?lng=".$lng;
  $dodo = 0;
}
else {
  $nextstep = "../";
  $dodo = 0;
}
?>

<p align="center">&nbsp;</p>
<p align="center"><img src="gyslogo.gif" width="104" height="39" alt="gyslogo.gif"/></p>
<p align="center">GuppY v<?php echo $version; ?><br />CeCILL free Licence - © 2004-2012</p>
</body></html>

<?php
if ($nextstep != "") {
  if ($dodo != 0) {
    sleep($dodo);
  }
?>

<script language="JavaScript">
 redir('<?php echo $nextstep; ?>');
</script>

<?php
}
?>
