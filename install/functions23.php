<?php
/*
    Functions - miniPortail PHP Script - version 2.3
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.aldweb.com/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002) : initial release
      v1.1 (02 January 2003)  : added AppendDBFields() function
                                replaced WriteDBFields() by AppendDBFields() where appropriate
                                  (in order to avoid overwrites when more users perform "add" simultaneously)
      v1.2 (05 January 2003)   : created database art.dtb for quicker display
                                   this new database is managed by the UpdateDBart() function => see update v1.7
                                 created databases thread.dtb and forum.dtb for quicker display of forum threads
                                   these new databases are managed by the UpdateDBforum() function
      v1.3 (06 January 2003)   : moved InitDBlog() function from log.inc
                                 added eMailTo() function
      v1.4 (07 January 2003)   : introduced logh.dtb for not loosing all of logd.dtb data
                                   in case of accidental erasal of logd.dtb file
      v1.5 (10 January 2003)   : no change
      v1.6 (23 January 2003)   : added option to hide on the site the e-mail address of poster
                                   that is insertion of a new field ($fieldd1) in database and
                                   update in UpdateDBforum() and ActionOnFields() functions
                                 added StartTimer() and StopTimer() functions
      v1.7 (28 January 2003)   : updated the eMailTo() function to add destination e-mail for recommend to a friend option
                                 created databases links.dtb and dnload.dtb files for category sorting of links and downloads
                                   these new databases (and art.dtb) are managed by the UpdateDBdtb() function
                                   insertion of a new field ($fieldd2) in database
                                 migrated news.dat management from admin.inc and upgraded it
      v1.8 (05 February 2003)  : added category for forum
                                   that is update in UpdateDBforum() function
      v1.9 (11 February 2003)  : moved make_seed() function (renamed as MakeSeed) from boxcita.inc (also used by
                                   the new boxban.inc banner management)
      v2.0 (27 February 2003)  : added advanced photo service, that is ActionOnFields() function small update
                                 added BreakEMail() function
      v2.1 (10 March 2003)     : no change
      v2.2 (22 April 2003)     : added INCREP variable (needed for boxes free positionning)
                                 updated UpdateDBdtb() function for left and right articles boxes management
                                 upgraded CompteVisites() function to have it compliant to the miniPortail DB
                                 added bmp type in IsImage() function
                                 updated souriez array definition for management of smileys themes
                                 added DrawSmileys() function
                                 cleanup in the images organization (Smileys)
      v2.3 (27 July 2003)      : replaced mtitre class by titre class in htable1()
                                 background of central boxes also change color according to mouse move in htable()
                                 removed link on counters numbers in counter box in the AfficheCompteur() function
                                 added US date format management
                                 modified DrawSmileys() function
                                 added PathToImage() function
                                 added $ special character management in PutHR()
*/

if (stristr($_SERVER["SCRIPT_NAME"], "functions23.php")) {
  header("location:../index.php");
  die();
}
define("CONNECTOR", "||");
define("DATAREP", "data/");
define("INCREP", "inc/");
define("DBEXT", ".dtb");
define("INCEXT", ".inc");
define("DBBASE", CHEMIN.DATAREP."doc");
define("NEXTID", CHEMIN.DATAREP."nextid".DBEXT);
define("DOCID", CHEMIN.DATAREP."docid".DBEXT);
define("DBART", CHEMIN.DATAREP.TYP_ART.DBEXT);
define("DBLINKS", CHEMIN.DATAREP.TYP_LINKS.DBEXT);
define("DBDNLOAD", CHEMIN.DATAREP.TYP_DNLOAD.DBEXT);
define("DBTHREAD", CHEMIN.DATAREP.TYP_THREAD.DBEXT);
define("DBFORUM", CHEMIN.DATAREP.TYP_FORUM.DBEXT);
define("DBFORUMCAT", CHEMIN.DATAREP.TYP_FORUM."cat".DBEXT);
define("DBPHOTO", CHEMIN.DATAREP.TYP_PHOTO.DBEXT);
define("DBLOGH", CHEMIN.DATAREP."logh".DBEXT);
define("DBLOGD", CHEMIN.DATAREP."logd".DBEXT);
define("DBLOGM", CHEMIN.DATAREP."logm".DBEXT);
define("DBLOGY", CHEMIN.DATAREP."logy".DBEXT);
define("DBLOGP", CHEMIN.DATAREP."logp".DBEXT);

