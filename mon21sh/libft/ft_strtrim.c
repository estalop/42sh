/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:27:04 by jbobin            #+#    #+#             */
/*   Updated: 2015/11/30 11:20:51 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count(char const *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		i = 0;
	return (i);
}

static char	*ft_strfill(char const *s, int i, int j)
{
	char	*str;
	int		k;

	k = 0;
	str = (char*)malloc(sizeof(char) * (i - j + 1));
	if (str == NULL)
		return (NULL);
	while (j <= i)
	{
		str[k] = s[j];
		k++;
		j++;
	}
	str[k] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = ft_count(s);
	j = i;
	while (s[i] != '\0')
		i++;
	while ((s[i] == '\0' || s[i] == ' ' || s[i] == '\t' || s[i] == '\n')\
		&& i > 0)
		i--;
	if (i == j && j == 0)
	{
		str = (char*)malloc(sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = ft_strfill(s, i, j);
	if (str == NULL)
		return (NULL);
	return (str);
}
