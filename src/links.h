/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:09:58 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/19 23:35:12 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKS_H
# define LINKS_H

# define TETRIMINO_SIZE 4
# define TETRIMINO_BOARD 20

//typedef struct		s_links
//{
//	struct s_links	*left;
//	struct s_links	*right;
//	struct s_links	*up;
//	struct s_links	*down;
//	struct s_links	*column;
//	char			*name;
//	int				n;
//}					t_links;

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

#endif
