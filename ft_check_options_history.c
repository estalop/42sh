/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_options_history.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 18:30:59 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/01 20:41:14 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_options_history2(char *arg, char c, int index)
{
	if (c == 'r')
		if (arg[index] == 'r' && (arg[index - 1] == '-' || arg[index - 1] == 'a'
	|| arg[index - 1] == 'd' || arg[index - 1] == 'n' || arg[index - 1] == 'c'
	|| arg[index - 1] == 'w' || arg[index - 1] == 'p' || arg[index - 1] == 's'))
			return (1);
	if (c == 'w')
		if (arg[index] == 'w' && (arg[index - 1] == '-' || arg[index - 1] == 'a'
	|| arg[index - 1] == 'd' || arg[index - 1] == 'n' || arg[index - 1] == 'r'
	|| arg[index - 1] == 'c' || arg[index - 1] == 'p' || arg[index - 1] == 's'))
			return (1);
	if (c == 'p')
		if (arg[index] == 'p' && (arg[index - 1] == '-' || arg[index - 1] == 'a'
	|| arg[index - 1] == 'd' || arg[index - 1] == 'n' || arg[index - 1] == 'r'
	|| arg[index - 1] == 'w' || arg[index - 1] == 'c' || arg[index - 1] == 's'))
			return (1);
	if (c == 's')
		if (arg[index] == 's' && (arg[index - 1] == '-' || arg[index - 1] == 'a'
	|| arg[index - 1] == 'd' || arg[index - 1] == 'n' || arg[index - 1] == 'r'
	|| arg[index - 1] == 'w' || arg[index - 1] == 'p' || arg[index - 1] == 'c'))
			return (1);
	return (0);
}

int		ft_check_options_history(char *arg, char c, int index)
{
	if (c == 'c')
		if (arg[index] == 'c' && (arg[index - 1] == '-' || arg[index - 1] == 'a'
	|| arg[index - 1] == 'd' || arg[index - 1] == 'n' || arg[index - 1] == 'r'
	|| arg[index - 1] == 'w' || arg[index - 1] == 'p' || arg[index - 1] == 's'))
			return (1);
	if (c == 'a')
		if (arg[index] == 'a' && (arg[index - 1] == '-' || arg[index - 1] == 'c'
	|| arg[index - 1] == 'd' || arg[index - 1] == 'n' || arg[index - 1] == 'r'
	|| arg[index - 1] == 'w' || arg[index - 1] == 'p' || arg[index - 1] == 's'))
			return (1);
	if (c == 'd')
		if (arg[index] == 'd' && (arg[index - 1] == '-' || arg[index - 1] == 'a'
	|| arg[index - 1] == 'c' || arg[index - 1] == 'n' || arg[index - 1] == 'r'
	|| arg[index - 1] == 'w' || arg[index - 1] == 'p' || arg[index - 1] == 's'))
			return (1);
	if (c == 'n')
		if (arg[index] == 'n' && (arg[index - 1] == '-' || arg[index - 1] == 'a'
	|| arg[index - 1] == 'd' || arg[index - 1] == 'c' || arg[index - 1] == 'r'
	|| arg[index - 1] == 'w' || arg[index - 1] == 'p' || arg[index - 1] == 's'))
			return (1);
	return (ft_check_options_history2(arg, c, index));
}
