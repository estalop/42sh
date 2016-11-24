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

- Leak avec les Quote
- Multiline casser avec et apres Quote (il passe toujours dans le parse pour les quote)
- Apres usage de Quote le 42sh est tres tres lent meme apres un redemarage du 42sh
- Enlever l ecriture du output quand on fait genre "commande " puis fleche du haut..

====================================================================


====================
=     ERROR404     =
===================================================================

- Souci avec unsetenv

- Les elements de ft_son_builtin ne sont pas utilise

=====================
=     Changelog     =
====================================================================
23 novembre 18h50 - ThomasV

- DeplacEment des built-in (j ai mis seulement echo en dur, le reste est en com)

Pour les deplacement je suis pas certain des valeurs de retour et tout vis-a-vis
du fait que son-env n'ai pas de retour via exit

23 novembre 11h34 - jean-yves

-double lancement pas du tout resolut (je bosse dessus pour le moment)-

ps : deja faut deplacer echo et ensuite ce probleme sera gerer par les valeurs
de retour demande moi si tu veut t'en occuper.

21 novembre 18h15 - ThomasV

- Resolution du double lancement pour les built-in (genre echo lancait celui du sys et le notre)

21 novembre 16h04 - jean-yves

- env de nouveau fonctionnel -

12 novembre 15h53 - ThomasV

- Le texte 21sh et minishell -> 42sh

24 octobre 14h30 - ThomasV

Fait :

- Del des headers useless

ps :

- Tout compilais et était beau, Si tu peux m'expliqué ou était le souci ?
(hormis le -g car ouais c'était débile de le viré)
====================================================================
24 octobre 9h30 - Jean-yves

Fait :

- Makefile modifier et corriger, c'etait du grand n'importe quoi

ps :

- AU GROS BOULET QUI FAIT DES MODIF SANS EN PARLER, tu fait plus
JAMAIS un changement pareil sans en parler + au autres
(surtout si je doit tout refaire deriere), ceci vaut
+aussi pour les autre. le prochaint qui fera une maj majeure
+dans son coin degage sans sommation
====================================================================
20 octobre 16h15 - ThomasV

Fait :

- Nouveau systeme de rangement des fichiers
- Reduction du code dans le main
- Changement du nom de l executable en 42sh

Retours :

- Leak dans la fonction create_tree (create_tree.c)
====================================================================
