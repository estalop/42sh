/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 09:17:20 by jbobin            #+#    #+#             */
/*   Updated: 2016/10/04 15:48:31 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_arrow_side(char *tmp, char buf[4], t_termcaps *cap, int strlen)
{
	ft_end(cap, tmp, strlen);
	if (buf[2] == 'C' && (size_t)(cap->x - cap->neg) < ft_strlen(tmp))
		cap->x++;
	else if (buf[2] == 'D' && cap->x > cap->prompt)
		cap->x--;
	else
		tputs(cap->bl, 0, ft_output);
	ft_put_cursor(cap, tmp);
}

char		*ft_arrow_up(t_termcaps *cap, char *tmp)
{
	char	*new;

	if (cap->hist[cap->y] != NULL && cap->y < 500) // verifier que y'a un prochain historique
	{
		ft_reset(cap, tmp); // efface tout sur la ligne actuelle
		ft_putstr(cap->prom); // affiche le prompt
		ft_putstr(cap->hist[cap->y]); // affiche la commande au dessus dans l'historique
		cap->x = ft_strlen(cap->hist[cap->y]) + cap->prompt; // cap->x = pos du curseur, calcule a partir de len de prompt + commande
		new = ft_strsub(tmp, 0, (cap->prompt - cap->neg)); // LAISSER COMME SA 
		ft_strdel(&tmp); // LAISSER comme sa
		if (new != NULL)
			tmp = ft_strjoin(new, cap->hist[cap->y]); // ne pas toucher, remplacer cap->hist[cap->y] par le str de la nouvelle commande // laisser le new trkle
		else
			tmp = ft_strdup(cap->hist[cap->y]); // remplacer pareil histp[cap->y] par le string de l'historique
		ft_strdel(&new); // laisser
		cap->y++; // on s'en fout (remplacer par ma pos dans l'historique)
		cap->oldlen = ft_calculate_height(tmp, \
		ft_strlen(cap->hist[cap->y]) + cap->prompt, cap); // remplacer cap->hist[cap->y] par la string 

	}
	else
		tputs(cap->bl, 0, ft_output); // laisser comme sa
	return (tmp);
}

static void		ft_sub_arrow_down(t_termcaps *cap, char *tmp)
{
	cap->y--; // tu descends la pos actuelle dans l'histo
	ft_reset(cap, tmp); // tu vires l'actuel ecriture 
	ft_putstr(cap->prom);// tu affiches le prompt
	if (cap->y != 0) // tu verifies encore que c'est bon pour la pos
	{
		ft_putstr(cap->hist[cap->y - 1]); // t'affiches la prochaine commande 
		cap->x = ft_strlen(cap->hist[cap->y - 1]) + cap->prompt; // remplacer par mon historique
		cap->oldlen = ft_calculate_height(tmp, \
		ft_strlen(cap->hist[cap->y]) + cap->prompt, cap); // pareil mais avec l'anciene commande (strlen de la commande juste avant)
	}
	else
	{
		cap->oldlen = 0;
		cap->x = cap->prompt;
	}
}

char		*ft_arrow_down(t_termcaps *cap, char *tmp)
{
	char	*new;

	if (cap->y > 0) // verifier que c'est pas deja la premiere entree (que y'en a une precedente)
	{
		ft_sub_arrow_down(cap, tmp); // POUR LA NORME : voir au dessus
		new = ft_strsub(tmp, 0, (cap->prompt - cap->neg)); // je laisse
		ft_strdel(&tmp); // je laisse
		if (cap->y != 0) // verifie que c'est pas le premier 
		{
			if (new == NULL)
				tmp = ft_strdup(cap->hist[cap->y - 1]); // remplacer par mon histo
			else
				tmp = ft_strjoin(new, cap->hist[cap->y - 1]); // remplacer par mon histo
			ft_strdel(&new); // tout laisser apres
		}
		else if (new != NULL)
			tmp = new;
		else
			tmp = NULL;
	}
	else
		tputs(cap->bl, 0, ft_output);
	return (tmp);
}

void		ft_newputstr(char const *str, t_termcaps *cap)
{
	int	i;
	int x;

	i = 0;
	x = cap->prompt;
	while (str[i] != '\0')
	{
		if (str[i] == '\t')
		{
			x = x + (8 - (x % 8));
			write(1, &str[i], 1);
		}
		if (str[i] != '\t')
		{
			write(1, &str[i], 1);
			x = str[i] == '\n' ? 0 : x + 1;
		}
		if (x >= cap->whidth)
		{
			tputs(cap->sf, 0, ft_output);
			tputs(cap->cr, 0, ft_output);
			x = 0;
		}
		i++;
	}
}