define("HIT_TIME", 1800);

$couleurs = array("bleu", "jaune", "marron", "or", "orange", "outremer", "rose", "rouge", "vert", "violet");
$souriez = array(
	         array("|:-)", "inc/img/smileys/cool.gif"),
	         array(";-)", "inc/img/smileys/wink.gif"),
	         array(":-))", "inc/img/smileys/biggrin.gif"),
	         array(":-)", "inc/img/smileys/smile.gif"),
	         array(":-o", "inc/img/smileys/frown.gif"),
             array(":o)", "inc/img/smileys/eek.gif"),
	         array(":-((", "inc/img/smileys/mad.gif"),
	         array(":-(", "inc/img/smileys/confused.gif"),
	         array("8-)", "inc/img/smileys/rolleyes.gif"),
	         array(":-p", "inc/img/smileys/tongue.gif"),
	         array(";-(", "inc/img/smileys/cry.gif")
           );

function htable($tblti, $largeur) {
  global $texte;
  echo "<table cellspacing=\"0\" cellpadding=\"1\" border=\"0\" align=\"center\" width=\"".$largeur."\" class=\"bordure\"><tr><td>\n";
  echo "<table cellspacing=\"1\" cellpadding=\"5\" border=\"".$texte[4]."\" align=\"center\" width=\"100%\">\n";
  echo "<tr><td nowrap class=\"tbl1\"><p class=\"titre\"><b>".$tblti."</b></p></td></tr>\n";
  echo "<tr><td class=\"tbl2\" onMouseOver=\"this.className = 'tbl2over';\" onMouseOut=\"this.className = 'tbl2';\">\n\n";
}

function htable1($tblti) {
  global $texte;
  echo "<table cellspacing=\"0\" cellpadding=\"1\" border=\"0\" align=\"center\" width=\"100%\" class=\"bordure\"><tr><td>\n";
  echo "<table cellspacing=\"1\" cellpadding=\"5\" border=\"".$texte[4]."\" align=\"center\" width=\"100%\">\n";
  echo "<tr><td nowrap class=\"tbl1\"><p class=\"titre\" align=\"center\"><b>".$tblti."</b></p></td></tr>\n";
  echo "<tr><td class=\"tbl2\" onMouseOver=\"this.className = 'tbl2over';\" onMouseOut=\"this.className = 'tbl2';\">\n\n";
}

function btable() {
  echo "\n</td></tr></table>\n";
  echo "\n</td></tr></table>\n";
}

function IsImage($extn) {
  $imgok = 0;
  $extn = strtolower($extn);
  if ($extn == "gif" || $extn == "jpg" || $extn == "jpeg") {
    $imgok = 1;
  }
  return $imgok;
}

function ExtImage($extn){
  $extn = strtolower($extn);
  if ($extn == "php"){ return "php"; }
  if ($extn == "php3"){ return "php"; }
  if ($extn == "phtml"){ return "php"; }
  if ($extn == "htm"){ return "html"; }
  if ($extn == "html"){ return "html"; }
  if ($extn == "js"){ return "js"; }
  if ($extn == "css"){ return "css"; }

  if ($extn == "gif"){ return "gif"; }
  if ($extn == "jpg"){ return "jpg"; }
  if ($extn == "jpeg"){ return "jpg"; }
  if ($extn == "png"){ return "png"; }
  if ($extn == "bmp"){ return "bmp"; }

  if ($extn == "cab"){ return "zip"; }
  if ($extn == "zip"){ return "zip"; }
  if ($extn == "ace"){ return "zip"; }
  if ($extn == "tgz"){ return "zip"; }
  if ($extn == "gz"){ return "zip"; }
  if ($extn == "tar"){ return "zip"; }
  if ($extn == "rar"){ return "zip"; }

  if ($extn == "wav"){ return "wav"; }
  if ($extn == "mid"){ return "mid"; }
  if ($extn == "mp3"){ return "mp3"; }

  if ($extn == "exe"){ return "exe"; }
  if ($extn == "bat"){ return "bat"; }
  if ($extn == "com"){ return "com"; }
  if ($extn == "pif"){ return "com"; }

  if ($extn == "mov"){ return "wav"; }
  if ($extn == "avi"){ return "wav"; }
  if ($extn == "mpg"){ return "wav"; }
  if ($extn == "mpeg"){ return "wav"; }
  if ($extn == "swf"){ return "swf"; }

  if ($extn == "txt"){ return "txt"; }
  if ($extn == "nfo"){ return "txt"; }
  return "inconnu";
}

