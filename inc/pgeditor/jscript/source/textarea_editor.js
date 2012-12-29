/*
	Plugin PostGuestEditor
	Version  : 2.5.0 (2007/09/20)
	Compatibility : Guppy v4.5.x
	Licence  : GNU Lesser General Public License
	Author   : jérôme CROUX (Djchouix)
	Web site : http://lebrikabrak.info/
	E-mail   : jchouix@wanadoo.fr
*/

var textselec = ''; //variable globale contenant le texte sélectionné

/**
 *   selectext 
 *	 Sélectionne un texte (IE et Opera 8)
 *   @param  nameform      string  Le nom assigné au formulaire (attribut name de la balise <form>)
 *   @param  nametextarea  string  Le nom assigné au textarea (attribut name de la balise <texarea>)
 */
function selectext(nameform, nametextarea)
{
	if (typeof(document.selection)!='undefined') {
    	document.forms[nameform].elements[nametextarea].focus();
		objetselection = document.selection.createRange();
    	textselec = objetselection.text;
    } else {
		return false;
	}
}

/**
 *   AddCode : 
 *	 Insère un code dans le textarea
 *   @param  code1         string  La partie du code avant le texte sélectionné
 *   @param  code2         string  La partie du code après le texte sélectionné
 *   @param  nameform      string  Le nom assigné au formulaire (attribut name de la balise <form>)
 *   @param  nametextarea  string  Le nom assigné au textarea (attribut name de la balise <texarea>)
 */
function AddCode(code1, code2, nameform, nametextarea)
{
	var textarea = document.forms[nameform].elements[nametextarea];
  	//IE et OPERA 8+
	if (typeof(document.selection) != 'undefined') {
    	objetselection.text = code1 + textselec + code2;
		textselec = '';
  	}  
	//MOZILLA 1.7.x/FIREFOX 1.x/NETSCAPE 7.1+/SAFARI 1.3+/KONQUEROR 3.5+
	else if (typeof(textarea.selectionStart) != 'undefined') {
        textarea.focus();
        var startPos = textarea.selectionStart;
        var endPos = textarea.selectionEnd;
		//Position et hauteur de la scrollbar
		if(textarea.scrollHeight) {
			var oldScrollPos = textarea.scrollTop;	
			var oldScrollHeight = textarea.scrollHeight;
		}
		//Modification de la valeur du textarea
        var chaine = textarea.value;
		var code = code1 + chaine.substring(startPos, endPos) + code2;
        textarea.value = chaine.substring(0, startPos) + code + chaine.substring(endPos, chaine.length);
        textarea.selectionStart = startPos + code.length ;
        textarea.selectionEnd = startPos + code.length ;
		//Nouvelle position et hauteur de la scollbar
		if(textarea.scrollHeight) {
			var newScrollHeight = textarea.scrollHeight - oldScrollHeight;
			textarea.scrollTop = oldScrollPos + newScrollHeight;
		}
   	}
    //AUTRES NAVIGATEURS
	else {
		var pos;
		var re = new RegExp('^[0-9]{0,3}$');
		while (!re.test(pos)) {
			pos = prompt("Veuillez taper le numéro de la place de la lettre (0.." + textarea.value.length + ") à partir de laquelle vous voulez insérer votre texte ou votre smiley :", "0");
		}
		if (pos > textarea.value.length) {
			pos = textarea.value.length;
		}
		if (code2 == '') {
			textarea.value = textarea.value.substr(0, pos) + code1 + textarea.value.substr(pos);
		} else {
			var insText = prompt("Veuillez taper le texte", '');	
			if (insText != null) textarea.value = textarea.value.substr(0, pos) + code1 + insText + code2 + textarea.value.substr(pos);
		}
	}
	textarea.focus();
    return;	
}

/**
 *   AddTagFormat : 
 *	 Insère un tag autour du texte sélectionné pour le mettre en forme
 *   @param  tag           string  Le tag choisi pour mettre en forme le texte
 *   @param  nameform      string  Le nom assigné au formulaire (attribut name de la balise <form>)
 *   @param  nametextarea  string  Le nom assigné au textarea (attribut name de la balise <texarea>)
 */
function AddTagFormat(tag, nameform, nametextarea)
{
	// Pas de texte sélectionné
	if (isEmptySelection(nameform, nametextarea)) {
		return false;
	}

	var code1 = '<' + tag + '>';
	var code2 = '<\/' + tag + '>';	
	AddCode(code1, code2, nameform, nametextarea);
	document.forms[nameform].elements[nametextarea].focus();
}

