/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_designators.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <chdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:56:36 by tviviand          #+#    #+#             */
/*   Updated: 2016/12/16 21:09:47 by chdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_prstruct	*g_process;

/*
**	!n & !-n & !!
*/

char		*history_designator_n(char *c, char **replace)
{
	int		n;
	char	*end;

	n = 0;
	if (*c == '!' && (n = -1))
		end = c + 1;
	else if ((*c == '-' || ft_isdigit(*c)) && (n = ft_atoi(c)))
	{
		end = *c == '-' ? c + 1 : c;
		while (ft_isdigit(*end))
			end++;
	}
	else
		return (NULL);
	if (!n)
		return (NULL);
	if (!(*replace = ft_get_element_from_list(g_process->histo2, n)))
		return (NULL);
	*replace = ft_strdup(*replace);
	return (end);
}

/*
**	!string
*/

char		*history_designator_beginsby(char *c, char **replace)
{
	char	*end;
	t_node	*l;
	char	*last;

	end = c;
	while (*end && !IS_SPACE(*end))
		end++;
	l = g_process->histo2->p_head;
	last = NULL;
	while (l)
	{
		if (ft_strnequ(l->data, c, end - c))
			last = l->data;
		l = l->p_next;
	}
	if (!last)
		return (NULL);
	*replace = ft_strdup(last);
	return (end);
}

/*
**	!?string?
*/

char		*history_designator_contains(char *c, char **replace)
{
	char	*end;
	char	*to_search;
	t_node	*l;
	char	*last;

	if (*c != '?')
		return (NULL);
	c++;
	end = c;
	while (*end && *end != '?')
		end++;
	l = g_process->histo2->p_head;
	to_search = ft_strsub(c, 0, end - c);
	last = NULL;
	while (l)
	{
		if (ft_strstr(l->data, to_search))
			last = l->data;
		l = l->p_next;
	}
	free(to_search);
	if (!last)
		return (NULL);
	*replace = ft_strdup(last);
	return (end + (*end == '?' ? 1 : 0));
}

/*
**	!# (tout ce qui a été tapé avant)
*/

char		*history_designator_typed(char *s, char *c, char **replace)
{
	char *end;

	if (*c != '#')
		return (NULL);
	end = c + 1;
	*replace = ft_strsub(s, 0, (c - 2) - s);
	return (end);
}