function FileSizeInKb($fic) {
  global $size_unit;
  $taille=filesize($fic);
  $taille = round($taille/1024);
  return $taille;
}

function ReadCounter($fic) {
  $fhandle = fopen($fic, "r");
  $DataDB = trim(fgets($fhandle, filesize($fic)));
  fclose($fhandle);
  return $DataDB;
}

function WriteCounter($fic,$DataDB) {
  $fhandle = fopen($fic, "w");
  fputs($fhandle, $DataDB."\n");
  fclose($fhandle);
}

function ReadFullDB($fic) {
  $DataDB = implode("", file($fic));
  return $DataDB;
}

function WriteFullDB($fic,$DataDB) {
  $fhandle = fopen($fic, "w");
  fputs($fhandle, $DataDB);
  fclose($fhandle);
}

function AppendFullDB($fic,$DataDB) {
  $fhandle = fopen($fic, "a");
  fputs($fhandle, $DataDB);
  fclose($fhandle);
}

function ReadDBFields($fic) {
  $DataDB = file($fic);
  for ($i = 0; $i < count($DataDB); $i++) {
    $Fields[$i] = explode(CONNECTOR,trim($DataDB[$i]));
  }
  return $Fields;
}

function WriteDBFields($fic,$Fields) {
  $fhandle = fopen($fic, "w");
  $DataDB = "";
  for ($i = 0; $i < count($Fields); $i++) {
    for ($j = 0 ; $j < (count($Fields[$i])-1); $j++) {
      $DataDB .= trim($Fields[$i][$j]).CONNECTOR;
    }
    $DataDB .= trim($Fields[$i][count($Fields[$i])-1])."\n";
  }
  fputs($fhandle, $DataDB);
  fclose($fhandle);
}

function AppendDBFields($fic,$Fields) {
  $fhandle = fopen($fic, "a");
  $DataDB = "";
  for ($i = 0 ; $i < (count($Fields)-1); $i++) {
    $DataDB .= trim($Fields[$i]).CONNECTOR;
  }
  $DataDB .= trim($Fields[count($Fields)-1])."\n";
  fputs($fhandle, $DataDB);
  fclose($fhandle);
}

function SelectDBFieldsByID($Fields,$id) {
  $DataDB = array();
  $k = 0;
  for ($i = 0; $i < count($Fields); $i++) {
    if ($Fields[$i][1] == $id) {
      for ($j = 0 ; $j < count($Fields[$i]); $j++) {
        $DataDB[$k][$j] = $Fields[$i][$j];
      }
      $k++;
    }
  }
  return $DataDB;
}

function SelectDBFieldsByType($Fields,$type) {
  $DataDB = array();
  $k = 0;
  for ($i = 0; $i < count($Fields); $i++) {
    if ($Fields[$i][0] == $type) {
      for ($j = 0 ; $j < count($Fields[$i]); $j++) {
        $DataDB[$k][$j] = $Fields[$i][$j];
      }
      $k++;
    }
  }
  return $DataDB;
}

function SelectDBFieldsByNotStatus($Fields,$status) {
  $DataDB = array();
  $k = 0;
  for ($i = 0; $i < count($Fields); $i++) {
    if ($Fields[$i][2] != $status) {
      for ($j = 0 ; $j < count($Fields[$i]); $j++) {
        $DataDB[$k][$j] = $Fields[$i][$j];
      }
    $k++;
    }
  }
  return $DataDB;
}

