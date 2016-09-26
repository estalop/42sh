/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:51:29 by jbobin            #+#    #+#             */
/*   Updated: 2016/09/26 10:28:41 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s1[i] < 0 && s2[i] < 0)
		return (int)(s2[i] - s1[i]);
	if (s1[i] < 0)
		return (int)(-s1[i] - s2[i]);
	if (s2[i] < 0)
		return (int)(s1[i] + s2[i]);
	return (int)(s1[i] - s2[i]);
}
