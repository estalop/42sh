/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_termcap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 12:48:10 by jbobin            #+#    #+#             */
/*   Updated: 2016/09/30 09:36:36 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_arrow(t_termcaps *cap, int strlen, char buf[4], char *tmp)
{
	if (tmp != NULL && (buf[2] == 'C' || buf[2] == 'D'))
		ft_arrow_side(tmp, buf, cap, strlen);
	else if (buf[2] == 'A')
		tmp = ft_arrow_up(cap, tmp, strlen);
	else if (buf[2] == 'B')
		tmp = ft_arrow_down(cap, tmp, strlen);
	else if (buf[2] == 'H')
		ft_thome(cap, tmp);
	else if (buf[2] == 'F')
	{
		ft_end(cap, tmp, strlen);
		cap->x = strlen;
	}
	else if (buf[2] == '1')
	{
		read(0, buf, 3);
		ft_shift_arrow(cap, strlen, buf, tmp);
	}
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

static char	*ft_tselect(t_termcaps *cap, char *str, char buf[4])
{
	if (buf[0] == 27 && buf[1] == 91)
		str = ft_arrow(cap, (ft_strlen(str) + cap->neg), buf, str);
	else if (buf[0] == 10)
		return (str);
	else if (buf[0] == 127)
		str = ft_del_char(cap, str, 0);
	else if (buf[0] == 12)
	{
		tputs(cap->cl, 1, ft_output);
		ft_strdel(&str);
	}
	else if (buf[0] != 27 && buf[1] != 0)
		str = ft_multiple_char(cap, str, buf);
	else if (str == NULL && buf[0] != 27)
	{
		str = ft_strnew(1);
		str[0] = buf[0];
		ft_putstr(str);
		cap->x++;
	}
	else if (buf[0] != 27)
		str = ft_print_char(cap, str, buf[0]);
	return (str);
}

static void	ft_create_history(t_termcaps *cap, char *str)
{
	cap->y = 0;
	while (cap->y < 500 && cap->hist[cap->y] != NULL)
		cap->y++;
	if (cap->y == 500)
		ft_strdel(&cap->hist[--cap->y]);
	while (cap->y > 0)
	{
		cap->hist[cap->y] = cap->hist[cap->y - 1];
		cap->y--;
	}
	cap->hist[cap->y] = ft_strdup(str);
	cap->y = 0;
}

int			ft_read_termcap(t_termcaps *cap)
{
	char	buf[4];
	char	*tmp;

	ft_set_prompt(cap);
	while (42)
	{
		ft_bzero(buf, 4);
		if (read(0, buf, 3) <= 0 || buf[0] == 4)
			return (1);
		cap->str = ft_tselect(cap, cap->str, buf);
		tmp = cap->cmd ? cap->cmd : cap->str;
		if (buf[0] == 12 || buf[0] == 10)
			ft_out(cap, buf, cap->str);
		if (buf[0] == 10)
			break ;
	}
	if ((cap->i = ft_quote_not_finished(tmp, 0, cap)) != 0)
	{
		cap->y = 0;
		cap->str = ft_return(cap->str);
		return (ft_read_termcap(cap));
	}
	ft_create_history(cap, tmp);
	return (0);
}
