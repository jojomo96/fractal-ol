NAME = minilibx_test
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lmlx -L/usr/local/lib -I/usr/local/include -lXext -lX11 -lm -lbsd
SRC = main.c events.c complex.c mandelbrot.c utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

phony: all clean fclean re
