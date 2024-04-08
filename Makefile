NAME = fractol
CC = cc
REPO_DIR = MLX42
REPO_URL = https://github.com/codam-coding-college/MLX42.git
LIBFT_PRINTF_DIR = libftprintf
LIBFT_DIR = libft
OBJDIR = obj


# Compiler and linker flags
CFLAGS = -Wall -Wextra -Werror -I$(REPO_DIR)/include/MLX42 -Ofast -I$(LIBFT_DIR) -I$(LIBFT_PRINTF_DIR)
LDFLAGS =
LIBS =

# Source and object files
SRC = main.c \
	colors/colors_rgb.c \
	overlay/overlay.c \
	events/key_events.c \
	events/key_color_events.c \
	events/mouse_events.c\
	events/scroll_events.c \
	utils/complex.c \
	utils/flags.c \
	utils/utils.c \
	fractals/burning_ship.c \
	fractals/julia.c \
	fractals/mandelbrot.c \
	utils/config.c

HEADERS = main.h \
	utils/flags.h \
	utils/complex.h \
	utils/config.h

OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

# Platform-specific settings
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    LIBS += -L$(REPO_DIR)/lib -lmlx42 -lm -ldl -lX11 -lXext -lbsd
endif
ifeq ($(UNAME_S),Darwin)
    LIBS += -L$(REPO_DIR)/lib -framework Cocoa -framework OpenGL -framework IOKit MLX42/build/libmlx42.a -lglfw
endif

# Link with libftprintf.a
LIBS +=  -L$(LIBFT_DIR) -lft -L$(LIBFT_PRINTF_DIR) -lftprintf

# Bonus files handling
BONUS =
ifeq ($(BONUS),yes)
    SRC += window_bonus.c
else
    SRC += window.c
endif

# Targets
all: $(NAME)


$(NAME): libft libftprintf clone_repo build_lib $(OBJ)
	$(CC) $(OBJ) -o $@ $(LIBS) $(LDFLAGS)

$(OBJDIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	$(MAKE) -C $(LIBFT_DIR)

libftprintf:
	$(MAKE) -C $(LIBFT_PRINTF_DIR)

clean:
	rm -fr $(OBJDIR)
	$(MAKE) -C $(LIBFT_PRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PRINTF_DIR) fclean
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

debug: CFLAGS += -g -DDEBUG
debug: re

.PHONY: all clean fclean re bonus clone_repo build_lib libft libftprintf debug
