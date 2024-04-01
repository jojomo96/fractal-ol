#include "main.h"

void	handle_ESC_key(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void move_window(t_data *data, int x_offset, int y_offset, double zoom)
{
  data->y_offset+=y_offset;
  data->x_offset+=x_offset;
  data->zoom+=zoom;
  printf("zoom: %f", data->zoom);
  put_image(*data);
}

int	key_press(int keycode, t_data *data)
{
	printf("keycode: %d\n", keycode);
	if (keycode == ESC_KEY_MAC || keycode == ESC_KEY_LINUX)
		handle_ESC_key(data);
	else if (keycode == UP_KEY_MAC || keycode == UP_KEY_LINUX)
    move_window(data, 0, -OFFSET_PER_CLICK, 0.0);
	else if (keycode == DOWN_KEY_MAC || keycode == DOWN_KEY_LINUX)
    move_window(data, 0, OFFSET_PER_CLICK, 0.0);
	else if (keycode == LEFT_KEY_MAC || keycode == LEFT_KEY_LINUX)
    move_window(data, -OFFSET_PER_CLICK, 0, 0.0);
	else if (keycode == RIGHT_KEY_MAC || keycode == RIGHT_KEY_LINUX)
    move_window(data, OFFSET_PER_CLICK, 0, 0.0);
  else if (keycode == PLUS_KEY)
    move_window(data, 0,0, -0.1);
  else if (keycode == MINUS_KEY)
    move_window(data, 0, 0, 0.1);
	return (0);
}
