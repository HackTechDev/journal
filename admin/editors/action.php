<?php
/*
     MinieditorTextarea réalisé par Djchouix
     Web site = http://lebrikabrak.free.fr/
     e-mail   = lebrikabrak@free.fr
	 version 1.5 (14 novembre 2005) compatibilité avec guppy v4.5.x
	 Ce fichier est basé sur le fichier suivant:
     Writer action - GuppY PHP Script - version 4.6
     CeCILL Copyright (C) 2004-2007 by Laurent Duveau
     Initiated by Laurent Duveau and Nicolas Alvès,
     followed by Albert Aymard, Jean Michel Misrachi, and all the GuppY Team
     Web site = http://www.freeguppy.org/
     e-mail   = guppy@freeguppy.org
     
     v4.5 (07 June 2005)     : initial release by Icare
*/
if (FileDBExist(CHEMIN.'admin/'.REDACREP.$userprefs[1].INCEXT)) {
  $wri = $userprefs[1];
}
else {
  $wri = "admin";
}
