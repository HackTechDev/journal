<?php
/*
    Functions for groups - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v4.6.15 (30 June 2011)      : initial release (by JeanMi)
      v4.6.16 (02 September 2011) : added functions IsValidForumCat, IsPrivateForumCat and ReadForumCats (by jchouix)
	  v4.6.18 (09 February 2012)  : corrected function IsPrivateForumCat() (by Saxbar)
	  v4.6.22 (29 December 2012)  : added pseudo-private group for members (by Saxbar)	  
*/

if (stristr($_SERVER["SCRIPT_NAME"], "functions.php")) {
  header("location:../index.php");
  die();
}

define ('GROUPS',  CHEMIN.DATAREP.'groups.dtb');
define ('MEMBERS', CHEMIN.DATAREP.'members.dtb');

/*******************************************************************************
 * Lecture du fichier GROUPS pour fournir un tableau associatif
 * dont l'index est le nom d'un groupe et
 * dont le contenu est la liste des membres de ce groupe
 *
 * return array
 ******************************************************************************/
function ReadGroups() {
    if (!File_Exists(GROUPS)) return array();
    $dbf = ReadDbFields(GROUPS);
    $grps = array();
    foreach($dbf as $f) {
        $grp = $f[0];
        unset($f[0]);
        $grps[$grp] = array_values($f);
    }
    return $grps;
}

/*******************************************************************************
 * Ecriture du fichier GROUPS
 * à partir du tableau associatif fourni par ReadGroups()
 *
 * param array $grps (une liste de groupes)
 * return void
 ******************************************************************************/
function WriteGroups($grps) {
    ksort($grps);
    $dbf = array();
    foreach ($grps as $grp=>$mbrs) {
        sort($mbrs);
        $dbf[] = array_merge(array($grp), $mbrs);
    }
    WriteDbFields(GROUPS, $dbf);
}

/*******************************************************************************
 * Lecture du fichier MEMBERS
 * pour fournir un tableau associatif
 * dont l'index est le nom d'un membre et
 * dont le contenu est la liste des groupes contenant ce membre
 *
 * return array
 ******************************************************************************/
function ReadMembers() {
    if (!File_Exists(MEMBERS)) return array();
    $dbf = ReadDbFields(MEMBERS);
    $mbrs = array();
    foreach($dbf as $f) {
        $mbr = $f[0];
        unset($f[0]);
        $mbrs[$mbr] = array_values($f);
    }
    return $mbrs;
}

/*******************************************************************************
 * Ecriture du fichier MEMBERS
 * à partir d'un tableau associatif fourni par ReadMembers()
 *
 * param array $mbrs (une liste de membres)
 * return void
 ******************************************************************************/
function WriteMembers($mbrs) {
    ksort($mbrs);
    $dbf = array();
    foreach ($mbrs as $mbr=>$grps) {
        sort($grps);
        $dbf[] = array_merge(array($mbr), $grps);
    }
    WriteDbFields(MEMBERS, $dbf);
}

/*******************************************************************************
 * Ajout d'un groupe dans le fichier GROUPS
 *
 * param string $grp (un nom de groupe)
 * return boolean (TRUE = réussite, FALSE = échec)
 ******************************************************************************/
function AddGroup($grp) {
	if ($grp == 'all_members') return FALSE;
    $grps = ReadGroups();
    if (array_key_exists($grp, $grps)) {
        return FALSE; // Le groupe existe déjà !
    } else {
        $grps[$grp] = array();
        WriteGroups($grps);
        return TRUE;
    }
}

/*******************************************************************************
 * Suppression d'un groupe de membres dans le fichier GROUPS
 * avec mise à jour du fichier MEMBERS
 *
 * param string $grp (un nom de groupe)
 * return boolean (TRUE = réussite, FALSE = échec)
 ******************************************************************************/
function DelGroup($grp) {
    $grps = ReadGroups();
    if (!array_key_exists($grp, $grps)) {
        return FALSE; // Le groupe n'existe pas !
    } else {
        unset($grps[$grp]);
        WriteGroups($grps);
        $mbrs1 = ReadMembers();
        $mbrs2 = array();
        foreach ($mbrs1 as $mbr=>$grps) {
            $find = array_search($grp, $grps);
            if (FALSE !== $find) {
                unset($grps[$find]);
                $grps = array_values($grps);
            }
            $mbrs2[$mbr] = $grps;
        }
        WriteMembers($mbrs2);
        return TRUE;
    }
}

/*******************************************************************************
 * Recherche d'un membre d'un groupe
 *
 * param string $grp (un nom de groupe)
 * param string $mbr (un nom de membre)
 * return boolean (TRUE = réussite, FALSE = échec)
 ******************************************************************************/
function CheckGroup($grp, $mbr) {
	if ($grp == 'all_members' && !empty($mbr)) return TRUE;
    $grps = ReadGroups();
    if (!array_key_exists($grp, $grps)) {
        return FALSE; // Le groupe n'existe pas !
    } else {
        $find = array_search($mbr, $grps[$grp]);
        if (FALSE !== $find) {
            return TRUE;
        }
    }
}

