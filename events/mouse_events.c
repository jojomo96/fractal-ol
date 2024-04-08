/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:59:41 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/08 21:06:55 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static void	handle_julia_c(t_data *data, double x, double y)
{
	const double	threshold = 0.03;
	double			delta_x;
	double			delta_y;

	delta_x = fabs((x / data->mlx->width * 4 - 2)
			- get_config_value(JULIA_C_REAL));
	delta_y = fabs((y / data->mlx->height * 4 - 2)
			- get_config_value(JULIA_C_IMAGINARY));
	if (delta_x > threshold || delta_y > threshold)
	{
		set_config_value(JULIA_C_REAL, x / data->mlx->width * 4 - 2);
		set_config_value(JULIA_C_IMAGINARY, y / data->mlx->height * 4 - 2);
		put_image(*data);
	}
}

static void	handle_dragging(t_data *data, t_point pos_old)
{
	double	delta_x;
	double	delta_y;
	double	move_sensitivity;

	move_sensitivity = 1.0;
	delta_x = pos_old.x - data->mouse_x;
	delta_y = pos_old.y - data->mouse_y;
	delta_x *= move_sensitivity;
	delta_y *= move_sensitivity;
	if ((fabs(delta_x) > 1 && fabs(delta_x) < 50) && (fabs(delta_y) > 1
			&& fabs(delta_y) < 50))
	{
		move_window(data, delta_x, delta_y);
	}
}

void	mouse_move_event(double x, double y, void *param)
{
	t_data			*data;
	t_point			pos_old;

	data = (t_data *)param;
	pos_old.x = data->mouse_x;
	pos_old.y = data->mouse_y;
	data->mouse_x = x;
	data->mouse_y = y;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
		handle_julia_c(data, x, y);
	if (get_flag(IS_DRAGGING) && !mlx_is_key_down(data->mlx,
			MLX_KEY_LEFT_SHIFT))
		handle_dragging(data, pos_old);
}

void	mouse_klick_event(mouse_key_t button, action_t action,
		modifier_key_t mods, void *param)
{
	(void)param;
	(void)mods;
	if (button == MLX_MOUSE_BUTTON_LEFT)
	{
		if (action == MLX_PRESS)
			set_flag(IS_DRAGGING, 1);
		else if (action == MLX_RELEASE)
			set_flag(IS_DRAGGING, 0);
	}
}
