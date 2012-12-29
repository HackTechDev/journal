<?php
/*
     Plugin PostGuestEditor
	 Version  : 2.5.1 (2010/11/05)
	 Compatibility : Guppy v4.5.x et Guppy v4.6.x
	 Licence  : GNU Lesser General Public License
	 Author   : Jérôme CROUX (jchouix)
     Web site : http://lebrikabrak.info/
     E-mail   : jchouix@wanadoo.fr
*/

if (stristr($_SERVER['SCRIPT_NAME'], 'hu_pgeditor.inc')) {
  header('location:../index.php');
  die();
}

$version_pgeditor = "Verzió: 2.5.1";
$charset = 'iso-8859-2';

$lang_pgeditor[0]  = 'hu';
$lang_pgeditor[1]  = 'Bezár';
$lang_pgeditor[2]  = 'Szövegszín';
$lang_pgeditor[3]  = 'Háttérszín';
$lang_pgeditor[4]  = 'Félkövér';
$lang_pgeditor[5]  = 'Dõlt';
$lang_pgeditor[6]  = 'Aláhúzott';
$lang_pgeditor[7]  = 'Idézet beszúrása';
$lang_pgeditor[8]  = 'Kód beszúrása';
$lang_pgeditor[9]  = 'Balra zárás';
$lang_pgeditor[10] = 'Középre zárás';
$lang_pgeditor[11] = 'Jobbra zárás';
$lang_pgeditor[12] = 'Link beszúrása';
$lang_pgeditor[13] = 'Link törlése';
$lang_pgeditor[14] = 'Számozott lista';
$lang_pgeditor[15] = 'Felsorolás lista';
$lang_pgeditor[16] = 'Mégse';
$lang_pgeditor[17] = 'Mégis';
$lang_pgeditor[18] = 'Emotikon beszúrása (popup)';
$lang_pgeditor[19] = 'Elõnézet (popup)';
$lang_pgeditor[20] = 'HTML nézet';
$lang_pgeditor[21] = 'URL :';
$lang_pgeditor[22] = 'Szerzõ :';
$lang_pgeditor[23] = 'Idézet :'; //vigyázz, ide ne írj be semmilyen speciális karaktert
$lang_pgeditor[24] = 'Kód nyelv :';
$lang_pgeditor[25] = 'Kód :'; //vigyázz, ide ne írj be semmilyen speciális karaktert
$lang_pgeditor[26] = 'Kattints ide az Opera böngészõ 9-es verziójának hibaelhárításához';
$lang_pgeditor[27] = 'Súgó mutatása';
$lang_pgeditor[28] = 'Súgó elrejtése';
$lang_pgeditor[29] = 'Semmi';
$lang_pgeditor[30] = 'Szerkesztési zóna';
$lang_pgeditor[31] = 'Mehet';
$lang_pgeditor[32] = 'Mégse';
$lang_pgeditor[33] = 'egyéb...';
$lang_pgeditor[34] = 'Semmi';
$lang_pgeditor[35]  = 'Image beszúrása';

