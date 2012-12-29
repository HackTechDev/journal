/*
	Plugin PostGuestEditor
	Version  : 2.5.1 (2010/11/05)
	Compatibility : Guppy v4.5.x
	Licence  : GNU Lesser General Public License
	Author   : jérôme CROUX (Djchouix)
	Web site : http://lebrikabrak.info/
	E-mail   : jchouix@wanadoo.fr
	
	This file is based on :
	KOIVI TTW WYSIWYG Editor Copyright (C) 2005 Justin Koivisto
	Version 3.2.4 Last Modified: 4/3/2006

    This library is free software; you can redistribute it and/or modify it
    under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 2.1 of the License, or (at
    your option) any later version.

    This library is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
    License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this library; if not, write to the Free Software Foundation,
    Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

    Full license agreement notice can be found in the LICENSE file contained
    within this distribution package.

    Justin Koivisto
    justin.koivisto@gmail.com
    http://koivi.com
*/

/**
 *   WYSIWYG_PGEditor
 *   Class constructor. Configures and displays the editor object according to values passed
 *   This is an implementation of OO-Javascript based on my previous editor.
 *   @param  instance_name   string  the name of the variable you assigned to this instance ( example: myEdt = new WYSIWYG_PGEditor('myEdt'); )                                  also used as the basis for the name and id attributes for this editor instance in the HTML (hidden input and iframe)
 *   @param  content         string  a string of the content to display in the editor.
 *   @param  path            string  the URI path to this directory to use for editor components (pallete, images, etc.)
 *   @param  fwidth          int     the width in pixels of the editor interface on the screen
 *   @param  fheight         int     the height in pixels of the editor interface on the screen
 *   @param  styleHref       string  the URI of the stylesheet to use for the editor's content window
 *   @param  configPath      string  the URI of the configuration for the editor
 */
function WYSIWYG_PGEditor(instance_name, content, path, fwidth, fheight, styleHref, configPath)
{
    // the name used to create the object - used to define the name of the field that contains the HTML on submission
    if (typeof(instance_name) == 'undefined') {
        alert('ERROR: No instance name was passed for the editor.');
        return false;
    } else {
        this.instance_name = instance_name;
    }	
    // the initial HTML source content for the editor
    if (typeof(content) == 'undefined' || content == '') {
		this.content = (this.isGECKO())? '&nbsp;' : '';  // correction bug Firefox 1.0.x - 1.5.x (pas de focus dans zone edition)
	} else {
        this.content = content;
    }	
    // define the path to use for the editor components like images
    if (typeof(path) == 'undefined') {
        this.wysiwyg_path = '.'; // default value
    } else {
        path = path.replace(/[\/\\]$/, ''); // remove trailing slashes
        this.wysiwyg_path = path;
    }
    // define the pixel dimensions of the editor
    if (typeof(fwidth) == 'number' && Math.round(fwidth) > 50) {
        this.frame_width = Math.round(fwidth); // default value
    } else {
        this.frame_width = 515; // default width
    }
    if (typeof(fheight) == 'number' && Math.round(fheight) > 50) {
        this.frame_height = Math.round(fheight);
    } else {
        this.frame_height = 250; // default height
    }
    // define the stylesheet to use for the editor components like images
    if (typeof(styleHref) == 'undefined') {
        this.stylesheet = 0; // default value
    } else {
        this.stylesheet = styleHref;
    }
    // define the configuration to use for the editor	
    if (typeof(configPath) == 'undefined') {
        this.config_path = ''; // default value
    } else {
        this.config_path = configPath;
    }
    // properties that depended on the validated values above
    this.wysiwyg_content = this.instance_name + '_WYSIWYG_PGEditor';  // the editor IFRAME element id
    this.wysiwyg_hidden = this.instance_name + '_content';          // the editor's hidden field to store the HTML in for the post
    this.ta_rows = Math.round(this.frame_height / 15);              // number of rows for textarea for unsupported browsers
    this.ta_cols = Math.round(this.frame_width / 8);                // number of cols for textarea for unsupported browsers
    // other property defaults
    this.viewMode = 1;                                              // by default, set to design view
    this._X = this._Y = 0;                                  		// these are used to determine mouse position when clicked
    // tool bar display
    this.allow_mode_toggle = false;                         		 // allow users to switch to source code mode
	this.isSupported = false;
	this.lang = new Array();										 // the language
	this.menu = new Array();										 // the menu options
	this.language_code = new Array();								 // the language code for select menu of the popupCode 
	this.base_path = '';											 // URL du site
};

/**
 *   WYSIWYG_PGEditor::isMSIE
 *   Checks if browser is MSIE by testing the document.all property that is only supported by MSIE and AOL
 */
WYSIWYG_PGEditor.prototype.isMSIE = function ()
{
    if (typeof(document.all) == 'object' && typeof(window.opera) != 'object') {
        return true;
    } else {
        return false;
    }
};

/**
 *   WYSIWYG_PGEditor::isOPERA9
 *   Checks if browser is OPERA 9+
 */
WYSIWYG_PGEditor.prototype.isOPERA = function ()
{
    if (typeof(window.opera) == 'object') {
		return true;
    } else {
        return false;
    }
};

/**
 *   WYSIWYG_PGEditor::isGECKO
 *   Checks if browser is Gecko browsers
 */
WYSIWYG_PGEditor.prototype.isGECKO = function ()
{
    if (typeof(window.sidebar) == 'object' && typeof(window.opera) != 'object') {
        return true;
    } else {
        return false;
    }
};

/**
 *   WYSIWYG_PGEditor::isSafari
 *   Checks if browser is Safari browser
 */
WYSIWYG_PGEditor.prototype.isSAFARI = function ()
{
    if (/WebKit/i.test(navigator.userAgent)) {
        return true;
    } else {
        return false;
    }
};

/**
 *   WYSIWYG_PGEditor::submitContent 
 *   Use this in the onsubmit event for the form that the editor is displayed inside.
 *	 Prepare , verify if the editor's content is empty or not and parse image path
 *	 @return boolean false if the editor's content is empty
 */
WYSIWYG_PGEditor.prototype.submitContent = function ()
{
	this.prepareSubmit();
	if (this.isEmptyContents()) {
		return false;
	} else {
		//Récupération et parsage des images issues d'un drag and drop dans la zone de texte
		//Remarque : Opera 9.0+ n'est pas concerné car le drag and drop des images n'est pas actif
		if (this.isMSIE() || this.isGECKO()) { 
			var contents = document.getElementById(this.wysiwyg_hidden).value;			
			contents = this.parseImage(contents);
			document.getElementById(this.wysiwyg_hidden).value = contents;
		}
		return true;
	}
};


