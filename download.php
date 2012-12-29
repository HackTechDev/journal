<?php
/*
    Download - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v1.0 (30 December 2002)     : initial release
      v1.7 (28 January 2003)      : added category ordering information
      v2.2 (22 April 2003)        : option for choosing the number of items to display in news, forum threads, links, downloads, FAQ and Guestbook
                                    cleanup in the images organization
      v2.3 (27 July 2003)         : added direct jump to pages (by Nicolas Alves and Laurent Duveau)
      v2.4 (24 September 2003)    : added section icon in central boxes
                                    added number of times a file was downloaded (by Nicolas Alves and Laurent Duveau)
                                    added ReadDoc() function
                                    added ReadDocCounter(), WriteDocCounter() and UpdateDocCounter() functions
                                    reviewed all Files Read & Write functions
                                    secured transfered parameters
                                    created $typ_[name] variables
      v4.0 (06 December 2004)     : added page title
                                    added openning pdf files (by Jean-Mi)
                                    added alt tags to img and removed border tag for non-linked img (by Isa)
                                    new look by adding td classes (by Icare)
                                    added optionnal quick admin (by Nicolas Alves)
      v4.5 (22 March 2005)        : new complete release (by Nicolas Alves)
                                    replacing navigation bar (by Jean-Mi)
                                    added close button and correct closing div (by Icare)
      v4.6.0 (04 June 2007)       : added accessibility without javascript, better support for $lng[1] (by Djchouix)
                                    corrected file size counter(by JeanMi)
                                    corrected Quick Admin delete item id (by Hpsam)
                                    corrected empty items in bi-lingual site if 2nd language empty, thanks slls (by Icare)
      v4.6.3 (30 August 2007)     : corrected lang items for alt and title,
                                    corrected 2nd language  (by Icare)
      v4.6.4 (30 September 2007)  : changed octets by string (thanks mannes)
      v4.6.6 (6 January 2008)     : corrected file characteristics description and bad initialization of $txt5,
                                    download now available without javascript (by Icare)
                                    added header("HTTP/1.0 404 Not found") in the event of pages not found (by JeanMi, thanks eDada)
      v4.6.8 (24 May 2008)        : changed links for dwnld.php (by jchouix)
      v4.6.10 (7 September 2009)  : corrected #272
      v4.6.11 (11 December 2009)  : corrected bad display of licence if only one language
      v4.6.15 (30 June 2011)      : added private management of download (by Icare)
      v4.6.16 (02 September 2011) : corrected private management of download (by Laroche)
      v4.6.17 (26 October 2011)   : added call dwnl_pr.php (by Laroche)
	                                added hyperlink (by Laroche)
				                    corrected display lang for download
      v4.6.18 (09 February 2012)  : corrected private management of download (by Laroche)
	  v4.6.22 (29 December 2012)  : corrected link and hyperlink (thanks JeanMi)
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");
include_once (CHEMIN.'inc/func_groups.php'); // déplacé
if ($serviz[10] != "on") {
  exit($web143);
}

$pg = strip_tags($pg);
if (!empty($pg) && !is_numeric($pg)) {
    die('STOP ! Variable $pg : illegal value ('.$pg.')');
}

$id = strip_tags($id);
if (!empty($id) && !is_numeric($id)) {
    die('STOP ! Variable $id : illegal value ('.$id.')');
}

function IsNotEmptyTitle($var) {
  global $lng, $lang;
  return $lng == $lang[0] ? !empty($var[2]) : !empty($var[3]);
}

$dbwork = array();
if (!empty($pg)) {
  if (count(SelectDBFields(TYP_DNLOAD,"a",$pg)) != 0) {
    $dbwork[0][4] = $pg;
  }
  else {
    $dbwork = array();
    header('HTTP/1.0 404 Not Found');
    $web38 = '';
  }
} else {
  $dbwork2 = ReadDBFields(DBDNLOAD);
  $dbwork = array_filter($dbwork2, 'IsNotEmptyTitle');
  unset($dbwork2);
}
sort($dbwork);

// début - compter et mémoriser les fichiers autorisés >>>>
$dbwork_allowed = array();
$ii = 0;
for($i = 0; $i < count($dbwork); $i++) {
   	ReadDoc(DBBASE.$dbwork[$i][4]);	
	if($fieldmod == '' || CheckGroup($fieldmod, $userprefs[1])) {
		$dbwork_allowed[] = $dbwork[$i];
    $dbwork_allowed[$ii][5] = $fieldmod;
    $ii++;
	}
}
// fin - compter et mémoriser les fichiers autorisés <<<<<
$i = ($lng == $lang[0])? 0 : 10 ;
$topmess = strip_tags($nom[$i+1]);
if ($page[9] != "") {
  	$topmess = '<img src="'.CHEMIN.'inc/img/icons/'.$page[9].'/download.gif" align="right" width="32" height="32" border="0" alt="download" title="download" />'.$topmess;
}
include("inc/hpage.inc");
htable($topmess, "100%");
if ($members[0]=="on" && $userprefs[1]=="" && $members[7]=="on") {
  echo '<p style="text-align:center;margin:20px 0px 0px;">'.$web342.'</p>';
  echo '<p style="text-align:center;margin:15px 0px 20px;">[&nbsp;<a href="'.CHEMIN.'user.php?lng='.$lng.'">'.$web343.'</a>&nbsp;]</p>';
} else {
	echo '<div style="text-align:center;">'.$web38.'</div>';
 	if (empty($id)) {
    $id = 1;
  }
 	if (!empty($dbwork_allowed)) { 
	  $typeRubrique = TYP_DNLOAD;
	  $imgOpen = "dl.gif";
	  $imgClose = "dl1.gif";
	  $subImgOpen = "puce1.gif";
	  $subImgClose = "puce2.gif";
    $fondmenu = "#FFFFFF";
    $bordmenu = "orange";
	  $mawmenu = (count($dbwork_allowed)-($serviz[4]*($id-1))>$serviz[4])? $serviz[4] : count($dbwork_allowed)-($serviz[4]*($id-1)) ;
    echo '
<script type="text/javascript">
var maxsub = '.$mawmenu.';
</script>';
   	$rubr = "";
   	$l = 0;
   	for ($i = $serviz[4]*($id-1); $i < Min($serviz[4]*$id, count($dbwork_allowed)); $i++) {
     	ReadDoc(DBBASE.$dbwork_allowed[$i][4]);
     	if ($lng == $lang[0]) {
       	$txt1 = $fieldb1;
       	$txt2 = $fieldc1;
       	$txt3 = $fielda1;
       	$file = $fieldd1;
     	} else {
       	$txt1 = $fieldb2;
       	$txt2 = $fieldc2;
       	$txt3 = $fielda2;
       	$file = $fieldd2;
       	if (preg_match("!^[/.]!", $fieldd2)) $file =  $fieldd1; // compatibility 4.6.2
   		}
   		$txt5 = ""; $licence = "";
   		if ($fieldweb != "") $licence = $fieldweb;
     	elseif (!preg_match("![/.]!", $fieldd2)) $licence = $fieldd2;// compatibility 4.6.2
     	if ($licence != "") $txt5 = "&amp;li=".$licence;
      $txtcount = "";
      if ($serviz[35] == "on") {
       	$downcounter  = ReadDocCounter(DBBASE.$dbwork_allowed[$i][4]);
			  $txtcount = ($downcounter <= 1)? $web188 : $web189 ;
      }
      if (preg_match('!^(http|ftp)!i',$file)) {
        $size = @filesize($file);
        if ($size === false) {
          $txt4 = '???';
        } else {
          $txt4 = (($lng == 'fr')? number_format($size/1000,2,',',' ') : number_format($size/1000,2,'.',' '));
        }
	  	} else {
	  	  $txt4 = (($lng == 'fr')? number_format(@filesize(CHEMIN.$file)/1000,2,',',' ') : number_format(@filesize(CHEMIN.$file)/1000,2,'.',' '));
	  	}
      if ($rubr != $txt3) {
       	$rubr = $txt3;
       	if ($l > 0) {
          echo '</div>';
        }
       	if (trim($rubr) != "") {
       		$l++;
          echo '<p id="titreRubr'.$typeRubrique.$i.'" class="rubr" style="cursor:pointer" onclick="MontreCacheItems(\'imgOpen'.$typeRubrique.$i.'\',\'imgClose'.$typeRubrique.$i.'\',\'itemsRubr'.$typeRubrique.$i.'\',\'itemsRubrSelect\');">'."\n";
			    echo '<img id="imgOpen'.$typeRubrique.$i.'" src="'.CHEMIN.'inc/img/general/'.$imgOpen.'" border="0" alt="'.$web429.'" title="'.$web429.'" style="display:none;" /> ';
			    echo '<img id="imgClose'.$typeRubrique.$i.'" src="'.CHEMIN.'inc/img/general/'.$imgClose.'" border="0" alt="'.$web57.'" title="'.$web57.'" style="display:inline;" /> ';
			    echo '<span>'.$rubr.'</span>';
			    echo '</p>'."\n";
			    if (count($dbwork_allowed) == 1) {
				    echo '<div id="itemsRubrSelect" style="display:block;">'."\n";
			    } else {
				    echo '<div id="itemsRubr'.$typeRubrique.$i.'" style="display:block;">'."\n";
			    }
       	}
      }
			$n = (count($dbwork_allowed)>$serviz[4])? $i-$serviz[4]*$id+$serviz[4] : $i ;
    	echo '<div id="titreSubRubr'.$typeRubrique.$i.'" class="rubr" style="cursor:pointer;" onclick="MontreCacheItems(\'subImgOpen'.$typeRubrique.$i.'\',\'subImgClose'.$typeRubrique.$i.'\',\'itemSubRubr'.$typeRubrique.$i.'\',\'itemSubRubrSelect\');">'."\n";
		  echo '<div style="float:left;text-align:right;margin-left:20px !important; margin-left:10px; height:15px;">';
			echo '<img id="subImgOpen'.$typeRubrique.$i.'" src="'.CHEMIN.'inc/img/general/'.$subImgOpen.'" border="0" alt="'.$web429.'" title="'.$web429.'" style="display:none;margin-top:3px;" /> ';
			echo '<img id="subImgClose'.$typeRubrique.$i.'" src="'.CHEMIN.'inc/img/general/'.$subImgClose.'" border="0" alt="'.$web57.'" title="'.$web57.'" style="display:inline;margin-top:5px;" /> ';
			echo '</div>';
			echo '<div style="text-align:justify;padding-left:35px;"><a name="subRubr'.$typeRubrique.$i.'">'.$txt1.'</a></div>';
			echo '</div>'."\n";
			echo '<div style="clear:both;"></div>';
			if (count($dbwork_allowed) == 1) {
			  echo '<div class="bord2" id="itemSubRubrSelect" style="display:block;">'."\n";
			} else {
			echo '<div class="bord2" id="itemSubRubr'.$typeRubrique.$i.'" style="display:block;">'."\n";
			}
			echo '<div class="rep" style="margin:5px">'."\n";
			echo $txt2;
			echo '<hr />';
			echo '<p style="font-size: 11px;">';
			echo basename($file).'<span style="margin:0px 20px;">('.$txt4.' '.$web28.')</span>';
      if ($dbwork_allowed[$i][5] != '') { // Téléchargement groupe privé 
          echo $web191.'&nbsp;'.$downcounter.'&nbsp;'.$txtcount;
          echo '<a href="dwnld_pr.php?lng='.$lng.'&amp;pg='.$dbwork_allowed[$i][4].'" target="_blank">';      
          echo '<img src="'.CHEMIN.'inc/img/general/download.gif" style="margin:0px 15px;" border="0" alt="'.$web362.'" title="'.$web362.'" /></a>';
          } else { 
        if ( in_array( strrchr($file, '.'), array('.php', '.inc', '.css', '.htm', '.html', '.pdf', '.txt') ) ) {
          echo $web191.'&nbsp;'.$downcounter.'&nbsp;'.$txtcount;
          echo '<a onclick="PopupWindow(\'dwnld.php?lng='.$lng.'&amp;delay=0&amp;pg='.$dbwork_allowed[$i][4].'\',\'dnload\',800,600,\'yes\',\'yes\');return false" title="'.$web362.'" style="margin:0px 15px;" href="dwnld.php?lng='.$lng.'&amp;delay=0&amp;pg='.$dbwork[$i][4].'" target="_blank">';        
        } else {
          echo $web191.'&nbsp;'.$downcounter.'&nbsp;'.$txtcount;
          echo '<a onclick="PopupWindow(\'dwnld.php?lng='.$lng.'&amp;pg='.$dbwork_allowed[$i][4].$txt5.'\',\'dnload\',540,340,\'no\',\'no\');return false" title="'.$web362.'" style="margin:0px 15px;" href="dwnld.php?lng='.$lng.'&amp;pg='.$dbwork[$i][4].$txt5.'" target="_blank">';
        }
        echo '<img src="'.CHEMIN.'inc/img/general/download.gif" border="0" alt="'.$web362.'" title="'.$web362.'" /></a>';
        }
        echo '<a href="'.CHEMIN.'download.php?lng='.$lng.'&amp;pg='.$dbwork[$i][4].'"><img src="'.CHEMIN.'inc/img/general/hyperlink.gif" border="0" alt="'.$web462.'" title="'.$web462.'" /></a> ';
        echo '</p>'."\n";
        echo '</div>'."\n";
        
      if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $drtuser[19]=="on")) {
        echo '<div align="right" style="cursor:pointer;">';
        echo ' <a href="'.CHEMIN.'admin/admin.php?lng='.$lng.'&amp;pg=dnload&amp;form=2&amp;id='.$dbwork_allowed[$i][4].'"><img src="'.CHEMIN.'inc/img/general/edit.gif" border="0" alt="'.$web308.'" title="'.$web308.'" /></a>';
       	echo ' <a href="'.CHEMIN.'admin/admin.php?lng='.$lng.'&amp;pg=dnload&amp;act=i&amp;id='.$dbwork_allowed[$i][4].'"><img src="'.CHEMIN.'inc/img/general/desact.gif" border="0" alt="'.$web333.'" title="'.$web333.'" /></a>';
       	echo ' <a href="'.CHEMIN.'admin/admin.php?lng='.$lng.'&amp;pg=dnload&amp;del='.$dbwork_allowed[$i][4].'"><img src="'.CHEMIN.'inc/img/general/del.gif" border="0" alt="'.$web324.'" title="'.$web324.'" /></a>';
			  echo '</div>'."\n";
       }
      echo '</div>'."\n";
    }
    if ($l > 0) {
      echo '</div>'."\n";
    }
    echo '
<script type="text/javascript">
//<![CDATA[
<!--
	var nbRubr = '.$i.';
	var typeRubr = \''.$typeRubrique.'\';
	for(i = 0; i < nbRubr; i++) {
		if((document.getElementById && document.getElementById(\'itemsRubr\'+ typeRubr + i) != null) || (document.all && document.all[\'itemsRubr\'+ typeRubr + i] != undefined ) || (document.layers && document.layers[\'itemsRubr\'+ typeRubr + i] != undefined) ) {
			cache(\'itemsRubr\'+ typeRubr + i);
			montre(\'imgOpen\'+ typeRubr + i,\'inline\');
			cache(\'imgClose\'+ typeRubr + i);
		}
		if((document.getElementById && document.getElementById(\'itemSubRubr\'+ typeRubr + i) != null) || (document.all && document.all[\'itemSubRubr\'+ typeRubr + i] != undefined ) || (document.layers && document.layers[\'itemSubRubr\'+ typeRubr + i] != undefined) ) {
			cache(\'itemSubRubr\'+ typeRubr + i);
			montre(\'subImgOpen\'+ typeRubr + i,\'inline\');
			cache(\'subImgClose\'+ typeRubr + i);
		}
	}
//-->
//]]>
</script>';
 	} else if (!empty($pg)) {
        echo '<p>'.$web36.'</p>';
    }
 	echo GetNavBar("download.php?lng=".$lng."&amp;pg=".$pg."&amp;id=", count($dbwork_allowed), $id, $serviz[4]);
}
btable();
include("inc/bpage.inc");
?>
