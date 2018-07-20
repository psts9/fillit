/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 19:19:38 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/19 23:35:14 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

#include "file_handler.h"
#include "links.h"

int		main(void)
{
	char	*str;
	char	*file = "../test_files/sample_file.fillit";
	t_tetri	*tetri_list;
	int		board_size;

	str = file_to_str(file);
	// error handling
	tetri_list = create_tetrimino_list(str);/*
	while (tetri_list)
	{
		int x = 0;
		while (x < 4)
		{
			printf("x = %d, %c\n", tetri_list->x[x], tetri_list->name);
			printf("y = %d, %c\n", tetri_list->y[x], tetri_list->name);
			++x;
		}
		printf("\n");
		tetri_list = tetri_list->next;
	}*/
//	do
//	{
//		int x = 0;
//		while (x < 4)
//		{
//			printf("x = %d, %c\n", tetri_list->x[x], tetri_list->name);
//			printf("y = %d, %c\n", tetri_list->y[x], tetri_list->name);
//			++x;
//		}
//		printf("\n");
//		tetri_list = tetri_list->prev;
//	} while (tetri_list->prev);
//	board_size = tet_list_size(tetri_list);
	
	fillit(tetri_list);
	// while no solution
	//	matrix = dancing_links_set_up(tetri_list, board_size)
	// 	if fillit(matrix);
	// 		solution = found;
	//	else
	//		++board_size
	int i;

	i = 0;
	/*
	while (tetri_list)
	{
		int x = 0;
		while (x < 4)
		{
			printf("x = %d, %c\n", tetri_list->x[x], tetri_list->name);
			printf("y = %d, %c\n", tetri_list->y[x], tetri_list->name);
			++x;
		}
		printf("\n");
		tetri_list = tetri_list->next;
		++i;
	}
	*/
//	printf("%d\n", i);
	return (0);
}
