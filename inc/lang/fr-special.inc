<?php
/*  Calendar - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2008 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.0 (06 December 2004)     : initial release (by Icare), calcul des jours f�ri�s
      v4.6.9 (25 December 2008)   : Optimized code, with static array of dates (by Hpsam)
      v4.6.11 (xx november 2009)  : corrected #306
*/

if (stristr($_SERVER["SCRIPT_NAME"], "fr-special.inc")) {
    header("location:../index.php");
    die();
}

function cal_ferie($jour,$mois,$annee)
{
    static $ferie = array();
    $jref = sprintf("%02d/%02d", $jour, $mois);
    if (!isset($ferie[$annee])) {
        // calcul date de P�ques (Easter day)
        $jf1 = $annee-1900;
        $jf2 = $jf1%19;
        $jf3 = intval((7*$jf2+1)/19);
        $jf4 = (11*$jf2+4-$jf3)%29;
        $jf5 = intval($jf1/4);
        $jf6 = ($jf1+$jf5+31-$jf4)%7;
        $jfj = 25-$jf4-$jf6;
        $jfm = 4;
        if ($jfj <= 0){
            $jfm = 3; $jfj = $jfj + 31;
        }
        $paques = sprintf("%02d/%02d", $jfj, $jfm);
        // d�termination des autres f�tes religieuses mobiles (other feasts)
        $lunpaq = date("d/m",mktime(12,0,0,$jfm,$jfj+1,$annee));   // lundi de P�ques
        $ascens = date("d/m",mktime(12,0,0,$jfm,$jfj+39,$annee));  // Ascension
        $lunpent = date("d/m",mktime(12,0,0,$jfm,$jfj+50,$annee)); // Lundi de Pentec�te

        // liste des jours f�ri�s de l'ann�e, jj/mm (all public holidays of the year, dd/mm)
        //  -----        you can add or change your public holidays here     -------
        $ferie[$annee] = array("01/01", $paques, $lunpaq, "01/05", "08/05", $ascens,
        $lunpent, "14/07", "15/08", "01/11", "11/11", "25/12");
    }
    foreach ($ferie[$annee] as $date) {
        if ($jref == $date) {
            return 'oui';
        }
    }
    return 'non';
}
?>