/**
 *   WYSIWYG_PGEditor::prepareSubmit
 *   Puts the HTML content into a hidden form field for the submission
 */
WYSIWYG_PGEditor.prototype.prepareSubmit = function ()
{
    if (this.viewMode == 2) {  // be sure this is in design view before submission
		this.toggleMode(); 
	}
    var html = document.getElementById(this.wysiwyg_content).contentWindow.document.body.innerHTML;
    document.getElementById(this.wysiwyg_hidden).value = html;
    return true;
};

/**
 *   WYSIWYG_PGEditor::isEmptyContents 
 *	 Verify if the editor's contents is empty or not
 *	 @return boolean true if the editor's contents is empty
 */
WYSIWYG_PGEditor.prototype.isEmptyContents = function ()
{
	var contents = document.getElementById(this.wysiwyg_hidden).value;

	if (this.isMSIE()) {
        var regexp = /^(&nbsp;|<p>(<br>|&nbsp;|\s)+<\/p>|<br>|\s)*$/i;
    } else if (this.isGECKO()) {
        var regexp = /^(&nbsp;|<br>|\s)*$/i;
	} else if (this.isOPERA()) {
        var regexp = /^(&nbsp;|<br\/>|\s)*$/i;
	} else if (this.isSAFARI()) {
		contents = contents.replace(/<span class="Apple-tab-span" style="white-space:pre">[\s\xA0]*<\/span>/g, "");
		contents = contents.replace(/<br( class="webkit-block-placeholder")?>/g, "");
		contents = contents.replace(/<div>[\s\xA0]*<\/div>/g, "");
		var regexp = /^[\s\xA0]*$/;
    }
	
	if (regexp.test(contents)) {
		return true;
	} else {
		return false;
	}
};

/**
 *   WYSIWYG_PGEditor::parseImage 
 *	 Parse image
 *	 @return string
 */
WYSIWYG_PGEditor.prototype.parseImage = function (html)
{
	var contents = html;
	var basePath = this.base_path;
	
	if (this.isMSIE()) {
        var regexp = /<(IMG) (.*?)src=(["'])([^'"]+)\3[^>]*>/g;
    } else if (this.isGECKO()) {
        var regexp = /<(img) (.*?)src=(["'])([^'"]+)\3[^>]*>/g;
	}

	if (this.isMSIE()) {
		contents = contents.replace(regexp, '<$1 src="$4">');
	} else if (this.isGECKO()) {
		contents = contents.replace(regexp, function(motif, tag, str, quote, path)
											{
												var url = path;
												if (url.indexOf('http://') !== 0) {
													url = basePath + url.replace(/^(\.\.\/)+/, '');	
												}
												return '<img src="' + url + '">'; 
											}
		);
	}
	return contents;
};

/**
 *   WYSIWYG_PGEditor::toggleMode
 *   Toggles between design view and source view in the IFRAME element
 */
WYSIWYG_PGEditor.prototype.toggleMode = function ()
{
	var contentWin = document.getElementById(this.wysiwyg_content).contentWindow;
    // change the display styles
    if (this.viewMode == 2) {
        contentWin.document.body.className = 'contentWIW'; //Wysiwyg
		document.getElementById('toolbarWIW_' + this.instance_name).style.visibility = 'visible';
    } else {
		contentWin.document.body.className = 'contentTA'; //textarea
		document.getElementById('toolbarWIW_' + this.instance_name).style.visibility = 'hidden';
    }
    // do the content swapping
    if (this.isMSIE() || this.isOPERA() || this.isSAFARI()) {
        this._toggle_mode_ie();
    } else {
        this._toggle_mode_gecko();
    }
};

/**
 *   WYSIWYG_PGEditor::_toggle_mode_ie
 *   Toggles between design view and source view in the IFRAME element for MSIE and Opera 9+ and Safari 3+
 */
WYSIWYG_PGEditor.prototype._toggle_mode_ie = function ()
{
	var contentWin = document.getElementById(this.wysiwyg_content).contentWindow;
    if (this.viewMode == 2) {
        contentWin.document.body.innerHTML = contentWin.document.body.innerText;
        contentWin.focus();
        this.viewMode = 1; // WYSIWYG
    } else {
        contentWin.document.body.innerText = contentWin.document.body.innerHTML;
        contentWin.focus();
        this.viewMode = 2; // Code
    }
};

/**
 *   WYSIWYG_PGEditor::_toggle_mode_gecko
 *   Toggles between design view and source view in the IFRAME element for Gecko browsers
 */
WYSIWYG_PGEditor.prototype._toggle_mode_gecko = function ()
{
	var contentWin = document.getElementById(this.wysiwyg_content).contentWindow;
    if (this.viewMode == 2) {
        var html = contentWin.document.body.ownerDocument.createRange();
        html.selectNodeContents(contentWin.document.body);
        contentWin.document.body.innerHTML = html.toString();
        contentWin.focus();
        this.viewMode = 1; // WYSIWYG
    } else {
        var html = document.createTextNode(contentWin.document.body.innerHTML);
        contentWin.document.body.innerHTML = '';
        contentWin.document.body.appendChild(html);
        contentWin.focus();
        this.viewMode = 2; // Code
    }
};

/**
 *   WYSIWYG_PGEditor::displayBlockById 
 *	 Display or not a block
 *   @id       string  block id
 *   @display  string  display  CSS value ('block', 'inline' or 'none') 
 */
WYSIWYG_PGEditor.prototype.displayBlockById = function (id, display)
{
	if (document.getElementById) {
		document.getElementById(id).style.display = display;
	} else if (document.all) {
		document.all[id].style.display = display;
	} else if (document.layers) {
		document.layers[id].display = display;
	} else {
		return false;
	}
};

/**
 *   WYSIWYG_PGEditor::display
 *   Display the editor interface for the user
 */
