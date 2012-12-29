<?php
/*
    Site Style CSS - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v2.4 (24 September 2003) : initial release (removed from inc/hpage.inc)
      v3.0 (25 February 2004)  : added skin management (by Nicolas Alves)
                                 added an links animation effect option (thanks reddog)
      v3.0p2 (09 April 2004)   : bug fix in the INPUT.bouton style (thanks Ouly)
      v4.0 (06 December 2004)  : splitted box style into side and central box's style (by Isa)
                                 splitted links style into 3 different styles : nav menu, central box, sidebox (by Isa)
                                 added HR style (by Isa)
                                 replaced P margin by the appropriate padding tag (by Isa)
                                 added scrollbars style to textareas (by Isa)
                                 added the new editor style (by Icare)
                                 transfered body attributes to the CSS (by Isa)
                                 extracted calendar CSS to calendar.php (by Isa)
                                 added some classes related to skins and hpage / bpage (by Isa)
                                 extracted body attributes from body tags to the CSS (by Isa)
                                 added comments in CSS (by Isa)
                                 added forum/tables style (by Icare)
                                 corrected body background style (by Icare)
      v4.5 (24 February 2005)  : added parameters for editor admin, added ul and li for articles (by Icare)
      v4.6.0 (04 June 2007)    : added new classes and reorganization(by Djchouix and Icare)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "style.inc")) {
  header("location:../index.php");
  die();
}

/*******************************************************************************************************************
 * Initialisation des variables
 */

$cssbody = "";
if (!empty($page[0])) $cssbody .= "background-color: ".$page[0].";";
if (!empty($page[24])) $cssbody .= "cursor: url(".CHEMIN."inc/img/cursor/".$page[24].".ani);";
if (!empty($bordure[1])) $cssbody .= "scrollbar-base-color: ".$bordure[1].";";
if (!empty($bordure[2])) $cssbody .= "scrollbar-arrow-color: ".$bordure[2].";";

$css0 = (!empty($page[0]))? "background: ".$page[0].";" : "";
$css1 = ($page[15] == "on")? " background-color: transparent; position: relative; top: 1px; left: 1px;" : "";
$css2 = ($boutoncenter != "")? " border: 0; height: 20px; margin: 0px; padding-bottom: 2px; vertical-align: top; text-decoration: none; background-image: url(".$boutoncenter."); background-repeat: repeat-x; font-size: 9px;" : "";
$css3 = (!empty($page[10]))? " fixed" : "";
$css4 = (!empty($page[3]))? "background-image: url(".CHEMIN."img/".$page[3].")".$css3.";" : "";
$css5 = (!empty($page[5]))? "background-color: ".$page[5].";" : "";
$css6 = (!empty($page[6]))? "background-image: url(".CHEMIN."img/".$page[6].")".$css3.";" : "";
$css7 = (!empty($page[21]))? "background-image: url(".CHEMIN."img/".$page[21].");" : "";
$css8 = (!empty($titre[8]))? "background-image: url(".CHEMIN."img/".$titre[8].");" : "";
$css9 = (!empty($titre[9]))? "background-image: url(".CHEMIN."img/".$titre[9].");" : "";
$css10 = (!empty($calendar[0]))? "background-color: ".$calendar[0].";" : "";
$css11 = ($boutoncenter != "")? "border: 0px inset; height: 20px; margin: 2px 0px; padding-bottom: 2px; vertical-align: top; text-decoration: none; background-color: transparent; background-image: url(".$boutoncenter."); background-repeat: repeat-x; font-size: 9px;" : "";

/*******************************************************************************************************************
 * Construction de la feuille CSS
 */

$csslist = "
/********************************************************************************************************
 * Mise en page générale
 */

body { /*  corps du document */
    margin: 0;
    font-size: ".$page[2].";
    font-family: ".$page[1].";
    color: ".$texte[0].";
    ".$cssbody."
}

a { /* lien */
    color: ".$lien[0].";
    text-decoration: none;
}

a:hover { /* lien survolé */
    color: ".$lien[1].";
    text-decoration: none;
    ".$css1."
}

