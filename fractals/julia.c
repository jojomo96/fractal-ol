/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:19:03 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/08 18:12:35 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	calc_julia(t_complex z, int max_iter)
{
	int			iter;
	t_complex	c;
	t_complex	z_temp;

	iter = 0;
	c = init_complex(get_config_value(JULIA_C_REAL),
			get_config_value(JULIA_C_IMAGINARY));
	while (iter < max_iter && complex_magnitude(z) <= 2.0)
	{
		z_temp = init_complex(z.re * z.re - z.im * z.im + c.re, 2.0 * z.re
				* z.im + c.im);
		z = z_temp;
		iter++;
	}
	return (iter);
}

u_int32_t	julia(t_complex z, int max_iter)
{
	return ((u_int32_t)get_color_rgb(calc_julia(z, max_iter), max_iter));
}
