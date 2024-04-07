/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:20:24 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/07 09:56:13 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_window_data(&data);
	if (!data.mlx)
		return (1);
	if (!data.img)
	{
		ft_error();
	}
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	data.fractal = &burning_ship;
	put_image(data);
	mlx_scroll_hook(data.mlx, &scroll_event, &data);
	mlx_loop_hook(data.mlx, &key_press, &data);
	mlx_cursor_hook(data.mlx, &mouse_move_event, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
