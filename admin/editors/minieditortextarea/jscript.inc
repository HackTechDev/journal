<?php
/*
     MinieditorTextarea réalisé par Djchouix - Licence CeCILL
     Web site = http://lebrikabrak.free.fr/
     e-mail   = lebrikabrak@free.fr
	 version 1.6 (24 février 2006) compatibilité avec guppy v4.5.x
     v4.6.10 (7 September 2009)    : corrected #272
*/
if (stristr($_SERVER["SCRIPT_NAME"], "jscript.inc")) {
  header("location:../index.php");
  die();
}

include(CHEMIN."data/config.inc"); //config guppy pour récupérer valeur $site[3]
$pathDirMinieditor = 'admin/editors/';    //chemin relatif du répertoire du miniéditeur (à ne pas modifier pour ne pas perdre la compatibilité avec les autres plugins)
if(!preg_match("!^[a-z]{2,3}$!i",$lng)) die("Erreur dans le nom de la variable de langue!!");

if(file_exists(CHEMIN.$pathDirMinieditor.'minieditortextarea/lang/'.$lng.'_minieditortextarea.inc')) {
	include(CHEMIN.$pathDirMinieditor.'minieditortextarea/lang/'.$lng.'_minieditortextarea.inc'); //FICHIER DE LANGUE
} else {
	include(CHEMIN.$pathDirMinieditor.'minieditortextarea/lang/en_minieditortextarea.inc'); //FICHIER DE LANGUE PAR DEFAUT
}
?>
<script type="text/javascript">
//fonction qui permet de sélectionner un texte (IE et Opera 8)  
var textselec = ''; //variable globale texte sélectionné

function selectext(nameform,nametextarea) {
  	if (document.selection) {
    	document.forms[nameform].elements[nametextarea].focus();
		objetselection = document.selection.createRange();
    	textselec = objetselection.text;
    }
}

//Fonction qui permet de récupérer la position du curseur
var g_posCurseur; // variable global position du curseur
 
function getPosCurseur(oTextArea) {
   var sAncienTexte = oTextArea.value; //sauvegarde contenu textarea
   //création objet TextRange et sauvegarde du texte avant modification
   var oRange = document.selection.createRange();
   var sAncRangeTexte = oRange.text;
   //construction marque (text qui ne doit pas déjà exiter dans textarea !)
   var sMarquer = String.fromCharCode(28) + String.fromCharCode(29) + String.fromCharCode(30); 
   //insertion texte+marque de l'objet TextRange à la position du curseur
   oRange.text = sAncRangeTexte + sMarquer; 
   oRange.moveStart('character', (0 - sAncRangeTexte.length - sMarquer.length));
   var sNouvTexte = oTextArea.value; //sauvegarde nouveau contenu textarea  
   oRange.text = sAncRangeTexte; //restauration ancienne valeur objet TextRange 
   //recherche chaîne de marquage et renvoie la position
   for (i=0; i <= sNouvTexte.length; i++) {
     var sTemp = sNouvTexte.substring(i, i + sMarquer.length);
     if (sTemp == sMarquer) {
       var cursorPos = (i - sAncRangeTexte.length);
       return cursorPos;
     }
   }
 }

//Fonction qui permet de récupérer le texte sélectionné (nécessaire pour OPERA 8 AVEC POPUP)
function getselectionOpera(nameform,nametextarea) {
		var x = textselec.length;
		var nb_caract =''
		for(i = 0; i < x; i++) {
			nb_caract += 'A'; 
		}
		document.getElementById('nb_caract').value = nb_caract;
		
		g_posCurseur = getPosCurseur(document.forms[nameform].elements[nametextarea]); //Récupération de la position du curseur
		var y =''
		for(i = 0; i < g_posCurseur; i++) {
			y += 'A'; 
		}
		document.getElementById('pos_cursor').value = y;
}

