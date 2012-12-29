<?php
/*
    Links - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2008 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.7 (28 January 2003)   : added category ordering information
      v2.2 (22 April 2003)     : option for choosing the number of items to display in news, forum threads, links, downloads, FAQ and Guestbook
                                 cleanup in the images organization
      v2.3 (27 July 2003)      : added direct jump to pages (by Nicolas Alves and Laurent Duveau)
      v2.4 (24 September 2003) : added section icon in central boxes
                                 added ReadDoc() function
                                 reviewed all Files Read & Write functions
                                 secured transfered parameters
                                 created $typ_[name] variables
      v4.0 (06 December 2004)  : added page title (by Jean-Mi)
                                 added alt tags to img and removed border tag for non-linked img (by Isa)
                                 added new appearance with td style (by Icare)
                                 added new navigation and optionnal quick admin (by Nicolas Alves)
      v4.5 (13 March 2005)     : new release (by Nico and Icare)
                                 replacing navigation bar (by Jean-Mi)
                                 added close button and correct closing div (by Icare)
      v4.6.0 (04 June 2007)    : added accessibility without javascript, better support for $lng[1] (by Djchouix)
      v4.6.3 (30 August 2007)  : corrected lang items for alt and title (by Icare)
      v4.6.6 (14 April 2008)   : deleted clear: both (by Icare)
                                 deleted </p> in quick admin icons (by JeanMi)
                                 added header("HTTP/1.0 404 Not found") in the event of pages not found (by JeanMi, thanks eDada)
      v4.6.15 (30 June 2011) : added links private management (by Icare)
      v4.6.17 (21 October 2011) :  added hyperlink (by Laroche)	 	  
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");

if ($serviz[11] != "on") {
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

if (!empty($pg)) {
  if (count(SelectDBFields(TYP_LINKS,"a",$pg)) != 0) {
    $dbwork[0][4] = $pg;
  }
  else {
    $dbwork = array();
    header('HTTP/1.0 404 Not Found');
    $web38 = '';
  }
} else {
  $dbwork2 = ReadDBFields(DBLINKS);
  $dbwork = array_filter($dbwork2, 'IsNotEmptyTitle');
  unset($dbwork2);
}
sort($dbwork);

$i = ($lng == $lang[0])? 0 : 10 ;

$topmess = strip_tags($nom[$i+3]);
if ($page[9] != "") {
  $topmess = "<img src=\"".CHEMIN."inc/img/icons/".$page[9]."/links.gif\" align=\"right\" width=\"32\" height=\"32\" alt=\"links.gif\" />".$topmess;
}
include("inc/hpage.inc");
htable($topmess, "100%");

if ($members[0]=="on" && $userprefs[1]=="" && $members[3]=="on") {
  echo '<p style="text-align:center;margin:20px 0px 0px;">'.$web342.'</p>';
  echo '<p style="text-align:center;margin:15px 0px 20px;">[&nbsp;<a href="'.CHEMIN.'user.php?lng='.$lng.'">'.$web343.'</a>&nbsp;]</p>';
} else {
	echo '<p style="text-align:center;">'.$web38.'</p>';
  if (empty($id)) $id = 1;
  if (!empty($dbwork)) {
		$typeRubrique = TYP_LINKS;
		$imgOpen = "plumenu.gif";
		$imgClose = "moinsmenu.gif";
		$subImgOpen = "puce1.gif";
		$subImgClose = "puce2.gif";
		$nlpg = (count($dbwork)-($serviz[5]*($id-1))>$serviz[5])? $serviz[5] : count($dbwork)-($serviz[5]*($id-1)) ;
?>
   	<script type="text/javascript">
   		var maxsub = <?php echo $nlpg; ?>;
   	</script>
<?php
   	$rubr = "";
   	$l = 0;
   	for ($i = $serviz[5]*($id-1); $i < Min($serviz[5]*$id, count($dbwork)); $i++) {
   		ReadDoc(DBBASE.$dbwork[$i][4]);
   		if ($lng == $lang[0]) {
     		$txt1 = $fieldb1;
     		$txt2 = $fieldc1;
     		$txt3 = $fielda1;
     		$txt4 = $fieldd1;
   		} else {
     		$txt1 = $fieldb2;
     		$txt2 = $fieldc2;
     		$txt3 = $fielda2;
     		$txt4 = $fieldd2;
   		}
   		$txt5 = $fieldmod;
   		/// début modif accès réservé
      $acces = "ok";
      if ($txt5 != "") {
        $acces = "no";
        if ($userprefs[1] != "") {
          include_once (CHEMIN.'inc/func_groups.php');
          if (CheckGroup($txt5, $userprefs[1])) $acces ="ok";
        }
      }
      if ($acces == "ok") {
      /// fin modif accès réservé
   		if ($rubr <> $txt3) {
     		$rubr = $txt3;
				if ($l > 0) echo '</div>';
     		if (trim($rubr) != "") {
					$l ++;
					echo '<p id="titreRubr'.$typeRubrique.$i.'" class="rubr" style="cursor:pointer" onclick="MontreCacheItems(\'imgOpen'.$typeRubrique.$i.'\',\'imgClose'.$typeRubrique.$i.'\',\'itemsRubr'.$typeRubrique.$i.'\',\'itemsRubrSelect\');">'."\n";
					echo '<img id="imgOpen'.$typeRubrique.$i.'" src="'.CHEMIN.'inc/img/general/'.$imgOpen.'" border="0" alt="'.$web429.'" title="'.$web429.'" style="display:none;" /> ';
					echo '<img id="imgClose'.$typeRubrique.$i.'" src="'.CHEMIN.'inc/img/general/'.$imgClose.'" border="0" alt="'.$web57.'" title="'.$web57.'" style="display:inline;" /> ';
					echo '<span>'.$rubr.'</span>';
					echo '</p>'."\n";
					if (count($dbwork) == 1) {
						echo '<div id="itemsRubrSelect" style="display:block;">'."\n";
					} else {
						echo '<div id="itemsRubr'.$typeRubrique.$i.'" style="display:block;">'."\n";
				  }
        }
      }
			$n = (count($dbwork) > $serviz[5])? $i-$serviz[5]*$id+$serviz[5] : $i ;
			echo '<div id="titreSubRubr'.$typeRubrique.$i.'" class="rubr" style="cursor:pointer;" onclick="MontreCacheItems(\'subImgOpen'.$typeRubrique.$i.'\',\'subImgClose'.$typeRubrique.$i.'\',\'itemSubRubr'.$typeRubrique.$i.'\',\'itemSubRubrSelect\');">'."\n";
			echo '<div style="float:left;text-align:right;margin-left:20px !important; margin-left:10px; height:15px;">';
			echo '<img id="subImgOpen'.$typeRubrique.$i.'" src="'.CHEMIN.'inc/img/general/'.$subImgOpen.'" border="0" alt="'.$web429.'" title="'.$web429.'" style="display:none;margin-top:3px;" /> ';
			echo '<img id="subImgClose'.$typeRubrique.$i.'" src="'.CHEMIN.'inc/img/general/'.$subImgClose.'" border="0" alt="'.$web57.'" title="'.$web57.'" style="display:inline;margin-top:5px;" /> ';
			echo '</div>'."\n";
			echo '<div style="text-align:justify;padding-left:35px;"><a name="subRubr'.$typeRubrique.$i.'">'.$txt1.'</a></div>'."\n";
			echo '</div>'."\n";
			if (count($dbwork) == 1) {
				echo '<div class="bord2" id="itemSubRubrSelect" style="display:block;">'."\n";
			} else {
				echo '<div class="bord2" id="itemSubRubr'.$typeRubrique.$i.'" style="display:block;">'."\n";
			}
			echo '<div class="rep" style="margin:5px">'."\n";
			echo $txt2;
			echo '<p style="text-align:right;cursor:pointer;">';
			echo '<a href="links.php?lng='.$lng.'&amp;pg='.$dbwork[$i][4].'"><img src="'.CHEMIN.'inc/img/general/hyperlink.gif" border="0" alt="'.$web462.'" title="'.$web462.'" /></a>&nbsp;&nbsp;';
			echo '<a href="'.$txt4.'" target="_blank"><img src="'.CHEMIN.'inc/img/general/site.gif" border="0" alt="'.$web304.'" title="'.$web304.'" /></a>';
			echo '</p>'."\n";
			echo '</div>'."\n";
   		if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $drtuser[20]=="on")) {
				echo '<div align="right" style="cursor:pointer;">';
?>
   			<a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=links&amp;form=2&amp;id=<?php echo $dbwork[$i][4]; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/edit.gif" border="0" alt="<?php echo $web308; ?>" title="<?php echo $web308; ?>" /></a>
   			<a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=links&amp;act=i&amp;id=<?php echo $dbwork[$i][4]; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/desact.gif" border="0" alt="<?php echo $web333; ?>" title="<?php echo $web333; ?>" /></a>
   			<a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=links&amp;del=<?php echo $dbwork[$i][4]; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/del.gif" border="0" alt="<?php echo $web324; ?>" title="<?php echo $web324; ?>" /></a>
<?php
				echo '</div>'."\n";
   		}
			echo '</div>'."\n";
			} /// fin accès réservé
   	}
   	if ($l > 0) echo '</div>'."\n";
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
				if((document.getElementById && document.getElementById('itemSubRubr'+ typeRubr + i) != null) || (document.all && document.all['itemSubRubr'+ typeRubr + i] != undefined ) || (document.layers && document.layers['itemSubRubr'+ typeRubr + i] != undefined) ) {
					cache('itemSubRubr'+ typeRubr + i);
					montre('subImgOpen'+ typeRubr + i,'inline');
					cache('subImgClose'+ typeRubr + i);
				}
			}
		//-->
		//]]>
		</script>
<?php
 	} else if (!empty($pg)) {
        echo '<p>'.$web36.'</p>';
    }
  echo GetNavBar("links.php?lng=".$lng."&amp;pg=".$pg."&amp;id=", count($dbwork), $id, $serviz[5]);
}
btable();
include("inc/bpage.inc");
?>