function SelectDBFieldsByStatus($Fields,$status) {
  $DataDB = array();
  $k = 0;
  for ($i = 0; $i < count($Fields); $i++) {
    if ($Fields[$i][2] == $status) {
      for ($j = 0 ; $j < count($Fields[$i]); $j++) {
        $DataDB[$k][$j] = $Fields[$i][$j];
      }
      $k++;
    }
  }
  return $DataDB;
}

function SelectDBFields($type,$status,$id) {
  $DataDB = array();
  if (!empty($status) && !empty($id)) {
    $DataDB = SelectDBFieldsByID(SelectDBFieldsByStatus(SelectDBFieldsByType(ReadDBFields(DOCID),$type),$status),$id);
  }
  elseif (!empty($status)) {
    $DataDB = SelectDBFieldsByStatus(SelectDBFieldsByType(ReadDBFields(DOCID),$type),$status);
  }
  elseif (!empty($id)) {
    $DataDB = SelectDBFieldsByID(SelectDBFieldsByType(ReadDBFields(DOCID),$type),$id);
  }
  else {
    $DataDB = SelectDBFieldsByType(ReadDBFields(DOCID),$type);
  }
  return $DataDB;
}

function RemoveConnector($chaine) {
  $traite = str_replace(CONNECTOR, "", $chaine);
  return $traite;
}

function RemoveBR($chaine) {
  $traite = str_replace("<br />", "\n", $chaine);
  $traite = str_replace("<br />", "\n", $traite);
  $traite = str_replace("<br />", "\n", $traite);
  $traite = str_replace("<br />", "\n", $traite);
  return $traite;
}

function PutBR($chaine) {
  $traite = str_replace(chr(10),"<br />",$chaine);
  $traite = str_replace(chr(13),"",$traite);
  return $traite;
}

function RemoveHR($chaine) {
  $traite = str_replace("</p><hr /><p>", "<hr />", $chaine);
  return $traite;
}

function PutHR($chaine) {
  $traite = str_replace("<hr />", "</p><hr /><p>", $chaine);
  $traite = str_replace("<hr />", "</p><hr /><p>", $traite);
  $traite = str_replace("<hr />", "</p><hr /><p>", $traite);
  $traite = str_replace("<hr />", "</p><hr /><p>", $traite);
  $traite = str_replace("$","$&shy;",$traite);
  return $traite;
}

function souriez($chaine) {
  global $souriez;
  $traite = str_replace($souriez[0][0], "<img src=\\\"".$souriez[0][1]."\\\" border=\\\"0\\\">", $chaine);
  $traite = str_replace($souriez[1][0], "<img src=\\\"".$souriez[1][1]."\\\" border=\\\"0\\\">", $traite);
  $traite = str_replace($souriez[2][0], "<img src=\\\"".$souriez[2][1]."\\\" border=\\\"0\\\">", $traite);
  $traite = str_replace($souriez[3][0], "<img src=\\\"".$souriez[3][1]."\\\" border=\\\"0\\\">", $traite);
  $traite = str_replace($souriez[4][0], "<img src=\\\"".$souriez[4][1]."\\\" border=\\\"0\\\">", $traite);
  $traite = str_replace($souriez[5][0], "<img src=\\\"".$souriez[5][1]."\\\" border=\\\"0\\\">", $traite);
  $traite = str_replace($souriez[6][0], "<img src=\\\"".$souriez[6][1]."\\\" border=\\\"0\\\">", $traite);
  $traite = str_replace($souriez[7][0], "<img src=\\\"".$souriez[7][1]."\\\" border=\\\"0\\\">", $traite);
  $traite = str_replace($souriez[8][0], "<img src=\\\"".$souriez[8][1]."\\\" border=\\\"0\\\">", $traite);
  $traite = str_replace($souriez[9][0], "<img src=\\\"".$souriez[9][1]."\\\" border=\\\"0\\\">", $traite);
  $traite = str_replace($souriez[10][0], "<img src=\\\"".$souriez[10][1]."\\\" border=\\\"0\\\">", $traite);
  return $traite;
}

