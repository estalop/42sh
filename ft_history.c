/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 18:00:35 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/30 16:00:04 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_run_history2(char *arg, t_dlist *histo, int index)
{
	int		number;

	number = ft_atoi(arg + index);
	ft_display_list4(histo, number);
	return (1);
}

int		ft_run_history3(char *arg, t_dlist *histo, int index)
{
	int		number;

	index++;
	number = ft_atoi(arg + index);
	ft_del_ele_list(histo, number, histo->p_head, 0);
	return (1);
}

int		ft_run_history4(char *home, t_dlist *histo)
{
	// a modifier, faudrait mettre un int new = 1 pour les commandes de ce bash actuel
	ft_write_history_file(histo, 2, open(ft_strjoin(home,
	"/.42sh"), O_RDWR | O_TRUNC | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR), 1);
	// on mets tout dans la liste, quand on ferme on doit rajouter dans le fichier
	// quand cette option est lance, il maj le fichier comme si on sortait maintenant du shell
	return (1);
}

int		ft_run_history5(char *arg, char *home, t_dlist *histo, int index)
{
	ft_get_check_file(histo, open(ft_strjoin(home, "/.42sh"), O_RDONLY), 0, 0);
	while (arg[index] == ' ' || arg[index] == '\t' || arg[index] == '\r' ||
			arg[index] == '\n')
		index++;
	if (arg[index] == '-')
		index++;
		// on recupere les lignes d'historique du fichier, et on ajoute celles non lues
		// cad celles ajoutees au fichier depuis l'ouverture du 42sh.
	return (1);
}

int			ft_run_history(char *arg, char *home, t_dlist *histo)
{
	int		index;

	index = 0;
	while (arg[index] == ' ' || arg[index] == '\t' || arg[index] == '\r' ||
			arg[index] == '\n')
		index++;
	if (arg[index] >= '0' && arg[index] <= '9')
		return (ft_run_history2(arg, histo, index));
	else if (arg[index] == '\0')
	{
		return (ft_display_list3(histo));
	}
	if (arg[index] == '-')
		index++;
	if (ft_check_options_history(arg, 'c', index) == 1)
	{
		// need to delete list, but need to check his code before 
		// ft_delete_list3(&histo);
		return (1);
	}
	if (ft_check_options_history(arg, 'd', index) == 1)
		return (ft_run_history3(arg, histo, index));
	if (ft_check_options_history(arg, 'a', index) == 1)
		return (ft_run_history4(home, histo));
	if (ft_check_options_history(arg, 'n', index) == 1)
		return (ft_run_history5(arg, home, histo, index));
	if (ft_check_options_history(arg, 'r', index) == 1)
	{
		// need to delete and then use ft_get_history_from_file
	}
	if (ft_check_options_history(arg, 'w', index) == 1)
		return (ft_write_history_file(histo, 2, open(ft_strjoin(home,
	"/.42sh"), O_RDWR | O_TRUNC | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR), 1));
	if (ft_check_options_history(arg, 's', index) == 1)
		ft_add_data(histo, arg + index + 2);
	return (1);
}
