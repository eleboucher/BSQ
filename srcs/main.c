/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweeks <nweeks@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 09:51:08 by nweeks            #+#    #+#             */
/*   Updated: 2017/08/18 10:35:39 by nweeks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

int	main(int argc, char **argv)
{
	int		cur_file;
	int		fd;
	t_map	*map;

	cur_file = 0;
	while (++cur_file < argc)
	{
		fd = ft_get_fd(argv[cur_file]);
		map = get_first_line(fd);
		if (map->valid_map == 0)
		{
			ft_putstr("map error\n", 2);
			continue ;
		}
		printf("%d%c%c%c\n", map->hauteur, map->vide,
				map->obstacle, map->plein);
	}
}
