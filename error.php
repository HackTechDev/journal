<?php
/*
	Error Track - GuppY PHP Script - version 4.6
	CeCILL Copyright (C) 2004-2009 by Laurent Duveau
	Initiated by Laurent Duveau and Nicolas Alves
	  Web site = http://www.freeguppy.org/
	  e-mail   = info@freeguppy.org

	Version History :
	  v2.1 (10 March 2003)        : initial release
	  v2.4 (24 September 2003)    : secured transfered parameters
	  v3.0 (25 February 2004)     : removed handling of Error code 500 as the webservers usually do not handle it correctly!
	  v4.5 (22 April 2005)        : new complete release (by Jean-Mi)
	  v4.5.17 (31 January 2007)   : new secured release (by Djchouix-Hpsam-JeanMi)
	  v4.6.0 (04 June 2007)       : modified in order to return good errors codes (by hpsam)
	  v4.6.4 (04 November 2007)   : new secured release (by Hpsam-Ghazette and jchouix)
	  v4.6.6 (14 April 2008)      : corrected 1st $err test (by JeanMi)
      v4.6.10 (7 September 2009)  : corrected #259
      v4.6.14(14 February 2011)   : corrected (thanks jchouix)	  
	  v4.6.21(18 October 2012)    : corrected spelling and vocabulary (thanks Corrector)
*/

header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");

$REMOTE_ADDR = strip_tags(addslashes($REMOTE_ADDR));
$msg = array();

