/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <chdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:07:29 by chdenis           #+#    #+#             */
/*   Updated: 2016/12/05 16:59:11 by chdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			export_add_var(char *name, char *value, int p, int son)
{
	t_localvar	*var;

	var = local_var_get(name);
	if (value)
		local_var_set(ft_strdup(name), ft_strdup(value));
	if (!p || !son)
		return ;
	if (ft_strlen(value))
		ft_printf("export: %s=%s\n", name, value);
	else if (var)
		ft_printf("export: %s\n", name);
}

static void			parse_export_arg(char *s, int p, int son)
{
	char		*name;
	char		*value;
	char		*equal;
	t_localvar	*var;

	equal = ft_strchr(s, '=');
	name = equal ? ft_strsub(s, 0, equal - s) : ft_strdup(s);
	value = equal ? ft_strdup(equal + 1) : NULL;
	if (ft_strisalphadigit(name))
	{
		export_add_var(name, value, p, son);
		var = local_var_get(name);
		if (var && (var->exported = 1))
			env_setter(name, var->value);
	}
	else if (son)
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

int					ft_export(char *s, int son)
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
			parse_export_arg(*a, p, son);
		a++;
	}
	ft_free_tab(&args);
	if (son)
		exit(0);
	return (-1);
}
