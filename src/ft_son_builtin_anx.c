/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_son_builtin_anx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 09:39:51 by jbobin            #+#    #+#             */
/*   Updated: 2017/01/04 09:53:36 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_son_history_anx(char *buf, int e)
{
	if (e == -1)
	{
		ft_putendl_fd(" Please set the home variable of \
env to execute history command", 2);
		exit(1);
	}
	else if (e == -2)
	{
		ft_putendl_fd(" You can't delete this historic entry", 2);
		exit(1);
	}
	else if (e == -3)
		exit(ft_error_fd());
	else if (e == -7)
		writehistoryp(&buf[7]);
	else if (e == -8)
		ft_putendl_fd("42sh: history: invalid option\nhistory: usage: \
history [-c] [-d offset] [n] or history -awrn [filename] or \
history -ps arg [arg...]", 2);
}
