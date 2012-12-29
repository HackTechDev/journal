<?php
/*
    Admin Boxes disposition - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v2.2 (22 April 2003)     : initial release (by Nicolas Alves and Laurent Duveau)
      v2.3 (27 July 2003)      : added dynamic menu option
                                 added a calendar box (by Nicolas Alves)
                                 added quotations style management (by Nicolas Alves and Isabelle)
                                 added forms style management (by Nicolas Alves)
                                 added user prefs management by cookie
                                 added US date format management
                                 added user news submission option (no more mandatory)
      v2.4 (24 September 2003) : added "Page loading" popup
                                 added forum summary in home page (last threads)
                                 added Guestbook favourite message on home page
                                 added homepage choice of central boxes
                                 config5 renamed to config6
                                 added react to an article option
                                 added option for choosing Articles mark (thanks Pavol)
                                 recycled $texte[3] to Articles mark (was no more used)
                                 added Hide Admin Button (by Nicolas Alves)
                                 added Quick Article Admin Access (by Nicolas Alves)
                                 added number of times an article was read (by Nicolas Alves and Laurent Duveau)
                                 added number of times a forum thread was read (by Nicolas Alves and Laurent Duveau)
                                 added number of times a file was downloaded (by Nicolas Alves and Laurent Duveau)
                                 added new dates formats and created time formats
                                 created shared Config Update script
                                 added 3 additional free boxes (by Nicolas Alves and Laurent Duveau)
      v3.0 (25 February 2004)    : added Newsletter
                                   added Plugin Management
                                   added dynamic list menu (thanks Graznok)
                                   added RSS News management
      v4.0 (06 December 2004)    : added new usuals fonts in selector (by Isa)
	                               added page title (by jean-Mi)
		                           added multi-admin management (by Nicolas Alves)
	  v4.6.0 (04 June 2007)      : added fieldset, new boxes and reorganization (by Icare)
	  v4.6.4 (30 September 2007) : deletion of duplicate > in disconnect, thanks Balou
	  v4.6.6 (14 April 2008)     : corrected 2 syntax errors (by JeanMi)
      v4.6.10 (7 September 2009) : corrected W3C
	  v4.6.19 (30 March 2012)    : add social networks by Saxbar
*/

if (stristr($_SERVER['SCRIPT_NAME'], 'config6.inc')) {
  header('location:../index.php');
  die();
}

// FONCTIONS DE MISE EN PAGE /////////////////////////////////////////////////////////////////////////
function legend($legend) {
	return '<legend style="font-weight:bold;margin-left:30px;padding:0 4px;">'.$legend.'</legend>'."\n";
}
//////////////////////////////////////////////////////////////////////////////////////////////////////

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
  include(REDACREP.$userprefs[1].INCEXT);
  if ($drtuser[5]=='') {
    $nomzone=$admin346;
    include('access.inc');
    exit();
  }
}


###############################################################################
function WriteSelect($name, $value, $boxes, $labels, $center=false, $border=false) {
  $style = '';
  if ($center && !$border) {
    $style = ' style="text-align:center;"';
  } elseif (!$center && $border) {
    $style = ' class="quest"';
  } elseif ($center && $border) {
    $style = ' class="quest" style="text-align:center;"';
  }
  echo '
        <p'.$style.'>
          <select name="'.$name.'" style="width:150px;">';
  for ($i = 0; $i < count($boxes); $i++) {
    $sel = ($value == $boxes[$i]) ? ' selected="selected"' : '';
    echo '
            <option value="'.$boxes[$i].'"'.$sel.'>'.$labels[$i].'</option>';
  }
  echo '
          </select>
        </p>';
}
###############################################################################
function TestPos(&$array, $min, $free=0) {
  if ($free != 0) {
    /// on modifie le tableau pour qu'il y ait $free emplacements libres en fin de tableau
    $nfree = 0;
    foreach ($array as $item) {
      if ($item == '') $nfree++; else $nfree = 0;
    }
    if ($nfree < $free) {
      /// on ajoute les emplacements manquants
      while ($nfree < $free) {
        $array[] = '';
        $nfree++;
      }
    } elseif ($nfree > $free) {
      /// on supprime les emplacements surnuméraires
      while ($nfree > $free) {
        array_pop($array);
        $nfree--;
      }
    }
  }
  /// on ajoute des emplacements s'il ni en a pas le nombre minimal $min
  while(count($array) < $min) $array[] = '';
}
###############################################################################

