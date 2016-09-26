/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 16:53:47 by tbayet            #+#    #+#             */
/*   Updated: 2016/09/21 16:24:28 by tbayet           ###   ########.fr       */
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
