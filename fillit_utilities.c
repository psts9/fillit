/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:59:53 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/22 21:54:04 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "links.h"
#include "libft.h"

int			min_board_size(int n)
{
	int pow;

	pow = 1;
	while ((pow * pow) < (n * 4))
		++pow;
	return (pow);
}

static void	create_grid(char ***grid, int board_size)
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
}

static void	print_grid(char **grid)
{
	int i;
	int j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			ft_putchar(grid[i][j]);
			++j;
		}
		ft_putchar('\n');
		++i;
	}
}

void		print_board(t_tetri *list, int board_size)
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
			grid[TRUE_YPOS(list, n)][TRUE_XPOS(list, n)] = list->name;
			++n;
		}
		list = list->next;
	}
	print_grid(grid);
}

void		name_tet_list(t_tetri **list)
{
	t_tetri *tmp;
	char	c;

	tmp = *list;
	c = 'A';
	while (tmp)
	{
		tmp->name = c++;
		tmp = tmp->next;
	}
}
