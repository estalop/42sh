/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 10:18:02 by jbobin            #+#    #+#             */
/*   Updated: 2016/12/12 13:59:14 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_dquote(char *str, int *pk, int i)
{
	int k;

	k = *pk;
	if (str[i] == '"' && (i != k || i == 0))
	{
		k = i + 1;
		while (str[k] != '"' && str[k] != '\0')
			k++;
		*pk = k;
		if (str[k] == '\0')
			return (1);
	}
	return (0);
}

static int	ft_quote(char *str, int *pl, int i)
{
	int l;

	l = *pl;
	if (str[i] == '\'' && (l != i || i == 0))
	{
		l = i + 1;
		while (str[l] != '\'' && str[l] != '\0')
			l++;
		*pl = l;
		if (str[l] == '\0')
			return (2);
	}
	return (0);
}

static int	ft_cursh(char *str, int m, int i)
{
	int	j;

	if (str[i] == '{')
	{
		j = 1;
		m = 0;
		while (m < i)
		{
			if (str[m] == '{')
				j++;
			m++;
		}
		while (j > 0 && str[m] != '\0')
		{
			if (str[m] == '}')
				j--;
			m++;
		}
		if (j > 0)
			return (3);
	}
	return (0);
}

static int	ft_subsh(char *str, int m, int i)
{
	int	j;

	if (str[i] == '(')
	{
		j = 1;
		m = 0;
		while (m < i)
		{
			if (str[m] == '(')
				j++;
			m++;
		}
		while (j > 0 && str[m] != '\0')
		{
			if (str[m] == ')')
				j--;
			m++;
		}
		if (j > 0)
			return (4);
	}
	return (0);
}

int			ft_quote_not_finished(char *str, int i, t_termcaps *cap)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (ft_heredoc(str, i, 0, cap) == 1 && (cap->quot = 1))
			return (6);
		else if (ft_dquote(str, &k, i) == 1 && (cap->quot = 1))
			return (1);
		else if (ft_quote(str, &l, i) == 2 && (cap->quot = 1))
			return (2);
		else if (ft_cursh(str, 0, i) == 3 && (cap->quot = 1))
			return (3);
		else if (ft_subsh(str, 0, i) == 4 && (cap->quot = 1))
			return (4);
		else if (str[i] == '\\' && str[i + 1] == '\0' && (cap->quot = 1))
			return (5);
		i++;
	}
	return (0);
}