p { /* paragraphe */
    margin: 4px 0px;
}

hr { /* ligne horizontale */
    height: ".$barre[1].";
	border: 0 none;
	border-bottom: ".$barre[1]." ".$barre[2]." ".$barre[0].";
    width: 98%;
}

ul, ol { /* listes */
	padding:0;
	margin:0;
    font-size: ".$page[2].";
    font-family: ".$page[1].";
    color: ".$texte[0].";
}

h1 { /* titre niveau 1 */
	font-size: 24px;
}
h2 { /* titre niveau 2 */
	font-size:18px;
}
h3 { /* titre niveau 3 */
	font-size:16px;
}
h4 { /* titre niveau 4 */
	font-size:14px;
}

/********************************************************************************************************
 * Mise en page des blocks div principaux
 */

#page{ /* all the page */
    z-index: 20;
    padding-top:10px;
    background-color: ". $page[0].";
    ".$css4."
}

#headTop { /* header top and middle (logo-banner + citation) */
    z-index: 15;
    margin: 0;
    padding: 4px;
    ".$css5."
    ".$css6."
}

#headBottom { /* header bottom (logo-menu) */
    margin: 0;
    padding: 0 4px;
    ".$css7."
}

#mainContent { /* main page */
    margin: 0px 4px;
    padding:0px;
}

#leftside { /* leftboxes area */
    margin: 0px;
    padding:0px;
}

#rightside { /* right boxes area */
    margin: 0px;
    padding:0px;
}

#endbox { /* optionnal areabtween corpse and bottom */
    margin: 0px;
    padding: 4px;
    text-align: left;
    ".$css7."
}

#foot { /* footer Copyright */
    font-family: ".$titre[2].";
    text-align: center;
    color: ".$titre[0].";
}

/********************************************************************************************************
 * Mise en page des blocks dans le header
 */

div.logo { /* block logo */
    background-color: transparent;
    padding: 4px;
    text-align: left;
}

div.banner { /* block bannière */
    background-repeat: no-repeat;
    padding: 8px;
    text-align: right;
}

/*************************
 * block boite citation
 */
div.quote { /* block citation */
    width: 100%;
    white-space: nowrap;
    text-align: center;
}

div.quote strong { /* titre */
	font-weight:bold;
}

div.quote cite { /* texte */
    ".$css5."
    font-family: ".$citation[0].";
    font-size: ".$citation[1].";
    color: ".$citation[2].";
	font-style: normal;
    text-align: center;
    width: 100%;
    border: 0;
    margin: 0;
    padding: 0;
}

div.quote span.author { /* auteur */
	font-style: normal;
}

/*************************
 * block box Header Menu sections
 */

div.menuIcons { /* block menu */
	padding:10px;
}

div.menuIcons ul { /* block liste du menu */
	margin:0;
	padding:0;
	list-style:none;width:100%;
}

div.menuIcons ul li { /* toutes les sections */
	float:left;
	margin-right:20px;
	text-align:center;
}

div.menuIcons ul li span { /* toutes les sections */
	display:block;
	white-space:nowrap;
}

div.menuIcons ul li.menu_flags { /* section drapeau */
	float:left;
	margin-right:20px;
	text-align:center;
}

div.menuIcons ul li.menu_flags img { /* séparation drapeau */
	margin:3px;
}

div.menuIcons ul li.menu_admin { /* section admin */
	float:right;
}

div.menuIcons ul li span { /* nom des sections */
	color: ".$lien[4].";
	white-space:nowrap;
}

div.menuIcons ul li a span { /* lien */
    color: ".$lien[4].";
    text-decoration: none;
    font-size: ".$page[19].";
    font-family: ".$page[18].";
}

div.menuIcons ul li a:hover span { /* lien */
    color: ".$lien[5].";
    text-decoration: underline;
    font-size: ".$page[19].";
    font-family: ".$page[18].";
    ".$css1."
}

/********************************************************************************************************
 * Mise en page des blocks dans le corps
 */

/*************************
 * block lateral boxes
 */
