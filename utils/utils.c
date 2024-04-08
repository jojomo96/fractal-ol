/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 09:48:29 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/08 19:24:22 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_complex	init_complex(double re, double im)
{
	t_complex	c;

	c.re = re;
	c.im = im;
	return (c);
}

void	print_help(char **argv)
{
	ft_printf("Usage: %s [OPTIONS]...\n", argv[0]);
	ft_printf("\nOptions:\n");
	ft_printf("  -j,   Generate Julia fractal.\n");
	ft_printf("  -m,   Generate Mandelbrot fractal.\n");
	ft_printf("  -b,   Generate Burning Ship fractal.\n");
	ft_printf("\n");
	ft_printf("  -o,   Apply an overlay on the generated fractal.\n");
	ft_printf("  -p,   Set the position for Julia fractal generation.\n");
	ft_printf("        Requires two double values. The values must be\n");
	ft_printf("        between -2.0 and 2.0. Example: -p 0.285 0.01\n");
	ft_printf("\nUsage Examples:\n");
	ft_printf("  %s -j -o              Generate a Julia fractal with", argv[0]);
	ft_printf(" an overlay.\n");
	ft_printf("  %s -m                 Generate a Mandelbrot fractal.\n",
		argv[0]);
	ft_printf("  %s -j -p 0.285 0.01   Generate a Julia fractal at", argv[0]);
	ft_printf(" position (0.285, 0.01).\n");
	ft_printf("\nNote: The -p option is only applicable with -j (Julia ");
	ft_printf("fractal) option.\n");
	exit(EXIT_FAILURE);
}

void	init_config(void)
{
	set_flag(SHIFT_COLOR, 0);
	set_config_value(FREQUENCY, 12.0);
	set_config_value(PHASE_SHIFT, 0.1);
	set_config_value(AMPLITUDE_R, 1.0);
	set_config_value(AMPLITUDE_G, 1.0);
	set_config_value(AMPLITUDE_B, 1.0);
	set_config_value(JULIA_C_REAL, -0.7);
	set_config_value(JULIA_C_IMAGINARY, 0.27015);
}

int	calculate_max_iter(double zoom_level)
{
	double	iter_scale;
	double	iter;

	iter_scale = 1.0 / zoom_level;
	iter = log(iter_scale) * 100.0;
	iter = floor(iter);
	if (iter < MIN_ITER)
		iter = MIN_ITER;
	else if (iter > MAX_ITER)
		iter = MAX_ITER;
	if ((int)get_config_value(ITER_OFFSET) + (int)iter <= 0)
		return ((int)iter);
	return ((int)iter + (int)get_config_value(ITER_OFFSET));
}

int	encode_rgb_as_int(t_rgb color)
{
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 255);
}
