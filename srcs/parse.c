/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweeks <nweeks@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 14:13:14 by nweeks            #+#    #+#             */
/*   Updated: 2017/08/23 23:23:37 by nweeks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

int		*ft_get_line_one(int fd, t_map *info)
{
	char	c;
	int		buffer;
	int		*arr;

	info->width = 0;
	buffer = BUFFSIZE;
	if (!(arr = malloc(buffer * sizeof(int))))
		return (NULL);
	while (read(fd, &c, 1) && c != '\n')
	{
		if (info->width == buffer - 1)
			if (!(arr = ft_realloc(arr, &buffer)))
				return (NULL);
		if (c == info->vide)
			arr[info->width++] = 1;
		else if (c == info->obstacle)
			arr[info->width++] = 0;
		else
		{
			free(arr);
			return (NULL);
		}
	}
	return (c == '\n' ? arr : NULL);
}

int		*ft_realloc(int *to_free, int *buffer)
{
	int	*new;
	int	cur;

	if (!(new = malloc(2 * *buffer * sizeof(int))))
		return (NULL);
	cur = -1;
	while (++cur < *buffer)
		new[cur] = to_free[cur];
	free(to_free);
	*buffer = *buffer * 2;
	return (new);
}

int		**ft_parse(int fd, t_map *info)
{
	int		cur_line;
	int		**matrice;
	char	*str;

	if (!(matrice = malloc(info->height * sizeof(int *))))
		return (NULL);
	if (!(matrice[0] = ft_get_line_one(fd, info)) || info->width == 0)
	{
		free(matrice);
		return (NULL);
	}
	cur_line = 0;
	if (!(str = malloc((info->width + 1) * sizeof(int))))
		return (NULL);
	while (++cur_line < info->height)
		if (read(fd, str, info->width + 1) != info->width + 1
				|| !(matrice[cur_line] = ft_fill_matrix(str, info))
				|| str[info->width] != '\n')
		{
			ft_destroy(matrice, cur_line);
			return (NULL);
		}
	free(str);
	return (matrice);
}

int		*ft_fill_matrix(char *str, t_map *info)
{
	int	cur;
	int	*arr;

	if (!(arr = malloc(sizeof(int) * info->width)))
		return (NULL);
	cur = -1;
	while (++cur < info->width)
	{
		if (*str == info->vide)
			arr[cur] = 1;
		else if (*str == info->obstacle)
			arr[cur] = 0;
		else
		{
			free(arr);
			return (NULL);
		}
		++str;
	}
	return (arr);
}

void	ft_destroy(int **matrice, int lines)
{
	int	cur_line;

	cur_line = -1;
	while (++cur_line < lines)
	{
		free(matrice[cur_line]);
	}
	free(matrice);
}
