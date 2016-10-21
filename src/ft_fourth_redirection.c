/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fourth_redirection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 08:33:18 by jbobin            #+#    #+#             */
/*   Updated: 2016/09/22 15:08:58 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_hered	*ft_newheredoc(t_termcaps *cap, char *str)
{
	t_hered	*start;

	start = cap->heredoc;
	if (!cap->heredoc)
	{
		if ((cap->heredoc = (t_hered*)malloc(sizeof(t_hered))))
		{
			cap->heredoc->str = str;
			cap->heredoc->next = NULL;
		}
		return (cap->heredoc);
	}
	else
	{
		while (cap->heredoc->next)
			cap->heredoc = cap->heredoc->next;
		if ((cap->heredoc->next = (t_hered*)malloc(sizeof(t_hered))))
		{
			cap->heredoc->next->str = str;
			cap->heredoc->next->next = NULL;
		}
	}
	return (start);
}

static int		ft_check_end(t_termcaps *cap)
{
	int		i;
	char	*new;

	i = ft_strlen(cap->str) - 1;
	while (i > 0 && cap->str[i] != '\n')
		i--;
	if (i > 0)
		i++;
	if (cap->str && ft_strcmp(&cap->str[i], cap->stop) == 0)
	{
		new = ft_strsub(cap->str, 0, i);
		ft_strdel(&cap->str);
		ft_strdel(&cap->stop);
		cap->heredoc = ft_newheredoc(cap, new);
		return (0);
	}
	return (1);
}

static int		ft_checkheredoc(char *str, t_termcaps *cap, int i)
{
	t_hered	*tmp;

	tmp = cap->heredoc;
	while (str[i] != '\0')
	{
		if (str[i] == '<' && str[i + 1] == '<')
		{
			if (tmp != NULL)
				tmp = tmp->next;
			else
				return (i);
		}
		i++;
	}
	return (-1);
}

int				ft_heredoc(char *str, int i, int j, t_termcaps *cap)
{
	if (i != 0)
		return (0);
	if (cap->stop != NULL)
		if (ft_check_end(cap) == 1)
			return (1);
	if ((i = ft_checkheredoc(str, cap, i)) != -1)
	{
		i = i + 2;
		while (str[i] == ' ')
			i++;
		j = i;
		while (ft_isprint(str[i]) && str[i] != ' ')
			i++;
		cap->stop = ft_strsub(str, j, i - j);
		cap->str = NULL;
		cap->cmd = str;
		return (1);
	}
	return (0);
}
