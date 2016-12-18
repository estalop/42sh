/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_options_history.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 18:30:59 by pbourdon          #+#    #+#             */
/*   Updated: 2016/12/18 17:36:19 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_check_options_history(char *arg, int i, int j, char *str)
{
	char	**tabu;
	char	*tmp;

	if (!(tabu = ft_split(arg)))
		return (NULL);
	while (tabu[i] && tabu[i][0] == '-')
	{
		j = 1;
		while (tabu[i][j] == 'r' || tabu[i][j] == 'a' ||
			tabu[i][j] == 'n' || tabu[i][j] == 'd' || tabu[i][j] == 'c' ||
			tabu[i][j] == 'w' || tabu[i][j] == 'p' || tabu[i][j] == 's')
			j++;
		if (tabu[i][j])
		{
			ft_free_tab(&tabu);
			ft_strdel(&str);
			return (NULL);
		}
		if (str)
		{
			tmp = ft_strjoin(str, tabu[i]);
			ft_strdel(&str);
			str = tmp;
		}
		else
			str = ft_strdup(tabu[i]);
		i++;
	}
	ft_free_tab(&tabu);
	return (str);
}
