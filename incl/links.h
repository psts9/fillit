/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 20:19:37 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/18 16:14:44 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKS_H
# define LINKS_H

# define TETRIMINO_SIZE 4
# define TETRIMINO_BOARD 20

typedef	struct		s_links
{
	struct s_links	*left;
	struct s_links	*right;
	struct s_links	*up;
	struct s_links	*down;
	struct s_links	*column;
	char			name;
}					t_links;

typedef struct		s_tetri
{
	int				x[TETRIMINO_SIZE];
	int				y[TETRIMINO_SIZE];
	char			name;
	struct s_tetri	*next;
}					t_tetri;

t_tetri	*create_tetrimino_list(const char *str);

#endif
