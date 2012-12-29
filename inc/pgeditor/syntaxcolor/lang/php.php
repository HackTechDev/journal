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

if (stristr($_SERVER['SCRIPT_NAME'], 'php.php')) {
  header('location:../index.php');
  die();
}

/**
 *   colorSyntaxPHP
 *   Coloration syntaxique du code PHP
 *   @param  $code  string  le code à colorer
 */
function colorSyntaxPHP($code)
{
	// MOTS-CLES
	$keyword = array(
     				'abstract', 'and', 'array', 'as', 'break', 'boolean', 'case', 'catch', 'char', 'class(?!=)', 'clone', 'const',
					'continue', 'declare', 'default', 'die', 'do', 'echo', 'else(?:if)?', 'empty', 'end(?:declare|for|foreach|if|switch|while)',
					'eval', 'exception', 'exit', 'extends', 'false', 'FALSE', 'final', 'float', 'for', 'foreach', 'function', 'global',
					'if', 'include(?:_once)?', 'implements', 'int', 'interface', 'isset', 'list', 'new', 'null', 'NULL', 'or', 'print',
					'require(?:_once)?', 'php_user_filter', 'private', 'protected', 'public', 'return', 'static', 'string', 'switch',
					'throw', 'true', 'TRUE', 'try', 'unset', 'use', 'var', 'while', 'xor', '__FILE__', '__FUNCTION__', '__CLASS__', '__METHOD__'
	);
	$in = array(
			"`(\W)(".implode('|', $keyword).")(\W)`",
			'`\&#36;(?:&#36;)?[a-zA-Z_\x7f-\xff][a-zA-Z0-9_\x7f-\xff]*`',
			'`(&lt;\?(php)?|\?&gt;)`'
	);
	$out = array(
			'$1<span class="php_keyword">$2</span>$3', 	// MOTS-CLES
			'<span class="php_var">$0</span>',			// VARIABLES
			'<span class="php_tag">$1</span>', 			// TAGS < ?php et ? >
	);
	$code = preg_replace($in, $out, $code);
	
	// ACCOLADES
 	$bracket = array('(', ')', '&#91;', '&#93;', '{', '}');
	for ($i = 0; $i < count($bracket); $i++) {
		$bracket_out[$i] = '<span class="php_bracket">'.$bracket[$i].'</span>';
	}
	$code = str_replace($bracket, $bracket_out, $code);	
		
	// CHAINES
	$code = preg_replace_callback("`(?<!\w)(&quot;|')(.*?)(?<!\\\|&#92;)\\1`", 'colorStringPHP', $code);

	// COMMENTAIRES
	$code = preg_replace_callback("`/\*(?:.+?)\*/`s", 'colorCommentPHP', $code);	
	$code = preg_replace_callback("`(?<!\w|:|-)\/\/(?:.*?)$`m",'colorCommentPHP', str_replace('<br />', "\n", $code));	

	return str_replace(array("\n", '<code>'), array('<br />', '<code class="php_code">'), $code);	// PAR DEFAUT
}

/**
 *   colorStringPHP
 *   Coloration des chaines entre guillemets
 *   @param  $matches  array  le tableau contenant l'ensemble des motifs capturés par l'expression régulière
 */
function colorStringPHP($matches)
{
	return '<span class="php_string">'.str_replace(array('<span class="php_keyword">', '<span class="php_var">', '<span class="php_tag">', '<span class="php_bracket">', '</span>'), '', $matches[0]).'</span>';
}

/**
 *   colorCommentPHP
 *   Coloration des commentaires
 *   @param  $matches  array  le tableau contenant l'ensemble des motifs capturés par l'expression régulière
 */
function colorCommentPHP($matches)
{
	return '<span class="php_comment">'.str_replace(array('<span class="php_keyword">', '<span class="php_var">', '<span class="php_tag">', '<span class="php_bracket">', '<span class="php_string">', '</span>'), '', $matches[0]).'</span>';
}
?>