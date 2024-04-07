/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:21:48 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/07 16:45:39 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	is_in_main_cardioid_or_bulb(t_complex c)
{
	double	q;

	q = (c.re - 0.25) * (c.re - 0.25) + c.im * c.im;
	return ((q * (q + (c.re - 0.25)) < 0.25 * c.im * c.im) || ((c.re + 1)
			* (c.re + 1) + c.im * c.im < 1.0 / 16));
}

int	calc_mandelbrot(t_complex c, int max_iter)
{
	int			i;
	t_complex	z;
	t_complex	old_z;

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

u_int32_t	mandelbrot(t_complex c, int max_iter)
{
	return ((u_int32_t)get_color_rgb(calc_mandelbrot(c, max_iter), max_iter));
}
