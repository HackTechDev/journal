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

if (stristr($_SERVER['SCRIPT_NAME'], 'pt_pgeditor.inc')) {
  header('location:../index.php');
  die();
}

$version_pgeditor = "Version 2.5.1";
$charset = 'iso-8859-1';

$lang_pgeditor[0]  = 'pt';
$lang_pgeditor[1]  = 'Fechar';
$lang_pgeditor[2]  = 'Cor do Texto';
$lang_pgeditor[3]  = 'Cor do Fundo';
$lang_pgeditor[4]  = 'Negrito';
$lang_pgeditor[5]  = 'Italico';
$lang_pgeditor[6]  = 'Sublinhado';
$lang_pgeditor[7]  = 'Inserir uma Citação';
$lang_pgeditor[8]  = 'Inserir Codigo';
$lang_pgeditor[9]  = 'Alinhar à Esquerda';
$lang_pgeditor[10] = 'Centrar';
$lang_pgeditor[11] = 'Alinhar à Direita';
$lang_pgeditor[12] = 'Inserir uma Ligação';
$lang_pgeditor[13] = 'Eliminar uma Ligação';
$lang_pgeditor[14] = 'Lista numerada';
$lang_pgeditor[15] = 'Lista de marcas e numerações';
$lang_pgeditor[16] = 'Annular';
$lang_pgeditor[17] = 'Repetir';
$lang_pgeditor[18] = 'Inserir um Smiley (popup)';
$lang_pgeditor[19] = 'Pré vizualizar (popup)';
$lang_pgeditor[20] = 'Publicação HTML';
$lang_pgeditor[21] = 'URL :';
$lang_pgeditor[22] = 'Autor :';
$lang_pgeditor[23] = 'Citação :'; //attention à ne pas introduire de caractères spéciaux
$lang_pgeditor[24] = 'Linguagem do codigo :';
$lang_pgeditor[25] = 'Codigo :'; //attention à ne pas introduire de caractères spéciaux
$lang_pgeditor[26] = 'Click aqui para resolver o problema com o navegador Opera 9';
$lang_pgeditor[27] = 'Afixar ajuda';
$lang_pgeditor[28] = 'Esconder ajuda';
$lang_pgeditor[29] = 'Nenhuma';
$lang_pgeditor[30] = 'Zona de edição';
$lang_pgeditor[31] = 'Ok';
$lang_pgeditor[32] = 'Anular';
$lang_pgeditor[33] = 'outro...';
$lang_pgeditor[34] = 'Nenhum';
$lang_pgeditor[35] = 'Inserir um Imagen';

//Aide
$lang_help_pgeditor[0] = 'Ajuda :';
$lang_help_pgeditor[1] = 'Para mais pormenores...';
//Syntaxe
$lang_help_pgeditor[2] = 'Syntaxe do codigo :';
$lang_help_pgeditor[3] = '<strong>&lt;color=<span class="tag_value">CodigoHexadécimal</span>&gt;&lt;/color&gt;</strong> permite colar texto.<br /><em>Nota :</em> Poderá determinar em vez do codigo hexadécimal (<span class="tag_value">#??????</span>), o nome da cor (<span class="tag_value">red, yellow, orange, green, blue,</span> etc...).'.$lang_help_pgeditor[1];
$lang_help_pgeditor[4] = '<strong>&lt;bgcolor=<span class="tag_value">CodigoHexadécimal</span>&gt;&lt;/bgcolor&gt;</strong> permite de sublinhar um texto em cor.<br /><em>Nota :</em> Poderá determinar em vez do codigo hexadécimal (<span class="tag_value">#??????</span>), o nome da cor (<span class="tag_value">red, yellow, orange, green, blue,</span> etc...).'.$lang_help_pgeditor[1];
$lang_help_pgeditor[5] = '<strong>&lt;b&gt;&lt;/b&gt;</strong> permite colocar em negrito o texto.';
$lang_help_pgeditor[6] = '<strong>&lt;i&gt;&lt;/i&gt;</strong> permite colocar em italico o texto.';
$lang_help_pgeditor[7] = '<strong>&lt;u&gt;&lt;/u&gt;</strong> permite de sublinahr o texto.';
$lang_help_pgeditor[8] = '<strong>&lt;cite&gt;&lt;/cite&gt;</strong> permite de inserir uma citação.<br /><em>Nota :</em> Poderá indicar o nome do autor da citação escrevendo <strong>&lt;cite<span class="tag_value">=Autor</span>&gt;</strong>';
$lang_help_pgeditor[9] = '<strong>&lt;code&gt;&lt;/code&gt;</strong> permite de inserir codigo.<br /><em>Nota :</em> Poderá indicar a linguagem escrevendo <strong>&lt;code<span class="tag_value">=NomedaLinguagem</span>&gt;</strong>';
$lang_help_pgeditor[10] = '<strong>&lt;left&gt;&lt;/left&gt;</strong> permite de alinhar à esquerda.';
$lang_help_pgeditor[11] = '<strong>&lt;center&gt;&lt;/center&gt;</strong> permite de alinhar ao centro.';
$lang_help_pgeditor[12] = '<strong>&lt;right&gt;&lt;/right&gt;</strong> permite de alinhar à direita.';
$lang_help_pgeditor[13] = '<strong>&lt;link&gt;&lt;/link&gt;</strong> permite de inserir uma ligação.<br /><em>Nota :</em> poderá indicar o url da ligação escrevendo <strong>&lt;link<span class="tag_value">=URL</span>&gt;texte&lt;/link&gt;</strong>. Si vous ne précisez pas l\'url du lien, l\'url sera ce qui se trouve entre les deux balises.<strong>&lt;link&gt;<span class="tag_value">URL</span>&lt;/link&gt;</strong>';
$lang_help_pgeditor[14] = '<strong>&lt;img=<span class="tag_value">NomduSmiley</span>&gt;</strong> permitet de inserir um smiley.<br /><em>Nota :</em> Os nomes dos smileys de base disponiveis são : <span class="tag_value">cool, wink, biggrin, smile, frown, eek, mad, confused, rolleyes, tongue, cry</span>.'.$lang_help_pgeditor[1];
//Raccourcis clavier
$lang_help_pgeditor[15] = 'Atalho Teclado (no Windows) :';
$lang_help_pgeditor[16] = 'Tecla <strong>SHIFT + seta (direita ou esquerda)</strong> permite de seleccionar textot';
$lang_help_pgeditor[17] = 'Tecla <strong>ALT + 2</strong> permite seleccionar a barra de ferramentas';
$lang_help_pgeditor[18] = 'Tecla <strong>ALT + 3</strong> permite de seleccionar a zona de edição';
$lang_help_pgeditor[19] = 'Tecla <strong>ALT + 4</strong> permite de afixar ajuda';
$lang_help_pgeditor[20] = 'Tecla <strong>ALT + 5</strong> permite de esconder ajuda';
$lang_help_pgeditor[21] = 'Tecla <strong>TAB</strong> permite de passar de uma selecção à seguinte';
$lang_help_pgeditor[22] = 'Tecla <strong>SHIFT + TAB</strong> permite de passar de uma selecção à precedente';
$lang_help_pgeditor[23] = 'Tecla <strong>ALT + seta (para baixo ou para cima)</strong> permite desdobrar o menu seleccionado';
$lang_help_pgeditor[24] = 'Tecla <strong>ALT + seta (para baixo ou para cima)</strong> permite tornar a dobrar um menu desdobrado';
$lang_help_pgeditor[25] = 'Tecla <strong>seta (para baixo ou para cima)</strong> permite de navegar num menu desdobrado';
$lang_help_pgeditor[26] = 'Tecla <strong>ALT + s</strong> permite de enviar o formulário';
//
$lang_help_pgeditor[27] = 'Informações a proposito do codigo de cores da Web';
$lang_help_pgeditor[28] = 'Informações a proposito do codigo para inserir smileys';
$lang_help_pgeditor[29] = ' (abertura numa nova janela)';

