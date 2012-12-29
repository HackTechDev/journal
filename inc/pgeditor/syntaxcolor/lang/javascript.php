<?php
/*
     Plugin PostGuestEditor
	 Version  : 2.1 (2006/12/05)
	 Compatibility : Guppy v4.5.x
	 Licence  : GNU Lesser General Public License
	 Author   : jérôme CROUX (Djchouix)
     Web site : http://lebrikabrak.info/
     E-mail   : jchouix@wanadoo.fr
*/
if (stristr($_SERVER['SCRIPT_NAME'], 'javascript.php')) {
  header('location:../index.php');
  die();
}

/**
 *   colorSyntaxJAVASCRIPT
 *   Coloration syntaxique du code JAVASCRIPT
 *   @param  $code  string  le code à colorer
 */
function colorSyntaxJAVASCRIPT($code)
{
	// MOTS-CLES
	$keyword = array(
     				'Array', 'as', 'break', 'boolean', 'case', 'catch', 'char', 'class(?!=)', 'const', 'continue', 'debugger',
					'default', 'delete', 'do', 'double', 'else', 'export', 'extends', 'eval', 'false', 'finally', 'float', 'for',
					'function', 'if', 'import', 'in', 'int', 'is', 'item', 'instanceof', 'namespace', 'new', 'null', 'package',
					'private', 'protected', 'public', 'return', 'static', 'super', 'switch', 'this', 'throw', 'true', 'try', 'typeof',
					'use', 'var', 'void', 'while', 'with'
	);	
	// FONCTIONS INTERNES
	$function = array(
      				'alert', 'all', 'back', 'blur', 'close', 'confirm', 'focus', 'forward', 'getElementById',
      				'open', 'print', 'prompt', 'scroll', 'status', 'substring',
      				'stop', 'write'
    );

	$in = array(
			"`(\W)(".implode('|', $keyword).")(\W)`",
			"`(\W)(".implode('|', $function).")(\W)`"
	);
	$out = array(
			'$1<span class="js_keyword">$2</span>$3',	// MOTS-CLES
			'$1<span class="js_function">$2</span>$3'	// FONCTIONS INTERNES
	);
	$code = preg_replace($in, $out, $code);
		
	// ACCOLADES
 	$bracket = array('(', ')', '&#91;', '&#93;', '{', '}');
	for ($i = 0; $i < count($bracket); $i++) {
		$bracket_out[$i] = '<span class="js_bracket">'.$bracket[$i].'</span>';	// ACCOLADES
	}
	$code = str_replace($bracket, $bracket_out, $code);	

	// CHAINES
	$code = preg_replace_callback("`(?<!\w)(&quot;|')(.*?)(?<!\\\|&#92;)\\1`", 'colorStringJS', $code);
	
	// COMMENTAIRES
	$code = preg_replace_callback("`/\*(?:.+?)\*/`s", 'colorCommentJS', $code);
	$code = preg_replace_callback("`(?<!\w|:|-)\/\/(?:.*?)$`m", 'colorCommentJS', str_replace('<br />', "\n", $code));	

	return str_replace(array("\n",'<code>'), array('<br />','<code class="js_code">'), $code);	// PAR DEFAUT
}

/**
 *   colorStringJS
 *   Coloration des chaines entre guillemets
 *   @param  $matches  array  le tableau contenant l'ensemble des motifs capturés par l'expression régulière
 */
function colorStringJS($matches)
{
	return '<span class="js_string">'.str_replace(array('<span class="js_keyword">', '<span class="js_function">', '<span class="js_bracket">', '</span>'), '', $matches[0]).'</span>';
}

/**
 *   colorCommentJS
 *   Coloration des commentaires
 *   @param  $matches  array  le tableau contenant l'ensemble des motifs capturés par l'expression régulière
 */
function colorCommentJS($matches)
{
	return '<span class="js_comment">'.str_replace(array('<span class="js_keyword">', '<span class="js_function">', '<span class="js_bracket">', '<span class="js_string">', '</span>'), '', $matches[0]).'</span>';
}
?>