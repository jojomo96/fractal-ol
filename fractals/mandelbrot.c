/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:21:48 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/05 12:16:55 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	calculate_max_iter(double zoom_level)
{
	double	iter_scale;
	double	iter;

	iter_scale = 1.0 / zoom_level;
	iter = log(iter_scale) * 100.0;
	iter = floor(iter);
	if (iter < 100)
	{
		iter = 100;
	}
	else if (iter > MAX_ITER)
	{
		iter = MAX_ITER;
	}
	return ((int)iter);
}

static int	is_in_main_cardioid_or_bulb(t_complex c)
{
	double	q;

	q = (c.re - 0.25) * (c.re - 0.25) + c.im * c.im;
	return ((q * (q + (c.re - 0.25)) < 0.25 * c.im * c.im) || ((c.re + 1)
			* (c.re + 1) + c.im * c.im < 1.0 / 16));
}

int	get_color(int iter, double zoom_level)
{
	int		max_iter;
	float	normalized;
	int		red;
	int		green;
	int		blue;

	max_iter = calculate_max_iter(zoom_level);
	if (iter >= max_iter)
	{
		return ((0 << 24) | (0 << 16) | (0 << 8) | 0xFF);
	}
	else
	{
		normalized = (float)iter / max_iter;
		red = (int)(9 * (1 - normalized) * normalized * normalized * normalized
				* 255);
		green = (int)(15 * (1 - normalized) * (1 - normalized) * normalized
				* normalized * 255);
		blue = (int)(8.5 * (1 - normalized) * (1 - normalized) * (1
					- normalized) * normalized * 255);
		return ((red << 24) | (green << 16) | (blue << 8) | 0xFF);
	}
}

int	calc_mandelbrot(t_complex c, double zoom_level)
{
	int			i;
	int			max_iter;
	t_complex	z;
	t_complex	old_z;

	max_iter = calculate_max_iter(zoom_level);
	if (is_in_main_cardioid_or_bulb(c))
		return (max_iter);
	z = init_complex(0, 0);
	old_z = init_complex(0, 0);
	i = 0;
	while ((z.re * z.re + z.im * z.im) <= 4.0 && i < max_iter)
	{
		z = complex_add(complex_mul(z, z), c);
		if (i % 20 == 0)
		{
			if (z.re == old_z.re && z.im == old_z.im)
				return (max_iter);
			old_z = z;
		}
		i++;
	}
	return (i);
}

u_int32_t	mandelbrot(t_complex c, double zoom_level)
{
	return ((u_int32_t)get_color(calc_mandelbrot(c, zoom_level), zoom_level));
}
