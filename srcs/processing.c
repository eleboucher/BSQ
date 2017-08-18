/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweeks <nweeks@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 11:51:10 by nweeks            #+#    #+#             */
/*   Updated: 2017/08/18 14:10:52 by nweeks           ###   ########.fr       */
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

void	ft_find_bsq(char **grid, t_map *map_info)
{
	t_point	cur;
	t_point	max;
	int		max_size;
	int		**memory;

	if (!(memory = malloc(sizeof(int *) * 2)))
		return ;
	if (!(memory[0] = malloc((map_info->width) * sizeof(int))))
		return ;
	if (!(memory[1] = malloc(map_info->width * sizeof(int))))
		return ;
	ft_memset(grid, memory[0], map_info);
	cur.y = 0;
	max_size = 0;
	while (++cur.y < map_info->width)
	{
		cur.x = 0;
		memory[cur.y % 2][0] = (grid[cur.y][0] == map_info->vide) ? 1 : 0;
		while (++cur.x < map_info->width)
		{
			if (grid[cur.y][cur.x] == map_info->vide)
				memory[cur.y % 2][cur.x % 2] = 1 +
					ft_min(memory[MOD(cur.y - 1)][MOD(cur.x - 1)],
							memory[MOD(cur.y - 1)][MOD(cur.x)],
							memory[MOD(cur.y)][MOD(cur.x & 2)]);
			else
				memory[cur.y % 2][cur.x % 2] = 0;
			max_size = (max_size > memory[cur.y % 2][cur.x % 2]) ? max_size :
				memory[cur.y % 2][cur.x % 2];
			max = (max_size > memory[cur.y % 2][cur.x % 2]) ? max : cur;
		}
	}
	ft_print(grid, map_info, max, max_size);
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
				write(1, &grid[cur.y][cur.x], 1);
		}
		write(1, "\n", 1);
	}
}
