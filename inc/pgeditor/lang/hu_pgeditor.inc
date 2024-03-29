<?php
/*
     Plugin PostGuestEditor
	 Version  : 2.5.1 (2010/11/05)
	 Compatibility : Guppy v4.5.x et Guppy v4.6.x
	 Licence  : GNU Lesser General Public License
	 Author   : J�r�me CROUX (jchouix)
     Web site : http://lebrikabrak.info/
     E-mail   : jchouix@wanadoo.fr
*/

if (stristr($_SERVER['SCRIPT_NAME'], 'hu_pgeditor.inc')) {
  header('location:../index.php');
  die();
}

$version_pgeditor = "Verzi�: 2.5.1";
$charset = 'iso-8859-2';

$lang_pgeditor[0]  = 'hu';
$lang_pgeditor[1]  = 'Bez�r';
$lang_pgeditor[2]  = 'Sz�vegsz�n';
$lang_pgeditor[3]  = 'H�tt�rsz�n';
$lang_pgeditor[4]  = 'F�lk�v�r';
$lang_pgeditor[5]  = 'D�lt';
$lang_pgeditor[6]  = 'Al�h�zott';
$lang_pgeditor[7]  = 'Id�zet besz�r�sa';
$lang_pgeditor[8]  = 'K�d besz�r�sa';
$lang_pgeditor[9]  = 'Balra z�r�s';
$lang_pgeditor[10] = 'K�z�pre z�r�s';
$lang_pgeditor[11] = 'Jobbra z�r�s';
$lang_pgeditor[12] = 'Link besz�r�sa';
$lang_pgeditor[13] = 'Link t�rl�se';
$lang_pgeditor[14] = 'Sz�mozott lista';
$lang_pgeditor[15] = 'Felsorol�s lista';
$lang_pgeditor[16] = 'M�gse';
$lang_pgeditor[17] = 'M�gis';
$lang_pgeditor[18] = 'Emotikon besz�r�sa (popup)';
$lang_pgeditor[19] = 'El�n�zet (popup)';
$lang_pgeditor[20] = 'HTML n�zet';
$lang_pgeditor[21] = 'URL :';
$lang_pgeditor[22] = 'Szerz� :';
$lang_pgeditor[23] = 'Id�zet :'; //vigy�zz, ide ne �rj be semmilyen speci�lis karaktert
$lang_pgeditor[24] = 'K�d nyelv :';
$lang_pgeditor[25] = 'K�d :'; //vigy�zz, ide ne �rj be semmilyen speci�lis karaktert
$lang_pgeditor[26] = 'Kattints ide az Opera b�ng�sz� 9-es verzi�j�nak hibaelh�r�t�s�hoz';
$lang_pgeditor[27] = 'S�g� mutat�sa';
$lang_pgeditor[28] = 'S�g� elrejt�se';
$lang_pgeditor[29] = 'Semmi';
$lang_pgeditor[30] = 'Szerkeszt�si z�na';
$lang_pgeditor[31] = 'Mehet';
$lang_pgeditor[32] = 'M�gse';
$lang_pgeditor[33] = 'egy�b...';
$lang_pgeditor[34] = 'Semmi';
$lang_pgeditor[35]  = 'Image besz�r�sa';

