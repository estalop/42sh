/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <jbobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 08:46:11 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/12 15:52:56 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error_cd(char *buf)
{
	struct stat		data;
	int				i;

	i = stat(buf, &data);
	if (access(buf, F_OK) == -1)
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putendl_fd(buf, 2);
	}
	else if (i != -1)
	{
		if ((data.st_mode & S_IFMT) != S_IFDIR)
		{
			ft_putstr_fd("cd: not a directory: ", 2);
			ft_putendl_fd(buf, 2);
		}
		else
		{
			ft_putstr_fd("cd: permission denied: ", 2);
			ft_putendl_fd(buf, 2);
		}
	}
}

void	ft_error_path(int i, char *path)
{
	if (i == 0)
	{
		ft_putstr_fd("42sh: command not found: ", 2);
		ft_putendl_fd(path, 2);
	}
	if (i == 1)
	{
		ft_putstr_fd("42sh: can not execute: ", 2);
		ft_putendl_fd(path, 2);
	}
	if (i == -1)
	{
		ft_putstr_fd("42sh: not authorised: ", 2);
		ft_putendl_fd(path, 2);
	}
}
