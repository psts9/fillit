/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 16:48:02 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/22 21:54:09 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "links.h"
#include "libft.h"

int				tet_list_size(t_tetri *list)
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

static void		set_tetri_to_lefttop(t_tetri **list)
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

static t_tetri	*make_tetri(const char *board)
{
	int		i;
	int		x;
	int		y;
	int		n;
	t_tetri *result;

	if (!(result = malloc(sizeof(t_tetri))))
		return (NULL);
	SET_TO_ZERO(n, y, i);
	while (i < TETRIMINO_BOARD)
	{
		x = 0;
		while (x < 4)
		{
			if (board[i] == '#')
			{
				result->x[n] = x;
				result->y[n++] = y;
			}
			INCREMENT(x, i);
		}
		INCREMENT(y, i);
	}
	SET_TO_ZERO(result->next, result->prev, n);
	return (result);
}

static void		add_tetri(t_tetri **list, const char *board)
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

t_tetri			*create_tetrimino_list(const char *str)
{
	int		i;
	char	tetri[TETRIMINO_BOARD];
	t_tetri *result;
	t_tetri	*tmp;
	t_tetri *prev;

	SET_TO_ZERO(i, result, tmp);
	while (str[i])
	{
		ft_strncpy(tetri, str + i, TETRIMINO_BOARD - 1);
		tetri[TETRIMINO_BOARD - 1] = '\0';
		i += TETRIMINO_BOARD;
		(str[i] ? ++i : 0);
		add_tetri(&result, tetri);
	}
	tmp = result;
	while (tmp)
	{
		prev = tmp;
		set_tetri_to_lefttop(&tmp);
		tmp = tmp->next;
		(tmp ? tmp->prev = prev : 0);
	}
	name_tet_list(&result);
	return (result);
}
