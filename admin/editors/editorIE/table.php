<?php
/*
    Table  - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2006 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alvès,
    followed by Albert Aymard, Jean Michel Misrachi, and all the GuppY Team
      Web site = http://www.freeguppy.org/
      e-mail   = info@aldweb.com

    Version History :
      v2.3 (27 July 2003)      : initial release (by Nicolas Alves)
      v2.4 (24 September 2003) : added character set management
      v3.0 (25 February 2004)  : compatibility with php.ini register_globals=off parameter (thanks JonnyQuest)
      v4.0 (06 December 2004)  :  added alt tags to img and removed border tag for non-linked img (by Isa)
*/

header("Pragma: no-cache");
define("CHEMIN", "../../../");
include(CHEMIN."inc/includes.inc");
function GetSelector($inputename='idselector', $default='') {
  return "<input size=\"8\" class=\"texte\" type=\"hidden\" id=\"".$inputename."\" name=\"".$inputename."\" value=\"".$default."\"><input id=\"".$inputename."btn\" name=\"".$inputename."btn\" type=\"image\" src='img/bgcolor.gif' alt='$admin395' class=\"clsCursor\" align='left' valign='middle' value=\"\" onClick=\"opencolorselector('".$inputename."', event)\" style=\"background:".$default."\">\n";
}
$nbrelist = array("0","1","2","3","4","5","6","7","8","9","10");
?>
<html>
<head>
<title><?php echo $admin444; ?></title>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset; ?>">
<style type="text/css">
 .clsCursor {
 cursor: hand
}
</style>
<script language="javascript">
function getInfoAndUpdate() {
 var callerWindowObj = dialogArguments;
 callerWindowObj.rtNumRows = formNumRows.value;
 callerWindowObj.rtNumCols = formNumCols.value;
 callerWindowObj.rtTblAlign = formTblAlign.value;
 callerWindowObj.rtTblWidth = formTblWidth.value;
 callerWindowObj.rtTblSpacing = formTblSpacing.value;
 callerWindowObj.rtTblPadding = formTblPadding.value;
 callerWindowObj.rtTblColor = formTblColor.value;
 callerWindowObj.rtTblBorder = formTblBorder.value;
 callerWindowObj.rtTblBorderColor = formBorderColor.value;
 callerWindowObj.createTable();
 window.close();
}
 var curselectorinput;

 function selectcolor(c) {
    document.getElementById(curselectorinput).value=c;
 if(document.all) {
      document.getElementById(curselectorinput+'btn').style.background=c;
}
else {
 if(document.getElementById) {		
        document.getElementById(curselectorinput+'btn').style.background=c;
      }
    }
    closecolorselector();
  }

 function opencolorselector(o, e) {
    selecto=document.getElementById('selectcolor').style;
 if(selecto.display=="block") {
      closecolorselector();
}
else {
      selecto.display="block";
 if(document.all) {
        selecto.left=event.x+document.body.scrollLeft - 150;
        selecto.top=event.y+document.body.scrollTop - 100;
}
else {
 if(document.getElementById) {
          selecto.left=e.clientX+window.pageXOffset; 
          selecto.top=e.clientY+window.pageYOffset;	
        }		
      }
      curselectorinput=o;
    }
  }

 function closecolorselector() {
 document.getElementById('selectcolor').style.display="none";
 }
</script>
</head>
<body leftmargin="5" topmargin="5" style="overflow: hidden;">
<fieldset><center>
<table width="100%" cellpadding="2" cellspacing="2" align="center" valign="middle" border="0">
<tr><td align="left" valign="middle"><font size="-1"><?php echo $admin436; ?></font></td>
<td align="left" valign="middle"><input maxlength="4" id="formTblWidth" size="5"></td>
<td align="left" valign="middle"><font size="-1"><?php echo $admin437; ?></font></td>
<td align="left" valign="middle"><select id="formTblBorder">
<?php
 for ($i = 0; $i < count($nbrelist); $i++) {
 $sel = "0";
 echo "<option value=\"".$nbrelist[$i]."\"".$sel.">".$nbrelist[$i]."</option>\n";
 }
