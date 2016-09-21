/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewnext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:56:24 by jbobin            #+#    #+#             */
/*   Updated: 2015/12/30 09:28:57 by jbobin           ###   ########.fr       */
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

t_list		*ft_lstnewnext(t_list *lst, void const *content,\
						size_t content_size)
{
	t_list	*tmplist;

	tmplist = lst;
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	lst->next = (t_list*)malloc(sizeof(t_list));
	if (lst->next == NULL)
		return (NULL);
	lst->next->content = ft_fillc((unsigned char*)content, content_size);
	if (lst->content == NULL)
		return (NULL);
	lst->next->content_size = content_size;
	lst->next->next = NULL;
	return (tmplist);
}
