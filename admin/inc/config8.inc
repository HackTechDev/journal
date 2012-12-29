<?php
/*
    CSS Generator - GuppY PHP Script -  version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History               : Script based on GenCSS plugin v1.0 of Nicolas Alves
      v4.6.0 (04 June 2007)       : initial release by Icare
      v4.6.1 (02 July 2007)       : corrected padding for .rubr (by Icare)
      v4.6.2 (22 July 2007)       : corrected rubr and item  font values (by Icare)
      v4.6.5 (05 December 2007)   : use of border attribute only if with not nul (by Icare)
      v4.6.8 (24 May 2008)        : corrected margins of p tag (by Icare)
                                    style.css created automaticaly by config2.inc,
                                    display only result after generation or modification (by Icare)
      v4.6.10 (7 September 2009)  : corrected W3C
      v4.6.14 (14 February 2011)  : corrected class pop (thanks Jean-Mi)
      v4.6.16 (02 September 2011) : optimizing display box quote (by Papinou)
      v4.6.17 (21 October 2011)   : corrected display for config style (by Saxbar)	  
	  v4.6.19 (30 March 2012)     : remove cursor in body (by Saxbar - thanks tonton_christian)
	  v4.6.20 (24 May 2012)       : corrected display block quote (by Saxbar)
	  v4.6.22 (29 December 2012)  : corrected for ck editor (by Saxbar)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "config8.inc")) {
    header("location:../index.php");
    die();
}

// FONCTIONS DE MISE EN PAGE /////////////////////////////////////////////////////////////////////////
function legend($legend) {
	return '<legend style="font-weight:bold;margin-left:30px;padding:0 4px;">'.$legend.'</legend>'."\n";
}
//////////////////////////////////////////////////////////////////////////////////////////////////////

if (is_file(REDACREP.$userprefs[1].INCEXT)) {
    include(REDACREP.$userprefs[1].INCEXT);
    if ($drtuser[43]=="") {
        $nomzone=$admin719;
        include("access.inc");
        exit();
    }
}

include(CHEMIN."inc/hpage.inc");
htable($admin720, "100%");
echo '<div align="center" style="width:98%; margin:auto; text-align:center;">';

if ($corit==1) {
    $cssval = str_replace("'", "\"", $cssval);
    $cssval = stripslashes($cssval);
    WriteFullDB(CHEMIN."skin/".$mycss."/style.css", $cssval);
    $cor_css = "ok";
    $mod_css = "off";
}

if($regit==1){
    $cssbody = "";
    if (!empty($page[0]))  $cssbody .= "  background-color: ".$page[0].";\n";
    $css0 = (!empty($page[0]))? "  background: ".$page[0].";\n" : "";
    $css1 = ($page[15] == "on")? "  background-color: inherit;\n  position: relative;\n  top: 1px;\n  left: 1px;" : "  background-color: inherit;\n";
    $css2 = ($boutoncenter != "")? "  border: 0;\n  height: 20px;\n  margin: 0px;\n  padding-bottom: 2px;\n  vertical-align: top;\n  text-decoration: none;\n  background-image: url(".$boutoncenter.");\n  background-repeat: repeat-x;\n  font-size: 9px;" : "";
    $css3 = (!empty($page[10]))? "  background-attachment: fixed;\n" : "";
    $css4 = (!empty($page[3]))? $css3."  background-image: url(../../img/".$page[3].");" : "";
    $css5 = (!empty($page[5]))? "  background-color: ".$page[5].";" : "  background-color: transparent;";
    $css6 = (!empty($page[6]))? $css3."  background-image: url(../../img/".$page[6].");" : "";
    $css7 = (!empty($page[21]))? "  background-image: url(../../img/".$page[21].");" : "";
    $css8 = (!empty($titre[8]))? "  background-image: url(../../img/".$titre[8].");" : "";
    $css9 = (!empty($titre[9]))? "  background-image: url(../../img/".$titre[9].");" : "";
    $css10 = (!empty($calendar[0]))? "  background-color: ".$calendar[0].";" : "  background-color: inherit;";
    $css11 = ($boutoncenter != "")? "  border: 0px inset;\n  height: 20px;\n  margin: 2px 0px;\n  padding-bottom: 2px;\n  vertical-align: top;\n  text-decoration: none;\n  background-color: transparent;\n  background-image: url(".$boutoncenter.");\n  background-repeat: repeat-x;\n  font-size: 9px;" : "";
    $css12 = ($texte[4] == "0px")? "  border-width: 0;" : "  border: ".$texte[4]." solid ".$bordure[0].";";
    /**********************************
    * Construction de la feuille CSS  */

    $csslist = "

