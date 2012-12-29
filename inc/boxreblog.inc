<?php
/*
    Blog reaction box - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2008 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v4.6.0 (04 June 2007)         : initial release by Icare
      v4.6.3 (30 August 2007)       : test of serviz[57] modified for moderation,
                                      display only active comments (by Icare)
      v4.6.6 (14 April 2008)        : added urlencode to $author (by JeanMi)
      v4.6.8 (24 May 2008)          : removal of useless items in navbar (by Icare)
      v4.6.9 (25 December 2008)     : added corrections for validation of W3C #236
      v4.6.10 (7 September 2009)    : corrected #288
      v4.6.11 (11 December 2009)    : deleted all hr tags and useless 2nd button if only one comment (by Icare)
      v4.6.15 (30 June 2011)        : added blog private management (by Icare)
      v4.6.22 (29 December 2012)    : corrected divs disposition for background (thanks Icare)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "boxreblog.inc")) {
  header("location:../index.php");
  die();
}

if ($serviz[57] == "") {
  exit($web143);
}
$pg = strip_tags($pg);
$react = strip_tags($react);
$id = strip_tags($id);
$cat = strip_tags($cat);
$dbwork = array();
if (!empty($react)) {
  $dbwork[0] = $react;
}
elseif (!empty($pg)) {
  $dbreaction = ReadDBFields(DBREBLOG);
  for ($i = 0; $i < count($dbreaction); $i++) {
    if ($dbreaction[$i][1] == $pg) {
      $dbwork[] = $dbreaction[$i][0];
    }
  }
}
@sort($dbwork);
$topmess = $web407;
if ($page[9] != "") {
  $topmess = "<img src=\"".CHEMIN."inc/img/icons/".$page[9]."/react.gif\" align=\"right\" width=\"32\" height=\"32\" alt=\"react.gif\" />".$topmess;
}
?>
<?php
  echo "
    <p style='text-align:left; font-weight: bold'>".$web407."</p>\n";
    
?>
<br />
<form name="formreblog1" action="postguest.php?lng=<?php echo $lng;?>" method="post">
<input type="hidden" name="typ" value="<?php echo TYP_REBLOG; ?>" />
<input type="hidden" name="pg" value="<?php echo $pg; ?>" />
<p align="center">
<?php echo $boutonleft; ?><button type="submit" title="<?php echo $web380; ?>"><?php echo $web380; ?></button><?php echo $boutonright; ?></p>
</form>
<?php
if (empty($id)) {
  $id = 1;
}
if (!empty($dbwork)) {
  echo GetNavBar("blog.php?lng=".$lng."&amp;pg=".$pg."&amp;id=", count($dbwork), $id, $serviz[30]);
  for ($i = $serviz[30]*($id-1); $i < Min($serviz[30]*$id, count($dbwork)); $i++) {
    ReadDoc(DBBASE.$dbwork[$i]);
    /// début modif accès réservé
    $acces = "ok";
    if ($fieldmod != "") {
      $acces = "no";
      if ($userprefs[1] != "") {
        include_once (CHEMIN.'inc/func_groups.php');
        if (CheckGroup($fieldmod, $userprefs[1])) $acces ="ok";
      }
    }
    if ($acces == "ok") {
    /// fin modif accès réservé
      if ($status == "a") {
        ?>
        <div class="bord" style="margin:10px 0; position:relative; text-align:left;">
        <p style="padding:4px 4px 0px;"><b><?php echo $web185.$fielda1; ?></b>&nbsp; - &nbsp;
        <?php
        echo $web6." ";
          if ($fieldd1 != "on") {
            $em = BreakEMail($email);
            ?>
            &nbsp;<b><a href="JavaScript:WriteMailTo('<?php echo addslashes(urlencode($author)); ?>','<?php echo $em[0]; ?>','<?php echo $em[1]; ?>','<?php echo $em[2]; ?>')" title="<?php echo "$web173 $author"; ?>"><?php echo addslashes($author); ?></a></b>
            <?php
          } else {
            echo "<b>".$author."</b>";
          }
            echo " ".$web7." ".FormatDate($creadate);
            ?>
    </p>
    <div class="rep">
            <?php
		        $fieldc1 = colorCode($fieldc1); /// Coloration syntaxique
		        echo $fieldc1;
            ?>
        </div>
        <?php
        if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $serviz[57]=="on" && $drtuser[40]=="on")) {
        ?>
      <p align="right">
      <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=reblog&amp;form=2&amp;id=<?php echo $dbwork[$i]; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/edit.gif" border="0" alt="<?php echo $web308; ?>" title="<?php echo $web308; ?>"></a>
      <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=reblog&amp;act=i&amp;id=<?php echo $dbwork[$i]; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/desact.gif" border="0" alt="<?php echo $web333; ?>" title="<?php echo $web333; ?>"></a>
      <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=reblog&amp;del=<?php echo $dbwork[$i]; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/del.gif" border="0" alt="<?php echo $web324; ?>" title="<?php echo $web324; ?>"></a></p>
      <?php
        }
      echo "</div>\n";
      }
    } /// fin accès privé
  }
  echo GetNavBar("blog.php?lng=".$lng."&amp;pg=".$pg."&amp;id=", count($dbwork), $id, $serviz[30]);
  if (count($dbwork) > 1) {
    ?>
    <form name="formreblog2" action="postguest.php?lng=<?php echo $lng;?>" method="post">
    <input type="hidden" name="typ" value="<?php echo TYP_REBLOG; ?>" />
    <input type="hidden" name="pg" value="<?php echo $pg; ?>" />
    <p align="center">
    <?php echo $boutonleft; ?><button type="submit" title="<?php echo $web380; ?>"><?php echo $web380; ?></button><?php echo $boutonright; ?></p>
    </form>
    <?php
  }
}
else {
  ?>
  <p align="center"><?php echo $web186; ?></p>
  <?php
}
?>
