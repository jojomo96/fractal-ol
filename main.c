#include "main.h"

static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int	get_color(int iter, double zoom_level)
{
	double	t;

	int r, g, b, a;
	if (iter == calculate_max_iter(zoom_level))
		return (0x000000FF);
	t = (double)iter / (double)calculate_max_iter(zoom_level);
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	a = 255;
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

void	put_image(t_data data)
{
	t_point		p;
	double		scale;
	t_complex	c;
	int			color;

	scale = data.zoom / WIN_WIDTH;
	p.x = 0;
	p.y = 0;
	while (p.y < WIN_HEIGHT)
	{
		p.x = 0;
		while (p.x < WIN_WIDTH)
		{
			c = init_complex((p.x + data.x_offset - WIN_WIDTH / 2.0) * scale
					+ data.center.re, (p.y + data.y_offset - WIN_HEIGHT / 2.0)
					* scale + data.center.im);
			color = get_color(mandelbrot(c, data.zoom), data.zoom);
			mlx_put_pixel(data.img, p.x, p.y, color);
			p.x++;
		}
		p.y++;
	}
	printf("zoom: %f\n", data.zoom);
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
	mlx_scroll_hook(data.mlx, &scroll_event, &data);
	mlx_loop_hook(data.mlx, &key_press, &data);
	mlx_cursor_hook(data.mlx, &mouse_move_event, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
