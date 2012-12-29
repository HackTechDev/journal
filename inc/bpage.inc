<?php
/*
    Site Index Bottom & Right of Page - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v1.0 (30 December 2002)     : initial release
      v1.6 (23 January 2003)      : added page loaded in n.nn seconds information
      v1.7 (28 January 2003)      : fixed display bug of pages' right column
                                    upgraded relative linking to smileys in page footer (for scripts run in file/ directory)
      v1.9 (11 February 2003)     : added free box
      v2.0 (27 February 2003)     : added Top link at bottom of page
      v2.2 (22 April 2003)        : new side boxes management (by Nicolas Alves)
                                    cleanup in the images organization
      v2.3 (27 July 2003)         : added user prefs management by cookie
                                    changed str_replace to PathToImage() function
      v2.4 (24 September 2003)    : created $dbfoot variable
      v2.4p1 (26 Sept. 2003)      : some users could not post messages in the guestbook or forum, it is fixed now
      v2.4p2 (28 Sept. 2003)      : corrected bug for slowlyness of page display for some users
      v3.0 (25 February 2004)     : added skin management (by Nicolas Alves)
                                    added possibility to put all boxes on the right side
                                    added copyright notice on all pages
                                    updated sideboxes display because of new plugins manager
      v4.0 (06 December 2003)     : replacing high an low table by hr (by Icare)
                                    added sideboxes specific style (by Isa)
                                    added alt tags to img and removed border tag for non-linked img (by Isa)
                                    changed _new target for _blank (by Isa)
                                    removed the transparent pixel (skins have to use the htable and htable1 classes to set up the space between boxes (by Isa)
                                    some changes in order the code is more standards compliant (by Isa)
      v4.5 (25 April 2005)        : updated optionnal footer box facility (by Icare)
                                    modified copyright (by JeanMi and Icare)
      v4.6.0 (04 June 2007)       : added item $widepage for wide forum, extracted right boxes, new copyright line (by Icare)
      v4.6.3 (30 August 2007)     : corrected bad target in copyright (thanks Xiva)
      v4.6.6(14 April 2008)       : added test $tabmenu for external custom,
                                    made W3C validator's icons removable (by Icare)
      v4.6.10 (7 September 2009)  : corrected years in copyright and #290
      v4.6.14 (14 February 2011)  : corrected years in copyright
      v4.6.17(21 October 2011)    : added directory inc/incfoot for automatic include scripts php or  html at the bottom of the page (by Saxbar)
	                                fixed print view (by Saxbar)
      v4.6.18(09 February 2012)   : added $mpcopyright (by Saxbar)
                                    corrected link validator XHTML (by Papinou)	 							   
*/

if (stristr($_SERVER["SCRIPT_NAME"], "bpage.inc")) {
  header("location:../index.php");
  die();
}

echo '
<div id="centerBoxes">';

if ($widepage == "") {
    if (!isset($xposbox)) {
        if(!empty($posbox[20])){
            $onemenu = 0;
            include(CHEMIN.$posbox[20].INCEXT);
        }
    } else {
        $onemenu = 0;
        foreach($xposbox["C"] as $item) {
            if ($item != '') {
                include(CHEMIN.$item.INCEXT);
                $onemenu = 0;
            }
        }
    }
}

echo '
</div>';

if ($tabmenu == "template") {
    include($meskin."template2.inc");
} else {
  echo "</td>";
  if ($widepage == "" && $userprefs[3] != 'L') {
    echo "<td valign='top'>";
    include(CHEMIN."inc/boxright.inc");
    echo '</td>';
  }
  echo "</tr></table>\n";

echo "</div>\n";
}
//if ($widepage == "") {
  if (!isset($xposbox)) {
    if(!empty($posbox[21])){
      $onemenu = "0";
      echo "<div id='endbox'>";
      include(CHEMIN.$posbox[21].INCEXT);
      echo "</div>";
    }
  } else {
    $onemenu = 0;
    if (strlen(implode($xposbox["B"])) > 0) {
      echo "<div id='endbox'>";
      foreach($xposbox["B"] as $item) {
        if ($item != '') {
          include(CHEMIN.$item.INCEXT);
          $onemenu = 0;
        }
      }
      echo "</div>";
    }
  }
//}

// php or html scripts located in directory inc/incfoot are automatically include at the bottom of the page
if (is_dir(CHEMIN."inc/incfoot") && !isset($prt)) { 
	$bd = opendir(CHEMIN."inc/incfoot");
	while ($file = readdir($bd)) { 
		$cr = pathinfo(CHEMIN."inc/incfoot/".$file);
		if ($cr["extension"] == "inc") include(CHEMIN."inc/incfoot/".$file);
	}
}

echo $tabdown;

