/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 11:27:46 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/08 18:16:28 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	create_overlay(t_data *data)
{
	char	*str;

	mlx_put_string(data->mlx, "Controls:", 10, 10);
	mlx_put_string(data->mlx, "WASD / Arrowkeys - Move", 10, 30);
	mlx_put_string(data->mlx, "Mousewheel - Zoom", 10, 50);
	mlx_put_string(data->mlx, "ESC - Exit", 10, 70);
	mlx_put_string(data->mlx, "Q - Switch Color Palette", 10, 90);
	mlx_put_string(data->mlx, "SHIFT + Mouse -> Change Julia values", 10, 110);
	str = " (7)(8) Iter: | (0) Reverse: | (1) Phase:"
		" | (4) Ampl R | (5) Ampl G | (6) Ampl B | (2) Frequenzy: |";
	mlx_put_string(data->mlx, str, 10, 130);
}

void	update_overlay(t_data *data)
{
	static mlx_image_t	*overlays[10];
	double				numbers[7];
	int					width[7];

	if (!get_flag(OVERLAY_IS_VISIBLE))
		return ;
	width[0] = 14;
	width[1] = 14;
	width[2] = 12;
	width[3] = 12;
	width[4] = 12;
	width[5] = 12;
	width[6] = 16;
	numbers[0] = calculate_max_iter(data->zoom);
	numbers[1] = (double)get_flag(SHIFT_COLOR);
	numbers[2] = get_config_value(PHASE_SHIFT);
	numbers[3] = get_config_value(AMPLITUDE_R);
	numbers[4] = get_config_value(AMPLITUDE_G);
	numbers[5] = get_config_value(AMPLITUDE_B);
	numbers[6] = get_config_value(FREQUENCY);
	mlx_delete_image(data->mlx, overlays[0]);
	overlays[0] = mlx_put_string(data->mlx,
			ft_combine_numbers_with_widths(numbers, sizeof(numbers)
				/ sizeof(numbers[0]), width), 10, 150);
}