/*  ---------  CSS generated for ".$mycss." ----------- */

html { /*  document */
  font: ".$page[2]." ".$page[1].";
  color: ".$texte[0].";
  background: inherit;
}
body { /*  corps du document */
  margin: 0;
  font: ".$page[2]." ".$page[1].";
  color: ".$texte[0].";
".$cssbody."
}
a { /* lien */
  color: ".$lien[0].";
  background: inherit;
  text-decoration: none;
}
a:hover { /* lien survolé */
  color: ".$lien[1].";
  text-decoration: none;
  font-weight: bold;
".$css1."
}
p { /* paragraphe */
  margin: 16px 0;
  color: inherit;
  background: inherit;
}
hr { /* ligne horizontale */
  height: ".$barre[1].";
  border: ".$barre[1]." ".$barre[2]." ".$barre[0].";
  width: 98%;
}
ul, ol { /* listes */
  padding: 0;
  margin: 0;
}

h1 { /* titre niveau 1 */
  font-size: 24px;
}
h2 { /* titre niveau 2 */
  font-size: 18px;
}
h3 { /* titre niveau 3 */
  font-size: 16px;
}
h4 { /* titre niveau 4 */
  font-size: 14px;
}
.bordure {
".$css12."
}
/******************************************
* Mise en page des blocks div principaux */
#screen_choice {
  z-index: 20;
  position: absolute;
  top: 2px;
  right: 4px;
  padding: 0px;
  margin: 0;
  text-align: right;
}
#page{ /* all the page */
  z-index: 10;
  padding-top: 8px;
  color: inherit;
  background-color: ".$page[0].";
".$css4."
}
#headTop { /* header top and middle (logo-banner + citation) */
  z-index: 15;
  margin: 0;
  padding: 0 10px;
  color: inherit;
".$css5."
".$css6."
}
#headBottom { /* header bottom (logo-menu) */
  margin: 0;
  padding: 0 4px;
  color: inherit;
".$css5."
".$css7."
}
#mainContent { /* main page */
  margin: 0 4px;
  padding:0;
}
#leftside { /* leftboxes area */
  margin: 0;
  padding-right: 4px;
}
#rightside { /* right boxes area */
  margin: 0;
  padding-left: 4px;
}
#endbox { /* optionnal area between main page and bottom */
  margin: 4px 8px;

  text-align: left;
".$css7."
}
#foot { /* footer Copyright */
  font-family: ".$titre[2].";
  text-align: center;
  color: ".$texte[8].";
".$css5."
  padding: 0 8px;
}
/*******************************************
 * Mise en page des blocks dans le header */
div.logo { /* block logo */
  padding: 0 8px;
  text-align: center;
}
div.banner { /* block bannière */
  background-repeat: no-repeat;
  padding: 8px;
  text-align: center;
}
/*************************
 * block boite citation */
div.quote { /* block citation */
  text-align: center;
  padding: 0 4px;
}
div.quote span.labelcita { /* label */
  font: bold ".$citation[1]." ".$citation[0].";
  color: ".$citation[2].";
  background: inherit;
  text-align: center;
  border: 0;
  margin: 0;
  padding: 0 8px;
}
div.quote span.cita { /* texte */
  font: ".$citation[1]." ".$citation[0].";
  color: ".$citation[2].";
  background: inherit;
  font-style: normal;
  text-align: center;
  border: 0;
  margin: 0;
  padding: 0 8px;
}
div.quote span.author { /* auteur */
  font: italic ".$citation[1]." ".$citation[0].";
  color: ".$citation[2].";
  background: inherit;
}

/***********************************
 * block box Header Menu sections */
