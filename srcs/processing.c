/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweeks <nweeks@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 11:51:10 by nweeks            #+#    #+#             */
/*   Updated: 2017/08/21 16:27:38 by nweeks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#define MOD(x) ((x) % 2)

int		ft_min(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

void	ft_print(char **grid, t_map *info, t_point max, int size)
{
	t_point	cur;

	cur.y = -1;
	while (++cur.y < info->height)
	{
		cur.x = -1;
		while (++cur.x < info->width)
		{
			if (cur.y <= max.y && cur.y > max.y - size
					&& cur.x <= max.x && cur.x > max.x - size)
				write(1, &info->plein, 1);
			else
			{
				if (cur.y > max.y || cur.y < max.y - size)
				{
					write(1, grid[cur.y], info->width);
					cur.x = info->width;
				}
				else
					write(1, &grid[cur.y][cur.x], 1);
			}
		}
		write(1, "\n", 1);
	}
}
