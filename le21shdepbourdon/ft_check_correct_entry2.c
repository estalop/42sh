/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_correct_entry2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 17:57:55 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/07 17:59:31 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_check_dquo(char *str)
{
	int		index;
	int		total;

	index = 0;
	total = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '"' && total == 0)
			total = 1;
		else if (str[index] == '"' && total == 1)
			total = 0;
		index++;
	}
	return (total);
}
