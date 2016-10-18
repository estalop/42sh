/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 10:07:37 by jbobin            #+#    #+#             */
/*   Updated: 2016/10/18 14:11:13 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					ft_print_cd(char *argv, char *buf)
{
	if (access(buf, F_OK) == 0)
		if (access(buf, X_OK) == 0)
			if (chdir(buf) == -1)
			{
				ft_putstr_fd("cd: not a directory: ", 2);
				ft_putendl_fd(argv, 2);
			}
			else
				return (0);
		else
		{
			ft_putstr_fd("cd: permission denied: ", 2);
			ft_putendl_fd(argv, 2);
		}
	else
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putendl_fd(argv, 2);
	}
	return (-1);
}
