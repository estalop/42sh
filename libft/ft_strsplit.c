/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:12:30 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/07 15:29:58 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_count(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (-42);
	while (s[i] != '\0')
	{
		i++;
		if (s[i] == c && s[i - 1] != c)
			j++;
	}
	if (s[i - 1] != c)
		j++;
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		l;
	char	**t;

	l = 0;
	i = 0;
	j = ft_count(s, c);
	if ((t = (char**)malloc(sizeof(char*) * (j + 1))) == NULL || j < 0)
		return (NULL);
	while (l < ft_count(s, c))
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if ((t[l] = ft_strsub(s, j, i - j)) == NULL)
			return (NULL);
		l++;
	}
	t[l] = NULL;
	return (t);
}
