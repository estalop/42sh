/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 15:43:35 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/11 18:33:44 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

pid_t			create_process(void)
{
	pid_t		pid;

	pid = -1;
	while (-1 == (pid = fork()) && errno == EAGAIN)
	{
		pid = fork();
	}
	return (pid);
}

static void		wait_child(void)
{
	int			status;

	signal(SIGINT, ft_get_sigint);
	wait(&status);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 11)
			ft_putstr("Segfault !\n");
		else if (WTERMSIG(status) == 8)
			ft_putstr("Arithmetic error !\n");
		else
			ft_putstr("Killed\n");
	}
	else if (WIFSTOPPED(status))
		ft_putstr("Stopped\n");
}

void			son_process(char *path, char *arg[], t_dlist *line)
{
	int			test;

	if (ft_check_file(path))
	{
		test = execve(path, arg, ft_tab_from_list(line));
		if (test == -1)
		{
			ft_putstr_fd(" error on performing this operation \n", 2);
			ft_putstr(" error on performing this operation \n");
			exit(EXIT_FAILURE);
		}
	}
}

int				ft_run_exe(char *path, char **options, t_dlist *list)
{
	pid_t		pid;

	if (path == NULL)
		return (0);
	pid = fork();
	if (pid > 0)
		wait_child();
	if (pid == 0)
	{
		execve(path, options, ft_tab_from_list(list));
		ft_putstr("error execve");
		exit(0);
	}
	return (EXIT_SUCCESS);
}