?>
</option></select></td></tr>
<tr><td  align="left" valign="middle"><font size="-1"><?php echo $admin438; ?></font></td>
<td align="left" valign="middle"><select id="formNumRows">
<?php
 for ($i = 0; $i < count($nbrelist); $i++) {
 $sel = "0";
 echo "<option value=\"".$nbrelist[$i]."\"".$sel.">".$nbrelist[$i]."</option>\n";
 }
?>
</option></select></td>
<td align="left" valign="middle"><font size="-1"><?php echo $admin440; ?></font></td>
<td align="left" valign="middle"><select id="formNumCols">
<?php
 for ($i = 0; $i < count($nbrelist); $i++) {
 $sel = "0";
  echo "<option value=\"".$nbrelist[$i]."\"".$sel.">".$nbrelist[$i]."</option>\n";
 }
?>
</option></select></td></tr>
<tr><td align="left" valign="middle"><font size="-1"><?php echo $admin439; ?></font></td>
<td align="left" valign="middle"><select id="formTblPadding">
<?php
 for ($i = 0; $i < count($nbrelist); $i++) {
 $sel = "0";
  echo "<option value=\"".$nbrelist[$i]."\"".$sel.">".$nbrelist[$i]."</option>\n";
 }
?>
</option></select></td>
<td align="left" valign="middle"><font size="-1"><?php echo $admin441; ?></font></td>
<td align="left" valign="middle"><select id="formTblSpacing">
<?php
 for ($i = 0; $i < count($nbrelist); $i++) {
 $sel = "0";
  echo "<option value=\"".$nbrelist[$i]."\"".$sel.">".$nbrelist[$i]."</option>\n";
 }
?>
</option></select></td></tr>
<tr><td align="left" valign="middle"><font size="-1"><?php echo $admin442; ?></font></td>
<td align="left" valign="middle">
<?php
 echo GetSelector("formTblColor", "$formTblColor");
?>
</td>
<td align="left" valign="middle"><font size="-1"><?php echo $admin443; ?></font></td>
<td align="left" valign="middle"><select id="formTblAlign">
<option selected value="left"><?php echo $admin494; ?>
<option value="center"><?php echo $admin391; ?>
<option value="right"><?php echo $admin495; ?></option></select></td></tr>
<tr><td align="left" valign="middle"><font size="-1"><?php echo $admin404; ?></font></td>
<td align="left" valign="middle">
<?php
 echo GetSelector("formBorderColor", "$formBorderColor");