//Súgó
$lang_help_pgeditor[0] = 'Súgó :';
$lang_help_pgeditor[1] = 'További információk...';
//Szintaxis
$lang_help_pgeditor[2] = 'Kód szintaxis :';
$lang_help_pgeditor[3] = '<strong>&lt;color=<span class="tag_value">Hexadecimális kód</span>&gt;&lt;/color&gt;</strong> lehetõvé teszi a szövegszínezést.<br /><em>Megjegyzés :</em> A hexadecimális kód helyett (<span class="tag_value">#??????</span>), meg lehet adni a szín nevét is (angolul) (<span class="tag_value">red, yellow, orange, green, blue,</span> stb...).'.$lang_help_pgeditor[1];
$lang_help_pgeditor[4] = '<strong>&lt;bgcolor=<span class="tag_value">Hexadecimális kód</span>&gt;&lt;/bgcolor&gt;</strong> színnel történõ szövegkiemelést tesz lehetõvé.<br /><em>Megjegyzés :</em> A hexadecimális kód helyett (<span class="tag_value">#??????</span>), meg lehet adni a szín nevét is (angolul) (<span class="tag_value">red, yellow, orange, green, blue,</span> stb...).'.$lang_help_pgeditor[1];
$lang_help_pgeditor[5] = '<strong>&lt;b&gt;&lt;/b&gt;</strong> lehetõvé teszi a szöveg kövérítését.';
$lang_help_pgeditor[6] = '<strong>&lt;i&gt;&lt;/i&gt;</strong> dõlt betûssé teszi a szöveget.';
$lang_help_pgeditor[7] = '<strong>&lt;u&gt;&lt;/u&gt;</strong> aláhúzottá teszi a szöveget.';
$lang_help_pgeditor[8] = '<strong>&lt;cite&gt;&lt;/cite&gt;</strong> idézetet szúr be.<br /><em>Megjegyzés :</em> Megadható a szerzõ neve is a következõ módon <strong>&lt;cite<span class="tag_value">=Author</span>&gt;</strong>';
$lang_help_pgeditor[9] = '<strong>&lt;code&gt;&lt;/code&gt;</strong> lehetõvé teszi kód beszúrását.<br /><em>Megjegyzés :</em> Meg lehet adni a programnyelvet is a következõ módon <strong>&lt;code<span class="tag_value">=LanguageName</span>&gt;</strong>';
$lang_help_pgeditor[10] = '<strong>&lt;left&gt;&lt;/left&gt;</strong> balra igazítja a szöveget.';
$lang_help_pgeditor[11] = '<strong>&lt;center&gt;&lt;/center&gt;</strong> középre igazítja a szöveget.';
$lang_help_pgeditor[12] = '<strong>&lt;right&gt;&lt;/right&gt;</strong> jobbra igazítja a szöveget.';
$lang_help_pgeditor[13] = '<strong>&lt;link&gt;&lt;/link&gt;</strong> linket szúr be.<br /><em>Megjegyzés :</em> A link URL-ja a következõ módon is megadható <strong>&lt;link<span class="tag_value">=URL</span>&gt;text&lt;/link&gt;</strong>. Ha a link URL-je nincs megadva, az URL a két tag közötti lesz.<strong>&lt;link&gt;<span class="tag_value">URL</span>&lt;/link&gt;</strong>';
$lang_help_pgeditor[14] = '<strong>&lt;img=<span class="tag_value">SmileyName</span>&gt;</strong> lehetõvé teszi emotikon beszúrását.<br /><em>Megjegyzés :</em> A rendelkezésre álló alap-emotikonok nevei a következõk : <span class="tag_value">cool (klassz), wink (kacsintás), biggrin (nagy vigyor), smile (mosoly), frown (rosszall), eek (ijesztõ, ijedt), mad (dühös, v. õrült), confused (zavart), rolleyes (tágra nyílt szemek), tongue (nyelv, nyelvet ölt), cry (sír, sírás)</span>.'.$lang_help_pgeditor[1];
//Billentyûparancsok
$lang_help_pgeditor[15] = 'Billentyûparancsok (Windows alatt) :';
$lang_help_pgeditor[16] = 'Billentyû <strong>SHIFT + nyíl (jobb vagy bal)</strong> lehetõvé teszi a szövegkiválasztást';
$lang_help_pgeditor[17] = 'Billentyû <strong>ALT + 2</strong> lehetõvé teszi az eszközsáv kiválasztását';
$lang_help_pgeditor[18] = 'Billentyû <strong>ALT + 3</strong> lehetõvé teszi a szerkesztési zóna kiválasztását';
$lang_help_pgeditor[19] = 'Billentyû <strong>ALT + 4</strong> a Súgó-t mutatja';
$lang_help_pgeditor[20] = 'Billentyû <strong>ALT + 5</strong> elrejti a Súgó-t';
$lang_help_pgeditor[21] = 'Billentyû <strong>TAB</strong> egyik kiválasztott részrõl a másikra vált';
$lang_help_pgeditor[22] = 'Billentyû <strong>SHIFT + TAB</strong> a jelenlegi kiválasztásról az elõzõre vált';
$lang_help_pgeditor[23] = 'Billentyû <strong>ALT + nyíl (lefelé vagy felfelé)</strong> kibontja a kiválasztott menüt';
$lang_help_pgeditor[24] = 'Billentyû <strong>ALT + nyíl (lefelé vagy felfelé)</strong> összecsukja a kinyitott menüt';
$lang_help_pgeditor[25] = 'Billentyû <strong> nyíl (lefelé vagy felfelé)</strong> lehetõvé teszi a végighaladást a kinyitott menün';
$lang_help_pgeditor[26] = 'Billentyû <strong>ALT + s</strong> lehetõvé teszi az ûrlapküldést';
//
$lang_help_pgeditor[27] = 'Információ a Web színkódokról';
$lang_help_pgeditor[28] = 'Információ az emotikon beillesztõ kódokról';
$lang_help_pgeditor[29] = ' (megnyitás új ablakban)';

