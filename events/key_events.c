/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:08:57 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/04 15:09:00 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		move_up_down;
	int		move_left_right;

	move_up_down = 0;
	move_left_right = 0;
	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		handle_ESC_key(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP) || mlx_is_key_down(data->mlx,
			MLX_KEY_W))
		move_up_down = -OFFSET_PER_CLICK;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_up_down = OFFSET_PER_CLICK;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) || mlx_is_key_down(data->mlx,
			MLX_KEY_A))
		move_left_right = -OFFSET_PER_CLICK;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_left_right = OFFSET_PER_CLICK;
	if (move_up_down != 0 || move_left_right != 0)
		move_window(data, move_left_right, move_up_down);
}