if ($regit == 1) {
  $messreg = ' : &nbsp;OK';
  include(CONFIG);
  $meskin = CHEMIN.'skin/'.$selskin.'/';
  if (is_file ($meskin.'confskin.inc'))
    include ($meskin.'confskin.inc');
  else
    include(CHEMIN.'skin/no_skin/confskin.inc');

  $testposbox = array_merge($xpb["L"], $xpb["R"], $xpb["C"], $xpb["B"]);

  $serviz3  = in_array('inc/boxartg',    $testposbox) ? 'on' : '';
  $serviz22 = in_array('inc/boxartd',    $testposbox) ? 'on' : '';
  $serviz23 = in_array('inc/boxpoll',    $testposbox) ? 'on' : '';
  $serviz28 = in_array('inc/boxuser',    $testposbox) ? 'on' : '';
  $serviz38 = in_array('inc/boxrss',     $testposbox) ? 'on' : '';

  unset($testposbox);

  $serviz[3] = $serviz3; // Boite Articles gauche ON / OFF
  $serviz[22] = $serviz22; // Boite Articles droit ON / OFF
  $serviz[23] = $serviz23; // Sondage ON / OFF
  $serviz[28] = $serviz28; // Préférences visiteurs
  $serviz[38] = $serviz38; // RSS News ON / OFF

  $posbox[0] = $xpb["L"][0]; // Première boite à gauche
  $posbox[1] = $xpb["R"][0]; // Première boite à droite
  $posbox[2] = $xpb["L"][1]; // Seconde boite à gauche
  $posbox[3] = $xpb["R"][1]; // Seconde boite à droite
  $posbox[4] = $xpb["L"][2]; // Troisième boite à gauche
  $posbox[5] = $xpb["R"][2]; // Troisième boite à droite
  $posbox[6] = $xpb["L"][3]; // Quatrième boite à gauche
  $posbox[7] = $xpb["R"][3]; // Quatrième boite à droite
  $posbox[8] = $xpb["L"][4]; // Cinquième boite à gauche
  $posbox[9] = $xpb["R"][4]; // Cinquième boite à droite
  $posbox[10] = $xpb["L"][5]; // Sixième boite à gauche
  $posbox[11] = $xpb["R"][5]; // Sixième boite à droite
  $posbox[12] = $xpb["L"][6]; // Septième boite à gauche
  $posbox[13] = $xpb["R"][6]; // Septième boite à droite
  $posbox[14] = $xpb["L"][7]; // Huitième boite à gauche
  $posbox[15] = $xpb["R"][7]; // Huitième boite à droite
  $posbox[16] = $xpb["L"][8]; // Neuvième boite à gauche
  $posbox[17] = $xpb["R"][8]; // Neuvième boite à droite
  $posbox[18] = $xpb["L"][9]; // Dixième boite à gauche
  $posbox[19] = $xpb["R"][9]; // dixième boite à droite
  $posbox[20] = $xpb["C"][0]; // Boite supplémentaire centrale
  $posbox[21] = $xpb["B"][0]; // Boîte supplémentaire bas de page

  $posbox[30] = $posbox30; // Emplacement logo 1
  $posbox[31] = $posbox31; // Emplacement bannières
  $posbox[32] = $posbox32; // Emplacement citations
  $posbox[33] = $posbox33; // Emplacement logo 2
  $posbox[34] = $posbox34; // Emplacement menu icônes

  $xposbox = $xpb;
  unset($xpb);

  include("inc/confskin.inc");
}

include(CONFIG);
$meskin = CHEMIN.'skin/'.$selskin.'/';
if (is_file ($meskin.'confskin.inc'))
  include ($meskin.'confskin.inc');
else
  include(CHEMIN.'skin/no_skin/confskin.inc');

