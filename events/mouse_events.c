/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:59:41 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/04 12:04:38 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	mouse_move_event(double x, double y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->mouse_x = x;
	data->mouse_y = y;
}
