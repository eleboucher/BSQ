/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweeks <nweeks@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 16:53:34 by nweeks            #+#    #+#             */
/*   Updated: 2017/08/23 23:40:43 by nweeks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

void	ft_print(int **matrix, t_point max, t_map *info)
{
	int		line;
	char	*buffer;
	int		i;

	if (!(buffer = malloc(sizeof(char) * (info->width + 1))))
		return ;
	line = -1;
	while (++line < info->height)
	{
		i = -1;
		while (++i < info->width)
		{
			if (line > max.y - matrix[max.y][max.x] && line <= max.y &&
					i > max.x - matrix[max.y][max.x] && i <= max.x)
				buffer[i] = info->plein;
			else if (matrix[line][i] == 0)
				buffer[i] = info->obstacle;
			else
				buffer[i] = info->vide;
		}
		buffer[i] = '\n';
		write(1, buffer, info->width + 1);
	}
	free(buffer);
}