WYSIWYG_PGEditor.prototype.display = function ()
{
	if (this.isSupported) {
		this.displayEditor();
		//Puts the passed content into the editor or textarea (Use this one *after* displaying the editor.)
		document.getElementById(this.wysiwyg_hidden).value = this.content;

		if(this.isOPERA() || this.isSAFARI()) {
			var thedoc = window.frames[this.wysiwyg_content].document;
		} else {
			var thedoc = document.getElementById(this.wysiwyg_content).contentWindow.document;
		}
		thedoc.designMode = 'on';	// Nécessaire pour Firefox 2
		thedoc.open();
		thedoc.write(' ');
		thedoc.designMode = 'on';	// Nécessaire pour Opera 9.5x
		
		var html = '<html><head>';
		html += '<title>' + this.lang[30] + '<\/title>';
		if(this.stylesheet) {
			//must be done after the document has been opened
			html += '<link rel="stylesheet" type="text/css" media="screen" href="' + this.stylesheet + '.css" />';
			//Patch CSS for IE browsers
			html += '<!--[if lte IE 7]>';
			html += '<link rel="stylesheet" type="text/css" media="screen" href="' + this.stylesheet + '-ie.css" />';
			html += '<![endif]-->';
		}
		html += '<\/head><body id="contentWIW_' + this.instance_name + '" class="contentWIW">';
		html += this.content;
		html += '<\/body><\/html>';
		
		thedoc.write(html);	
        thedoc.close();
    } else {
		alert('WARNING: Your browser does not support the WYSIWYG_PGEditor class.');
		return false;
    }
};

/**
 *   WYSIWYG_PGEditor::displayEditor
 *   Used to display the actual wysiwyg editor HTML interface to supported browsers
 */
WYSIWYG_PGEditor.prototype.displayEditor = function ()
{	
	var html = '';
	html += '<div id="toolbarIcons_' + this.instance_name + '" class="toolbarIcons" style="width:' + this.frame_width + 'px;">';
	if (this.allow_mode_toggle) {
		html += '<div id="toggle_' + this.instance_name + '" class="toggle">';
        html += '	<img alt="' + this.lang[20] + '" title="' + this.lang[20] + '" class="icon" border="0" src="' + this.wysiwyg_path + '/images/mode.gif" onclick="' + this.instance_name + '.toggleMode()" />';
		html += '</div>';
	}
    html += '	 <div id="toolbarWIW_' + this.instance_name + '" class="toolbarWIW">';
	for (i = 0; i < this.menu.length; i++) {
		var tool = true;
		switch (this.menu[i]) {
			case 'color' :
				alt = this.lang[2];
				action = this.instance_name + '.displayPopup(\'color\', 148, 100, event)';
				break;
			case 'bgcolor' :
				alt = this.lang[3];
				action = this.instance_name + '.displayPopup(\'bgcolor\', 148, 100, event)';
				break;
			case 'bold' :
				alt = this.lang[4];
				action = this.instance_name + '.doTextFormat(\'bold\', \'\')';
				break;
			case 'italic' :
				alt = this.lang[5];
				action = this.instance_name + '.doTextFormat(\'italic\', \'\')';
			break;
			case 'underline' :
				alt = this.lang[6];
				action = this.instance_name + '.doTextFormat(\'underline\', \'\')';
				break;
			case 'cite' :
				alt = this.lang[7];
				action = this.instance_name + '.displayPopup(\'cite\', 310, 130, event)';
				break;
			case 'code' :
				alt = this.lang[8];
				action = this.instance_name + '.displayPopup(\'code\', 260, 130, event)';
				break;
			case 'left' :
				alt = this.lang[9];
				action = this.instance_name + '.doTextFormat(\'justifyleft\', \'\')';
				break;
			case 'center' :
				alt = this.lang[10];
				action = this.instance_name + '.doTextFormat(\'justifycenter\', \'\')';
				break;
			case 'right' :
				alt = this.lang[11];
				action = this.instance_name + '.doTextFormat(\'justifyright\', \'\')';
				break;
			case 'link' :
				alt = this.lang[12];
				action = this.instance_name + '.displayPopup(\'link\', 305, 130, event)';
				break;
			case 'unlink' :
				alt = this.lang[13];
				action = this.instance_name + '.doTextFormat(\'unlink\', \'\')';
				break;
			case 'ordlist' :
				alt = this.lang[14];
				action = this.instance_name + '.doTextFormat(\'insertorderedlist\', \'\')';
				break;
			case 'bullist' :
				alt = this.lang[15];
				action = this.instance_name + '.doTextFormat(\'insertunorderedlist\', \'\')';
				break;
			case 'undo' :
				alt = this.lang[16];
				action = this.instance_name + '.doTextFormat(\'undo\', \'\')';
				break;
			case 'redo' :
				alt = this.lang[17];
				action = this.instance_name + '.doTextFormat(\'redo\', \'\')';
				break;
			case 'image' :
				if (! this.allow_insert_img) {	// Autorisation (voir config)
					tool = false;
				}
				alt = this.lang[35];
				action = this.instance_name + '.displayPopup(\'image\', 305, 130, event)';
				break;
			case 'smiley' :
				alt = this.lang[18];
				action = this.instance_name + '.displayPopup(\'smiley\', 200, 200, event)';
				break;
			case 'preview' :
				alt = this.lang[19];
				action = this.instance_name + '.displayPopup(\'preview\', 600, 400, event)';
				break;
			default:
				tool = false;
		}
		
		if(tool) {
			html += '<a href="javascript:void(0);"><img id="' + this.menu[i] + '" alt="' + alt + '" title="' + alt + '" class="icon" border="0" src="' + this.wysiwyg_path + '/images/' + this.menu[i] + '.gif" onclick="' + action + '; return false;" /></a>';		
		}
	}
	html += '	</div>';	
	html += '</div>';	
    html += '<div class="contentWIW" style="width:' + this.frame_width + 'px; height:' + this.frame_height + 'px;">';
	html += '	<iframe id="' + this.wysiwyg_content + '" title="' + this.lang[30] + '" style="width:' + this.frame_width + 'px; height:' + this.frame_height + 'px;" src="' + this.wysiwyg_path + '/jscript/blank.html" width="480" height="400" frameborder="0"></iframe>';
	html += '   <input type="hidden"  name="' + this.wysiwyg_hidden + '" id="' + this.wysiwyg_hidden + '" value="" />';
	html += '</div>';
	
	document.write(html);
};

/**
 *   WYSIWYG_PGEditor::doTextFormat
 *   Apply a text formatting command to the selected text in the editor (or starting at the current cursor position)
 *   @param  command string  Which of the editor/browser text formatting commands to apply
 */
WYSIWYG_PGEditor.prototype.doTextFormat = function (command, optn, evnt)
{
	var contentWin = document.getElementById(this.wysiwyg_content).contentWindow;
    if (contentWin.document.queryCommandEnabled(command)) {
		contentWin.document.execCommand(command, false, optn);
		return true;
	} else {
		return false;
	}
    contentWin.focus();
};

/**
 *   WYSIWYG_PGEditor::displayPopup
 *	 Display a pop-up
 *   @param  command string  Which of the editor/browser text formatting commands to apply
 *   @param  width   number  The popup width (pixels)
 *   @param  height  number  The popup height (pixels)
 */
