<?php
/*
    Upload / Delete files - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v2.2 (22 April 2003)     : replaced <P><CENTER> by <P align="center"> otherwise IE takes the default font instead of the required one (Thanks Michel)
                                 Automatic directory change in Upload area (no more need to press a button for changing of directory)
                                 moved images from inc/img/ to inc/img/files/
      v2.3 (27 July 2003)      : added forms style management (by Nicolas Alves)
      v3.0 (25 February 2004)  : added skins management (by Nicolas Alves)
                                 added a new pages/ directory
      v4.0 (06 December 2004)  : added alt tags to img and removed border tag for non-linked img (by Isa)
	                               added multi-admin management (by NIcolas Alves)
	  v4.5 (March 2005)          : added list of directory and sub-directory (by Jean-Mi)
	  v4.6.0 (04 June 2007)      : changed copy by move_uploaded_file (by Icare)
	  v4.6.8 (24 May 2008)       : new release with create/delete subdirectory (by JeanMi)
    v4.6.10 (7 september 2009) : corrected #274
    v4.6.11 (11 December 2009) : corrected #307
    v4.6.12 (01 May 2010) : corrected #320
    v4.6.13 (22 May 2010) : corrected #320
*/

if (stristr($_SERVER["SCRIPT_NAME"], "upload.inc")) {
  header("location:../index.php");
  die();
}

// Liste des répertoires où l'upload est autorisé
$list_baserep = array("file", "flash", "img", "pages", "photo");

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[36]=="") {
    $nomzone=$admin171;
    include("access.inc");
    exit();
  }
}

// Fonctions d'exploration récursive des répertoires
function lister_sousrepertoires($dir){
    $r = $dir." ";
    $h = opendir(CHEMIN.$dir);
    while ($f = readdir($h)) {
        if (is_dir(CHEMIN.$dir."/".$f) && ($f[0] != "."))
            $r .= lister_sousrepertoires($dir."/".$f)." ";
    }
    closedir($h);
    return trim($r);
}
function lister_repertoires($list){
    $r = "";
    for($i=0; $i<count($list); $i++){
        if (is_dir(CHEMIN.$list[$i])) {
            $r .= " ".lister_sousrepertoires($list[$i]);
        }
    }
    return explode(" ", trim($r));
}

if (empty($rep)) {
    $rep="file";
}

/// DELETE FILE
if (!empty($del)) {
    @chmod(CHEMIN.$rep."/".$del,0777);
    unlink(CHEMIN.$rep."/".$del);
}

/// CREATE DIRECTORY
if (!empty($newrep)) {
    if (stristr($newrep, 'script') !== false) {
        echo '
<script type="text/javascript">
    alert("Nom de répertoire interdit - Forbidden directory name !!!");
    history.back();
</script>';
    } else {
        $tmp = explode('/', $rep);
        if (in_array($tmp[0], $list_baserep)) {
            $subreps = explode('/', $newrep);
            if (!in_array('..', $tmp) && !in_array('..', $subreps)) {
                $path = CHEMIN.$rep.'/';
                foreach ($subreps as $subrep) {
                    if (!is_dir($path.$subrep)) {
                        if (@mkdir($path.$subrep)) {
                            @chmod($path.$subrep, 0777);
                            @copy(CHEMIN.'file/index.php', $path.$subrep.'/index.php');
                        } else {
                            $msg = $path.$subrep.' '.$admin20;
                            break;
                        }
                    }
                    $path .= $subrep.'/';
                }
                if (empty($msg)) {
                    $rep .= '/'.$newrep;
                }
            }
        }
    }
}

/// DELETE DIRECTORY
if (isset($delrep)) {
    $tmp = explode('/', $delrep);
    if (count($tmp) > 1) {
        $last = array_pop($tmp);
        if ($dh = opendir(CHEMIN.$delrep)) {
            $empty = true;
            $notdel = true;
            while ($empty && ($file = readdir($dh)) !== false) {
                switch ($file) {
                case '.' :
                case '..' :
                    break;
                case 'index.php' :
                    @chmod(CHEMIN.$delrep.'/index.php', 0777);
                    $empty = @unlink(CHEMIN.$delrep.'/index.php');
                    break;
                default :
                    $empty = false;
                }
            }
            closedir($dh);
            if ($empty) {
                @chmod(CHEMIN.$delrep, 0777);
                if (@rmdir(CHEMIN.$delrep)) {
                    if (!is_dir(CHEMIN.$delrep)) {
                        $delrep = implode('/', $tmp);
                        $notdel = false;
                    }
                }
            }
            if ($notdel) {
                $msg = $delrep.' : '.$admin20.'!! &nbsp;nb '.$admin171.' > 0';
            }
        }
    }
    $rep = $delrep;
}

/// UPLOAD FILE
if (!empty($_FILES['ficup']['name']) && isset($_POST['OK'])) {
    if (is_uploaded_file($_FILES['ficup']['tmp_name'])) {
        move_uploaded_file($_FILES['ficup']['tmp_name'], CHEMIN.$rep.'/'.$_FILES['ficup']['name']);
    }
}