/*******************************************************************************
 * Ajout d'un membre dans un groupe
 * avec mise à jour des fichiers MEMBERS et GROUPS
 *
 * param string $grp (un nom de groupe)
 * param string $mbr (un nom de membre)
 * return boolean (TRUE = réussite, FALSE = échec)
 ******************************************************************************/
function AddMember($grp, $mbr) {
    $grps = ReadGroups();
    if (!array_key_exists($grp, $grps)) {
        return FALSE; // Le groupe n'existe pas !
    } else {
        $mbrs = $grps[$grp];
        if (in_array($mbr, $mbrs)) {
            return FALSE; // Le membre existe déjà !
        } else {
            $grps[$grp][] = $mbr;
            WriteGroups($grps);
            $mbrs = ReadMembers();
            $change = FALSE;
            if (!array_key_exists($mbr, $mbrs)) {
                // Le membre n'existe pas encore
                $mbrs[$mbr] = array($grp);
                $change = TRUE;
            } else {
                if (!in_array($grp, $mbrs[$mbr])) {
                    // Le groupe n'est pas encore dans la liste
                    $mbrs[$mbr][] = $grp;
                    $change = TRUE;
                }
            }
            if ($change) WriteMembers($mbrs);
            return TRUE;
        }
    }
}

/*******************************************************************************
 * Retrait d'un membre d'un groupe
 * avec mise à jour des fichiers MEMBERS et GROUPS
 *
 * param string $grp (un nom de groupe)
 * param string $mbr (un nom de membre)
 * return boolean (TRUE = réussite, FALSE = échec)
 ******************************************************************************/
function DelMember($grp, $mbr) {
    $grps = ReadGroups();
    if (!array_key_exists($grp, $grps)) {
        return FALSE; // Le groupe n'existe pas !
    } else {
        if (!in_array($mbr, $grps[$grp])) {
            return FALSE; // Le membre n'existe pas !
        } else {
            $find = array_search($mbr, $grps[$grp]);
            if (FALSE !== $find) {
                unset($grps[$grp][$find]);
                $grps[$grp] = array_values($grps[$grp]);
                WriteGroups($grps);
            }
            $mbrs = ReadMembers();
            $find = array_search($grp, $mbrs[$mbr]);
            if (FALSE !== $find) {
                unset($mbrs[$mbr][$find]);
                $mbrs[$mbr] = array_values($mbrs[$mbr]);
                WriteMembers($mbrs);
            }
            return TRUE;
        }
    }
}

/*******************************************************************************
 * Suppression d'un membre 
 * avec mise à jour des fichiers MEMBERS et GROUPS
 *
 * param string $grp (un nom de groupe)
 * param string $mbr (un nom de membre)
 * return void
 ******************************************************************************/
function DestroyMember($mbr) {
    $mbrs = ReadMembers();
    unset($mbrs[$mbr]);
    WriteMembers($mbrs);
    unset($mbrs);
    
    $grps1 = ReadGroups();
    $grps2 = array();
    foreach ($grps1 as $grp=>$mbrs) {
        $find = array_search($mbr, $mbrs);
        if (FALSE !== $find) {
            unset($mbrs[$find]);
            $mbrs = array_values($mbrs);
        }
        $grps2[$grp] = $mbrs;
    }
    WriteGroups($grps2);
}

/*******************************************************************************
 * Contrôle l'existance des membres présents dans les fichiers GROUPS et MEMBERS
 *
 * return void
 ******************************************************************************/
function CheckMembers() {
    $mbrs = ReadMembers();
    foreach ($mbrs as $mbr=>$grps) {
        if (!file_exists(USEREP.$mbr.DBEXT)) {
            DestroyMember($mbr);
        }
    }
}

/*******************************************************************************
 * Contrôle si une catégorie de discussion du forum existe bien
 *
 * param string $cat (identifiant de la catégorie)
 * return boolean (TRUE = réussite, FALSE = échec)
 ******************************************************************************/
function IsValidForumCat($cat) {
	
	$cats = ReadForumCats();

	if (!empty($cat) && in_array($cat, $cats)) {
			return TRUE;
	}
	
	return FALSE;
}


/*******************************************************************************
 * Vérifie si une catégorie de discussion du forum est privée ou non
 *
 * param string $cat (identifiant de la catégorie)
 * return boolean (TRUE = réussite, FALSE = échec)
 ******************************************************************************/
function IsPrivateForumCat($cat) {
	if (!empty($cat) && substr($cat, 0, 2) ==  'PR') {
		return TRUE;
	}
	return FALSE;
}

/*******************************************************************************
 * Lecture du fichier FORUM_CATS
 * pour fournir un tableau associatif
 * dont l'index est le nom d'un membre et
 * dont le contenu est la liste des groupes contenant ce membre
 *
 * return array
 ******************************************************************************/ 
function ReadForumCats() {
    if (!File_Exists(DBFORUMCAT)) return array();
	
    $dbwork = ReadDbFields(DBFORUMCAT);
	
	$cats = array();
	for ($i = 0; $i < count($dbwork); $i++) {
		$prcat = explode(',', $dbwork[$i][0]);
		$cats[] = $prcat[0]; //id de la catégorie
	}

    return $cats;
}