# Project Name
NAME = fractol

# Compiler
CC = cc

# Repository for MLX42
REPO_DIR = MLX42
REPO_URL = https://github.com/codam-coding-college/MLX42.git

# Directories
LIBFT_PRINTF_DIR = libftprintf
LIBFT_DIR = libft
OBJDIR = obj

# Compiler and Linker Flags
CFLAGS = -Wall -Wextra -Werror -I$(REPO_DIR)/include/MLX42 -Ofast -I$(LIBFT_DIR) -I$(LIBFT_PRINTF_DIR)
LDFLAGS =
LIBS =

# Source Files
SRC = main.c \
      colors/colors_rgb.c \
      overlay/overlay.c \
      events/key_events.c \
      events/key_color_events.c \
      events/mouse_events.c \
      events/scroll_events.c \
      utils/complex.c \
      utils/complex_2.c \
      utils/flags.c \
      utils/utils.c \
      fractals/burning_ship.c \
      fractals/julia.c \
      fractals/mandelbrot.c \
      fractals/newton_fractal.c \
      utils/config.c

# Header Files
HEADERS = main.h \
          utils/flags.h \
          utils/complex.h \
          utils/config.h

# Object Files
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

# Platform-Specific Settings
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    LIBS += -L$(REPO_DIR)/lib -lmlx42 -lm -ldl -lX11 -lXext -lbsd
endif
ifeq ($(UNAME_S),Darwin)
    LIBS += -L$(REPO_DIR)/lib -framework Cocoa -framework OpenGL -framework IOKit MLX42/build/libmlx42.a -lglfw
endif

# Link with libftprintf.a
LIBS += -L$(LIBFT_DIR) -lft -L$(LIBFT_PRINTF_DIR) -lftprintf

# Handling Bonus Files
BONUS =
ifeq ($(BONUS),yes)
    SRC += window_bonus.c
else
    SRC += window.c
endif

# Main Target
all: $(NAME)

# Linking the Executable
$(NAME): libft libftprintf clone_repo build_lib $(OBJ)
	$(CC) $(OBJ) -o $@ $(LIBS) $(LDFLAGS)

# Compiling Object Files
$(OBJDIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Building libft
libft:
	$(MAKE) -C $(LIBFT_DIR)

# Building libftprintf
libftprintf:
	$(MAKE) -C $(LIBFT_PRINTF_DIR)

# Cleaning Up
clean:
	rm -fr $(OBJDIR)
	$(MAKE) -C $(LIBFT_PRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

# Remove Cloned Library
cleanlib:
	rm -rf $(REPO_DIR)

# Full Clean
fclean: clean cleanlib
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild Everything
re: fclean all

# Enable Bonus Features
bonus:
	$(MAKE) BONUS=yes all

# Clone the MLX42 Repository
clone_repo:
	@if [ ! -d "$(REPO_DIR)" ]; then \
		git clone $(REPO_URL); \
	fi

# Build the MLX42 Library
build_lib:
	@if [ ! -d "$(REPO_DIR)/build" ]; then \
		mkdir -p $(REPO_DIR)/build; \
	fi
	cd $(REPO_DIR)/build && cmake .. && make

# Debug Build
debug: CFLAGS += -g -DDEBUG
debug: re

.PHONY: all clean fclean re bonus clone_repo build_lib libft libftprintf debug cleanlib
