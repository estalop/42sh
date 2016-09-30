/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:07:30 by jbobin            #+#    #+#             */
/*   Updated: 2015/11/28 09:06:58 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < size)
	{
		i++;
	}
	k = i;
	while (i < size - 1 && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (k != size)
		dst[i] = '\0';
	while (src[j] != '\0')
		j++;
	return (k + j);
}
