/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_son_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <chdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:55:06 by jbobin            #+#    #+#             */
/*   Updated: 2016/12/09 11:30:44 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_son_env_anx(int *i, char ***tmp, char *buf)
{
	int		j;
	char	**argv;

	j = 1;
	if ((argv = ft_split(buf)) == NULL)
		exit(1);
	while (argv[j] != NULL && argv[j][0] == '-' && argv[j][1] != '\0' && \
			ft_strcmp(argv[j], "--") != 0)
		j++;
	while (argv[j] && (!ft_strcmp(argv[j], "--") ||
	ft_strchr(argv[j], '=')))
		(j)++;
	*i = j;
	*tmp = argv;
}

static void	ft_son_env(char **buf, char **bin, char **env, t_prstruct *proc)
{
	char	**argv;
	char	*tmp;
	int		i;

	ft_son_env_anx(&i, &argv, *buf);
	if (argv[i] == NULL)
	{
		ft_free_tab(&argv);
		ft_print_env(env);
		exit(0);
	}
	else
	{
		tmp = *buf;
		ft_strdel(bin);
		if (!(*bin = ft_check_bin(argv[i], proc->env[2], proc->path, 0)))
			exit(1);
		i = 0;
		while (ft_strncmp(&tmp[i], *bin, ft_strlen(*bin) != 0))
			i++;
		ft_free_tab(&argv);
		*buf = ft_strdup(&tmp[i]);
		ft_strdel(&tmp);
	}
}

void		ft_son_builtin(char **buf, char **bin, char **env, t_prstruct *proc)
{
	if (ft_strncmp(*bin, "env", 3) == 0)
		ft_son_env(buf, bin, env, proc);
	else if (ft_strncmp(*bin, "setenv", 6) == 0)
	{
		ft_print_env(env);
		exit(0);
	}
	else if (ft_strncmp(*bin, "echo", 4) == 0)
		ft_echo(*buf);
	else if (ft_strncmp(*bin, "export", 6) == 0)
		ft_export(*buf, 1);
}
