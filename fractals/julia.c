/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:19:03 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/05 12:23:38 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	get_color_julia(int iter, double zoom_level)
{
	double	normalized;
	double	hue;
	double	rad;
	int		r;
	int		g;
	int		b;
	int		a;

	if (iter == calculate_max_iter(zoom_level))
		return (0x000000FF);
	normalized = (double)iter / calculate_max_iter(zoom_level);
	hue = normalized * 360.0;
	rad = hue * M_PI / 180.0;
	r = (int)((sin(rad) + 1) * 127.5);
	g = (int)((sin(rad + 2.0 * M_PI / 3.0) + 1) * 127.5);
	b = (int)((sin(rad + 4.0 * M_PI / 3.0) + 1) * 127.5);
	a = 255;
	return ((a << 24) | (r << 16) | (g << 8) | b);
}

int	calc_julia(t_complex z, double zoom)
{
	int			iter;
	t_complex	c;
	t_complex	z_temp;
	double		max_iter;

	iter = 0;
	c = init_complex(-0.7, 0.27015);
	max_iter = calculate_max_iter(zoom);
	while (iter < max_iter && complex_magnitude(z) <= 2.0)
	{
		z_temp = init_complex(z.re * z.re - z.im * z.im + c.re, 2.0 * z.re
				* z.im + c.im);
		z = z_temp;
		iter++;
	}
	return (iter);
}

u_int32_t julia(t_complex z, double zoom)
{
	return ((u_int32_t)get_color_julia(calc_julia(z, zoom), zoom));
}
