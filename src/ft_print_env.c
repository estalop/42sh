/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <jbobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 09:17:30 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/23 14:56:32 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		ft_putendl(env[i]);
		i++;
	}
}

char	**ft_sub_env(char ***env, char **argv, int k, int i)
{
	char	**tmp;

	tmp = *env;
	if (tmp != NULL && tmp[k] != NULL)
	{
		ft_strdel(&tmp[k]);
		tmp[k] = ft_strdup(argv[i]);
	}
	else if (tmp != NULL && tmp[0] != NULL)
	{
		tmp = ft_tabdup_plusone(*env, argv[i]);
		ft_free_tab(env);
	}
	else
	{
		if (tmp)
			free(tmp);
		if ((tmp = (char**)malloc(sizeof(char*) * 2)) != NULL)
		{
			tmp[0] = ft_strdup(argv[i]);
			tmp[1] = NULL;
		}
	}
	*env = tmp;
	return (tmp);
}

char	**ft_subunsetenv(t_structenv t, char ***env)
{
	int		i;
	char	**tmpenv;

	i = 0;
	tmpenv = *env;
	if (tmpenv[t.k] == NULL)
		return (tmpenv);
	if ((t.tmpenv = (char**)malloc(sizeof(char*) * ft_tablen(tmpenv))) \
		== NULL)
		return (tmpenv);
	ft_putendl("Ok");
	while (i < t.k)
	{
		t.tmpenv[i] = tmpenv[i];
		i++;
	}
	while (tmpenv[i + 1] != NULL)
	{
		t.tmpenv[i] = tmpenv[i + 1];
		i++;
	}
	i = 0;
	while (tmpenv[i])
	{
		ft_strdel(&tmpenv[i]);
		i++;
	}
	free(tmpenv);
	t.tmpenv[i] = NULL;
	*env = t.tmpenv;
	return (t.tmpenv);
}

char	**ft_subsetenv(t_structenv t, char **env)
{
	t.tmp2 = ft_strjoin(t.argv[1], "=");
	while (env[t.k] != NULL && ft_strncmp(t.tmp2, \
			env[t.k], ft_strlen(t.tmp2)) != 0)
		t.k++;
	if ((t.tmp = ft_strjoin(t.tmp2, t.argv[2])) != NULL)
	{
		ft_strdel(&t.tmp2);
		t.tmp2 = t.tmp;
	}
	env = ft_new_env(t, env);
	ft_strdel(&t.tmp2);
	return (env);
}
