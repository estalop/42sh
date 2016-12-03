/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <chdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:43:10 by chdenis           #+#    #+#             */
/*   Updated: 2016/12/03 15:18:48 by chdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Gestion des variables locales au shell (VAR=value; echo $VAR)
*/

t_localvar	*g_localvars = NULL;


/*
**	Set une variable et la creer si besoin
**	Return: 0 si erreur, 1 si set, 2 si créée et set
*/

int					local_var_set(char *name, char *value)
{
	t_localvar		*var;
	int				result;

	if (!name)
		return (0);
	result = 1;
	if (!(var = local_var_get(name)))
		result = 2;
	if (!var &&
		!(var = (t_localvar *)ft_memalloc(sizeof(t_localvar))))
		return (0);
	if (var->name)
		free(var->name);
	if (var->value)
		free(var->value);
	var->name = name;
	var->value = value;
	if (result == 1)
		return (result);
	var->next = g_localvars;
	g_localvars = var;
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
**	(var=value; ls; echo $var)
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
	if (!equal || equal > end || equal - 1 == ' '))
		return (s);
	local_var_set(ft_strsub(s, 0, equal - s),
		ft_strsub(equal, 1, end - (equal + 1)));
	while (*end && *end == ' ')
		end++;
	rec = parse_local_var(ft_strdup(end));
	new = (rec != end ? rec : ft_strdup(end));
	if (new != rec)
		free(rec);
	if (!new)
		return (s);
	free(s);

	// t_localvar *t = g_localvars;
	// while (t)
	// {
	// 	ft_printf("var %s = %s\n", t->name, t->value);
	// 	t = t->next;
	// }

	return (new);
}

void				free_local_var(void)
{
	t_localvar	*next;

	while (g_localvars)
	{
		next = g_localvars->next;
		free(g_localvars);
		g_localvars = next;
	}
}
