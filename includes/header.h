/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweeks <nweeks@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 09:54:57 by nweeks            #+#    #+#             */
/*   Updated: 2017/08/21 16:24:12 by nweeks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUFFSIZE 128
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

char			ft_read_int(int fd, int *number);
void			ft_putstr(char *str, int fd);
t_map			*get_first_line(int fd);
int				ft_get_fd(char *file);
int				ft_is_valid(t_map *map_info, char c);
int				**ft_parse(int fd, t_map *info);
int				*ft_fill_matrix(char *str, t_map *info);
void			ft_destroy(int **matrice, int lines);
int				*ft_realloc(int *to_free, int *buffer);
int				*ft_get_line_one(int fd, t_map *info);
#endif
