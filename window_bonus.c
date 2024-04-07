/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:46:11 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/07 09:50:47 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_window_data(t_data *data)
{
	data->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Fract'ol", false);
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->x_offset = 0;
	data->y_offset = 0;
	data->zoom = 2.0;
	data->scale = data->zoom / WIN_WIDTH;
	data->center = init_complex(-0.75, 0);
}
#define THREAD_COUNT 12

void	*render_section(void *arg)
{
	t_thread_data	*thread_data;
	t_point			p;
	double			scale;
	t_complex		c;

	thread_data = (t_thread_data *)arg;
	scale = thread_data->data.zoom / WIN_WIDTH;
	thread_data->data.max_iter = calculate_max_iter(thread_data->data.zoom);
	p.y = thread_data->start_y;
	while (p.y < thread_data->end_y)
	{
		p.x = 0;
		while (p.x < WIN_WIDTH)
		{
			c = init_complex((p.x + thread_data->data.x_offset - WIN_WIDTH
						/ 2.0) * scale + thread_data->data.center.re, (p.y
						+ thread_data->data.y_offset - WIN_HEIGHT / 2.0) * scale
					+ thread_data->data.center.im);
			mlx_put_pixel(thread_data->data.img, p.x, p.y,
				thread_data->data.fractal(c, thread_data->data.max_iter));
			p.x++;
		}
		p.y++;
	}
	return (NULL);
}

void	put_image(t_data data)
{
	pthread_t		threads[THREAD_COUNT];
	t_thread_data	thread_data[THREAD_COUNT];
	int				i;
	int				segment_height;

	i = 0;
	segment_height = WIN_HEIGHT / THREAD_COUNT;
	while (i < THREAD_COUNT)
	{
		thread_data[i].data = data;
		thread_data[i].start_y = i * segment_height;
		thread_data[i].end_y = (i + 1) * segment_height;
		if (i == THREAD_COUNT - 1)
			thread_data[i].end_y = WIN_HEIGHT;
		if (pthread_create(&threads[i], NULL, render_section, &thread_data[i]))
		{
			perror("Failed to create thread");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < THREAD_COUNT)
		pthread_join(threads[i++], NULL);
}