?>
</td>
<td align="left" valign="middle"></td>
<td align="left" valign="middle">&nbsp;&nbsp;</td></tr>
<tr><td align="left" valign="middle" colspan="4"><p align="center">
<input type=button name=batal value="<?php echo $admin38; ?>" onclick='getInfoAndUpdate();'>&nbsp;
<input type=button value="<?php echo $admin121; ?>" onclick='window.close();'></p></td></tr>
</table>
</center></fieldset>
<div id="selectcolor" style="position:absolute;top:15px;display:none;border:thin solid white;background: #FFFFFF;">
<p align="center"></p>
<table cellspacing="1" cellpadding="0" width="92" bgColor="#cccccc" border="1">
<tr height="12">      
<td bgColor=#000000><img class=clsCursor onClick="selectcolor('#000000')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#444444><img class=clsCursor onClick="selectcolor('#444444')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#666666><img class=clsCursor onClick="selectcolor('#666666')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#888888><img class=clsCursor onClick="selectcolor('#888888')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#aaaaaa><img class=clsCursor onClick="selectcolor('#AAAAAA')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#cccccc><img class=clsCursor onClick="selectcolor('#CCCCCC')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#ffffff><img class=clsCursor onClick="selectcolor('#FFFFFF')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td></tr>
<tr height="12">
<td bgColor=#ff0000><img class=clsCursor onClick="selectcolor('#FF0000')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#400000><img class=clsCursor onClick="selectcolor('#400000')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#800000><img class=clsCursor onClick="selectcolor('#800000')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#c00000><img class=clsCursor onClick="selectcolor('#C00000')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#ff4040><img class=clsCursor onClick="selectcolor('#FF4040')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#ff8080><img class=clsCursor onClick="selectcolor('#FF8080')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#ffc0c0><img class=clsCursor onClick="selectcolor('#FFC0C0')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td></tr>
<tr height="12">
<td bgColor=#ff7f00><img class=clsCursor onClick="selectcolor('#FF7F00')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#462300><img class=clsCursor onClick="selectcolor('#462300')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#864200><img class=clsCursor onClick="selectcolor('#864200')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#c46100><img class=clsCursor onClick="selectcolor('#C46100')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#ffa247><img class=clsCursor onClick="selectcolor('#FFA247')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#ffc185><img class=clsCursor onClick="selectcolor('#FFC185')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#ffe1c3><img class=clsCursor onClick="selectcolor('#FFE1C3')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td></tr>
<tr height="12">
<td bgColor=#ffff00><img class=clsCursor onClick="selectcolor('#FFFF00')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#404000><img class=clsCursor onClick="selectcolor('#404000')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#808000><img class=clsCursor onClick="selectcolor('#808000')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#c0c000><img class=clsCursor onClick="selectcolor('#C0C000')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#ffff40><img class=clsCursor onClick="selectcolor('#FFFF40')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#ffff80><img class=clsCursor onClick="selectcolor('#FFFF80')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#ffffc0><img class=clsCursor onClick="selectcolor('#FFFFC0')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td></tr>
<tr height="12">
<td bgColor=#00ff00><img class=clsCursor onClick="selectcolor('#00FF00')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#004000><img class=clsCursor onClick="selectcolor('#004000')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#008000><img class=clsCursor onClick="selectcolor('#008000')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#00c000><img class=clsCursor onClick="selectcolor('#00C000')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#40ff40><img class=clsCursor onClick="selectcolor('#40FF40')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#80ff80><img class=clsCursor onClick="selectcolor('#80FF80')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#c0ffc0><img class=clsCursor onClick="selectcolor('#C0FFC0')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td></tr>
<tr height="12">
<td bgColor=#00ffff><img class=clsCursor onClick="selectcolor('#00FFFF')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#004040><img class=clsCursor onClick="selectcolor('#004040')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#008080><img class=clsCursor onClick="selectcolor('#008080')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#00c0c0><img class=clsCursor onClick="selectcolor('#00C0C0')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#40ffff><img class=clsCursor onClick="selectcolor('#40FFFF')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#80ffff><img class=clsCursor onClick="selectcolor('#80FFFF')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#c0ffff><img class=clsCursor onClick="selectcolor('#C0FFFF')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td></tr>
<tr height="12">
<td bgColor=#0000ff><img class=clsCursor onClick="selectcolor('#0000FF')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#000040><img class=clsCursor onClick="selectcolor('#000040')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#000080><img class=clsCursor onClick="selectcolor('#000080')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#0000c0><img class=clsCursor onClick="selectcolor('#0000C0')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#4040ff><img class=clsCursor onClick="selectcolor('#4040FF')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#8080ff><img class=clsCursor onClick="selectcolor('#8080FF')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#c0c0ff><img class=clsCursor onClick="selectcolor('#C0C0FF')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td></tr>
<tr height="12">
<td bgColor=#ff00ff><img class=clsCursor onClick="selectcolor('#FF00FF')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#400040><img class=clsCursor onClick="selectcolor('#400040')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#800080><img class=clsCursor onClick="selectcolor('#800080')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#c000c0><img class=clsCursor onClick="selectcolor('#C000C0')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#ff40ff><img class=clsCursor onClick="selectcolor('#FF40FF')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#ff80ff><img class=clsCursor onClick="selectcolor('#FF80FF')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td>
<td bgColor=#ffc0ff><img class=clsCursor onClick="selectcolor('#FFC0FF')" src="img/blank.gif" height="12" width="12" border="0" alt="" /></td></tr>
<tr></td></tr></div>
</table>
</body>
</html>
