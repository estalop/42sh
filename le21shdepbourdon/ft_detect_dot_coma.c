/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_dot_coma.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 11:09:43 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/11 11:24:32 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_detect_dot_coma(char *str)
{
	int		index;
	int		total;

	index = 0;
	total = 1;
	while (str[index] != '\0')
	{
		if (str[index] == ';')
			total++;
		index++;
	}
	return (total);
}
