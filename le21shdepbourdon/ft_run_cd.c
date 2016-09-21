/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 14:24:12 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/08 15:55:36 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		*ft_run_cd2(char *tmp, t_dlist *line)
{
	free(tmp);
	if (ft_prev(line) != NULL)
		tmp = ft_strdup(ft_prev(line));
	else
		tmp = getcwd(0, 0);
	ft_putstr(tmp);
	ft_putchar('\n');
	return (tmp);
}

int			ft_run_cd3(char *tmp, char *tmp2)
{
	free(tmp);
	free(tmp2);
	return (0);
}

int			ft_run_cd(char *arg, t_dlist *line, char *tmp, char *tmp2)
{
	tmp2 = ft_delete_space(arg);
	tmp = ft_get_path(arg);
	if (ft_strcmp("-", tmp) == 0)
		tmp = ft_run_cd2(tmp, line);
	else if (tmp[0] == '~' && tmp[1] == '/')
	{
		free(tmp);
		if (ft_home(line) != NULL)
			tmp = ft_strjoin(ft_home(line), tmp + 1);
		else
			return (ft_error_home2(tmp2));
	}
	else if (ft_strcmp("~", tmp) == 0 || ft_strcmp2("cd", tmp2) == 0)
	{
		free(tmp);
		if (ft_home(line) != NULL)
			tmp = ft_strdup(ft_home(line));
		else
			return (ft_error_home2(tmp2));
	}
	if (chdir(tmp) == 0)
		line = ft_exchange_element(line, NULL, NULL);
	else
		ft_error(tmp, 2);
	return (ft_run_cd3(tmp, tmp2));
}
