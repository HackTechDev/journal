/*
    javascript - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.0 (06 December 2004)  : initial release, scripts mini-editor extracted from postguest (by Icare)
	                         added other browsers compatibility (by Icare)
*/

function MM_showHideLayers() {
  var i,p,v,obj,args=MM_showHideLayers.arguments;
  for (i=0; i<(args.length-2); i+=3) if ((obj=MM_findObj(args[i]))!=null) { v=args[i+2];
    if (obj.style) { obj=obj.style; v=(v=='show')?'visible':(v='hide')?'hidden':v; }
    obj.visibility=v; }
 }

function MM_findObj(n, d) {
  var p,i,x;  if(!d) d=document; if((p=n.indexOf("?"))>0&&parent.frames.length) {
    d=parent.frames[n.substring(p+1)].document; n=n.substring(0,p); }
  if(!(x=d[n])&&d.all) x=d.all[n]; for (i=0;!x&&i<d.forms.length;i++) x=d.forms[i][n];
  for(i=0;!x&&d.layers&&i<d.layers.length;i++) x=MM_findObj(n,d.layers[i].document);
  if(!x && document.getElementById) x=document.getElementById(n); return x;
 }

function couleur(colorstring) {
  if (document.selection) {
    var str = document.selection.createRange().text;
    document.rapporter.ptxt.focus();
    var sel = document.selection.createRange();
    sel.text = "[c=" + colorstring + "]"  + str +  "[/c]";
	}
	else {
    document.rapporter.ptxt.value=document.rapporter.ptxt.value + "[c=" + colorstring + "] [/c]"; }
    document.rapporter.ptxt.focus();
    MM_showHideLayers('Layer1','','hide')  
 }

function surlign(colorstring) {
  if (document.selection) {
    var str = document.selection.createRange().text;
    document.rapporter.ptxt.focus();
    var sel = document.selection.createRange();
    sel.text = "[span style=background-color:" + colorstring + "]"  + str +  "[/span]";
	}
	else {
document.rapporter.ptxt.value=document.rapporter.ptxt.value + "[span style=background-color:" + colorstring + "] [/span]";
 }	
    document.rapporter.ptxt.focus();
	MM_showHideLayers('Layer2','','hide');
 }

function format(f) {
  if (document.selection) {
    var str = document.selection.createRange().text;
    document.rapporter.ptxt.focus();
    var sel = document.selection.createRange();
    sel.text = "[" + f + "]"  + str +  "[/" + f + "]";
	}
	else {
    document.rapporter.ptxt.focus();
	document.rapporter.ptxt.value =document.rapporter.ptxt.value + "[" + f + "] [/" + f + "]"; }
    document.rapporter.ptxt.focus();
 }

function AddSmiley(zoop) {
  if (document.selection) {
    document.rapporter.ptxt.focus();
    var sel = document.selection.createRange();
    sel.text = zoop;
	}
	else {
    document.rapporter.ptxt.focus();
    document.rapporter.ptxt.value=document.rapporter.ptxt.value+zoop; }
    document.rapporter.ptxt.focus();
 }
    
function undo() {
    document.execCommand("undo");
 }

function redo() {
    document.execCommand("redo");
}
