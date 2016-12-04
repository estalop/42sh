/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <chdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 16:08:16 by tviviand          #+#    #+#             */
/*   Updated: 2016/12/04 13:51:40 by chdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char *line)
{
	int		i;
	char	**txt;

	i = 1;
	txt = NULL;
	txt = ft_strsplit(line, ' ');
	if (!txt)
		exit(1);
	while (txt[i])
	{
		ft_printf("%s", txt[i]);
		if (txt[i + 1])
			ft_putchar(' ');
		else
			break ;
		i++;
	}
	ft_putchar('\n');
	ft_free_tab(&txt);
	exit(0);
}
