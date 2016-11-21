/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 14:45:30 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/21 13:24:13 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	*ft_error_env(char **argv, int i, int j)
{
	ft_putstr_fd("env: illegal option -- ", 2);
	ft_putendl_fd(&argv[i][j], 2);
	ft_putendl_fd("usage: env [-i] [name=value ...]", 2);
	ft_free_tab(&argv);
	return (NULL);
}

char		**ft_opt_env(char **argv, char **env)
{
	int		i;
	int		j;
	char	**tmp;

	i = 1;
	tmp = NULL;
	if (argv == NULL)
		return (NULL);
	while (argv[i] != NULL && argv[i][0] == '-' && argv[i][1] != '\0' && \
		ft_strcmp(argv[i], "--") != 0)
	{
		j = 1;
		while (argv[i][j] != '\0' && ft_strchr("i", argv[i][j]) != NULL)
			j++;
		if (argv[i][j] != '\0')
			return (ft_error_env(argv, i, j));
		if (tmp == NULL)
			tmp = (char**)malloc(sizeof(char*));
		tmp[0] = NULL;
		i++;
	}
	if (tmp == NULL)
		tmp = ft_tabdup(env);
	ft_free_tab(&env);
	return (tmp);
}