/**
 *   AddSmiley : 
 *	 Insère un smiley
 *   @param  code           string  Le code du smiley choisi
 *   @param  nameform       string  Le nom assigné au formulaire (attribut name de la balise <form>)
 *   @param  nametextarea   string  Le nom assigné au textarea (attribut name de la balise <texarea>)
 */
function AddSmiley(code, nameform, nametextarea)
{
    var code1 = code;
	var code2 = '';
	AddCode(code1, code2, nameform, nametextarea);
	document.forms[nameform].elements[nametextarea].focus();
}

/**
 *   popupPGEditor : 
 *	 Crée et ouvre une popup au centre de l'écran
 *   @param  url            string  L'url de la page appelée dans la popup
 *   @param  name           string  Le nom de la popup
 *   @param  width          number  La largeur de la popup (en pixels)
 *   @param  height         number  La hauteur de la popup (en pixels)
 *   @param  resizable      yes/no  Redimensionnement ou non de la popup
 *   @param  scrollbars     yes/no  Présence ou non des barres de défilement
 *   @param  nameform       string  Le nom assigné au formulaire (attribut name de la balise <form>)
 *   @param  nametextarea   string  Le nom assigné au textarea (attribut name de la balise <texarea>)
 */
function popupPGEditor(url, name, width, height, resizable, scrollbars, nameform, nametextarea)
{	
    var top = (screen.height-height)/2;
    var left = (screen.width-width)/2;
    window.open(url, name, 'top=' + top + ', left=' + left + ', width=' + width + ', height=' + height + ', resizable=' + resizable + ', scrollbars=' + scrollbars + ',menubar=no,location=no,directories=no,status=no,copyhistory=no,toolbar=no');
}

/**
 *   AddTagColor : 
 *	 Insère un tag pour colorer le texte sélectionné
 *   @param  nameselect     string  Le nom du menu (attribut name de la balise <select>)
 *   @param  tag            string  Le tag choisi (color ou bgcolor)
 *   @param  nameform       string  Le nom assigné au formulaire (attribut name de la balise <form>)
 *   @param  nametextarea   string  Le nom assigné au textarea (attribut name de la balise <texarea>)
 */
function AddTagColor(nameselect, tag, nameform, nametextarea)
{
	var sel = document.forms[nameform].elements[nameselect];
	var id = sel.selectedIndex;
	var colorstring = sel.options[id].value;

	// Pas de texte sélectionné
	if (isEmptySelection(nameform, nametextarea)) {
		sel.value = sel.options[0].value;	
		document.forms[nameform].elements[nametextarea].focus();
		return false;
	}

	if(colorstring != '') {
		var code1 = '<' + tag + '=' + colorstring + '>';
		var code2 = '<\/'+ tag + '>';
		AddCode(code1, code2, nameform, nametextarea);
	}
	sel.value = sel.options[0].value;	
	document.forms[nameform].elements[nametextarea].focus();
}

/**
 *   AddTagFormatPrompt : 
 *	 Insère un lien, une citation ou un code (affichage d'une boite de dialoque prompt)
 *   @param  tag            string  Le tag choisi
 *   @param  message        string  Le message de la boite de dialogue prompt
 *   @param  nameform       string  Le nom assigné au formulaire (attribut name de la balise <form>)
 *   @param  nametextarea   string  Le nom assigné au textarea (attribut name de la balise <texarea>)
 */
function AddTagFormatPrompt(tag, message, nameform, nametextarea)
{
	// Pas de texte sélectionné
	if (isEmptySelection(nameform, nametextarea)) {
		return false;
	}

	var content = (tag == 'link')? 'http://' : '';
	var url = prompt(message, content);
	if(url != null) {
		url = url.replace(/[\n\r\v\t ]+/g,'');
		if (url != '') { 
			url = '=' + url;
		}
    	var code1 = '<' + tag + url + '>';
		var code2 = '<\/'+ tag + '>';
		AddCode(code1, code2, nameform, nametextarea);
	}
	document.forms[nameform].elements[nametextarea].focus();
}

/**
 *   AddTagCode : 
 *	 Insère un tag pour insérer du code
 *   @param  nameselect     string  Le nom du menu (attribut name de la balise <select>)
 *   @param  tag            string  Le tag choisi (code)
 *   @param  nameform       string  Le nom assigné au formulaire (attribut name de la balise <form>)
 *   @param  nametextarea   string  Le nom assigné au textarea (attribut name de la balise <texarea>)
 */
