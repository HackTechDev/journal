<?php
/*
    Maintenance Routine - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v1.0 (30 December 2002)   : initial release
      v1.9 (11 February 2003)   : added $fieldd1 and $fieldd2 updating & displaying (forgot before!)
      v2.3 (27 July 2003)       : manual maintainance form for changing characteristics of a document (creation and modification dates, author and e-mail)
      v2.4 (24 September 2003)  : added CHMOD 777 before destroying file
                                  added destroying of data/doc[n].dtb counter files
                                  added ReadDoc() function
                                  added DestroyDBFile() function
                                  created $typ_[name] variables
      v3.0 (25 February 2004)   : added skins management (by Nicolas Alves)
      v4.0 (06 December 2004)   : added new table with style color, changed text links by buttons (by icare)
                                  added multi-admin management (by Nicolas Alves)
                                  added page title (by Jean-Mi)
                                  changed display format of dates (by Icare)
      v4.5 (14 March 2005)      : added fast actions, display bugfix  (by Jean-Mi)
      v4.6.0 (04 June 2007)     : added blog types (by Icare)
      v4.6.1 (02 July 2007)     : added maintain rss feed for articles and blog (by Icare)
      v4.6.5 (10 November 2007) : added discard all (by djchouix)
      v4.6.8 (24 May 2008)      : changed include by include_once for funcrss.php (by Icare)
      v4.6.10(07 September 2009): corrected W3C
	  v4.6.19(30 March 2012)    : add social networks by Saxbar
*/