WYSIWYG_PGEditor.prototype.displayPopup = function (command, width, height, evnt)
{
	if (typeof(pwin) == 'object' && !pwin.closed) {
		pwin.close();
	}

	var pos = this.posEvent(evnt); //position de l'évènement onclick 

	var url = '';
	var name = command;
	var top = pos[0];
	var left = pos[1];
	var resizable = 'no';
	var scrollbars = 'no';
	var html = '';
	
	switch(command) {
		case 'cite' :
			html = this.getPopupCite_html();
			break;
		case 'code' :
			html = this.getPopupCode_html();
			break;
		case 'color' :
			html = this.getPopupColor_html('forecolor');
			break;
		case 'bgcolor' :
			html = this.getPopupColor_html('hilitecolor');
			break;
		case 'image' :
			html = this.getPopupImage_html();
			break;
		case 'link' :
			html = this.getPopupLink_html();
			break;
		case 'preview' :
			top = (screen.height-height)/2;
			left = (screen.width-width)/2;
			url = this.wysiwyg_path + '/popups/preview.php?lng=' + this.lang[0] + '&wysiwyg=true&configpath=' + this.config_path + '&nameditor=' + this.instance_name;
			resizable = 'yes';
			scrollbars = 'yes';
			break;
		case 'smiley' :
			url = this.wysiwyg_path + '/popups/smileys.php?lng=' + this.lang[0] + '&wysiwyg=true&configpath=' + this.config_path + '&nameditor=' + this.instance_name;
			resizable = 'yes';
			scrollbars = 'yes';
			//get current selected range
			var contentWin = document.getElementById(this.wysiwyg_content).contentWindow;
			var sel = contentWin.document.selection;
			if(sel != null) {
				rng = sel.createRange();
			}
			break;
		default :
			alert('Error');
			return false;
	}
	
    pwin = window.open(url, name, 'top=' + top + ', left=' + left + ', width=' + width + ', height=' + height + ', status=no, toolbar=no, resizable=' + resizable + ', scrollbars=' + scrollbars + '');
	if (url == '' && html != '') {
		pwin.document.write(html);
    	pwin.document.close();		
	}
};

/**
 *   WYSIWYG_PGEditor::getPopupColor_html
 *   Apply a text color to selected text or starting at current position
 *   @param  command string  Used to determine which pallete pop-up to display
 *   @return  html   string  The html code
 */
WYSIWYG_PGEditor.prototype.getPopupColor_html = function (command)
{
	var html = new Array();
	var buffer = 0;

	html[buffer++] = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">';
	html[buffer++] = '<html xmlns="http://www.w3.org/1999/xhtml">';
    html[buffer++] = '<head>';
    html[buffer++] = '<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />';
	html[buffer++] = '<meta http-equiv="Content-Style-Type" content="text/css" />';
    html[buffer++] = '<title>' + ((command == 'forecolor')? this.lang[2] : this.lang[3]) + '</title>';
	if(this.stylesheet) {
		//must be done after the document has been opened
		html[buffer++] = '<link rel="stylesheet" type="text/css" media="screen" href="' + this.stylesheet + '_popup.css" />';
		//Patch CSS for IE browsers
		html[buffer++] = '<!--[if lte IE 7]>';
		html[buffer++] = '<link rel="stylesheet" type="text/css" media="screen" href="' + this.stylesheet + '_popup-ie.css" />';
		html[buffer++] = '<![endif]-->';
	}
    html[buffer++] = '<style type="text/css">';
    html[buffer++] = '    html, body{margin:0px; padding:0px;}';
    html[buffer++] = '    table, td {border:2px solid #FFFFFF; cursor:pointer;}';
    html[buffer++] = '    td:hover{border:2px solid #000000;}';
	html[buffer++] = '    td.over {border:2px solid #000000;}';  //IE et Opera (émulation pseudo-class :hover) 
	html[buffer++] = '    td.out{border:2px solid #FFFFFF;}';    //IE et Opera (émulation pseudo-class :hover)
    html[buffer++] = '</style>';
    html[buffer++] = '</head>';
	html[buffer++] = '<body class="popupColor" onload="window.focus()">';
	var color = new Array(
					[['#000000','black'], ['#808080','gray'],          ['#800000','maroon'], ['#A52A2A','brown'],  ['#808000','olive'],   ['#BDB76B','darkkhaki']    ],
					[['#FFFFFF','white'], ['#C0C0C0','silver'],        ['#FF0000','red'],    ['#FFA500','orange'], ['#FFFF00','yellow'],  ['#FFFACD','lemonchiffon'] ],
					[['#008000','green'], ['#2F4F4F','darkslategray'], ['#008080','teal'],   ['#000080','navy'],   ['#800080','purple'],  ['#9400D3','darkviolet']   ],
					[['#00FF00','lime'],  ['#00FF7F','springgreen'],   ['#00FFFF','aqua'],   ['#0000FF','blue'],   ['#FF00FF','fuchsia'], ['#FF1493','deeppink']     ]
	);
    html[buffer++] = '<table border="0" cellpadding="0" cellspacing="0">';
	for (i = 0; i < color.length; i++) {
		html[buffer++] = '<tr>';
		if (this.isMSIE() || this.isOPERA()) {
			for (j = 0; j < color[i].length; j++) {
   				html[buffer++] = '<td bgcolor="' + color[i][j][0] + '" width="20" height="20" onmouseover="this.className=\'over\';" onmouseout="this.className=\'out\';" onclick="opener.' + this.instance_name + '.setColor(\'' + color[i][j][0] + '\',\'' + command + '\');window.close();"><img src="' + this.wysiwyg_path + '/images/blank.gif" width="20" height="20" alt="' + color[i][j][1] + '" title="' + color[i][j][1] + '" /></td>';			
			}	
		} else {
			height = (this.isSAFARI()) ? 16 : 20;	// Fix for SAFARI
			
			for (j = 0; j < color[i].length; j++) {
    			html[buffer++] = '<td bgcolor="' + color[i][j][0] + '" width="20" height="' + height + '" onclick="opener.' + this.instance_name + '.setColor(\'' + color[i][j][0] + '\',\'' + command + '\');window.close();"><img src="' + this.wysiwyg_path + '/images/blank.gif" width="20" height="' + height + '" alt="' + color[i][j][1] + '" title="' + color[i][j][1] + '" /></td>';			
			}
		}
		html[buffer++] = '</tr>';
	}
    html[buffer++] = '</table>';
    html[buffer++] = '</body>';
    html[buffer++] = '</html>';

	return html.join("\n");
};

/**
 *   WYSIWYG_PGEditor::getPopupCode_html
 *	 Select the language code in a pop-up
 *   @return  html   string  The html code
 */
