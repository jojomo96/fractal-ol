/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:55:49 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/08 19:48:33 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_complex	complex_div(t_complex a, t_complex b)
{
	double		divisor;
	t_complex	result;

	divisor = b.re * b.re + b.im * b.im;
	result = init_complex((a.re * b.re + a.im * b.im) / divisor, (a.im * b.re
				- a.re * b.im) / divisor);
	return (result);
}

t_complex	polynomial_f(t_complex z)
{
	t_complex	z_cubed;
	t_complex	one;

	z_cubed = complex_mul(complex_mul(z, z), z);
	one = init_complex(1, 0);
	return (complex_sub(z_cubed, one));
}

t_complex	polynomial_fp(t_complex z)
{
	t_complex	z_squared;

	z_squared = complex_mul(z, z);
	return (init_complex(3 * z_squared.re, 3 * z_squared.im));
}

t_complex	init_complex(double re, double im)
{
	t_complex	c;

	c.re = re;
	c.im = im;
	return (c);
}
