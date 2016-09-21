/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_auto_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 16:26:38 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/08 16:08:06 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*ft_reset(char *str, int *compteur)
{
	int		index;

	*compteur = 0;
	index = 0;
	while (str[index] != '\0')
	{
		str[index] = '\0';
		index++;
	}
	return (str);
}

char	*fuck(char *retur, int compteur)
{
	retur[compteur] = '/';
	retur[compteur + 1] = '\0';
	return (retur);
}

char	*ft_get_auto_path(int x, t_dlist *list, int drop, int index)
{
	char	*temp;
	char	*retur;
	int		compteur;

	compteur = 0;
	retur = malloc(sizeof(char) * ft_strlen(ft_get_ele(list,
		ft_search_list(list, "PATH"))) + 5);
	temp = ft_get_ele(list, ft_search_list(list, "PATH=")) + 5;
	while (temp[index] != '\0')
	{
		while (temp[index] != '\0' && temp[index] != ':')
		{
			retur[compteur] = temp[index];
			index++;
			compteur++;
		}
		drop++;
		retur = fuck(retur, compteur);
		if (drop == x)
			return (retur);
		retur = ft_reset(retur, &compteur);
		index++;
	}
	return (NULL);
}
