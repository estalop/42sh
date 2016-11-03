/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_and_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 13:36:26 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/03 15:57:34 by tbayet           ###   ########.fr       */
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

void	ft_end(t_termcaps *cap, char *str, int strlen)
{
	int	i;

	i = ft_calculate_height(str, strlen, cap) - \
		ft_calculate_height(str, cap->x, cap);
	cap->oldlen = ft_calculate_height(str, ft_strlen(str) + cap->neg, cap);
	while (i-- > 0)
		tputs(cap->sf, 1, ft_output);
	tputs(tgoto(cap->cv, 0, ft_calculate_whidth(str, strlen, cap)), 1, \
		ft_output);
}

void	ft_sig_stop_ex(int sig)
{
	if (sig == 2)
		ft_putchar('\n');
}

char	*ft_out(t_termcaps *cap, char buf[4], char *tmp)
{
	if (cap->exec == 1)
	{
		ft_select_cancel(cap->autotab, cap);
		cap->exec = 0;
	}
	else if (cap->exec == 2)
	{
		tmp = ft_select_get(cap->autotab, cap, &tmp);
		cap->exec = 0;
	} 
	else
	{
		if (buf[0] == 12)
			ft_putstr(cap->prom);
		if (buf[0] == 10)
		{
			ft_end(cap, tmp, ft_strlen(tmp) + cap->neg);
			tputs(cap->sf, 0, ft_output);
			tputs(cap->cr, 0, ft_output);
		}
	}
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
}
