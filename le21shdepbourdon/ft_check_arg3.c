/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 14:59:09 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/08 16:30:41 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_check_arg3(char *boucle, t_dlist *list, char **options)
{
	char	*generated;

	if (boucle[0] != '.')
	{
		generated = ft_generate_path(boucle, list);
		ft_run_exe(generated, options, list);
		free(generated);
	}
	else
		ft_run_exe(boucle, options, list);
	ft_free_tab(options);
	free(boucle);
	return (1);
}
