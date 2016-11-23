/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 10:32:28 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/23 11:29:35 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_count_pipe(const char *buf)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '|')
			j++;
		i++;
	}
	while (i > 0 && (buf[i] == ' ' || buf[i] == '\t' || buf[i] == '\0'))
		i--;
	if (buf[i] == '|')
		return (-1);
	return (j);
}

static t_idlist	*ft_newlist(t_idlist *prev)
{
	t_idlist	*new;

	if ((new = (t_idlist*)malloc(sizeof(t_idlist))) == NULL)
		return (NULL);
	new->prev = prev;
	if (prev != NULL)
		new->no = prev->no + 1;
	else
		new->no = 0;
	new->next = NULL;
	new->id = fork();
	return (new);
}

pid_t			ft_fork(t_idlist **list)
{
	t_idlist	*tmp;

	if (*list == NULL)
	{
		*list = ft_newlist(NULL);
		if (*list != NULL)
			return ((*list)->id);
		else
			return (-1);
	}
	else
		tmp = *list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_newlist(tmp);
	if (tmp->next != NULL)
		return (tmp->next->id);
	else
		return (-1);
}

void			ft_kill_process(t_idlist **list, pid_t id)
{
	t_idlist	*tmp;

	tmp = *list;
	while (tmp != NULL && tmp->id != id)
		tmp = tmp->next;
	while (tmp != NULL)
	{
		if (tmp->id != id && tmp->id != 0)
			kill(tmp->id, SIGINT);
		tmp->id = 0;
		if (tmp->prev == NULL)
			*list = tmp;
		tmp = tmp->prev;
	}
}

void			ft_son(t_prstruct *proc, char **buf, char **env[3], int e)
{
	if (proc->i > 0 && proc->npipe != 0)
	{
		close(proc->pipe->pipe[1]);
		dup2(proc->pipe->pipe[0], STDIN_FILENO);
		if (proc->pipe->next != NULL)
		{
			dup2(proc->pipe->next->pipe[1], STDOUT_FILENO);
			close(proc->pipe->next->pipe[0]);
		}
	}
	else if (proc->npipe != 0)
	{
		dup2(proc->pipe->pipe[1], STDOUT_FILENO);
		close(proc->pipe->pipe[0]);
	}
	if (ft_strchr(buf[proc->i], '>') || ft_strchr(buf[proc->i], '<'))
		ft_redirect(proc, buf);
	if (proc->herepipe != -1)
	{
		close(proc->herepipe);
		proc->herepipe = -1;
	}
	if (e >= 0)
		exit(e);
	if (buf[proc->i][proc->s] != '\0' && \
		buf[proc->i] != NULL && buf[proc->i][0] != '\0')
		ft_execute(buf[proc->i], env[1], proc->bin, proc);
}
