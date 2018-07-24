/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 19:47:46 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/23 17:25:19 by edehmlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HANDLER_H
# define FILE_HANDLER_H

# define BUFF_SIZE 4096

typedef struct	s_variables
{
	int			tetcount;
	int			tet;
	int			line;
	int			k;
	int			hash_count;
	int			connects;
}				t_variables;

char			*file_to_str(const char *file);
int				check_valid_file(char *str);
int				chk_lines_per(char *str);

#endif
