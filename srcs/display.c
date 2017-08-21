/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweeks <nweeks@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 16:53:34 by nweeks            #+#    #+#             */
/*   Updated: 2017/08/21 17:22:46 by nweeks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

void	ft_fill_buffer(int **matrix, int line, char *str,
		t_map *info, t_point max)
{
	int	i;
	int	maximum;

	i = -1;
	maximum = matrix[max.y][max.x];
	while (++i < info->width)
	{
		if (line > max.y - maximum && line <= max.y &&
				i > max.x - maximum && i <= max.x)
			str[i] = info->plein;
		else if (matrix[line][i] == 0)
			str[i] = info->obstacle;
		else
			str[i] = info->vide;
	}
	str[i] = '\n';
}

void	ft_print(int **matrix, t_point max, t_map *info)
{
	int		cur_line;
	char	*buffer;

	if (!(buffer = malloc(sizeof(char) * (info->width + 1))))
		return ;
	cur_line = -1;
	while (++cur_line < info->height)
	{
		ft_fill_buffer(matrix, cur_line, buffer, info, max);
		write(1, buffer, info->width + 1);
	}
}
