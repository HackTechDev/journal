<?php
/*
    Forum Archiving - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
	v3.0 (25 February 2004)  : initial release
	v4.0 (06 December 2004)  : added page title (by Jean-Mi)
	                         : added extended management (by Nico)
      v4.6.10 (7 September 2009)    : corrected W3C
*/

if (stristr($_SERVER["SCRIPT_NAME"], "archive.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[7]=="") {
    $nomzone=$admin577;
    include("access.inc");
    exit();
  }
}
  $topmess = $admin578;
  include(CHEMIN."inc/hpage.inc");
  htable($admin578, "100%");
  ?>
  <p align="center"><?php echo $admin579." ".$admin580."<br />".$admin581; ?></p>
  <p>&nbsp;</p>
  <?php
  if (!empty($archgo)) {
    if ($archdate*10000 <= ReadCounter(DBFORUMARCHDATE) || $archdate*10000 > GetCurrentDateTime()) {
      $nextstep = 2;
    }
    else {
      $nextstep = 1;
    }
  }
  ?>
  <p>&nbsp;</p>
  <form name="archiveit" action="admin.php?lng=<?php echo $lng; ?>&amp;pg=archive" method="post">
  <input type="hidden" name="archgo" value="1" />
  <?php
  if (ReadCounter(DBFORUMARCHDATE) > 0) {
    ?>
    <p align="center"><?php echo $admin590." ".FormatDate(ReadCounter(DBFORUMARCHDATE)); ?></p>
    <p>&nbsp;</p>
    <?php
  }
  ?>
  <table cellspacing="0" cellpadding="2" align="center" border="0" summary="">
    <tr>
      <td><p><?php echo $admin582; ?></p></td>
      <td><input name="archdate" class="texte" type="text" size="10" value="<?php echo $archdate; ?>" title="<?php echo $archdate; ?>" /></td>
    </tr>
  </table>
  <p>&nbsp;</p>
  <p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin583; ?>"><?php echo $admin583; ?></button><?php echo $boutonright; ?></p>
  </form>
  <hr />
  <p align="center">
  <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b></p>
  <?php
  btable();
  include(CHEMIN."inc/bpage.inc");
  if ($nextstep == 1) {
    ?>
    <script language="javascript">
    PopupWindow('inc/archbatch.php?lng=<?php echo $lng; ?>&archdate=<?php echo $archdate; ?>','archbatch',400,300,'no','no')
    </script>
    <?php
  }
  elseif ($nextstep == 2) {
    ?>
    <script language="javascript">
     alert('<?php echo addslashes($admin591); ?>');
    </script>
    <?php
  }

?>
