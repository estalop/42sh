/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <jbobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 10:48:54 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/25 18:32:41 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_reset(t_termcaps *cap, char *str)
{
	int	i;
	int	j;

	j = ft_calculate_height(str, (ft_strlen(str) + cap->neg), cap);
	if ((i = ft_calculate_height(str, cap->x, cap)) > 0)
		while (i > 0)
		{
			tputs(cap->sr, 1, ft_output);
			i--;
		}
	tputs(cap->cr, 1, ft_output);
	while (j >= 0)
	{
		tputs(cap->dc, 0, ft_output);
		j--;
	}
}

void		ft_put_cursor(t_termcaps *cap, char *str)
{
	int	i;

	if ((i = ft_calculate_height(str, (ft_strlen(str) + cap->neg), cap)) > 0)
		while (i > 0)
		{
			tputs(cap->sr, 1, ft_output);
			i--;
		}
	i = ft_calculate_height(str, cap->x, cap);
	while (i > 0)
	{
		tputs(cap->sf, 1, ft_output);
		i--;
	}
	tputs(tgoto(cap->cv, 0, ft_calculate_whidth(str, cap->x, cap)), 1, \
			ft_output);
}

static void	ft_put_info(t_termcaps *cap, char *str, char **del)
{
	ft_strdel(del);
	ft_printf(cap->prom);
	ft_newputstr(&str[cap->prompt - cap->neg], cap);
	ft_put_cursor(cap, str);
}

char		*ft_del_char(t_termcaps *cap, char *str, int i)
{
	char	*tmp;

	if (cap->x > cap->prompt)
	{
		ft_reset(cap, str);
		cap->x--;
		tmp = ft_strnew(ft_strlen(str) - 1);
		while (str[i] != '\0' && i < (cap->x - cap->neg))
		{
			tmp[i] = str[i];
			i++;
		}
		if (str[i] != '\0')
			i++;
		while (str[i] != '\0')
		{
			tmp[i - 1] = str[i];
			i++;
		}
		ft_put_info(cap, tmp, &str);
		return (tmp);
	}
	else
		tputs(cap->bl, 0, ft_output);
	return (str);
}

char		*ft_multiple_char(t_termcaps *cap, char *str, char buf[4])
{
	int		i;

	i = 0;
	while (ft_isprint(buf[i]) == 0)
		i++;
	if (str == NULL)
	{
		str = ft_strnew(1);
		str[0] = buf[0];
		ft_putstr(&str[cap->prompt - cap->neg]);
		cap->x = cap->prompt + 1;
		i++;
	}
	while (buf[i] != '\0')
	{
		if (ft_isprint(buf[i]) == 1)
			str = ft_print_char(cap, str, buf[i++]);
		else
			i++;
	}
	return (str);
}
