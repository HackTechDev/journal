/*
    Hpage Javascript - GuppY PHP Script -
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.5 (20 March 2005)        : initial release (by Jean-Mi)
      v4.6.6 (14 April 2008)      : corrected DesactiveMenu() (by jchouix)
      v4.6.9 (25 December 2008)   : improvement function "Add to the favourites" (suggestions box #156)
*/

var lgtexte=texte.length-1;
var postexte=0;

if (window!=top) {
  top.location=window.location;
}

function msgdefil() {
  if (postexte == texte.length) {
    postexte=0;
  }
  if (postexte<=lgtexte) {
    afftexte = texte.substring((texte.length -(lgtexte-postexte)), texte.length) + texte.substring(0, postexte);
    postexte++;
  }
  window.status = afftexte;
  vitessedefil = setTimeout("msgdefil()", 150);
}


function WriteMailTo(empseudo,emname,emdomain,emext) {
  var hauteur = 112;
  var largeur = 300;
  var top=(screen.height-hauteur)/2;
  var left=(screen.width-largeur)/2;
  if (empseudo == "") {
    empseudo = emname + "@" + emdomain + "." + emext;
  }
  fenetremail = window.open("", "",
    "top=" + top +
    ", left=" + left +
    ", width=" + largeur +
    ", height=" + hauteur +
    ", directories=no, menubar=no, status=no, resizable=no, location=no");
  fenetreNote = fenetremail;
  if (fenetreNote != null) {
    docmail = fenetremail.document;
    textemail = '<html><head><title>email</title><meta http-equiv="Content-Type" content="text/html; charset="' + charset + '" ></head><body onblur="javascript:setTimeout(\'window.close();\',5000);" style="margin: 5px; background-color:<?php echo $forum[0]; ?>; color: <?php echo $texte[0] ?>; overflow: hidden;"><div align="center"><br /><?php echo $web173; ?> <b>' + empseudo + '</b> :<br /><br /><a ' + ' h' + 're' + 'f="' + 'ma' + 'il' + 'to' + ':' + emname + '@' + emdomain + '.' + emext + '">' + emname + '@' + emdomain + '.' + emext + '</a><br /><br /></div></body></html>';
    docmail.write(textemail);
    docmail.close();
  }
}

function ContactMe(ircsoft,ircpseudo,ircname,ircdomain,ircext) {
  var hauteur = 112;
  var largeur = 360;
  var top=(screen.height-hauteur)/2;
  var left=(screen.width-largeur)/2;
  if (ircext != "") {
    ircext = "." + ircext;
  }
  if (ircdomain != "") {
    ircdomain = "@" + ircdomain;
  }
  ircident = ircname + ircdomain + ircext;
  switch(ircsoft){
  case "ICQ": ircsite = "http://www.icq.com/people/webmsg.php?to=" + ircident;
  break;
  case "MSN": ircsite = "msnim:chat?contact=" + ircident;
  break;
  case "Yahoo": ircsite = "ymsgr:sendim?" + ircident;
  break;
  case "Gtalk": ircsite = "http://mail.google.com/mail/";
  break;
  case "Skype": ircsite = "skype:" + ircident + "?call";
  break;
  case "AIM": ircsite = "aim:goim?screenname=" + ircident;
  break;
  case "Teamspeak": ircsite = "teamspeak://" + ircident;
  break;
  }
  fenetremail = window.open("", "",
    "top=" + top +
    ", left=" + left +
    ", width=" + largeur +
    ", height=" + hauteur +
    ", directories=no, menubar=no, status=no, resizable=no, location=no");
  fenetreNote = fenetremail;
  if (fenetreNote != null) {
    docmail = fenetremail.document;
    textemail = '<html><head><title>email</title><meta http-equiv="Content-Type" content="text/html; charset="' + charset + '" ></head><body onblur="javascript:setTimeout(\'window.close();\',5000);" style="margin: 5px; background-color:<?php echo $forum[0]; ?>; color: <?php echo $texte[0] ?>; overflow: hidden;"><div align="center"><br /><?php echo $web173; ?> <b> ' + ircpseudo + ' via ' + ircsoft + '</b> :<br /><br /><br />';
    textemail +='<a href="' + ircsite + '">' + ircident + '</a>';
    textemail +='</div></body></html>';
    docmail.write(textemail);
    docmail.close();
  }
}
function AddFavo() {
  if (window.sidebar) {
    window.sidebar.addPanel(site0, site3, '');
  }
  else if (window.external) {
    window.external.AddFavorite(site3, site0);
  }
  else {
    return true;
  }
}

