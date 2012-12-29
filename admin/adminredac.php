<?php
/*
    AdminRedac Main page - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v4.0 (06 December 2004)    : initial release (by Nicolas Alves)
      	                           insert planner management (by Nicolas Alves)
                        		   Optimized Html tags (by Icare)
      v4.5 (2 June 2005)         : Show only writer rights given by Admin (by SLLS, Guppy NL)
                                   Script optimization (by Icare)
      v4.6.0 (04 June 2007)      : Changed Forum Topics by Forum Config (by Icare)
                                   Add writers access to the plugins (by Hpsam)
                                   added fieldset and reordered icons list (by Icare)
      v4.6.7 (30 April 2008)     : don't display useless icons (by JeanMi)
      v4.6.8 (10 May 2008)       : corrected plugins process (by JeanMi)
      v4.6.9 (25 December 2008)  : correction of test for RSS #231
                                 : move of the function ShowBlock to functions.php #221
      v4.6.10 (7 September 2009) : corrected #266 and #269
	  v4.6.19 (30 March 2012)    : add social networks by Saxbar
*/

if (stristr($_SERVER["SCRIPT_NAME"], "adminredac.php")) {
  header("location:../index.php");
  die();
}

if ($selskin == "") $selskin = $userprefs[10];

echo '
<div align="center">
  <p><strong>'.$admin2.'</strong><br />
  '.$admin3.'<br />
  '.$admin4.'<br />
  </p>
  <hr />
    <strong><a href="admin.php?lng='.$lng.'&amp;logout=1">'.$admin19.'</a></strong>
  <hr />
</div>
<br />';

if (($drtuser[1] == "" && $drtuser[5] == "" && $drtuser[43] == ""))  {}
else {
$skintheme = ExploreDir('skin/');
}
$items = array();
if ($drtuser[1] != "")                          $items[] = array('txt'=>$admin888, 'href'=>'config9', 'src'=>'config2');
if ($drtuser[1] != "")                          $items[] = array('txt'=>$admin890, 'href'=>'config2', 'src'=>'config9');
if ($drtuser[5] != "")                          $items[] = array('txt'=>$admin346, 'href'=>'config6');
if ($drtuser[43] != "")                         $items[] = array('txt'=>$admin719, 'href'=>'config8', 'src'=>'css');

ShowBlock($admin725, $items, $skintheme);


$items = array();
if ($drtuser[0] != "")                          $items[] = array('txt'=>$admin7, 'href'=>'config1');
if ($drtuser[4] != "")                          $items[] = array('txt'=>$admin169, 'href'=>'config5');
if ($drtuser[3] != "")                          $items[] = array('txt'=>$admin166, 'href'=>'config4');
if ($drtuser[2] != "")                          $items[] = array('txt'=>$admin469, 'href'=>'config3');
if ($drtuser[24] != "" && $serviz[13] == 'on')  $items[] = array('txt'=>$admin253, 'href'=>'config7');
if ($drtuser[7] != ""  && $serviz[13] == 'on')  $items[] = array('txt'=>$admin577, 'href'=>'archive');
if ($drtuser[10] != "")                         $items[] = array('txt'=>$admin816, 'href'=>'members');
if ($drtuser[12] != "" && $serviz[42] == 'on')  $items[] = array('txt'=>$admin818, 'href'=>'droits');
if ($drtuser[8] != "")                          $items[] = array('txt'=>$admin278, 'href'=>'dbcheck');
if ($drtuser[6] != "")                          $items[] = array('txt'=>$admin170, 'href'=>'maintain');
if ($drtuser[11] != "")                         $items[] = array('txt'=>$admin817, 'href'=>'maintenance');
                                                $items[] = array('txt'=>$admin276, 'href'=>'about');

ShowBlock($admin881, $items);


$items = array();
if ($drtuser[13] != "")                         $items[] = array('txt'=>$admin8, 'href'=>'homepg', 'src'=>'edito');
if ($drtuser[14] != "" && $serviz[8] == 'on')   $items[] = array('txt'=>$admin13, 'href'=>'news');
if ($drtuser[15] != "")                         $items[] = array('txt'=>$admin5, 'href'=>'art&amp;tri=ch', 'src'=>'article');
if ($drtuser[16] != "" && $serviz[29] != '')    $items[] = array('txt'=>$admin476, 'href'=>'react');

