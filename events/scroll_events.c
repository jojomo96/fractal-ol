/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:46:54 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/04 12:12:51 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	scroll_event(double xdelta, double ydelta, void *param)
{
	t_data	*data;
	double	mX;
	double	mY;

	data = (t_data *)param;
	(void)xdelta;
	if (ydelta > 0)
		data->zoom *= ZOOM_PER_CLICK;
	else if (ydelta < 0)
		data->zoom /= ZOOM_PER_CLICK;
	mX = (data->mouse_x - WIN_WIDTH / 2.0) * (data->scale) + data->center.re;
	mY = (data->mouse_y - WIN_HEIGHT / 2.0) * (data->scale) + data->center.im;
	if (ydelta > 0)
	{
		data->center.re += (mX - data->center.re) * (1 - 1 / ZOOM_PER_CLICK);
		data->center.im += (mY - data->center.im) * (1 - 1 / ZOOM_PER_CLICK);
	}
	else if (ydelta < 0)
	{
		data->center.re -= (mX - data->center.re) * (1 - ZOOM_PER_CLICK);
		data->center.im -= (mY - data->center.im) * (1 - ZOOM_PER_CLICK);
	}
	data->scale = data->zoom / WIN_WIDTH;
	put_image(*data);
}
