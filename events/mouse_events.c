/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:59:41 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/08 13:58:52 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	mouse_move_event(double x, double y, void *param)
{
	t_data			*data;
	double			deltaX;
	double			deltaY;
	const double	threshold = 0.03;

	data = (t_data *)param;
	data->mouse_x = x;
	data->mouse_y = y;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
	{
		deltaX = fabs((x / data->mlx->width * 4 - 2)
				- get_config_value(JULIA_C_REAL));
		deltaY = fabs((y / data->mlx->height * 4 - 2)
				- get_config_value(JULIA_C_IMAGINARY));
		if (deltaX > threshold || deltaY > threshold)
		{
			set_config_value(JULIA_C_REAL, x / data->mlx->width * 4 - 2);
			set_config_value(JULIA_C_IMAGINARY, y / data->mlx->height * 4 - 2);
			put_image(*data);
		}
	}
}
