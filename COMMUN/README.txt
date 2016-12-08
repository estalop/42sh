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

- Apres une commande parfois le builtin OU ses arguments (genre cd ..) sont bugé
- Env affichage pas bon (retour ligne au debut)
- Sans Path il trouve genre ls
- Unsetenv HOME puis cd ~    SEGFAULT
- Unsetenv OLDPWD puis cd -   SEGFAULT
- Unsetenv PWD   puis cd tamere  SEGFAULT

====================================================================


====================
=     ERROR404     =
===================================================================

- lors d'un redimentionnement, si l'on utilise l'autocompletion, le
terminal passe en couleur inverser.

- l'autocompletion ne remet pas le curseur au bon endroit.

=====================
=     Changelog     =
====================================================================
5 decembre 9h59 - jean-yves

- gestion d'erreur de l'historique

3 decembre 16h41 - ThomasV

- Check du nom dans le setenv
- Mise a la norme depuis un moment

28 novembre 21h14 - ThomasV

- Ajout du systeme d OPERATEURS
ATTENTION ! Il est bugé mais les erreurs sont toutes connes (je pense)
J'ai mis un max de commentaires pour bien expliqué comment ça fonctionne
Plus aucune commande ne peux contre etre entrée
Utilisez PS puis KILL pour tuer


25 novembre 19h42 - ThomasV

- Leaks de l historique des commandes (avec fleches haut-bas) bouché

Note : Après 2h j'ose toujours pas foutre les main dans le truc de Quote, on
vois ça ensemble MallocGiver ?

Les built-in faut les lancer via l ancien ou le nouveau systeme ?
=============
24 novembre 14h00 - jean-yves

- unsetenv fonctionnel, echo fonctionnel -

tu a bien un retour, je l'ai stockee dans proc->stat_lock mais ont ne peut pas y acceder du shell.

=============
23 novembre 18h50 - ThomasV

- Deplacement des built-in (j ai mis seulement echo en dur, le reste est en com)

Pour les deplacement je suis pas certain des valeurs de retour et tout vis-a-vis
du fait que son-env n'ai pas de retour via exit

=============
23 novembre 11h34 - jean-yves

-double lancement pas du tout resolut (je bosse dessus pour le moment)-

ps : deja faut deplacer echo et ensuite ce probleme sera gerer par les valeurs
de retour demande moi si tu veut t'en occuper.

=============
21 novembre 18h15 - ThomasV

- Resolution du double lancement pour les built-in (genre echo lancait celui du sys et le notre)

=============
21 novembre 16h04 - jean-yves

- env de nouveau fonctionnel -

=============
12 novembre 15h53 - ThomasV

- Le texte 21sh et minishell -> 42sh

=============
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
