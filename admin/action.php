<?php
/*
    Writer action - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :    
      v4.5 (07 June 2005)     : initial release by Icare
*/
if (FileDBExist(REDACREP.$userprefs[1].INCEXT)) {
  $wri = $userprefs[1];
}
else {
  $wri = "admin";
}
?>
