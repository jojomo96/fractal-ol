#include "main.h"

void	init_window_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Fract'ol");
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->x_offset = 0;
	data->y_offset = 0;
	data->zoom = 2.0;
  data->scale = data->zoom / WIN_WIDTH;
}
