/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <chdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 09:17:20 by jbobin            #+#    #+#             */
/*   Updated: 2017/01/04 09:00:33 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_arrow_side(char *tmp, char buf[4], t_termcaps *cap, int strlen)
{
	ft_end(cap, tmp, strlen);
	if (buf[2] == 'C' && (size_t)(cap->x - cap->neg) < ft_strlen(tmp))
		cap->x++;
	else if (buf[2] == 'D' && cap->x > cap->prompt)
		cap->x--;
	else
		tputs(cap->bl, 0, ft_output);
	ft_put_cursor(cap, tmp);
}

char		*ft_arrow_up(t_termcaps *cap, char *t)
{
	char	*new;
	char	*str;

	new = t;
	if (cap->histo2->pos > 0)
	{
		t = ft_history_multiline(t, cap);
		ft_putstr(cap->prom);
		cap->histo2->pos--;
		str = ft_strdup(ft_get_element_from_list(cap->histo2,
			cap->histo2->pos));
		ft_newputstr(str, cap);
		cap->x = ft_strlen(str) + cap->prompt;
		if (t != NULL)
			new = ft_strjoin(t, str);
		else
			new = ft_strdup(str);
		ft_strdel(&str);
		ft_strdel(&t);
		cap->oldlen = ft_calculate_height(t, ft_strlen(str) + cap->prompt, cap);
	}
	else
		tputs(cap->bl, 0, ft_output);
	return (new);
}

char		*ft_arrow_down(t_termcaps *cp, char *tmp)
{
	char	*new;
	char	*str;

	new = tmp;
	if (cp->histo2->pos < cp->histo2->length)
	{
		tmp = ft_history_multiline(tmp, cp);
		ft_putstr(cp->prom);
		cp->histo2->pos++;
		str = ft_strdup(ft_get_element_from_list(cp->histo2, cp->histo2->pos));
		if (str)
			ft_newputstr(str, cp);
		cp->x = ft_strlen(str) + cp->prompt;
		if (tmp != NULL)
			new = ft_strjoin(tmp, str);
		else
			new = ft_strdup(str);
		ft_strdel(&tmp);
		ft_strdel(&str);
		cp->oldlen = ft_calculate_height(tmp, ft_strlen(str) + cp->prompt, cp);
	}
	else
		tputs(cp->bl, 0, ft_output);
	return (new);
}

void		ft_newputstr(char const *str, t_termcaps *cap)
{
	int	i;
	int x;

	i = 0;
	x = cap->prompt;
	while (str[i] != '\0')
	{
		if (str[i] == '\t')
		{
			x = x + (8 - (x % 8));
			write(1, &str[i], 1);
		}
		if (str[i] != '\t')
		{
			write(1, &str[i], 1);
			x = str[i] == '\n' ? 0 : x + 1;
		}
		if (x >= cap->whidth && (str[i + 1] == 0 || str[i] == '\t'))
			tputs(cap->sf, 0, ft_output);
		if (x >= cap->whidth)
			x = 0;
		i++;
	}
}
