/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:28:09 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/08 14:11:20 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

typedef enum e_flags_bool
{
	SHIFT_COLOR,
	IS_DRAGGING,
	NUM_FLAGS
}		t_flags;

int		get_flag(t_flags flag);
void	set_flag(t_flags flag, int state);
void	toggle_flag(t_flags flag);

#endif
