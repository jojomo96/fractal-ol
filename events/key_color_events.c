/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_color_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:33:16 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/08 12:17:19 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	adjust_value(mlx_key_data_t keydata, t_config_index config, float delta)
{
	if (keydata.key == MLX_KEY_KP_ADD && keydata.action == MLX_PRESS)
		set_config_value(config, get_config_value(config) + delta);
	else if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action == MLX_PRESS)
		set_config_value(config, get_config_value(config) - delta);
}

void	handle_phase_shift_and_amplitude_changes(mlx_key_data_t keydata,
		t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_KP_1))
		adjust_value(keydata, PHASE_SHIFT, 0.01);
	if (mlx_is_key_down(data->mlx, MLX_KEY_KP_4))
		adjust_value(keydata, AMPLITUDE_R, 0.1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_KP_5))
		adjust_value(keydata, AMPLITUDE_G, 0.1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_KP_6))
		adjust_value(keydata, AMPLITUDE_B, 0.1);
}

void	handle_color_palette_switch(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS)
	{
		switch_color_palette();
		put_image(*data);
	}
}

void	render_updated_image(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.action == MLX_PRESS && keydata.key != MLX_KEY_ESCAPE)
	{
		update_overlay(data);
		put_image(*data);
		printf("Render Image\n");
		printf("Phase Shift: %f, R: %f, G: %f, B: %f\n",
			get_config_value(PHASE_SHIFT), get_config_value(AMPLITUDE_R),
			get_config_value(AMPLITUDE_G), get_config_value(AMPLITUDE_B));
	}
}

void	key_color_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	handle_color_palette_switch(keydata, data);
	if (keydata.key == MLX_KEY_KP_0 && keydata.action == MLX_PRESS)
		toggle_flag(SHIFT_COLOR);
	handle_phase_shift_and_amplitude_changes(keydata, data);
	render_updated_image(keydata, data);
}
