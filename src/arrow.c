/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 09:17:20 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/07 17:00:46 by tbayet           ###   ########.fr       */
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

char		*ft_arrow_up(t_termcaps *cap, char *tmp)
{
	char	*new;
	char	*str;

	if (cap->histo2->pos > 1)
	{
		ft_reset(cap, tmp);
		ft_putstr(cap->prom);
		cap->histo2->pos--;
		str = ft_strdup(ft_get_element_from_list(cap->histo2,
			cap->histo2->pos));
		ft_putstr(str);
		cap->x = ft_strlen(str) + cap->prompt;
		new = ft_strsub(tmp, 0, (cap->prompt - cap->neg));
		ft_strdel(&tmp);
		if (new != NULL && str != NULL)
			tmp = ft_strjoin(new, str);
		else
			tmp = str;
		ft_strdel(&new);
		cap->oldlen = ft_calculate_height(tmp, ft_strlen(str) + cap->prompt,
			cap);
	}
	else
		tputs(cap->bl, 0, ft_output);
	return (tmp);
}

char		*ft_arrow_down(t_termcaps *cap, char *tmp)
{
	char	*new;
	char	*str;

	if (cap->histo2->pos <= cap->histo2->length)
	{
		ft_reset(cap, tmp);
		ft_putstr(cap->prom);
		cap->histo2->pos++;
		str = ft_strdup(ft_get_element_from_list(cap->histo2,
					cap->histo2->pos));
		ft_putstr(str);
		cap->x = ft_strlen(str) + cap->prompt;
		new = ft_strsub(tmp, 0, (cap->prompt - cap->neg));
		ft_strdel(&tmp);
		if (new != NULL && str != NULL)
			tmp = ft_strjoin(new, str);
		else
			tmp = str;
		ft_strdel(&new);
		cap->oldlen = ft_calculate_height(tmp, ft_strlen(str) + cap->prompt,
				cap);
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
