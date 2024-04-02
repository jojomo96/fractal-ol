#include "main.h"

void	handle_ESC_key(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void	move_window(t_data *data, int x_offset, int y_offset,
		double zoom_factor)
{
	data->x_offset += x_offset;
	data->y_offset += y_offset;
	data->zoom *= zoom_factor;
	put_image(*data);
}

void	move_viewport(t_data *data, int x_offset, int y_offset)
{
	move_window(data, x_offset, y_offset, 1);
}

void	adjust_zoom(t_data *data, double zoom_factor)
{
	move_window(data, 0, 0, zoom_factor);
}

int	key_press(int keycode, t_data *data)
{
	printf("keycode: %d\n", keycode);
	if (keycode == ESC_KEY_MAC || keycode == ESC_KEY_LINUX)
		handle_ESC_key(data);
	else if (keycode == UP_KEY_MAC || keycode == UP_KEY_LINUX)
		move_viewport(data, 0, -OFFSET_PER_CLICK);
	else if (keycode == DOWN_KEY_MAC || keycode == DOWN_KEY_LINUX)
		move_viewport(data, 0, OFFSET_PER_CLICK);
	else if (keycode == LEFT_KEY_MAC || keycode == LEFT_KEY_LINUX)
		move_viewport(data, -OFFSET_PER_CLICK, 0);
	else if (keycode == RIGHT_KEY_MAC || keycode == RIGHT_KEY_LINUX)
		move_viewport(data, OFFSET_PER_CLICK, 0);
	else if (keycode == PLUS_KEY)
		adjust_zoom(data, ZOOM_PER_CLICK);
	else if (keycode == MINUS_KEY)
		adjust_zoom(data, 1 / ZOOM_PER_CLICK);
	return (0);
}
