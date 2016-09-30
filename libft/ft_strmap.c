/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:15:46 by jbobin            #+#    #+#             */
/*   Updated: 2015/11/30 11:18:29 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	i = 0;
	if (s != NULL && f != NULL)
	{
		while (s[i] != '\0')
			i++;
		str = (char*)malloc(sizeof(char) * (i + 1));
		i = 0;
		while (s[i] != '\0')
		{
			str[i] = f(s[i]);
			i++;
		}
		return (str);
	}
	else
		return (NULL);
}
