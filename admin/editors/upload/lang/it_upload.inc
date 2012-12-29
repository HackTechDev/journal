<?php
/*
     MinieditorTextarea réalisé par Djchouix - Licence CeCILL
     Web site = http://lebrikabrak.free.fr/
     e-mail   = lebrikabrak@free.fr
	 version 1.6.2 (22 avril 2006) compatibilité avec guppy v4.5.x
	 Traduction par Palpiccolo et Vanix (merci à tous les deux)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "it_upload.inc")) {
  header("location:../index.php");
  die();
}

$lang_upload[1] = "Fallimento nella creazione perché una directory con lo stesso nome esiste già.<br /><br />Prego ricomincia cambiando il nome della directory da creare.";
$lang_upload[2] = "Fallimento perché un file con lo stesso nome esiste già.<br /><br />Prego ricomincia cambiando il nome del file";
$lang_upload[3] = "Fallimento perché una directory con lo stesso nome esiste già.<br /><br />Prego ricomincia cambiando il nome della directory";
$lang_upload[4] = "Fallimento nella cancellazione della directory perché il server non lo autorizza.<br /><br />Prego cancellalo utilizzando il tuo FTP.";
$lang_upload[5] = "Fallimento nell'upload perché non é un file della forma \"nome_del_file.ext\" ";
$lang_upload[6] = "Fallimento dell'upload perché un file con lo stesso nome esiste già.<br /><br />Prego ricomincia cambiando il nome del file dà upload";
$lang_upload[7] = "É qui che gestisci i file ed le directory del vostro sito.<br /><img src='img/explorer.gif' alt='Aprire' title='Aprire' border='0' style='vertical-align:middle;' /> : permette di aprire la directory<br /><img src='img/look.gif' alt='Vedere' title='Vedere' border='0' style='vertical-align:middle;' /> : permette di visualizzare il file.<br /><img src='img/edit.gif' alt='Rinominare' title='Rinominare' border='0' style='vertical-align:middle;' /> : permette di rinominare il file o la directory<br /><img src='img/sup.gif' alt='Cancellare' title='Cancellare' border='0' style='vertical-align:middle;' /> : permette di cancellare il file o la directory.<br />";
$lang_upload[8] = "Creare una directory";
$lang_upload[9] = "Nome della directory";
$lang_upload[10] = "Creare";
$lang_upload[11] = 'Clicca qui per mostrare l\'aiuto';
$lang_upload[12] = 'Clicca qui per nascondere l\'aiuto';
$lang_upload[13] = "Caricare un file";
$lang_upload[14] = "Directory";
$lang_upload[15] = "File";
$lang_upload[16] = "Taglia (octet)";
$lang_upload[17] = "Azione";
$lang_upload[18] = "Trasferire sul sito";
$lang_upload[19] = "Per recuperare l'(URL) del file, prego clicca sul suo nome.";
$lang_upload[20] = 'Devi riempire i campi';
$lang_upload[21] = "Non sei autorizzato a fare l'upload di questo tipo del file. Prego contattate l'amministratore del sito.";
$lang_upload[22] = 'Descrizione';
$lang_upload[23] = 'Sei sul punto di cancellare il file';
$lang_upload[24] = 'Sei sul punto di cancellare la directory';
$lang_upload[25] = 'compreso il  suo contenuto (file e sotto-directory)';
$lang_upload[26] = 'Attenzione, la cancellazione é irreversibile.\n Prego confermate questa cancellazione peché sia effettiva.';
$lang_upload[27] = 'Prego inserisci il nuovo nome del file';
$lang_upload[28] = 'scrivere qui il nuovo nome del file senza l\'estensione';
$lang_upload[29] = 'Prego inserisci il nuovo nome della directory';
$lang_upload[30] = 'scrivere qui il nuovo nome della directory';
$lang_upload[31] = 'Attenzione, devi utilizzare unicamente dei caratteri non accentuati e/o delle cifre e/o dei caratteri (-_) senza spazio nel nome.';
$lang_upload[32] = "Aprire";
$lang_upload[33] = "Ritorno";
$lang_upload[34] = "Directory Parente";
$lang_upload[35] = "Vedere";
$lang_upload[36] = "Rinominare";
$lang_upload[37] = "Cancellare";
$lang_upload[38] = "Scegliere";