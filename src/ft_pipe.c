/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <jbobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 10:32:28 by jbobin            #+#    #+#             */
/*   Updated: 2016/12/19 17:55:20 by jbobin           ###   ########.fr       */
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

void			ft_son(t_prstruct *pr, char **b, char **env[3], int e)
{
	if (pr->i > 0 && pr->npipe != 0)
	{
		close(pr->pipe->pipe[1]);
		dup2(pr->pipe->pipe[0], STDIN_FILENO);
		if (pr->pipe->next != NULL)
		{
			dup2(pr->pipe->next->pipe[1], STDOUT_FILENO);
			close(pr->pipe->next->pipe[0]);
		}
	}
	else if (pr->npipe != 0)
	{
		dup2(pr->pipe->pipe[1], STDOUT_FILENO);
		close(pr->pipe->pipe[0]);
	}
	if (ft_strchr(b[pr->i], '>') || ft_strchr(b[pr->i], '<'))
		ft_redirect(pr, b, pr->s, NULL);
	if (pr->herepipe != -1)
		close(pr->herepipe);
	pr->herepipe = pr->herepipe != -1 ? -1 : pr->herepipe;
	if (e >= 0)
		exit(e);
	if (b[pr->i][pr->s] != '\0' && b[pr->i] != NULL && b[pr->i][0] != '\0')
		ft_execute(b[pr->i], env[1], e, pr);
}
