<?php
/*
    FAQ - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2008 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v4.5 (13 March 2005)     : new complete release (by Nicolas Alves)
                                 replacing navigation bar, exported javascript in inc/hpage.js (by Jean-Mi)
                                 added close button, correct closing div and corrected members test (by Icare)
      v4.6.0 (04 June 2007)    : added accessibility without javascript, better support for $lng[1] (by Djchouix)
                                 corrected language support for Update and create date words (by Hpsam)
      v4.6.3 (30 August 2007)  : corrected lang items for alt and title (by Icare)
      v4.6.6 (6 January 2008)  : deleted clear:both (by Icare)
                                 added header("HTTP/1.0 404 Not found") in the event of pages not found (by JeanMi, thanks eDada)
      v4.6.10 (7 September 2009)     : added #281
      v4.6.15 (30 June 2011) :  added group management (by Icare)
      v4.6.17 (21 October 2011) :  added hyperlink (by Laroche)
                                                  fixed print view (by Saxbar)	  
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");
if ($serviz[14] != "on") {
  exit($web143);
}
$pg = strip_tags($pg);
$id = strip_tags($id);
if (isset($prt)) $prt = strip_tags($prt);
if (!empty($pg) && !is_numeric($pg)) die('Erreur dans la variable $pg');
if (!empty($id) && !is_numeric($id)) die('Erreur dans la variable $id');

function IsNotEmptyTitle($var) {
  global $lng, $lang;
  return $lng == $lang[0] ? !empty($var[2]) : !empty($var[3]);
}

if (!empty($pg)) {
  if (count(SelectDBFields(TYP_FAQ,"a",$pg)) != 0) {
    $dbwork[0][4] = $pg;
  }
  else {
    $dbwork = array();
    header('HTTP/1.0 404 Not Found');
  }
} else {
  $dbwork2 = ReadDBFields(DBFAQ);
  $dbwork = array_filter($dbwork2, 'IsNotEmptyTitle');
  unset($dbwork2);
}
sort($dbwork);

$i = ($lng == $lang[0])? 0 : 1 ;
$topmess = strip_tags($nom[$i+24]);
if ($page[9] != "") {
  	$topmess = "<img src=\"".CHEMIN."inc/img/icons/".$page[9]."/faq.gif\" align=\"right\" width=\"32\" height=\"32\" alt=\"faq.gif\" />".$topmess;
}
include("inc/hpage.inc");
htable($topmess, "100%");
if ($members[0]=="on" && $userprefs[1]=="" && $members[4]=="on") {
  echo '<p style="text-align:center;margin:20px 0px 0px;">'.$web342.'</p>';
  echo '<p style="text-align:center;margin:15px 0px 20px;">[&nbsp;<a href="'.CHEMIN.'user.php?lng='.$lng.'">'.$web343.'</a>&nbsp;]</p>';
} else {
  if (empty($id)) $id = 1;
  if (!empty($dbwork)) {
		$typeRubrique = TYP_FAQ;
		$imgOpen = "plusfaq.gif";
		$imgClose = "moinsfaq.gif";
		$subImgOpen = "puce1.gif";
		$subImgClose = "puce2.gif";
		$nfaqpg = (count($dbwork)-($serviz[6]*($id-1))>$serviz[6])? $serviz[6] : count($dbwork)-($serviz[6]*($id-1)) ;
  	$rubr = "";
   	$l = 0;
   	for ($i = $serviz[6]*($id-1); $i < Min($serviz[6]*$id, count($dbwork)); $i++) {
   		ReadDoc(DBBASE.$dbwork[$i][4]);
   		if ($lng == $lang[0]) {
     		$txt1 = $fieldb1;
     		$txt2 = $fieldc1;
     		$txt3 = $fielda1;
   		} else {
     		$txt1 = $fieldb2;
     		$txt2 = $fieldc2;
     		$txt3 = $fielda2;
   		}
   		$txt4 = FormatDate($moddate);
   		$txt5 = FormatDate($creadate);
   		$txt6 = $fieldmod;
   		/// début modif accès réservé
      $acces = "ok";
      if ($txt6 != "") {
        $acces = "no";
        if ($userprefs[1] != "") {
          include_once (CHEMIN.'inc/func_groups.php');
          if (CheckGroup($txt6, $userprefs[1])) $acces ="ok";
        }
      }
      if ($acces == "ok") {
      /// fin modif accès réservé
   		if ($rubr <> $txt3 || $txt3 == "") {
     		$rubr = $txt3;
     		if ($l > 0) echo '</div>';
     		if (trim($rubr) != "") {
    			$l ++;
  				echo '<p id="titreRubr'.$typeRubrique.$i.'" class="rubr" style="cursor:pointer;" onclick="MontreCacheItems(\'imgOpen'.$typeRubrique.$i.'\',\'imgClose'.$typeRubrique.$i.'\',\'itemsRubr'.$typeRubrique.$i.'\',\'itemsRubrSelect\');">'."\n";
  				echo '<img id="imgOpen'.$typeRubrique.$i.'" src="'.CHEMIN.'inc/img/general/'.$imgOpen.'" border="0" alt="'.$web429.'" title="'.$web429.'" style="display:none;" />';
  				echo '<img id="imgClose'.$typeRubrique.$i.'" src="'.CHEMIN.'inc/img/general/'.$imgClose.'" border="0" alt="'.$web57.'" title="'.$web57.'" style="display:inline;" /> ';
  				echo '&nbsp;<span>'.$rubr.'</span>';
  				echo '</p>'."\n";
  				if (count($dbwork) == 1) {
  					echo '<div class="curr_item" id="itemsRubrSelect" style="display:block;">'."\n";
  				} else {
  					echo '<div class="item" id="itemsRubr'.$typeRubrique.$i.'" style="display:block;">'."\n";
  				}
     		}
    	}
  		$n = (count($dbwork) > $serviz[6])? $i-$serviz[6]*$id+$serviz[6] : $i ;
			echo '<div id="titreSubRubr'.$typeRubrique.$i.'" class="rubr" style="cursor:pointer;" onclick="MontreCacheItems(\'subImgOpen'.$typeRubrique.$i.'\',\'subImgClose'.$typeRubrique.$i.'\',\'itemSubRubr'.$typeRubrique.$i.'\',\'itemSubRubrSelect\');">'."\n";
			echo '<div style="float:left;text-align:right;margin-left:20px !important; margin-left:12px; height:15px;">';
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
			echo '<hr />';
			echo '<p style="font-size: 11px;">';
			echo $web95.'<strong style="margin-right:20px;">'.$txt5.'</strong>'.$web20.'<strong style="margin-right:20px;">'.$txt4.'</strong>';
			if (!isset($prt)) {
				echo '<a href="faq.php?lng='.$lng.'&amp;pg='.$dbwork[$i][4].'&amp;prt=2" target="_blank"><img src="'.CHEMIN.'inc/img/general/impfaq.gif" border="0" alt="'.$web22.'" title="'.$web22.'" /></a>';
				echo '&nbsp;&nbsp;<a href="faq.php?lng='.$lng.'&amp;pg='.$dbwork[$i][4].'"><img src="'.CHEMIN.'inc/img/general/hyperlink.gif" border="0" alt="'.$web462.'" title="'.$web462.'" /></a> ';
			}
			echo '</p>'."\n";
			echo '</div>'."\n";
      if ((($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $drtuser[21]=="on")) && !isset($prt)) {
				echo '<div align="right" style="cursor:pointer;">';
?>
       	<a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=faq&amp;form=2&amp;id=<?php echo $dbwork[$i][4]; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/edit.gif" border="0" alt="<?php echo $web308; ?>" title="<?php echo $web308; ?>" /></a>
       	<a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=faq&amp;act=i&amp;id=<?php echo $dbwork[$i][4]; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/desact.gif" border="0" alt="<?php echo $web333; ?>" title="<?php echo $web333; ?>" /></a>
       	<a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=faq&amp;del=<?php echo $dbwork[$i][4]; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/del.gif" border="0" alt="<?php echo $web324; ?>" title="<?php echo $web324; ?>" /></a>
<?php
				echo '</div>'."\n";
      }
		  echo '</div>'."\n";
		  } /// fin accès privé
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
  echo GetNavBar("faq.php?lng=".$lng."&amp;pg=".$pg."&amp;id=", count($dbwork), $id, $serviz[6]);
}
btable();
include("inc/bpage.inc");
?>
