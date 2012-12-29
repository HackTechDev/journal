<?php
/*
    Mini-editor controls - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2005 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.0 (06 December 2004)  : initial release
                                 controls extracted  from postguest (by Icare)
      v4.6.0 (04 June 2007)    : added chr(10) and chr(13) replacement (by Djchouix)
      v4.6.10 (7 September 2009)    : corrected #272
*/

if (stristr($_SERVER["SCRIPT_NAME"], "ptxt_ctrl.inc")) {
  header("location:../index.php");
  die();
}
if ($browser == "OK") {
	$ptxt = str_replace('&amp;','&',$ptxt);
   if(preg_match_all("`<code([^>]*)>(.+)</code>`isU",$ptxt,$codeHTML)){
  	for($i=0; $i < count($codeHTML[0]); $i++) {
			$codetraite = $codeHTML[2][$i];
			if(!preg_match('` options=\"[a-z0-9\[\]\:]+\"`',$codeHTML[1][$i])) {
				$codetraite = str_replace('<br />',"\n",$codetraite);
			}
			$codetraite = str_replace('&nbsp;',' ',$codetraite);
			$codetraite = str_replace('&lt;','<&shy;',$codetraite);
			$codetraite = str_replace('&gt;','&shy;>\\\\n',$codetraite);
			$codetraite = str_replace('&#36;','$',$codetraite);
			$ptxt = str_replace('<code'.$codeHTML[1][$i].'>'.$codeHTML[2][$i].'</code>','<code'.$codeHTML[1][$i].'>'.$codetraite.'</code>',$ptxt);
		}
  }
  $ptxt = str_replace('&lt;br /&gt;','\n',$ptxt);
}
else {
$ptxt = str_replace("<","&lt;",$ptxt);
$ptxt = str_replace(">","&gt;",$ptxt);
$ptxt = str_replace("$","&#36;",$ptxt);
$ptxt = str_replace(chr(10),"<br />",$ptxt);  //remplacement \n par <br />
$ptxt = str_replace(chr(13),"",$ptxt);
$ptxt = str_replace("[n]","<p align=center>",$ptxt);
$ptxt = str_replace("[/n]","</p>",$ptxt);
$ptxt = str_replace("[N]","<p align=center>",$ptxt);
$ptxt = str_replace("[/N]","</p>",$ptxt);
$ptxt = str_replace("[b]","<b>",$ptxt);
$ptxt = str_replace("[B]","<b>",$ptxt);
$ptxt = str_replace("[/b]","</b>",$ptxt);
$ptxt = str_replace("[/B]","</b>",$ptxt);
$ptxt = str_replace("[p]","<pre>",$ptxt);
$ptxt = str_replace("[P]","<pre>",$ptxt);
$ptxt = str_replace("[/p]","</pre>",$ptxt);
$ptxt = str_replace("[/P]","</pre>",$ptxt);
$ptxt = str_replace("[i]","<i>",$ptxt);
$ptxt = str_replace("[I]","<i>",$ptxt);
$ptxt = str_replace("[/i]","</i>",$ptxt);
$ptxt = str_replace("[/I]","</i>",$ptxt);
$ptxt = str_replace("[u]","<u>",$ptxt);
$ptxt = str_replace("[U]","<u>",$ptxt);
$ptxt = str_replace("[/u]","</u>",$ptxt);
$ptxt = str_replace("[/U]","</u>",$ptxt);
$ptxt = str_replace("[q]","<br /><i>Dixit...</i><div style='padding: 4px; background-color: #FFFFFF; border: 1px solid #000099'>",$ptxt);
$ptxt = str_replace("[/q]","</div><br />",$ptxt);


$ptxt = preg_replace("!\\[l\\]([^\[\(\"']*)\\[/l\\]!i","<a href=\"\\1\" target=_blank>\\1</a>",$ptxt);
$ptxt = preg_replace("!\\[l\\]([^\[\(\"']*)\\[/L\\]!i","<a href=\"\\1\" target=_blank>\\1</a>",$ptxt);
$ptxt = preg_replace("!\\[L\\]([^\[\(\"']*)\\[/l\\]!i","<a href=\"\\1\" target=_blank>\\1</a>",$ptxt);
$ptxt = preg_replace("!\\[L\\]([^\[\(\"']*)\\[/L\\]!i","<a href=\"\\1\" target=_blank>\\1</a>",$ptxt);
$ptxt = preg_replace("!\\[l=([^\[\(\"']*)\\]([^\[]*)\\[/l\\]!i","<a href=\"\\1\" target=_blank>\\2</a>",$ptxt);
$ptxt = preg_replace("!\\[l=([^\[\(\"']*)\\]([^\[]*)\\[/L\\]!i","<a href=\"\\1\" target=_blank>\\2</a>",$ptxt);
$ptxt = preg_replace("!\\[L=([^\[\(\"']*)\\]([^\[]*)\\[/l\\]!i","<a href=\"\\1\" target=_blank>\\2</a>",$ptxt);
$ptxt = preg_replace("!\\[L=([^\[\(\"']*)\\]([^\[]*)\\[/L\\]!i","<a href=\"\\1\" target=_blank>\\2</a>",$ptxt);
$ptxt = preg_replace("!\\[l\\]www.([^\[\(\"']*)\\[/l\\]!i", "<a href=\"http://www.\\1\" target=_blank>\\1</a>",$ptxt);
$ptxt = preg_replace("!\\[l\\]www.([^\[\(\"']*)\\[/L\\]!i", "<a href=\"http://www.\\1\" target=_blank>\\1</a>",$ptxt);
$ptxt = preg_replace("!\\[L\\]www.([^\[\(\"']*)\\[/l\\]!i", "<a href=\"http://www.\\1\" target=_blank>\\1</a>",$ptxt);
$ptxt = preg_replace("!\\[L\\]www.([^\[\(\"']*)\\[/L\\]!i", "<a href=\"http://www.\\1\" target=_blank>\\1</a>",$ptxt);

$ptxt = preg_replace("/(\[c=([#a-zA-Z0-9]*)\])(.*?)(\[\/c\])/i", "<font style=\"color:\\2\">\\3</font>",$ptxt);
$ptxt = preg_replace("/(\[c=([#a-zA-Z0-9]*)\])(.*?)(\[\/C\])/i", "<font style=\"color:\\2\">\\3</font>",$ptxt);
$ptxt = preg_replace("/(\[C=([#a-zA-Z0-9]*)\])(.*?)(\[\/c\])/i", "<font style=\"color:\\2\">\\3</font>",$ptxt);
$ptxt = preg_replace("/(\[C=([#a-zA-Z0-9]*)\])(.*?)(\[\/C\])/i", "<font style=\"color:\\2\">\\3</font>",$ptxt);
//$ptxt = preg_replace("/(\[)(.*?)(\])/i","<\\2>",$ptxt);
}
?>
