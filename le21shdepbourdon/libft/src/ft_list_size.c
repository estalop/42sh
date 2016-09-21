/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 22:41:06 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/05 02:37:08 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_list_size(t_node *head)
{
	t_node	*p_temp;
	int		compteur;

	p_temp = head;
	compteur = 0;
	while (p_temp)
	{
		compteur++;
		p_temp = p_temp->p_next;
	}
	return (compteur);
}
