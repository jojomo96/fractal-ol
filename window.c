#include "main.h"

void	init_window_data(t_data *data)
{
	data->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Fract'ol", false);
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->x_offset = 0;
	data->y_offset = 0;
	data->zoom = 2.0;
	data->scale = data->zoom / WIN_WIDTH;
	data->center = init_complex(-0.75, 0);
}

void	put_image(t_data data)
{
	t_point		p;
	double		scale;
	t_complex	c;

	scale = data.zoom / WIN_WIDTH;
	p.x = 0;
	p.y = 0;
    data.max_iter = calculate_max_iter(data.zoom);
	while (p.y < WIN_HEIGHT)
	{
		p.x = 0;
		while (p.x < WIN_WIDTH)
		{
			c = init_complex((p.x + data.x_offset - WIN_WIDTH / 2.0) * scale
					+ data.center.re, (p.y + data.y_offset - WIN_HEIGHT / 2.0)
					* scale + data.center.im);
			u_int32_t color = data.fractal(c, data.max_iter);
			mlx_put_pixel(data.img, p.x, p.y, color);
			p.x++;
		}
		p.y++;
	}
	printf("inter: %f\n", data.zoom);
	// mlx_image_to_window(data.mlx, data.img, 0, 0);
}