if ($skn_top !="") {
  echo "\n<p><a class='top' href='#top'>".$skn_top."</a></p>";
}
else {
  echo "\n".'<div align="center" style="clear:both"><a class="top" href="#top">';
  echo '<img src="'.CHEMIN.'inc/img/general/up.gif" border="0" alt="^"/>';
  echo '<b> '.$web136.' </b>';
  echo '<img src="'.CHEMIN.'inc/img/general/up.gif" border="0" alt="^"/>';
  echo '</a></div>';
}
echo "\n<div id=\"foot\">";
switch ($tabfoot) {
  case "on";
    htable2();
    break;
  case "" :
    echo "<hr />";
    break;
  default;
    echo $tabfoot;
}

include(DBFOOT);
if ($lng == $lang[0]) {
  $txtspe = PathToImage($foot1);
}
else {
  $txtspe = PathToImage($foot2);
}
if (trim($txtspe) != "") {
  echo $txtspe;
  if ($skn_hr == "") {
    echo " <hr />";
  }
}
if ($site[32] == "on") echo "
 <a href='http://validator.w3.org/check?uri=".$site[3]."' target='_blank' title='Valid XHTML 1.0 Transitional'>
 <img src='".CHEMIN."inc/img/general/xhtml10.png' alt='Valid XHTML 1.0 Transitional' style='border:0;' /></a> &nbsp;\n";

    ///////////////////////////////////////////////////////////////////////////////////
    //                                                                               //
    //                GuppY is protected by the CeCILL FREE LICENSE.                 //
    //  REMOVING OR MODIFYING THE FOLLOWING COPYRIGHT NOTICE IS STRICTLY FORBIDDEN.  //
    //                                                                               //
    ///////////////////////////////////////////////////////////////////////////////////
$txtspe  = "&nbsp;";
if ($lng == "fr") {
  $txtspe .= " <a class='copyright' href='http://www.freeguppy.org/' title='freeguppy.org' target='_blank'><img src='".CHEMIN."inc/img/general/gypower.gif' border='0' alt='freeguppy.org' /> </a> ";
  $txtspe .= "&nbsp; © ".$mpcopyright." &nbsp;";
  $txtspe .= " <a class='copyright' href='http://www.cecill.info/index.fr.html' title='En savoir plus ...' target='_blank'> <img src='".CHEMIN."inc/img/general/gycecill_f.gif' border='0' alt='En savoir plus ...' /> </a> ";
}
else {
  $txtspe .= " <a class='copyright' href='http://www.freeguppy.org/' title='freeguppy.org' target='_blank'><img src='".CHEMIN."inc/img/general/gypower.gif' border='0' alt='freeguppy.org' /> </a> ";
  $txtspe .= "&nbsp; © ".$mpcopyright." &nbsp;";
  $txtspe .= " <a class='copyright' href='http://www.cecill.info/index.en.html' title='More info ...' target='_blank'> <img src='".CHEMIN."inc/img/general/gycecill_e.gif' border='0' alt='More info ...' /> </a> ";
}
$txtspe .= "&nbsp;";

$imgspe = "";
if ($site[24] != "N") {
  $imgspe  = "<a href='http://www.freeguppy.org/' target='_blank' title='GuppY site'>";
  $imgspe .= "<img src='".CHEMIN.INCREP."img/general/gy".$site[24]."logo.gif' alt='GuppY site' style='vertical-align:middle;border:none;' /></a>";
  if ($site[25] == "T") {
    $txtspe = $imgspe."<br />".$txtspe;
  }
  elseif ($site[25] == "L") {
    $txtspe = $imgspe."&nbsp;&nbsp;".$txtspe;
  }
  elseif ($site[25] == "R") {
    $txtspe = $txtspe."&nbsp;&nbsp;".$imgspe;
  }
  else {
    $txtspe = $imgspe."&nbsp;&nbsp;".$txtspe."&nbsp;&nbsp;".$imgspe;
  }
}
echo $txtspe;
    ///////////////////////////    END of COPYRIGHT NOTICE    /////////////////////////
if ($site[32] == "on") echo "
 &nbsp;<a href='http://jigsaw.w3.org/css-validator/validator?uri=".$site[3]."' target='_blank' title='Valid CSS 2.1'>
 <img src='".CHEMIN."inc/img/general/css20.png' alt='Valid CSS 2.1' style='border:0;' /></a>\n";

if ($page[8] == "on") {
  $timer = StopTimer();
  echo "<p class='timer'>".$web116." ".$timer." ";
  if ($timer <= 1) {
     echo $web117;
  }
  else {
    echo $web118;
  }
  echo "</p>";
}

if ($tabfoot == "on")
  btable2();

echo $imgtabdown;
echo "</div>\n</div>";
echo "\n</body>\n</html>";
if ($obgo == true) {
  ob_end_flush();
}
?>
