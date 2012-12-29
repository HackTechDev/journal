<?php
/*
    Web Language Strings - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v1.0 (30 December 2002)     : initial release
      v1.1 (02 January 2003)      : various strings updates and add-ons
      v1.2 (05 January 2003)      : various strings updates and add-ons
      v1.3 (06 January 2003)      : various strings updates and add-ons
      v1.4 (07 January 2003)      : various strings updates and add-ons
      v1.5 (10 January 2003)      : various strings updates and add-ons
      v1.6 (23 January 2003)      : various strings add-ons
      v1.7 (28 January 2003)      : various strings add-ons
      v1.8 (05 February 2003)     : various strings add-ons
                                    added charset management
      v1.9 (11 February 2003)     : various strings add-ons
      v2.0 (27 February 2003)     : various strings updates and add-ons
      v2.1 (10 March 2003)        : replaced all \' occurrences by ' (now managed by Javascript functions calls)
                                    various strings updates and add-ons in Admin
      v2.2 (22 April 2003)        : various strings updates and add-ons
                                    split of file in two xx-web.inc and xx-admin.inc for faster loading
      v2.3 (27 July 2003)         : various strings updates and add-ons
      v2.4 (24 September 2003)    : various strings updates and add-ons
      v2.4p2 (28 Sept. 2003)      : upgraded $web121 (thanks FabriceV)
      v3.0 (25 February 2004)     : various strings updates and add-ons
      v4.0 (06 December 2004)     : added new strings and add-ons (by Icare - Nico)
      v4.5 (04 april 2005)        : added new strings and add-ons (by Icare - Nico - Jean-Mi)
      v4.6.0 (04 June 2007)       : added new strings and add-ons (by Icare)
      v4.6.3 (30 August 2007)     : added new strings (by Icare)
      v4.6.5 (05 December 2007)   : added new strings (by Icare)
      v4.6.9 (25 December 2008)   : added new strings (by JeanMi)
      v4.6.14(14 February 2011)   : added $web435 (thanks JeanMi)
      v4.6.15 (30 June 2011)      : added new strings (by Icare)
	  v4.6.16 (02 September 2011) : various strings updates and add-ons
	  v4.6.17 (21 October 2011)   : various strings updates and add-ons (by Laroche)
                                    correcting mistakes (by Corrector)
      v4.6.18 (09 February 2012)  : added new strings,various strings updates (by Saxbar, Papinou)
	  v4.6.22 (29 December 2012)  : corrected $web406 (thanks Laroche)
*/

if (stristr($_SERVER["SCRIPT_NAME"], "fr-web.inc")) {
  header("location:../index.php");
  die();
}

$charset = "iso-8859-1";

