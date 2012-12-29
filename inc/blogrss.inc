<?php
/*
    Blog RSS include links - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2008 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :                     : blog rss links extracted from blog.php and blog.inc
      v4.6.11 (xx november 2009)          : initial release by Icare
      v4.6.22 (29 December 2012)          : display of links like in articles boxes (thanks Icare)

*/
if (stristr($_SERVER["SCRIPT_NAME"], "blogrss.inc")) {
  header("location:../index.php");
  die();
}

  if ($serviz[27] =="on") {
  // blog rss -------------------------
      if ($lng == $lang[0]) {
          $i = 0;
      } else {
        $i = 1;
      }
      $dbbss = ReadDBFields(DBBSS);
      sort($dbbss);
      htable1($web402);
      for ($j = 0; $j < count($dbbss); $j++) {
          echo '
     <div class="item" style="padding:3px;text-align:left;">'.$texte[3].' <a href="'.CHEMIN.'blogrss.php?lng='.$lng.'&amp;id='.$dbbss[$j][4].'">'.$dbbss[$j][$i].'</a></div>';
      }
      if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $drtuser[41]=="on")) {
          echo '
     <p align="right"><a href="'.CHEMIN.'admin/admin.php?lng='.$lng.'&amp;pg=bss"><img src="'.CHEMIN.'inc/img/general/edit.gif" border="0" alt="'.$web308.'" title="'.$web308.'" /></a></p>';
      }
      btable1();
        }
?>
