/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <chdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:07:31 by chdenis           #+#    #+#             */
/*   Updated: 2016/12/04 14:24:09 by chdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	unset builtin: unset les variables données
*/

int			ft_unset(char *s)
{
	char	**args;
	char	**name;

	args = ft_strsplit(s, ' ');
	name = args + 1;
	while (*name)
	{
		// TODO: supprimer *a des variables locales et de l'environnement si existe
		name++;
	}
	ft_free_tab(&args);
	return (0);
}
