/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:21:48 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/06 12:57:35 by jmoritz          ###   ########.fr       */
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

static int	float_to_color_component(double value)
{
	return (int)((sin(value) + 1.0) * 127.5);
}

int	get_color(int iter, int max_iter)
{
	double	t;
	t_rgb	color;

	if (iter == max_iter)
		return (0x000000FF);
	t = (double)iter / max_iter;
	color.r = float_to_color_component(t * 12.0 + 0.0);
	color.g = float_to_color_component(t * 12.0 + 2.0);
	color.b = float_to_color_component(t * 12.0 + 4.0);
	return (encode_rgb_as_int(color));
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
	return ((u_int32_t)get_color(calc_mandelbrot(c, max_iter), max_iter));
}
