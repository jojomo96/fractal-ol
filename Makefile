NAME = fractol
CC = cc
# Include the header file location of libftprintf
CFLAGS = -Wall -Wextra -Werror -I$(REPO_DIR)/include/MLX42 -Ofast -I../libftprintf/include
# Initial SRC list
SRC = main.c colors.c events/key_events.c events/mouse_events.c events/scroll_events.c complex.c fractals/burning_ship.c fractals/julia.c fractals/mandelbrot.c utils.c
OBJDIR = obj
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)
REPO_DIR = MLX42
REPO_URL = https://github.com/codam-coding-college/MLX42.git
LIBFT_DIR = libftprintf
LIBS =

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
    LIBS += -L$(REPO_DIR)/lib -lmlx42 -lm -ldl -lX11 -lXext -lbsd
endif
ifeq ($(UNAME_S),Darwin)
    LIBS += -L$(REPO_DIR)/lib -framework Cocoa -framework OpenGL -framework IOKit MLX42/build/libmlx42.a -Iinclude -lglfw
endif

# Link with libftprintf.a
LIBS += -L $(LIBFT_DIR) -lftprintf

BONUS =

ifeq ($(BONUS),yes)
    SRC += window_bonus.c
else
    SRC += window.c
endif

OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

all: libftprintf $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): clone_repo build_lib $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

libftprintf:
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -fr $(OBJDIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

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

.PHONY: all clean fclean re bonus clone_repo build_lib libftprintf
