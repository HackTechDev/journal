<?php
/*
  Prepare Empty Database - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v2.0 (27 February 2003)    : initial release
      v2.2 (22 April 2003)       : full rewrite
      v2.3 (27 July 2003)        : upgraded the installation / migration script
      v2.4 (24 September 2003)   : created many new $d[something] variables
                                   added FileDBExist() function
                                   added DestroyDBFile() function
                                   upgrade for v2.4 compatibility
      v3.0 (25 February 2004)    : upgrade for v3.0 compatibility
      v4.0 (06 December 2004)    : added alt tags to img and removed border tag for non-linked img (by Isa)
                                   corrected include (by Jean-Mi)
      v4.6.0 (15 March 2007)     : upgrade for v4.6.0 (by Icare)
      v4.6.11 (xx november 2009) : added no run button (by Icare)
      v4.6.19 (30 March 2012)    : added initialization fields of DBLOGL (thanks Icare)
*/

header("Pragma: no-cache");
define("CHEMIN", "../");
include(CHEMIN."inc/includes.inc");
$version = "4.6";
$scriptname = "cleanup.php";

if ($lng == "en") {
  $clean1 = "INSTALL GUPPY IN VERSION ".$version;
  $clean2 = "<CENTER>This script is ment:</CENTER><UL><LI>for clearing the demo database shipped with GuppY version ".$version." and for preparing your empty database</UL>";
  $clean3 = "<CENTER><U>IMPORTANT:</U> make sure that you carefully read the <A HREF=\"../readme.html\">readme.html</A> file (I even advise you to print it) before going on.</CENTER>";
  $clean4 = "Let's go!";
  $clean5 = "Clean install";
  $clean6 = "<CENTER>You are about to launch a clean install.</CENTER>";
  $clean7 = "<CENTER>Clean install ON GOING.</CENTER>";
  $clean8 = "<CENTER>Step #1/2: Database deleted.</CENTER>";
  $clean9 = "<CENTER>Step #2/2: Empty database created.</CENTER>";
  $clean10 = "<CENTER>Clean install DONE.</CENTER>";
  $clean11 = "<CENTER>The install in version ".$version." of GuppY is now over.</CENTER>";
  $clean12 = "Next";
  $clean13 = "No...";
}
else {
  $lng = "fr";
  $clean1 = "INSTALLATION DE GUPPY EN VERSION ".$version;
  $clean2 = "<CENTER>Ce script permet :</CENTER><UL><LI>de vider la base de données de démonstration livrée avec GuppY version ".$version." et de préparer votre base de données vierge</UL>";
  $clean3 = "<CENTER><U>IMPORTANT :</U> assurez-vous de bien avoir lu le fichier <A HREF=\"../lisezmoi.html\">lisezmoi.html</A> (je vous conseille même de l'imprimer) avant de poursuivre.</CENTER>";
  $clean4 = "Allons-y !";
  $clean5 = "Installation propre";
  $clean6 = "<CENTER>Vous êtes  sur le point de lancer une installation propre.</CENTER>";
  $clean7 = "<CENTER>Installation propre EN COURS.</CENTER>";
  $clean8 = "<CENTER>Etape n 1/2 : Base de données supprimée.</CENTER>";
  $clean9 = "<CENTER>Etape n 2/2 : Base de données vierge créée.</CENTER>";
  $clean10 = "<CENTER>Installation propre TERMINEE.</CENTER>";
  $clean11 = "<CENTER>L'installation en version ".$version." de GuppY est maintenant terminée.</CENTER>";
  $clean12 = "Suivant";
  $clean13 = "Non...";
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

function CleanDataRep() {
  $dossier = opendir(CHEMIN.DATAREP);
  while ($fichier = readdir($dossier)) {
    if (FileDBExist(CHEMIN.DATAREP.$fichier)) {
      if ($fichier != "config".INCEXT && $fichier != "index.php") {
        DestroyDBFile(CHEMIN.DATAREP.$fichier);
      }
    }
  }
  closedir($dossier);
  $dossier = opendir(USEREP);
  while ($fichier = readdir($dossier)) {
    if (FileDBExist(USEREP.$fichier)) {
      if ($fichier != "index.php") {
        DestroyDBFile(USEREP.$fichier);
      }
    }
  }
  closedir($dossier);
  $dossier = opendir(CACHEREP);
  while ($fichier = readdir($dossier)) {
    if (FileDBExist(CACHEREP.$fichier)) {
      if ($fichier != "index.php") {
        DestroyDBFile(CACHEREP.$fichier);
      }
    }
  }
  closedir($dossier);
  $dossier = opendir(ARCHREP);
  while ($fichier = readdir($dossier)) {
    if (FileDBExist(ARCHREP.$fichier)) {
      if ($fichier != "index.php") {
        DestroyDBFile(ARCHREP.$fichier);
      }
    }
  }
  closedir($dossier);
}

function PrepareDataRep() {
  global $version;
  WriteFullDB(DBADMIN,"");
  WriteFullDB(DBART,"");
  WriteFullDB(DBBLOG,"");
  WriteFullDB(DBREACT,"");
  WriteFullDB(DBREBLOG,"");
  WriteCounter(DBCOUNTER,0);
  WriteFullDB(DBDNLOAD,"");
  WriteFullDB(DOCID,"");
  WriteFullDB(DBFORUM,"");
  WriteFullDB(DBFORUMCAT,"");
  WriteCounter(DBFORUMCOUNTER,0);
  WriteFullDB(DBRULES,"");
  WriteFullDB(DBIPPOLL,"");
  WriteFullDB(DBIPSTATS,"");
  WriteFullDB(DBLINKS,"");
  WriteFullDB(DBHOMEPAGE,"");
  WriteFullDB(DBSPECIAL,"");
  $dbt = array();
  $dbt = InitDBlog(1);
  $dbt[0][0] = (integer) date("H");
  WriteDBFields(DBLOGH,$dbt);
  $dbt = array();
  $dbt = InitDBlog(24);
  $dbt[0][0] = (integer) date("d");
  WriteDBFields(DBLOGD,$dbt);
  $dbt = array();
  $dbt = InitDBlog(31);
  $dbt[0][0] = (integer) date("m");
  WriteDBFields(DBLOGM,$dbt);
  $dbt[0][0] = $dbt[0][0]-1;
  WriteDBFields(DBLOGL,$dbt);
  $dbt = array();
  $dbt = InitDBlog(12);
  $dbt[0][0] = (integer) date("Y");
  WriteDBFields(DBLOGY,$dbt);
  $dbt[0][0] = $dbt[0][0]-1;
  WriteDBFields(DBLOGP,$dbt);
  WriteCounter(NEXTID,0);
  WriteFullDB(DBPHOTO,"");
  WriteFullDB(DBPOLL,"");
  WriteCounter(DBSTATS,1);
  WriteCounter(DBSTATSBK,1);
  WriteFullDB(DBTHREAD,"");
  WriteFullDB(DBNEWS,"");
  WriteFullDB(DBFAQ,"");
  $data[0] = TYP_FOOTER;
  $data[1] = "";
  $data[2] = "a";
  $data[3] = "";
  $data[4] = "";
  $data[5] = "";
  $data[6] = "";
  $data[7] = "";
  $data[8] = "";
  $data[9] = "";
  $data[10] = "";
  $data[11] = "";
  $data[12] = "";
  $data[13] = "";
  $data[14] = "";
  ActionOnFields("add",$data);
  $txt = "<?php
\$foot1 = stripslashes(\"\");
\$foot2 = stripslashes(\"\");
?>"; ?> <?php
  WriteFullDB(DBFOOT,$txt);
  $freetitle = "Free Box";
  $freetext = "";
  $txt = "<?php
\$freetitle1 = stripslashes(\"$freetitle\");
\$freetitle2 = stripslashes(\"$freetitle\");
\$freetext1 = stripslashes(\"$freetext\");
\$freetext2 = stripslashes(\"$freetext\");
?>"; ?> <?php
  WriteFullDB(DBFREEBOX1,$txt);
  WriteFullDB(DBFREEBOX2,$txt);
  WriteFullDB(DBFREEBOX3,$txt);
  WriteFullDB(DBFREEBOX4,$txt);
  WriteFullDB(DBNEWSLETTER,"");
  WriteFullDB(DBLOGBOOK,"");
  WriteFullDB(DBBSS,"");
  WriteFullDB(DBRSS,"");
  WriteFullDB(DBFORUMARCHDATE," ");
  WriteFullDB(DBLOGDATE, date("d/m/y"));
  WriteFullDB(DBLOGFILES, "stats.dtb");
  WriteFullDB(DBLOGSTATS, date("d/m/y").";0;");
  WriteFullDB(CHEMIN.DATAREP."nwlist.tmp","");
}

function WriteNewVersion() {
  global $version;
  $txt = "<?php
\$DBversion = \"$version\";
?>"; ?> <?php
  WriteFullDB(CHEMIN.DATAREP."dbversion.php",$txt);
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

<p align="center"><a href="Javascript: redir('<?php echo $scriptname; ?>?lng=fr'); "><img src="<?php echo CHEMIN; ?>inc/lang/fr.gif" width="24" height="16" border="0" alt="fr"/></a>&nbsp;&nbsp;&nbsp;&nbsp;<a href="Javascript: redir('<?php echo $scriptname; ?>?lng=en'); "><img src="<?php echo CHEMIN; ?>inc/lang/en.gif" width="24" height="16" border="0" alt="en"/></a></p>

<?php
 DisplayTitre($clean1,$clean2."<br /><br />".$clean3);
?>

<form name="instal0" action="<?php echo $scriptname; ?>?lng=<?php echo $lng; ?>" method="post">
<input type="hidden" name="form" value="1"/>
<center>
<input type="submit" value="<?php echo $clean4; ?>"/>
<input type="reset" value="<?php echo $clean13; ?>" onclick="redir('install.php?lng=fr&form=1')" />
</center>
</form>

<?php
 }
 elseif ($form == "1") {
 DisplayTitre($clean5,$clean6);
?>

<form name="instal1" action="<?php echo $scriptname; ?>?lng=<?php echo $lng; ?>" method="post">
<input type="hidden" name="form" value="2"/>
<center><input type="submit" value="<?php echo $clean4; ?>"/>
<input type="reset" value="<?php echo $clean13; ?>" onclick="javascript:redir('install.php?lng=fr&form=1')" />
</center>
</form>

<?php
 }
 elseif ($form == "2") {
   if (empty($doing)) {
    CleanDataRep();
    DisplayProcess($clean5,$clean7,$clean8);
    $nextstep = $scriptname."?lng=".$lng."&form=2&doing=1";
  }
  elseif ($doing == "1") {
    PrepareDataRep();
    DisplayProcess($clean5,$clean7,$clean8."<br />".$clean9);
    $nextstep = $scriptname."?lng=".$lng."&form=2&doing=2";
  }
  elseif ($doing == "2") {
    WriteNewVersion();
    DisplayProcess($clean5,$clean10,$clean8."<br />".$clean9);
    $nextstep = $scriptname."?lng=".$lng."&form=3";
    $dodo = 2;
  }
}
elseif ($form == "3") {
 DisplayTitre($clean1,$clean11);
?>

<form name="instal3" action="<?php echo $scriptname; ?>?lng=<?php echo $lng; ?>" method="post">
<input type="hidden" name="form" value="4"/>
<center><input type="submit" value="<?php echo $clean12; ?>"/>
<input type="reset" value="<?php echo $clean13; ?>" onclick="javascript:redir('install.php?lng=fr&form=1')" />
</center>
</form>

<?php
}
else {
  $nextstep = "install.php?lng=".$lng."&form=1&done=1";
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

