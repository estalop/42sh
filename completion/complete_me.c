/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_me.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 14:59:27 by tbayet            #+#    #+#             */
/*   Updated: 2016/09/26 09:18:28 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocompletion.h"

static t_exec	*texec_get(char *str, t_exec *tree)
{
	t_exec	*tmp;
	char	*ptr;

	tmp = tree;
	ptr = str;
	if (!tmp)
		return (NULL);
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

char			**complete_me(char *str, t_exec *tree)
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
