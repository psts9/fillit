/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:04:08 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/23 19:15:10 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "links.h"

static void	fillit_setup(t_tetri **list)
{
	t_tetri *head;
	int		n;
	int		width;
	int		height;

	head = *list;
	while (head)
	{
		head->x_pos = 0;
		head->y_pos = 0;
		n = 0;
		width = 0;
		height = 0;
		while (n < 4)
		{
			if (head->x[n] > width)
				width = head->x[n];
			if (head->y[n] > height)
				height = head->y[n];
			++n;
		}
		head->width = width + 1;
		head->height = height + 1;
		head = head->next;
	}
}

static int	crosses_tet(t_tetri *tetri)
{
	t_tetri *curr;
	int		n1;
	int		n2;

	curr = tetri;
	tetri = tetri->prev;
	while (tetri)
	{
		n1 = 0;
		while (n1 < 4)
		{
			n2 = 0;
			while (n2 < 4)
			{
				if (TRUE_XPOS(tetri, n1) == TRUE_XPOS(curr, n2))
					if (TRUE_YPOS(tetri, n1) == TRUE_YPOS(curr, n2))
						return (1);
				++n2;
			}
			++n1;
		}
		tetri = tetri->prev;
	}
	return (0);
}

static int	place_tet(t_tetri **tetri, int board_size)
{
	int n;

	n = 0;
	while (board_size - (*tetri)->y_pos - (*tetri)->height >= 0)
	{
		while (board_size - (*tetri)->x_pos - (*tetri)->width >= 0)
		{
			if (!crosses_tet(*tetri))
				return (1);
			++((*tetri)->x_pos);
		}
		++((*tetri)->y_pos);
		(*tetri)->x_pos = 0;
	}
	return (0);
}

static void	fillit_update(t_tetri **list, int *board_size, t_tetri **temp)
{
	if (!((*list)->prev))
	{
		++(*board_size);
		*temp = *list;
		while (*temp)
		{
			(*temp)->x_pos = 0;
			(*temp)->y_pos = 0;
			(*temp) = (*temp)->next;
		}
	}
	else
	{
		(*list)->x_pos = 0;
		(*list)->y_pos = 0;
		(*list) = (*list)->prev;
		if (*board_size - (*list)->x_pos - 1 >= 0)
			++((*list)->x_pos);
		else
		{
			(*list)->x_pos = 0;
			++((*list)->y_pos);
		}
	}
}

void		fillit(t_tetri *list)
{
	int		board_size;
	t_tetri	*head;
	t_tetri *temp;

	fillit_setup(&list);
	board_size = min_board_size(tet_list_size(list));
	head = list;
	while (list)
	{
		if (place_tet(&list, board_size))
			list = list->next;
		else
			fillit_update(&list, &board_size, &temp);
	}
	print_board(head, board_size);
}
