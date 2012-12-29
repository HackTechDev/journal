<?php
/*
     MinieditorTextarea réalisé par Djchouix - Licence CeCILL
     Web site = http://lebrikabrak.free.fr/
     e-mail   = lebrikabrak@free.fr
	 version 1.6.3 (24 février 2007) compatibilité avec guppy v4.5.x
	 Traduction par Palpiccolo et correction par Vanix (merci à eux)
*/
if (stristr($_SERVER["SCRIPT_NAME"], "it_minieditortextarea.inc")) {
  header("location:../index.php");
  die();
}

$version_minieditor = "Version 1.6.3";
$lang_minieditor[0] = 'Ok';
$lang_minieditor[1] = 'Chiudere';
$lang_minieditor[2] = 'Nuovo';
$lang_minieditor[3] = 'Caratteri';
$lang_minieditor[4] = 'Taglia';
$lang_minieditor[5] = 'Colore dei Caratteri';
$lang_minieditor[6] = 'Colore del Fondo';
$lang_minieditor[7] = 'Allineato a Sinistra';
$lang_minieditor[8] = 'Centrato';
$lang_minieditor[9] = 'Allineato a Destra';
$lang_minieditor[10] = 'Giustificato';
$lang_minieditor[11] = 'Grassetto';
$lang_minieditor[12] = 'Italico';
$lang_minieditor[13] = 'Sottolineato';
$lang_minieditor[14] = 'Sbarrato';
$lang_minieditor[15] = 'Indice';
$lang_minieditor[16] = 'Esponente';
$lang_minieditor[17] = 'Inserire un\'Immagine';
$lang_minieditor[18] = 'Inserire un Link';
$lang_minieditor[19] = 'Previsualizzazione';
$lang_minieditor[20] = 'Editore Wysiwyg';
$lang_minieditor[21] = 'Tag HTML';
$lang_minieditor[22] = 'Classe CSS';
$lang_minieditor[23] = 'Cammino';
$lang_minieditor[24] = 'relativo';
$lang_minieditor[25] = 'assoluto';
$lang_minieditor[26] = 'URL';
$lang_minieditor[27] = 'Percorrere il server';
$lang_minieditor[28] = 'Target';
$lang_minieditor[29] = 'Alt';
$lang_minieditor[30] = 'Larghezza (px)';
$lang_minieditor[31] = 'Altezza (px)';
$lang_minieditor[32] = 'Bordi (px)';
$lang_minieditor[33] = 'Spazio orrizontale (px)';
$lang_minieditor[34] = 'Spazio verticale (px)';
$lang_minieditor[35] = 'Allineamento';
$lang_minieditor[36] = 'Selezionare un Colore';
$lang_minieditor[37] = 'Colore';
$lang_minieditor[38] = "Incollare il testo qui";
$lang_minieditor[39] = 'Prego inserite l\'URL del documento.';
$lang_minieditor[40] = 'Il codice del colore non é scritto correttamente.\nDeve essere della forma #XXXXXX o X = 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E ou F.\nPrego fate la correzione.';
$lang_minieditor[41] = "Si è verificato un errore. Prego ricominciate o contattate l'autore del plugin.";
$lang_minieditor[42] = 'Titolo';
$lang_minieditor[43] = 'Inserire il tag BR';
$lang_minieditor[44] = 'no';
$lang_minieditor[45] = 'Inserire il tag';
$lang_minieditor[46] = 'Annulla';
$lang_minieditor[47] = 'Ripristina';
$lang_minieditor[48] = 'Inserire un\'Animazione Flash';
$lang_minieditor[49] = 'Id';
$lang_minieditor[50] = 'Qualità';
$lang_minieditor[51] = 'Di Base';
$lang_minieditor[52] = 'Alta';
$lang_minieditor[53] = 'Bassa automatica';
$lang_minieditor[54] = 'Bassa';
$lang_minieditor[55] = 'Continua';
$lang_minieditor[56] = 'Lettura automatica';
$lang_minieditor[57] = 'Menu';
$lang_minieditor[58] = 'Taglia';
$lang_minieditor[59] = 'Senza bordi';
$lang_minieditor[60] = 'Taglia esatta';
$lang_minieditor[61] = "<br /><br />Errore perché il nome di una directory nella variabile <strong>\$nameRepPath</strong> situato  nel file <strong>minieditortextarea_config.inc</strong> contiene dei caratteri non validi.<br /><span style='font-weight:bold;text-decoration:underline;'>PER MEMORIA:</span><br />Per la scelta del nome di una directory, voi dovete utilizzare unicamente delle <strong>lettere</strong> e/o delle <strong>cifre</strong> e/o i caratteri <strong>meno ( - )</strong> e <strong>sottolineato ( _ )</strong>.<br />Tutti gli altri caratteri compresi gli spazi bianchi non sono permessi.<br />Prego correggete o ricominciate.";
$lang_minieditor[62] = '<a href="http://www.macromedia.com/go/getflashplayer" target="_blank"><img src="flash\/document_Flash.gif" alt="Get FlashPlayer" title="Get FlashPlayer" width="114" height="21" border="0" /><\/a>';
$lang_minieditor[63] = 'La larghezza non è scritta correttamente.\nDovete mettere un numero.\nVolete correggere.';
$lang_minieditor[64] = 'L\'altezza non è scritta correttamente.\nDovete mettere un numero.\nVolete correggere.';
$lang_minieditor[65] = 'Lo Spazio Orrizontale non è scritto correttamente.\nDovete mettere un numero.\nVolete correggere.';
$lang_minieditor[66] = 'Lo Spazio Verticale non è scritto correttamente.\nDovete mettere un numero.\nVolete correggere.';
$lang_minieditor[67] = 'Lo spessore dei bordi non è scritto correttamente.\nDovete mettere un numero.\nVolete correggere.';
$lang_minieditor[68] = 'A proposito';
$lang_minieditor[69] = 'Inserire un Smiley';
$lang_minieditor[70] = 'Chiudere';
$lang_minieditor[71] = 'Inserire un carattere speciale';
?>