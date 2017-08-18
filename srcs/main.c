/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweeks <nweeks@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 09:51:08 by nweeks            #+#    #+#             */
/*   Updated: 2017/08/18 11:39:51 by nweeks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

int	main(int argc, char **argv)
{
	int		cur_file;
	int		fd;
	t_map	*map;
	char	**grid;

	cur_file = 0;
	while (++cur_file < argc)
	{
		fd = ft_get_fd(argv[cur_file]);
		if (fd == -1)
			continue ;
		map = get_first_line(fd);
		if (map->valid_map == 0)
		{
			ft_putstr("map error\n", 2);
			continue ;
		}
		grid = ft_parse(fd, map);
		if (!grid)
		{
			ft_putstr("map error\n", 2);
			continue ;
		}
		for(int i = 0; i < map->height; ++i)
			printf("%s\n", grid[i]);
		close(fd);
	}
}
