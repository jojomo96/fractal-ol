/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:55:49 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/08 21:32:35 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

/**
 * Divides two complex numbers.
 *
 * @param a The dividend complex number.
 * @param b The divisor complex number.
 * @return The result of the division as a complex number.
 */
t_complex	complex_div(t_complex a, t_complex b)
{
	double		divisor;
	t_complex	result;

	divisor = b.re * b.re + b.im * b.im;
	result = init_complex((a.re * b.re + a.im * b.im) / divisor, (a.im * b.re
				- a.re * b.im) / divisor);
	return (result);
}

/**
 * Evaluates a polynomial function f(z) = z^3 - 1.
 *
 * @param z The input complex number.
 * @return The result of the polynomial function as a complex number.
 */
t_complex	polynomial_f(t_complex z)
{
	t_complex	z_cubed;
	t_complex	one;

	z_cubed = complex_mul(complex_mul(z, z), z);
	one = init_complex(1, 0);
	return (complex_sub(z_cubed, one));
}

/**
 * Evaluates the derivative of the polynomial function f'(z) = 3z^2.
 *
 * @param z The input complex number.
 * @return The result of the derivative as a complex number.
 */
t_complex	polynomial_fp(t_complex z)
{
	t_complex	z_squared;

	z_squared = complex_mul(z, z);
	return (init_complex(3 * z_squared.re, 3 * z_squared.im));
}

/**
 * Initializes a complex number with the given real and imaginary parts.
 *
 * @param re The real part of the complex number.
 * @param im The imaginary part of the complex number.
 * @return The initialized complex number.
 */
t_complex	init_complex(double re, double im)
{
	t_complex	c;

	c.re = re;
	c.im = im;
	return (c);
}