$newrep = '';
$candel = !in_array($rep,$list_baserep);
$list_rep = lister_repertoires($list_baserep);
$dbfiles = array();
$i = 0;
$dossier = opendir(CHEMIN.$rep);
while ($fichier = readdir($dossier)) {
    if (is_file(CHEMIN.$rep."/".$fichier) && $fichier != "index.php") {
        $dbfiles[$i][0] = $fichier;
        $path_parts = basename($fichier);
        $path_parts = substr($path_parts, strrpos($path_parts, ".") + 1);
        $dbfiles[$i][1] = "inc/img/files/".ExtImage($path_parts).".gif";
        $dbfiles[$i][2] = FileSizeInKb(CHEMIN.$rep."/".$fichier);
        $i++;
    }
}
closedir($dossier);
sort($dbfiles);

$topmess = $admin180;
include(CHEMIN."inc/hpage.inc");
htable($admin180, "100%");

echo '

<p align="center">'.$admin181.'</p>
<hr />
<p align="center"><a href="admin.php?lng='.$lng.'">'.$admin22.'</a> || <strong><a href="admin.php?lng='.$lng.'&amp;logout=1">'.$admin19.'</a></strong></p>
<hr />
<form name="changedir" action="admin.php?lng='.$lng.'" method="post">
 <input type="hidden" name="pg" value="upload" />
 <table cellspacing="0" cellpadding="5" align="center" border="0" summary="">
  <tr>
   <td><p style="text-align:left;margin-bottom:2px">
    <strong>'.$admin182.'</strong>&nbsp;: <img src="inc/img/files/directory.gif" alt="'.$admin182.'" style="vertical-align:middle;" /> '.'
    <select style="font-weight:bold;" name="rep" onchange="document.changedir.submit();">';
sort($list_rep);
for($i=0; $i<count($list_rep); $i++){
    echo '
     <option value="'.$list_rep[$i].'"'.($list_rep[$i] == $rep ? " selected=\"selected\"" : "").">".$list_rep[$i]."</option>";
}
echo '
    </select>';
    if ($candel) {
        echo '<a href="admin.php?lng='.$lng.'&amp;pg=upload&amp;delrep='.$rep.'" title="'.$web53.' '.$rep.'"> <img src="'.CHEMIN.'admin/inc/img/files/delete.gif" title="'.$web53.' '.$rep.'" alt="'.$web53.' '.$rep.'" style="vertical-align:middle; border-style:none;padding-left:30px;" /></a>';
    }
    echo '
    </p>';
if (!empty($msg)) {
    echo '
<p style="text-align:center;">'.$msg.'</p>';
}
echo '
    <p style="text-align:left; margin-top:2px; padding-left:76px;">
    <img src="'.CHEMIN.'inc/img/general/pluspg.gif" title="" alt="" /><img src="inc/img/files/directory.gif" style="vertical-align:middle;" title="'.$admin182.'" alt="'.$admin182.'" />
    <input type="text" name="newrep" value="'.$newrep.'" size="25" />
    <input type="submit" value="'.$web371.strtolower($admin182) .'" /></p>
   </td>
  </tr>
 </table>
</form>
<hr />
<table cellspacing="0" cellpadding="0" border="0" width="80%" style="margin:auto;" summary="">
 <tr>
  <td style="width:10%"></td>
  <td style="width:50%"><p><strong>'.$admin184.'</strong></p></td>
  <td style="width:"20%"><p align="center"><strong>'.$admin185.'</strong></p></td>
  <td style="width:20%"><p align="center"><strong>'.$admin186.'</strong></p></td>
 </tr>';
for ($i = 0; $i < count($dbfiles); $i++) {
    echo '
 <tr>
  <td><p align="center"><img src="'.$dbfiles[$i][1].'" width="17" height="17" title="" alt="" /></p></td>
  <td><p><a href="'.CHEMIN.$rep."/".$dbfiles[$i][0].'" target="_blank">'.$dbfiles[$i][0].'</a></p></td>
  <td><p align="center">'.$dbfiles[$i][2].' '.$web28.'</p></td>
  <td><p align="center"><a href="admin.php?lng='.$lng.'&amp;pg=upload&amp;rep='.$rep.'&amp;del='.$dbfiles[$i][0].'" title="'.$admin187.'"><img src="inc/img/files/delete.gif" border="0" width="43" height="19" title="'.$admin187.'" alt="'.$admin187.'" /></a></p></td>
 </tr>';
}
echo '
</table>
<hr />
<form name="uploadit" enctype="multipart/form-data" action="admin.php?lng='.$lng.'" method="post">
 <input type="hidden" name="pg" value="upload" />
 <input type="hidden" name="rep" value="'.$rep.'" />
 <p align="center"><img src="inc/img/files/upload.gif" width="17" height="17" alt="'.$admin188.'"/><strong>'.$admin188.'</strong></p>
 <p>&nbsp;</p>
 <p align="center"><input class="texte" type="file" name="ficup" size="36" /></p>
 <p align="center">'.$boutonleft.'<button type="submit" name="OK" title="'.$admin189.'">'.$admin189.'</button>'.$boutonright.'</p>
</form>
<hr />
<p align="center"><a href="admin.php?lng='.$lng.'">'.$admin22.'</a> || <strong><a href="admin.php?lng='.$lng.'&amp;logout=1">'.$admin19.'</a></strong></p>

';
btable();
include(CHEMIN."inc/bpage.inc");
