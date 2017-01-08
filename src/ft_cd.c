/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <jbobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 08:15:37 by jbobin            #+#    #+#             */
/*   Updated: 2017/01/08 18:59:04 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char				*ft_opt_home(char *argv, char **env, int i)
{
	int		k;
	char	*tmp;

	if (env == NULL || (argv && argv[i] != '-' && argv[i] != '~'))
		return (ft_strdup(argv));
	tmp = NULL;
	k = argv == NULL ? 0 : 1;
	if (k == 1 && argv[0] == '~')
		k = 2;
	while (env[i] && (k == 0 || k == 2) && ft_strncmp(env[i], "HOME=", 5))
		i++;
	while (env[i] && k == 1 && ft_strncmp(env[i], "OLDPWD=", 7))
		i++;
	k = 0;
	while (env[i] && env[i][k] != '=')
		k++;
	if (env != NULL && env[i] != NULL && argv != NULL)
		tmp = ft_strjoin(&env[i][k + 1], &argv[1]);
	else if (env != NULL && env[i] != NULL)
		tmp = ft_strdup(&env[i][k + 1]);
	return (tmp);
}

char				*ft_cdpath(char *argv, char **env)
{
	int		i;
	char	**tmp;
	char	*new;

	if (!env)
		return (argv);
	i = 0;
	while (env[i] && ft_strncmp(env[i], "CDPATH=", 7))
		i++;
	if (env[i])
		tmp = ft_strsplit(&env[i][7], ':');
	else
		return (argv);
	if (ft_cdpath_anx(&tmp, &new, &argv))
		return (new);
	ft_free_tab(&tmp);
	return (argv);
}

static t_structpwd	ft_init_struct(char **env)
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

int					ft_pwd_up(char ***oenv, char *argv, int opt)
{
	t_structpwd	up;
	char		buf[255];
	char		**env;

	env = *oenv;
	up = ft_init_struct(env);
	env = ft_check_pwd(env, &up);
	*oenv = env;
	if (up.tmpold == NULL || env == NULL || !argv)
		return (1);
	if (env[up.pwd] != NULL)
	{
		ft_strdel(&env[up.pwd]);
		env[up.pwd] = ft_strjoin("PWD=", opt == 1 ? getcwd(buf, 255) : argv);
	}
	if (env[up.old] != NULL && ft_strcmp(argv, up.tmpold) != 0)
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
