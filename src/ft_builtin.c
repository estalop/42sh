/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <chdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 12:38:42 by jbobin            #+#    #+#             */
/*   Updated: 2016/12/16 21:03:01 by chdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(char *buf, char **env, int j, t_cdstruct *argv)
{
	if (buf[2] != '\0' && buf[2] != ' ' && buf[2] != '\t')
		return (-1);
	if ((argv = ft_get_cdinfo(buf, env)) != NULL)
	{
		if (ft_strlen(argv->argv) > 255)
		{
			ft_putstr_fd("cd: file name too long: ", 2);
			ft_putendl_fd(argv->argv, 2);
		}
		if (ft_print_cd(argv->argv, argv->curpath) == 0)
			ft_pwd_up(env, argv->curpath, argv->opt);
		ft_strdel(&argv->argv);
		ft_strdel(&argv->curpath);
		free(argv);
	}
	return (j);
}

int	ft_setenv(char *buf, char ***adenv, char **env, char ***nenv)
{
	t_structenv		t;
	int				i;

	t.k = 0;
	if (!(i = 0) && env == NULL)
	{
		ft_putendl_fd("42sh: no env set", 2);
		i = 1;
	}
	else if (buf[6] != ' ' && buf[6] != '\t' && buf[6] != '\0')
		i = -1;
	else if ((t.argv = ft_split(buf)) != NULL && t.argv[1] == NULL)
	{
		ft_free_tab(&t.argv);
		i = -1;
	}
	else if (t.argv && (!t.argv[2] || (t.argv[2] && t.argv[3])))
		i = ft_setenv_anx(adenv, nenv, &t, env);
	else if (t.argv != NULL)
	{
		ft_putendl_fd("setenv: too many arguments", 2);
		i = 1;
	}
	ft_free_tab(&t.argv);
	return (i);
}

int	ft_unsetenv(char *buf, char ***adenv, char **env)
{
	t_structenv		t;
	int				i;

	t.k = 0;
	i = 1;
	if ((buf[8] != ' ' && buf[8] != '\t' && buf[8] != '\0') || env == NULL \
		|| (t.argv = ft_split(buf)) == NULL)
		return (-1);
	if (t.argv[1] == NULL)
	{
		ft_putendl_fd("unsetenv: too fiew arguments", 2);
		return (1);
	}
	t.tmp2 = NULL;
	ft_unsetenv_anx(i, adenv, &t, env);
	ft_free_tab(&t.argv);
	return (0);
}

int	ft_env(char *buf, char ***env, int i)
{
	char	**argv;
	char	**tmp;

	if (buf[3] != ' ' && buf[3] != '\t' && buf[3] != '\0')
		return (-1);
	argv = ft_split(buf);
	if ((tmp = ft_opt_env(argv, *env)) == NULL)
		return (1);
	while (argv[i] != NULL && argv[i][0] == '-' && argv[i][1] != '\0' && \
			ft_strcmp(argv[i], "--") != 0)
		i++;
	if (argv[i] != NULL && ft_strcmp(argv[i], "--") == 0)
		i++;
	ft_split_env(env, argv, i, &tmp);
	ft_free_tab(&argv);
	*env = tmp;
	return (-1);
}

int	ft_exit(char *buf, int i, t_prstruct *proc)
{
	char	**argv;

	if (buf[4] == '\0')
	{
		ft_run_history(" -w", ft_get_home(proc->env[2]), proc, 1);
		exit(0);
	}
	else if (buf[4] == ' ' || buf[4] == '\t')
	{
		if ((argv = ft_split(buf)) != NULL && argv[2] == NULL)
			ft_exit_anx(&i, &argv, proc);
		else
			ft_putendl_fd("exit: too many arguments", 2);
		ft_free_exit(&argv);
		return (1);
	}
	return (-1);
}