if ($drtuser[17] != "")                         $items[] = array('txt'=>$admin16, 'href'=>'special', 'src'=>'spe');
if ($drtuser[18] != "" && $serviz[9] == 'on')   $items[] = array('txt'=>$admin322, 'href'=>'photo');
if ($drtuser[19] != "" && $serviz[10] == 'on')  $items[] = array('txt'=>$admin18, 'href'=>'dnload', 'src'=>'download');
if ($drtuser[20] != "" && $serviz[11] == 'on')  $items[] = array('txt'=>$admin10, 'href'=>'links');

if ($drtuser[21] != "" && $serviz[14] == 'on')  $items[] = array('txt'=>$admin206, 'href'=>'faq');
if ($drtuser[22] != "" && $serviz[12] == 'on')  $items[] = array('txt'=>$admin11, 'href'=>'guestbk', 'src'=>'guestbook');
if ($drtuser[23] != "" && $serviz[13] == 'on')  $items[] = array('txt'=>$admin9, 'href'=>'forum&amp;tri=-ch', 'src'=>'forum');
if ($drtuser[25] != "" && $serviz[23] == 'on')  $items[] = array('txt'=>$admin15, 'href'=>'poll');

if ($drtuser[26] != "")                         $items[] = array('txt'=>$admin270, 'href'=>'freebox');
if ($drtuser[44] != '')                         $items[] = array('txt'=>$admin952, 'href'=>'socnet');
if ($drtuser[27] != "" && $serviz[19] == 'on')  $items[] = array('txt'=>$admin263, 'href'=>'banner'); /// $serviz[19] est toujours à 'on'
if ($drtuser[28] != "" && $serviz[0] == 'on')   $items[] = array('txt'=>$admin6, 'href'=>'think'); /// $serviz[0] est toujours à 'on'
if ($drtuser[29] != "")                         $items[] = array('txt'=>$admin14, 'href'=>'footer', 'src'=>'foot');

if ($drtuser[30] != "")                         $items[] = array('txt'=>$admin249, 'href'=>'reco');
if ($drtuser[31] != "")                         $items[] = array('txt'=>$admin17, 'href'=>'count', 'src'=>'counter');
if ($drtuser[32] != "")                         $items[] = array('txt'=>$admin212, 'href'=>'stats');
if ($drtuser[33] != "" && $serviz[36] != '')    $items[] = array('txt'=>$admin546, 'href'=>'newsletter');

if ($drtuser[34] != "" && $serviz[27] == 'on')  $items[] = array('txt'=>$admin602, 'href'=>'rss', 'src'=>'newsrss');
if ($drtuser[35] != "")                         $items[] = array('txt'=>$admin553, 'href'=>'logbook', 'src'=>'eye');
if ($drtuser[36] != "")                         $items[] = array('txt'=>$admin171, 'href'=>'upload');
if ($drtuser[37] != "" && $serviz[47] == 'on')  $items[] = array('txt'=>$admin624, 'href'=>'agenda');

if ($drtuser[39] != "" && $serviz[53] == 'on')  $items[] = array('txt'=>$admin770, 'href'=>'blog&amp;tri=ch', 'src'=>'blog');
if ($drtuser[40] != "" && $serviz[53] == 'on')  $items[] = array('txt'=>$admin774, 'href'=>'reblog');
if ($drtuser[41] != "" && $serviz[53] == 'on')  $items[] = array('txt'=>$admin791, 'href'=>'bss', 'src'=>'blogrss');
ShowBlock($admin882, $items);

$pluginlist = array();
$dossier = opendir("plugins/");
while ($fichier = readdir($dossier)) {
    if ($fichier != "." && $fichier != ".." && is_dir(CHEMIN."plugins/".$fichier) && $drtuserplg[$fichier] != '') {
        $pluginlist[] = $fichier;
    }
}
closedir($dossier);
@sort($pluginlist);

if (!empty($pluginlist)) {
    $items = array();
    echo '<div style="width:540px;margin:0 auto;">';
    foreach ($pluginlist as $item) {
        if(is_file("plugins/".$item."/plugin.inc")) {
            $plugin_admin_name = '';
            include("plugins/".$item."/plugin.inc");
            if ($plugin_admin_name != '') {
                $items[] = array('txt'=>$plugin_admin_name, 'href'=>'plugin&amp;plug='.$plugin_admin_url, 'src'=>'plugins/'.$plugin_admin_icon);
            }
        }
    }
    echo '</div>';
    ShowBlock($admin883, $items);
}

unset($items);
