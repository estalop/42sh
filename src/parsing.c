/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <chdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:47:56 by chdenis           #+#    #+#             */
/*   Updated: 2016/12/13 13:57:22 by chdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Fonction mere des fonctions parsing (l'ordre d'execution est important)
*/

char				*parse_process(char *s)
{
	s = parse_dollar_pipeline_exit_status(s);
	s = parse_dollar_variable(s);
	s = parse_local_var(s);
	return (s);
}

/*
**	Parse la commande pour voir s'il y a une affectation
**	(var=value var2=value; ls; echo $var)
*/

char				*parse_local_var(char *s)
{
	char	*equal;
	char	*end;
	char	*new;
	char	*rec;

	end = ft_strchr(s, ' ');
	if (!end)
		end = s + ft_strlen(s);
	equal = ft_strchr(s, '=');
	if (!equal || equal > end || equal[-1] == ' ' || equal == s)
		return (s);
	if (!local_var_set(ft_strsub(s, 0, equal - s),
		ft_strsub(equal, 1, end - (equal + 1))))
		return (s);
	while (*end && *end == ' ')
		end++;
	rec = parse_local_var(ft_strdup(end));
	new = (rec != end ? rec : ft_strdup(end));
	if (new != rec)
		free(rec);
	if (!new)
		return (s);
	free(s);
	return (new);
}
