/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_son_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:55:06 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/18 14:32:06 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_son_env(char **buf, char **bin, char **env)
{
	char	**argv;
	char	*tmp;
	int		i;

	i = 1;
	if ((argv = ft_split(*buf)) == NULL)
		exit(1);
	while (argv[i] != NULL && argv[i][0] == '-' && argv[i][1] != '\0' && \
			ft_strcmp(argv[i], "--") != 0)
		i++;
	if (argv[i] != NULL && ft_strcmp(argv[i], "--") == 0)
		i++;
	if (argv[i] == NULL)
	{
		ft_free_tab(&argv);
		ft_print_env(env);
		exit(0);
	}
	else
	{
		tmp = *buf;
		ft_strdel(bin);
		*bin = ft_strdup(argv[i]);
		i = 0;
		while (ft_strncmp(&tmp[i], *bin, ft_strlen(*bin) != 0))
			i++;
		*buf = ft_strdup(&tmp[i]);
		ft_strdel(&tmp);
	}
}

void	 	ft_son_builtin(char **buf, char **bin, char **env)//, t_prstruct *proc)
{
	if (ft_strncmp(*bin, "env", 3) == 0)
		ft_son_env(buf, bin, env);

}
