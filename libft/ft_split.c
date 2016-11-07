/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 08:37:01 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/07 15:36:39 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_count(char const *s)
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
		if ((s[i] == ' ' || s[i] == '\t') \
			&& (s[i - 1] != ' ' && s[i - 1] != '\t'))
			j++;
	}
	if (s[i - 1] != ' ' && s[i - 1] != '\t')
		j++;
	return (j);
}

char			**ft_split(char const *s)
{
	int		i;
	int		j;
	int		l;
	char	**t;

	l = 0;
	i = 0;
	j = ft_count(s);
	if (j < 0 || (t = (char**)malloc(sizeof(char*) * (j + 1))) == NULL)
		return (NULL);
	while (l < ft_count(s))
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		j = i;
		while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t')
			i++;
		if ((t[l] = ft_strsub(s, j, i - j)) == NULL)
			return (NULL);
		l++;
	}
	t[l] = NULL;
	return (t);
}
