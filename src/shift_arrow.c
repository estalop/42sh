/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_arrow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 09:08:06 by jbobin            #+#    #+#             */
/*   Updated: 2016/09/17 13:05:56 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_shift_arrow_left(t_termcaps *cap, char *tmp)
{
	int		i;
	char	*str;
	int		j;

	str = tmp;
	i = cap->x - cap->neg;
	while (i > (cap->prompt - cap->neg) && (str[i - 1] == ' ' \
		|| str[i - 1] == '\t' || str[i - 1] == '\n'))
		i--;
	while (i > (cap->prompt - cap->neg) && str[i - 1] != \
			'\t' && str[i - 1] != ' ' && str[i - 1] != '\n')
		i--;
	j = ft_calculate_height(str, cap->x, cap) - \
		ft_calculate_height(str, i + cap->neg, cap);
	while (j-- > 0)
		tputs(cap->sr, 1, ft_output);
	cap->x = i + cap->neg;
	tputs(tgoto(cap->cv, 0, ft_calculate_whidth(str, cap->x, cap)), 1, \
				ft_output);
}

static void	ft_shift_arrow_right(t_termcaps *cap, char *tmp)
{
	int		i;
	char	*str;
	int		j;

	i = cap->x - cap->neg;
	str = tmp;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && \
		str[i] != '\n')
		i++;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || \
				str[i] == '\n'))
		i++;
	j = ft_calculate_height(str, i + cap->neg, cap) - \
		ft_calculate_height(str, cap->x, cap);
	while (j-- > 0)
		tputs(cap->sf, 1, ft_output);
	cap->x = i + cap->neg;
	tputs(tgoto(cap->cv, 0, ft_calculate_whidth(str, cap->x, cap)), 1, \
				ft_output);
}

static void	ft_shift_arrow_up(char *tmp, t_termcaps *cap, int i, int j)
{
	if ((j = ft_calculate_height(tmp, cap->x, cap)) > 0)
	{
		j--;
		tputs(cap->sr, 1, ft_output);
		if (cap->x - cap->whidth > cap->prompt)
			cap->x -= cap->whidth;
		else
			cap->x = cap->prompt;
		while (ft_calculate_height(tmp, cap->x, cap) < j)
			cap->x++;
		while (tmp[cap->x - cap->neg] != '\n' && \
			ft_calculate_whidth(tmp, cap->x, cap) < i)
			cap->x++;
		tputs(tgoto(cap->cv, 0, ft_calculate_whidth(tmp, cap->x, cap)), 1, \
			ft_output);
	}
	else
	{
		cap->x = cap->prompt;
		tputs(tgoto(cap->cv, 0, ft_calculate_whidth(tmp, cap->x, cap)), 1, \
			ft_output);
	}
}

static void	ft_shift_arrow_down(t_termcaps *cap, int strlen, char *tmp)
{
	int		i;
	int		j;

	i = ft_calculate_whidth(tmp, cap->x, cap);
	if ((ft_calculate_height(tmp, strlen, cap) - \
	(j = ft_calculate_height(tmp, cap->x, cap))) > 0)
	{
		j++;
		tputs(cap->sf, 1, ft_output);
		while (ft_calculate_height(tmp, cap->x, cap) < j)
			cap->x++;
		while (tmp[cap->x - cap->neg] != '\n' && \
				ft_calculate_whidth(tmp, cap->x, cap) < i)
			cap->x++;
		tputs(tgoto(cap->cv, 0, ft_calculate_whidth(tmp, cap->x, cap)), 1, \
					ft_output);
	}
	else
	{
		cap->x = strlen;
		tputs(tgoto(cap->cv, 0, ft_calculate_whidth(tmp, cap->x, cap)), 1, \
					ft_output);
	}
}

void		ft_shift_arrow(t_termcaps *cap, int strlen, char buf[4], char *tmp)
{
	if (tmp != NULL && buf[2] == 'D' && cap->x > cap->neg)
		ft_shift_arrow_left(cap, tmp);
	else if (tmp != NULL && buf[2] == 'C' && cap->x < strlen)
		ft_shift_arrow_right(cap, tmp);
	else if (tmp != NULL && buf[2] == 'A' && cap->x > cap->prompt)
		ft_shift_arrow_up(tmp, cap, ft_calculate_whidth(tmp, cap->x, cap), 0);
	else if (tmp != NULL && buf[2] == 'B' && cap->x < strlen)
		ft_shift_arrow_down(cap, strlen, tmp);
	else
		tputs(cap->bl, 0, ft_output);
}
