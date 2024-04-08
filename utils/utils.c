/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 09:48:29 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/07 17:25:30 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_complex	init_complex(double re, double im)
{
	t_complex	c;

	c.re = re;
	c.im = im;
	return (c);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	calculate_max_iter(double zoom_level)
{
	double	iter_scale;
	double	iter;

	iter_scale = 1.0 / zoom_level;
	iter = log(iter_scale) * 100.0;
	iter = floor(iter);
	if (iter < MIN_ITER)
		iter = MIN_ITER;
	else if (iter > MAX_ITER)
		iter = MAX_ITER;
	return ((int)iter);
}

int	encode_rgb_as_int(t_rgb color)
{
	return ((color.r << 24) | (color.g << 16) | (color.b << 8) | 255);
}