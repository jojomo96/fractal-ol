#include "main.h"

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

void	key_press(mlx_key_data_t keycode, void *data)
{

	printf("keycode.key: %d\n", keycode.key);
	if (keycode.key == ESC_KEY_MAC || keycode.key == ESC_KEY_LINUX)
		handle_ESC_key(data);
	else if (keycode.key == UP_KEY_MAC || keycode.key == UP_KEY_LINUX)
		move_window(data, 0, -OFFSET_PER_CLICK);
	else if (keycode.key == DOWN_KEY_MAC || keycode.key == DOWN_KEY_LINUX)
		move_window(data, 0, OFFSET_PER_CLICK);
	else if (keycode.key == LEFT_KEY_MAC || keycode.key == LEFT_KEY_LINUX)
		move_window(data, -OFFSET_PER_CLICK, 0);
	else if (keycode.key == RIGHT_KEY_MAC || keycode.key == RIGHT_KEY_LINUX)
		move_window(data, OFFSET_PER_CLICK, 0);
	else if (keycode.key == PLUS_KEY)
		adjust_zoom(data, ZOOM_PER_CLICK, WIN_WIDTH / 2.0, WIN_HEIGHT / 2.0);
	else if (keycode.key == MINUS_KEY)
		adjust_zoom(data, 1 / ZOOM_PER_CLICK, WIN_WIDTH / 2.0, WIN_HEIGHT
			/ 2.0);
}
