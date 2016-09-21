/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:31:10 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/13 08:57:01 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		a;
	int		sign;
	int		result;

	result = 0;
	sign = 1;
	a = 0;
	while (str[a] == '\t'
			|| str[a] == '\v'
			|| str[a] == '\f'
			|| str[a] == '\n'
			|| str[a] == '\r'
			|| str[a] == ' ')
		a++;
	if (str[a] == '-')
		sign = -sign;
	if (str[a] == '+' || str[a] == '-')
		a++;
	while (str[a] >= '0' && str[a] <= '9')
	{
		result = result * 10 + str[a] - 48;
		a++;
	}
	result = result * sign;
	return (result);
}
