<?php
/*
    Menu Box - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.6.0 (02 April 2007)     : initial release extracted from hpage.inc (by Icare)
                                   total new release (by djchouix))
      v4.6.3 (30 August 2007)    : corrected alt tags (by Icare)
                                   added lang verification, thanks JeanMi
      v4.6.9 (25 December 2008)  : correction of the activation of the items of the principal menu #224
	  v4.6.20 (24 May 2012)      : corrected btable1 (by Saxbar)

*/
if (stristr($_SERVER["SCRIPT_NAME"], "boxmenu.inc")) {
  header("location:../index.php");
  die();
}

/****************************************************************************************************************************
 * Initialisation des variables et du tableau des Sections
 */
$menu = array();

$i = ($lng == $lang[0])? 0 : 10;	// Indice pour le nom des sections
$j = ($lng == $lang[0])? 0 : 1;		// Indice pour le nom des sections et le titre de la boite latérale (cf : inc/boxlang.inc)
$title_menu = $nom[$j+44];
//Flags Langue
if ($lang[1] != '' && is_file(CHEMIN."inc/boxlang.inc")) {
	include CHEMIN."inc/boxlang.inc";
}

$parse_url = parse_url($site[3]);
$base_current = substr($_SERVER["SCRIPT_NAME"], strlen($parse_url['path']));

//Home
if ($serviz[1] == 'on') {
  $menu[$nom[$i+0].'_home'] = array(
    'id' => 'home',
    'name' => $nom[$i+0],
    'icon' => 'inc/img/icons/'.$page[9].'/home.gif',
    'url' => 'index.php'
  );
}
//News
if ($serviz[8] == 'on') {
	$menu[$nom[$i+7].'_news'] = array(
		'id' => 'news',
		'name' => $nom[$i+7],
		'icon' => 'inc/img/icons/'.$page[9].'/news.gif',
		'url' => 'news.php'
	);
}
//photorama
if ($serviz[9] == 'on') {
	$photoName = ($serviz[21] == 'on')? 'photorama' : 'photos';
	$menu[$nom[$i+2].'_photo'] = array(
		'id' => 'photo',
		'name' => $nom[$i+2],
		'icon' => 'inc/img/icons/'.$page[9].'/photo.gif',
		'url' => $photoName.'.php'
	);
}
//Blog
if ($serviz[53] == 'on') {
	$menu[$nom[$j+42].'_blog'] = array(
		'id' => 'blog',
		'name' => $nom[$j+42],
		'icon' => 'inc/img/icons/'.$page[9].'/blog.gif',
		'url' => 'blogs.php',
		'alturls' => array('blog.php')
	);
}
//Download
if ($serviz[10] == 'on') {
	$menu[$nom[$i+1].'_download'] = array(
		'id' => 'download',
		'name' => $nom[$i+1],
		'icon' => 'inc/img/icons/'.$page[9].'/download.gif',
		'url' => 'download.php'
	);
}
//Link
if ($serviz[11] == 'on') {
	$menu[$nom[$i+3].'_links'] = array(
		'id' => 'links',
		'name' => $nom[$i+3],
		'icon' => 'inc/img/icons/'.$page[9].'/links.gif',
		'url' => 'links.php'
	);
}
//FAQ
if ($serviz[14] == 'on') {
	$menu[$nom[$j+24].'_faq'] = array(
		'id' => 'faq',
		'name' => $nom[$j+24],
		'icon' => 'inc/img/icons/'.$page[9].'/faq.gif',
		'url' => 'faq.php'
	);
}
//Guestbook
if ($serviz[12] == 'on') {
	$menu[$nom[$i+9].'_guestbk'] = array(
		'id' => 'guestbook',
		'name' => $nom[$i+9],
		'icon' => 'inc/img/icons/'.$page[9].'/guestbook.gif',
		'url' => 'guestbk.php'
	);
}
//Forum
if ($serviz[13] == 'on') {
	$forumName = ($serviz[18] == 'on')? 'fortopic' : 'forum';
	$menu[$nom[$j+22].'_forum'] = array(
		'id' => 'forum',
		'name' => $nom[$j+22],
		'icon' => 'inc/img/icons/'.$page[9].'/forum.gif',
		'url' => $forumName.'.php',
		'alturls' => array('forum.php', 'thread.php')
	);
}
//Stats
if ($serviz[15] == 'on') {
	$menu[$nom[$j+26].'_stats'] = array(
		'id' => 'stats',
		'name' => $nom[$j+26],
		'icon' => 'inc/img/icons/'.$page[9].'/stats.gif',
		'url' => 'stats.php'
	);
}

//Admin
$menu_admin = array();
if ($serviz[45] == '') {
	$menu_admin = array(
		'id' => 'admin',
		'name' => $web144,
		'icon' => 'inc/img/icons/'.$page[9].'/admin.gif',
		'url' => 'admin/admin.php'
	);
}

//Plugins
if (is_file(CHEMIN."inc/hplugins.inc")) {
	include CHEMIN."inc/hplugins.inc";
}

//Tri des sections par ordre alphabétique
ksort($menu);

/****************************************************************************************************************************
 * Construction et affichage du menu
 */

