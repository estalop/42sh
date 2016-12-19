/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <jbobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 17:07:18 by jbobin            #+#    #+#             */
/*   Updated: 2016/12/19 14:01:23 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_localvar	*g_localvars;

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

void	ft_main_free(char ***env, t_termcaps *cap, char ***path)
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
	ft_free_tab(env);
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

void	free_local_var(void)
{
	t_localvar	*next;

	while (g_localvars)
	{
		next = g_localvars->next;
		free(g_localvars);
		g_localvars = next;
	}
}

void	ft_free_cdstruct(t_cdstruct **struc)
{
	if (struc && *struc)
	{
		ft_strdel(&(*struc)->curpath);
		ft_strdel(&(*struc)->argv);
		free(*struc);
	}
	*struc = NULL;
}
