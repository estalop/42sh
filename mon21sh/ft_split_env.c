/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 17:06:59 by jbobin            #+#    #+#             */
/*   Updated: 2016/06/06 09:49:00 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_split_env(char ***env, char **argv, int *i, char ***tmp)
{
	int		j;
	int		k;
	char	**tmptmp;

	tmptmp = *tmp;
	while (argv[*i] != NULL && ft_strchr(argv[*i], '=') != NULL)
	{
		j = 0;
		k = 0;
		while (argv[*i][j] != '=')
			j++;
		while (tmptmp != NULL && tmptmp[k] != NULL && \
			ft_strncmp(argv[*i], tmptmp[k], j) != 0)
			k++;
		*tmp = ft_sub_env(&tmptmp, argv, k, *i);
		*i = *i + 1;
		*env = *tmp;
	}
}

char	**ft_new_env(t_structenv t, char **env)
{
	if (t.k == 0 && env[t.k] == NULL)
	{
		ft_free_tab(&env);
		if ((env = (char**)malloc(sizeof(char*) * 2)) != NULL)
		{
			env[0] = ft_strdup(t.tmp2);
			env[1] = NULL;
		}
	}
	else if (env[t.k] != NULL)
	{
		ft_strdel(&env[t.k]);
		env[t.k] = ft_strdup(t.tmp2);
	}
	else if ((t.tmpenv = ft_tabdup_plusone(env, t.tmp2)) != NULL)
	{
		ft_free_tab(&env);
		env = t.tmpenv;
	}
	return (env);
}
