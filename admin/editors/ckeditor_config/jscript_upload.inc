<?php
/*
 * Plugin CKeditor
 * Version  : 4.6.5.2.6.4 (2009/06/20)
 * Compatibility : Guppy v4.6.x
 * Author   : jérôme CROUX (djchouix)
 * Web site : http://lebrikabrak.info/
 * E-mail   : lebrikabrak@free.fr
 * Licence  : GNU Lesser General Public License
 *
 * v4.6.22 (29 December 2012)    : corrected for ck editor (by Saxbar) 
 */

if (stristr($_SERVER["SCRIPT_NAME"], "jscript_upload.inc")) {
	header("location:../index.php");
	die();
}
?>
//Numéro attribué à l'éditeur (identifiant)
var funcNum = parseInt(getUrlParam('CKEditorFuncNum'));

// --------------------------------------------------------------------

/**
 * Récupère la valeur d'un paramètre passées dans l'url
 */
function getUrlParam(paramName)
{
  var reParam = new RegExp('(?:[\?&]|&amp;)' + paramName + '=([^&]+)', 'i') ;
  var match = window.location.search.match(reParam) ;
 
  return (match && match.length > 1) ? match[1] : '' ;
};

// --------------------------------------------------------------------

/**
 * Supprime l'adresse du serveur
 */
function delHostName(url)
{
	var posPathName = document.location.href.indexOf('admin/editors/upload/', 0);
	if (posPathName !== -1) {
		return url.substring(posPathName);
	}
	
	return url;
};

// --------------------------------------------------------------------

/**
 * Récupération de l'URL du fichier sélectionné dans le gestionnaire de fichiers
 */
function openURL(url, type, alt, width, height)
{
	url = delHostName(url);	// Path relative
	
    
    if (type == 'file') // Fichier lien
    {    
        url = url.replace(/^http:\/\//i , '');
        
        window.opener.CKEDITOR.tools.callFunction(funcNum, url, function () {
            var element, dialog = this.getDialog();
            if (dialog.getName() == 'link') {
                element = dialog.getContentElement( 'info', 'protocol' );
                if ( element ) {
                    element.setValue('');
                }
            }
        });
	}
    else if (type == 'img')	// Fichier image
    {
        window.opener.CKEDITOR.tools.callFunction(funcNum, url, function () {
            var element, dialog = this.getDialog();
            if (dialog.getName() == 'image') {
                element = dialog.getContentElement( 'info', 'txtAlt' );
                if ( element ) {
                    element.setValue( alt );
                }
                element = dialog.getContentElement( 'info', 'txtBorder' );
                if ( element ) {
                    element.setValue("0");
                } 
            }
        });
	}
	else if (type == 'flash')   // Fichier flash
    {
        window.opener.CKEDITOR.tools.callFunction(funcNum, url);
	}
    
    window.close();
};

/**
 * Ajout du paramètre 'CKEditorFuncNum' contenant l'identifiant de l'éditeur
 * dans l'url des éléments A et FORM
 */
(function () {
    
    function addUrlParam(paramName, paramValue)
    {       
        /**
         * Elements A
         */
        var aElements = document.getElementsByTagName('a');

        for ( var i = 0, len = aElements.length ; i < len ; i++ ) {
            if (aElements[i].href.indexOf("upload.php") !== -1 && aElements[i].href.indexOf(paramName) === -1) {
                aElements[i].href += '&'+paramName+'='+paramValue;
            }
        }
        //
        
        /**
         * Elements FORM
         */
        var formElements = document.getElementsByTagName('form');

        for ( var i = 0, len = formElements.length ; i < len ; i++ ) {
            if (formElements[i].action.indexOf("upload.php") !== -1 && formElements[i].action.indexOf(paramName) === -1) {
                formElements[i].action += '&'+paramName+'='+paramValue;
            }
        }
        //
    }

    // --------------------------------------------------------------------

	/**
	 * initialisation
	 */ 
	function init()
	{
        addUrlParam('CKEditorFuncNum', funcNum);
	}

    // --------------------------------------------------------------------

	/**
	 * Ajoute la fonction à l'évènement load de la page
	 */
	function addLoadListener(func)
	{
		if (window.addEventListener) {
			window.addEventListener("load", func, false);
		} else if (document.addEventListener) {
			document.addEventListener("load", func, false);
		} else if (window.attachEvent) {
			window.attachEvent("onload", func);
		}
	}

    // --------------------------------------------------------------------

	// Chargement
	addLoadListener(init);
   
})();
