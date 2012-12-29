<?php
/*
    Mail function Standard #2 - GuppY PHP Script - vversion 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v2.4 (24 September 2003) : initial release
      v3.0 (25 February 2004)  : no change
      v4.0 (06 December 2004)  : no change
*/

if (stristr($_SERVER["SCRIPT_NAME"], "standard_2.inc")) {
  header("location:../index.php");
  die();
}

@mail($eTo, $eSubject, $eMessage, "From: ".$eFrom."\r\n".$eHeaders);
?>
