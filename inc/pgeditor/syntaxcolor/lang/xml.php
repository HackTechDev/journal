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

if (stristr($_SERVER['SCRIPT_NAME'], 'xml.php')) {
  header('location:../index.php');
  die();
}

/**
 *   colorSyntaxXML
 *   Coloration syntaxique du code XML
 *   @param  $code  string  le code à colorer
 */
function colorSyntaxXML($code)
{
	$tab = array(
				"`&lt;(?:.*?)&gt;`s" => 'colorTagXML',	// TAGS, ATTRIBUTS ET VALEURS
				"`&lt;!--(?:.+?)--&gt;`s" => 'colorCommentXML'	// COMMENTAIRES
				"`&lt;\!&#91;CDATA&#91;(?:.+?)&#93;&#93;&gt;`s" => 'colorCDATAXML',	// CDATA
	);
	foreach($tab as $modele => $callback) {
		$code = preg_replace_callback($modele, $callback, $code);
	}
	return str_replace('<code>', '<code class="xml_code">', $code); // PAR DEFAUT
}

/**
 *   colorTagXML
 *   Coloration des tags, des attributs et des valeurs
 *   @param  $matches  array  le tableau contenant l'ensemble des motifs capturés par l'expression régulière
 */
function colorTagXML($matches)
{
	$matches[0] = preg_replace("`([-a-z:]+(?:&nbsp;)*=)(?:&nbsp;)*((&quot;|')(?:.*?)\\3)`is", '<span class="xml_attribute">$1</span><span class="xml_attribute_value">$2</span>', $matches[0]);  	// ATTRIBUTS ET VALEURS
	return '<span class="xml_tag">'.$matches[0].'</span>';  // TAGS
}

/**
 *   colorCommentXML
 *   Coloration des commentaires
 *   @param  $matches  array  le tableau contenant l'ensemble des motifs capturés par l'expression régulière
 */
function colorCommentXML($matches)
{
	return '<span class="xml_comment">'.str_replace(array('<span class="xml_tag">', '<span class="xml_attribute">', '<span class="xml_attribute_value">','</span>'), '', $matches[0]).'</span>';
}

/**
 *   colorCDATAXML
 *   Coloration des section CDATA
 *   @param  $matches  array  le tableau contenant l'ensemble des motifs capturés par l'expression régulière
**/
function colorCDATAXML($matches)
{
	return '<span class="xml_cdata">'.str_replace(array('<span class="xml_tag">', '<span class="xml_attribute">', '<span class="xml_attribute_value">', '<span class="xml_comment">', '</span>'), '', $matches[0]).'</span>';
}	
?>