if (!isset($xposbox)) {
  $xposbox["L"][0] = $posbox[0] ;
  $xposbox["R"][0] = $posbox[1] ;
  $xposbox["L"][1] = $posbox[2] ;
  $xposbox["R"][1] = $posbox[3] ;
  $xposbox["L"][2] = $posbox[4] ;
  $xposbox["R"][2] = $posbox[5] ;
  $xposbox["L"][3] = $posbox[6] ;
  $xposbox["R"][3] = $posbox[7] ;
  $xposbox["L"][4] = $posbox[8] ;
  $xposbox["R"][4] = $posbox[9] ;
  $xposbox["L"][5] = $posbox[10];
  $xposbox["R"][5] = $posbox[11];
  $xposbox["L"][6] = $posbox[12];
  $xposbox["R"][6] = $posbox[13];
  $xposbox["L"][7] = $posbox[14];
  $xposbox["R"][7] = $posbox[15];
  $xposbox["L"][8] = $posbox[16];
  $xposbox["R"][8] = $posbox[17];
  $xposbox["L"][9] = $posbox[18];
  $xposbox["R"][9] = $posbox[19];
  $xposbox["C"][0] = $posbox[20];
  $xposbox["B"][0] = $posbox[21];
}
TestPos($xposbox["L"], 10, 3);
TestPos($xposbox["R"], 10, 3);
if (count($xposbox["L"]) != count($xposbox["R"])) {
  /// il faut qu'il y ait autant d'emplacements à gauche et à droite
  if (count($xposbox["L"]) > count($xposbox["R"]))
    TestPos($xposbox["R"], count($xposbox["L"]));
  else
    TestPos($xposbox["L"], count($xposbox["R"]));
}
TestPos($xposbox["C"], 2, 2);
TestPos($xposbox["B"], 2, 2);

$topmess = $admin350;
include(CHEMIN.'inc/hpage.inc');
htable($admin350, '100%');

$toplabelslist = array("$admin335","$admin879","$admin263","$admin6","$admin876","$admin952");
$topboxeslist = array("","inc/boxlogo","inc/boxban","inc/boxcita","inc/boxmenu","inc/boxsocnet");
$labelslist = array("$admin335", "$admin880","$admin361","$admin362","$admin363","$admin364","$admin365","$admin496","$admin497","$admin498","$admin366","$admin367","$admin369","$admin408","$admin450","$admin547","$admin609","$admin952");
$boxeslist = array('', 'inc/boxmenu', 'inc/boxartg', 'inc/boxartd', 'inc/boxspec', 'inc/boxsearch', 'inc/boxfree1', 'inc/boxfree2', 'inc/boxfree3', 'inc/boxfree4', 'inc/boxpoll', 'inc/boxwebm', 'inc/boxcount', 'inc/boxcal', 'inc/boxuser', 'inc/boxnewslet', 'inc/boxrss','inc/boxsocnet');
$centerlabelslist = array("$admin335","$admin363","$admin365","$admin496","$admin497","$admin498","$admin952");
$centerboxeslist = array('', 'inc/boxspec', 'inc/boxfree1', 'inc/boxfree2', 'inc/boxfree3', 'inc/boxfree4','inc/boxsocnet');
$bottomlabelslist = array("$admin335","$admin879","$admin263","$admin6","$admin876","$admin363","$admin365","$admin496","$admin497","$admin498");
$bottomboxeslist = array('', 'inc/boxlogo', 'inc/boxban', 'inc/boxcita', 'inc/boxmenu', 'inc/boxspec', 'inc/boxfree1', 'inc/boxfree2', 'inc/boxfree3', 'inc/boxfree4');
include('plugins/plugbox.inc');
if (isset($selskin)) $skn = '&amp;selskin='.$selskin;

  echo '
<div  style="text-align:center">
<p>  <br />'.$admin351.'<br /><br /></p>
<hr />
<a href="admin.php?lng='.$lng.$skn.'">'.$admin22.'</a> || <b><a href="admin.php?lng='.$lng.'&amp;logout=1">'.$admin19.'</a></b>
<hr /><br /><br />
<div style="width:100%;margin-left:auto;margin-right:auto;text-align:center">
<fieldset class="forum">'.$admin725.' &nbsp; '.$userprefs[10].$messreg.'<br />
</fieldset>
<form name="conf6" action="admin.php?lng='.$lng.'" method="post">
<p style="text-align:center">'.$boutonleft.'<button type="submit" title="'.$admin66.'">'.$admin66.'</button>'.$boutonright.'</p>
<input type="hidden" name="pg" value="config6" />
<input type="hidden" name="regit" value="1" />
<input type="hidden" name="selskin" value="'.$selskin.'" />';

