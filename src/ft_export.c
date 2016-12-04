/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <chdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:07:29 by chdenis           #+#    #+#             */
/*   Updated: 2016/12/04 14:23:16 by chdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			export_add_var(char *name, char *value, int p)
{
	t_localvar	*var;

	if (!local_var_set(ft_strdup(name), ft_strdup(value)))
		return ;
	var = local_var_get(name);
	// TODO: ajouter la variable (name, value) a l'environnement
	var->exported = 1;
	if (!p)
		return ;
	if (ft_strlen(value))
		ft_printf("export: %s=%s\n", name, value);
	else
		ft_printf("export: %s\n", name);
}

static void			parse_export_arg(char *s, int p)
{
	char		*name;
	char		*value;
	char		*equal;

	equal = ft_strchr(s, '=');
	name = equal ? ft_strsub(s, 0, equal - s) : ft_strdup(s);
	value = equal ? ft_strdup(equal + 1) : ft_strnew(0);
	if (ft_strisalphadigit(name))
	{
		if (equal || !local_var_get(name))
			export_add_var(name, value, p);
	}
	else
		ft_printf("export: '%s' not a valid identifier\n", name);
	free(name);
	free(value);
}

static int			parse_export_option(char *s)
{
	while (*s && *s != 'p')
		s++;
	return (*s == 'p');
}

/*
**	export builtin: exporte les variables données en affectants si besoin
**	si -p est spécifié, affiche les variables exportées sur la sortie standard
*/

int					ft_export(char *s)
{
	int		options;
	int		p;
	char	**args;
	char	**a;

	options = 0;
	args = ft_strsplit(s, ' ');
	a = args + 1;
	p = 0;
	while (*a)
	{
		if (**a == '-' && !options)
			p = parse_export_option(*a + 1) || p;
		else if ((options = 1))
			parse_export_arg(*a, p);
		a++;
	}
	ft_free_tab(&args);
	return (0);
}
