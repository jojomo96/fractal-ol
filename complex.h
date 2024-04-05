/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:12:27 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/05 12:13:10 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# include <math.h>

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_sub(t_complex a, t_complex b);
t_complex	complex_mul(t_complex a, t_complex b);
double		complex_abs(t_complex z);
double		complex_magnitude(t_complex z);

#endif
