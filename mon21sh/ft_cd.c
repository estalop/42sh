/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 08:15:37 by jbobin            #+#    #+#             */
/*   Updated: 2016/04/04 10:42:46 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					ft_opt_home(char **argv, char **env, int i)
{
	int		k;

	k = argv[1] == NULL ? 0 : 1;
	if (k == 1 && argv[1][0] == '~')
		k = 2;
	while (env != NULL && \
	env[i] && (k == 0 || k == 2) && ft_strncmp(env[i], "HOME=", 5) != 0)
		i++;
	while (env != NULL && \
	env[i] && k == 1 && ft_strncmp(env[i], "OLDPWD=", 7) != 0)
		i++;
	if (env != NULL && \
	argv[1] == NULL && (chdir(&env[i][5]) != -1 || env[i] == NULL))
		return (ft_pwd_up(env));
	if (chdir(&env[i][5]) == -1 && chdir(&env[i][7]) == -1)
		ft_putendl_fd("cd: no home set", 2);
	else if (env != NULL)
		ft_pwd_up(env);
	if (k == 0)
		return (1);
	else if (argv[1][1] == '/' && chdir(&argv[1][2]) == -1 && \
			ft_pwd_up(env) != 1)
		ft_error_cd(argv[1]);
	return (1);
}

t_structpwd			ft_init_struct(char **env)
{
	t_structpwd up;

	up.pwd = 0;
	up.old = 0;
	up.home = 0;
	while (env[up.pwd] != NULL && ft_strncmp(env[up.pwd], "PWD=", 4) != 0)
		up.pwd++;
	while (env[up.old] != NULL && ft_strncmp(env[up.old], "OLDPWD=", 7) != 0)
		up.old++;
	while (env[up.home] != NULL && ft_strncmp(env[up.home], "HOME=", 5) != 0)
		up.home++;
	if (env[up.pwd] != NULL && env[up.pwd][4] != '\0')
		up.tmpold = ft_strdup(&env[up.pwd][4]);
	else
		up.tmpold = NULL;
	up.tmp = NULL;
	up.tmpwd = NULL;
	up.i = 0;
	return (up);
}

int					ft_pwd_up(char **env)
{
	t_structpwd	up;
	char		buf[256];

	up = ft_init_struct(env);
	if (up.tmpold == NULL || env == NULL || getcwd(buf, 255) == NULL)
		return (1);
	if (env[up.pwd] != NULL)
	{
		ft_strdel(&env[up.pwd]);
		env[up.pwd] = ft_strjoin("PWD=", buf);
	}
	if (env[up.old] != NULL && ft_strcmp(buf, up.tmpold) != 0)
	{
		ft_strdel(&env[up.old]);
		env[up.old] = ft_strjoin("OLDPWD=", up.tmpold);
	}
	ft_strdel(&up.tmpold);
	return (1);
}

char				*ft_home(char **env, char argv)
{
	int i;

	i = 0;
	if (env == NULL)
	{
		if (argv == '-')
			return ("-");
		else
			return ("~");
	}
	while (env[i] != NULL && argv == '~' && ft_strncmp(env[i], "HOME=", 5) != 0)
		i++;
	while (env[i] != NULL && argv == '-' && \
			ft_strncmp(env[i], "OLDPWD=", 7) != 0)
		i++;
	if (env[i] != NULL && ft_strncmp(env[i], "HOME=", 5) == 0)
		return (&env[i][5]);
	if (env[i] != NULL && ft_strncmp(env[i], "OLDPWD=", 7) == 0)
		return (&env[i][7]);
	if (argv == '~')
		return ("~");
	return ("-");
}
