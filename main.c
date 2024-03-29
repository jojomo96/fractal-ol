#include "main.h"

void	draw_pixel(void *mlx_ptr, void *win_ptr, int x, int y, int color)
{
	mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
}

int	color_scheme(int iter, int max_iter)
{
	int	color;

	color = 255 - (255 * iter / max_iter);
	return ((color << 16) | (color << 8) | color); // Grayscale
}

int	get_color(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
	{
		return (0x000000); // Black for points inside the Mandelbrot set
	}
	else
	{
		// Generate a trippy color palette
		t = (double)iter / (double)max_iter;
		r = (int)(9 * (1 - t) * t * t * t * 255);
		g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		return ((r << 16) | (g << 8) | b);
	}
}

int	main(void)
{
	t_data		data;
	int			window_width;
	int			window_height;
	double		scale;
	t_complex	center;
	int			max_iter;
	int			x;
	int			y;
	double		re;
	double		im;
	t_complex	c;
	int			iter;

	window_width = 800;
	window_height = 600;
	scale = 4.0 / window_width;
	center = init_complex(-0.75, 0);
	max_iter = 50;
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);
	data.win = mlx_new_window(data.mlx, window_width, window_height,
			"MiniLibX Window");
	if (data.win == NULL)
	{
		free(data.mlx);
		return (1);
	}
	x = 0;
	y = 0;
	while (y < window_height)
	{
		x = 0;
		while (x < window_width)
		{
			re = (x - window_width / 2.0) * scale + center.re;
			im = (y - window_height / 2.0) * scale + center.im;
			c = init_complex(re, im);
			iter = mandelbrot(c, max_iter);
			draw_pixel(data.mlx, data.win, x, y, get_color(iter, max_iter));
			x++;
		}
		y++;
	}
	mlx_key_hook(data.win, key_press, &data);
	mlx_loop(data.mlx);
	return (0);
}
