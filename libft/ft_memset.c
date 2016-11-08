/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:17:46 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/08 11:13:56 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*n;
	unsigned int	e;

	n = b;
	e = 0;
	while (e < len)
	{
		n[e] = c;
		e++;
	}
	return ((void*)n);
}
