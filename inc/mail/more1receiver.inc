<?php
/*
    Standard Mail function type for more than one receiver - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v2.4p3 (29 Sept. 2003)   : initial release
      v4.5 (06 June 2005)      : new release by JeanMi
*/

if (stristr($_SERVER["SCRIPT_NAME"], "more1receiver.inc")) {
  header("location:../index.php");
  die();
}

if ($eTo == trim($user[1])) {
  // Partie … adapter aux besoins
  $list_email = array(
    "NAME1" => "name1@mail.ext",
    "NAME2" => "name2@mail.ext",
    "NAME3" => "name3@mail.ext" );
  // Fin de la partie … adapter
  foreach($list_email as $name => $email) {
    $eTo1 = trim($email);
    $eTo2 = trim($name)." <".trim($email).">";
    @mail($eTo1, $eSubject, $eMessage," From: ".$eFrom."\r\n".$eHeaders."To: ".$eTo2."\n");
  }
}
?>
