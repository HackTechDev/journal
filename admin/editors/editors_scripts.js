/**
 * Permet l'insertion des smileys de guppy dans l'�diteur
 * 
 * @param string Nom de l'�diteur
 * @param string Chemin du smiley
 * @param string Attribut alt
 * @param integer Largeur du smiley
 * @param integer Hauteur du smiley
 *
 * @return string
 */
function insert_smiley_in_editor(instanceName, src, alt, width, height)
{
    if (typeof(CKEDITOR) === 'object') {
        insert_smiley_in_CKEditor(instanceName, src, alt, width, height);
	} else if (typeof(FCKeditorAPI) === 'object') {
		insert_smiley_in_FCKEditor(instanceName, src, alt, width, height);
	} else {
	   return false;
	}
};

// --------------------------------------------------------------------

/**
 * Permet l'insertion des smileys de guppy dans l'�diteur CKEditor
 * 
 * @param string Nom de l'�diteur
 * @param string Chemin du smiley
 * @param string Attribut alt
 * @param integer Largeur du smiley
 * @param integer Hauteur du smiley
 * @return string
 */
function insert_smiley_in_CKEditor(instanceName, src, alt, width, height)
{
    var oEditor = CKEDITOR.instances[instanceName];
	
	if ( oEditor.mode == "wysiwyg") {
		var img = "<img src=\""+src+"\" alt=\""+alt+"\" style=\"width:"+width+"px; height:"+height+"px; border:0px solid;\" />";
        
        oEditor.insertHtml(img);
	} else {
		return false;
	}
};

// --------------------------------------------------------------------
