/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:12:30 by jbobin            #+#    #+#             */
/*   Updated: 2016/03/07 08:33:30 by jbobin           ###   ########.fr       */
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
	if (i != 0)
		j++;
	return (j);
}

static int		ft_counts(char const *s, char c, int i)
{
	int j;

	j = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		j++;
	}
	return (j + 1);
}

static	char	*ft_fill(char const *s, char c, int i)
{
	char	*t;
	int		k;

	k = 0;
	t = (char*)malloc(sizeof(char) * ft_counts(s, c, i));
	if (t == NULL)
		return (NULL);
	while (s[i] != '\0' && s[i] != c)
	{
		t[k] = s[i];
		i++;
		k++;
	}
	t[k] = '\0';
	return (t);
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
	while (l < j)
	{
		while (s[i] == c)
			i++;
		if ((t[l] = ft_fill(s, c, i)) == NULL)
			return (NULL);
		while (s[i] != '\0' && s[i] != c)
			i++;
		l++;
	}
	if (s[i - 1] == c)
		t[l - 1] = NULL;
	else
		t[l] = NULL;
	return (t);
}
