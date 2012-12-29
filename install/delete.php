<?php
/*
  Delete Install script - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v2.0 (27 February 2003)    : initial release
      v2.2 (22 April 2003)       : full rewrite
      v2.3 (27 July 2003)        : upgraded the installation / migration script
      v2.4 (24 September 2003)   : small update to try to set install/ dir to CHMOD 755 before trying CHMOD 777 (for easier deletion)
      v4.0 (06 December 2004)    : added alt tags to img and removed border tag for non-linked img (by Isa)
                                   corrected include (by Jean-Mi)
      v4.6.11 (xx november 2009) : added no run button and ckeck_install delete (by Icare)
*/

header("Pragma: no-cache");
define("CHEMIN", "../");
include(CHEMIN."inc/includes.inc");
$version = "4.6";
$scriptname = "delete.php";

if ($lng == "fr") {
  $clean1 = "SUPPRESSION DES FICHIERS D'INSTALLATION DE GUPPY";
  $clean2 = "<CENTER>Ce script permet :</CENTER><UL><LI> de supprimer ce script d'installation de votre serveur, opération INDISPENSABLE pour éviter que des personnes indélicates ne viennent corrompre votre site GuppY</UL>";
  $clean3 = "<CENTER><U>IMPORTANT :</U>  assurez-vous de bien avoir lu le fichier <A HREF=\"../lisezmoi.txt\">lisezmoi.txt</A> (je vous conseille même de l'imprimer) avant de poursuivre.</CENTER>";
  $clean4 = "Allons-y !";
  $clean5 = "Suppression des fichiers d'installation";
  $clean6 = "<CENTER>Vous êtes sur le point de supprimer les fichiers d'installation de GuppY.</CENTER>";
  $clean7 = "<CENTER>Suppression du répertoire d'installation EN COURS.</CENTER>";
  $clean8 = "<CENTER>Etape n°1/1 : Suppression du répertoire d'installation TERMINEE.</CENTER>";
  $clean9 = "Non...";
}
else {
  $lng = "en";
  $clean1 = "DELETE INSTALL FILES OF GUPPY";
  $clean2 = "<CENTER>This script is ment:</CENTER><UL><LI> to remove this install script from your server, which is a MUST to avoid bad people from corrupting your GuppY web site</UL>";
  $clean3 = "<CENTER><U>IMPORTANT:</U> make sure that you carefully read the <A HREF=\"../readme.txt\">readme.txt</A> file (I even advise you to print it) before going on.</CENTER>";
  $clean4 = "Let's go!";
  $clean5 = "Deletion of the install directory";
  $clean6 = "<CENTER>You are about to launch the deletion of the install files of GuppY.</CENTER>";
  $clean7 = "<CENTER>Deletion of the install directory ON GOING.</CENTER>";
  $clean8 = "<CENTER>Step #1/1 : Deletion of the install directory DONE.</CENTER>";
  $clean9 = "No...";
}

$nextstep = "";
$dodo = 1;

function DisplayTitre($titre,$texte) {
?>

<h3><center><?php echo $titre; ?></center></h3>
<table width="90%" align="center" cellpadding="0" cellspacing="0">
<tr><td bgcolor="#DDDDFF">
<br /><?php echo $texte; ?><br />
</td></tr>
</table>

<?php
}
function DisplayProcess($titre,$processus,$resultat) {
 DisplayTitre($titre,$processus);
?>

<p align="center">&nbsp;</p>
<table width="50%" align="center" cellpadding="0" cellspacing="0">
<tr><td bgcolor="#FF9933">
<br /><?php echo $resultat; ?><br />
</td></tr>
</table>

<?php
}
function EraseInstall() {
  $dossier = opendir(CHEMIN."install/");
  while ($fichier = readdir($dossier)) {
    if (is_file(CHEMIN."install/".$fichier)) {
      @chmod(CHEMIN."install/".$fichier,0777);
      @unlink(CHEMIN."install/".$fichier);
    }
  }
  closedir($dossier);
  @chmod(CHEMIN."install",0755);
  @chmod(CHEMIN."install",0777);
  @rmdir(CHEMIN."install");
  if (file_exists(CHEMIN."data/chk_install.dtb")) {
    @chmod(CHEMIN."data/chk_install.dtb",0777);
    @unlink(CHEMIN."data/chk_install.dtb");
  }
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
<p align="center"><img src="gylogo.gif" alt="logo"/></p>

<?php
 if (empty($form)) {
?>

<p align="center"><a href="Javascript: redir('<?php echo $scriptname; ?>?lng=fr'); "><img src="<?php echo CHEMIN; ?>inc/lang/fr.gif" width="24" height="16" border="0"/></a>&nbsp;&nbsp;&nbsp;&nbsp;<a href="Javascript: redir('<?php echo $scriptname; ?>?lng=en'); "><img src="<?php echo CHEMIN; ?>inc/lang/en.gif" width="24" height="16" border="0"/></a></p>

<?php
 DisplayTitre($clean1,$clean2."<br /><br />".$clean3);
?>

<form name="instal0" action="<?php echo $scriptname; ?>?lng=<?php echo $lng; ?>" method="post">
<input type="hidden" name="form" value="1"/>
<center>
<input type="submit" value="<?php echo $clean4; ?>"/>
<input type="reset" value="<?php echo $clean9; ?>" onclick="javascript:history.back();" />
</center>
</form>

<?php
}
elseif ($form == "1") {
  DisplayTitre($clean5,$clean6);
?>

<form name="instal1" action="<?php echo $scriptname; ?>?lng=<?php echo $lng; ?>" method="post">
<input type="hidden" name="form" value="2"/>
<center>
<input type="submit" value="<?php echo $clean4; ?>" />
<input type="reset" value="<?php echo $clean9; ?>" onclick="javascript:redir('install.php?lng=fr&form=1')" />
</center>
</form>

<?php
}
elseif ($form == "2") {
  if (empty($doing)) {
    EraseInstall();
    DisplayProcess($clean5,$clean7,$clean8);
    $nextstep = "../";
    $dodo = 2;
  }
}
else {
  $nextstep = "../";
  $dodo = 0;
}
?>

<p align="center">&nbsp;</p>
<p align="center"><img border="0" src="gyslogo.gif" alt="logo"/></p>
<p align="center">GuppY v<?php echo $version; ?><br />CeCILL free Licence - © 2004-2010</p>
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
