#ifndef MAIN_H
# define MAIN_H

# include "complex.h"
# include <mlx.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# define ESC_KEY_MAC 53
# define ESC_KEY_LINUX 65307

# define UP_KEY_MAC 126
# define UP_KEY_LINUX 65362
# define DOWN_KEY_MAC 125
# define DOWN_KEY_LINUX 65364
# define LEFT_KEY_MAC 123
# define LEFT_KEY_LINUX 65361
# define RIGHT_KEY_MAC 124
# define RIGHT_KEY_LINUX 65363

typedef struct s_data
{
	void	*mlx;
	void	*win;
}			t_data;

int			key_press(int keycode, t_data *data);

int			mandelbrot(t_complex c, int max_iter);
t_complex	init_complex(double re, double im);
#endif
