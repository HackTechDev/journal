<?php
/*
    Admin Counter- GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.0 (06 December 2004)  : initial release by Nicolas Alves
*/

if (stristr($_SERVER["SCRIPT_NAME"], "gestcounter.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[31]=="") {
    $nomzone=$admin17;
    include("access.inc");
    exit();
  }
}
  $mod = strip_tags($mod);
  $del = strip_tags($del);
  $id = strip_tags($id);
  $docdtb = DBBASE.$id.DBEXT;
  $docinc = DBBASE.$id.DBINC;
  include(CHEMIN."inc/hpage.inc");
  if ($cnum == 1) {
    $countername = "countdwnl";
    $namecount = $admin18;
  }
  if ($cnum == 2) {
    $countername = "countart";
    $namecount = $admin5;
  }
  if ($cnum == 3) {
    $countername = "countforum";
    $namecount = $admin253;
  }
  if ($regit == 1) {
    WriteCounter($docdtb, $newcount);
  }
  if ($mod == 1) {
    htable($admin660." ".$namecount, "100%");
    $dbcounter = ReadCounter($docdtb);
    ReadDoc($docinc);
    if ($cnum == 1) {
      if ($lng == $lang[0]) {
        $txt = $admin670." ".$fieldb1;
      }
      else {
        $txt = $admin670." ".$fieldb2;
      }
    }
    if ($cnum == 2) {
      if ($lng == $lang[0]) {
        $txt = $admin671." ".$fieldb1;
      }
      else {
        $txt = $admin671." ".$fieldb2;
      }
    }
    if ($cnum == 3) {
      $txt = $admin672." ".$fieldb1;
    }
    ?>
    <p align="center"><?php echo $txt; ?></p><hr />
    <table cellspacing="0" cellpadding="0" align="center" border="0">
    <form name="gestcounter" action="admin.php?lng=<?php echo $lng; ?>" method="post">
    <input type="hidden" name="pg" value="gestcounter" />
    <input type="hidden" name="id" value="<?php echo $id; ?>" />
    <input type="hidden" name="mod" value="1" />
    <input type="hidden" name="cnum" value="<?php echo $cnum; ?>" />
    <input type="hidden" name="regit" value="1" />
    <tr>
    <td nowrap="nowrap"><p align="center"><input type="text" name="newcount" value="<?php echo $dbcounter; ?>" size="5" /></p></td>
    </tr>
    <tr><td align="center"><p>&nbsp;</p><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin38; ?>"><?php echo $admin38; ?></button><?php echo $boutonright; ?></td></tr>
    </table></form>
    <script language="javascript">
    document.gestcounter.newcount.focus();
    </script>
    <?php
    echo "<br /><p align=\"center\">[ <a href=\"admin.php?lng=".$lng."&amp;pg=".$countername."\">".$admin669." ".$namecount."</a> ]</p>";
  }
  if($del == 1){
    htable($admin666." ".$namecount, "100%");
    @chmod($docdtb, 0777);
    @unlink($docdtb);
    echo "<p align=\"center\">".$admin667."<b> ".$deldoc." </b>".$admin668."</p>";
    echo "<br /><p align=\"center\">[ <a href=\"admin.php?lng=".$lng."&amp;pg=".$countername."\">".$admin669." ".$namecount."</a> ]</p>";
  }
  ?>
  <br /><hr />
  <p align="center">
  [ <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=count"><?php echo $admin657; ?></a> || <a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b> ]</p>
  <?php
  btable();
  include(CHEMIN."inc/bpage.inc");

?>
