<?php
/*
    Editor IE - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alvès,
    followed by Albert Aymard, Jean Michel Misrachi, and all the GuppY Team
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v2.2 (22 April 2003)       : initial release (by Nicolas Alves)
      v2.3 (27 July 2003)        : WYSIWIG editor upgraded (by Nicolas Alves)
      v2.4 (24 September 2003)   : added character set management
                                   replaced "Webpage Preview" string by string translated in the adequate language
      v2.5 (25 February 2004)    : compatibility with php.ini register_globals=off parameter (thanks JonnyQuest)
      v4.0 (06 December 2004)    : Added new alert for unefficent browsers (by Icare)
      v4.5.4 (01 September 2005) : Added url translations in data input,
                                   deleting \r\n of table tags in output data (by Icare)
      v4.6.1 (18 June 2007)      : corrected bad <br> change (by jchouix)
*/

header("Pragma: no-cache");
define("CHEMIN", "../../");
include(CHEMIN."inc/includes.inc");
if ($browser == "KO")
 {
?>
<script language="javascript">
  var errorString = "<?php echo $admin374; ?>";
  alert(errorString);window.close();
</script>
<?php
 }

?>

<html>
<head>
<title><?php echo $admin220; ?></title>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset; ?>">
</head>
<body bgcolor="#CCCCCC" text="#000000" topmargin="1" leftmargin="0">
<style type="text/css">
.clsCursor { cursor: pointer; cursor: hand; }
</style>
<script type="text/javascript">
  var url = new String (document.location.href);
  if (url.indexOf('?') > -1) {
	if (url.substring(0, url.indexOf('contenu1'))) {
		editorvalue = window.opener.document.adminsend.contenu1.value;
	}
	else if(url.substring(0, url.indexOf('contenu2'))) {
		editorvalue = window.opener.document.adminsend.contenu2.value;
		}
   }
   else {
	editorvalue = window.opener.document.adminsend.contenu1.value;
   }

  //Affichage des images dans l'éditeur
  var IPATH = '<?php echo $site[3]; ?>';
  editorvalue = editorvalue.replace (/\|\:\-\)/g, '<img src="inc/img/smileys/cool.gif" alt="cool" border="0">');
	editorvalue = editorvalue.replace (/\;\-\)/g, '<img src="inc/img/smileys/wink.gif" alt="wink" border="0">');
	editorvalue = editorvalue.replace (/\:\-\)\)/g, '<img src="inc/img/smileys/biggrin.gif" alt="biggrin" border="0">');
	editorvalue = editorvalue.replace (/\:\-\)/g, '<img src="inc/img/smileys/smile.gif" alt="smile" border="0">');
	editorvalue = editorvalue.replace (/\:\-o/gi, '<img src="inc/img/smileys/frown.gif" alt="frown" border="0">');
  editorvalue = editorvalue.replace (/\:o\)/gi, '<img src="inc/img/smileys/eek.gif" alt="eek" border="0">');
	editorvalue = editorvalue.replace (/\:\-\(\(/g, '<img src="inc/img/smileys/mad.gif" alt="mad" border="0">');
	editorvalue = editorvalue.replace (/\:\-\(/g, '<img src="inc/img/smileys/confused.gif" alt="confused" border="0">');
	editorvalue = editorvalue.replace (/8\-\)/gi, '<img src="inc/img/smileys/rolleyes.gif" alt="rolleyes" border="0">');
	editorvalue = editorvalue.replace (/\:\-p/g, '<img src="inc/img/smileys/tongue.gif" alt="tongue" border="0">');
	editorvalue = editorvalue.replace (/\;\-\(/g, '<img src="inc/img/smileys/cry.gif" alt="" border="0">');
	editorvalue = editorvalue.replace (/src=\"img/gi,"src=\"" + IPATH + "img");
  editorvalue = editorvalue.replace (/src=\"photo/gi,"src=\"" + IPATH + "photo");
  editorvalue = editorvalue.replace (/src=\"inc/gi,"src=\"" + IPATH + "inc");
  editorvalue = editorvalue.replace (/src=img/gi,"src=" + IPATH + "img");
  editorvalue = editorvalue.replace (/src=photo/gi,"src=" + IPATH + "photo");
  editorvalue = editorvalue.replace (/src=inc/gi,"src=" + IPATH + "inc");
  editorvalue = editorvalue.replace (/url\(img/gi,"url(" + IPATH + "img");
  editorvalue = editorvalue.replace (/url\(inc/gi,"url(" + IPATH + "inc");
  editorvalue = editorvalue.replace (/url\(photo/gi,"url(" + IPATH + "photo");
  editorvalue = editorvalue.replace (/\n/g,"<br />");
  //editorvalue = editorvalue.replace (/<br /><p>/ig,"<p>");
   document.write('<form name=\"fHtmlEditor\" method=\"GET\" action=\"\">');
   document.write('<textarea name=\"EditorValue\" style=\"display: none;\">' + editorvalue + '</textarea>');

   var errorString = "<?php echo $admin374; ?>"
   var Ok = "false";
   var name =  navigator.appName;
   var version =  parseFloat(navigator.appVersion);
   var platform = navigator.platform;
   if (platform == "Win32" && name == "Microsoft Internet Explorer" && version >= 4){
      Ok = "true";
	}
	else {
      Ok = "false";
   }
   if (Ok == "false") {
      alert(errorString);
      self.close();
   }

function popup_img() {
    var hauteur = 450;
    var largeur = 380;
    var top=(screen.height-hauteur)/4;
    var left=(screen.width-largeur)*3/4;
    window.open('<?php echo CHEMIN; ?>admin/editors/editorIE/listimg.php?op=img', 'itmp', 'top='+top+', left='+left+', width='+largeur+', height='+hauteur+', resizable=yes,menubar=no,location=no,directories=no,status=no,copyhistory=no,toolbar=no,scrollbars=yes');
}

function addTableDialog() {
  var rtNumRows = null;
  var rtNumCols = null;
  var rtTblAlign = null;
  var rtTblWidth = null;
  var rtTblSpacing = null;
  var rtTblPadding =  null;
  var rtTblColor = null;
  var rtTblBorder = null;
  var rtTblBorderColor = null;
  showModalDialog("<?php echo CHEMIN; ?>admin/editors/editorIE/table.php",window,"dialogHeight: 250px; dialogWidth: 450px; dialogTop: 200px; dialogLeft: 400px; center: Yes; help: No; resizable: No; status: No;");
}

function createTable() {
  var cursor = myEditor.document.selection.createRange();
  if (rtNumRows == "" || rtNumRows == "0") {
    rtNumRows = "1";
  }
  if (rtNumCols == "" || rtNumCols == "0") {
    rtNumCols = "1";
  }
  var rttrnum=1
  var rttdnum=1
  var rtNewTable = "<table bordercolor='"+rtTblBorderColor+"' border='"+rtTblBorder+"' bgcolor='"+rtTblColor+"' cellpadding='"+rtTblPadding+"' cellspacing='"+rtTblSpacing+"' border='1' align='" + rtTblAlign + "' cellpadding='0' cellspacing='0' width='" + rtTblWidth + "' >"
  while (rttrnum <= rtNumRows) {
    rttrnum=rttrnum+1
    rtNewTable = rtNewTable + "<tr>"
    while (rttdnum <= rtNumCols) {
      rtNewTable = rtNewTable + "<td>&nbsp;</td>"
      rttdnum=rttdnum+1
    }
    rttdnum=1
    rtNewTable = rtNewTable + "</tr>"
  }
  rtNewTable = rtNewTable + "</table>"
  cursor.pasteHTML(rtNewTable);
}

function Symbol() {
  var symbol = null;
  showModalDialog("<?php echo CHEMIN; ?>admin/editors/editorIE/carspec.php",window,"dialogHeight: 185px; dialogWidth: 240px; dialogTop: 200px; dialogLeft: 450px; center: Yes; help: No; resizable: No; status: No;");
}

function createSymbol() {
  var cursor = myEditor.document.selection.createRange();
  var rtNewTable = ""+symbol+""
  cursor.pasteHTML(rtNewTable);
}

function previewControl() {
  ff = window.open("","","width=620,height=480,menubar=no,toolbar=no,scrollbars=yes");
  ff.document.write('<html><head><title><?php echo $admin474; ?></title><meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset; ?>"></head><body>'+document.frames('myEditor').document.frames('textEdit').document.body.innerHTML+'</body></html>');
}

function createLink() {
  document.execCommand("CreateLink");
}

function undo() {
  document.execCommand("undo");
}

function redo() {
  document.execCommand("redo");
}

function setcolor(colorString) {
  if (document.fHtmlEditor.co.value=="fond") {
    doFormat('BackColor',colorString);
  }
  if (document.fHtmlEditor.co.value=="texte") {
    doFormat('ForeColor',colorString);
  }
  else {
    backcolor(colorString);
  }
}

function MM_findObj(n, d) {
  var p,i,x;  if(!d) d=document; if((p=n.indexOf("?"))>0&&parent.frames.length) {
    d=parent.frames[n.substring(p+1)].document; n=n.substring(0,p);}
  if(!(x=d[n])&&d.all) x=d.all[n]; for (i=0;!x&&i<d.forms.length;i++) x=d.forms[i][n];
  for(i=0;!x&&d.layers&&i<d.layers.length;i++) x=MM_findObj(n,d.layers[i].document); return x;
}

function MM_showHideLayers() {
  var i,p,v,obj,args=MM_showHideLayers.arguments;
  for (i=0; i<(args.length-2); i+=3) if ((obj=MM_findObj(args[i]))!=null) { v=args[i+2];
    if (obj.style) { obj=obj.style; v=(v=='show')?'visible':(v='hide')?'hidden':v; }
    obj.visibility=v; }
}

function doFormat(what) {
   var eb = document.all.editbar;
   if(what == "FontName"){
      if(arguments[1] != 1){
         eb._editor.execCommand(what, arguments[1]);
         document.all.font.selectedIndex.value;selectedIndex = 0;
      }
   }
   if(what == "FontSize"){
      if(arguments[1] != ''){
         eb._editor.execCommand(what, arguments[1]);
         document.all.size.selectedIndex.value;selectedIndex = 0;
      }
   }
   if(what == "FormatBlock"){
      if(arguments[1] != ''){
         eb._editor.execCommand(what, arguments[1]);
         document.all.format.selectedIndex.value;selectedIndex = 0;
      }
   }
   else {
      eb._editor.execCommand(what, arguments[1]);
   }
}

function initToolBar(ed) {
   var eb = document.all.editbar;
   if (ed!=null) {
      eb._editor = window.frames['myEditor'];
   }
}

function InStr(sChaine, sSous_Chaine) {
   sChaine = String(sChaine);
   return( sChaine.lastIndexOf( sSous_Chaine));
}

function InsertXfile() {
   var X=document.all.Xfile.value;
   Y=X.substr(InStr(X,'\\')+1);
   document.frames("myEditor").document.frames("textEdit").document.body.innerHTML=" [ <a href='File://"+document.all.Xfile.value+"'>"+Y+"</a> ] "+document.frames("myEditor").document.frames("textEdit").document.body.innerHTML;
}

function swapMode() {
   var eb = document.all.editbar._editor;
   eb.swapModes();
}

function create() {
   var eb = document.all.editbar;
   eb._editor.newDocument();
}

function newFile() {
   create();
}

function copyValue() {
   var theHtml = "" + document.frames("myEditor").document.frames("textEdit").document.body.innerHTML + "";
   document.all.EditorValue.value = theHtml;
}

function SwapView_OnClick() {
   if(document.all.btnSwapView.value == "<?php echo $admin238; ?>") {
      document.all.btnsave.style.visibility="hidden";
      var sMes = "HTML";
	}
	else {
      document.all.btnsave.style.visibility="visible";
      var sMes = "<?php echo $admin238; ?>"
   }
   document.all.btnSwapView.value = sMes;
   swapMode();
}

function OnFormSubmit() {
  if(confirm("<?php echo $admin373; ?>")) {
    copyValue();
  var url = new String (document.location.href);
  SubmitedValue = document.fHtmlEditor.EditorValue.value.replace(/<br>/gi,"<br />");
  SubmitedValue = SubmitedValue.replace(/\n/gi,"");
  SubmitedValue = SubmitedValue.replace(/\r/gi,"");
  var SRC_PATH = 'src="' + IPATH;
  var sup_url = new RegExp(SRC_PATH,"ig") ;
  SubmitedValue = SubmitedValue.replace(sup_url, "src=\""); //supprime le path image
  var ADM_PATH = IPATH + "admin/";
  var sup_url = new RegExp(ADM_PATH,"ig") ;
  SubmitedValue = SubmitedValue.replace(sup_url, ""); // supprime url sur lien local.
	if (url.indexOf('?') > -1) {
		if (url.substring(0, url.indexOf('contenu1'))) {
		window.opener.document.adminsend.contenu1.value = SubmitedValue;
		}
		else if(url.substring(0, url.indexOf('contenu2'))) {
			window.opener.document.adminsend.contenu2.value = SubmitedValue;
		}
	}
	else {
		window.opener.document.adminsend.contenu1.value = SubmitedValue;
	}
	self.close();
  }
}
</script>
<table cellspacing="0" cellpadding="0" width="90%" height="100%" bordercolor="#FFE6CC" bgcolor="buttonface" border="0">
<tr valign="top"><td>
<table cellpadding="0" cellspacing="0" width="100%" height="100%" border="0">
<tr valign="top"><td valign="top"><div id=editbar style="width: 620; height: 19">
<table width="100%" cellpadding="0" cellspacing="0" align="left" border="0"><tr><td>
<table cellpadding="0" cellspacing="0" border="0">
<tr><td>
<table cellspacing="0" cellpadding="1" border="0">
<tr><td nowrap>
<img class='clsCursor' src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/new.gif" width="16" height="16" border="0" alt="<?php echo $admin372; ?>"  onClick="newFile();"/>&nbsp;
<img class='clsCursor' name="btnsave" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/save.gif" width="16" height="16" border="0" alt="<?php echo $admin38; ?>"  onClick="OnFormSubmit();"/>&nbsp;
<img class='clsCursor' src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/cut.gif" width="16" height="16" border="0" alt="<?php echo $admin375; ?>"  onClick="doFormat('Cut')"/>&nbsp;
<img class='clsCursor' src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/copy.gif" width="16" height="16" border="0" alt="<?php echo $admin376; ?>"  onClick="doFormat('Copy')"/>&nbsp;
<img class='clsCursor' src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/paste.gif" border="0" alt="<?php echo $admin377; ?>"  onClick="doFormat('Paste')" width="16" height="16"/>&nbsp;
</td></tr>
</table>
<td>
<table cellspacing="0" cellpadding="1" align="right" border="0">
<tr><td nowrap>
<img class='clsCursor' src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/para_bul.gif" width="16" height="16" border="0" alt="<?php echo $admin378; ?>"  onClick="doFormat('InsertUnorderedList');" />&nbsp;
<img class='clsCursor' src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/para_num.gif" width="16" height="16" border="0" alt="<?php echo $admin379; ?>"  onClick="doFormat('InsertOrderedList');" />&nbsp;
<img class='clsCursor' src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/indent.gif" width="20" height="16" alt="<?php echo $admin380; ?>"  onClick="doFormat('Indent')"/>&nbsp;
<img class='clsCursor' src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/outdent.gif" width="20" height="16" alt="<?php echo $admin381; ?>"  onClick="doFormat('Outdent')"/>&nbsp;
<img class='clsCursor' src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/hr.gif" width="16" height="18" alt="<?php echo $admin382; ?>"  onClick="doFormat('InsertHorizontalRule')"/>&nbsp;
<img class='clsCursor' src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/bold.gif" width="16" height="16" border="0" align="absmiddle" alt="<?php echo $admin387; ?>" onClick="doFormat('Bold')"/>&nbsp;
<img class='clsCursor' src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/italics.gif" width="16" height="16" border="0" align="absmiddle" alt="<?php echo $admin388; ?>" onClick="doFormat('Italic')"/>&nbsp;
<img class='clsCursor' src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/underline.gif" width="16" height="16" border="0" align="absmiddle" alt="<?php echo $admin389; ?>" onClick="doFormat('Underline')" />&nbsp;
<img class='clsCursor' src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/left.gif" width="16" height="16" border="0" alt="<?php echo $admin390; ?>" align="absmiddle" onClick="doFormat('JustifyLeft')"/>
<img class='clsCursor' src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/centre.gif" width="16" height="16" border="0" alt="<?php echo $admin391; ?>" align="absmiddle" onClick="doFormat('JustifyCenter')"/>&nbsp;
<img class='clsCursor' src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/right.gif" width="16" height="16" border="0" alt="<?php echo $admin392; ?>" align="absmiddle" onClick="doFormat('JustifyRight')"/>&nbsp;
<img class='clsCursor' src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/justify.gif" width="16" height="16" border="0" alt="<?php echo $admin384; ?>" align="absmiddle" onClick="doFormat('JustifyFull')"/>&nbsp;&nbsp;
<img class='clsCursor' src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/undo.gif" border="0" alt="<?php echo $admin446; ?>" align="absmiddle"   onClick="undo();" />&nbsp;
<img class='clsCursor' src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/redo.gif" border="0" alt="<?php echo $admin447; ?>" align="absmiddle"   onClick="redo();" />&nbsp;
<img class='clsCursor' src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/preview.gif" alt="<?php echo $admin419; ?>" onClick="previewControl()"/>&nbsp;
<img class='clsCursor' src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/link.gif" border="0" alt="<?php echo $admin383; ?>" align="absmiddle"  onClick="createLink();" /></td>
</td></tr>
</table>
<td width=100%>
</table>
<tr><td height="40">
<table width="100%" border="0">
<tr><td nowrap><div align="left">
<select name="font" onChange=" doFormat('FontName',document.all.font.value);" style="color: #ffffff; background-color: #004D71; font-size: 10px; font-family: Verdana,sans-serif; font-weight: 50; border: 1 solid #ffffff">
<option value="1" selected ><?php echo $admin385; ?></option>
<option value="Arial">Arial</option>
<option value="Comic Sans MS">Comic Sans MS</option>
<option value="Courier New">Courier New</option>
<option value="Georgia">Georgia</option>
<option value="Sans Serif">Sans Serif</option>
<option value="Tahoma">Tahoma</option>
<option value="Times New Roman">Times New Roman</option>
<option value="trebuchet MS">trebuchet MS</option>
<option value="Verdana">Verdana</option></select>
<select name="size" onChange="doFormat('FontSize',document.all.size.value);" style="color: #ffffff; background-color: #004D71; font-size: 10px; font-family: Verdana,sans-serif; font-weight: 50; border: 1 solid #ffffff">
<option value="None" selected><?php echo $admin386; ?></option>
<option value="1">1 ( 8 pt)</option>
<option value="2">2 (10 pt)</option>
<option value="3">3 (12 pt)</option>
<option value="4">4 (14 pt)</option>
<option value="5">5 (18 pt)</option>
<option value="6">6 (24 pt)</option>
<option value="7">7 (36 pt)</option></select>
<select name="format" onChange="doFormat('FormatBlock',document.all.format.value);" style="color: #ffffff; background-color: #004D71; font-size: 10px; font-family: Verdana,sans-serif; font-weight: 50; border: 1 solid #ffffff">
<option value="None" selected><?php echo $admin422; ?></option>
<option value="<p>"><?php echo $admin423; ?></option>
<option value="<pre>"><?php echo $admin424; ?></option>
<option value="<address>"><?php echo $admin425; ?></option>
<option value="<H1>"><?php echo $admin426; ?></option>
<option value="<H2>"><?php echo $admin427; ?></option>
<option value="<H3>"><?php echo $admin428; ?></option>
<option value="<H4>"><?php echo $admin429; ?></option>
<option value="<H5>"><?php echo $admin430; ?></option>
<option value="<H6>"><?php echo $admin431; ?></option>
<option value="<ol>"><?php echo $admin379; ?></option>
<option value="<ul>"><?php echo $admin378; ?></option>
<option value="<dir>"><?php echo $admin432; ?></option>
<option value="<menu>"><?php echo $admin433; ?></option>
<option value="<dt>"><?php echo $admin434; ?></option>
<option value="<dd>"><?php echo $admin435; ?></option>
</select>
<img class='clsCursor' src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/img.gif" alt="<?php echo $admin241; ?>" onClick="popup_img();" />
<img class='clsCursor' src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/table.gif" alt="<?php echo $admin421; ?>" onClick="addTableDialog()"/>
<img class='clsCursor' src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/carsepc.gif" alt="<?php echo $admin420; ?>" onClick="Symbol()"/>
<input type=hidden name=co value=texte><img class='clsCursor' onClick="document.fHtmlEditor.co.value='texte'; MM_showHideLayers('Layer1','','show')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/textecolor.gif" alt=<?php echo $admin394; ?>/>
<input type=hidden name=co value=fond><img class='clsCursor' onClick="document.fHtmlEditor.co.value='fond'; MM_showHideLayers('Layer1','','show')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/surlignement.gif" alt=<?php echo $admin395; ?>/>
<div id=Layer1 style="Z-INDEX: 1; LEFT: 400px; VISIBILITY: hidden; WIDTH: 111px; POSITION: absolute; TOP: 70px; HEIGHT: 133px">
<a onClick="MM_showHideLayers('Layer1','','hide')" href="#">
<table cellspacing="1" cellpadding="0" width="92" bgcolor=#cccccc border=1">
<tr height=2><td height="2" rowspan="9" >&nbsp;</td><td colspan="7" height="2"></td><td height="2" rowspan="9" >&nbsp;</td></tr>
<tr height="12">
<td bgColor=#000000><img class=clsCursor onClick="setcolor('#000000')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#444444><img class=clsCursor onClick="setcolor('#444444')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#666666><img class=clsCursor onClick="setcolor('#666666')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#888888><img class=clsCursor onClick="setcolor('#888888')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#aaaaaa><img class=clsCursor onClick="setcolor('#AAAAAA')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#cccccc><img class=clsCursor onClick="setcolor('#CCCCCC')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#ffffff><img class=clsCursor onClick="setcolor('#FFFFFF')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td></tr>
<tr height="12">
<td bgColor=#ff0000><img class=clsCursor onClick="setcolor('#FF0000')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#400000><img class=clsCursor onClick="setcolor('#400000')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#800000><img class=clsCursor onClick="setcolor('#800000')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#c00000><img class=clsCursor onClick="setcolor('#C00000')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#ff4040><img class=clsCursor onClick="setcolor('#FF4040')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#ff8080><img class=clsCursor onClick="setcolor('#FF8080')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#ffc0c0><img class=clsCursor onClick="setcolor('#FFC0C0')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td></tr>
<tr height="12">
<td bgColor=#ff7f00><img class=clsCursor onClick="setcolor('#FF7F00')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#462300><img class=clsCursor onClick="setcolor('#462300')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#864200><img class=clsCursor onClick="setcolor('#864200')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#c46100><img class=clsCursor onClick="setcolor('#C46100')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#ffa247><img class=clsCursor onClick="setcolor('#FFA247')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#ffc185><img class=clsCursor onClick="setcolor('#FFC185')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#ffe1c3><img class=clsCursor onClick="setcolor('#FFE1C3')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td></tr>
<tr height="12">
<td bgColor=#ffff00><img class=clsCursor onClick="setcolor('#FFFF00')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#404000><img class=clsCursor onClick="setcolor('#404000')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#808000><img class=clsCursor onClick="setcolor('#808000')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#c0c000><img class=clsCursor onClick="setcolor('#C0C000')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#ffff40><img class=clsCursor onClick="setcolor('#FFFF40')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#ffff80><img class=clsCursor onClick="setcolor('#FFFF80')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#ffffc0><img class=clsCursor onClick="setcolor('#FFFFC0')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td></tr>
<tr height="12">
<td bgColor=#00ff00><img class=clsCursor onClick="setcolor('#00FF00')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#004000><img class=clsCursor onClick="setcolor('#004000')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#008000><img class=clsCursor onClick="setcolor('#008000')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#00c000><img class=clsCursor onClick="setcolor('#00C000')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#40ff40><img class=clsCursor onClick="setcolor('#40FF40')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#80ff80><img class=clsCursor onClick="setcolor('#80FF80')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#c0ffc0><img class=clsCursor onClick="setcolor('#C0FFC0')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td></tr>
<tr height="12">
<td bgColor=#00ffff><img class=clsCursor onClick="setcolor('#00FFFF')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#004040><img class=clsCursor onClick="setcolor('#004040')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#008080><img class=clsCursor onClick="setcolor('#008080')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#00c0c0><img class=clsCursor onClick="setcolor('#00C0C0')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#40ffff><img class=clsCursor onClick="setcolor('#40FFFF')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#80ffff><img class=clsCursor onClick="setcolor('#80FFFF')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#c0ffff><img class=clsCursor onClick="setcolor('#C0FFFF')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td></tr>
<tr height="12">
<td bgColor=#0000ff><img class=clsCursor onClick="setcolor('#0000FF')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#000040><img class=clsCursor onClick="setcolor('#000040')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#000080><img class=clsCursor onClick="setcolor('#000080')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#0000c0><img class=clsCursor onClick="setcolor('#0000C0')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#4040ff><img class=clsCursor onClick="setcolor('#4040FF')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#8080ff><img class=clsCursor onClick="setcolor('#8080FF')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#c0c0ff><img class=clsCursor onClick="setcolor('#C0C0FF')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td></tr>
<tr height="12">
<td bgColor=#ff00ff><img class=clsCursor onClick="setcolor('#FF00FF')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#400040><img class=clsCursor onClick="setcolor('#400040')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#800080><img class=clsCursor onClick="setcolor('#800080')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#c000c0><img class=clsCursor onClick="setcolor('#C000C0')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#ff40ff><img class=clsCursor onClick="setcolor('#FF40FF')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#ff80ff><img class=clsCursor onClick="setcolor('#FF80FF')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td>
<td bgColor=#ffc0ff><img class=clsCursor onClick="setcolor('#FFC0FF')" src="<?php echo CHEMIN; ?>admin/editors/editorIE/img/blank.gif" height="12" width="12" border="0"></td></tr>
<tr><td colspan="9" class=clsCursor align="center"><font face="verdana" size="2"><?php echo $admin121; ?></font></td></tr> </table>
</a></div>
<td align="left" nowrap>
<input type="button" name="btnSwapView" class="clsCursor" value="<?php echo $admin238; ?>" onClick="SwapView_OnClick();" style="color: #ffffff; background-color: #004D71; font-size: 10px; font-family: Verdana,sans-serif; font-weight: 50; border: 1 solid #ffffff"></td>
</table>
</td></tr>
</table>
<tr valign="top" align="left"><td valign="top" height=95%>
<table width="100%" height="100%"border="0">
<tr valign="top"><td width="100%" height="100%">
<table width="100%" cellspacing="0" cellpadding="0" height="100%" border="0">
<tr valign="top"><td bgcolor="#FFFFFF">
<iframe id=myEditor src="<?php echo CHEMIN; ?>admin/editors/editorIE/edit.php" onFocus="initToolBar(this)" width=100% height=100%></iframe></td></tr>
</table>
</td>
<td width="9%" align="center">
</table>
<br /><br /><br /><br /><br /><br /></td></tr>
</table>
</td></tr>
</table>
</form>
<script language="javascript">
 initToolBar("foo");
 window.status = "Current View: Wysiwyg";
</script>
</body>
</html>
