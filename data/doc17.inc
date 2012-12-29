<?php
$type = 'ar';
$fileid = '17';
$status = 'a';
$creadate = '201210150400';
$moddate = '201210232127';
$author = stripslashes('GuppY Team');
$email = stripslashes('guppy@freeguppy.org');
$fielda1 = stripslashes('<!--01-->GuppY');
$fielda2 = stripslashes('<!--01-->GuppY');
$fieldb1 = stripslashes('<!--09-->Historique des versions');
$fieldb2 = stripslashes('<!--09-->Versions history');
$fieldc1 = stripslashes('<p>
	<span style=\"font-weight: bold;\">v5.0 (et suivantes, toute cette liste de souhaits ne sera peut-être pas réalisée dans cette prochaine version)</span></p>
<p>
	- déjà en cours de développement<br />
	- Objectif général : avec la série 4.x, nous avons atteint un certain palier de maturité fonctionnelle. Nous allons donc nous concentrer sur l\'adéquation du système avec les techniques les plus récentes, pour une rapidité et une facilité d\'utilisation encore accrues. KISS...<br />
	- optimisation de la conformité aux standards du W3C, amélioration de l\'accessibilité<br />
	<strong>- prise en compte des suggestions déposées dans la boîte à idées de FreeGuppY</strong></p>
<p>
	<br />
	<span style=\"font-size:12px;\"><strong>GuppY - Patch de sécurité 4.6.21a</strong></span><br />
	<br />
	<strong>Nous vous proposons le patch 4.6.21a avec des corrections, trois nouveautés, et la correction d\'une faille permettant l\'injection de code, découverte le samedi 20 octobre 2012.<br />
	<br />
	Attention, toutes les versions de GuppY sont concernées, y compris la version 4.6.21.<br />
	<br />
	Vous devez installer IMPERATIVEMENT et IMMEDIATEMENT ce correctif pour la sécurité de votre site.</strong><br />
	<br />
	<strong>Les corrections :</strong><br />
	- correction affichage &#36;web111 dans postguest.php (merci JeanMi, Saxbar)<br />
	- correction MAJ_AGENDA.PHP (merci linuxmr)<br />
	- correction textes anglais de error.php (merci Corrector)<br />
	- correction affichage drapeau dans boxlang.inc (merci Saxbar)<br />
	- correction &#36;pluginlist dans attribdroits.inc (merci linuxmr)<br />
	- correction contrôle saisie email, url (merci jchouix, merci Saxbar)<br />
	- correction fichier langue française fr_upload.inc (merci Corrector)<br />
	- correction fichier langue anglaise en_upload.inc (merci Corrector)<br />
	- correction htmlspecialchars dans fckeditor_php5.inc et fckeditor_php4.inc (merci linuxmr)<br />
	- mise à jour crédits et générique (merci Papinou)<br />
	- modification du fichier .htaccess, seuls les fichiers avec l\'extension inc ou dtb sont bloqués (merci JeanMi)<br />
	- ajout possibilité de s\'abonner à un fil du forum en cas de modification du sujet (merci Saxbar)<br />
	<br />
	<strong>Les nouveautés :</strong><br />
	- nouvelle version de pgeditor.php (merci jchouix)<br />
	- intégration de la version 3.6.4 de CKEditor (merci Papinou)<br />
	- fichier de mise à jour du .htaccess de la racine de GuppY (merci JeanMi, merci Saxbar)<br />
	&nbsp; Pour la mise à jour du .htaccess de la racine, vous devez ajouter MAJ_HTACCESS.PHP à l\'url de votre site puis Entrée pour l\'exécuter après l\'application du patch 4.6.21a.<br />
	<br />
	<br />
	Comme à chaque nouvelle version, n\'oubliez pas de mettre à jour vos plugins, de réinstaller vos forks, de revalider vos pages de configuration.<br />
	Pour passer de la version 4.6.20 à la version 4.6.21a, c\'est ce patch_nc_4621a que vous devez utiliser.<br />
	&nbsp;&nbsp; &nbsp;<br />
	Merci à tous les participants à ce patch.</p>
<p>
	&nbsp;</p>
<p>
	<strong>v4.6.21 - 18 Octobre 2012</strong><br />
	<br />
	Nous vous proposons le patch 4.6.21 avec des corrections et deux nouveautés.<br />
	<br />
	Les corrections :<br />
	- correction affichage &#36;web111 dans postguest.php (merci JeanMi, Saxbar)<br />
	- correction MAJ_AGENDA.PHP (merci linuxmr)<br />
	- correction textes anglais de error.php (merci Corrector)<br />
	- correction affichage drapeau dans boxlang.inc (merci Saxbar)<br />
	- correction &#36;pluginlist dans attribdroits.inc (merci linuxmr)<br />
	- correction fichier langue française fr_upload.inc (merci Corrector)<br />
	- correction fichier langue anglaise en_upload.inc (merci Corrector)<br />
	- correction htmlspecialchars dans fckeditor_php5.inc et fckeditor_php4.inc (merci linuxmr)<br />
	- mise à jour crédits et générique (merci Papinou)<br />
	- modification du fichier .htaccess, seuls les fichiers avec l\'extension inc ou dtb sont bloqués (merci JeanMi)<br />
	- ajout possibilité de s\'abonner à un fil du forum en cas de modification du sujet (merci Saxbar)<br />
	<br />
	Les nouveautés :<br />
	- nouvelle version de pgeditor.php (merci jchouix)<br />
	- intégration de la version 3.6.4 de CKEditor (merci Papinou)<br />
	<br />
	ATTENTION : modification du fichier .htaccess dans le patch.<br />
	&nbsp;&nbsp; &nbsp;<br />
	Merci à tous les participants à ce patch.</p>
<p>
	&nbsp;</p>
<p>
	<span style=\"font-size:12px;\"><strong>v4.6.20 - 24 Mai 2012</strong></span><br />
	<br />
	Le patch_nc_4.6.20 corrige une faille XSS, deux failles permettant l\'injection de code et trois couics signalés par Antoine Cervoise, expert en sécurité informatique.<br />
	<br />
	Tous nos remerciements à Antoine Cervoise, pour son intérêt et pour ses recherches sur la sécurité de GuppY.<br />
	Vous pouvez retrouver ses travaux sur http://www.antoine-cervoise.fr<br />
	En plus de la correction des failles et couics, nous avons ajouté dans ce patch:<br />
	<br />
	- la correction des fichiers pour l\'affichage de toutes les boites (thanks Saxbar)<br />
	- la correction du blocage de l\'inscription des membres par la suppression automatique du fichier .dtb sans pseudo(thanks Saxbar, JeanMi)<br />
	- la prise en charge des langues étrangères par le plugin smileys de FCK Editor, dans le fichier admin/editors/guppy_fckconfig.js (thanks jchouix)<br />
	- la correction de l\'insertion d\'image avec Chrome dans admin/editors/upload/upload.php (thanks jchouix)<br />
	- la correction de admin/inc/attribdroits.inc pour (thanks Saxbar)<br />
	- la correction de dans les fichiers du blog (thanks Saxbar)<br />
	- la correction de dans toutes les skins (thanks Saxbar - Papinou)<br />
	- la correction de l\'affichage des boites sans titre dans toutes les skins (thanks Saxbar)<br />
	- la correction de l\'affichage du bloc citation (thanks Saxbar)<br />
	- La mise à jour de CK Editor version 3.6.3 (thanks Papinou)<br />
	- la correction de CK Editor et de FCK Editor (htlmspecialchars, ) pour l\'édition des textes en admin pour PHP 5.4 et supérieur(thanks Saxbar, jchouix)<br />
	<br />
	Tous nos remerciements à JeanMi pour ses propositions et la correction d\'un couic pour &#36;site[\'TZ\'] .<br />
	&nbsp;&nbsp;&nbsp;<br />
	Attention: Toutes les skins sont concernées par des modifications.<br />
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Pour les skins no_skin, skn1, skn_css, skn_css1 vous devez régénérer le fichier style.css de chaque skin par admin/config look/config style pour appliquer les modifications.<br />
	&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp; Pour les skins island et web20, le fichier style.css modifié pour chacune est dans le patch.</p>
<p>
	&nbsp;</p>
<p>
	<strong><span style=\"font-size:12px;\">V4.6.19</span> - 30 Mars 2012</strong><br />
	<br />
	Ce patch 4.6.19 corrige une faille critique, rendue publique concernant toutes les versions précédentes de GuppY.<br />
	Vous devez installer <b>IMPERATIVEMENT</b> et <b>IMMEDIATEMENT </b>ce correctif pour la sécurité de votre site.<br />
	<br />
	<br />
	Nous y avons ajouté quelques nouveautés ou corrections:<br />
	<br />
	- correction function WriteDoc, thanks jchouix<br />
	- ajout des réseaux sociaux, thanks Saxbar<br />
	- ajout de l\'initialisation de DBLOGL dans install/cleanup.php, thanks Icare<br />
	- remplacement de Close par &#36;admin458 dans admin/inc/archbatch.php, thanks Icare<br />
	- mise à jour pages/db_guppy.txt, thanks Icare, Saxbar<br />
	- correction dans config8 et config9 relative aux curseurs dans le body , thanks Saxbar<br />
	- correction dans config2, suppression de &#36;page[24] pour le curseur dans le body et cursor:hand, thanks Saxbar, tonton_christian<br />
	- ajout d\'une étape supplémentaire dans les scripts de migration du répertoire install,<br />
	&nbsp; pour mettre les datas conformes avec le php5 (basée sur le script de la moulinette à datas), thanks Saxbar, Icare, JeanMi<br />
	- affichage des boites latérales et centrales sans titre si celui ci est vide, thanks Saxbar<br />
	<br />
	Attention:</p>
<p>
	Tous les fichiers skin.inc des skins du pack GuppY sont modifiés y compris celui de la no_skin pour ne pas afficher les titres de boite&nbsp;&nbsp;&nbsp; s\'ils sont vides.<br />
	Si vous avez personnalisé votre ou vos fichiers skin.inc, il est indispensable de faire une sauvegarde pour ne pas les écraser.<br />
	&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;<br />
	Merci à tous les participants à ce patch.</p>
<p>
	&nbsp;</p>
<p>
	<span style=\"font-size:12px;\"><strong>V4.6.18 - 09 Février 2012</strong></span><br />
	<br />
	L\'intégration dans GuppY des groupes privés a induit un certain nombre de dysfonctionnements.<br />
	Quelques failles de sécurité ont encore été détectées dans la version 4.6.17.<br />
	<br />
	Nous proposons donc la version 4.6.18 qui corrige ces failles ainsi que certains couics.<br />
	Cette version intègre également quelques nouveautés.<br />
	L\'installation de cette version est indispensable pour la sécurité des données des groupes privés, pour le contrôle de l\'inscription des membres.<br />
	<br />
	Dans ce patch les modifications suivantes sont prises en compte :</p>
<p>
	<br />
	Sur le tracker:<br />
	<br />
	FS#384 - Ajout des tailles de polices manquantes dans admin/editors/guppy_ckconfig.js (merci François, Saxbar)<br />
	FS#387 - Suppression fichier inc/plugin.inc (merci JeanMi)<br />
	FS#388 - Correction gestion thread réponse du forum (merci linuxmr, Saxbar)<br />
	<br />
	<br />
	Sur le forum :<br />
	<br />
	&nbsp;- Ajout &#36;supervision10 dans admin/inc/config5 pour courriel modérateurs / administrateurs en supervision (merci tonton_christian, Saxbar)<br />
	&nbsp;- Correction compatibilité php 4 admin/inc/config7.inc (merci Laroche)<br />
	&nbsp;- Ajout &#36;supervision10 dans admin/inc/confupdt.inc (merci tonton_christian, Saxbar)<br />
	&nbsp;- Correction fichier admin/inc/logread.inc (merci Papinou)<br />
	&nbsp;- Ajout patch correction download.php et dwnld_pr.php (merci&nbsp; Laroche)<br />
	&nbsp;- Ajout choix largeur de CK Editor en config services (merci Saxbar)<br />
	&nbsp;- Modification fichier inc/includes.inc pour largeur éditeur et changement de version (merci Saxbar)<br />
	&nbsp;- Correction &#36;typ illegal value pour blog, nouvelles, livre d\'or, et &#36;screen_choice (merci Saxbar)<br />
	<br />
	<br />
	Les autres corrections, améliorations:<br />
	<br />
	- Suppression short tag ligne 236 de admin/inc/members.inc (merci Laroche)<br />
	- Modification fichiers langue français et anglais (merci Saxbar, Papinou)<br />
	- Ajout demande de confirmation pour désinscription de la newsletter.(merci Saxbar)<br />
	- Correction &#36;uwebsite, suppression affichage message de bienvenue en cas de modification, correction renvoi pour admin (merci Laroche, Saxbar)<br />
	- Contrôle groupes privés pour archivage forum (merci Saxbar)<br />
	- Correction ajustement iframe calendrier (merci Saxbar)<br />
	- Correction lien validation XHTML (merci Papinou)<br />
	- Modification affichage copyright pages, maintenance et mobile (merci Saxbar)<br />
	- Modification contrôle enregistrement membres (merci Saxbar)<br />
	- Suppression champs anciens en cas de modification du profil (merci JeanMi)<br />
	- Correction affichage icônes plugins pour attribution droits (merci Saxbar)<br />
	- Affichage des services actifs pour attribution droits collaborateurs (merci Saxbar)<br />
	- Ajout time zone (merci Saxbar)<br />
	- Initialisation du time zone par défaut à \"Europe/Paris\" (merci JeanMi)<br />
	- Correction fonction IsPrivateForumCat() (merci Saxbar)<br />
	- Correction &#36;obgo (merci Saxbar)<br />
	- Correction gestion forum privé pour mobile (merci Saxbar)<br />
	<br />
	<br />
	Tous nos remerciements à tous les participants à ce patch.</p>
<p>
	&nbsp;</p>
<p>
	<strong>V4.6.17 - 21 Octobre 2011</strong></p>
<p>
	Ce patch 4.6.17 regroupe des corrections, des améliorations et des nouveautés.</p>
<p>
	Les nouveautés:</p>
<p>
	- Insertion de CK Editor 3.6.2 comme éditeur WYSIWYG dans GuppY (thanks jchouix)<br />
	- Adaptation de la partie mobile aux groupes privés (thanks Saxbar)<br />
	- Ajout drapeaux de tous les pays dans inc/lang (thanks François)<br />
	- Ajout de plusieurs membres dans un groupe privé en une seule fois (thanks Saxbar)<br />
	- création du répertoire inc/inchead pour permettre un include automatique de scripts php ou html dans le haut de la page (thanks Saxbar - Laroche)<br />
	- création du répertoire inc/incfoot pour permettre un include automatique de scripts php ou html dans le bas de la page (thanks Saxbar - Laroche)<br />
	- création d\'un hyperlien pour la FAQ, les liens et les téléchargements , ajout de l\'imagette hyperlink dans inc/img/general (thanks Laroche)<br />
	<br />
	Les corrections:</p>
<p>
	- Correction caractères pour affichage drapeaux pays dans log (thanks François)<br />
	- Modification affichage pour config look et config style (thanks Saxbar)<br />
	- Correction affichage iframe calendrier (thanks Laroche)<br />
	- Correction affichage lire la suite pour le blog et les nouvelles en page d\'accueil (thanks Laroche)<br />
	- Optimisation affichage boite webmestre (thanks Saxbar)<br />
	- Correction construction lien après recherche pour agenda et forum dans search.php(thanks Saxbar)<br />
	- Correction coquille blog.inc, suppression &amp;nbsp ligne 315 (thanks JeanMi)<br />
	- Mise à jour et ajout dans les fichiers langues inc/lang/en-admin.inc, en-web.inc, fr-admin.inc, fr-web.inc<br />
	- Correction de printfaq.php limité à la FAQ (thanks Laroche)<br />
	- Optimisation affichage header skin Island (thanks Papinou)<br />
	- Modification affichage des pages pour impression (thanks Saxbar)<br />
	<br />
	La sécurisation des groupes privés:</p>
<p>
	- Correction des téléchargements privés (thanks Laroche)<br />
	- Correction de la recherche respectant les données des groupes privés (thanks Laroche)<br />
	- Correction du forum, des sujets privés, de l\'affichage de forum en direct (thanks Laroche)<br />
	- Possibilité d\'avoir un forum sans catégories si non utilisation des groupes privés (thanks Laroche)<br />
	- Modification de la création d\'une section privée dans le forum par simple coche d\'une case et création du groupe privé PR correspondant.(thanks Laroche)</p>
<p>
	&nbsp;</p>
<p>
	Nous vous conseillons l\'installation de cette version 4.6.17 pour la sécurisation complète de&nbsp; vos groupes privés, la suppression du dossier file/private et l\'utilisation d\'un sous-répertoire personnel dans file pour vos téléchargements privés.<br />
	La lecture du fichier lisezmoi.html et du tutoriel sur l\'utilisation des groupes privés est indispensable.</p>
<p>
	&nbsp;</p>
<p>
	Attention: Comme à chaque nouvelle version, n\'oubliez pas de mettre à jour vos plugins, de réinstaller vos forks, de revalider vos pages de configuration.</p>
<p>
	&nbsp;</p>
<p>
	<strong>v4.6.16 - 02 Septembre 2011</strong></p>
<p>
	L\'intégration dans GuppY des groupes privés a induit un certain nombre de dysfonctionnements<br />
	et surtout des failles de sécurité qui n\'ont pas été détectées lors des bêta tests.</p>
<p>
	Nous proposons donc la version 4.6.16 qui corrige ces failles ainsi que certains couics.<br />
	L\'installation de cette version est indispensable pour la sécurité des données des groupes privés.</p>
<p>
	Sur le bugtracker :<br />
	#366 - correction failles pour les forums privés et les téléchargements(thanks jchouix, Laroche, Pascal31)<br />
	#367 - correction affichage forum en direct(thanks jchouix, Laroche, Pascal31)<br />
	#365 - correction incohérence création data/temp (thanks Hpsam)<br />
	#363 - correction affichage booster dans counter.inc (thanks Papinou)<br />
	#372 - correction coquille dans forum.php (thanks JeanMi)<br />
	#374 - optimisation prise encompte des langues dans fck editor (thanks jchouix)<br />
	#375 - modification gestion enregistrement des membres (thanks Laroche)</p>
<p>
	Sur le forum:<br />
	- Correction encadrement icône dans news.inc (thanks Papinou)</p>
<p>
	# Correction entête fichier admin.inc<br />
	# Correction fichiers langues fr et en<br />
	# Correction affichage dernières nouvelles en page d\'accueil (thanks Laroche)<br />
	# Correction affichage et traitement des téléchargements privés,<br />
	&nbsp; création d\'un sous répertoire file/private avec un .htaccess pour sécuriser les téléchargements privés qui devront être mis dans ce répertoire private (thanks Laroche)<br />
	# Modification fichiers de configuration pour contrôle de la création des catégories privées du forum(thanks Laroche)<br />
	# Optimisation affichage block boite citation dans toutes les skins du pack (thanks Papinou)<br />
	attention : Si vous avez personnalisé une skin du pack GuppY sans en changer le nom, vous devez impérativement la renommer avant l\'installation du patch sous peine de perdre vos modifications.<br />
	Les fichiers style.css et skin.inc de chaque skin sont modifiés.</p>
<p>
	Tous nos remerciements à cece45 pour nous avoir signalé la faille des forums privés.<br />
	Il nous reste à adapter la partie mobile.</p>
<p>
	attention : la non prise en compte de la partie mobile oblige impérativement à supprimer celle-ci lorsque les groupes privés sont utilisés.<br />
	Avec ces corrections, si vous ne configurez pas et n\'utilisez pas les groupes privés, le fonctionnement de GuppY est inchangé.</p>
<p>
	&nbsp;</p>
<p>
	<strong>v4.6.15 - 30 juin 2011</strong></p>
<p>
	Sur le bugtracker:<br />
	- #327 - suppression error 401 htaccess<br />
	- #340 - concerne l\'ajout de balise HR - merci jchouix<br />
	- #357 - correction nombre de jours du mois précédent - merci jchouix<br />
	- #358 - correction prise en compte adresse web sous domaine.domaine - merci jchouix<br />
	- #359 - correction erreur pour validation - merci jchouix<br />
	- #360 - suppression accès code source PgEditor - merci jchouix<br />
	- #361 - amélioration affichage partiel nouvelle en page d\'accueil et permalink - merci Laroche<br />
	- #362 - amélioration affichage partiel du blog an page d\'accueil - merci Laroche</p>
<p>
	- Forum anglais: correction coquille dans inc/blogcalendar.inc<br />
	- Boite à idées n°234: correction affichage date journée pour évènement (autre que j/m/a) - merci Quefer</p>
<p>
	Une nouveauté :<br />
	- La gestion des groupes privés d\'utilisateurs - merci Icare - merci JeanMi (voir le tutoriel spécialisé)</p>
<p>
	&nbsp;</p>
<p>
	<strong>v4.6.14 - 14 Février 2011</strong></p>
<p>
	Copyright - Version<br />
	-1- MAJ copyright année inc/bpage.inc<br />
	-2- MAJ copyright année inc/hpage.inc<br />
	-3- MAJ version inc/includes.inc</p>
<p>
	Sur le bugtracker:<br />
	-1- FS#348 - Icônes de l\'éditeur absentes de tinymsg<br />
	-2- FS#347 - Position de la bulle liée à la classe pop<br />
	-3- FS#354 - Rapport de couic graphique et correction.<br />
	-4- FS#340 - Boîte à idées : Concerne l\'ajout de balise HR<br />
	-5- FS#338 - Sujets bloqués au top ne restent pas au top<br />
	-6- FS#329 - Plugin Vitesse de connexion<br />
	-7- FS#341 - En français, il y a deux &#36;web434 et pas de &#36;web435<br />
	-8- FS#337 - Echec du contrôle de la dernière version chez Free</p>
<p>
	Boites à idées:<br />
	-1- Réaction n°217 - Correction admin/inc/config7.inc<br />
	-2- Réaction n°206 - Correction fichier inc/log.inc<br />
	-3- Réaction n°202 - Modification admin/inc/admin.inc - Ajout titre article dans Admin - Réaction aux articles</p>
<p>
	PgEditor :<br />
	- Ajout MAJ PgEditor 2.5.1 - Correction couic Opéra<br />
	- FS#355 Correction d\'une faille de sécurité signalé par Antoine CERVOISE (http://www.antoine-cervoise.fr/)<br />
	Les correctifs et modifications étaient en attente sur le tracker.<br />
	La nouvelle version de PgEditor et le correctif de la faille de sécurité sont de djchouix.</p>
<p>
	<strong>v4.6.13 - 22 Mai 2010</strong></p>
<p>
	#286 - initialisation du timezone à \'Europe/Paris\' si la version PHP &gt;=5.1<br />
	#316 - fichier inc/log.inc oublié en 4.6.12<br />
	#323 - correction de l\'affichage dans admin/inc/members.inc<br />
	#324 - correction d\'une coquille dans admin/inc/poll.inc, merci Laroche<br />
	#325 - correction des fichiers d\'upload (suite de #320)<br />
	#328 - correction de l\'affichage dans inc/bloglist.inc si aucun billet</p>
<p>
	&nbsp;</p>
<p>
	<strong>v4.6.12 - 01/05/2010</strong></p>
<p>
	#314 - dans admin/inc/admin.inc, correction d\'une balise &lt;/table sans &gt;<br />
	#315 - dans inc/pgeditor/style/pgeditor.css, remplacement d\'une valeur \"undeline\" par \"underline\"<br />
	#316 - NEW : Ajout des statistiques du mois précédent, visible au bout d\'un mois<br />
	#317 - dans admin/inc/members.inc, correction du chemin des icônes du miniéditeur<br />
	#318 - ajout des champs auteur et email dans la page d\'administration des articles<br />
	#319 - suppression du fichier admin/adminstrateur.php (uniquement dans le pack complet)<br />
	#320 - lors d\'upload, la création de répertoire est interdite si le nom du répertoire contient le mot script<br />
	#321 - correction de la page d\'administration du sondage, qui perdait la valeur de la skin sélectionnée<br />
	#322 - correction dans inc/topforum.inc pour validation W3C</p>
<p>
	<br />
	<strong>v4.6.11 - 11 Décembre 2009</strong><br />
	#291 - correction coquille de preg_match() dans admin/editors/minieditortextarea/popup/image.php<br />
	#293 - correction coquille dans inc/blogcalendar.inc<br />
	#294 - sécurisation de l\'affichage du document dans agenda.php par hpsam<br />
	#295 - correction pluginlist dans admin/inc/infos.inc<br />
	#297 - correction functions.php: génération du lien mailto par la fonction ForceToAbsolute_callback()<br />
	#298 - reprise lang/fr-admin.inc du pack 4.6.10 qui était erroné dans les patches<br />
	#299 - correction abrégé des évènements du jour dans inc/calendar.php, merci Linuxmr.<br />
	#300 - correction erreur css et titre de Rubrique en double dans blogrss.php<br />
	#301 - optimisation des fonctions selectDBFieldsBy...<br />
	#302 - suppression du lien vide&nbsp; sur les bannières si pas d\'URL définie<br />
	#303 - optimisation affichage des boîtes du blog, suppression des hr du blog de news.inc et de boxreact.inc<br />
	#304 - remplacement de &#36;admin53 par &#36;admin173 dans admin.inc modification message du forum<br />
	#305 - correction prise en compte extensions en majuscules dans upload.php<br />
	#306 - correction test dans inc/lang/fr-special.inc et en-special.inc<br />
	#307 - fiabilisation affichage du forum (suppression déformations et optimisation des classes div.code de pgeditor) et remplacement de width par style=width dans les cellules de tableaux de divers scripts<br />
	#310 - fiabilisation saisie URL avec bouton \"Parcourir le serveur\" dans admin.inc, merci Linuxmr<br />
	#311 - correction coquille prag_match dans admin/editors/minieditortextarea/popup/entities.php<br />
	- ajout bouton abandon de transaction dans les scripts install, cleanup et delete.php<br />
	#312 - correction affichage licence dans download.php<br />
	#313 - ajout dans administrateur.php d\'un message périodique incitant à supprimer le dossier install en ligne<br />
	- modification des dates du copyright</p>
<p>
	<br />
	<strong>v4.6.10 - 7 Septembre 2009</strong><br />
	#253 - correction des adresses relatives des images (img/, inc/img/ et photo/) en adresses absolues dans la lettre d\'informations et dans les flux RSS<br />
	#253 - correction des adresses relatives des liens en adresses absolues dans la lettre d\'informations, les flux RSS et les emails de supervision<br />
	#253 - correction des ancres dans la lettre d\'informations, qui restent relatives<br />
	#253 - correction de la fonction pubDate<br />
	#253 - correction de la fonction UpdateDBBlog<br />
	#256 - correction de la gestion en zone membres dans postguest.php<br />
	#259 - correction de error.php suite au patch 4.6.9<br />
	#260 - rajout du fichier install/migrate24.php<br />
	#262 - correction des liens lors du changement de langue<br />
	#263 - ajout d\'une fonction iconv lorsque PHP &lt; 5, merci linuxmr<br />
	#266 - correction de l\'ordre des tests dans le parcours d\'un répertoire avec la fonction is_dir<br />
	#267 - correction de la prise en compte de la langue dans FCKeditor<br />
	#268 - NOUVEAU : la fonction Bannières devient bilingue<br />
	#269 - correction de la gestion des droits sur les plugins pour les rédacteurs<br />
	#271 - correction pour l\'utilisation des quotes dans les categories<br />
	#272 - remplacement des fonctions de la famille EREG dépréciées à partir de PHP 5.3<br />
	#273 - suppression du popup vide dans le blog, lorsque l\'option \"Masquer l\'adresse émail\" est activée<br />
	#274 - correction de nombreux fichiers pour une meilleure conformité aux recommandations du W3C<br />
	#275 - ajout des boîtes libres dans la page d\'accueil<br />
	#276 - intégration de la version 2.6.4 de FCKeditor<br />
	#278 - ajout d\'images pour les types de fichiers : pdf, doc, xls, ppt et OpenOffice<br />
	#279 - amélioration des tests sur les URLS dans Config.Générale<br />
	#280 - amélioration de la page agenda en cas de paramétres erronés<br />
	#281 - impression de la partie centrale des pages avec une feuille de style dédiée<br />
	#282 - amélioration de la duplication avec création du nouvel élément après validation et non avant<br />
	#283 - amélioration du test sur le REFERER dans postguest.php<br />
	#285 - correction de la gestion membre du blog en page d\'accueil<br />
	#287 - correction FCKeditor non vide<br />
	#288 - correction code des boîtes du blog<br />
	#289 - correction css sujet dans thread.php, merci Kamila<br />
	#290 - suppression colonne 1 (ou 3) vide sur affichage en 2 colonnes</p>
<p>
	<br />
	<b>v4.6.9 - 25 Décembre 2008</b><br />
	- correction du test de sécurité sur admin/inc/access.inc #232<br />
	- correction du test affichant l\'icône RSS en administration #231<br />
	- déplacement de la fonction ShowBlock vers inc/functions.php #221<br />
	- correction de la fonction ShowBlock<br />
	- déplacement de la fonction SearchOption vers inc/functions.php #219<br />
	- correction de la fonction TestEmail dans admin/inc/nwlist.inc #226<br />
	- correction des incohérences dans les statistiques #218<br />
	- ajout / correction des statistiques pour les pages Blog et Admin #216<br />
	- amélioration du contrôle de la variable &#36;num dans postguest.php #203<br />
	- correction de l\'email utilisé dans les RSS #225<br />
	- correction du mode pleine page du blog #228<br />
	- correction du mode pleine page du forum #234<br />
	- amélioration du forum en cas de sujet inexistant ou archivés #237<br />
	- ajout de la limitation du calendrier du blog depuis le premier billet jusqu\'à maintenant #221<br />
	- ajout de la gestion des pages inexistantes du blog #221<br />
	- ajout du controle des fonctions \"Recommander\" et \"Mail PHP\" #20<br />
	- correction de l\'activation des items du menu principal #224<br />
	- correction de l\'affichage de certains flux RSS #229<br />
	- ajout du champ pubDate dans les flux RSS #240<br />
	- ajout d\'un test de sécurité sur les paramètres numériques<br />
	- ajout d\'un champ \"URL du site\" dans l\'administration du forum #241<br />
	- nombreuses petites corrections améliorant la conformité aux standards du W3C<br />
	- amélioration de la migration<br />
	- optimisation du code de test des jours fériés<br />
	- amélioration de la fonction \"Ajouter aux favoris\" (boîte à idées #156)<br />
	- conservation de la saisie en cas de pseudo déjà utilisé (boîte à idée #160)</p>
<p>
	<br />
	<b>v4.6.8 - 10 Mai 2008</b><br />
	- rectification liste des plugins dans admin/adminredac.php et admin/inc/plugins.inc<br />
	- rectification du select dans inc/boxsearch.inc et du moteur dans search.php<br />
	- remise date de la nouvelle (disparue!) dans inc/news.inc<br />
	- modification du lien de la popup dwnld dans download.php<br />
	- ajout du n° de sujet, retour vers forum si pas de paramètres dans thread.php<br />
	- correction du test HTTP_REFERER, et des mails de supervision dans postguest.php/mod_thread.inc<br />
	- correction sélection des commentaires dans inc/bloglist.inc<br />
	- suppression des paramètres du lien liste globale dans blog.php<br />
	- correction coquilles &#36;msg2 dans admin/inc/members.inc<br />
	- rectification affichage de fortopic.php, inc/topblog.inc et topforum.inc<br />
	- correction config des entités html de FCKeditor<br />
	- remplacement de include par include_once pour funcrss dans admin.inc et maintain.inc<br />
	- modification de config2/config8.inc (génération automatique de la css, si permis)<br />
	- ajout de création/suppression de sous-répertoire dans upload.inc<br />
	- nouvelle version de pgeditor</p>
<p>
	<br />
	<b>v4.6.7 - 23 Avril 2008</b><br />
	- suppression des icônes inutilisées dans administration<br />
	- correction de tags erronés dans generic.htm<br />
	- correction anomalie enregistrement de tinymsg<br />
	- correction du module de recherche<br />
	- correction tags br dans postguest</p>
<p>
	<br />
	<b>v4.6.6 - 14 Avril 2008</b><br />
	- Correction prise en compte de &amp;serviz31 dans admin/inc/config5.inc<br />
	- correction erreurs de syntaxe dans config6 et config7.inc<br />
	- icônes de validation W3c rendues amovibles dans config1.inc<br />
	- ajout de la sélection des catégories dans admin.inc<br />
	- correction des fonctions putBR() et putHR() pour miniéditor<br />
	- Correction test langue de poll.php<br />
	- correction emplacement include hpage.inc dans pages/sample.php<br />
	- download possible si javascript inactif et correction caractéristiques du fichier dans download.php<br />
	- suppression clear:both et &lt;/p&gt; inutiles&nbsp; dans links news et faq<br />
	- correction curseur dans photorama.php<br />
	- correction double quote dans le tag body de photoview.php<br />
	- modification de updateDBdtb (nouveau champ pour TYP_BLOG) dans functions.inc<br />
	- création de MAJ_BLOG.PHP pour prendre en compte le nouveau champ date de DBBLOG<br />
	- correction sélection des billets dans blogcalendar.inc<br />
	- affichage page en erreur si le billet n\'est pas actif dans blog.php<br />
	- correction largeur et affichage titres dans blog.php, blog, blogcat et bloglist.inc<br />
	- ajout de title dans liens des menus articles<br />
	- correction couic compteur du forum et test sujet du thread dans postguest.php<br />
	- rectification affichage nouveau et important dans forum et thread.php<br />
	- correction &amp;fieldmod vide, valorisation variables pour supervision dans inc/mod_thread.inc<br />
	- report de l\'ajustement onload du calendrier dans calendar.php pour compatibilité W3C<br />
	- ajustement de la taille de search dans topblog et topforum.inc<br />
	- ajout de urlencode lors de l\'utilisation de toutes les fonctions WriteMailto()<br />
	- modification de hpage.js pour correction affichage nouvelles et dernières nouvelles<br />
	- optimisation de hpage et bpage.inc pour étendre les possibilités de customisation<br />
	- correction du nombre de jours du mois dans statcalc.inc<br />
	- correction de boxsearch.inc pour la recherche des photos<br />
	- correction test &amp;err dans error.php<br />
	- ajout header(\"HTTP/1.0 404 Not found\") en cas de page non trouvé, merci eDada<br />
	- intégration de la version 2.5.1 de FCKeditor</p>
<p>
	<br />
	<b>v4.6.5 - 5 Décembre 2007</b><br />
	- Inscription à la newsletter par message de confirmation<br />
	- Ajout des enrichissements dans le mini-message aux membres<br />
	- Correction liste des plugins dans admin/plugins<br />
	- Correction champ &amp;fieldd1 et &amp;admin915 erronés dans admin.inc, merci JeanMi<br />
	- Amélioration saisie URL dans config1<br />
	- Modification texte[4] dans config2<br />
	- Correction &amp;&amp;serviz[36], &amp;serviz[31] mis à espace dans config5.inc<br />
	- suppression d\'un &gt; inutile dans config6.inc<br />
	- Correction attribut border dans config8.inc<br />
	- Remplacement de button par input class=bouton dans nwllist.inc<br />
	- Correction sélection Collaborateur dans attribdroits.inc<br />
	- Correction tests de langue dans inc/boxpoll.inc<br />
	- Correction item titre de la boîte spécial<br />
	- Ajout du blog dans inc/statcalc.inc<br />
	- Suppression drapeau inutile dans mobile<br />
	- Optimisation affichage des dernières nouvelles (pas d\'affichage boîte si pas de nouvelle)<br />
	- Correction erreurs d\'affichage, suppression affichage nb de lectures si compteur inactif dans forum.php<br />
	- Correction table de headTop dans hpage.inc (remplacée par des divs), merci JeanMi<br />
	- Correction de variables en dur dans download.php, boxsearch.inc, attribdroits.inc et upload.inc<br />
	- Ajout de stop sur variable illégale dans printfaq.php<br />
	- Ajustement auto de la hauteur du calendrier<br />
	- Correction define CHEMIN et sécurité d\'accès dans tinymsg.php<br />
	- correction display image du billet dans blog.php<br />
	- ajout d\'effacement global dans admin/inc/maintain.inc<br />
	- ajout de la restriction de forum en direct aux seuls membres</p>
<p>
	<br />
	<b>v4.6.4 - 04 Novembre 2007</b><br />
	- correction vulnérabilité de error.php découverte par irk4z<br />
	- correction vulnérabilité de includes.inc découverte par irk4z</p>
<p>
	<br />
	<b>v4.6.3 - 30 Août 2007</b><br />
	- La nouveauté: ajout de la duplication d\'article, blog, news, etc... dans admin.inc, merci JeanMi<br />
	- ajout de confirmation par l\'admin pour les réactions aux articles et les commentaires blog<br />
	- activation de la newsletter dans Config services avec test serveur de mail facultatif<br />
	- possibilité de mettre un plugin (ou la boîte spécial) en page d\'accueil, merci JeanMi<br />
	- suppression image langue courante dans le menu de navigation<br />
	- correction des liens des mails de supervision dans postguest<br />
	- amélioration du test mail dans newsletter.php et admin/inc/nwllist.inc<br />
	- correction du copyright dans bpage.inc<br />
	- correction download et admin download pour les fichiers multilangue<br />
	- remplacement de ouvrir et fermer par des strings langue dans les menus (articles, blog, faq, liens et download)<br />
	- nouveaux strings dans les fichiers de langue</p>
<p>
	<br />
	<b>v4.6.2 - 1er Août 2007</b><br />
	- correction lien css-validator dans bpage.inc<br />
	- correction screen_choice dans hpage.inc<br />
	- correction mise en forme du blog et bas de page manquant dans blogrss.php<br />
	- modification taille du select de admin/inc/config6 et css rubr de config8.inc<br />
	- nouvelle procédure de test email dans newsletter.php<br />
	- test email rectifié dans la liste des abonnés à la newsletter<br />
	- correction insertion css IE de pgeditor<br />
	- correction item DBNEWS dans functions.php<br />
	- correction balise p dans agenda.php et boxreact.inc<br />
	- correction short tags php oubliés</p>
<p>
	<br />
	<b>v4.6.1 - 3 Juillet 2007</b><br />
	- correction lien dernier message dans forum et fortopic.php<br />
	- corrections javascript dans postguest.php<br />
	- modification config8.inc suite pb affichage faq liens et Téléchargement<br />
	- correction padding de la classe rubr pour style.css de chaque skin<br />
	- correction couic éditeur IE<br />
	- modification test anti-usurpation de cookie dans includes.inc<br />
	- correction mauvaise prise en compte des modifications de thread dans admin.inc<br />
	- correction prise en compte des caractères accentués dans FCKeditor<br />
	- modification PathAbs() dans functions.php<br />
	- correction mails de supervision dans postguest.php<br />
	- ajout de strip_tags pour tous les noms de scripts appelés par le menu icônes<br />
	- ajout de recherche dans blog et commentaires dans search.php<br />
	- optimisation du module de vérification e-mail dans newsletter.php<br />
	- fiabilisation du contrôle d\'intégrité<br />
	- rectification lien articles erroné dans funcrss.php<br />
	- incrémentation automatique de boîtes supplémentaires dans config boîtes, merci JeanMi.<br />
	- correction de divers tags non valides xhtml</p>
<p>
	<br />
	<b>v4.6.0 - 4 Juin 2007</b><br />
	- La NOUVEAUTE : Guppy a dorénavant son blog !!!<br />
	- forum new-look avec sa propre page d\'administration et sa charte<br />
	- édition des posts par leurs auteurs respectifs et les admin/modérateurs<br />
	- refonte des pages d\'administration<br />
	- accès à l\'administration rapide pour les collaborateurs<br />
	- ajout droits d\'administration des plugins pour les collaborateurs<br />
	- affichage optionnel de la charte du forum dans le module fortopic<br />
	- mise en conformité avec le standard XHTML<br />
	- remplacement de l\'éditeur wysiwyg TypeTool par FCKeditor compatible xhtml<br />
	- remplacement du mini-éditeur d\'admin<br />
	- remplacement de l\'éditeur wysiwyg de postguest<br />
	- évolution des modules photo et photorama avec possibilité de sous-dossiers<br />
	- correction d\'un couic d\'affichage des modules download, faq et links<br />
	- correction vulnérabilité de archbatch.php et nwlmail.php<br />
	- affichage optionnel de la licence lors du téléchargement de logiciels protégés<br />
	- amélioration de l\'accessibilité et du fonctionnement sans javascript<br />
	- choix de la largeur de la page affichée<br />
	- choix d\'affichage du forum et du blog en pleine page<br />
	- correction du calendrier et de l\'agenda<br />
	- amélioration de la disposition des boites ( en haut, en bas, au centre, sur les cotés )<br />
	- gestion des skins individualisée et couplée à la disposition des boites<br />
	- gestion intégrée de la feuille de style css (génération, modification)<br />
	- ajout de déconnexion/reconnexion avec sauvegarde temporaire de votre cookie<br />
	- ajout du contact webmaster via la plupart des messageries instantanées<br />
	- amélioré choix du message préféré du livre d\'or en page d\'accueil<br />
	- amélioration du traitement des caractères accentués dans le pseudo<br />
	- remplacement des short tags php pour compatibilité php5</p>
<p>
	<br />
	<b>v4.5.19 - 10 Novembre 2007</b><br />
	- corrections dans error.php de failles de sécurité découvertes par rgod<br />
	<br />
	<b>v4.5.18 - 1 Avril 2007</b><br />
	- Correction FAQ restriction membre<br />
	- Correction des liens mailto dans les mails Recommander et Contacter Webmaster<br />
	- Correction couic d\'affichage du Sondage sous IE en cas de second vote<br />
	- Correction d\'un lien dans la version mobile<br />
	- Passage en lecture seul du pseudo lors de l\'édition de son profil pour éviter la création d\'un nouveau membre.<br />
	- Suppression de l\'affichage parasite au dessus de la boite centrale dans l\'admin des compteurs<br />
	- correction function PathToImage<br />
	- Correction du calendrier qui affichait le 30 ou 31 février<br />
	<br />
	<b>v4.5.17 - 31 Janvier 2007</b><br />
	- correction vulnérabilité de error.php découverte par rgod<br />
	- correction boxcal.inc<br />
	<br />
	<b>v4.5.16 - 28 Janvier 2007</b><br />
	- correction function PathToImage<br />
	- correction news.inc<br />
	- correction download.php - faq.php - links.php<br />
	- création fonction IncrNextID() pour éviter d\'écraser un ancien document lors de la création d\'un nouveau document<br />
	<br />
	<b>v4.5.15 - 27 Janvier 2007</b><br />
	- correction dans le cas d\'un élément seul appelé par son id ou le titre de la catégorie est le titre de la dernière catégorie de la boite article de gauche.<br />
	- correction de l\'inversion date Création / Modification lors de l\'affichage des FAQ.<br />
	- correction du couic d\'affichage des nouvelles en langue secondaire.<br />
	- correction photorama pour problème de galeries imbriquées<br />
	- correction boite calendrier visible si agenda désactivé<br />
	- correction postguest pour éviter l\'accès à des services désactivés<br />
	- correction dwnld.php (&amp;serviz[10] au lieu de &amp;serviz[35])<br />
	- amelioration de liste des abonnés à la lettre d\'information<br />
	&nbsp; - présentation des abonnés les plus récents en début de liste<br />
	&nbsp; - possibilité de suppressions multiples en une seule action<br />
	&nbsp; - présentation de la liste par page d\'un maximum de 25 abonnés<br />
	- correction de tinymsg.php (suppression du maxlength=\"10\")<br />
	- amelioration de la fonction PathToImage pour corriger aussi les urls des liens<br />
	<br />
	<b>v4.5.14 - 19 Mai 2006</b><br />
	- rectification du patch 4.5.13<br />
	<br />
	<b>v4.5.13 - 19 Mai 2006</b><br />
	- correction des fichiers download.php, faq.php, links.php et news.inc<br />
	- correction du test interdisant l\'emploi du pseudo \"Votre Nom\" dans newsletter.php<br />
	- remplacement de getenv(\"HTTP_USER_AGENT\") par &amp;_SERVER[\"HTTP_USER_AGENT\"] dans includes.inc<br />
	- suppression de l\'affichage des réactions pour les non-membres dans articles.php<br />
	- correction de l\'affichage dans photorama.php<br />
	- correction de l\'activation des news RSS dans hpage.inc<br />
	- correction de l\'agenda pour la seconde langue<br />
	- amélioration du moteur de recherche pour respecter les restrictions \"membres\"<br />
	<br />
	<b>v4.5.12 - 09 Mars 2006</b><br />
	- correction vulnérabilité de dwnld.php découverte par kapda.ir<br />
	<br />
	<b>v4.5.11 - 25 Décembre 2005</b><br />
	- correction seconde langue dans search.php<br />
	- correction de l\'initialisation des paramètres de l\'anti-spam<br />
	- correction de la couleur figée à blanc pour l\'icone \"moins\" des téléchargements<br />
	- correction d\'un test dans l\'admin de l\'agenda<br />
	- uniformisation des pages téléchargements, liens et faq<br />
	- remplissage des cellules du calendrier au delà du dernier jour du mois<br />
	- ajout d\'un avertissement pour l\'administrateur quand son site est en travaux<br />
	- ajout de contrôles en cas de fichiers docXXX.inc absent, vide ou corrompu<br />
	Boîte à idées n°63<br />
	- interdition de l\'indexation des pages error et newsrss par les robots<br />
	Boîte à idées n°48<br />
	- suppression du soulignement de la page courante dans la barre de navigation<br />
	Boîte à idées n°64<br />
	- ajout du texte de la réponse à un sujet du forum dans le mail de suivi d\'un sujet<br />
	Boîte à idées n°46<br />
	- correction du retour systématiquement en langue principale lors de l\'inscription d\'un visiteur<br />
	Boîte à idées n°70<br />
	- ajout d\'un affichage dépliée lorsque l\'on accède à une seule page de téléchargements (par &amp;pg=99)<br />
	- ajout d\'un affichage dépliée lorsque l\'on accède à une seule page de liens (par &amp;pg=99)<br />
	- ajout d\'un affichage dépliée lorsque l\'on accède à une seule page de faq (par &amp;pg=99)<br />
	Boîte à idées n°28<br />
	- ajout du choix de l\'état (actif ou non) des éléments créés en admin.<br />
	<br />
	<b>v4.5.10 - 29 Novembre 2005</b><br />
	- correction de 5 failles de sécurité découverte par rgod<br />
	<br />
	<b>v4.5.9 - 27 Novembre 2005</b><br />
	- correction du sélecteur de couleurs<br />
	- correction des menus articles sous FireFox<br />
	- corrections mineures dans plusieurs fichiers<br />
	- amélioration de l\'archivage du forum et du contrôle d\'intégrité<br />
	- amélioration de postguest.php<br />
	<br />
	<b>v4.5.8 - 16 Octobre 2005</b><br />
	- correction de postguest (ajout des breaks manquants)<br />
	<br />
	<b>v4.5.7 - 8 Octobre 2005</b><br />
	- correction du sondage<br />
	- amélioration du mécanisme anti-spam<br />
	- ajout du paramétrage du mécanisme anti-spam<br />
	- correction d\'une balise input non fermée dans admin.php<br />
	- correction de la balise head mal placé dans calendar.php<br />
	<br />
	<b>v4.5.6a - 28 Septembre 2005</b><br />
	- correction de printfaq.php<br />
	<br />
	<b>v4.5.6 - 27 Septembre 2005</b><br />
	- correction d\'une vulnérabilité \"file transversal flaw\" dans printfaq.php<br />
	- correction du nombre d\'erreurs pendant le contrôle d\'intégrité en batch<br />
	- correction de deux fautes d\'orthographe dans fr-admin.inc<br />
	- amélioration de l\'éditeur (meta et script) et de la prévisualisation (flash)<br />
	<br />
	<b>v4.5.5 - 10 Septembre 2005</b><br />
	- correction des pages d\'administration des compteurs<br />
	- correction de la lettre d\'informations (ajout du charset)<br />
	<br />
	<b>v4.5.4 - 6 Septembre 2005</b><br />
	- correction de trois failles de sécurité (error.php et printfaq.php) Merci Romano<br />
	- correction définitive de l\'agenda (voir lisezmoi_agenda.txt)<br />
	- correction définitive de l\'éditeur<br />
	<br />
	<b>v4.5.3a - 30 August 2005</b><br />
	- correction de l\'agenda dans admin/inc/admin.inc<br />
	<br />
	<b>v4.5.3 - 27 Aout 2005</b><br />
	- correction du chemin du fichier RSS (ajout de data) merci Tanet<br />
	- correction de l\'agenda / calendrier<br />
	- correction de l\'éditeur (prise en compte du path images, conversion n &lt;=&gt; &lt;br /&gt; en entrée et sortie)<br />
	- correction de Config Génerale (suppression de : &amp;site[29] = \"\" // Libre)<br />
	- correction du couic mettant le nombre de réponses du forum à 0 lors de suppressions physiques<br />
	- amélioration des news abrégés (maintenant en HTML)<br />
	- uniformisation de la barre de navigation (archives du forum et partie mobile)<br />
	- amélioration du contrôle d\'intégrité par batch<br />
	- ajout d\'un mécanisme anti-spam pour toutes les soumissions<br />
	<br />
	<b>v4.5.2 - 23 Juillet 2005</b><br />
	- configuration dans Config.Services du nombre de fichiers à conserver dans data/error<br />
	- configuration dans Config.Accueil du nombre de caractères affichés des nouvelles<br />
	- correction de la classe CSS des catégories en page Téléchargements et Liens<br />
	- correction de la classe CSS des informations (dates, compteurs...) en page Articles<br />
	- correction du chemin pour le bon fonctionnement du \"shortcut ico\"<br />
	- simplification du sélecteur d\'image qui accepte récursivement les sous-répertoires de img et photo (suppression des fichiers listimg1.php et listimg2.php)<br />
	- ajout automatique du \"/\" final de l\'URL du site<br />
	- amélioré les mails de supervision de la newsletter (e-mail en HTML + liens cliquables)<br />
	- correction du chemin de l\'image utilisé par le plugin speed<br />
	- suppression des r oubliés dans inc/mail/standard_2.inc et inc/mail/standard_3.inc<br />
	<br />
	<b>v4.5.1 - 7 Juillet 2005</b><br />
	- Correction&nbsp; de la liste déroulante photorama<br />
	- optimisation des news RSS: ajout date de sortie, modif présentation) (merci Tanet))<br />
	- correction de l\'envoi de mail dans tous les scripts concernés<br />
	- correction inversion des légendes Italic et souligné dans l\'éditeur TypeTool<br />
	- correction faute de frappe et ajout de chemins dans l\'éditeur de postguest (merci Djchouix)<br />
	- correction d\'un bug d\'admin (le rédacteur pouvait se connecter même Option Rédacteur non cochée!<br />
	- correction fontion eMailHtmlTo() pour prendre en compte l\'expéditeur du mail (reco, webmaster)<br />
	<br />
	<b>v4.5 - 28 Juin 2005</b><br />
	- Affichage des listes d\'administration par bloc (page) de 25 éléments<br />
	- Sélection des actions par case à cocher avec exécution globale par page<br />
	- Processus de connexion administrateur et rédacteur amélioré (séparation des menus administrateur et rédacteur, multi-administration simultanée optimisée).<br />
	- Moteur de recherche nettement amélioré avec affichage du contenu recherché<br />
	- Généralisation de l\'admin rapide<br />
	- Ajout d\'un contrôle anti-usurpation des adresses émetteur/destinataire des mini-messages<br />
	- Nouvelles abrégées en page d\'accueil (avec affichage suite)<br />
	- Download, liens et FAQ modifiés suivant le fork de Nicolas<br />
	- Amélioration-optimisation des modules photo<br />
	- Correction du menu articles: il reste ouvert, l\'article sélectionné est identifié.<br />
	- Optimisation des éditeurs d\'administration (option popup) et intégration facilitée d\'éditeur tiers.<br />
	- Prévisualisation du texte saisi dans le mini-éditeur d\'admin.<br />
	- Améliorations de l\'éditeur usuel (balises interdites,sauts de ligne, citation, code, previsualisation du message...)<br />
	- Correction du calendrier (seconde langue, aujourd\'hui surligné seulement sur mois-année courants)<br />
	- Ajout de \"alt\" dans le calendrier (merci Hubby) et de \"title\"<br />
	- Affichage de l\'agenda du mois, aperçu de l\'évènement du jour<br />
	- Compatibilité ascendante avec les versions PHP (quels que soient les réglages \"register_globals\", register_long_arrays\" et error_reporting)<br />
	- Sécurisation accrue (principalement constantes, includes)<br />
	- Possibilité de bannières en flash<br />
	- Mail de supervision au format HTML<br />
	- Envoi des mails php en multi-format (texte + HTML)<br />
	- Refonte du mail webmaster et de recommandation<br />
	- Ajout d\'un lien de consultation dans les mails de supervision<br />
	- Lettre d\'information au format HTML<br />
	- Correction de l\'agenda (affichage évènements année+1 corrigé)<br />
	- Optimisation du style et des skins grâce à l\'accroissement de l\'utilisation des div et css<br />
	<br />
	<b>V4.0 - 06 Décembre 2004</b><br />
	- Nouvel éditeur WYSIWYG compatible IE, Mozilla et dérivés pour la rédaction des articles<br />
	- Option d\'Administration différenciée (droits et mot de passe des rédacteurs individualisés)<br />
	- icone Admin pour accès rapide à tous les contenus pour le webmaster<br />
	- Option de gestion en mode membres<br />
	- Option de soumission des contributions forum et livre d\'or<br />
	- Titre de page individualisés<br />
	- Gestion de l\'UID améliorée<br />
	- Amélioration et journalisation des compteurs<br />
	- Calendrier amélioré doté des fonctions agenda<br />
	- Amélioration du forum doté d\'un mini-éditeur WYSIWYG<br />
	- Extension de l\'amélioration visuelle du forum aux tableaux de toutes les pages<br />
	- Nouveau gestionnaire de mini-messages<br />
	- Nouveau formulaire pour écrire au webmaster<br />
	- envoi d\'un e-mail aux utilisateurs qui le souhaitent quand une réponse a été mise dans un thread de forum pour lequel ils désirent être tenus au courant<br />
	<br />
	<b>v3.0p4 - 06 septembre 2004</b><br />
	- limitation de la taille des entrées des visiteurs<br />
	<br />
	<b>v3.0p3 - 29 juillet 2004</b><br />
	- correction d\'une faille de sécurité (trouvée par L0rd L4m3R)<br />
	<br />
	<b>v3.0p2 - 9 avril 2004</b><br />
	- fix compatibilité : GuppY est maintenant complètement compatible avec Abyss webserver, KF Web Server, IIS et sans doute d\'autres serveurs web (merci Kromonos et lordloose)<br />
	- ai retiré 2 lignes d\'information de debug dans le script de recherche, lignes oubliées lors du développement de la version 3.0 (merci Realia)<br />
	- correction d\'un bug dans la feuille de style CSS (merci Ouly)<br />
	- correction d\'un bug qui trompait Netscape dans les skins (par Icare)<br />
	- correction de la base de démo dans laquelle plusieurs documents comportaient des caractères \"\" parasites<br />
	- ai retiré l\'affichage du lien URL vide dans la boîte de réactions (merci Realia)<br />
	- ai corrigé l\'erreur de frappe \"adress\" par \"address\" dans le miniéditeur de l\'admin (merci JeanMi)<br />
	<br />
	<b>v3.0p1 - 26 février 2004</b><br />
	- correction d\'un bug (apparu en v3.0) dans la migration d\'une v2.3 vers une v2.4, les fichiers doc[n].inc migrent maintenant correctement<br />
	- correction d\'un bug, vérifie maintenant correctement l\'e-mail dans la fonction VerifyForm() des préférences utilisateurs<br />
	- correction d\'un bug, n\'inclue qu\'une seule fois la classe Protomail dans la gestion de la fonction mail() de Free.fr<br />
	- améliorations ergonomiques dans les e-mail envoyés quand un utilisateur s\'inscrit à la newsletter<br />
	- correction d\'un bug, si aucun set d\'icones n\'a été sélectionné, alors n\'affiche pas l\'image des news dans le module RSS<br />
	- n\'inclut qu\'une seule fois les reglobals si nécessaire (gain de temps dans l\'admin)<br />
	<br />
	<b>v3.0 - 25 février 2004</b><br />
	- ajout d\'un système de thèmes de \"skins\" pour les boîtes (par Nicolas Alves et Laurent Duveau). Merci à Ricsen pour le design des boutons submit<br />
	- newsletter avec liste d\'abonnement (par Nicolas Alves et Laurent Duveau)<br />
	- ajout d\'un suivi admin des accès (par B@lou, Nicolas Alves et Laurent Duveau)<br />
	- correction d\'un bug d\'affichage de date dans le script forum mobile (par B@lou)<br />
	- ajout de la possibilité de mettre toutes les boîtes à droite dans les préférences utilisateur<br />
	- ajout du copyright GuppY sur toutes les pages parce que trop de gens cachaient que leur site avait été fait avec GuppY ou usurpaient carrément le copyright <img alt=\"confused\" border=\"0\" src=\"inc/img/smileys/confused.gif\" title=\"confused\" /><br />
	- la compression des pages introduite avec la v2.4 est maintenant une option d\'admin<br />
	- ai créé un système de gestion de plugins de façon à faciliter l\'intégration de scripts plugins à GuppY<br />
	- ai transformé les fichiers exemples de scripts externes en plugins<br />
	- ai ajouté deux nouvelles options de menu en liste dynamique (merci Graznok et Icare)<br />
	- ajout de la gestion d\'UID pour les mini-messages<br />
	- ajout d\'une vérification des caractères \"(\", \")\" et \";\" pour contrer les tentatives de nuisance Javascript dans la saisie d\'URL pour le livre d\'or (amélioration sécurité)<br />
	- ajout d\'une vérification des mots trop longs (pour éviter les distorsions d\'affichage) dans les posts utilisateurs, dans les mini messages et dans les préférences utilisateur<br />
	- compatibilité avec le paramètre register_globals=off de php.ini (merci JonnyQuest)<br />
	- remerciements chaleureux (mais tardifs... parce que j\'avais oublié où je l\'avais trouvé !) à Pascal aka \"Le Sorcier\" (http://lesorcier.free.fr) pour le jeu d\'images du compteur miniportail_1 (le tout premier, inclus dès la version 1.0 !)<br />
	- ai aussi ajouté une nouvelle barre de progression d\'affichage des pages par Pascal aka \"Le Sorcier\" ainsi qu\'une autre barre de progression mais dont je ne me souviens plus où je l\'ai trouvée...<br />
	- nouvelle option d\'exécution en batch du contrôle d\'intégrité de la base de données<br />
	- ai corrigé un bug dans le contrôle d\'intégrité DB qui était tellement vicieux que je ne trouve pas les mots pour le décrire...<br />
	- ajout d\'une vérification de la catégorie du forum dans les posts utilisateurs (amélioration sécurité)<br />
	- nouveau module d\'archivage du forum et de consultation de cette archive (attention, notez bien que le module recherche ne scanne pas les discussions archivées)<br />
	- ai ajouté une option pour un message \"Merci de patienter...\" quand un post utilisateur est en cours de traitement et une vérification évitant les posts redondants (merci Icare)<br />
	- ai ajouté un nouveau répertoire pages/ pour y placer les pages web externes (au lieu de les mettre dans file/ qui est plutôt dédié aux fichiers à télécharger)<br />
	- ai simplifié le code source de changement de langue dans la boîte de sélection de langue<br />
	- ai ajouté le focus dans la zone de saisie d\'un mini message (par B@lou)<br />
	- correction d\'un bug dans le module recherche qui ne marchait pas pour les Nouvelles et les Photos<br />
	- les nouvelles sont maintenant publiées au format standard RSS (Web content syndication format) au lieu d\'un format spécifique à GuppY (merci Palmipod). Ce module utilise la splendide classe PHP lastRSS 0.6 pour \'parser\" des fichiers RSS sous licence GPL (par Vojtech Semecky, webmaster@webdot.cz, http/lastrss.webdot.cz/)<br />
	- ajout d\'une option d\'effet d\'animation des liens (merci reddog)<br />
	- remplacement de la variable globale &amp;REQUEST_URI par &amp;SCRIPT_NAME pour obtenir la compatibilité avec IIS (merci Erik)<br />
	- ai changé les libellés de &amp;web30 et &amp;web115 pour une meilleure compréhension (merci FabriceV)<br />
	- ai ajouté la prise en compte du Title meta tag (merci Tanet et Realia)<br />
	- ai amélioré la version imprimable des articles (merci tuture et B@lou)<br />
	- correction d\'un bug dans les préférences utilisateur qui cachait la signature du forum dans un cas bien particulier (merci bugs974)<br />
	- retour automatique suite à un post (merci Icare)<br />
	- ai ajouté 2 nouveaux formats standards de la fonction PHP mail()<br />
	- merci à Realia pour corriger l\'orthographe française de ce fichier lisezmoi.txt et à Neil pour avoir corrigé mon anglais dans le fichier readme.txt<br />
	- merci à Realia pour avoir mis à jour la base de données de démonstration<br />
	- merci à tous les membres de la GuppY Team pour leur beta testing approfondi !<br />
	- premiers plugins développés en plus des plugins exemples :<br />
	&nbsp; - plugin chat en direct (par Nicolas Alves) - NOTE : téléchargement séparé<br />
	&nbsp; - plugin d\'envoi de cartes (par Nicolas Alves) - NOTE : téléchargement séparé<br />
	&nbsp; - plugin radio (par Nicolas Alves) - NOTE : téléchargement séparé<br />
	&nbsp; - plugin musique (par Nicolas Alves) - NOTE : téléchargement séparé<br />
	<br />
	<b>v2.4p4 - 4 octobre 2003</b><br />
	- différentes corrections de failles de sécurité (par frog-m@n, http://www.phpsecure.info, merci)<br />
	<br />
	<b>v2.4p3 - 29 septembre 2003</b><br />
	- amélioration de la fonctionnalité ob_gzhandler (compression des pages), maintenant ne le fait que si utile (ne s\'appuie plus sur PHP et les navigateurs pour ce faire)<br />
	- ajout d\'une extension e-mail pour la fonction PHP mail() standard, permettant d\'envoyer les e-mails de suivi à plus d\'un destinataire<br />
	<br />
	<b>v2.4p2 - 28 septembre 2003</b><br />
	- correction de bug = certains utilisateurs voyaient les pages s\'afficher très lentement, c\'est réparé (merci Nicol@s et Arnaud)<br />
	- correction de bug = l\'e-mail de suivi du compteur renvoie la valeur du compteur<br />
	- correction de bug = les boutons de la barre supérieure n\'apparaissaient pas correctement (centrés au lieu d\'être alignés à gauche) si le bouton Stats n\'était pas affiché (merci Raiponce)<br />
	- amélioration de traduction = passage au vouvoiement d\'une phrase restée en tutoiement (merci FabriceV)<br />
	- correction de bug = le moteur de recherche ne renvoyait aucun résultat quand le site était monolangue (merci Laorens)<br />
	- correctif de sécurité XSS dans le module de publipostage (par Das, http://www.echu.org, merci)<br />
	<br />
	<b>v2.4p1 - 26 septembre 2003</b><br />
	- correction de bug = le script free.fr fonctionne<br />
	- correction de bug = le module de Stats recompte le Nombre de Visiteurs<br />
	- correction de bug = [retour] fonctionne après un post dans le forum<br />
	- correction de bug = dans la version mobile, si pas de logo du site, le code HTML est bon maintenant (merci Michel)<br />
	- correction de bug = certains utilisateurs ne pouvaient pas poster de messages dans le livre d\'or ou le forum, c\'est réparé<br />
	<br />
	<strong>v2.4 - 24 septembre 2003</strong><br />
	- ajout d\'un popup \"Page en cours de chargement\"<br />
	- le compteur de visites incrémente même si la boîte compteur n\'est pas affichée<br />
	- affiche le pseudo des utilisateurs branchés<br />
	- ajout d\'une icone pour les articles et les news<br />
	- ajout de l\'option de recherche dans une seule langue<br />
	- ajout d\'un nouveau thème de smileys<br />
	- ajout de l\'icone de la section dans les boîtes centrales<br />
	- ajout résumé du forum en page d\'accueil (derniers messages)<br />
	- ai déplacé le paramétrage de la page d\'accueil de Config Générale à Config Services<br />
	- ajout du message Livre d\'or préféré en page d\'accueil<br />
	- ajout du choix des boîtes centrales de la page d\'accueil (boîte d\'accueil, boîte dernières nouvelles, boîte forum en direct, boîte message préféré du livre d\'or)<br />
	- ajout d\'un icone Config accueil dans l\'admin<br />
	- ai changé la boîte Ecrire avec maintenant la couleur de fond par défaut des pages (et plus un fond blanc)<br />
	- saut à la ligne pour une ligne de menu dynamique si elle est trop longue<br />
	- ai renommé les boîtes Articles Gauche et Droite en 1ère et 2ème boîtes Articles<br />
	- ajout de l\'option réagir à un article<br />
	- ai ajouté la prise en compte du jeu de caractères dans tous les endroits où elle avait été oubliée : éditeur, tableau, caractères spéciaux, popup e-mail, sélecteur d\'image (merci Pavol)<br />
	- ai remplacé la phrase \"Webpage Preview\" dans l\'éditeur par la phrase traduite dans la langue du site<br />
	- ai amélioré le sélecteur d\'image<br />
	- ai ajouté l\'accès au sélecteur d\'image dans le petit éditeur de l\'admin<br />
	- ai corrigé un bug dans la version mobile : la présentation des articles pour chacune des 2 boites articles est maintenant correcte (merci Hubert)<br />
	- ai rajouté l\'étiquette alternative pour les images des drapeaux des langues<br />
	- ai rajouté l\'étiquette alternative pour l\'image du logo du site (nom du site)<br />
	- ai corrigé un bug dans le contrôle d\'intégrité DB qui se produisait quand le dernier document avait été créé mais pas enregistré dans les index<br />
	- ai changé le titre de la boîte \"Infos Webmaster / Site\" par \"Webmaster\" plus court (merci Realia)<br />
	- les menus dynamiques sont maintenant centrés dans les boîtes articles (merci Pavol)<br />
	- les smileys apparaissent maintenant quand le texte du contenu doit apparaître dans la liste de documents de l\'admin (merci Pavol)<br />
	- ai ajouté un noveau jeu de compteur \"venteux\" (merci César) et un nouveau jeu de compteur \"tournesol\" (merci Realia)<br />
	- la boîte de rattachement (1ère ou 2ème) est fournie pour les articles dans la liste de documents de l\'admin (thanks Pavol)<br />
	- ai ajouté une option pour choisir la puce des articles dans les boîtes articles (merci Pavol)<br />
	- ai ajouté une option pour cacher le bouton d\'Admin (par Nicolas Alves)<br />
	- ai ajouté un accès rapide à l\'admin des articles (par Nicolas Alves)<br />
	- le libellé du bouton \"Devenir membre\" se change en \"Vos préférences\" si l\'utilisateur s\'est enregistré (par Nicolas Alves)<br />
	- l\'utilisateur enregistré peut décider s\'il veut ou non apparaître dans la liste des utilisateurs en ligne (par Nicolas Alves et Laurent Duveau)<br />
	- des mini messages peuvent être envoyés aux utilisateurs enregistrés en ligne (par Nicolas Alves et Laurent Duveau)<br />
	- ajout du nombre de fois où un article a été lu (par Nicolas Alves et Laurent Duveau)<br />
	- ajout du nombre de fois où un fil de discussion du forum a été lu (par Nicolas Alves et Laurent Duveau)<br />
	- ajout du nombre de fois où un fichier a été téléchargé (par Nicolas Alves et Laurent Duveau). Ce compteur ne fonctionne pas sur la version mobile.<br />
	- ajout d\'un compteur de backup pour le prochain numéro de fil de discussion du forum<br />
	- amélioration de la fonction eMailTo() pour accepter des fonctions d\'e-mail spécifiques aux hébergeurs<br />
	- rajout du paramètre \"-f\" dans la fonction d\'envoi d\'e-mails (merci Michel)<br />
	- la fonction eMailTo() fonctionne chez l\'hébergeur Free.fr (avec l\'utilisation de la libraire Protomail sous licence GPL)<br />
	- ajout d\'une signature forum personaliséee pour les utilisateurs enregistrés<br />
	- l\'appel aux documents de la base de données ne se fait plus via la fonction PHP include() mais via la fonction dédiée ReadDoc()<br />
	- ai revu toutes les fonctions d\'accès en lecture et écriture sur les fichiers<br />
	- ajout du rangement par catégorie pour la FAQ<br />
	- ajout des fonctions GetCurrentDateTime() et FormatDate() pour faciliter divers formats de présentation de la date et l\'heure<br />
	- ajout de nouveaux formats de date et création de formats d\'heure<br />
	- amélioration importante du code source des scripts inc/config[n].inc<br />
	- ajout de la recherche des images png et bmp dans la fonction IsImage()<br />
	- ai retiré la feuille de style CSS du fichier inc/hpage.inc et l\'ai mis dans un nouveau fichier inc/style.inc<br />
	- ai corrigé un bug dans le script de recherche qui faisait que les articles trouvés étaient toujours considérés comme étant dans la 1ère boîte (merci Pavol)<br />
	- pour un affichage plus rapide, les pages sont compressées avant d\'être envoyées au navigateur web (pour les sites web tournant sous PHP &gt;= 4 et pour les navigateurs qui acceptent la réception de pages compressées)<br />
	- ai sécurisé les paramètres de ligne de commande (Secunia Advisory: SA9621 sur le paramètre lng)<br />
	- ajout de 3 boîtes libres additionnelles (par Nicolas Alves et Laurent Duveau)<br />
	- ai effectué de nombreux changements dans tous les scripts afin de diminuer la taille des fichiers de la base de données<br />
	- CHANGEMENT DE NOM : MINIPORTAIL DEVIENT GUPPY<br />
	<br />
	<strong>v2.3p1 - 03 août 2003</strong><br />
	- ai corrigé le bug dans lequel le lien dans le bouton page suivante était erroné dans la page news mobile (merci airhero)<br />
	- ai corrigé un bug en remplaçant include(\"minieditor.inc\") par include(\"inc/minieditor.inc\") dans le fichier admin.inc (merci Eddie)<br />
	<br />
	<strong>v2.3 - 27 juillet 2003</strong><br />
	- ajout d\'une option de choix des menus en liste ou en dynamique<br />
	- postage de news visiteur : même si écrite dans une seule langue, mettre le contenu de la news dans les deux langues (jusqu\'à ce que le webmaster la traduise)<br />
	- ajout de trois nouveaux thèmes de smileys<br />
	- ajout de deux nouveaux thèmes d\'icones (merci B@lou et Florent)<br />
	- ajout du cas où UNE seule news est affichée sur la homepage (merci Laurent Roger)<br />
	- ajout d\'un saut direct aux pages (par Nicolas Alves et Laurent Duveau)<br />
	- passage du tutoiement au vouvoiement dans la langue française (merci Realia)<br />
	- changements mineurs des police et formats de texte dans la recherche, les notes et autres pages générales (merci Realia et Nicolas)<br />
	- correction de la faille de sécurité (merci frog-m@n)<br />
	- correction du bug qui faisait que le script d\'installation ne retournait pas à la page d\'accueil si les fichiers d\'installation sont effacés<br />
	- ajout d\'une option \"pas de logo\"<br />
	- grosse amélioration de l\'éditeur WYSIWIG (par Nicolas Alves)<br />
	- ajout d\'une boîte calendrier (par Nicolas Alves et Laurent Duveau)<br />
	- option pour choisir le nombre d\'éléments à afficher dans les news, le forum, les liens, les téléchargements, la FAQ et le livre d\'or déplacée de \"Config Site\" à \"Config Services\"<br />
	- homogénéisation du rendu des boîtes centrales et latérales<br />
	- correction de bug : accepte les e-mails du style \"prenom-nom@site.com (caractère \"-\" accepté). La vérification de l\'e-mail n\'est pas aussi exhaustive qu\'auparavant mais elle vérifie les cas les plus courants de mauvaise saisie<br />
	- ajout de la gestion de style des citations (par Nicolas Alves et Realia)<br />
	- ajout de la gestion de style des formulaires (par Nicolas Alves)<br />
	- ai enlevé le lien sur les nombres des compteurs dans la boîte \"Visites\"<br />
	- passage au vouvoiement dans ce fichier lisezmoi.txt à la place du tutoiement (par Realia)<br />
	- ai ajouté un premier niveau de gestion des préférences utilisateur par cookie<br />
	- gestion du format de date US (merci à Julien et à Realia qui a relayé l\'information)<br />
	- ajout du choix de laisser les visiteurs soumettre des news ou non<br />
	- ajout d\'une recherche ciblée sur une catégorie (forum, articles, news...)<br />
	- ajout d\'un formulaire de maintenance manuelle des caractéristiques d\'un document (dates création et modification, auteur et e-mail)<br />
	- ajout d\'un petit éditeur pour les saisies utilisateurs et la zone admin (par Nicolas Alves et Laurent Duveau)\'article (merci Realia)<br />
	- ajout d\'un script externe exemple intégré à GuppY et qui affiche les nouvelles de l\'aldweb Site<br />
	- changement de l\'ordre des icones d\'Admin depuis un classement alphabétique en un classement voulu plus logique (merci <a href=\"mailto:B@lou\">B@lou</a>)<br />
	<br />
	<strong>v2.2 - 18 avril 2003</strong><br />
	- correction de bug : \"Times New Roman, serif\" à la place du faux \"Time New Roman, serif\" (merci Realia)<br />
	- correction de bug : les stats de l\'heure en cours sont aussi remises à zéro quand demandé dans l\'Admin<br />
	- ajout du message de forum en cours de réponse pour mémoire dans le formulaire de réponse (par Nicolas Alves)<br />
	- choix donné au webmaster du positionnement des boites latérales (par Nicolas Alves et Laurent Duveau)<br />
	- ajout d\'une autre boite pour les articles de façon à séparer les articles en 2 catégories principales (par Nicolas Alves et Laurent Duveau)<br />
	- ajout d\'un nouveau thème d\'icones (par Roger)<br />
	- ajout d\'un nouveau thème de compteur (par César)<br />
	- ajout d\'une gestion de thèmes pour smileys (par Nicolas Alves)<br />
	- séparation du fichier de langue en deux (admin et web) pour un chargement des pages plus rapide<br />
	- petite mise à jour dans la mise en forme de l\'e-mail envoyé au webmaster dans le cas d\'un nouveau fil de discussion<br />
	- correction d\'un petit bug \"inc/img/trans.gif\" à la place de \"/inc/img/trans.gif\" dans le fichier inc/boxhome.inc (merci Michel)<br />
	- ai remplacé [P][CENTER] par [P align=\"center\"] sinon IE prend la police de caractères par défaut au lieu de celle qui lui est demandée (merci Michel)<br />
	- ajout d\'une option pour choisir le nombre d\'éléments à afficher dans les news, le forum, les liens, les téléchargements, la FAQ et le livre d\'or<br />
	- mise à jour de la fonction CompteVisites() pour qu\'elle soit conforme à la structure de la base de données GuppY ainsi que de toutes les parties du code source qui accèdent aux fichiers ipstats.dtb et ippoll.dtb<br />
	- ai changé le code source pour tous les accès à la fonction PHP foreach() de façon à être compatible PHP3 puisque foreach() marche seulement avec PHP4<br />
	- ai changé le code source pour tous les accès à la fonction PHP pathinfo() de façon à être compatible PHP3 puisque pathinfo() marche seulement avec PHP4<br />
	- ai renommé toutes les variables ­service[] en ­serviz[] (pour d\'étranges problèmes d\'incompatibilité sur certains Linux, la Mandrake si je me souviens bien)<br />
	- changement de répertoire automatique dans la zone Fichiers (plus besoin d\'appuyer sur un bouton pour déclencher le changement de répertoire)<br />
	- un clic sur une balise de formatage de texte copie la balise dans le texte dans le formulaire utilisateur<br />
	- nouveau sélecteur de couleur dans Config Site (par Nicolas Alves)<br />
	- ajout d\'un éditeur WYSIWYG pour le contenu dans la zone d\'Admin (par Nicolas Alves, à partir d\'un script dont l\'auteur original nous est malheureusement inconnu =&gt; nous aurions souhaité lui demander son autorisation et aussi le remercier !)<br />
	- un nettoyage dans l\'organisation des images a été effectué<br />
	- ré-écriture du script d\'installation qui est maintenant un vrai script d\'installation propre et de migration<br />
	<br />
	<strong>v2.1 - 10 mars 2003</strong><br />
	- correction d\'un bug où l\'URL du Site et le Meta Identifier URL étaient inversés<br />
	- correction d\'un bug dans lequel les fonctions Javascript pouvaient créer des erreurs si le caractère \' était passé à ces fonctions Javascript<br />
	- un clic sur un smiley copie le smiley dans le texte (par Nicolas Alves)<br />
	- gestion des erreurs 40x (pour serveur web Apache uniquement)<br />
	- ajout d\'une gestion de thèmes pour compteur (par Nicolas Alves)<br />
	- ajout de la gestion de la couleur pour la barre de défilement (par Nicolas Alves)<br />
	- focus sur le premier champ dans les formulaires de saisie (par B@lou &amp; Laurent Duveau)<br />
	- réécriture complète du module de contrôle d\'intégrité et de correction de la base de données<br />
	<br />
	<strong>v2.0 - 27 février 2003</strong><br />
	- correction d\'un bug dans la vérification des données saisies da<br />
	bouton retour<br />
	- ajout en bas de page d\'un lien Retour en haut de page<br />
	- ajout de l\'affichage défilant du slogan (merci ßugs)<br />
	- ajout d\'une gestion de photorama plus sophistiqué (avec description des photos)<br />
	- ajout des logs pour les pages fortopic.php (que j\'avais oubliée dans la v1.9) et photorama.php dans les Stats<br />
	- ajout d\'un système de cryptage des adresses e-mail (protection contre le SPAM) même si elles apparaissent clairement dans la fenêtre du navigateur<br />
	<br />
	<strong>v1.9 - 11 février 2003</strong><br />
	- mise à jour de statsbk.dtb at remise à zéro de ipstats.dtb quand la valeur du compteur de visites est changée manuellement<br />
	- dans l\'interface d\'admin de choix des services, la présentation de l\'option forum avec catégories a été légèrement modifiée pour mieux mettre en évidence qu\'il s\'agit d\'une sous-option de la section Forum<br />
	- ajout de la catégorie de forum dans l\'envoi de l\'e-mail de supervision<br />
	- quelques petits bugs mineurs corrigés<br />
	- ajout d\'une gestion de bannières<br />
	- ajout d\'une boite extra (appelée \'boite libre\')<br />
	- ajout d\'une fenêtre popup \'à propos\'<br />
	- utilitaire de vérification de l\'intégrité de la base de données<br />
	- ajout d\'une gestion de thème d\'icones<br />
	<br />
	<strong>v1.8 - 05 février 2003</strong><br />
	- ai changé le texte du titre des messages de forum dans l\'admin (le texte n\'était pas correct)<br />
	- titre retiré des réponses de forum (n\'était pas nécessaire et augmentait la taille de la base de données)<br />
	- ai corrigé un bug où le résultat d\'une recherche vers un thread de forum produisait une erreur<br />
	- remise des smileys dans inc/img/ qui avaient été enlevés par mégarde en version 1.7<br />
	- correction d\'un bug dans les appels à la fonction eMailTo(), dans boite compteur et publipostage visiteurs<br />
	- correction d\'un bug dabs lequel une modification par l\'admin dans le forum, les news ou le guestbook affichait ensuite systématiquement l\'adresse e-mail du posteur (même s\'il avait coché qu\'il ne voulait pas que son e-mail soit affiché en clair !)<br />
	- ajout de sujets de discussion dans le forum<br />
	- affichage des news sur la homepage que si le nombre de news à afficher est supérieur à 0<br />
	- ajout de la gestion des charsets (pour les langues comme l\'Arabe...)<br />
	- amélioration du changement de langue dans l\'admin (dans le cas où le langage principal est changé et aucune langue alternative n\'est choisie)<br />
	<br />
	<strong>v1.7 - 28 janvier 2003</strong><br />
	- correction du bug page n/m dans le forum où m était faux en version 1.6<br />
	- correction d\'un bug d\'affichage de la colonne de droite des pages<br />
	- ajout d\'une boite Recommander à un ami<br />
	- ajout du rangement par catégorie pour les liens et téléchargements<br />
	- mise à jour du script de migration pour la version 1.7<br />
	- ajout de 2 exemples de scripts externes qui s\'intègrent à GuppY (file/speed.php et file/mind.php)<br />
	- amélioration des liens vers des smileys dans la boite Spécial et les images du pied de page quand les scripts sont exécutés depuis le répertoire file/<br />
	- correction d\'un bug qui faisait que le titre des nouvelles était toujours affiché dans la langue principale<br />
	- changement de langue sans retourner systématiquement à la page index (merci Alex)<br />
	- changement de l\'appel d\'une fonction PHP de façon à rendre GuppY compatible avec PHP version &lt; 4.1.0<br />
	- correction d\'un bug \"invisible\" dans la boite recherche<br />
	<br />
	<strong>v1.6 - 23 janvier 2003</strong><br />
	- nouvelles traductions : Espagnol et Hollandais<br />
	- traduction améliorée : Anglais<br />
	- ajout d\'une fenêtre popup d\'aide au choix des couleurs RGB<br />
	- très légère mise à jour du format de l\'e-mail de supervision livre d\'or<br />
	- ajout d\'une option de publication des nouvelles vers un site externe (merci de vous référer au fichier de script getmpnews.php)<br />
	- ajout d\'une option d\'effet de transition entre pages (pour le navigateur IE seulement, sans effet sur les autres navigateurs)<br />
	- affiche 10 messages du forum plutôt que 5<br />
	- ajout d\'une option permettant au posteur de choisir que son adresse e-mail soit<br />
	bug dans le module Stats (news, links, photos, poll, search et stats étaient comptés comme une page index)<br />
	- correction du numéro de version de GuppY dans l\'en-tête du fichier readme.txt.<br />
	- ajout de services de supervision (envoi d\'e-mails au webmaster par le site)<br />
	- utilisation des fichiers frth.dtb et forum.dtb introduits avec la v1.2 pour accélérer le travail de publipostage des discussions de forum<br />
	<br />
	<strong>v1.2 - 5 janvier 2003</strong><br />
	- amélioration du temps d\'affichage de toutes les pages par création d\'une table intermédiaire contenant les informations nécessaires pour la boite articles<br />
	- amélioration de la vitesse d\'affichage du module Forum<br />
	- ré-éecriture complète du module Statistiques qui s\'avérait bien trop lourd pour un site ayant plus d\'une dizaine de visiteurs par jour<br />
	<br />
	<strong>v1.1 - 2 janvier 2003</strong><br />
	- correctif pour éviter que les utilisateurs ajoutent des enregistrements de façon simultanée sur les mêmes fichiers (problème principal trouvé dans les Stats)<br />
	- Le formulaire de postage utilisateurs a été amélioré (le rendu n\'était pas très beau pour une résolution d\'écran inférieure à 1024x768)<br />
	<br />
	<strong>v1.0 - 30 décembre 2002</strong><br />
	- première version</p>
');
$fieldc2 = stripslashes('<p>
	<strong>v5.0 (AND following ones, perhaps not all of this wish list will be done in that release)</strong><br />
	- currently under development -<br />
	- Overall objective: with the 4.x series, we achieve a functional maturity level. Now, we will focus our work on new technicals for more user friendliness and better managing. KISS...<br />
	- Optimization of standards compliance<br />
	- Take care of your suggestions posted on FreeGuppY</p>
<p>
	&nbsp;</p>
<p>
	<span style=\"font-size:12px;\"><strong>GuppY - Security patch 4.6.21a</strong></span><br />
	<br />
	<strong>This latest release is 4.6.21a patch with corrections, three new features, and the correction of a squeak that allows code injection, discovered Saturday, October 20, 2012.<br />
	<br />
	Attention! All versions of GuppY are involved, including version 4.6.21.<br />
	<br />
	You MUST IMMEDIATELY install this fix for the security of your site.</strong><br />
	<br />
	<strong>Corrections:</strong><br />
	- Fixed display in postguest.php &#36;web111 (thank you JeanMi, Saxbar)<br />
	- Correction MAJ_AGENDA.PHP (thank you linuxmr)<br />
	- Correction in English text of error.php (thank you Corrector)<br />
	- Fixed display flag in boxlang.inc (thank you Saxbar)<br />
	- Fixed &#36;pluginlist in attribdroits.inc (thank you linuxmr)<br />
	- Correction control input email, url (thank you jchouix, thank you Saxbar)<br />
	- Fixed file fr_upload.inc in French language (thank you Corrector)<br />
	- Fixed file en_upload.inc in English (thank you Corrector)<br />
	- Correction of htmlspecialchars in fckeditor_php5.inc and fckeditor_php4.inc (thank you linuxmr)<br />
	- Updated scrolling credits (thank you Papinou)<br />
	- Changed Htaccess file: only files with the extension inc. or dtb are blocked (thank you JeanMi)<br />
	- Added possibility to subscribe to a forum thread if subject is changed (thank you Saxbar)<br />
	<br />
	<strong>News features:</strong><br />
	- New version of pgeditor.php (thank you jchouix)<br />
	- Integration of version 3.6.4 of CKEditor (thank you Papinou)<br />
	- File update. Htaccess root GuppY (JeanMi thank you, thank you Saxbar)<br />
	&nbsp; For update. Htaccess root, you must add MAJ_HTACCESS.PHP the url of your site,<br />
	&nbsp; then Enter to run it after applying the patch 4.6.21a.<br />
	<br />
	As for each new version, do not forget to update your plugins, reinstall your forks, and validate your configuration pages.<br />
	To upgrade from version 4.6.20 to version 4.6.21a, it is this patch_nc_4621a you must use.<br />
	&nbsp;<br />
	Thank you to all the participants in this patch.</p>
<p>
	&nbsp;</p>
<p>
	<strong>v4.6.21 - 18 October 2012</strong><br />
	<br />
	We are happy to come up with patch 4.6.21 which contains fixes and two new features.<br />
	<br />
	Corrections:<br />
	- Fixed display in postguest.php &#36;web111 (thank you JeanMi, Saxbar)<br />
	- Correction MAJ_AGENDA.PHP (thank you linuxmr)<br />
	- Correction in English text of error.php (thank you Corrector)<br />
	- Fixed display flag in boxlang.inc (thank you Saxbar)<br />
	- Fixed &#36;pluginlist in attribdroits.inc (thank you linuxmr)<br />
	- Fixed file fr_upload.inc in French language (thank you Corrector)<br />
	- Fixed file en_upload.inc in English (thank you Corrector)<br />
	- Correction of htmlspecialchars in fckeditor_php5.inc and fckeditor_php4.inc (thank you linuxmr)<br />
	- Updated scrolling credits (thank you Papinou)<br />
	- Changed Htaccess file: only files with the extension inc or dtb are blocked (thank you JeanMi)<br />
	- Added possibility to subscribe to a forum thread if subject has been changed (thank you Saxbar)<br />
	<br />
	News features:<br />
	- New version of pgeditor.php (thank you jchouix)<br />
	- Integration of version 3.6.4 of CKEditor (thank you Papinou)<br />
	<br />
	ATTENTION: Htaccess file has been changed in this patch.<br />
	&nbsp; &nbsp;<br />
	Thank you to all the participants in this patch.</p>
<p>
	&nbsp;</p>
<p>
	<span style=\"font-size:12px;\"><strong>v4.6.20 - 24 May 2012</strong></span><br />
	<br />
	The patch_nc_4.6.20 fixes an XSS flaw, two vulnerabilities allowing code injection and three squeaks reported by Antoine Cervoise, a computer security expert.<br />
	<br />
	Many thanks to Antoine Cervoise, for his interest and for his research on the security of GuppY.<br />
	You may see his works on http://www.antoine-cervoise.fr<br />
	<br />
	In addition to the correction of faults and squeaks, here is what we\'ve added in this patch:<br />
	<br />
	- Correction of files for all boxes display (thanks Saxbar)<br />
	- Correction of blocked registration of members by automatically deleting the .dtb file with missing pseudo (thanks Saxbar, JeanMi)<br />
	- Management of foreign languages by the FCK Editor plugin smileys in file admin/editors/guppy_fckconfig.js (thanks jchouix)<br />
	- Correction of image insertion with Chrome in admin/editors/upload/upload.php (thanks jchouix)<br />
	- Correction of admin/inc/attribdroits.inc for &#36; plugin list (thanks Saxbar)<br />
	- Correction of in the blog files (thanks Saxbar)<br />
	- Correction of in all skins (thanks Saxbar - Papinou)<br />
	- Correction of the untitled boxes display in all skins (thanks Saxbar)<br />
	- Correction of the display of the block quote (thanks Saxbar)<br />
	- Update of CK Editor version 3.6.3 (thanks Papinou)<br />
	- Correction of CKEditor and FCK Editor (htlmspecialchars, ) for editing text in admin for PHP 5.4 and higher (thanks Saxbar, jchouix)<br />
	<br />
	Many thanks to JeanMi for its proposals and the correction of a squeak for &#36;site[\'TZ\'] .<br />
	&nbsp; &nbsp;<br />
	Warning: All skins are affected by changes.<br />
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; For skins no_skin, skn1, skn_css, skn_css1 you must regenerate the file style.css of each skin with admin/config look/config style to apply the changes.<br />
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; For skins island and web20, the style.css has been changed for each one in the patch.</p>
<p>
	&nbsp;</p>
<p>
	<strong>v4.6.19 - 30 March 2012</strong></p>
<p>
	<br />
	This non-cumulative patch 4.6.19 fixes a critical flaw, released and intended for any previous version of GuppY.<br />
	You <strong>MUST IMMEDIATELY</strong> install this fix for the security of your site.<br />
	<br />
	We added some new features or corrections:<br />
	<br />
	- Corrected function WriteDoc, thanks jchouix<br />
	- Added social networks, thanks Saxbar<br />
	- Added initialisation DBLOGL in install/cleanup.php, thanks Icare<br />
	- Replaced Close by &#36; admin458 in admin/inc/archbatch.php, thanks Icare<br />
	- Updated pages/db_guppy.txt, thanks Icare<br />
	- Correction in config8 config9 and sliders on the body, thanks Saxbar<br />
	- Correction in config2, deleting &#36;page[24] for the cursor in the body and cursor:hand, thanks Saxbar and tonton_christian<br />
	- Added an additional step in the install directory migration scripts, in order to comply the datas with php5 (based on the script of the data-mill), thanks Saxbar, Icare, and JeanMi.<br />
	- display of lateral and central titleless boxes (if title\'s empty) thanks Saxbar.<br />
	<br />
	BEWARE: all skin.inc files of the skins in the GuppY pack have been updated including no_skin to prevent display of box title if it\'s empty.If you\'ve customised one or all of your skin.inc files, then you have to make a backup not to lose them by overwriting.<br />
	<br />
	Many thanks to all contributors to this patch</p>
<p>
	&nbsp;</p>
<p>
	<strong>V4.6.18 - 09 February 2012</strong><br />
	<br />
	Integration into GuppY of private groups has induced a number of disorders. Some vulnerabilities have still been detected in the version 4.6.17.<br />
	<br />
	We therefore propose version 4.6.18 which fixes these flaws and some squeaks.<br />
	This version also includes some new features.<br />
	Installation of this version is essential for data security of private groups, and to control the registration of members.<br />
	<br />
	The following changes have been achieved in this patch:<br />
	<br />
	<br />
	On the tracker :<br />
	<br />
	FS # 384 - Added missing font sizes in admin / editors / guppy_ckconfig.js (thanks François Saxbar)<br />
	FS # 387 - Remove inc/plugin.inc (thanks JeanMi)<br />
	FS # 388 - Fixed forum answer thread management (thanks linuxmr, Saxbar)<br />
	<br />
	<br />
	&nbsp; On the forum:<br />
	<br />
	- Added &#36;supervision10 admin/inc/config5 in email to moderators / administrators in supervision (thanks tonton_christian, Saxbar)<br />
	- Fixed php4 compatibility admin/inc/config7.inc (thanks Laroche)<br />
	- Added &#36; supervision10 in admin/inc/confupdt.inc (thanks tonton_christian, Saxbar)<br />
	- fixed file admin/inc/logread.inc (thanks Papinou)<br />
	- Added correction patch for download.php and dwnld_pr.php&nbsp; (thanks Laroche)<br />
	- Added width choice of CK Editor in services config (thanks Saxbar)<br />
	- Changed inc/includes.inc for editor width and changed version (thanks Saxbar)<br />
	- Correction of &#36;typ illegal value for blog, news, guestbook, and &#36;screen_choice (thanks Saxbar)<br />
	<br />
	<br />
	Other changes and improvements:<br />
	<br />
	- Removed short tag line 236 of admin/inc/members.inc (thanks Laroche)<br />
	- Changed language file .fr and en.<br />
	- Added confirmation request to unsubscribe from the newsletter. (Thanks Saxbar)<br />
	- Fixed &#36;uwebsite, deleted welcome message display in case of modification, correction reference to admin (thanks Laroche)<br />
	- Private groups Control for forum archiving (thanks Saxbar)<br />
	- Fixed calendar adjustment iframe (thanks Saxbar)<br />
	- Fixed XHTML validation link (thanks Papinou)<br />
	- Changed copyright display bpage and maintenance (thanks Saxbar)<br />
	- Changed members registering control (thanks Saxbar)<br />
	- Fixed display icons for plugins allocation rights (thanks Saxbar)<br />
	- Display of active services for granting collaborator permissions (thanks Saxbar)<br />
	- Deleted old boxes in profile changing area (thanks JeanMi)<br />
	- Added time zone (thanks Saxbar)<br />
	- Correction of date_default_timezone_set &gt;= PHP 5.1 (thanks JeanMi)<br />
	- Initialisation of default time zone at \"Europe/Paris\" (thanks JeanMi)<br />
	- Correction of function IsPrivateForumCat() (thanks Saxbar)<br />
	- Fixed IsPrivateForumCat() function (thanks Saxbar)<br />
	- Changed variable &#36;obgo (thanks Saxbar)<br />
	- Correction of private forum management for mobile phone. (thanks Saxbar)<br />
	<br />
	Many thanks to all contributors to this patch.</p>
<p>
	&nbsp;</p>
<p>
	<strong>V4.6.17 - 21 October 2011</strong></p>
<p>
	This includes patch_nc_4617 corrections, improvements and innovations.</p>
<p>
	What\'s new:</p>
<p>
	- Insertion of CK Editor 3.6.2 as WYSIWYG editor in GuppY (thanks jchouix)<br />
	- Adaptation of the mobile phone part to private groups (thanks Saxbar)<br />
	- Added flags of all countries in inc / lang (thanks François)<br />
	- Added batch addition of new members to a private group (thanks Saxbar)<br />
	- Created directory inc/inchead to allow automatic include of php scripts or html at the top of the page (thanks Saxbar - Laroche)<br />
	- Creation of a directory inc/incfoot to allow automatic include of php scripts or html at the bottom of the page (thanks Saxbar - Laroche<br />
	- Creation of a link to the FAQ, download and links, add the thumbnail hyperlink in inc/img/general (thanks Laroche)</p>
<p>
	Corrections:</p>
<p>
	- Fixed characters to display country flags in log (thanks François)<br />
	- Change display of config look and config style (thanks Saxbar)<br />
	- Fixed calendar iframe display (thanks Laroche)<br />
	- Fixed \"read more\" display for the blog and the news on homepage (thanks Laroche)<br />
	- Optimization of Webmaster display box (thanks Saxbar)<br />
	- Correction of link making after search for planner and forum in search.php (thanks Saxbar)<br />
	- Correction of misprint in blog.inc. Deletion of&nbsp; &amp;nbsp on line 315 (thanks JeanMi)<br />
	- Updated and added language files in the inc/lang/en-admin.inc in-web.inc, en-admin.inc, en-web.inc<br />
	- Fixed printfaq.php limited to the FAQ (thanks Laroche)<br />
	- Optimization of skin header Island display (thanks Papinou)<br />
	- Change pages display for printing (thanks Saxbar)</p>
<p>
	Securing private groups:</p>
<p>
	- Fixed private downloads (thanks Laroche)<br />
	- Correction of research to respect private groups data.(thanks Laroche)<br />
	- Fixed forum, private subjects, live forum display. (thanks Laroche)<br />
	- Possibility of having a forum without categories if not using private groups (thanks Laroche)<br />
	- Modified the creation of a private section in the forum by a simple check box and creation of the corresponding private group PR.</p>
<p>
	We recommend installing this version 4.6.17 for the complete security of your private groups, deleting the file/private folder and using of a personal sub-directory in /file for private downloads.<br />
	Reading the file readme.html and tutorial on the use of private groups is essential.</p>
<p>
	Caution - As with any new version, remember to update your plugins, reinstall or do your forks again, revalidate your configuration pages.</p>
<p>
	<strong>V4.6.16 - 02 September 2011</strong><br />
	Patches and security version 4.6.16</p>
<p>
	Integration of private groups within GuppY has led to a number of disorders and especially security flaws that were not detected during the beta testing.</p>
<p>
	We therefore propose version 4.6.16 which fixes these flaws and some squeaks.<br />
	The installation of this release is essential for data security private groups.</p>
<p>
	On the bugtracker:<br />
	# 366 - fix vulnerabilities to private forums and downloads (thanks jchouix, Laroche, Pascal31)<br />
	# 367 - fixed display online forum (thanks jchouix, Laroche, Pascal31)<br />
	# 365 - fixed inconsistency creating data / temp (thanks hpsam)<br />
	# 363 - fixed display boost in counter.inc (thanks Papinou)<br />
	# 372 - fixed typo in forum.php (thanks JeanMi)<br />
	# 374 - taking into account optimization of languages ??in fck editor (thanks jchouix)<br />
	# 375 - change management record of the members (thanks Laroche)</p>
<p>
	Forum:<br />
	- Fixed icon frame in news.inc (thanks Papinou)</p>
<p>
	# Header correction in admin.inc<br />
	# Correction of language files -fr and -en<br />
	# Correction of latest news display on homepage (thanks Laroche)<br />
	# Correction of display and treatment of private downloads,<br />
	&nbsp;&nbsp; Creation of a sub-directory file/private with. htaccess to secure private downloads to be placed in this directory private (thanks Laroche)<br />
	# Change configuration files to control the creation of categories of private forum (thanks Laroche)<br />
	# Optimization of block quote box display in every pack of skins (thanks Papinou)<br />
	&nbsp;&nbsp; Attention: If you have customized a GuppY skin pack without changing the name, you must rename it before installing the patch or lose your changes.<br />
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Style.css files and skin.inc in each skin have been changed.</p>
<p>
	Many thanks to cece45 for pointing out the flaw in private forums.</p>
<p>
	We still have to adapt the \"mobile part\" of GuppY<br />
	Warning: Delete the folder \"mobile\" is required when private groups are used.</p>
<p>
	With these corrections, if you do not configure or use private groups, the operation of GuppY is unchanged.</p>
<p>
	Note: It is essential to read the instructions above, and the readme.html Private_Groups_Tuto.pdf or readme.txt that come with the pack guppy_4616.zip</p>
<p>
	<strong>v4.6.15 - 01 July 2011</strong><br />
	On the bugtracker:<br />
	- # 327 - removal htaccess error 401<br />
	- # 340 - is the addition of HR tag - thanks jchouix<br />
	- # 357 - fixed number of days the previous month - thanks jchouix<br />
	- # 358 - correction taken into account in domaine.domaine web address - thanks jchouix<br />
	- # 359 - fixed validation error - thanks jchouix<br />
	- # 360 - removal PGeditor access source code - thanks jchouix<br />
	- # 361 - improvement in partial display new page and permalink - thanks Laroche<br />
	- # 362 - improved display part of the year blog home page - thanks Laroche<br />
	- English Forum: Fixed typo in inc / blogcalendar.inc<br />
	- Suggestion Box No. 234: Fixed date display day event (other than d / m / a) - thanks Quefer</p>
<p>
	New:<br />
	- The management of private groups of users - thanks Icare - thanks JeanMi</p>
<p>
	<strong>V4.6.14 - 14 February 2011</strong><br />
	Copyright - Version<br />
	-1- Update, year copyright inc/bpage.inc<br />
	-2- Update, year copyright inc/hpage.inc<br />
	-3- Update, version inc/includes.inc<br />
	On the bugtracker:<br />
	-1- FS#348 - The editor icons are missing in tinymsg<br />
	-2- FS#347 - Position of the tooltip linked to the class ‘pop’<br />
	-3- FS#354 - Report of graphic bug and correction.<br />
	-4- FS#340 - Suggestion box : about the addition of the HR tag<br />
	-5- FS#338 - Blocked topics at the top do not stay there<br />
	-6- FS#329 - Plugin connexion speed<br />
	-7- FS#341 - In French, there are two &#36;web434 and no &#36;web435<br />
	-8- FS#337 - At Free, control of last version fails<br />
	Suggestion box:<br />
	-1- Reaction n°217 - admin/inc/config7.inc correction<br />
	-2- Reaction n°206 - Correction of file inc/log.inc<br />
	-3- Reaction n°202 - Modification of admin/inc/admin.inc, by adding article title in Admin - Articles reactions<br />
	PgEditor:<br />
	- Addition and update of PgEditor 2.5.1 - Correction Opéra bug</p>
<p>
	FS#355 Correction of security flaw by Antoine CERVOISE (http://www.antoine-cervoise.fr/)</p>
<p>
	Corrections and modifications were on the tracker.<br />
	PgEditor new version and the correction of security flaw are from djchouix.</p>
<p>
	<strong>v4.6.13 - 22 May 2010</strong><br />
	#286 - initialization of the timezone with \'Europe/Paris\' if version PHP &gt;=5.1<br />
	#316 - file inc/log.inc forgotten into 4.6.12<br />
	#323 - correction of posting in admin/inc/members.inc<br />
	#324 - correction of a bad character in admin/inc/poll.inc, thanks Laroche<br />
	#325 - correction of the files of upload (continuation of #320)<br />
	#328 - correction of posting in inc/bloglist.inc if no ticket</p>
<p>
	<strong>v4.6.12 - 01 May 2010</strong><br />
	#314 - in admin/inc/admin.inc, correction of a tag &lt;/table without &gt;<br />
	#315 - in inc/pgeditor/style/pgeditor.css, replacement of a value \"undeline\" by \"underline\"<br />
	#316 - NEW: Addition of the statistics of the previous month, visible at the end of one month<br />
	#317 - in admin/inc/members.inc, correction of the path of the icons of the minieditor<br />
	#318 - addition of the fields author and email in the page of administration of the articles<br />
	#319 - removal of the file admin/adminstrateur.php (only in the complete pack)<br />
	#320 - at the time of upload, the creation of directory is prohibited if the name of the repertory contains the word script<br />
	#321 - correction of the poll administration page , which lost the value of the selected skin<br />
	#322 - correction in inc/topforum.inc for W3C validation</p>
<p>
	<strong>v4.6.11 - December 11th, 2009</strong><br />
	#291 - typo correction in preg_match() in admin/editors/minieditortextarea/popup/image.php<br />
	#293 - typo correction in inc/blogcalendar.inc<br />
	#294 - Document view secured in agenda.php by hpsam<br />
	#295 - pluginlist correction in admin/inc/infos.inc<br />
	#297 - functions.php corrected: generation of mailto link by ForceToAbsolute_callback() function<br />
	#298 - lang/fr-admin.inc of pack 4.6.10 reviewed as was incorrect in the patches<br />
	#299 - daily events summary corrected in inc/calendar.php, thank you Linuxmr<br />
	#300 - css error corrected as well as duplicate of rubric title in blogrss.php<br />
	#301 - selectDBFieldsBy functions optimised...<br />
	#302 - Empty link deleted in banners where undefined URL<br />
	#303 - blog boxes view optimised; hr in blog, news.inc and boxreact.inc deleted<br />
	#304 - &#36;admin53 replaced by &#36;admin173 in admin.inc, forum message modified<br />
	#305 - correction, in upload.php extensions in capital letters taken into account<br />
	#306 - test in inc/lang/fr-special.inc and en-special.inc corrected<br />
	#307 - forum view made reliable (distortions removed and div.code classes in pgeditor optimised) and width replaced by style=width in table cells of various scripts<br />
	#310 - added button to browse server for downloads in admin.inc, thanks Linuxmr<br />
	#311 - correction of prag_match in admin/editors/minieditortextarea/popup/entities.php<br />
	- added no go button in scripts install, cleanup and delete.php<br />
	#312 - correction of display licence in download.php<br />
	#313 - added daily warning in administrateur.php to remember the removal of install directory<br />
	- updated all dates of copyright<br />
	<strong>v4.6.10 - September, 7th 2009</strong><br />
	#253 - correction of the relative addresses of the images (img/, Inc/img/and photograph) in permanent addresses in the newsletter and flows RSS<br />
	#253 - correction of the relative addresses of the links in permanent addresses in the newsletter, flows RSS and supervision emails<br />
	#253 - correction of the anchors in the newsletter, which remains relative<br />
	#253 - correction of the function pubDate<br />
	#253 - correction of the UpdateDBBlog function<br />
	#256 - correction of management in zone members in postguest.php<br />
	#259 - correction of error.php following the patch 4.6.9<br />
	#260 - addition of the file install/migrate24.php<br />
	#262 - correction of the bonds during the change of language<br />
	#263 - addition of a function iconv when PHP &lt; 5, thank you linuxmr<br />
	#266 - correction about the tests in the course of a repertory with the function to is_dir<br />
	#267 - correction of the taking into account of the language in FCKeditor<br />
	#268 - NEW: the Banners function becomes bilingual<br />
	#269 - correction of the management of the rights on the plugins for the writers<br />
	#271 - correction for the use of the quotes in the categories<br />
	#272 - replacement of the functions of family EREG depreciated starting from PHP 5.3<br />
	#273 - suppression of the popup vacuum in the blog, when the option \"To mask the address enamel\" is activated<br />
	#274 - correction of many files for a better conformity with the recommendations of the W3C<br />
	#275 - addition of freebox in the home page<br />
	#276 - updated FCKeditor to release&nbsp; 2.6.4<br />
	#278 - addition of images for the extension of files : pdf, doc, xls, ppt and OpenOffice<br />
	#279 - improvement of the tests on the URLS in General Config<br />
	#280 - improvement of the diary page in the event of erroneous parameters<br />
	#281 - impression of the central part of the pages with a dedicated stylesheet<br />
	#282 - improvement of duplication with creation of the new element after validation and not before<br />
	#283 - improvement of the test on REFERER it postguest.php<br />
	#285 - correction of management member of the blog in banner page<br />
	#287 - correction field not empty of FCKeditor<br />
	#288 - correction code of all blog boxes<br />
	#289 - correction css of head topic in thread.php, thanks Kamila<br />
	#290 - removal of first (or theard) column empty while displaying with two columns only<br />
	<br />
	<b>v4.6.9 - December, 25th 2008</b><br />
	- Correction of safety test in admin/inc/access.inc #232<br />
	- Correction of the test displaying the RSS icon en administration #231<br />
	- Function ShowBlock moved to inc/functions.php #221<br />
	- correction of the ShowBlock function<br />
	- Function SearchOption moved to inc/functions.php #219<br />
	- Correction of TestEmail function in admin/inc/nwlist.inc #226<br />
	- Correction of discrepancies in statistics #218<br />
	- Addition / correction of the statistics for the pages Blog and Admin #216<br />
	- improvement of the checking of the variable &#36;num in postguest.php #203<br />
	- Correction of the email used in the RSS #225<br />
	- Correction of the full page display mode of the blog #228<br />
	- Correction of the full page display mode of the forum #234<br />
	- improvement of the forum in case of subjec absent or archived #237<br />
	- Added calendar limitation in the blog from the first note till now #221<br />
	- Adde management of the non-existent pages of the blog #221<br />
	- Added checking of functions \"Recommend this site\" and \"Mail PHP\" #20<br />
	- Correction of items activation in the main menu #224<br />
	- Correction of some RSS feeds display #229<br />
	- addition of the field pubDate in flows RSS #240<br />
	- Added a test of security on the numeric parameters<br />
	- Added field URL of the site in the administration of the forum #241<br />
	- Many small corrections improving the compliance with W3C standards<br />
	- Improvement of the migration<br />
	- Optimization of the code of test of bank holidays<br />
	- Improvement of the function \"Add to favourite (suggestions box #156)<br />
	- Remembering of the entry in case of already used pseudonym (suggestions box #160)<br />
	<br />
	<b>v4.6.8 - May, 10th 2008</b><br />
	- corrected plugins list in admin/adminredac.php and admin/inc/plugins.inc<br />
	- modified select in inc/boxsearch.inc search engine in search.php<br />
	- put again dta of news (disapeared!) in inc/news.inc<br />
	- corrected link of popup dwnld in download.php<br />
	- added n° of topic, back to forum if no parameter in thread.php<br />
	- corrected HTTP_REFERER test, and supervision mails in postguest.php/mod_thread.inc<br />
	- corrected selecting comments in inc/bloglist.inc<br />
	- deleted parameterss of the link to global list in blog.php<br />
	- corrected mistakes of &#36;msg2 in admin/inc/members.inc<br />
	- corrected display of fortopic.php, inc/topblog.inc and topforum.inc<br />
	- corrected htmlentities management of FCKeditor<br />
	- remplacing include by include_once for funcrss in admin.inc and maintain.inc<br />
	- modified config2/config8.inc (generate automaticaly style.css if permitted)<br />
	- added create/erase subdirectory in upload.inc<br />
	- new release of pgeditor<br />
	<br />
	<b>v4.6.7 - April, 23th 2008</b><br />
	- don\'t display useless icons in administration<br />
	- corrected bad html tags in generic.htm<br />
	- correction bug writing message in tinymsg.php<br />
	- corrected search module<br />
	- corrected bad tags br in postguest.php<br />
	<br />
	<b>v4.6.6 - April, 14th 2008</b><br />
	- Corrected processing &#36;serviz31 in admin/inc/config5.inc<br />
	- correctes syntax errors in config6 et config7.inc<br />
	- W3C validation icons are now removable in config1.inc<br />
	- added select for categories in admin.inc<br />
	- corrected putBR() and putHR() functions for minieditor<br />
	- corrected language test in poll.php<br />
	- corrected include place of hpage.inc in pages/sample.php<br />
	- download possible if javascript not active et corrected caracteristics of the file in download.php<br />
	- deletion of useless clear:both et &lt;/p&gt; in links news and faq<br />
	- corrected cursor in photorama.php<br />
	- deleted useless quote in body tag of photoview.php<br />
	- modification of updateDBdtb (new field date in blog) in functions.inc<br />
	- created MAJ_BLOG.PHP to update the new field date of DBBLOG<br />
	- corrected notes select in blogcalendar.inc<br />
	- display error if a note isn\'t active in blog.php<br />
	- corrected width and display of titles in blog.php, blog, blogcat and bloglist.inc<br />
	- added attribute title in links of menu articles<br />
	- corrected couic of forum counter and test thread topic in postguest.php<br />
	- updated display of new and important in forum and thread.php<br />
	- corrected empty &#36;fieldmod, update fields for supervision in inc/mod_thread.inc<br />
	- move onload adjust of calendar height to calendar.php for W3C compatibility<br />
	- minimyzed search width in topblog and topforum.inc<br />
	- added urlencode using all WriteMailto() functions<br />
	- corrected hpage.js for display of news and last news<br />
	- optimisation of hpage et bpage.inc to extend customisation facility<br />
	- corrected days of the month in statcalc.inc<br />
	- corrected searching photos in boxsearch.inc<br />
	- corrected &#36;err test in error.php<br />
	- added header(\"HTTP/1.0 404 Not found\") when page not found, thanks eDada<br />
	- updated FCKeditor to release 2.5.1<br />
	<br />
	<b>v4.6.5 - December 5th, 2007</b><br />
	- Subscrition to newsletter with confirm message<br />
	- Added rich text in tinymsg to all members<br />
	- Corrected plugins list admin/plugins<br />
	- Corrected errored &amp;fieldd1 et &amp;admin915 in admin.inc, thanks JeanMi<br />
	- Better URLs input in config1<br />
	- Updated texte[4] in config2<br />
	- Corrected &#36;&#36;serviz[36] added space to &#36;serviz[31] in config5.inc<br />
	- discard useless &gt; in config6.inc<br />
	- Corrected border attribut in config8.inc<br />
	- Replacement of button by input class=bouton in nwllist.inc<br />
	- Corrected Collaborator select in attribdroits.inc<br />
	- Corrected language test in inc/boxpoll.inc<br />
	- Corrected item title in spécial box<br />
	- Added blog in inc/statcalc.inc<br />
	- Cancel useless flag in mobile<br />
	- Optimized display of last news (no display of the box if no news)<br />
	- Corrected mismatch display, delete display of read count if count unavailable in forum.php<br />
	- Changed headTop table by divs in hpage.inc, thanks JeanMi<br />
	- Corrected hardcoded itemsin download.php, boxsearch.inc, attribdroits.inc and upload.inc<br />
	- Added stop on illegal input in printfaq.php<br />
	- Auto adjustment of iframe height in inc/boxcal.inc<br />
	- Corrected bad define CHEMIN and secure access in tinymsg.php<br />
	- Corrected image display of stand alone note in blog.php<br />
	- added checking destroy all in admin/inc/maintain.inc<br />
	- added missing restriction to members in forum live<br />
	<br />
	<b>v4.6.4 - November 04, 2007</b><br />
	- fixed vulnerability of error.php found by irk4z<br />
	- fixed vulnerability of includes.inc found by irk4z<br />
	<br />
	<strong>v4.6.3 - August 30, 2007</strong><br />
	- new: added duplicate for article, blog, news, etc... in admin.inc, thanks JeanMi<br />
	- added administrator valivation for reaction on articles and blog comments<br />
	- Choice of newsletter is now in services config and test email server is optionnal<br />
	- you can display a plugin (or special box) in welcome page page, thanks JeanMi<br />
	- corrected links for supervision mails in postguest<br />
	- better mail test in newsletter.php and admin/inc/nwllist.inc<br />
	- corrected copyright in bpage.inc<br />
	- corrected mistake in dwnld.inc<br />
	- replacement of ouvrir and fermer par language strins in menus (articles, blog, faq, links and download)<br />
	- new strings in language files<br />
	<br />
	<strong>v4.6.2 - August 1st, 2007</strong><br />
	- corrected css-validator link in bpage.inc<br />
	- corrected screen_choice in hpage.inc<br />
	- corrected blog display and missing end of page in blogrss.php<br />
	- modification of select size in admin/inc/config6 and css rubr of config8.inc<br />
	- new email testing process in newsletter.php<br />
	- test email corrected in newsletter listing<br />
	- corrected insert of CSS for IE in pgeditor<br />
	- corrected DBNEWS item in functions.php<br />
	- corrected p tag in agenda.php and inc/boxreact.inc<br />
	- corrected some php short tags and bad xhtml tags forgotten<br />
	<br />
	<strong>v4.6.1 - July 3, 2007</strong><br />
	- corrected last message link in forum and fortopic.php<br />
	- corrected javascript in postguest.php<br />
	- corrected css attributes in config8.inc<br />
	- corrected padding for rubr class in style.css of each skin<br />
	- corrected bug in IE editor<br />
	- modification of test anti-theaf of cookie in includes.inc<br />
	- corrected thread modification in admin.inc<br />
	- corrected accentuated characters management in FCKeditor config<br />
	- corrected PathAbs() in functions.php<br />
	- corrected supervision mails in postguest.php<br />
	- added strip_tags for all scripts names wanted by icons menu<br />
	- added search for blog and comments in search.php<br />
	- updated e-mail checking in newsletter.php<br />
	- optimization of integrity check<br />
	- corrected bad link for articles in funcrss.php<br />
	- adding automatically new boxes (if needed) in boxes config<br />
	- corrected many bad xhtml tags</p>
<p>
	<strong>v4.6.0 - 15 fevrier 2007</strong><br />
	- NEW : Guppy has now it\'s own blog !!!<br />
	- new forum release more efficient, with it\'s own configuration page (with charter)<br />
	- edition of the posts by their respective authors and the admin/mod&amp;eacute;rateurs<br />
	- access to the fast administration for the collaborators<br />
	- added optionnal charter display in fortopic module<br />
	- standard XHTML compliance<br />
	- change TypeTool wysiwyg editor by FCKeditor, much in<br />
	- replacement of the admin mini-editor<br />
	- replacement of the wywiwyg editor of postguest<br />
	- new photo et photorama modules<br />
	- corrected display bug in download, faq and links modules<br />
	- corrected vulnerability of archbatch.php and nwlmail.php<br />
	- optional posting of the licence when downloading protected software<br />
	- more efficient accessibility and better management with javascript disabled<br />
	- choice of displayed page width (1024 or full size)<br />
	- choice of full width display for forum and blog<br />
	- correction of the calendar<br />
	- improvement of the boxes positions (on top, at the bottom, in the center, on the sides)<br />
	- management of the skins individualized and coupled with the boxes positions<br />
	- integrated management of the style sheet css (generation, modification)<br />
	- added plugins management rights for writers<br />
	- added disconnect/reconnect in user box with temporary save of your cookie<br />
	- contact webmaster via the majority of messengers software<br />
	- improved choice of the preferred message of the gold book in home page<br />
	- improvement of the characters accentuated treatment in the name/pseudo<br />
	- corrected php short tags for php5 compatibility</p>
<p>
	<strong>v4.5.19 - November 10 2007</strong><br />
	- correct error.php vulnerabilties discovered by rgod</p>
<p>
	<strong>v4.5.18 - April 1, 2007</strong><br />
	- correct FAQ member area<br />
	- correct links mailto in Recommend and Webmaster contact mails<br />
	- correct display bug of poll section in case of a second vote with IE<br />
	- correct a link in the mobile version<br />
	- Pseudo is readonly when you modify your account. In other case a new member is create.<br />
	- Delete in admin counters the text over central box wich don\'t need to be here<br />
	- correct function PathToImage()<br />
	- correct 30 or 31 february display in calendrar<br />
	<br />
	<strong>v4.5.17 - 31 Janvier 2007</strong><br />
	- correction vulnerability of error.php found by rgod<br />
	- correction boxcal.inc</p>
<p>
	&nbsp;</p>
<p>
	<span style=\"font-weight: bold;\">v4.5.16 - January 28, 2007</span><br />
	- correct function PathToImage()<br />
	- correct news.inc<br />
	- correct download.php - faq.php - links.php<br />
	- add function IncrNextID() to avoid crushing an old document at the time of the creation of a new document<br />
	<br />
	<span style=\"font-weight: bold;\">v4.5.15 - 27 January 2007</span><br />
	- correction in case of one element in article in the left article box.<br />
	- correct the invertion between creation and modification in FAQ<br />
	- correct news in secund language<br />
	- correct photorama for inbriqued galery<br />
	- correct calendar box show if agenda is not activated.<br />
	- correct postguest to disalow pust in unactivated services.<br />
	- correct dwnld.php (&amp;serviz[10] instead of &amp;serviz[35])<br />
	- improvement of list of the subscribers to the neswletter<br />
	- presentation of the most recent subscribers at the beginning of list<br />
	- possibility of multiple deletions in only one action<br />
	- presentation of the list by page of a maximum of 25 subscribers<br />
	- correct tinymsg.php (deletion of the maxlength=&amp;quot;10&amp;quot;)<br />
	- improvement of the PathToImage function to also correct the urls links</p>
<p>
	<strong>v4.5.14 - Mai 19, 2006</strong><br />
	- updating errors of 4.5.13 patch</p>
<p>
	<strong>v4.5.13 - Mai 19, 2006</strong><br />
	- correction of the files download.php, faq.php, links.php and news.inc<br />
	- correction of the test prohibiting the use of the pseudo &amp;quot;Your Name&amp;quot; in newsletter.php<br />
	- replacement of getenv(&amp;quot;HTTP_USER_AGENT&amp;quot;) by &amp;_SERVER[&amp;quot;HTTP_USER_AGENT&amp;quot;] in includes.inc<br />
	- suppression of the posting of the reactions for the non-members in articles.php<br />
	- correction of posting in photorama.php<br />
	- correction of the activation of news RSS in hpage.inc<br />
	- correction of the agenda for the second language<br />
	- improvement of the search engine to respect the restrictions &amp;quot;members&amp;quot;</p>
<p>
	<strong>v4.5.12 - March 9, 2006</strong><br />
	- correction vulnerability of dwnld.php found by kapda.ir</p>
<p>
	<strong>v4.5.11 - December 25, 2005</strong><br />
	- correction second language in search.php<br />
	- correction of the initialization of the parameters of the anti-spam<br />
	- correction of the forced color with white for the icon &amp;quot;minus&amp;quot; of the downloads<br />
	- correction of a test in the admin of the diary/calendar<br />
	- standardization of the pages downloads, links and faq<br />
	- filling of the cells of the calendar beyond the last day of the month<br />
	- addition of a warning for the administrator when its site is in work<br />
	- addition of controls in case of files docXXX.inc absent, empty or corrupted<br />
	Suggestions box n&amp;deg;63<br />
	- interdition of the indexing of the error and newsrss pages by the robots<br />
	Suggestions box n&amp;deg;48<br />
	- suppression of the underlining of the current page in the bar of navigation<br />
	Suggestions box n&amp;deg;64<br />
	- addition of the text of the response on a subject of the forum in the mall of follow-up of a subject<br />
	Suggestions box n&amp;deg;46<br />
	- correction of the return systematically in principal language at the time of the inscription of a visitor<br />
	Suggestions box n&amp;deg;70<br />
	- addition of a posting unfolded when one reaches only one page of downloads (by &amp;pg=99)<br />
	- addition of a posting unfolded when one reaches only one page of links (by &amp;pg=99)<br />
	- addition of a posting unfolded when one reaches only one page of faq (by &amp;pg=99)<br />
	Suggestions box n&amp;deg;28<br />
	- addition of the choice of the state (active or not) of the elements created in admin.</p>
<p>
	<strong>v4.5.10 - November 29, 2005</strong><br />
	- correction of 5 vulnerabilties by rgod</p>
<p>
	<strong>v4.5.9 - November 27, 2005</strong><br />
	- correction of the selector of colors<br />
	- correction of the menus articles under FireFox<br />
	- minor corrections in many files<br />
	- improvement of the archiving of the forum and the control of integrity<br />
	- improvement of postguest.php</p>
<p>
	<strong>v4.5.8 - October 16, 2005</strong><br />
	- correction in postguest.php (add the missing break)</p>
<p>
	<strong>v4.5.7 - October 8, 2005</strong><br />
	- correction of the poll<br />
	- improvement of the mechanism anti-spam<br />
	- addition of the parameter setting of the mechanism anti-spam<br />
	- correction of a input tag not closed in admin.php<br />
	- correction of a head tag badly placed in calendar.php<br />
	<br />
	<strong>v4.5.6a - September 28, 2005</strong><br />
	- correction of printfaq.php</p>
<p>
	<strong>v4.5.6 - September 27, 2005</strong><br />
	- correction of a vulnerability &amp;quot;file transverse flaw&amp;quot; in printfaq.php<br />
	- correction of the error count during the control of integrity in batch<br />
	- correction of two spelling mistakes in fr-admin.inc<br />
	- improvement of the editor (meta and script) and the preview (flash)</p>
<p>
	<strong>v4.5.5 - September 10, 2005</strong><br />
	- correction of the admin. pages of the counters<br />
	- correction of the newsletter (addition of the charset)</p>
<p>
	<strong>v4.5.4 - September 6, 2005</strong><br />
	- correction of two faults of safety (error.php and printfaq.php) Thank you Romano<br />
	- final correction of the diary/calendar (see readme_agenda.txt)<br />
	- final correction of the editor</p>
<p>
	<strong>v4.5.3a - 30 August 2005</strong><br />
	- correction of the diary into admin/inc/admin.inc</p>
<p>
	<strong>v4.5.3 - 27 August 2005</strong><br />
	- correction of the path of the file RSS (addition of data) thank you Tanet<br />
	- correction of the diary/calendar<br />
	- correction of the editor (taken into account of the path images, conversion n &lt;=&gt;<br />
	into entry and exit)<br />
	- correction of General Config (suppression of : = &amp;quot;&amp;quot; // Libre)<br />
	- correction of the couic putting the number of answers of the forum at 0 during physical suppressions<br />
	- improvement of the shortened news (now in HTML)<br />
	- standardization of the bar of navigation (files of the forum and &amp;quot;mobile&amp;quot; part)<br />
	- improvement of the control of integrity by batch<br />
	- addition of a mechanism anti-spam for all the posts</p>
<p>
	<strong>v4.5.2 - 23 July 2005</strong><br />
	- configuration in Config.Services of the number of files to be preserved in data/error<br />
	- configuration in Config.Home of the number of characters of the news<br />
	- correction of the class CSS of the categories on Download page and Links<br />
	- correction of the class CSS of information (dates, counter...) on Articles page<br />
	- correction of the path for the correct operation of the &amp;quot;shortcut ico&amp;quot;<br />
	- simplification of the selector of image which accepts the sub-directories recursively of img and photo (removal of the files listimg1.php and listimg2.php)<br />
	- addition automatic of &amp;quot;/&amp;quot; final of the URL of the site<br />
	- improved the e-mails of supervision of the newsletter (e-mail in HTML + links usable)<br />
	- correction of the path of the image used by the plugin speed .<br />
	- suppression of the r forgotten in inc/mail/standard_2.inc and inc/mail/standard_3.inc</p>
<p>
	<strong>v4.5.1 - 07 July 2005</strong><br />
	- Corrected collapsed categories list in photorama<br />
	- optimized RSS news: new display with ceating date (thanks Tanet)<br />
	- corrected mail sending process where needed in many scripts<br />
	- corrected inverted summary between Italic and Underline in TypeTool editor<br />
	- corrected a typing mistake and modified some pathes in postguest editor (thanks Djchouix)<br />
	- Corrected writer connexion (it was able even if Writer option not checked!)<br />
	- Corrected eMailHtmlTo() function to include real sender in webmaster mail and recommend)<br />
	<br />
	<strong>v4.5.0 - 4 May 2005</strong><br />
	- Display managements lists with 25 items a page<br />
	- Select actions by check boxes and global execution for all the page<br />
	- Separate manager and writer connexion and better multi-management<br />
	- New search engine with direct display of items found<br />
	- Extension of quick management to all scripts<br />
	- Checking tinymsg addresses to prevent mail usurpation<br />
	- Partial news on home page (with &amp;quot;see more&amp;quot;)<br />
	- Dowload, links and FAQ updated as Nicolas\'s fork<br />
	- Now the articles boxes stay opened on the selected article<br />
	- Optimization admin editors (popup option) and easier insert of others editors<br />
	- Added preview in admin mini-editor<br />
	- Optimization postguest editor (newline, forbidden tags, cite, code, preview...)<br />
	- Corrected second language of the calendar, today highlighted only for current date<br />
	- Added &amp;quot;alt&amp;quot; (thanks Hubby) and title on calendar days<br />
	- On the calendar, clicking month name displays month planner, day displaying a summary of an event<br />
	- Corrected Planner: displaying events of current month year+1 in now correct<br />
	- Compatibility with new PHP releases (whatever are &amp;quot;register_globals&amp;quot;, register_long_array&amp;quot;, &amp;quot;register_notice&amp;quot;)<br />
	- Better security in icludes ans constants<br />
	- Possible flash banners<br />
	- Supervision mails with HTML tags<br />
	- Sending mails in multi-formant (text + HTML).<br />
	- New webmaster mail and optimized recommendation<br />
	- Added reading link on supervision mails<br />
	- Newsletter with HTML tags<br />
	- Style ans skins optimized by using more div ans css</p>
<p>
	<b>v4.0 - 06 December 2004</b><br />
	- New WYSIWYG editor also running with Mozilla and sons... for admin articles.<br />
	- Different admin levels<br />
	- Admin icon in content for quick access on all document (for webmaster only)<br />
	- optional members management<br />
	- forum and guestbook posts submitted to administrator<br />
	- form to write to the webmaster<br />
	- agenda integrated with new calendar<br />
	- title different on each page<br />
	- new tiny messages manager<br />
	- new tiny WYSIWYG editor for forum, news, guestbook...<br />
	- more efficient counters management<br />
	- Best looking forum, and so for all other pages<br />
	<br />
	<b>v3.0p4 - September 06 2004</b><br />
	- limitation of the size of the inputs of the visitors<br />
	<br />
	<b>v3.0p3 - July 29 2004</b><br />
	- solved a security issue (found by L0rd L4m3R)<br />
	<br />
	<b>v3.0p2 - 9 April 2004</b><br />
	- Compatibility fix: now GuppY is fully compatible with Abyss webserver, KF Web Server, IIS and probably with other web servers (thanks Kromonos and lordloose)<br />
	- removed 2 debug information lines forgotten during v3.0 development in the Search script (thanks Realia)<br />
	- bug fix in the CSS style sheet (thanks Ouly)<br />
	- bug fix in the GuppY skins which fooled Netscape (by Icare)<br />
	- corrected the demo database in which some documents had parasitic \"\" characters<br />
	- removed the empty URL link display in the reaction box (thanks Realia)<br />
	- corrected \"adress\" typo mistake to \"address\" in admin minieditor (thanks JeanMi)<br />
	<br />
	<b>v3.0p1 - 26 February 2004</b><br />
	- bug fix (appeared with v3.0) in migration from v2.3 to v2.4, now migrates correctly the doc[n].inc files<br />
	- bug fix, now checks e-mail correctly in the VerifyForm() function in user preferences<br />
	- bug fix, now includes Protomail class only once in the Free.fr mail() management<br />
	- ergonomic fixes in the e-mails sent when a user subscribes to the newsletter<br />
	- bug fix, if no icons set selected, then do not display news image in the RSS news module<br />
	- include only once reglobals if required (time saving when in admin)</p>
<p>
	<strong>v3.0 - 25 February 2004</strong><br />
	- added a &amp;quot;skins&amp;quot; themes system for boxes (by Nicolas Alves and Laurent Duveau). Thanks to Ricsen for designing the submit buttons<br />
	- added a newsletter functionality with inscription form (by Nicolas Alves and Laurent Duveau)<br />
	- added a logbook monitoring admin tool (by B@lou, Nicolas Alves and Laurent Duveau)<br />
	- date format display fix in the mobile forum script (by B@lou)<br />
	- added possibility to put all boxes on the right side in the user preferences<br />
	- added GuppY copyright information on all pages because too many people were hiding that their website was built with GuppY or were definitely usurping the copyright <img alt=\"confused\" src=\"inc/img/smileys/confused.gif\" />.<br />
	- pages compression introduced in v2.4 is now an admin option<br />
	- created a plugins management system to ease the integration of plugin scripts to GuppY<br />
	- changed sample external files to plugins<br />
	- added 2 new options for dynamic list menu (thanks Graznok and Icare)<br />
	- added UID management for Tiny Messages<br />
	- added check for &amp;quot;(&amp;quot;, &amp;quot;)&amp;quot; and &amp;quot;;&amp;quot; characters to avoid Javascript pollution attempts in URL input for guestbook (security improvement)<br />
	- added check for too long words (to avoid display misalignment) in user posts, in tiny messages and in user preferences<br />
	- Compatibility with php.ini register_globals=off parameter (thanks JonnyQuest)*<br />
	- Friendly thanks (but late... because I had forgotten where I had found it!) to Pascal aka &amp;quot;Le Sorcier&amp;quot; (http://lesorcier.free.fr) for the miniportail_1 counter images set (the very first set, included as from version 1.0!)<br />
	- also added a new progress bar for pages loading from Pascal aka &amp;quot;Le Sorcier&amp;quot; as well as another one which I do not remember where I found it...<br />
	- new batch processing option for the database integrity check<br />
	- fixed a bug in the DB integrity check that was so tricky that I just cannot find words to describe it...<br />
	- added check for valid forum category in user posts (security enhancement)<br />
	- new forum archiving and displaying of this archive module (please note that the search module does not scan the archived forum threads)<br />
	- added an option for a &amp;quot;Please Wait...&amp;quot; message while a post is being processed and a check to avoid redundant posting (thanks Icare)<br />
	- added a new pages/ directory to put external webpages in (instead of putting them in file/ rather dedicated to files downloads)<br />
	- simplified language switch source code in the language selection box<br />
	- added focus in tiny message input area (by B@lou)<br />
	- fixed bug in search non working for News and Photos<br />
	- news are now be published in the RSS standard Web content syndication format instead of a GuppY specific format (thanks Palmipod). This module uses the great GPL licensed lastRSS 0.6 PHP class to parse RSS files (by Vojtech Semecky, webmaster@webdot.cz, http/lastrss.webdot.cz/)<br />
	- added an links animation effect option (thanks reddog)<br />
	- replaced &amp;REQUEST_URI global variable by &amp;SCRIPT_NAME for IIS compatibility (thanks Erik)<br />
	- changed &amp;web30 and &amp;web115 labels for better understanding (thanks FabriceV)<br />
	- added Title meta tag management (thanks Tanet and Realia)<br />
	- upgraded the printable version of articles (thanks tuture and B@lou)<br />
	- bug fix in the user preferences that would hide forum signature in a very specific case (thanks bugs974)<br />
	- automated return after posting (thanks Icare)<br />
	- added 2 new PHP mail() functions standard formats<br />
	- thanks to Realia for correcting the French spelling of the lisezmoi.txt file and to Neil for correcting my English in this readme.txt file<br />
	- thanks to Realia for upgrading the demo database<br />
	- thanks to the GuppY Team members for their hard beta testing!<br />
	- first developed plugins in addition to the sample plugins:<br />
	- live chat plugin (by Nicolas Alves) - NOTICE: separate download<br />
	- postcards plugin (by Nicolas Alves) - NOTICE: separate download<br />
	- radios plugin (by Nicolas Alves) - NOTICE: separate download<br />
	- music plugin (by Nicolas Alves) - NOTICE: separate download</p>
<p>
	<strong>v2.4p4 - 4 October 2003</strong><br />
	- Various security corrections (by frog-m@n, http://www.phpsecure.info, thanks)</p>
<p>
	<strong>v2.4p3 - 29 September 2003</strong><br />
	- upgraded the ob_gzhandler functionality (compression of pages), now is done only if relevant (do not trust PHP and browsers anymore)<br />
	- added an e-mail add-on for standard PHP mail() function, allowing to send follow-up e-mails to more than one receiver</p>
<p>
	<strong>v2.4p2 - 28 September 2003</strong><br />
	- bug correction = some users were suffering from very slow displaying of webpages, it is fixed now (thanks Nicol@s and Arnaud)<br />
	- bug correction = counter follow-up e-mail sends back counter value<br />
	- bug correction = buttons bar would not appear correctly (centered instead of left aligned) if Stats button was not displayed (Thanks Raiponce)<br />
	- Translation upgrade = upgraded a French string (thanks FabriceV)<br />
	- bug correction = the search engine would return no answer if the site was monolingual (thanks Laorens)<br />
	- XSS security correction in the posting module (by Das, http://www.echu.org, thanks)</p>
<p>
	<strong>v2.4p1 - 26 September 2003</strong><br />
	- bug correction = now free.fr script works<br />
	- bug correction = now the Stats module counts back the Number of Visitors<br />
	- bug correction = now [ back] works after forum thread posting<br />
	- bug correction = in mobile version, if no site logo, HTML code is now good (thanks Miche)<br />
	- bug correction = some users could not post messages in the guestbook or forum, it is fixed now</p>
<p>
	<strong>v2.4 - 24 September 2003</strong><br />
	- added &amp;quot;Page loading&amp;quot; popup<br />
	- visitors counter now increments even if counter box not displayed<br />
	- show pseudo of users online<br />
	- added an icon for articles and news<br />
	- added Search in one language only option<br />
	- added a new smileys theme<br />
	- added section icon in central boxes<br />
	- added forum summary on home page (last messages)<br />
	- moved homepage parametrization from General config to Services config<br />
	- added Guestbook\'s favourite message on home page<br />
	- added homepage\'s choice of central boxes (homepage box, last news box, forum in live box, favourite guestbook message box)<br />
	- added a Config homepage icon in admin<br />
	- changed mailto box to default pages\' background color (no more white background)<br />
	- split dynamic menu line if line too long<br />
	- renamed Left and Right Articles boxes to 1st and 2nd Articles boxes<br />
	- added react to an article option<br />
	- added character set management in all parts it was forgotten: editor, table, special characters, e-mail popup, image picker (thanks Pavol)<br />
	- replaced &amp;quot;Webpage Preview&amp;quot; string in the editor by string translated in the adequate language<br />
	- upgraded the image picker<br />
	- added access to the Image Picker in the admin basic editor<br />
	- corrected a bug in the mobile version: the showing of articles for each of the 2 articles boxes is now fine (thanks Hubert)<br />
	- added alternative label for language flag images<br />
	- added alternative label for site\'s logo image (name of the site)<br />
	- fixed a bug in the DB integrity check that occured when the last document was created but not recorded in the indexes<br />
	- changed the tile of the &amp;quot;Webmaster/Site Info&amp;quot; box by the shorter &amp;quot;Webmaster&amp;quot; (thanks Realia)<br />
	- dynamic menus are now centered in articles boxes (thanks Pavol)<br />
	- smileys now appear when content\'s text needs to be displayed in the admin\'s documents list (thanks Pavol)<br />
	- added a new &amp;quot;windy&amp;quot; counter set (thanks C&amp;eacute;sar) and a new &amp;quot;sunflower&amp;quot; counter set (thanks Realia)<br />
	- the information of box belonging (1st or 2nd) given for articles in the admin\'s documents list (thanks Pavol)<br />
	- added option for choosing Articles mark in articles boxes (thanks Pavol)<br />
	- added Hide Admin Button (by Nicolas Alves)<br />
	- added Quick Article Admin Access (by Nicolas Alves)<br />
	- &amp;quot;Become a member&amp;quot; button label becomes &amp;quot;Your preferences&amp;quot; if user registered (by Nicolas Alves)<br />
	- show user name in the user box option (by Nicolas Alves)<br />
	- registered users can decide if they wish to appear in the online users list or not (by Nicolas Alves and Laurent Duveau)<br />
	- tiny messages can be sent to online registered users (by Nicolas Alves and Laurent Duveau)<br />
	- added number of times an article was read (by Nicolas Alves and Laurent Duveau)<br />
	- added number of times a forum thread was read (by Nicolas Alves and Laurent Duveau)<br />
	- added number of times a file was downloaded (by Nicolas Alves and Laurent Duveau). This counter does not work with the mobile version.<br />
	- added backup counter for next forum thread number<br />
	- upgraded eMailTo() function to accept additional specific e-mailing according to providers<br />
	- added the &amp;quot;-f&amp;quot; parameter in the e-mail sending function (thanks Michel)<br />
	- the eMailTo() functions works for the Free.fr webhoster (with the use of the Protomail library, GPL licensed)<br />
	- added forum personalized signature for registered users<br />
	- call to documents in database is no more done through an include() PHP function call but through a ReadDoc() dedicated function<br />
	- fully reviewed all the Read &amp; Write files access functions<br />
	- added category ordering information for FAQ<br />
	- added GetCurrentDateTime() and FormatDate() functions to ease various date and time formatings<br />
	- added new date formats and created time formats<br />
	- important source code upgrade in the inc/config[n].inc scripts<br />
	- added lookup for png and bmp images in IsImage() function<br />
	- removed style sheet CSS from inc/hpage.inc and put it in a new inc/style.inc file<br />
	- corrected a bug in the search script which would always say that articles found were in the 1st box (thanks Pavol)<br />
	- for faster output, pages are compressed before being sent to the web browser (for websites running PHP &gt;= 4 and for web browsers which are able to work with compressed pages)<br />
	- secured command line parameters (Secunia Advisory: SA9621 about the lng parameter)<br />
	- added 3 additional free boxes (by Nicolas Alves and Laurent Duveau)<br />
	- made many changes in all scripts to decrease size of database files<br />
	- NAME CHANGED : MINIPORTAIL BECOMES GUPPY</p>
<p>
	<strong>v2.3p1 - 03 August 2003</strong><br />
	- corrected bug in which next page link button in mobile news was wrong (thanks airhero)<br />
	- bug correction: replaced include(&amp;quot;minieditor.inc&amp;quot;) by include(&amp;quot;inc/minieditor.inc&amp;quot;) in admin.inc (thanks Eddie)</p>
<p>
	<strong>v2.3 - 27 July 2003</strong><br />
	- added dynamic/list menu option<br />
	- user news post: even if written in one language, put the news in both languages (until the webmaster translates it)<br />
	- added three new smileys themes<br />
	- added two new icons themes (thanks B@lou and Florent)<br />
	- added case of only ONE news displayed on homepage (thanks Laurent Roger)<br />
	- added direct jump to pages (by Nicolas Alves and Laurent Duveau)<br />
	- changed from &amp;quot;tutoiement&amp;quot; to &amp;quot;vouvoiement&amp;quot; in the French language strings (thanks Realia)<br />
	- minor font and text formating changes in search, quotations, general pages (thanks Realia and Nicolas)<br />
	- fixed security issue (thanks frog-m@n)<br />
	- fixed install script bug that would not launch home page when install files are erased<br />
	- added a &amp;quot;no logo&amp;quot; option<br />
	- WYSIWIG editor highly upgraded (by Nicolas Alves)<br />
	- added a calendar box (by Nicolas Alves and Laurent Duveau)<br />
	- option for choosing the number of items to display in news, forum threads, links, downloads, FAQ and Guestbook moved from Site Config to Services Config<br />
	- homogenized central and lateral boxes rendering<br />
	- bug correction: accepts e-mails like &amp;quot;firstname-lastname@site.com (accept &amp;quot;-&amp;quot; character). The check for the e-mail is not as exhaustive as it used to be but it checks for most bad input cases<br />
	- added quotations style management (by Nicolas Alves and Realia)<br />
	- added forms style management (by Nicolas Alves)<br />
	- removed link on counter\'s numbers in counter box<br />
	- changed from unformal &amp;quot;you&amp;quot; to polite &amp;quot;you&amp;quot; in the French version of this readme.txt file (by Realia)<br />
	- added a first lever of user preferences management by cookie<br />
	- added US date format management (thanks to Julien and to Realia for relaying the information)<br />
	- added choice for letting visitors submit news or not<br />
	- added search focused on one category (forum, articles, news...)<br />
	- added a manual maintainance form for changing characteristics of a document (creation and modification dates, author and e-mail)<br />
	- added basic editor capabilities for user input and in admin area (by Nicolas Alves and Laurent Duveau)<br />
	- smileys are now inserted at cursor position and no more at the end of text<br />
	- removed automated ErrorDocument management in .htaccess file for Apache servers (thanks Miche)<br />
	- upgraded WriteMailTo() function for better SPAM protection (thanks Michel)<br />
	- bug fix, papers from right articles boxes would not appear when left articles boxes was not active<br />
	- developed a GuppY extension adapted to Palm display capabilities (thanks Palmipod). Furthermore, this light display version is adequate for our blind friends who can now easily read a GuppY web site (thanks Hubert)<br />
	- images in side boxes are now always seen even if in the admin area (thanks Realia)<br />
	- added charset meta tag in the HTML print friendly version of articles (thanks Pavol)<br />
	- upgraded the d\'installation / migration script<br />
	- added two new sample external scripts which integrate with GuppY (by Realia)<br />
	- if no category for an article, remove parenthesis in print friendly version of the article (thanks Realia)<br />
	- added an external script example integrated with GuppY which displays the news of the aldweb Site<br />
	- changed the order of Admin icons from a French alphabeutical sorting to one wanted to be more logical (thanks <a href=\"mailto:B@lou\">B@lou</a>)</p>
<p>
	<strong>v2.2 - 18 APril 2003</strong><br />
	- bug fix: &amp;quot;Times New Roman, serif&amp;quot; instead of wrong &amp;quot;Time New Roman, serif&amp;quot; (thanks Realia)<br />
	- bug fix: now current hour stats are also reset when required in Admin<br />
	- added thread message being answered to for reminder in<br />
	ipstats.dtb et ippoll.dtb<br />
	- changed source code for all accesses to the foreach() PHP function for compatibility with PHP3 as foreach() only works with PHP4<br />
	- changed source code for all accesses to the pathinfo() PHP function for compatibility with PHP3 as pathinfo() only works with PHP4<br />
	- renamed all &amp;service[] variables to &amp;serviz[] (for strange compatibility problems with some local Linux, the Mandrake one if I remember well)<br />
	- automatic directory change in Upload area (no more need to press a button for changing of directory)<br />
	- click on text formating tag copies tag to text in user post form<br />
	- new color selector in Site Config (by Nicolas Alves)<br />
	- added a WYSIWYG editor for content in Admin area (by Nicolas Alves, who worked from a script basis whose original author is very badly unknown =&gt; we would have loved to ask for his approval and to thank him!)<br />
	- some cleanup in the images organization has been made<br />
	- rewrote the install script which is now a real clean install and migration script</p>
<p>
	<strong>v2.1 - 10 March 2003</strong><br />
	- fixed bug where Site URL and Meta Identifier URL were inverted<br />
	- fixed a bug in which Javascript functions could lead to errors if single quotes were passed to these Javascript functions<br />
	- click on smiley copies smiley to text (by Nicolas Alves)<br />
	- management of 40x errors (for Apache web server only)<br />
	- added a counter theme management (by Nicolas Alves)<br />
	- added a color management for the side scroll bar (by Nicolas Alves)<br />
	- focus on first field in input forms (by B@lou &amp; Laurent Duveau)<br />
	- fully rewrote the database integrity check and repair module</p>
<p>
	<strong>v2.0 - 27 February 2003</strong><br />
	- bug correction of the data validation in the user input forms<br />
	- set background color to transparent for the About and DB Check icons<br />
	- added metatags management (by Nicolas Alves &amp; Laurent Duveau)<br />
	- added fixed background image option (thanks Maxrebo)<br />
	- site logo is no more a must, you can set up a site without a top left image logo now<br />
	- the admin cookie is now automatically unactivated when closing the browser, no more a 24 hours survival duration (thanks Marc)<br />
	- photos: corrected image file size calculation and merged the two boxes for photo displaying into one single box<br />
	- added three new icons themes, one was made by B@lou<br />
	- upgraded the Icon themes management (thanks Alex)<br />
	- added auxiliary indexes rebuild in index database rebuild<br />
	- added freebox and photo search<br />
	- added links to jump back in thread and forum (by Alex)<br />
	- removed input form on postguest form return &amp; added back button to it<br />
	- added a Go back to Top of page link at bottom of pages<br />
	- added slogan display (thanks &amp;szlig;ugs)<br />
	- added a more sophisticated photo display management (with photo description)<br />
	- added fortopic.php log (I forgot it in v1.9) and photorama.php log in Stats Log<br />
	- added a system for e-mail addresses encryption (protection against SPAM) even though they appear fine on the browser\'s window</p>
<p>
	<strong>v1.9 - 11 February 2003</strong><br />
	- added update of statsbk.dtb and reset of ipstats.dtb when the visits counter value is manually modified<br />
	- in the admin services selection, category for forum presentation was slighly changed for showing better that it is a sub option of Forum area<br />
	- forum category added in the supervision e-mail sending<br />
	- a few minor bugs were fixed<br />
	- added a banners management<br />
	- added an extra box (so called \'free box\')<br />
	- added an \'about\' popup window<br />
	- database integrity check tool<br />
	- added an icons theme management</p>
<p>
	<strong>v1.8 - 05 February 2003</strong><br />
	- changed the title\'s text for forum thread in admin (the text was not correct)<br />
	- title removed from Forum answers (was not needed and increased database size)<br />
	- corrected bug where search result to forum thread would go in error<br />
	- put back in inc/img/ the smileys that were removed by mistake in version 1.7<br />
	- bug correction in the eMailTo() function call, in counter box and visit<br />
	language without going back to index page (thanks Alex)<br />
	- changed a PHP function call to have GuppY compatible with PHP version &lt; 4.1.0<br />
	- &amp;quot;invisible&amp;quot; bug fixed in search box</p>
<p>
	<strong>v1.6 - 23 January 2003</strong><br />
	- new languages available: Spanish and Dutch<br />
	- improved translation: Anglais<br />
	- added a popup window to help choosing RGB colors<br />
	- slightly updated the supervision e-mail formating sent for guestbook<br />
	- added news publishing option for external sites (please refer to getmpnews.php script file)<br />
	- added transition effect option between pages (for IE browser only, no effect on the other browsers)<br />
	- display 10 forum messages rather than 5<br />
	- added option to let poster choose to hide or show his e-mail address on the site<br />
	- corrected bug that would not save ICQ number when it was entered<br />
	- added timer &amp;quot;page loaded in n.nn seconds&amp;quot; information<br />
	- wrote a migration script from version 1.5 to version 1.6</p>
<p>
	<strong>v1.5 - 10 January 2003</strong><br />
	- remplaced the Lynx and WebTV browsers by iCab and DA<br />
	- upgraded the counter by creating a backup of its value in case it would be accidentaly deleted<br />
	- remplaced Hits by Visitors in the Stats module<br />
	- URL of guestbook posters now opens in a new broser\'s window</p>
<p>
	<strong>v1.4 - 07 January 2003</strong><br />
	- upgraded the sent text in the supervision e-mails (stripslashes) for easier reading<br />
	- the counter supervision e-mail is now only sent one time<br />
	- upgraded the Stats module by creating one log file per hour (to avoid loosing too much data in case this file was accidentaly erased)<br />
	- bug correction in tracking hits<br />
	<br />
	<strong>v1.3 - 06 January 2003</strong><br />
	- bug correction in the Stats module (news, links, photos, poll, search and stats were counted as index)<br />
	- corrected version number of GuppY in the header of the readme.txt file<br />
	- added supervision services (the web site sends e-mails to the webmaster)<br />
	- use databases frth.dtb and forum.dtb introduced with v1.2 for quicker work on forum threads posts</p>
<p>
	<strong>v1.2 - 5 January 2003</strong><br />
	- upgraded the displaying speed of all pages by creating an intermediate table that holds the information needed by the articles box<br />
	- accelerated the displaying speed of the Forum option<br />
	- fully rewrote the Statistics option that prooved to be much too slow for a web site that would have more than about 10 visitors per day.</p>
<p>
	<strong>v1.1 - 2 January 2003</strong><br />
	- patch to avoid users to add records simultaneously on the same files (main problem found in the Stats)<br />
	- Users Post forms\' look &amp; feel upgraded (was not be beautiful for screen resolution inferior to 1024x768)</p>
<p>
	<strong>v1.0 - 30 December 2002</strong><br />
	- initial release</p>
');
$fieldd1 = stripslashes('left');
$fieldd2 = stripslashes('gyslogo.gif');
$fieldweb = stripslashes('');
$fieldmail = stripslashes('');
$fieldmod = stripslashes('');
