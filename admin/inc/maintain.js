(function()
{
	/**
	 * addCheckBoxActionsToTable
	 * ajoute les cases � cocher des actions dans un tableau
	 * @param id string Identifiant du tableau
	 */
	function addCheckBoxActionsToTable(table, lang)
	{
		var tbody = table.getElementsByTagName("tbody")[0];
		var tr = tbody.getElementsByTagName("tr")[0];

		// Ajout de l'attribut rowspan aux cellules du groupe
		var td = tr.getElementsByTagName("td");
		for (var i = 0; i < (td.length - 1); i ++) {
			td[i].rowSpan = "2";
		}

		// Cr�ation d'une nouvelle ligne de tableau
		var newTr = document.createElement("tr");
		newTr.className = "forum";

		// Cr�ation de la cellule contenant les cases � cocher
		var tdAction = createTdAction(table, lang);

		newTr.appendChild(tdAction);
		tbody.insertBefore(newTr, tr.nextSibling);
	}

	/**
	 * createTdAction
	 * ajoute les cases � cocher des actions dans l'ent�te ou le pied du tableau
	 * @param table object Element repr�sentant le tableau
	 * @param id string Identifiant des cases � cocher dans la cellule
	 */
	function createTdAction(table, lang)
	{
		var td = document.createElement('td');
		td.className = "action";
		td.noWrap = "nowrap";

		// Ajout du groupe Restaurer tout
		//addCheckboxAction(table, td, 'i', "restoreAllItems", "Restaurer tous les items", "inc/img/files/save.gif");
		addSpace(td, 7);

		// Ajout du groupe Supprimer tout
		addCheckboxAction(table, td, 's', "destroyAllItems", lang[0], "inc/img/files/sup.gif");

		return td;
	}

	/**
	 * addCheckboxAction
	 * Ajoute une case � cocher
	 * @param table object Tableau contenant la case � cocher
	 * @param td object Cellule du tableau contenant la case � cocher
	 * @param action string Action de la case � cocher (�v�nement onclick)
	 * @param id string Identifiant de la case � cocher
	 * @param title string Titre de la case � cocher
	 * @param imgPath string Chemin de l'image associ�e � la case � cocher
	 * @return false
	 */
	function addCheckboxAction(table, td, action, id, title, imgPath)
	{
		var checkbox = createCheckbox(id, title);
		var img = createImg(imgPath, title);
		var label = createLabel(id, img);

		checkbox.onclick = function () {
			checkAllCheckboxByStatus(table, checkbox, action);
		}

		td.appendChild(checkbox);
		td.appendChild(label);
	}

	/**
	 * checkAllCheckboxByStatus
	 * coche toutes cases selon leur status
	 * @param table object Tableau contenant les cases � cocher
	 * @param checkbox object Case � cocher responsable de l'action
	 * @param action string Status des cases qui doivent �tre coch�es
	 * @return false
	 */
	function checkAllCheckboxByStatus(table, checkbox, action)
	{
		var items = table.getElementsByTagName('input');

		for (var i = 2; i < items.length; i ++) {
			var itemStatus = items[i].id.substring(0, 1);
			if (itemStatus == action) {
				items[i].value = (checkbox.checked)? "on" : "";
				var img0 = items[i].nextSibling;
				var img1 = img0.nextSibling;
				img0.style.display = (checkbox.checked)? "none" : "inline";
				img1.style.display = (checkbox.checked)? "inline" : "none";
			}
		}
	}

	/**
	 * createCheckbox
	 * cr�e une case � cocher <input type="checkbox" />
	 * @param id string id de la case � cocher
	 * @return object case � cocher
	 */
	function createCheckbox(id, title)
	{
		var checkbox = document.createElement('input');
		checkbox.type = 'checkbox';
		checkbox.id = id;
		checkbox.name = id;
		checkbox.title = title;

		return checkbox;
	}

	/**
	 * createLabel
	 * cr�e un libell� <label>
	 * @param id string id de la balise <label>
	 * @param contents string contenu de la balise <label>
	 * @return object label
	 */
	function createLabel(id, contents)
	{
		var label = document.createElement('label');
		label.htmlFor = id;
		label.appendChild(contents);

		return label;
	}

	/**
	 * createImg
	 * cr�e une image <img />
	 * @param path string Chemin de l'image
	 * @param alt string Texte alternatif de l'image
	 * @return object image
	 */
	function createImg(path, alt)
	{
		var img = document.createElement('img');
		img.src = path;
		img.alt = alt;
		img.title = alt;

		return img;
	}

	/**
	 * addSpace
	 * ajoute un ou des espaces ins�cables
	 * @param parent object Element parent contenant les espaces
	 * @param nbSpace integer Nombre d'espaces
	 */
	function addSpace(parent, nbSpace)
	{
		var space = document.createTextNode(createSpace(nbSpace));
		parent.appendChild(space);
	}

	/**
	 * createSpace
	 * cr�e un ou des espaces ins�cables
	 * @param nb integer nombre d'espace ins�cable
	 * @return string espace ins�cable
	 */
	function createSpace(nb)
	{
		var space = '';
		for (var i = 0; i < nb; i ++) {
			space += String.fromCharCode(160);
		}

		return space;
	}

	/**
	 * getInfos
	 * R�cup�re des informations d'une page html
	 * @param id string Identifiant du champ contenant les informations � r�cup�rer
	 * @param connector string Connecteur pour s�parer les infos dans le champ
	 * @return array tableau contenant contenant les informations � r�cup�rer
	 */
	function getInfos(id, connector)
	{
		if (document.getElementById(id)) {
			var infos = document.getElementById(id).value.split(connector);
		} else {
			var infos = new Array();
		}

		return infos;
	};

	/**
	 * addLoadListener
	 * ajoute une fonction au gestionnaire d'�v�nement onload
	 * @param func string nom de la fonction
	 */
	function addLoadListener(func)
	{
		if (window.addEventListener) {
			window.addEventListener("load", func, false);
		} else if (document.addEventListener) {
			document.addEventListener("load", func, false);
		} else if (window.attachEvent) {	// IE
			window.attachEvent("onload", func);
		} else if (typeof window.onload != "function") {	// Autres navigateurs
			window.onload = func;
		} else {
			var oldOnload = window.onload;
			window.onload = function()
			{
				oldOnload();
				func();
			}
		}
	}

	/**
	 * init
	 * initialisation des fonctions
	 */
	function init()
	{
		if (document.getElementById("tableDB")) {
			var table = document.getElementById("tableDB");
			var lang = getInfos("lang_maintain_js", "``");

			addCheckBoxActionsToTable(table, lang);
		}

	}

	// Ex�cution des fonctions
	if (document.getElementById && document.createElement && document.createTextNode) {
		addLoadListener(init);
	}

}) ();
