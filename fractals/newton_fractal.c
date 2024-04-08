/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:58:34 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/08 19:54:59 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	calc_newton_fractal(t_complex c, int max_iter)
{
	int			i;
	t_complex	z;
	t_complex	f;
	t_complex	fp;
	t_complex	z_next;

	i = 0;
	z = c;
	while (i < max_iter)
	{
		f = polynomial_f(z);
		fp = polynomial_fp(z);
		if (fp.re == 0 && fp.im == 0)
			break ;
		z_next = complex_sub(z, complex_div(f, fp));
		if ((z_next.re - z.re) * (z_next.re - z.re) + (z_next.im - z.im)
			* (z_next.im - z.im) < 1e-6)
			break ;
		z = z_next;
		i++;
	}
	return (i);
}

u_int32_t	newton_fractal(t_complex z, int max_iter)
{
	return ((u_int32_t)get_color_rgb(calc_newton_fractal(z, max_iter),
			max_iter));
}
