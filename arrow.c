/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 09:17:20 by jbobin            #+#    #+#             */
/*   Updated: 2016/09/20 08:36:52 by jbobin           ###   ########.fr       */
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

char		*ft_arrow_up(t_termcaps *cap, char *tmp, int strl)
{
	char	*new;

	if (cap->hist[cap->y] != NULL && cap->y < 500)
	{
		ft_reset(cap, tmp);
		strl = (ft_strlen(cap->hist[cap->y - 1]) + cap->prompt);
		ft_putstr(cap->prom);
		ft_putstr(cap->hist[cap->y]);
		cap->x = ft_strlen(cap->hist[cap->y]) + cap->prompt;
		new = ft_strsub(tmp, 0, (cap->prompt - cap->neg));
		ft_strdel(&tmp);
		if (new != NULL)
			tmp = ft_strjoin(new, cap->hist[cap->y]);
		else
			tmp = ft_strdup(cap->hist[cap->y]);
		ft_strdel(&new);
		cap->y++;
		cap->oldlen = ft_calculate_height(tmp, \
		ft_strlen(cap->hist[cap->y]) + cap->prompt, cap);
	}
	else
		tputs(cap->bl, 0, ft_output);
	return (tmp);
}

static int	ft_sub_arrow_down(t_termcaps *cap, int strl, char *tmp)
{
	cap->y--;
	ft_reset(cap, tmp);
	ft_putstr(cap->prom);
	if (cap->y != 0)
	{
		strl = (ft_strlen(cap->hist[cap->y - 1]) + cap->prompt);
		ft_putstr(cap->hist[cap->y - 1]);
		cap->x = ft_strlen(cap->hist[cap->y - 1]) + cap->prompt;
		cap->oldlen = ft_calculate_height(tmp, \
		ft_strlen(cap->hist[cap->y]) + cap->prompt, cap);
	}
	else
	{
		cap->oldlen = 0;
		cap->x = cap->prompt;
	}
	return (strl);
}

char		*ft_arrow_down(t_termcaps *cap, char *tmp, int strl)
{
	char	*new;

	if (cap->y > 0)
	{
		strl = ft_sub_arrow_down(cap, strl, tmp);
		new = ft_strsub(tmp, 0, (cap->prompt - cap->neg));
		ft_strdel(&tmp);
		if (cap->y != 0)
		{
			if (new == NULL)
				tmp = ft_strdup(cap->hist[cap->y - 1]);
			else
				tmp = ft_strjoin(new, cap->hist[cap->y - 1]);
			ft_strdel(&new);
		}
		else if (new != NULL)
			tmp = new;
		else
			tmp = NULL;
	}
	else
		tputs(cap->bl, 0, ft_output);
	return (tmp);
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
		if (x >= cap->whidth)
		{
			tputs(cap->sf, 0, ft_output);
			tputs(cap->cr, 0, ft_output);
			x = 0;
		}
		i++;
	}
}
