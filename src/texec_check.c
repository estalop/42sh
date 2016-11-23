/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texec_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 16:51:24 by tbayet            #+#    #+#             */
/*   Updated: 2016/11/23 13:17:53 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocompletion.h"

int		texec_check(char *name, t_exec *tree)
{
	t_exec	*tmp;
	char	*ptr;

	tmp = tree;
	ptr = name;
	if (!tmp)
		return (0);
	tmp = tmp->next;
	while (*ptr)
	{
		while (tmp && (*ptr > tmp->c))
			tmp = tmp->change;
		if (!tmp || *ptr != tmp->c)
			return (0);
		ptr++;
		if (*ptr)
		{
			if (tmp && tmp->next)
				tmp = tmp->next;
			else
				return (0);
		}
	}
	return ((ft_strcmp(name, tmp->name) == 0) ? 1 : 0);
}
