/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:46:54 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/04 14:59:48 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	scroll_event(double xdelta, double ydelta, void *param)
{
	t_data	*data;
	double	mX;
	double	mY;
	double	newMX;
	double	newMY;

	(void)xdelta;
	data = (t_data *)param;
	if (ydelta > 0)
		data->zoom *= ZOOM_PER_CLICK;
	else if (ydelta < 0)
		data->zoom /= ZOOM_PER_CLICK;
	mX = ((data->mouse_x - WIN_WIDTH / 2.0) + data->x_offset) * data->scale
		+ data->center.re;
	mY = ((data->mouse_y - WIN_HEIGHT / 2.0) + data->y_offset) * data->scale
		+ data->center.im;
	data->scale = data->zoom / WIN_WIDTH;
	newMX = ((data->mouse_x - WIN_WIDTH / 2.0) + data->x_offset) * data->scale
		+ data->center.re;
	newMY = ((data->mouse_y - WIN_HEIGHT / 2.0) + data->y_offset) * data->scale
		+ data->center.im;
	data->center.re += mX - newMX;
	data->center.im += mY - newMY;
	put_image(*data);
}