function UpdateDBnews() {
  global $lang,$lng,$site,$serviz;
  if ($serviz[16] == "on") {
    $dbwork1 = SelectDBFields("news","a","");
    if ($lang[1] != "") {
      include(CHEMIN."inc/lang/".$lang[1]."-web.inc");
      $par2 = $web6;
      $le2 = $web7;
    }
    include(CHEMIN."inc/lang/".$lng."-web.inc");
    $par1 = $web6;
    $le1 = $web7;
    $sito = $site[3];
    if ($sito[strlen($sito)] != "/") {
      $sito .= "/";
    }
    for ($i = 0; $i < count($dbwork1); $i++) {
      include(DBBASE.$dbwork1[$i][1].INCEXT);
      $dbwork2[$i][0] = $fieldb1." - ".$par1." ".$author." ".$le1." ".$creadate;
      $dbwork2[$i][1] = $fieldc1;
      $dbwork2[$i][2] = $sito."news.php?lng=".$lng."&id=".$fileid;
      if ($lang[1] != "") {
        $dbwork2[$i][3] = $fieldb2." - ".$par2." ".$author." ".$le2." ".$creadate;
        $dbwork2[$i][4] = $fieldc2;
        $dbwork2[$i][5] = $sito."news.php?lng=".$lang[1]."&id=".$fileid;
      }
      else {
        $dbwork2[$i][3] = "";
        $dbwork2[$i][4] = "";
        $dbwork2[$i][5] = "";
      }
    }
    WriteDBFields(CHEMIN.DATAREP."news.dat",$dbwork2);
  }
  else {
    WriteFullDB(CHEMIN.DATAREP."news.dat","\n");
  }
}

function UpdateDBdtb($dtb) {
  $db = SelectDBFields($dtb,"a","");
  $dba = array();
  $j = 0;
  for ($i = 0; $i < count($db); $i++) {
    include(DBBASE.$db[$i][1].INCEXT);
    if (!($dtb == "art" && trim($fielda1).trim($fielda2) == "")) {
      $dba[$j][0] = RemoveConnector($fielda1);
      $dba[$j][1] = RemoveConnector($fielda2);
      $dba[$j][2] = RemoveConnector($fieldb1);
      $dba[$j][3] = RemoveConnector($fieldb2);
      $dba[$j][4] = $fileid;
      if ($dtb == "art") {
        $dba[$j][5] = RemoveConnector($fieldd1);
      }
      $j++;
    }
  }
  WriteDBFields(CHEMIN.DATAREP.$dtb.DBEXT,$dba);
}

