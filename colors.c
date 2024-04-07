/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:06:34 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/07 09:47:55 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	*get_current_index(void)
{
	static int	index;

	return (&index);
}

void	switch_color_palette(void)
{
	*get_current_index() = (*get_current_index() + 1) % 4;
}

static t_color_palette	get_current_color_palette(void)
{
	static const t_color_palette	color_paletts[] = {
	{12.0, 0.0, 2.0, 4.0},
	{10.0, 1.0, 3.0, 5.0},
	{8.0, 2.0, 4.0, 6.0},
	{6.0, 3.0, 5.0, 7.0},
	};

	return (color_paletts[*get_current_index()]);
}

static int	float_to_color_component(double value)
{
	return ((int)((sin(value) + 1.0) * 127.5));
}

int	get_color(int iter, int max_iter)
{
	double			t;
	t_rgb			color;
	t_color_palette	palette;

	if (iter == max_iter)
		return (0x000000FF);
	palette = get_current_color_palette();
	t = (double)iter / max_iter;
	color.r = float_to_color_component(t * palette.frequency + palette.phase_r);
	color.g = float_to_color_component(t * palette.frequency + palette.phase_g);
	color.b = float_to_color_component(t * palette.frequency + palette.phase_b);
	return (encode_rgb_as_int(color));
}
