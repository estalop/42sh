/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_termcap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <jbobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 12:48:10 by jbobin            #+#    #+#             */
/*   Updated: 2016/12/09 14:52:47 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_select.h"

static char	*ft_arrow(t_termcaps *cap, int strlen, char buf[4], char *tmp)
{
	if (cap->exec == 1)
	{
		ft_select_cancel(cap->autotab, cap, tmp);
		cap->exec = 0;
	}
	if (cap->exec == 2)
		ft_select_move(cap->autotab, buf[2], cap, tmp);
	else if (tmp != NULL && (buf[2] == 'C' || buf[2] == 'D'))
		ft_arrow_side(tmp, buf, cap, strlen);
	else if (buf[2] == 'A')
		tmp = ft_arrow_up(cap, tmp);
	else if (buf[2] == 'B')
		tmp = ft_arrow_down(cap, tmp);
	else if (buf[2] == 'H')
		ft_thome(cap, tmp);
	else if (buf[2] == 'F')
	{
		ft_end(cap, tmp, strlen);
		cap->x = strlen;
	}
	else if (buf[2] == '1' && (read(0, buf, 3) > -2))
		ft_shift_arrow(cap, strlen, buf, tmp);
	return (tmp);
}

char		*ft_print_char(t_termcaps *cap, char *str, char buf)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strnew(ft_strlen(str) + 1);
	while (i < (cap->x - cap->neg) && str[i] != '\0')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = buf;
	while (str[i] != '\0')
	{
		tmp[i + 1] = str[i];
		i++;
	}
	tmp[i + 1] = '\0';
	ft_strdel(&str);
	ft_reset(cap, tmp);
	ft_putstr(cap->prom);
	ft_newputstr(&tmp[cap->prompt - cap->neg], cap);
	cap->x++;
	ft_put_cursor(cap, tmp);
	return (tmp);
}

static int	ft_tselect_anx(t_termcaps *cap, char **str, char *buf)
{
	if (buf[0] == 10)
		return (1);
	else if (buf[0] == 127)
		*str = ft_del_char(cap, *str, 0);
	else if (buf[0] == 12)
	{
		tputs(cap->cl, 1, ft_output);
		ft_strdel(str);
	}
	else if (buf[0] != 27 && buf[1] != 0)
		*str = ft_multiple_char(cap, *str, buf);
	else if (*str == NULL && buf[0] != 27)
	{
		*str = ft_strnew(1);
		*str[0] = buf[0];
		ft_putstr(*str);
		cap->x++;
	}
	else if (buf[0] != 27)
		*str = ft_print_char(cap, *str, buf[0]);
	return (0);
}

static char	*ft_tselect(t_termcaps *cap, char *str, char buf[4])
{
	if (buf[0] == 4)
		return (str);
	if (buf[0] == 27 && buf[1] == 91)
		str = ft_arrow(cap, (ft_strlen(str) + cap->neg), buf, str);
	else if (buf[0] == '\t' && buf[1] == 0)
		str = ft_autocomp(cap, str);
	else
	{
		if (buf[0] != 10 && cap->exec)
		{
			ft_select_cancel(cap->autotab, cap, str);
			cap->exec = 0;
		}
		if (ft_tselect_anx(cap, &str, buf))
			return (str);
	}
	return (str);
}

int			ft_read_termcap(t_termcaps *cap)
{
	char	buf[4];
	char	*tmp;

	ft_set_prompt(cap);
	while (42)
	{
		ft_bzero(buf, 4);
		if (read(0, buf, 3) <= 0 || (buf[0] == 4 && !cap->str && !cap->cmd))
			return (1);
		cap->str = ft_tselect(cap, cap->str, buf);
		tmp = cap->cmd ? cap->cmd : cap->str;
		if (buf[0] == 12 || buf[0] == 10)
			tmp = ft_out(cap, buf, tmp);
		if (buf[0] == 10)
			break ;
		else if (buf[0] == 4)
			tputs(cap->bl, 0, ft_output);
	}
	if ((cap->i = ft_quote_not_finished(tmp, 0, cap)) != 0)
	{
		cap->y = 0;
		cap->str = ft_return(cap->str);
		return (ft_read_termcap(cap));
	}
	return (0);
}
