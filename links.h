/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:09:58 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/22 21:54:06 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKS_H
# define LINKS_H

# define TETRIMINO_SIZE 4
# define TETRIMINO_BOARD 20

# define TRUE_XPOS(l, n) (l->x[n] + l->x_pos)
# define TRUE_YPOS(l, n) (l->y[n] + l->y_pos)
# define SET_TO_ZERO(a, b, c) a = 0; b = 0; c = 0;
# define INCREMENT(a, b) ++a; ++b;

typedef struct		s_tetri
{
	int				x[TETRIMINO_SIZE];
	int				y[TETRIMINO_SIZE];
	int				x_pos;
	int				y_pos;
	int				width;
	int				height;
	char			name;
	struct s_tetri	*next;
	struct s_tetri	*prev;
}					t_tetri;

t_tetri				*create_tetrimino_list(const char *str);
int					tet_list_size(t_tetri *list);
void				fillit(t_tetri *list);
int					min_board_size(int n);
void				print_board(t_tetri *list, int board_size);
void				name_tet_list(t_tetri **list);

#endif
