<?php
$type = "ar";
$fileid = "13";
$status = "a";
$creadate = "201210150400";
$moddate = "201210150400";
$author = stripslashes("GuppY Team");
$email = stripslashes("webmaster@guppy.cms");
$fielda1 = stripslashes("<!--01-->GuppY");
$fielda2 = stripslashes("<!--01-->GuppY");
$fieldb1 = stripslashes("<!--06-->Compatibilit�, probl�mes et notes techniques");
$fieldb2 = stripslashes("<!--06-->Compatibility, issues and technical notices");
$fieldc1 = stripslashes("<h3>
	<font color=\"#ff0000\">I. Compatibilit�</font></h3>
<p>
	Pour fonctionner correctement, GuppY a besoin que votre navigateur web puisse g�rer correctement les feuilles de style CSS et le langage HTML dans sa <strong>version 4</strong>.<br />
	<br />
	GuppY devrait fonctionner correctement avec <strong>Firefox, </strong><strong>Internet Explorer, Chrome, Opera</strong>, <span style=\"font-weight: bold;\">Safari</span> et bien d\'autres. Nous l\'avons test� avec ces navigateurs mais votre compte-rendu d\'utilisation sur un autre navigateur web sera le bienvenu <img alt=\"\" border=\"0\" src=\"inc/img/smileys/biggrin.gif\" /><br />
	&nbsp;</p>
<h3>
	<font color=\"#ff0000\">II. Probl�mes �ventuels</font></h3>
<p>
	- le nouvel �diteur WYSIWYG introduit dans cette version 4.6.17 est CK Editor. Il est compatible avec&nbsp; la plupart des navigateurs de derni�re g�n�ration et Windows, Mac, Linux.</p>
<p>
	- GuppY devrait maintenant (depuis la version 3.0) �tre <span style=\"text-decoration: underline;\">compatible � 100% avec</span> <strong>IIS</strong>, �a reste � tester.<br />
	&nbsp;</p>
<h3>
	<font color=\"#ff0000\">III. Notes techniques</font></h3>
<p>
	<span style=\"text-decoration: underline;\"><strong>1. e-mail</strong></span><br />
	<br />
	Certains h�bergeurs de sites ne travaillent pas avec la <strong>fonction PHP mail() standard</strong>, mais avec une version modifi�e de cette fonction (comme <em>Online.net</em> ou <em>Nexen.net</em> par exemple) ou une version \"truqu�e\" (comme <em>Free.fr</em> par exemple il fut un temps).<br />
	A partir de la version 2.4 de GuppY, ces fonctions e-mail peuvent �tre int�gr�es dans le r�pertoire <strong>inc/mail/</strong> d�di�.<br />
	<br />
	Si vous �crivez un script pour acc�der � une telle fonction sp�cifique d\'un h�bergeur (voir les fichiers <strong>Online.net.inc</strong> et <strong>Nexen.net.inc</strong> pour apprendre comment faire), l\'�quipe de d�veloppement de GuppY serait tr�s heureuse d\'en recevoir une copie.</p>
<p>
	&nbsp;</p>
<p>
	<span style=\"text-decoration: underline;\"><strong>2. e-mail sp�cifique � Free.fr</strong></span><br />
	<br />
	Free utilise d�sormais la fonction <strong>mail standard de PHP</strong>. Il n\'est donc plus n�cessaire d\'utiliser \"protomail\".</p>
<p>
	<span style=\"text-decoration: underline;\"><strong>3. Chargement de fichiers</strong></span><br />
	<br />
	Certains h�bergeurs (<strong>Free</strong> notamment) d�sactivent la fonctionnalit� de chargement HTTP. La fonctionnalit� <strong>\"Fichiers\"</strong> dans l\'admin est alors inutilisable. Vous transf�rerez donc vos fichiers sur votre site en utilisant votre logiciel FTP.</p>
<p>
	<span style=\"text-decoration: underline;\"><strong>4. Partage de contenu inter-sites au format RSS</strong></span><br />
	<br />
	Certains h�bergeurs limitent la fonction <strong>PHP include()</strong> � l\'acc�s des seuls fichiers internes au site, et ne permettent pas l\'acc�s aux fichiers d\'un autre site web. Dans ce cas, le module de partage de nouvelles au format RSS <span style=\"text-decoration: underline;\">ne fonctionnera pas</span>.</p>
<p>
	<span style=\"text-decoration: underline;\"><strong>5. Comment acc�der � la version mobile de GuppY</strong></span><br />
	<br />
	Si l\'acc�s � votre site se fait de cette fa�on : http://www.votresite.com/ici/ (par exemple), alors la version mobile (qui est destin�e aux utilisateurs de PDA et aux aveugles) est ais�ment et automatiquement accessible � l\'adresse suivante : <strong>http://www.votresite.com/ici/mobile/</strong>. Mettez juste un lien dans votre site pour indiquer � vos visiteurs comment y acc�der.</p>
<p>
	<span style=\"text-decoration: underline;\"><strong>6. e-mail de suivi � plusieurs destinataires</strong></span><br />
	<br />
	Un exemple de fonction qui permet l\'envoi d\'e-mails de suivi � plusieurs destinataires est fourni dans <strong>inc/mail/more1receiver.inc</strong>.</p>
<p>
	Soyez attentif au fait que <span style=\"text-decoration: underline;\">ce n\'est qu\'un exemple</span> (il se peut aussi que sa fonction mail ne soit pas adapt�e) et que vous aurez � �diter ce fichier <strong>inc/mail/more1receiver.inc</strong> (avec n\'importe quel �diteur de texte basique) et � saisir les identifiants (pseudo et adresse e-mail) suppl�mentaires.</p>
<p>
	<br />
	&nbsp;</p>
");
$fieldc2 = stripslashes("<h3>
	<font color=\"#ff0000\">I. Compatibility</font></h3>
<br />
<p>
	To work properly, GuppY needs that your web browser can manage correctly CSS stylesheets and HTML <strong>version 4</strong>.<br />
	<br />
	GuppY should work properly with <strong>Firefox, Internet Explorer</strong>, <span style=\"font-weight: bold;\">Chrome, </span><strong>Opera, Safari </strong>and many others. It was tested with these browsers, so your feedback with other browsers will be more than welcome <img alt=\"\" border=\"0\" src=\"inc/img/smileys/biggrin.gif\" /><br />
	&nbsp;</p>
<h3>
	<font color=\"#ff0000\">II. Known issues</font></h3>
<br />
<p>
	- New WYSIWYG editor that comes with version 4.6.17 is CK Editor.It is compatible with most latest generation browsers and Windows, Mac, Linux.</p>
<p>
	- GuppY should now (since version 3.0) be fully compliant with <strong>IIS</strong>, which has not yet been tested.</p>
<h3>
	<font color=\"#ff0000\">III. Technical notices</font></h3>
<p>
	<span style=\"text-decoration: underline;\"><strong>1. e-mail</strong></span><br />
	<br />
	Some web hosts do not work with the <strong>standard PHP mail() function</strong>, but with a modified version (like <em>Online.net</em> or <em>Nexen.net</em> for instance) or with a tricked version (like <em>Free.fr</em> for instance, see next paragraph). As from version 2.4 of GuppY, these e-mail functions can be set up in a dedicated <strong>inc/mail/</strong> directory.<br />
	<br />
	If you write such a script for a web host specific function (see the <strong>Online.net.inc</strong> and <strong>Nexen.net.inc</strong> to learn how to proceed), the GuppY development team would be more than happy to receive a copy of it.</p>
<p>
	<span style=\"text-decoration: underline;\"><strong>2. Free.fr </strong></span><span style=\"text-decoration: underline;\"><strong>specific </strong></span><span style=\"text-decoration: underline;\"><strong>e-mail </strong></span></p>
<p>
	Now Free uses the <strong>standard php mail function</strong>. Then you don\'t need to use \"protomail\".</p>
<p>
	<span style=\"text-decoration: underline;\"><strong>3. Files upload</strong></span><br />
	<br />
	Some web hosts disable the HTTP file upload functionality. Then, the <strong>Upload</strong> admin functionality will be useless. Upload your files o�n your site using your FTP software.</p>
<p>
	<span style=\"text-decoration: underline;\"><strong>4. Content sharing between sites in RSS format</strong></span><br />
	<br />
	Some web hosts limit the <strong>PHP include()</strong> function to access o�nly internal files, not files from another website.<br />
	Then, the news sharing module between sites in RSS format will not work.</p>
<p>
	<strong>5. How to access to the mobile version of GuppY</strong><br />
	<br />
	If your site is accessed this way : http://www.yoursite.com/here/ (for example), then the mobile version (which is a lightened version of GuppY aimed for PDA users and blind people) is easily and automatically accessed this way : <strong>http://www.yoursite.com/here/mobile/</strong>. Just put a link in your web site for telling your mobile visitors how to access it.</p>
<p>
	<span style=\"text-decoration: underline;\"><strong>6. Follow-up e-mail to more than o�ne receiver</strong></span><br />
	<br />
	An <span style=\"text-decoration: underline;\">example</span> of a function which sends follow-up e-mails to more than o�ne receivers is given in <strong>inc/mail/more1receiver.inc.</strong><br />
	Be careful that you have to edit the <strong>inc/mail/more1receiver.inc</strong> file (with any basic text file editor) and input the additional names and e-mail addresses (and perhaps correct the mail function).</p>
");
$fieldd1 = stripslashes("left");
$fieldd2 = stripslashes("gyslogo.gif");
$fieldweb = stripslashes("");
$fieldmail = stripslashes("");
$fieldmod = stripslashes("");
