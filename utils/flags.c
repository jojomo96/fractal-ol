/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:28:00 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/07 17:49:56 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static unsigned int	*get_bitmap(void)
{
	static unsigned int	bitmap;

	return (&bitmap);
}

void	set_flag(t_flags flag, int state)
{
	unsigned int	*bitmap;

	bitmap = get_bitmap();
	if (flag >= NUM_FLAGS)
		return ;
	if (state)
		*bitmap |= (1U << flag);
	else
		*bitmap &= ~(1U << flag);
}

void	toggle_flag(t_flags flag)
{
	unsigned int	*bitmap;

	bitmap = get_bitmap();
	if (flag >= NUM_FLAGS)
		return ;
	*bitmap ^= (1U << flag);
}

int	get_flag(t_flags flag)
{
	unsigned int	*bitmap;

	bitmap = get_bitmap();
	if (flag >= NUM_FLAGS)
		return (0);
	return ((*bitmap >> flag) & 1U);
}
