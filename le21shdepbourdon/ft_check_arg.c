/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 20:47:18 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/11 17:42:44 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		*ft_boucle(char *arg)
{
	int		index;
	int		index2;
	char	*process;

	process = malloc(sizeof(char) * ft_strlen(arg));
	index2 = 0;
	index = 0;
	while (arg[index] == ' ' || arg[index] == '\t' || arg[index] == '\n'
		|| arg[index] == '\r')
		index++;
	while (arg[index] != '\0' && arg[index] != '\t' && arg[index] != '\n'
		&& arg[index] != ' ')
	{
		process[index2] = arg[index];
		index2++;
		index++;
	}
	process[index2] = '\0';
	index2 = 0;
	while (arg[index] == '\t' || arg[index] == ' ' || arg[index] == '\n'
		|| arg[index] == '\n')
		index++;
	return (process);
}

char		**ft_get_options(char *arg, t_dlist *list, int x, char **option)
{
	size_t	index;

	option = ft_get_options1(arg, option);
	index = ft_strlen(option[0]);
	while (arg[index++] != '\0')
	{
		if (arg[index] == '-')
			option = ft_get_options2(arg, option, &index, &x);
		if (index < ft_strlen(arg) && arg[index] != '\0' && arg[index] != ' ')
		{
			if (ft_home(list) != NULL)
				option[x] = ft_memalloc(ft_strlen(arg) + ft_strlen(ft_home(list)));
			else
				option[x] = ft_memalloc(ft_strlen(arg) + 1);
			if (arg[index] == '~' && ft_home(list) != NULL)
				option[x] = ft_get_options3(ft_home(list), arg, &index, option[x]);
			else if (arg[index] == '~' && ft_home(list) == NULL)
				return (ft_error_home());
			else
				option[x] = ft_get_options4(&index, 0, option[x], arg);
			x++;
		}
	}
	option[x] = NULL;
	return (option);
}

char		*ft_generate_path(char *arg, t_dlist *list)
{
	int		compteur;
	char	*strjoin;
	char	*auto_path;

	compteur = ft_get_total_path(list) + 1;
	while (compteur > 0)
	{
		auto_path = ft_get_auto_path(compteur, list, 0, 0);
		strjoin = ft_strjoin(auto_path, arg);
		if (auto_path != NULL)
			free(auto_path);
		if (access(strjoin, X_OK) == 0)
			return (strjoin);
		compteur--;
		free(strjoin);
	}
	ft_putstr("zsh: command not found (or minishell did not find the correct");
	ft_putstr(" PATH. Check your PATH env variable)\n");
	return (NULL);
}

int			ft_check_arg2(char *arg, char **options, t_dlist *list, char *boucl)
{
	char	*tmp;

	tmp = ft_give_path(arg);
	ft_run_exe(tmp, options, list);
	ft_free_tab(options);
	free(boucl);
	free(tmp);
	return (1);
}

int			ft_check_arg(char *arg, t_dlist *list, int index, char *boucle)
{
	char	**options;

	options = NULL;
	if (ft_check_pipe(arg) == 1)
		arg = ft_new_arg(arg);
	options = ft_get_options(arg, list, 1, options);
	if (options == NULL)
		return (1);
	if (arg[index] == '/')
		return (ft_check_arg2(arg, options, list, boucle));
	else if (arg[index] != '\0')
		return (ft_check_arg3(boucle, list, options));
	else
	{
		ft_free_tab(options);
		free(boucle);
		return (0);
	}
	return (1);
}
