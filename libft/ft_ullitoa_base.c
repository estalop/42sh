/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviviand <tviviand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:34:01 by tviviand          #+#    #+#             */
/*   Updated: 2016/04/20 18:34:02 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ullitoa_base(unsigned long long int v, char *base)
{
	size_t					bl;
	int						i;
	unsigned long long int	nbr;
	char					*str;

	if (!base || (bl = ft_strlen(base)) < 2)
		return (NULL);
	nbr = v;
	i = 1;
	while (nbr / bl > 0)
		i++ && (nbr /= bl);
	if (!(str = ft_strnew(i)))
		return (NULL);
	nbr = v;
	while (i)
	{
		i--;
		str[i] = base[nbr % bl];
		nbr /= bl;
	}
	return (str);
}
