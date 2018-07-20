/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 16:48:02 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/19 18:03:33 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "links.h"
#include "libft.h"

#include <stdio.h>

int		tet_list_size(t_tetri *list)
{
	int i;

	i = 0;
	while (list)
	{
		list = list->next;
		++i;
	}
	return (i);
}

void	set_tetri_to_lefttop(t_tetri **list)
{
	int	i;
	int	min_x;
	int	min_y;

	i = 0;
	min_x = (*list)->x[0];
	min_y = (*list)->y[0];
	while (i < 4)
	{
		if ((*list)->x[i] < min_x)
			min_x = (*list)->x[i];
		if ((*list)->y[i] < min_y)
			min_y = (*list)->y[i];
		++i;
	}
	i = 0;
	while (i < 4)
	{
		(*list)->x[i] -= min_x;
		(*list)->y[i] -= min_y;
		++i;
	}
}

t_tetri	*make_tetri(const char *board)
{
	int		i;
	int		x;
	int		y;
	int		n;
	t_tetri *result;

	if (!(result = malloc(sizeof(t_tetri))))
		return (NULL);
	n = 0;
	y = 0;
	i = 0;
	while (board[i])
	{
		x = 0;
		while (x < 4)
		{
			if (board[i] == '#')
			{
				result->x[n] = x;
				result->y[n] = y;
				++n;
			}
			++x;
			++i;
		}
		++i;
		++y;
	}
	result->next = NULL;
	result->prev = NULL;
	return (result);
}

void	add_tetri(t_tetri **list, const char *board)
{
	t_tetri *tmp;

	if (!(*list))
	{
		*list = make_tetri(board);
		return ;
	}
	tmp = *list;
	while ((*list)->next)
		*list = (*list)->next;
	(*list)->next = make_tetri(board);
	*list = tmp;
}

t_tetri	*create_tetrimino_list(const char *str)
{
	int		i;
	char	c;
	char	tetri[TETRIMINO_BOARD];
	t_tetri *result;
	t_tetri	*tmp;
	t_tetri *prev;

	i = 0;
	result = NULL;
	while (str[i])
	{
		ft_strncpy(tetri, str + i, TETRIMINO_BOARD - 1);
		tetri[TETRIMINO_BOARD - 1] = '\0';
		i += TETRIMINO_BOARD;
		if (str[i])
			++i;
		add_tetri(&result, tetri);
	}
	tmp = result;
	c = 'A';
	while (tmp)
	{
		prev = tmp;
		tmp->name = c++;
		set_tetri_to_lefttop(&tmp);
		tmp = tmp->next;
		if (tmp)
			tmp->prev = prev;
	}
	return (result);
}

// ####
// t_tetri.coords[0].x = 0
// t_tetri.coords[0].y = 0
//
// t_tetri.coords[1].x = 1
// t_tetri.coords[1].y = 0
//
// t_tetri.coords[2].x = 2
// t_tetri.coords[2].y = 0
//
// t_tetri.coords[3].x = 3
// t_tetri.coords[3].y = 0
//
// ###
// #
// t_tetri.coords[0].x = 0
// t_tetri.coords[0].y = 0
//
// t_tetri.coords[1].x = 1
// t_tetri.coords[1].y = 0
//
// t_tetri.coords[2].x = 2
// t_tetri.coords[2].y = 0
//
// t_tetri.coords[3].x = 0
// t_tetri.coords[3].y = 1
