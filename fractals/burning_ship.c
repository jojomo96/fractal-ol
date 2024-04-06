/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:29:04 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/06 12:47:02 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	calc_burning_ship(t_complex c, int max_iter)
{
	int			iter;
	t_complex	z;
	t_complex	temp;

	iter = 0;
	z = init_complex(0, 0);
	while (iter < max_iter && complex_abs(z) <= 2.0)
	{
		z = init_complex(fabs(z.re), fabs(z.im));
		temp = complex_mul(z, z);
		z = complex_add(temp, c);
		iter++;
	}
	return (iter);
}

int	get_color_burning_ship(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;
	int		a;

	if (iter == max_iter)
		return (0x000000FF);
	t = (double)iter / (double)max_iter;
	t = t - log(t) * sin(0.2 * iter) * cos(0.2 * iter);
	r = (int)((0.5 * sin(2.0 * M_PI * t) + 0.5) * 255);
	g = (int)((0.5 * sin(2.0 * M_PI * (t + 0.8)) + 0.5) * 64);
	b = (int)((0.5 * sin(2.0 * M_PI * (t + 0.8)) + 0.5) * 64);
	a = 255;
	return ((a << 24) | (r << 16) | (g << 8) | b);
}

u_int32_t	burning_ship(t_complex c, int max_iter)
{
	return ((u_int32_t)get_color(calc_burning_ship(c, max_iter), max_iter));
}
