<?php
/*
     Plugin PostGuestEditor
	 Version  : 2.0 (2006/12/05)
	 Compatibility : Guppy v4.5.x
	 Licence  : GNU Lesser General Public License
	 Author   : jérôme CROUX (Djchouix)
     Web site : http://lebrikabrak.info/
     E-mail   : jchouix@wanadoo.fr
*/

if (stristr($_SERVER['SCRIPT_NAME'], 'syntaxcolor.php')) {
  header('location:../index.php');
  die();
}

/**
 *   colorCode
 *   Coloration syntaxique du code
 *   @param  $code  string  le code à colorer
 */
function colorCode($code)
{
	global $lang_pgeditor;
	$tab = preg_split("`(<div class=\"code\"><span class=\"code\">".$lang_pgeditor[25]." [-0-9a-zA-Z_]+</span><pre>.+</pre></div>)`sU", $code, -1, PREG_SPLIT_DELIM_CAPTURE);
	foreach ($tab as $val) {
		if (preg_match("`<div class=\"code\"><span class=\"code\">".$lang_pgeditor[25]." ([-0-9a-zA-Z_]+)</span><pre>(.+)</pre></div>`sU", $val, $matches)) {
			$lang_name = trim($matches[1]);
			if ($lang_name == 'xhtml') $lang_name = 'html';  //parser xhtml === parser html
			if (file_exists(CHEMIN.PATH_PGEDITOR.'syntaxcolor/lang/'.$lang_name.'.php')) {
				include_once CHEMIN.PATH_PGEDITOR.'syntaxcolor/lang/'.$lang_name.'.php';
				$func_name = 'colorSyntax'.strtoupper($lang_name);
				$matches[2] = $func_name($matches[2]);
			}	
			$out[] = str_replace($matches[0], '<div class="code"><span class="code">'.$lang_pgeditor[25].' '.$matches[1].'</span><pre>'.$matches[2].'</pre></div>', $val);
		} else {
			$out[] = $val;
		}
	}	
	return implode('', $out);	
}
?>