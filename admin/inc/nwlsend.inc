<?php
/*
    Send Newsletter - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v3.0 (25 February 2004)  : initial release by Nicolas Alves and Laurent Duveau
      v4.0 (06 December 2004)  : added page title (by Jean-Mi)
				                 added multi-admin management (by Nicolas Alves)
	  v4.5 (30 March 2005)     : added security management (by Jean-Mi)
	                             corrected image path (by Icare)
	  v4.6.9f (8 January 2009) : added conversion of the relative url in absolute url
    v4.6.10 (7 September 2009)    : corrected #253
    v4.6.15 (30 June 2011) : added newsletter management for private group (by Icare)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "nwlsend.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
    include(REDACREP.$userprefs[1].INCEXT);
    if ($drtuser[33]=="") {
        $nomzone=$admin546;
        include("access.inc");
        exit();
    }
}

header("Pragma: no-cache");
define("CHEMIN", "../");


$topmess = $admin530;
include(CHEMIN."inc/hpage.inc");
$dbwork = SelectDBFieldsByStatus(SelectDBFieldsByType(ReadDBFields(DOCID),TYP_NWL),"a");
@rsort($dbwork);
htable($admin530, "100%");
echo '
<p align="center">'.$admin529.'</p><hr /><br />
';
for ($i = 0; $i < count($dbwork); $i++) {
    ReadDoc(DBBASE.$dbwork[$i][1]);
echo '
<p align="center"><a href="'.CHEMIN.'admin/admin.php?lng='.$lng.'&amp;pg=nwlsend&amp;id='.$dbwork[$i][1].'&amp;action=edit" title="">'.$admin756.'<b>'.$fieldb1.'</b></a></p>
';
}
if ($action == "edit") {
    ReadDoc(DBBASE.$id);
    $body1 = ForceToAbsolute($fieldc1);
    /// début modif groupe privé
    $nl_for = $admin526;
    if ($fieldmod != "") $nl_for .= ' ( <b>'.$admin928.' '.$fieldmod.'</b> )';
    /// fin modif groupe privé
    echo '
<hr />
<p align="center"><b>'.$admin528.'</b>
 <img src="'.CHEMIN.'inc/lang/'.$lang[0].'.gif" width="24" height="16" align="top" alt="'.$lang[0].'" title="'.$lang[0].'" /></p>
<br />
<p>'.$admin527.' '.$user[1].'</p>
<p>'.$nl_for.' </p>
<div style="padding:5px; border:1px dotted; text-align:left;">
<u>'.$admin525.'</u> '.$fieldb1.'<br /><br />
'.$body1;
    include(CHEMIN."inc/lang/".$lang[0]."-admin".INCEXT);
    echo '
<br /><br /><hr />
'.$admin533.'
</div>';
    include(CHEMIN."inc/lang/".$lng."-admin".INCEXT);
    if ($lang[1] != "") {
        echo '
<p><br /></p>
<p align="center"><b>'.$admin528.'</b>
 <img src="'.CHEMIN.'inc/lang/'.$lang[1].'.gif" width="24" height="16" align="top" alt="'.$lang[1].'" title="'.$lang[1].'" /></p>
<br />';
        include(CHEMIN."inc/lang/".$lang[1]."-admin".INCEXT);
        $body2 = ForceToAbsolute($fieldc2);
        /// début modif groupe privé
        $nl_for = $admin526;
        if ($fieldmod != "") $nl_for .= ' ( <b>'.$admin928.' '.$fieldmod.'</b> )';
        /// fin modif groupe privé
        echo '
<p>'.$admin527.' '.$user[1].'</p>
<p>'.$nl_for.'</p>
<div style="padding:5px; border:1px dotted; text-align:left;">
<u>'.$admin525.'</u> '.$fieldb2.'<br /><br />
'.$body2;
        echo '
<br /><br /><hr />
'.$admin533.'
</div>';
        include(CHEMIN."inc/lang/".$lng."-admin".INCEXT);
    }
    echo '
<p align="center">'.$boutonleft.'<button type="submit" title="'.$admin757.'" onclick="javascript:PopupWindow(\'inc/nwlmail.php?lng='.$lng.'&amp;id='.$id.'&amp;lsn=-1\',\'nwlmail\',400,225,\'no\',\'no\')">'.$admin757.'</button>'.$boutonright.'</p>
';
    $listabon = ReadDBFields(DBNEWSLETTER);
    if (!empty($listabon)) {
        echo '
<p align="center">'.$boutonleft.'<button type="submit" title="'.$admin523.'" onclick="javascript:PopupWindow(\'inc/nwlmail.php?lng='.$lng.'&amp;id='.$id.'&amp;lsn=0\',\'nwlmail\',400,225,\'no\',\'no\')">'.$admin523.'</button>'.$boutonright.'</p>
';
    }
}
echo '
<hr />
<p align="center">
[ <a href="'.CHEMIN.'admin/admin.php?lng='.$lng.'&amp;pg=newsletter">'.$admin535.'</a> || <a href="admin.php?lng='.$lng.'">'.$admin22.'</a> || <b><a href="admin.php?lng='.$lng.'&amp;logout=1">'.$admin19.'</a></b> ]
</p>
';
btable();
include(CHEMIN."inc/bpage.inc");
