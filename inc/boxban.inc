<?php
/*
    Banner Box - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.9 (11 February 2003)    : initial release
      v2.0 (27 February 2003)    : no logo option added
      v2.2 (22 April 2003)       : cleanup in the images organization
      v2.4 (24 September 2003)   : added alternative label for site's logo image (name of the site)
                                   added ReadDoc() function
                                   created $typ_[name] variables
      v3.0 (25 February 2004)    : added skin management (by Nicolas Alves)
      v4.0 (06 December 2004)    : optimization table (by Icare)
                                   added alt tags to img and removed border tag for non-linked img (by Isa)
                                   corrected target=_new to target=_blank (by Isa)
                                   added class and bgcolor to the second table (thanks Ricsen)
      v4.5 (01 May 2005)         : added banner in flash (by Jean-Mi)
                                   added possible banner in a box like Header box (by Icare)
      v4.5.11 (06 January 2006)  : corrected table width, deleted alignment for benner cell (by Icare)
      v4.6.0 (04 June 2007)      : updated flash banner function, great thanks Kertiad
      v4.6.10 (7 September 2009)    : corrected #268
      v4.6.11 (11 December 2009)    : corrected #302
*/

if (stristr($_SERVER["SCRIPT_NAME"], "boxban.inc")) {
  header("location:../index.php");
  die();
}

echo '<div class="banner">'."\n";
  $dbw = SelectDBFields(TYP_BANNER,"a","");
  if (count($dbw)>0) {
    srand(MakeSeed());
    $i = rand(0,count($dbw)-1);
    ReadDoc(DBBASE.$dbw[$i][1]);
    if ($lng == $lang[0]) {
        $img = $fielda1;
        $url = $fieldb1;
        $alt = empty($fieldd1) ? $url : $fieldd1;
    } else {
        $img = empty($fielda2) ? $fielda1 : $fielda2;
        $url = empty($fieldb2) ? $fieldb1 : $fieldb2;
        $alt = empty($fieldd2) ? $url : $fieldd2;
    }
    $img = CHEMIN."img/".$img;
    $extn = substr($img,-3);
    if ($boxban == "on") htable2(); else echo $boxban; // Top of optionnal banner box
    if (isImage($extn)) {
      if (!empty($url)) {
        echo "<a href='".$url."' target='_blank' title='".$alt."'>";
      }
      echo "<img src='".$img."' border='0' alt='".$alt."' title='".$alt."' />";
      if (!empty($url)) {
        echo "</a>";
      }
      echo "\n";
    }
    elseif (IsFlash($extn)) {
      ?>
      <object type="application/x-shockwave-flash" data="<?php echo $img; ?>" width="468" height="60" class="flashban" title="<?php echo $alt; ?>">
      	<param name="wmode" value="transparent" />
      	<param name="quality" value="high" />
      	<param name="menu" value="false" />
      	<param name="movie" value="<?php echo $img; ?>" />
      	<span><a href="http://www.adobe.com/go/getflashplayer" title="<?php echo $web421; ?>"><?php echo $web421; ?></a></span>
      </object>
      <?php
    }
    if ($boxban == "on") btable2(); else echo $endban; // Bottom of optionnal banner box
  }

  if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $drtuser[27]=="on")) {
    ?>
    <p align="right"><a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=banner"><img src="<?php echo CHEMIN; ?>inc/img/general/edit.gif" border="0" alt="<?php echo $web308; ?>" title="<?php echo $web308; ?>" /></a></p>
   <?php
  }
echo "</div>\n";
