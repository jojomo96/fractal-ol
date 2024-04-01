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

int	get_color(int iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == MAX_ITER)
	{
		return (0x000000); // Black for points inside the Mandelbrot set
	}
	else
	{
		// Generate a trippy color palette
		t = (double)iter / (double)MAX_ITER;
		r = (int)(9 * (1 - t) * t * t * t * 255);
		g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		return ((r << 16) | (g << 8) | b);
	}
}

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Fract'ol");
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

void	put_image(t_data data, int x_offset, int y_offset, double zoom)
{
	int		x;
	int		y;
	double		scale;
  t_complex	c;
  t_complex	center;

	center = init_complex(-0.75, 0);

	scale = zoom / WIN_WIDTH;
	x = 0;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			c = init_complex((x + x_offset - WIN_WIDTH / 2.0) * scale + center.re, (y + y_offset - WIN_HEIGHT / 2.0) * scale + center.im);
      int color = get_color(mandelbrot(c));
			*(int *)(data.addr + (y * data.line_length + x * (data.bits_per_pixel / 8))) = color;
			x++;
		}
		y++;
	}
}

int	main(void)
{
	t_data		data;

	init_data(&data);
	if (data.mlx == NULL)
		return (1);
	if (data.win == NULL)
	{
		free(data.mlx);
		return (1);
	}
  
  put_image(data, 200, 500, 2.0);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_key_hook(data.win, key_press, &data);
	mlx_loop(data.mlx);
	return (0);
}
