/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:21:48 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/05 14:41:12 by jmoritz          ###   ########.fr       */
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

// Helper function to interpolate between two colors in RGBA format
static int	float_to_color_component(double value)
{
	return (int)((sin(value) + 1.0) * 127.5);
}

// Generates funky colors based on iteration count
int	get_color(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
	{
		return (0x000000FF);
	}
	else
	{
		t = (double)iter / max_iter;
		r = float_to_color_component(t * 12.0 + 0.0);
		g = float_to_color_component(t * 12.0 + 2.0);
		b = float_to_color_component(t * 12.0 + 4.0);
		return ((r << 24) | (g << 16) | (b << 8) | 255);
	}
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
