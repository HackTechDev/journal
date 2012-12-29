<?php
/*
    Newsletter List - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2008 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v3.0 (25 February 2004)     : initial release by Nicolas Alves
      v4.0 (06 December 2004)     : added alt tags to img and removed border tag for non-linked img (by Isa)
                                    added multi-admin management (by Nicolas Alves)
				                            added page title (by Jean-Mi)
				                            changed link [Delete] by icon delete (by Icare)
		  v4.6.0 (04 June 2007)        : added email address checking (by JeanMi)
		  v4.6.3 (30 August 2007)      : added gethostbyname (by Icare)
		  v4.6.5 (05 December 2007)   : replacing button by input class=bouton (by Icare)
		  v4.6.9 (25 December 2008)   : correction of the function TestEmail #226
          v4.6.10 (7 September 2009)    : corrected #272
*/
if (stristr($_SERVER["SCRIPT_NAME"], "nwllist.inc")) {
  header("location:../index.php");
  die();
}

/// Nombre d'abonnés par page
///***************************
$nbpg = 15;

/// Textes utilisés
///****************
$state0 = '<br /><span style="color:red">'.$admin732.'</span>';
$state1 = '<br /><span style="color:red">'.$admin733.'</span>';
$state2 = '<br /><span style="color:green">'.$admin734.'</span>';
$state3 = '<br /><span style="color:black">'.$admin735.'</span>';
$state4 = '<br /><span style="color:black">'.$admin736.'</span>';
$state5 = '<br /><span style="color:green">'.$admin737.'</span>';

/// Fonctions de tri
///******************

function pseudo_sort($a, $b) {
  $a = strtolower($a[0]);
  $b = strtolower($b[0]);
  if ($a == $b) {
  } else {
    return $a < $b ? -1 : +1;
  }
}

function pseudo_rsort($a, $b) {
  return - pseudo_sort($a, $b);
}

function address_sort($a, $b) {
  $a[1] = strtolower($a[1]);
  $b[1] = strtolower($b[1]);
  list($an, $ad) = explode('@', $a[1]);
  list($bn, $bd) = explode('@', $b[1]);
  if ($ad == $bd) {
    if ($an == $bn) {
      return 0;
    } else {
      return $an < $bn ? -1 : +1;
    }
  } else {
    return $ad < $bd ? -1 : +1;
  }
}

function address_rsort($a, $b) {
  return - address_sort($a, $b);
}

/// Fonctions de vérification des adresses mail
///*********************************************

function TestEmail($email, $testserveur = '') {
  global $state0, $state1, $state2, $state3, $state4, $state5;
  $result = "";
  if (!function_exists('getmxrr')) $testserveur = '';

  $result = $state5;
  if (!preg_match("`^[a-zA-Z0-9][a-zA-Z0-9_-]*(?:\.[a-zA-Z0-9_-]+)*@[a-zA-Z0-9][a-zA-Z0-9-]*(?:\.[a-zA-Z0-9-]+)*\.[a-z]{2,6}$`", $email)) {
    $result = $state0;
  }
  if ($testserveur != '') {
    list($username, $domain ) = explode("@", $email);
    $verify = "on";
    $iphost = gethostbyname($domain);
    if ($iphost == $domain) {
      $result = '<br /><span style="color:red">Unknown domain</span>';
    }
    else {
    if (function_exists('checkdnsrr')) {
      # Construct array of available mailservers
      if (getmxrr($domain, $mxhosts, $mxweight)) {
        for($i=0;$i<count($mxhosts);$i++){
          $mxs[$mxhosts[$i]] = $mxweight[$i];
        }
        asort($mxs);
        $mailers = array_keys($mxs);
      }
      elseif(checkdnsrr($domain, 'A')) {
         $mailers[0] = gethostbyname($domain);
      }
      else {
       $mailers=array();
      }
      $result = $state4;
      $total = count($mailers);
      # Query each mailserver
      if ($total > 0 && $verify) {
        # Check if mailers accept mail
        for($n=0; $n < $total; $n++) {
          # Check if socket can be opened
          if ($debug) { echo "Checking server $mailers[$n]...<br />\n";}
          $connect_timeout = 2;
          $errno = 0;
          $errstr = 0;
          $probe_address = 'postmaster@'.$domain;
          # Try to open up socket
          if ($Connect = @fsockopen($mailers[$n], 25, $errno , $errstr, $connect_timeout)) {
            $Out = fgets($Connect, 1024);
            //echo $Out.'<br />';
            if (preg_match("!^220!", $Out)) {
              fputs ($Connect, 'HELO '.$_SERVER['HTTP_HOST']."\r\n");
              $Out = fgets ( $Connect, 1024 );
              fputs ($Connect, "MAIL FROM: <$email>\r\n");
              $From = fgets ( $Connect, 1024 );
              fputs ($Connect, "RCPT TO: <$email>\r\n");
              $To = fgets ($Connect, 1024);
              //echo $Out.'<br />';
              fputs ($Connect, "QUIT\r\n");
              fclose($Connect);
              if (preg_match ("!^250!", $To) || preg_match ( "!^251!", $To )) {
                $result=$state2;
                return $result;
                exit();
              }
              else {
                $result=$state1;

              }
            }
            else {
              $result = $state3;
            }
          }
          else {
            $result=$state4;
          }
        }
      }
      else {
        $result=$state4;
      }
    }
    }
  }

  return $result;
}