$web1 = "Bienvenue sur";
$web2 = "Les";
$web3 = "dernières nouvelles";
$web4 = "Poster une nouvelle";
$web5 = "Texte à méditer :";
$web6 = "par";
$web7 = "le";
$web8 = "Votre langue pour l'interface :";
$web9 = "Vote !";
$web10 = "Résultats";
$web11 = "Webmestre";
$web12 = "Webmestre - Infos";
$web13 = "E-mail :";
$web14 = "Ce site est compatible avec les navigateurs de version 4 minimum.";
$web15 = "visiteur";
$web16 = "visiteurs";
$web17 = "visiteur en ligne";
$web18 = "visiteurs en ligne";
$web19 = "Poster un nouveau sujet";
$web20 = "Dernière modification :";
$web21 = "Catégorie :";
$web22 = "Imprimer l'article";
$web23 = "Version imprimable";
$web24 = "votes";
$web25 = "Total des votes :";
$web26 = "Vous avez déjà voté !";
$web27 = "Sélectionnez un fichier dans la liste déroulante ci-dessous ou utilisez les flèches de navigation.";
$web28 = "ko";
$web29 = "Fichier n°";
$web30 = "Note : l'adresse e-mail utilisée est protégée contre le SPAM.";
$web31 = "Cliquez sur la couleur désirée";
$web32 = "Précédent";
$web33 = "Liste des fichiers";
$web34 = "Suivant";
$web35 = "Cette page n'existe pas !";
$web36 = "Cette page n'existe pas !<br />Cela vient soit d'une erreur de votre part, soit du lien erroné qui pointe vers cette page.<br />Merci de le signaler au sympathique webmestre de ce site.";
$web37 = "inconnue";
$web38 = "Si le lien ne fonctionne pas, contactez le webmestre pour l'en informer.";
$web39 = "Note n°";
$web40 = "vous n'avez pas mis votre nom (ou votre pseudo).";
$web41 = "Poster un message";
$web42 = "vous n'avez pas saisi correctement votre e-mail.";
$web43 = "le message est trop court ou inexistant.";
$web44 = "Le message n'a pas été envoyé parce que : ";
$web45 = "Je vous remercie de prendre le temps d'écrire ce message.";
$web46 = "Merci de votre contribution !";
$web47 = "Cette saisie n'est pas valide !";
$web48 = "Je la validerai prochainement.";
$web49 = "Votre nom (ou pseudo) :";
$web50 = "Votre e-mail :";
$web51 = "Votre site web :";
$web52 = "Envoyer";
$web53 = "Effacer";
$web54 = "Titre de votre nouvelle :";
$web55 = "Votre nouvelle :";
$web56 = "Votre message :";
$web57 = "Fermer";
$web58 = "Rechercher";
$web59 = "Résultat de la recherche";
$web60 = "réponse trouvée pour";
$web61 = "réponses trouvées pour";
$web62 = "Aucune réponse";
$web63 = "Sujet n°";
$web64 = "Titre de votre message :";
$web65 = "Poster une réponse";
$web66 = "Dernière réponse par";
$web67 = "Réponses";
$web68 = "Réponse n° ";
$web69 = "Votre réponse :";
$web70 = "Retour à la liste des sujets";
$web71 = "Période :";
$web72 = "Aujourd'hui";
$web73 = "Mois en cours";
$web74 = "Cette année";
$web75 = "L'année dernière";
$web76 = "Analyse :";
$web77 = "Nombre de visiteurs &amp; de pages vues";
$web78 = "Langue de lecture &amp; pages vues";
$web79 = "Navigateur &amp; système opératif";
$web80 = "Voir l'analyse";
$web81 = "Nombre de visiteurs par heure";
$web82 = "Nombre de visiteurs par jour";
$web83 = "Nombre de visiteurs par mois";
$web84 = "Nombre de pages vues par heure";
$web85 = "Nombre de pages vues par jour";
$web86 = "Nombre de pages vues par mois";
$web87 = "Langue";
$web88 = "Pages vues";
$web89 = "Navigateur";
$web90 = "Système opératif";
$web91 = "Cette fonctionnalité n'est proposée que par Internet Explorer 4+";
$web92 = "Ajouter aux favoris";
$web93 = "1 réponse (par";
$web94 = "le";
$web95 = "Date de création :";
$web96 = "défaire";
$web97 = "refaire";
$web98 = "texte en gras";
$web99 = "texte souligné";
$web100 = "texte en italique";
$web101 = "texte préformaté";
$web102 = "compteur";
$web103 = "Message du";
$web104 = "le";
$web105 = "Bonne nouvelle, je viens juste de passer la valeur";
$web106 = "Proposition de nouvelle";
$web107 = "Soumission de : ";
$web108 = "Titre : ";
$web109 = "Message : ";
$web110 = "Nouveau fil de discussion";
$web111 = "Réponse à un fil de discussion existant";
$web112 = "Son site web : ";
$web113 = "Publication dans le livre d'or";
$web114 = "Publication dans le forum";
$web115 = "Masquer aux visiteurs votre adresse e-mail :";
$web116 = "Document généré en";
$web117 = "seconde";
$web118 = "secondes";
$web119 = "Favoris";
$web120 = "Recommander";
$web121 = "L'e-mail de votre ami :";
$web122 = "vous n'avez pas saisi correctement l'e-mail de votre ami.";
$web123 = "le titre est trop court ou inexistant.";
$web124 = "Recommander ce site à un ami";
$web125 = "Recommandation de";
$web126 = "a souhaité vous faire part du message ci-dessous concernant le site web";
$web127 = "Merci de répondre à l'adresse e-mail";
$web128 = "et pas à l'adresse de l'expéditeur de ce message.";
$web129 = "Le message de";
$web130 = "Catégories de discussion";
$web131 = "Nombre de sujets";
$web132 = "Nombre de messages";
$web133 = "Dernier message";
$web134 = "Retour à la liste des forums";
$web135 = "Retour";
$web136 = "Haut";
$web137 = "indéfinie";
$web138 = "Catégorie :";
$web139 = "Photo :";
$web140 = "Répondre à ce message";
$web141 = "Vous répondez à";
$web142 = "qui a écrit :";
$web143 = "Option non disponible sur décision du webmestre. Merci d'appuyer sur le bouton [retour] de votre navigateur.";
$web144 = "Admin";
$web145 = "La dernière nouvelle";
$web146 = "D"; // Dimanche
$web147 = "L"; // Lundi
$web148 = "M"; // Mardi
$web149 = "M"; // Mercredi
$web150 = "J"; // Jeudi
$web151 = "V"; // Vendredi
$web152 = "S"; // Samedi
$web153 = "0"; // Premier jour de la semaine : 1 = Dimanche, 0 = Lundi
$web154 = "Enregistrer";
$web155 = "Votre langue pour le contenu :";
$web156 = "Vous pouvez ici enregistrer vos préférences pour ce site : langue de navigation (arrivée automatiquement dans cette langue), pseudo et e-mail (proposés dans vos messages sur le livre d'or, le forum, etc...)";
$web157 = "Aucune de ces informations n'est stockée sur ce site. Elles le sont uniquement sur votre ordinateur par l'intermédaire d'un cookie (il vous faut donc vérifier que vous avez paramétré votre navigateur internet de façon à ce qu'il accepte les cookies).";
$web158 = "Votre nom :";
$web159 = "Invité";
$web160 = "Devenir membre";
$web161 = "Vos informations personnelles ont bien été enregistrées sur votre ordinateur.";
$web162 = "Supprimer mes préférences";
$web163 = "Vos informations personnelles ont été supprimées sur votre ordinateur.";
$web164 = "Position des boîtes :";
$web165 = "A droite et à gauche";
$web166 = "Toutes à gauche";
$web167 = ", bienvenue sur";
$web168 = "Tous les contenus";
$web169 = "Articles";
$web170 = "insérer un lien";
$web171 = "texte centré";
$web172 = "couleur du texte";
$web173 = "Ecrire à";
$web174 = "Page en cours de chargement";
$web175 = "Connectés :";
$web176 = "( personne )";
$web177 = "et";
$web178 = "seulement";
$web179 = "en direct";
$web180 = "Mon préféré";
$web181 = "Réagir à cet article";
$web182 = "Réaction à un article";
$web183 = "L'article sur lequel il a réagi";
$web184 = "Réactions à cet article";
$web185 = "Réaction n°";
$web186 = "Personne n'a encore laissé de commentaire.<br />Soyez donc le premier !";
$web187 = "Réactions Articles";
$web188 = "fois";
$web189 = "fois";
$web190 = "Page lue";
$web191 = "Téléchargé";
$web192 = "Zone de Téléchargement";
$web193 = "Le téléchargement commencera dans 5 secondes.<br />Sinon, cliquez sur le nom du fichier pour le déclencher.";
$web194 = "Nom du fichier :";
$web195 = "Taille :";
$web196 = "Dernière mise à jour :";
$web197 = "Dernier téléchargement :";
$web198 = "ADSL (512 Ko) :";
$web199 = "Téléchargé :";
$web200 = "Modem (56 Ko) :";
$web201 = "Modem (33.6 Ko) :";
$web202 = "min";
$web203 = "sec";
$web204 = "à :";
$web205 = "Annuler";
$web206 = "Etat";
$web207 = "Messages reçus";
$web208 = "de :";
$web209 = "Messages lus";
$web210 = "Expéditeur";
$web211 = "Messages non lus";
$web212 = "Mon compte";
$web213 = "Afficher votre nom (ou pseudo) dans la liste des connectés et recevoir des mini messages";
$web214 = "Envoyer un message à";
$web215 = "Courrier";
$web216 = "Vous répondez au message :";
$web217 = "Sujet lu";
$web218 = "Nom du téléchargement :";
$web219 = "Signature forum personnalisée :";
$web220 = "Votre contribution est en cours de traitement. Merci de patienter...";
$web221 = "Ces nouvelles sont disponibles en format standard RSS pour publication sur votre site web";
$web222 = "Abonnement à notre Newsletter";
$web223 = "forum actif";
$web224 = "Les discussions postérieures sont consultables dans le";
$web225 = "Le forum archivé contient toutes les discussions antérieures au";
$web226 = "Archives du forum";
$web227 = "Les discussions antérieures sont consultables dans les";
$web228 = "Le forum actif contient toutes les discussions postérieures au";
$web229 = "L'adresse de votre site web n'est pas valide !";
$web230 = "Ce message n'a pas été envoyé parce que le destinataire n'existe pas.";
$web231 = "Ce pseudo est déjà utilisé par quelqu'un ou bien le code secret ne correspond pas à ce pseudo! Merci d'essayer un autre pseudo ou code secret.";
$web232 = "Toutes à droite";
$web233 = "ne figure pas dans notre liste d'abonnés";
$web234 = "Pour vous réinscrire, veuillez suivre ce lien :";
$web235 = "Cordialement";
$web236 = "Se désabonner";
$web237 = "S'abonner";
$web238 = "s'est désinscrit de la Newsletter de";
$web239 = ", que nous vous confirmons votre désinscription à la Newsletter de";
$web240 = "C'est avec regret,";
$web241 = "Désinscription à la Newsletter";
$web242 = "vient de s'inscrire à la Newsletter de";
$web243 = "Pour vous désinscrire de cette Newsletter, veuillez suivre ce lien :";
$web244 = ", que nous vous confirmons votre inscription a la Newsletter de";
$web245 = "C'est avec plaisir,";
$web246 = "Inscription à la Newsletter";
$web247 = "Pour avoir des nouvelles de ce site, inscrivez-vous à notre Newsletter.";
$web248 = "a été inséré correctement dans notre liste d'abonnés.";
$web249 = "Merci";
$web250 = "Votre e-mail figure déjà dans notre liste d'abonnés";
$web251 = "Vous avez omis ou n'avez pas saisi correctement votre e-mail";
$web252 = "Vous avez omis de saisir votre nom ou pseudo";
$web253 = "Bonjour";
$web254 = "a bien été supprimée de notre liste d'abonnés";
$web255 = "Votre adresse e-mail :";
$web256 = "Veuillez corriger la ou les saisies suivante(s) :";
$web257 = "Abonné";
$web258 = "Abonnés";
$web259 = "Votre nom";
$web260 = "Votre e-mail";
$web261 = "Cache absent";
$web262 = "Erreur : fichier RSS non trouvé...";
$web263 = "Dernière mise à jour :";
$web264 = "Prévisualiser"; //modified in v4.6.0
$web265 = "Vos préférences n'ont pas été enregistrées parce que : ";
$web266 = "Votre pseudo contient des caractères non valides (format 2 à 20 caractères comprenant lettres, chiffres et _ ).";
$web267 = "Vous allez être automatiquement redirigé vers la page précédente dans 2 secondes.<br />Si ceci n'arrivait pas, cliquez sur le lien [ Retour ].";
$web268 = "Janvier";
$web269 = "Février";
$web270 = "Mars";
$web271 = "Avril";
$web272 = "Mai";
$web273 = "Juin";
$web274 = "Juillet";
$web275 = "Août";
$web276 = "Septembre";
$web277 = "Octobre";
$web278 = "Novembre";
$web279 = "Décembre";
$web280 = "Choisir un dossier";
$web281 = "Objet :";
$web282 = "Voir, puis sauvegarder";
$web283 = "Lire le dernier message";
$web284 = "0"; // 0 = jour/mois/an, 1 = mois/jour/an, 2 = an/mois/jour
$web285 = "Agenda du";
$web286 = "Voir l'agenda complet :";
$web287 = "Agenda : ";
$web288 = "Mois suivant";
$web289 = "Mois précédent";
$web290 = "Aucun évènement pour le mois demandé";
$web291 = "Vous pouvez conserver ici jusqu'à ";
$web292 = " Article n° ";
$web293 = "Cite";
$web294 = "maintenance";
$web295 = "Version mobile";
$web296 = "Lire la suite";
$web297 = "Voir?";
$web298 = "Titre du forum"; // new in v4.6.0
$web299 = "Auteur"; // new in v4.6.0
$web300 = "Votre code secret"; //modified in v4.6.0
$web301 = "(à ne remplir que si vous avez perdu votre cookie et que vous connaissez votre code secret)";
$web302 = "Le code secret contient des caractères non valides (format 5 à 20 caractères parmi A à Z, a à z et _)";
$web303 = "Choisissez un avatar";
$web304 = "Site web";
$web305 = "Anonyme";
$web306 = "Bonjour et bienvenue sur le site";
$web307 = "Sélectionner un thème :";
$web308 = "Modifier";
$web309 = "Pas de signature";
$web310 = "Thème skin :";
$web311 = "Avatars :";
$web312 = "Afficher votre pseudo :";
$web313 = "Oui";
$web314 = "Non";
$web315 = "Skin d'origine";
$web316 = "Aucun ou non mentionné";
$web317 = "Compte";
$web318 = "Mon courrier";
$web319 = "Nouveaux messages";
$web320 = "Nombre de membres";
$web321 = "membres";
$web322 = "membre";
$web323 = "Action";
$web324 = "Supprimer";
$web325 = "Date &amp; heure";
$web326 = "Lire";
$web327 = "Messages envoyés";
$web328 = "Destinataire";
$web329 = "qui répondait à votre message du";
$web330 = "Message de";
$web331 = "Message bien supprimé.";
$web332 = "Vous allez être automatiquement redirigé vers 'Courrier' dans 2 secondes.<br />Si ce n'était le cas, cliquez sur la flèche.";
$web333 = "Désactiver";
$web334 = "message";
$web335 = "messages";
$web336 = "page suivante";
$web337 = "pages suivantes";
$web338 = "Fin";
$web339 = "Début";
$web340 = "pages précédentes";
$web341 = "page précédente";
$web342 = "Vous devez être membre pour accéder à cette section";
$web343 = "Devenir membre";
$web344 = "S'abonner à ce fil de discussion"; // changed in v4.6.0
$web345 = "Réponse au sujet - ";
$web346 = "Une réponse à été postée au sujet : ";
$web347 = "Vous pouvez consulter cette réponse en cliquant sur ce lien :";
$web348 = "Cordialement";
$web349 = "Informations pour l'administration";
$web350 = "Lien modification  : ";
$web351 = "Lien activation    : ";
$web352 = "Lien désactivation : ";
$web353 = "Lien suppression   : ";
$web354 = "ID N°";
$web355 = "ID article N°";
$web356 = "ID réaction N°";
$web357 = "Erreur d'utilisation de la messagerie interne";
$web358 = "La messagerie interne est réservée aux membres !";
$web359 = "Le destinataire n'est pas indiqué !";
$web360 = "Lien consultation : ";
$web361 = "Exécuter les actions sélectionnées...";
$web362 = "Télécharger";
// ajouté en v4.6.0
$web363 = "Clôturer ";
$web364 = "Remonter ";
$web365 = "Bloquer en haut";
$web366 = "sujet ";
$web367 = "actif";
$web368 = "clos";
$web369 = "Rectifier ";
$web370 = "Important!";
$web371 = "Nouveau ";
$web372 = "Déconnexion";
$web373 = "Se reconnecter";
$web374 = ", vous avez peut-être perdu votre cookie... Complétez vos préférences SVP!";
$web375 = "Mini-éditeur simple (non WYSIWYG)";
$web376 = "Au revoir ";
$web377 = "INFORMATIONS PERSONNELLES";
$web378 = "PREFERENCES";
$web379 = "commentaire";
$web380 = "Poster un commentaire";
$web381 = "Blog";
$web382 = "derniers billets";
$web383 = "Tous les billets";
$web384 = "Sujet :";
$web385 = "Ajouter le vôtre?";
$web386 = "Poster un billet";
$web387 = "Titre de votre billet :";
$web388 = "Votre billet :";
$web389 = "Le dernier billet";
$web390 = "Stopper, cloturer";
$web391 = "vous pouvez annoter ce message...";
$web392 = "Ce pseudo est déjà utilisé !!!";
$web393 = "Rubrique :";
$web394 = "Publié le ";
$web395 = "Evènement";
$web396 = "Proposition de billet";
$web397 = "Vous n'avez pas mentionné de catégorie !!!";
$web398 = "Ces billets sont disponibles en format standard RSS pour publication sur votre site web";
$web399 = "Archives";
$web400 = "Rubriques";
$web401 = "Derniers commentaires";
$web402 = "Billets des amis";
$web403 = "Billets du ";
$web404 = "Ce n'est pas votre pseudo !!!";
$web405 = "Ce pseudo est déjà utilisé ";
$web406 = "Ces articles sont disponibles en format standard RSS pour publication sur votre site web";
$web407 = "Commentaires";
$web408 = "caractères... Message trop long (maximum:";
$web409 = "La Charte du Forum";
$web410 = "UTILISATION du FORUM";
$web411 = "Signification des icônes :";
$web412 = "<b>Actions utilisateur</b> (vous devez être membre et avoir un <u>navigateur compatible éditeur WYSIWYG</u>) :";
$web413 = "Citation:";
$web414 = "Je refuse";
$web415 = "J'accepte";
$web416 = "Vous n'êtes pas autorisé à modifier ce message !!!";
$web417 = "Rectifié";
$web418 = "Administrateur";
$web419 = "Rédacteur";
$web420 = "Modérateur";
$web421 = "Votre plugin Flash est absent ou trop ancien !!! Cliquez pour le télécharger";
$web422 = "Dialoguer par ";
$web423 = "Menu";
$web424 = "Supprimer les messages sélectionnés";
$web425 = "Tout sélectionner";
$web426 = "Sélectionner tous les messages reçus";
$web427 = "Sélectionner tous les messages envoyés";
$web428 = "Il n'y a aucun message à supprimer";
// ----------- added in v4.6.3 -------- //
$web429 = "Déplier";
$web430 = "aucun";
// ----------- added in v4.6.4 -------- //
$web431 = ", que nous enregistrons votre demande d'abonnement à la Newsletter de ";
$web432 = "Pour confirmer votre inscription, veuillez suivre ce lien :";
$web433 = "Veuillez répondre à notre mail pour confirmation, merci.";
$web434 = "Opération illégale ou délai expiré !!!";
$web435 = "octets";
$web436 = "Agenda";
$web437 = "Fonction";
// ----------- added in v4.6.9 -------- //
$web438 = 'Aucun billet ce mois-ci.';
$web439 = 'Il n\'y a pas encore de billet.';
$web440 = 'Soyez-le premier à en écrire un.';
$web441 = 'Certaines réponses ne sont accessibles qu\'aux seuls membres.';
// ----------- added in v4.6.9 -------- //
$web442 = '(Non traduit à ce jour)';
// ----------- added in v4.6.15 -------- //
$web443 = "<font color='red'>Vous n'avez pas accès à ce forum !</font>";
$web444 = "<strong>Document privé, lecture non autorisée !!!</strong>";
$web445 = "<strong>Document privé, téléchargement non autorisé !!!</strong>";
$web446 = "La lecture de certaines réponses n'est pas autorisée !!!";
$web447 = 'Inscription membre non autorisée';
$web448 = 'Votre demande est déjà prise en compte,<br /> veuillez répondre à notre mail !!!';
$web449 = 'Votre demande est déjà prise en compte,<br /> veuillez attendre la confirmation du webmestre !!!';
$web450 = 'Confirmation d\'inscription';
$web451 = 'que nous acceptons votre inscription en tant que membre de ';
$web452 = 'Pour valider votre inscription <strong>reconnectez-vous </strong> sur : ';
$web453 = 'Refus d\'inscription';
$web454 = 'que nous déclinons votre inscription comme membre de ';
$web455 = 'demande son inscription comme membre de ';
$web456 = 'Accepter l\'inscription';
$web457 = 'Refuser l\'inscription';
$web458 = 'Inscription membre';
$web459 = 'Votre demande est prise en compte.';
$web460 = 'Veuillez attendre le mail de confirmation du webmestre.';
// ----------- added in v4.6.17 -------- //
$web461 = '<sup>...</sup> / ... ';
$web462 = 'Hyperlien';
// ----------- added in v4.6.18 -------- //
$web463 = 'Je confirme ma désinscription.';
$web464 = 'Vous pouvez maintenant vous connecter sur : ';
$web465 = 'Cette adresse mail est déjà utilisée !';
$web466 = 'Une inscription avec ce pseudo est en cours de validation.<br />Merci de recommencer avec un autre pseudo.';
$web467 = 'Cliquez ici si votre navigateur ne vous redirige pas.';

?>