/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 15:59:31 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/08 16:03:54 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_get_size(char *str)
{
	int		index;
	int		compteur;

	index = 1;
	compteur = 2;
	while (str[index] != '\0')
	{
		if ((str[index] == ' ' || str[index] == '\t' || str[index] == '\n') && (
			str[index - 1] != ' ' || str[index - 1] != '\t' || str[index - 1]
			!= '\n'))
			compteur++;
		index++;
	}
	return (compteur);
}
