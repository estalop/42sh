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

- L'historique ne reviens toujours pas a la derniere valeur

EDITION SPECIAL : HISTORIQUE DE MERDE

- Ce qu'on ecrit avec des ; && ect n'est pas mis dans l'historique toujours
- !ec   --> Premiere valeur de l'historique avec ec
- History dois faire le changement quand on appuis sur TAB (Si pas trouvé fait rien)
- Dois faire "zsh: event not found: commande" si pas trouvé et appuis sur entrée
- Empecher le lancement automatique ! (Changer la string et empêcher le lancement)
- !x --> (x etant un truc)
- Un espace remplace la valeur directement
- Le remplacement des valeurs est pas toujours fait
- Le rendu fait nimp (genre echo text && !?), lancement dans le mauvais sens ect c'est nimp
- Mettre des couleurs avec le prompt ? (genre histoire de couleur quoi)
- Voir ce que c'est cette histoire de # (codé mais pourquoi ?...)
- Affichage par le seigneur de la commande lancée..

Comment lutter contre la liste ci-dessus ?

	Il faut d'abord arrêter de lancer automatiquement la ligne en cas de présence d'un
	élément qui a besoin d'un changement ( genre !commande ), puis changer TOUT les éléments
	et permettre l'affichage de la ligne avec les changements (remplacement de la ligne actuelle).
	Ainsi avec un historique 8795 = ls et une commande précédente echo TEST FINI:
		echo TEST ; !8795 ; !?     deviendra     echo TEST ; ls ; echo TEST FINI
	Prendre en compte aussi le fait que le ! est un élément qui devrait être géré suivan les cas
	donc bien bien essayer des test de fou après

====================================================================


====================
=     ERROR404     =
===================================================================

- l'autocompletion ne remet pas le curseur au bon endroit.

- L autocompletion fait de la merde en cas de mouvement de la fenetre si il est ouvert

=====================
=     Changelog     =
====================================================================
13 Decembre 20h02 - ThomasV

- Segfault si operateur en dernier argument FIX

12 decembre 15h34 - jean-yves

-le resize est finit niveau termcaps mais encore a voir avec l'autocompletion

10 decembre 20h14 - ThomasV

- Norme
- Message d'erreur niveau acces rectifie (sinon pas valide dans certains cas)
- option -n dans Echo

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
