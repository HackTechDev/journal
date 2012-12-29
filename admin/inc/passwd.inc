<?php
/*
    Admin Password - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@aldweb.com

    Version History :
      v1.0 (30 December 2002)  : initial release
      v2.1 (10 March 2003)     : added addslashes() to var in Javascript functions (to avoid errors)
                                 focus on first field in new password input form (by B@lou and Laurent Duveau)
      v2.3 (27 July 2003)      : added forms style management (by Nicolas Alves)
      v3.0 (25 February 2004)  : added skins management (by Nicolas Alves)
      v4.0 (06 December 2004)  : added page title (by Jean-Mi)
				                 added multi-admin management (by Nicolas Alves)
      v4.6.9 (25 December 2008): added the update of the cookie GuppYAdmin and the redirection towards the Admin page
      v4.6.10 (7 September 2009)    : corrected W3C
*/

if (stristr($_SERVER["SCRIPT_NAME"], "passwd.inc")) {
    header("location:../index.php");
    die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
    include(REDACREP.$userprefs[1].INCEXT);
    if ($drtuser[9]=="") {
        $nomzone=$admin12;
        include("access.inc");
        exit();
    }
}
$rep = 0;
if ($rec == 1) {
    include("mdp.php");
    if (md5($pass1) != $mdp && $mdp != "") {
        $rep = 1;
    }
    elseif ($pass2 != $pass3 || empty($pass2)) {
        $rep = 2;
    }
    else {
        $rep = 3;
        $portalname = "GuppyAdmin";
        setcookie($portalname, crc32(md5($pass2)));
        $pass2 = md5($pass2);
        $txt = "<?php
\$mdp = \"$pass2\";
?>"; ?>
        <?php
        WriteFullDB("mdp.php", $txt);
    }
}
$topmess = $admin116;
include(CHEMIN."inc/hpage.inc");
htable($admin116, "100%");
?>
<p align="center"><?php echo $admin117; ?></p><br />
<form name="newpwd" action="admin.php?lng=<?php echo $lng; ?>" method="post">
<input type="hidden" name="rec" value="1" />
<input type="hidden" name="pg" value="passwd" />
<table cellspacing="0" cellpadding="0" align="center" summary="">
<tr><td nowrap="nowrap"><p><b><?php echo $admin118; ?></b></p></td>
<td nowrap="nowrap"><p><input class="texte" type="password" name="pass1" size="15" /></p></td></tr>
<tr><td nowrap="nowrap"><p><b><?php echo $admin119; ?></b></p></td>
<td nowrap="nowrap"><p><input class="texte" type="password" name="pass2" size="15" /></p></td></tr>
<tr><td nowrap="nowrap"><p><b><?php echo $admin120; ?></b></p></td>
<td nowrap="nowrap"><p><input class="texte" type="password" name="pass3" size="15" /></p></td></tr>
<tr><td><p>&nbsp;</p></td></tr>
<tr><td align="center" colspan="2"><p align="center"><?php echo $boutonleft; ?><input class="bouton" type="submit" value="<?php echo $admin38; ?>" title="<?php echo $admin38; ?>"/><?php echo $boutonright; ?>&nbsp;
<?php echo $boutonleft; ?><input class="bouton" type="reset" value="<?php echo $admin121; ?>" title="<?php echo $admin121; ?>"/><?php echo $boutonright; ?></p></td></tr>
</table>
</form>
<script type="text/javascript">
 document.newpwd.pass1.focus()
</script>
<hr />
<p align="center">
<a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b></p>
<?php
btable();
include(CHEMIN."inc/bpage.inc");

if ($rep == 1) {
?>
<script type="text/javascript">
 alert("<?php echo addslashes($admin122); ?>");
</script>
<?php
}
elseif ($rep == 2) {
?>
<script type="text/javascript">
 alert("<?php echo addslashes($admin123); ?>");
</script>
<?php
}
elseif ($rep == 3) {
?>
<script type="text/javascript">
 alert("<?php echo addslashes($admin124); ?>");
 document.location.href="admin.php?lng=<?php echo $lng; ?>";
</script>
<?php
}

?>
