/*
Copyright (c) 2003-2012, CKSource - Frederico Knabben. All rights reserved.
For licensing, see LICENSE.html or http://ckeditor.com/license

v4.6.22 (29 December 2012) : modified config enterMode by Papinou
                             modified config shiftEnterMode by Papinou
*/

CKEDITOR.editorConfig = function( config )
{
	// Define changes to default configuration here. For example:

    /**
     * Définitions des barres d'outils
     */
    config.toolbar_Default =    // Barre par défaut (ensemble de tous les outils)
    [
    	['Source','-','Save','NewPage','Preview','-','Templates'],
    	['Cut','Copy','Paste','PasteText','PasteFromWord','-','Print', 'SpellChecker', 'Scayt'],
    	['Undo','Redo','-','Find','Replace','-','SelectAll','RemoveFormat'],
    	['Form', 'Checkbox', 'Radio', 'TextField', 'Textarea', 'Select', 'Button', 'ImageButton', 'HiddenField'],
    	'/',
    	['Bold','Italic','Underline','Strike','-','Subscript','Superscript'],
    	['NumberedList','BulletedList','-','Outdent','Indent','Blockquote','CreateDiv'],
    	['JustifyLeft','JustifyCenter','JustifyRight','JustifyBlock'],
    	['Link','Unlink','Anchor'],
    	['Image','Flash','Table','HorizontalRule','Smiley','SpecialChar','PageBreak'],
    	'/',
    	['Styles','Format','Font','FontSize'],
    	['TextColor','BGColor'],
    	['Maximize', 'ShowBlocks','-','About']
    ];
    
    config.toolbar_Guppy_in = [     // Barre affichée par l'éditeur intégré
    	['NewPage','Preview','Source','Templates',
    	'Cut','Copy','Paste','PasteText','PasteFromWord','Print', 'SpellChecker',
    	'Undo','Redo','Find','Replace','SelectAll','RemoveFormat','Table','SpecialChar'],
    	['Bold','Italic','Underline','Strike','Subscript','Superscript','NumberedList','BulletedList','Indent',
    	'JustifyLeft','JustifyCenter','JustifyRight','JustifyBlock','TextColor','BGColor',
    	'Link','Unlink','Anchor','Image','Flash','Smileys'],
    	'/',
    	['Styles','Format','Font','FontSize','Maximize','About']
    ] ;
    //
        
    config.colorButton_enableMore = true;  // Affiche (true) ou non (false) le bouton "Plus de couleurs..." 

    config.disableNativeSpellChecker = false;   // Active (false) ou désactive (true) le vérificateur orthographique des navigateurs (firefox et safari)
    config.disableNativeTableHandles = false;   // Active (false) ou désactive (true) les outils présents nativement dans les navigateurs (actuellement Firefox seulement)
    config.disableObjectResizing = false;        // Active (false) ou désactive (true) le redimensionnement des images et des tableaux    

    config.enterMode = CKEDITOR.ENTER_BR;
	config.shiftEnterMode = CKEDITOR.ENTER_DIV;	
	
    config.entities = false;     //
    //config.extraPlugins = 'smileys';
    
    config.format_tags	= 'p;h1;h2;h3;h4;h5;h6;pre;address;div' ;
    config.font_names		= 'Arial;Comic Sans MS;Courier New;Tahoma;Times New Roman;Verdana' ;
    config.fontSize_sizes   = '8/8px;9/9px;10/10px;11/11px;12/12px;13/13px;14/14px;15/15px;16/16px;18/18px;20/20px;22/22px;24/24px;26/26px;28/28px;36/36px;48/48px;72/72px';
  
    config.forcePasteAsPlainText = false;
    config.forceSimpleAmpersand = false;
    
    config.resize_dir = 'vertical';
    
    config.skin = 'kama, ' + site3 + 'admin/editors/ckeditor_config/custom/skins/kama/';

    config.templates_files =
    [
        site3 + 'admin/editors/ckeditor_config/custom/templates/templates/default.js'
    ];
    config.templates = 'default';
    
    config.stylesSet = 'styles:'+ site3 + 'admin/editors/ckeditor_config/custom/styles/styles.js';

    //config.width = '577px';
};
