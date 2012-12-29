<?php
/*
     Plugin PostGuestEditor
	 Version  : 2.5.1 (2010/11/05)
	 Compatibility : Guppy v4.5.x
	 Licence  : GNU Lesser General Public License
	 Author   : Jérôme CROUX (Djchouix)
     Web site : http://lebrikabrak.info/
     E-mail   : jchouix@wanadoo.fr
	 
     Slovenian language pack 
      v4.5.x : by Stane Accetto, SI
      e-mail: = stane.accetto@siol.net          
*/

if (stristr($_SERVER['SCRIPT_NAME'], 'sl_pgeditor.inc')) {
  header('location:../index.php');
  die();
}

$version_pgeditor = "Version 2.5.1";
$charset = "windows-1250";

$lang_pgeditor[0]  = 'sl';
$lang_pgeditor[1]  = 'Zapri';
$lang_pgeditor[2]  = 'Barva besedila';
$lang_pgeditor[3]  = 'Barva ozadja';
$lang_pgeditor[4]  = 'Krepko';
$lang_pgeditor[5]  = 'Poševno';
$lang_pgeditor[6]  = 'Podèrtano';
$lang_pgeditor[7]  = 'Vstavitev navedbe';
$lang_pgeditor[8]  = 'Vstavitev kode';
$lang_pgeditor[9]  = 'Poravnava levo';
$lang_pgeditor[10] = 'Sredinska poravnava';
$lang_pgeditor[11] = 'Poravnava desno';
$lang_pgeditor[12] = 'Vstavi povezavo';
$lang_pgeditor[13] = 'Izbris povezave';
$lang_pgeditor[14] = 'Oštevilèen seznam';
$lang_pgeditor[15] = 'Pikèasti seznam';
$lang_pgeditor[16] = 'Undo';
$lang_pgeditor[17] = 'Redo';
$lang_pgeditor[18] = 'Vstavi smeška (popup)';
$lang_pgeditor[19] = 'Predpregled (popup)';
$lang_pgeditor[20] = 'Pogled HTML';
$lang_pgeditor[21] = 'URL :';
$lang_pgeditor[22] = 'Avtor :';
$lang_pgeditor[23] = 'Navedba :'; //pazite, da ne boste uporabili posebne znake
$lang_pgeditor[24] = 'Jezikovna koda :';
$lang_pgeditor[25] = 'Koda :';//pazite, da ne boste uporabili posebne znake
$lang_pgeditor[26] = 'Kliknite, da odpravite hrošèa v brskalniku Opera 9';
$lang_pgeditor[27] = 'Prikaz pomoèi';
$lang_pgeditor[28] = 'Skrivanje pomoèi';
$lang_pgeditor[29] = 'Niè';
$lang_pgeditor[30] = 'Obmoèje urejanja';
$lang_pgeditor[31] = 'Ok';
$lang_pgeditor[32] = 'Briši';
$lang_pgeditor[33] = 'drugo...';
$lang_pgeditor[34] = 'Niè';
$lang_pgeditor[35] = 'Vstavi image';

//Help
$lang_help_pgeditor[0] = 'Pomoè :';
$lang_help_pgeditor[1] = 'Za dodatni info...';
//Syntax
$lang_help_pgeditor[2] = 'Sintaksa kode :';
$lang_help_pgeditor[3] = '<strong>&lt;color=<span class="tag_value">CodeHexadecimal</span>&gt;&lt;/color&gt;</strong> omogoèi barvanje besedila.<br /><em>Opomba :</em> Namesto heksadecimalne kode (<span class="tag_value">#??????</span>), lahko izberete ime barve(<span class="tag_value">red, yellow, orange, green, blue,</span> etc...).'.$lang_help_pgeditor[1];
$lang_help_pgeditor[4] = '<strong>&lt;bgcolor=<span class="tag_value">CodeHexadecimal</span>&gt;&lt;/bgcolor&gt;</strong> omogoèi posvetlitev besedila v barvi.<br /><em>Opomba :</em> Namesto heksadecimalne kode (<span class="tag_value">#??????</span>), lahko izberete ime barve(<span class="tag_value">red, yellow, orange, green, blue,</span> etc...).'.$lang_help_pgeditor[1];
$lang_help_pgeditor[5] = '<strong>&lt;b&gt;&lt;/b&gt;</strong> omogoèi odebelitev besedila.';
$lang_help_pgeditor[6] = '<strong>&lt;i&gt;&lt;/i&gt;</strong> omogoèi poševno besedilo.';
$lang_help_pgeditor[7] = '<strong>&lt;u&gt;&lt;/u&gt;</strong> omogoèi podèrtano besedilo.';
$lang_help_pgeditor[8] = '<strong>&lt;cite&gt;&lt;/cite&gt;</strong> omogoèi vstavljanje navedbe.<br /><em>Opomba :</em> Lahko doloèite ime avtorja z vnosomY <strong>&lt;cite<span class="tag_value">=Author</span>&gt;</strong>';
$lang_help_pgeditor[9] = '<strong>&lt;code&gt;&lt;/code&gt;</strong> omogoèi vnos kode.<br /><em>Opomba :</em> Lahko doloèite jezik z vnosom <strong>&lt;code<span class="tag_value">=LanguageName</span>&gt;</strong>';
$lang_help_pgeditor[10] = '<strong>&lt;left&gt;&lt;/left&gt;</strong> omogoèi levo poravnavo.';
$lang_help_pgeditor[11] = '<strong>&lt;center&gt;&lt;/center&gt;</strong> omogoèi sredinsko poravnavo.';
$lang_help_pgeditor[12] = '<strong>&lt;right&gt;&lt;/right&gt;</strong> omogoèi desno poravnavo.';
$lang_help_pgeditor[13] = '<strong>&lt;link&gt;&lt;/link&gt;</strong> omogoèi vnos povezave.<br /><em>Opomba :</em> Lahko doloèite URL povezavo z vnosom <strong>&lt;link<span class="tag_value">=URL</span>&gt;text&lt;/link&gt;</strong>. Èe ne doloèite URL povezave, bo URL med dvema oznakama.<strong>&lt;link&gt;<span class="tag_value">URL</span>&lt;/link&gt;</strong>';
$lang_help_pgeditor[14] = '<strong>&lt;img=<span class="tag_value">SmileyName</span>&gt;</strong> omogoèi vnos smeška.<br /><em>Opomba :</em> Imena osnovnih smeškov so: <span class="tag_value">cool, wink, biggrin, smile, frown, eek, mad, confused, rolleyes, tongue, cry</span>.'.$lang_help_pgeditor[1];
//Access keys
$lang_help_pgeditor[15] = 'Access keys (under Windows) :';
$lang_help_pgeditor[16] = 'Key <strong>SHIFT + arrow (right or left)</strong> enables text selection';
$lang_help_pgeditor[17] = 'Key <strong>ALT + 2</strong> enables toolbar selection';
$lang_help_pgeditor[18] = 'Key <strong>ALT + 3</strong> enables editing zone selection';
$lang_help_pgeditor[19] = 'Key <strong>ALT + 4</strong> displays Help';
$lang_help_pgeditor[20] = 'Key <strong>ALT + 5</strong> hides Help';
$lang_help_pgeditor[21] = 'Key <strong>TAB</strong> enables going from one selection to the next';
$lang_help_pgeditor[22] = 'Key <strong>SHIFT + TAB</strong> enables going from one selection to the previous';
$lang_help_pgeditor[23] = 'Key <strong>ALT + arrow (towards bottom or top)</strong> enables folding out of the selected menu';
$lang_help_pgeditor[24] = 'Key <strong>ALT + arrow (towards bottom or top)</strong> enables the folding up of a spread out menu';
$lang_help_pgeditor[25] = 'Key <strong> arrow (towards bottom or top)</strong> enables the browsing through a spread out menu';
$lang_help_pgeditor[26] = 'Key <strong>ALT + s</strong> enables form sending';
//
$lang_help_pgeditor[27] = 'Informacije o kodah barv za web';
$lang_help_pgeditor[28] = 'Informacije o vstavljanju kode smeška';
$lang_help_pgeditor[29] = ' (odpri v novem oknu)';

