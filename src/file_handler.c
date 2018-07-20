/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 19:44:09 by pthorell          #+#    #+#             */
/*   Updated: 2018/07/17 20:17:37 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>

#include "file_handler.h"
#include "libft.h"

char	*file_to_str(const char *file)
{
	int		rd;
	int		fd;
	char	buf[BUFF_SIZE];
	char	*result;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	result = ft_strnew(0);
	while ((rd = read(fd, buf, BUFF_SIZE)))
	{
		buf[rd] = '\0';
		free_strjoin(&result, buf);
	}
	return (result);
}
