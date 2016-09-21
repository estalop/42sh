/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:04:52 by jbobin            #+#    #+#             */
/*   Updated: 2015/11/30 11:18:46 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s != NULL && f != NULL)
	{
		while (s[i] != '\0')
			i++;
		str = (char*)malloc(sizeof(char) * (i + 1));
		i = 0;
		while (s[i] != '\0')
		{
			str[i] = f(i, s[i]);
			i++;
		}
		return (str);
	}
	else
		return (NULL);
}
