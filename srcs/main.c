/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweeks <nweeks@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 09:51:08 by nweeks            #+#    #+#             */
/*   Updated: 2017/08/23 11:35:52 by nweeks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

void	ft_start_bsq(int fd)
{
	int		**matrix;
	t_map	*map;
	t_point	max;

	if (fd == -1)
		return ;
	map = get_first_line(fd);
	if (!map || map->valid_map == 0)
	{
		ft_putstr("map error\n", 2);
		return ;
	}
	matrix = ft_parse(fd, map);
	if (!matrix)
	{
		ft_putstr("map error\n", 2);
		return ;
	}
	max = ft_find_bsq(matrix, map->height, map->width);
	ft_print(matrix, max, map);
	ft_destroy(matrix, map->height);
	free(map);
}

int		main(int argc, char **argv)
{
	int		cur_file;
	int		fd;

	cur_file = 0;
	if (argc == 1)
		ft_start_bsq(0);
	while (++cur_file < argc)
	{
		if (cur_file != 1)
			ft_putstr("\n", 1);
		fd = open(argv[cur_file], O_RDONLY, S_IREAD);
		if (fd == -1)
		{
			ft_putstr("map error\n", 2);
			continue ;
		}
		ft_start_bsq(fd);
		close(fd);
	}
}