.titrebox { /* Titre */
    background-color: ".$titre[5].";
    ".$css9."
    border: ".$texte[4]." solid ".$bordure[0].";
    padding: 4px;
    white-space: nowrap;
    font-size: ".$titre[7].";
    font-family: ".$titre[6].";
    color: ".$titre[4].";
    text-align: left;
    font-weight: bold;
}

.tblbox {  /* Corps */
    background-color: ".$texte[1].";
    border: ".$texte[4]." solid ".$bordure[0].";
    padding: 4px;
    margin-bottom: 8px;
    text-align:left;
}

.tblboxover { /* Corps survolé */
    background-color: ".$texte[2].";
    border: ".$texte[4]." solid ".$bordure[0].";
    padding: 4px;
    margin-bottom: 8px;
    text-align:left;
}

/*************************
 * block central boxes
 */
.titre {
    background-color: ".$titre[1].";
    ".$css8."
    border: ".$texte[4]." solid ".$bordure[0].";
    padding: 5px;
    white-space: nowrap;
    font-size: ".$titre[3].";
    font-family: ".$titre[2].";
    color: ".$titre[0].";
    text-align: left;
    font-weight: bold;
}
.tbl {
    background-color: ".$texte[1].";
    font-size: ".$page[2].";
    font-family: ".$page[1].";
    color: ".$texte[0].";
    border: ".$texte[4]." solid ".$bordure[0].";
    padding: 5px;
    margin-bottom: 8px;
    text-align:left;
}
.tblover {
    background-color: ".$texte[2].";
    font-size: ".$page[2].";
    font-family: ".$page[1].";
    color: ".$texte[0].";
    border: ".$texte[4]." solid ".$bordure[0].";
    padding: 5px;
    margin-bottom: 8px;
    text-align:left;
}

/*************************
 * block box lateral Menu Sections
 */
ul.boxmenu { /* block liste */
	margin:0;
	padding:10px;
	list-style:none;
}

ul.boxmenu li { /* items liste */
	margin-bottom:10px;
}

ul.boxmenu li img { /* icons */
	vertical-align:middle;
	margin-right:10px;
}

/*************************
 * block box lateral Article (menu list, menu dynamic 1, menu dynamic 2)
 */
p.rubr { /* catégories des articles */
    background-color: transparent;
    padding: 4px 2px;
    margin: 1px;
    font-size: ".$page[2].";
    font-family: ".$page[1].";
    font-weight: bold;
    color: ".$texte[0].";
    text-align:left;
}
ul.item {
	margin:0;
	padding:0;
}
ul.item li.item { /* titres des articles */
    background-color: ".$forum[2].";
    padding: 2px 0px 2px 10px;
    font-size: ".$page[2].";
    font-family: ".$page[1].";
    color: ".$texte[0].";
    text-align:left;
    list-style: none;
}

ul.item li.curr_item { /* titre dont l'article est affiché */
    background-color: ".$forum[0].";
    padding: 2px 0px 2px 10px;
    font-size: ".$page[2].";
    font-family: ".$page[1].";
    color: ".$texte[0].";
    text-align:left;
    list-style: none;
}

/*************************
 * block box central forum - tables
 */
.forum {
    background-color: ".$forum[0].";
    padding: 5px 5px;
    font-size: ".$page[2].";
    font-family: ".$page[1].";
    color: ".$texte[0].";
    text-align: center;
    font-weight: bold;
}
.forum2 {
    background-color: ".$forum[0].";
    padding: 5px 5px;
    font-size: ".$page[2].";
    font-family: ".$page[1].";
    color: ".$texte[0].";
    text-align:left;
}
tr.forum2 {
    background-color: ".$forum[0].";
    ".$css8."
    padding: 5px 5px;
    font-size: ".$page[2].";
    font-family: ".$page[1].";
    color: ".$texte[0].";
    font-weight: bold;
    text-align:left;
}
.quest {
    background-color: ".$forum[1].";
    padding: 5px 5px 5px 5px;
    font-size: ".$page[2].";
    font-family: ".$page[1].";
    color: ".$texte[0].";
    text-align:left;
}
.rep {
    background-color: ".$forum[2].";
    padding: 10px 5px 5px 5px;
    font-size: ".$page[2].";
    font-family: ".$page[1].";
    color: ".$texte[0].";
    text-align:left;
}
.bord {
    border: 1px solid ".$forum[0].";
    padding: 1px;
}
.bord2 {
    border: 2px double ".$forum[2].";
}

