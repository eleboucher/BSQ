/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweeks <nweeks@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 09:54:57 by nweeks            #+#    #+#             */
/*   Updated: 2017/08/18 10:33:58 by nweeks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


typedef struct	s_map
{
	int			valid_map;
	char		vide;
	char		obstacle;
	char		plein;
	int			hauteur;
	int			largeur;
}				t_map;

char	ft_read_int(int fd, int *number);
void	ft_putstr(char *str, int fd);
t_map	*get_first_line(int fd);
int		ft_get_fd(char *file);

#endif
