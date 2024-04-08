/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:12:41 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/08 12:17:59 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static double	*get_double_array(void)
{
	static double	double_array[NUM_DOUBLES] = {0};

	return (double_array);
}

void	set_config_value(t_config_index index, double value)
{
	double	*double_array;

	if (index < NUM_DOUBLES)
	{
		double_array = get_double_array();
		double_array[index] = value;
	}
}

double	get_config_value(t_config_index index)
{
	double	*double_array;

	if (index < NUM_DOUBLES)
	{
		double_array = get_double_array();
		return (double_array[index]);
	}
	return (0);
}
