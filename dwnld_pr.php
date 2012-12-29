<?php
/*
    Download - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
    v4.6.17 (21 October 2011 )  : initial release (by Laroche)
    v4.6.17 (26 October 2011 )  : corrected for private groups (by Laroche)
    v4.6.18 (09 February 2012)  : corrected for private groups (by Laroche)
*/

define("CHEMIN", "");
include("inc/includes.inc");
include('inc/func_groups.php');
$usercookie = "GuppYUser";
$userprefs = array();
if (!empty($_COOKIE[$usercookie])) {
    $userprefs = explode("||",$_COOKIE[$usercookie]);
    $userprefs[0] = strip_tags($userprefs[0]);
    $userprefs[1] = preg_replace("![^a-zA-Z0-9_]!i","",substr(strip_tags($userprefs[1]),0,20));
}

if (!empty($_GET['pg']) && !empty($_GET['lng'])) {
  $pg = strip_tags($_GET['pg']);
  $lng = strip_tags($_GET['lng']);
  if (!is_numeric($pg) || strlen($lng) != 2) {
      die();
  } else {
    ReadDoc(DBBASE.$pg);
    if ($lng == $lang[0]) {
      $repfichier = $fieldd1;
    } else {
      $repfichier = $fieldd2;
    }
    if(file_exists($repfichier)) {
      if (CheckGroup($fieldmod, $userprefs[1])) {
        UpdateDocCounter($pg);
        $download = fopen ($repfichier, "r");
        $size = filesize($repfichier);
        $fileInfo = pathinfo($repfichier);
        $ext = strtolower($fileInfo["extension"]);
        switch ($ext) {
          case "pdf":
            header("Content-type: application/pdf"); 
            header("Content-Disposition: attachment; filename=\"{$fileInfo["basename"]}\"");
            break;
          default;
            header("Content-type: application/octet-stream");
            header("Content-Disposition: filename=\"{$fileInfo["basename"]}\"");
        }    
        header("Content-length: $size");
        while(!feof($download)) {
          $buffer = fread($download, 2048);
          echo $buffer;
        }
        fclose ($download);
        exit;
      }
    } 
  }
}
?>