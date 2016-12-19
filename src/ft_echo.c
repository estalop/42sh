/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviviand <tviviand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 16:08:16 by tviviand          #+#    #+#             */
/*   Updated: 2016/12/19 09:10:09 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char *line)
{
	int		i;
	char	**txt;
	int		n;

	i = 1;
	txt = NULL;
	txt = ft_strsplit(line, ' ');
	if (!(n = 0) && !txt)
		exit(1);
	while (txt[i])
	{
		if (ft_strequ(txt[i], "-n"))
			n = 1;
		else
			ft_printf("%s", txt[i]);
		if (txt[i + 1] && !ft_strequ(txt[i], "-n"))
			ft_putchar(' ');
		else if (!txt[i + 1])
			break ;
		i++;
	}
	if (!n)
		ft_putchar('\n');
	ft_free_tab(&txt);
	exit(0);
}
