/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texec_new                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 16:22:01 by tbayet            #+#    #+#             */
/*   Updated: 2016/11/09 14:59:39 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocompletion.h"

t_exec	*texec_new(char c, char *name)
{
	t_exec	*new;

	if (!(new = (t_exec*)malloc(sizeof(t_exec))))
		return (NULL);
	if (name)
	{
		if (!(new->name = ft_strjoin(name, " ")))
		{
			free(new);
			return (NULL);
		}
	}
	else
		new->name = NULL;
	new->nbelems = 0;
	new->c = c;
	new->next = NULL;
	new->change = NULL;
	return (new);
}
