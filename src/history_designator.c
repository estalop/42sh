/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_designator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <chdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:56:36 by tviviand          #+#    #+#             */
/*   Updated: 2016/12/16 20:43:47 by chdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_prstruct	*g_process;

/*
**	check si ! est present et passe en revue les 4 fonctions
**	pour savoir si ça doit etre remplacé
*/

static char		*history_designator_parse(char *s, char *c, char **replace)
{
	char	*end;

	if ((end = history_designator_n(c, replace)) ||
		(end = history_designator_typed(s, c, replace)) ||
		(end = history_designator_contains(c, replace)) ||
		(end = history_designator_beginsby(c, replace)))
		return (end);
	return (NULL);
}

char			*history_designator(char *s)
{
	char	*c;
	char	*end;
	char	*replace;
	char	*err;
	int		l;

	end = NULL;
	err = NULL;
	c = s;
	while ((c = ft_strchr(c, '!')) && c++ && !err)
	{
		l = c - s + 1;
		if ((end = history_designator_parse(s, c, &replace)) &&
			ft_strsplice(&s, c - 1, end - c + 1, replace))
			free(replace);
		else if ((g_process->stop = 1))
		{
			err = c - 1;
			while (*err && !IS_SPACE(*err))
				err++;
			ft_printf("42sh: %.*s: event not found\n", (int)(err - c), c);
		}
		c = s + l;
	}
	return (s);
}
