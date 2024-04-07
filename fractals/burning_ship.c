/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:29:04 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/07 10:01:15 by jmoritz          ###   ########.fr       */
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

u_int32_t	burning_ship(t_complex c, int max_iter)
{
	return ((u_int32_t)get_color(calc_burning_ship(c, max_iter), max_iter));
}
