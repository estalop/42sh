/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 10:07:37 by jbobin            #+#    #+#             */
/*   Updated: 2017/01/08 16:33:48 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_print_cd(char *buf)
{
	if (access(buf, F_OK) == 0)
		if (access(buf, X_OK) == 0)
		{
			if (chdir(buf) == -1)
				return (-3);
		}
		else
			return (-4);
	else
		return (-5);
	return (0);
}

int	ft_print_error_cd(char *argv)
{
	if (argv && argv[0] == '-')
		return (-7);
	else if (argv && argv[0] == '~')
		return (-8);
	return (-8);
}
