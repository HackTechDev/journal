<?php
/*
    Right Papers Box - GuppY PHP Script -  version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v1.1 (02 January 2002)   : no change
      v1.2 (05 January 2003)   : created database art.dtb for quicker display
                                 this new database is managed by the UpdateDBArt() function
      v2.2 (22 April 2003)     : file renamed and split from boxart.inc to boxartg.inc and boxartd.inc
                                 added another box for articles in order to split articles in 2 main categories (by Nicolas Alves)
      v2.3 (27 July 2003)      : added dynamic menu option
      v2.4 (24 September 2003) : split dynamic menu line if line too long
                                 dynamic menus are now centered in box (thanks Pavol)
                                 added option for choosing Articles mark (thanks Pavol)
      v3.0 (25 February 2004)  : added skin management (by Nicolas Alves)
                                 added dynamic list menu (thanks Graznok and Icare)
      v4.0 (06 December 2004)  : added box specific style (by Isa)
                                 added alt tags to img and removed border tag for non-linked img (by Isa)
                                 replaced & by &amp; in URLs to be more standard compliant (by Isa)
      v4.5 (05 June 2005)      : replacing table by div (by Icare)
                                 selected submenu staying opened, mark on selected article (by Nico and Icare)
      v4.6.0 (04 June 2007)    : display elapsed menu if javascript disabled (by JeanMi)
      v4.6.3 (30 August 2007)  : corrected lang items for alt and title (by Icare)
      v4.6.6 (14 April 2008)   : added title on article links (by Icare)
      v4.6.15 (30 June 2011)   : added private group management (by Icare)
	  v4.6.20 (24 May 2012)    : added $boxtitle (by Saxbar)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "boxartd.inc")) {
  header("location:../index.php");
  die();
}

$i = ($lng == $lang[0])? 0 : 1 ;
$boxtitle = $nom[$i+30];
htable1($boxtitle, "100%");
$dbw = ReadDBFields(DBART);
if (!empty($dbw)) {
	$j = ($lng == $lang[0])? 0 : 1 ;
  	$k = 0;
  	$arttbl = array();
  	$curr_rubr = "";
  	$curr_art = "";
  	for ($i = 0; $i < count($dbw); $i++) {
  	  /// début modif accès privé
      $acces = "ok";
      if ($dbw[$i][6] != "") {
        $acces = "no";
        if ($userprefs[1] != "") {
          include_once (CHEMIN.'inc/func_groups.php');
          if (CheckGroup($dbw[$i][6], $userprefs[1])) $acces ="ok";
        }
      }
      if ($acces == "ok") {
      /// fin modif accès privé
    	if (($serviz[3] == "on" && $dbw[$i][5] == "right") || $serviz[3] != "on") {
      		if (trim($dbw[$i][0+$j]) != "") {
        		$arttbl[$k][0] = trim($dbw[$i][0+$j]);
        		$arttbl[$k][1] = trim($dbw[$i][2+$j]);
        		$arttbl[$k][2] = $dbw[$i][4];
        		if ($pg == $dbw[$i][4]) {
           			$curr_rubr = $arttbl[$k][0];
           			$curr_art = $arttbl[$k][2];
        		}
        		$k++;
      		}
    	}
    	} /// fin accès privé
	}
	sort($arttbl);

	$typeRubrique = 'boxartd';
  	$rubr = "";
  	$marqueur = $texte[3];
  	$curr_marq = "<img src='".CHEMIN."inc/img/general/puce2.gif' alt='puce' class='puce' />";
  	$url = CHEMIN.'articles.php?lng='.$lng.'&amp;pg=';
  	switch ($serviz[26]) {
  		case "0" : // liste de menu
    		for ($i = 0; $i < count($arttbl); $i++) {
        		if ($rubr <> $arttbl[$i][0]) {
        			if (!empty($rubr)) {
          				echo '</ul>'."\n";
        			}
            		$rubr = $arttbl[$i][0];
        			echo '<p class="rubr">'.$rubr.'</p>'."\n";
					echo '<ul class="item">'."\n";
        		}
        		if ($curr_art == $arttbl[$i][2]) {
           			echo '<li class="curr_item">'.$curr_marq.'<a href="'.$url.$arttbl[$i][2].'" title="'.strip_tags($arttbl[$i][1]).'">'.$arttbl[$i][1].'</a>'."\n";
        		} else {
          			echo '<li class="item">'.$marqueur.'<a href="'.$url.$arttbl[$i][2].'" title="'.strip_tags($arttbl[$i][1]).'">'.$arttbl[$i][1].'</a>'."\n";
        		}
       			 echo '</li>'."\n";
			}
    		echo '</ul>'."\n";
    	break;

    	case "1" : // menu dynamique
    		echo '<form name="artd" action="" method="post"><p style="text-align:center">'."\n";
    		for ($i = 0; $i < count($arttbl); $i++) {
        		if ($rubr <> strip_tags($arttbl[$i][0])) {
        			if (!empty($rubr)) echo '</select>'."\n";
            		$rubr = strip_tags($arttbl[$i][0]);
        			$maxlen = max(strlen($rubr),25);
            		echo '<select size="1" onchange="document.artd.action=this.value; document.artd.submit();" style="width:135px">'."\n";
            		echo '<option>'.$rubr.'</option>'."\n";
        		}
        		echo '<option value="'.$url.$arttbl[$i][2].'">&nbsp;&nbsp;'.$marqueur.'&nbsp;'.substr(strip_tags($arttbl[$i][1]), 0, $maxlen).'</option>'."\n";
    		}
    		if (!empty($rubr)) echo '</select>'."\n";
    		echo '</p></form>'."\n";
      	break;

    	case "2" : // menu liste dynamique n°1
    		$openimg = CHEMIN."inc/img/general/plus.gif";
    		$closeimg = CHEMIN."inc/img/general/minus.gif";
    	case "3" : // menu liste dynamique n°2
    		if ($serviz[26] == "3") {
        		$openimg = CHEMIN."inc/img/general/open.gif";
        		$closeimg = CHEMIN."inc/img/general/close.gif";
    		}
    		$l = 0;
    		for ($i = 0; $i < count($arttbl); $i++) {
     	  		if ($rubr <> $arttbl[$i][0]) {
          			if (!empty($rubr)) echo '</ul>'."\n";
         	 		$rubr = $arttbl[$i][0];
       		   		$l++;
           			echo '<p id="titreRubr'.$typeRubrique.$l.'" class="rubr" style="cursor:pointer" onclick="MontreCacheItems(\'imgOpen'.$typeRubrique.$l.'\',\'imgClose'.$typeRubrique.$l.'\',\'itemsRubr'.$typeRubrique.$l.'\',\'itemsRubrSelect\');">'."\n";
          			echo '<img id="imgOpen'.$typeRubrique.$l.'" src="'.$openimg.'" border="0" alt="'.$web429.'" title="'.$web429.'" style="display:none;" /> ';
          			echo '<img id="imgClose'.$typeRubrique.$l.'" src="'.$closeimg.'" border="0" alt="'.$web57.'" title="'.$web57.'" style="display:inline;" /> ';
					echo $rubr.'</p>'."\n";
					if ($curr_rubr == $arttbl[$i][0]) {
          				echo '<ul id="itemsRubrSelect" class="item">'."\n";

					} else {
         				echo '<ul id="itemsRubr'.$typeRubrique.$l.'" class="item">'."\n";
					}
      			}
       			if ($curr_art == $arttbl[$i][2]) {
          			echo '<li class="curr_item">'.$curr_marq.'<a href="'.$url.$arttbl[$i][2].'" title="'.strip_tags($arttbl[$i][1]).'"> '.$arttbl[$i][1].'</a></li>'."\n";
       			} else {
          			echo '<li class="item">'.$marqueur.'<a href="'.$url.$arttbl[$i][2].'" title="'.strip_tags($arttbl[$i][1]).'"> '.$arttbl[$i][1].'</a></li>'."\n";
       			}
    		}
        	if (!empty($rubr)) echo '</ul>'."\n";
?>
			<script type="text/javascript">
			//<![CDATA[
			<!--
				var nbRubr = <?php echo ($l+1); ?>;
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
    	break;
	}
  if (($serviz[32] == "on" && !empty($serviz[31]) && $serviz[31] == $userprefs[1]) || ($serviz[32] == "on" && $drtuser[15] == "on")) {
      	echo '<p style="text-align:right"><a href="'.CHEMIN.'admin/admin.php?lng='.$lng.'&amp;pg=art"><img src="'.CHEMIN.'inc/img/general/edit.gif" border="0" alt="'.$web308.'" title="'.$web308.'" /></a></p>';
  }
}
btable1($boxtitle);
?>
