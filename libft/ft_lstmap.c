/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:12:43 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/08 11:03:27 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lstc;
	t_list	*lsto;

	lstc = f(ft_lstnew(lst->content, lst->content_size));
	if (lstc == NULL)
		return (NULL);
	lsto = lstc;
	while (lst->next != NULL)
	{
		lst = lst->next;
		lstc->next = f(ft_lstnew(lst->content, lst->content_size));
		if (lstc->next == NULL)
			return (NULL);
		lstc = lstc->next;
	}
	return (lsto);
}
