/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:19:03 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/04 15:22:19 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	julia(t_complex z, double zoom)
{
	int			iter;
	t_complex	c;
	t_complex	z_temp;

	iter = 0;
	c = init_complex(-0.7, 0.27015);
	while (iter < calculate_max_iter(zoom) && complex_magnitude(z) <= 2.0)
	{
		z_temp = init_complex(z.re * z.re - z.im * z.im + c.re, 2.0 * z.re
				* z.im + c.im);
		z = z_temp;
		iter++;
	}
	return (iter);
}
