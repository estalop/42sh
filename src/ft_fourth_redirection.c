/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fourth_redirection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <jbobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 08:33:18 by jbobin            #+#    #+#             */
/*   Updated: 2016/12/18 18:29:33 by tviviand         ###   ########.fr       */
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

static void		ft_if_hyphen(t_termcaps *cap, int i, int j, char *tmp)
{
	char	*tmp3;
	char	*tmp2;
	t_hered	*tmpstruct;

	tmp2 = NULL;
	tmpstruct = cap->heredoc;
	while (!(tmp3 = NULL) && tmpstruct->next != NULL)
		tmpstruct = tmpstruct->next;
	while (tmpstruct->str[i] != '\0')
	{
		if (tmpstruct->str[i] == '\t')
		{
			tmp = ft_strsub(tmpstruct->str, j, i - j);
			tmp3 = tmp2 ? ft_strjoin(tmp2, tmp) : tmp;
			ft_strdel(&tmp2);
			tmp3 != tmp ? ft_strdel(&tmp) : 0;
			tmp2 = tmp3;
			while (tmpstruct->str[i] == '\t')
				i++;
			j = i;
		}
		i++;
	}
	tmp = ft_strsub(tmpstruct->str, j, i - j);
	ft_if_hyphen_anx(&tmp, &tmp2, &tmp3, tmpstruct);
}

static int		ft_check_end(t_termcaps *cap, int *c)
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
		if (*c == 1 && !(*c = 0))
			ft_if_hyphen(cap, 0, 0, NULL);
		return (0);
	}
	return (1);
}

static int		ft_checkheredoc(char *str, t_termcaps *cap, int i, int *c)
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
			{
				if (str[i + 2] == '-')
					*c = 1;
				return (i);
			}
		}
		i++;
	}
	return (-1);
}

int				ft_heredoc(char *str, int i, int j, t_termcaps *cap)
{
	static int	c = 0;

	if (i != 0 || str[0] == '<')
		return (0);
	if (cap->stop != NULL)
		if (ft_check_end(cap, &c) == 1)
			return (1);
	if ((i = ft_checkheredoc(str, cap, i, &c)) != -1)
	{
		i = i + 2;
		while (str[i] == ' ' || str[i] == '-')
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
