/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 21:35:05 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/15 15:45:53 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	char		*new;

	s1 = (s1 == NULL) ? "" : s1;
	s2 = (s2 == NULL) ? "" : s2		;
	if (s1 && s2)
	{
		i = ft_strlen(s1) + ft_strlen(s2);
		new = ft_strnew(i);
		if (new)
		{
			new = ft_strcpy(new, s1);
			new = ft_strcat(new, s2);
			return (new);
		}
	}
	return (NULL);
}

char	*ft_strjoin_special(char const *s1, char const *s2)
{
	char	*str;
	int		a;
	int		b;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (s1[ft_strlen(s1) - 1] != '/')
		s1 = ft_strjoin(s1, "/");
	a = 0;
	b = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}

char	*t(char const *s1, char const *s2)
{
	char	*str;
	int		a;
	int		b;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (s1[ft_strlen(s1) - 1] != '/')
		s1 = ft_strjoin(s1, "/");
	a = 0;
	b = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
