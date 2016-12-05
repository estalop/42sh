/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_son_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <chdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:55:06 by jbobin            #+#    #+#             */
/*   Updated: 2016/12/05 13:37:13 by chdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_son_env_anx(int *i, char ***argv, char ***buf)
{
	*i = 1;
	if ((*argv = ft_split(**buf)) == NULL)
		exit(1);
	while (*argv[*i] != NULL && *argv[*i][0] == '-' && *argv[*i][1] != '\0' && \
			ft_strcmp(*argv[*i], "--") != 0)
		(*i)++;
	while (*argv[*i] && (!ft_strcmp(*argv[*i], "--") ||
	ft_strchr(*argv[*i], '=')))
		(*i)++;
}

static void	ft_son_env(char **buf, char **bin, char **env, t_prstruct *proc)
{
	char	**argv;
	char	*tmp;
	int		i;

	ft_son_env_anx(&i, &argv, &buf);
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
