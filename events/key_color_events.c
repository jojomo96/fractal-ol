/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_color_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:33:16 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/08 10:44:42 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	key_color_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	printf("key_color_hook\n");
	data = (t_data *)param;
	if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS)
	{
		switch_color_palette();
		put_image(*data);
	}
	if (keydata.key == MLX_KEY_KP_0 && keydata.action == MLX_PRESS)
		toggle_flag(SHIFT_COLOR);
	if (mlx_is_key_down(data->mlx, MLX_KEY_KP_1))
	{
		if (keydata.key == MLX_KEY_KP_ADD && keydata.action == MLX_PRESS)
			set_config_value(PHASE_SHIFT, get_config_value(PHASE_SHIFT) + 0.1);
		else if (keydata.key == MLX_KEY_KP_SUBTRACT
			&& keydata.action == MLX_PRESS)
			set_config_value(PHASE_SHIFT, get_config_value(PHASE_SHIFT) - 0.1);
	}

	if(keydata.action == MLX_PRESS)
	{
		update_overlay(data);
		put_image(*data);
	}
}
