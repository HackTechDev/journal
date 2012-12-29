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

if (stristr($_SERVER['SCRIPT_NAME'], 'html.php')) {
  header('location:../index.php');
  die();
}

/**
 *   colorSyntaxHTML
 *   Coloration syntaxique du code (X)HTML
 *   @param  $code  string  le code à colorer
 */
function colorSyntaxHTML($code)
{
	$tab = array(
				"`&lt;(?:.*?)&gt;`s" => 'colorTagHTML',	// TAGS, ATTRIBUTS ET VALEURS
				"`&lt;\!&#91;CDATA&#91;(?:.+?)&#93;&#93;&gt;`s" => 'colorCommentHTML',	// COMMENTAIRES CDATA
				"`&lt;!--(?:.+?)--&gt;`s" => 'colorCommentHTML'	// COMMENTAIRES HTML
	);
	foreach($tab as $modele => $callback) {
		$code = preg_replace_callback($modele, $callback, $code);
	}
	return str_replace('<code>','<code class="html_code">', $code); // PAR DEFAUT
}

/**
 *   colorTagHTML
 *   Coloration des tags, des attributs et des valeurs
 *   @param  $matches  array  le tableau contenant l'ensemble des motifs capturés par l'expression régulière
 */
function colorTagHTML($matches)
{
	$matches[0] = preg_replace("`([-a-z:]+(?:&nbsp;)*=)(?:&nbsp;)*((&quot;|')(?:.*?)\\3)`is", '<span class="html_attribute">$1</span><span class="html_attribute_value">$2</span>', $matches[0]);  	// ATTRIBUTS ET VALEURS
	return '<span class="html_tag">'.$matches[0].'</span>';  // TAGS
}

/**
 *   colorCommentHTML
 *   Coloration des commentaires
 *   @param  $matches  array  le tableau contenant l'ensemble des motifs capturés par l'expression régulière
 */
function colorCommentHTML($matches)
{
	return '<span class="html_comment">'.str_replace(array('<span class="html_tag">', '<span class="html_attribute">', '<span class="html_attribute_value">', '<span class="html_comment">', '</span>'), '', $matches[0]).'</span>';
}	
?>