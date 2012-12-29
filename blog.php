<?php
/*
    Blog script - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v4.6.0 (04 June 2007)       : initial release
      v4.6.3 (30 August 2007)     : test of serviz[57] modified for moderation (by Icare)
      v4.6.5 (05 December 2007)   : added missing optionnal img while displaying only one note (by Icare)
      v4.6.6 (06 January 2008)    : new colum width parameter according to width of lateral boxes
                                    corrected display of inactive notes (by Icare)
      v4.6.8 (24 May 2008)        : removal parameters in link to blogs.php (by Icare)
      v4.6.9 (25 December 2008)   : added corrections for validation of W3C #236
                                    added management of the non-existent pages
      v4.6.10 (07 September 2009) : corrected #273 #274 and #288
      v4.6.11 (11 December 2009)  : optimization display left or right (by Icare)
      v4.6.15 (30 June 2011)      : added private management of blog (by Icare)
                                    deleted test of $members[16]]( by Icare)
      v4.6.16 (02 September 2011) : corrected private management of blog (by Laroche)
      v4.6.20 (24 May 2012)       :	corrected $boxwidth (by Saxbar)
	  v4.6.22 (29 December 2012)  : corrected $prt (by Saxbar, thanks Ludo)
                                    changed divs by htable1()/btable1 in lateral boxes (thanks Icare)
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");
define('PATH_PGEDITOR', 'inc/pgeditor/');		//Chemin relatif de l'éditeur (ne pas modifier)
define('PATH_CONFIG_PGEDITOR','inc/config_pgeditor_guppy/'); //Chemin relatif du fichier de configuration de l'éditeur
include CHEMIN.PATH_PGEDITOR.'pgeditor.php';    //Fichier contenant toutes les fonctions nécessaires pour intégration de l'éditeur
include CHEMIN.PATH_PGEDITOR.'syntaxcolor/syntaxcolor.php'; //Coloration syntaxique
if ($serviz[53] != "on") {
  exit($web143);
}
if ($userprefs[3] == "" || $userprefs[3] == "LR") $userprefs[3] = "L";
$widepage = $serviz[58];
$cat = strip_tags($cat);
$pg = strip_tags($pg);
if (isset($prt)) $prt = strip_tags($prt);

if (count(SelectDBFields(TYP_BLOG,"a",$pg)) == 1) {
  ReadDoc(DBBASE.$pg);
  $countit = 1;
  if ($lng == $lang[0]) {
    $txtart1 = $fieldb1;
    $txtprt = strip_tags($fieldb1);
    $txtart2 = $fieldc1;
    $txtart3 = $fielda1;
  }
  else {
    $txtart1 = $fieldb2;
    $txtprt = strip_tags($fieldb2);
    $txtart2 = $fieldc2;
    $txtart3 = $fielda2;
  }
  $txtart4 = FormatDate($moddate);
  $txtart5 = FormatDate($creadate);
  $txtart6 = $author;
  if ($fieldd1 != "on") {
    $txtart7 = $email;
  }
  $txtart8 = $fieldd2;
  $txtart9 = $fieldmod; /// modif accès réservé
}
else {
  $prt = 0;
  $countit = 0;
  $txtart1 = $web35;
  $txtart2 = $web36;
  $txtart3 = $web37;
  $txtart4 = $web37;
  $txtart5 = $web37;
  header('HTTP/1.0 404 Not found');
}
if ($lng == $lang[0]) {
  $topmess = strip_tags($nom[42]);
}
else {
  $topmess = strip_tags($nom[43]);
}
if (!empty($txtprt)) $topmess .= " - ".$txtart3;
if ($page[9] != "") {
  $topmess = "<img src=\"".CHEMIN."inc/img/icons/".$page[9]."/blog.gif\" align=\"right\" width=\"32\" height=\"32\" alt=\"blog.gif\" />".$topmess;
}
if (empty($prt)) {
$widepage = $serviz[58];
include("inc/hpage.inc");

htable($topmess, "100%");

if ($widepage != "") include(CHEMIN."inc/topblog.inc");
//if ($userprefs[3] == "" || $userprefs[3] == "LR") $userprefs[3] = "L";

echo "<br />";
  if ($members[0]=="on" && $userprefs[1]=="" && $members[15]=="on") {
    echo "<p align=\"center\">".$web342."</p><br />";
    echo "<p align=\"center\">[ <a href=\"".CHEMIN."user.php?lng=".$lng."\">".$web343."</a> ]</p><br />";
  }
  else {
if ($indexblog == 0){
  ?>
  <table cellpadding="4" border="0" width="100%" summary=""><tr style="vertical-align:top">
  <?php
    $widthbox = !isset($boxwidth) ? "172px" : strpos($boxwidth, 'px') === false ? '172px' : $boxwidth;
    if ($widepage == "on" || $userprefs[3] != "L") {
      echo '
   <td valign="top" style="width:'.$widthbox.';">';
      include(CHEMIN."inc/blogcat.inc");
      echo "<br />";
      include(CHEMIN."inc/bloglist.inc");
      if ($widepage != "on") {
          include(CHEMIN."inc/blogcalendar.inc");
          include(CHEMIN."inc/blogrss.inc");
      }
      echo '
   </td>';
    }
  ?>
  <td style="width:auto;vertical-align:top">
  <?php
    if (!empty($txtart1)) {
          /// modif accès réservé
          $acces = "ok";
          if ($txtart9 != "") {
            $acces = "no";
            if ($userprefs[1] != "") {
              include_once (CHEMIN.'inc/func_groups.php');
              if (CheckGroup($txtart9, $userprefs[1])) $acces ="ok";
            }
          }
          if ($acces == "no") {
			header("location:blogs.php");
			die;
          } else {
          /// fin modif accès réservé

    echo "
    <div class='titre' style='width:auto;margin:0px;'>".$txtart3."</div>
      <div class='tbl'>\n";
    //htable($txtart3, "100%");
    if ($site[30] != "2") {
        echo '
    <br />
    <form name="comment" action="'.CHEMIN.'postguest.php" method="post">
     <input type="hidden" name="lng" value="'.$lng.'"/>
     <input type="hidden" name="typ" value="'.TYP_BLOG.'"/>
     <div align="center">'.$boutonleft.'<button type="submit" title="'.$web386.'">'.$web386.'</button>'.$boutonright.'</div>
    </form>';
    }
    if (!empty($txtart8)) {
      $txtart1 = "<img src=\"".CHEMIN."img/".$txtart8."\" align=\"right\" alt=\"".$txtart8."\"/>".$txtart1;
    }
    echo "<p align='left'><b>".$txtart1."</b> &nbsp;- &nbsp;".$web6." ";
      if (isset($textart7)) {
        $em = BreakEMail($txtart7);
        ?>
        <b><a href="JavaScript:WriteMailTo('<?php echo addslashes(urlencode($txtart6)); ?>','<?php echo $em[0]; ?>','<?php echo $em[1]; ?>','<?php echo $em[2]; ?>')"><?php echo addslashes(urlencode($txtart6)); ?></a></b>
        <?php
      }
      else {
        echo "<b>".$txtart6."</b>";
      }
    ?></p>
    <div class="bord" style="margin:4px;">
    <div class="rep" style="padding:4px;text-align:left;">
    <div>
	<?php
		$txtart2 = colorCode($txtart2);
		echo $txtart2;
	?>
	</div>
    </div>
    <div style="float:left;width:50%;padding:2px 4px;font-size:smaller;text-align:left;vertical-align:middle">
    <b><?php echo $web394; ?></b> <?php echo $txtart5 ; ?>&nbsp;&nbsp;
    <?php
    if ($serviz[33] == "on" && $countit == 1) {
      $artcounter = UpdateDocCounter($pg);
      if ($artcounter <= 1) {
        $txtcount = $web188;
      }
      else {
        $txtcount = $web189;
      }
    }
      echo "</div>\n";
      echo "<div id='action' style='width:40%;float:right;padding:2px 4px;font-size:smaller;text-align:right;vertical-align:middle'>\n";
    if ($countit == 1) {
  if ($indexblog == 0) {
    $dbw = array();
    $dbw = SelectDBFields(TYP_BLOG,"a","");
    @rsort($dbw);
    for ($i = 0; $i < count($dbw) ; $i++) {
      if ($dbw[$i][1] == $pg){
      $idb = floor(1+($i/$serviz[55]));
      break;
      }
    }
    echo "<a href='blogs.php?lng=".$lng."'><img src='inc/img/general/ed_copy.gif' border='0' alt='".$web383."' title='".$web383."' /></a>&nbsp;";
  }
      ?>
      <a href="blog.php?lng=<?php echo $lng; ?>&amp;pg=<?php echo $pg; ?>&amp;prt=1" target="_blank"><img src="inc/img/general/look.gif" border="0" alt="<?php echo $web264; ?>" title="<?php echo $web264; ?>" /></a>&nbsp;
      <a href="blog.php?lng=<?php echo $lng; ?>&amp;pg=<?php echo $pg; ?>&amp;prt=2" target="_blank"><img src="inc/img/general/print.gif" border="0" alt="<?php echo $web22; ?>" title="<?php echo $web22; ?>" /></a>&nbsp;
      <?php
    }
    echo "</div><div style='clear:both'></div>\n";
    echo "</div>\n";
      if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1] && $countit == 1) || ($serviz[32] && $drtuser[39]=="on" && $countit == 1)) {
      ?>
      <p align="right">
      <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=blog&amp;form=2&amp;id=<?php echo $pg; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/edit.gif" border="0" alt="<?php echo $web308; ?>" title="<?php echo $web308; ?>" /></a>
      <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=blog&amp;act=i&amp;id=<?php echo $pg; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/desact.gif" border="0" alt="<?php echo $web333; ?>" title="<?php echo $web333; ?>" /></a>
      <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=blog&amp;del=<?php echo $pg; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/del.gif" border="0" alt="<?php echo $web324; ?>" title="<?php echo $web324; ?>" /></a></p>
      <?php
    }
    }/// fin accès réservé
    } else $countit = 0;
  if ($serviz[57] != "" && $countit == 1) {
  echo "<input type='hidden' name='cat' value='".$txtart3."'/><br /><br />";
  include("inc/boxreblog.inc");
  }
  btable();
echo "</td>";
  if ($indexblog == 0) {
    if ($widepage == "on" || $userprefs[3] == "L") {
      echo '
   <td valign="top" style="width:'.$widthbox.';">';
      if ($widepage != "on") {
        include(CHEMIN."inc/blogcat.inc");
        echo "<br />";
        include(CHEMIN."inc/bloglist.inc");
      }
      include(CHEMIN."inc/blogcalendar.inc");
      include(CHEMIN."inc/blogrss.inc");
      echo '
   </td>';
    }
  } 
echo "</tr></table>\n";
}

}
echo "</div>";
//btable();


include("inc/bpage.inc");
}
else {
  ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
  <head>
  <title><?php echo $site[0]; ?> - <?php echo $txtprt; ?> - <?php echo $web23; ?></title>
  <meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset; ?>" />
  <meta name="Robots" content="NONE" />
  <style type="text/css">
    P { font-family: Arial, Helvetica, sans-serif; }
    a { color: <?php echo $lien[0]; ?>; text-decoration: underline; }
    a:hover { color: <?php echo $lien[1]; ?>; text-decoration: underline; }
  </style>
  <?php
  if ($prt == "2") {
    ?>
    <script type="text/javascript">
    window.print();
    </script>
    <?php
  }
  ?>
  </head>
  <body bgcolor="#FFFFFF" text="#000000">
  <h1 align="center"><?php echo $site[0]; ?></h1>
  <p align="center"><?php echo $site[3]; ?></p>
  <h3 align="center"><?php echo $txtprt; if (!empty($txtart3)) { echo " (".$txtart3.")"; } ?><br /></h3>
  <?php
  if ($fieldd2 != "") {
    echo "<img src=\"".CHEMIN."img/".$fieldd2."\" alt=\"".$fieldd2."\" />";
  }
  ?>
  <p><?php echo $txtart2; ?></p>
  </body>
  </html>
  <?php
}
?>