div.menuIcons { /* block menu */
  padding: 8px 0;
}
div.menuIcons ul { /* block liste du menu */
  margin: 0;
  padding: 0;
  list-style: none;
  width: 100%;
}
div.menuIcons ul li { /* toutes les sections */
  float: left;
  margin-right: 8px;
  text-align: center;
}
div.menuIcons ul li span { /* toutes les sections */
  display: block;
  white-space: nowrap;
}
div.menuIcons ul li.menu_flags { /* section drapeau */
  float: left;
  margin-right: 10px;
  text-align: center;
}
div.menuIcons ul li.menu_flags img { /* séparation drapeau */
	margin: 0;
}
div.menuIcons ul li.menu_admin { /* section admin */
  float: right;
  padding-right: 3px;
}
div.menuIcons ul li a span { /* lien */
  color: ".$lien[4].";
  background-color: inherit;
  text-decoration: none;
  font: bold ".$page[19]." ".$page[18].";
}
div.tblbox ul li a span, td.tblbox ul li a span { /* lien latéral */
  color: ".$lien[2].";
  background-color: inherit;
  text-decoration: none;
  font: bold ".$page[19]." ".$page[18].";
}
div.menuIcons ul li a span.current { /* lien actif */
  color:".$lien[5].";
  background-color: ".$lien[4].";
  text-decoration: underline;
}
div.tblbox ul li a span.current, td.tblbox ul li a span.current { /* lien latéral actif */
  color:".$lien[3].";
  background-color: ".$forum[0].";
  text-decoration: underline;
}
div.menuIcons ul li a:hover span { /* lien survolé*/
  color: ".$lien[5].";
  text-decoration: underline;
".$css1."
}
div.tblbox ul li a:hover span, td.tblbox ul li a:hover span { /* lien latéral survolé*/
  color: ".$lien[3].";
  text-decoration: underline;
".$css1."
}
/******************************************
 * Mise en page des blocks dans le corps */
/* block lateral boxes */
.htable {
  margin-bottom: 8px;
}
.htable1 {
  margin-bottom: 8px;
}
.htable2 {
  padding: 0 2px;
}
.spacer {
  padding: 8px 2px;
}
.titrebox { /* Titre */
  background-color: ".$titre[5].";
".$css9."
".$css12."
  padding: 4px;
  white-space: nowrap;
  font: bold ".$titre[7]." ".$titre[6].";
  color: ".$titre[4].";
  text-align: left;
}
.titrebox2 {  /* Autre titre */
  font: bold ".$titre[7]." ".$titre[6].";
  color: ".$titre[4].";
  background-color: ".$titre[5].";
  text-align: center;
}
.tblbox {  /* Corps */
  color:inherit;
  background-color: ".$texte[6].";
".$css12."
  padding: 4px;
  margin-bottom: 8px;
  text-align:left;
}
.tblboxover { /* Corps survolé */
  color: inherit;
  background-color: ".$texte[7].";
".$css12."
  padding: 4px;
  margin-bottom: 8px;
  text-align:left;
}
/* block central boxes */
.titre {
  background-color: ".$titre[1].";
".$css8."
".$css12."
  padding: 5px;
  white-space: nowrap;
  font: bold ".$titre[3]." ".$titre[2].";
  color: ".$titre[0].";
  text-align: left;
}
.tbl {
  background-color: ".$texte[1].";
".$css12."
  font: ".$page[2]." ".$page[1].";
  color: ".$texte[0].";
  padding: 4px;
  margin-bottom: 8px;
  text-align:left;
}
.tblover {
  background-color: ".$texte[2].";
  font: ".$page[2]." ".$page[1].";
  color: ".$texte[0].";
".$css12."
  padding: 4px;
  margin-bottom: 8px;
  text-align: left;
}
div ul, ol { /* listes */
  padding: 8px 0 8px 8px;
  margin-left: 16px;
}
div li{
  padding: 0;
  margin-left: 12px;
}
/************************************
 * block box lateral Menu Sections */
ul.boxmenu { /* block liste */
  margin: 0;
  padding: 5px 0;
  list-style: none;
}
ul.boxmenu li { /* items liste */
  margin-bottom: 10px;
}
ul.boxmenu li img { /* icons */
  vertical-align: middle;
  margin-right: 10px;
}
/****************************
 * block box lateral Article
 * (menu list, menu dynamic 1, menu dynamic 2) */
