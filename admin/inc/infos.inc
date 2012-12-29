<?php
/*
    Admin Technicals Information - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2009 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = info@freeguppy.org

    Version History :
      v4.6 (17 March 2007)        : initial release by Hpsam
	  v4.6.0 (04 June 2007)         : added cURL for host with allow_url_fopen set to false (vy Hpsam)
      v4.6.9 (25 December 2008)   : added corrections for validation of W3C
      v4.6.10 (7 September 2009)  : corrected #266
      v4.6.11 (11 December 2009)  : corrected #295
      v4.6.14(14 February 2011   : corrected tests (thanks Jean-Mi)	  
*/
if (stristr($_SERVER["SCRIPT_NAME"], "infos.inc")) {
  header("location:../index.php");
  die();
}

	// Show phpinfo() output
if (isset($itact) and $itact == 'phpinfo') {
	phpinfo();
	exit();
}
else {
	// Check for upgrade : code inspired from punbb and pwg
	$version = array();
	$version['current']=trim($mpversion);
	$version['url']="http://www.freeguppy.org/update.txt";
	$load_ok = false;
	$lines = array();
        if (ini_get('allow_url_fopen')) {
        $lines = @file($version['url']);
        $load_ok = $lines !== FALSE;
    }
    if (!$load_ok && $curl = @curl_init($version['url'])){
        $timeout = 5; // set to zero for no timeout
		curl_setopt ($curl, CURLOPT_CONNECTTIMEOUT, $timeout);
		curl_setopt ($curl, CURLOPT_RETURNTRANSFER, 1);
		$version_content = curl_exec($curl);
		curl_close($curl);
		if ($version_content != false) {
			$lines = explode("\n", $version_content);
			$load_ok=true;
		}
	}
	else {
		$version['errors'] = $admin898;
	}
	if ($load_ok){
		$version['latest'] = trim($lines[0]);
		switch ($version['latest']){
		case '':
            $version['errors'] = $admin899;
            break;
		default:
			if (version_compare($version['current'], $version['latest']) < 0) {
				$version['ok'] = $admin900.'<br /><a href="'.trim($lines[2]).'" target="_blank" title="'.$admin900.'">'.$admin901.' '.$version['latest'].' '.$admin902.' '.trim($lines[1])."</a>\n";
			}
			else {
				$version['ok'] = $admin903;
			}
		}
	}
	$php_os = PHP_OS;
	$php_rel = @php_uname('r');
?>
<hr /><p align="center"><strong><?php echo $admin895; ?></strong></p><hr /><br />
<div class="rep" style="padding:8px;width:480px;height:104px;margin-left:auto;margin-right:auto;overflow:auto;text-align:left;">
<fieldset>
	<legend><?php echo $admin904; ?></legend>
	<ul>
		<li>GuppY <?php echo $version['current']; ?></li>
		<li><?php
		if ($version['ok']!=""){
			echo "<span style=\"color:green;\">".$version['ok'];
		}
		else {
			echo "<span style=\"color:red;\">".$version['errors'];
		} ?></span></li>
	</ul>
</fieldset>
<fieldset>
	<legend><?php echo $admin905; ?></legend>
	<ul><?php
		echo "		<li>$admin906&nbsp;:&nbsp;".$php_os.' '.$php_rel."</li>\n";
		echo "		<li>PHP&nbsp;:&nbsp;".phpversion()." (<a href='admin.php?lng=$lng&amp;pg=infos&amp;itact=phpinfo' title='$admin907'>$admin907</a>)</li>\n";
		echo "		<li>$admin53".$site[3]."</li>\n"; ?>
	</ul>
</fieldset>
		<?php
		$pluginlist = ExploreDir('admin/plugins/');
		if (!empty($pluginlist)) {
			?>
<fieldset>
	<legend><?php echo $admin908; ?></legend>
	<ul>
			<?php
			$listplugin = 'Plugins : ';
			for ($i = 0; $i < count($pluginlist); $i++) {
				include("plugins/".$pluginlist[$i]."/plugin.inc");
				echo '		<li><a href="admin.php?lng='.$lng.'&amp;pg=plugin&amp;plug='.$plugin_admin_url.'">'.strip_tags($plugin_admin_name).'</a></li>'."\n";
				$listplugin .= ($i!=0)?", ":"";
				$listplugin .= strip_tags($plugin_admin_name);
		  }
			?>
	</ul>
</fieldset>
			<?php
		}
		?>
<br /></div><br />
<hr /><p><strong><?php echo $admin909." :"; ?></strong></p><hr />
<script type="text/javascript">
window.CopyToClipboard = function(rSource){
	rSource.select();
	if(window.clipboardData){
		var r=clipboardData.setData('Text',rSource.value); rSource.blur(); return 1;
	}
	else return 0;
}
</script>

<textarea cols="59" rows="6" onfocus="if(window.CopyToClipboard(this)) alert('<?php echo $admin910; ?>')">
<?php
		echo 'GuppY '.$version['current']."\n".$admin906.'&nbsp;:&nbsp;'.$php_os.' '.$php_rel."\n";
		echo 'PHP&nbsp;:&nbsp;'.phpversion()."\n";
		echo $admin53.$site[3];
		if (!empty($pluginlist)) echo "\n".$listplugin;
?>
</textarea>
<?php
}
?>
