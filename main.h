#ifndef MAIN_H
# define MAIN_H

# include "complex.h"
# include <MLX42.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# define ESC_KEY_MAC 256
# define ESC_KEY_LINUX 65307

# define UP_KEY_MAC 265
# define UP_KEY_LINUX 65362
# define DOWN_KEY_MAC 264
# define DOWN_KEY_LINUX 65364
# define LEFT_KEY_MAC 263
# define LEFT_KEY_LINUX 65361
# define RIGHT_KEY_MAC 262
# define RIGHT_KEY_LINUX 65363
# define PLUS_KEY 334
# define MINUS_KEY 333

# define WIN_WIDTH 1200
# define WIN_HEIGHT 1000

# define OFFSET_PER_CLICK 10
# define ZOOM_PER_CLICK 1.1

# define MAX_ITER 5000

typedef int			(*fractal_func)(t_complex, double);
typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_complex		center;
	double			mouse_x;
	double			mouse_y;
	double			x_offset;
	double			y_offset;
	double			zoom;
	double			scale;
	fractal_func	fractal;
}					t_data;

typedef struct s_point
{
	uint32_t				x;
	uint32_t				y;
}					t_point;

void				key_press(void *param);
void				scroll_event(double xdelta, double ydelta, void *param);
void				mouse_move_event(double x, double y, void *param);

int					mandelbrot(t_complex c, double zoom_level);
int					julia(t_complex z, double zoom);
int					burning_ship(t_complex c, double zoom);

t_complex			init_complex(double re, double im);
t_data				*get_data(void);
void				init_window_data(t_data *data);
int				calculate_max_iter(double zoom_level);
void				put_image(t_data data);

#endif
