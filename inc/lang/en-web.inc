<?php
/*
    Web Language Strings - GuppY PHP Script - version 4.6
    CeCILL Copyright (C) 2004-2012 by Laurent Duveau
    Initiated by Laurent Duveau and Nicolas Alves
      Web site = http://www.freeguppy.org/
      e-mail   = guppy@freeguppy.org

    Version History :
      v1.0 (30 December 2002)    : initial release
      v1.1 (02 January 2003)     : various strings updates and add-ons
      v1.2 (05 January 2003)     : various strings updates and add-ons
      v1.3 (06 January 2003)     : various strings updates and add-ons
      v1.4 (07 January 2003)     : various strings updates and add-ons
      v1.5 (10 January 2003)     : various strings updates and add-ons
      v1.6 (23 January 2003)     : various strings add-ons
      v1.7 (28 January 2003)     : various strings add-ons
      v1.8 (05 February 2003)    : various strings add-ons
                                   added charset management
      v1.9 (11 February 2003)    : various strings add-ons
      v2.0 (27 February 2003)    : various strings updates and add-ons
      v2.1 (10 March 2003)       : replaced all \' occurrences by ' (now managed by Javascript functions calls)
                                   various strings updates and add-ons in Admin
      v2.2 (22 April 2003)       : various strings updates and add-ons
                                   split of file in two xx-web.inc and xx-admin.inc for faster loading
      v2.3 (27 July 2003)        : various strings updates and add-ons
      v2.4 (24 September 2003)   : various strings updates and add-ons
      v3.0 (25 February 2004)    : various strings updates and add-ons
      v4.0 (06 December 2004)    : added new strings and add-ons (by Icare - Nico)
      v4.5 (04 april 2005)       : added new strings and add-ons (by Icare - Nico - Jean-Mi)
      v4.6.0 (04 June 2007)      : added new strings and add-ons (by Icare)
      v4.6.3 (30 August 2007)    : added new strings (by Icare)
      v4.6.5 (05 December 2007)  : added new strings (by Icare)
      v4.6.9 (25 December 2008)  : added new strings (by JeanMi)
      v4.6.13 (22 May 2010)      : new translation (by Katryne)	  
      v4.6.14 (14 February 2011) : added $web435 (thanks JeanMi)
      v4.6.15 (30 June 2011)     : added new strings (by Icare)
	  v4.6.16 (02 September 2011): various strings updates and add-ons
	  v4.6.17 (21 October 2011)  : various strings updates and add-ons (by Laroche)
                                   new translation (by Corrector)
	  v4.6.18 (09 February 2012) : added new strings, various strings updates (by Saxbar, Papinou)
      v4.6.22 (29 December 2012) : corrected $web406 (thanks Laroche)	  
*/

if (stristr($_SERVER["SCRIPT_NAME"], "en-web.inc")) {
  header("location:../index.php");
  die();
}

$charset = "iso-8859-1";

