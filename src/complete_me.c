/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_me.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <tbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 14:59:27 by tbayet            #+#    #+#             */
/*   Updated: 2016/11/03 14:20:44 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_exec	*texec_get(char *str, t_exec *tree)
{
	t_exec	*tmp;
	char	*ptr;

	tmp = tree;
	ptr = str;
	if (!tmp)
		return (NULL);
	if (!(*ptr))
		return (tmp);
	tmp = tmp->next;
	while (*ptr)
	{
		while (tmp && (*ptr > tmp->c))
			tmp = tmp->change;
		if (!tmp || *ptr != tmp->c)
			return (NULL);
		ptr++;
		if (*ptr)
		{
			if (tmp && tmp->next)
				tmp = tmp->next;
			else
				return (NULL);
		}
	}
	return (tmp);
}

static int		complete_fill(t_exec *tree, char **res, int i, int stop)
{
	if (tree->name)
		res[i++] = tree->name;
	if (tree->next)
		i = complete_fill(tree->next, res, i, 0);
	if (!stop && tree->change)
		i = complete_fill(tree->change, res, i, 0);
	return (i);
}

static char		**complete_me(char *str, t_exec *tree)
{
	char	**res;
	t_exec	*tmp;
	int		len;

	if (!(tmp = texec_get(str, tree)))
		len = 0;
	else
		len = tmp->nbelems;
	if (!(res = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	res[len] = NULL;
	if (!len)
		return (res);
	complete_fill(tmp, res, 0, 1);
	return (res);
}

static int		is_spec_separator(char c)
{
	if ( c == ';' || c == '&' || c == '|' || c == '>' || c == '<') //etc
		return (1);
	else
		return (0);
}

char			**autocompletion(char *line, int i, t_exec *tree, char *pwd)
{
	int		j;
	char	**table;

	table = NULL;
	if (line)
	{
		i--;
		while (i >= 0 && line[i] != ' ' && line[i] != '\t' && line[i] != '\v'
				&& !is_spec_separator(line[i]))
			i--;
		j = i;
		i++;
		while (j >= 0 && ( line[j] == ' ' || line[j] == '\t' || line[j] == '\v'))
			j--;
		if (j == -1 || is_spec_separator(line[j]))
			table = complete_me(line + i, tree);
		else
			table = tfiles_getlst(pwd, line + i);
		return (table);
	}
	return (NULL);
}
