NAME = minilibx_test
CC = cc
SRC = main.c events/key_events.c events/mouse_events.c events/scroll_events.c complex.c fractals/burning_ship.c fractals/julia.c fractals/mandelbrot.c utils.c window.c
OBJDIR = obj
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)
REPO_DIR = MLX42
REPO_URL = https://github.com/codam-coding-college/MLX42.git

# Detect operating system
UNAME_S := $(shell uname -s)

CFLAGS = -Wall -Wextra -Werror -I$(REPO_DIR)/include/MLX42 -Ofast -Wshadow -Wconversion

ifeq ($(UNAME_S),Linux)
    LIBS = -L$(REPO_DIR)/lib -lmlx42 -lm -ldl -lX11 -lXext -lbsd
endif
ifeq ($(UNAME_S),Darwin) # macOS is Darwin
    LIBS = -L$(REPO_DIR)/lib -framework Cocoa -framework OpenGL -framework IOKit MLX42/build/libmlx42.a -Iinclude -lglfw
endif

all: $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): clone_repo build_lib $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

clean:
	rm -fr $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

clone_repo:
	@if [ ! -d "$(REPO_DIR)" ]; then \
		git clone $(REPO_URL); \
	fi

build_lib:
	@if [ ! -d "$(REPO_DIR)/build" ]; then \
		mkdir -p $(REPO_DIR)/build; \
	fi
	cd $(REPO_DIR)/build && cmake .. && make

.PHONY: all clean fclean re clone_repo build_lib
