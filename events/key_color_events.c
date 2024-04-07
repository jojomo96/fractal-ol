/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_color_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:33:16 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/07 16:59:48 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	key_color_hook(mlx_key_data_t keydata, void* param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS)
	{
		switch_color_palette();
		put_image(*data);
	}

}
