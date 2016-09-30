/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 18:11:30 by jbobin            #+#    #+#             */
/*   Updated: 2016/05/20 11:19:50 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_set_home_in_argv(char **argv, char **env)
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

char	**ft_create_environ(int i)
{
	char	**env;
	char	buf[257];
	char	*tmp;

	if ((env = ft_tabdup(*_NSGetEnviron())) != NULL)
	{
		while (env[i] != NULL && ft_strncmp(env[i], "SHLVL=", 6) != 0)
			i = i + 1;
		if (env[i] != NULL)
			tmp = ft_itoa(ft_atoi(&env[i][6]) + 1);
		ft_strdel(&env[i]);
		env[i] = ft_strjoin("SHLVL=", tmp);
		ft_strdel(&tmp);
		return (env);
	}
	if (getcwd(buf, 256) == NULL || (env = (char**)malloc(sizeof(char*) * 5)) \
		== NULL)
		return (NULL);
	env[0] = ft_strjoin("PWD=", buf);
	env[1] = ft_strdup("SHLVL=1");
	env[2] = ft_strdup("_=usr/bin/env");
	env[3] = ft_strdup("TERM=xterm-256color");
	env[4] = NULL;
	return (env);
}
