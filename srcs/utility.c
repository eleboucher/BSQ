/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweeks <nweeks@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 09:55:26 by nweeks            #+#    #+#             */
/*   Updated: 2017/08/21 17:13:43 by nweeks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#define BUFF_SIZE 500000

t_map	*get_first_line(int fd)
{
	t_map	*first_line;
	char	junk;

	first_line = malloc(sizeof(t_map));
	first_line->valid_map = 0;
	first_line->vide = ft_read_int(fd, &first_line->height);
	if (first_line->vide == '\n')
		return (first_line);
	if ((read(fd, &first_line->obstacle, 1)) == 0 ||
			first_line->obstacle == '\n')
		return (first_line);
	if ((read(fd, &first_line->plein, 1)) == 0 || first_line->plein == '\n')
		return (first_line);
	read(fd, &junk, 1);
	if (junk == '\n')
		first_line->valid_map = 1;
	return (first_line);
}

int		ft_get_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	return (fd);
}
