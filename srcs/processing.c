/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweeks <nweeks@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 11:51:10 by nweeks            #+#    #+#             */
/*   Updated: 2017/08/18 12:00:29 by nweeks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int		ft_max(int a, int b, int c)
{
	int	max;

	max = (b > a) ? b : a;
	return ((max > c) ? max : c);
}

void	ft_find_bsq(char **grid, t_map *map_info)
{
	t_point	cur;
	t_point	max;
	int		**memory;

	if (!)
}
