<?php
/*
    Blog catalog Box - GuppY PHP Script -  version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v4.6.0 (04 June 2007)        : initial release by Icare
      v4.6.6 (14 April 2008)       : corrected box title (by Icare)
      v4.6.9 (25 December 2008)    : new formatting of the code
      v4.6.10 (7 september 2009)   : corrected #288
      v4.6.11 (xx november 2009)   : deleted padding of tblbox
      v4.6.15 (30 June 2011)       : added private blog management (by Icare)
	  v4.6.20 (24 May 2012)        : corrected $boxwidth (by Saxbar)
      v4.6.22 (29 December 2012)   : box created using htable1()/btable1() (thanks Icare)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "blogcat.inc")) {
  header("location:../index.php");
  die();
}

$i = ($lng == $lang[0])? 0 : 1 ;
$dbw = ReadDBFields(DBBLOG);
if (!empty($dbw)) {
	$j = ($lng == $lang[0])? 0 : 1 ;
 	$k = 0;
 	$txtbi = array();
 	$curr_rubr = "";
 	$curr_bi = "";
 	for ($i = 0; $i < count($dbw); $i++) {
 	  /// début accès privé
    $acces = "ok";
    if ($dbw[$i][6] != "") {
      $acces = "no";
      if ($userprefs[1] != "") {
        include_once (CHEMIN.'inc/func_groups.php');
        if (CheckGroup($dbw[$i][6], $userprefs[1])) $acces ="ok";
      }
    }
    if ($acces == "ok") {
      if (trim($dbw[$i][0+$j]) != "") {
     	  $txtbi[$k][0] = trim($dbw[$i][0+$j]);
     	  $txtbi[$k][1] = trim($dbw[$i][2+$j]);
     	  $txtbi[$k][2] = $dbw[$i][4];
     	  if ($pg == $dbw[$i][4]) {
     		 $curr_rubr = $txtbi[$k][0];
     		 $curr_bi = $txtbi[$k][2];
     	  }
     	  $k++;
      }
     }
     /// fin accès réservé
 	}
 	sort($txtbi);
	$typeRubrique = 'blog';
 	$rubr = "";
 	$marqueur = $texte[3];
 	$curr_marq = "<img src='".CHEMIN."inc/img/general/puce2.gif' alt='puce' class='puce' />";
 	$url = CHEMIN.'blog.php?lng='.$lng.'&amp;sel=pg&amp;pg=';
	$widthbox = !isset($boxwidth) ? "172px" : strpos($boxwidth, 'px') === false ? '172px' : $boxwidth;
  htable1($web400);
   switch ($serviz[59]) {
	case "0" : // liste de menu
 		for ($i = 0; $i < count($txtbi); $i++) {
   		if ($rubr <> $txtbi[$i][0]) {
   			if (!empty($rubr)) {
   				echo '
      </ul>';
   			}
        $rubr = $txtbi[$i][0];
   		  echo '
     <p class="item">'.$rubr.'</p>
      <ul class="item">';
     	}
     	if ($curr_bi == $txtbi[$i][2]) {
     		echo '
       <li class="curr_item">'.$curr_marq.' <a href="'.$url.$txtbi[$i][2].'">'.$txtbi[$i][1].'</a>';
      }
      else {
        echo '
       <li class="item">'.$marqueur.' <a href="'.$url.$txtbi[$i][2].'">'.$txtbi[$i][1].'</a>';
      }
      echo '
       </li>';
    }
    echo '
      </ul>';
  break;
 	case "1" : // menu dynamique
   	echo '
     <form name="blog" action="" method="post">
      <p align="center">';
    for ($i = 0; $i < count($txtbi); $i++) {
    	if ($rubr <> strip_tags($txtbi[$i][0])) {
    		if (!empty($rubr)) echo '
       </select>'."\n";
       		$rubr = strip_tags($txtbi[$i][0]);
    		$maxlen = max(strlen($rubr), 25);
       	echo '
       <select size="1" onchange="document.blog.action=this.value; document.blog.submit();" style="width:166px">';
       	echo '
        <option>'.$rubr.'</option>';
     	}
     	echo '
        <option value="'.$url.$txtbi[$i][2].'">&nbsp;&nbsp;'.$marqueur.'&nbsp;'.substr(strip_tags($txtbi[$i][1]), 0, $maxlen).'</option>';
    }
    if (!empty($rubr)) {
        echo '
       </select>';
    }
    echo '
      </p>
     </form>';
 	break;
  case "2" : // menu liste dynamique n°1
  	$openimg = CHEMIN."inc/img/general/plus.gif";
  	$closeimg = CHEMIN."inc/img/general/minus.gif";
  case "3" : // menu liste dynamique n°2
  	if ($serviz[59] == "3") {
   		$openimg = CHEMIN."inc/img/general/open.gif";
   		$closeimg = CHEMIN."inc/img/general/close.gif";
  	}
  	$l = 0;
  	//echo '
    
  	for ($i = 0; $i < count($txtbi); $i++) {
   		if ($rubr <> $txtbi[$i][0]) {
   			if (!empty($rubr)) echo '
      </ul>'."\n";
     		$rubr = $txtbi[$i][0];
     		$rubric = '
       <a href="'.CHEMIN.'blogs.php?lng='.$lng.'&amp;sel=cat&amp;cat='.$txtbi[$i][0].'">'.$txtbi[$i][0].'</a>';
     		$l++;
     		echo '
      <p id="titreRubr'.$typeRubrique.$l.'" class="rubr" style="cursor:pointer" onclick="MontreCacheItems(\'imgOpen'.$typeRubrique.$l.'\',\'imgClose'.$typeRubrique.$l.'\',\'itemsRubr'.$typeRubrique.$l.'\',\'itemsRubrSelect\');">
       <img id="imgOpen'.$typeRubrique.$l.'" src="'.$openimg.'" border="0" alt="'.$web429.'" title="'.$web429.'" style="display:none;" />
       <img id="imgClose'.$typeRubrique.$l.'" src="'.$closeimg.'" border="0" alt="'.$web57.'" title="'.$web57.'" style="display:inline;" />'.$rubr.'
      </p>';
				if ($curr_rubr == $txtbi[$i][0]) {
     			echo '
      <ul id="itemsRubrSelect" class="item"> ';
				}
        else {
          echo '
      <ul id="itemsRubr'.$typeRubrique.$l.'" class="item">';
				}
      }
      if ($curr_bi == $txtbi[$i][2]) {
      	echo '
       <li class="curr_item">'.$curr_marq.' <a href="'.$url.$txtbi[$i][2].'">'.$txtbi[$i][1].'</a></li>';
      }
      else {
      	echo '
       <li class="item">'.$marqueur.' <a href="'.$url.$txtbi[$i][2].'">'.$txtbi[$i][1].'</a></li>';
      }
    }
    if (!empty($rubr)) {
        echo '
      </ul>';
    }
    //   
echo '
<script type="text/javascript">
//<![CDATA[
<!--
var nbRubr = '.($l+1).';
var typeRubr = \''.$typeRubrique.'\';
for(i = 0; i < nbRubr; i++) {
 if((document.getElementById && document.getElementById(\'itemsRubr\'+ typeRubr + i) != null) || (document.all && document.all[\'itemsRubr\'+ typeRubr + i] != undefined ) || (document.layers && document.layers[\'itemsRubr\'+ typeRubr + i] != undefined) ) {
  cache(\'itemsRubr\'+ typeRubr + i);
  montre(\'imgOpen\'+ typeRubr + i,\'inline\');
  cache(\'imgClose\'+ typeRubr + i);
 }
}
//-->
//]]>
</script>';
  break;
  }
  if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $drtuser[39]=="on")) {
    echo '
    <p align="right"><a href="'.CHEMIN.'admin/admin.php?lng='.$lng.'&amp;pg=blog"><img src="'.CHEMIN.'inc/img/general/edit.gif" border="0" alt="'.$web308.'" title="'.$web308.'" /></a></p>';
  }
  btable1();
}
?>