/// Début de la page
///******************
if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[33]=="") {
    $nomzone=$admin553;
    include("access.inc");
    exit();
  }
}

  header("Pragma: no-cache");
  $topmess = $admin542;
  define("CHEMIN", "../");
  include(CHEMIN . "inc/hpage.inc");
  $list = ReadDBFields(DBNEWSLETTER);
  /// Mémorisation de la position dans le fichier non trié utilisée pour les suppressions
  for ($i = 0; $i < count($list); $i++) {
    $list[$i][3] = $i;
  }

  /// Tri des abonnés
  ///*****************
  if (!isset($tri)) $tri = -1;
  switch ($tri) {
  case 1  : break;
  case -1 : $list = array_reverse($list); break;
  case 2  : usort($list, 'pseudo_sort'); break;
  case -2 : usort($list, 'pseudo_rsort'); break;
  case 3  : usort($list, 'address_sort'); break;
  case -3 : usort($list, 'address_rsort'); break;
  default :
    $tri = 1;
  }

  /// Suppression rapide d'abonnés
  ///******************************
  if ($action == "fastdel") {
    $list0 = ReadDBFields(DBNEWSLETTER);;
    $count = count($list);
    for ($i = ($idpg - 1)*$nbpg; $i < Min($nbpg*$idpg, $count); $i++) {
      if (${'s_'.$i} == 'on') {
        unset($list0[$list[$i][3]]);
        unset($list[$i]);
      }
    }
    $list = array_values($list);
    $list0 = array_values($list0);
    WriteDBFields(DBNEWSLETTER, $list0);
    unset($list0);
  }

  /// Affichage par page
  ///********************
  $count = count($list);
  if (!isset($idpg)) {
    $idpg = 1;
  } else {
    while ($count <= ($idpg - 1)* $nbpg) $idpg--;
  }

  /// Mode de vérification des email
  ///********************************
  if (!isset($testserveur)) {
    $testserveur = '';
  } else {
    if ($testserveur != '') $testserveur = 'on';
  }

  htable($admin542, "100%");
  echo '<p align="center">'.$admin541.'</p><br /><hr />
<p align="center">
<a href="'.CHEMIN.'admin/admin.php?lng='.$lng.'&amp;pg=newsletter">'.$admin535.'</a>
 || <a href="admin.php?lng='.$lng.'">'.$admin22.'</a>
 || <strong><a href="admin.php?lng='.$lng.'&amp;logout=1">'.$admin19.'</a></strong>