if (!empty($err)){
  $error_number = array('400', '401', '403', '404', '500');
  if (!in_array(abs($err), $error_number)) {
		header("HTTP/1.0 403 Forbidden");
		die('STOP ! Bad error number');
	}
  $with_mail = "false";

  if (!is_numeric($err)) {
		header("HTTP/1.0 403 Forbidden");
	    die('STOP ! $err is not numeric');
  }

  $ip = explode('.', $REMOTE_ADDR);
  if (count($ip) != 4) {
		header("HTTP/1.0 403 Forbidden");
		die('STOP ! Bad IP');
	}

  foreach($ip as $n) {
	if (!is_numeric($n) || $n < 0 || $n > 255) {
			header("HTTP/1.0 403 Forbidden");
			die('STOP ! Bad IP');
		}
  }

  if ($err < 0) {
	$with_mail = "true";
	$err = abs($err);
  }

  $fichiers = array();
  if ($hd = opendir(DATAREP."error")) {
	while ($fichier = readdir($hd)) {
	  if (stristr($fichier, INCEXT) == TRUE ) {
		$fichiers[] = $fichier;
	  }
	}
	closedir($hd);
  }
  $max_fic = 20;
  if (isset($serviz[50]) && ($serviz[50] > 0)) $max_fic = $serviz[50];
  $min_fic = max(0, $max_fic - 10);
  if (count($fichiers) > $max_fic) {
	for ($i=0; $i < count($fichiers) - $min_fic; $i++) {
	  DestroyDBFile(DATAREP."error/".$fichiers[$i]);
	}
  }
  if ($lang[0] == "fr") {
		$msg['400'] = array(
		  "Mauvaise requête",
		  "La requête HTTP n'a pas pu être comprise par le serveur en raison d'une syntaxe erronée.",
		  "Le problème peut provenir d'un navigateur web trop récent ou d'un serveur HTTP trop ancien.",
			"HTTP/1.0 400 Bad Request" );
	  $msg['401'] = array(
		"Non autorisé",
		"La requête nécessite une identification de l'utilisateur.",
		"",
			"HTTP/1.0 401 Unauthorized" );
	  $msg['403'] = array(
		"Interdit",
		"Le serveur HTTP a compris la requête, mais refuse de la traiter. ",
		"Ce code est généralement utilisé lorsqu'un serveur ne souhaite pas indiquer pourquoi la requête a été rejetée, ou lorsqu'aucune autre réponse ne correspond (par exemple le serveur est un Intranet et seules les machines du réseau local sont autorisées à se connecter au serveur).",
			"HTTP/1.0 403 Forbidden" );
	  $msg['404'] = array(
		"Non trouvé",
		"Le serveur n'a rien trouvé qui corresponde à l'adresse (URI) demandée.",
			"Cela signifie que l'URL que vous avez tapée ou cliquée est mauvaise ou obsolète et ne correspond à aucun document existant sur le serveur (vous pouvez essayer de supprimer progressivement les composants de l'URL en partant de la fin pour éventuellement retrouver un chemin d'accès existant).",
			"HTTP/1.0 404 Not Found" );
	  $msg['500'] = array(
		"Erreur interne du serveur",
		"Le serveur HTTP a rencontré une condition inattendue qui l'a empêché de traiter la requête.",
			"Cette erreur peut par exemple être le résultat d'une mauvaise configuration du serveur, ou d'une ressource épuisée ou refusée au serveur sur la machine hôte.",
			"HTTP/1.0 500 Internal server error" );
	}
	else {
	  $msg['400'] = array(
			"Bad Request",
			"The HTTP request could not be understood by the server due to malformed syntax.",
			"The web browser may be too recent, or the HTTP server may be too old.",
			"HTTP/1.0 400 Bad Request" );
	  $msg['401'] = array(
		"Unauthorized",
		"The request requires user authentication",
		"",
			"HTTP/1.0 401 Unauthorized" );
	  $msg['403'] = array(
		"Forbidden",
		"The HTTP server has understood the request, but it is refusing to fulfill it.",
		"This status code is commonly used when the server does not wish to reveal exactly why the request has been refused, or when no other response is applicable (for example the server is an Intranet and only LAN machines are authorized to connect).",
			"HTTP/1.0 403 Forbidden" );
	  $msg['404'] = array(
		"Not found",
		"The server has not found anything matching the request address (URI).",
		"This means the URL you have typed or clicked is wrong or obsolete and does not match any document existing on the server (you may try to gradually remove the URL components from de right to the left to eventually retrieve an existing path).",
			"HTTP/1.0 404 Not Found" );
	  $msg['500'] = array(
		"Internal server error",
		"The HTTP server encountered an unexpected condition which prevented it from fulfilling the request.",
		"For example this error can be caused by a server misconfiguration, or an exhausted resource or denied to the server on the host machine.",
			"HTTP/1.0 500 Internal server error" );
	}
  $msg0 = $msg[$err][0];
  $msg1 = addslashes($msg[$err][1]);
  $msg2 = addslashes($msg[$err][2]);
  $msg3 = $msg[$err][3];
  if (empty($msg0)) {
	  $msg0 = "Unexpected error";
	  $msg1 = "Unexpected error";
	  $msg2 = "See the <a href='http://www.apachefrance.com/Articles/7/page2.html' alt=''>errors code HTTP</a>.";
			$msg3 = "HTTP/1.0 403 Forbidden";
  }
  $date = date("d/m/Y H:i:s");
  $dest = $REQUEST_URI.(empty($REQUEST_QUERY_STRING)?"":"?".$REQUEST_QUERY_STRING);
  $domaine = gethostbyaddr($REMOTE_ADDR);

$err=addslashes($err);
$dest=strip_tags(addslashes($dest));
$HTTP_REFERER=strip_tags(addslashes($HTTP_REFERER));
$HTTP_USER_AGENT = strip_tags(addslashes($HTTP_USER_AGENT));


$mettre = "<?php
\$err = '$err';
\$msg0 = '$msg0';
\$msg1 = '$msg1';
\$msg2 = '$msg2';
\$msg3 = '$msg3';
\$date = 'Date : $date';
\$dest = 'Page requested : $dest';
\$source = 'Page source : $HTTP_REFERER';
\$browser = 'Browser : $HTTP_USER_AGENT';
\$addr_ip = 'IP address : $REMOTE_ADDR';
\$domaine = 'Domaine : $domaine';
\$with_mail = $with_mail;
";

  $errorId = date('Ymd_His_').$err;
  WriteFullDB(DATAREP."error/".$errorId.INCEXT, $mettre);
	header($msg3);
  header("location:".$site[3]."error.php?errorId=".$errorId);
}
else {
  $errorId = preg_replace("`[^0-9_]`","",$errorId);
  if (!is_file(DATAREP."error/".$errorId.INCEXT)) {
    header("HTTP/1.0 404 Not Found");
    die('STOP ! No file !');
  }

  include(DATAREP."error/".$errorId.INCEXT);

  header($msg3);
  $topmess = "Error ".$err." : ".$msg0;
  include("inc/hpage.inc");
  htable($topmess, "100%");
  echo "<b>".stripslashes($msg1)."</b><br />".stripslashes($msg2);
  echo "<hr /><b>Context of the error</b><br />".$dest."<br />".$source."<br />".$browser."<br />".$addr_ip."<br />".$domaine;

  if ($with_mail) {
	eMailHtmlTo(
	  $site[0]." : ERROR ".$err,
	  "Site : ".$site[0]."<br />ERROR ".$err." : ".$msg0."<br />".$date."<br />".$dest."<br />".$source."\n".$browser."<br />".$addr_ip."<br />".$domaine,
	  "");
	echo "<br /><b>This context has been recorded and communicated to the webmaster.</b>";
  }
  btable();
  include("inc/bpage.inc");
}
?>
