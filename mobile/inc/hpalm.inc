<?php
/*
    Site Top of Page for PDA - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v2.3 (27 July 2003)         : initial release (thanks Palmipod)
      v2.4 (24 September 2003)    : added character set management
                                    added alternative label for language flag
                                    added alternative label for site's logo image (name of the site)
      v2.4p1 (26 Sept. 2003)      : bug correction = if no site logo, HTML code is now good (thanks Mitch)
      v3.0 (25 February 2004)     : simplified language switch parametrization
      v3.1 (18 July 2004)         : added optionnal long titles (by jmmis)
      v4.0 (06 December 2004)     : no change
      v4.35 (01 June 2005)        : corrected header look (by icare)
      v4.6.0 (04 June 2007)       : corrected smo mistakes in section names, thanks Guppimode
                                    added strip_tags() for section names (by Icare)
      v4.6.5 (05 December 2007)   : ommited deletion of useless current flag for language, thanks ghaz
	  v4.6.18 (09 February 2012)  : added $mpcopyright (by Saxbar)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "hpalm.inc")) {
  header("location:../index.php");
  die();
}

$toppage = $site[0];
if (($page[22]) && (!empty($topmess)))
	$toppage .= " - ".strip_tags($topmess);
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<?php
	//////////////////////////////////////////////////////////////////////////////////
	//                                                                              //
	//               GuppY is protected by the CeCILL FREE LICENSE.                 //
	// IT IS STRICTLY FORBIDDEN TO REMOVE OR MODIFY THE FOLLOWING COPYRIGHT NOTICE. //
	//                                                                              //
	//////////////////////////////////////////////////////////////////////////////////
?>

     <!--[  GuppY v<?php echo $mpversion; ?> CeCILL Copyright (C) <?php echo $mpcopyright; ?> by Laurent Duveau - http://www.freeguppy.org/  ]-->

<head>
<title><?php echo $toppage; ?></title>
<link rel="shortcut icon" href="<?php echo $site[3]; ?>guppy.ico" />
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset; ?>" />
<meta http-equiv="Content-Style-Type" content="text/css" />
<meta name="Description" lang="<?php echo $site[15]; ?>" content="<?php echo $site[1]; ?>" />
<meta name="Keywords" lang="<?php echo $site[15]; ?>" content="<?php echo $site[2]; ?>" />
<meta name="Identifier-url" content="<?php echo $site[16]; ?>" />
<meta name="Robots" content="<?php echo $site[7]; ?>" />
<meta name="Revisit-After" content="<?php echo $site[8]; ?>" />
<meta name="Author" content="<?php echo $site[9]; ?>" />
<meta name="Owner" content="<?php echo $site[10]; ?>" />
<meta name="Reply-To" content="<?php echo $site[11]; ?>" />
<meta name="Rating" content="<?php echo $site[12]; ?>" />
<meta name="Distribution" content="<?php echo $site[13]; ?>" />
<meta name="Copyright" content="<?php echo $site[14]; ?>" />
<meta name="Language" content="<?php echo $site[15]; ?>" />
<meta name="Title" content="<?php echo $site[6]; ?>" />
<meta name="Generator" content="GuppY" />
</head>
<body>
<?php
if ($page[4] != "") {
  ?>
  <center>
  <a href="index.php?lng=<?php echo $lng; ?>"><img src="<?php echo CHEMIN; ?>img/<?php echo $page[4]; ?>" border="0" align="center" alt="<?php echo $site[0]; ?>" /></a>
  </center>
  <br>
  <?php
}
if ($lng == $lang[0]) {
  $i = 0;
  $j = 0;
}
else {
  $i = 10;
  $j = 1;
}

if ($lang[1] != "") {
  if (substr_count($endurl,"?lng=") == 0) {
    $endurl0 = "?lng=".$lang[0];
    $endurl1 = "?lng=".$lang[1];
  }
  else {
    $endurl0 = str_replace("?lng=".$lang[1],"?lng=".$lang[0],$endurl);
    $endurl1 = str_replace("?lng=".$lang[0],"?lng=".$lang[1],$endurl);
  }
  if (substr_count($endurl,"articles.php") != 0 && substr_count($endurl,"&pg=") == 0) {
    $endurl0 = $endurl0."&pg=".$pg;
    $endurl1 = $endurl1."&pg=".$pg;
  }
  if ($lng == $lang[0]) {
    echo '<a href="'.$endurl1.'" title="['.$lang[1].']"><img src="'.$flag2.'" width="24" height="16" border="0" align="top" alt="['.$lang[1].']" /></a>&nbsp;'."\n";
  } else {
    echo '<a href="'.$endurl0.'" title="['.$lang[0].']"><img src="'.$flag1.'" width="24" height="16" border="0" align="top" alt="['.$lang[0].']" /></a>&nbsp;'."\n";
  }
}
$nom[$i+0] = strip_tags($nom[$i+0]);
?>
<a class="menu" href="<?php echo CHEMIN; ?>mobile/index.php?lng=<?php echo $lng; ?>" title="<?php echo $nom[$i+0]; ?>">
<?php
if ($page[9] != "") {
  ?>
  <img src="<?php echo CHEMIN; ?>inc/img/icons/<?php echo $page[9]; ?>/home.gif" alt="<?php echo $nom[$i+0]; ?>" width="32" height="32" border="0" align="center" /></a>&nbsp;
  <?php
}
else {
  echo $nom[$i+0]."</a>&nbsp;";
}
if ($serviz[53] == "on") {
  $nom[$j+42] = strip_tags($nom[$j+42]);
  ?>
  <a href="blogs.php?lng=<?php echo $lng; ?>" title="<?php echo $nom[$j+42] ?>">
  <?php
  if ($page[9] != "") {
    ?>
    <img src="<?php echo CHEMIN; ?>inc/img/icons/<?php echo $page[9]; ?>/blog.gif" alt="<?php echo $nom[$j+42] ?>" width="32" height="32" border="0" align="center" /></a>&nbsp;
    <?php
  }
  else {
  echo $nom[$j+42]."</a>&nbsp;";
  }
}
if ($serviz[8] == "on") {
  $nom[$i+7] = strip_tags($nom[$i+7]);
  ?>
  <a href="news.php?lng=<?php echo $lng; ?>" title="<?php echo $nom[$i+7] ?>">
  <?php
  if ($page[9] != "") {
    ?>
    <img src="<?php echo CHEMIN; ?>inc/img/icons/<?php echo $page[9]; ?>/news.gif" alt="<?php echo $nom[$i+7]; ?>" width="32" height="32" border="0" align="center" /></a>&nbsp;
    <?php
  }
  else {
    echo $nom[$i+7]."</a>&nbsp;";
  }
}
if ($serviz[10] == "on") {
  $nom[$i+1] = strip_tags($nom[$i+1]);
  ?>
  <a href="download.php?lng=<?php echo $lng; ?>" title="<?php echo $nom[$i+1] ?>">
  <?php
  if ($page[9] != "") {
    ?>
    <img src="<?php echo CHEMIN; ?>inc/img/icons/<?php echo $page[9]; ?>/download.gif" alt="<?php echo $nom[$i+1]; ?>" width="32" height="32" border="0" align="center" /></a>&nbsp;
    <?php
  }
  else {
    echo $nom[$i+1]."</a>&nbsp;";
  }
}
if ($serviz[11] == "on") {
  $nom[$i+3] = strip_tags($nom[$i+3]);
  ?>
  <a href="links.php?lng=<?php echo $lng; ?>" title="<?php echo $nom[$i+3] ?>">
  <?php
  if ($page[9] != "") {
    ?>
    <img src="<?php echo CHEMIN; ?>inc/img/icons/<?php echo $page[9]; ?>/links.gif" alt="<?php echo $nom[$i+3]; ?>" width="32" height="32" border="0" align="center" /></a>&nbsp;
    <?php
  }
  else {
    echo $nom[$i+3]."</a>&nbsp;";
  }
}
if ($serviz[14] == "on") {
  $nom[$j+24] = strip_tags($nom[$j+24]);
  ?>
  <a href="faq.php?lng=<?php echo $lng; ?>" title="<?php echo $nom[$j+24] ?>">
  <?php
  if ($page[9] != "") {
    ?>
    <img src="<?php echo CHEMIN; ?>inc/img/icons/<?php echo $page[9]; ?>/faq.gif" alt="<?php echo $nom[$j+24]; ?>" width="32" height="32" border="0" align="center" /></a>&nbsp;
    <?php
  }
  else {
  echo $nom[$j+24]."</a>&nbsp;";
  }
}
if ($serviz[12] == "on") {
  $nom[$i+9] = strip_tags($nom[$i+9]);
  ?>
  <a href="guestbk.php?lng=<?php echo $lng; ?>" title="<?php echo $nom[$i+9] ?>">
  <?php
  if ($page[9] != "") {
    ?>
    <img src="<?php echo CHEMIN; ?>inc/img/icons/<?php echo $page[9]; ?>/guestbook.gif" alt="<?php echo $nom[$i+9]; ?>" width="32" height="32" border="0" align="center" /></a>&nbsp;
    <?php
  }
  else {
    echo $nom[$i+9]."</a>&nbsp;";
  }
}
if ($serviz[13] == "on") {
  $nom[$ij+22] = strip_tags($nom[$j+22]);
  if ($serviz[18] == "on") {
  ?>
  <a href="fortopic.php?lng=<?php echo $lng; ?>" title="<?php echo $nom[$j+22] ?>">
  <?php
    if ($page[9] != "") {
    ?>
      <img src="<?php echo CHEMIN; ?>inc/img/icons/<?php echo $page[9]; ?>/forum.gif" alt="<?php echo $nom[$j+22]; ?>" width="32" height="32" border="0" align="center" /></a>
    <?php
    }
    else {
      echo $nom[$j+22]."</a>";
    }
  }
  else {
    ?>
    <a href="forum.php?lng=<?php echo $lng; ?>" title="<?php echo $nom[$j+22] ?>">
    <?php
    if ($page[9] != "") {
      ?>
      <img src="<?php echo CHEMIN; ?>inc/img/icons/<?php echo $page[9]; ?>/forum.gif" alt="<?php echo $nom[$j+22]; ?>" width="32" height="32" border="0" align="center" /></a>
      <?php
    }
    else {
      echo $nom[$j+22]."</a>";
    }
  }
}
?>
<hr />