.rubr { /* catégories des articles */
  font: bold ".$page[17]." ".$page[16].";
  color: ".$lien[2].";
  background-color: inherit;
  text-align: left;
  margin: 1px;
  padding: 4px 2px;
}
.item {
  font: ".$page[17]." ".$page[16].";
  color: ".$lien[2].";
  background-color: inherit;
  text-align: left;
  list-style: none;
  margin: 0;
  padding: 2px 0;
}
ul.item {
  margin: 0;
  padding: 0;
}
ul.item li.item { /* titres des articles */
  font: ".$page[17]." ".$page[16].";
  color: ".$lien[2].";
  background-color: inherit;
  text-align: left;
  list-style: none;
  padding: 2px 0 2px 10px;
}
.curr_item {
  font: ".$page[17]." ".$page[16].";
  color: ".$lien[3].";
  background-color: ".$forum[0].";
  text-align: left;
  list-style: none;
  padding: 2px 0;
}
ul.item li.curr_item { /* titre article est affiché */
  font: ".$page[17]." ".$page[16].";
  color: ".$lien[3].";
  background-color: ".$forum[0].";
  text-align: left;
  list-style: none;
  padding: 2px 0 2px 10px;
}
/*************************************
 * block box central forum - tables */
.forum {
  background-color: ".$forum[0].";
  padding: 5px 5px;
  font: bold ".$page[2]." ".$page[1].";
  color: ".$texte[0].";
  text-align: center;
}
.forum2 {
  background-color: ".$forum[0].";
  padding: 5px 5px;
  font: ".$page[2]." ".$page[1].";
  color: ".$texte[0].";
  text-align: left;
}
tr.forum2 {
  background-color: ".$forum[0].";
".$css8."
  padding: 5px 5px;
  font: bold ".$page[2]." ".$page[1].";
  color: ".$texte[0].";
  text-align: left;
}
.quest {
  background-color: ".$forum[1].";
  padding: 5px 5px 5px 5px;
  font: ".$page[2]." ".$page[1].";
  color: ".$texte[0].";
  text-align: left;
}
.rep {
  background-color: ".$forum[2].";
  padding: 10px 5px 5px 5px;
  font: ".$page[2]." ".$page[1].";
  color: ".$texte[0].";
  text-align: left;
}
.bord {
  border: 1px solid ".$forum[0].";
  padding: 1px;
}
.bord2 {
  border: 2px double ".$forum[2].";
}
/*************
 * Calendar */
.cal {
  border-collapse: separate;
  border: ".$calendar[9]." solid ".$calendar[3].";
  border-spacing: ".$calendar[9].";
  color: inherit;
  background-color: ".$calendar[11].";
}
tr.cal { /* calendar nav bar */
  font: ".$calendar[6]." ".$calendar[5].";
  color: ".$calendar[8].";
  background-color: ".$calendar[3].";
  text-align: center;
}
td.cals { /* week */
  font: ".$calendar[6]." ".$calendar[5].";
  color: ".$calendar[8].";
  background-color: ".$calendar[11].";
".$css9."
  width: 14%;
  text-align: center;
}
td.cal0 { /* empty cell*/
  font: ".$calendar[6]." ".$calendar[5].";
  color: ".$calendar[7].";
".$css10."
  width: 14%;
  text-align: center;
}
td.cal1 { /* days */
  font: ".$calendar[6]." ".$calendar[5].";
  color: ".$calendar[7].";
  background-color: ".$calendar[1].";
  width: 14%;
  text-align: center;
}
td.cal2 { /* today */
  font: ".$calendar[6]." ".$calendar[5].";
  color: ".$calendar[7].";
  background-color: ".$calendar[2].";
  width: 14%;
  text-align: center;
}
td.cal3 { /* sunday or special */
  font: ".$calendar[6]." ".$calendar[5].";
  color: ".$calendar[7].";
  background-color: ".$calendar[3].";
  width: 14%;
  text-align: center;
}
td.cal4 { /* today is sunday or special */
  font: ".$calendar[6]." ".$calendar[5].";
  color: ".$calendar[7].";
  background-color: ".$calendar[4].";
  width: 14%;
  text-align: center;
}
td.calevt { /* planner event */
  font: bold ".$calendar[6]." ".$calendar[5].";
  color: ".$calendar[8].";
  background-color: ".$calendar[10].";
  text-decoration: underline;
  text-align: center;
  width: 14%;
}
/************************
 * Formulaires (Forms) */
