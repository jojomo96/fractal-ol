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

// int	get_color(int iter, double zoom_level)
// {
// 	double	t;

// 	int r, g, b, a;
// 	if (iter == calculate_max_iter(zoom_level))
// 		return (0x000000FF);
// 	t = (double)iter / (double)calculate_max_iter(zoom_level);
// 	r = (int)(9 * (1 - t) * t * t * t * 255);
// 	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
// 	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
// 	a = 255;
// 	return ((r << 24) | (g << 16) | (b << 8) | a);
// }



// int get_color_julia(int iter, double zoom_level)
// {
//     if (iter == calculate_max_iter(zoom_level))
//         return (0x000000FF); // Use black for points inside the set

//     // Normalize iteration count to a [0, 1] range
//     double normalized = (double)iter / calculate_max_iter(zoom_level);

//     // Create a cyclic color effect to emphasize fractal details
//     double hue = normalized * 360.0; // Map normalized iteration to hue value

//
	// Convert hue to RGB using a simplified HSV-to-RGB conversion for vibrant colors
//     double rad = hue * M_PI / 180.0;
//     int r = (int)((sin(rad) + 1) * 127.5); // Red peaks at 0 and 360 degrees
//     int g = (int)((sin(rad + 2.0 * M_PI / 3.0) + 1) * 127.5);
	// Green peaks at 120 degrees
//     int b = (int)((sin(rad + 4.0 * M_PI / 3.0) + 1) * 127.5);
	// Blue peaks at 240 degrees
//     int a = 255; // Full opacity for all pixels

//     // Combine components into a single ARGB value
//     return ((a << 24) | (r << 16) | (g << 8) | b);
// }

// int get_color_burning_ship(int iter, double zoom_level)
// {
//     if (iter == calculate_max_iter(zoom_level))
//         return (0x000000FF);
	// Black with full opacity for points inside the set

//     // Apply a transformation to 't' to create more complex color variations
//     double t = (double)iter / (double)calculate_max_iter(zoom_level);
//     t = t - log(t) * sin(0.2 * iter) * cos(0.2 * iter);

//     // Emphasize red hues, using sin functions for smooth transitions
//     int r = (int)((0.5 * sin(2.0 * M_PI * t) + 0.5) * 255);
	// Strong red component
//     int g = (int)((0.5 * sin(2.0 * M_PI * (t + 0.8)) + 0.5) * 64);
	// Subdued green component
//     int b = (int)((0.5 * sin(2.0 * M_PI * (t + 0.8)) + 0.5) * 64);
	// Subdued blue component
//     int a = 255; // Full opacity

//     // Assemble the color in ARGB format (assuming your system uses ARGB)
//     return ((a << 24) | (r << 16) | (g << 8) | b);
// }

void	put_image(t_data data)
{
	t_point		p;
	double		scale;
	t_complex	c;

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
			u_int32_t color = data.fractal(c, data.zoom);
			if(p.x == 459 && p.y == 547)
				printf("color: %d\n", color);
			mlx_put_pixel(data.img, p.x, p.y, color);
			p.x++;
		}
		p.y++;
	}
	printf("inter: %f\n", data.zoom);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
}