//Popup súgó a színbeszúráshoz
$lang_color_pgeditor[0] = 'Az alapszínek nevei (16 + 1), ahogy a W3C által a HTML-ben és a CSS 2.1-ben meg van határozva ';
$lang_color_pgeditor[1] = 'black (fekete)';
$lang_color_pgeditor[2] = 'gray (szürke)';
$lang_color_pgeditor[3] = 'silver (ezüst)';
$lang_color_pgeditor[4] = 'white (fehér)';
$lang_color_pgeditor[5] = 'maroon (gesztenyebarna)';
$lang_color_pgeditor[6] = 'red (vörös, piros)';
$lang_color_pgeditor[7] = 'orange (narancssárga)';
$lang_color_pgeditor[8] = 'yellow (sárga)';
$lang_color_pgeditor[9] = 'lime (világoszöld)';
$lang_color_pgeditor[10] = 'green (zöld)';
$lang_color_pgeditor[11] = 'olive (barnászöld)';
$lang_color_pgeditor[12] = 'aqua (kékeszöld)';
$lang_color_pgeditor[13] = 'blue (kék)';
$lang_color_pgeditor[14] = 'teal (sötétzöld)';
$lang_color_pgeditor[15] = 'navy (sötétkék, tengerkék)';
$lang_color_pgeditor[16] = 'fuchsia (vöröseslila)';
$lang_color_pgeditor[17] = 'purple (bíborlila)';
$lang_color_pgeditor[18] = 'A webszínek neve';
$lang_color_pgeditor[19] = 'A szín HTML neve';
$lang_color_pgeditor[20] = 'Hexadecimális kód';
$lang_color_pgeditor[21] = 'Megtekintés';
$lang_color_pgeditor[22] = 'fordítás';
$lang_color_pgeditor[23] = 'A 140 "nemhivatalos" webszín neve';
$lang_color_pgeditor[24] = '<span class="warning">Legyél óvatos :</span> ezek a színnevek a következõ böngészõk által felismertek : Netscape 2.0+, Internet Explorer 3.0+ valamint a legtöbb modern böngészõ (Firefox, Safari, stb...) de a támogatásuk nem minden böngészõ által garantált, mert ezek a színnevek nem szerepelnek a W3C hivatalos javaslataiban.';

//Popup súgó az emotikonok beszúrásához
$lang_smiley_pgeditor[0] = 'Emotikon nevek';
$lang_smiley_pgeditor[1] = 'klassz (cool)';
$lang_smiley_pgeditor[2] = 'kacsintás (wink)';
$lang_smiley_pgeditor[3] = 'nagy vigyor (biggrin)';
$lang_smiley_pgeditor[4] = 'mosoly (smile)';
$lang_smiley_pgeditor[5] = 'rosszall (frown)';
$lang_smiley_pgeditor[6] = 'ijedt (eek)';
$lang_smiley_pgeditor[7] = 'dühös (mad)';
$lang_smiley_pgeditor[8] = 'zavart (confused)';
$lang_smiley_pgeditor[9] = 'kerek szemek (rolleyes)';
$lang_smiley_pgeditor[10] = 'nyelv (tongue)';
$lang_smiley_pgeditor[11] = 'sírás (cry)';
$lang_smiley_pgeditor[12] = 'Guppy alap-emotikonok';
$lang_smiley_pgeditor[13] = 'Emotikon neve';
$lang_smiley_pgeditor[14] = 'Emotikon beszúrás kódja';
$lang_smiley_pgeditor[15] = 'Megtekintés';
$lang_smiley_pgeditor[16] = 'A többi rendelkezésre álló emotikon';
?>