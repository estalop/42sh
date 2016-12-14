/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocessing_anx.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviviand <tviviand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:00:06 by tviviand          #+#    #+#             */
/*   Updated: 2016/12/14 17:28:38 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	islast(char *l, int cur)
{
	int i;

	i = cur + 1;
	while (l[i])
	{
		if (l[i] != ' ' && l[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_preprocesssplit_anx_anx(t_preprocesssplit *p, char *l)
{
	if (!islast(l, p->i))
	{
		p->com[p->c] = ft_strsub(l, p->j, p->i - p->j);
		p->c++;
		p->j = p->i + 1;
		p->i += 2;
	}
	else
	{
		p->com[p->c] = NULL;
		p->j = p->i + 1;
		p->i++;
		return (1);
	}
	return (0);
}

int			ft_preprocesssplit_anx(char *l, t_operators *t,
	t_preprocesssplit *p)
{
	while (l[p->i])
	{
		if ((!ft_strncmp(&l[p->i], ";", 1) && ft_strncmp(&l[p->i], ";;", 2)) ||
		(!ft_strncmp(&l[p->i], "&&", 2) && ft_strncmp(&l[p->i], "&&&", 3)) ||
		(!ft_strncmp(&l[p->i], "||", 2) && ft_strncmp(&l[p->i], "|||", 3)))
		{
			if (ft_preprocesssplit_anx_anx(p, l))
				break ;
		}
		else if (!ft_strncmp(&l[p->i], "&&&", 3) || \
		!ft_strncmp(&l[p->i], "|||", 3) || !ft_strncmp(&l[p->i], ";;", 2))
		{
			ft_printf("42sh: parse error near '%c'\n", l[p->i]);
			t->err = -1;
			p->com[p->c + 1] = NULL;
			ft_free_tab(&p->com);
			return (1);
		}
		p->i++;
	}
	p->com[p->c] = ft_strsub(l, p->j, p->i - p->j);
	p->com[p->c + 1] = NULL;
	return (0);
}
