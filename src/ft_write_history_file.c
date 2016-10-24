/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_history_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 15:57:57 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/04 16:04:30 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_error_fd(void)
{
	ft_putstr("An error just happened. Check your rights");
	ft_putstr(" and home env variable");
	return (1);
}

int		ft_write_history_file(t_dlist *histo, int index, int fd, int pos)
{
	t_node		*courant;

	courant = histo->p_head;
	if (fd <= 0)
		return (ft_error_fd());
	while (pos <= histo->length)
	{
		if (courant->wrote == 0)
		{
			ft_putstr_fd(courant->data, fd);
			ft_putchar_fd('\n', fd);
		}
		courant->wrote = 1;
		courant = courant->p_next;
		pos++;
	}
	if (index == 2)
		ft_putstr_fd("history -w\n", fd);
	else if (index == 0)
		ft_putstr_fd("history -a\n", fd);
	else
		ft_putstr_fd("exit\n", fd);
	close(fd);
	return (1);
}

int		ft_write_history_file2(t_dlist *histo, int fd, int pos, int exit)
{
	t_node		*courant;

	courant = histo->p_head;
	if (fd > 0)
	{
		while (pos <= histo->length)
		{
			ft_putstr_fd(courant->data, fd);
			ft_putchar_fd('\n', fd);
			courant->wrote = 1;
			courant = courant->p_next;
			pos++;
		}
	}
	else
	{
		ft_printf("An error just happened, Check your rights and your \
		home env variable");
		return (1);
	}
	if (exit != 1)
		ft_putstr_fd("history -w\n", fd);
	close(fd);
	return (1);
}
