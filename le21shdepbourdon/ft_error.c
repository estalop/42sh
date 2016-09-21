/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 19:23:35 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/08 15:54:17 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		ft_putchar_error(char c)
{
	write(2, &c, 1);
}

void		ft_putstr_error(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar_error(str[index]);
		index++;
	}
}

void		ft_error(char *arg, int version)
{
	if (version == 1)
	{
		ft_putstr_error("zsh: command not found: ");
		ft_putstr_error(arg);
		ft_putchar_error('\n');
	}
	else if (version == 2)
	{
		ft_putstr_error("cd: no such file or directory: ");
		ft_putstr_error(arg);
		ft_putchar_error('\n');
	}
}