WYSIWYG_PGEditor.prototype.getPopupCode_html = function ()
{
	var html = new Array();
	var buffer = 0;

	html[buffer++] = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">';
	html[buffer++] = '<html xmlns="http://www.w3.org/1999/xhtml">';
    html[buffer++] = '<head>';
    html[buffer++] = '<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />';
	html[buffer++] = '<meta http-equiv="Content-Style-Type" content="text/css" />';
    html[buffer++] = '<title>' + this.lang[8] + '</title>';
	html[buffer++] = '<script type="text/javascript">';
	html[buffer++] = '    function init(){window.focus();}';
	html[buffer++] = '    function getLangCode(formulaire)';
	html[buffer++] = '    {';
	html[buffer++] = '        var sel = formulaire.elements["langcode"];';
	html[buffer++] = '        var id = sel.selectedIndex;';
	html[buffer++] = '        var langCode = sel.options[id].value;';
	html[buffer++] = '        return langCode;';
	html[buffer++] = '    }';
	html[buffer++] = '</script>';
	if(this.stylesheet) {
		//must be done after the document has been opened
		html[buffer++] = '<link rel="stylesheet" type="text/css" media="screen" href="' + this.stylesheet + '_popup.css" />';
		//Patch CSS for IE browsers
		html[buffer++] = '<!--[if lte IE 7]>';
		html[buffer++] = '<link rel="stylesheet" type="text/css" media="screen" href="' + this.stylesheet + '_popup-ie.css" />';
		html[buffer++] = '<![endif]-->';
	}
    html[buffer++] = '<style type="text/css">';
    html[buffer++] = '    html, form {margin:0px; padding:0px;}';
	html[buffer++] = '    body.popupCode {margin:0px; padding:10px;text-align:center;}';
	html[buffer++] = '    fieldset {padding-bottom:10px;padding-right:10px;text-align:right;}';
	html[buffer++] = '    legend {margin:0px;}';
	html[buffer++] = '    div.contents {padding:10px 0px;}';
    html[buffer++] = '</style>';
    html[buffer++] = '</head>';
	html[buffer++] = '<body class="popupCode" onload="init();">';
	html[buffer++] = '<form name="send" action="javascript:void(0);" method="post" onsubmit="opener.'+ this.instance_name +'.insertHTML(\'code\', getLangCode(this)); window.close();">';
	html[buffer++] = '<fieldset>';
	html[buffer++] = '<legend>' + this.lang[8] + '</legend>';
	html[buffer++] = '<div class="contents">';
	html[buffer++] = '    <label for="langcode">' + this.lang[24] + '</label>';
    html[buffer++] = '    <select id="langcode" name="langcode" size="1">';
	for (i = 0; i < this.language_code.length; i++) {
		html[buffer++] = '    <option value="' + this.language_code[i] + '">' + this.language_code[i] + '</option>';	
	}
	html[buffer++] = '    <option value="">' + this.lang[33] + '</option>';
    html[buffer++] = '    </select>';
	html[buffer++] = '</div>';
	if (this.isMSIE()) {
		html[buffer++] = '<input id="ok" name="ok" onmouseover="this.id = \'over\';" onmouseout="this.id = \'ok\';" type="submit" value="' + this.lang[31] + '" />';
		html[buffer++] = '<input id="cancel" name="cancel" onmouseover="this.id = \'over\';" onmouseout="this.id = \'cancel\';" type="reset" value="' + this.lang[32] + '" onclick="window.close();" />';
	} else {
		html[buffer++] = '<input id="ok" name="ok" type="submit" value="' + this.lang[31] + '" />';
		html[buffer++] = '<input id="cancel" name="cancel" type="reset" value="' + this.lang[32] + '" onclick="window.close();" />';	
	}
	html[buffer++] = '</fieldset>';
	html[buffer++] = '</form>';
    html[buffer++] = '</body>';
    html[buffer++] = '</html>';

	return html.join("\n");
};

/**
 *   WYSIWYG_PGEditor::getPopupCite_html
 *	 Get the author name in a pop-up
 *   @return  html   string  The html code
 */
