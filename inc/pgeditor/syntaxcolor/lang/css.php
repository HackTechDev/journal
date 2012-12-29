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

if (stristr($_SERVER['SCRIPT_NAME'], 'css.php')) {
  header('location:../index.php');
  die();
}

/**
 *   colorSyntaxCSS
 *   Coloration syntaxique du code CSS
 *   @param  $code  string  le code à colorer
 */
function colorSyntaxCSS($code)
{	
	$code = preg_replace_callback('`\{(.+?)\}`s', 'colorValueCSS', $code);  // PROPRIETES ET DES VALEURS	
	$code = preg_replace('`(\}?)([^{}]+)\{`','$1<span class="css_selector">$2</span>{', $code); // SELECTEURS
	$code = str_replace(array('{', '}', '!important'), array('<span class="css_bracket">{</span>', '<span class="css_bracket">}</span>', '<span class="css_keyword">!important</span>'), $code); // ACCOLADES ET MOTS CLES	
	$code = preg_replace_callback('`/\*(?:.+?)\*/`s','colorCommentCSS', $code);  // COMMENTAIRES
	return $code;
}

/**
 *   colorValueCSS
 *   Coloration des tags, des proptiétés et des valeurs
 *   @param  $matches  array  le tableau contenant l'ensemble des motifs capturés par l'expression régulière
 */
function colorValueCSS($matches)
{
	$matches[1] = preg_replace("`([^:]+)(?<!&nbsp|&gt|&lt|&quot|&#93|&#91|&#36|&amp)\;`", '<span class="css_propriety_value">$1</span>;', $matches[1]);  	// VALEURS
	$matches[0] = '{<span class="css_propriety">'.$matches[1].'</span>}';  	// PROPRIETES
	return $matches[0];
}

/**
 *   colorCommentCSS
 *   Coloration des commentaires
 *   @param  $matches  array  le tableau contenant l'ensemble des motifs capturés par l'expression régulière
 */
function colorCommentCSS($matches)
{
	return '<span class="css_comment">'.str_replace(array('<span class="css_selector">', '<span class="css_bracket">', '<span class="css_keyword">', '<span class="css_propriety">', '<span class="css_propriety_value">', '</span>'), '', $matches[0]).'</span>';
}
?>