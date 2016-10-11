/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviviand <tviviand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:21:17 by tviviand          #+#    #+#             */
/*   Updated: 2016/04/20 18:21:21 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_llitoa(long long int n)
{
	int						neg;
	unsigned long long int	nbr;
	int						i;
	char					*str;

	neg = n < 0;
	nbr = neg ? -n : n;
	i = 1 + neg;
	while (nbr / 10 > 0)
		i++ && (nbr /= 10);
	if ((str = ft_strnew(i)) == NULL)
		return (NULL);
	if (neg)
		(str[0] = '-') && i--;
	nbr = neg ? -n : n;
	while (i)
	{
		i--;
		str[i + neg] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
