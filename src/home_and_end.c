/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_and_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <jbobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 13:36:26 by jbobin            #+#    #+#             */
/*   Updated: 2016/12/19 15:36:57 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_select.h"

void	ft_thome(t_termcaps *cap, char *str)
{
	int i;

	i = ft_calculate_height(str, cap->x, cap);
	cap->x = cap->prompt;
	cap->oldlen = 0;
	while (i-- > 0)
		tputs(cap->sr, 1, ft_output);
	tputs(tgoto(cap->cv, 0, cap->neg), 1, ft_output);
}

int		ft_end(t_termcaps *cap, char *str, int strlen)
{
	int	i;
	int	l;

	i = ft_calculate_height(str, strlen, cap) - \
		ft_calculate_height(str, cap->x, cap);
	cap->oldlen = ft_calculate_height(str, ft_strlen(str) + cap->neg, cap);
	l = i;
	while (i-- > 0)
		tputs(cap->sf, 1, ft_output);
	tputs(tgoto(cap->cv, 0, ft_calculate_whidth(str, strlen, cap)), 1, \
		ft_output);
	return (l);
}

void	ft_sig_stop_ex(int sig)
{
	if (sig == 2)
		ft_putchar('\n');
}

char	*ft_out(t_termcaps *cap, char buf[4], char *tmp)
{
	int	save;
	int	nblines;

	if (cap->exec == 1 && !(buf[0] = 0))
	{
		ft_select_cancel(cap->autotab, cap, tmp);
		cap->exec = 0;
	}
	else if (cap->exec == 2)
	{
		if (ft_out_anx(&tmp, cap))
			return (NULL);
		buf[0] = 0;
		nblines = ft_calculate_height(tmp, cap->x, cap);
		while (nblines > 0)
		{
			ft_putstr_fd(cap->sf, 1);
			nblines--;
		}
		save = ft_calculate_whidth(tmp, cap->x, cap);
		tputs(tgoto(cap->cv, 0, save), 1, ft_output);
	}
	else if (cap->exec != 1 && cap->exec != 2)
		ft_out_anx_b(buf, &tmp, cap);
	return (tmp);
}

void	ft_set_prompt(t_termcaps *cap)
{
	cap->prom = ft_prompt(cap->i);
	cap->neg = ft_strlen(cap->prom);
	cap->prompt = ft_start_of_str(cap->str, cap);
	cap->x = cap->prompt;
	ft_putstr(cap->prom);
	ft_set_term();
	cap->histo2->pos = cap->histo2->length;
}
