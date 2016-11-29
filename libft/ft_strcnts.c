/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:03:09 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/29 14:08:46 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcnts(char const *str, char const *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str || !s)
		return (0);
	while (str[i] != '\0')
	{
		if (ft_strncmp(&str[i], s, ft_strlen(s)) == 0)
		{
			++j;
			i += ft_strlen(s);
		}
		++i;
	}
	return (j);
}
