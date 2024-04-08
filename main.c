/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:20:24 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/08 14:13:24 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	set_fracatal(char *name, t_data *data)
{
	if (!ft_strcmp(name, "mandelbrot"))
		data->fractal = &mandelbrot;
	else if (!ft_strcmp(name, "julia"))
		data->fractal = &julia;
	else if (!ft_strcmp(name, "burning_ship"))
		data->fractal = &burning_ship;
	else
	{
		errno = EINVAL;
		ft_printf("Invalid fractal name");
		exit(EXIT_FAILURE);
	}
}

void	parse_args(int argc, char **argv, t_data *data)
{
	if (argc >= 2)
	{
		set_fracatal(argv[1], data);
	}
	else
	{
		set_fracatal("mandelbrot", data);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	set_flag(SHIFT_COLOR, 0);
	set_config_value(FREQUENCY, 12.0);
	set_config_value(PHASE_SHIFT, 0.1);
	set_config_value(AMPLITUDE_R, 1.0);
	set_config_value(AMPLITUDE_G, 1.0);
	set_config_value(AMPLITUDE_B, 1.0);
	set_config_value(JULIA_C_REAL, -0.7);
	set_config_value(JULIA_C_IMAGINARY, 0.27015);
	parse_args(argc, argv, &data);
	init_window_data(&data);
	if (!data.mlx)
		return (1);
	if (!data.img)
		ft_error();
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	create_overlay(&data);
	put_image(data);
	mlx_scroll_hook(data.mlx, &scroll_event, &data);
	mlx_loop_hook(data.mlx, &key_press, &data);
	mlx_key_hook(data.mlx, &key_color_hook, &data);
	mlx_cursor_hook(data.mlx, &mouse_move_event, &data);
	mlx_mouse_hook(data.mlx, &mouse_klick_event, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
