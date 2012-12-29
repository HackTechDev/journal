<?php
$type = "ar";
$fileid = "11";
$status = "a";
$creadate = "201210150400";
$moddate = "201210150400";
$author = stripslashes("GuppY Team");
$email = stripslashes("webmaster@guppy.cms");
$fielda1 = stripslashes("<!--01-->GuppY");
$fielda2 = stripslashes("<!--01-->GuppY");
$fieldb1 = stripslashes("<!--04-->Gérer le contenu");
$fieldb2 = stripslashes("<!--04-->Manage the content");
$fieldc1 = stripslashes("<p>
	<strong>GuppY</strong> fonctionne grâce aux dernières technologies web.<br />
	<br />
	Pour comprendre comment il marche, retournons un peu en arrière et revenons sur la création d\'une page web traditionnelle. Dans une page web classique, on écrit du texte dans lequel on insère des <strong>tags HTML</strong> (pour Hyper Text Markup Language) qui indiquent au navigateur comment positionner et mettre en forme les différents éléments (texte, images, liens...) dans la page.<br />
	<br />
	On doit ensuite relier manuellement les différentes pages d\'un site entre elles via des <strong>liens</strong>. Et, chaque fois qu\'on veut modifier le rendu de son site, il faut reprendre l\'ensemble des pages...</p>
<p>
	C\'est lourd et fastidieux, et on passe rapidement plus de temps à gérer la mise en forme que le contenu !<br />
	<br />
	Maintenant, existent des langages de programmation web complets qui permettent de gérer du contenu Internet comme n\'importe quel programme qui tourne sur votre PC. Ainsi, GuppY utilise le langage de programmation le plus répandu, à savoir le <strong>PHP</strong> (qui signifie <strong>Hypertext PreProcessor</strong>).<br />
	<br />
	Le principe de GuppY est alors le suivant : on sépare le <strong>contenu</strong> (stocké dans une petite base de données \"texte\") de la <strong>mise en forme</strong> (gérée par l\'ensemble de scripts PHP qui composent GuppY).<br />
	<br />
	Et l\'on obtient ainsi ce que l\'on appelle un <strong>CMS</strong> (pour <strong>Content Management System</strong>). Bref, vous n\'avez plus qu\'à saisir l\'information dans les rubriques appropriées (articles, news, etc.) via une interface d\'administration (la petite icone \"Admin\" en haut à droite de l\'écran vous permet d\'y accéder) et GuppY se charge de la gestion complète et de la présentation de cette information selon les clics des visiteurs qui viennent sur votre site.<br />
	<br />
	Comme le code HTML est autorisé, il est possible d\'utiliser toutes les balises HTML que l\'on veut (IMG, A, B, I, U, etc.) dans les articles, liens, nouvelles, etc. Vérifiez bien systématiquement que ces balises n\'interfèrent pas de façon négative avec le fonctionnement du site.<br />
	<br />
	<em>Note : votre site sera aussi très beau sans insérer de balises HTML.</em> <img alt=\"\" border=\"0\" src=\"inc/img/smileys/wink.gif\" /><br />
	<br />
	Les visiteurs de votre site peuvent eux-mêmes poster des nouvelles, des messages dans le livre d\'or ou le forum. L\'usage des balises HTML est légèrement plus restreint pour eux, afin d\'éviter tout dysfonctionnement du site, mais un petit éditeur leur permet d\'utiliser les balises les plus courantes.<br />
	<br />
	Vous disposez de <strong>5 répertoires</strong> pour poser les objets spécifiques (via l\'icône <strong>\"Fichiers\"</strong>) :</p>
<p>
	- <strong><font color=\"#ff0000\">file</font></strong> : pour mettre les fichiers de téléchargement. Vous réfèrerez alors à un fichier via le tag HTML suivant : <strong>[A href=\"http://localhost/guppy/file/fichier.ext\"]texte[/A]</strong> (en remplaçant les [ et ] par &lt; et &gt;).</p>
<p>
	- <strong><font color=\"#ff0000\">img</font></strong> : pour mettre les images de fond, le logo de votre site et l\'ensemble des images avec lesquelles vous souhaitez agrémenter votre site. Vous réfèrerez alors à une image via le tag HTML suivant : <strong>[IMG src=\"http://localhost/guppy/img/image.ext\"]</strong> (en remplaçant les [ et ] par &lt; et &gt;).</p>
<p>
	- <strong><font color=\"#ff0000\">photo</font></strong> : pour mettre les photos du diaporama. Le diaporama détecte automatiquement la présence des images déposées dans ce répertoire et les proposera à l\'affichage.</p>
<p>
	- <strong><font color=\"#ff0000\">pages</font></strong> : pour mettre les pages HTML ou PHP spécifiques. Vous réfèrerez alors à une page via le tag HTML suivant : <strong>[A href=\"http://localhost/guppy/pages/page.ext\"]texte[/A]</strong> (en remplaçant les [ et ] par &lt; et &gt;).</p>
<p>
	- <span style=\"font-weight: bold; color: rgb(255, 0, 0);\">flash </span>: pour stocker vos animations vidéo au format flash, sauf vos bannières en flash qui doivent se trouver dans img<br />
	<br />
	<br />
	Enfin le répertoire <span style=\"font-weight: bold; color: rgb(255, 0, 0);\">skin</span> concerne l\'apparence de vos pages. C\'est ici que vous stockerez les répertoires skin (peau en anglais) , ensembles de scripts gérant l\'aspect visuel de votre site.</p>
<p>
	&nbsp;</p>
");
$fieldc2 = stripslashes("<p>
	<strong>GuppY</strong> works thanks to the last web technologies.<br />
	<br />
	To understand how it works, let\'s go back to the way a traditional web page is created. In a classical web page, you input some text in the middle of which you insert some <strong>HTML</strong> (initials of Hyper Text Markup Language) <strong>tags</strong> that tell to the web browser how to place and format the different components (text, images, links...) in the page.<br />
	You then need to manually link the different pages between them using the <strong>HTML linking tag</strong>. And, each time you want to change the look &amp; feel of your web site, you have to work back on all pages...<br />
	<br />
	This is a heavy and tedious job, and you easily come to spend more time managing the formatting of your pages than their content!<br />
	<br />
	Now exist full web programming languages that allows you to manage the Internet content like any software that runs on your PC. GuppY uses the most used of them being <strong>PHP</strong> (which stands for <strong>Hypertext PreProcessor</strong>).<br />
	<br />
	The principle of GuppY is the following one : the <strong>content</strong> (which is stocked in a little &amp;quot;textfile&amp;quot; database) is separated from the <strong>formating</strong> (which is managed by the PHP scripts that make GuppY).<br />
	<br />
	And, we then get what is called a <strong>CMS</strong> (initials for <strong>Content Management System</strong>). So, at the end, you only have to input the information in the appropriated areas (papers, news, etc.) using an administration interface (which you reach through the Admin icon at the top right corner of the screen) and GuppY takes care of the management and the formating of this information according to the clicks of your web site\'s visitors.<br />
	<br />
	As HTML tagging is allowed, you can use all HTML tags that you want (IMG, A, B, I, U, etc.) in papers, news, links, etc. Check and make sure each time that these tags don\'t prevent your web site to display correctly.<br />
	<br />
	<em>Note : your site will also be beautiful if you don\'t use HTML tags.</em> <img alt=\"\" border=\"0\" src=\"inc/img/smileys/wink.gif\" /><br />
	<br />
	The visitors of your site can by themselves post news, messages in the guestbook or in the forum. The use of HTML tags has been slightly restricted for them, in order to avoid any interference with your site\'s displaying, but a tiny editor helps them in using most used tags.<br />
	<br />
	You have <strong>5 directories</strong> available to put specific objects (through the use of the <strong>Files</strong> icon):<br />
	- <strong><font color=\"#ff0000\">file</font></strong> : to put downloadable files. You will then refer to this file with the use of the following HTML tag: <strong>[A href=\"http://localhost/guppy/file/fichier.ext\"]texte[/A]</strong> (replacing the [ and ] by &lt; and &gt;).<br />
	- <strong><font color=\"#ff0000\">img</font></strong> : to put background images, your logo and all images with which you wish to embellish your site. You will then refer to an image with the following HTML tag : <strong>[IMG src=\"http://localhost/guppy/img/image.ext\"]</strong> (replacing the [ and ] by &lt; and &gt;).<br />
	- <strong><font color=\"#ff0000\">photo</font></strong> : to put the photos of your diaporama. The diaporama automatically detects the images that were put in this directory and will present them for displaying.<br />
	- <strong><font color=\"#ff0000\">pages</font></strong> : to put specific HTML or PHP pages. You will then refer to this file with the use of the following HTML tag : <strong>[A href=\"http://localhost/guppy/pages/page.ext\"]texte[/A]</strong> replacing the [ and ] by &lt; and &gt;).<br />
	- <span style=\"font-weight: bold; color: rgb(255, 0, 0);\">flash</span> : to put videos except flash banners that must stay in img directory.<br />
	<br />
	Another important directory managing the look of your pages is <span style=\"font-weight: bold; color: rgb(255, 0, 0);\">skin.</span> In that directory you put the skins of your site.</p>
<p>
	&nbsp;</p>
");
$fieldd1 = stripslashes("left");
$fieldd2 = stripslashes("gyslogo.gif");
$fieldweb = stripslashes("");
$fieldmail = stripslashes("");
$fieldmod = stripslashes("");