if (stristr($_SERVER["SCRIPT_NAME"],"maintain.inc")) {
  header("location:../index.php");
  die();
}

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[6]=="") {
    $nomzone=$admin170;
    include("access.inc");
    exit();
  }
}
  if ($act == "fast") {
    $dbids = explode(" ", trim($ids));
    $data = array();
    for ($ij=0; $ij < count($dbids); $ij++) {
      $ii = $dbids[$ij];
      if (${"i_".$ii} == "on") {
        $data[] = array("", $ii, "i");
      }
      elseif (${"s_".$ii} == "on") {
        $data[] = array("", $ii, "s");
      }
    }
    unset($dbids);
    $dbdocid = ReadDBFields(DOCID);
    foreach($dbdocid as $i=>$d) {
      $idx[$d[1]] =  $i;
    }
    $types = array();
    for ($i = 0; $i < count($data); $i++) {
        ReadDoc(DBBASE.$data[$i][1]);
        $types[] = $type;
        switch ($data[$i][2]) {
        case "i" :
            $status  = $data[$i][2];
            $author  = addslashes($author);
            $email   = addslashes($email);
            $fielda1 = addslashes($fielda1);
            $fielda2 = addslashes($fielda2);
            $fieldb1 = addslashes($fieldb1);
            $fieldb2 = addslashes($fieldb2);
            $fieldc1 = addslashes($fieldc1);
            $fieldc2 = addslashes($fieldc2);
            $fieldd1 = addslashes($fieldd1);
            $fieldd2 = addslashes($fieldd2);
            if($data[$i][0] == TYP_FORUM || $data[$i][0] == TYP_THREAD) {
                $fieldweb  = addslashes($fieldweb);
                $fieldmail = addslashes($fieldmail);
                $fieldmod = addslashes($fieldmod);
            }
            WriteDoc();
            $dbdocid[$idx[$data[$i][1]]][2] = $data[$i][2];
            break;
        case "s" :
            DestroyDBFile(DBBASE.$data[$i][1].INCEXT);
            DestroyDBFile(DBBASE.$data[$i][1].DBEXT);
            DestroyDBFile(DBIPBASE.$data[$i][1].DBEXT);
            unset($dbdocid[$idx[$data[$i][1]]]);
            break;
        }
    }
    unset($idx);
    if (count($data) > 0) {
      usort($dbdocid, "compare_id1");
      WriteDBFields(DOCID, $dbdocid);
      unset($dbdocid, $data);
      $uniq_types = array_unique($types);
      unset($types);
      foreach($uniq_types as $type) {
        if (in_array($type, array(TYP_ART, TYP_BLOG, TYP_LINKS, TYP_DNLOAD, TYP_PHOTO, TYP_FAQ, TYP_RSS, TYP_AGENDA, TYP_SOCNET))) {
            UpdateDBdtb($type);
            if ($type == TYP_ART) {
				include_once(CHEMIN.INCREP."funcrss.php");
				UpdateDBart();
            }
            if ($type == TYP_BLOG) {
				include_once(CHEMIN.INCREP."funcrss.php");
				UpdateDBblog();
            }
        }
        elseif ($type == TYP_NEWS) {
            include_once(CHEMIN.INCREP."funcrss.php");
            UpdateDBnews();
        }
        elseif ($type == TYP_REACT) {
            UpdateDBreact("", 0);
        }
        elseif ($type == TYP_REBLOG) {
            UpdateDBreblog("", 0);
        }
        elseif ($type == TYP_FORUM) {

          $db1 = SelectDBFields(TYP_FORUM, "a", "");
          sort($db1);
          for ($i = 0; $i < count($db1); $i++) {
            ReadDoc(DBBASE.$db1[$i][1]);
            $db2[$i][0] = $creadate;
            $db2[$i][1] = $fielda1;
            $db2[$i][2] = $fielda2;
            $db2[$i][3] = $fileid;
            $db2[$i][4] = RemoveConnector($author);
            $db2[$i][5] = RemoveConnector($email);
            $db2[$i][6] = RemoveConnector($fieldb1);
            $db2[$i][7] = $fieldd1;
            $db2[$i][8] = $fieldb2;
            $db2[$i][9] = $fieldmail;
          }
          unset($db1);
          @sort($db2,SORT_REGULAR);
          WriteDBFields(DBTHREAD, $db2);

          @usort($db2, "compare_db2");
          $db3 = array();
          $j = 0;
          for ($i = 0; $i < count($db2); $i++) {
            if ($db2[$i][2] == "0") {
              $db3[$j][0] = $db2[$i][0];
              $db3[$j][1] = $db2[$i][1];
              $db3[$j][2] = $db2[$i][3];
              $db3[$j][3] = $db2[$i][4];
              $db3[$j][4] = $db2[$i][5];
              $db3[$j][5] = $db2[$i][6];
              $db3[$j][6] = $db2[$i][0];
              $db3[$j][7] = 0;
              $db3[$j][8] = "";
              $db3[$j][9] = "";
              $db3[$j][10] = $db2[$i][7];
              $db3[$j][11] = "";
              $db3[$j][12] = $db2[$i][8];
              $k = 1;
              while(($i + $k < count($db2)) && ($db2[$i][1] == $db2[$i + $k][1])){
                $db3[$j][0]  = $db2[$i + $k][0];
                $db3[$j][7]++;
                $db3[$j][8]  = $db2[$i + $k][4];
                $db3[$j][9]  = $db2[$i + $k][5];
                $db3[$j][11] = $db2[$i + $k][7];
                $k++;
              }
              $i += $k - 1;
              $j++;
            }
          }
          unset($db2);
          @rsort($db3,SORT_REGULAR);
          WriteDBFields(DBFORUM, $db3);
          unset($db3);
        }
      }
    }
  }
  elseif (!empty($modify)) {
    ReadDoc(DBBASE.$modify);
    $creadate = $mcreadate;
    $moddate = $mmoddate;
    $author = addslashes(stripslashes($mauthor));
    $email = addslashes(stripslashes($memail));
    $fielda1 = addslashes($fielda1);
    $fielda2 = addslashes($fielda2);
    $fieldb1 = addslashes($fieldb1);
    $fieldb2 = addslashes($fieldb2);
    $fieldc1 = addslashes($fieldc1);
    $fieldc2 = addslashes($fieldc2);
    $fieldd1 = addslashes($fieldd1);
    $fieldd2 = addslashes($fieldd2);
    if ($type == TYP_FORUM) {
      $fieldweb  = addslashes($fieldweb);
      $fieldmail = addslashes($fieldmail);
      $fieldmod = addslashes($fieldmod);
    }
    $rec = "<?php
  \$type = \"$type\";
  \$fileid = \"$fileid\";
  \$status = \"$status\";
  \$creadate = \"$creadate\";
  \$moddate = \"$moddate\";
  \$author = stripslashes(\"$author\");
  \$email = stripslashes(\"$email\");
  \$fielda1 = stripslashes(\"$fielda1\");
  \$fielda2 = stripslashes(\"$fielda2\");
  \$fieldb1 = stripslashes(\"$fieldb1\");
  \$fieldb2 = stripslashes(\"$fieldb2\");
  \$fieldc1 = stripslashes(\"$fieldc1\");
  \$fieldc2 = stripslashes(\"$fieldc2\");
  \$fieldd1 = stripslashes(\"$fieldd1\");
  \$fieldd2 = stripslashes(\"$fieldd2\");";
  if ($type == TYP_FORUM) {
    $rec .= "
    \$fieldweb = stripslashes(\"$fieldweb\");
    \$fieldmail = stripslashes(\"$fieldmail\");
    \$fieldmod = stripslashes(\"$fieldmod\");";
   }
   $rec.= "?>";
    WriteFullDB(DBBASE.$fileid.INCEXT,$rec);
  }
// Insertion javascript
 $headinc .= '<script type="text/javascript" src="'.CHEMIN.'admin/inc/maintain.js"></script>';
// Fin insertion javascript
  $topmess = $admin192;
  include(CHEMIN."inc/hpage.inc");
  htable($admin192, "100%");
  echo "<div align=\"center\">";
  ?>
  <p align="center"><?php echo $admin221; ?></p><hr />
  <?php
  if (empty($see) && empty($mod)) {
    $dbwork = SelectDBFieldsByStatus(ReadDBFields(DOCID),"d");
    @rsort($dbwork);
    if (count($dbwork) > 0) {
      echo "<form name=\"fast_actions\" action=\"admin.php?lng=".$lng."&amp;pg=maintain&amp;act=fast\" method=\"post\">";
     echo '<input type="hidden" id="lang_maintain_js"  value="'.$admin60.': '.strtolower($admin893).'" />';
      echo "<div align=\"right\" style=\"width:96%;padding-right:25px\">".$boutonleft."<button type=\"submit\" title=\"".$web361."\">".$web361."</button>".$boutonright;
      echo " <img src=\"".CHEMIN."inc/img/general/bas.gif\" alt=\"\" />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div>";
      echo "<table id=\"tableDB\" cellpadding=\"4\" width=\"96%\" border=\"0\" summary=\"\"><tr class=\"forum\"><td>Id/Type</td><td>".$admin679."</td><td>".$admin680."</td></tr>";

      $ids = "";
      $flng = ($lng == $lang[0]);
      $format_nextid = "%".ceil(log10(ReadCounter(NEXTID)))."u";
      $format_fr = "%".ceil(log10(ReadCounter(DBFORUMCOUNTER)))."u";
      for ($i = 0; $i < count($dbwork); $i++) {
        ReadDoc(DBBASE.$dbwork[$i][1]);

        $fielda1 = strip_tags(str_replace("<!--", "", str_replace("-->", " ", $fielda1)));
        $fielda2 = strip_tags(str_replace("<!--", "", str_replace("-->", " ", $fielda2)));
        $fieldb1 = strip_tags(str_replace("<!--", "", str_replace("-->", " ", $fieldb1)));
        $fieldb2 = strip_tags(str_replace("<!--", "", str_replace("-->", " ", $fieldb2)));
        $fieldc1 = strip_tags(str_replace("<!--", "", str_replace("-->", " ", $fieldc1)));
        $fieldc2 = strip_tags(str_replace("<!--", "", str_replace("-->", " ", $fieldc2)));
        $champs0 = "";
        $champs1 = "";
        $champs2 = "";

        switch ($type) {
        case TYP_GUESTBK :
          $champs1 = $admin175.$fielda1." - ";
          $champs2 = $author;
          break;
        case TYP_BANNER :
          $champs1 = $fieldb1." - ";
          $champs2 = $fielda1;
          break;
        case TYP_REACT :
          $champs0 = $web292.Formatage($format_nextid, $fielda2)." - ";
          $champs1 = $admin175.Formatage("%' 2u", $fielda1)." - ";
          $champs2 = $author;
          break;
        case TYP_REBLOG :
          $champs0 = $web292.Formatage($format_nextid, $fielda2)." - ";
          $champs1 = $admin175.Formatage("%' 2u", $fielda1)." - ";
          $champs2 = $author;
          break;
        case TYP_NEWS :
          $champs1 = ($flng ? $fieldb1 : $fieldb2)." - ";
          $champs2 = $author;
          break;
        case TYP_NWL :
        case TYP_SOCNET :
          $champs1 = ($flng ? $fieldb1 : $fieldb2);
          break;
        case TYP_FORUM :
          if ($fielda2 == "0") {
              $champs1 = $admin208.Formatage($format_fr, $fielda1)." + ";
              $champs2 = "<b>".$fieldb1."</b>";
          }
          else {
              $champs1 = $admin208.Formatage($format_fr, $fielda1)." - ";
              $champs2 = $admin209.Formatage("%' 2u", $fielda2);
          }
          break;
        case TYP_ART :
          if ($serviz[3] == "on" && $serviz[22] == "on") {
            if ($fieldd1 == "right") {
                $champs0 = $admin353." ";
            }
            else {
                $champs0 = $admin352." ";
            }
            if (empty($fielda1)) {
                $champs0 = $admin681." ";
            }
          }
          $champs1 = ($flng ? $fielda1 : $fielda2)." - ";
          $champs2 = ($flng ? $fieldb1 : $fieldb2);
          break;
        case TYP_BLOG :
          if ($serviz[54] == "on" && $serviz[55] == "on") {
            if ($fieldd1 == "right") {
                $champs0 = $admin353." ";
            }
            else {
                $champs0 = $admin352." ";
            }
            if (empty($fielda1)) {
                $champs0 = $admin681." ";
            }
          }
          $champs1 = ($flng ? $fielda1 : $fielda2)." - ";
          $champs2 = ($flng ? $fieldb1 : $fieldb2);
          break;
        break;
        case TYP_DNLOAD :
        case TYP_FAQ :
        case TYP_LINKS :
        case TYP_PHOTO :
        case TYP_RSS :
        case TYP_BSS :
          $champs1 = ($flng ? $fielda1 : $fielda2)." - ";
          $champs2 = ($flng ? $fieldb1 : $fieldb2);
          break;
        case TYP_THINK :
          $champs1 = ($flng ? $fieldb1 : $fieldb2)." - ";
          $champs2 = ($flng ? $fieldc1 : $fieldc2);
          break;
        case TYP_RECO :
          $champs1 = $fieldb1." - ";
          $champs2 = ($flng ? $fieldc1 : $fieldc2);
          break;
        case TYP_AGENDA :
          $champs1 = $fielda1." - ";
          $champs2 = ($flng ? $fieldc1 : $fieldc2);
          break;
        }

        if ($i %2 == 0)
          echo "<tr class=\"quest\">";
        else
          echo "<tr class=\"rep\">";
          ?>
          <td style="white-space: nowrap;"><b>
          <?php
          echo $fileid." - ".$type;
          ?>
          </b></td>
          <td style="width:100%;text-align:left;">
          <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=maintain&amp;see=<?php echo $fileid; ?>" title="<?php echo $admin190; ?>"><img src="inc/img/files/look.gif" border="0" alt="<?php echo $admin190; ?>" title="<?php echo $admin190; ?>" /></a>
          <a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=maintain&amp;mod=<?php echo $fileid; ?>" title="<?php echo $admin33; ?>"><img src="inc/img/files/edit.gif" border="0" alt="<?php echo $admin33; ?>" title="<?php echo $admin33; ?>" /></a>
          <?php
          echo $champs0."<b>".$champs1."</b>".$champs2;
          ?>
          </td><td style="white-space: nowrap;">
          <?php
          MakeRadioGroup(array( array("d", "i", $fileid), array("d", "s", $fileid)));
          ?>
          </td></tr>
          <?php
          $ids .= $fileid." ";
        }
        ?>
        </table>
        <?php
        echo "<input type=\"hidden\" name=\"ids\" value=\"".$ids."\" />";
        echo "<div align=\"right\" style=\"width:90%; padding-right:10px;\">".$boutonleft."<button type=\"submit\" title=\"".$web361."\">".$web361."</button>".$boutonright;
        echo " <img src=\"".CHEMIN."inc/img/general/up1.gif\" alt=\"\" /></div>";
        echo "</form>";
      }
      else {
        echo '<p style="text-align: center;">'.$admin854.'</p>';
      }
      ?>
      <div align="center">
      <hr /><a href="admin.php?lng=<?php echo $lng; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b>
      </div>
      <?php
      }
      elseif (!empty($see)) {
    ReadDoc(DBBASE.$see);
    $datecrea= FormatDate($creadate); $datemod= FormatDate($moddate);
    ?>
    <table>
    <tr><td nowrap="nowrap">&nbsp;&nbsp;</td><td nowrap="nowrap"><b><?php echo $admin193; ?></b></td><td><?php echo $fileid; ?></td></tr>
    <tr><td nowrap="nowrap">&nbsp;</td><td nowrap="nowrap"><b><?php echo $admin194; ?></b></td><td><?php echo $type; ?></td></tr>
    <tr><td nowrap="nowrap">&nbsp;</td><td nowrap="nowrap"><b><?php echo $admin195; ?></b></td><td><?php echo $status; ?></td></tr>
    <tr><td nowrap="nowrap">&nbsp;</td><td nowrap="nowrap"><b><?php echo $admin196; ?></b></td><td><?php echo $datecrea; ?></td></tr>
    <tr><td nowrap="nowrap">&nbsp;</td><td nowrap="nowrap"><b><?php echo $admin197; ?></b></td><td><?php echo $datemod; ?></td></tr>
    <tr><td nowrap="nowrap">&nbsp;</td><td nowrap="nowrap"><b><?php echo $admin198; ?></b></td><td><?php echo $author; ?></td></tr>
    <tr><td nowrap="nowrap">&nbsp;</td><td nowrap="nowrap"><b><?php echo $admin199; ?></b></td><td><?php echo $email; ?></td></tr>
    </table><hr />
    <?php
    if (!empty($fielda1)) {
      echo "<p>".$fielda1."</p><hr />";
    }
    if (!empty($fielda2)) {
      echo "<p>".$fielda2."</p><hr />";
    }
    if (!empty($fieldb1)) {
      echo "<p>".$fieldb1."</p><hr />";
    }
    if (!empty($fieldb2)) {
      echo "<p>".$fieldb2."</p><hr />";
    }
    if (!empty($fieldc1)) {
      echo "<p>".$fieldc1."</p><hr />";
    }
    if (!empty($fieldc2)) {
      echo "<p>".$fieldc2."</p><hr />";
    }
    if (!empty($fieldd1)) {
      echo "<p>".$fieldd1."</p><hr />";
    }
    if (!empty($fieldd2)) {
      echo "<p>".$fieldd2."</p><hr />";
    }
    ?>
    <p>&nbsp;</p>
    <p align="center"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=maintain"><?php echo $admin191; ?></a></p>
    <?php
  }
  else {
    ReadDoc(DBBASE.$mod);
    ?>
    <form name="hardmod" action="admin.php?lng=<?php echo $lng; ?>&amp;pg=maintain" method="post">
    <input type="hidden" name="modify" value="<?php echo $mod; ?>" />
    <table>
    <tr><td nowrap="nowrap">&nbsp;&nbsp;</td><td nowrap="nowrap"><b><?php echo $admin193; ?></b></td><td><?php echo $fileid; ?></td></tr>
    <tr><td nowrap="nowrap">&nbsp;</td><td nowrap="nowrap"><b><?php echo $admin194; ?></b></td><td><?php echo $type; ?></td></tr>
    <tr><td nowrap="nowrap">&nbsp;</td><td nowrap="nowrap"><b><?php echo $admin195; ?></b></td><td><?php echo $status; ?></td></tr>
    <tr><td nowrap="nowrap">&nbsp;</td><td nowrap="nowrap"><b><?php echo $admin196; ?></b></td><td><input class="texte" type="text" name="mcreadate" size="20" value="<?php echo $creadate; ?>" /></td></tr>
    <tr><td nowrap="nowrap">&nbsp;</td><td nowrap="nowrap"><b><?php echo $admin197; ?></b></td><td><input class="texte" type="text" name="mmoddate" size="20" value="<?php echo $moddate; ?>" /></td></tr>
    <tr><td nowrap="nowrap">&nbsp;</td><td nowrap="nowrap"><b><?php echo $admin198; ?></b></td><td><input class="texte" type="text" name="mauthor" size="30" value="<?php echo $author; ?>" /></td></tr>
    <tr><td nowrap="nowrap">&nbsp;</td><td nowrap="nowrap"><b><?php echo $admin199; ?></b></td><td><input class="texte" type="text" name="memail" size="40" value="<?php echo $email; ?>" /></td></tr>
    </table><hr />
    <?php
    if (!empty($fielda1)) {
      echo "<p>".$fielda1."</p><hr />";
    }
    if (!empty($fielda2)) {
      echo "<p>".$fielda2."</p><hr />";
    }
    if (!empty($fieldb1)) {
      echo "<p>".$fieldb1."</p><hr />";
    }
    if (!empty($fieldb2)) {
      echo "<p>".$fieldb2."</p><hr />";
    }
    if (!empty($fieldc1)) {
      echo "<p>".$fieldc1."</p><hr />";
    }
    if (!empty($fieldc2)) {
      echo "<p>".$fieldc2."</p><hr />";
    }
    if (!empty($fieldd1)) {
      echo "<p>".$fieldd1."</p><hr />";
    }
    if (!empty($fieldd2)) {
      echo "<p>".$fieldd2."</p><hr />";
    }
    ?>
    <p>&nbsp;</p>
    <p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin38; ?>"><?php echo $admin38; ?></button><?php echo $boutonright; ?></p>
    </form>
    <p align="center"><a href="admin.php?lng=<?php echo $lng; ?>&amp;pg=maintain"><?php echo $admin191; ?></a></p>
    <?php
  }
  echo "</div>";
  btable();
  include(CHEMIN."inc/bpage.inc");

?>
