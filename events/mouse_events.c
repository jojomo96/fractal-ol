/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:59:41 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/08 14:35:06 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	mouse_move_event(double x, double y, void *param)
{
	t_data			*data;
	const double	thresholdForJulia = 0.03;
	t_point			pos_old;
	double			deltaX;
	double			deltaY;
	double			moveSensitivity;

	moveSensitivity = 1.0;
	data = (t_data *)param;
	pos_old.x = data->mouse_x;
	pos_old.y = data->mouse_y;
	data->mouse_x = x;
	data->mouse_y = y;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
	{
		deltaX = fabs((x / data->mlx->width * 4 - 2)
				- get_config_value(JULIA_C_REAL));
		deltaY = fabs((y / data->mlx->height * 4 - 2)
				- get_config_value(JULIA_C_IMAGINARY));
		if (deltaX > thresholdForJulia || deltaY > thresholdForJulia)
		{
			set_config_value(JULIA_C_REAL, x / data->mlx->width * 4 - 2);
			set_config_value(JULIA_C_IMAGINARY, y / data->mlx->height * 4 - 2);
			put_image(*data);
		}
	}
	if (get_flag(IS_DRAGGING) && !mlx_is_key_down(data->mlx,
			MLX_KEY_LEFT_SHIFT))
	{
		deltaX = pos_old.x - data->mouse_x;
		deltaY = pos_old.y - data->mouse_y;
		deltaX *= moveSensitivity;
		deltaY *= moveSensitivity;
		if ((fabs(deltaX) > 1 && fabs(deltaX) < 50) && (fabs(deltaY) > 1
				&& fabs(deltaY) < 50))
		{
			move_window(data, deltaX, deltaY);
		}
	}
}

void	mouse_klick_event(mouse_key_t button, action_t action,
		modifier_key_t mods, void *param)
{
	t_data	*data;

	(void)mods;
	data = (t_data *)param;
	if (button == MLX_MOUSE_BUTTON_LEFT)
	{
		if (action == MLX_PRESS)
			set_flag(IS_DRAGGING, 1);
		else if (action == MLX_RELEASE)
			set_flag(IS_DRAGGING, 0);
	}
}
