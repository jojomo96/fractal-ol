#include "main.h"

void	init_window_data(t_data *data)
{
	data->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Fract'ol", true);
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->x_offset = 0;
	data->y_offset = 0;
	data->zoom = 2.0;
	data->scale = data->zoom / WIN_WIDTH;
	data->center = init_complex(-0.75, 0);
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
	printf("inter: %f\n", calculate_max_iter(data.zoom));
	mlx_image_to_window(data.mlx, data.img, 0, 0);
}
