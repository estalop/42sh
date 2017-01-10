/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_son_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <jbobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:55:06 by jbobin            #+#    #+#             */
/*   Updated: 2017/01/10 16:40:07 by jbobin           ###   ########.fr       */
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

static void	ft_son_cd(char *buf, int e)
{
	char	**argv;

	argv = ft_split(buf);
	if (e == -2)
		ft_putstr_fd("cd: file name too long: ", 2);
	else if (e == -3)
		ft_putstr_fd("cd: not a directory: ", 2);
	else if (e == -4)
		ft_putstr_fd("cd: permission denied: ", 2);
	else if (e == -5)
		ft_putstr_fd("cd: no such file or directory: ", 2);
	else if (e == -6 || e == -7 || e == -8)
	{
		if (e == -6)
			ft_putendl_fd("cd: path not found", 2);
		else if (e == -7)
			ft_putendl_fd("cd: OLDPWD does not exist", 2);
		else if (e == -8)
			ft_putendl_fd("cd: HOME not set", 2);
		ft_free_tab(&argv);
		return ;
	}
	ft_putendl_fd(argv[1], 2);
	ft_free_tab(&argv);
}

static void	ft_son_history(char *buf, int e, t_prstruct *proc)
{
	if (e == -4)
		exit(ft_run_history2(&buf[7], proc->histo2, 0));
	else if (e == -5)
		exit(ft_display_list3(proc->histo2));
	else if (e == -6)
	{
		ft_putstr_fd("42sh: history: ", 2);
		ft_putstr_fd(&buf[7], 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit(1);
	}
	else
		ft_son_history_anx(buf, e);
}

void		ft_son_builtin(char **buf, int e, char **env, t_prstruct *proc)
{
	if (ft_strncmp(proc->bin, "env", 3) == 0)
		ft_son_env(buf, &proc->bin, env, proc);
	else if (ft_strncmp(proc->bin, "setenv", 6) == 0)
	{
		ft_print_env(env);
		exit(0);
	}
	else if (ft_strncmp(proc->bin, "echo", 4) == 0)
		ft_echo(*buf);
	else if (ft_strncmp(proc->bin, "export", 6) == 0)
		ft_export(*buf, 1);
	else if (ft_strncmp(proc->bin, "history", 7) == 0)
		ft_son_history(*buf, e, proc);
	else if (ft_strncmp(proc->bin, "cd", 2) == 0)
		ft_son_cd(*buf, e);
	else if (ft_strncmp(proc->bin, "exit", 4) == 0)
		ft_putendl_fd("exit: too many arguments", 2);
}
