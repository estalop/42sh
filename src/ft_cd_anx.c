/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_anx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviviand <tviviand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:16:05 by tviviand          #+#    #+#             */
/*   Updated: 2016/12/03 15:25:20 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cdpath_anx(char ***tmp, char **new, char **argv)
{
	int	i;

	i = 0;
	while (*tmp && *tmp[i])
	{
		if (*tmp[i][ft_strlen(*tmp[i]) - 1] != '/')
		{
			*new = ft_strjoin(*tmp[i], "/");
			ft_strdel(tmp[i]);
			*tmp[i] = *new;
		}
		*new = ft_strjoin(*tmp[i], *argv);
		if (access(*new, F_OK) == 0)
		{
			ft_free_tab(tmp);
			ft_strdel(argv);
			return (1);
		}
		ft_strdel(new);
		i++;
	}
	return (0);
}
