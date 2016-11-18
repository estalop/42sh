/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <jbobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 12:38:42 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/18 14:27:57 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(char *buf, char **env, int j, t_cdstruct *argv)
{
	if (buf[2] != '\0' && buf[2] != ' ' && buf[2] != '\t')
		return (0);
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

	t.k = 0;
	if (env == NULL)
	{
		ft_putendl_fd("42sh: no env set", 2);
		return (1);
	}
	if (buf[6] != ' ' && buf[6] != '\t' && buf[6] != '\0')
		return (0);
	if ((t.argv = ft_split(buf)) != NULL && t.argv[1] == NULL)
		ft_print_env(*nenv);
	else if (t.argv != NULL && (t.argv[2] == NULL || \
		(t.argv[2] != NULL && t.argv[3] == NULL)))
	{
		*adenv = ft_subsetenv(t, env);
		*nenv = ft_subsetenv(t, *nenv);
	}
	else if (t.argv != NULL)
		ft_putendl_fd("setenv: too many arguments", 2);
	ft_free_tab(&t.argv);
	return (1);
}

int	ft_unsetenv(char *buf, char ***adenv, char **env)
{
	t_structenv		t;
	int				i;

	t.k = 0;
	i = 1;
	if ((buf[8] != ' ' && buf[8] != '\t' && buf[8] != '\0') || env == NULL \
		|| (t.argv = ft_split(buf)) == NULL)
		return (0);
	if (t.argv[1] == NULL)
		ft_putendl_fd("unsetenv: too fiew arguments", 2);
	t.tmp2 = NULL;
	while (t.argv[i] != NULL)
	{
		if (t.tmp2 == NULL)
			t.tmp2 = ft_strjoin(t.argv[i], "=");
		if (((env[t.k] != NULL && ft_strncmp(t.tmp2, env[t.k], \
			ft_strlen(t.tmp2)) == 0) || env[t.k] == NULL) && (i++))
		{
			ft_strdel(&t.tmp2);
			ft_free_tab(adenv);
			*adenv = ft_subunsetenv(t, &env);
			t.k = -1;
		}
		t.k++;
	}
	ft_free_tab(&t.argv);
	return (1);
}

int	ft_env(char *buf, char ***env, int i)//, t_prstruct *proc)
{
	char	**argv;
	char	**tmp;

	if (buf[3] != ' ' && buf[3] != '\t' && buf[3] != '\0')
		return (-1);
	argv = ft_split(buf);
	if ((tmp = ft_opt_env(argv, *env)) == NULL)
		return (-1);
	while (argv[i] != NULL && argv[i][0] == '-' && argv[i][1] != '\0' && \
			ft_strcmp(argv[i], "--") != 0)
		i++;
	if (argv[i] != NULL && ft_strcmp(argv[i], "--") == 0)
		i++;
	ft_split_env(env, argv, &i, &tmp);
	ft_free_tab(&argv);
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
		{
			while (ft_isdigit(argv[1][i]) == 1)
				i++;
			if (i == 0)
			{
				ft_run_history(" -w", ft_get_home(proc->env[2]), proc, 1);
				exit(0);
			}
			if (argv[1][i] == '\0')
			{
				ft_run_history(" -w", ft_get_home(proc->env[2]), proc, 1);
				exit(ft_atoi(argv[1]));
			}
			else
				ft_putendl_fd("exit: invalid argument", 2);
		}
		else
			ft_putendl_fd("exit: too many arguments", 2);
		ft_free_exit(&argv);
		return (1);
	}
	return (-1);
}
