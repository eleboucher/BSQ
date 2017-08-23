/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweeks <nweeks@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 09:55:26 by nweeks            #+#    #+#             */
/*   Updated: 2017/08/23 21:15:03 by nweeks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#define BUFF_SIZE 500000

t_map	*get_map_info(int fd)
{
	t_map	*first_line;
	char	*str;
	int		i;

	if (!(str = get_first_line(fd)))
		return (NULL);
	if (!(first_line = malloc(sizeof(t_map))))
		return (NULL);
	first_line->valid_map = 1;
	first_line->width = 0;
	first_line->height = 0;
	while (str[first_line->width] != '\n')
		first_line->width++;
	if (first_line->width < 4)
		return (NULL);
	first_line->plein = str[first_line->width - 1];
	first_line->obstacle = str[first_line->width - 2];
	first_line->vide = str[first_line->width - 3];
	i = -1;
	while (++i < first_line->width - 3 && str[i] >= '0' && str[i] <= '9')
		first_line->height = first_line->height * 10 + str[i] - 48;
	if (i != first_line->width - 3)
		first_line->valid_map = 0;
	free(str);
	return (first_line);
}

char	*get_first_line(int fd)
{
	int		buffer;
	char	*str;
	int		i;

	i = -1;
	buffer = BUFF_SIZE;
	if (!(str = malloc(sizeof(char) * buffer)))
		return (NULL);
	while (read(fd, &str[++i], 1) && str[i] != '\n')
		if (i == buffer - 1)
			if (!(str = ft_str_realloc(str, &buffer)))
				return (NULL);
	return (str);
}

int		ft_get_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_putstr("map error\n", 2);
	return (fd);
}

char	*ft_str_realloc(char *to_free, int *buffer)
{
	char	*str;
	int		i;

	i = -1;
	if (!(str = malloc(sizeof(char) * *buffer * 2)))
		return (NULL);
	while (++i < *buffer)
		str[i] = to_free[i];
	free(to_free);
	*buffer *= 2;
	return (str);
}
