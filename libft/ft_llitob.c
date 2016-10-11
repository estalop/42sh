/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitob.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviviand <tviviand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:21:27 by tviviand          #+#    #+#             */
/*   Updated: 2016/04/20 18:21:28 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_llitob(long long int n)
{
	int		len;
	char	*res;

	len = !n ? 1 : ft_binsize(n);
	if (!(res = ft_strnew(len + 1)))
		return (NULL);
	len--;
	while (n && len >= 0)
	{
		res[len--] = (n & 1) + '0';
		n = n >> 1;
	}
	return (res);
}