//Popup Aide Insertion Couleur
$lang_color_pgeditor[0] = 'Os nomes das (16 + 1) cores de base do HTML e do CSS 2.1 especificadas pelo W3C';
$lang_color_pgeditor[1] = 'preto';
$lang_color_pgeditor[2] = 'cinzento';
$lang_color_pgeditor[3] = 'prateado';
$lang_color_pgeditor[4] = 'branco';
$lang_color_pgeditor[5] = 'castanho';
$lang_color_pgeditor[6] = 'vermelho';
$lang_color_pgeditor[7] = 'laranja';
$lang_color_pgeditor[8] = 'amarelo';
$lang_color_pgeditor[9] = 'verde limão';
$lang_color_pgeditor[10] = 'verde';
$lang_color_pgeditor[11] = 'azeitona';
$lang_color_pgeditor[12] = 'cyan';
$lang_color_pgeditor[13] = 'azul';
$lang_color_pgeditor[14] = 'azul cinzento';
$lang_color_pgeditor[15] = 'azul marine';
$lang_color_pgeditor[16] = 'magenta';
$lang_color_pgeditor[17] = 'purpúreo';
$lang_color_pgeditor[18] = 'Nome das cores web';
$lang_color_pgeditor[19] = 'Nome HTML da cor';
$lang_color_pgeditor[20] = 'Codigo hexadécimal';
$lang_color_pgeditor[21] = 'Vizualização';
$lang_color_pgeditor[22] = 'tradução';
$lang_color_pgeditor[23] = 'os nomes das 140 cores "não oficiais" da web';
$lang_color_pgeditor[24] = '<span class="warning">Atenção :</span> os nomes dessas cores são suportados pelos navegadores Netscape 2.0+, Internet Explorer 3.0+ bem como a maior parte dos navegadores modernos (Firefox, Safari, etc...) mas o seu suporte de todos os navegadores mais conhecidos não é garantido porque não fazem parte das recomendações oficiais do W3C.';

//Popup Aide Insertion Smiley
$lang_smiley_pgeditor[0] = 'Nome dos smileys';
$lang_smiley_pgeditor[1] = 'smiley tranquilo';
$lang_smiley_pgeditor[2] = 'smiley complice';
$lang_smiley_pgeditor[3] = 'smiley contente';
$lang_smiley_pgeditor[4] = 'smiley sourridente';
$lang_smiley_pgeditor[5] = 'smiley sidéré';
$lang_smiley_pgeditor[6] = 'smiley perturbado';
$lang_smiley_pgeditor[7] = 'smiley em furia';
$lang_smiley_pgeditor[8] = 'smiley descontente';
$lang_smiley_pgeditor[9] = 'smiley espantado';
$lang_smiley_pgeditor[10] = 'smiley trocista';
$lang_smiley_pgeditor[11] = 'smiley triste';
$lang_smiley_pgeditor[12] = 'Os smileys de base de Guppy';
$lang_smiley_pgeditor[13] = 'Nome do smiley';
$lang_smiley_pgeditor[14] = 'Codigo para inserir o smiley';
$lang_smiley_pgeditor[15] = 'Vizualização';
$lang_smiley_pgeditor[16] = 'Os outros smileys disponiveis';
?>