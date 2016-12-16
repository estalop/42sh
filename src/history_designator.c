/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_designator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviviand <tviviand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:56:36 by tviviand          #+#    #+#             */
/*   Updated: 2016/12/16 17:30:06 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// !n   n eme command line
// !-n	idem a l'envers
// !! 	derniere commande dans l'historique
// !str	plus recente commande commencant par str
// !?s	plus recente contenant s jusqu'a un ? ou newline
// !#	remet tout ce qu'il y a avant

static char		*history_designator_n(char *s, char *c, char **replace)
{
	int		n;
	char	*end;

	n = 0;
	// si ! mettre n a -1, sinon atoi
	if (*c == '!'&& (n = -1))
		end = c + 1;
	else if ((*c == '-' || ft_isdigit(*c) && (n = ft_atoi(c))))
	{
		end = *c == '-' ? c + 1 : c;
		while (ft_isdigit(*end))
			end++;
	}
	else
		return (NULL);
	if (!n)
		return (NULL);
	// chercher dans l'historique la n eme
}


char			*history_designator(char *s)
{
	char	*c;
	char	*end;
	char	*replace;

	end = NULL;
	c = s - 1;
	while ((c = ft_strchr(c, '!')))
	{
		c++;
		if ((end = history_designator_n(s, c, &replace)) ||
			(end = history_designator_beginsby(s, c, &replace)) ||
			(end = history_designator_contains(s, c, &replace)) ||
			(end = history_designator_typed(s, c, &replace)))
		{
			s = ft_strsplice(s, c - 1, e - c + 1, replace);
			// free(replace);  // a voir si besoin
		}
		else
		{
			// printf !stringtnewline: event not found
		}
		if (end)
			c = end;
	}
	return (s);
}
