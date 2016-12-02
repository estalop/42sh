/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_anx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviviand <tviviand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:11:00 by tviviand          #+#    #+#             */
/*   Updated: 2016/12/02 17:27:01 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_check_bin_anx(char **bin, char ***argv)
{
	if (access(*bin, F_OK) == -1)
		ft_error_path(0, *argv[0]);
	else if (access(*bin, X_OK) == -1)
		ft_error_path(-1, *argv[0]);
	if (access(*bin, F_OK) == -1 || access(*bin, X_OK) == -1)
		ft_strdel(bin);
	ft_free_tab(argv);
	return (*bin);
}
