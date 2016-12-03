/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <chdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:07:29 by chdenis           #+#    #+#             */
/*   Updated: 2016/12/03 16:51:17 by chdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char			*parse_export(char *s)
{
	char	*name;
	char	*value;
	char	*equal;

	if (!(equal = ft_strchr(s, '=')))
	{
		name = ft_strdup(s);
		value = ft_strnew(0);
	}
	else
	{
		name = ft_strsub(s, 0, equal - s - 1);
		value = ft_strdup(equal + 1);
	}
	
	// check que name est valide (alpha, num, ou underscore) (not a valid identifier)
}

static int			parse_export_option(char *s)
{
	while (*s)
	{
		if (*s == 'p')
			return (1);
	}
	return (0);
}

int					ft_export(char *s)
{
	char	*e;
	int		options;
	int		p;
	char	**args;
	char	**a;

	options = 0;
	args = ft_strsplit(s, ' ');
	a = args;
	while (*a)
	{
		if (*s == '-' && !options)
			p = parse_option(*a + 1) || p;
		else if ((options = 1))
			parse_export(*a);
		a++;
	}
	ft_free_tab(args);
	// while (*s)
	// {
	// 	if (*s == ' ')
	// 		s++;
	// 	e = ft_strchr(s, ' ');
	// 	if (!e)
	// 		e = s + ft_strlen(e);
	// 	if (*s == '-' && !options)
	// 		p = parse_option(s + 1) || p;
	// 	else if ((options = 1))
	// 		parse_export(ft_strsub(s, 0, e - s));
	// 	s = e;
	// }
	// pour chaque args, exporter local var, la creer si pas fait puis
	// attacher la envar a la local, pour les futures modifs
	// option -p pour afficher output
	return (0);
}
