<?php
/*
    FAQ for PDA - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2007 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v2.3 (27 July 2003)      : initial release (thanks Palmipod)
      v2.4 (24 September 2003) : added ReadDoc() function
                                 added category ordering information
                                 secured transfered parameters
                                 created $typ_[name] variables
      v4.0 (06 December 2004)  : added page title (by Jean-Mi)
            		             added alt tag to img and removed border tag for unlinked img (by Isa)
      v4.6.17 (21 October 2011) : added private management (by Saxbar)								 
*/

header("Pragma: no-cache");
define("CHEMIN", "../");
include(CHEMIN."inc/includes.inc");

if ($serviz[14] != "on") {
  exit($web143);
}

$section_index = 4;
$section_name = $lng == $lang[0] ? $nom[24] : $nom[25];
include('inc/members.inc');
if ($section_access) {

	$id = strip_tags($id);

	$dbwork = ReadDBFields(DBFAQ);
	@sort($dbwork);

	if ($lng == $lang[0]) {
		$topmess = $nom[24];
	} else {
		$topmess = $nom[25];
	}
	include("inc/hpalm.inc");
	if ($lng == $lang[0]) {
		$i = 0;
	}
	else {
		$i = 1;
	}
	echo "<center><b>".$nom[$i+24]."</b></center><hr />";
	if (empty($id)) {
		$id = 1;
	}
	if (!empty($dbwork)) {
		?>
		<br><ul>
		<?php
		for ($i = $serviz[6]*($id-1); $i < Min($serviz[6]*$id, count($dbwork)); $i++) {
			ReadDoc(DBBASE.$dbwork[$i][4]);
			/// début modif accès privé
			$acces = "ok";
			if ($fieldmod != "") {
				$acces = "no";
				if ($userprefs[1] != "") {
					include_once (CHEMIN.'inc/func_groups.php');
					if (CheckGroup($fieldmod, $userprefs[1])) $acces ="ok";
				}
			}
			if ($acces == "ok") {
			/// fin modif accès privé
				if ($lng == $lang[0]) {
					if ($rubr <> $fielda1) {
						$rubr = $fielda1;
						if (trim($rubr) != "") {
							echo "<li><b>".$rubr."</b><br><br>\n";
						}
					}
					$txt1 = $fieldb1;
					$txt2 = PathToImage($fieldc1);
				}	else {
					if ($rubr <> $fielda2) {
						$rubr = $fielda2;
						if (trim($rubr) != "") {
							echo "<li><b>".$rubr."</b><br><br>\n";
						}
					}
					$txt1 = $fieldb2;
					$txt2 = PathToImage($fieldc2);
				}
				?>
				<img src="<?php echo CHEMIN; ?>inc/img/general/faq.gif" width="16" height="16" alt="*" />&nbsp;&nbsp;<?php echo $txt1; ?><br><br>
				<?php echo $txt2; ?><br><br>
				<?php
				if ($i < Min($serviz[6]*$id, count($dbwork))-1) {
					echo "<hr />";
				}
			} /// fin accès privé
		}
	}
	?>
	</ul>
	<?php
	if (count($dbwork)>$serviz[6])
	{
		echo '<hr />'.GetNavBar("faq.php?lng=".$lng."&amp;id=", count($dbwork), $id, $serviz[6]);
	}
	include("inc/bpalm.inc");
}
?>
