<?php
/*
    Image Picker - GuppY PHP Script - version 4.6.4
    CeCILL Copyright (C) 2004-2006 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alvès,
    followed by Albert Aymard, Jean Michel Misrachi, and all the GuppY Team
      Web site = http://www.freeguppy.org/
      e-mail   = info@aldweb.com

    Version History :
	v2.2 (22 April 2003)       : initial release (by Nicolas Alves and Laurent Duveau)
	v2.4 (24 September 2003)   : added character set management
                               upgraded this Image Picker
	v3.0 (25 February 2004)    : compatibility with php.ini register_globals=off parameter (thanks JonnyQuest)
	v3.0 (1st April 2004 )     : text alignment and images alignment to left
	v4.0 (25 October 2004 )    : added choice in directory img or photo (by Nicolas Alves)
	                             modified table alignment, added autoclose delay on blur,
				                       modified to use drad and drop into editor (by Icare)
		                           added alt tags to img and removed border tag for non-linked img (by Isa)
    v4.5.4 (01 September 2005) : added css include (by Icare)
    v4.6.10 (7 September 2009)    : corrected #272
*/

header("Pragma: no-cache");
define("CHEMIN", "../../../");

/// Ajouté fonctions d'exploration récursive des répertoires
function lister_sousrepertoires($dir){
  $r = $dir." ";
  $h = opendir(CHEMIN.$dir);
  while ($f = readdir($h)) {
    if (is_dir(CHEMIN.$dir."/".$f) && ($f[0] != "."))
      $r .= lister_sousrepertoires($dir."/".$f)." ";
  }
  closedir($h);
  return trim($r);
}
function lister_repertoires($list){
  $r = "";
  for($i=0; $i<count($list); $i++){
    if (is_dir(CHEMIN.$list[$i][0])) {
      if ($list[$i][1])
        $r .= " ".lister_sousrepertoires($list[$i][0]);
      else
        $r .= " ".$list[$i][0];
    }
  }
  return explode(" ", trim($r));
}
/// Ajouté un tableau "liste des répertoires uploadables" avec ou sans récursivité
$list_rep = lister_repertoires(array(
  array("img", true),
  array("photo", true)
  ));


include(CHEMIN."inc/includes.inc");
echo "<html>\n<head>\n<title>".$admin215."</title>\n";
echo '<meta http-equiv="Content-Type" content="text/html; charset='.$charset.'">'."\n";
if ($contenu == '1' || $contenu == '2') {
?>
<script type="text/javascript">
function openphoto(code) {
  code = ' ' + code + ' ';
  opener.document.forms['adminsend'].contenu<?php echo $contenu; ?>.focus();
  opener.document.forms['adminsend'].contenu<?php echo $contenu; ?>.value  += code;
  opener.document.forms['adminsend'].contenu<?php echo $contenu; ?>.focus();
  window.close();
}
</script>
<?php
}
 if (file_exists($meskin."style.css")) {
    echo "<link type=\"text/css\" rel=\"stylesheet\" href=\"".$meskin."style.css\" />";
 }
 else {
    echo "<style type=\"text/css\">";
      if (file_exists($meskin."style.inc")) { 
	     include($meskin."style.inc");
	  }
	  else {
	    include(CHEMIN."inc/style.inc");
	  }
    echo "</style>";
 }
echo '</head>'."\n";

if ($page[14]=="no_skin") {
?>	
<body background="<?php if ($page[3] != "") { echo CHEMIN."img/".$page[3]; } ?>" <?php if ($page[10] == "on") { echo "bgproperties=\"fixed\""; } ?> bgcolor="<?php echo $page[0]; ?>" leftmargin="7" topmargin="5" marginwidth="0" marginheight="0" onBlur="javascript: setTimeout('window.close();',20000);">
<?php
}
else {
?>
<body background="<?php echo $bodybackground; ?>" <?php if ($page[10] == "on") { echo "bgproperties=\"fixed\""; } ?> bgcolor="<?php echo $page[0]; ?>" leftmargin="7" topmargin="5" marginwidth="0" marginheight="0" onblur="javascript: setTimeout('window.close();',20000);">
<?php
}


echo '<form name="dirbrowser" method="post" action="listimg.php">'."\n";
echo '<input type="hidden" name="contenu" value="'.$contenu.'">'."\n";
echo '<table cellpadding="2" cellspacing="0" width="100%" border="0">'."\n";
echo '<tr><td align="center">'."\n";
echo '<select name="directory" size="1" class="input" onChange="dirbrowser.submit();">'."\n";
echo '<option value="">'.$web280.'</option>'."\n";

for ($i = 0; $i < count($list_rep); $i++) {
  if ($directory == $list_rep[$i]."/") {
    $sel = ' selected="selected"';
  }
  else {
    $sel = "";
  }
  echo '<option value="'.$list_rep[$i].'/"'.$sel.'>'.$list_rep[$i].'</option>'."\n";
}
echo '</select></td></tr>'."\n";
echo '</table></form>'."\n";

if ($directory != "") {
  $nbimg=1;
  $handle=opendir(CHEMIN.$directory);
  while ($file = readdir($handle)) {
    if (preg_match('!\.(gif|bmp|jpg|jpeg|png)$!i',$file)) $filelist[] = $file;
  }
  echo $directory;
  echo "<hr />"."\n";
  if (count($filelist) == 0) {
    echo '<b>'.$admin90.'</b>';
  } else {
    asort($filelist);
    $imgid=2;
    echo '<table width="100%" border="0"><tr>'."\n";
    while (list ($key, $file) = each ($filelist)) {
      echo '<td><p>'.$file.'</p></td>'."\n";
      
      if ($contenu == '1' || $contenu == '2') {
        $href = "javascript: openphoto('<img src=".$directory.$file.' border=0 alt='.$file.'>\')';
        echo '<td><a href="'.$href.'" ><img src="'.CHEMIN.$directory.$file.'" border="0" alt="'.$file.'" /></a></td>';
      } else {
        echo '<td><img src="'.CHEMIN.$directory.$file.'" alt="'.$file.'" /></td>'."\n";
      }
      
      if ($imgid >= $nbimg) {
        echo '</tr><tr>'."\n";
        $imgid=1;
      }
      else {
        $imgid++;
      }
    }
    closedir($handle);
    unset($filelist);
    echo "</tr>\n</table>\n";
  }
}
echo "</body>\n</html>";
