#include "main.h"

void	handle_ESC_key(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void	move_window(t_data *data, int x_offset, int y_offset)
{
	data->x_offset += x_offset;
	data->y_offset += y_offset;
	put_image(*data);
}

void	adjust_zoom(t_data *data, double zoom_factor, double mouse_x,
		double mouse_y)
{
	double	new_zoom;
	double	new_scale;
	double	mouse_pos_x;
	double	mouse_pos_y;

	printf("x_offset: %f\n", data->x_offset);
	printf("y_offset: %f\n", data->y_offset);
	// Calculate the new zoom level and scale.
	new_zoom = data->zoom * zoom_factor;
	new_scale = new_zoom / WIN_WIDTH;
	// Convert mouse coordinates to the coordinate system of your content,
	// taking into account current offsets and scale.
	mouse_pos_x = (mouse_x - WIN_WIDTH / 2.0 + data->x_offset) * data->scale;
	mouse_pos_y = (mouse_y - WIN_HEIGHT / 2.0 + data->y_offset) * data->scale;

  printf("mouse_pos_x: %f\n", mouse_pos_x);
  printf("mouse_pos_y: %f\n", mouse_pos_y);
	// Adjust offsets to ensure the mouse position remains stationary.
	data->x_offset = mouse_pos_x - (mouse_x - WIN_WIDTH / 2.0) * new_scale;
	data->y_offset = mouse_pos_y - (mouse_y - WIN_HEIGHT / 2.0) * new_scale;
		printf("x_offset: %f\n", data->x_offset);
	printf("y_offset: %f\n", data->y_offset);
	// Update the zoom and scale.
	data->zoom = new_zoom;
	data->scale = new_scale;
	// Render the image with updated parameters.
	put_image(*data);
}

int	key_press(int keycode, t_data *data)
{
	// printf("keycode: %d\n", keycode);
	if (keycode == ESC_KEY_MAC || keycode == ESC_KEY_LINUX)
		handle_ESC_key(data);
	else if (keycode == UP_KEY_MAC || keycode == UP_KEY_LINUX)
		move_window(data, 0, -OFFSET_PER_CLICK);
	else if (keycode == DOWN_KEY_MAC || keycode == DOWN_KEY_LINUX)
		move_window(data, 0, OFFSET_PER_CLICK);
	else if (keycode == LEFT_KEY_MAC || keycode == LEFT_KEY_LINUX)
		move_window(data, -OFFSET_PER_CLICK, 0);
	else if (keycode == RIGHT_KEY_MAC || keycode == RIGHT_KEY_LINUX)
		move_window(data, OFFSET_PER_CLICK, 0);
	else if (keycode == PLUS_KEY)
		adjust_zoom(data, ZOOM_PER_CLICK, WIN_WIDTH / 2.0, WIN_HEIGHT / 2.0);
	else if (keycode == MINUS_KEY)
		adjust_zoom(data, 1 / ZOOM_PER_CLICK, WIN_WIDTH / 2.0, WIN_HEIGHT
			/ 2.0);
	return (0);
}