function AddTagCode(nameselect, tag, nameform, nametextarea)
{
	var sel = document.forms[nameform].elements[nameselect];
	
	// Pas de texte sélectionné
	if (isEmptySelection(nameform, nametextarea)) {
		sel.value = sel.options[0].value;	
		document.forms[nameform].elements[nametextarea].focus();
		return false;
	}

	var id = sel.selectedIndex;
	var lang = sel.options[id].value;
	if(lang != 'none') {
		if (lang != '') { 
			lang = '=' + lang;
		}
		var code1 = '<' + tag + lang + '>';
		var code2 = '<\/'+ tag + '>';
		AddCode(code1, code2, nameform, nametextarea);
	}
	sel.value = sel.options[0].value;	
	document.forms[nameform].elements[nametextarea].focus();
}

/**
 *   isEmptySelection : 
 *	 vérifie si du texte a été sélectionné ou non
 *   @param  nameform       string  Le nom assigné au formulaire (attribut name de la balise <form>)
 *   @param  nametextarea   string  Le nom assigné au textarea (attribut name de la balise <texarea>)
 *   @return boolean
 */
function isEmptySelection(nameform, nametextarea)
{
	var textarea = document.forms[nameform].elements[nametextarea];

  	//IE et OPERA 8+
	if (typeof(document.selection) != 'undefined') {
    	if (textselec == "") {
			return true;
		}
  	}  
	//MOZILLA 1.7.x/FIREFOX 1.x/NETSCAPE 7.1+/SAFARI 1.3+/KONQUEROR 3.5+
	else if (typeof(textarea.selectionStart) != 'undefined') {
        textarea.focus();
        var startPos = textarea.selectionStart;
        var endPos = textarea.selectionEnd;
		if (startPos == endPos) {
			return true;
		}
	}
	
	return false;
}

/**
 *   displayBlockById : 
 *	 Affiche ou masque un block
 *   @param  id       string  L'id du block
 *   @param  display  string  La valeur de la propriété CSS display ('block', 'inline' ou 'none')
 */
function displayBlockById(id, display)
{
	if(document.getElementById) {
		document.getElementById(id).style.display = display;
	} else if(document.all) {
		document.all[id].style.display = display;
	} else if(document.layers) {
		document.layers[id].display = display;
	} else {
		return false;
	}
}

/**
 *   displayBlockById : 
 *	 Affiche ou masque l\èaide
 *   @param  flag     boolean Affiche ou masque l\'aide     
 *   @param  nameform       string  Le nom assigné au formulaire (attribut name de la balise <form>)
 *   @param  nametextarea   string  Le nom assigné au textarea (attribut name de la balise <texarea>)
 */
function displayHelp(flag,  nameform, nametextarea)
{
	if (flag) {
		displayBlockById('iconHelpOpen_' + nametextarea, 'none');
		displayBlockById('iconHelpClose_' + nametextarea, 'inline');
		displayBlockById('helpTA_' + nametextarea, 'block');
	} else {
		displayBlockById('iconHelpOpen_' + nametextarea, 'inline');
		displayBlockById('iconHelpClose_' + nametextarea, 'none');
		displayBlockById('helpTA_' + nametextarea, 'none');
		document.forms[nameform].elements[nametextarea].focus();
	}
}

/**
 *   submitPGEditor
 *   Vérifie si le contenu du textarea est vide ou non
 *	Renvoie false si le contenu du textarea est vide
 *   @param  nameform       string  Le nom assigné au formulaire (attribut name de la balise <form>)
 *   @param  nametextarea   string  Le nom assigné au textarea (attribut name de la balise <texarea>)
 */
function submitPGEditor(nameform, nametextarea)
{
	var regexp = /^\s*$/i;
	var content = document.forms[nameform].elements[nametextarea].value;
	if (regexp.test(content)) {
		return false;
	} else {
		return true;
	}	
}

/**
 *   AddTagExternalImg : 
 *	 Insère une image externe
 *   @param  tag            string  Le tag choisi
 *   @param  message        string  Le message de la boite de dialogue prompt
 *   @param  nameform       string  Le nom assigné au formulaire (attribut name de la balise <form>)
 *   @param  nametextarea   string  Le nom assigné au textarea (attribut name de la balise <texarea>)
 */
function AddTagExternalImg(tag, message, nameform, nametextarea)
{
	var content = 'http://';
	var url = prompt(message, content);
	
	if(url != null) {
		url = url.replace(/[\n\r\v\t ]+/g,'');
		if (url != '') { 
			url = '=' + url;
		} else {
			return false;	
		}
    	var code1 = '<' + tag + url + '>';
		var code2 = '';
		AddCode(code1, code2, nameform, nametextarea);
	}
	document.forms[nameform].elements[nametextarea].focus();
}