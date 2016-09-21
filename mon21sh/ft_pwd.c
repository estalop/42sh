/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 09:16:32 by jbobin            #+#    #+#             */
/*   Updated: 2016/06/02 10:10:42 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_cd_buf(char *argv)
{
	int		i;

	i = 0;
	while (argv[i] == '.' || argv[i] == '/')
		i++;
	if (argv[ft_strlen(argv) - 1] == '/')
		argv[ft_strlen(argv) - 1] = '\0';
	return (&argv[i]);
}

void	ft_sync_env(char **env[3], int pwd, int pwd1, int old)
{
	int		old1;

	old1 = 0;
	while (env[0][pwd] != NULL && ft_strncmp("PWD=", env[0][pwd], 4) != 0)
		pwd++;
	while (env[2][pwd1] != NULL && ft_strncmp("PWD=", env[2][pwd1], 4) != 0)
		pwd1++;
	while (env[0][old] != NULL && ft_strncmp("OLDPWD=", env[0][old], 7) != 0)
		old++;
	while (env[2][old1] != NULL && ft_strncmp("OLDPWD=", env[2][old1], 7) != 0)
		old1++;
	if (env[2][pwd1] != NULL && env[0][pwd] != NULL && \
		ft_strcmp(env[0][pwd], env[2][pwd1]) != 0)
	{
		ft_strdel(&env[2][pwd1]);
		env[2][pwd1] = ft_strdup(env[0][pwd]);
	}
	if (env[2][old1] != NULL && env[0][old] != NULL && \
		ft_strcmp(env[0][old], env[2][old1]) != 0)
	{
		ft_strdel(&env[2][old1]);
		env[2][old1] = ft_strdup(env[0][old]);
	}
}
