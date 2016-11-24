/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:33:41 by tbayet            #+#    #+#             */
/*   Updated: 2016/11/23 11:09:37 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_select_move_up(t_ldim *dims)
{
	if ((dims->pos % dims->y) == dims->scroll)
	{
		if (dims->pos)
		{
			dims->pos--;
			if (dims->scroll)
				dims->scroll--;
			else
				dims->scroll = dims->y - MAX_SELECT_LINES;
		}
		else
		{
			dims->pos = dims->size - 1;
			dims->scroll = dims->y - MAX_SELECT_LINES;
		}
		if (dims->scroll < 0)
			dims->scroll = 0;
	}
	else
		dims->pos--;
}

void	ft_select_move_down(t_ldim *dims)
{
	if (((dims->pos % dims->y) == dims->scroll + MAX_SELECT_LINES - 1)
		|| dims->pos == dims->size - 1)
	{
		if (dims->pos != dims->size - 1)
		{
			dims->pos++;
			if (dims->scroll == dims->y - MAX_SELECT_LINES)
				dims->scroll = 0;
			else
				dims->scroll++;
		}
		else
		{
			dims->pos = 0;
			dims->scroll = 0;
		}
	}
	else
		dims->pos++;
}

void	ft_select_move_left(t_ldim *dims)
{
	if (dims->pos - dims->y < 0)
	{
		dims->pos += dims->y * dims->x;
		if (dims->pos >= dims->size)
			dims->pos -= dims->y;
	}
	else
		dims->pos -= dims->y;
}

void	ft_select_move_right(t_ldim *dims)
{
	if (dims->pos + dims->y >= dims->size)
		dims->pos = dims->pos % dims->y;
	else
		dims->pos += dims->y;
}