form { /* formulaire */
  margin: 3px 0;
}
fieldset { /* Encadrement des champs */
  border: 1px solid ".$forum[0].";
  margin: 8px;
}
legend { /* légende des encadrements */
  font: ".$page[2]." ".$page[1].";
  color: ".$texte[0].";
  background-color: inherit;
  font-weight: bold;
}
input.bouton, button { /* bouton */
  cursor: pointer;
  margin: 4px 0;
  color: ".$presform[0].";
  border: 1px inset ".$presform[8].";
  background-color: ".$presform[2].";
  font: ".$presform[5]." ".$presform[4].";
".$css11."
}
input.texte { /* champ texte */
  background-color: ".$presform[3].";
  font: ".$presform[5]." ".$presform[4].";
  color: ".$presform[0].";
  border: ".$presform[7]." solid ".$presform[8].";
  margin: 4px 0;
}
select { /* champ select */
  color: ".$presform[0].";
  background-color: ".$presform[1].";
  font: ".$presform[5]." ".$presform[4].";
  border: ".$presform[7]." solid ".$presform[8].";
  margin: 4px 0;
}
textarea { /* champ textarea */
  color: ".$presform[0].";
  background-color: ".$presform[6].";
  border: ".$presform[7]." solid ".$presform[8].";
  overflow: auto;
  margin: 4px 0;
}
/**********************
 * Editeur CKEditor */
.Code {
  border: ".$forum[0]." 1px solid;
  padding-right: 5px;
  padding-left: 5px;
  color: ".$texte[5].";
  font: 11px ".$titre[2].", Monospace;
  background-color: ".$forum[2].";
}
/*********************
 * Editeur pgeditor */
div.pgeditor {
 color: inherit;
 background-color: ".$forum[0].";
 border: 1px solid ".$forum[0].";
}
div #toolbarIcons_ptxt, div #toolbarSmileys_ptxt {
 color: inherit;
 background-color: ".$forum[0].";
 border: 1px solid ".$forum[0].";
}
/*******************
 * pop comment RSS */
.pop {
  z-index: 30;
  width: 380px;
  text-align: left;
  position: relative;
}
.pop a {
  display: block;
}
.pop span {
  z-index: 30;
  display: none;
}
.pop a:hover span {
  display: block;
  width: 280px;
  position: absolute;
  top: 2em;
  left: 2em;
  color: ".$texte[0].";
  background-color: ".$presform[6].";
  font: normal ".$page[2]." ".$page[1].";
  border: 1px solid ".$presform[8].";
  padding: 4px;
}
/*******************************************
 * Mise en page des blocks dans le footer */
#foot span.copyright { /* Copyright */
  font: 1em ".$titre[2].";
  color: ".$texte[8].";
  background-color: inherit;
  text-align: center;
}
/************************
 * Divers, inclassables */
.box {
  font: ".$page[17]." ".$page[16].";
  color: ".$texte[5].";
  background-color: inherit;
  text-align: left;
}
p.box {
  margin: 0;
  font: ".$page[17]." ".$page[16].";
  color: ".$texte[5].";
  background-color: inherit;
}
.box a, .item a {
  color: ".$lien[2].";
  background-color: inherit;
  text-decoration: none;
  font: ".$page[17]." ".$page[16].";
}
.box2 a {
  color: ".$lien[3].";
  background-color: inherit;
  text-decoration: none;
  font: ".$page[17]." ".$page[16].";
  font-weight: bold;
}
.box a:hover, .item a:hover {
  color: ".$lien[3].";
  text-decoration: none;
".$css1."
}
.top {
  font: 0.8em ".$titre[2].";
  color: ".$texte[8].";
  background-color: inherit;
  text-align: center;
}
.timer {
  font: italic 0.9em ".$titre[2].";
  color: ".$texte[8].";
  background-color: inherit;
  text-align: center;
  padding: 8px;
}
.clsCursor {
  cursor: pointer;
}
.notice {
  color: red;
  background-color: #FF9;
  padding: 2px;
}
.band {
".$css6."
}
";

    if (FileDBExist($meskin."styleplus.css")) { // add particular css list
        $plus = fopen($meskin."styleplus.css", "r");
        while (!feof($plus)) {
            $csslist .= fgets($plus, 255);
        }
        fclose($plus);
    }
    @chmod(CHEMIN."skin", 0777);
    @chmod(CHEMIN."skin/".$mycss, 0777);
    @chmod(CHEMIN."skin/".$mycss."/style.css", 0666);
    $csslist = str_replace("'","\"",$csslist);
    WriteFullDB(CHEMIN."skin/".$mycss."/style.css",$csslist);
    $put_css = "ok";
    $mod_css = "off";
}
if (isset($selskin)) $skn = "&amp;selskin=".$selskin;

