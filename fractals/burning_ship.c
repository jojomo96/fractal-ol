/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:29:04 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/04 15:40:25 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	burning_ship(t_complex c, double zoom)
{
	int			iter;
	t_complex	z;
	t_complex	temp;
	double		max_iter;

	iter = 0;
	z = init_complex(0, 0);
	max_iter = calculate_max_iter(zoom);
	while (iter < max_iter && complex_abs(z) <= 2.0)
	{
		z = init_complex(fabs(z.re), fabs(z.im));
		temp = complex_mul(z, z);
		z = complex_add(temp, c);
		iter++;
	}
	return (iter);
}
