<?php
/*
     MinieditorTextarea realizado por Djchouix - Licenca CeCILL
     Web site = http://lebrikabrak.free.fr/
     e-mail   = lebrikabrak@free.fr
	 versao 1.6.3 (24 février 2007) compativel com o guppy v4.5.x
	 Traduction par Astral God (http://astralgod.free.fr)
*/
if (stristr($_SERVER["SCRIPT_NAME"], "pt_minieditortextarea.inc")) {
  header("location:../index.php");
  die();
}

$version_minieditor = "Versao 1.6.3";
$lang_minieditor[0] = 'Ok';
$lang_minieditor[1] = 'Fechar';
$lang_minieditor[2] = 'Novo';
$lang_minieditor[3] = 'Letra';
$lang_minieditor[4] = 'Tamanho';
$lang_minieditor[5] = 'Cor das Letras';
$lang_minieditor[6] = 'Cor de Fundo';
$lang_minieditor[7] = 'Alinhar à Esquerda';
$lang_minieditor[8] = 'Centrado';
$lang_minieditor[9] = 'Alinhar à Direita';
$lang_minieditor[10] = 'Justificado';
$lang_minieditor[11] = 'Negrito';
$lang_minieditor[12] = 'Italico';
$lang_minieditor[13] = 'Sublinhado';
$lang_minieditor[14] = 'Traçado';
$lang_minieditor[15] = 'Indice';
$lang_minieditor[16] = 'Exponente';
$lang_minieditor[17] = 'Inserir uma Imagem';
$lang_minieditor[18] = 'Inserir um Link';
$lang_minieditor[19] = 'Prévisualisar';
$lang_minieditor[20] = 'Editor Wysiwyg';
$lang_minieditor[21] = 'Codigo HTML';
$lang_minieditor[22] = 'Classe CSS';
$lang_minieditor[23] = 'Caminho';
$lang_minieditor[24] = 'relativo';
$lang_minieditor[25] = 'absoluto';
$lang_minieditor[26] = 'URL';
$lang_minieditor[27] = 'Percorrer o servidor';
$lang_minieditor[28] = 'Objectivo';
$lang_minieditor[29] = 'Alt';
$lang_minieditor[30] = 'Largura (px)';
$lang_minieditor[31] = 'Altura (px)';
$lang_minieditor[32] = 'Quadro (px)';
$lang_minieditor[33] = 'Espaço Horiz. (px)';
$lang_minieditor[34] = 'Espaço Vert. (px)';
$lang_minieditor[35] = 'Alinhamento';
$lang_minieditor[36] = 'Seleccionar uma Cor';
$lang_minieditor[37] = 'Cor';
$lang_minieditor[38] = "Colar o texto aqui";
$lang_minieditor[39] = 'Indicar o URL do documento.';
$lang_minieditor[40] = 'O codigo cor nao foi inserido.\nEle deve ser do tipo #XXXXXX ou X = 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E ou F.\nPor favor corrija.';
$lang_minieditor[41] = "Um erro foi detectado. Por favor recomece ou contacte o autor do plugin.";
$lang_minieditor[42] = 'Titulo';
$lang_minieditor[43] = 'Inserir um paragrafo';
$lang_minieditor[44] = 'Nenhum';
$lang_minieditor[45] = 'Inserir um codigo';
$lang_minieditor[46] = 'Anular';
$lang_minieditor[47] = 'Recomecar';
$lang_minieditor[48] = 'Inserir uma Animacao Flash';
$lang_minieditor[49] = 'Id';
$lang_minieditor[50] = 'Qualidade';
$lang_minieditor[51] = 'Normal';
$lang_minieditor[52] = 'Alta';
$lang_minieditor[53] = 'Baixa auto';
$lang_minieditor[54] = 'Baixa';
$lang_minieditor[55] = 'Repetir';
$lang_minieditor[56] = 'Leitura auto';
$lang_minieditor[57] = 'Menu';
$lang_minieditor[58] = 'Escala';
$lang_minieditor[59] = 'Sem quadro';
$lang_minieditor[60] = 'Tamanho exacto';
$lang_minieditor[61] = "<br /><br />Erro porque o nome da pasta na variavel <strong>\$nameRepPath</strong> no ficheiro <strong>minieditortextarea_config.inc</strong> apresenta simbolos invalidos.<br /><span style='font-weight:bold;text-decoration:underline;'>NOTA:</span><br />Para escolher o nome de uma pasta, deve utilisar apenas <strong>letras</strong> e/ou <strong>numeros</strong> e/ou simbolos <strong>tiret ( - )</strong> e <strong>sublinhado ( _ )</strong>.<br />Os outros tipos de letra e os espacos em branco sao invalidos.<br />Por favor recomece e corrija.";
$lang_minieditor[62] = '<a href="http://www.macromedia.com/go/getflashplayer" target="_blank"><img src="flash\/document_Flash.gif" alt="Get FlashPlayer" title="Get FlashPlayer" width="114" height="21" border="0" /><\/a>';
$lang_minieditor[63] = 'A largura nao foi inserida correctamente.\nInsira um numero.\nPor favor corrija.';
$lang_minieditor[64] = 'A altura nao foi inserida correctamente.\nInsira um numero.\nPor favor corrija.';
$lang_minieditor[65] = 'O tamanho Horizontal nao foi inserido correctamente.\nInsira um numero.\nPor favor corrija.';
$lang_minieditor[66] = 'O tamanho vertical nao foi inserido correctamente.\nInsira um numero.\nPor favor corrija.';
$lang_minieditor[67] = 'A expessura do quadro nao foi inserida correctamente.\nInsira um numero.\nPor favor corrija.';
$lang_minieditor[68] = 'Acerca de';
$lang_minieditor[69] = 'Inserir um Smiley';
$lang_minieditor[70] = 'Fechar';
$lang_minieditor[71] = 'Inserir um carácter especial';
?>