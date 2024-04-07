NAME = fractol
CC = cc
# Initial SRC list without window.c to avoid duplication in the conditional assignment below
SRC = main.c colors.c events/key_events.c events/mouse_events.c events/scroll_events.c complex.c fractals/burning_ship.c fractals/julia.c fractals/mandelbrot.c utils.c
OBJDIR = obj
# Placeholder for OBJ, will be defined based on SRC
OBJ =
REPO_DIR = MLX42
REPO_URL = https://github.com/codam-coding-college/MLX42.git

UNAME_S := $(shell uname -s)

CFLAGS = -Wall -Wextra -Werror -I$(REPO_DIR)/include/MLX42 -Ofast

ifeq ($(UNAME_S),Linux)
    LIBS = -L$(REPO_DIR)/lib -lmlx42 -lm -ldl -lX11 -lXext -lbsd
endif
ifeq ($(UNAME_S),Darwin)
    LIBS = -L$(REPO_DIR)/lib -framework Cocoa -framework OpenGL -framework IOKit MLX42/build/libmlx42.a -Iinclude -lglfw
endif

# Conditional assignment for the BONUS variable
BONUS =

# Conditional inclusion of window_bonus.c or window.c based on the BONUS flag
ifeq ($(BONUS),yes)
    SRC += window_bonus.c
else
    SRC += window.c
endif

# Define OBJ based on SRC after SRC has been finalized
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

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

bonus:
	$(MAKE) BONUS=yes all

clone_repo:
	@if [ ! -d "$(REPO_DIR)" ]; then \
		git clone $(REPO_URL); \
	fi

build_lib:
	@if [ ! -d "$(REPO_DIR)/build" ]; then \
		mkdir -p $(REPO_DIR)/build; \
	fi
	cd $(REPO_DIR)/build && cmake .. && make

.PHONY: all clean fclean re bonus clone_repo build_lib
