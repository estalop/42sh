/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirdarkd <sirdarkd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:44:33 by sirdarkd          #+#    #+#             */
/*   Updated: 2016/11/21 18:07:35 by sirdarkdev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	isinbuiltin(char *l)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (l[i])
	{
		if (l[i] != ' ' && l[i] != '\t')
		{
			j = i;
			while (l[i])
			{
				if (l[i] == ' ' && l[i] == '\t')
					break ;
				i++;
			}
			break ;
		}
		i++;
	}
	if (!ft_strncmp(l + j, "env",i - j) || !ft_strncmp(l + j, "setenv",i - j) ||
	!ft_strncmp(l + j, "unsetenv",i - j) || !ft_strncmp(l + j, "echo",i - j) ||
	!ft_strncmp(l + j, "cd",i - j) || !ft_strncmp(l + j, "history",i - j))
		return (1);
	return (0);
}
