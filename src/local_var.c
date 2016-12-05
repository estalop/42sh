/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <chdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:43:10 by chdenis           #+#    #+#             */
/*   Updated: 2016/12/05 17:20:07 by chdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Gestion des variables locales au shell (VAR=value; echo $VAR)
*/

t_localvar	*g_localvars = NULL;

static void			local_var_update_export(char *name)
{
	t_localvar	*var;

	if (!(var = local_var_get(name)) || !var->exported)
		return ;
	env_setter(var->name, var->value);
}

/*
**	Set une variable et la creer si besoin
**	Return: 0 si erreur, 1 si set, 2 si créée et set
*/

int					local_var_set(char *name, char *value)
{
	t_localvar		*var;
	int				result;

	if (!name || !ft_strlen(name) || !ft_strisalphadigit(name))
		return (0);
	result = 1;
	if (!(var = local_var_get(name)))
		result = 2;
	if (var || (var = (t_localvar *)ft_memalloc(sizeof(t_localvar))))
	{
		free(var->name);
		free(var->value);
		var->name = ft_strdup(name);
		var->value = ft_strdup(value);
		if (result == 2 && ((var->next = g_localvars) || 1))
			g_localvars = var;
	}
	else
		result = 0;
	local_var_update_export(name);
	free(name);
	free(value);
	return (result);
}

t_localvar			*local_var_get(char *name)
{
	t_localvar		*var;

	if (!name)
		return (NULL);
	var = g_localvars;
	while (var)
	{
		if (ft_strequ(var->name, name))
			return (var);
		var = var->next;
	}
	return (NULL);
}

void				local_var_destroy(char *name)
{
	t_localvar		*var;
	t_localvar		*prev;

	var = local_var_get(name);
	if (!var)
		return ;
	if (var == g_localvars)
		g_localvars = var->next;
	else
	{
		prev = g_localvars;
		while (prev->next != var)
			prev = prev->next;
		prev->next = var->next;
	}
	free(var);
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