function UpdateDBforum($action,$id) {
  global $site;
  $db = array();
  if ($action == "add") {
    include(DBBASE.$id.INCEXT);
    if ($site[19] == "US") {
      $db[0] = substr($creadate,6,4).substr($creadate,0,2).substr($creadate,3,2); // date du thread
    }
    else {
      $db[0] = substr($creadate,6,4).substr($creadate,3,2).substr($creadate,0,2); // date du thread
    }
    $db[1] = substr($creadate,13);                    // heure du thread
    $db[2] = $creadate;                               // date @ heure du thread
    $db[3] = $fielda1;                                // numéro de thread
    $db[4] = $fielda2;                                // numéro de réponse ou "new" si nouveau thread
    $db[5] = $fileid;                                 // id du thread
    $db[6] = RemoveConnector($author);                // auteur
    $db[7] = RemoveConnector($email);                 // e-mail auteur
    $db[8] = RemoveConnector($fieldb1);               // titre
    $db[9] = $fieldd1;                                // show or hide e-mail auteur
    $db[10] = $fieldb2;                               // ID catégorie thread
    AppendDBFields(DBTHREAD,$db);
  }
  else {
    $db = SelectDBFields("forum","a","");
    sort($db);
    $dbf = array();
    for ($i = 0; $i < count($db); $i++) {
      include(DBBASE.$db[$i][1].INCEXT);
      if ($site[19] == "US") {
        $dbf[$i][0] = substr($creadate,6,4).substr($creadate,0,2).substr($creadate,3,2); // date du thread
      }
      else {
        $dbf[$i][0] = substr($creadate,6,4).substr($creadate,3,2).substr($creadate,0,2); // date du thread
      }
      $dbf[$i][1] = substr($creadate,13);             // heure du thread
      $dbf[$i][2] = $creadate;                        // date @ heure du thread
      $dbf[$i][3] = $fielda1;                         // numéro de thread
      $dbf[$i][4] = $fielda2;                         // numéro de réponse ou "new" si nouveau thread
      $dbf[$i][5] = $fileid;                          // id du thread
      $dbf[$i][6] = RemoveConnector($author);         // auteur
      $dbf[$i][7] = RemoveConnector($email);          // e-mail auteur
      $dbf[$i][8] = RemoveConnector($fieldb1);        // titre
      $dbf[$i][9] = $fieldd1;                         // show or hide e-mail auteur
      $dbf[$i][10] = $fieldb2;                        // ID catégorie thread
    }
    @sort($dbf,SORT_REGULAR);
    WriteDBFields(DBTHREAD,$dbf);
  }
  $db = array();
  $db = ReadDBFields(DBTHREAD);
  $dbf = array();
  $j = 0;
  for ($i = 0; $i < count($db); $i++) {
    if ($db[$i][4] == "new") {
      $dbf[$j][0] = $db[$i][0];            // date de la dernière réponse
      $dbf[$j][1] = $db[$i][1];            // heure de la dernière réponse
      $dbf[$j][2] = $db[$i][2];            // date @ heure de la dernière réponse
      $dbf[$j][3] = $db[$i][3];            // numéro de thread
      $dbf[$j][4] = $db[$i][5];            // id de début du thread
      $dbf[$j][5] = $db[$i][6];            // auteur
      $dbf[$j][6] = $db[$i][7];            // e-mail auteur
      $dbf[$j][7] = $db[$i][8];            // titre
      $dbf[$j][8] = $db[$i][2];            // date @ heure de création du thread
      $dbf[$j][9] = 0;                     // nombre de réponses
      $dbf[$j][10] = "";                   // auteur de la dernière réponse
      $dbf[$j][11] = "";                   // e-mail auteur de la dernière réponse
      $dbf[$j][12] = $db[$i][9];           // show or hide e-mail auteur
      $dbf[$j][13] = "";                   // show or hide e-mail auteur de la dernière réponse
      $dbf[$j][14] = $db[$i][10];          // ID catégorie thread
      for ($k = $i+1; $k < count($db); $k++) {
        if ($db[$k][3] == $dbf[$j][3]) {
          $dbf[$j][0] = $db[$k][0];
          $dbf[$j][1] = $db[$k][1];
          $dbf[$j][2] = $db[$k][2];
          $dbf[$j][9] = $dbf[$j][9]+1;
          $dbf[$j][10] = $db[$k][6];
          $dbf[$j][11] = $db[$k][7];
          $dbf[$j][13] = $db[$k][9];
        }
      }
      $j++;
    }
  }
  @rsort($dbf,SORT_REGULAR);
  WriteDBFields(DBFORUM,$dbf);
}

