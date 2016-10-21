/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:05:42 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/06 14:09:08 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_tmp(char *arg)
{
	int		index;

	index = 0;
	while (arg[index] != '\0')
	{
		if (arg[index] != ' ' && arg[index] != '\t' && arg[index] != '\n' &&
			arg[index] != '\r')
			return (1);
		index++;
	}
	return (0);
}
