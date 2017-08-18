/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweeks <nweeks@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 09:55:26 by nweeks            #+#    #+#             */
/*   Updated: 2017/08/18 10:18:34 by nweeks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#define BUFF_SIZE 500000

t_map	*get_first_line(int fd)
{
	t_map	*first_line;
	char	junk;

	first_line = malloc(sizeof(t_map));
	first_line->vide = ft_read_int(fd, &first_line->hauteur);
	read(fd, &first_line->obstacle, 1);
	read(fd, &first_line->plein, 1);
	read(fd, &junk, 1);
	return (first_line);
}

int		ft_get_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		
}
