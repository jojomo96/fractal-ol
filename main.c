/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:20:24 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/08 18:18:33 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void	set_fractal(t_data *data, t_flags flag, int *has_flag)
{
	if (flag == JULIA_IS_ACTIVE && !*has_flag)
	{
		data->fractal = &julia;
		*has_flag = 1;
	}
	else if (flag == MANDELBROT_IS_ACTIVE && !*has_flag)
	{
		data->fractal = &mandelbrot;
		*has_flag = 1;
	}
	else if (flag == BURNING_SHIP_IS_ACTIVE && !*has_flag)
	{
		data->fractal = &burning_ship;
		*has_flag = 1;
	}
}

static void	handle_p(int argc, char **argv, int *i)
{
	double	real;
	double	imaginary;
	char	*endptr1;
	char	*endptr2;

	if (*i + 2 < argc)
	{
		real = ft_strtod(argv[*i + 1], &endptr1);
		imaginary = ft_strtod(argv[*i + 2], &endptr2);
		while (ft_isspace((unsigned char)*endptr1))
			endptr1++;
		while (ft_isspace((unsigned char)*endptr2))
			endptr2++;
		if (*endptr1 != '\0' || *endptr2 != '\0')
			print_help(argv);
		if (real < -2.0 || real > 2.0 || imaginary < -2.0 || imaginary > 2.0)
			print_help(argv);
		set_config_value(JULIA_C_REAL, real);
		set_config_value(JULIA_C_IMAGINARY, imaginary);
		*i += 2;
	}
	else
		print_help(argv);
}

void	parse_args(int argc, char **argv, t_data *data)
{
	int	i;
	int	has_fractal;

	if (argc < 2)
		print_help(argv);
	has_fractal = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-o") == 0)
			set_flag(OVERLAY_IS_VISIBLE, 1);
		else if (ft_strcmp(argv[i], "-j") == 0 && !has_fractal)
			set_fractal(data, JULIA_IS_ACTIVE, &has_fractal);
		else if (ft_strcmp(argv[i], "-m") == 0 && !has_fractal)
			set_fractal(data, MANDELBROT_IS_ACTIVE, &has_fractal);
		else if (ft_strcmp(argv[i], "-b") == 0 && !has_fractal)
			set_fractal(data, BURNING_SHIP_IS_ACTIVE, &has_fractal);
		else if (ft_strcmp(argv[i], "-p") == 0)
		{
			handle_p(argc, argv, &i);
		}
		else
			print_help(argv);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_config();
	parse_args(argc, argv, &data);
	init_window_data(&data);
	if (!data.mlx)
		return (1);
	if (!data.img)
		ft_error();
	if (get_flag(OVERLAY_IS_VISIBLE))
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