</p><hr />';


  if (empty($list)) {
    /// Liste vide
    ///************
    echo '
<table width="98%" summary="">
  <tr>
    <td align="center">
      <img src="'.CHEMIN.'inc/img/smileys/rolleyes.gif" alt="8-)" title="8-)" />
      <strong>'.$admin543.'</strong>
    </td>
  </tr>
</table>';

  } else {
    /// Liste non vide
    ///****************
    $tris = array (1=>$admin738, -1=>$admin739, 2=>$admin740, -2=>$admin741, 3=>$admin742, -3=>$admin743);
    $navbar = GetNavBar('admin.php?lng='.$lng.'&amp;pg=nwllist&amp;testserveur='.$testserveur.'&amp;tri='.$tri.'&amp;idpg=', $count, $idpg, $nbpg);
    echo '
<div style="text-align:center">
  <br />
  <fieldset><legend>'.$admin748.'</legend>
  <form name="nwlistsort" method="post" action="admin.php?lng='.$lng.'&amp;pg=nwllist">'.$admin744.'
    <select name="tri" style="vertical-align:middle">';
    foreach ($tris as $k=>$v) {
      echo '
      <option value="'.$k.'"'.($k == $tri ? ' selected="selected"' : '').'>'.($k == $tri ? '&bull; ' : '- ').$v.'</option>';
    }
    echo '
    </select>
    <br />
    <acronym title="'.$admin746.'">'.$admin745.' : </acronym>
    <input type="checkbox" name="testserveur"'.($testserveur == '' ? '' : ' checked').' style="vertical-align:middle" title="'.$admin746.'" />
    <br />
    <input type="hidden" name="idpg" value="'.$idpg.'" />
    '.$boutonleft.'<input class="bouton" type="submit" value="'.$admin747.'" />'.$boutonright.'
  </form>
  </fieldset><br />
</div>
<hr />
<div style="text-align:center">'.$navbar.'</div>
<hr />

<center>
<form name="nwlistdel" method="post" action="admin.php?lng='.$lng.'&amp;pg=nwllist">
<div align="right" style="width:80%; padding: 5px 60px 5px 0px">'
  .$boutonleft.'<input class="bouton" type="submit" value="'.$web361.'" />'.$boutonright.'
  <img src="'.CHEMIN.'inc/img/general/bas.gif" title="" alt="" />
</div>
<table cellpadding="4" cellspacing="0" width="80%" summary="">
  <tr class="forum2">
    <td width="30%"><strong>'.$admin517.'</strong></td>
    <td width="65%"><strong>'.$admin544.'</strong></td>
    <td width="5%"><strong>'.$admin186.'</strong></td>
  </tr>';

    for ($i = ($idpg - 1)*$nbpg; $i < Min($nbpg*$idpg, $count); $i++) {
      if ($i % 2 == 0)
        echo "<tr class=\"rep\">";
      else
        echo "<tr class=\"quest\">";

      echo '
    <td valign="top"><strong>'.$list [$i][0].'</strong></td>
    <td><strong>'.$list [$i][1].'</strong>'.TestEmail($list [$i][1], $testserveur).'</td>
    <td valign="top" align="center">';
      echo MakeRadioGroup(array(array('d', 's', $i)));
      echo '
    </td>
  </tr>';
    }

    echo '
</table>
<div align="right" style="width:80%; padding: 10px 55px 0px 0px">'
  .$boutonleft.'<input class="bouton" type="submit"  value="'.$web361.'" />'.$boutonright.'
  <img src="'.CHEMIN.'inc/img/general/up1.gif" align="top" alt="" title="" />
</div>
<input type="hidden" name="action" value="fastdel" />
<input type="hidden" name="idpg" value="'.$idpg.'" />
<input type="hidden" name="tri" value="'.$tri.'" />
<input type="hidden" name="testserveur" value="'.$testserveur.'" />
</form>
</center>';
  }

  echo '
<hr />
<div style="text-align:center">'.$navbar.'</div>
<hr />
<p align="center">
<a href="'.CHEMIN.'admin/admin.php?lng='.$lng.'&amp;pg=newsletter">'.$admin535.'</a>
 || <a href="admin.php?lng='.$lng.'">'.$admin22.'</a>
 || <strong><a href="admin.php?lng='.$lng.'&amp;logout=1">'.$admin19.'</a></strong>
</p>';
  btable();
  include(CHEMIN . "inc/bpage.inc");
?>
