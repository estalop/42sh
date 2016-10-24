/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviviand <tviviand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 16:08:16 by tviviand          #+#    #+#             */
/*   Updated: 2016/10/24 16:35:26 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char *line)
{
	int		i;
	char	**txt;

	//Get l env et voir ce qui est necessaire
	i = 1;
	txt = ft_strsplit(line, ' ');
	//Voir le vrai code retour erreur
	if (!txt)
		return (1);
	while (txt[i])
	{
		ft_printf(txt[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	ft_deltab(txt);
	return (0);
}
