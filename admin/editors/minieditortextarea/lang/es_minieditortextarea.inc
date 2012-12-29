<?php
/*
     MinieditorTextarea r�alis� par Djchouix - Licence CeCILL
     Web site = http://lebrikabrak.free.fr/
     e-mail   = lebrikabrak@free.fr
	 version 1.6.3 (24 f�vrier 2007) compatibilit� avec guppy v4.5.x
	 Traducci�n por Enrique (muchas gracias)
*/
if (stristr($_SERVER["SCRIPT_NAME"], "es_minieditortextarea.inc")) {
  header("location:../index.php");
  die();
}

$version_minieditor = "Version 1.6.3";
$lang_minieditor[0] = 'Ok';
$lang_minieditor[1] = 'Cerrar';
$lang_minieditor[2] = 'Nuevo';
$lang_minieditor[3] = 'Fuentes';
$lang_minieditor[4] = 'Tama�o';
$lang_minieditor[5] = 'Color de los Caracteres';
$lang_minieditor[6] = 'Color del Fondo';
$lang_minieditor[7] = 'Alineado a la Izquierda';
$lang_minieditor[8] = 'Centrado';
$lang_minieditor[9] = 'Alineado a la Derecha';
$lang_minieditor[10] = 'Justificado';
$lang_minieditor[11] = 'Gruesa';
$lang_minieditor[12] = 'Italica';
$lang_minieditor[13] = 'Subrayado';
$lang_minieditor[14] = 'Tachado';
$lang_minieditor[15] = 'Indice';
$lang_minieditor[16] = 'Expositor';
$lang_minieditor[17] = 'Insertar una Imagen';
$lang_minieditor[18] = 'Insertar un Enlace';
$lang_minieditor[19] = 'Previsualizar';
$lang_minieditor[20] = 'Editor Wysiwyg';
$lang_minieditor[21] = 'Se�al HTML';
$lang_minieditor[22] = 'Tipo CSS';
$lang_minieditor[23] = 'Camino';
$lang_minieditor[24] = 'relativo';
$lang_minieditor[25] = 'absoluto';
$lang_minieditor[26] = 'URL';
$lang_minieditor[27] = 'Recorrer el sevidor';
$lang_minieditor[28] = 'Target';
$lang_minieditor[29] = 'Alt';
$lang_minieditor[30] = 'Largo (px)';
$lang_minieditor[31] = 'Alto (px)';
$lang_minieditor[32] = 'Borde (px)';
$lang_minieditor[33] = 'Estiramiento Horiz. (px)';
$lang_minieditor[34] = 'Estiramiento Vert. (px)';
$lang_minieditor[35] = 'Alineamiento';
$lang_minieditor[36] = 'Seleccionar un Color';
$lang_minieditor[37] = 'Color';
$lang_minieditor[38] = "Pega aqu� el texto";
$lang_minieditor[39] = 'Indicar la URL del documento';
$lang_minieditor[40] = 'El codigo de color no est� correctamente escrito.\Debe tener la forma #XXXXXX donde X = 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E ou F. Modif�calo';
$lang_minieditor[41] = "Ha ocurrido un error. Vuelve a comenzar o contacta con el autor del plugin.";
$lang_minieditor[42] = 'T�tulo';
$lang_minieditor[43] = 'Inserta un salto de l�nea';
$lang_minieditor[44] = 'Ninguno';
$lang_minieditor[45] = 'Inserta tu se�al preferida';
$lang_minieditor[46] = 'Anular';
$lang_minieditor[47] = 'Rehacer';
$lang_minieditor[48] = 'Insertar una Animaci�n Flash';
$lang_minieditor[49] = 'Id';
$lang_minieditor[50] = 'Calidad';
$lang_minieditor[51] = 'Por defecto';
$lang_minieditor[52] = 'Alto';
$lang_minieditor[53] = 'Base auto';
$lang_minieditor[54] = 'Base';
$lang_minieditor[55] = 'Bucle';
$lang_minieditor[56] = 'Lectura auto';
$lang_minieditor[57] = 'Menu';
$lang_minieditor[58] = 'Escala';
$lang_minieditor[59] = 'Ning�n borde';
$lang_minieditor[60] = 'Tama�o exacto';
$lang_minieditor[61] = "<br /><br />Error porque el n�mero del directorio de la variable <strong>\$nameRepPath</strong> situada en el fichero <strong>minieditortextarea_config.inc</strong> contiene caracteres no v�lidos.<br /><span style='font-weight:bold;text-decoration:underline;'>RAPPEL:</span><br />Para seleccionar el n�mero de un directorio, debes utilizar �nicamente <strong>letras</strong> y/o <strong>n�meros</strong> y/o los caracteres <strong>gui�n ( - )</strong> y <strong>subrayado ( _ )</strong>.<br />Los dem�s caracteres as� como los espacios en blanco est�n prohibidos.<br />Modif�calo y vuelve a comenzar.";
$lang_minieditor[62] = '<a href="http://www.macromedia.com/go/getflashplayer" target="_blank"><img src="flash\/document_Flash.gif" alt="Get FlashPlayer" title="Get FlashPlayer" width="114" height="21" border="0" /><\/a>';
$lang_minieditor[63] = 'La longitud no est� escrita correctamente. Tienes que poner un n�mero. Modif�calo.';
$lang_minieditor[64] = 'La altura no est� escrita correctamente. Tienes que poner un n�mero. Modif�calo.';
$lang_minieditor[65] = 'El espaciado horizontal no est� escrito correctamente. Tienes que poner un n�mero. Modif�calo.';
$lang_minieditor[66] = 'El espaciado vertical no est� escrito correctamente. Tienes que poner un n�mero.  Modif�calo.';
$lang_minieditor[67] = 'El grosor del borde no est� escrito correctamente. Debes poner un n�mero. Modif�calo.';
$lang_minieditor[68] = 'A prop�sito';
$lang_minieditor[69] = 'Insertar un Smiley';
$lang_minieditor[70] = 'Cerrar';
$lang_minieditor[71] = 'Insertar un car�cter especial';
?>