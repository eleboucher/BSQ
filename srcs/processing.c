/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweeks <nweeks@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 11:51:10 by nweeks            #+#    #+#             */
/*   Updated: 2017/08/23 23:23:47 by nweeks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int		ft_min(int a, int b, int c)
{
	int	min;

	min = (a < b) ? a : b;
	return ((min < c) ? min : c);
}

t_point	ft_find_bsq(int **matrix, int height, int lenght)
{
	t_point	cur;
	t_point	max;

	max.y = 0;
	max.x = 0;
	cur.y = 0;
	while (++cur.y < height)
	{
		cur.x = 0;
		while (++cur.x < lenght)
		{
			matrix[cur.y][cur.x] = ft_calculate(matrix, cur);
			if (matrix[cur.y][cur.x] > matrix[max.y][max.x])
				max = cur;
		}
	}
	return (max);
}

int		ft_calculate(int **matrix, t_point point)
{
	if (matrix[point.y][point.x] == 0)
		return (matrix[point.y][point.x]);
	return (1 + ft_min(matrix[point.y - 1][point.x - 1],
				matrix[point.y - 1][point.x],
				matrix[point.y][point.x - 1]));
}