function ActionOnFields($action,$data) {
  global $site;
  if ($action == "del") {
    $id = $data[1];
    $db = ReadDBFields(DOCID);
    for ($i = 0; $i < count($db); $i++) {
      if ($db[$i][1] == $id) {
        $db[$i][2] = "d";
      }
    }
    WriteDBFields(DOCID,$db);
    include(DBBASE.$id.INCEXT);
    $status = "d";
    $author = addslashes($author);
    $email = addslashes($email);
    $fielda1 = addslashes($fielda1);
    $fielda2 = addslashes($fielda2);
    $fieldb1 = addslashes($fieldb1);
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
  }
  elseif ($action == "act") {
    $id = $data[1];
    $db = ReadDBFields(DOCID);
    for ($i = 0; $i < count($db); $i++) {
      if ($db[$i][1] == $id) {
          $db[$i][2] = $data[2];
      }
    }
    WriteDBFields(DOCID,$db);
    include(DBBASE.$id.INCEXT);
    $status = $data[2];
    $author = addslashes($author);
    $email = addslashes($email);
    $fielda1 = addslashes($fielda1);
    $fielda2 = addslashes($fielda2);
    $fieldb1 = addslashes($fieldb1);
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
  }
  elseif ($action == "add") {
	$id = ReadCounter(NEXTID);
	$id = $id+1;
	WriteCounter(NEXTID,$id);
	$db = array();
	$db[0] = $data[0];
    $db[1] = $id;
    $db[2] = $data[2];
	AppendDBFields(DOCID,$db);
    $type = $data[0];
    $fileid = $id;
    $status = $data[2];
    if ($site[19] == "US") {
      $creadate = date("m/d/Y")." @ ".date("H:i");
    }
    else {
      $creadate = date("d/m/Y")." @ ".date("H:i");
    }
    $moddate = $creadate;
    $author = addslashes(stripslashes($data[5]));
    $email = addslashes(stripslashes($data[6]));
    $fielda1 = addslashes(stripslashes($data[7]));
    $fielda2 = addslashes(stripslashes($data[8]));
    $fieldb1 = addslashes(stripslashes($data[9]));
    $fieldb2 = addslashes(stripslashes($data[10]));
    $fieldc1 = addslashes(stripslashes(souriez(PutHR(PutBR($data[11])))));
    $fieldc2 = addslashes(stripslashes(souriez(PutHR(PutBR($data[12])))));
    $fieldd1 = addslashes(stripslashes($data[13]));
    $fieldd2 = addslashes(stripslashes($data[14]));
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
  }
  elseif ($action == "mod") {
    $id = $data[1];
    include(DBBASE.$id.INCEXT);
    if ($site[19] == "US") {
      $moddate = date("m/d/Y")." @ ".date("H:i");
    }
    else {
      $moddate = date("d/m/Y")." @ ".date("H:i");
    }
    $author = addslashes(stripslashes($data[5]));
    $email = addslashes(stripslashes($data[6]));
    $fielda1 = addslashes(stripslashes($data[7]));
    $fielda2 = addslashes(stripslashes($data[8]));
    $fieldb1 = addslashes(stripslashes($data[9]));
    $fieldb2 = addslashes(stripslashes($data[10]));
    $fieldc1 = addslashes(stripslashes(souriez(PutHR(PutBR($data[11])))));
    $fieldc2 = addslashes(stripslashes(souriez(PutHR(PutBR($data[12])))));
    $fieldd1 = addslashes(stripslashes($data[13]));
    $fieldd2 = addslashes(stripslashes($data[14]));
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
  }
  if ($data[0] == "art" || $data[0] == "links" || $data[0] == "dnload" || $data[0] == "photo") {
    UpdateDBdtb($data[0]);
  }
  elseif ($data[0] == "forum") {
    UpdateDBforum($action,$id);
  }
  elseif ($data[0] == "news") {
    UpdateDBnews();
  }
}

function AfficheCompteur($chemino, $hits, $grow = 1) {
  $spot = "";
  for ($lecon = 0; $lecon < $grow - strlen($hits); $lecon++ ) {
    $spot .= "<IMG SRC=\"".$chemino."cnt0.gif\" BORDER=0>";
  }
  for ($lecon = 0; $lecon < strlen($hits); $lecon++) {
    $cols = substr($hits, $lecon, 1);
    $spot .= "<IMG SRC=\"".$chemino."cnt".$cols.".gif\" BORDER=0>";
  }
  echo $spot;
}

