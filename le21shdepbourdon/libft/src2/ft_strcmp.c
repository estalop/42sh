/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:03:31 by pbourdon          #+#    #+#             */
/*   Updated: 2016/07/18 19:01:58 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				a;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!*str2)
		return (*str1);
	a = 0;
	while (str1[a] != '\0' && str2[a] != '\0' && str1[a] == str2[a])
		a++;
	return (str1[a] - str2[a]);
}

int		s(const char *s1)
{
	int				a;
	unsigned char	*str1;
	unsigned char	*str2;
	const char		*s2;

	s2 = malloc(sizeof(char) * 4);
	s2 = "..";
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!*str2)
		return (*str1);
	a = 0;
	while (str1[a] != '\0' && str2[a] != '\0' && str1[a] == str2[a])
		a++;
	return (str1[a] - str2[a]);
}

int		e(const char *s1)
{
	int				a;
	unsigned char	*str1;
	unsigned char	*str2;
	const char		*s2;

	s2 = malloc(sizeof(char) * 4);
	s2 = ".";
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!*str2)
		return (*str1);
	a = 0;
	while (str1[a] != '\0' && str2[a] != '\0' && str1[a] == str2[a])
		a++;
	return (str1[a] - str2[a]);
}
