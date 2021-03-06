/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <jbobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 18:11:30 by jbobin            #+#    #+#             */
/*   Updated: 2016/12/19 11:32:19 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_set_home_in_argv(char **argv, char **env)
{
	int		i;
	char	*tmp;

	i = 0;
	while (argv[i] != NULL)
	{
		if (argv[i][0] == '~')
		{
			tmp = ft_strjoin(ft_home(env, argv[i][0]), &argv[i][1]);
			ft_strdel(&argv[i]);
			argv[i] = tmp;
		}
		i++;
	}
}

static char	**ft_checkenv(char **env)
{
	int		i;

	i = 0;
	while (env[i] != NULL && ft_strncmp(env[i], "SHLVL=", 6) != 0)
		i++;
	if (!env[i])
		env = ft_tabdup_plusone_del(env, "SHLVL=1");
	i = 0;
	while (env[i] != NULL && ft_strncmp(env[i], "_=", 2) != 0)
		i++;
	if (!env[i])
		env = ft_tabdup_plusone_del(env, "_=usr/bin/env");
	i = 0;
	while (env[i] != NULL && ft_strncmp(env[i], "TERM=", 5) != 0)
		i++;
	if (!env[i])
		env = ft_tabdup_plusone_del(env, "TERM=xterm-256color");
	return (env);
}

static char	**ft_create_environbis(char **env)
{
	env[1] = ft_strdup("SHLVL=1");
	env[2] = ft_strdup("_=usr/bin/env");
	env[3] = ft_strdup("TERM=xterm-256color");
	env[4] = NULL;
	return (env);
}

char		**ft_create_environ(int i)
{
	char	**env;
	char	buf[257];
	char	*tmp;

	if ((env = ft_tabdup(*_NSGetEnviron())) != NULL)
	{
		while (env[i] != NULL && ft_strncmp(env[i], "SHLVL=", 6) != 0)
			i = i + 1;
		if (env[i] != NULL)
		{
			if ((tmp = ft_itoa(ft_atoi(&env[i][6]) + 1)))
			{
				ft_strdel(&env[i]);
				env[i] = ft_strjoin("SHLVL=", tmp);
			}
		}
		ft_strdel(&tmp);
		env = ft_checkenv(env);
		return (env);
	}
	if (!getcwd(buf, 256) || !(env = (char**)malloc(sizeof(char*) * 5)))
		return (NULL);
	env[0] = ft_strjoin("PWD=", buf);
	env = ft_create_environbis(env);
	return (env);
}
