<?php
/*
    Photorama - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v2.0 (27 February 2003)    : initial release
      v2.4 (24 September 2003)   : added section icon in central boxes
                                   added ReadDoc() function
                                   reviewed all Files Read & Write functions
                                   secured transfered parameters
                                   created $typ_[name] variables
      v4.0 (06 December 2004)    : added page title (by Jean-Mi)
                                   added alt tags to img and removed border tag for non-linked img (by Isa)
                                   added members management (by Nicolas Alves)
      v4.5 (15 April 2005)       : new complete release (by Icare)
      v4.5.1 (06 July 2005)      : bug fix in collapsed categories list (by Icare)
      v4.5.11 (28 December 2005) : new display management (by Icare)
      v4.6.0 (04 June 2007)      : new release by Icare
                                   accessibility optimization if javascript disabled (by Djchouix)
                                   corrected empty items in bi-lingual site if 2nd language empty, thanks slls (by Icare)
      v4.6.3 (30 August 2007)    : corrected lang items for alt and title (by Icare)
      v4.6.6 (6 January 2008)    : added cursor:pointer (by Icare)
                                   added header("HTTP/1.0 404 Not found") in the event of pages not found (by JeanMi, thanks eDada)
      v4.6.10 (7 September 2009)    : corrected #274
      v4.6.15 (30 June 2011): added private management for photos (by Icare)
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");
if ($serviz[9] != "on") {
  exit($web143);
}
$pg = strip_tags($pg);
$id = strip_tags($id);
if (!empty($pg) && !is_numeric($pg)) die('Erreur dans la variable $pg');
if (!empty($id) && !is_numeric($id)) die('Erreur dans la variable $id');

function IsNotEmptyTitle($var) {
  global $lng, $lang;
  return $lng == $lang[0] ? !empty($var[2]) : !empty($var[3]);
}

$dbwork = array();
if (!empty($pg)) {
  if (count(SelectDBFields(TYP_PHOTO,"a",$pg)) != 0) {
    $dbwork[0][4] = $pg;
  }
  else {
    $dbwork = array();
    header('HTTP/1.0 404 Not Found');
  }
} else {
  $dbwork2 = ReadDBFields(DBPHOTO);
  $dbwork = array_filter($dbwork2, 'IsNotEmptyTitle');
  unset($dbwork2);
}

sort($dbwork);
$i = ($lng == $lang[0])? 0 : 10;
$topmess = strip_tags($nom[$i+2]);
if ($page[9] != "") {
  $topmess = "<img src=\"".CHEMIN."inc/img/icons/".$page[9]."/photo.gif\" align=\"right\" width=\"32\" height=\"32\" alt=\"photo.gif\"/>".$topmess;
}
include("inc/hpage.inc");
htable($topmess, "100%");
echo "<br />";
if ($members[0]=="on" && $userprefs[1]=="" && $members[2]=="on") {
    echo "<p align=\"center\">".$web342."</p><br />";
    echo "<p align=\"center\">[ <a href=\"".CHEMIN."user.php?lng=".$lng."\">".$web343."</a> ]</p><br />";
} else {
 	if (empty($id)) $id = 1;
  if (!empty($dbwork)) {
		$typeRubrique = TYP_PHOTO;
   	$nbfoto=count($dbwork);
		$imgOpen = "plusfaq.gif";
		$imgClose = "moinsfaq.gif";
   	$rubr = "&lfloor;";
		$l = 0;
   	for ($i = 0; $i < count($dbwork); $i++) {
   		ReadDoc(DBBASE.$dbwork[$i][4]);
   		if ($lng == $lang[0]) {
     		$foto1 = $fieldb1;
     		$foto2 = $fieldc1;
     		$foto3 = $fielda1;
   		} else {
     		$foto1 = $fieldb2;
     		$foto2 = $fieldc2;
     		$foto3 = $fielda2;
   		}
   		/// début modif accès réservé
   		$foto6 = $fieldmod;
   		$acces = "ok";
   		if ($foto6 != "") {
        $acces = "no";
        if ($userprefs[1] != "") {
          include_once (CHEMIN.'inc/func_groups.php');
          if (CheckGroup($foto6, $userprefs[1])) $acces ="ok";
        }
      }
      if ($acces == "no") { // pas d'affichage
        $txt1 = "";
        $txt2 = "<p align='center'><br><br>".$web444."<br /><br /></p>\n";
        $fieldd1 = "trans.gif";
      } else {
      /// fin modif accès réservé
   		$foto4 = $fieldd1;
   		$foto5 = getimagesize(CHEMIN."photo/".$fieldd1);
   		$popw = $foto5[0]+28; //width popup
     	$poph = $foto5[1]+72; //height popup
     	if ($foto5[0] < $foto5[1]) $dia ="height"; else $dia="width";
   		if ($rubr <> $foto3) {
     		$rubr = $foto3;
     		if ($l > 0) echo '</div></div><br /><hr />';
				$l ++;
     		if (trim($rubr) != "") {
					echo '<p id="titreRubr'.$typeRubrique.$i.'" class="rubr" style="text-align:left;cursor:pointer" onclick="MontreCacheItems(\'imgOpen'.$typeRubrique.$i.'\',\'imgClose'.$typeRubrique.$i.'\',\'itemsRubr'.$typeRubrique.$i.'\',\'itemsRubrSelect\');">'."\n";
					echo '<img id="imgOpen'.$typeRubrique.$i.'" src="'.CHEMIN.'inc/img/general/'.$imgOpen.'" border="0" alt="'.$web429.'" title="'.$web429.'" style="display:none;" />&nbsp;';
					echo '<img id="imgClose'.$typeRubrique.$i.'" src="'.CHEMIN.'inc/img/general/'.$imgClose.'" border="0" alt="'.$web57.'" title="'.$web57.'" style="display:inline;" />&nbsp;';
					echo '<span>'.$rubr.'</span>';
					echo '</p>'."\n";
					echo '<div style="text-align:center;">'."\n";
					if (count($dbwork) == 1) {
						echo '<div id="itemsRubrSelect" class="forum2" style="width:320px;height:272px;display:block;margin-right:auto;margin-left:auto;overflow:auto;background-image:url('.CHEMIN.'inc/img/general/film.gif);background-repeat:repeat-y;">';
					} else {
						echo '<div id="itemsRubr'.$typeRubrique.$i.'" class="forum2" style="width:320px;height:272px;display:block;margin-right:auto;margin-left:auto;overflow:auto;background-image:url('.CHEMIN.'inc/img/general/film.gif);background-repeat:repeat-y;">';
					}
     		} else {
					echo '<div style="text-align:center;">';
					echo '<div class="forum2" style="width:320px;height:272px;display:block;margin-right:auto;margin-left:auto;overflow:auto;background-image:url('.CHEMIN.'inc/img/general/film.gif);background-repeat:repeat-y;">';
        }
     	}
?>
     	<table align="center" style="margin-right:auto;margin-left:auto;margin-top:12px;" summary="">
     	<tr><td  class="rep" style="height:200px;width:200px;text-align:center;vertical-align:middle;">
     	<a href="photoview.php?lng=<?php echo $lng; ?>&amp;pg=<?php echo $dbwork[$i][4]; ?>" onclick="javascript:PopupWindow('photoview.php?lng=<?php echo $lng; ?>&amp;pg=<?php echo $dbwork[$i][4]; ?>','Photo',<?php echo $popw; ?>,<?php echo $poph; ?>,'no','no');return false;" target="_blank" title="<?php echo $web297; ?>">
     	<img src="<?php echo CHEMIN; ?>photo/<?php echo $fieldd1; ?>" <?php echo $dia; ?>="150" border="0" style="vertical-align:middle" alt="<?php echo $web297; ?>" title="<?php echo $web297; ?>" /></a>
     	</td></tr></table>
     	<table align="center" style="margin-right:auto;margin-left:auto;margin-top:2px;" summary="">
     	<tr><td class="rep" style="width:200px;font-size: 11px;text-align:center;"><b>&nbsp;<?php echo $foto1; ?>&nbsp;</b></td></tr>
<?php
   		if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $drtuser[18]=="on")) {
?>
     		<tr><td nowrap style="cursor:pointer;text-align:right">
     		<a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=photo&amp;form=2&amp;id=<?php echo $dbwork[$i][4]; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/edit.gif" border="0" alt="<?php echo $web308; ?>" title="<?php echo $web308; ?>"/></a>
     		<a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=photo&amp;act=i&amp;id=<?php echo $dbwork[$i][4]; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/desact.gif" border="0" alt="<?php echo $web333; ?>" title="<?php echo $web333; ?>"/></a>
     		<a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=photo&amp;del=<?php echo $dbwork[$i][4]; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/del.gif" border="0" alt="<?php echo $web324; ?>" title="<?php echo $web324; ?>"/></a>
     		</td></tr>
<?php
   		}
   		echo '</table><br />'."\n";
   	} /// fin accès réservé
   	}
   	echo '</div></div>'."\n";
?>
		<script type="text/javascript">
		//<![CDATA[
		<!--
			var nbRubr = <?php echo ($i); ?>;
			var typeRubr = '<?php echo $typeRubrique; ?>';
			for(i = 0; i < nbRubr; i++) {
				if((document.getElementById && document.getElementById('itemsRubr'+ typeRubr + i) != null) || (document.all && document.all['itemsRubr'+ typeRubr + i] != undefined ) || (document.layers && document.layers['itemsRubr'+ typeRubr + i] != undefined) ) {
					cache('itemsRubr'+ typeRubr + i);
					montre('imgOpen'+ typeRubr + i,'inline');
					cache('imgClose'+ typeRubr + i);
				}
			}
		//-->
		//]]>
		</script>
<?php
  } else if (!empty($pg)) {
    echo '<p>'.$web36.'</p>';
  }
}
btable();
include("inc/bpage.inc");
?>
