/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:15:57 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/08 21:33:27 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

/**
 * Adds two complex numbers.
 *
 * @param a The first complex number.
 * @param b The second complex number.
 * @return The sum of the two complex numbers.
 */
t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	result;

	result.re = a.re + b.re;
	result.im = a.im + b.im;
	return (result);
}

/**
 * Subtracts two complex numbers.
 *
 * @param a The first complex number.
 * @param b The second complex number.
 * @return The difference between the two complex numbers.
 */
t_complex	complex_sub(t_complex a, t_complex b)
{
	t_complex	result;

	result.re = a.re - b.re;
	result.im = a.im - b.im;
	return (result);
}

/**
 * Multiplies two complex numbers.
 *
 * @param a The first complex number.
 * @param b The second complex number.
 * @return The product of the two complex numbers.
 */
t_complex	complex_mul(t_complex a, t_complex b)
{
	t_complex	result;

	result.re = a.re * b.re - a.im * b.im;
	result.im = a.re * b.im + a.im * b.re;
	return (result);
}

/**
 * Calculates the absolute value of a complex number.
 *
 * @param z The complex number.
 * @return The absolute value of the complex number.
 */
double	complex_abs(t_complex z)
{
	return (sqrt(z.re * z.re + z.im * z.im));
}

/**
 * Calculates the magnitude of a complex number.
 *
 * @param z The complex number.
 * @return The magnitude of the complex number.
 */
double	complex_magnitude(t_complex z)
{
	return (sqrt(z.re * z.re + z.im * z.im));
}
t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	result;

	result.re = a.re + b.re;
	result.im = a.im + b.im;
	return (result);
}

t_complex	complex_sub(t_complex a, t_complex b)
{
	t_complex	result;

	result.re = a.re - b.re;
	result.im = a.im - b.im;
	return (result);
}

t_complex	complex_mul(t_complex a, t_complex b)
{
	t_complex	result;

	result.re = a.re * b.re - a.im * b.im;
	result.im = a.re * b.im + a.im * b.re;
	return (result);
}

double	complex_abs(t_complex z)
{
	return (sqrt(z.re * z.re + z.im * z.im));
}

double	complex_magnitude(t_complex z)
{
	return (sqrt(z.re * z.re + z.im * z.im));
}
