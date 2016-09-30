/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:17:43 by jbobin            #+#    #+#             */
/*   Updated: 2015/11/30 11:12:36 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*st1;
	unsigned char	*st2;

	if (n == 0)
		return (0);
	st1 = (unsigned char*)s1;
	st2 = (unsigned char*)s2;
	i = 0;
	while (st1[i] == st2[i] && i < (n - 1))
		i++;
	return (int)(st1[i] - st2[i]);
}
