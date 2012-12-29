<?php
/*
    PHP Register Globals Off Solving - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v3.0 (25 February 2004)  : initial release for compatibility with php.ini register_globals=off parameter management (thanks JonnyQuest)
      v3.0p3 (29 July 2004)    : security patch - thanks to L0rd L4m3R
      v4.5 (26 Mai 2005)       : new release (by Jean-Mi)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "reglobals.inc")) {
  header("location:../index.php");
  die();
}

error_reporting( E_ALL ^ E_NOTICE );

if ((substr(phpversion(),0,1) <= 3) || ((substr(phpversion(),0,1) == 4) && (substr(phpversion(),2,1) == 0))) {
  /// avant la 4.1.0, les variables _GET, _POST... n'existaient pas, nous les simulons
  if (isset($HTTP_GET_VARS))     $_GET     =& $HTTP_GET_VARS;
  if (isset($HTTP_POST_VARS))    $_POST    =& $HTTP_POST_VARS;
  if (isset($HTTP_ENV_VARS))     $_ENV     =& $HTTP_ENV_VARS;
  if (isset($HTTP_SERVER_VARS))  $_SERVER  =& $HTTP_SERVER_VARS;
  if (isset($HTTP_COOKIE_VARS))  $_COOKIE  =& $HTTP_COOKIE_VARS;
  if (isset($HTTP_SESSION_VARS)) $_SESSION =& $HTTP_SESSION_VARS;
  if (isset($HTTP_POST_FILES))   $_FILES   =& $HTTP_POST_FILES;
}
elseif ((version_compare(phpversion(), "5.0.0") == -1) && (@get_cfg_var("register_long_arrays") != 1)) {
  /// A partir de la version 5, si register_long_arrays est OFF, alors les variables HTTP_*_VARS 
  /// n'existent plus, nous les simulons
  /// Il faudra à  l'avenir, éliminer toutes utilisations des variables HTTP_*_VARS
  if (isset($_GET))     $HTTP_GET_VARS     =& $_GET;
  if (isset($_POST))    $HTTP_POST_VARS    =& $_POST;
  if (isset($_ENV))     $HTTP_ENV_VARS     =& $_ENV;
  if (isset($_SERVER))  $HTTP_SERVER_VARS  =& $_SERVER;
  if (isset($_COOKIE))  $HTTP_COOKIE_VARS  =& $_COOKIE;
  if (isset($_SESSION)) $HTTP_SESSION_VARS =& $_SESSION;
  if (isset($_FILES))   $HTTP_POST_FILES   =& $_FILES;
}
  
if (@get_cfg_var("register_globals") != 1) {
  /// Si register_globals est OFF, alors nous simulons le comportement register_globals = ON
  if (isset($_GET))     extract($_GET);
  if (isset($_POST))    extract($_POST);
  if (isset($_ENV))     extract($_ENV);
  if (isset($_SERVER))  extract($_SERVER);
  if (isset($_COOKIE))  extract($_COOKIE);
  if (isset($_SESSION)) extract($_SESSION);
  if (isset($_FILES))   extract($_FILES);
}

?>
