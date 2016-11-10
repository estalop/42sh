/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:36:48 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/10 15:27:30 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_returnofprocess(int stat_lock)
{
	if (WIFEXITED(stat_lock))
		return (WEXITSTATUS(stat_lock));
	else if (WIFSIGNALED(stat_lock))
		return (128 + WTERMSIG(stat_lock));
	else if (WIFSTOPPED(stat_lock))
		return (128 + WSTOPSIG(stat_lock));
	return (-1);
}
