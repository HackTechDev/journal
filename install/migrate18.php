<?php
/*
    Migrate Data to miniPortail v1.8 from previous version 1.7 - GuppY PHP Script - version 4.0
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Made by Laurent Duveau and Nicolas Alves
      Web site = http://www.aldweb.com/
      e-mail   = info@freeguppy.org
      
    Version History :
      v1.8 (05 February 2003)  : initial release
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
    if ($fielda2 != "new") {
      $fielda1 = addslashes($fielda1);
      $fielda2 = addslashes($fielda2);
      $fieldb1 = addslashes("");
      $fieldb2 = addslashes($fieldb2);
      $fieldc1 = addslashes($fieldc1);
      $fieldc2 = addslashes($fieldc2);
      $fieldd1 = addslashes($fieldd1);
      $fieldd2 = addslashes($fieldd2);
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
}
?>
<html>
<head>
<title>miniPortail - migration script to version 1.8</title>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset; ?>">
</head>
<body bgcolor="#FFFFFF">
<?php
if ($migr == 1) {
  echo "<center><img src=\"mplogo.gif\"><br /><br />";
  echo "You are migrating to version 1.8 of miniPortail.<br /><br /><br /></center>";
  echo "Starting migration to miniPortail v1.8...<br /><br />";
  UpdateData(SelectDBFields("forum","",""));
  echo "Main Forum database ('doc*.inc' files) migrated to v1.8<br /><br />";
  UpdateDBForum("mod",0);
  echo "Files 'forum.dtb' and 'thread.dtb' migrated to v1.8<br />";
  WriteFullDB(CHEMIN.DATAREP."forumcat.dtb","\n");
  echo "File 'forumcat.dtb' created for v1.8<br />";
  echo "<CENTER><br />Migration to miniPortail v1.8 done.<br /><br />";
  echo "<H4>Please proceed to <A HREF=\"install.php\">migration to v2.2</A></H4>.";
  echo "<br /><br /><center><img src=\"mpslogo.gif\"></CENTER>";
}
else {
  echo "<center><img src=\"mplogo.gif\"><br /><br />";
  echo "You are about to migrate to version 1.8 of miniPortail.<br />";
  echo "YOU SHOULD be in version 1.7 of miniPortail to proceed.<br />";
  echo "If this is not the case, then you should apply the migration script to version 1.7 first.<br />";
  echo "Make sure to launch this migration process ONLY ONCE.<br />";
  echo "Then, move to the migration script from version 2.2 of miniPortail (see readme.txt file for further explanations).<br />";
?>
<form name="migrate18" action="migrate18.php" method="POST">
<input type="hidden" name="migr" value="1">
<input type="submit" value="Launch migration process to v1.8">
</form>
<form name="migrate17" action="migrate17.php" method="POST">
<input type="hidden" name="migr" value="1">
<input type="submit" value="Apply first migration process to v1.7">
</form>
<?php
  echo "<br /><br /><center><img src=\"mpslogo.gif\"></center><br />";
}
?>
</body>
</html>