//S�g�
$lang_help_pgeditor[0] = 'S�g� :';
$lang_help_pgeditor[1] = 'Tov�bbi inform�ci�k...';
//Szintaxis
$lang_help_pgeditor[2] = 'K�d szintaxis :';
$lang_help_pgeditor[3] = '<strong>&lt;color=<span class="tag_value">Hexadecim�lis k�d</span>&gt;&lt;/color&gt;</strong> lehet�v� teszi a sz�vegsz�nez�st.<br /><em>Megjegyz�s :</em> A hexadecim�lis k�d helyett (<span class="tag_value">#??????</span>), meg lehet adni a sz�n nev�t is (angolul) (<span class="tag_value">red, yellow, orange, green, blue,</span> stb...).'.$lang_help_pgeditor[1];
$lang_help_pgeditor[4] = '<strong>&lt;bgcolor=<span class="tag_value">Hexadecim�lis k�d</span>&gt;&lt;/bgcolor&gt;</strong> sz�nnel t�rt�n� sz�vegkiemel�st tesz lehet�v�.<br /><em>Megjegyz�s :</em> A hexadecim�lis k�d helyett (<span class="tag_value">#??????</span>), meg lehet adni a sz�n nev�t is (angolul) (<span class="tag_value">red, yellow, orange, green, blue,</span> stb...).'.$lang_help_pgeditor[1];
$lang_help_pgeditor[5] = '<strong>&lt;b&gt;&lt;/b&gt;</strong> lehet�v� teszi a sz�veg k�v�r�t�s�t.';
$lang_help_pgeditor[6] = '<strong>&lt;i&gt;&lt;/i&gt;</strong> d�lt bet�ss� teszi a sz�veget.';
$lang_help_pgeditor[7] = '<strong>&lt;u&gt;&lt;/u&gt;</strong> al�h�zott� teszi a sz�veget.';
$lang_help_pgeditor[8] = '<strong>&lt;cite&gt;&lt;/cite&gt;</strong> id�zetet sz�r be.<br /><em>Megjegyz�s :</em> Megadhat� a szerz� neve is a k�vetkez� m�don <strong>&lt;cite<span class="tag_value">=Author</span>&gt;</strong>';
$lang_help_pgeditor[9] = '<strong>&lt;code&gt;&lt;/code&gt;</strong> lehet�v� teszi k�d besz�r�s�t.<br /><em>Megjegyz�s :</em> Meg lehet adni a programnyelvet is a k�vetkez� m�don <strong>&lt;code<span class="tag_value">=LanguageName</span>&gt;</strong>';
$lang_help_pgeditor[10] = '<strong>&lt;left&gt;&lt;/left&gt;</strong> balra igaz�tja a sz�veget.';
$lang_help_pgeditor[11] = '<strong>&lt;center&gt;&lt;/center&gt;</strong> k�z�pre igaz�tja a sz�veget.';
$lang_help_pgeditor[12] = '<strong>&lt;right&gt;&lt;/right&gt;</strong> jobbra igaz�tja a sz�veget.';
$lang_help_pgeditor[13] = '<strong>&lt;link&gt;&lt;/link&gt;</strong> linket sz�r be.<br /><em>Megjegyz�s :</em> A link URL-ja a k�vetkez� m�don is megadhat� <strong>&lt;link<span class="tag_value">=URL</span>&gt;text&lt;/link&gt;</strong>. Ha a link URL-je nincs megadva, az URL a k�t tag k�z�tti lesz.<strong>&lt;link&gt;<span class="tag_value">URL</span>&lt;/link&gt;</strong>';
$lang_help_pgeditor[14] = '<strong>&lt;img=<span class="tag_value">SmileyName</span>&gt;</strong> lehet�v� teszi emotikon besz�r�s�t.<br /><em>Megjegyz�s :</em> A rendelkez�sre �ll� alap-emotikonok nevei a k�vetkez�k : <span class="tag_value">cool (klassz), wink (kacsint�s), biggrin (nagy vigyor), smile (mosoly), frown (rosszall), eek (ijeszt�, ijedt), mad (d�h�s, v. �r�lt), confused (zavart), rolleyes (t�gra ny�lt szemek), tongue (nyelv, nyelvet �lt), cry (s�r, s�r�s)</span>.'.$lang_help_pgeditor[1];
//Billenty�parancsok
$lang_help_pgeditor[15] = 'Billenty�parancsok (Windows alatt) :';
$lang_help_pgeditor[16] = 'Billenty� <strong>SHIFT + ny�l (jobb vagy bal)</strong> lehet�v� teszi a sz�vegkiv�laszt�st';
$lang_help_pgeditor[17] = 'Billenty� <strong>ALT + 2</strong> lehet�v� teszi az eszk�zs�v kiv�laszt�s�t';
$lang_help_pgeditor[18] = 'Billenty� <strong>ALT + 3</strong> lehet�v� teszi a szerkeszt�si z�na kiv�laszt�s�t';
$lang_help_pgeditor[19] = 'Billenty� <strong>ALT + 4</strong> a S�g�-t mutatja';
$lang_help_pgeditor[20] = 'Billenty� <strong>ALT + 5</strong> elrejti a S�g�-t';
$lang_help_pgeditor[21] = 'Billenty� <strong>TAB</strong> egyik kiv�lasztott r�szr�l a m�sikra v�lt';
$lang_help_pgeditor[22] = 'Billenty� <strong>SHIFT + TAB</strong> a jelenlegi kiv�laszt�sr�l az el�z�re v�lt';
$lang_help_pgeditor[23] = 'Billenty� <strong>ALT + ny�l (lefel� vagy felfel�)</strong> kibontja a kiv�lasztott men�t';
$lang_help_pgeditor[24] = 'Billenty� <strong>ALT + ny�l (lefel� vagy felfel�)</strong> �sszecsukja a kinyitott men�t';
$lang_help_pgeditor[25] = 'Billenty� <strong> ny�l (lefel� vagy felfel�)</strong> lehet�v� teszi a v�gighalad�st a kinyitott men�n';
$lang_help_pgeditor[26] = 'Billenty� <strong>ALT + s</strong> lehet�v� teszi az �rlapk�ld�st';
//
$lang_help_pgeditor[27] = 'Inform�ci� a Web sz�nk�dokr�l';
$lang_help_pgeditor[28] = 'Inform�ci� az emotikon beilleszt� k�dokr�l';
$lang_help_pgeditor[29] = ' (megnyit�s �j ablakban)';

