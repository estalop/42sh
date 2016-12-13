/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <chdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 00:22:09 by chdenis           #+#    #+#             */
/*   Updated: 2016/12/13 13:58:17 by chdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	ft_strsplice supprime de *str le bout de string commençant à *begin
**	et se terminant à *begin + len
**	si *rep est non NULL, le bout de string est remplacé par *rep
**	Attention, l'ancienne chaine est free et une nouvelle est renvoyé et
**	placé dans **str
**	*rep reste intacte dans la mémoire
**
**	Exemple:
**	char *str = "42 is my school !!";
**	ft_strsplice(&str, ft_strstr(str, "school"), ft_strlen("school"), "home");
**	ft_printf("%s\n", str);
**	=> `42 is my home !!`
*/

char	*ft_strsplice(char **str, char *begin, size_t len, char *rep)
{
	char	*n;
	char	*s;
	size_t	i;
	size_t	l;

	if (!str || !begin)
		return (str ? *str : NULL);
	l = ft_strlen(*str) - len + ft_strlen(rep);
	if (!(n = ft_strnew(l)))
		return (NULL);
	i = 0;
	s = *str;
	while (*s && s != begin)
		((n[i++] = *s) || 1) && s++;
	if (rep)
		while (*rep)
			((n[i++] = *rep) || 1) && rep++;
	begin += len;
	if ((begin - *str) <= (long)ft_strlen(*str))
		while (*begin && i < l)
			(n[i++] = *begin) && begin++;
	free(*str);
	*str = n;
	return (n);
}
