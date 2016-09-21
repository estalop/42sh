/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_from_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 22:34:04 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/18 18:03:25 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tab_from_list(t_dlist *list)
{
	t_node		*p_temp;
	char		**env;
	int			c;

	p_temp = list->p_head;
	env = (char **)malloc((ft_list_size(list->p_head) + 1) * sizeof(char *));
	c = 0;
	while (p_temp != NULL)
	{
		env[c] = ft_strdup(p_temp->data);
		p_temp = p_temp->p_next;
		c++;
	}
	env[c] = 0;
	return (env);
}
