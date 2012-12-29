<?php
/*
    Editor IE - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2006 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alvès,
    followed by Albert Aymard, Jean Michel Misrachi, and all the GuppY Team
      Web site = http://www.freeguppy.org/
      e-mail   = info@aldweb.com

    Version History :
      v2.2 (22 April 2003)     : initial release (by Nicolas Alves)
      v2.3 (27 July 2003)      : WYSIWIG tiny editor upgraded (by Nicolas Alves)
      v2.4 (24 September 2003) : added character set management
      v4.0 (06 December 2004)  : no change
*/

?>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset; ?>">
</head>
<style>
 body {
 margin: 0pt; padding: 0pt; border: none
}

 iframe {
 width: 100%; height: 100%; border: none
}
</style>
<script type="text/javascript">
 var format="HTML"
 function setFocus() {
 textEdit.focus()
}

 function execCommand(command) {
 textEdit.focus()
 if (format=="HTML") {
     var edit = textEdit.document.selection.createRange()
 if (arguments[1]==null)
     edit.execCommand(command)
else
     edit.execCommand(command,false, arguments[1])
     edit.select()
     textEdit.focus()
 }
 }

 function selectAllText() {
     var edit = textEdit.document;
     edit.execCommand('SelectAll');
     textEdit.focus();
 }

 function newDocument() {
     textEdit.document.open()
     textEdit.document.write("")
     textEdit.document.close()
     textEdit.focus()
 }
  
 function loadDoc(htmlString) {
     textEdit.document.open()
     textEdit.document.write(htmlString)
     textEdit.document.close()
 }

 function initEditor() {
     var htmlString = parent.document.all.EditorValue.value;
     textEdit.document.designMode = "On"
     textEdit.document.open()
     textEdit.document.write(htmlString)
     textEdit.document.close()
     textEdit.focus()
 }

 function swapModes() {
 if (format == "HTML") {
     textEdit.document.body.innerText = textEdit.document.body.innerHTML
     textEdit.document.body.style.fontFamily = "courier new"
     textEdit.document.body.style.fontSize = "12px"
     format = "Text"
}
else {
     textEdit.document.body.innerHTML = textEdit.document.body.innerText
     textEdit.document.body.style.fontFamily = ""
     textEdit.document.body.style.fontSize = ""
     format = "HTML"
 }
 var s = textEdit.document.body.createTextRange()
 s.collapse(false)
 s.select()
 }
window.onload = initEditor
</script>
<body scroll=No>
<iframe ID=textEdit>
</iframe>
<script type="text/javascript">
 textEdit.focus();
</script>
</body>
</html>
