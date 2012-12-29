<?php
/*
    Migrate Data to miniPortail v1.7 from previous version 1.x - GuppY PHP Script - version 4.5
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.aldweb.com/
      e-mail   = info@freeguppy.org
      
    Version History :
      v1.7 (28 January 2003)   : initial release
      v2.2 (22 April 2003)     : partial rewrite for compliancy with new install / migration script
                                 this is a dirty migration script that will no more be maintained from now on
*/

header("Pragma: no-cache");
define("CHEMIN", "../");
include(CHEMIN."inc/reglobals.inc");
include(CHEMIN."inc/functions.php");

function UpdateData($data) {
  global $newdate;
  for ($i = 0; $i < count($data); $i++) {
    include(DBBASE.$data[$i][1].INCEXT);
    if ($type == "links" || $type == "dnload") {
      $fieldd1 = addslashes($fieldb1);
      $fieldd2 = addslashes($fieldb2);
      $fieldb1 = addslashes($fielda1);
      $fieldb2 = addslashes($fielda2);
      $fielda1 = addslashes("");
      $fielda2 = addslashes("");
    }
    else {
      $fielda1 = addslashes($fielda1);
      $fielda2 = addslashes($fielda2);
      $fieldb1 = addslashes($fieldb1);
      $fieldb2 = addslashes($fieldb2);
      $fieldd1 = addslashes("");
      $fieldd2 = addslashes("");
    }
    $fieldc1 = addslashes($fieldc1);
    $fieldc2 = addslashes($fieldc2);
    $rec = "<?php
\$type = \"$type\";
\$fileid = \"$fileid\";
\$status = \"$status\";
\$creadate = \"$creadate\";
\$moddate = \"$moddate\";
\$author = stripslashes(\"$author\");
\$email = stripslashes(\"$email\");
\$fielda1 = stripslashes(\"$fielda1\");
\$fielda2 = stripslashes(\"$fielda2\");
\$fieldb1 = stripslashes(\"$fieldb1\");
\$fieldb2 = stripslashes(\"$fieldb2\");
\$fieldc1 = stripslashes(\"$fieldc1\");
\$fieldc2 = stripslashes(\"$fieldc2\");
\$fieldd1 = stripslashes(\"$fieldd1\");
\$fieldd2 = stripslashes(\"$fieldd2\");
?>"; ?> <?php
    WriteFullDB(DBBASE.$fileid.INCEXT,$rec);
    echo "File 'doc".$fileid.".inc' migrated<br />";
  }
}
?>
<html>
<head>
<title>miniPortail - migration script to version 1.7</title>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset; ?>">
</head>
<body bgcolor="#FFFFFF">
<?php
if ($migr == 1) {
  echo "<center><img src=\"mplogo.gif\"><br /><br />";
  echo "You are migrating to version 1.7 of miniPortail.<br /><br /><br /></center>";
  echo "Starting migration to miniPortail v1.7...<br /><br />";
  UpdateData(ReadDBFields(CHEMIN.DATAREP."docid.dtb"));
  echo "Main database ('doc*.inc' files) migrated to v1.7<br /><br />";
  UpdateDBForum("mod",0);
  echo "Files 'forum.dtb' and 'thread.dtb' migrated to v1.7<br />";
  UpdateDBdtb("art");
  echo "File 'art.dtb' migrated to v1.7<br />";
  UpdateDBdtb("dnload");
  echo "File 'dnload.dtb' created for v1.7<br />";
  UpdateDBdtb("links");
  echo "File 'links.dtb' created for v1.7<br />";
  UpdateDBnews();
  echo "File 'news.dat' created for v1.7<br />";
  WriteCounter(CHEMIN.DATAREP."statsbk.dtb",ReadCounter(CHEMIN.DATAREP."statsbk.dtb"));
  echo "File 'statsbk.dtb' created for v1.7<br /><br />";
  echo "<CENTER>Migration to miniPortail v1.7 done.<br />";
  echo "<H4>Please proceed to <A HREF=\"migrate18.php\">migration to v1.8</A></H4>.";
  echo "<br /><br /><img src=\"mpslogo.gif\"><br /></CENTER>";
}
else {
  echo "<center><img src=\"mplogo.gif\"><br /><br />";
  echo "You are about to migrate to version 1.7 of miniPortail.<br />";
  echo "Make sure to launch this migration process ONLY ONCE.<br />";
  echo "Then, move to the migration script from version 1.8 of miniPortail (see readme.txt file for further explanations).<br />";
?>
<form name="migrate" action="migrate17.php" method="POST">
<input type="hidden" name="migr" value="1">
<input type="submit" value="Launch migration process">
</form>
<?php
  echo "</center>";
}
?>
</body>
</html>