/*************************
 * Calendar
 */
.cal {
    border-collapse: separate;
    border: ".$calendar[9]." solid ".$calendar[3].";
    border-spacing: ".$calendar[9].";
    background-color: ".$calendar[11].";
}
tr.cal { /* calendar nav bar */
    font-size: ".$calendar[6].";
    font-family: ".$calendar[5].";
    color: ".$calendar[8].";
    background-color: ".$calendar[3].";
    text-align: center;
}
td.cals { /* week */
    font-size: ".$calendar[6].";
    font-family: ".$calendar[5].";
    color: ".$calendar[8].";
    background-color: ".$calendar[11].";
    ".$css9."
    width: 14%;
    text-align: center;
}
td.cal0 { /* empty cell*/
    font-size: ".$calendar[6].";
    font-family: ".$calendar[5].";
    color: ".$calendar[7].";
    ".$css10."
    width: 14%;
    text-align: center;
}
td.cal1 { /* days */
    font-size: ".$calendar[6].";
    font-family: ".$calendar[5].";
    color: ".$calendar[7].";
    background-color: ".$calendar[1].";
    width: 14%;
    text-align: center;
}
td.cal2 { /* today */
    font-size: ".$calendar[6].";
    font-family: ".$calendar[5].";
    color: ".$calendar[7].";
    background-color: ".$calendar[2].";
    width: 14%;
    text-align: center;
}
td.cal3 { /* sunday or special */
    font-size: ".$calendar[6].";
    font-family: ".$calendar[5].";
    color: ".$calendar[7].";
    background-color: ".$calendar[3].";
    width: 14%;
    text-align: center;
}
td.cal4 { /* today is sunday or special */
    font-size: ".$calendar[6].";
    font-family: ".$calendar[5].";
    color: ".$calendar[7].";
    background-color: ".$calendar[4].";
    width: 14%;
    text-align: center;
}
td.calevt { /* planner event */
    font-size: ".$calendar[6].";
    font-family: ".$calendar[5].";
    font-weight: bold;
    color: ".$calendar[8].";
    background-color: ".$calendar[10].";
    text-decoration: underline;
    text-align: center;
    width: 14%;
}

/*******************************
 * Formulaires (Forms)
 */

form { /* formulaire */
    margin: 3px 0px;
}
fieldset { /* Encadrement des champs */
    border: 1px solid ".$forum[0].";
    margin: 8px;
}
legend { /* légende des encadrements */
    font-size: ".$page[2].";
    font-family: ".$page[1].";
    color: ".$texte[0].";
    font-weight: bold;
}
input.bouton, button { /* bouton */
    cursor: pointer;
    margin: 4px 0px;
    color: ".$presform[0].";
    border: 1px inset ".$presform[8].";
    background-color: ".$presform[2].";
    font-size: ".$presform[5].";
    font-family: ".$presform[4].";
    ".$css11."
}
input.texte { /* champ texte */
    background-color: ".$presform[3].";
    font-size: ".$presform[5].";
    font-family: ".$presform[4].";
    color: ".$presform[0].";
    border: ".$presform[7]." solid ".$presform[8].";
    margin: 4px 0px;
}
select { /* champ select */
    color: ".$presform[0].";
    background-color: ".$presform[1].";
    font-family: ".$presform[4].";
    font-size: ".$presform[5].";
    border: ".$presform[7]." solid ".$presform[8].";
    margin: 4px 0px;
}
textarea { /* champ textarea */
    color: ".$presform[0].";
    background-color: ".$presform[6].";
    border: ".$presform[7]." solid ".$presform[8].";
    overflow: auto;
    scrollbar-base-color: ".$presform[6].";
    scrollbar-arrow-color: ".$presform[0].";
    margin: 4px 0px;
}