function CompteVisites($chemino, $file_ip, $file_counter) {
  global $REMOTE_ADDR;
  $remoteadr = $REMOTE_ADDR;
  $nbr_connect = 0;
  $var_bool = false;
  $subdata = array();
  $var_ip = array();
  $k = 0;
  $subdata = ReadDBFields($chemino.$file_ip);
  $now_time = time();
  for ($i = 0; $i < count($subdata); $i++) {
    list($jour, $mois, $annee) = explode("/", substr($subdata[$i][1], 0, 10));
    list($heure, $minute, $seconde) = explode(":", substr($subdata[$i][1], 10, 18));
    if ($now_time < mktime($heure, $minute, $seconde, $mois, $jour, $annee) + HIT_TIME) {
      $nbr_connect++;
      $var_ip[$k][0] = $subdata[$i][0];
      $var_ip[$k][1] = $subdata[$i][1];
      $k++;
      if ($remoteadr == $subdata[$i][0]) {
        $var_bool = true;
      }
    }
  }
  $nbr_visit = ReadCounter($chemino.$file_counter);
  if (!$var_bool) {
    $nbr_visit++;
    WriteCounter($chemino.$file_counter,$nbr_visit);
    $var_ip[$k][0] = $remoteadr;
    $var_ip[$k][1] = date("d/m/Y H:i:s");
    WriteDBFields($chemino.$file_ip,$var_ip);
    $nbr_connect++;
  }
  $retcmpt[0] = $nbr_visit;
  $retcmpt[1] = $nbr_connect;
  return $retcmpt;
}

function InitDBlog($typ) {
  $db = array();
  $db[0][0] = 0;
  for ($i = 0; $i < 12; $i++) {$db[1][$i] = 0;}
  for ($i = 0; $i < 2; $i++) {$db[2][$i] = 0;}
  for ($i = 0; $i < 9; $i++) {$db[3][$i] = 0;}
  for ($i = 0; $i < 10; $i++) {$db[4][$i] = 0;}
  for ($i = 0; $i < $typ; $i++) {$db[5][$i] = 0;}
  for ($i = 0; $i < $typ; $i++) {$db[6][$i] = 0;}
  $db[7][0] = 1;
  return $db;
}

function eMailTo($eSubject,$eMessage,$eTo) {
  global $supervision,$user;
  if ($eTo == "") {
    $eTo = trim($user[1]);
  }
  if ($supervision[5] == "standard") {
    @mail($eTo,$eSubject,$eMessage,"From: ".trim($user[1]));
  }
  elseif ($supervision[5] == "online") {
    $eFrom = trim(substr($user[1],0,strpos($user[1],"@")));
    @email($eFrom,$eTo,$eSubject,$eMessage);
  }
  elseif ($supervision[5] == "nexen") {
    include("mail.inc");
    @email($eTo,$eSubject,$eMessage,"From: ".trim($user[1]));
  }
}

function BreakEMail($eminput) {
  $eminput = trim($eminput);
  $em1 = strpos($eminput,"@");
  $em2 = strrpos($eminput,".");
  $emoutput[0] = substr($eminput,0,$em1);
  $emoutput[1] = substr($eminput,$em1+1,$em2-$em1-1);
  $emoutput[2] = substr($eminput,$em2+1);
  return $emoutput;
}

function StartTimer() {
 global $starttime;
 $mtime = microtime();
 $mtime = explode(' ', $mtime);
 $mtime = $mtime[1] + $mtime[0];
 $starttime = $mtime;
}

function StopTimer() {
  global $starttime;
  $mtime = microtime();
  $mtime = explode(' ', $mtime);
  $mtime = $mtime[1] + $mtime[0];
  $stoptime = round (($mtime - $starttime), 2);
  return $stoptime;
}

function MakeSeed() {
  list($usec, $sec) = explode(' ', microtime());
  return (float) $sec + ((float) $usec * 100000);
}

function DrawSmileys($num) {
  global $souriez;
  echo "<p align=\"center\">\n";
  for ($i = 0; $i < count($souriez); $i++) {
    echo "<img src=\"".CHEMIN.$souriez[$i][1]."\" class=\"clsCursor\" border=\"0\" alt=\"".$souriez[$i][0]."\" onClick=\"JavaScript:AddSmiley".$num."('".$souriez[$i][0]."')\">&nbsp;\n";
  }
  echo "</p>";
}

function PathToImage($pathin) {
  $pathout = str_replace("img/",CHEMIN."img/",$pathin);
  $pathout = str_replace("inc/".CHEMIN."img/",CHEMIN."inc/img/",$pathout);
  return $pathout;
}
?>
