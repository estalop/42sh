/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 17:07:18 by jbobin            #+#    #+#             */
/*   Updated: 2016/10/06 14:28:40 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_exit(char ***argv)
{
	int		i;
	char	**av;

	av = *argv;
	i = 0;
	while (av != NULL && av[i] != NULL)
	{
		ft_strdel(&av[i]);
		i++;
	}
	free(av);
	*argv = NULL;
}

void	ft_main_free(char ***env, t_termcaps *cap, char ***path, char ***com)
{
	t_hered	*tmp;

	while (cap->heredoc)
	{
		tmp = cap->heredoc;
		cap->heredoc = cap->heredoc->next;
		ft_strdel(&tmp->str);
		tmp->next = NULL;
		free(tmp);
	}
	ft_free_tab(com);
	ft_free_tab(env);
	ft_strdel(&cap->str);
	ft_strdel(&cap->cmd);
	ft_strdel(&cap->stop);
	ft_free_tab(path);
}

void	ft_free_list(t_idlist **list)
{
	t_idlist	*tmp;
	t_idlist	*tmp2;

	if (list != NULL && *list != NULL)
	{
		tmp = *list;
		while (tmp != NULL)
		{
			tmp2 = tmp;
			tmp = tmp->next;
			tmp2->next = NULL;
			tmp2->prev = NULL;
			free(tmp2);
		}
		*list = NULL;
	}
}