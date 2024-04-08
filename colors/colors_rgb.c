/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:06:34 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/08 18:04:08 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static t_color_palette	*get_current_color_palette(int update, double shift)
{
	static double			phase_shift;
	static t_color_palette	current_palette = {12.0, 1.0, 2.0, 4.0};

	if (shift)
	{
		phase_shift = shift;
	}
	if (update)
	{
		current_palette.phase_r += phase_shift;
		current_palette.phase_g += phase_shift;
		current_palette.phase_b += phase_shift;
		current_palette.phase_r = fmod(current_palette.phase_r, 2 * M_PI);
		current_palette.phase_g = fmod(current_palette.phase_g, 2 * M_PI);
		current_palette.phase_b = fmod(current_palette.phase_b, 2 * M_PI);
	}
	return (&current_palette);
}

void	update_color_palette(void)
{
	get_current_color_palette(1, 0);
}

void	switch_color_palette(void)
{
	static int	counter = 0;
	double		phase_shift;

	phase_shift = get_config_value(PHASE_SHIFT);
	if (get_flag(SHIFT_COLOR) == 0)
		return ((void)get_current_color_palette(1, phase_shift));
	counter = (counter + 1) % 100;
	if (counter > 30)
		phase_shift *= -1;
	get_current_color_palette(1, phase_shift);
}

static int	float_to_color_component(double value)
{
	return ((int)((sin(value) + 1.0) * 127.5));
}

int	get_color_rgb(int iter, int max_iter)
{
	double			t;
	t_rgb			color;
	t_color_palette	*palette;

	if (iter == max_iter)
		return (0x000000FF);
	palette = get_current_color_palette(0, 0);
	t = (double)iter / max_iter;
	color.r = float_to_color_component((t * get_config_value(FREQUENCY)
				+ palette->phase_r) * get_config_value(AMPLITUDE_R));
	color.g = float_to_color_component((t * get_config_value(FREQUENCY)
				+ palette->phase_g) * get_config_value(AMPLITUDE_G));
	color.b = float_to_color_component((t * get_config_value(FREQUENCY)
				+ palette->phase_b) * get_config_value(AMPLITUDE_B));
	return (encode_rgb_as_int(color));
}
