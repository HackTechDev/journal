<?php
/*
    Top forum Box - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2008 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.6.0 (04 June 2007)         : initial release by Icare
      v4.6.6 (14 April 2008)        : modified search width (by Icare)
      v4.6.8 (24 May 2008)          : corrected box display (by Icare)
      v4.6.9 (25 December 2008)     : correction of the wide page layout view of the forum #234
      v4.6.11 (xx november 2009)    : corrected #307
      v4.6.12 (01 May 2010) : corrected #322 : deleted invalid attribute hspace="5"
*/

if (stristr($_SERVER["SCRIPT_NAME"], "topforum.inc")) {
  header("location:../index.php");
  die();
}

if ($serviz[28] == 'on' || $serviz[24] == 'on') {
    echo "<center><div class=\"bord\" style=\"width:auto;height:38px;text-align:left;position:relative;\">\n";
    if ($serviz[28] == 'on') {
    
        echo "<div style=\"float:left;width:20%;padding:6px 4px 2px;\">\n";
        if (!empty($userprefs[1])) {
            echo '
<form name="usermsg" action="'.CHEMIN.'tinymsg.php?lng='.$lng.'" method="post">
<input type="hidden" name="action" value="3" />
<img src="'.CHEMIN.'inc/img/general/b_mess.gif" alt="[" style="vertical-align:top;" /><button type="submit" style="background:transparent url('.CHEMIN.'inc/img/general/b_ton.gif) repeat-x;border:none;height:22px;margin:0;cursor:pointer;vertical-align:top;" title="'.$web318.'">'.$web318.'</button><img src="'.CHEMIN.'inc/img/general/b_right.gif" alt="]" style="vertical-align:top;" />
</form>';
        }
        else {
            echo '
<form name="userpref" action="'.CHEMIN.'user.php?lng='.$lng.'" method="post">
<img src="'.CHEMIN.'inc/img/general/b_post.gif" alt="[" style="vertical-align:top;" /><button type="submit" style="background:transparent url('.CHEMIN.'inc/img/general/b_ton.gif) repeat-x;border:none;height:22px;margin:0;cursor:pointer;vertical-align:top;" title="'.$web160.'">'.$web160.'</button><img src="'.CHEMIN.'inc/img/general/b_right.gif" alt="]" style="vertical-align:top;" />
</form>';
        }
        echo "</div>\n";
        echo "<div style='float:left;z-index:20;display:block;width:15%;text-align:center;padding-top:10px;'>\n";
        $nbrmsg = array();
        if (FileDBExist(USEREP.$userprefs[1].DBEXT)) {
            $dbmsg = ReadDBFields(USEREP.$userprefs[1].DBEXT);
            if ($dbmsg[0][0] == $userprefs[7]) {
                for ($i = 2; $i < count($dbmsg); $i++) {
                    if ($dbmsg[$i][3]=="new") {
                        $nbrmsg[]=$dbmsg[$i][3];
                    }
                }
            }
            if (count($nbrmsg)!=0) {
                echo '
<div style="position:absolute;top:0px;left:16%;z-index:20;display:block;width:38px;height:38px;vertical-align:middle;">
<a class="box" href="'.CHEMIN.'tinymsg.php?lng='.$lng.'&action=3"><img src="'.CHEMIN.'inc/img/general/newmsg.gif" border="0" alt="'.$web319.'" title="'.$web319.'"/></a>
<embed src="'.CHEMIN.'inc/mail/mail.wav" hidden="true" autostart="true" loop="false"></embed>
</div>';
            }
        }
        $dossier_users=USEREP;
        $file_users=opendir($dossier_users);
        $nbr_membres=0;
        while ($nomfichier=readdir($file_users)) {
            if( substr($nomfichier,-3)=="dtb" ) {
                $nbr_membres++;
            }
        }
        closedir($file_users);
        if ($nbr_membres >1) {
            $text_nbr_membres=$web321;
        } else {
            $text_nbr_membres=$web322;
        }
        echo '<img src="'.CHEMIN.'inc/img/general/nbrmembres.gif" border="0" alt="'.$web320.'" title="'.$web320.'" />&nbsp;<b>'.$nbr_membres.' '.$text_nbr_membres.'</b>'."\n";
        echo "</div>\n";
        $regusers = ReadDBFields(DBIPSTATS);
        $usersonline = array();
        for ($i = 0; $i < count($regusers); $i++) {
            if (!empty($regusers[$i][2])) {
                $usersonline[] = $regusers[$i][2];
            }
        }
        @sort($usersonline);
        $uniqueusers = array();
        $uniqueusers[] = $usersonline[0];
        for ($i = 1; $i < count($usersonline); $i++) {
            if ($usersonline[$i] != $usersonline[$i-1]) {
                $uniqueusers[] = $usersonline[$i];
            }
        }
        if (empty($usersonline)) {
            echo "<div style=\"float:left;width:40%;vertical-align:middle;text-align:center;padding-top:10px\">\n";
            echo "<b>".$web175."</b> ".$web176;
            echo "</div>\n";
        }
        else {
            if (count($uniqueusers) == "1") {
                $pad = "9px";
            } else {
                $pad = "5px";
            }
            echo "<div style=\"float:left;width:40%;text-align:center;vertical-align:middle;padding-top:".$pad.";\">\n";
            echo '<form name="tinysend" method="post" action="'.CHEMIN.'tinymsg.php">'."\n";
            echo "<b>".$web175."</b> ".count($uniqueusers)."&nbsp;";
            if ($userprefs[1] != "") {
                $from = $userprefs[1];
                echo "&nbsp;<img src='".CHEMIN."inc/img/general/puce2.gif' border='0' alt='".$web321."' title='".$web321."' />\n";
                echo $userprefs[1]." &nbsp;\n";
            }
            echo "<input type=\"hidden\" name=\"from\" value=\"".$from."\" />\n";
            echo "<input type=\"hidden\" name=\"lng\" value=\"".$lng."\" />\n";
            echo "<input type=\"hidden\" name=\"action\" value=\"1\" />\n";
            if (count($uniqueusers) > "1") {
                echo " + <select name=\"to\" onchange=\"this.form.submit\" style=\"vertical-align:middle\">\n";
                for ($i = 0; $i < count($uniqueusers); $i++) {
                    if ($uniqueusers[$i] != $userprefs[1]) {
                        echo '<option value="'.$uniqueusers[$i].'">&nbsp;'.$uniqueusers[$i].'</option>'."\n";
                    }
                }
                echo "</select>\n";
            }
            if ($userprefs[1] != "" && count($uniqueusers) > "1") {
                echo '<input type="image" style="vertical-align:middle; padding-left:5px;" src="'.CHEMIN.'inc/img/general/mail.gif" alt="'.$web214.'" title="'.$web214.'" />'."\n";
            }
            echo "</form>\n";
            echo "</div>\n";
        }
    }
    if ($serviz[24] == 'on') {
        echo '
<div style="float:right;width:22%;text-align:right;padding:4px 2px;">
<form action="'.CHEMIN.'search.php?lng='.$lng.'" method="post" name="what">
<input name="searchin" type="hidden" value="'.TYP_FORUM.'" />
<input name="search" class="texte" type="text" size="16" value="'.$web58.'" onfocus=\'this.value=""\' />
&nbsp;<input type="image" style="vertical-align:bottom;" src="'.CHEMIN.'inc/img/general/search.gif" alt="'.$web58." ".$forumname.'" />
</form>
</div>';
    }
    echo '
</div>
<div style="width:98%;clear:both;"></div>
</center>
<br />';
}
