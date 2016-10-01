/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_home.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 15:52:52 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/01 16:24:04 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_home(char **env)
{
	int		index;

	if (env == NULL)
		return (NULL);
	index = 0;
	while (env[index] != NULL && ft_strncmp(env[index], "HOME=", 5) != 0)
		index++;
	if (env[index] != NULL && ft_strncmp(env[index], "HOME=", 5) == 0 && ft_strlen(env[index]) > 5)
	{
		return (env[index] + 5);
	}
	return (NULL);
}
