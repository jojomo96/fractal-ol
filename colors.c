/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:06:34 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/07 16:27:40 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static t_color_palette	*get_current_color_palette(int update)
{
	const double			phase_shift = 0.1;
	static t_color_palette	current_palette = {12.0, 0.0, 2.0, 4.0};

	// Initial values
	if (update)
	{
		// Define how much each button press changes the color components
		// Adjust the phases (and frequency if desired)
		current_palette.phase_r += phase_shift;
		current_palette.phase_g += phase_shift;
		current_palette.phase_b += phase_shift;
		// Wrap phase adjustments, if necessary
		current_palette.phase_r = fmod(current_palette.phase_r, 2 * M_PI);
		current_palette.phase_g = fmod(current_palette.phase_g, 2 * M_PI);
		current_palette.phase_b = fmod(current_palette.phase_b, 2 * M_PI);
	}
	return (&current_palette);
}


// Function to switch color palette
void	switch_color_palette(void)
{
	// Pass 1 to update the palette
	get_current_color_palette(1);
}

static int	float_to_color_component(double value)
{
	return ((int)((sin(value) + 1.0) * 127.5));
}

int	get_color(int iter, int max_iter)
{
	double			t;
	t_rgb			color;
	t_color_palette	*palette;

	if (iter == max_iter)
		return (0x000000FF);
	palette = get_current_color_palette(0);
	t = (double)iter / max_iter;
	color.r = float_to_color_component(t * palette->frequency
			+ palette->phase_r);
	color.g = float_to_color_component(t * palette->frequency
			+ palette->phase_g);
	color.b = float_to_color_component(t * palette->frequency
			+ palette->phase_b);
	return (encode_rgb_as_int(color));
}
