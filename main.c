#include "main.h"

static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
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

void	put_image(t_data data)
{
	int			x;
	int			y;
	double		scale;
	t_complex	c;
	t_complex	center;
	int			color;

	center = init_complex(-0.75, 0);
	scale = data.zoom / WIN_WIDTH;
	x = 0;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			c = init_complex((x + data.x_offset - WIN_WIDTH / 2.0) * scale
					+ center.re, (y + data.y_offset - WIN_HEIGHT / 2.0) * scale
					+ center.im);
			color = get_color(mandelbrot(c, data.zoom));
			mlx_put_pixel(data.img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_image_to_window(data.mlx, data.img, 0, 0);
}

int	main(void)
{
	t_data	data;

	init_window_data(&data);
	if (!data.mlx)
		return (1);
	if (!data.img)
	{
		ft_error();
	}
	put_image(data);
	mlx_loop_hook(data.mlx, &key_press, &data);
	mlx_loop(data.mlx);
	// mlx_terminate(data.mlx);
	return (0);
}
