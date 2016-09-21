/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_home.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 19:45:05 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/08 15:50:07 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*ft_home(t_dlist *list)
{
	if (ft_search_list(list, "HOME=") != 0 && ft_strlen(ft_get_ele(list,
		ft_search_list(list, "HOME="))) > 5)
		return (ft_get_ele(list, ft_search_list(list, "HOME=")) + 5);
	else
		return (NULL);
}
