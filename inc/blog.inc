<?php
/*
    Blog - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v4.6.0 (04 June 2007)        : initial release by Icare
      v4.6.3 (30 August 2007)      : test of serviz[57] modified for moderation,
                                     modifed comments count (by Icare)
      v4.6.6 (14 April 2008)       : corrected columns width and boxes title (by Icare)
                                     added urlencode to $author (by JeanMi)
      v4.6.9 (25 December 2008)    : corrected name of form #236
                                     added management of the non-existent pages #221
      v4.6.9c (28 December 2008)   : corrected
      v4.6.10 (07 Septmeber 2009)  : corrected #274 #288
      v4.6.11 (xx november 2009)   : optimization display left or right (by Icare)
      v4.6.15 (30 June 2011)       : added private blog management(by Icare)
	                                   partial display changes (thanks Laroche)
      v4.6.16 (02 September 2011)  : corrected display notes blog home (by Laroche)
      v4.6.17 (21 October 2011)    : deleting entity &nbsp line 315 (thanks JeanMi)
	                                 corrected display read more (by Laroche)
 	  v4.6.20 (24 May 2012)        : corrected $boxwidth, display btable (by Saxbar)
      v4.6.22 (29 December 2012)   : box created using htable1()/btable1() (thanks Icare)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "blog.inc")) {
    header("location:../index.php");
    die();
}
// déplacé
include_once (CHEMIN.'inc/func_groups.php');

$id = strip_tags($id);
$longword = 220;
$separator = "<!--CUT-->";
if (isset($site[29]) && $site[29] > 0) $longword = $site[29];
//if ($userprefs[3] =="" || $userprefs[3] == "LR") $userprefs[3] = "R";
$max_height = round($longword/3*0.72);
if ($page[9] != "") {
    $topmess = "<img src=\"".CHEMIN."inc/img/icons/".$page[9]."/blog.gif\" align=\"right\" width=\"32\" height=\"32\" alt=\"blog.gif\" />".$topmess;
}
// filtrage des billets autorisés
$db = array();
$db_filter = array();
$db_allowed = array();
$db = ReadDBFields(DBBLOG);
for ($ii = 0; $ii < count($db); $ii++) {
	if (CheckGroup($db[$ii][6], $userprefs[1]) || ($db[$ii][6] == '' )) { 
		$db_allowed[] = $db[$ii];
		$db_filter[] = $db[$ii][4];
	}
}

$xdbw = array();
switch ($sel) {
case 'pg': // cas billet unique ---------------------
    if (!empty($pg)) {
        $titre = "";
        $xdbw = SelectDBFields(TYP_BLOG,"a",$pg);
    }
    break;
case 'cat': // cas liste catégorie -----------------
    if (!empty($cat)) {
        $titre = $cat;
        $dbwork = $db_allowed;		
        if (!empty($db_allowed)) {
            if ($lng == $lang[0]) {
                $j = 0;
            }
            else {
                $j = 1;
            }
            for ($i = 0; $i < count($db_allowed); $i++) {
                if ($cat == strip_tags($db_allowed[$i][0+$j])) {
                    $xdbw[$i][0] = TYP_BLOG;
                    $xdbw[$i][1] = $db_allowed[$i][4];
                }
            }
        }
    }
    break;
case 'jour': // cas liste jour ---------------------
    if (!empty($datej)) {
        $titre = $web403.substr(formatDate($datej), 0, 10);
        $date = $datej;
        $dbwork = $db_allowed;
        for ($i = 0; $i < count($db_allowed); $i++) {
            ReadDoc(DBBASE.$db_allowed[$i][4]);
            $datebi = CutLongWord($creadate, 8);
            if ($datebi == $datej) {
                $xdbw[$i][0] = $typ;
                $xdbw[$i][1] = $fileid;
            }
        }
    }
    break;
case 'mois': // cas liste mois ---------------------
    if (!empty($date)) {
        $titre = $web399." ".substr(formatDate($date), 1, 7);
        $dbwork = $db_allowed;
        for ($i = 0; $i < count($db_allowed); $i++) {
            ReadDoc(DBBASE.$db_allowed[$i][4]);
            $datebi = CutLongWord($creadate, 6);
            if ($datebi == $date) {
                $xdbw[$i][0] = $typ;
                $xdbw[$i][1] = $fileid;
            }
        }
    }
    break;
default: // cas liste globlale ---------------------
    $titre = $web383;
	$db = SelectDBFields(TYP_BLOG,"a",""); // filtrage sur autorisés
	for ($ii = 0; $ii < count($db); $ii++) {
		if (in_array($db[$ii][1], $db_filter)) {
			$xdbw[] = $db[$ii] ;
		}
	}	
}
if (!empty($xdbw) || $sel == 'mois' || $indexblog == 0) {
    @rsort($xdbw);	
    if (empty($id)) {
        $id = 1;
    }
    if ($indexblog == 1) {
        $minblog = $site[31];
        $maxblog = Min($site[31],count($xdbw));
        $id = 1;
    }
    else {
        $minblog = $serviz[55];
        $maxblog = Min($serviz[55]*$id,count($xdbw));
    }
    if ($indexblog == 0) include("inc/hpage.inc");
    htable($topmess,"100%");
    if ($indexblog == 0) {
    if ($widepage != "") include(CHEMIN."inc/topblog.inc");
        echo '
<br />
<div style="width:100%;">
 <table align="center" cellpadding="4" style="width:100%" summary="">
  <tr>';
        $widthbox = !isset($boxwidth) ? "172px" : strpos($boxwidth, 'px') === false ? '172px' : $boxwidth;
        if ($widepage == "on" || $userprefs[3] != "L") {
            echo '
   <td valign="top" style="width:'.$widthbox.';">';
            include(CHEMIN."inc/blogcat.inc");
            include(CHEMIN."inc/bloglist.inc");
            if ($widepage != "on") {
                include(CHEMIN."inc/blogcalendar.inc");
                include(CHEMIN."inc/blogrss.inc");
            }
            echo '
   </td>';
        }
        echo '
   <td style="width:auto;vertical-align:top">';
      echo '
    <div class="titre" style="width:auto;margin:0px;">'.$titre.'</div>
    <div class="tbl">'; 
    //htable($titre,"100%");
    }
    if ($site[30] != "2") {
        echo '
    <br />
    <form name="comment" action="'.CHEMIN.'postguest.php" method="post">
     <input type="hidden" name="lng" value="'.$lng.'"/>
     <input type="hidden" name="typ" value="'.TYP_BLOG.'"/>
     <div align="center">'.$boutonleft.'<button type="submit" title="'.$web386.'">'.$web386.'</button>'.$boutonright.'</div>
    </form>';
    }
    if ($indexblog == 0) {
        echo GetNavBar("blogs.php?lng=".$lng."&amp;sel=".$sel."&amp;pg=".$pg."&amp;cat=".$cat."&amp;datej=".$datej."&amp;date=".$date."&amp;id=", count($xdbw), $id, $minblog);
    }

    if (count($xdbw) > $site[31]) {
        $nbrnvisi = $site[31];
    } else {
        $nbrnvisi = count($xdbw);
    }

    if (count($xdbw) == 0) {
        /// Cas particuliers
        if ($sel == 'mois') {
            /// Le mois est vide
            echo '
    <p style="text-align:center; font-weight:bold;">'.$web438.'</p>';
        } else {
            /// Le blog est vide
            echo '
    <p style="text-align:center; font-weight:bold;">'.$web439.($site[30] == '2'? '' : '<br />'.$web440).'</p>';
        }
    } else {
        /// Cas général
        for ($i = $minblog*($id-1); $i < $maxblog; $i++) { /// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   DEBUT BOUCLE
            ReadDoc(DBBASE.$xdbw[$i][1]);
            $hr = "<hr />";
            if ($i == $maxblog-1) {
                $hr = "";
            }
            $txt0 = $fileid;
            if ($lng == $lang[0]) {
                $txt1 = $fieldb1;
                $txt2 = $fieldc1;
            }
            else {
                $txt1 = $fieldb2;
                $txt2 = $fieldc2;
            }
            $txt2 = colorCode($txt2);
            /// début modif accès privé
            $txt9 = $fieldmod;
            $acces = "ok";
            if ($txt9 != "") {
              $acces = "no";
              if ($userprefs[1] != "") { 
                if (CheckGroup($txt9, $userprefs[1])) $acces ="ok";
              }
            }
            if ($acces == "ok") {
            if ($acces == "no" && $indexblog == 1) $txt2 = "";
            /// fin modif accès privé
            if (!empty($txt2)){
                if (!empty($fieldd2)) {
                    $txt1 = "<img src=\"".CHEMIN."img/".$fieldd2."\" align=\"right\" alt=\"".$fieldd2."\"/>".$txt1;
                }
                echo '
    <p style="padding:8px 4px 0px;text-align:left;">
     <b>'.$txt1.'</b> - '.$web6.' ';
                if ($fieldd1 != "on") {
                    $em = BreakEMail($email);
                    echo '
     <b><a href="JavaScript:WriteMailTo(\''.addslashes(urlencode($author)).'\',\''.$em[0].'\',\''.$em[1].'\',\''.$em[2].'\')">'.addslashes($author).'</a></b>';
                }
                else {
                    echo '
     <b>'.$author.'</b>';
                }
                echo '
    </p>
    <div class="bord" style="margin:4px; padding: 1px;text-align:left;vertical-align:top">';
    /// début modif accès privé
                if ($acces == "no") {
					die;
                }
    /// fin modif accès privé
	
                if ($indexblog == 1) { ///------------------------------------------------------ page d'accueil -----------
                    $txt3 = '
     <div id="blog3'.$i.'" class="rep" style="margin: 0px; padding:2px">';
                    if(preg_match("`".$separator."`",$txt2)) {
						$block = explode($separator,$txt2);
                        echo '<div class="rep" style="overflow:hidden; padding: 4px;">'.$block[0].'</div>';
			$part1 = '<div class="rep" id="bltxt'. $i . '" style="display:none; padding: 2px">'. $block[1].'</div>';
			$part1 .= '<div id="blls'. $i .'" class="rep" style="display:none; text-align:right;">';
			$part1 .='<img src="'. CHEMIN .'inc/img/general/minus.gif" border="0" alt="" title=""  onclick="cache(\'bltxt' .$i .'\');cache(\'blls'.$i.'\');montre(\'blft'. $i . '\');" />&nbsp;</div>';
			echo $part1;
			$part2 = '<div class="rep" id="blft'.$i.'" style="text-align:right;font-size:smaller">';
			$part2 .='<a href="#'.$i.'" onclick="montre(\'bltxt' . $i . '\');montre(\'blls'.$i.'\');cache(\'blft'.$i.'\')" title="'.$web296.'">';
			$part2 .= $web461.'&nbsp; <img src="'.  CHEMIN . 'inc/img/general/plus.gif" border="0" alt="" /></a>&nbsp;</div></div';
			echo $part2;
					} else if (strlen($txt2) >= $longword){
                        $txt3 .= '
      <div class="rep" style="height:'.$max_height.'px; overflow:hidden; padding: 4px;">'.$txt2.'</div>
      <p style="text-align:right"><a href="javascript:ActiveMenu(\'blog3\',\'blog2\',0,'.$nbrnvisi.','.$i.')" class="box" title="'.$web296.'">'.$web461.'&nbsp;
      <img src="'.CHEMIN.'inc/img/general/plus.gif" border="0" alt="'.$web296.'" /></a>
      </p>
     </div>';
                    }
                    else{
                        $txt3 .= '
     <div class="rep" style="padding: 4px">'.$txt2.'</div>
    </div>';
                    }
                    echo $txt3;
                    echo '
    <div id="blog2'.$i.'" class="bord" style="display:none; margin: 2px; padding: 5px">'.$txt2.'
     <p align="right" style="cursor:pointer;"><img src="'.CHEMIN.'inc/img/general/minus.gif" border="0" alt="'.$web57.'" title="'.$web57.'" onclick="cache(\'blog2'.$i.'\');montre(\'blog3'.$i.'\')" /></p></div>';
                }
                else{
                    echo '
     <div id="blog'.$i.'" class="rep" style="padding: 5px">'.$txt2.'</div>';
                }
                echo '
     <div style="padding:6px 4px 2px;font-size:0.9em;text-align:right;vertical-align:middle">
      <form name="formblog'.$i.'" action="'.CHEMIN.'blog.php?lng='.$lng.'" method="post">
       <b>'.$web394.'</b>'.FormatDate($creadate).'&nbsp;';
              if ($acces == "ok") {// début modif accès privé
                if ($serviz[57] != "") {
                    $dbcom = ReadDBFields(DBREBLOG);
                    $nbcom = 0;
                    for ($k = 0; $k < count($dbcom); $k++) {
                        if ($dbcom[$k][1] == $txt0) {
                            $dbblog = ReadDoc(DBBASE.$dbcom[$k][0]);
                            if ($status == "a") {
                                $nbcom++;
                            }
                        }
                    }
                    $fileid = $txt0;
                    if ($nbcom == 0) {
                        $nbcom = $web430." ".$web379;
                    } elseif ($nbcom == 1) {
                        $nbcom = $nbcom." ".$web379;
                    } else {
                        $nbcom = $nbcom." ".$web379."s";
                    }
                    echo '
       <span style="font-size:smaller;"> - <a href="'.CHEMIN.'blog.php?lng='.$lng.'&amp;pg='.$fileid.'" title="'.$nbcom.' - '.$web297.' '.$web385.'"> '.$nbcom.' <img src="'.CHEMIN.'inc/img/general/comment.gif" alt="'.$nbcom.' - '.$web297.' '.$web385.'" title="'.$nbcom.' - '.$web297.' '.$web385.'" border="0" /> </a></span> &nbsp;';
                }
                echo '
       <input type="hidden" name="pg" value="'.$fileid.'"/>
       <input type="hidden" name="cat" value="'.$cat.'"/>
       <input type="hidden" name="sel" value="'.$sel.'"/>
       <a href="'.CHEMIN.'blog.php?lng='.$lng.'&amp;pg='.$fileid.'&amp;prt=1" target="_blank"><img src="inc/img/general/look.gif" border="0" alt="'.$web264.'" title="'.$web264.'" /></a>&nbsp;
       <a href="'.CHEMIN.'blog.php?lng='.$lng.'&amp;pg='.$fileid.'&amp;prt=2" target="_blank"><img src="inc/img/general/print.gif" border="0" alt="'.$web22.'" title="'.$web22.'" /></a>'."\n";
              } // fin modif accès privé
      echo '</form>
     </div>
    </div>'."\n";
                if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $drtuser[39]=="on")) {
                    echo '
     <div style="text-align:right; clear:both; margin-bottom:8px;">
      <a href="'.CHEMIN.'admin/admin.php?lng='.$lng.'&amp;pg=blog&amp;form=2&amp;id='.$xdbw[$i][1].'"><img src="'.CHEMIN.'inc/img/general/edit.gif" border="0" alt="'.$web308.'" title="'.$web308.'" /></a>
      <a href="'.CHEMIN.'admin/admin.php?lng='.$lng.'&amp;pg=blog&amp;act=i&amp;id='.$xdbw[$i][1].'"><img src="'.CHEMIN.'inc/img/general/desact.gif" border="0" alt="'.$web333.'" title="'.$web333.'" /></a>
      <a href="'.CHEMIN.'admin/admin.php?lng='.$lng.'&amp;pg=blog&amp;del='.$xdbw[$i][1].'"><img src="'.CHEMIN.'inc/img/general/del.gif" border="0" alt="'.$web324.'" title="'.$web324.'" /></a>
     </div>';
                }
            }
          } ///fin accès privé
        }
        if ($serviz[54] == "on") {
            $rssblogurl = $site[3].DATAREP."blog".$lng.".xml";
            echo '
    <div class="pop">
     <a href="'.$rssblogurl.'" target="_blank">
      <img src="'.CHEMIN.'inc/img/general/rss.gif" style="border:0px;vertical-align:bottom;" alt="" /> <span>'.$web398.':<br /><b> '.$rssblogurl.'</b></span>
     </a>
    </div>';
        }
        if ($indexblog == 0) {
            echo GetNavBar("blogs.php?lng=".$lng."&amp;sel=".$sel."&amp;pg=".$pg."&amp;cat=".$cat."&amp;datej=".$datej."&amp;date=".$date."&amp;id=", count($xdbw), $id, $minblog);
        }
    }
    if ($indexblog == 0) {
        if ($site[30] != "2") {
            echo '
    <form action="'.CHEMIN.'postguest.php" method="post">
     <input type="hidden" name="lng" value="'.$lng.'" />
     <input type="hidden" name="typ" value="'.TYP_BLOG.'" />
     <div align="center">'.$boutonleft.'<button type="submit" title="'.$web386.'">'.$web386.'</button>'.$boutonright.'</div>
    </form>';
        }
        echo '</div>';
        //btable();
        echo '
   </td>';
        if ($widepage == "on" || $userprefs[3] == "L") {
            echo '
   <td valign="top" style="width:'.$widthbox.';">';
            if ($widepage != "on") {
                include(CHEMIN."inc/blogcat.inc");
                include(CHEMIN."inc/bloglist.inc");
            }
            include(CHEMIN."inc/blogcalendar.inc");
            include(CHEMIN."inc/blogrss.inc");
            echo '
   </td>';
        }
        echo '
  </tr>
 </table>
</div>
';
        btable($topmess);
        include("inc/bpage.inc");
    } else {
        btable($topmess);
    }
}
else {
    if ($indexblog == 0) {
        header('HTTP/1.0 404 Not found');
        include("inc/hpage.inc");
        htable($topmess, "100%");
        echo '
<hr />
<div style="padding: 6px;">'.$web36.'</div>
<hr />';
        btable($topmess);
        include("inc/bpage.inc");
    } else {
        htable($topmess, "100%");
        if ($site[30] != "2") {
            echo '
<form name="comment" action="'.CHEMIN.'postguest.php" method="post">
 <input type="hidden" name="lng" value="'.$lng.'"/>
 <input type="hidden" name="typ" value="'.TYP_BLOG.'"/>
 <div align="center">'.$boutonleft.'<button type="submit" title="'.$web386.'">'.$web386.'</button>'.$boutonright.'</div>
</form>
<hr />';
        }
        echo '
<p style="text-align:center; font-weight:bold;">'.$web439.($site[30] == '2'? '' : '<br />'.$web440).'</p>';
        if ($indexblog == 0 && $site[30] != "2") {
            echo '
<hr />
<form name="comment" action="'.CHEMIN.'postguest.php" method="post">
 <input type="hidden" name="lng" value="'.$lng.'"/>
 <input type="hidden" name="typ" value="'.TYP_BLOG.'"/>
 <div align="center">'.$boutonleft.'<button type="submit" title="'.$web386.'">'.$web386.'</button>'.$boutonright.'</div>
</form>
    ';
    btable1();
        }
        btable($topmess);
   }
}
