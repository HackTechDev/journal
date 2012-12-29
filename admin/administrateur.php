<?php
/*
    AdminWebmster Main page - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v4.0 (06 December 2004)     : initial release by Nicolas Alves
	                                  added planner management, changed counters management (by Nicolas Alves)
				                            Optimized html tags (by Icare)
      v4.6.0 (15 March 2007)      : Changed Forum Topics by Forum Config (by Icare)
                                    Corrected  opendir("plugins/") by opendir(CHEMIN."admin/plugins/")	(by Hpsam)
                                    added fieldset and reordered icons list (by Icare)
      v4.6.7 (30 April 2008)      : don't display useless icons (by JeanMi)
      v4.6.9 (25 December 2008)   : correction of test for RSS #231
                                    move of the function ShowBlock to functions.php #221
      v4.6.10 (7 September 2009)  : corrected #266
      v4.6.11 (11 December 2009)  : #313, added checking install directory by Icare (thanks Kamila)
	  v4.6.19 (30 March 2012)     : add social networks by Saxbar
*/

if (stristr($_SERVER["SCRIPT_NAME"], "administrateur.php")) {
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
<br />';
if (file_exists(CHEMIN."install/install.php")) {
  include ("inc/check_install.inc");
}
echo "</div>";
$skintheme = ExploreDir('skin/');
$items = array();
                            $items[] = array('txt'=>$admin888, 'href'=>'config9', 'src'=>'config2');
                            $items[] = array('txt'=>$admin890, 'href'=>'config2', 'src'=>'config9');
                            $items[] = array('txt'=>$admin346, 'href'=>'config6');
                            $items[] = array('txt'=>$admin719, 'href'=>'config8', 'src'=>'css');

ShowBlock($admin725, $items, $skintheme);


$items = array();
                            $items[] = array('txt'=>$admin7, 'href'=>'config1');
                            $items[] = array('txt'=>$admin169, 'href'=>'config5');
                            $items[] = array('txt'=>$admin166, 'href'=>'config4');
                            $items[] = array('txt'=>$admin469, 'href'=>'config3');
if ($serviz[13] == 'on')    $items[] = array('txt'=>$admin253, 'href'=>'config7');
if ($serviz[13] == 'on')    $items[] = array('txt'=>$admin577, 'href'=>'archive');
                            $items[] = array('txt'=>$admin816, 'href'=>'members');
if ($serviz[42] == 'on')    $items[] = array('txt'=>$admin818, 'href'=>'droits');
                            $items[] = array('txt'=>$admin12, 'href'=>'passwd', 'src'=>'password');
                            $items[] = array('txt'=>$admin278, 'href'=>'dbcheck');
                            $items[] = array('txt'=>$admin170, 'href'=>'maintain');
                            $items[] = array('txt'=>$admin817, 'href'=>'maintenance');
                            $items[] = array('txt'=>$admin276, 'href'=>'about');

ShowBlock($admin881, $items);


$items = array();
                            $items[] = array('txt'=>$admin8, 'href'=>'homepg', 'src'=>'edito');
if ($serviz[8] == 'on')     $items[] = array('txt'=>$admin13, 'href'=>'news');
                            $items[] = array('txt'=>$admin5, 'href'=>'art&amp;tri=ch', 'src'=>'article');
if ($serviz[29] != '')      $items[] = array('txt'=>$admin476, 'href'=>'react');

                            $items[] = array('txt'=>$admin16, 'href'=>'special', 'src'=>'spe');
if ($serviz[9] == 'on')     $items[] = array('txt'=>$admin322, 'href'=>'photo');
if ($serviz[10] == 'on')    $items[] = array('txt'=>$admin18, 'href'=>'dnload', 'src'=>'download');
if ($serviz[11] == 'on')    $items[] = array('txt'=>$admin10, 'href'=>'links');

if ($serviz[14] == 'on')    $items[] = array('txt'=>$admin206, 'href'=>'faq');
if ($serviz[12] == 'on')    $items[] = array('txt'=>$admin11, 'href'=>'guestbk', 'src'=>'guestbook');
if ($serviz[13] == 'on')    $items[] = array('txt'=>$admin9, 'href'=>'forum&amp;tri=-ch', 'src'=>'forum');
if ($serviz[23] == 'on')    $items[] = array('txt'=>$admin15, 'href'=>'poll');

                            $items[] = array('txt'=>$admin270, 'href'=>'freebox');
                            $items[] = array('txt'=>$admin952, 'href'=>'socnet');
if ($serviz[19] == 'on')    $items[] = array('txt'=>$admin263, 'href'=>'banner'); /// $serviz[19] est toujours à 'on'
if ($serviz[0] == 'on')     $items[] = array('txt'=>$admin6, 'href'=>'think'); /// $serviz[0] est toujours à 'on'
                            $items[] = array('txt'=>$admin14, 'href'=>'footer', 'src'=>'foot');

                            $items[] = array('txt'=>$admin249, 'href'=>'reco');
                            $items[] = array('txt'=>$admin17, 'href'=>'count', 'src'=>'counter');
                            $items[] = array('txt'=>$admin212, 'href'=>'stats');
if ($serviz[36] != '')      $items[] = array('txt'=>$admin546, 'href'=>'newsletter');

if ($serviz[27] == 'on')    $items[] = array('txt'=>$admin602, 'href'=>'rss', 'src'=>'newsrss');
                            $items[] = array('txt'=>$admin553, 'href'=>'logbook', 'src'=>'eye');
                            $items[] = array('txt'=>$admin171, 'href'=>'upload');
if ($serviz[47] == 'on')    $items[] = array('txt'=>$admin624, 'href'=>'agenda');

if ($serviz[53] == 'on')    $items[] = array('txt'=>$admin770, 'href'=>'blog&amp;tri=ch', 'src'=>'blog');
if ($serviz[53] == 'on')    $items[] = array('txt'=>$admin774, 'href'=>'reblog');
if ($serviz[53] == 'on')    $items[] = array('txt'=>$admin791, 'href'=>'bss', 'src'=>'blogrss');
ShowBlock($admin882, $items);

unset($items);
