/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweeks <nweeks@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 10:10:56 by nweeks            #+#    #+#             */
/*   Updated: 2017/08/22 13:08:43 by nweeks           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	ft_read_int(int fd, int *number)
{
	char	c;

	while ((read(fd, &c, 1)) && c >= '0' && c <= '9')
		*number = *number * 10 + c - 48;
	return (c);
}

void	ft_putstr(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}
