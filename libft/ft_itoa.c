/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:08:27 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/28 13:18:45 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_fill(char *str, int i, int k)
{
	while (i >= 10)
	{
		str[k] = (i % 10) + '0';
		i = i / 10;
		k--;
	}
	str[k] = i + '0';
	return (str);
}

static int	ft_count(unsigned int i, int n)
{
	int	j;

	j = n == 1 ? 2 : 1;
	while (i >= 10)
	{
		i = i / 10;
		j++;
	}
	return (j);
}

char		*ft_itoa(int n)
{
	char			*str;
	unsigned int	i;
	int				j;
	int				k;

	i = (unsigned int)(n >= 0 ? n : -n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	j = n >= 0 ? 0 : 1;
	k = ft_count(i, j);
	if (!(str = ft_strnew(k)))
		return (NULL);
	str = ft_fill(str, i, --k);
	if (j == 1)
		str[0] = '-';
	return (str);
}
