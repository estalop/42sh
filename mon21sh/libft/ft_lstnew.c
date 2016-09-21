/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 09:17:12 by jbobin            #+#    #+#             */
/*   Updated: 2015/12/14 17:32:42 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	*ft_fillc(unsigned char *str2, size_t content_size)
{
	size_t			i;
	unsigned char	*str1;
	void			*strr;

	i = 0;
	str1 = (unsigned char*)malloc(sizeof(char) * content_size);
	if (str1 == NULL)
		return (NULL);
	while (i < content_size)
	{
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
	strr = str1;
	return (strr);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*tmp;

	tmp = (t_list*)malloc(sizeof(t_list));
	if (tmp == NULL)
		return (NULL);
	tmp->content_size = content_size;
	if (content != NULL)
	{
		tmp->content = ft_fillc((unsigned char*)content, content_size);
		if (tmp == NULL)
			return (NULL);
	}
	else
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	tmp->next = NULL;
	return (tmp);
}
