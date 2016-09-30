/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:13:28 by jbobin            #+#    #+#             */
/*   Updated: 2016/04/01 17:38:44 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] &&\
		i < n - 1)
		i++;
	if (s1[i] < 0 && s2[i] < 0)
		return (int)(s2[i] - s1[i]);
	if (s1[i] < 0)
		return (int)(-s1[i] - s2[i]);
	if (s2[i] < 0)
		return (int)(s1[i] + s2[i]);
	return (int)(s1[i] - s2[i]);
}
