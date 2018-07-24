/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 19:19:38 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/23 20:23:45 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "file_handler.h"
#include "links.h"

int		main(int argc, char **argv)
{
	char	*str;
	t_tetri	*tetri_list;

	if (argc != 2)
	{
		ft_putendl("usage: fillit source_file");
		return (-1);
	}
	str = file_to_str(argv[1]);
	if (!check_valid_file(str))
	{
		ft_putendl("error");
		return (-1);
	}
	tetri_list = create_tetrimino_list(str);
	fillit(tetri_list);
	return (0);
}
