/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviviand <tviviand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:34:07 by tviviand          #+#    #+#             */
/*   Updated: 2016/04/20 18:34:09 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ullitoa(unsigned long long int n)
{
	unsigned long long int	nbr;
	int						i;
	char					*str;

	i = 1;
	nbr = n;
	while (nbr / 10 > 0)
		i++ && (nbr /= 10);
	if ((str = ft_strnew(i)) == NULL)
		return (NULL);
	nbr = n;
	while (i)
	{
		i--;
		str[i] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
