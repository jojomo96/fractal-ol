#include "../main.h"

void	handle_ESC_key(t_data *data)
{
	mlx_terminate(data->mlx);
	exit(0);
}

void	move_window(t_data *data, int x_offset, int y_offset)
{
	data->x_offset += x_offset;
	data->y_offset += y_offset;
	put_image(*data);
}

void	key_press(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		handle_ESC_key(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		move_window(data, 0, -OFFSET_PER_CLICK);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		move_window(data, 0, OFFSET_PER_CLICK);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		move_window(data, -OFFSET_PER_CLICK, 0);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		move_window(data, OFFSET_PER_CLICK, 0);
}
