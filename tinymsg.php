<?php
/*
    Tiny Messages - GuppY PHP Script -  version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v2.4 (24 September 2003)    : initial release (by Nicolas Alves and Laurent Duveau)
      v2.4p4 (04 October 2003)    : XSS security correction in the tiny-message module (by frog-m@n, http://www.phpsecure.info, thanks)
      v3.0 (25 February 2004)     : added skins (by Nicolas Alves)
                                    added UID management for Tiny Messages and check if Pseudo is already taken
                                    added check for too long words (to avoid screen disalignment)
                                    added focus on message entry area (by B@lou)
      v4.0 (06 December 2004)     : new release (by Nicolas Alves)
                                    modified tables and added style management in td tags, increased timeout on sending tinymessage (by Icare)
      v4.5 (15 February 2005)     : added controls (by Jean-Mi)
      v4.6.0 (04 June 2007)       : added smileys usage (by Icare)
                                  : added global delete (by djchouix)
      v4.6.5 (05 December 2007)   : corrected define (by Icare, thanks irk4z)
      v4.6.7  (23 April 2008)     : deleted putBR for $msg, corrected cr/lf translation (by Icare))
      v4.6.10 (7 September 2009)    : corrected #274
      v4.6.11 (11 December 2009)    : changed width by style=width for cells
      v4.6.14(14 February 2011)  : corrected links pgeditor (thanks Icare - thanks zet)
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");
$action = strip_tags($action);
$fic = strip_tags($fic);
$form = strip_tags($form);
$id = strip_tags($id);
$ancienmsg = addslashes($ancienmsg);
$msg = strip_tags(addslashes($msg));
$maxcar = "1500"; // max length of tiny messages in chr

include("inc/hpage.inc");
htable($web215." - ".$userprefs[1], "100%");
$from = KeepGoodChars(CutLongWord(strip_tags($from),20));
$to = KeepGoodChars(CutLongWord(strip_tags($to),20));

if (empty($userprefs[1])) {
    echo "<strong>".$web357."</strong><br /><br />".$web358."<br />";
    btable();
    include("inc/bpage.inc");
    exit;
}

function UpdateFicForm($fic, $form, $id) {
  $array = explode("\n", fread(fopen($fic, "r"), filesize($fic)));
  $delete = array_pop($array);
  $new = $form;
  $array[$id] = $new;
  $fhandle = fopen($fic,"w");
  for($a=0;$a< count($array);$a++) {
    fwrite($fhandle,stripslashes($array[$a])."\n");
  }
  fclose($fhandle);
}

if ($action == 1) {
    $from = $userprefs[1];
    if (empty($to)) {
        echo "<strong>".$web357."</strong><br /><br />".$web359."<br />";
        btable();
        include("inc/bpage.inc");
        exit;
    }
  ?>
  <script language="javascript" type="text/javascript" src="<?php echo CHEMIN; ?>inc/tinymsg.js"></script>
  <table width="100%" align="center" summary="">
  <tr><td>
  <form name="nmsgr" action="tinymsg.php?action=2" method="post">
  <input type="hidden" name="to" value="<?php echo $to; ?>" />
  <input type="hidden" name="lng" value="<?php echo $lng; ?>" />
  <input type="hidden" name="from" value="<?php echo $from; ?>" />
  <p>
  <?php
  echo $web208."&nbsp;&nbsp;<strong>".$from."</strong><br />";
  echo $web204."&nbsp;&nbsp;<strong>".$to."</strong>";
  ?>
  </p>
  <table cellpadding="5" width="80%" align="center" border="0" summary="">
  <?php
  if (FileDBExist(USEREP.$userprefs[1].DBEXT)) {
    $dbmsg = ReadDBFields(USEREP.$userprefs[1].DBEXT);
    if ($id != "") {
      if ($dbmsg[0][0] == $userprefs[7]) {
        if ($dbmsg[$id][3] == "new") {
          $dbmsg[$id][3] = "lu";
          UpdateFicForm(USEREP.$userprefs[1].DBEXT, $dbmsg[$id][0].CONNECTOR.$dbmsg[$id][1].CONNECTOR.$dbmsg[$id][2].CONNECTOR.$dbmsg[$id][3].CONNECTOR.$dbmsg[$id][4].CONNECTOR.$dbmsg[$id][5].CONNECTOR.$dbmsg[$id][6].CONNECTOR.$dbmsg[$id][7], $id);
        }
      }
      ?>
      <tr><td><input type="hidden" name="anciendate" value="<?php echo $dbmsg[$id][1]; ?>" /></td></tr>
      <tr><td align="center"><p align="center"><?php echo $web216; ?></p>
      <input type="hidden" name="ancienmsg" value="<?php echo stripslashes($dbmsg[$id][2]); ?>" />
      <div class="rep" style="height:80px;width:330px;overflow:auto;border:1px solid;"><?php echo stripslashes(souriez($dbmsg[$id][2])); ?></div>
      </td></tr>
      <?php
    }
  }
  ?>
  <tr><td align="center"><p align="center"><?php echo $web56; ?></p></td></tr>
  <tr><td style="width:100%;text-align:center"><textarea name="msg" rows="5" cols="40"></textarea></td></tr>
  <tr><td align="center" style="vertical-align:middle">
    <a href="javascript: format('b')"><img class="clsCursor" border="0" src="inc/pgeditor/images/bold.gif" alt="<?php echo $web98; ?>" title="<?php echo $web98; ?>" /></a>&nbsp; 
    <a href="javascript: format('i')"><img class="clsCursor" border="0" src="inc/pgeditor/images/italic.gif" alt="<?php echo $web100; ?>" title="<?php echo $web100; ?>" /></a>&nbsp;
    <a href="javascript: format('u')"><img class="clsCursor" border="0" src="inc/pgeditor/images/underline.gif" alt="<?php echo $web99; ?>" title="<?php echo $web99; ?>" /></a>&nbsp;
    <a href="javascript: dolink ('href=http://<?php echo $admin457; ?>')"><img class="clsCursor" border="0" src="inc/pgeditor/images/link.gif" alt="<?php echo $web170; ?>" title="<?php echo $web170; ?>" /></a>&nbsp;  &nbsp;
    <?php DrawSmileys(""); ?></td></tr>
  </table>
  <p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $web52; ?>"><?php echo $web52; ?></button><?php echo $boutonright; ?>&nbsp;<?php echo $boutonleft; ?><button type="reset" title="<?php echo $web205; ?>"><?php echo $web205; ?></button><?php echo $boutonright; ?></p>
  </form></td></tr></table>
  <script type="text/javascript">
   document.nmsgr.msg.focus()
  </script>
  <br /><p align="center"><a href="tinymsg.php?lng=<?php echo $lng; ?>&action=3"><img src="<?php echo CHEMIN ?>inc/img/general/back.gif" border="0" alt="<?php echo $web135; ?>" title="<?php echo $web135; ?>" /></a></p>
  <?php
}
elseif ($action == 2) {
    $from = $userprefs[1];
    if (empty($to)) {
        echo "<p><strong>".$web357."</strong><br /><br />".$web359."</p>";
        btable();
        include("inc/bpage.inc");
        exit;
    }
  if (strlen($msg) > $maxcar) {
  ?>
  <script type="text/javascript">
   alert('<?php echo strlen($msg)." ".$web408." ".$maxcar.")"; ?>');
   history.back();
  </script>
  <?php
  exit;
  }
  $msg = str_replace(chr(10),"<br />",$msg);
  $msg = str_replace(chr(13),"",$msg);
  $msg = str_replace("[b]","<b>",$msg);
  $msg = str_replace("[/b]","</b>",$msg);
  $msg = str_replace("[i]","<i>",$msg);
  $msg = str_replace("[/i]","</i>",$msg);
  $msg = str_replace("[u]","<u>",$msg);
  $msg = str_replace("[/u]","</u>",$msg);
  $msg = str_replace("[l]href=","<a href='",$msg);
  $msg = str_replace("[/l]","' target='_blank'><img src='".CHEMIN."inc/img/general/site.gif' border='0' alt='".$web304."' /></a>",$msg);
  $msg = str_replace("\"","'",$msg);
  $dbmsg = array();
  if (FileDBExist(USEREP.$to.DBEXT)) {
    $dbmsg[0] = $from;
    $dbmsg[1] = GetCurrentDateTime();
    $dbmsg[2] = RemoveConnector(stripslashes($msg));
    $dbmsg[3] = "new";
    $dbmsg[4] = "";
    $dbmsg[5] = RemoveConnector(stripslashes($ancienmsg));
    $dbmsg[6] = $anciendate;
    $dbmsg[7] = $userprefs[8];
    AppendDBFields(USEREP.$to.DBEXT, $dbmsg);
    $dbmsg[0] = $to;
    $dbmsg[1] = GetCurrentDateTime();
    $dbmsg[2] = RemoveConnector(stripslashes($msg));
    $dbmsg[3] = "lu";
    $dbmsg[4] = "send";
    $dbmsg[5] = RemoveConnector(stripslashes($ancienmsg));
    $dbmsg[6] = $anciendate;
    $dbmsg[7] = $userprefs[8];
    AppendDBFields(USEREP.$from.DBEXT, $dbmsg);
    ?>
    <br /><div align="center"><p><?php echo $web332; ?><br />
    <br /><a href="tinymsg.php?lng=<?php echo $lng; ?>&action=3"><img src="<?php echo CHEMIN; ?>inc/img/general/back.gif" border="0" alt="<?php echo $web135; ?>" title="<?php echo $web135; ?>" /></a></p>
    </div>
    <form name="suit2" action="tinymsg.php?action=3" method="post"></form>
    <script type="text/javascript">
     setTimeout("document.suit2.submit();",4000);
    </script>
    <?php
    }
    else {
    ?>
    <br /><p align="center"><?php echo $web230; ?></p>
    <?php
 }
}
elseif ($action == 3) { //Gérer les tinymsg
    $nbrtinymsg = ReadDBFields(USEREP.$userprefs[1].DBEXT);
    if(count($nbrtinymsg) > ($serviz[48]+2)) {
        DeleteDBFieldById(USEREP.$userprefs[1].DBEXT, 2);
    }
    $dbmsg = Array();
  if (FileDBExist(USEREP.$userprefs[1].DBEXT)) {
    $dbmsg = ReadDBFields(USEREP.$userprefs[1].DBEXT);
    if ($dbmsg[0][0] == $userprefs[7]) {
      ?>
	  <script type="text/javascript">
		function selectAllMsg(opt)
		{
			var option = opt.name;
			var allSelected = opt.checked;
			switch (option) {
				case 'delRecu_all' :
					var allMsg = document.forms['boxtinymsg'].elements['delRecu_id[]'];
					break;
				case 'delSend_all' :
					var allMsg = document.forms['boxtinymsg'].elements['delSend_id[]'];
					break;
				default :
					return false;
			}

			if (allMsg.length != undefined) {
				for (i = 0; i < allMsg.length; i++) {
					allMsg[i].checked = (allSelected)? true : false;
				}
			} else {
				allMsg.checked = (allSelected)? true : false;
			}
			return false;
		}

		function verifyTinyMsgChecked()
		{
			var error = true;
			var message = "<?php echo $web428; ?>";

			if (document.forms['boxtinymsg'].elements['delRecu_id[]']) {
				var allMsgRecu = document.forms['boxtinymsg'].elements['delRecu_id[]'];
				if (allMsgRecu.length != undefined) {
					for (i = 0; i < allMsgRecu.length; i++) {
						if (allMsgRecu[i].checked) { error = false; }
					}
				} else {
					if (allMsgRecu.checked) { error = false; }
				}
			}

			if (document.forms['boxtinymsg'].elements['delSend_id[]']) {
				var allMsgSend = document.forms['boxtinymsg'].elements['delSend_id[]'];
				if (allMsgSend.length != undefined) {
					for (i = 0; i < allMsgSend.length; i++) {
						if (allMsgSend[i].checked) { error = false; }
					}
				} else {
					if (allMsgSend.checked) { error = false; }
				}
			}

			if (error) {
				alert(message);
				return false;
			} else {
				return true;
			}
		}
	  </script>

      <p align="center"><?php echo "$web291 $serviz[48] $web335"; ?></p>
      <p align="center"><img src="<?php echo CHEMIN ?>inc/img/general/new.gif" border="0" alt="<?php echo $web211; ?>" title="<?php echo $web211; ?>" /> <?php echo $web211; ?>&nbsp;&nbsp;&nbsp;&nbsp;<img src="<?php echo CHEMIN ?>inc/img/general/lu.gif" border="0" alt="<?php echo $web209; ?>" title="<?php echo $web209; ?>" /> <?php echo $web209; ?></p>
      <hr />
	  <form name="boxtinymsg" action="tinymsg.php" method="post" onsubmit="return verifyTinyMsgChecked(); return false;">
	  <input type="hidden" name="lng" value="<?php echo $lng; ?>" />
	  <input type="hidden" name="action" value="5" />
      <table width="400"  align="center" summary="">
      <tr><td colspan="5"><p><strong><?php echo $web207; ?></strong></p></td></tr>
      <tr class="forum" align="center">
      <td style="width:10%"><strong><?php echo $web206; ?></strong></td>
      <td style="width:35%"><strong><?php echo $web210; ?></strong></td>
      <td style="width:35%"><strong><?php echo $web325; ?></strong></td>
      <td style="width:20%" colspan="2"><strong><?php echo $web323; ?></strong></td>
	  </tr>
      <?php
	  $nbMsgRecu = 0;
      for ($i = 2; $i < count($dbmsg); $i++) {
        if ($dbmsg[$i][4] != "send") {
          if ($dbmsg[$i][3] == "new") {
              $tdcolor = "class=\"quest\"";
           }
          elseif ($dbmsg[$i][3] == "lu") {
            $tdcolor = "class=\"rep\"";
          }
          ?>
          <tr <?php echo $tdcolor; ?> style="text-align:center;padding:8px 0px;">
          <td style="width:10%"><img src="<?php echo CHEMIN ?>inc/img/general/<?php echo $dbmsg[$i][3]; ?>.gif" border="0" alt="<?php echo$dbmsg[$i][3]; ?>" title="<?php echo$dbmsg[$i][3]; ?>" /></td>
          <td style="width:35%;text-align:left;padding:8px 4px;"><a href="tinymsg.php?lng=<?php echo $lng; ?>&action=1&id=<?php echo $i; ?>&to=<?php echo $dbmsg[$i][0]; ?>&from=<?php echo $userprefs[1]; ?>" title="<?php echo $web140 ?>"><strong><?php echo $dbmsg[$i][0]; ?></strong></a></td>
          <td style="width:35%"><?php echo FormatDate($dbmsg[$i][1]); ?></td>
          <td style="width:8%"><a href="tinymsg.php?lng=<?php echo $lng; ?>&action=4&id=<?php echo $i; ?>"><img src="<?php echo CHEMIN ?>inc/img/general/look.gif" border="0" alt="<?php echo $web326; ?>" title="<?php echo $web326; ?>" /></a></td>
          <td style="width:12%">
		  	<input type="checkbox" name="delRecu_id[]" value="<?php echo $i; ?>" />
		  	<img src="<?php echo CHEMIN ?>inc/img/general/del.gif" border="0" alt="<?php echo $web324; ?>" title="<?php echo $web324; ?>" />
		  </td>
		  </tr>
          <?php
		  $nbMsgRecu ++;
        }
      }
	  if ($nbMsgRecu > 0) { //Case Tout supprimer
      ?>
	  <tr style="text-align:center;padding:8px 0px;">
	  <td align="right" colspan="4"><?php echo $web425; ?></td>
	  <td style="width:12%">
	  	<input title="<?php echo $web426; ?>" type="checkbox" name="delRecu_all" value="" onclick="selectAllMsg(this)" />
		<img src="<?php echo CHEMIN ?>inc/img/general/del.gif" border="0" alt="<?php echo $web324; ?>" title="<?php echo $web324; ?>" />
	  </td>
	  </tr>
<?php
	}
?>
      </table>
      <br />
      <table width="400" align="center" summary="">
      <tr><td colspan="5"><p><strong><?php echo $web327; ?></strong></p></td></tr>
      <tr class="forum" align="center">
	    <td style="width:10%"><strong><?php echo $web206; ?></strong></td>
      <td style="width:35%"><strong><?php echo $web328; ?></strong></td>
      <td style="width:35%"><strong><?php echo $web325; ?></strong></td>
      <td colspan="2" style="width:20%"><strong><?php echo $web323; ?></strong></td>
	  </tr>
      <?php
	  $nbMsgSend = 0;
      for ($i = 2; $i < count($dbmsg); $i++) {
        if ($dbmsg[$i][4] == "send") {
          ?>
          <tr class="rep" style="text-align:center;padding:8px 0px;">
          <td style="width:10%"><img src="<?php echo CHEMIN ?>inc/img/general/<?php echo$dbmsg[$i][3]; ?>.gif" border="0" alt="<?php echo$dbmsg[$i][3]; ?>" title="<?php echo$dbmsg[$i][3]; ?>" /></td>
          <td style="width:35%;text-align:left;padding:8px 4px;"><strong><?php echo $dbmsg[$i][0]; ?></strong></td>
          <td style="width:35%"><p><?php echo FormatDate($dbmsg[$i][1]); ?></p></td>
          <td style="width:8%"><a href="tinymsg.php?lng=<?php echo $lng; ?>&action=6&id=<?php echo $i; ?>"><img src="<?php echo CHEMIN ?>inc/img/general/look.gif" border="0" alt="<?php echo $web326; ?>" title="<?php echo $web326; ?>" /></a></td>
          <td style="width:12%">
		  	<input type="checkbox" name="delSend_id[]" value="<?php echo $i; ?>" />
		  	<img src="<?php echo CHEMIN ?>inc/img/general/del.gif" border="0" alt="<?php echo $web324; ?>" title="<?php echo $web324; ?>" />
		  </tr>
          <?php
		  $nbMsgSend ++;
        }
      }

	  if ($nbMsgSend > 0) { //Case Tout supprimer
?>
		<tr style="text-align:center;padding:8px 0px;">
		<td align="right" colspan="4"><?php echo $web425; ?></td>
		<td style="width:12%">
		<input title="<?php echo $web427; ?>" type="checkbox" name="delSend_all" value="" onclick="selectAllMsg(this)" />
		<img src="<?php echo CHEMIN ?>inc/img/general/del.gif" border="0" alt="<?php echo $web324; ?>" title="<?php echo $web324; ?>" />
		</td>
		</tr>
<?php
	}
?>
		</table>
		<br />
		<div style="width:400px; margin-left:auto; margin-right:auto; text-align:right;">
    <?php echo $boutonleft; ?><button type="submit" title="<?php echo $web324; ?>"><?php echo $web424; ?></button><?php echo $boutonright; ?> <img src="<?php echo CHEMIN ?>inc/img/general/up1.gif" alt=" " />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    </div>
		<br />
		</form>
<?php
    }
  }
}
elseif ($action == 4) { //Répondre à ou Supprimer un tinymsg
  if (empty($id)) die("tinymsg.php : action=4 empty id");
	$dbmsg = array();
  if (FileDBExist(USEREP.$userprefs[1].DBEXT)) {
    $dbmsg = ReadDBFields(USEREP.$userprefs[1].DBEXT);
    if ($dbmsg[0][0] == $userprefs[7]) {
      $dbmsg[$id][3] = "lu";
      UpdateFicForm(USEREP.$userprefs[1].DBEXT,$dbmsg[$id][0].CONNECTOR.$dbmsg[$id][1].CONNECTOR.$dbmsg[$id][2].CONNECTOR.$dbmsg[$id][3].CONNECTOR.$dbmsg[$id][4].CONNECTOR.$dbmsg[$id][5].CONNECTOR.$dbmsg[$id][6].CONNECTOR.$dbmsg[$id][7], $id)
      ?>
      <p align="center"><b><?php echo $web330." ".$dbmsg[$id][0]; ?></b> <?php echo $web7." ".FormatDate($dbmsg[$id][1]); ?></p>
      <?php
			if($dbmsg[$id][7]!="") {
				$imgavexp = $page[23]."/".$dbmsg[$id][7];
			}
			else {
				$imgavexp = "unknow.gif";
			}
      ?>
      <br /><fieldset>
      <table width="98%" align="center" summary="">
      <tr class="quest">
      <td style="width:10%;text-align:center;"><img src="<?php echo CHEMIN ?>inc/img/avatars/<?php echo $imgavexp; ?>" alt="<?php echo $dbmsg[$id][0]; ?>" title="<?php echo $dbmsg[$id][0]; ?>" border="0" /></td>
      <td style="width:90%"><p><?php echo stripslashes(souriez($dbmsg[$id][2])); ?></p></td></tr>
      <?php
			if($dbmsg[$id][5] != "") {
				if($userprefs[8] != "") {
					$imgavdest = $page[23]."/".$userprefs[8];
				}
				else {
					$imgavdest = "unknow.gif";
				}
        ?>
        <tr class="forum">
        <td colspan="2" align="center"><p><?php echo $web329." ".FormatDate($dbmsg[$id][6]); ?></p></td></tr>
        <tr class="quest">
        <td style="width:10%;text-align:center;"><img src="inc/img/avatars/<?php echo $imgavdest; ?>" alt="Avatar <?php echo $dbmsg[$id][0]; ?>" border="0" /></td>
        <td style="width:90%"><p><?php echo stripslashes(souriez($dbmsg[$id][5])); ?></p></td></tr>
        <?php
			}
      ?>
      </table></fieldset>
	  <div style="margin:0 auto;text-align:center;width:280px;">
	  <div style="float:left;">
	  <form name="msg_answer" action="tinymsg.php" method="post" style="margin:0; padding:0;">
	  <input type="hidden" name="lng" value="<?php echo $lng; ?>" />
	  <input type="hidden" name="action" value="1" />
	  <input type="hidden" name="id" value="<?php echo $id; ?>" />
	  <input type="hidden" name="to" value="<?php echo $dbmsg[$id][0]; ?>" />
	  <input type="hidden" name="from" value="<?php echo $userprefs[1]; ?>" />
		<?php echo $boutonleft; ?><button type="submit" title="<?php echo $web140; ?>"><?php echo $web140; ?></button><?php echo $boutonright; ?>
	  </form>
	  </div>
	  <div>
	  <form name="msg_del" action="tinymsg.php" method="post" style="margin:0; padding:0;">
	  <input type="hidden" name="lng" value="<?php echo $lng; ?>" />
	  <input type="hidden" name="delRecu_id[]" value="<?php echo $id; ?>" />
	  <input type="hidden" name="action" value="5" />
		<?php echo $boutonleft; ?><button type="submit" title="<?php echo $web324; ?>"><?php echo $web324; ?></button><?php echo $boutonright; ?>
	  </form>
	  </div>
		</div>
	  <?php
		}
	}
  ?>
  <br /><p align="center"><a href="tinymsg.php?lng=<?php echo $lng; ?>&action=3"><img src="<?php echo CHEMIN ?>inc/img/general/back.gif" border="0" alt="<?php echo $web135; ?>" title="<?php echo $web135; ?>" /></a></p>
  <?php
}
elseif ($action == 5) { //Supprimer des tinymsg
	$id = array();
	$id_recu = (isset($_POST['delRecu_id']) && is_array($_POST['delRecu_id']))? $_POST['delRecu_id'] : array();
	$id_send = (isset($_POST['delSend_id']) && is_array($_POST['delSend_id']))? $_POST['delSend_id'] : array();
	$id = array_merge($id_recu, $id_send);

	if (FileDBExist(USEREP.$userprefs[1].DBEXT) && !empty($id)) { //Vérification de l'existence du membre
		$dbmsg = array();
		$dbmsg = ReadDBFields(USEREP.$userprefs[1].DBEXT);
		if ($dbmsg[0][0] == $userprefs[7]) { //Vérification du mot de passe
			for ($i = 0; $i < count($id); $i++) {
				unset($dbmsg[$id[$i]]);
			}
			$dbmsg = array_values($dbmsg);
			WriteDBFields(USEREP.$userprefs[1].DBEXT, $dbmsg);
		}
	}
?>
  <p align="center"><?php echo $web331; ?></p>
  <br /><p align="center"><a href="tinymsg.php?lng=<?php echo $lng; ?>&action=3"><img src="<?php echo CHEMIN ?>inc/img/general/back.gif" border="0" alt="<?php echo $web135; ?>" title="<?php echo $web135; ?>" /></a></p>
  <form name="suit5" action="tinymsg.php?action=3" method="post"></form>
  <script type="text/javascript">
	setTimeout("document.suit5.submit();",2400);
  </script>
  <?php
}
elseif ($action == 6) {
  if (empty($id)) die("tinymsg.php : action=6 empty id");
  $dbmsg = Array();
  if (FileDBExist(USEREP.$userprefs[1].DBEXT)) {
    $dbmsg = ReadDBFields(USEREP.$userprefs[1].DBEXT);
      if ($dbmsg[0][0] == $userprefs[7]) {
            $dbmsg[$id][3] = "lu";
            UpdateFicForm(USEREP.$userprefs[1].DBEXT,$dbmsg[$id][0].CONNECTOR.$dbmsg[$id][1].CONNECTOR.$dbmsg[$id][2].CONNECTOR.$dbmsg[$id][3].CONNECTOR.$dbmsg[$id][4], $id)
      ?>
      <p align="center"><?php echo $web328." : &nbsp;" ; ?> <strong><?php echo $dbmsg[$id][0]; ?></strong> <?php echo " &nbsp;".$web7." &nbsp;".FormatDate($dbmsg[$id][1]); ?></p>
      <div class="rep" style="width:98%;padding:4px;margin-top:8px;"><?php echo stripslashes(souriez($dbmsg[$id][2])); ?></div>
      <?php
        }
    }
  ?>
  <div align="center"><hr /><a href="tinymsg.php?lng=<?php echo $lng; ?>&action=3"><img src="<?php echo CHEMIN ?>inc/img/general/back.gif" border="0" alt="<?php echo $web135; ?>" title="<?php echo $web135; ?>" /></a></div>
  <?php
}
btable();
include("inc/bpage.inc");
?>
