/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <chdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:02:26 by chdenis           #+#    #+#             */
/*   Updated: 2016/12/05 17:11:56 by chdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Fichier pour ajouter a l'env en passant par utilisant vos fonctions
*/

extern t_prstruct	*g_process;

void		env_setter(char *name, char *value)
{
	char			cmd[1048];
	char			*s;
	static char		prefix[] = "setenv ";

	ft_bzero(cmd, 1048);
	ft_strcpy(cmd, prefix);
	s = cmd + ft_strlen(prefix);
	ft_strcpy(s, name);
	s += ft_strlen(name);
	ft_strcpy(s, " ");
	ft_strcpy(s + 1, value);
	ft_setenv(cmd, &g_process->env[0], g_process->env[0], &g_process->env[2]);
}

void		env_destroyer(char *name)
{
	char			cmd[1048];
	char			*s;
	static char		prefix[] = "unsetenv ";

	ft_bzero(cmd, 1048);
	ft_strcpy(cmd, prefix);
	s = cmd + ft_strlen(prefix);
	ft_strcpy(s, name);
	ft_unsetenv(cmd, &g_process->env[2], g_process->env[2]);
}
