#include "main.h"

void	handle_ESC_key(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	key_press(int keycode, t_data *data)
{
  printf("keycode: %d\n", keycode);
	if (keycode == ESC_KEY_MAC || keycode == ESC_KEY_LINUX)
		handle_ESC_key(data);
	else if (keycode == UP_KEY_MAC || keycode == UP_KEY_LINUX)
		printf("UP\n");
	else if (keycode == DOWN_KEY_MAC || keycode == DOWN_KEY_LINUX)
		printf("DOWN\n");
	else if (keycode == LEFT_KEY_MAC || keycode == LEFT_KEY_LINUX)
		printf("LEFT\n");
	else if (keycode == RIGHT_KEY_MAC || keycode == RIGHT_KEY_LINUX)
		printf("RIGHT\n");
	return (0);
}

