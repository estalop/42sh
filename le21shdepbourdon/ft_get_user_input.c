/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_user_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 14:08:26 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/11 17:34:05 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int				ft_get_user_input(void)
{
	char		*buffer;
	t_dlist		*list;
	t_dlist		*histo;
	t_dlist		*to_paste;
	t_dlist		*env;

	env = NULL;
	histo = NULL;
	list = NULL;
	to_paste = NULL;
	to_paste = dlist_new(to_paste);
	histo = dlist_new(histo);
	buffer = malloc(sizeof(char) * 7);
	list = dlist_new(list);
	env = dlist_new(env);
	env = ft_cpy_env(env);
	if (ft_list_size(env->p_head) == 0)
		env = ft_cpy_env2(env);
	ft_show_prompt();
	while (42)
	{
		buffer = ft_bzero(buffer, 7);
		read(0, buffer, 6);
		if (ft_detect_up(buffer) == 1 || ft_detect_down(buffer) == 1)
		{
			ft_move_and_clean(list);
			if (ft_get_size_from_list(list) > 0 && list->length > 0)
				ft_delete_list(&list);
			list = NULL;
			list = dlist_new(list);
		}
		if (ft_deal_input(buffer, list, histo, to_paste) == 1)
		{
			ft_putchar('\n');
			if (ft_process(ft_get_str_from_list(list), env) == 1)
				return (1);
			ft_delete_list(&list);
			list = NULL;
			list = dlist_new(list);
		}
	}
}
