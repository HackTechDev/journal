<?php
/*
    Symbol  - GuppY PHP Script - version 4.0
    CeCILL Copyright (C) 2004-2006 by Laurent Duveau
    Made by Laurent Duveau, Nicolas Alves, Albert Aymard, 
	Jean-Michel Misrachi, Isabelle Marchina and Team
      Web site = http://www.freeguppy.org/
      e-mail   = info@aldweb.com

    Version History :
      v2.3 (27 July 2003)      : initial release (by Nicolas Alves)
      v3.0 (25 February 2004)  : compatibility with php.ini register_globals=off parameter (thanks JonnyQuest)
      v4.0 (06 December 2004)  : nochange
*/

header("Pragma: no-cache");
define("CHEMIN", "../../../");
include(CHEMIN."inc/includes.inc");
$carspec = array("!","&quot;","#","$","%","&","'","(",")","*","+","-",".","/","0","1","2","3","4",
"5","6","7","8","9",":",";","&lt;","=","&gt;","?","@","A","B","C","D","E","F","G","H","I","J","K","L",
"M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","[","]","^","_","`","a","b","c","d","e","f","g",
"h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","{","|","}","~","&euro;",
"&#402;","&#8222;","&#8230;","&#8224;","&#8225;","&#710;","&#8240;","&#352;","&#8249;","&#338;","&#8216;","&#8217;","&#8220;","&#8221;","&#8226;","&#8211;",
"&#8212;","&#732;","&#8482;","&#353;","&#8250;","&#339;","&#376;","&#161;","&#162;","&#163;","&#164;","&#165;","&#166;",
"&#167;","&#168;","&#169;","&#170;","&#171;","&#172;","&#173­","&#174;","&#175;","&#176;","&#177;","&#178;",
"&#179;","&#180;","&#181;","&#182;","&#183;","&#184;","&#185;","&#186;","&#187;","&#188;",
"&#189;","&#190;","&#191;","&#192;","&#193;","&#194;","&#195;","&#196;","&#197;","&#198;",
"&#199;","&#200;","&#201;","&#202;","&#203;","&#204;","&#205;","&#206;","&#207;","&#208;",
"&#209;","&#210;","&#211;","&#212;","&#213;","&#214;","&#215;","&#216;","&#217;","&#218;",
"&#219;","&#220;","&#221;","&#222;","&#223;","&#224;","&#225;","&#226;","&#227;","&#228;",
"&#229;","&#230;","&#231;","&#232;","&#233;","&#234;","&#235;","&#236;","&#237;","&#238;",
"&#239;","&#240;","&#241","&#242;","&#243;","&#244;","&#245;","&#246;","&#247;","&#248;",
"&#249;","&#250;","&#251;","&#252;","&#252;","&#253;","&#254;","&#255;");
?>
<html>
<head>
<title><?php echo $admin445; ?></title>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $charset; ?>">
<script type="text/javascript">
 function getInfoAndUpdate() {
  var callerWindowObj = dialogArguments;
  callerWindowObj.symbol = clip.value;
  callerWindowObj.createSymbol();
  window.close();
 }
</script>	   
</head>
<body leftmargin="5" topmargin="5" style="overflow: hidden;">
<fieldset>
<table align="center" border="0">
<tr><td><p align="center">
<select id="clip" size="6" style="width: 60px;" onDblClick="getInfoAndUpdate();">
<?php
 for ($i = 0; $i < count($carspec); $i++) {
 $sel = "0";
 echo "<option value=\"".$carspec[$i]."\"".$sel.">".$carspec[$i]."</option>\n";
 }
?>
</option></select><tr><td colspan=2>
<input type="button" name="batal" value="<?php echo $admin38; ?>" onclick="getInfoAndUpdate();" />&nbsp;
<input type="button" value="<?php echo $admin121; ?>" onclick="window.close();" />
</table></fieldset>
</body>
</html>
