/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_total_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 16:49:49 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/08 16:05:30 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_get_total_path(t_dlist *list)
{
	int		index;
	int		compteur;
	char	*tmp;

	index = 0;
	compteur = 0;
	tmp = ft_get_ele(list, ft_search_list(list, "PATH=")) + 5;
	while (tmp[index] != '\0')
	{
		if (tmp[index] == ':')
			compteur++;
		index++;
	}
	return (compteur);
}
