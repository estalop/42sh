/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fourth_redirection_anx.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviviand <tviviand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 18:20:45 by tviviand          #+#    #+#             */
/*   Updated: 2016/12/18 18:31:34 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_if_hyphen_anx(char **tmp, char **tmp2, char **tmp3,
	t_hered *tmpstruct)
{
	*tmp3 = *tmp2 ? ft_strjoin(*tmp2, *tmp) : *tmp;
	ft_strdel(tmp2);
	*tmp3 != *tmp ? ft_strdel(tmp) : 0;
	ft_strdel(&tmpstruct->str);
	tmpstruct->str = *tmp3;
}
