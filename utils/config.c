/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:12:41 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/07 18:27:30 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static double	*get_double_array(void)
{
	static double doubleArray[NUM_DOUBLES] = {0};

	return (doubleArray);
}

void	set_config_value(t_config_index index, double value)
{
	double	*doubleArray;

	if (index < NUM_DOUBLES)
	{
		doubleArray = get_double_array();
		doubleArray[index] = value;
	}
}

double	get_config_value(t_config_index index)
{
	if (index < NUM_DOUBLES)
	{
		double *doubleArray = get_double_array();
		return (doubleArray[index]);
	}
	return (0);
}
