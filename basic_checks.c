/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edehmlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:37:36 by edehmlow          #+#    #+#             */
/*   Updated: 2018/07/23 16:12:49 by edehmlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		chk_lines_per(char *str)
{
	int i;
	int	line_cnt;

	i = 0;
	line_cnt = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			line_cnt++;
		if (str[i] == '\n' && str[i - 1] == '\n')
		{
			if (line_cnt != 5)
				return (0);
			line_cnt = 0;
		}
		i++;
	}
	return (1);
}
