# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/18 10:00:59 by elebouch          #+#    #+#              #
#    Updated: 2017/08/23 17:08:17 by elebouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror -O3
EXEC = bsq

SRCS = main.c		\
	   utility.c	\
	   libft.c		\
	   processing.c \
	   parse.c      \
	   display.c

SRC = $(addprefix srcs/, $(SRCS))
OBJ = $(SRC:.c=.o)

all:  $(EXEC)

$(EXEC): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(EXEC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(EXEC)

re: fclean  all

.PHONY: all clean fclean re
