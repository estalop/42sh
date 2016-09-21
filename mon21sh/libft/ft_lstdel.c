/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 10:12:27 by jbobin            #+#    #+#             */
/*   Updated: 2016/01/04 10:00:10 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *alst;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		del(tmp1->content, tmp1->content_size);
		free(tmp1);
		tmp1 = tmp2;
	}
	*alst = NULL;
}