if (!isset($onemenu) || $onemenu ==0) { //Menu horizontal
	echo '
  <div class="menuIcons">
  <ul>';

	//Admin
	if ($serviz[45] == '') {
		// Class ajouté à la section du menu affichée
		$currentMenuClass = ($base_current == $menu_admin['url'])? ' current' : '';

		$contents = '<a href="'.CHEMIN.$menu_admin['url'].'?lng='.$lng.'" title="'.strip_tags($menu_admin['name']).'">';
		if($page[9] != '' && is_file(CHEMIN.$menu_admin['icon'])) {
			$contents .= '<img src="'.CHEMIN.$menu_admin['icon'].'" alt="'.strip_tags($menu_admin['name']).'" title="'.strip_tags($menu_admin['name']).'" border="0" '.(($page[20] != '')? 'class="imgover"' : '').' />';
		}
		$contents .= '<span class="name_'.$menu_admin['id'].$currentMenuClass.'">'.$menu_admin['name'].'</span>';
		$contents .= '</a>';

		echo '
      <li class="menu_'.$menu_admin['id'].$currentMenuClass.'">'.$contents.'</li>';
	}

	//Flags
	if ($lang[1] != '') { //Présence d'une seconde langue
		echo '
      <li class="menu_flags">'.$flags.'</li>';
	}

	//Sections du menu
	$found_current = false;
	foreach ($menu as $section) {
		// Class ajouté à la section du menu affichée
        if ($currentMenuClass != '') {
            $found_current = true;
            $currentMenuClass = '';
        }
        if (!$found_current) {
    		if (!isset($section['alturls'])) {
    		    $currentMenuClass = ($base_current == $section['url'])? ' current' : '';
    		} else {
    		    $currentMenuClass = ($base_current == $section['url'])? ' current' : '';
                foreach($section['alturls'] as $url) {
                    if ($base_current == $url) {
                        $currentMenuClass = ' current';
                        break;
                    }
                }
    		}
		}

		if ($page[9] != '' || $section['name'] != '') {
			$contents = '<a href="'.CHEMIN.$section['url'].'?lng='.$lng.'" title="'.strip_tags($section['name']).'">';
			if($page[9] != '' && is_file(CHEMIN.$section['icon'])) {
				$contents .= '<img src="'.CHEMIN.$section['icon'].'" alt="'.strip_tags($section['name']).'" title="'.strip_tags($section['name']).'" border="0" '.(($page[20] != '')? 'class="imgover"' : '').' />';
			}
			if ($section['name'] != '') {
				$contents .= '<span class="name_'.$section['id'].$currentMenuClass.'">'.$section['name'].'</span>';
			}
			$contents .= '</a>';

			echo '
      <li class="menu_'.$section['id'].$currentMenuClass.'">'.$contents.'</li>';
		}
	}

	echo '
  </ul>
  </div>
  <div style="clear:both;"></div>';

} else {  //Menu boite latérale

	htable1($title_menu);
	echo '
  <ul class="boxmenu">
	';

	//Sections du menu
	$found_current = false;
	$currentMenuClass = '';
	foreach ($menu as $section) {

		// Class ajouté à la section du menu affichée
        if ($currentMenuClass != '') {
            $found_current = true;
            $currentMenuClass = '';
        }
        if (!$found_current) {
    		if (!isset($section['alturls'])) {
    		    $currentMenuClass = ($base_current == $section['url'])? ' curr_item' : '';
    		} else {
    		    $currentMenuClass = ($base_current == $section['url'])? ' curr_item' : '';
                foreach($section['alturls'] as $url) {
                    if ($base_current == $url) {
                        $currentMenuClass = ' curr_item';
                        break;
                    }
                }
    		}
		}

		if ($page[9] != '' || $section['name'] != '') {
			$contents = '  <a href="'.CHEMIN.$section['url'].'?lng='.$lng.'" title="'.strip_tags($section['name']).'">';
			if($page[9] != '' && is_file(CHEMIN.$section['icon'])) {
				$contents .= '<img src="'.CHEMIN.$section['icon'].'" alt="'.strip_tags($section['name']).'" title="'.strip_tags($section['name']).'" border="0" '.(($page[20] != '')? 'class="imgover"' : '').' />';
			}
			if ($section['name'] != '') {
				$contents .= '<span class="name_'.$section['id'].$currentMenuClass.'">'.$section['name'].'</span>';
			}
			$contents .= '</a>';

			echo '
      <li class="menu_'.$section['id'].$currentMenuClass.'">'.$contents.'</li>';
		}
	}

	//Admin
	if ($serviz[45] == '') {
		// Class ajouté à la section du menu affichée
		$currentMenuClass = ($base_current == $menu_admin['url'])? ' curr_item' : '';

		$contents = ' <a href="'.CHEMIN.$menu_admin['url'].'?lng='.$lng.'" title="'.strip_tags($menu_admin['name']).'">';
		if ($page[9] != '' && is_file(CHEMIN.$menu_admin['icon'])) {
			$contents .= '<img src="'.CHEMIN.$menu_admin['icon'].'" alt="'.strip_tags($menu_admin['name']).'" title="'.strip_tags($menu_admin['name']).'"border="0" '.(($page[20] != '')? 'class="imgover"' : '').' />';
		}
		$contents .= '<span class="name_'.$menu_admin['id'].$currentMenuClass.'">'.$menu_admin['name'].'</span>';
		$contents .= '</a>';

		echo '
    <li class="menu_'.$menu_admin['id'].$currentMenuClass.'">'.$contents.'</li>';
	}

	echo '
  </ul>';
	btable1($title_menu);
}
?>
