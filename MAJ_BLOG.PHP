<?php
/*   Update DBBLOG older than v4.6.6 release
     by adding item creation date of the notes
                  ---------
     Ajout du champ date de cr�ation dans DBBLOG
     pour les versions ant�rieures � v4.6.6
*/
header("Pragma: no-cache");
define("CHEMIN", "");
include("inc/includes.inc");

include("inc/hpage.inc");
if ($lng == "fr") {
  $title_maj = "Mise � jour des dates de DBBLOG ";
  $mess1 = "D�but de mise � jour....";
  $mess2 = "Mise � jour termin�e";
}
else {
  $title = "Update dates for DBBLOG";
  $mess1 = "Beginning update....";
  $mess2 = "End of update successfull";
}
htable($title_maj, "100%");

echo "<div align='center' style='height:100px;'>\n";
echo "<br />".$mess1."<br />\n";

updateDBdtb(TYP_BLOG);
    echo "<div id='mess' class='forum' style='z-index:50; position: relative; top: -20px; width: 300px; padding: 20px; border: 4px inset;'>";
    echo "<p align='center'><strong>".$mess2."</strong><br />";
    echo "</p></div>";
echo "</div>\n";

btable();
include("inc/bpage.inc");

?>
