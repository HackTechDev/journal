<?php
/* 
correction du .htaccess
  v4.6.21a (23 October 2012) : update .htaccess (thanks JeanMi, Saxbar)
*/

header('Pragma: no-cache');
define('CHEMIN', '');
include 'inc/includes.inc';

include 'inc/hpage.inc';
htable('Mise à jour du fichier .htaccess', '100%');

$c = file_get_contents('.htaccess');/// Lire .htaccess
$c = str_replace(
    '<Files ~ "^.*\.(inc|dtb)">',   /// Ligne avant modif
    '<Files ~ "\.(inc|dtb)$">',     /// Ligne après modif
    $c );
file_put_contents('.htaccess', $c); /// Ecrire .htaccess

echo '
<div style="text-align:center;padding:12px;">
  Votre version de GuppY : <b>'.$mpversion.'</b><br /><br />
  Mise à jour terminée.<br /><br />
  <form name="retour" action="'.$site[3].'index.php?lng='.$lng.'" method="POST">'.
    $boutonleft.'<button type="submit">Retour à la page d\'accueil</button>'.$boutonright.'
  </form>
</div>';

btable();
include 'inc/bpage.inc';
?>
