/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <jbobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:56:31 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/25 18:17:30 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_return(char *str)
{
	char	*tmp;
	char	*new;
	int		i;

	if (str == NULL)
		return (str);
	i = 0;
	tmp = str;
	new = ft_strnew(ft_strlen(tmp));
	while (tmp[i] != '\0')
	{
		new[i] = tmp[i];
		i++;
	}
	ft_strdel(&str);
	new[i] = '\n';
	new[i + 1] = '\0';
	return (new);
}

char	*ft_prompt(int i)
{
	if (i == 1)
		return ("dquote> ");
	else if (i == 2)
		return ("quote> ");
	else if (i == 3)
		return ("cursh> ");
	else if (i == 4)
		return ("subsh> ");
	else if (i == 5 || i == 6)
		return ("> ");
	return ("42sh> ");
}

int		ft_start_of_str(char *str, t_termcaps *cap)
{
	int	s;
	int l;

	l = ft_strlen(cap->prom);
	if (str != NULL)
	{
		if (cap->i > 0)
		{
			s = ft_strlen(str);
			while (s > 0 && str[s] != '\n')
				s--;
			if (str[s] == '\n')
				s++;
			return (s + l);
		}
	}
	return (l);
}

int		ft_calculate_whidth(char *str, int i, t_termcaps *cap)
{
	int val[4];
	int	*xy;

	val[0] = cap->neg;
	val[1] = 0;
	val[2] = cap->prompt;
	val[3] = 0;
	xy = ft_calculate_length(str, i, cap, val);
	return (xy[0]);
}

int		ft_calculate_height(char *str, int i, t_termcaps *cap)
{
	int val[4];
	int	*xy;

	val[0] = cap->neg;
	val[1] = 0;
	val[2] = cap->prompt;
	val[3] = 0;
	xy = ft_calculate_length(str, i, cap, val);
	return (xy[1]);
}
