<?php
/*
    Standard Mail function type for more than one receiver - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :            simplistic multi-mail example
      v4.5 (015 June 2005)     : new release by Icare
*/

if (stristr($_SERVER["SCRIPT_NAME"], "more2receiver.inc")) {
  header("location:../index.php");
  die();
}

if ($eTo == trim($user[1])) {
  /// Partie … adapter aux besoins
  $list_email = array(
    "name1@mail.ext",
    "name2@mail.ext",
    "name3@mail.ext" );
  /// Fin de la partie … adapter
  foreach($list_email as $email) {
    $eTo1 = trim($email);
    @mail($eTo1, $eSubject, $eMessage,"From: ".$eFrom."\n".$eHeaders); // standard_2
    // @mail($eTo1, $eSubject, $eMessage, "From: ".$eFrom."\n".$eHeaders, "-f".$eFrom); // for standard_3
  }
}
?>
