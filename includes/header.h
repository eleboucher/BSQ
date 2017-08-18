/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweeks <nweeks@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 09:54:57 by nweeks            #+#    #+#             */
/*   Updated: 2017/08/18 13:25:06 by nweeks           ###   ########.fr       */
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
	int			height;
	int			width;
}				t_map;

typedef struct	s_point
{
	int			y;
	int			x;
}				t_point;

char	ft_read_int(int fd, int *number);
void	ft_putstr(char *str, int fd);
t_map	*get_first_line(int fd);
int		ft_get_fd(char *file);
int		ft_is_valid(t_map *map_info, char c);
void	ft_destroy(char **to_free, int lines);
char	*ft_get_line(int fd, t_map *map_info);
char	**ft_parse(int fd, t_map *map_info);
char	*ft_strdup(char *str, int len);
void	ft_memset(char **grid, int *line, t_map *map);
void	ft_print(char **grid, t_map *info, t_point max, int size);
void	ft_find_bsq(char **grid, t_map *map_info);
#endif
