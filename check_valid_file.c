/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edehmlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 18:39:53 by edehmlow          #+#    #+#             */
/*   Updated: 2018/07/23 18:56:51 by edehmlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "file_handler.h"
#include "links.h"

static char	***ft_tetarray(char **lines, int strlen)
{
	char		***tetarray;
	t_variables	a;

	ft_memset(&a, 0, sizeof(t_variables));
	a.tetcount = (strlen - 20) / 21 + 1;
	tetarray = (char ***)ft_memalloc(sizeof(char **) * (a.tetcount + 1));
	if (!tetarray)
		return (NULL);
	while (a.tet < a.tetcount)
	{
		a.k = 0;
		tetarray[a.tet] = (char **)ft_memalloc(sizeof(char *) * (4 + 1));
		if (!tetarray[a.tet])
			return (NULL);
		while (a.k < 4 && lines[a.line] && tetarray[a.tet])
		{
			tetarray[a.tet][a.k] = ft_strdup(lines[a.line]);
			a.line++;
			a.k++;
		}
		a.tet++;
	}
	return (tetarray);
}

static int	connects_chk_k(char ***tetarray, int tet, int line, int k)
{
	int connects;

	connects = 0;
	if (k != 3)
	{
		if (tetarray[tet][line][k + 1] == '#')
			connects++;
		if (k != 0)
		{
			if (tetarray[tet][line][k - 1] == '#')
				connects++;
		}
	}
	else
	{
		if (tetarray[tet][line][k - 1] == '#')
			connects++;
	}
	return (connects);
}

static int	connects_chk(char ***tetarray, int tet, int line, int k)
{
	int connects;

	connects = 0;
	connects += connects_chk_k(tetarray, tet, line, k);
	if (line != 3)
	{
		if (tetarray[tet][line + 1][k] == '#')
			connects += 1;
		if (line != 0)
		{
			if (tetarray[tet][line - 1][k] == '#')
				connects += 1;
		}
	}
	else
	{
		if (tetarray[tet][line - 1][k] == '#')
			connects += 1;
	}
	return (connects);
}

static int	full_chk(char ***tetarray)
{
	t_variables a;

	ft_memset(&a, 0, sizeof(t_variables));
	while (tetarray[a.tet])
	{
		SET_TO_ZERO(a.hash_count, a.connects, a.line);
		while (tetarray[a.tet][a.line])
		{
			a.k = 0;
			while (tetarray[a.tet][a.line][a.k])
			{
				if (tetarray[a.tet][a.line][a.k] == '#')
				{
					a.connects += connects_chk(tetarray, a.tet, a.line, a.k);
					a.hash_count++;
				}
				a.k++;
			}
			a.line++;
		}
		if ((a.connects != 6 && a.connects != 8) || a.hash_count != 4)
			return (0);
		a.tet++;
	}
	return (1);
}

int			check_valid_file(char *str)
{
	int		strlen;
	char	**lines;
	char	***tetarray;
	int		i;

	i = 0;
	if (!str)
		return (0);
	strlen = (int)ft_strlen(str);
	if ((strlen < 21 && strlen != 20) || strlen > 550)
		return (0);
	else if (((strlen - 20) % 21 != 0) || !chk_lines_per(str))
		return (0);
	while (str[i] != '\0')
	{
		if ((str[i] != '.' && str[i] != '#' && str[i] != '\n') ||
				(str[i] == '\n' && str[i + 1] == '\n' && str[i + 2] == '\n'))
			return (0);
		i++;
	}
	lines = ft_strsplit(str, '\n');
	tetarray = ft_tetarray(lines, strlen);
	if (!full_chk(tetarray))
		return (0);
	return (1);
}
