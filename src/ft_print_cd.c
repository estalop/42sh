/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 10:07:37 by jbobin            #+#    #+#             */
/*   Updated: 2017/01/04 10:39:38 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					ft_print_cd(char *buf)
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
	return (-1);
}
