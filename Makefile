NAME = minilibx_test
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lmlx -L/usr/local/lib -I/usr/local/include -lXext -lX11 -lm -lbsd
SRC = main.c events.c complex.c fractals/mandelbrot.c utils.c window.c
OBJDIR = obj
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

clean:
	rm -fr $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

