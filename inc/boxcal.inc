<?php
/*
    Calendar Box - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v2.3 (27 July 2003)         : initial release (by Nicolas Alves and Laurent Duveau)
      v2.4 (24 September 2003)    : no change
      v3.0 (25 February 2004)     : added skin management (by Nicolas Alves)
                                    corrected some TR tags and other cosmetics
      v4.0 (06 December 2004)     : extracted calendar into iframe calendar.php (by Icare)
                                    corrected frameborder and align attributes (by Isa)
                                    corrected iframe width (by Icare)
      v4.5 (22 February 2005)     : corrected second language option (by Icare)
      v4.6.0 (15 February 20077)  : added serviz control (by JeanMi)
      v4.6.5 (05 December 2007)   : added iframe adjustment (by Icare)
      v4.6.6 (14 April 2008)      : moved iframeHeight() to body of calendar, thanks eDada
      v4.6.17(21 October 2011)    : use adjustMyFrameHeight (by Laroche)
      v4.6.18(09 February 2012)   : corrected adjustment display iframe (by Saxbar)
	  v4.6.20 (24 May 2012)       : added $bctitle (by Saxbar)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "boxcal.inc")) {
  header("location:../index.php");
  die();
}

if ($serviz[47] == 'on') {
  $bctitle = $lng == $lang[0] ? $nom[32] : $nom[33];
  htable1($bctitle, "100%");
  ?>

  
<div align="center" style="margin:0px;">
<script language="javascript" type="text/javascript">
  function getElement(aID) {
    return (document.getElementById) ? document.getElementById(aID) : document.all[aID];
  }
  function getIFrameDocument(aID){ 
    var rv = null; 
    var frame=getElement(aID);
    if (frame.contentDocument)
      rv = frame.contentDocument;
    else // bad Internet Explorer  ;)
      rv = document.frames[aID].document;
      return rv;
  }
    
function adjustMyFrameHeight() {
  var frame = getElement("calbox");
  var frameDoc = getIFrameDocument("calbox");
  frame.height = frameDoc.body.offsetHeight;
} 
</script>
  <iframe id="calbox" src="<?php echo CHEMIN; ?>inc/calendar.php?lng=<?php echo $lng; ?>" width="156" frameborder="0"  scrolling="no"></iframe>
</div>
<?php
 if (($serviz[32]=="on" && !empty($serviz[31]) && $serviz[31]==$userprefs[1]) || ($serviz[32]=="on" && $drtuser[37]=="on")) {
    echo '
<p align="right" style="margin:0px">
  <a href="'.CHEMIN.'admin/admin.php?lng='.$lng.'&amp;pg=agenda" title="'.$web308.'">
    <img src="'.CHEMIN.'inc/img/general/edit.gif" border="0" alt="'.$web308.'" title="'.$web308.'" />
  </a>
</p>';
   }
  btable1($bctitle);
  }
?>