if ($mod_css != "off") echo '<p align="center">'.$admin722.'</p>';
?>
<hr />
<p align="center"><a href="admin.php?lng=<?php echo $lng.$skn; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b></p>
<hr />
<br />
<?php
if ($mod_css != "off") {
?>
<fieldset>
<?php
    echo legend($admin724);
?>
<br />
<?php
    if (FileDBExist($meskin."style.css")) {
        echo "<b>".$admin725."&nbsp;&nbsp;".$selskin."</b>";
    }
?>
<br />
<form name="gencss" action="admin.php?lng=<?php echo $lng; ?>" method="post">
<input type="hidden" name="pg" value="config8" />
<input type="hidden" name="regit" value="1" />
<input type="hidden" name="selskin" value="<?php echo $selskin; ?>" />
<input type="hidden" name="mycss" value="<?php echo $selskin; ?>" />
<br />
<p class="forum2" style="text-align:center;"><?php echo $admin723; ?></p>
<br />
<p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin726; ?>"><?php echo $admin726; ?></button><?php echo $boutonright; ?></p>
</form>
<br />
</fieldset>
<?php
}
?>
<br />
<?php
$meskin = CHEMIN."skin/".$selskin."/";
if (FileDBExist($meskin."style.css")) {
    if (isset($put_css)) {
        echo "<br /><br /><span class=\"quest\">".$admin721." <b>&nbsp;".$mycss."</span></b><br /><br />";
        echo '<fieldset>'.legend($admin727);
    }
    elseif (isset($cor_css)) {
        echo "<br /><br /><span class=\"forum\">".$admin721." <b>&nbsp;".$mycss."</span></b><br /><br />";
        echo '<fieldset>'.legend($admin728);
    }
    else {
        echo '<fieldset>'.legend($admin144." ".$admin729);
    }
?>
<br />
<p class="notice"><?php echo $admin887; ?></p>
<br />
<form name="modcss" action="admin.php?lng=<?php echo $lng; ?>" method="post">
<input type="hidden" name="pg" value="config8" />
<input type="hidden" name="corit" value="1" />
<input type="hidden" name="selskin" value="<?php echo $selskin; ?>" />
<input type="hidden" name="mycss" value="<?php echo $selskin; ?>" />
<br /><center>
<textarea name="cssval" rows="22" cols="64">
<?php
$cssfile = fopen($meskin."style.css", "r");
while (!feof($cssfile)) {
    $cssline = fgets($cssfile, 255);
    echo $cssline;
}
fclose($cssfile);
?>
</textarea>
</center>
<br />
<p align="center"><?php echo $boutonleft; ?><button type="submit" title="<?php echo $admin144." ".$admin422; ?>"><?php echo $admin144." ".$admin422; ?></button><?php echo $boutonright; ?></p>
</form>
<?php
}
echo "</fieldset>\n";
if (isset($selskin)) $skn = "&amp;selskin=".$selskin;
?>

<hr />
<p align="center"><a href="admin.php?lng=<?php echo $lng.$skn; ?>"><?php echo $admin22; ?></a> || <b><a href="admin.php?lng=<?php echo $lng; ?>&amp;logout=1"><?php echo $admin19; ?></a></b></p>
<?php
echo "</div>";
btable();
include(CHEMIN."inc/bpage.inc");
?>
