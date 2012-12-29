<?php
/*
     Plugin PostGuestEditor
	 Version  : 2.5.1 (2010/11/05)
	 Compatibility : Guppy v4.5.x et Guppy v4.6.x
	 Licence  : GNU Lesser General Public License
	 Author   : Jйrфme CROUX (djchouix)
     Web site : http://lebrikabrak.info/
     E-mail   : jchouix@wanadoo.fr
*/

if (stristr($_SERVER['SCRIPT_NAME'], 'ru_pgeditor.inc')) {
  header('location:../index.php');
  die();
}

$version_pgeditor = "Version 2.5.1";
$charset = 'windows-1251';

$lang_pgeditor[0]  = 'ru';
$lang_pgeditor[1]  = 'Закрыть';
$lang_pgeditor[2]  = 'Цвет текста';
$lang_pgeditor[3]  = 'Цвет фона';
$lang_pgeditor[4]  = 'Жирный';
$lang_pgeditor[5]  = 'Курсив';
$lang_pgeditor[6]  = 'Подчеркивание';
$lang_pgeditor[7]  = 'Вставка цитат';
$lang_pgeditor[8]  = 'Вставка кода';
$lang_pgeditor[9]  = 'Выравнивание по левому краю';
$lang_pgeditor[10] = 'Выравнивание по центру';
$lang_pgeditor[11] = 'Выравнивание по правому краю';
$lang_pgeditor[12] = 'Вставка ссылки';
$lang_pgeditor[13] = 'Удалить ссылку';
$lang_pgeditor[14] = 'нумерованный список';
$lang_pgeditor[15] = 'список с дефисом';
$lang_pgeditor[16] = 'назад';
$lang_pgeditor[17] = 'вперед';
$lang_pgeditor[18] = 'Всавка смайлов (popup)';
$lang_pgeditor[19] = 'Предпросмотр (popup)';
$lang_pgeditor[20] = 'Просмотреть HTML';
$lang_pgeditor[21] = 'URL :';
$lang_pgeditor[22] = 'Автор :';
$lang_pgeditor[23] = 'Цитирование :'; //be careful not to type any special character
$lang_pgeditor[24] = 'Code Language :';
$lang_pgeditor[25] = 'Код :';//be careful not to type any special character
$lang_pgeditor[26] = 'Click in order to solve a bug with the browser Opera 9';
$lang_pgeditor[27] = 'Отобразить Помощь';
$lang_pgeditor[28] = 'Hide Help';
$lang_pgeditor[29] = 'нет';
$lang_pgeditor[30] = 'Поле редактирования';
$lang_pgeditor[31] = 'Ok';
$lang_pgeditor[32] = 'Отмена';
$lang_pgeditor[33] = 'другой...';
$lang_pgeditor[34] = 'нет';
$lang_pgeditor[35] = 'Insert image';

//Help
$lang_help_pgeditor[0] = 'Помощь :';
$lang_help_pgeditor[1] = 'For extra info...';
//Syntax
$lang_help_pgeditor[2] = 'Code Syntax :';
$lang_help_pgeditor[3] = '<strong>&lt;color=<span class="tag_value">CodeHexadecimal</span>&gt;&lt;/color&gt;</strong> enables text colouring.<br /><em>Note :</em> Instead of the hexadecimal code (<span class="tag_value">#??????</span>), you can specify the name of the colour(<span class="tag_value">red, yellow, orange, green, blue,</span> etc...).'.$lang_help_pgeditor[1];
$lang_help_pgeditor[4] = '<strong>&lt;bgcolor=<span class="tag_value">CodeHexadecimal</span>&gt;&lt;/bgcolor&gt;</strong> enables the colored highlighting of a text.<br /><em>Note :</em> Instead of the hexadecimal code (<span class="tag_value">#??????</span>), you can specify the name of the colour(<span class="tag_value">red, yellow, orange, green, blue,</span> etc...).'.$lang_help_pgeditor[1];
$lang_help_pgeditor[5] = '<strong>&lt;b&gt;&lt;/b&gt;</strong> enables the emboldening of a text.';
$lang_help_pgeditor[6] = '<strong>&lt;i&gt;&lt;/i&gt;</strong> enables the italicising of a text.';
$lang_help_pgeditor[7] = '<strong>&lt;u&gt;&lt;/u&gt;</strong> enables the underlining of a text.';
$lang_help_pgeditor[8] = '<strong>&lt;cite&gt;&lt;/cite&gt;</strong> enables quotation inserting.<br /><em>Note :</em> You can specify the name of the authors by typing <strong>&lt;cite<span class="tag_value">=Author</span>&gt;</strong>';
$lang_help_pgeditor[9] = '<strong>&lt;code&gt;&lt;/code&gt;</strong> enables code inserting.<br /><em>Note :</em> You can specify the language by typing <strong>&lt;code<span class="tag_value">=LanguageName</span>&gt;</strong>';
$lang_help_pgeditor[10] = '<strong>&lt;left&gt;&lt;/left&gt;</strong> enables left align.';
$lang_help_pgeditor[11] = '<strong>&lt;center&gt;&lt;/center&gt;</strong> enables center align.';
$lang_help_pgeditor[12] = '<strong>&lt;right&gt;&lt;/right&gt;</strong> enables right align.';
$lang_help_pgeditor[13] = '<strong>&lt;link&gt;&lt;/link&gt;</strong> enables link inserting.<br /><em>Note :</em> You can specify the link URL by typing <strong>&lt;link<span class="tag_value">=URL</span>&gt;text&lt;/link&gt;</strong>. If you do not specify the link URL, the URL will be the one between the two tags.<strong>&lt;link&gt;<span class="tag_value">URL</span>&lt;/link&gt;</strong>';
$lang_help_pgeditor[14] = '<strong>&lt;img=<span class="tag_value">SmileyName</span>&gt;</strong> enables smiley insertion.<br /><em>Note :</em> The names of available basic smileys are : <span class="tag_value">cool, wink, biggrin, smile, frown, eek, mad, confused, rolleyes, tongue, cry</span>.'.$lang_help_pgeditor[1];
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
$lang_help_pgeditor[27] = 'Informations about Web colour codes';
$lang_help_pgeditor[28] = 'Informations about smiley inserting code';
$lang_help_pgeditor[29] = ' (open in a new window)';