//fonction qui permet d'insérer un code
function AddCode(code1,code2,nameform,nametextarea) {
	var textarea = document.forms[nameform].elements[nametextarea];
  	//IE et OPERA 8
	if (document.selection) {
    	objetselection.text = code1 + textselec + code2;
  	}  
	//MOZILLA 1.7.x/FIREFOX 1.x/NETSCAPE 7.1+
	else if (textarea.selectionStart || textarea.selectionStart == 0) {
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
        var chaine = textarea.value;
		var message = (code2 == '')? '' :  '<?php echo $lang_minieditor[38]; ?>';
        textarea.value = chaine + code1 + message + code2;
	}
	textarea.focus();
    return;	
}

//fonction pour formatter un texte
function AddFormat(balise,style,nameform,nametextarea) {
	if (balise == 'br' || balise == 'hr' || balise == 'img' || balise == 'input' || balise == 'embed' || balise == 'area') {
		var code1 ='<' + balise + ' \/>';
		var code2 ='';
	} else if (style == '') {
    	var code1 = '<' + balise + '>';
		var code2 ='<\/' + balise + '>';	
	} else {
    	var code1 = '<' + balise + ' style="' + style + ';">';
		var code2 ='<\/' + balise + '>';
	}
	AddCode(code1,code2,nameform,nametextarea);
	document.forms[nameform].elements[nametextarea].focus();
}

//Fonction pour insérer balise HTML via menu
function AddBalise(nameselect,nameform,nametextarea) {
	var id = document.forms[nameform].elements[nameselect].selectedIndex;
	var balise = document.forms[nameform].elements[nameselect].options[id].value;
	if(balise != '') {
		balise = balise.toLowerCase();
		if (balise == 'br' || balise == 'hr' || balise == 'img' || balise == 'input' || balise == 'embed' || balise == 'area') {
			var code1 ='<' + balise + ' \/>';
			var code2 ='';
		} else {
			var code1 ='<' + balise + '>';
			var code2 ='<\/' + balise + '>';		
		}
		AddCode(code1,code2,nameform,nametextarea);
	}
	document.forms[nameform].elements[nameselect].value = document.forms[nameform].elements[nameselect].options[0].value;
	document.forms[nameform].elements[nametextarea].focus();
}

//Fonction pour insérer type et taille de la police via menu
function AddFont(nameselect,nameform,nametextarea) {
	var id = document.forms[nameform].elements[nameselect].selectedIndex;
	var style = document.forms[nameform].elements[nameselect].options[id].value;
	if(style != '') {
		var code1 ='<span style="' + style + ';">';
		var code2 ='<\/span>';
		AddCode(code1,code2,nameform,nametextarea);
	}
	document.forms[nameform].elements[nameselect].value = document.forms[nameform].elements[nameselect].options[0].value;
	document.forms[nameform].elements[nametextarea].focus();
}

//Fonction pour insérer class CSS via menu
function AddCSS(nameselect,nameform,nametextarea) {
	var id = document.forms[nameform].elements[nameselect].selectedIndex;
	var nameclass = document.forms[nameform].elements[nameselect].options[id].value;
	var code1 = ' class="' + nameclass + '" ';
	var code2 ='';
	if(nameclass != '') {
		AddCode(code1,code2,nameform,nametextarea);
	}
	document.forms[nameform].elements[nameselect].value = document.forms[nameform].elements[nameselect].options[0].value;
	document.forms[nameform].elements[nametextarea].focus();
}

//Fonction pour insérer smiley de guppy
function AddSmiley(chemin,largeur,hauteur,alt,nameform,nametextarea) {
    var code1 = '<img src="'+ chemin +'" width="'+ largeur +'" height="'+ hauteur +'" alt="'+ alt +'" border="0" \/>';
	var code2 ='';
	AddCode(code1,code2,nameform,nametextarea);
	document.forms[nameform].elements[nametextarea].focus();
}

