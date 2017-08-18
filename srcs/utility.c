/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweeks <nweeks@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 09:55:26 by nweeks            #+#    #+#             */
/*   Updated: 2017/08/18 11:38:11 by nweeks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#define BUFF_SIZE 500000
#define ERR_MSG "A COMPLETER"

t_map	*get_first_line(int fd)
{
	t_map	*first_line;
	char	junk;

	first_line = malloc(sizeof(t_map));
	first_line->valid_map = 0;
	first_line->vide = ft_read_int(fd, &first_line->height);
	if (first_line->vide == '\n')
		return (first_line);
	if((read(fd, &first_line->obstacle, 1)) == 0 ||
			first_line->obstacle == '\n')
		return (first_line);
	if((read(fd, &first_line->plein, 1)) == 0 || first_line->plein == '\n')
		return (first_line);
	read(fd, &junk, 1);
	if (junk == '\n')
		first_line->valid_map = 1;
	return (first_line);
}

char	**ft_parse(int fd, t_map *map_info)
{
	char	**grid;
	int		cur_line;

	map_info->width = 0;
	cur_line = 0;
	if (!(grid = malloc(map_info->height * sizeof(char *))))
		return (NULL);
	if(!(grid[0] = malloc(BUFF_SIZE * sizeof(char))))
			return (NULL);
	while ((read(fd, &grid[0][map_info->width], 1)) &&
			grid[0][map_info->width] != '\n' &&
			ft_is_valid(map_info, grid[0][map_info->width]))
		map_info->width++;
//	free(&grid[0][map_info->width + 1]);
	grid[0][map_info->width] = 0;
	while (++cur_line < map_info->height)
	{
		if (!(grid[cur_line] = ft_get_line(fd, map_info)))
			return (NULL);
	}
	return (grid);
}

int		ft_get_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_putstr(ERR_MSG, 2);
	return (fd);
}

int		ft_is_valid(t_map *map_info, char c)
{
	return (c == map_info->vide || c == map_info->plein || map_info->obstacle);
}

char	*ft_get_line(int fd, t_map *map_info)
{
	char	*ret;
	int		cursor;
	char	junk;

	if (!(ret = malloc((map_info->width + 1 * sizeof(char)))))
		return (NULL);
	cursor = 0;
	while (cursor < map_info->width && (read(fd, &ret[cursor], 1)) &&
			ft_is_valid(map_info, ret[cursor]))
		cursor++;
	if (cursor != map_info->width)
	{
		free(ret);
		return (NULL);
	}
	read(fd, &junk, 1);
	if (junk != '\n')
	{
		free(ret);
		return (NULL);
	}
	ret[map_info->width] = 0;
	return (ret);
}