//Popup Help with Color insertion
$lang_color_pgeditor[0] = 'The names of the (16 + 1) basic colours for HTML and CSS 2.1 as specified by W3C';
$lang_color_pgeditor[1] = 'black';
$lang_color_pgeditor[2] = 'gray';
$lang_color_pgeditor[3] = 'silver';
$lang_color_pgeditor[4] = 'white';
$lang_color_pgeditor[5] = 'maroon';
$lang_color_pgeditor[6] = 'red';
$lang_color_pgeditor[7] = 'orange';
$lang_color_pgeditor[8] = 'yellow';
$lang_color_pgeditor[9] = 'lime';
$lang_color_pgeditor[10] = 'green';
$lang_color_pgeditor[11] = 'olive';
$lang_color_pgeditor[12] = 'aqua';
$lang_color_pgeditor[13] = 'blue';
$lang_color_pgeditor[14] = 'teal';
$lang_color_pgeditor[15] = 'navy';
$lang_color_pgeditor[16] = 'fuchsia';
$lang_color_pgeditor[17] = 'purple';
$lang_color_pgeditor[18] = 'Name of web colours';
$lang_color_pgeditor[19] = 'HTML name of the colour';
$lang_color_pgeditor[20] = 'Hexadecimal code';
$lang_color_pgeditor[21] = 'Viewing';
$lang_color_pgeditor[22] = 'translation';
$lang_color_pgeditor[23] = 'Names of the 140 "unofficial" web colours';
$lang_color_pgeditor[24] = '<span class="warning">Be careful :</span> these colour names are supported by the browsers : Netscape 2.0+, Internet Explorer 3.0+ as well as by most modern browsers(Firefox, Safari, and so on...) but their support is not garanteed for every standard respecting browser, for these colour names are not included in the W3C official recommendations.';

//Popup Help with Smiley insertion
$lang_smiley_pgeditor[0] = 'Smileys names';
$lang_smiley_pgeditor[1] = 'smiley cool';
$lang_smiley_pgeditor[2] = 'smiley wink';
$lang_smiley_pgeditor[3] = 'smiley biggrin';
$lang_smiley_pgeditor[4] = 'smiley smile';
$lang_smiley_pgeditor[5] = 'smiley frown';
$lang_smiley_pgeditor[6] = 'smiley eek';
$lang_smiley_pgeditor[7] = 'smiley mad';
$lang_smiley_pgeditor[8] = 'smiley confused';
$lang_smiley_pgeditor[9] = 'smiley rolleyes';
$lang_smiley_pgeditor[10] = 'smiley tongue';
$lang_smiley_pgeditor[11] = 'smiley cry';
$lang_smiley_pgeditor[12] = 'Guppy basic smileys';
$lang_smiley_pgeditor[13] = 'Smiley name';
$lang_smiley_pgeditor[14] = 'Smiley inserting code';
$lang_smiley_pgeditor[15] = 'Viewing';
$lang_smiley_pgeditor[16] = 'The other available smileys';
?>