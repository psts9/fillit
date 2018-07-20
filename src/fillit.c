/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:04:08 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/19 23:35:10 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "links.h"

#include <stdio.h>
#include <unistd.h>


int		min_board_size(int n)
{
	int	pow;

	pow = 1;
	while ((pow * pow) < (n * 4))
		++pow;
	return (pow);
}

void	fillit_setup(t_tetri **list)
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

void	create_grid(char ***grid, int board_size)
{
	int i;
	int j;

	i = 0;
	(*grid) = (char**)malloc(sizeof(char*) * (board_size + 1));
	while (i < board_size)
	{
		(*grid)[i] = (char*)malloc(sizeof(char) * (board_size + 1));
		(*grid)[i][board_size] = '\0';
		j = 0;
		while (j < board_size)
		{
			(*grid)[i][j] = '.';
			++j;
		}
		++i;
	}
	(*grid)[i] = NULL;
	i = 0;
	return ;
}

void	print_grid(char **grid)
{
	int i = 0;
	int j = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			putchar(grid[i][j]);
			++j;
		}
		putchar('\n');
		++i;
	}
}

int		crosses_tet(t_tetri *tetri)
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
				if ((tetri->x[n1] + tetri->x_pos) == (curr->x[n2] + curr->x_pos))
					if ((tetri->y[n1] + tetri->y_pos) == (curr->y[n2] + curr->y_pos))
						return (1);
				++n2;
			}
			++n1;
		}
		tetri = tetri->prev;
	}
	return (0);
}

int		place_tet(t_tetri **tetri, int board_size)
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

void	print_board(t_tetri *list, int board_size)
{
	char	**grid;
	int		n;

	create_grid(&grid, board_size);
	while (list->prev)
		list = list->prev;
	while (list)
	{
		n = 0;
		while (n < 4)
		{
			grid[list->y[n] + list->y_pos][list->x[n] + list->x_pos] = list->name;
			++n;
		}
		list = list->next;
	}
	print_grid(grid);
}

void	fillit(t_tetri *list)
{
	int		board_size;
	int		x;
	t_tetri	*head;

	fillit_setup(&list);
	board_size = min_board_size(tet_list_size(list));
	head = list;
	while (list)
	{
		if (place_tet(&list, board_size))
			list = list->next;
		else if (!(list->prev))
		{
			++board_size;
			t_tetri *temp = list;
			while (temp)
			{
				temp->x_pos = 0;
				temp->y_pos = 0;
				temp = temp->next;
			}
		}
		else
		{
			list->x_pos = 0;
			list->y_pos = 0;
			list = list->prev;
			if (board_size - list->x_pos - 1 >= 0)
				++(list->x_pos);
			else
			{
				list->x_pos = 0;
				++(list->y_pos);
			}
		}
	}
	print_board(head, board_size);
}
