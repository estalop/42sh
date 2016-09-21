/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyse_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 19:25:43 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/11 15:53:36 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_get_info_from_list(t_dlist *list, t_dlist *histo)
{
	char	*str;
	int		index;

	index = 0;
	str = ft_get_str_from_list(list);
	while (str[index] == ' ')
		index++;
	if (ft_strlen(str) > 0 && index != ft_strlen(str))
		histo = ft_add_data2(histo, str);
	if (ft_strcmp("exit", str) == 0)
	{
		free(str);
		exit(EXIT_SUCCESS);
	}
	free(str);
	return (histo);
	// need to send the str to the correct programm and then free it
}
