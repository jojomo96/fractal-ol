NAME = minilibx_test
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lmlx -L/usr/local/lib -I/usr/local/include -lXext -lX11 -lm -lbsd
SRC = main.c events.c complex.c fractals/mandelbrot.c utils.c window.c
OBJDIR = obj
OBJ = $(OBJDIR)/$(SRC:.c=.o)

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

clean:
	rm -fr $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

phony: all clean fclean re
