<?php
$type = "ar";
$fileid = "9";
$status = "a";
$creadate = "201210150400";
$moddate = "201210150400";
$author = stripslashes("GuppY Team");
$email = stripslashes("webmaster@guppy.cms");
$fielda1 = stripslashes("<!--01-->GuppY");
$fielda2 = stripslashes("<!--01-->GuppY");
$fieldb1 = stripslashes("<!--02-->Installation");
$fieldb2 = stripslashes("<!--02-->Install");
$fieldc1 = stripslashes("<h3>
	<font color=\"#ff0000\">I. Première installation (démo)</font></h3>
<p>
	<br />
	<br />
	Ce paragraphe sur la première installation explique comment préparer un site GuppY avec du contenu de démonstration, de façon à ce que vous puissiez jouer avec.</p>
<ul>
	<li>
		<p>
			Téléchargez le fichier <strong>guppy.zip</strong> (<a href=\"http://www.freeguppy.org/\" target=\"_blank\">http://www.freeguppy.org</a>) sur votre PC.</p>
	</li>
	<li>
		<p>
			Décompressez ce fichier <strong>guppy.zip</strong> avec votre programme de décompression favori (7zip, WinZip, Winrar...) dans un dossier de votre PC.</p>
	</li>
	<li>
		<p>
			<strong>BRAVO</strong>, GuppY est prêt à fonctionner !</p>
	</li>
	<li>
		<p>
			Si vous souhaitez jouer avec GuppY sur votre PC avant de le mettre sur Internet, installez EasyPHP (<a href=\"http://www.easyphp.org/\" target=\"_blank\">http://www.easyphp.org</a>) sur votre PC et copiez le contenu du dossier précédent dans le sous-répertoire <strong>www</strong> de EasyPHP, puis lancez EasyPHP... et votre site web tournera en local sur votre PC. C\'est aussi simple que cela !</p>
	</li>
	<li>
		<p>
			Si vous souhaitez installer votre site directement sur Internet, alors copiez tous les fichiers décompressés sur le FTP de votre site avec un simple programme client FTP (FileZilla, FireFTP, CuteFTP, etc.). Et c\'est tout, il vous suffit maintenant de taper l\'URL de votre site dans la barre d\'adresse de votre navigateur pour vous retrouver sur votre site \"online\".</p>
	</li>
	<li>
		<p>
			Félicitations, vous venez d\'installer GuppY avec succès !</p>
	</li>
</ul>
<p>
	<br />
	&nbsp;</p>
<p>
	<span style=\"background: rgb(255, 255, 0) none repeat scroll 0% 50%; -moz-background-clip: -moz-initial; -moz-background-origin: -moz-initial; -moz-background-inline-policy: -moz-initial;\"><strong>REMARQUE IMPORTANTE</strong></span><br />
	<br />
	-Si vous ne prévoyez pas d\'installer une base de données vierge, supprimez le répertoire <strong>install/</strong> maintenant.Sinon toute personne qui l\'exécuterait détruirait tout le contenu de votre site web !</p>
<p>
	&nbsp;</p>
<p>
	<span style=\"background: rgb(255, 255, 0) none repeat scroll 0% 50%; -moz-background-clip: -moz-initial; -moz-background-origin: -moz-initial; -moz-background-inline-policy: -moz-initial;\"><strong>ALTERNATIVE</strong></span><br />
	<br />
	Vous pouvez aussi télécharger <strong>miniGuppY</strong> sur le site de GuppY. miniGuppY est un package qui comprend un serveur léger et complet (ZazouMiniWebServer) et GuppY, le tout \"packagé\"avec un programme d\'installation automatique pour PC sous Windows.</p>
<p>
	On ne peut pas faire plus simple !</p>
<p>
	miniGuppY ne modifie pas la base de registres de Windows, s\'installe aussi bien sur clé USB et se prête donc parfaitement à une utilisation \"nomade\";.</p>
<p>
	<br />
	&nbsp;</p>
<p>
	<strong><span style=\"text-decoration: underline;\">Remarque \"CHMOD\";</span></strong><br />
	<br />
	Voici comment mettre en place les droits sur les fichiers pour les serveurs internet qui le nécessitent (pas tous).</p>
<p>
	1. Répertoire admin<br />
	- Fichier admin/mdp.php : droits = 666. commande UNIX = chmod 666 admin/mdp.php<br />
	+ Répertoire admin/redac : droits = 777. commande UNIX = chmod 777 admin/redac<br />
	- Fichiers admin/redac/* : droits = 666. commande UNIX = chmod 666 admin/redac/*</p>
<p>
	2. Répertoire data : droits = 777. commande UNIX = chmod 777 data<br />
	- Fichiers data/* : droits = 666. commande UNIX = chmod 666 data/*<br />
	+ Répertoire data/archive : droits = 777. commande UNIX = chmod 777 data/archive<br />
	- Fichiers data/archive/* : droits = 666. commande UNIX = chmod 666 data/archive/*<br />
	+ Répertoire data/cache : droits = 777. commande UNIX = chmod 777 data/cache<br />
	- Fichiers data/cache/* : droits = 666. commande UNIX = chmod 666 data/cache/*<br />
	+ Répertoire data/countmsg : droits = 777. commande UNIX = chmod 777 data/countmsg<br />
	- Fichiers data/countmsg/* : droits = 666. commande UNIX = chmod 666 data/countmsg/*<br />
	+ Répertoire data/usermsg : droits = 777. commande UNIX = chmod 777 data/usermsg<br />
	- Fichiers data/usermsg/* : droits = 666. commande UNIX = chmod 666 data/usermsg/*<br />
	+ Répertoire data/error : droits = 777. commande UNIX = chmod 777 data/error<br />
	- Fichiers data/error/* : droits = 666. commande UNIX = chmod 666 data/error/*</p>
<p>
	3. Répertoire file : droits = 777 : commande UNIX = chmod 777 file<br />
	- Fichiers file/* : droits = 666. commande UNIX = chmod 666 file/*</p>
<p>
	4. Répertoire img : droits = 777. commande UNIX = chmod 777 img<br />
	- Fichiers img/* : droits = 666. commande UNIX = chmod 666 img/*</p>
<p>
	5. Répertoire pages : droits = 777. commande UNIX = chmod 777 pages<br />
	- Fichiers pages/* : droits = 666. commande UNIX = chmod 666 pages/*</p>
<p>
	6. Répertoire photo : droits = 777. commande UNIX = chmod 777 photo<br />
	- Fichiers photo/* : droits = 666. commande UNIX = chmod 666 photo/*<br />
	<br />
	7. Pour <b>tous</b> les dossiers de skins il sera peut-être nécessaire de chmoder aussi les fichier de configuration:<br />
	- skin/ma_skin/confskin.inc : droits = 666. commande UNIX = chmod 666 skin/ma_skin/confskin.inc<br />
	- skin/ma_skin/style.css : droits = 666. commande UNIX = chmod 666 skin/ma_skin/style.css</p>
<p>
	<br />
	<br />
	Comment détecter que vous devez exécuter ces \"CHMOD\" ? Eh bien c\'est facile àdétecter, c\'est quand vous obtenez une ribambelle de messages d\'erreurs de ce style :</p>
<p>
	<em>Warning: fopen(\"data/logh.dtb\",\"w\")- Permission denied in http://www.mysite.com/inc/functions.php online 198<br />
	Warning: Supplied argument is not a valid File-Handleresource in http://www.mysite.com/inc/ functions.php on line206<br />
	Warning: fopen(\"../data/logh.dtb\", \"w\") -Read-only file system in functions.php on line 198<br />
	Warning:fputs(): supplied argument is not a valid File-Handle resource infunctions.php on line 206</em></p>
<p>
	<br />
	<strong><span style=\"text-decoration: underline;\">Remarque .htaccess</span></strong><br />
	<br />
	GuppY est proposé avec un fichier <strong>.htaccess</strong> dans le répertoire racine. Ce fichier n\'est utile que si votre serveur web fonctionne sous Apache (serveur web le plus commun). Voici sa structure:<br />
	--------------------------------------<br />
	&lt;files&gt;<br />
	Order allow,deny<br />
	Deny from all<br />
	Satisfy All<br />
	&lt;/files&gt;<br />
	&lt;files&gt;<br />
	Order allow,deny<br />
	Deny from all<br />
	Satisfy All<br />
	&lt;/files&gt;<br />
	ErrorDocument 400 /error.php?err=400<br />
	ErrorDocument 403 /error.php?err=403<br />
	ErrorDocument 404 /error.php?err=404<br />
	ErrorDocument 500 /error.php?err=500<br />
	--------------------------------------<br />
	Les 10 premières lignes servent à protéger le contenu de votre base de données des regards indiscrets des internautes mal intentionnés (et il y en a !). Sinon, des fichiers comme le fichier data/frth.dtb par exemple qui contient toutes les adresses e-mail des gens ayant posté un message dans le forum sont lisibles et peuvent même servir à alimenter un fichier de Spam (berk !). Ces 10 lignes sont à laisser telles quelles.<br />
	<br />
	Les 4 lignes suivantes servent à rediriger les internautes vers la page erreur lorsqu\'ils demandent une page inexistante, etc. Celles ci doivent être adaptées par vos soins (via un simple éditeur de texte comme Notepad ou Notepad++ par exemple) selon l\'endroit où est placé votre GuppY.<br />
	<br />
	Ainsi, si votre installation GuppY est faite à la racine de votre site (URL = http://www.votresite.com/) alors vous n\'avez rien à faire. Par contre si votre installation GuppY est faite dans un répertoire de votre site (URL =http://www.votresite.com/ici/ par exemple) alors il vous faut modifier ainsi ces 4 lignes:<br />
	------------------------------------------<br />
	ErrorDocument 400/ici/error.php?err=400<br />
	ErrorDocument 403/ici/error.php?err=403<br />
	ErrorDocument 404/ici/error.php?err=404<br />
	ErrorDocument 500/ici/error.php?err=500<br />
	------------------------------------------<br />
	<br />
	Dans certains cas, vous aurez peut-être à modifier ainsi ces 4 lignes (pour un site dont l\'URL serait http://www.votresite.com/):<br />
	--------------------------------------------------------------<br />
	ErrorDocument400 http://www.votresite.com/error.php?err=400<br />
	ErrorDocument 403http://www.votresite.com/error.php?err=403<br />
	ErrorDocument 404http://www.votresite.com/error.php?err=404<br />
	ErrorDocument 500http://www.votresite.com/error.php?err=500<br />
	--------------------------------------------------------------<br />
	<br />
	Ou encore, si installé dans le sous-répertoire ici/:<br />
	------------------------------------------------------------------<br />
	ErrorDocument400 http://www.votresite.com/ici/error.php?err=400<br />
	ErrorDocument403 http://www.votresite.com/ici/error.php?err=403<br />
	ErrorDocument404 http://www.votresite.com/ici/error.php?err=404<br />
	ErrorDocument500http://www.votresite.com/ici/error.php?err=500<br />
	------------------------------------------------------------------<br />
	<br />
	Il serait aussi judicieux de protéger votre répertoire par un nom d\'utilisateur et un mot de passe spécifiques via <strong>.htaccess</strong>. Comme la façon de faire est souvent spécifique à votre hébergeur, merci de consulter ses pages d\'aide à ce sujet.<br />
	Pour de plus amples renseignements sur la protection de votre site par .htaccess, référez-vous à la documentation officielle d\'Apache.</p>
<p>
	&nbsp;</p>
<h3>
	<font color=\"#ff0000\">II. Installation propre</font></h3>
<p>
	<br />
	L\'installation propre permet de supprimer le contenu de démonstration et de commencer avec un beau site GuppY vierge de tout contenu.<br />
	<br />
	Le point de départ de cette installation propre est n\'importe où entre la première installation et l\'état de votre base de démo avec son contenu que vous avez pu modifier. Cette installation va détruire tout le contenu mais garder le paramétrage que vous avez pu réaliser dans les différents &amp;quot;Config quelquechose&amp;quot; dans la zone d\'admin.</p>
<ul>
	<li>
		<p>
			Si l\'URL de votre site est http://www.mysite.com/ alors saisissez le texte suivant dans votre navigateur : <a href=\"http://www.mysite.com/install/\"><strong>http://www.mysite.com/install/</strong></a></p>
	</li>
	<li>
		<p>
			Suivez les instructions pour une <strong>\"Installation propre\"</strong>.</p>
	</li>
	<li>
		<p>
			Félicitations, votre site web est prêt à fonctionner avec votre contenu !<br />
			&nbsp;</p>
	</li>
</ul>
<h3>
	<font color=\"#ff0000\">III. Migrer d\'une version ANTERIEURE à Miniportail 1.7 ou GuppY 2.4</font></h3>
<ul>
	<li>
		<p>
			Faites une <strong>sauvegarde</strong> complète de votre site avant de passer à l\'étape suivante.</p>
	</li>
	<li>
		<p>
			Exécutez un <span style=\"font-weight: bold;\">\"</span><strong>contrôle d\'intégrité DB</strong>\". Assurez-vous qu\'il ne produit pas d\'erreur sinon exécutez-le une nouvelle fois.</p>
	</li>
	<li>
		<p>
			Aller dans Config. Site pour activer la skin <span style=\"font-weight: bold;\">\"</span><strong>no_skin</strong>\".</p>
	</li>
	<li>
		<p>
			Aller dans les pages d\'administration des plugins pour retirer les <strong>icônes</strong> de la barre supérieure d\'icônes.</p>
	</li>
	<li>
		<p>
			Supprimez les fichiers contenus à la racine de votre site (/) sauf guppy.ico<br />
			Conservez précieusement les 5 répertoires : <strong>data</strong>/ ; <strong>file</strong>/ ; <strong>img</strong>/ ; <strong>pages</strong>/ et <strong>photo</strong>/ qu\'il ne faut donc surtout pas les supprimer de votre site web.<br />
			Suprimez les autres repertoires : <strong>admin</strong>/ ; <strong>inc</strong>/ ; <strong>install</strong>/ et <strong>mobile</strong>/ et tout leurs contenus y compris leurs sous-répertoires.<br />
			(<strong>mobile</strong>/ est apparu avec la version 2.3)</p>
	</li>
	<li>
		<p>
			Ajoutez les nouveaux répertoires et fichiers de la nouvelle version de GuppY : / ; <strong>admin</strong>/ ; <strong>flash</strong>/ ; <strong>inc</strong>/ ; <strong>install</strong>/ ; <strong>mobile</strong>/ ; <strong>plugins</strong>/ et <span style=\"text-decoration: underline;\"><strong>skins</strong></span>/ .</p>
	</li>
	<li>
		<p>
			Si l\'URL de votre site est http://www.mysite.com/ alors saisissez le texte suivant dans la barre d\'adresse de votre navigateur : <a href=\"http://www.mysite.com/install/migrate17.php\">http://www.mysite.com/install/migrate17.php</a><br />
			puis http://www.mysite.com/install/migrate18.php si vous êtes en version &lt; 1.7 de miniPortail. Ou bien exécutez http://www.mysite.com/install/migrate18.php si vous êtes en version 1.7 de miniPortail.</p>
	</li>
	<li>
		<p>
			Vérifiez si la remarque <span style=\"font-weight: bold;\">\"</span><strong>CHMOD</strong>\" (du paragraphe 2) s\'applique à votre installation. C\'est le cas si vous avez eu à l\'appliquer dans vos installations/migrations précédentes de miniPortail / GuppY.</p>
	</li>
	<li>
		<p>
			Si l\'URL de votre site est http://www.mysite.com/ alors saisissez le texte suivant dans la barre d\'adresse de votre navigateur : <a href=\"http://www.mysite.com/install/\">http://www.mysite.com/install/</a></p>
	</li>
	<li>
		<p>
			Suivez les instructions pour une <span style=\"font-weight: bold;\">\"</span><strong>Migration</strong>\".</p>
	</li>
	<li>
		<p>
			Félicitations, vous venez de migrer dans la toute dernière version de GuppY.</p>
	</li>
	<li>
		<p>
			Des modifications dans le paramétrage vous imposent de revérifier \"Config générale\", \"Config site\", \"Config sections\", \"Config services\", \"Config boîtes\", \"Config forum\" et \"Config style\". Il vous faudra aussi faire tourner un \"Contrôle d\'intégrité DB\" pour mettre à jour les index de la base de données GuppY.</p>
	</li>
	<li>
		<p>
			Il vous reste à installer votre skin et vos plugins en vous assurant auparavant que vous disposez de versions compatibles avec la présente version.<br />
			&nbsp;</p>
	</li>
</ul>
<h3>
	<font color=\"#ff0000\">IV. Migrer d\'une version ULTERIEURE à Miniportail 1.7 ou GuppY 2.4</font></h3>
<p>
	&nbsp;</p>
<p>
	<strong>IMPORTANT </strong>: le script de migration est destiné aux sitesweb fonctionnant avec miniPortail v1.8 ou GuppY v 2.4 ou ultérieure.</p>
<ul>
	<li>
		<p>
			Faites une <strong>sauvegarde</strong> complète de votre site avant de passer à l\'étape suivante.</p>
	</li>
	<li>
		<p>
			Exécutez un <span style=\"font-weight: bold;\">\"</span><strong>contrôle d\'intégrité DB\"</strong>. Assurez-vous qu\'il ne produit pas d\'erreur sinon exécutez-le une nouvelle fois.</p>
	</li>
	<li>
		<p>
			Désactiver les <strong>plugins</strong> utilisés.</p>
	</li>
	<li>
		<p>
			Aller dans Config. Site pour activer la skin <span style=\"font-weight: bold;\">\"</span><strong>no_skin</strong>\".</p>
	</li>
	<li>
		<p>
			Aller dans les pages d\'administration des plugins pour retirer les <strong>icônes</strong> de la barre supérieure d\'icônes.</p>
	</li>
	<li>
		<p>
			Aller dans Config. Boîtes pour retirer les boîtes latérales des <strong>plugins</strong>.</p>
	</li>
	<li>
		<p>
			Supprimez les fichiers contenus à la racine de votre site (/) sauf guppy.ico<br />
			Conservez précieusement les 6 répertoires : <strong>data/ ; file/ ; img/ ; flash/ ; pages/ et photo/</strong> qu\'il ne faut donc surtout pas supprimer de votre site web.<br />
			Supprimez les autres repertoires : <strong>admin/ ; inc/ ; install/ ; mobile/ </strong>et<strong> plugins/</strong> et tout leurs contenus y compris leurs sous-répertoires.<br />
			(mobile/ est apparu avec la version 2.3 ; <strong>plugins</strong>/ est apparu avec la version 3.0 ; <strong>flash/</strong> et <strong>skins/</strong> avec la version 4.6)</p>
	</li>
	<li>
		<p>
			Ajoutez les nouveaux répertoires et fichiers de la nouvelle version de GuppY : / ; <strong>admin/ ; flash/ ; inc/ ; install/ ; mobile/ ; plugins/ et <span style=\"text-decoration: underline;\">skins</span>/</strong> .</p>
	</li>
	<li>
		<p>
			Vérifiez si la remarque <span style=\"font-weight: bold;\">\"</span><strong>CHMOD</strong>\" (du paragraphe 2) s\'applique à votre installation. C\'est le cas si vous avez eu à l\'appliquer dans vos installations/migrations précédentes de miniPortail / GuppY.</p>
	</li>
	<li>
		<p>
			Si l\'URL de votre site est http://www.mysite.com/ alors saisissez le texte suivant dans la barre d\'adresse de votre navigateur : http://www.mysite.com/install/</p>
	</li>
	<li>
		<p>
			Suivez les instructions pour une <span style=\"font-weight: bold;\">\"</span><strong>Migration</strong>\".</p>
	</li>
	<li>
		<p>
			Félicitations, vous venez de migrer dans la toute dernière version de GuppY.</p>
	</li>
	<li>
		<p>
			Des modifications dans le paramétrage vous imposent de revérifier \"Config générale\", \"Config sections\", \"Config services\", \"Config accueil\", \"Config forum\", et pour chaque skin \"Config boîtes\",&nbsp; \"Config site\",et \"Config style\". Il vous faudra aussi faire tourner un \"Contrôle d\'intégrité DB\" pour mettre à jour les index de la base de données GuppY.</p>
	</li>
	<li>
		<p>
			Il vous reste à installer votre skin et vos plugins en vous assurant auparavant que vous disposez de versions compatibles avec la présente version.<br />
			&nbsp;</p>
	</li>
</ul>
<h3>
	<font color=\"#ff0000\">V. Remarques importantes à prendre en compte pour toute installation ou mise à jour :</font></h3>
<ul>
	<li>
		<p>
			Une fois que vous avez fini la migration, assurez-vous que les fichiers dans le répertoire <strong>install</strong>/ ont bien été supprimés. Sinon toute personne qui l\'exécuterait détruirait tout le contenu de votre site web !</p>
	</li>
	<li>
		<p>
			Si vous ne pouvez plus voir le répertoire <strong>install</strong>/, ça veut dire que tout s\'est passé correctement. Même conclusion si le répertoire <strong>install</strong>/ existe toujours mais est vide (supprimez le alors par FTP, votre hébergeur n\'autorise pas son effacement par PHP).</p>
	</li>
	<li>
		<p>
			A l\'issue de la migration, le mot de passe d\'admin est remis à <span style=\"font-weight: bold;\">\"</span><strong>pass\"</strong>. N\'oubliez pas de le changer.<br />
			Profitez-en pour <span style=\"font-weight: bold;\">revalider</span> <span style=\"text-decoration: underline;\">toutes</span> les pages de configuration (<span style=\"text-decoration: underline;\">même après une mise à jour</span>)</p>
	</li>
	<li>
		<p>
			Si vous avez rapatrié votre site en local ou inversement, aussitôt le transfert effectué modifiez l\'url de votre site comme indiqué dans \"config générale\", sinon vous pourriez rencontrer quelques messages d\'erreurs lors de l\'édition d\'article.</p>
	</li>
</ul>
<p>
	<br />
	&nbsp;</p>
");
$fieldc2 = stripslashes("<h3>
	<font color=\"#ff0000\">I. First install (demo)</font></h3>
<p>
	<br />
	This first install paragraph explains how to set up a GuppY web site with some demo content, so that you can play with it.</p>
<ul>
	<li>
		<p>
			Download the <strong>guppy.zip</strong> file (<a href=\"http://www.freeguppy.org/\" target=\"_blank\">http://www.freeguppy.org</a>) on your PC.</p>
	</li>
	<li>
		<p>
			Unzip this <strong>guppy.zip</strong> file in a directory of your PC with your favorite unzipping tool (7zip, WinZip, Winrar...).</p>
	</li>
	<li>
		<p>
			<strong>EXCELLENT</strong>! GuppY is ready to run !</p>
	</li>
	<li>
		<p>
			If you wish to play with GuppY on your PC before putting it on the Internet, install a webserver and PHP (you may also rather install a package like EasyPHP - <a href=\"http://www.easyphp.org/\" target=\"_blank\">http://www.easyphp.org</a>) on your PC and copy the content of the directory where you unzipped guppy.zip in the <strong>www</strong> sub directory of EasyPHP, then launch EasyPHP... and your site will be running locally on your PC. It\'s just as easy as that !</p>
	</li>
	<li>
		<p>
			If you wish to install your web site directly on the Internet, then copy all unzipped files via FTP to your site with a simple FTP client software (FileZilla, FireFTP, CuteFTP, etc.). And that\'s all, you now just need to input the URL of your site in your browser to find yourself on your web site.</p>
	</li>
	<li>
		<p>
			Wonderful, you\'ve just installed GuppY successfully!</p>
	</li>
</ul>
<p>
	<br />
	<span style=\"background: rgb(255, 255, 0) none repeat scroll 0% 50%; -moz-background-clip: -moz-initial; -moz-background-origin: -moz-initial; -moz-background-inline-policy: -moz-initial;\"><strong>IMPORTANT NOTICE</strong></span><br />
	<br />
	- If you do not plan to prepare a new clean database, delete the <strong>install/</strong> directory now. Otherwise anybody could run it on yourweb site and delete all the content on your web site!</p>
<p>
	&nbsp;</p>
<p>
	<span style=\"background: rgb(255, 255, 0) none repeat scroll 0% 50%; -moz-background-clip: -moz-initial; -moz-background-origin: -moz-initial; -moz-background-inline-policy: -moz-initial;\"><strong>ALTERNATIVE</strong></span><br />
	<br />
	Youcan also download <strong>miniGuppY</strong> on the GuppY site. miniGuppY is a package made of a light web server, PHP and GuppY, all packaged with an automated install program for a PC with Windows. You just cannot do easier than that !</p>
<p>
	&nbsp;</p>
<p>
	<strong><span style=\"text-decoration: underline;\">.CHMOD</span></strong><br />
	<br />
	Here is how to set upfiles rights for web servers that require it (not all of them requireit).<br />
	1. Directory admin<br />
	- File admin/mdp.php : rights = 666. UNIX command = chmod 666 admin/mdp.php<br />
	+ Directory admin/redac : rights = 777. UNIX command = chmod 777 admin/redac<br />
	- Files admin/redac/* : rights = 666. UNIX command = chmod 666 admin/redac/*<br />
	2. Directory data : rights = 777. UNIX command = chmod 777 data<br />
	- Files data/* : rights = 666. UNIX command = chmod 666 data/*<br />
	+ Directory data/archive : rights = 777. UNIX command = chmod 777 data/archive<br />
	- Files data/archive/* : rights = 666. UNIX command = chmod 666 data/archive/*<br />
	+ Directory data/cache : rights = 777. UNIX command = chmod 777 data/cache<br />
	- Files data/cache/* : rights = 666. UNIX command = chmod 666 data/cache/*<br />
	+ Directory data/countmsg : rights = 777. UNIX command = chmod 777 data/countmsg<br />
	- Files data/countmsg/* : rights = 666. UNIX command = chmod 666 data/countmsg/*<br />
	+ Directory data/usermsg : rights = 777. UNIX command = chmod 777 data/usermsg<br />
	- Files data/usermsg/* : rights = 666. UNIX command = chmod 666 data/usermsg/*<br />
	+ Directory data/error : rights = 777. UNIX command = chmod 777 data/error<br />
	- Files data/error/* : rights = 666. UNIX command = chmod 666 data/error/*<br />
	3. Directory file : rights = 777. UNIX command = chmod 777 file<br />
	- Files file/* : rights = 666. UNIX command = chmod 666 file/*<br />
	4. Directory img : rights = 777. UNIX command = chmod 777 img<br />
	- Files img/* : rights = 666. UNIX command = chmod 666 img/*<br />
	5. Directory pages : rights = 777. UNIX command = chmod 777 pages<br />
	- Files pages/* : rights = 666. UNIX command = chmod 666 pages/*<br />
	6. Directory photo : rights = 777. UNIX command = chmod 777 photo<br />
	- Files photo/* : rights = 666. UNIX command = chmod 666 photo/*<br />
	<br />
	7. For <b>all</b> skins directories, it should be necessary to chmod the skin configuration files:<br />
	- skin/your_skin/confskin.inc : rights = 666. UNIX command = chmod 666 skin/your_skin/confskin.inc<br />
	- skin/your_skin/style.css : rights = 666. UNIX command = chmod 666 skin/your_skin/style.css<br />
	<br />
	<br />
	How can you detect that you should execute these &amp;quot;CHMOD&amp;quot; ?Well, it is pretty easy to know, it is in the case you get many errormessages of this kind :</p>
<p>
	<em>Warning: fopen(\"data/logh.dtb\",\"w\")- Permission denied in http://www.mysite.com/inc/functions.php online 198<br />
	Warning: Supplied argument is not a valid File-Handleresource in http://www.mysite.com/inc/ functions.php on line206<br />
	Warning: fopen(\"../data/logh.dtb\", \"w\") -Read-only file system in functions.php on line 198<br />
	Warning:fputs(): supplied argument is not a valid File-Handle resource infunctions.php on line</em></p>
<p>
	<br />
	<strong><span style=\"text-decoration: underline;\">.htaccess notice</span></strong><br />
	<br />
	GuppY is shipped with a<strong>.htaccess</strong> file in the root directory. This file is only usefulif your web site runs with an Apache server (this is the case most ofthe time). Here is itsstructure:<br />
	--------------------------------------<br />
	&lt;files&gt;<br />
	Order allow,deny<br />
	Deny from all<br />
	Satisfy All<br />
	&lt;/files&gt;<br />
	&lt;files&gt;<br />
	Order allow,deny<br />
	Deny from all<br />
	Satisfy All<br />
	&lt;/files&gt;<br />
	ErrorDocument 400 /error.php?err=400<br />
	ErrorDocument 403 /error.php?err=403<br />
	ErrorDocument 404 /error.php?err=404<br />
	ErrorDocument 500 /error.php?err=500<br />
	--------------------------------------<br />
	The first 10 lines are used to protect the content of your database from hackers and other bad people (and there are some !). Otherwise, files like the data/frth.dtb file for example which hold all e-mail addresses of the people who posted a message in the forum can be read and even help to enrich a Spam file (ugly !). These 10 lines are not to be modified.<br />
	<br />
	The 4 following lines are used to direct users to the error page when ask for a non existing page or other possible errors. These lines might require to be adapted (with a simple text editor like Notepad or Wordpad for example) according to where you have put your GuppY.<br />
	<br />
	If you\'ve installed GuppY at the root of your site (URL = http://www.yoursite.com/) then you have nothing to do. But if you installed it in a directory of your site (URL =http://www.yoursite.com/here/ for example) then you will have to modify these 4 lines:<br />
	-------------------------------------------<br />
	ErrorDocument 400/here/error.php?err=400<br />
	ErrorDocument 403/here/error.php?err=403<br />
	ErrorDocument 404/here/error.php?err=404<br />
	ErrorDocument 500/here/error.php?err=500<br />
	-------------------------------------------<br />
	<br />
	In some cases, you might need to modify these 4 lines as follows (for a website having a URL like http://www.yoursite.com/) :<br />
	-------------------------------------------------------------<br />
	ErrorDocument 400 http://www.yoursite.com/error.php?err=400<br />
	ErrorDocument 403http://www.yoursite.com/error.php?err=403<br />
	ErrorDocument 404http://www.yoursite.com/error.php?err=404<br />
	ErrorDocument 500http://www.yoursite.com/error.php?err=500<br />
	-------------------------------------------------------------<br />
	<br />
	Or,if installed in the here/ subdir:<br />
	------------------------------------------------------------------<br />
	ErrorDocument 400 http://www.yoursite.com/here/error.php?err=400<br />
	ErrorDocument 403 http://www.yoursite.com/here/error.php?err=403<br />
	ErrorDocument 404 http://www.yoursite.com/here/error.php?err=404<br />
	ErrorDocument 500 http://www.yoursite.com/here/error.php?err=500<br />
	------------------------------------------------------------------<br />
	<br />
	It would also be wise to protect your directory by a user name and password within the <strong>.htaccess</strong> file. As the way of doing it is usually specific to your web host, please refer to its documentation for this topic.<br />
	For further information on how to protect your website with a .htaccess file, please refer to the official Apachedocumentation.</p>
<h3>
	<font color=\"#ff0000\">II. Clean install</font></h3>
<p>
	The clean install is meant for when you want to erase the demo content and start with a brand new empty GuppY site.<br />
	<br />
	The starting point for this clean install is anywhere between the first install and anything you did with the demo content. It will erase all of the content but keep the current parameters set up in the different Config and Admin areas.<br />
	&nbsp;</p>
<ul>
	<li>
		<p>
			If your web site URL is http://www.mysite.com/ input the following URL in your browser : <a href=\"http://www.mysite.com/install/\"><strong>http://www.mysite.com/install/</strong></a></p>
	</li>
	<li>
		<p>
			Follow instructions for a <strong>\"Clean install\"</strong>.</p>
	</li>
	<li>
		<p>
			Great! Your web site is ready to run with your content !</p>
	</li>
</ul>
<h3>
	<font color=\"#ff0000\">III. Migrate from previous versions of Miniportail 1.7 or GuppY 2.4</font></h3>
<ul>
	<li>
		<p style=\"margin-bottom: 0cm;\">
			<strong>Back up</strong> whole web site before going ahead.<br />
			&nbsp;</p>
	</li>
	<li>
		<p>
			Run a<span style=\"font-weight: bold;\"> </span><strong>\"DB integrity check\"</strong>. Make sure it finds no error or run it again.</p>
	</li>
	<li>
		<p>
			To Config site to activate the skin \"<strong>no_skin\"</strong>.</p>
	</li>
	<li>
		<p>
			Go to the management pages of your plugins to <strong>take their icons </strong><strong>off </strong> from the top menu bar.</p>
	</li>
	<li>
		Preciously keep the five directories <span style=\"font-weight: bold;\">data, file, img, pages and photo</span>.</li>
</ul>
<ul>
	<li>
		<p>
			Copy the new directories and files from the latest version of GuppY (that is <strong>/ ; admin/ ; flash/ ; inc/ ; install/ </strong><span style=\"\">and</span><strong> mobile/ ; plugins/ et skins/ . </strong>) as well as install/ and its content.</p>
	</li>
	<li>
		<p>
			Check if the <span style=\"font-weight: bold;\">\"</span><strong>CHMOD</strong>\" notice (from paragraph #2) is required for your installation. This will be the case if you had to apply it for your previous miniPortail / GuppY installs/migrations.</p>
	</li>
	<li>
		<p>
			If your web site URL is http://www.mysite.com/ input the following URL in your browser : <a href=\"http://www.mysite.com/install/\"><strong>http://www.mysite.com/install/</strong></a></p>
	</li>
	<li>
		<p>
			Follow instructions for a <strong>\"Migration\"</strong>.</p>
	</li>
	<li>
		<p>
			Greta! You have just migrated to the latest version of GuppY.</p>
	</li>
	<li>
		<p>
			Some modifications in the GuppY parameters require you to check for \"General Config\", \"Site Config\", \"Home Config\", \"Sections Config\", \"Services Config\" and \"Boxes Config\". You will also have to run a \"DB integrity check\" for updating the GuppY database indexes.</p>
	</li>
</ul>
<h3>
	<font><font color=\"#ff0000\">IV. Migrate from latest versions than Miniportail 1.7 or GuppY 2.4</font></font></h3>
<p style=\"text-decoration: none;\">
	IMPORTANT : the migration script isfor web sites running with miniPortail version 1.8 or later / GuppYversion 2.4 or later.</p>
<ul>
	<li>
		<p style=\"margin-bottom: 0cm;\">
			<strong>Back up</strong> all of your web site before going ahead.<br />
			&nbsp;</p>
	</li>
</ul>
<ul>
	<li>
		<p>
			Run a <strong>\"DB integrity check\"</strong>. Make sure it finds no error or run it again.</p>
	</li>
	<li>
		<p>
			<strong>Deactivate</strong> the plugins you are using</p>
	</li>
	<li>
		<p>
			To Config site activate the skin <span style=\"font-weight: bold;\">\"</span><strong>no_skin</strong>\".</p>
	</li>
	<li>
		<p>
			Go to the management pages of your plugins to <strong>take their icons</strong> <strong>off </strong>from the heigher menu bar.</p>
	</li>
	<li>
		Preciously keep the five directories <span style=\"font-weight: bold;\">data, file, img, pages and photo</span></li>
	<li>
		<p>
			Copy the new directories and files from the latest version of GuppY (that is <strong>/ ; admin/ ; flash/ ; inc/ ; install/ ; mobile/ ; plugins/ </strong>and<strong> skins/ . </strong>) as well as install/ and its content.</p>
	</li>
	<li>
		<p>
			Check if the <span style=\"font-weight: bold;\">\"</span><strong>CHMOD</strong>\" notice (from paragraph #2) is required for your installation. This will be the case if you had to apply it for your previous miniPortail / GuppY installs/migrations.</p>
	</li>
	<li>
		<p>
			If your web site URL is http://www.mysite.com/ input the following URL in your browser : <a href=\"http://www.mysite.com/install/\"><strong>http://www.mysite.com/install/</strong></a></p>
	</li>
	<li>
		<p>
			Follow instructions for a <strong>\"Migration\"</strong>.</p>
	</li>
	<li>
		<p>
			Great! You have just migrated to the latest version of GuppY.</p>
	</li>
	<li>
		<p>
			Some modifications in the GuppY parameters require you to check for \"General Config\", \"Themes config\", \"Home Config\", \"Sections Config\", \"Services Config\", and for all skins \"Look config\", \"Generate CSS\" and \"Boxes Config\". You will also have to run a \"DB integrity check\" for updating the GuppY database indexes.</p>
	</li>
	<li>
		You need now to install your skin and compatible plugins</li>
</ul>
<p>
	&nbsp;</p>
<p>
	<span style=\"background: rgb(255, 255, 0) none repeat scroll 0% 50%; -moz-background-clip: -moz-initial; -moz-background-origin: -moz-initial; -moz-background-inline-policy: -moz-initial;\"><strong>V. IMPORTANT NOTICES </strong></span></p>
<ul>
	<li>
		<p>
			Once you have finished install or migrating, make sure that all the files in the <strong>install/</strong> directory were deleted. Otherwise anybody could run it on your web site and delete all the contents of your web site !</p>
	</li>
	<li>
		<p>
			If you cannot see the <strong>install/</strong> directory anymore, then it means that everything is fine. The same conclusion applies if the <strong>install/</strong> directory still exists but is empty (you should the delete it by FTP, as your webhoster does not allow its deletion with PHP).</p>
	</li>
	<li>
		<p>
			After the migration, the admin password is reset to <strong>\"pass\".</strong></p>
	</li>
	<li>
		<p>
			Don\'t forget to validate all admin pages to prevent from errors (<b>even after an update</b>).</p>
	</li>
</ul>
<p>
	&nbsp;</p>
");
$fieldd1 = stripslashes("left");
$fieldd2 = stripslashes("gyslogo.gif");
$fieldweb = stripslashes("");
$fieldmail = stripslashes("");
$fieldmod = stripslashes("");
