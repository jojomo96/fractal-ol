/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:11:31 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/07 18:21:41 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

typedef enum e_config
{
	PHASE_SHIFT,
	FREQUENCY,
	NUM_DOUBLES
}		t_config_index;

void	set_config_value(t_config_index index, double value);
double	get_config_value(t_config_index index);
#endif
