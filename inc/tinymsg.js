/*
    Tinymsg Javascript - GuppY PHP Script -
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.6.0 (15 february)  : initial release (by Icare)
*/
  function AddSmiley(zoop) {
  if (document.selection) {
    document.nmsgr.msg.focus();
    var sel = document.selection.createRange();
    sel.text = zoop;
	}
	else {
    document.nmsgr.msg.focus();
    document.nmsgr.msg.value=document.nmsgr.msg.value+zoop;
  }
    document.nmsgr.msg.focus();
 }
  function format(f) {
  if (document.selection) {
    var str = document.selection.createRange().text;
    document.nmsgr.msg.focus();
    var sel = document.selection.createRange();
    sel.text = '[' + f + ']' + str + '[\/' + f + ']';
    document.nmsgr.msg.focus();
    return;
  }
  else if (navigator.product == "Gecko" && navigator.productSub >= 20030210) {
    var startPos = document.nmsgr.msg.selectionStart;
    var endPos = document.nmsgr.msg.selectionEnd;
    var chaine = document.nmsgr.msg.value;
    document.nmsgr.msg.value = chaine.substring(0, startPos) + '[' + f + ']' + chaine.substring(startPos, endPos) + '[\/' + f + ']' + chaine.substring(endPos, chaine.length);
    document.nmsgr.msg.focus();
    return;
  }
  else {
    var chaine = document.nmsgr.msg.value;
    document.nmsgr.msg.value = chaine + '[' + f + '] [\/' + f + ']';
    document.nmsgr.msg.focus();
    return;
	}
}
  function dolink(f) {
  if (document.selection) {
     var str = document.selection.createRange().text;
     document.nmsgr.msg.focus();
     var sel = document.selection.createRange();
     sel.text = '[l]' + f + str + '[\/l]';
     document.nmsgr.msg.focus();
     return;
  }
  else if (navigator.product == "Gecko" && navigator.productSub >= 20030210) {
     var startPos = document.nmsgr.msg.selectionStart;
     var endPos = document.nmsgr.msg.selectionEnd;
     var chaine = document.nmsgr.msg.value;
     document.nmsgr.msg.value = chaine.substring(0, startPos) + '[l]' + f + chaine.substring(startPos, endPos) + '[\/l]' + chaine.substring(endPos, chaine.length);
     document.nmsgr.msg.focus();
     return;
  }
  else {
      var chaine = document.nmsgr.msg.value;
      document.nmsgr.msg.value = chaine + '[l]' + f + '[\/l]';
      document.nmsgr.msg.focus();
      return;
	}
}
