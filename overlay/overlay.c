/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 11:27:46 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/08 10:35:46 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	create_overlay(t_data *data)
{
	mlx_put_string(data->mlx, "Controls:", 10, 10);
	mlx_put_string(data->mlx, "WASD / Arrowkeys - Move", 10, 30);
	mlx_put_string(data->mlx, "Mousewheel - Zoom", 10, 50);
	mlx_put_string(data->mlx, "ESC - Exit", 10, 70);
	mlx_put_string(data->mlx, " Iter: | Shift: | Phase: |", 10, 130);
}

void	update_overlay(t_data *data)
{
	static mlx_image_t	*overlays[10];
	double				numbers[3];
	int					width[3];
	int					size;

	width[0] = 7;
	width[1] = 8;
	width[2] = 8;
	numbers[0] = calculate_max_iter(data->zoom);
	numbers[1] = (double)get_flag(SHIFT_COLOR);
	numbers[2] = get_config_value(PHASE_SHIFT);
	size = sizeof(numbers) / sizeof(numbers[0]);
	mlx_delete_image(data->mlx, overlays[0]);
	overlays[0] = mlx_put_string(data->mlx,
			ft_combine_numbers_with_widths(numbers, size, width), 10, 150);
}
