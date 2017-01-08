/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 10:07:37 by jbobin            #+#    #+#             */
/*   Updated: 2017/01/08 19:31:46 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_print_cd(char *buf)
{
	if (access(buf, F_OK) == 0)
		if (access(buf, X_OK) == 0)
		{
			if (chdir(buf) == -1)
				return (-3);
		}
		else
			return (-4);
	else
		return (-5);
	return (0);
}

int		ft_print_error_cd(char *argv)
{
	if (argv && argv[0] == '-')
		return (-7);
	else if (argv && argv[0] == '~')
		return (-8);
	return (-8);
}

char	**ft_check_pwd(char **env, t_structpwd *up, char *argv)
{
	char	**new;
	char	cwd[255];

	ft_bzero(&cwd, 254);
	if (env[up->pwd] == NULL)
	{
		new = ft_tabdup_plusone(env, "PWD=");
		ft_free_tab(&env);
		env = new;
		up->tmpold = ft_strdup(getcwd(cwd, 254));
		if (up->pwd == up->old)
			up->old++;
	}
	if (env[up->old] == NULL && ft_strcmp(up->tmpold, argv) != 0)
	{
		new = ft_tabdup_plusone(env, "OLDPWD=");
		ft_free_tab(&env);
		env = new;
	}
	return (env);
}