function PopupWindow(page, titre, largeur, hauteur, resizeyn, scrollb) {
  var top=(screen.height-hauteur)/2;
  var left=(screen.width-largeur)/2;
  window.open(page, titre,
    "top=" + top +
    ", left=" + left +
    ", width=" + largeur +
    ", height=" + hauteur +
    ", directories=no, menubar=no, status=no, resizable=" + resizeyn +
    ", scrollbars=" +scrollb +
    ",location=no");
}

function hideLoadingPage() {
  if (document.getElementById) {
    document.getElementById('hidepage').style.visibility = 'hidden';
  }
  else {
    if (document.layers) {
      document.hidepage.visibility = 'hidden';
    }
    else {
      document.all.hidepage.style.visibility = 'hidden';
    }
  }
}

//FONCTION POUR DOWNLOAD FAQ LINK et BOX ARTICLES
function MontreCacheItems(idImgOpen,idImgClose,idDivItems,idMenuSelect) {
	if((document.getElementById && document.getElementById(idImgOpen).style.display == 'inline') || (document.all && document.all[idImgOpen].style.display == 'inline') || (document.layers && document.layers[idImgOpen].display == 'inline') ) {
		cache(idImgOpen);
		montre(idImgClose,'inline');
		if((document.getElementById && document.getElementById(idDivItems) != null) || (document.all && document.all[idDivItems] != undefined ) || (document.layers && document.layers[idDivItems] != undefined) ) {
			montre(idDivItems,'block');
		} else {
			montre(idMenuSelect,'block');
		}
	} else {
		cache(idImgClose);
		montre(idImgOpen,'inline');
		if((document.getElementById && document.getElementById(idDivItems) != null) || (document.all && document.all[idDivItems] != undefined ) || (document.layers && document.layers[idDivItems] != undefined) ) {
			cache(idDivItems);
		} else {
			cache(idMenuSelect);
		}
	}
}

function montre(id, display) {
  	if (display != 'block' && display != 'inline') display = 'block';
  	if (document.getElementById) {
    	document.getElementById(id).style.display = display;
  	} else if (document.all) {
    	document.all[id].style.display = display;
  	} else if (document.layers) {
    	document.layers[id].display = display;
  	}
}

function cache(id) {
  if (document.getElementById) {
    document.getElementById(id).style.display = 'none';
  }
  else if (document.all) {
    document.all[id].style.display = 'none';
  }
  else if (document.layers) {
    document.layers[id].display = 'none';
  }
}

function ToggleValue(id) {
  if (document.getElementById) {
    document.getElementById(id).value = document.getElementById(id).value == "on" ? "" : "on";
  }
  else if (document.all) {
    document.all[id].value = document.all[id].value == "on" ? "" : "on";
  }
  else if (document.layers) {
    document.layers[id].value = document.layers[id].value == "on" ? "" : "on";
  }
}

function submenu(id) {
  	if (document.all) {
    	for (i=1; i<=maxsub; i++) {
      		menu = document.all['sub'+i];
     		if (i != id)
        		menu.style.display = "none";
      		else
        		menu.style.display = "block";
    		}
  	} else if (document.getElementById) {
      	for (i=1; i<=maxsub; i++) {
        	menu = document.getElementById('sub'+i);
        	if (i != id)
          		menu.style.display = "none";
        	else
          		menu.style.display = "block";
      	}
    }
}

///
/// items_off = prefixe des blocs affichant l'etat "off"
/// items_on  = prefixe des blocs affichant l'etat "on"
/// min_items = indice minimale des blocs présents dans la page
/// nbr_items = nombre de blocs présents dans la page
/// active_item = indice de l'item a activer ou desactiver
/// display = 'block' ou 'inline'
///

function ActiveMenu(items_off, items_on, min_items, nbr_items, active_item, display) {
	DesactiveMenu(items_off, items_on, min_items, nbr_items, display)
	ActiveItem(items_off, items_on, active_item, display);
}

function DesactiveMenu(items_off, items_on, min_items, nbr_items, display) {
    for (i = min_items; i < min_items + nbr_items; i++) {
        if (document.getElementById(items_on + i) && document.getElementById(items_off + i)) {
            cache(items_on + i);
            montre(items_off + i, display);
        }
    }
}

function ActiveItem(items_off, items_on, active_item, display) {
	cache(items_off + active_item);
	montre(items_on + active_item, display);
}

function DesactiveItem(items_off, items_on, active_item, display) {
	cache(items_on + active_item);
	montre(items_off + active_item, display);
}