/*********************
 * Editeur FckEditor
 */
.Code {
    border: ".$forum[0]." 1px solid;
    padding-right: 5px;
    padding-left: 5px;
    color: ".$texte[5].";
    font-family: ".$titre[6]." , Monospace;
    font-size: 11px;
    background-color: ".$forum[2].";
}

/********************************************************************************************************
 * Mise en page des blocks dans le footer
 */
#foot span.copyright { /* Copyright */
    font-family: ".$titre[2].";
    font-size: 1em;
    color: ".$titre[0].";
}

/*********************************************************************************************
 * Autre à classer
 */
.htable {
    margin-bottom: 8px;
}
.htable1 {
    margin-bottom: 8px;
}
.htable2 {
    padding: 0px 2px;
}

.titrebox2 {
    font-size: ".$titre[7].";
    font-family: ".$titre[6].";
    color: ".$titre[4].";
    font-weight: bold;
    text-align: center;
}

.box {
    font-size: ".$page[17].";
    font-family: ".$page[16].";
    color: ".$texte[5].";
}
p.box {
    margin: 0px;
    font-size: ".$page[17].";
    font-family: ".$page[16].";
    color: ".$texte[5].";
}


.bordure {
    border: ".$texte[4]." solid ".$bordure[0].";
}

a.box {
    color: ".$lien[2].";
    text-decoration: none;
    font-size: ".$page[17].";
    font-family: ".$page[16].";
}
a.box2 {
    color: ".$lien[3].";
    text-decoration: none;
    font-size: ".$page[17].";
    font-family: ".$page[16].";
    font-weight: bold;
}
a:hover.box {
    color: ".$lien[3].";
    text-decoration: none;
    font-size: ".$page[17].";
    font-family: ".$page[16].";
    font-weight: bold;
    ".$css1."
}
a.pop {
    position: relative;
}
a.pop span {
    display:none;
}
a.pop:hover span {
    display:block;
    position:absolute;
    top:2em;
    left:2em;
    color: ".$texte[0].";
    background-color: ".$presform[6].";
    font-family: ".$page[1].";
    font-size: ".$page[2].";
    border: 1px solid ".$presform[8].";
    padding: 4px;
}

.top {
    font-family: ".$titre[2].";
    font-size: 0.8em;
    text-align: center;
}
.timer {
    font-family: ".$titre[2].";
    font-size: 1em;
    font-style: italic;
    color: ".$titre[0].";
    text-align: center;
    padding: 8px;
}
.clsCursor {
    cursor: pointer;
}

.notice {
    color:red;
    background-color:yellow;
    padding:2px;
}
.spacer {
    padding: 8px 2px;
}
.caption {
    font: bold 11px verdana, tahoma, arial, helvetica, sans-serif;
    background-color: ".$titre[1].";
    ".$css8."
    padding: 4px 10px 4px 10px;
    margin:0px 0px 0px 6px;
    position: relative; top: 6px;
    border-right: 1px solid #ccc;
    border-bottom: 1px solid #999;
}
.caption2 {
    font: bold 11px verdana, tahoma, arial, helvetica, sans-serif;
    background-color: ".$titre[1].";
    ".$css9."
    padding: 4px 10px 4px 10px;
    margin:0px 0px 0px 6px;
    position: relative; top: 6px;
    border-right: 1px solid #ccc;
    border-bottom: 1px solid #999;
}
.bodytable {
    border: 1px solid ".$forum[0].";
    padding: 16px 4px 2px;
    margin: 0px 0px 4px;
    font: 10px verdana, tahoma, arial, helvetica, sans-serif;
    color: #000;
    ".$css0."
    border-right: 2px solid #ccc;
    border-bottom: 2px solid #999;
}

ul.art {
    font-weight:bold; padding:0px; margin:0px;
}
li.art {
    font-weight:normal; list-style-type:none; padding:0px; margin-left:4px;
}

.band {
    ".$css6."
}
";

echo $csslist;

