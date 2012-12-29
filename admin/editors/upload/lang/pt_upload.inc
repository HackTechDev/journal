<?php
/*
     MinieditorTextarea realizado por Djchouix - Licenca CeCILL
     Web site = http://lebrikabrak.free.fr/
     e-mail   = lebrikabrak@free.fr
	 versao 1.6.2 (22 avril 2006) compativel com o guppy v4.5.x
	 Traduction par Astral God (http://astralgod.free.fr) (merci à lui)
*/
if (stristr($_SERVER["SCRIPT_NAME"], "pt_upload.inc")) {
  header("location:../index.php");
  die();
}

$lang_upload[1] = "Falhou pois uma pasta com o mesmo nome ja existe.<br /><br />Por favor modifique o nome da pasta a criar e recomece";
$lang_upload[2] = "Falhou pois um ficheiro com o mesmo nome existe.<br /><br />Por favor modifique o nome do ficheiro e recomece";
$lang_upload[3] = "Falhou pois uma pasta com o mesmo nome existe.<br /><br />Por favor modifique o nome da pasta e recomece";
$lang_upload[4] = "Falhou pois o servidor nao autorisa essa accao.<br /><br />Por favor apague a partir do programa de FTP.";
$lang_upload[5] = "Falhou o upload pois o ficheiro nao pertence a classe \"nome_do_ficheiro.ext\" ";
$lang_upload[6] = "Falhou o upload do ficheiro pois outro fichiero com o mesmo nome existe.<br /><br />Por favor modifique o nome do ficheiro e recomece";
$lang_upload[7] = "E aqui que gere os ficheiros e as pastas do seu site.<br /><img src='img/explorer.gif' alt='Abrir' title='Abrir' border='0' style='vertical-align:middle;' /> : abre a pasta<br /><img src='img/look.gif' alt='Visualisar' title='Visualisar' border='0' style='vertical-align:middle;' /> : visualisar o ficheiro.<br /><img src='img/edit.gif' alt='Renommer' title='Mudar Nome' border='0' style='vertical-align:middle;' /> : mudar o nome do ficheiro ou da pasta<br /><img src='img/sup.gif' alt='Apagar' title='Apagar' border='0' style='vertical-align:middle;' /> : apagar o ficheiro ou a pasta.<br />";
$lang_upload[8] = "Criar uma pasta";
$lang_upload[9] = "Nome da pasta";
$lang_upload[10] = "Criar";
$lang_upload[11] = 'Clique aqui para mostrar a ajuda';
$lang_upload[12] = 'Clique aqui para esconder a ajuda';
$lang_upload[13] = "Carregar um ficheiro";
$lang_upload[14] = "Pasta";
$lang_upload[15] = "Ficheiro";
$lang_upload[16] = "Tamanho (bytes)";
$lang_upload[17] = "Accao";
$lang_upload[18] = "Carregar no site";
$lang_upload[19] = "Para recuperar o endereco (URL) do ficheiro, clique no seu nome.";
$lang_upload[20] = 'Deve completar o formulario';
$lang_upload[21] = "Nao tem autorizacao para fazer o upload do ficheiro. Por favor contacte o webmaster do site.";
$lang_upload[22] = 'Visualisar';
$lang_upload[23] = 'Voce vai apagar o ficheiro';
$lang_upload[24] = 'Voce vai apagar a pasta';
$lang_upload[25] = 'e todo o seu conteudo (ficheiros e pastas)';
$lang_upload[26] = 'Atencao, impossivel voltar atras.\n Confirme a sua accao para continuar.';
$lang_upload[27] = 'Por favor insira o novo nome do ficheiro';
$lang_upload[28] = 'insira o novo nome do ficheiro sem a extensao';
$lang_upload[29] = 'Por favor insira o novo nome da pasta';
$lang_upload[30] = 'escrever aqui o novo nome da pasta';
$lang_upload[31] = 'Atencao, deve utilisar apenas letras sem acentos e/ou des numeros e/ou simbolos(- _) sem espacos no nome.';
$lang_upload[32] = "Abrir";
$lang_upload[33] = "Voltar";
$lang_upload[34] = "Pasta Principal";
$lang_upload[35] = "Visualisar";
$lang_upload[36] = "Mudar o nome";
$lang_upload[37] = "Apagar";
$lang_upload[38] = "Seleccionar";