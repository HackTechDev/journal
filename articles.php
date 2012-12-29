<?php
/*
    Articles - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v1.0 (30 December 2002)  : initial release
      v2.2 (22 April 2003)     : cleanup in the images organization
      v2.3 (27 July 2003)      : bug fix, papers from right articles boxes would not appear when left articles boxes was not active
                                 added charset meta tag in the HTML print friendly version
                                 if no category for article, remove parenthesis in print friendly option
      v2.4 (24 September 2003) : added an icon for articles and news
                                 added react to an article option
                                 added Quick Article Admin Access (by Nicolas Alves)
                                 added number of times an article was read (by Nicolas Alves and Laurent Duveau)
                                 added ReadDoc() function
                                 added ReadDocCounter(), WriteDocCounter() and UpdateDocCounter() functions
                                 added GetCurrentDateTime() and FormatDate() function to ease various date and time formatings
                                 reviewed all Files Read & Write functions
                                 secured transfered parameters
                                 created $typ_[name] variables
      v3.0 (25 February 2004)  : upgraded the printable version (thanks tuture and B@lou)
      v4.0 (06 December 2004)  : added page title (by Jean-Mi)
                                 added alt tags to img and removed border tag for non-linked img (by Isa)
                                 minimal CSS for a print friendly version (by Isa)
                                 added optionnal quick admin and members management(by Nicolas Alves)
      v4.6.0 (15 Fevrier 2007) : added missing btable(), added rss link for articles (by Icare)
      v4.6.3 (30 August 2007)  : test of serviz[29] modified for moderation (by Icare)
      v4.6.6 (14 April 2008)   : added header("HTTP/1.0 404 Not found") in the event of pages not found (by JeanMi, thanks eDada)
      v4.6.10 (7 September 2009)    : added #281
      v4.6.15 (30 June 2011)   : added private group management(by Icare)
      v4.6.17 (21 October 2011) : fixed print view (by Saxbar)
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");

if ($serviz[3] != "on" && $serviz[22] != "on") {
    exit($web143);
}

$pg = strip_tags($pg);
if (isset($prt)) $prt = strip_tags($prt);

if (count(SelectDBFields(TYP_ART,"a",$pg)) == 1) {
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
    $txtart6 = $fieldmod; /// accès réservé
}
else {
    $countit = 0;
    $txtart1 = $web35;
    $txtart2 = $web36;
    $txtart3 = $web37;
    $txtart4 = $web37;
    $txtart5 = $web37;
    header('HTTP/1.0 404 Not Found');
}
$topmess = !empty($txtart3) ? $txtart3." - ".$txtart1 : $txtart1;

if (!empty($fieldd2)) {
    $topmess = "<img src=\"".CHEMIN."img/".$fieldd2."\" align=\"right\" alt=\"".$fieldd2."\" />".$topmess;
}

include("inc/hpage.inc");
htable($topmess, "100%");
if ($members[0]=="on" && $userprefs[1]=="" && $members[1]=="on") {
    echo "<p align=\"center\">".$web342."</p><br />";
    echo "<p align=\"center\">[ <a href=\"".CHEMIN."user.php?lng=".$lng."\">".$web343."</a> ]</p><br />";
    btable();
} else {
/// début modif accès réservé
    $acces = "ok";
    if ($txtart6 != "") {
        $acces = "no";
        if ($userprefs[1] != "") {
            include_once (CHEMIN.'inc/func_groups.php');
            if (CheckGroup($txtart6, $userprefs[1])) $acces ="ok";
        }
    }
    if ($acces == "no") {
        echo "<p align='center'><br><br>".$web444."<br /><br /></p>\n";
        btable();
    } else {
/// fin modif accès réservé
        if ($serviz[60] == "on" && !isset($prt)) {
            $rssnewsurl = $site[3].DATAREP."art".$lng.".xml";
            echo '<div class="pop">';
            echo '<a href="'.$rssnewsurl.'" target="_blank"><img src="'.CHEMIN .'inc/img/general/rss.gif" style="border:0px;vertical-align:bottom;"  alt="rss" /> ';
            echo '<span>'.$web406.':<br /><b> '.$rssnewsurl.'</b></span>';
            echo '</a></div><hr />';
        }
        if (!empty($txtart2)) {
            ?>
<div style="padding: 6px;"><?php echo $txtart2; ?></div>
<hr />
<p style="font-size:smaller"><?php echo $web95; ?> <b><?php echo $txtart5 ; ?></b><br />
            <?php echo $web20; ?> <b><?php echo $txtart4 ; ?></b><br />
            <?php echo $web21; ?> <b><?php echo $txtart3; ?></b>
            <?php
            if ($serviz[33] == "on" && $countit == 1) {
                $artcounter = UpdateDocCounter($pg);
                $txtcount = $artcounter <= 1 ? $web188 : $web189;
                ?>
<br /><?php echo $web190; ?> <b><?php echo $artcounter." ".$txtcount; ?></b></p>
                <?php
            } else {
                  echo "</p>";
            }
            if ($countit == 1 && !isset($prt)) {
            ?>
<hr /><p align="center">
  <a href="articles.php?lng=<?php echo $lng; ?>&amp;pg=<?php echo $pg; ?>&amp;prt=2" target="_blank"><img src="inc/img/general/print.gif" border="0" width="16" height="15" alt="<?php echo $web22; ?>" title="<?php echo $web22; ?>" />&nbsp;<?php echo $web22; ?></a>
</p>
            <?php
            }
            if ((($serviz[32] == "on" && !empty($serviz[31]) && $serviz[31] == $userprefs[1] && $countit == 1) || ($serviz[32] == "on" && $drtuser[15] == "on" && $countit == 1)) && !isset($prt)) {
            ?>
<hr /><p align="right">
    <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=art&amp;form=2&amp;id=<?php echo $pg; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/edit.gif" border="0" alt="<?php echo $web308; ?>" title="<?php echo $web308; ?>" /></a>
    <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=art&amp;act=i&amp;id=<?php echo $pg; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/desact.gif" border="0" alt="<?php echo $web333; ?>" title="<?php echo $web333; ?>" /></a>
    <a href="<?php echo CHEMIN; ?>admin/admin.php?lng=<?php echo $lng; ?>&amp;pg=art&amp;del=<?php echo $pg; ?>"><img src="<?php echo CHEMIN; ?>inc/img/general/del.gif" border="0" alt="<?php echo $web324; ?>" title="<?php echo $web324; ?>" /></a></p>
            <?php
            }
        } else {
            $countit = 0;
        }
        btable();
        if ($serviz[29] != "" && $countit == 1) {
            include("inc/boxreact.inc");
        }
    }
}
include("inc/bpage.inc");
?>
