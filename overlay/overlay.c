/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 11:27:46 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/07 15:14:40 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	create_overlay(t_data *data)
{
	mlx_put_string(data->mlx, "Controls:", 10, 10);
	mlx_put_string(data->mlx, "WASD / Arrowkeys - Move", 10, 30);
	mlx_put_string(data->mlx, "Mousewheel - Zoom", 10, 50);
	mlx_put_string(data->mlx, "ESC - Exit", 10, 70);
	mlx_put_string(data->mlx, "Iterations:", 10, 130);
}

void	update_overlay(t_data *data)
{
	static mlx_image_t	*overlays[10];

	mlx_delete_image(data->mlx, overlays[0]);
	// mlx_put_string(data->mlx, "R - Reset", 10, 70);
	overlays[0] = mlx_put_string(data->mlx,
			ft_itoa(calculate_max_iter(data->zoom)), 140, 130);
	// mlx_put_string(data->mlx, "Fractal:", 10, 150);
	// mlx_put_string(data->mlx, "Mandelbrot", 10, 170);
	// mlx_put_string(data->mlx, "Center:", 10, 190);
	// mlx_put_string(data->mlx, ft_dtoa(data->center.re, 2), 10, 210);
	// mlx_put_string(data->mlx, ft_dtoa(data->center.im, 2), 10, 230);
	// mlx_put_string(data->mlx, "Mouse:", 10, 250);
	// mlx_put_string(data->mlx, ft_dtoa(data->mouse_x, 2), 10, 270);
	// mlx_put_string(data->mlx, ft_dtoa(data->mouse_y, 2), 10, 290);
}
