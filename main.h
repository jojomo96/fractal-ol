#ifndef MAIN_H
# define MAIN_H

# include "complex.h"
# include <MLX42.h>
# include <pthread.h>
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

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define OFFSET_PER_CLICK 10
# define ZOOM_PER_CLICK 1.1

# define MAX_ITER 5000
# define MIN_ITER 30

typedef u_int32_t	(*fractal_func)(t_complex, int);

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
	int				max_iter;
}					t_data;

typedef struct s_point
{
	uint32_t		x;
	uint32_t		y;
}					t_point;

typedef struct s_thread_data
{
	uint32_t		start_y;
	uint32_t		end_y;
	t_data			data;
}					t_thread_data;

typedef struct s_rgb
{
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
}					t_rgb;

typedef struct s_color_palette
{
	double			frequency;
	double			phase_r;
	double			phase_g;
	double			phase_b;
}					t_color_palette;

void				key_press(void *param);
void				scroll_event(double xdelta, double ydelta, void *param);
void				mouse_move_event(double x, double y, void *param);

u_int32_t			mandelbrot(t_complex c, int max_iter);
u_int32_t			julia(t_complex z, int max_iter);
u_int32_t			burning_ship(t_complex c, int max_iter);

t_complex			init_complex(double re, double im);
void				init_window_data(t_data *data);
int					calculate_max_iter(double zoom_level);
void				put_image(t_data data);
int					encode_rgb_as_int(t_rgb color);
int					get_color(int iter, int max_iter);
void				switch_color_palette(void);

#endif