WYSIWYG_PGEditor.prototype.getPopupCite_html = function ()
{
	var html = new Array();
	var buffer = 0;

	html[buffer++] = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">';
	html[buffer++] = '<html xmlns="http://www.w3.org/1999/xhtml">';
    html[buffer++] = '<head>';
    html[buffer++] = '<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />';
	html[buffer++] = '<meta http-equiv="Content-Style-Type" content="text/css" />';
    html[buffer++] = '<title>' + this.lang[7] + '</title>';
	html[buffer++] = '<script type="text/javascript">';
	html[buffer++] = '    function init()';
	html[buffer++] = '    {';
	html[buffer++] = '        window.focus();';
	html[buffer++] = '        document.getElementById("author").focus();';
	html[buffer++] = '    }';
	html[buffer++] = '    function getAuthor(formulaire)';
	html[buffer++] = '    {';
	html[buffer++] = '        var authName = formulaire.elements["author"].value;';
	html[buffer++] = '        authName = authName.replace(/^\\s+/g, "");';
	html[buffer++] = '        authName = authName.replace(/\\s+$/g, "");';
	html[buffer++] = '        authName = authName.replace(/[\xE0-\xE6]/g, "a");';
	html[buffer++] = '        authName = authName.replace(/[\xC0-\xC6]/g, "A");';
	html[buffer++] = '        authName = authName.replace(/[\xE7]/g, "c");';
	html[buffer++] = '        authName = authName.replace(/[\xC7]/g, "C");';
	html[buffer++] = '        authName = authName.replace(/[\xE8-\xEB]/g, "e");';
	html[buffer++] = '        authName = authName.replace(/[\xC8-\xCB]/g, "E");';
	html[buffer++] = '        authName = authName.replace(/[\xEC-\xEF]/g, "i");';
	html[buffer++] = '        authName = authName.replace(/[\xCC-\xCF]/g, "I");';
	html[buffer++] = '        authName = authName.replace(/[\xF1]/g, "n");';
	html[buffer++] = '        authName = authName.replace(/[\xD1]/g, "N");';
	html[buffer++] = '        authName = authName.replace(/[\xF2-\xF6\xF8]/g, "o");';
	html[buffer++] = '        authName = authName.replace(/[\xD2-\xD6\xD8]/g, "O");';
	html[buffer++] = '        authName = authName.replace(/[\xF9-\xFC]/g, "u");';
	html[buffer++] = '        authName = authName.replace(/[\xD9-\xDC]/g, "U");';
	html[buffer++] = '        authName = authName.replace(/[\xFD\xFF]/g, "y");';
	html[buffer++] = '        authName = authName.replace(/[\xDD]/g, "Y");';
	html[buffer++] = '        authName = authName.replace(/[^-a-z0-9_]+/gi, "_");';
	html[buffer++] = '        return authName;';
	html[buffer++] = '    }';
	html[buffer++] = '</script>';
	if(this.stylesheet) {
		html[buffer++] = '<link rel="stylesheet" type="text/css" media="screen" href="' + this.stylesheet + '_popup.css" />';
		//Patch CSS for IE browsers
		html[buffer++] = '<!--[if lte IE 7]>';
		html[buffer++] = '<link rel="stylesheet" type="text/css" media="screen" href="' + this.stylesheet + '_popup-ie.css" />';
		html[buffer++] = '<![endif]-->';
	}
    html[buffer++] = '<style type="text/css">';
    html[buffer++] = '    html, form {margin:0px; padding:0px;}';
	html[buffer++] = '    body.popupCitation {margin:0px; padding:10px;text-align:center;}';
	html[buffer++] = '    fieldset {padding-bottom:10px;padding-right:10px;text-align:right;}';
	html[buffer++] = '    legend {margin:0px;}';
	html[buffer++] = '    div.contents {padding:10px 0px;}';
    html[buffer++] = '</style>';
    html[buffer++] = '</head>';
	html[buffer++] = '<body class="popupCitation" onload="init();">';
	html[buffer++] = '<form name="send" action="javascript:void(0);" method="post" onsubmit="opener.'+ this.instance_name +'.insertHTML(\'cite\', getAuthor(this)); window.close();">';
	html[buffer++] = '<fieldset>';
	html[buffer++] = '<legend>' + this.lang[7] + '</legend>';
	html[buffer++] = '<div class="contents">';
	html[buffer++] = '    <label for="author">' + this.lang[22] + '</label>';
	html[buffer++] = '    <input id="author" name="author" type="text" value="" />';
	html[buffer++] = '</div>';
	if (this.isMSIE()) {
		html[buffer++] = '<input id="ok" name="ok" onmouseover="this.id = \'over\';" onmouseout="this.id = \'ok\';" type="submit" value="' + this.lang[31] + '" />';
		html[buffer++] = '<input id="cancel" name="cancel" onmouseover="this.id = \'over\';" onmouseout="this.id = \'cancel\';" type="reset" value="' + this.lang[32] + '" onclick="window.close();" />';
	} else {
		html[buffer++] = '<input id="ok" name="ok" type="submit" value="' + this.lang[31] + '" />';
		html[buffer++] = '<input id="cancel" name="cancel" type="reset" value="' + this.lang[32] + '" onclick="window.close();" />';	
	}
	html[buffer++] = '</fieldset>';
	html[buffer++] = '</form>';
	html[buffer++] = '<script type="text/javascript">document.getElementById("author").focus();</script>';
    html[buffer++] = '</body>';
    html[buffer++] = '</html>';

	return html.join("\n");
};

/**
 * WYSIWYG_PGEditor::getPopupLink_html
 * Get the link 's url 
 * @return  html   string  The html code
 */
WYSIWYG_PGEditor.prototype.getPopupLink_html = function ()
{
	var html = new Array();
	var buffer = 0;

	html[buffer++] = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">';
	html[buffer++] = '<html xmlns="http://www.w3.org/1999/xhtml">';
    html[buffer++] = '<head>';
    html[buffer++] = '<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />';
	html[buffer++] = '<meta http-equiv="Content-Style-Type" content="text/css" />';
    html[buffer++] = '<title>' + this.lang[12] + '</title>';
	html[buffer++] = '<script type="text/javascript">';
	html[buffer++] = '    function init()';
	html[buffer++] = '    {';
	html[buffer++] = '        window.focus();';
	html[buffer++] = '        document.getElementById("url").focus();';
	html[buffer++] = '    }';
	html[buffer++] = '    function getURL(formulaire)';
	html[buffer++] = '    {';
	html[buffer++] = '        var link = formulaire.elements["url"].value;';
	html[buffer++] = '        link = link.replace(/(\\s| )+/g, "");';
	html[buffer++] = '        return link;';
	html[buffer++] = '    }';
	html[buffer++] = '</script>';
	if(this.stylesheet) {
		html[buffer++] = '<link rel="stylesheet" type="text/css" media="screen" href="' + this.stylesheet + '_popup.css" />';
		//Patch CSS for IE browsers
		html[buffer++] = '<!--[if lte IE 7]>';
		html[buffer++] = '<link rel="stylesheet" type="text/css" media="screen" href="' + this.stylesheet + '_popup-ie.css" />';
		html[buffer++] = '<![endif]-->';
	}
    html[buffer++] = '<style type="text/css">';
    html[buffer++] = '    html, form {margin:0px; padding:0px;}';
	html[buffer++] = '    body.popupLink {margin:0px; padding:10px;text-align:center;}';
	html[buffer++] = '    fieldset {padding-bottom:10px;padding-right:10px;text-align:right;}';
	html[buffer++] = '    legend {margin:0px;}';
	html[buffer++] = '    div.contents {padding:10px 0px;}';
    html[buffer++] = '</style>';
    html[buffer++] = '</head>';
	html[buffer++] = '<body class="popupLink" onload="init();">';
	html[buffer++] = '<form name="send" action="javascript:void(0);" method="post" onsubmit="opener.'+ this.instance_name +'.insertLink(getURL(this)); window.close();">';
	html[buffer++] = '<fieldset>';
	html[buffer++] = '<legend>' + this.lang[12] + '</legend>';
	html[buffer++] = '<div class="contents">';
	html[buffer++] = '    <label for="url">' + this.lang[21] + '</label>';
	html[buffer++] = '    <input id="url" name="url" type="text" value="http://" />';
	html[buffer++] = '</div>';
	if (this.isMSIE()) {
		html[buffer++] = '<input id="ok" name="ok" onmouseover="this.id = \'over\';" onmouseout="this.id = \'ok\';" type="submit" value="' + this.lang[31] + '" />';
		html[buffer++] = '<input id="cancel" name="cancel" onmouseover="this.id = \'over\';" onmouseout="this.id = \'cancel\';" type="reset" value="' + this.lang[32] + '" onclick="window.close();" />';
	} else {
		html[buffer++] = '<input id="ok" name="ok" type="submit" value="' + this.lang[31] + '" />';
		html[buffer++] = '<input id="cancel" name="cancel" type="reset" value="' + this.lang[32] + '" onclick="window.close();" />';	
	}
	html[buffer++] = '</fieldset>';
	html[buffer++] = '</form>';
	html[buffer++] = '<script type="text/javascript">document.getElementById("url").focus();</script>';
    html[buffer++] = '</body>';
    html[buffer++] = '</html>';

	return html.join("\n");
};

