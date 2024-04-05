/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:46:54 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/05 12:18:45 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	scroll_event(double xdelta, double ydelta, void *param)
{
	t_data	*data;
	double	m_x;
	double	m_y;
	double	new_mx;
	double	new_my;

	(void)xdelta;
	data = (t_data *)param;
	if (ydelta > 0)
		data->zoom *= ZOOM_PER_CLICK;
	else if (ydelta < 0)
		data->zoom /= ZOOM_PER_CLICK;
	m_x = ((data->mouse_x - WIN_WIDTH / 2.0) + data->x_offset) * data->scale
		+ data->center.re;
	m_y = ((data->mouse_y - WIN_HEIGHT / 2.0) + data->y_offset) * data->scale
		+ data->center.im;
	data->scale = data->zoom / WIN_WIDTH;
	new_mx = ((data->mouse_x - WIN_WIDTH / 2.0) + data->x_offset) * data->scale
		+ data->center.re;
	new_my = ((data->mouse_y - WIN_HEIGHT / 2.0) + data->y_offset) * data->scale
		+ data->center.im;
	data->center.re += m_x - new_mx;
	data->center.im += m_y - new_my;
	put_image(*data);
}