$web1 = "Welcome to";
$web2 = "The";
$web3 = "last news";
$web4 = "Write a piece of news";
$web5 = "Sentence to think about :";
$web6 = "by";
$web7 = " ";
$web8 = "Your language for the interface :";
$web9 = "Vote!";
$web10 = "Results";
$web11 = "Webmaster";
$web12 = "Webmaster - Infos";
$web13 = "E-mail :";
$web14 = "This site requires web browsers to be at least version 4.";
$web15 = "visitor";
$web16 = "visitors";
$web17 = "visitor online";
$web18 = "visitors online";
$web19 = "Post a new topic";
$web20 = "Last update :";
$web21 = "Category :";
$web22 = "Print the article";
$web23 = "Printable version";
$web24 = "votes";
$web25 = "Number of votes :";
$web26 = "You already voted !";
$web27 = "Select a file in the scroll list below or use the navigation arrows.";
$web28 = "Kb";
$web29 = "File #";
$web30 = "Note: the e-mail address is protected against SPAM.";
$web31 = "Choose your color";
$web32 = "Previous";
$web33 = "List of files";
$web34 = "Next";
$web35 = "This page does not exist !";
$web36 = "This page does not exist !<br />Either you made a mistake or the link to this web page is broken.<br />Will you please report it to the Webmaster of this site.";
$web37 = "unknown";
$web38 = "If you find a broken link in this list, please report it to the webmaster.";
$web39 = "Note #";
$web40 = "You did not enter your user name.";
$web41 = "Post a Message";
$web42 = "You did not enter your e-mail correctly.";
$web43 = "The message is too short or empty.";
$web44 = "The message was not sent because : ";
$web45 = "Thanks for taking the time to write this message.";
$web46 = "Thanks for your input !";
$web47 = "This input is not valid !";
$web48 = "I will validate it soon.";
$web49 = "Your user name :";
$web50 = "Your e-mail :";
$web51 = "Your website :";
$web52 = "Send";
$web53 = "Cancel";
$web54 = "Title of your piece of news :";
$web55 = "Your piece of News :";
$web56 = "Your Comment :";
$web57 = "Close";
$web58 = "Search";
$web59 = "Search Result";
$web60 = "answer found for";
$web61 = "answers found for";
$web62 = "No answer";
$web63 = "Topic #";
$web64 = "Title of your comment :";
$web65 = "Post an answer";
$web66 = "Last answer by";
$web67 = "Answers";
$web68 = "Answer n° ";
$web69 = "Your answer :";
$web70 = "Back to the list of topics";
$web71 = "Period of time :";
$web72 = "Today";
$web73 = "Current month";
$web74 = "This year";
$web75 = "Last year";
$web76 = "Analysis :";
$web77 = "Number of Visitors &amp; and viewed Pages";
$web78 = "Reading Language &amp; viewed Pages";
$web79 = "Browser &amp; Operating System";
$web80 = "Launch the analysis";
$web81 = "Number of Visitors per hour";
$web82 = "Number of Visitors per day";
$web83 = "Number of Visitors per month";
$web84 = "Number of viewed Pages per hour";
$web85 = "Number of viewed Pages per day";
$web86 = "Number of viewed Pages per month";
$web87 = "Language";
$web88 = "Viewed Pages";
$web89 = "Browser";
$web90 = "Operating System";
$web91 = "This feature is only available through Internet Explorer 4+";
$web92 = "Add to bookmarks";
$web93 = "1 answer (by";
$web94 = "on";
$web95 = "Creation date :";
$web96 = "undo";
$web97 = "redo";
$web98 = "bold text";
$web99 = "underlined text";
$web100 = "italic text";
$web101 = "preformatted text";
$web102 = "counter";
$web103 = "Message of";
$web104 = "at";
$web105 = "Good news, I just passed value";
$web106 = "News Proposal";
$web107 = "Submitted by : ";
$web108 = "Title : ";
$web109 = "Message : ";
$web110 = "New thread";
$web111 = "Answer to an existing thread";
$web112 = "His web site : ";
$web113 = "Guestbook Publishing";
$web114 = "Forum Publishing";
$web115 = "Hide your e-mail address to visitors:";
$web116 = "Document generated in";
$web117 = "second";
$web118 = "seconds";
$web119 = "Bookmarks";
$web120 = "Recommend";
$web121 = "Your friend's e-mail :";
$web122 = "you did not enter your friend's e-mail correctly.";
$web123 = "The title was not entered or it is too short.";
$web124 = "Recommend this site to a friend";
$web125 = "Recommendation from";
$web126 = "wrote the following message to you about the web site";
$web127 = "Please, answer to e-mail address";
$web128 = "and not to the e-mail address of the sender of this message.";
$web129 = "The message from";
$web130 = "Forum Topic";
$web131 = "Subjects Number";
$web132 = "Messages Number";
$web133 = "Last Message";
$web134 = "Back to the list of forums";
$web135 = "Back";
$web136 = "Top";
$web137 = "undefined";
$web138 = "Category :";
$web139 = "Photo :";
$web140 = "Answer to this message";
$web141 = "You are answering to";
$web142 = "who wrote:";
$web143 = "Option unavailable by decision of the webmaster. Please press the [back] button of your browser.";
$web144 = "Admin";
$web145 = "The latest piece of news";
$web146 = "S"; // Sunday
$web147 = "M"; // Monday
$web148 = "T"; // Tuesday
$web149 = "W"; // Wednesday
$web150 = "T"; // Thursday
$web151 = "F"; // Friday
$web152 = "S"; // Saturday
$web153 = "1"; /* First day of the week : 1=Sunday 0=Monday */
$web154 = "Save";
$web155 = "Your language for the content :";
$web156 = "You may save here your preferences for this web site : browsing language (automatic arrival in this language), user name and e-mail (will be entered by default in your messages on the guestbook, forum, etc...).";
$web157 = "None of this information is stored on this site. They are only remembered by your computer thanks to the use of a cookie (you must have allowed your internet browser to accept cookies).";
$web158 = "Your user name :";
$web159 = "Guest";
$web160 = "Become a member";
$web161 = "Your personal data was saved on your computer.";
$web162 = "Remove my preferences";
$web163 = "Your personal data was removed from your computer.";
$web164 = "Boxes location :";
$web165 = "Left and right";
$web166 = "All on the left";
$web167 = ", welcome to";
$web168 = "All contents";
$web169 = "Articles";
$web170 = "insert a link";
$web171 = "center text";
$web172 = "text color";
$web173 = "Write to";
$web174 = "Page loading";
$web175 = "Connected :";
$web176 = "(nobody)";
$web177 = "and";
$web178 = "only";
$web179 = "live";
$web180 = "My favourite";
$web181 = "React to this article";
$web182 = "React to an article";
$web183 = "The article he reacted to";
$web184 = "Reactions to this article";
$web185 = "Reaction #";
$web186 = "Nobody gave a comment yet.<br />Be the first to do so!";
$web187 = "Articles Reactions";
$web188 = "time";
$web189 = "times";
$web190 = "Page read";
$web191 = "Downloaded";
$web192 = "Download Area";
$web193 = "Download will start in 5 seconds.<br />If not, click on the file name to initiate it.";
$web194 = "File name :";
$web195 = "Size :";
$web196 = "Last update :";
$web197 = "Last download :";
$web198 = "ADSL (512 Kb) :";
$web199 = "Downloaded :";
$web200 = "Modem (56 Kb) :";
$web201 = "Modem (33.6 Kb) :";
$web202 = "min";
$web203 = "sec";
$web204 = "to :";
$web205 = "Cancel";
$web206 = "State";
$web207 = "Received messages";
$web208 = "from :";
$web209 = "Read messages";
$web210 = "Sender";
$web211 = "Unread messages";
$web212 = "My account";
$web213 = "Display your name in the online users list and receive tiny messages";
$web214 = "Send a tiny message to";
$web215 = "Mail";
$web216 = "You are answering the message :";
$web217 = "Topic read";
$web218 = "Download name :";
$web219 = "Personal forum signature :";
$web220 = "Your message is being processed. Please wait...";
$web221 = "These news are available in the standard RSS format for publication on your website";
$web222 = "Subscription to our Newsletter";
$web223 = "active forum";
$web224 = "The live threads are to be found in the";
$web225 = "The forum archives hold all threads written before";
$web226 = "Forum archives";
$web227 = "The previous threads are to be found in the";
$web228 = "The active forum holds all threads written after";
$web229 = "Your website address is not correct!";
$web230 = "The message was not sent because the recipient does not exist.";
$web231 = "This user name is already used by somebody else or the secret code does not match this user name! Please enter another user name or secret code.";
$web232 = "All on the right";
$web233 = "is not listed in our Newsletter list.";
$web234 = "To subscribe again, please follow this link:";
$web235 = "Best regards";
$web236 = "Unsubscribe";
$web237 = "Subscribe";
$web238 = "just unsubscribed from the Newsletter of";
$web239 = ", to confirm that you were removed from the Newsletter subscription list of";
$web240 = "We regret,";
$web241 = "Unsubscription to the Newsletter";
$web242 = "just subscribed to the Newsletter.";
$web243 = "To unsubscribe from this Newsletter, please follow this link:";
$web244 = ", to confirm your subscription to the Newsletter of";
$web245 = "We are happy,";
$web246 = "Subscription to the Newsletter";
$web247 = "To receive news about this website, consider subscribing to our Newsletter.";
$web248 = "was added to our Newsletter subscription list.";
$web249 = "Thank you";
$web250 = "Your e-mail is already in our Newsletter subscription list";
$web251 = "You did not enter correctly your e-mail";
$web252 = "You forgot to give your user name";
$web253 = "Hello";
$web254 = "was removed from our subscription list";
$web255 = "Your e-mail address:";
$web256 = "Please correct the following input(s):";
$web257 = "Subscriber";
$web258 = "Subscribers";
$web259 = "Your name";
$web260 = "Your e-mail";
$web261 = "Cache missing";
$web262 = "Error: RSS file not found...";
$web263 = "Last import :";
$web264 = "Preview"; //modified in v4.6.0
$web265 = "Your preferences were not saved because : ";
$web266 = "Your user name includes invalid characters (format 2 to 20 characters among letters, numbers and the underscore: _ )";
$web267 = "You will be redirected automatically to the previous page up to 2 seconds.<br />If it does not happen, please click on the [ Back ] link.";
$web268 = "January";
$web269 = "February";
$web270 = "March";
$web271 = "April";
$web272 = "May";
$web273 = "June";
$web274 = "July";
$web275 = "August";
$web276 = "September";
$web277 = "October";
$web278 = "November";
$web279 = "December";
$web280 = "Select a folder";
$web281 = "Item :";
$web282 = "View and save";
$web283 = "Read the last message";
$web284 = "1"; // 0 = day/month/year, 1 = month/day/year, 2 = year/month/day
$web285 = "Planning of";
$web286 = "View complete planner :";
$web287 = "Planner : ";
$web288 = "Next month";
$web289 = "Previous month";
$web290 = "No event for this month";
$web291 = "Here you can store up to ";
$web292 = " Article # ";
$web293 = "Quote";
$web294 = "maintenance";
$web295 = "Mobile version";
$web296 = "Read more...";
$web297 = "View ?";
$web298 = "Forum title"; // new in v4.6.0
$web299 = "Author"; //new in v4.6.0
$web300 = "Your secret code";
$web301 = "(Only if you lost your cookie and you remember your secret code)";
$web302 = "The secret code has invalid characters (format 5 to 20 characters among A to Z, a to z or _)";
$web303 = "Choose an avatar";
$web304 = "Website";
$web305 = "Anonymous";
$web306 = "Hello, welcome on site";
$web307 = "Select a theme :";
$web308 = "Modify ";
$web309 = "No signing";
$web310 = "Skin theme :";
$web311 = "Avatars :";
$web312 = "Display your user name :";
$web313 = "Yes";
$web314 = "No";
$web315 = "Original skin";
$web316 = "None or not noted";
$web317 = "Account";
$web318 = "My mail";
$web319 = "New messages";
$web320 = "Count of members";
$web321 = "members";
$web322 = "member";
$web323 = "Action";
$web324 = "Cancel";
$web325 = "Day &amp; hour";
$web326 = "Read";
$web327 = "Sent messages";
$web328 = "Recipient";
$web329 = "who was answering your mail of";
$web330 = "Message from";
$web331 = "Message cancelled.";
$web332 = "You will be redirected automatically to \"mail\" within 2 seconds.<br />If not, please click on this arrow.";
$web333 = "Disable";
$web334 = "message";
$web335 = "messages";
$web336 = "next page";
$web337 = "next pages";
$web338 = "End";
$web339 = "Start";
$web340 = "previous pages";
$web341 = "previous page";
$web342 = "You need to be a registered member to access this area";
$web343 = "Become a member";
$web344 = "Subscribe to this thread"; // changed in v4.6.0
$web345 = "Answer to topic - ";
$web346 = "An answer has been posted to the topic : ";
$web347 = "Click this link to read that answer :";
$web348 = "Cordially";
$web349 = "Information for administration";
$web350 = "Link modification : ";
$web351 = "Link activation   : ";
$web352 = "Link deactivation : ";
$web353 = "Link deletion     : ";
$web354 = "ID #";
$web355 = "ID article #";
$web356 = "ID reaction #";
$web357 = "Error using the internal messaging";
$web358 = "Internal messaging is for members only !";
$web359 = "The recipient is not indicated !";
$web360 = "Link for consultation : ";
$web361 = "Perform the selected actions...";
$web362 = "Download";
// added in v4.6.0
$web363 = "Close ";
$web364 = "Make sticky ";
$web365 = "Keep topic sticky";
$web366 = "topic ";
$web367 = "active";
$web368 = "closed";
$web369 = "Correct ";
$web370 = "Sticky";
$web371 = "New ";
$web372 = "Disconnect";
$web373 = "Connect again";
$web374 = " , perhaps you lost you cookie... Enter again your preferences please!";
$web375 = "Simple mini-editor (not WYSIWYG)";
$web376 = "Bye bye ";
$web377 = "PERSONNAL INFORMATION";
$web378 = "PREFERENCES";
$web379 = "comment";
$web380 = "Post a comment";
$web381 = "Blog";
$web382 = "last posts";
$web383 = "All the posts";
$web384 = "Topic :";
$web385 = "Add yours ?";
$web386 = "Write a post in the blog";
$web387 = "Title of your post :";
$web388 = "Your post :";
$web389 = "The last note";
$web390 = "Stop, close";
$web391 = "you may annotate that message...";
$web392 = "That user name is already in use !!!";
$web393 = "Category :";
$web394 = "Published on ";
$web395 = "Event";
$web396 = "Blog Proposal";
$web397 = "you must input a category !!!";
$web398 = "These posts are available in the standard RSS format for publication on your website";
$web399 = "Archives";
$web400 = "Categories";
$web401 = "Last comments";
$web402 = "Friends' posts";
$web403 = "Posts of ";
$web404 = "It is not your user name !!!";
$web405 = "Your user name is already registered ";
$web406 = "These articles are available in the standard RSS format for publication on your website";
$web407 = "Comments";
$web408 = "characters... Message is too long (maximum:";
$web409 = "Forum charter";
$web410 = "FORUM USAGE";
$web411 = "Icons meaning :";
$web412 = "<b>User actions</b> (you must be a member and have a browser suitable with WYSIWYG editing) :";
$web413 = "Quotation:";
$web414 = "I reject";
$web415 = "I agree";
$web416 = "You are not entitled to modify this message !!!";
$web417 = "Rectified";
$web418 = "Administrator";
$web419 = "Writer";
$web420 = "Moderator";
$web421 = "Your Flash plugin  is too old or non-existent!!! Click to download it.";
$web422 = "Converse with ";
$web423 = " Menu ";
$web424 = "Discard selected messages";
$web425 = "Select all";
$web426 = "Select all received messages";
$web427 = "Select all sent messages";
$web428 = "There is no message to delete";
// ----------- added in v4.6.3 -------- //
$web429 = "Unfold";
$web430 = "none";
// ----------- added in v4.6.4 -------- //
$web431 = ", that we register your request for subscription to the Newsletter of ";
$web432 = "To confirm your subscription, follow that link :";
$web433 = "Will you please answer our mail, in order to confirm. Thanks.";
$web434 = "Illegal action or time limit exceeded !!!";
$web435 = "bytes";
$web436 = "Planner";
$web437 = "Function";
// ----------- added in v4.6.9 -------- //
$web438 = 'No post this month.';
$web439 = 'There is no post yet.';
$web440 = 'Be the first to write a post in the blog.';
$web441 = 'Some answers are accessible only to the members.';
// ----------- added in v4.6.10 -------- //
$web442 = "(not yet translated)";
// ----------- added in v4.6.15 -------- //
$web443 = "<font color='red'> You do not have access to this forum!</font>";
$web444 = "<strong> private document, unauthorized reading!</strong>";
$web445 = "<strong> private document, unauthorized downloading!</strong>";
$web446 = "Reading some of the answers is not allowed !!!";
$web447 = 'Member Registration unauthorized';
$web448 = 'Your request is already taken into account,<br />please answer our mail !!!';
$web449 = 'Your request is already taken into account,<br />please wait for confirmation from the webmaster !!!';
$web450 = 'Confirmation of registration';
$web451 = 'that we accept your registration as a member of ';
$web452 = 'To validate your registration <strong>reconnect</strong> to : ';
$web453 = 'Refusal of registration';
$web454 = 'that we accept your registration as a member of ';
$web455 = 'asks for registration as a member of ';
$web456 = 'Accepting registration';
$web457 = 'Refuse registration';
$web458 = 'Member Registration';
$web459 = 'Your request is taken into account.';
$web460 = 'Please wait for the confirmation email from the webmaster.';
// ----------- added in v4.6.17 -------- //
$web461 = '<sup>...</sup> / ... ';
$web462 = 'Hyperlink';
// ----------- added in v4.6.18 -------- //
$web463 = 'I confirm my unsubscribe.';
$web464 = 'You can now log on : ';
$web465 = 'This email address is already in use !';
$web466 = 'An inscription with this nickname is under validation.<br />Thank you for repeat with another nickname.';
$web467 = 'Click here if your browser does not redirect.';

?>
