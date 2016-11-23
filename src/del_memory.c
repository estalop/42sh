/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 16:53:47 by tbayet            #+#    #+#             */
/*   Updated: 2016/11/23 13:27:56 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocompletion.h"

t_exec	*texec_del(t_exec **tree)
{
	if (*tree)
	{
		if ((*tree)->next)
			texec_del(&((*tree)->next));
		if ((*tree)->change)
			texec_del(&((*tree)->change));
		if ((*tree)->name)
		{
			free((*tree)->name);
			(*tree)->name = NULL;
		}
		free(*tree);
		*tree = NULL;
	}
	return (NULL);
}

t_files	*tfiles_del(t_files **lst)
{
	if (*lst)
	{
		if ((*lst)->next)
			tfiles_del(&((*lst)->next));
		if ((*lst)->prev)
			tfiles_del(&((*lst)->prev));
		free(*lst);
		*lst = NULL;
	}
	return (NULL);
}

char	**tfiles_cancel(char **path, char **name, t_files **lst)
{
	if (path)
		ft_strdel(path);
	if (name)
		ft_strdel(name);
	if (lst)
		tfiles_del(lst);
	return (NULL);
}
