<?php
/*
     MinieditorTextarea réalisé par Djchouix - Licence CeCILL
     Web site = http://lebrikabrak.free.fr/
     e-mail   = lebrikabrak@free.fr
	 version 1.6.2 (22 avril 2006) compatibilité avec guppy v4.5.x
	 Traducción por Enrique (muchas gracias)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "es_upload.inc")) {
  header("location:../index.php");
  die();
}

$lang_upload[1] = "Error de creación porque existe un directorio con el mismo nombre.<br /><br />Vuelve a comenzar cambiando el nombre del directorio a crear";
$lang_upload[2] = "Error porque ya existe un fichero con el mismo nombre.<br /><br />Vuelve a comenzar cambiando el nombre del fichero";
$lang_upload[3] = "Error porque ya existe un fichero con el mismo nombre.<br /><br />Vuelve a empezar cambiando el nombre del directorio";
$lang_upload[4] = "Error de supresión del directorio porque el servidor no lo autoriza.<br /><br />Volver a suprimirlo utilizando tu conexión FTP.";
$lang_upload[5] = "Error de subida porque el fichero no tiene el formato \"nombre_del_fichero.ext\" ";
$lang_upload[6] = "Error de subida porque ya existe un fichero con ese nombre.<br /><br />Volver a comenzar cambiando el nombre del fichero a subir";
$lang_upload[7] = "Aqui es donde administras los ficheros y los directorios de tu sitio.<br /><img src='img/explorer.gif' alt='Abrir' title='Abrir' border='0' style='vertical-align:middle;' /> : permite abrir el directorio<br /><img src='img/look.gif' alt='Ver' title='Ver' border='0' style='vertical-align:middle;' /> : permite visualizar el fichero.<br /><img src='img/edit.gif' alt='Renomear' title='Renomear' border='0' style='vertical-align:middle;' /> : permite renombrar o ficheiro ou o directorio<br /><img src='img/sup.gif' alt='Suprimir' title='Suprimir' border='0' style='vertical-align:middle;' /> : permite suprimir o ficheiro ou o directorio.<br />";
$lang_upload[8] = "Crear un directorio";
$lang_upload[9] = "Nome do directorio";
$lang_upload[10] = "Crear";
$lang_upload[11] = 'Preme aquí para abrir a axuda';
$lang_upload[12] = 'Preme aquí para pechar a axuda';
$lang_upload[13] = "Cargar un ficheiro";
$lang_upload[14] = "Directorio";
$lang_upload[15] = "Ficheiro";
$lang_upload[16] = "Tamaño (byte)";
$lang_upload[17] = "Acción";
$lang_upload[18] = "Subir ao sitio";
$lang_upload[19] = "Para recuperar a dirección (URL) do ficheiro, preme sobre seu nome.";
$lang_upload[20] = 'Tes que rechear este campo';
$lang_upload[21] = "Non estás autorizado para subir este tipo de ficheiro. Contacta co administrador do sitio.";
$lang_upload[22] = 'Idea';
$lang_upload[23] = 'Estás a piques de eliminar o ficheiro';
$lang_upload[24] = 'Estás a piques de eliminar o directorio';
$lang_upload[25] = 'así coma todo seu contido (ficheiros e sub-directorios)';
$lang_upload[26] = 'Atención, a eliminación é irreversible. Confirma esta eliminación para que se faga efectiva.';
$lang_upload[27] = 'Coloca o novo nome do ficheiro';
$lang_upload[28] = 'pon aquí o novo nome do ficheiro, sen extensión';
$lang_upload[29] = 'Coloca o nome do novo directorio';
$lang_upload[30] = 'pon aquí o novo nome do directorio';
$lang_upload[31] = 'Atención, debes utilizar únicamente caracteres sen acento e/ou números e/ou os caracteres(- _) sen espacios en branco no nome.';
$lang_upload[32] = "Abrir";
$lang_upload[33] = "Voltar";
$lang_upload[34] = "Directorio Raiz";
$lang_upload[35] = "Ver";
$lang_upload[36] = "Renomear";
$lang_upload[37] = "Suprimir";
$lang_upload[38] = "Seleccionar";