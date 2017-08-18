# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/18 10:00:59 by elebouch          #+#    #+#              #
#    Updated: 2017/08/18 10:04:51 by elebouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror 
EXEC = bsq

SRCS = srcs/main.c 		\
	   srcs/utility.c	

INCLUDES = includes/header.h

all: $(EXEC)

$(EXEC):
	$(CC) $(FLAGS) $(SRCS) -I $(INCLUDES) -o $(EXEC)

clean:

fclean: clean
	rm -f $(EXEC)
