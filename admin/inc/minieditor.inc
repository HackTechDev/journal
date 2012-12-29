<?php
/*
    Mini-editor - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v2.3 (27 July 2003)      : initial release by Nicolas Alves
      v2.4 (24 September 2003) : no change
      v3.0 (25 February 2004)  : no change
      v3.0p2 (09 April 2004)   : corrected "adress" typo mistake to "address" (thanks JeanMi)
	  v4.0 (25 October 2004)   : updated MM_showHidelayer and MM_findObj (by Icare)
	                             added other browsers low compatibility (by Icare)
							     updated and added Gecko compatibility (thanks Djchioux)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "minieditor.inc")) {
  header("location:../index.php");
  die();
}

?>
<script language="JavaScript" type="text/javascript">
<!--
function MM_showHideLayers() { //v3.0
  var i,p,v,obj,args=MM_showHideLayers.arguments;
  for (i=0; i<(args.length-2); i+=3) if ((obj=MM_findObj(args[i]))!=null) { v=args[i+2];
    if (obj.style) { obj=obj.style; v=(v=='show')?'visible':(v='hide')?'hidden':v; }
    obj.visibility=v; }
}
function MM_findObj(n, d) { //v4.0
  var p,i,x;  if(!d) d=document; if((p=n.indexOf("?"))>0&&parent.frames.length) {
    d=parent.frames[n.substring(p+1)].document; n=n.substring(0,p);}
  if(!(x=d[n])&&d.all) x=d.all[n]; for (i=0;!x&&i<d.forms.length;i++) x=d.forms[i][n];
  for(i=0;!x&&d.layers&&i<d.layers.length;i++) x=MM_findObj(n,d.layers[i].document);
  if(!x && document.getElementById) x=document.getElementById(n); return x;
}


// --- textarea contenu1 --- //
function AddSmiley1(zoop) {
if (document.selection) {
    document.adminsend.contenu1.focus();
    var sel = document.selection.createRange();
    sel.text = zoop;
    document.adminsend.contenu1.focus();
  }
else if (navigator.product == "Gecko" && navigator.productSub >= 20030210) {
        document.adminsend.contenu1.focus();
        var startPos = document.adminsend.contenu1.selectionStart;
        var endPos = document.adminsend.contenu1.selectionEnd;
        var chaine = document.adminsend.contenu1.value;
        document.adminsend.contenu1.value = chaine.substring(0, startPos) + zoop + chaine.substring(endPos, chaine.length);
        document.adminsend.contenu1.selectionStart = startPos + zoop.length ;
        document.adminsend.contenu1.selectionEnd = startPos+ zoop.length ;
        document.adminsend.contenu1.focus();
        return;
        }
else {
        var chaine = document.adminsend.contenu1.value;
        document.adminsend.contenu1.value = chaine + zoop;
		document.adminsend.contenu1.focus();
        return;
		}
}
 
function format(f) {
if (document.selection) {
     var str = document.selection.createRange().text;
     document.adminsend.contenu1.focus();
     var sel = document.selection.createRange();
     sel.text = '<' + f + '>' + str + '<\/' + f + '>';
     document.adminsend.contenu1.focus();
     return;
     }
else if (navigator.product == "Gecko" && navigator.productSub >= 20030210) {
     var startPos = document.adminsend.contenu1.selectionStart;
     var endPos = document.adminsend.contenu1.selectionEnd;
     var chaine = document.adminsend.contenu1.value;
     document.adminsend.contenu1.value = chaine.substring(0, startPos) + '<' + f + '>' + chaine.substring(startPos, endPos) + '<\/' + f + '>' + chaine.substring(endPos, chaine.length);
     document.adminsend.contenu1.focus();
     return;
}
else {
      var chaine = document.adminsend.contenu1.value;
      document.adminsend.contenu1.value = chaine + '<' + f + '> <\/' + f + '>';
      document.adminsend.contenu1.focus();
      return;
	}
}

function alignement(f) {
if (document.selection) {
     var str = document.selection.createRange().text;
     document.adminsend.contenu1.focus();
     var sel = document.selection.createRange();
     sel.text = '<' + f + '>' + str + "<\/p>";
     document.adminsend.contenu1.focus();
     return;
     }
else if (navigator.product == "Gecko" && navigator.productSub >= 20030210) {
     var startPos = document.adminsend.contenu1.selectionStart;
     var endPos = document.adminsend.contenu1.selectionEnd;
     var chaine = document.adminsend.contenu1.value;
     document.adminsend.contenu1.value = chaine.substring(0, startPos) + '<' + f + '>' + chaine.substring(startPos, endPos) + '<\/p>' + chaine.substring(endPos, chaine.length);
     document.adminsend.contenu1.focus();
     return;
}
else {
      var chaine = document.adminsend.contenu1.value;
      document.adminsend.contenu1.value = chaine + '<' + f + '> <\/p>';
      document.adminsend.contenu1.focus();
      return;
	}
}

function dolink(f) {
if (document.selection) {
     var str = document.selection.createRange().text;
     document.adminsend.contenu1.focus();
     var sel = document.selection.createRange();
     sel.text = '<' + f + '>' + str + '<\/a>';
     document.adminsend.contenu1.focus();
     return;
     }
else if (navigator.product == "Gecko" && navigator.productSub >= 20030210) {
     var startPos = document.adminsend.contenu1.selectionStart;
     var endPos = document.adminsend.contenu1.selectionEnd;
     var chaine = document.adminsend.contenu1.value;
     document.adminsend.contenu1.value = chaine.substring(0, startPos) + '<' + f + '>' + chaine.substring(startPos, endPos) + '<\/a>' + chaine.substring(endPos, chaine.length);
     document.adminsend.contenu1.focus();
     return;
}
else {
      var chaine = document.adminsend.contenu1.value;
      document.adminsend.contenu1.value = chaine + '<' + f + '> <\/a>';
      document.adminsend.contenu1.focus();
      return;
	}
}
 
 function fontlist(f) {
if (document.selection) {
    var str = document.selection.createRange().text;
    document.adminsend.contenu1.focus();
    var sel = document.selection.createRange();
    sel.text = '<font face="' + f + '">'  + str +  '<\/font>';
    document.adminsend.contenu1.focus();
	return;
}
else if (navigator.product == "Gecko" && navigator.productSub >= 20030210) {
     var startPos = document.adminsend.contenu1.selectionStart;
     var endPos = document.adminsend.contenu1.selectionEnd;
     var chaine = document.adminsend.contenu1.value;
     document.adminsend.contenu1.value = chaine.substring(0, startPos) + '<font face="' + f + '">' + chaine.substring(startPos, endPos) + '<\/font>' + chaine.substring(endPos, chaine.length);
     document.adminsend.contenu1.focus();
     return;
}
else {
      var chaine = document.adminsend.contenu1.value;
      document.adminsend.contenu1.value = chaine + '<font face="' + f + '"> <\/font>';
      document.adminsend.contenu1.focus();
      return;
	}
} 

 function formatstyle(f) {
if (document.selection) {
     var str = document.selection.createRange().text;
     document.adminsend.contenu1.focus();
     var sel = document.selection.createRange();
     sel.text = '<' + f + '>' + str + '<\/' + f + '>';
     document.adminsend.contenu1.focus();
	return;
}
else if (navigator.product == "Gecko" && navigator.productSub >= 20030210) {
     var startPos = document.adminsend.contenu1.selectionStart;
     var endPos = document.adminsend.contenu1.selectionEnd;
     var chaine = document.adminsend.contenu1.value;
     document.adminsend.contenu1.value = chaine.substring(0, startPos) + "<" + f + ">" + chaine.substring(startPos, endPos) + "<\/" + f + ">" + chaine.substring(endPos, chaine.length);
     document.adminsend.contenu1.focus();
     return;
}
else {
      var chaine = document.adminsend.contenu1.value;
      document.adminsend.contenu1.value = chaine + "<" + f + "> <\/" + f + ">";
      document.adminsend.contenu1.focus();
      return;
	}
} 

function couleur(colorstring) {
if (document.selection) {
    var str = document.selection.createRange().text;
    document.adminsend.contenu1.focus();
    var sel = document.selection.createRange();
    sel.text = '<span style="color:' + colorstring + ';">'  + str +  '<\/span>';
    document.adminsend.contenu1.focus();
	return;
}
else if (navigator.product == "Gecko" && navigator.productSub >= 20030210) {
     var startPos = document.adminsend.contenu1.selectionStart;
     var endPos = document.adminsend.contenu1.selectionEnd;
     var chaine = document.adminsend.contenu1.value;
     document.adminsend.contenu1.value = chaine.substring(0, startPos) + '<span style="color: ' + colorstring +';">' + chaine.substring(startPos, endPos) + '<\/span>' + chaine.substring(endPos, chaine.length);
     document.adminsend.contenu1.focus();
     return;
}
else {
        var chaine = document.adminsend.contenu1.value;
        document.adminsend.contenu1.value = chaine + '<span style="color: ' + colorstring +';"> <\/span>' ;
		document.adminsend.contenu1.focus();
        return;
		}
}

function surlignement(colorstring) {
if (document.selection) {
    var str = document.selection.createRange().text;
    document.adminsend.contenu1.focus();
    var sel = document.selection.createRange();
    sel.text = '<span style="background-color:' + colorstring + ';">'  + str +  '<\/span>';
    document.adminsend.contenu1.focus();
	return;
}
else if (navigator.product == "Gecko" && navigator.productSub >= 20030210) {
        var startPos = document.adminsend.contenu1.selectionStart;
        var endPos = document.adminsend.contenu1.selectionEnd;
        var chaine = document.adminsend.contenu1.value;
        document.adminsend.contenu1.value = chaine.substring(0, startPos) + '<span style="background-color: ' + colorstring +';">' + chaine.substring(startPos, endPos) + '<\/span>' + chaine.substring(endPos, chaine.length);
        document.adminsend.contenu1.focus();
        return;
}
else {
        var chaine = document.adminsend.contenu1.value;
        document.adminsend.contenu1.value = chaine + '<span style="background-color: ' + colorstring +';"> <\/span>' ;
		document.adminsend.contenu1.focus();
        return;
		}
}

//  --- textarea contenu2 ---  //
function AddSmiley2(zoop) {
if (document.selection) {
    document.adminsend.contenu2.focus();
    var sel = document.selection.createRange();
    sel.text = zoop;
    document.adminsend.contenu2.focus();
  }
else if (navigator.product == "Gecko" && navigator.productSub >= 20030210) {
            document.adminsend.contenu2.focus();
        var startPos = document.adminsend.contenu2.selectionStart;
        var endPos = document.adminsend.contenu2.selectionEnd;
        var chaine = document.adminsend.contenu2.value;
        document.adminsend.contenu2.value = chaine.substring(0, startPos) + zoop + chaine.substring(endPos, chaine.length);
        document.adminsend.contenu2.selectionStart = startPos + zoop.length ;
        document.adminsend.contenu2.selectionEnd = startPos+ zoop.length ;
        document.adminsend.contenu2.focus();
        return;
        }
else {
        var chaine = document.adminsend.contenu2.value;
        document.adminsend.contenu2.value = chaine + zoop;
		document.adminsend.contenu2.focus();
        return;
		}
}
 
function format2(f) {
if (document.selection) {
     var str = document.selection.createRange().text;
     document.adminsend.contenu2.focus();
     var sel = document.selection.createRange();
     sel.text = '<' + f + '>' + str + '<\/' + f + '>';
     document.adminsend.contenu2.focus();
     return;
     }
else if (navigator.product == "Gecko" && navigator.productSub >= 20030210) {
     var startPos = document.adminsend.contenu2.selectionStart;
     var endPos = document.adminsend.contenu2.selectionEnd;
     var chaine = document.adminsend.contenu2.value;
     document.adminsend.contenu2.value = chaine.substring(0, startPos) + '<' + f + '>' + chaine.substring(startPos, endPos) + '<\/' + f + '>' + chaine.substring(endPos, chaine.length);
     document.adminsend.contenu2.focus();
     return;
}
else {
      var chaine = document.adminsend.contenu2.value;
      document.adminsend.contenu2.value = chaine + '<' + f + '> <\/' + f + '>';
      document.adminsend.contenu2.focus();
      return;
	}
}

function alignement2(f) {
if (document.selection) {
     var str = document.selection.createRange().text;
     document.adminsend.contenu2.focus();
     var sel = document.selection.createRange();
     sel.text = '<' + f + '>' + str + "<\/p>";
     document.adminsend.contenu2.focus();
     return;
     }
else if (navigator.product == "Gecko" && navigator.productSub >= 20030210) {
     var startPos = document.adminsend.contenu2.selectionStart;
     var endPos = document.adminsend.contenu2.selectionEnd;
     var chaine = document.adminsend.contenu2.value;
     document.adminsend.contenu2.value = chaine.substring(0, startPos) + '<' + f + '>' + chaine.substring(startPos, endPos) + '<\/p>' + chaine.substring(endPos, chaine.length);
     document.adminsend.contenu2.focus();
     return;
}
else {
      var chaine = document.adminsend.contenu2.value;
      document.adminsend.contenu2.value = chaine + '<' + f + '> <\/p>';
      document.adminsend.contenu2.focus();
      return;
	}
}

function dolink2(f) {
if (document.selection) {
     var str = document.selection.createRange().text;
     document.adminsend.contenu2.focus();
     var sel = document.selection.createRange();
     sel.text = '<' + f + '>' + str + '<\/a>';
     document.adminsend.contenu2.focus();
     return;
     }
else if (navigator.product == "Gecko" && navigator.productSub >= 20030210) {
     var startPos = document.adminsend.contenu2.selectionStart;
     var endPos = document.adminsend.contenu2.selectionEnd;
     var chaine = document.adminsend.contenu2.value;
     document.adminsend.contenu2.value = chaine.substring(0, startPos) + '<' + f + '>' + chaine.substring(startPos, endPos) + '<\/a>' + chaine.substring(endPos, chaine.length);
     document.adminsend.contenu2.focus();
     return;
}
else {
      var chaine = document.adminsend.contenu2.value;
      document.adminsend.contenu2.value = chaine + '<' + f + '> <\/a>';
      document.adminsend.contenu2.focus();
      return;
	}
}
 
 function fontlist2(f) {
if (document.selection) {
    var str = document.selection.createRange().text;
    document.adminsend.contenu2.focus();
    var sel = document.selection.createRange();
    sel.text = '<font face="' + f + '">'  + str +  '<\/font>';
    document.adminsend.contenu2.focus();
	return;
}
else if (navigator.product == "Gecko" && navigator.productSub >= 20030210) {
     var startPos = document.adminsend.contenu2.selectionStart;
     var endPos = document.adminsend.contenu2.selectionEnd;
     var chaine = document.adminsend.contenu2.value;
     document.adminsend.contenu2.value = chaine.substring(0, startPos) + '<font face="' + f + '">' + chaine.substring(startPos, endPos) + '<\/font>' + chaine.substring(endPos, chaine.length);
     document.adminsend.contenu2.focus();
     return;
}
else {
      var chaine = document.adminsend.contenu2.value;
      document.adminsend.contenu2.value = chaine + '<font face="' + f + '"> <\/font>';
      document.adminsend.contenu2.focus();
      return;
	}
} 

 function formatstyle2(f) {
if (document.selection) {
     var str = document.selection.createRange().text;
     document.adminsend.contenu2.focus();
     var sel = document.selection.createRange();
     sel.text = '<' + f + '>' + str + '<\/' + f + '>';
     document.adminsend.contenu2.focus();
	return;
}
else if (navigator.product == "Gecko" && navigator.productSub >= 20030210) {
     var startPos = document.adminsend.contenu2.selectionStart;
     var endPos = document.adminsend.contenu2.selectionEnd;
     var chaine = document.adminsend.contenu2.value;
     document.adminsend.contenu2.value = chaine.substring(0, startPos) + "<" + f + ">" + chaine.substring(startPos, endPos) + "<\/" + f + ">" + chaine.substring(endPos, chaine.length);
     document.adminsend.contenu2.focus();
     return;
}
else {
      var chaine = document.adminsend.contenu2.value;
      document.adminsend.contenu2.value = chaine + "<" + f + "> <\/" + f + ">";
      document.adminsend.contenu2.focus();
      return;
	}
} 

function color(colorstring) {
if (document.selection) {
    var str = document.selection.createRange().text;
    document.adminsend.contenu2.focus();
    var sel = document.selection.createRange();
    sel.text = '<span style="color:' + colorstring + ';">'  + str +  '<\/span>';
    document.adminsend.contenu2.focus();
	return;
}
else if (navigator.product == "Gecko" && navigator.productSub >= 20030210) {
     var startPos = document.adminsend.contenu2.selectionStart;
     var endPos = document.adminsend.contenu2.selectionEnd;
     var chaine = document.adminsend.contenu2.value;
     document.adminsend.contenu2.value = chaine.substring(0, startPos) + '<span style="color: ' + colorstring +';">' + chaine.substring(startPos, endPos) + '<\/span>' + chaine.substring(endPos, chaine.length);
     document.adminsend.contenu2.focus();
     return;
}
else {
        var chaine = document.adminsend.contenu2.value;
        document.adminsend.contenu2.value = chaine + '<span style="color: ' + colorstring +';"> <\/span>' ;
		document.adminsend.contenu2.focus();
        return;
		}
}

function surlign(colorstring) {
if (document.selection) {
    var str = document.selection.createRange().text;
    document.adminsend.contenu1.focus();
    var sel = document.selection.createRange();
    sel.text = '<span style="background-color:' + colorstring + ';">'  + str +  '<\/span>';
    document.adminsend.contenu1.focus();
	return;
}
else if (navigator.product == "Gecko" && navigator.productSub >= 20030210) {
        var startPos = document.adminsend.contenu2.selectionStart;
        var endPos = document.adminsend.contenu2.selectionEnd;
        var chaine = document.adminsend.contenu2.value;
        document.adminsend.contenu2.value = chaine.substring(0, startPos) + '<span style="background-color: ' + colorstring +';">' + chaine.substring(startPos, endPos) + '<\/span>' + chaine.substring(endPos, chaine.length);
        document.adminsend.contenu2.focus();
        return;
}
else {
        var chaine = document.adminsend.contenu2.value;
        document.adminsend.contenu2.value = chaine + '<span style="background-color: ' + colorstring +';"> <\/span>' ;
		document.adminsend.contenu2.focus();
        return;
		}
}
-->
</script>

<DIV id=Layer1 style="Z-INDEX: 1; LEFT: 600px; VISIBILITY: hidden; WIDTH: 180px; POSITION: absolute; TOP: 650px; HEIGHT: 120px">
<A href="#" onclick="MM_showHideLayers('Layer1','','hide')">
<table class="clsCursor" border="0" cellspacing="1" cellpadding="1" align="center" bgcolor="#ffffff">
<tr>
<?php
$fill = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
$col_r = 0;
$col_g = 0;
$col_b = 0;
$row_return = 0;
$block_return = 0;
while($col_r <= 255) {
  $col_g = 0;
  $block_return++;
  while($col_g <= 255) {
    $col_b = 0;
    while($col_b <= 255) {
      $red = strtoupper(dechex($col_r));
      $green = strtoupper(dechex($col_g));
      $blue = strtoupper(dechex($col_b));
      $color = str_pad($red,2,'0',STR_PAD_LEFT)."".str_pad($green,2,'0',STR_PAD_LEFT)."".str_pad($blue,2,'0',STR_PAD_LEFT);
      echo "<td height=\"10\" width=\"10\" bgcolor=\"#".$color."\" onclick='couleur(\"#".$color."\")'></td>";
      $row_return++;
      if($row_return == 18) {
        echo "</tr><tr>";
        $row_return = 0;
      }
      $col_b += 51;
    }
    $col_g += 51;
  }
  $col_r += 51;
}
$col = 15;
while($col <= 255) {
  $red = strtoupper(dechex($col));
  $green = strtoupper(dechex($col));
  $blue = strtoupper(dechex($col));
  $color = str_pad($red,2,'0',STR_PAD_LEFT)."".str_pad($green, 2,'0',STR_PAD_LEFT)."".str_pad($blue,2,'0',STR_PAD_LEFT);
  echo "<td height=\"10\" width=\"10\" bgcolor=\"#".$color."\" onclick='couleur(\"#".$color."\")'></td>";
  $col += 14;
}
?>
</tr><tr><td colspan="18" align="center" bgColor="#C0C0C0">
<A href="#" onclick="MM_showHideLayers('Layer1','','hide')"><font color="#ffffff" size="1" face="Verdana"><?php echo $admin458; ?></font></A>
</td></tr></table></A></DIV>

<DIV id=Layer2 style="Z-INDEX: 2; LEFT: 600px; VISIBILITY: hidden; WIDTH: 180px; POSITION: absolute; TOP: 650px; HEIGHT: 120px">
<A href="#" onclick="MM_showHideLayers('Layer2','','hide')">
<table class="clsCursor" border="0" cellspacing="1" cellpadding="1" align="center" bgcolor="#ffffff">
<tr>
<?php
$fill = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
$col_r = 0;
$col_g = 0;
$col_b = 0;
$row_return = 0;
$block_return = 0;
while($col_r <= 255) {
  $col_g = 0;
  $block_return++;
  while($col_g <= 255) {
    $col_b = 0;
    while($col_b <= 255) {
      $red = strtoupper(dechex($col_r));
      $green = strtoupper(dechex($col_g));
      $blue = strtoupper(dechex($col_b));
      $color = str_pad($red,2,'0',STR_PAD_LEFT)."".str_pad($green,2,'0',STR_PAD_LEFT)."".str_pad($blue,2,'0',STR_PAD_LEFT);
      echo "<td height=\"10\" width=\"10\" bgcolor=\"#".$color."\" onclick='surlignement(\"#".$color."\")'></td>";
      $row_return++;
      if($row_return == 18) {
        echo "</tr><tr>";
        $row_return = 0;
      }
      $col_b += 51;
    }
    $col_g += 51;
  }
  $col_r += 51;
}
$col = 15;
while($col <= 255) {
  $red = strtoupper(dechex($col));
  $green = strtoupper(dechex($col));
  $blue = strtoupper(dechex($col));
  $color = str_pad($red,2,'0',STR_PAD_LEFT)."".str_pad($green, 2,'0',STR_PAD_LEFT)."".str_pad($blue,2,'0',STR_PAD_LEFT);
  echo "<td height=\"10\" width=\"10\" bgcolor=\"#".$color."\" onclick='surlignement(\"#".$color."\")'></td>";
  $col += 14;
}
?>
</tr><tr><td colspan="18" align="center" bgColor="#C0C0C0">
<A href="#" onclick="MM_showHideLayers('Layer2','','hide')"><font color="#ffffff" size="1" face="Verdana"><?php echo $admin458; ?></font></A>
</td></tr></table></A></DIV>

<DIV id=Layer3 style="Z-INDEX: 3; LEFT: 600px; VISIBILITY: hidden; WIDTH: 180px; POSITION: absolute; TOP: 1120px; HEIGHT: 120px">
<A href="#" onclick="MM_showHideLayers('Layer3','','hide')">
<table class="clsCursor" border="0" cellspacing="1" cellpadding="1" align="center" bgcolor="#ffffff">
<tr>
<?php
$fill = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
$col_r = 0;
$col_g = 0;
$col_b = 0;
$row_return = 0;
$block_return = 0;
while($col_r <= 255) {
  $col_g = 0;
  $block_return++;
  while($col_g <= 255) {
    $col_b = 0;
    while($col_b <= 255) {
      $red = strtoupper(dechex($col_r));
      $green = strtoupper(dechex($col_g));
      $blue = strtoupper(dechex($col_b));
      $color = str_pad($red,2,'0',STR_PAD_LEFT)."".str_pad($green,2,'0',STR_PAD_LEFT)."".str_pad($blue,2,'0',STR_PAD_LEFT);
      echo "<td height=\"10\" width=\"10\" bgcolor=\"#".$color."\" onclick='color(\"#".$color."\")'></td>";
      $row_return++;
      if($row_return == 18) {
        echo "</tr><tr>";
        $row_return = 0;
      }
      $col_b += 51;
    }
    $col_g += 51;
  }
  $col_r += 51;
}
$col = 15;
while($col <= 255) {
  $red = strtoupper(dechex($col));
  $green = strtoupper(dechex($col));
  $blue = strtoupper(dechex($col));
  $color = str_pad($red,2,'0',STR_PAD_LEFT)."".str_pad($green, 2,'0',STR_PAD_LEFT)."".str_pad($blue,2,'0',STR_PAD_LEFT);
  echo "<td height=\"10\" width=\"10\" bgcolor=\"#".$color."\" onclick='color(\"#".$color."\")'></td>";
  $col += 14;
}
?>
</tr><tr><td colspan="18" align="center" bgColor="#C0C0C0">
<A href="#" onclick="MM_showHideLayers('Layer3','','hide')"><font color="#ffffff" size="1" face="Verdana"><?php echo $admin458; ?></font></A>
</td></tr></table></A></DIV>

<DIV id=Layer4 style="Z-INDEX: 4; LEFT: 600px; VISIBILITY: hidden; WIDTH: 180px; POSITION: absolute; TOP: 1100px; HEIGHT: 120px">
<A href="#" onclick="MM_showHideLayers('Layer4','','hide')">
<table class="clsCursor" border="0" cellspacing="1" cellpadding="1" align="center" bgcolor="#ffffff">
<tr>
<?php
$fill = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
$col_r = 0;
$col_g = 0;
$col_b = 0;
$row_return = 0;
$block_return = 0;
while($col_r <= 255) {
  $col_g = 0;
  $block_return++;
  while($col_g <= 255) {
    $col_b = 0;
    while($col_b <= 255) {
      $red = strtoupper(dechex($col_r));
      $green = strtoupper(dechex($col_g));
      $blue = strtoupper(dechex($col_b));
      $color = str_pad($red,2,'0',STR_PAD_LEFT)."".str_pad($green,2,'0',STR_PAD_LEFT)."".str_pad($blue,2,'0',STR_PAD_LEFT);
      echo "<td height=\"10\" width=\"10\" bgcolor=\"#".$color."\" onclick='surlign(\"#".$color."\")'></td>";
      $row_return++;
      if($row_return == 18) {
        echo "</tr><tr>";
        $row_return = 0;
      }
      $col_b += 51;
    }
    $col_g += 51;
  }
  $col_r += 51;
}
$col = 15;
while($col <= 255) {
  $red = strtoupper(dechex($col));
  $green = strtoupper(dechex($col));
  $blue = strtoupper(dechex($col));
  $color = str_pad($red,2,'0',STR_PAD_LEFT)."".str_pad($green, 2,'0',STR_PAD_LEFT)."".str_pad($blue,2,'0',STR_PAD_LEFT);
  echo "<td height=\"10\" width=\"10\" bgcolor=\"#".$color."\" onclick='surlign(\"#".$color."\")'></td>";
  $col += 14;
}
?>
</tr><tr><td colspan="18" align="center" bgColor="#C0C0C0">
<A href="#" onclick="MM_showHideLayers('Layer4','','hide')"><font color="#ffffff" size="1" face="Verdana"><?php echo $admin458; ?></font></A>
</td></tr></table></A></DIV>

<DIV id=Layer5 style="Z-INDEX: 5; LEFT: 290px; VISIBILITY: hidden; WIDTH: 180px; POSITION: absolute; TOP: 680px; HEIGHT: 120px">
<A href="#" onclick="MM_showHideLayers('Layer5','','hide')">
<table class="clsCursor" border="1" style="border-color:black" bgcolor="#C0C0C0" cellspacing="1">
<tr><td onClick="fontlist('Arial')" align="center"><font size="1" face="Arial">Arial</font></td></tr>
<tr><td onClick="fontlist('Book Antiqua')" align="center"><font size="1" face="Book Antiqua">Book Antiqua</font></td></tr>
<tr><td onClick="fontlist('Comics Sans MS')" align="center"><font size="1" face="Comic Sans MS">Comics</font></td></tr>
<tr><td onClick="fontlist('Courier')" align="center"><font size="1" face="Courier">Courier</font></td></tr>
<tr><td onClick="fontlist('Tahoma')" align="center"><font size="1" face="Tahoma">Tahoma</font></td></tr>
<tr><td onClick="fontlist('Times New Roman')" align="center"><font size="1" face="Times New Roman">Times New Roman</font></td></tr>
<tr><td onClick="fontlist('Verdana')" align="center"><font face="Verdana" size="1">Verdana</font></td></tr>
<tr><td align="center"><font face="Verdana" size="1" color="#FFFFFF"><?php echo $admin458; ?></font></td></tr>
</table></A></DIV>

<DIV id=Layer6 style="Z-INDEX: 6; LEFT: 290px; VISIBILITY: hidden; WIDTH: 180px; POSITION: absolute; TOP: 1120px; HEIGHT: 120px">
<A href="#" onclick="MM_showHideLayers('Layer6','','hide')">
<table class="clsCursor" border="1" style="border-color:black" bgcolor="#C0C0C0" cellspacing="1">
<tr><td onClick="fontlist2('Arial');" align="center"><font size="1" face="Arial">Arial</font></td></tr>
<tr><td onClick="fontlist2('Book Antiqua');" align="center"><font size="1" face="Book Antiqua">Book Antiqua</font></td></tr>
<tr><td onClick="fontlist2('Comics Sans MS');" align="center"><font size="1" face="Comic Sans MS">Comics</font></td></tr>
<tr><td onClick="fontlist2('Courier');" align="center"><font size="1" face="Courier">Courier</font></td></tr>
<tr><td onClick="fontlist2('Tahoma');" align="center"><font size="1" face="Tahoma">Tahoma</font></td></tr>
<tr><td onClick="fontlist2('Times New Roman');" align="center"><font size="1" face="Times New Roman">Times New Roman</font></td></tr>
<tr><td onClick="fontlist2('Verdana');" align="center"><font face="Verdana" size="1">Verdana</font></td></tr>
<tr><td align="center"><font face="Verdana" size="1" color="#FFFFFF"><?php echo $admin458; ?></font></td></tr>
</table></A></div>

<DIV id=Layer7 style="Z-INDEX: 7; LEFT: 350px; VISIBILITY: hidden; WIDTH: 180px; POSITION: absolute; TOP: 680px; HEIGHT: 120px">
<A href="#" onclick="MM_showHideLayers('Layer7','','hide')">
<table class="clsCursor" border="1" style="border-color:black" bgcolor="#C0C0C0" cellspacing="1">
<tr><td align="center" onClick="formatstyle('h1')"><font face="Verdana" size="1"><?php echo $admin426; ?></font></td></tr>
<tr><td align="center" onClick="formatstyle('h2')"><font face="Verdana" size="1"><?php echo $admin427; ?></font></td></tr>
<tr><td align="center" onClick="formatstyle('h3')"><font face="Verdana" size="1"><?php echo $admin428; ?></font></td></tr>
<tr><td align="center" onClick="formatstyle('h4')"><font face="Verdana" size="1"><?php echo $admin429; ?></font></td></tr>
<tr><td align="center" onClick="formatstyle('h5')" ><font face="Verdana" size="1"><?php echo $admin430; ?></font></td></tr>
<tr><td align="center" onClick="formatstyle('h6')" ><font face="Verdana" size="1"><?php echo $admin431; ?></font></td></tr>
<tr><td align="center" onClick="formatstyle('address')" ><font face="Verdana" size="1"><?php echo $admin425; ?></font></td></tr>
<tr><td align="center" onClick="formatstyle('pre')" ><font face="Verdana" size="1"><?php echo $admin424; ?></font></td></tr>
<tr><td align="center"><font face="Verdana" size="1" color="#FFFFFF"><?php echo $admin458; ?></font></td></tr>
</table></A></div>

<DIV id=Layer8 style="Z-INDEX: 8; LEFT: 350px; VISIBILITY: hidden; WIDTH: 180px; POSITION: absolute; TOP: 1120px; HEIGHT: 120px">
<A href="#" onclick="MM_showHideLayers('Layer8','','hide')">
<table class="clsCursor" border="1" style="border-color:black" bgcolor="#C0C0C0" cellspacing="1">
<tr><td align="center" onClick="formatstyle2('h1');" ><font face="Verdana" size="1"><?php echo $admin426; ?></font></td></tr>
<tr><td align="center" onClick="formatstyle2('h2');"><font face="Verdana" size="1"><?php echo $admin427; ?></font></td></tr>
<tr><td align="center" onClick="formatstyle2('h3');"><font face="Verdana" size="1"><?php echo $admin428; ?></font></td></tr>
<tr><td align="center" onClick="formatstyle2('h4');"><font face="Verdana" size="1"><?php echo $admin429; ?></font></td></tr>
<tr><td align="center" onClick="formatstyle2('h5');" ><font face="Verdana" size="1"><?php echo $admin430; ?></font></td></tr>
<tr><td align="center" onClick="formatstyle2('h6');" ><font face="Verdana" size="1"><?php echo $admin431; ?></font></td></tr>
<tr><td align="center" onClick="formatstyle2('address');" ><font face="Verdana" size="1"><?php echo $admin425; ?></font></td></tr>
<tr><td align="center" onClick="formatstyle2('pre');" ><font face="Verdana" size="1"><?php echo $admin424; ?></font></td></tr>
<tr><td align="center"><font face="Verdana" size="1" color="#FFFFFF"><?php echo $admin458; ?></font></td></tr>
</table></A></div>
