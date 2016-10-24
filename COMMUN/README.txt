LE SAINT README !

Ce fichier ET la page Github sont des havres de paix.
Merci d ecrire vos bugs, idees, reports ici ou sur git.
Il y a une page ISSUS dessus, le mieux est de faire une issus pour chaque bug.

Le nouveau systeme fait en sorte de separer les fichiers vue que l ancien
systeme etait d un relou de fou.

Il faudrait aussi mettre la liste des trucs a faire ici :

=====================
=      A faire      =
====================================================================

- Mettre les .c dans le dossier inc et faire le lien dans le Makefile
- Corriger le leak dans create_tree (Tout du moins cela viens du path)
- Faire un parseur (En discuter avec Chris tout ca)
- Voir si on prend le 21sh de Chris ou pas

====================================================================

L ideal aussi sera a chaque commit de dire en gros ce qu on a fait.
Genre pour ce commit ce serrais :

=====================
=     Changelog     =
====================================================================
20 octobre 16h15 - ThomasV

Fait :

- Nouveau systeme de rangement des fichiers
- Reduction du code dans le main
- Changement du nom de l executable en 42sh

Retours :

- Leak dans la fonction create_tree (create_tree.c)

====================================================================
=====================
=     Changelog     =
====================================================================
24 octobre 9h30 - jean-yves

fait :

- Makefile modifier et corriger, c'etait du grand n'importe quoi

ps :

- thomas, tu fait plus JAMAIS un changement pareil sans en parler
au autres (surtout si je doit tout refaire deriere), ceci vaut 
aussi pour les autre. le prochaint qui fera une maj majeure
dans son coin degage sans sommation
====================================================================
