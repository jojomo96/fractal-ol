/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:21:48 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/04 16:42:44 by jmoritz          ###   ########.fr       */
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

int	mandelbrot(t_complex c, double zoom_level)
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
