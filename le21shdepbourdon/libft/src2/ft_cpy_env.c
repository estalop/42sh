/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 19:33:48 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/17 15:38:03 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist			*ft_cpy_env3(t_dlist *list)
{
	list = ft_add_data(list, "ZSH=");
	list = ft_add_data(list, "PAGER=");
	list = ft_add_data(list, "LESS=");
	list = ft_add_data(list, "LC_CTYPE=");
	list = ft_add_data(list, "LSCOLORS=");
	list = ft_add_data(list, "_=");
	return (list);
}

t_dlist			*ft_cpy_env2(t_dlist *list)
{
	list = ft_add_data(list, "TERM_SESSION_ID=");
	list = ft_add_data(list, "SSH_AUTH_SOCK=");
	list = ft_add_data(list, "Apple_PubSub_Socket_Render=");
	list = ft_add_data(list, "COLORFGBG=");
	list = ft_add_data(list, "ITERM_PROFILE=");
	list = ft_add_data(list, "XPC_FLAGS=");
	list = ft_add_data(list, "LANG=");
	list = ft_add_data(list, "PWD=");
	list = ft_add_data(list, "SHELL=");
	list = ft_add_data(list, "TERM_PROGRAM_VERSION=");
	list = ft_add_data(list, "TERM_PROGRAM=");
	list = ft_add_data(list, "PATH=");
	list = ft_add_data(list, "TERM=");
	list = ft_add_data(list, "HOME=");
	list = ft_add_data(list, "TMPDIR=");
	list = ft_add_data(list, "USER=");
	list = ft_add_data(list, "XPC_SERVICE_NAME=");
	list = ft_add_data(list, "LOGNAME=");
	list = ft_add_data(list, "ITERM_SESSION_ID=");
	list = ft_add_data(list, "__CF_USER_TEXT_ENCODING=");
	list = ft_add_data(list, "SHLVL=");
	list = ft_add_data(list, "OLDPWD=");
	list = ft_cpy_env3(list);
	return (list);
}

t_dlist			*ft_cpy_env(t_dlist *list)
{
	int				i;
	extern char		**environ;

	i = 0;
	while (environ[i])
	{
		list = ft_add_data(list, environ[i]);
		i++;
	}
	return (list);
}
