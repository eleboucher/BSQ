CC = gcc
FLAGS = -Wall -Wextra -Werror -Iincludes -O3
EXEC = bsq
SRCS = srcs/main.c \
	   srcs/utility.c \

all: $(EXEC)

$(EXEC):
	$(CC) $(FLAGS) $(SRCS) -o $(EXEC)

clean:

fclean: clean
	rm -f $(EXEC)
