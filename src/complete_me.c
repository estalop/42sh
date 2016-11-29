/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_me.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <tbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 14:59:27 by tbayet            #+#    #+#             */
/*   Updated: 2016/11/29 14:15:53 by jbobin           ###   ########.fr       */
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
		if (++ptr && *ptr)
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
	{
		if (!(res[i++] = ft_strdup(tree->name)))
		{
			ft_free_tab(&res);
			return (-1);
		}
	}
	if (tree->next)
	{
		if ((i = complete_fill(tree->next, res, i, 0)) == -1)
			return (-1);
	}
	if (!stop && tree->change)
	{
		if ((i = complete_fill(tree->change, res, i, 0)) == -1)
			return (-1);
	}
	return (i);
}

static char		**complete_me(char *str, t_exec *tree)
{
	char	**res;
	t_exec	*tmp;
	int		len;
	int		i;

	if (!(tmp = texec_get(str, tree)))
		return (NULL);
	else
		len = tmp->nbelems;
	if (!(res = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	i = 0;
	while (i <= len)
		res[i++] = NULL;
	if (!len)
		return (res);
	if (complete_fill(tmp, res, 0, 1) == -1)
		return (NULL);
	return (res);
}

int				is_spec_separator(char c)
{
	if (c == ';' || c == '&' || c == '|')
		return (1);
	else
		return (0);
}

char			**autocompletion(char *line, int i, t_exec *tree, char *pwd)
{
	int		j;
	int		len;
	char	**table;
	char	*value;

	table = (line) ? NULL : complete_me("", tree);
	if (line)
	{
		len = i--;
		while (i >= 0 && line[i] != ' ' && line[i] != '\t' && line[i] != '\v'
				&& !is_spec_separator(line[i]))
			i--;
		j = i++;
		while (j >= 0 && (line[j] == ' ' || line[j] == '\t' || line[j] == '\v'))
			j--;
		if (!(value = ft_strndup(line + i, len - i)))
			return (NULL);
		if ((j == -1 || is_spec_separator(line[j]))
			&& !(table = complete_me(value, tree)))
			table = tfiles_getlst(pwd, value);
		else if (!table)
			table = tfiles_getlst(pwd, value);
		free(value);
	}
	return (table);
}
