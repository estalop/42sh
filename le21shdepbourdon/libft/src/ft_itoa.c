/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:39:39 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/13 08:56:52 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static		void	ft_calc_len(int n, int *len, int *a)
{
	*len = 1;
	if (n >= 0)
	{
		*len = 0;
		n = -n;
	}
	*a = 1;
	while (n / *a < -9)
	{
		*a = *a * 10;
		*len = *len + 1;
	}
}

char				*ft_itoa(int n)
{
	int		a;
	int		len;
	char	*new;
	int		index;

	ft_calc_len(n, &len, &a);
	index = 0;
	new = malloc(len * sizeof(char) + 1);
	if (new == NULL)
		return (NULL);
	if (n < 0)
	{
		new[index] = '-';
		index++;
	}
	if (n > 0)
		n = -n;
	while (a >= 1)
	{
		new[index] = -(n / a % 10) + 48;
		a = a / 10;
		index++;
	}
	new[index++] = '\0';
	return (new);
}