//Fonction pour changer le chemin (relatif, absolu) des src et des href
function ChangeURLPath(nameselect,nameform,nametextarea) {
	id = document.forms[nameform].elements[nameselect].selectedIndex;
	chemin = document.forms[nameform].elements[nameselect].options[id].value;
	editorvalue = document.forms[nameform].elements[nametextarea].value;
	
	switch(chemin) {
		case 'relatif' :
		<?php		
			function expRegExpression($expression) {
				$chaine = $expression;
				$expRegMetaCar = array('\\','^','$','.','*','+','?','=','!','|','/','(',')','[',']','{','}');
				for($i=0; $i<count($expRegMetaCar); $i++) {
					$chaine =  str_replace($expRegMetaCar[$i],'\\'.$expRegMetaCar[$i],$chaine);
				}
				return $chaine;
			}
			$expRegURLSite = expRegExpression($site[3]);
			echo 'editorvalue = editorvalue.replace (/(src=\"'.$expRegURLSite.')/gi,"src=\"");'."\n"; 
			echo 'editorvalue = editorvalue.replace (/(href=\"'.$expRegURLSite.')/gi,"href=\"");'."\n"; 
			echo 'editorvalue = editorvalue.replace (/(value=\"'.$expRegURLSite.')/gi,"value=\"");'."\n"; 
			echo 'editorvalue = editorvalue.replace (/(data=\"'.$expRegURLSite.')/gi,"data=\"");'."\n"; 
		?>
		break;
		case 'absolu' :
		<?php
			echo 'var IPATH = "'.$site[3].'";'."\n";
			echo 'editorvalue = editorvalue.replace (/src=\"inc\//gi,"src=\"" + IPATH + "inc\/");'."\n";
			echo 'editorvalue = editorvalue.replace (/href=\"inc\//gi,"href=\"" + IPATH + "inc\/");'."\n";
			foreach($nameRepPath as $nameRepUp) {
				if(!preg_match('!^[-a-z0-9_]+$!i',$nameRepUp)) die($lang_minieditor[61]);
				echo 'editorvalue = editorvalue.replace (/src=\"'.$nameRepUp.'\//gi,"src=\"" + IPATH + "'.$nameRepUp.'\/");'."\n"; 		
				echo 'editorvalue = editorvalue.replace (/href=\"'.$nameRepUp.'\//gi,"href=\"" + IPATH + "'.$nameRepUp.'\/");'."\n"; 		
				echo 'editorvalue = editorvalue.replace (/value=\"'.$nameRepUp.'\//gi,"value=\"" + IPATH + "'.$nameRepUp.'\/");'."\n"; 		
				echo 'editorvalue = editorvalue.replace (/data=\"'.$nameRepUp.'\//gi,"data=\"" + IPATH + "'.$nameRepUp.'\/");'."\n";
			}
		?>
		break;
		default :
			return;	
	}	
	document.forms[nameform].elements[nameselect].value = document.forms[nameform].elements[nameselect].options[0].value;
	document.forms[nameform].elements[nametextarea].value = editorvalue;
	document.forms[nameform].elements[nametextarea].focus();
}

//Popup du miniéditeur
function popup_minieditortextarea(URL,title,largeur,hauteur,resizable,scrollbars,nameform,nametextarea) {
    //Debut modif pour opera 8 qui perd la sélection lors du click
   	if (document.selection) { 	
		getselectionOpera(nameform,nametextarea);
    }  
	//Fin modif pour opera 8 qui perd perd la sélection lors du click
	
	//Ouverture de la popup
    var top=(screen.height-hauteur)/2;
    var left=(screen.width-largeur)/2;
    window.open(URL, title, 'top='+top+', left='+left+', width='+largeur+', height='+hauteur+', resizable='+resizable+', scrollbars='+scrollbars+',menubar=no,location=no,directories=no,status=no,copyhistory=no,toolbar=no');
}

//Fonction pour tout effacer
function NewPage(nameform,nametextarea) {
	document.forms[nameform].elements[nametextarea].value = '';
}

//Afficher élément survolé
function MouseOverFile(id,color) {
	document.getElementById(id).style.backgroundColor = color;
}
</script>
