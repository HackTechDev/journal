<?php
/*
    Best of The Guestbook - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v2.4 (24 September 2003)     : initial release
      v4.0 (06 December 2004)      : added alt tags to img and removed border tag for non-linked img (by Isa)
                                     removed the trans pixel (by Isa)
                                     replaced & by &amp; in URL for standard compliance (by Isa)
                                     added new colored appearance and submit button (by Icare)
      v4.6.6 (14 April 2008)       : added urlencode to $author (by JeanMi)
      v4.6.10 (7 September 2009)   : corrected #274
	  v4.6.20 (24 May 2012)        : corrected btable (by Saxbar)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "boxguest.inc")) {
    header("location:../index.php");
    die();
}

if ($serviz[12] == "on" && $site[21] > 0) {
    $messok = false;
    if (count(SelectDBFields(TYP_GUESTBK,"a",$site[21])) != 0) {
        $messok = true;
    }
    $topmess = ( $lng == $lang[0] ? $nom[9] : $nom[19] )." - ".$web180;
    if ($page[9] != "") {
        $topmess = "<img src=\"".CHEMIN."inc/img/icons/".$page[9]."/guestbook.gif\" align=\"right\" width=\"32\" height=\"32\" alt=\"guestbook.gif\"/>".$topmess;
    }
    htable($topmess, "100%");
    if ($members[0]=="on" && $userprefs[1]=="" && $members[12]=="on") {
        echo "<p align=\"center\">".$web342."</p><br />";
        echo "<p align=\"center\">[ <a href=\"".CHEMIN."user.php?lng=".$lng."\">".$web343."</a> ]</p><br />";
    }
    else {
        ?>
        <br />
        <form action="<?php echo CHEMIN ?>postguest.php?lng=<?php echo $lng."&amp;typ=".TYP_GUESTBK; ?>" method="post">
        <p align="center">
        <?php echo $boutonleft; ?><button type="submit" title="<?php echo $web41; ?>"><?php echo $web41; ?></button><?php echo $boutonright; ?></p>
        </form>
        <hr />
        <?php
        if ($messok) {
            ReadDoc(DBBASE.$site[21]);
        ?>
        <center>
        <table width="98%" summary="">
        <tr><td class="forum" width="10%"><?php echo $web39.$fielda1; ?></td>
        <td class="forum2">
        <?php
            echo $web6." ";
            if ($fieldd1 != "on") {
                $em = BreakEMail($email);
        ?>
        <b><a href="JavaScript:WriteMailTo('<?php echo addslashes(urlencode($author)); ?>','<?php echo $em[0]; ?>','<?php echo $em[1]; ?>','<?php echo $em[2]; ?>')"><?php echo addslashes($author); ?></a></b>
        <?php
            }
            else {
                echo "<b>".$author."</b>";
            }
            echo " ".$web7." ".FormatDate($creadate);

            if (!empty($fieldb1)) {
                echo '<br />&nbsp;&nbsp;&nbsp;&nbsp;';
                echo '<img src="inc/img/general/gbkurl.gif" width="17" height="17" alt="*"/>&nbsp;&nbsp;<a href="'.$fieldb1.'" target="_blank">'.$fieldb1.'</a>';
            }
            echo '</td></tr><tr><td colspan="2" style="text-align:left;">'.$fieldc1;
            echo '</td></tr>';
            echo '</table></center><hr />';
        }
    }
    btable($topmess);
}
?>
