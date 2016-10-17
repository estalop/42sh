/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviviand <tviviand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 18:45:47 by tviviand          #+#    #+#             */
/*   Updated: 2016/10/09 19:15:31 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoind(char *s1, char *s2, int dela, int delb)
{
	char	*str;
	int		s1_len;

	if (!s1 || !s2)
		exit(-42);
	s1_len = ft_strlen(s1);
	if ((str = ft_strnew(s1_len + ft_strlen(s2))) == NULL)
		exit(-42);
	ft_strcpy(str, s1);
	ft_strcpy(str + s1_len, s2);
	if (dela && s1)
		ft_strdel(&s1);
	if (delb && s2)
		ft_strdel(&s2);
	return (str);
}
