<?php
/*
    Control members access - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.6 (01 June 2005)      : created by JeanMi
*/

if (stristr($_SERVER["SCRIPT_NAME"], "members.inc")) {
    header("location:../index.php");
    die();
}

if (isset($section_index) && isset($section_name)) {
    if ($members[0]=='on' && $userprefs[1]=='' && $members[$section_index]=='on') {
        include('inc/hpalm.inc');
        echo '
<div style="text-align:center">
    <div style="font-weight:bold">'.$section_name.'</div>
    <hr />
    <div>'.$web342.'</div>
    <br>
    <div>[ <a href="'.CHEMIN.'user.php?lng='.$lng.'">'.$web343.'</a> ]</div>
    <br>
</div>';
        include('inc/bpalm.inc');
        $section_access = false;
    } else {
        $section_access = true;
    }
} else {
    $section_access = true;
}

?>