//Popup Help with Color insertion
$lang_color_pgeditor[0] = 'Imena (16 + 1) osnovnih barv za HTML in CSS 2.1 kot jih navaja W3C';
$lang_color_pgeditor[1] = 'èrna';
$lang_color_pgeditor[2] = 'siva';
$lang_color_pgeditor[3] = 'srebrna';
$lang_color_pgeditor[4] = 'bela';
$lang_color_pgeditor[5] = 'kostanjeva';
$lang_color_pgeditor[6] = 'rdeèa';
$lang_color_pgeditor[7] = 'oranžna';
$lang_color_pgeditor[8] = 'rumena';
$lang_color_pgeditor[9] = 'limonska';
$lang_color_pgeditor[10] = 'zelena';
$lang_color_pgeditor[11] = 'olivna';
$lang_color_pgeditor[12] = 'vodena';
$lang_color_pgeditor[13] = 'modra';
$lang_color_pgeditor[14] = 'teal';
$lang_color_pgeditor[15] = 'mornarska';
$lang_color_pgeditor[16] = 'fuksija';
$lang_color_pgeditor[17] = 'rožnata';
$lang_color_pgeditor[18] = 'Ime barv za splet';
$lang_color_pgeditor[19] = 'HTML ime barve';
$lang_color_pgeditor[20] = 'Heksadecimalna koda';
$lang_color_pgeditor[21] = 'Vpogled';
$lang_color_pgeditor[22] = 'prevod';
$lang_color_pgeditor[23] = 'Imena 140 "neuradnih" barv za splet';
$lang_color_pgeditor[24] = '<span class="opozorilo">Bodite previdni :</span> imena teh barv podpirajo brskalniki : Netscape 2.0+, Internet Explorer 3.0+ pravtako veèina modernih (Firefox, Safari, itd...) toda njihova podpora ni zagotovljena za vsak standard glede na brskalnik, kajti ta niso vkljuèena v uradna priporoèila W3C.';

//Popup Help with Smiley insertion
$lang_smiley_pgeditor[0] = 'Imena smeškov';
$lang_smiley_pgeditor[1] = 'smeško cool';
$lang_smiley_pgeditor[2] = 'smeško wink';
$lang_smiley_pgeditor[3] = 'smeško biggrin';
$lang_smiley_pgeditor[4] = 'smeško smile';
$lang_smiley_pgeditor[5] = 'smeško frown';
$lang_smiley_pgeditor[6] = 'smeško eek';
$lang_smiley_pgeditor[7] = 'smeško mad';
$lang_smiley_pgeditor[8] = 'smeško confused';
$lang_smiley_pgeditor[9] = 'smeško rolleyes';
$lang_smiley_pgeditor[10] = 'smeško tongue';
$lang_smiley_pgeditor[11] = 'smeško cry';
$lang_smiley_pgeditor[12] = 'Osnovni Guppy smeški';
$lang_smiley_pgeditor[13] = 'Ime smeška';
$lang_smiley_pgeditor[14] = 'Vstavljanje kode smeška';
$lang_smiley_pgeditor[15] = 'Vpogled';
$lang_smiley_pgeditor[16] = 'Ostali dostopni smeški';
?>