//Popup s�g� a sz�nbesz�r�shoz
$lang_color_pgeditor[0] = 'Az alapsz�nek nevei (16 + 1), ahogy a W3C �ltal a HTML-ben �s a CSS 2.1-ben meg van hat�rozva ';
$lang_color_pgeditor[1] = 'black (fekete)';
$lang_color_pgeditor[2] = 'gray (sz�rke)';
$lang_color_pgeditor[3] = 'silver (ez�st)';
$lang_color_pgeditor[4] = 'white (feh�r)';
$lang_color_pgeditor[5] = 'maroon (gesztenyebarna)';
$lang_color_pgeditor[6] = 'red (v�r�s, piros)';
$lang_color_pgeditor[7] = 'orange (narancss�rga)';
$lang_color_pgeditor[8] = 'yellow (s�rga)';
$lang_color_pgeditor[9] = 'lime (vil�gosz�ld)';
$lang_color_pgeditor[10] = 'green (z�ld)';
$lang_color_pgeditor[11] = 'olive (barn�sz�ld)';
$lang_color_pgeditor[12] = 'aqua (k�kesz�ld)';
$lang_color_pgeditor[13] = 'blue (k�k)';
$lang_color_pgeditor[14] = 'teal (s�t�tz�ld)';
$lang_color_pgeditor[15] = 'navy (s�t�tk�k, tengerk�k)';
$lang_color_pgeditor[16] = 'fuchsia (v�r�seslila)';
$lang_color_pgeditor[17] = 'purple (b�borlila)';
$lang_color_pgeditor[18] = 'A websz�nek neve';
$lang_color_pgeditor[19] = 'A sz�n HTML neve';
$lang_color_pgeditor[20] = 'Hexadecim�lis k�d';
$lang_color_pgeditor[21] = 'Megtekint�s';
$lang_color_pgeditor[22] = 'ford�t�s';
$lang_color_pgeditor[23] = 'A 140 "nemhivatalos" websz�n neve';
$lang_color_pgeditor[24] = '<span class="warning">Legy�l �vatos :</span> ezek a sz�nnevek a k�vetkez� b�ng�sz�k �ltal felismertek : Netscape 2.0+, Internet Explorer 3.0+ valamint a legt�bb modern b�ng�sz� (Firefox, Safari, stb...) de a t�mogat�suk nem minden b�ng�sz� �ltal garant�lt, mert ezek a sz�nnevek nem szerepelnek a W3C hivatalos javaslataiban.';

//Popup s�g� az emotikonok besz�r�s�hoz
$lang_smiley_pgeditor[0] = 'Emotikon nevek';
$lang_smiley_pgeditor[1] = 'klassz (cool)';
$lang_smiley_pgeditor[2] = 'kacsint�s (wink)';
$lang_smiley_pgeditor[3] = 'nagy vigyor (biggrin)';
$lang_smiley_pgeditor[4] = 'mosoly (smile)';
$lang_smiley_pgeditor[5] = 'rosszall (frown)';
$lang_smiley_pgeditor[6] = 'ijedt (eek)';
$lang_smiley_pgeditor[7] = 'd�h�s (mad)';
$lang_smiley_pgeditor[8] = 'zavart (confused)';
$lang_smiley_pgeditor[9] = 'kerek szemek (rolleyes)';
$lang_smiley_pgeditor[10] = 'nyelv (tongue)';
$lang_smiley_pgeditor[11] = 's�r�s (cry)';
$lang_smiley_pgeditor[12] = 'Guppy alap-emotikonok';
$lang_smiley_pgeditor[13] = 'Emotikon neve';
$lang_smiley_pgeditor[14] = 'Emotikon besz�r�s k�dja';
$lang_smiley_pgeditor[15] = 'Megtekint�s';
$lang_smiley_pgeditor[16] = 'A t�bbi rendelkez�sre �ll� emotikon';
?>