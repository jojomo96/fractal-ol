/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 09:44:57 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/08 12:25:57 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libftprintf/ft_printf.h"
# include "utils/complex.h"
# include "utils/config.h"
# include "utils/flags.h"
# include <MLX42.h>
# include <errno.h>
# include <math.h>
# include <pthread.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define OFFSET_PER_CLICK 10
# define ZOOM_PER_CLICK 1.1

# define MAX_ITER 5000
# define MIN_ITER 40

# define THREAD_COUNT 12

typedef u_int32_t	(*t_fractal_func)(t_complex, int);
typedef int			(*t_get_color_func)(int, int);

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
	t_fractal_func	fractal;
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
void				key_color_hook(mlx_key_data_t keydata, void *param);

u_int32_t			mandelbrot(t_complex c, int max_iter);
u_int32_t			julia(t_complex z, int max_iter);
u_int32_t			burning_ship(t_complex c, int max_iter);

t_complex			init_complex(double re, double im);
void				init_window_data(t_data *data);
int					calculate_max_iter(double zoom_level);
void				put_image(t_data data);
int					encode_rgb_as_int(t_rgb color);
int					get_color_rgb(int iter, int max_iter);
void				switch_color_palette(void);
int					ft_strcmp(const char *s1, const char *s2);

// overlay
void				update_overlay(t_data *data);
void				create_overlay(t_data *data);
void				update_color_palette(void);

#endif
