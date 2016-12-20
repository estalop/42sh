/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:27:04 by jbobin            #+#    #+#             */
/*   Updated: 2016/12/20 16:31:56 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	countnbtrim(char *s)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
			nb++;
		i++;
	}
	return (nb);
}

char		*ft_strctrim(char *s)
{
	int		len;
	char	*str;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	if (countnbtrim(s) == 0)
		return (s);
	len = ft_strlen(s) - countnbtrim(s);
	if (!(str = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		j = i;
		while (s[j] && s[j] != '\'' && s[j] != '\"')
			j++;
		str = ft_strncat(str, s + i, j - i);
		i = (s[j]) ? j + 1 : j;
	}
	free(s);
	s = NULL;
	return (str);
}