############ Entête #########################
  echo '
<fieldset>
  '.legend(strtoupper($web136)).'
  <table style="width:100%;text-align:center" cellspacing="2" cellpadding="2" border="0" summary="">
    <tr class="quest" align="center">
      <td style="width:30%; text-align:left; padding-left: 4px;">';
  WriteSelect('posbox30', $posbox[30], $topboxeslist, $toplabelslist);
  echo '
      </td>
      <td style="width:70%; text-align:center;">';
  WriteSelect('posbox31', $posbox[31], $topboxeslist, $toplabelslist, true);
  echo '
      </td>
    </tr>
    <tr class="quest" style="text-align:center;">
      <td colspan="2">';
  WriteSelect('posbox32', $posbox[32], $topboxeslist, $toplabelslist, true);
  echo '
      </td>
    </tr>
    <tr class="quest" style="text-align:center">
      <td style=" text-align:left; padding-left: 4px;">';
  WriteSelect('posbox33', $posbox[33], $topboxeslist, $toplabelslist);
  echo '
      </td>
      <td>';
  WriteSelect('posbox34', $posbox[34], $topboxeslist, $toplabelslist, true);
  echo '
      </td>
    </tr>
  </table>
</fieldset>
<br />';
############ Fin entête #########################

  echo '
<fieldset>
  '.legend($admin83).'
  <table cellspacing="2" cellpadding="2" style="text-align:center; width:100%;" border="0" summary="">
    <tr>
      <td width="25%">
        <p style="text-align:center;font-weight:bold">'.$admin337.'</p>
      </td>
      <td width="50%">
        <p style="text-align:center;font-weight:bold">'.$admin877.'</p>
      </td>
      <td width="25%">
        <p style="text-align:center;font-weight:bold">'.$admin338.'</p>
      </td>
    </tr>

    <tr class="quest">
      <td>';
  for($i=0; $i<count($xposbox["L"]); $i++) {
    WriteSelect('xpb[L]['.$i.']', $xposbox["L"][$i], $boxeslist, $labelslist, true, true);
  }
  echo '
      </td>
      <td>
        <p style="text-align:center;height:130px">&nbsp;</p>
        <p style="text-align:center;font-weight:bold;">'.$admin878.'</p>
        <p style="text-align:center;height:130px;">&nbsp;</p>
        ';
  for($i=0; $i<count($xposbox["C"]); $i++) {
    WriteSelect('xpb[C]['.$i.']', $xposbox["C"][$i], $centerboxeslist, $centerlabelslist, true, true);
  }
  echo '
      </td>
      <td>';
  for($i=0; $i<count($xposbox["R"]); $i++) {
    WriteSelect('xpb[R]['.$i.']', $xposbox["R"][$i], $boxeslist, $labelslist, true, true);
  }
  echo '
      </td>
      </tr>
      <tr class="quest" align="center">
        <td colspan="3" style="text-align:center; padding: 4px;">';
  for($i=0; $i<count($xposbox["B"]); $i++) {
    WriteSelect('xpb[B]['.$i.']', $xposbox["B"][$i], $bottomboxeslist, $bottomlabelslist, true);
  }
  echo '
      </td>
    </tr>
  </table>
</fieldset>';

echo '
<br />
<p style="text-align:center">'.$boutonleft.'<button type="submit" title="'.$admin66.'">'.$admin66.'</button>'.$boutonright.'</p>
</form>
</div>
</div>
<hr />
<p style="text-align:center">
<a href="admin.php?lng='.$lng.(isset($selskin) ? '&amp;selskin='.$selskin : '').'">'.$admin22.'</a> || <b><a href="admin.php?lng='.$lng.'&amp;logout=1">'.$admin19.'</a></b>
</p>';

btable();
include(CHEMIN."inc/bpage.inc");
