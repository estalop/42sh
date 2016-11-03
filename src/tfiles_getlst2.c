/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tfiles_getlst2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:20:53 by tbayet            #+#    #+#             */
/*   Updated: 2016/11/03 11:15:26 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocompletion.h"

static int	tfiles_count(t_files *lst)
{
	int	i;

	if (lst)
	{
		i = 1;
		if (lst->prev)
			i += tfiles_count(lst->prev);
		if (lst->next)
			i += tfiles_count(lst->next);
	}
	else
		return (0);
	return (i);
}

static int	tfiles_totabfill(t_files **lst, char **tab, int i)
{
	if (*lst)
	{
		if ((*lst)->prev)
			i = tfiles_totabfill(&((*lst)->prev), tab, i);
		tab[i] = (*lst)->name;
		i++;
		if ((*lst)->next)
			i = tfiles_totabfill(&((*lst)->next), tab, i);
		free(*lst);
		*lst = NULL;
	}
	else
		return (0);
	return (i);
}

char		**tfiles_totab(t_files **lst)
{
	int			len;
	char		**tab;

	len = tfiles_count(*lst);
	if (!(tab = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	tab[len] = NULL;
	tfiles_totabfill(lst, tab, 0);
	return (tab);
}