/**
 * WYSIWYG_PGEditor::getPopupImage_html
 * Get the image 's url 
 * @return  html   string  The html code
 */
WYSIWYG_PGEditor.prototype.getPopupImage_html = function ()
{
	var html = new Array();
	var buffer = 0;

	html[buffer++] = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">';
	html[buffer++] = '<html xmlns="http://www.w3.org/1999/xhtml">';
    html[buffer++] = '<head>';
    html[buffer++] = '<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />';
	html[buffer++] = '<meta http-equiv="Content-Style-Type" content="text/css" />';
    html[buffer++] = '<title>' + this.lang[35] + '</title>';
	html[buffer++] = '<script type="text/javascript">';
	html[buffer++] = '    function init()';
	html[buffer++] = '    {';
	html[buffer++] = '        window.focus();';
	html[buffer++] = '        document.getElementById("url").focus();';
	html[buffer++] = '    }';
	html[buffer++] = '    function getUrlImage(formulaire)';
	html[buffer++] = '    {';
	html[buffer++] = '        var url = formulaire.elements["url"].value;';
	html[buffer++] = '        url = url.replace(/^\\s+/g, "");';
	html[buffer++] = '        url = url.replace(/\\s+$/g, "");';
	html[buffer++] = '        return url;';
	html[buffer++] = '    }';
	html[buffer++] = '</script>';
	if(this.stylesheet) {
		html[buffer++] = '<link rel="stylesheet" type="text/css" media="screen" href="' + this.stylesheet + '_popup.css" />';
		//Patch CSS for IE browsers
		html[buffer++] = '<!--[if lte IE 7]>';
		html[buffer++] = '<link rel="stylesheet" type="text/css" media="screen" href="' + this.stylesheet + '_popup-ie.css" />';
		html[buffer++] = '<![endif]-->';
	}
    html[buffer++] = '<style type="text/css">';
    html[buffer++] = '    html, form {margin:0px; padding:0px;}';
	html[buffer++] = '    body.popupLink {margin:0px; padding:10px;text-align:center;}';
	html[buffer++] = '    fieldset {padding-bottom:10px;padding-right:10px;text-align:right;}';
	html[buffer++] = '    legend {margin:0px;}';
	html[buffer++] = '    div.contents {padding:10px 0px;}';
    html[buffer++] = '</style>';
    html[buffer++] = '</head>';
	html[buffer++] = '<body class="popupImage" onload="init();">';
	html[buffer++] = '<form name="send" action="javascript:void(0);" method="post" onsubmit="opener.'+ this.instance_name +'.addImage(getUrlImage(this)); window.close();">';
	html[buffer++] = '<fieldset>';
	html[buffer++] = '<legend>' + this.lang[35] + '</legend>';
	html[buffer++] = '<div class="contents">';
	html[buffer++] = '    <label for="url">' + this.lang[21] + '</label>';
	html[buffer++] = '    <input id="url" name="url" type="text" value="http://" />';
	html[buffer++] = '</div>';
	if (this.isMSIE()) {
		html[buffer++] = '<input id="ok" name="ok" onmouseover="this.id = \'over\';" onmouseout="this.id = \'ok\';" type="submit" value="' + this.lang[31] + '" />';
		html[buffer++] = '<input id="cancel" name="cancel" onmouseover="this.id = \'over\';" onmouseout="this.id = \'cancel\';" type="reset" value="' + this.lang[32] + '" onclick="window.close();" />';
	} else {
		html[buffer++] = '<input id="ok" name="ok" type="submit" value="' + this.lang[31] + '" />';
		html[buffer++] = '<input id="cancel" name="cancel" type="reset" value="' + this.lang[32] + '" onclick="window.close();" />';	
	}
	html[buffer++] = '</fieldset>';
	html[buffer++] = '</form>';
	html[buffer++] = '<script type="text/javascript">document.getElementById("url").focus();</script>';
    html[buffer++] = '</body>';
    html[buffer++] = '</html>';

	return html.join("\n");
};

/**
 *   WYSIWYG_PGEditor::setColor
 *   Used to set the text or highlight color of the selected text in Gecko engine browsers
 *   @param  color   string  Used to determine the color
 *   @param  command string  Which of the editor/browser text formatting commands to apply
 */
WYSIWYG_PGEditor.prototype.setColor = function (color, command)
{
	if (typeof(pwin) == 'object' && !pwin.closed) {
		pwin.close();
	}

    if (this.isMSIE() && command == 'hilitecolor') {
		command = 'backcolor';
	}
    //get current selected range
    var contentWin = document.getElementById(this.wysiwyg_content).contentWindow;
    var sel = contentWin.document.selection;
    if (sel != null) {
		rng = sel.createRange();
	}
    contentWin.focus();
    if (contentWin.document.queryCommandEnabled(command)) {
        contentWin.document.execCommand(command, false, color);
    } else { 
		return false; 
	}
    contentWin.focus();
    return true;
};

/**
 *   WYSIWYG_PGEditor::insertHTML
 *   Generates the HTML that will be insert in the editor.
 *   @param  command string  The command that indicates which text is being set
 *   @return boolean
 */
WYSIWYG_PGEditor.prototype.insertHTML = function (command, html)
{
	var tag = '';
	var attribut = '';
	var option = false;	
	switch (command) {
		case 'cite':
			tag = 'cite';
			option = true;
			var nom = /^[-a-z0-9_]+$/i;
			attribut = (nom.test(html))? this.lang[23]+' ' + html : this.lang[23];
			break;		
		case 'code':
			tag = 'code';
			option = true;
			var nom = /^[-a-z0-9]+$/i;
			attribut = (nom.test(html))? this.lang[25]+' ' + html : this.lang[25];
			break;			
		default :
			alert('Error');
			return false;
	}	
	if (option) {
		if (this.isMSIE()) {		// IE
        	return this._insert_HTML_ie(tag, attribut);
    	} else if (this.isGECKO() || this.isSAFARI()) {	// Gecko and Safari
        	return this._insert_HTML_gecko(tag, attribut);
		} else if (this.isOPERA()) {	// Opera
        	return this._insert_HTML_opera(tag, attribut);
    	}
	} else {
		return false;
	}
};

/**
 *   WYSIWYG_PGEditor::_insert_HTML_ie
 *   This is the browser engine-specific code for inserting a html code for MSIE browsers.
 *   @param  tag       string  The selected tag
 *   @param  attribut  string  The selected attribut
 */
