<?php
/*
    Blogs listing script - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v4.6.0 (04 June 2007)          : initial release by Icare
      v4.6.6 (14 April 2008)         : corrected box title (by Icare)
      v4.6.8 (24 May 2008)           : corrected test for displaying last active comments (by Icare)
      v4.6.9 (25 December 2008)      : corrected the width of the box
      v4.6.10 (07 september 2009)    : corrected #288
      v4.6.11 (xx november 2009)     : canceled tests $recent and $comment, deleted padding of tblbox (by Icare)
      v4.6.13 (22 May 2010)          : corrected #328
      v4.6.15 (30 June 2011)         : added group management (by Icare)
	  v4.6.20 (24 May 2012)          : corrected $boxwidth (by Saxbar)
      v4.6.22 (29 December 2012)     : box created using htable1()/btable1() (thanks Icare)
*/
if (stristr($_SERVER["SCRIPT_NAME"], "bloglist.inc")) {
  header("location:../index.php");
  die();
}

// les billets récents -----------------------
  $i = ($lng == $lang[0])? 0 : 1 ;
  $dbwl = ReadDBFields(DBBLOG);
  $widthbox = !isset($boxwidth) ? "172px" : strpos($boxwidth, 'px') === false ? '172px' : $boxwidth;
  htable1(ucfirst($web382));
  if (!empty($dbwl)) {
    $j = ($lng == $lang[0])? 0 : 1 ;
    $txtbl = array();
    $nbNewBillet = (count($dbwl)-1-$serviz[61] > 0)? (count($dbwl)-1-$serviz[61]) : 0;
    for ($i = count($dbwl)-1; $i > $nbNewBillet; $i--) {
      echo '
     <div style="width:auto;padding:3px 6px;text-align:left;">';
      if (trim($dbwl[$i][0+$j]) != "") {
        ReadDoc(DBBASE.$dbwl[$i][4]);
        /// modif accès privé
          $acces = "ok";
          if ($fieldmod != "") {
            $acces = "no";
            if ($userprefs[1] != "") {
              include_once (CHEMIN.'inc/func_groups.php');
              if (CheckGroup($fieldmod, $userprefs[1])) $acces ="ok";
            }
          }
        if ($acces == "ok"){
        $sujet = ($lng == $lang[0])? $fieldb1 : $fieldb2 ;
        $sujet = CutLongWord(strip_tags($sujet), 60)." ...";
        echo " - ".formatDate($creadate)."<br /><a href=\"blog.php?lng=".$lng."&amp;sel=pg&amp;pg=".$fileid."\" title=\"".$web297."\">".$sujet."</a>";
        } /// fin modif accès privé
      }
      echo '
     </div>';
  }
}
btable1();

// Les derniers commentaires -----------------
if ($serviz[57] != "") {
$dbreac = array();
$dbreac = ReadDBFields(DBREBLOG);
@rsort($dbreac);
  if (!empty($dbreac)) {
    htable1($web401);
    for ($i = 0; $i < $serviz[61]; $i++) {
      /// début accès privé
      ReadDoc(DBBASE.$dbreac[$i][1]);
      $acces = "ok";
      if ($fieldmod != "") {
        $acces = "no";
        if ($userprefs[1] != "") {
          include_once (CHEMIN.'inc/func_groups.php');
          if (CheckGroup($fieldmod, $userprefs[1])) $acces ="ok";
        }
      }
      if ($acces == "ok") {
      /// fin accès privé
        ReadDoc(DBBASE.$dbreac[$i][0]);
        $reac0 = $fieldc1; //($lng == $lang[0])? $fieldc1 : $fieldc2 ;
        $reac1 = formatDate($creadate);
        $reac2 = $fielda2;
        if (!empty($reac0) && $status == "a" && $acces == "ok") {
          echo "
      <div style='width:auto;padding:3px 6px;text-align:left;'> - ".$reac1."<br />
        <a href=\"blog.php?lng=".$lng."&amp;sel=pg&amp;pg=".$reac2."\" title=\"".$web297."\">".CutLongWord(strip_tags($reac0), 80)." ...</a>
      </div>";
        }
      } /// accès privé
    }
    btable1();
    echo "
    <br />";
  }
}
?>