WYSIWYG_PGEditor.prototype._insert_HTML_ie = function (tag, attribut)
{
	var contentWin = document.getElementById(this.wysiwyg_content).contentWindow;
    contentWin.focus();
    //get current selected range
    var sel = contentWin.document.selection.createRange();
	var selText = sel.text;
	//replace code
	if (tag == 'cite') {
		var block = 'p';
		selText = selText.replace(/&/g, '&amp;');
		selText = selText.replace(/</g, '&lt;');
		selText = selText.replace(/>/g, '&gt;');
		selText = selText.replace(/[\n\r]+/g, '<br />');
	} else if (tag == 'code') {
	 	var block = 'pre';
		selText = selText.replace(/&/g, '&amp;');
		selText = selText.replace(/</g, '&lt;');
		selText = selText.replace(/>/g, '&gt;');
		selText = selText.replace(/[\n\r]+/g, '<br />');
	}
	var html = '<div class="' + tag + '"><span class="' + tag + '">' + attribut + '</span><' + block + '><' + tag + '>' + selText + '</' + tag + '></' + block + '></div> ';
	sel.pasteHTML(html);  //IE
    contentWin.focus();
	return true;
};

/**
 *   WYSIWYG_PGEditor::_insert_HTML_gecko
 *   This is the browser engine-specific code for inserting a html code for Gecko browsers.
 *   @param  tag       string  The selected tag
 *   @param  attribut  string  The selected attribut
 */
WYSIWYG_PGEditor.prototype._insert_HTML_gecko = function (tag, attribut)
{
	var contentWin = document.getElementById(this.wysiwyg_content).contentWindow;
    contentWin.focus();
	//get current selected range text
	var sel = contentWin.getSelection();
	var selText = sel.toString();
	//replace code
	if (tag == 'cite') {
		var block = 'p';
		selText = selText.replace(/&/g, '&amp;');
		selText = selText.replace(/</g, '&lt;');
		selText = selText.replace(/>/g, '&gt;');
		selText = selText.replace(/[\n\r]+/g, '<br />');
	} else if (tag == 'code') {
	 	var block = 'pre';
		selText = selText.replace(/&/g, '&amp;');
		selText = selText.replace(/</g, '&lt;');
		selText = selText.replace(/>/g, '&gt;');
		selText = selText.replace(/[\n\r]+/g, '<br />');
	}
	
	var html = '&nbsp;<div class="' + tag + '"><span class="' + tag + '">' + attribut + '</span><' + block + '><' + tag + '>' + selText + '</' + tag + '></' + block + '></div>&nbsp;';
	contentWin.document.execCommand('insertHTML', false, html);
    contentWin.focus();
	return true;
};

/**
 *   WYSIWYG_PGEditor::_insert_HTML_opera
 *   This is the browser engine-specific code for inserting a html code for Opera 9 browser.
 *   @param  tag       string  The selected tag
 *   @param  attribut  string  The selected attribut
 */
WYSIWYG_PGEditor.prototype._insert_HTML_opera = function (tag, attribut)
{
	var contentWin = document.getElementById(this.wysiwyg_content).contentWindow;
    contentWin.focus();

    /**
     * get current selected range text
     */
    if (contentWin.document.selection) {    // Opera 9 -> 10.53
        var sel = contentWin.document.selection.createRange();
    	var selText= sel.text;
    }
    else if (typeof contentWin.getSelection() == 'object') { //Opera 10.63+
    	var sel = contentWin.getSelection();
        var selRange = sel.getRangeAt(0);
        var selFragment = selRange.extractContents();
        
        var children = selFragment.childNodes;
        var selText = '';
        
        for (var i = 0; i < children.length; i++) {
            if (children[i].nodeType == 1) {    //Element
                selText += children[i].innerText;
                selText += (children[i].nodeName == 'P' || children[i].nodeName == 'BR')? "\n" : '';
            } else if (children[i].nodeType == 3) { // Text
                selText += children[i].data;
            }
        }
    }
    else {
        return false;
    }
    //
    
	/**
     * replace code
     */
	if (tag == 'cite') {
		var block = 'p';
		selText = selText.replace(/&/g, '&amp;');
		selText = selText.replace(/</g, '&lt;');
		selText = selText.replace(/>/g, '&gt;');
		selText = selText.replace(/[\n\r]+/g, '<br />');
	} else if (tag == 'code') {
	 	var block = 'pre';
		selText = selText.replace(/&/g, '&amp;');
		selText = selText.replace(/</g, '&lt;');
		selText = selText.replace(/>/g, '&gt;');
		selText = selText.replace(/[\n\r]+/g, '<br />');
	}
    //
    
    // Insert code
	var html = '<div class="' + tag + '"><span class="' + tag + '">' + attribut + '</span><' + block + '><' + tag + '>' + selText + '</' + tag + '></' + block + '></div>&nbsp;';
	contentWin.document.execCommand('insertHTML', false, html);  //Opera
    
    contentWin.focus();
	return true;	
};

/**
 *   WYSIWYG_PGEditor::insertLink
 *   Generates the HTML that will be insert in the editor.
 *   @param  command string  The command that indicates which text is being set
 */
WYSIWYG_PGEditor.prototype.insertLink = function (url)
{
	var contentWin = document.getElementById(this.wysiwyg_content).contentWindow;

	if (url != null && contentWin.document.queryCommandEnabled('createlink')) {
		contentWin.document.execCommand('CreateLink', false, url);
		return true;
	} else {
		return false;
	}
};

/**
 *   WYSIWYG_PGEditor::addImage
 *   Puts the image into the editor iframe (Called from the pop-up window that insertImage creates)
 *   @param  thisimage   string  The path of the image
 */
WYSIWYG_PGEditor.prototype.addImage = function (thisimage)
{
	if (typeof(pwin) == 'object' && !pwin.closed) {
		pwin.close();
	}

	var contentWin = document.getElementById(this.wysiwyg_content).contentWindow;
	contentWin.focus();
    if (this.viewMode == 1) {
        var x = contentWin.document;
        x.execCommand('insertimage', false, thisimage);
    }
    contentWin.focus();
    return true;
};

/**
 *  WYSIWYG_PGEditor::posEvent
 *	Relative Position of event
 *  @param  evnt  object  Object Event
 */
WYSIWYG_PGEditor.prototype.posEvent = function (evnt)
{
	var pos = new Array();
	pos[0] = evnt.screenY; //Top
	pos[1] = evnt.screenX; //Left

	if(this.isOPERA()){ //Correction pour Opera 9
		pos[0] = pos[0] - 60;
		pos[1] = pos[1] - 10;
	}
	return pos;
};